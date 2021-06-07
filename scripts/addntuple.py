'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py <ntuplename>
To delete an already added ntuple, run python3 addntuple.py <ntuplename> --delete
To edit template, change templates/default_ntuple_template.c
'''

import os
import sys
from string import Template
from optparse import OptionParser
import fileinput

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
uppername = name.upper()
lowername = name.lower()
delete = option.delete

# Create (or delete) the c file for the new ntuple
c_file = '../CLA/'+name+'.C'

# Edit CLA.Q file


class FILE_HELPER:
    def __init__(self, file):
        self.file = open(file, 'r+')
        self.content = self.file.read()
        self.seek_zero()

    def seek_zero(self):
        self.file.seek(0)

    def find_line(self, text, lines):
        counter = 0
        for line in lines:
            if text in line:
                break
            counter += 1
        return counter

    def remove(self, find_line, lines):
        for line in fileinput.input(self.file.name, inplace=True):
            if lines[find_line] in line:
                continue
            print(line, end='')

    def remove_from_file(self, text):
        self.seek_zero()
        lines = self.file.readlines()
        find_line = self.find_line(text, lines)
        self.remove(find_line, lines)

    def find_and_write(self, search, add):
        self.seek_zero()
        lines = self.file.readlines()
        find_line = self.find_line(search, lines)
        lines.insert(find_line, add)
        self.seek_zero()
        self.file.write("".join(lines))

    def find_and_write_with_delete(self, search, add):
        self.find_and_write(search, add)
        self.remove_from_file(search)

    def find(self, search):
        self.seek_zero()
        lines = self.file.readlines()
        find_line = self.find_line(search, lines)
        return lines[find_line]


def remove_files():
    # remove exist c_file
    if os.path.exists(c_file):
        os.remove(c_file)
    else:
        return print("nothing")

    # remove CLA.Q edits
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.remove_from_file('#include "'+name+'.h"')
    claq.remove_from_file('bool use_'+lowername+'=false;')
    claq.remove_from_file('else if (inptype == "'+uppername+'"')
    file_types = claq.find('<< " [-inp')
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.find_and_write_with_delete(
        file_types, file_types.replace(" | "+uppername+" | ", " | "))
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.remove_from_file('}else if (use_'+lowername+'){')
    claq.remove_from_file('cout << "~Now using ' +
                          uppername+' files.~~~~~~ beta!\\n";')
    claq.remove_from_file('chain = new TChain("Events"); //'+uppername)
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.remove_from_file('} else if (use_'+lowername+'){')
    claq.remove_from_file(name+' *'+name+'a=new '+name+'("XXX",chain);')
    claq.remove_from_file(name+'a->Loop(aselect, username);')
    claq.file.close()
    claq = FILE_HELPER('../CLA/Makefile')
    objs_1 = claq.find('OBJS_1        = $(ANLOBJS) ')
    claq.find_and_write_with_delete(objs_1, objs_1.replace(
        " "+name+".o ", " "))
    claq.file.close()


# Create the new ntuple
if not delete:
    # Check if the ntuple already exists
    if os.path.exists(c_file):
        question = 'Ntuple '+c_file + \
            ' already exists.  Do you want to delete?'
        yes = {'yes', 'y', 'ye', ''}
        no = {'no', 'n'}
        ianswer = -1
        while ianswer == -1:
            answer = str(input(question+' (y/n): ')).lower().strip()
            if answer[0] in yes:
                print('Deleting '+c_file)
                ianswer = 1
                remove_files()
            if answer[0] in no:
                print('Keeping '+c_file+' and exiting.')
                ianswer = 0
                sys.exit(0)

    # Read template
    f = open(os.getcwd()+"/templates/default_ntuple_template.C", "r")
    ntuple_tmp = f.read()

    # Fill out the template
    ntuple_filled = Template(ntuple_tmp).substitute(name=name)

    # Copy the contents of the new ntuple under CLA
    open(c_file, 'w').write(ntuple_filled)

    print('\nCreated the ntuple CLA/' +
          name+'.C. \nPlease edit and recompile.\n')

    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.file.write('#include "'+name+'.h"\n'+claq.content)
    claq.find_and_write("bool use_", " bool use_"+lowername+"=false;\n")
    file_types = claq.find('<< " [-inp')
    claq.find_and_write_with_delete(
        file_types, file_types.replace("]\\n", uppername+" | ]\\n"))
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.find_and_write(
        'else if (inptype ==', ' else if (inptype == "'+uppername+'"){ use_'+lowername+' =true; }\n')
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.find_and_write(
        '  }else if (use_', '   chain = new TChain("Events"); //'+uppername+'\n')
    claq.find_and_write('   chain = new TChain("Events"); //'+uppername+'',
                        '   cout << "~Now using '+uppername+' files.~~~~~~ beta!\\n";\n')
    claq.find_and_write(
        '   cout << "~Now using '+uppername+' files.~~~~~~ beta!\\n";', '  }else if (use_'+lowername+'){\n')
    claq.file.close()
    claq = FILE_HELPER('../CLA/CLA.Q')
    claq.find_and_write(
        '} else if (use_', '    } else if (use_'+lowername+'){\n        '+name+' *'+name+'a=new '+name+'("XXX",chain);\n       '+name+'a->Loop(aselect, username);\n')
    claq.file.close()
    claq = FILE_HELPER('../CLA/Makefile')
    objs_1 = claq.find('OBJS_1        = $(ANLOBJS) ')
    claq.find_and_write_with_delete(objs_1, objs_1.replace(
        "$(ANLOBJS) ", "$(ANLOBJS) "+name+".o "))
    claq.file.close()


# Delete the user function header
else:
    remove_files()
