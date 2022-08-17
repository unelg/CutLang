import re
import ROOT
from os import listdir
from os.path import exists,isfile
import numpy as np
import os
import sys


def in_root():    
    root_files = []
    for subdir, dirs, files in os.walk(d):
        # print(root_files)
        for f in files:
            if '.root' in f:
                r = 1
                msg = 'ROOT file found in '+os.path.join(subdir, f)+', use that? [Y/n]: '
                ok = input(msg)
                if not ok:
                    # rtype = input('Give the ROOT type: ')
                    rootinpath = os.path.join(subdir, f)
                    # root_files.append([fileinpath,rtype])
                    root_files.append(rootinpath)
                    # print(root_files)
                elif not ok in ['n','N','0']:
                    # rtype = input('Give the ROOT type: ')                    
                    rootinpath = os.path.join(subdir, f)
                    root_files.append(rootinpath)
                    # print(root_files)
    if r == 0:
        msg = 'ROOT file not found in folder, give a ROOT file: '
        rootinpath = input(msg)

    while not exists(rootinpath):
        msg = 'File not found! \nGive a ROOT file: '
        rootinpath = input(msg)
        if exists(rootinpath):
            # rtype = input('Give the ROOT type: ')
            root_files.append(rootinpath)
    print(root_files)
    return rootinpath,root_files


d = input('Give a model directory with all CLA files: ')

while not d:
    d = input('Give a model directory with all CLA files: ')
    
if not exists(d):
    msg = 'Results directory ('+d+') not found! Exiting.'
    print(msg)
    sys.exit()

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
if r == 0:
    msg = 'ADL file not found in folder, give an ADL file: '
    fileinpath = input(msg)
    if not exists(fileinpath):
        print('File not found! Nothing to be done. :( Exiting.')
        sys.exit()
        

# go through adl_files and idk ask what rootfile to run with them or go through the dir and run that as default

rootin,roots = in_root()

# print(rootin,roots)

oo = 0 # only one ROOT file used
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
else:
    msg = 'Multiple ROOT files found, use them all? [Y/n]: '
    ok = input(msg)
    if not ok:
        oo = 0
    if ok in ['N','n','False','F','f','0']:
        oo = 1
        msg = 'Which ROOT file to use for all ADL files? Give an index [0,'+str(len(roots)-1)+'] of '+str(roots)+': '
        whichroot = int(input(msg))
        rootin = roots[whichroot]
    else:
        oo = 0

if oo == 1:
    rtype = input('Give the ROOT type: ')
    for adl in adl_files:
        bashCmd = 'CLA '+rootin+' '+rtype+' -i '+adl
        print(bashCmd)
        os.system(bashCmd)
else:
    for adl in adl_files:
        msg = 'Which ROOT file to use for the ADL file '+str(adl)+'? Give an index [0,'+str(len(roots)-1)+'] of '+str(roots)+': '
        whichroot = int(input(msg))
        rootin = roots[whichroot]
        rtype = input('Give the ROOT type: ')
        bashCmd = 'CLA '+rootin+' '+rtype+' -i '+adl
        print(bashCmd)
        os.system(bashCmd)
        
#bashCommand = "cwm --rdf test.rdf --ntriples > test.nt"
#os.system(bashCommand)


