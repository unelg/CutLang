from metakernel import Magic, option
from metakernel.display import HTML, display

class CutLangMagics(Magic):
    def __init__(self, kernel):
        super(CutLangMagics, self).__init__(kernel)
    @option('file', action="store", help='Root file path')
    @option('filetype', action="store", help='Root file type')
    @option('adlfile', action="store", help='HistoOut file name')
    @option('events', action="store", help='Number of events')
    @option('start', action="store", help='Starting event')
    @option('verbose', action="store", help='Verbose frequency')
    @option('parallel', action="store", help='Number of cores')

    def cell_cutlang(self, __args): # real
        _args = __args.split(" ")
        args = self.kernel.argMergerCLA(_args)
        
        if "file" not in args or "filetype" not in args:
            print("file and filetype flags are required")
            return

        if self.code.strip():
            files=args["file"].split(";")
            adlfiles=args["adlfile"].split(";")
            self.kernel.runCLA(display, HTML, self.code, args, files, adlfiles)
    
        self.evaluate = False

def register_magics(kernel):
    kernel.register_magics(CutLangMagics)
