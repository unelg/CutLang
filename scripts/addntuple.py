'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py <ntuplename>
To delete an already added ntuple, run python3 addntuple.py <ntuplename> --delete
To create an ntuple template, run python3 addntuple.py <ntuplename> --create
To edit template, change templates/default_ntuple_template.c
'''

import sys
import fileinput
from optparse import OptionParser
from ROOT import TFile
import csv
import os

# Parsing options
usage = "Usage: python3 %prog <ntuplename>"
parser = OptionParser(usage=usage)
parser.add_option("--file", action="store",
                  dest="file", default="", help="root file")
parser.add_option("--branchname", action="store",
                  dest="branchname", default="", help="root file selected tree key")
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
delete = option.delete
create = option.create
FILE = option.file
branchname = option.branchname

# Create (or delete) the c file for the new ntuple
c_file = '../CLA/'+name+'.C'
h_file = '../analysis_core/'+name+'.h'

templates_dir_with_name='templates/'+name
csv_dir=templates_dir_with_name+"/variables.csv"


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


def create_template():
    if not FILE:
        print("create option needs file option!")
        sys.exit(0)
    f = TFile(FILE)
    listKeys = f.GetListOfKeys()

    leaves = ""
    branchName = ""
    tree = ""

    if branchname:
        tree = f.Get(branchname)
        try:
            leaves = tree.GetListOfLeaves()
            branchName = branchname
            print(branchName+" was selected")
        except:
            print(branchname+" has no leaf, so it was skipped")
    else:
        for key in listKeys:
            tree = f.Get(key.GetName())
            try:
                leaves = tree.GetListOfLeaves()
                branchName = key.GetName()
                print(branchName+" was selected")
            except:
                print(key.GetName()+" has no leaf, so it was skipped")
                continue
            break

    if branchName == "":
        print("Please select true type")
        sys.exit(0)

    fieldnames = ['type_name', 'branch_name', 'name', 'title', 'title_type', 'n_data']
    rows=[]

    leafTitleType=""
    for leaf in leaves:
        leafTypeName=leaf.GetTypeName()
        leafBranchName=branchName
        leafName=leaf.GetName()
        leafTitle=leaf.GetTitle()
        if "[" in leafTitle and "]" in leafTitle:
            leafTitleType = str(leaf.GetTitle()).split("[")[-1].split("]")[0]
        else:
            leafTitleType="___NONE___"
        leafNData = leaf.GetNdata()
        rows.append({'type_name': leafTypeName, 'branch_name': leafBranchName, 'name': leafName,
               'title': leafTitle, 'title_type': leafTitleType, 'n_data': leafNData})
               
    if not os.path.exists(templates_dir_with_name):
        os.makedirs(templates_dir_with_name)

    with open(csv_dir, 'w', encoding='UTF8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


if create:
    create_template()
