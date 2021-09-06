#!/usr/bin/env python3

import os
import sys
import glob
import platform
import concurrent.futures
import random


# noinspection PyShadowingBuiltins,PyShadowingNames
def help():
    for i in placeholders:
        for j in i:
            print(j, end=' ')
        print("")
    print('ROOT file type can be:')
    os.system('grep "inptype ==" ../CLA/CLA.C | cut -f3 -d\'=\' | cut -f1 -d\')\'')


SCRIPT=os.path.dirname(os.path.abspath(__file__))+"/CLA.py"         # /home/.../CutLang/runs/CLA.sh
RUNS_PATH=os.path.dirname(SCRIPT)                                   # /home/.../CutLang/runs
WORK_PATH=os.path.dirname(RUNS_PATH)                                # /home/.../CutLang

SHELL_ID = str(random.randint(0,10000))

# noinspection PyShadowingNames,SpellCheckingInspection
def removePattern(pattern):
    if type(pattern) is str:
        _pattern=arguments["chdir"]+"/"+pattern
        for i in glob.glob(_pattern):
            try:
                os.remove(i)
            except FileNotFoundError:
                pass
    elif type(pattern) is list:
        for i in pattern:
            _pattern=arguments["chdir"]+"/"+i
            try:
                os.remove(_pattern)
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
        os.system("cp " + arguments['inifile'] + " "+arguments["chdir"]+"/BP_1-card.ini")

    removePattern('histoOut-BP_*.root')
    #print(base_dir + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT')
    print(base_dir + 'CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
        algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
        arguments['start'])+ ' -HLT ' + str(HLTLIST))

    res = os.system('cd ' + arguments["chdir"] + ";" + base_dir + "scripts/CLApy_helper.sh " '"' + base_dir + 'CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
        algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
        arguments['start'])+ ' -HLT ' + str(HLTLIST) + '"')

    if res == 0:
        print('CutLang finished successfully, now adding histograms')
        try:
            os.remove(arguments["chdir"]+'/histoOut-' + arguments['inifile'].split('/')[-1][:-4] + '.root')
        except FileNotFoundError:
            pass
        if histoId is not None:
            hadd_query = 'hadd -f '+arguments["chdir"]+'/histoOut-' + arguments['inifile'].split('/')[-1][:-4] + str(histoId) + '.root'
        else:
            hadd_query = 'hadd -f '+arguments["chdir"]+'/histoOut-' + arguments['inifile'].split('/')[-1][:-4] + '.root'
        for i in glob.glob(arguments["chdir"]+'/histoOut-BP_*.root'):
            hadd_query += " " + i
        res = os.system(hadd_query)
        if res == 0:
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
             'start': 0,
             'chdir': "."}
POSITIONAL = ()

for i, arg in enumerate(sys.argv[3::2]):
    if arg in placeholders[3]:
        print("command line arguments:")
        help()
        sys.exit(1)
    else:
        for a in placeholders:
            if arg in a:
                arguments[a[1][2:]] = sys.argv[i * 2 + 4]



# for histoList command
f = open(arguments["inifile"], 'r')
Lines = f.readlines()
newLines = ""
histoLists = {}
histoListControl = False
for linenumber, line in enumerate(Lines):
    if histoListControl != False and (line.strip() == "" or "histoList" in line): # if histoListControl is defined and does not belong to the relevant histolist
        histoListControl = False
    elif histoListControl != False: # if histoListControl is defined, append line and count to 0
        histoLists[histoListControl].append(line)
        histoLists[histoListControl+"_count"] = 0
    if histoListControl == False and "histoList" not in line and line[0] != "#": # if histoListControl is not defined and is not comment line or histoList line
        newLines += line
    
    for histo in histoLists: # histoLists for loop: fills histo definitions using counter
        if line.strip() == histo and line[0] != "#":
            newLines = "\n".join(newLines.split("\n")[:-2])+"\n"
            for linenumber, line in enumerate(histoLists[histo]):
                lineSplit = list(filter(None, line.split(" ")))
                if histoLists[histo+"_count"] != 0:
                    lineSplit[1] = lineSplit[1][:-1]
                    histoLists[histo][linenumber] = "histo " + lineSplit[1] + str(histoLists[histo+"_count"]) + line.replace("histo", "").replace(lineSplit[1]+str(histoLists[histo+"_count"]-1), "")
                else:
                    histoLists[histo][linenumber] = "histo " + lineSplit[1] + str(histoLists[histo+"_count"]) + line.replace("histo", "").replace(lineSplit[1], "")
            newLines += "\n".join(histoLists[histo])
            histoLists[histo+"_count"] = int(histoLists[histo+"_count"]) + 1

    if "histoList" in line:
        histoListName = line.split(" ")[1].strip()
        histoLists[histoListName] = []
        histoListControl = histoListName

arguments["inifile"] += ".tmp"
f = open(arguments["inifile"], "w+")
f.write(newLines)
f.close()
f = open(arguments["inifile"], 'r')


# for select HLT command
hltInFile=os.popen(''' grep -E "select HLT" '''+arguments["inifile"]+''' | sed 's/select HLT//g' ''').read()
hltList=""
for i in hltInFile.replace("||", " ").replace("'", " ").replace('"'," ").split():
    hltList+=i+","
HLTLIST=hltList

arguments['parallel'] = int(arguments['parallel']) // 1
if not os.path.exists(arguments['datafile']):
    sys.exit(arguments['datafile'] + " does not exist.")

algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
n_cpu = os.cpu_count()
#base_dir = os.path.dirname(os.path.abspath(__file__))[:-4]
base_dir = WORK_PATH + "/"

if arguments['parallel'] > n_cpu or arguments['parallel'] == 0:
    arguments['parallel'] = n_cpu - 1

if arguments['parallel'] > 1:
    # skip_count = getStringCount(arguments['inifile'], ['SkipHistos', 'SkipEffs'])
    skip_histos = getStringCount(arguments['inifile'], 'SkipHistos')
    skip_effs = getStringCount(arguments['inifile'], 'SkipEffs')
    print("Using", arguments['parallel'], "cores")
    intrvl=False
    if int(arguments['events']) == 0:
        hltInFile=os.popen(''' grep -E "select HLT" '''+arguments["inifile"]+''' | sed 's/select HLT//g' ''').read()

        dt=os.popen(''' grep "'''+arguments["datatype"]+'''" '''+base_dir+'''CLA/CLA.C | cut -d '{' -f 2 | head -c -9 | cut -c 2- | grep true; ''').read().split(" ")[0]
        chn=os.popen(''' grep -A2 "if ('''+dt+''')" '''+base_dir+'''CLA/CLA.C | grep "TChain(" | cut -d '"' -f 2 ''').read().split()[0]
        TotalEvents=os.popen(''' root -l -q \''''+base_dir+'''analysis_core/getentries.cxx("'''+arguments["datafile"]+'''" ,"'''+chn+'''")' ''').read().split()[-1]
        EVENTS=os.popen(''' echo '''+TotalEvents+''' | awk '{print $NF}' ''').read().split()[0]
        print("Total number of events: " + EVENTS)
        arguments['events'] = EVENTS
        intrvl=int(arguments['events']) // arguments['parallel']
    print("*" * 100,
          base_dir + 'CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -PLL ${PRLL}',
          sep='\n')

    temp_dir = base_dir+'temp_runs_'+SHELL_ID
    temp_adl_dir = base_dir+'temp_adl_'+SHELL_ID
    os.mkdir(temp_adl_dir)
    os.system('cp ' + arguments['inifile'] + " " + temp_adl_dir + "/tempor.adl")
    for i in range(arguments['parallel']):
        dir_name = temp_dir + "_" + str(i)
        os.mkdir(dir_name)
        os.system('cp -a ' + base_dir + 'runs/. ' + dir_name)
        # Copied {runs, CLA, analysis_core, BP}
        removePattern('histoOut-BP_*.root')
        print(dir_name, 'copied from runs')

    res=os.popen('grep -i "SkipEffs" '+temp_adl_dir + "/tempor.adl").read().split("=")[0]
    if not res:
        os.system(''' sed -i '/SkipEffs/Id' '''+base_dir+'''temp_adl_'''+SHELL_ID+'''/tempor.adl ''')
    os.system(''' ex -sc '1i|SkipEffs = 1' -cx '''+base_dir+'''temp_adl_'''+SHELL_ID+'''/tempor.adl ''')
    
    interval = intrvl if intrvl else int(arguments['events']) // arguments['parallel']
    processes = []
    for i in range(arguments['parallel']):
        cur_arguments = arguments.copy()
        cur_arguments['start'] = cur_arguments['start'] + interval * i
        cur_arguments['events'] = interval
        if i + 1 == arguments['parallel']:
            cur_arguments['events'] += int(arguments['events']) % interval
        cur_arguments['inifile'] = temp_adl_dir + "/" + "tempor.adl"
        cur_arguments['chdir'] = temp_dir + "_" + str(i)
        cur_arguments['datafile'] = os.path.realpath(arguments['datafile'])
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

    allHistos=""
    for i in range(arguments['parallel']):
        allHistos=allHistos + temp_dir + "_" + str(i) + "/" + "histoOut-tempor.root "
    res = os.system(
        'hadd -f histoOut-' + arguments['inifile'] + '.root ' + allHistos)
    print("removing auxiliary files")
    if res == 0:
        os.system('root -l -q \'' + base_dir + 'analysis_core/FinalEff.C("' + './histoOut-' + arguments[
            'inifile'] + '.root", \'' + str(skip_histos) + '\', \'' + str(skip_effs) + '\')\'')
    removePattern('histoOut-BP_*.root')
    removePattern(['_head.ini', '_algos.ini', '_inifile'])
    removePattern('BP_*-card.ini')
    os.system('rm -r '+base_dir+'temp*')
else:
    singleAnalysis(arguments)
