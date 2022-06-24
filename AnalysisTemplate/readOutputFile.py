from os.path import exists


### Read file

def read_file(filepath):
    if exists(filepath):
        file = open(filepath,'r')
        lines=file.readlines()
    else:
        print('File not found!')
        lines = []

    for line in lines:
        line.replace(' ','')
        line.replace('\n','')
    return lines

### Find type and subsample sizes

def find_typesize_samplesize(type_sample,lines):
    typesize = ''
    for line in lines:
        if type_sample in line:
            l = (line.rsplit('='))
            for s in l[1]:
                if s.isdigit():
                    typesize = typesize + str(s)
    if typesize == '':
        return 0
    else:
        return int(typesize)

### Find the value of given variable

def find_variable(typeId,variable,lines):
    v = ''
    for line in lines:
        if variable in line and typeId in line:
            l = (line.rsplit('= '))
            l[1].replace('\n','')
            l[1].replace(' ','')
            v = l[1]
    return v

### Read the number of types and subsamples from the file

def num_of_types_and_subs():
    typesize = find_typesize_samplesize('TYPESIZE',lines)
    samplesize = find_typesize_samplesize('SAMPLESIZE',lines)

### Read the numbers of signal, bg, and fixed samples and subsamples from the file

def num_of_sig_bg_sub(lines):
    linecounter = 0
    bgline = 0
    sigline = 0
    fixline = 0
    for line in lines:
        linecounter += 1
        if 'BACKGROUNDS' in line:
            bgline = linecounter
        elif 'SIGNALS' in line:
            sigline = linecounter
        elif 'FIXED TYPES' in line:
            fixline = linecounter
    nsig = 0
    nbg = 0
    nfix = 0
    nsubsig = 0
    nsubbg = 0
    nsubfix = 0

    sigs = []
    bgs = []
    fixs = []

    for line in lines[bgline:sigline]:
        if '-N =' in line:
            nbg += 1
            nsubbg_1 = 0
            bgs.append(nsubbg_1)
        if '-F =' in line:
            nsubbg += 1
            nsubbg_1 += 1
            bgs[(nbg-1)] = nsubbg_1

    for line in lines[sigline:fixline]:
        if '-N =' in line:
            nsig += 1
            nsubsig_1 = 0
            sigs.append(nsubsig_1)
        elif '-F =' in line:
            nsubsig += 1
            nsubsig_1 += 1
            sigs[(nsig-1)] = nsubsig_1
        
    for line in lines[fixline:]:
        if '-N =' in line:
            nfix += 1
            nsubfix_1 = 0
            fixs.append(nsubfix_1)
        elif '-F =' in line:
            nsubfix += 1
            nsubfix_1 += 0
            fixs[(nfix-1)] = nsubfix_1
        
    return nsig,sigs,nbg,bgs,nfix,fixs

### Get values for different variables

# typeId-2-Rmin = 21
# rmin_2 = find_variable('typeId-2','Rmin',lines)
# print(rmin_2)
