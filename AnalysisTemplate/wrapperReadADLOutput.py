import numpy as np
from os.path import exists
import os

import readADLoutputCompare2
import inputSamples2
import outputANADEFS2

# Reads model directory. Asks for the dir name, if either the directory <input> or model_<input> is found, it's used.
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
        msg = 'Directory '+fol+' not found. Initialize new directory? [y]/n: ' # If not found, new one is initialized if prompted.
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
    # If output file already exists, permission to overwrite is asked.
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
    # Asks for output filename, default is compare.dat
    defoutput = 'compare.dat'
    msg = 'Give an output file (default '+defoutput+'): '
    outfname = input(msg)
    if outfname:
        outfname = if_outfile(outfname) # Checks if outfile already exists and if user wants to overwrite it.
    else:
        outfname = defoutput
        outfname = if_outfile(outfname)
    return outfname


d = model_dir()
# print(d)
readADLoutputCompare2.rADLoComp(d) # Reads ADL file in folder, outputs compare.dat
inputSamples2.inputsamples(d) # Asks user to input sample information, checks samples file in the given folder
outputANADEFS2.anadefs() # Asks user input for ANADEFS file
