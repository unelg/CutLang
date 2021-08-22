from IPython.core.magic import (Magics, magics_class, cell_magic)
from IPython.core.magic_arguments import (argument, magic_arguments, parse_argstring)

from JupyROOT.helpers import cutlang_utils

from IPython.display import display, HTML

@magics_class
class CutLangMagics(Magics):
    @cell_magic
    @magic_arguments()
    @argument('file', default=False, action="store", help='Root file path')
    @argument('filetype', default=False, action="store", help='Root file type')
    @argument('adlfile', default="cutlang-adl-name", action="store", help='HistoOut file name')
    @argument('events', default=False, action="store", help='Number of events')
    @argument('start', default=False, action="store", help='Starting event')
    @argument('verbose', default=False, action="store", help='Verbose frequency')
    @argument('parallel', default=False, action="store", help='Number of cores')
    def cutlang(self, line, cell):
        _args = line.split(" ")
        args = cutlang_utils.argMergerCLA(_args)
        
        if "file" not in args or "filetype" not in args:
            print("file and filetype flags are required")
            return

        if cell:
            files=args["file"].split(";")
            adlfiles=args["adlfile"].split(";")
            cutlang_utils.runCLA(display, HTML,cell, args, files, adlfiles)

def load_ipython_extension(ipython):
    ipython.register_magics(CutLangMagics)
