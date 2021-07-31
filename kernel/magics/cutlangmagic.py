from metakernel import Magic, option

import os
import subprocess as sp

class CutLangMagics(Magic):
    def __init__(self, kernel):
        super(CutLangMagics, self).__init__(kernel)
    @option('file', action="store", help='Root file path')
    @option('filetype', action="store", help='Root file type')
    
    @option('i', 'inifile', action="store", help='HistoOut file name')
    @option('e', 'events', type=int, action="store", help='Number of events')
    @option('s', 'start', type=int, action="store", help='Starting event')
    @option('h', 'help', action="store_true", help='Help')
    @option('d', 'deps', action="store", help='DEPS')
    @option('v', 'verbose', type=int, action="store", help='Verbose frequency')

    def cell_cutlang(self, __args): # real
        _args = __args.split(" ")
        args = {"file": "", "filetype": "", "inifile": "cutlang-adl-name", "events": 0, "start": 0, "help": False, "deps": " ", "verbose": 0}
        extraArgs = ""
        for arg in _args:
            argName=arg.split("=")[0]
            argVal=arg.split("=")[1]
            if argName=="i" or argName=="inifile":
                argName="inifile"
            elif argName=="e" or argName=="events":
                argName="events"
                extraArgs+=" -e "+str(argVal)
            elif argName=="s" or argName=="start":
                argName="start"
                extraArgs+=" -s "+str(argVal)
            elif argName=="h" or argName=="help":
                argName="help"
                extraArgs+=" -h "
            elif argName=="d" or argName=="deps":
                argName="deps"
                extraArgs+=" -d "+str(argVal)
            elif argName=="v" or argName=="verbose":
                argName="verbose"
                extraArgs+=" -v "+str(argVal)
            args[argName.replace("-", "")]=argVal
        if self.code.strip():
            PWD = sp.getoutput('pwd')
            adlName = args["inifile"] + ".adl"
            print("/tmp/" + adlName)
            f = open("/tmp/" +adlName, "a")
            f.write(self.code)
            f.close()
            print(PWD, "pwd", 'CLA ' + PWD + "/" + args["file"] + ' ' + args["filetype"] + ' -i ' + "/tmp/" + adlName + extraArgs)
            if(os.path.isfile(os.environ["CUTLANG_PATH"]+'/mybinder_true')):
                print(os.popen('CLA ' + PWD + "/" + args["file"] + ' ' + args["filetype"] + ' -i ' + "/tmp/" + adlName + extraArgs).read())
            else:
                os.system('CLA ' + PWD + "/" + args["file"] + ' ' + args["filetype"] + ' -i ' + "/tmp/" + adlName + extraArgs)
            os.remove("/tmp/" + adlName)
        self.evaluate = False

def register_magics(kernel):
    kernel.register_magics(CutLangMagics)
