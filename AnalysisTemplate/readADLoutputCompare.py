import numpy as np
from os.path import exists

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
        

fileinpath = '../../cern2022/VLL-2LOS.adl' #input('Give an ADL file: ') 
while not exists(fileinpath):
    print('File not found!')
    fileinpath = input('Give an ADL file: ') 
infile = open(fileinpath,'r')
lines=infile.readlines()
infile.close()

outfname = 'VLL_compare.dat' #ask_outfile()
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
    minmaxout = 'minmax'+str(n)+' = '+histos[n-1][3]+','+histos[n-1][4]+'\n'
    lineout = psetout+muonout+eleout+rebinout+minmaxout+'\n'
    outf.write(lineout)
outf.close()

msg = 'Printed histograms ['
for n in numbers[:-1]:
    msg += str(n)+', '
msg += str(numbers[-1])+'] to a file.'
print(msg)
