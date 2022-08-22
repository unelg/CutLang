import numpy as np
from os.path import exists
import os
import sys

# Asks if existing output file is to be overwritten.
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

# Asks for output file, default compare.dat    
def ask_outfile(d):
    defoutput = d+'/compare.dat'
    msg = 'Give an output compare.dat file (default '+defoutput+'): '
    outfname = input(msg)
    if outfname:
        outfname = if_outfile(outfname)
    else:        
        outfname = defoutput
        outfname = if_outfile(outfname)
    return outfname

# Goes through the given folder, looks if ADL files are found. If not, asks user to input the path.
def rADLoComp(d):
    r = 0
    for subdir, dirs, files in os.walk(d):
        for f in files:
            if '.adl' in f or '.ADL' in f:
                r = 1
                msg = 'ADL file found in '+os.path.join(subdir, f)+', use that? [Y/n]'
                ok = input(msg)
                if not ok:
                    fileinpath = os.path.join(subdir, f)
                if ok in ['n','N','0']:
                    fileinpath = input('Give an ADL file: ')
                    while not exists(fileinpath):
                        print('File not found!')
                        fileinpath = input('Give an ADL file: ') 
                else:
                    fileinpath = os.path.join(subdir, f)
    if r == 0:
        msg = 'ADL file not found in folder, give an ADL file: '
        fileinpath = input(msg)
        while not exists(fileinpath):
            print('File not found!')
            fileinpath = input('Give an ADL file: ') 
    infile = open(fileinpath,'r')
    lines=infile.readlines()
    infile.close()

    # Asks for output file.
    outfname = ask_outfile(d) #'VLL_compare.dat' 
    print('Writing to file',outfname)
    outf = open(outfname,'w')

    histos = []
    for line in lines:
        if 'histo' in line:
            hashornot = line.split('histo')
            if '#' not in hashornot[0]:
                line = line.replace(' ','')
                line = line.replace('\n','')
                line = line.replace('histo','')
                line = line.split(',')
                histos.append(line)

    numbers = np.arange(1,1+len(histos),1)
    for n in numbers:
        psetout = ' PSET'+str(n)+' = 1\n'
        muonout = ' MUON'+str(n)+' = '+histos[n-1][0]+'\n'
        eleout = ' ELE'+str(n)+' = '+histos[n-1][0]+'\n'
        rebinout = 'rebin'+str(n)+' = '+str(1)+'\n'
        if len(histos[n-1]) > 4:
            minmaxout = 'minmax'+str(n)+' = '+histos[n-1][3]+','+histos[n-1][4]+'\n'
            lineout = psetout+muonout+eleout+rebinout+minmaxout+'\n'
        else:
            lineout = psetout+muonout+eleout+rebinout+'\n'
        outf.write(lineout)
    outf.close()

    # Prints the number of histos written to file.
    if len(numbers)>0:
        msg = 'Printed histograms ['
        for n in numbers[:-1]:
            msg += str(n)+', '
        msg += str(numbers[-1])+'] to a file.'
        print(msg)
    else:
        'No histograms found!'
    return None


# To use the script without the wrapper. Asks for the model folder where the ADL file is.
def main():
    d = input("Input (model) directory with the ADL file: ")
    while not d:
        d = input("Input (model) directory with the ADL file: ")
    if not exists(d):
        print("Directory not found, exiting.")
        sys.exit()

    rADLoComp(d)
    
if __name__ == "__main__":
    main()
