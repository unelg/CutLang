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

# Parsing options
usage = "Usage: python3 %prog <ntuplename>"
parser = OptionParser(usage=usage)
parser.add_option("--file", action="store",
                  dest="file", default="", help="root file")
parser.add_option("--treekey", action="store",
                  dest="treekey", default="", help="root file selected tree key")
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
treekey = option.treekey

# Create (or delete) the c file for the new ntuple
c_file = '../CLA/'+name+'.C'
h_file = '../analysis_core/'+name+'.h'


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
    listKeyName = ""
    tree = ""

    if treekey:
        tree = f.Get(treekey)
        try:
            leaves = tree.GetListOfLeaves()
            listKeyName = treekey
            print(listKeyName+" was selected")
        except:
            print(treekey+" has no leaf, so it was skipped")
    else:
        for key in listKeys:
            tree = f.Get(key.GetName())
            try:
                leaves = tree.GetListOfLeaves()
                listKeyName = key.GetName()
                print(listKeyName+" was selected")
            except:
                print(key.GetName()+" has no leaf, so it was skipped")
                continue
            break

    if listKeyName == "":
        print("Please select true type")
        sys.exit(0)

    selectedLeavesTypes = {}
    _selectedTypes=[]
    notSelectedLeaves = []


    for leaf in leaves:
        # Select leaf names which is important
        try:
            leafType = str(leaf.GetTitle().split("[")[1].split("]")[0])
            selectedLeafTypeName = ""
            if leafType.lower().startswith("n"):
                selectedLeafTypeName = leafType[1:].lower()
                if selectedLeafTypeName not in selectedLeavesTypes:
                    selectedLeavesTypes[selectedLeafTypeName] = {}
            elif leafType.endswith("_"):
                selectedLeafTypeName = leafType[:-1].lower()
                if selectedLeafTypeName not in selectedLeavesTypes:
                    selectedLeavesTypes[selectedLeafTypeName] = {}
            else:
                print("There was problem!")
                sys.exit(0)

            leafType = str(leaf.GetTitle().split("[")[0].split("_")[-1])
            if leafType=="":
                leafType = str(leaf.GetTitle().split("[")[0].split("_")[0])
            selectedLeavesTypes[selectedLeafTypeName][leafType.lower(
            )] = leaf.GetName()
            _selectedTypes.append(leaf.GetName())

            # print(leaf)
        except:
            notSelectedLeaves.append(leaf)
            pass

    # Check others
    for i, leaf in enumerate(notSelectedLeaves):
        for leafType in selectedLeavesTypes:
            if leafType in leaf.GetTitle().lower():
                selectedLeafPropertyTypeName = leaf.GetTitle().split(
                    "_")[-1].lower()
                if selectedLeafPropertyTypeName != "":
                    selectedLeavesTypes[leafType][selectedLeafPropertyTypeName] = leaf.GetName(
                    )
                    _selectedTypes.append(leaf.GetName())
                else:
                    selectedLeafPropertyTypeName = leaf.GetTitle().split(
                    "_")[0].lower()
                    selectedLeavesTypes[leafType][selectedLeafPropertyTypeName] = leaf.GetName(
                    )
                    _selectedTypes.append(leaf.GetName())

    # Collect some other types
    for i, leaf in enumerate(notSelectedLeaves):
        if (leaf.GetTitle().lower().split("_")[-1] == "px" or leaf.GetTitle().lower().split("_")[-1] == "py" or leaf.GetTitle().lower().split("_")[-1] == "pz"
                or leaf.GetTitle().lower().split("_")[-1] == "pt" or leaf.GetTitle().lower().split("_")[-1] == "phi"):
            selectedLeafPropertyTypeName = leaf.GetTitle().lower().split(
                "_")[0]
            if selectedLeafPropertyTypeName not in selectedLeavesTypes:
                selectedLeavesTypes[selectedLeafPropertyTypeName]={}
            selectedLeavesTypes[selectedLeafPropertyTypeName][leaf.GetTitle(
            ).lower().split("_")[-1]] = leaf.GetName()
            _selectedTypes.append(leaf.GetName())

    # notSelectedLeaves humanize
    for i, leaf in enumerate(notSelectedLeaves):
        notSelectedLeaves[i] = leaf.GetName()

    # Clear notSelectedLeaves
    for i in selectedLeavesTypes:
        for leafType in selectedLeavesTypes[i]:
            clearType=selectedLeavesTypes[i][leafType]
            if clearType in notSelectedLeaves:
                notSelectedLeaves.remove(clearType)

    #for i in leaves:
        #print(i)
    counterSelectedLeavesTypes=0
    for i in selectedLeavesTypes:
        for leafType in selectedLeavesTypes[i]:
            #print(selectedLeavesTypes[i][leafType])
            counterSelectedLeavesTypes+=1
    #for leaf in leaves:
        #if leaf.GetName() not in _selectedTypes:
            #print(leaf.GetName(),"error")
    print(selectedLeavesTypes, "selectedLeavesTypes")
    print(notSelectedLeaves,"notSelectedLeaves")
    print(counterSelectedLeavesTypes+len(notSelectedLeaves),
          "counterSelectedLeavesTypes+notSelectedLeaves")
    print(len(leaves),"len(leaves)")


if create:
    create_template()
