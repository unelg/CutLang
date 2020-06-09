import os
import sys
import glob


# noinspection PyShadowingBuiltins
def help():
    for i in placeholders:
        for j in i:
            print(j, end=' ')
        print("")
    os.system('echo "ROOT file type can be:"; grep "inptype ==" ../CLA/CLA.C | cut -f3 -d\'=\' | cut -f1 -d\')\'')


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
            if query in line and '#' not in line:
                print(line)
                n += 1
    elif type(query) is list:
        for line in open(filename).readlines():
            for single_query in query:
                if single_query in line and '#' not in line:
                    n += 1
    return n


placeholders = [
    ["-i", "--inifile"],
    ["-e", "--events"],
    ["-s", "--start"],
    ["-h", "--help"],
    ["-v", "--verbose"]]

if len(sys.argv) < 2:
    print("ERROR: Not enough arguments")
    help()
    sys.exit(1)

arguments = {'inifile': "CLA.ini",
             'datafile': sys.argv[1],
             'datatype': sys.argv[2],
             'verbose': 5000,
             'events': 0,
             'strt': 0}
POSITIONAL = ()

for i, arg in enumerate(sys.argv[3::2]):
    if arg in placeholders[3]:
        print("command line arguments:")
        help()
        sys.exit(1)
    elif arg in placeholders[i]:
        arguments[placeholders[i][1][2:]] = sys.argv[i * 2 + 4]

if not os.path.exists(arguments['datafile']):
    sys.exit(arguments['datafile'] + " does not exist.")

algorithm_count = getStringCount(arguments['inifile'], ['region', 'algo'])
print(algorithm_count)
if algorithm_count > 1:
    print("Analysis with Multiple Regions")
    os.system("../scripts/separate_algos.sh " + arguments['inifile'])
else:
    print("Single Analysis")
    os.system("cp " + arguments['inifile'] + " BP_1-card.ini")

removePattern('histoOut-BP_*.root')
print(r'../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT')
res = os.system('export PATH=$PATH:$ROOTSYS/bin ;\
           export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:../CLA/ ;\
           ../CLA/CLA.exe ' + arguments['datafile'] + ' -inp ' + arguments['datatype'] + ' -BP ' + str(
    algorithm_count) + ' -EVT ' + str(arguments['events']) + ' -V ' + str(arguments['verbose']) + ' -ST ' + str(
    arguments['strt']))

if res == 0:
    print('CutLang finished successfully, now adding histograms')
    try:
        os.remove('histoOut-' + arguments['inifile'][:-4] + '.root')
    except FileNotFoundError:
        pass
    hadd_query = 'hadd histoOut-' + arguments['inifile'][:-4] + '.root'
    for i in glob.glob('histoOut-BP_*.root'):
        hadd_query += " " + i
    res = os.system(hadd_query)
    if res == 120:
        print("hadd finished successfully, now removing auxiliary files")
        removePattern('histoOut-BP_*.root')
        removePattern(['_head.ini', '_algos.ini', '_inifile'])
        removePattern('BP_*-card.ini')
