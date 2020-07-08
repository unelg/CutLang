#!/usr/bin/env python3

import os
import sys
import glob
import platform
import concurrent.futures


# noinspection PyShadowingBuiltins,PyShadowingNames
def help():
    for i in placeholders:
        for j in i:
            print(j, end=' ')
        print("")
    print('ROOT file type can be:')
    os.system('grep "inptype ==" ../CLA/CLA.C | cut -f3 -d\'=\' | cut -f1 -d\')\'')


# noinspection PyShadowingNames,SpellCheckingInspection
def removePattern(pattern):
    if type(pattern) is str:
        for i in glob.glob(pattern):
            try:
                os.remove(i)
            except FileNotFoundError:
                pass
    elif type(pattern) is list:
        for i in pattern:
            try:
                os.remove(i)
            except FileNotFoundError:
                pass


def getStringCount(filename, query):
    n = 0
    if type(query) is str:
        for line in open(filename).readlines():
            if query in line and '#' not in line:
                n += 1
    elif type(query) is list:
        for line in open(filename).readlines():
            for single_query in query:
                if single_query in line and '#' not in line:
                    n += 1
    return n


# noinspection PyShadowingNames
def singleAnalysis(arguments, histoId=None):
    algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
    if algorithm_count > 1:
        print("Analysis with Multiple Regions")
        os.system(base_dir + "scripts/separate_algos.sh " + arguments['inifile'])
    else:
        print("Single Analysis")
        os.system("cp " + arguments['inifile'] + " BP_1-card.ini")

    removePattern('histoOut-BP_*.root')
    print(base_dir + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT')
    res = os.system('export PATH=$PATH:$ROOTSYS/bin ;\
               export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:../CLA/ ;\
               ' + base_dir + 'CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
        algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
        arguments['start']))

    if res == 0:
        print('CutLang finished successfully, now adding histograms')
        try:
            os.remove('histoOut-' + arguments['inifile'].split('/')[-1][:-4] + '.root')
        except FileNotFoundError:
            pass
        if histoId is not None:
            hadd_query = 'hadd -f histoOut-' + arguments['inifile'].split('/')[-1][:-4] + str(histoId) + '.root'
        else:
            hadd_query = 'hadd -f histoOut-' + arguments['inifile'].split('/')[-1][:-4] + '.root'
        for i in glob.glob('histoOut-BP_*.root'):
            hadd_query += " " + i
        res = os.system(hadd_query)
        if res == 120:
            print("hadd finished successfully, now removing auxiliary files")
            removePattern('histoOut-BP_*.root')
            removePattern(['_head.ini', '_algos.ini', '_inifile'])
            removePattern('BP_*-card.ini')
    return res


placeholders = [
    ["-i", "--inifile"],
    ["-e", "--events"],
    ["-j", "--parallel"],
    ["-s", "--start"],
    ["-v", "--verbose"],
    ["-h", "--help"]]

if '-h' in sys.argv or '--help' in sys.argv:
    help()
    sys.exit(1)

if len(sys.argv) < 3:
    print("ERROR: Not enough arguments")
    help()
    sys.exit(1)

arguments = {'inifile': "CLA.ini",
             'datafile': sys.argv[1],
             'datatype': sys.argv[2],
             'parallel': 1,
             'verbose': 5000,
             'events': 0,
             'start': 0}
POSITIONAL = ()

for i, arg in enumerate(sys.argv[3::2]):
    if arg in placeholders[3]:
        print("command line arguments:")
        help()
        sys.exit(1)
    elif arg in placeholders[i]:
        arguments[placeholders[i][1][2:]] = sys.argv[i * 2 + 4]

arguments['parallel'] = int(arguments['parallel']) // 1
if not os.path.exists(arguments['datafile']):
    sys.exit(arguments['datafile'] + " does not exist.")

algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
n_cpu = os.cpu_count()
base_dir = os.path.dirname(os.path.abspath(__file__))[:-4]

if arguments['parallel'] > n_cpu or arguments['parallel'] == 0:
    arguments['parallel'] = n_cpu - 1

if arguments['parallel'] > 1:
    # skip_count = getStringCount(arguments['inifile'], ['SkipHistos', 'SkipEffs'])
    skip_histos = getStringCount(arguments['inifile'], 'SkipHistos')
    skip_effs = getStringCount(arguments['inifile'], 'SkipEffs')
    print("Using", arguments['parallel'], "cores")
    if int(arguments['events']) == 0:
        arguments['events'] = int(os.popen('../scripts/event_count.sh ' + arguments['datafile']).read().split()[-1])
    print("*" * 100,
          base_dir + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -PLL ${PRLL}',
          sep='\n')

    os.system('rm -r temp')
    temp_dir = 'temp'
    os.mkdir(temp_dir)
    for i in range(arguments['parallel']):
        dir_name = 'cut_' + str(i)
        os.mkdir(os.path.join(temp_dir, dir_name))
        os.system(
            'mkdir ' + os.path.join(temp_dir, dir_name) + '/runs; cp ' + base_dir + 'runs/* ' + os.path.join(temp_dir,
                                                                                                             dir_name) + '/runs/')
        os.system('cp -r ' + base_dir + 'CLA ' + os.path.join(temp_dir, dir_name))
        os.system('cp -r ' + base_dir + 'analysis_core ' + os.path.join(temp_dir, dir_name))
        os.system('cp -r ' + base_dir + 'BP ' + os.path.join(temp_dir, dir_name))
        # Copied {runs, CLA, analysis_core, BP}
        removePattern('histoOut-BP_*.root')
        print(dir_name, 'copied from runs')

    interval = int(arguments['events']) // arguments['parallel']
    processes = []
    for i in range(arguments['parallel']):
        cur_arguments = arguments.copy()
        cur_arguments['start'] = cur_arguments['start'] + interval * i
        cur_arguments['events'] = interval
        if i + 1 == arguments['parallel']:
            cur_arguments['events'] += int(arguments['events']) % interval
        cur_arguments['inifile'] = temp_dir + '/cut_' + str(i) + '/runs/' + arguments['inifile']
        processes.append(cur_arguments)

    with concurrent.futures.ThreadPoolExecutor(max_workers=arguments['parallel']) as executor:
        executor.map(singleAnalysis, processes)
        executor.shutdown(wait=True)

    try:
        os.remove('histoOut-' + arguments['inifile'][:-4] + '.root')
    except FileNotFoundError:
        pass
    arguments['inifile'] = arguments['inifile'].split('/')[-1][:-4]
    res = 0

    for i in os.listdir(base_dir + 'runs/temp/'):
        res = os.system(
            'hadd -a histoOut-' + arguments['inifile'] + '.root ' + base_dir + 'runs/temp/' + i + '/runs/histoOut-' +
            arguments['inifile'] + '.root')
    print("removing auxiliary files")
    if res == 0:
        os.system('root -l -q \'' + base_dir + 'analysis_core/FinalEff.C("' + base_dir + 'runs/histoOut-' + arguments[
            'inifile'] + '.root", \'' + str(skip_histos) + '\', \'' + str(skip_effs) + '\')\'')
    removePattern('histoOut-BP_*.root')
    removePattern(['_head.ini', '_algos.ini', '_inifile'])
    removePattern('BP_*-card.ini')
    os.system('rm -r temp')
else:
    singleAnalysis(arguments)
