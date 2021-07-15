from metakernel import Magic, option

import os
import subprocess as sp

class CutLangMagics(Magic):
    def __init__(self, kernel):
        super(CutLangMagics, self).__init__(kernel)
    @option('file', action="store", help='Root file path')
    @option('filetype', action="store", help='Root file type')
    @option('name', action="store", help='HistoOut file name')
    def cell_cutlang(self, __args): # real
        _args = __args.split(" ")
        args = {"file": "", "filetype": "", "name": ""}
        for arg in _args:
            args[arg.split("=")[0].replace("-", "")]=arg.split("=")[1]
        if self.code.strip():
            PWD = sp.getoutput('pwd')
            f = open("/tmp/" + args["name"], "a")
            f.write(self.code)
            f.close()
            print(PWD, "pwd", 'CLA ' + PWD + "/" + args["file"] + ' ' + args["filetype"] + ' -i ' + tf.name)
            os.system('CLA ' + PWD + "/" + args["file"] + ' ' + args["filetype"] + ' -i ' + tf.name)
        self.evaluate = False

def register_magics(kernel):
    kernel.register_magics(CutLangMagics)
