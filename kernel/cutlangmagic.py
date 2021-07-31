from IPython.core.magic import (Magics, magics_class, cell_magic)
from IPython.core.magic_arguments import (argument, magic_arguments, parse_argstring)

@magics_class
class CutLangMagics(Magics):
    @cell_magic
    @magic_arguments()
    @argument('file', action="store", help='Root file path')
    @argument('filetype', action="store", help='Root file type')
    
    @argument('i', 'inifile', action="store", help='HistoOut file name')
    @argument('e', 'events', action="store", help='Number of events')
    @argument('s', 'start', action="store", help='Starting event')
    @argument('h', 'help', action="store", help='Help')
    @argument('d', 'deps', action="store", help='DEPS')
    @argument('v', 'verbose', action="store", help='Verbose frequency')
    
    def cutlang(self, line, cell):
        args = parse_argstring(self.cutlang, line)
        print(args, "cutlang kernel args")

def load_ipython_extension(ipython):
    ipython.register_magics(CutLangMagics)
