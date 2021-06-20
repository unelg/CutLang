'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py <ntuplename>
To delete an already added ntuple, run python3 addntuple.py <ntuplename> --delete
To create an ntuple template, run python3 addntuple.py <ntuplename> --create
To edit template, change templates/default_ntuple_template.c
'''

import os
from string import Template
import sys
from jinja2 import Environment, FileSystemLoader
from optparse import OptionParser
import fileinput
import shutil
import datetime
from ROOT import TFile, TH1F

# Parsing options
usage = "Usage: python3 %prog <ntuplename>"
parser = OptionParser(usage=usage)
parser.add_option("--file", action="store",
                  dest="file", default="", help="root file")
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
FILE = option.file

# Create (or delete) the c file for the new ntuple
c_file = '../CLA/'+name+'.C'
h_file = '../analysis_core/'+name+'.h'
# Create the C file for the new ntuple template
template_c_file = 'templates/'+name+'.C'
# Create the h file for the new ntuple template
template_h_file = 'templates/'+name+'.h'

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
        os.remove(h_file)
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

    if not FILE:
        print("create option needs file option!")
        sys.exit(0)

    # ROOT
    CONTENT_GET_PHYS_TEMP_VAR = ""
    CONTENT_PHOTONS = ""
    CONTENT_MUONS = ""
    CONTENT_ELECTRONS = ""
    CONTENT_JETS = ""
    CONTENT_MET = ""
    CONTENT_POST_FINISH = ""

    f = TFile(FILE)
    fTreeName = str(f.GetListOfKeys()[0]).split(" ")[1]
    tree = f.Get(fTreeName)
    leaves = tree.GetListOfLeaves()

    leafTypes = ["Px", "Py", "Pz", "E", "Pt", "eta", "phi", "M"]

    photonSearchList = ["photon", "Photon", "PHOTON"]
    photonLeafNames = {}

    muonSearchList = ["muon", "Muon", "mu", "Mu", "MUON", "MU"]
    muonLeafNames = {}

    electronSearchList = ["electron", "Electron", "ELECTRON"]
    electronLeafNames = {}

    jetSearchList = ["Jet", "jet", "JET"]
    jetLeafNames = {}

    metSearchList = ["met", "Met", "MET"]
    metLeafNames = {}

    def fill_names(searchList, leafNames):
        for i in leaves:
            leafName = str(i).split(" ")[1]
            for l in searchList:
                if l in leafName:
                    for leafType in leafTypes:
                        if (
                            leafName.endswith("_" + leafType) or leafName.endswith("." + leafType) or
                            leafName.endswith("_" + leafType.lower()) or leafName.endswith("." + leafType.lower()) or
                            leafName.endswith(
                                "_" + leafType.upper()) or leafName.endswith("." + leafType.upper())
                        ):
                            leafNames[leafType] = leafName


    fill_names(photonSearchList, photonLeafNames)
    fill_names(muonSearchList, muonLeafNames)
    fill_names(electronSearchList, electronLeafNames)
    fill_names(jetSearchList, jetLeafNames)
    fill_names(metSearchList, metLeafNames)

    # Fill photons content
    controller = False
    if ("Px" in photonLeafNames and "Py" in photonLeafNames and "Pz" in photonLeafNames and "E" in photonLeafNames):
        CONTENT_PHOTONS += "\talv.SetPxPyPzE("+photonLeafNames["Px"]+"[i], "+photonLeafNames["Py"] + \
            "[i], "+photonLeafNames["Pz"]+"[i], " + \
            photonLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in photonLeafNames and "eta" in photonLeafNames and "phi" in photonLeafNames and "E" in photonLeafNames):
        CONTENT_PHOTONS += "\talv.SetPtEtaPhiE("+photonLeafNames["Pt"]+"[i], "+photonLeafNames["eta"] + \
            "[i], "+photonLeafNames["phi"]+"[i], " + \
            photonLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in photonLeafNames and "eta" in photonLeafNames and "phi" in photonLeafNames and "M" in photonLeafNames):
        CONTENT_PHOTONS += "\talv.SetPtEtaPhiM("+photonLeafNames["Pt"]+"[i], "+photonLeafNames["eta"] + \
            "[i], "+photonLeafNames["phi"]+"[i], " + \
            photonLeafNames["M"]+"[i]);\n"
        controller = True
    elif ("Pt" in photonLeafNames and "eta" in photonLeafNames and "phi" in photonLeafNames):
        CONTENT_PHOTONS += "\talv.SetPtEtaPhiM("+photonLeafNames["Pt"]+"[i], "+photonLeafNames["eta"] + \
            "[i], "+photonLeafNames["phi"]+"[i], (105.658/1E3));\n"
        controller = True
    if controller:
        CONTENT_PHOTONS += "\tadbxp = new dbxPhoton(alv);\n"

        CONTENT_PHOTONS += "\tdelete adbxp;\n"

    # Fill muons content
    controller = False
    if ("Px" in muonLeafNames and "Py" in muonLeafNames and "Pz" in muonLeafNames and "E" in muonLeafNames):
        CONTENT_MUONS += "\talv.SetPxPyPzE("+muonLeafNames["Px"]+"[i], "+muonLeafNames["Py"] + \
            "[i], "+muonLeafNames["Pz"]+"[i], " + \
            muonLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in muonLeafNames and "eta" in muonLeafNames and "phi" in muonLeafNames and "E" in muonLeafNames):
        CONTENT_MUONS += "\talv.SetPtEtaPhiE("+muonLeafNames["Pt"]+"[i], "+muonLeafNames["eta"] + \
            "[i], "+muonLeafNames["phi"]+"[i], " + \
            muonLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in muonLeafNames and "eta" in muonLeafNames and "phi" in muonLeafNames and "M" in muonLeafNames):
        CONTENT_MUONS += "\talv.SetPtEtaPhiM("+muonLeafNames["Pt"]+"[i], "+muonLeafNames["eta"] + \
            "[i], "+muonLeafNames["phi"]+"[i], " + \
            muonLeafNames["M"]+"[i]);\n"
        controller = True
    elif ("Pt" in muonLeafNames and "eta" in muonLeafNames and "phi" in muonLeafNames):
        CONTENT_MUONS += "\talv.SetPtEtaPhiM("+muonLeafNames["Pt"]+"[i], "+muonLeafNames["eta"] + \
            "[i], "+muonLeafNames["phi"]+"[i], (105.658/1E3));\n"
        controller = True
    if controller:
        CONTENT_MUONS += "\tadbxm = new dbxMuon(alv);\n"

        CONTENT_MUONS += "\tdelete adbxm;\n"

    # Fill electrons content
    controller = False
    if ("Px" in electronLeafNames and "Py" in electronLeafNames and "Pz" in electronLeafNames and "E" in electronLeafNames):
        CONTENT_ELECTRONS += "\talv.SetPxPyPzE("+electronLeafNames["Px"]+"[i], "+electronLeafNames["Py"] + \
            "[i], "+electronLeafNames["Pz"]+"[i], " + \
            electronLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in electronLeafNames and "eta" in electronLeafNames and "phi" in electronLeafNames and "E" in electronLeafNames):
        CONTENT_ELECTRONS += "\talv.SetPtEtaPhiE("+electronLeafNames["Pt"]+"[i], "+electronLeafNames["eta"] + \
            "[i], "+electronLeafNames["phi"]+"[i], " + \
            electronLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in electronLeafNames and "eta" in electronLeafNames and "phi" in electronLeafNames and "M" in electronLeafNames):
        CONTENT_ELECTRONS += "\talv.SetPtEtaPhiM("+electronLeafNames["Pt"]+"[i], "+electronLeafNames["eta"] + \
            "[i], "+electronLeafNames["phi"]+"[i], " + \
            electronLeafNames["M"]+"[i]);\n"
        controller = True
    elif ("Pt" in electronLeafNames and "eta" in electronLeafNames and "phi" in electronLeafNames):
        CONTENT_ELECTRONS += "\talv.SetPtEtaPhiM("+electronLeafNames["Pt"]+"[i], "+electronLeafNames["eta"] + \
            "[i], "+electronLeafNames["phi"]+"[i], (105.658/1E3));\n"
        controller = True
    if controller:
        CONTENT_ELECTRONS += "\tadbxe = new dbxElectron(alv);\n"

        CONTENT_ELECTRONS += "\tdelete adbxe;\n"

    # Fill jets content
    controller = False
    if ("Px" in jetLeafNames and "Py" in jetLeafNames and "Pz" in jetLeafNames and "E" in jetLeafNames):
        CONTENT_JETS += "\talv.SetPxPyPzE("+jetLeafNames["Px"]+"[i], "+jetLeafNames["Py"] + \
            "[i], "+jetLeafNames["Pz"]+"[i], " + \
            jetLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in jetLeafNames and "eta" in jetLeafNames and "phi" in jetLeafNames and "E" in jetLeafNames):
        CONTENT_JETS += "\talv.SetPtEtaPhiE("+jetLeafNames["Pt"]+"[i], "+jetLeafNames["eta"] + \
            "[i], "+jetLeafNames["phi"]+"[i], " + \
            jetLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in jetLeafNames and "eta" in jetLeafNames and "phi" in jetLeafNames and "M" in jetLeafNames):
        CONTENT_JETS += "\talv.SetPtEtaPhiM("+jetLeafNames["Pt"]+"[i], "+jetLeafNames["eta"] + \
            "[i], "+jetLeafNames["phi"]+"[i], " + \
            jetLeafNames["M"]+"[i]);\n"
        controller = True
    elif ("Pt" in jetLeafNames and "eta" in jetLeafNames and "phi" in jetLeafNames):
        CONTENT_JETS += "\talv.SetPtEtaPhiM("+jetLeafNames["Pt"]+"[i], "+jetLeafNames["eta"] + \
            "[i], "+jetLeafNames["phi"]+"[i], (105.658/1E3));\n"
        controller = True
    if controller:
        CONTENT_JETS += "\tadbxj = new dbxJet(alv);\n"

        CONTENT_JETS += "\tdelete adbxj;\n"

    # Fill mets content ???
    controller = False
    if ("Px" in metLeafNames and "Py" in metLeafNames and "Pz" in metLeafNames and "E" in metLeafNames):
        CONTENT_MET += "\talv.SetPxPyPzE("+metLeafNames["Px"]+"[i], "+metLeafNames["Py"] + \
            "[i], "+metLeafNames["Pz"]+"[i], " + \
            metLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in metLeafNames and "eta" in metLeafNames and "phi" in metLeafNames and "E" in metLeafNames):
        CONTENT_MET += "\talv.SetPtEtaPhiE("+metLeafNames["Pt"]+"[i], "+metLeafNames["eta"] + \
            "[i], "+metLeafNames["phi"]+"[i], " + \
            metLeafNames["E"]+"[i]);\n"
        controller = True
    elif ("Pt" in metLeafNames and "eta" in metLeafNames and "phi" in metLeafNames and "M" in metLeafNames):
        CONTENT_MET += "\talv.SetPtEtaPhiM("+metLeafNames["Pt"]+"[i], "+metLeafNames["eta"] + \
            "[i], "+metLeafNames["phi"]+"[i], " + \
            metLeafNames["M"]+"[i]);\n"
        controller = True
    elif ("Pt" in metLeafNames and "eta" in metLeafNames and "phi" in metLeafNames):
        CONTENT_MET += "\talv.SetPtEtaPhiM("+metLeafNames["Pt"]+"[i], "+metLeafNames["eta"] + \
            "[i], "+metLeafNames["phi"]+"[i], (105.658/1E3));\n"
        controller = True
    if controller:
        #CONTENT_MET+="\tadbxp = new dbxMet(alv);\n"

        #CONTENT_MET+="\tdelete adbxp;\n"
        pass

    print("photonData", photonLeafNames)
    print("muonData", muonLeafNames)
    print("electronData", electronLeafNames)
    print("jetData", jetLeafNames)
    print("metData", metLeafNames)
    # ROOT

    # Read template
    fC = open(os.getcwd()+"/templates/default_ntuple_content_template.C", "r")
    ntuple_tmp_c = fC.read()
    fh = open(os.getcwd()+"/templates/default_ntuple_content_template.h", "r")
    ntuple_tmp_h = fh.read()

    # Fill out the template
    ntuple_filled_c = Template(ntuple_tmp_c).substitute(
        CONTENT_GET_PHYS_TEMP_VAR=CONTENT_GET_PHYS_TEMP_VAR, CONTENT_PHOTONS=CONTENT_PHOTONS, CONTENT_MUONS=CONTENT_MUONS,
                                 CONTENT_ELECTRONS=CONTENT_ELECTRONS, CONTENT_JETS=CONTENT_JETS, CONTENT_MET=CONTENT_MET, CONTENT_POST_FINISH=CONTENT_POST_FINISH
    )
    ntuple_filled_h = Template(ntuple_tmp_h).substitute()

    # Copy the contents of the new ntuple template under templates
    open(template_c_file, 'w').write(ntuple_filled_c)
    print("New template C created at "+os.getcwd()+"/"+template_c_file)

    open(template_h_file, 'w').write(ntuple_filled_h)
    print("New template h created at "+os.getcwd()+"/"+template_h_file)


# Create blank ntuple template
if create:
    create_template()
# Create the new ntuple
if not delete:
    if not os.path.exists("./templates/"+name+".C"):
        create_template()
        print("Template not found, created one for you, please edit " +
              os.getcwd()+"/"+template_c_file+" and "+os.getcwd()+"/"+template_h_file)
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
    template_h = env.get_template(name+".h")

    # Extract marks
    output_c = template_c.render(name=name)
    output_h = template_h.render(name=name, date=datetime.datetime.now())

    # Copy the contents of the new ntuple under CLA
    open(c_file, 'w').write(output_c)
    open(h_file, 'w').write(output_h)

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
