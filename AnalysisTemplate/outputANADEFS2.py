from os.path import exists
import sys
import os

# Ask input for a given variable.
def ask_input(d,variable,prompt):
    # msg = 'Input '+variable+': '
    if variable == 'MODEL':
        value = d
    else:
        value = input(prompt)
    msg = variable+' = '+str(value)
    print(msg)
    return variable,value

# Ask for output file.
def ask_output(d):
    # msg = 'Give an output ANA_DEFS file: '
    # outfn = input(msg)
    # if not outfn:
    #     outfn = ask_output()
    # else:
    outfn = d+'/ANA_DEFS'
    outfn = check_output(outfn) # Check if output exists already.
    return outfn

# Check if output exists and if so, if user wants to overwrite it.
def check_output(outfn):
    if exists(outfn):
        msg = 'File '+outfn+' exists, overwrite? [Y/n]: '
        ok = input(msg)
        if not ok:
            return outfn
        else:
            if ok in ['Y','y','1']:
                return outfn
            else:
                print('ANA_DEFS not written.') #outfn = ask_output()
                return None #outfn
    else:
        return outfn

# Write the definitions to output file.
def write_ANA_DEFS(d,out_vars,out_defs,prompts):
    outfn = ask_output(d)
    if not outfn:
        sys.exit()
    outf = open(outfn,'w')
    for i in range(len(out_vars)):
        x = slice(-2)
        line = out_vars[i]+' = '+str(out_defs[i])+' # '+prompts[i][x]+'\n'
        outf.write(line)
    outf.close()

# Main function, with variables hard coded to list.    
def anadefs(d):
    regs = []
    if exists('regions_out.txt'):
        regout = open('regions_out.txt','r')
        regions = regout.readlines()
        for r in regions:
            regs.append(r.replace('\n',''))
        os.remove('regions_out.txt')
    else:
        regs.append('signal, background, etc.')
            
    in_vars = ['MCD_e', 'DATAF_e', 'MCD_m', 'DATAF_m', 'CHANNEL', 'SUMCHANNELS', 'MODEL', 'INTLUMI', 'LOG_GRAPHS', 'ECM', 'LIMITTER', 'STAT', 'SYSTERR', 'STATERR', 'OBSERVEDLIMIT', 'INJECTION', 'LUMI_TAG', 'LIVE_TAG', 'DIRECTORY']

    prompts = ['Name of the directory containing MC run results for electrons (str): ',
               'Name of the datafile (omitting .root extension) containing data run results for electrons (str): ',
               'Name of the directory containing MC run results for muons (str): ',
               'Name of the datafile (omitting .root extension) containing data run results for muons (str): ',
               'Electrons or muons? (0: muons, 1: electrons): ',
               'Sum electron and muon channels? (0: do not add, 1: add): ',
               '',
               'Integrated luminosity (float, pb-1): ',
               'Use linear or log graphs? (0: linear y-axis, 1: log y-axis): ',
               'Center of mass energy (7, 8, or 13 GeV): ',
               'Limitter (0: TLimit, 1: RSLLimit, 2: fastPCL, 3: mclimit): ',
               'Confidence limits using signal or signal + background? (0: sig only, 1: sig+bkg): ',
               'Consider systematic errors? (0: do not, 1: consider): ',
               'Consider statistical errors? (0: do not, 1: consider): ',
               'Observed limit (0: do not do, 1: do measured = observed limit calculation): ',
               'Do injection test? (0: do not do, any positive real number: injection cross-section multiplicative factor): ',
               'Luminosity tag (tag specifying the luminosity measurement version) (str): ',
               'Live tag (this trigger is only used to compute the L1 live fraction) (str): ',
               'Region to be worked with '+str(regs)+': ']
    out_vars = []
    out_values = []
    msg = 'Writing ANA_DEFS file, initialize values...'
    print(msg)

    for i in range(len(in_vars)):
        ov,od = ask_input(d,in_vars[i],prompts[i])
        out_vars.append(ov)
        out_values.append(od)


    write_ANA_DEFS(d,out_vars,out_values,prompts)
    return None


# To use the script without a wrapper.
def main():
    d = input("Input a model directory (or '.' to use the current folder): ")
    while not d:
        d = input("Input model directory (or '.' to use the current folder): ")
    if not exists(d):
        print("Directory not found, exiting.")
        sys.exit()

    anadefs(d)

if __name__ == "__main__":
    main()


# def main():
#     anadefs()

# if __name__ == "__main__":
#     main()    
