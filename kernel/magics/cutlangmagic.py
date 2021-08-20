from metakernel import Magic, option

import os
import subprocess as sp

class CutLangMagics(Magic):
    def __init__(self, kernel):
        super(CutLangMagics, self).__init__(kernel)
    @option('file', action="store", help='Root file path')
    @option('filetype', action="store", help='Root file type')
    
    @option('adl', 'adlfile', action="store", help='HistoOut file name')
    @option('events', action="store", help='Number of events')
    @option('start', action="store", help='Starting event')
    @option('verbose', action="store", help='Verbose frequency')
    @option('parallel', action="store", help='Number of cores')

    def cell_cutlang(self, __args): # real
        _args = __args.split(" ")
        args = {"file": False, "filetype": False, "adlfile": "cutlang-adl-name", "events": False, "start": False, "verbose": False, "parallel": False}
        for arg in _args:
            argName=arg.split("=")[0]
            argVal=arg.split("=")[1]
            if argName=="adl" or argName=="adlfile":
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
        if "file" not in args or "filetype" not in args:
            print("file and filetype flags are required")
            return
        if self.code.strip():
            files=args["file"].split(";")
            adlfiles=args["adlfile"].split(";")
            def runCLA(_file, _filetype, _adlName, _extraArgs):
                tmpAdlName = "/tmp/" + _adlName + ".adl"
                print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n")
                print("Analysis for " + tmpAdlName)
                f = open(tmpAdlName, "a")
                f.write(self.code)
                f.close()
                print('RUN -> CLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs)
                print("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                if(os.path.isfile(os.environ["CUTLANG_PATH"]+'/mybinder_true')):
                    print(os.popen('CLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs).read())
                else:
                    os.system('CLA ' + _file + ' ' + _filetype + ' -i ' + tmpAdlName + _extraArgs)
                os.remove(tmpAdlName)
            if len(files) > 1:
                for i, file in enumerate(files):
                    fileName=""
                    if len(file.split(",")) > 1:
                        for _file in file.split(","):
                            fileName = _file.split(".")[0]
                    else:
                        fileName = file.split(".")[0]
                    adlName = adlfiles[0] + "-" + fileName
                    if len(adlfiles) == len(files):
                        #adlName = adlfiles[i] + "-" + fileName
                        adlName = adlfiles[0] + "-" + fileName
                    else:
                        adlName = adlfiles[0] + "-" + fileName
                    
                    extraArgs=""

                    filetypes=args["filetype"].split(";")
                    _filetype=""
                    events=args["events"].split(";")
                    start=args["start"].split(";")
                    verbose=args["verbose"].split(";")
                    parallel=args["parallel"].split(";")
                    _filetype=filetypes[i] if len(filetypes) == len(files) else filetypes[0]

                    if events != False:
                        if len(events) == len(files):
                            extraArgs=extraArgs+" -e "+str(events[i])
                        else:
                            extraArgs+" -e "+str(events[0])

                    if start != False:
                        if len(start) == len(files):
                            extraArgs=extraArgs+" -s "+str(start[i])
                        else:
                            extraArgs+" -s "+str(start[0])

                    if verbose != False:
                        if len(verbose) == len(files):
                            extraArgs=extraArgs+" -v "+str(verbose[i])
                        else:
                            extraArgs+" -v "+str(verbose[0])

                    if parallel != False:
                        if len(parallel) == len(files):
                            extraArgs=extraArgs+" -j "+str(parallel[i])
                        else:
                            extraArgs=extraArgs+" -j "+str(parallel[0])
                    runCLA(file, _filetype, adlName, extraArgs)
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
                runCLA(files[0], _filetype, adlName, extraArgs)
        self.evaluate = False

def register_magics(kernel):
    kernel.register_magics(CutLangMagics)
