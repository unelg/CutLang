from IPython.core.magic import (Magics, magics_class, cell_magic)
from IPython.core.magic_arguments import (argument, magic_arguments, parse_argstring)

@magics_class
class CutLangMagics(Magics):
    @cell_magic
    @magic_arguments()
    @argument('file', action="store", help='Root file path')
    @argument('filetype', action="store", help='Root file type')
    
    @argument('adl', 'adlfile', action="store", help='HistoOut file name')
    @argument('events', action="store", help='Number of events')
    @argument('start', action="store", help='Starting event')
    @argument('verbose', action="store", help='Verbose frequency')
    @argument('parallel', action="store", help='Number of cores')
    
    def cutlang(self, line, cell):
        args = parse_argstring(self.cutlang, line)
        print(args, "cutlang kernel args")

def load_ipython_extension(ipython):
    ipython.register_magics(CutLangMagics)
