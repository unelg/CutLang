from IPython.core.magic import (Magics, magics_class, cell_magic)
from IPython.core.magic_arguments import (argument, magic_arguments, parse_argstring)

@magics_class
class ShellMagics(Magics):
    @cell_magic
    @magic_arguments()
    def shell(self, line, cell):
        args = parse_argstring(self.shell, line)
        print(args, "shell kernel args")

def load_ipython_extension(ipython):
    ipython.register_magics(ShellMagics)
