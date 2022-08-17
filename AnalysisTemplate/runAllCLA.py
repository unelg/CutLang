import re
import ROOT
from os import listdir
from os.path import exists,isfile
import numpy as np
import os
import sys


def in_root():
    # Goes through the directory, checks if user wants to use the ROOT files
    root_files = []
    for subdir, dirs, files in os.walk(d):
        for f in files:
            if '.root' in f:
                r = 1
                msg = 'ROOT file found in '+os.path.join(subdir, f)+', use that? [Y/n]: '
                ok = input(msg)
                if not ok:
                    rootinpath = os.path.join(subdir, f)
                    root_files.append(rootinpath)
                elif not ok in ['n','N','0']:
                    rootinpath = os.path.join(subdir, f)
                    root_files.append(rootinpath)
    # If ROOT file is not found in dir, the path must be given.
    if r == 0:
        msg = 'ROOT file not found in folder, give a ROOT file: '
        rootinpath = input(msg)

    # Checks if exists, does not stop until existing ROOT file is given.
    while not exists(rootinpath):
        msg = 'File not found! \nGive a ROOT file: '
        rootinpath = input(msg)
        if exists(rootinpath):
            root_files.append(rootinpath)
    return rootinpath,root_files


# Prompts until a directory is given, exits if not found.
d = input('Give a model directory with all CLA files: ')
while not d:
    d = input('Give a model directory with all CLA files: ')
if not exists(d):
    msg = 'Results directory ('+d+') not found! Exiting.'
    print(msg)
    sys.exit()

# Goes through all ADL files in the folder, asks if user wants to use them.     
adl_files = []
r = 0
for subdir, dirs, files in os.walk(d):
    for f in files:
        if '.adl' in f or '.ADL' in f:
            r = 1
            msg = 'ADL file found in '+os.path.join(subdir, f)+', use that? [Y/n]: '
            ok = input(msg)
            if not ok:
                fileinpath = os.path.join(subdir, f)
                adl_files.append(fileinpath)
            elif not ok in ['n','N','0']:
                fileinpath = os.path.join(subdir, f)
                adl_files.append(fileinpath)
                
# If not found in the folder, asks user for the path, and if not found, exits.                
if r == 0:
    msg = 'ADL file not found in folder, give an ADL file: '
    fileinpath = input(msg)
    if not exists(fileinpath):
        print('File not found! Nothing to be done. :( Exiting.')
        sys.exit()
        

# Gets the list of ROOT files.
rootin,roots = in_root()

oo = 0 # 1 = only one ROOT file used, 0 = multiple ROOT files

# If using only one ROOT file, asks if thats used for all files.
# (If not, that doesn't really change anything at this point, as ATM user cannot add new ROOT files in the middle of the script running.)
if len(roots) == 1:
    msg = 'Only one ROOT file given, use that for all ADL files? [Y/n]: '
    ok = input(msg)
    if not ok:
        oo = 1
        rtype = roots[0][1]
    if ok in ['N','n','False','F','f','0']:
        oo = 0
    else:
        oo = 1
        rtype = roots[0][1]
# If using multiple ROOT files, user can choose to use only one for all ADL scripts, or choose a ROOT file for each script.
else:
    msg = 'Multiple ROOT files found, use them all? [Y/n]: '
    ok = input(msg)
    if not ok:
        oo = 0
    if ok in ['N','n','False','F','f','0']:
        oo = 1
        msg = 'Which ROOT file to use for all ADL files? Give an index 0-'+str(len(roots)-1)+' of '+str(roots)+': '
        whichroot = int(input(msg))
        rootin = roots[whichroot]
    else:
        oo = 0

# If only one ROOT file, the type is input only once and the ADL files are all run with it.        
if oo == 1:
    rtype = input('Give the ROOT type: ')
    for adl in adl_files:
        bashCmd = 'CLA '+rootin+' '+rtype+' -i '+adl
        print(bashCmd)
        os.system(bashCmd) # Runs the bash command: CLA <rootfile> <rootfile type> -i <adlfile>
        
# If multiple ROOT files, the file and type must be given for each ADL file.        
else:
    for adl in adl_files:
        msg = 'Which ROOT file to use for the ADL file '+str(adl)+'? Give an index 0-'+str(len(roots)-1)+' of '+str(roots)+': '
        whichroot = int(input(msg))
        rootin = roots[whichroot]
        rtype = input('Give the ROOT type: ')
        bashCmd = 'CLA '+rootin+' '+rtype+' -i '+adl
        print(bashCmd)
        os.system(bashCmd) # Runs the bash command: CLA <rootfile> <rootfile type> -i <adlfile> 
        


