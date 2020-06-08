import os
import sys
import glob
import time
import tempfile
import multiprocessing


# noinspection PyShadowingBuiltins,PyShadowingNames
def help():
    for i in placeholders:
        for j in i:
            print(j, end=' ')
        print("")
    print('ROOT file type can be:')
    os.system('grep "inptype ==" ' + base_dir[:-4] + 'CLA/CLA.C | cut -f3 -d\'=\' | cut -f1 -d\')\'')


# noinspection PyShadowingNames,SpellCheckingInspection
def removePattern(pattern):
    if type(pattern) is str:
        for i in glob.glob(pattern):
            os.remove(i)
    elif type(pattern) is list:
        for i in pattern:
            os.remove(i)


def getStringCount(filename, query):
    n = 0
    if type(query) is str:
        for line in open(filename).readlines():
            if query in line:
                n += 1
    elif type(query) is list:
        for line in open(filename).readlines():
            for single_query in query:
                if single_query in line:
                    n += 1
    return n


# noinspection PyShadowingNames
def singleAnalysis(arguments):
    algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
    if algorithm_count > 1:
        print("Analysis with Multiple Regions")
        os.system(base_dir[:-4] + "scripts/separate_algos.sh " + arguments['inifile'])
    else:
        print("Single Analysis")
        os.system("cp " + arguments['inifile'] + " BP_1-card.ini")

    removePattern('histoOut-BP_*.root')
    print(base_dir[:-4] + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT')
    res = os.system('export PATH=$PATH:$ROOTSYS/bin ;\
               export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:../CLA/ ;\
               ' + base_dir[:-4] + 'CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
        algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
        arguments['start']))
    return res
"""
    algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
    if algorithm_count > 1:
        print("Analysis with Multiple Regions")
        os.system(base_dir[:-4] + "scripts/separate_algos.sh " + arguments['inifile'])
    else:
        print("Single Analysis")
        os.system("cp " + arguments['inifile'] + " BP_1-card.ini")
        for i in range(algorithm_count):
            os.system(base_dir[:-4] + "scripts/ini2txt.sh BP_" + str(i))

    removePattern('histoOut-BP_*.root')
    print(r'' + base_dir[:-4] + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT')
    res = os.system('export PATH=$PATH:$ROOTSYS/bin ;\
               export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:' + dir_name[:-4] + 'CLA;\
               ' + base_dir[:-4] + 'CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
        algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
        arguments['start']))
"""

starttime = time.time()
placeholders = [
    ["-i", "--inifile"],
    ["-e", "--events"],
    ["-j", "--parallel"],
    ["-s", "--start"],
    ["-v", "--verbose"],
    ["-h", "--help"]]

if len(sys.argv) < 2:
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
base_dir = os.path.dirname(os.path.abspath(__file__))

if arguments['parallel'] > n_cpu or arguments['parallel'] == 0:
    arguments['parallel'] = n_cpu - 1

if arguments['parallel'] > 1:
    skip_count = getStringCount(arguments['inifile'], ['SkipHistos', 'SkipEffs'])
    print("Using", arguments['parallel'], "cores")
    if int(arguments['events']) == 0:
        events = int(os.popen(
            'export PATH=$PATH:$ROOTSYS/bin ;\
            export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:' + base_dir[:-4] + 'CLA/; dt=$(grep "\"' +
            arguments[
                'datatype'] + '\"" ' + base_dir[:-4] + 'CLA/CLA.C | cut -d \'{\' -f 2 | head -c -9 | cut -c 2-); chn=$(grep -A2 "if ($dt)" ' + base_dir[:-4] + 'CLA/CLA.C | grep "TChain(" | cut -d \'"\' -f 2); TotalEvents="$(root -l -q \'' + base_dir[:-4] + 'analysis_core/getentries.cxx("\'' +
            arguments[
                'datafile'] + '\'" ,"\'${chn}\'")\')"; EVENTS="$(echo $TotalEvents | awk \'{print $NF}\')"; echo $EVENTS').read())
    print("*" * 100,
          base_dir[:-4] + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -PLL ${PRLL}',
          sep='\n')

    os.mkdir('temp')
    temp_dir = 'temp'
    for i in range(arguments['parallel']):
        dir_name = 'temp_runs' + str(i)
        os.mkdir(os.path.join(temp_dir, dir_name))
        # os.chdir(os.path.join(temp_dir, dir_name))
        os.system('cp ' + base_dir + '/* ' + os.path.join(temp_dir, dir_name) + ' -r')
        removePattern('histoOut-BP_*.root')
        print(dir_name, 'copied from runs')

    interval = int(arguments['events']) // arguments['parallel']

    processes = []
    for i in range(arguments['parallel']):
        cur_arguments = arguments
        cur_arguments['start'] = cur_arguments['start'] + interval * i
        cur_arguments['events'] = interval
        cur_arguments['inifile'] = os.path.join(temp_dir, 'temp_runs' + str(i), arguments['inifile'])
        p = multiprocessing.Process(target=singleAnalysis, args=(cur_arguments,))
        processes.append(p)
        p.start()
    for process in processes:
        process.join()
else:
    singleAnalysis(arguments)
print(time.time() - starttime)
os.system('rm temp -r')