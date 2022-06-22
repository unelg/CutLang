import numpy as np
from os.path import exists

def value_error_f(t,val):
    try:
        t(val)
        return True
    except ValueError:
        return False

outfname = input('Give an output file path: ')

if exists(outfname):
    outf = open(outfname,'w')
else:
    print('File does not exist, using default samples.txt')
    outf = open('samples.txt','w')

subsoutfname = input('Give a subsample cross-section file path: ')
if exists(subsoutfname):
    subsoutf = open(subsoutfname,'w')
else:
    print('File does not exist, using default xsections.txt')    
    subsoutf = open('xsections.txt','w')

modeln = input('Name of the model: ')
nsig = input('Number of signal samples (default 1): ')
try:
    int(nsig)
except ValueError:
    nsig = 1

nbg = input('Number of background samples (default 0): ')
try:
    int(nbg)
except ValueError:
    nbg = 0

nsig = int(nsig)
nbg = int(nbg)

typesize = nsig + nbg + 5
samplesize = 0

def variables_type():
    name = input('Name of type: ')
    while not name:
        name = input('Name has to have a value: ')
        #name = 'name'

    nsubsamples = input('Number of subsamples (default 1): ')
        
    try:
        int(nsubsamples)
    except ValueError:
        nsubsamples = 1
    nsubsamples = int(nsubsamples)
    
    drawable = input('Drawable (T/F, default T): ')
    if drawable == 'T' or drawable == 't' or drawable == 'True' or drawable == 'true' or drawable == 'TRUE' or drawable == '1': drawable = 1
    elif drawable == 'F' or drawable == 'f' or drawable == 'False' or drawable == 'false' or drawable == 'FALSE' or drawable == '0': drawable = 0
    else: drawable = 1

    style = input('Style (default b1): ')
    if style:
        style = style
    else:
        style = 'b1'
    return name,nsubsamples,drawable,style

def variables_subsamples():

    name = input('Name of subsample type: ')
    while not name:
        name = input('Name has to have a value: ')
        #name='subsample'
        
    dsid = input('DSID (int): ')
    while value_error_f(int,dsid) == False:
        dsid = input('DSID (int): ')
        #dsid=1
    dsid = int(dsid)
    
    cs = input('Cross-section (float): ')
    while value_error_f(float,cs) == False:
        cs = input('Cross-section (float): ')
        #cs =1
    cs = float(cs)
    
    weight = input('Weight (float, def 1): ')
    try:
        float(weight)
    except ValueError:
        weight = 1 #input('Weight (float, def 1): ')
    weight = float(weight)

    return name,dsid,cs,weight
    

signals = []
for i in range(nsig):
    print('########### SIGNALS ###########')
    print('Signal number',i+1)
    sig_i = variables_type()
    samplesize += sig_i[1]
    subs = []
    for subi in range(sig_i[1]):
        print('--------SIGNAL SUBSAMPLES--------')
        print('Signal number',i+1, ', subsample number',subi+1)
        sub_i = variables_subsamples()
        subs.append([sub_i[0]] + [sub_i[1]] + [sub_i[2]] + [sub_i[3]])
    signals.append([sig_i[0]] + [subs] + [sig_i[2]] + [sig_i[3]])

bgs = []
for i in range(nbg):
    print('########### BACKGROUNDS ###########')
    print('Background number',i+1)
    bgs_i = variables_type()
    samplesize += bgs_i[1]
    subs = []
    for subi in range(bgs_i[1]):
        print('--------BACKGROUND SUBSAMPLES--------')
        print('BG number',i+1, ', subsample number',subi+1)
        sub_i = variables_subsamples()
        subs.append([sub_i[0]] + [sub_i[1]] + [sub_i[2]] + [sub_i[3]])
    bgs.append([bgs_i[0]] + [subs] + [bgs_i[2]] + [bgs_i[3]])


outf.write('MODEL NAME = '+modeln+'\n')
outf.write('TYPESIZE = '+str(typesize)+'\n')
outf.write('SAMPLESIZE = '+str(samplesize)+'\n\n')

fixed = [0,1] 
fixed_n = ['data','smbg','QCD','signal+smbg','QCDunc']
fixed_draw = [1,0,0,0,1]
fixed_style = ['e1','b1','b1','b1','e4']
fixed_R = ['',['2','-3'],'',['2','-2'],'']
bg = np.arange(2,2+nbg)
signal = np.arange(nbg+2,nbg+2+nsig)
fixed = fixed + [2+nsig+nbg] + [3+nsig+nbg] + [4+nsig+nbg]

#### PRINT BGS

outf.write('\n## BACKGROUNDS ##\n')
subsoutf.write('\n## BACKGROUNDS ##\n')

if len(bgs) == 0:
    outf.write('\n# No background given!\n')
else:
    for i in range(len(bgs)):
        if len(bgs[i][1]) == 0:
            outf.write('\ntypeId-'+str(bg[i])+'-N = '+bgs[i][0]+'\n')
            outf.write('typeId-'+str(bg[i])+'-Drawable = '+str(bgs[i][2])+'\n')
            outf.write('typeId-'+str(bg[i])+'-Style = '+bgs[i][3]+'\n\n')
        else:
            R = []
            for j in range(len(bgs[i][1])):
                R.append(str(bg[i])+str(j+1))
            outf.write('\ntypeId-'+str(bg[i])+'-N = '+bgs[i][0]+'\n')
            outf.write('typeId-'+str(bg[i])+'-Rmin = '+R[0]+'\n')
            outf.write('typeId-'+str(bg[i])+'-Rmax = '+R[-1]+'\n')        
            outf.write('typeId-'+str(bg[i])+'-Drawable = '+str(bgs[i][2])+'\n')
            outf.write('typeId-'+str(bg[i])+'-Style = '+bgs[i][3]+'\n\n')

        if len(bgs[i][1]) == 0:
            outf.write('\n# No subsamples input for given BG!\n')
            subsoutf.write('\n# No subsamples input for given BG!\n')
        else:
            for j in range(len(bgs[i][1])):
                outf.write('sampleId-'+str(bg[i])+str(j+1)+'-F = '+str(bgs[i][1][j][1])+'\n')
                subsoutf.write('\nsampleId-'+str(bg[i])+str(j+1)+'-F = '+str(bgs[i][1][j][1])+'\n')
                subsoutf.write('typeId-'+str(bg[i])+str(j+1)+'-CS = '+str(bgs[i][1][j][2])+'\n')

#### PRINT SIGS

outf.write('\n## SIGNALS ##\n')
subsoutf.write('\n## SIGNALS ##\n')
if len(signals) == 0:
    outf.write('\n# No signals given!\n')
else:
    for i in range(len(signals)):
        if len(signals[i][1]) == 0:
            outf.write('\ntypeId-'+str(signal[i])+'-N = '+signals[i][0]+'\n')
            outf.write('typeId-'+str(signal[i])+'-Drawable = '+str(signals[i][2])+'\n')
            outf.write('typeId-'+str(signal[i])+'-Style = '+signals[i][3]+'\n\n')
        else:
            R = []
            for j in range(len(signals[i][1])):
                R.append(str(signal[i])+str(j+1))
            outf.write('\ntypeId-'+str(signal[i])+'-N = '+signals[i][0]+'\n')
            outf.write('typeId-'+str(signal[i])+'-Rmin = '+R[0]+'\n')
            outf.write('typeId-'+str(signal[i])+'-Rmax = '+R[-1]+'\n')        
            outf.write('typeId-'+str(signal[i])+'-Drawable = '+str(signals[i][2])+'\n')
            outf.write('typeId-'+str(signal[i])+'-Style = '+signals[i][3]+'\n\n')

        if len(signals[i][1]) == 0:
            outf.write('\n# No subsamples input for given signal!\n')
            subsoutf.write('\n# No subsamples input for given signal!\n')            
        else:
            for j in range(len(signals[i][1])):
                outf.write('sampleId-'+str(signal[i])+str(j+1)+'-F = '+str(signals[i][1][j][1])+'\n')
                subsoutf.write('\nsampleId-'+str(signal[i])+str(j+1)+'-F = '+str(signals[i][1][j][1])+'\n')
                subsoutf.write('typeId-'+str(signal[i])+str(j+1)+'-CS = '+str(signals[i][1][j][2])+'\n')

        
outf.write('\n## FIXED TYPES ##\n')
for i in range(len(fixed)):
    outf.write('\ntypeId-'+str(fixed[i])+'-N = '+fixed_n[i]+'\n')
    if isinstance(fixed_R[i],list):
        outf.write('typeId-'+str(fixed[i])+'-Rmin = '+fixed_R[i][0]+'\n')
        outf.write('typeId-'+str(fixed[i])+'-Rmax = '+fixed_R[i][1]+'\n')
    outf.write('typeId-'+str(fixed[i])+'-Drawable = '+str(fixed_draw[i])+'\n')
    outf.write('typeId-'+str(fixed[i])+'-Style = '+fixed_style[i]+'\n\n')

outf.close()
subsoutf.close()
