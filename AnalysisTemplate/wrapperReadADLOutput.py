import numpy as np
from os.path import exists
import os

import readADLoutputCompare2
import inputSamples2
import outputANADEFS2

def model_dir():
    msg = 'Input model (directory) name: '
    fol = input(msg)
    r = 1
    if exists(fol):
        msg = 'Using directory '+fol+'.'
        print(msg)
    elif exists('model_'+fol):
        fol = 'model_'+fol
        msg = 'Using directory '+fol+'.'
        print(msg)
    else:
        msg = 'Directory '+fol+' not found. Initialize new directory? [y]/n: '
        ok = input(msg)
        if not ok:
            os.mkdir(fol)
        elif ok in ['n','N','0']:
            msg = 'Directory not found or initialized, aborting.'
            print(msg)
            exit()
        else:
            os.mkdir(fol)
    return fol
        
def if_outfile(outfname):
    if exists(outfname):
            msg = 'Overwrite file '+outfname+'? [Y/n]: '
            ok = input(msg)
            if not ok:
                return outfname
            else:
                if ok in ['Y','y']:
                    return outfname
                else:
                    outfname = ask_outfile()
                    return outfname
    else:
        return outfname

def ask_outfile():
    defoutput = 'compare.dat'
    msg = 'Give an output file (default '+defoutput+'): '
    outfname = input(msg)
    if outfname:
        outfname = if_outfile(outfname)
    else:
        outfname = defoutput
        outfname = if_outfile(outfname)
    return outfname


d = model_dir()
print(d)
readADLoutputCompare2.main(d)
inputSamples2.main(d)
outputANADEFS2.main()
