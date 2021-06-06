'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py <ntuplename>
To delete an already added ntuple, run python3 addntuple.py <ntuplename> --delete
To edit template, change addntuple_template.c
'''

import os
import sys
from string import Template
from optparse import OptionParser

# Parsing options
usage = "Usage: python3 %prog <ntuplename>"
parser = OptionParser(usage=usage)
parser.add_option("--delete", action="store_true",
                  dest="delete", default=False, help="delete the ntuple")
(option, args) = parser.parse_args()

# Get the new ntuple name
if len(args) < 1:
    print("Please specify the name of the new ntuple")
    print("For help, run python3 addntuple.py -h")
    sys.exit()
name = args[0]
delete = option.delete

# Create (or delete) the c file for the new ntuple
funcfile = '../CLA/'+name+'.C'

# Create the new ntuple
if not delete:
    # Check if the ntuple already exists
    if os.path.exists(funcfile):
        question = 'Ntuple '+funcfile + \
            ' already exists.  Do you want to delete?'
        yes = {'yes', 'y', 'ye', ''}
        no = {'no', 'n'}
        ianswer = -1
        while ianswer == -1:
            answer = str(input(question+' (y/n): ')).lower().strip()
            if answer[0] in yes:
                print('Deleting '+funcfile)
                ianswer = 1
            if answer[0] in no:
                print('Keeping '+funcfile+' and exiting.')
                ianswer = 0
                sys.exit(0)

    # Read template
    f = open(os.getcwd()+"/addntuple_template.c", "r")
    ntuple_tmp = f.read()

    # Fill out the template
    ntuple_filled = Template(ntuple_tmp).substitute(name=name)

    # Copy the contents of the new ntuple under CLA
    open(funcfile, 'w').write(ntuple_filled)

    print('\nCreated the ntuple CLA/' +
          name+'.C. \nPlease edit and recompile.\n')

# Delete the user function header
else:
    if os.path.exists(funcfile):
        os.remove(funcfile)
