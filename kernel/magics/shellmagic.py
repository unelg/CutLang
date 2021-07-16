from metakernel import Magic, option

import os
import subprocess as sp

class ShellMagics(Magic):
    def __init__(self, kernel):
        super(ShellMagics, self).__init__(kernel)
    def cell_shell(self, __args): # real
        for line in self.code.split("\\n"):
            os.system(line)
            

def register_magics(kernel):
    kernel.register_magics(ShellMagics)
