from os.path import exists

def ask_input(variable):
    msg = 'Input '+variable+': '
    value = input(msg)
    msg = variable+' = '+str(value)
    print(msg)
    return variable,value

def ask_output():
    msg = 'Input an output ANA_DEFS file: '
    outfn = input(msg)
    if not outfn:
        outfn = ask_output()
    else:
        outfn = check_output(outfn)
    return outfn
    
def check_output(outfn):
    if exists(outfn):
        msg = 'File '+outfn+' exists, overwrite? [Y/n]: '
        ok = input(msg)
        if not ok:
            return outfn
        else:
            if ok in ['Y','y']:
                return outfn
            else:
                outfn = ask_output()
                return outfn
    else:
        return outfn


def write_ANA_DEFS(out_vars,out_defs):
    outfn = ask_output()
    outf = open(outfn,'w')
    for i in range(len(out_vars)):
        line = out_vars[i]+' = '+str(out_defs[i])+'\n'
        outf.write(line)
    outf.close()
    
# msg = 'Input directory: '
# indirn = input(msg)

# if exists(indirn):
#     msg = 'Using directory '+indirn
#     print(msg)
# else:
#     msg = 'Directory '+indirn+' not found!'
#     print(msg)

in_vars = ['MCD_e', 'DATAF_e', 'MCD_m', 'DATAF_m', 'CHANNEL', 'SUMCHANNELS', 'MODEL', 'INTLUMI', 'LOG_GRAPHS', 'ECM', 'LIMITTER', 'STAT', 'SYSTERR', 'OBSERVEDLIMIT', 'INJECTION', 'LUMI_TAG', 'LIVE_TAG', 'DIRECTORY', 'STATERR']

out_vars = []
out_values = []

for i in range(len(in_vars)):
    ov,od = ask_input(in_vars[i])
    out_vars.append(ov)
    out_values.append(od)


write_ANA_DEFS(out_vars,out_values)

# print(out_vars)
# print(out_defs)
