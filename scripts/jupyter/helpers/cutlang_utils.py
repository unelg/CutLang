import os
from IPython import get_ipython
from IPython.core.extensions import ExtensionManager
from shutil import copyfile

def argMergerCLA(_args):
    args={"file": False, "filetype": False, "adlfile": "cutlang-adl-name", "events": False, "start": False, "verbose": False, "parallel": False}
    for arg in _args:
        argName=arg.split("=")[0]
        argVal=arg.split("=")[1]
        if argName=="adlfile":
            argName="adlfile"
        elif argName=="events":
            argName="events"
        elif argName=="start":
            argName="start"
        elif argName=="verbose":
            argName="verbose"
        elif argName=="parallel":
            argName="parallel"
        args[argName.replace("-", "")]=argVal
    return args

def run(display, HTML, code, _file, _filetype, _adlName, _extraArgs):
    tmpAdlName = "/tmp/" + _adlName + ".adl"
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
    print("Analysis for " + tmpAdlName)
    f = open(tmpAdlName, "a")
    f.write(code)
    f.close()
    print('RUNNING ->\n\tCLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs)
    print()
    display(HTML('<small style="color:red">please wait until the process is finished</small>'))
    print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    print()
    if(os.path.isfile(os.environ["CUTLANG_PATH"]+'/mybinder_true')):
        print(os.popen('CLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs).read())
    else:
        os.system('CLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs)
    os.remove(tmpAdlName)

    histoOutRoot=tmpAdlName.replace("/tmp/", "histoOut-").replace(".adl", ".root")
    copyfile(histoOutRoot, os.environ["CUTLANG_PATH"] + "/scripts/JsRoot620/jsroot/" + histoOutRoot)
    display(HTML('''
    <iframe width="700" height="400"
        src="http://127.0.0.1:8888/static/jsroot/index.htm?file=./{histoOutRoot}">
    </iframe>
    '''.format(histoOutRoot=histoOutRoot)))

def runCLA(display, HTML, code, args, files, adlfiles):
    if len(files) > 1:
        for i, file in enumerate(files):
            fileName=""
            if len(str(file).split(",")) > 1:
                for _file in str(file).split(","):
                    fileName = str(_file).split(".")[0]
            else:
                fileName = str(file).split(".")[0]
            adlName = adlfiles[0] + "-" + fileName
            if len(adlfiles) == len(files):
                #adlName = adlfiles[i] + "-" + fileName
                adlName = adlfiles[0] + "-" + fileName
            else:
                adlName = adlfiles[0] + "-" + fileName
            
            extraArgs=""

            filetypes=str(args["filetype"]).split(";")
            _filetype=""
            events=args["events"]
            start=args["start"]
            verbose=args["verbose"]
            parallel=args["parallel"]
            _filetype=filetypes[i] if len(filetypes) == len(files) else filetypes[0]

            if events != False:
                events=args["events"].split(";")
                if len(events) == len(files):
                    extraArgs=extraArgs+" -e "+str(events[i])
                else:
                    extraArgs+" -e "+str(events[0])

            if start != False:
                start=args["start"].split(";")
                if len(start) == len(files):
                    extraArgs=extraArgs+" -s "+str(start[i])
                else:
                    extraArgs+" -s "+str(start[0])

            if verbose != False:
                verbose=args["verbose"].split(";")
                if len(verbose) == len(files):
                    extraArgs=extraArgs+" -v "+str(verbose[i])
                else:
                    extraArgs+" -v "+str(verbose[0])

            if parallel != False:
                parallel=args["parallel"].split(";")
                if len(parallel) == len(files):
                    extraArgs=extraArgs+" -j "+str(parallel[i])
                else:
                    extraArgs=extraArgs+" -j "+str(parallel[0])
            run(display, HTML, code, file, _filetype, adlName, extraArgs)
    else:
        extraArgs=""

        filetypes=args["filetype"]
        _filetype=""
        events=args["events"]
        start=args["start"]
        verbose=args["verbose"]
        parallel=args["parallel"]
        if filetypes: _filetype=filetypes

        if events != False: extraArgs=extraArgs+" -e "+str(events)

        if start != False: extraArgs=extraArgs+" -s "+str(start)

        if verbose != False: extraArgs=extraArgs+" -v "+str(verbose)

        if parallel != False: extraArgs=extraArgs+" -j "+str(parallel)
        
        adlName = adlfiles[0] + "-" + files[0].split(".")[0]
        run(display, HTML, code, files[0], _filetype, adlName, extraArgs)


def welcomeMsg():
    print("with ROOT C++ with CutLang")
    
captures = []

def loadMagicsCLA():
    global captures
    extNames = ["JupyROOT.magics." + name for name in ["cutlangmagic"]]
    ip = get_ipython()
    extMgr = ExtensionManager(ip)
    for extName in extNames:
        extMgr.load_extension(extName)

    for capture in captures: capture.register()
def iPythonize():
    #setStyle()
    loadMagicsCLA()
    #loadMagicsAndCapturers()
    #declareProcessLineWrapper()
    ##enableCppHighlighting()
    #enhanceROOTModule()
    welcomeMsg()