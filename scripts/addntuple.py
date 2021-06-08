'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py <ntuplename>
To delete an already added ntuple, run python3 addntuple.py <ntuplename> --delete
To create an ntuple template, run python3 addntuple.py <ntuplename> --create
To edit template, change templates/default_ntuple_template.c
'''

import os
from re import template
import sys
from jinja2 import Environment, FileSystemLoader
from optparse import OptionParser
import fileinput
import shutil

# Parsing options
usage = "Usage: python3 %prog <ntuplename>"
parser = OptionParser(usage=usage)
parser.add_option("--delete", action="store_true",
                  dest="delete", default=False, help="delete the ntuple")
parser.add_option("--create", action="store_true",
                  dest="create", default=False, help="create the ntuple template")
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
create = option.create

# Create (or delete) the c file for the new ntuple
c_file = '../CLA/'+name+'.C'
# Create the C file for the new ntuple template
template_c_file = 'templates/'+name+'.C'

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


def create_template():
    # Copy the contents of the new ntuple template under templates
    f = open(os.getcwd()+"/"+template_c_file, "w")
    f.close()
    shutil.copy2(os.getcwd()+"/templates/default_ntuple_content_template.C",
                 os.getcwd()+"/"+template_c_file)
    print("New template created at "+os.getcwd()+"/"+template_c_file)


# Create blank ntuple template
if create:
    create_template()
# Create the new ntuple
elif not delete:
    if not os.path.exists("./templates/"+name+".C"):
        create_template()
        print("Template not found, created one for you, please edit " +
              os.getcwd()+"/"+template_c_file)
        sys.exit(0)
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
    file_loader = FileSystemLoader("templates")
    env = Environment(loader=file_loader)

    # Fill out the template
    template_c = env.get_template(name+".C")

    # Extract marks
    output_c = template_c.render(name=name)

    # Copy the contents of the new ntuple under CLA
    open(c_file, 'w').write(output_c)

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

    print('\nCreated the ntuple CLA/' +
          name+'.C. \nPlease edit and recompile.\n')


# Delete the user function header
else:
    remove_files()
