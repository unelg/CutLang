'''
Script for adding (or deleting) new ntuples into CutLang
run as python3 addntuple.py
To create an ntuple template, run python3 addntuple.py --name <ntuplename> --file <rootfile> --create [--branchname <branchname>]
To save an already added ntuple, run python3 addntuple.py --name <ntuplename> --save
To delete an already added ntuple, run python3 addntuple.py --name <ntuplename> --delete
To edit template, change templates/<ntuplename>
'''

import sys
import fileinput
from optparse import OptionParser
from ROOT import TFile, gInterpreter, gSystem, gROOT
import csv
import os
import json
from time import gmtime, strftime

# Parsing options
usage = '''
python3 %prog --[name | file | branchname | delete | create | save]
To create an ntuple template, run:
    python3 addntuple.py --name <ntuplename> --file <rootfile> --create [--branchname <branchname>]
To save an already added ntuple, run:
    python3 addntuple.py --name <ntuplename> --save
To delete an already added ntuple, run:
    python3 addntuple.py --name <ntuplename> --delete
'''
parser = OptionParser(usage=usage)
parser.add_option("--name", action="store",
                  dest="name", default="", help="template name")
parser.add_option("--file", action="store",
                  dest="file", default="", help="root file")
parser.add_option("--branchname", action="store",
                  dest="branchname", default="", help="branch name to select (optional)")
parser.add_option("--delete", action="store_true",
                  dest="delete", default=False, help="delete the ntuple (needs --name flag)")
parser.add_option("--create", action="store_true",
                  dest="create", default=False, help="create the ntuple template (needs --file and --name flag)")
parser.add_option("--save", action="store_true",
                  dest="save", default=False, help="save the ntuple template (needs --name flag)")
(option, args) = parser.parse_args()

# Get the new ntuple name
name = option.name
delete = option.delete
create = option.create
FILE = option.file
branchname = option.branchname
save = option.save

full_path = os.path.realpath(__file__)
filePath, fileName = os.path.split(full_path)
workPath = os.path.dirname(filePath)

# Create (or delete) the c file for the new ntuple
c_file = workPath+'/CLA/'+name+'.C'
h_file = workPath+'/analysis_core/'+name+'.h'

templates_dir = filePath+'/templates'
templates_dir_with_name = filePath+'/templates/'+name

dateNow = strftime("%Y-%m-%d_%H-%M-%S", gmtime())


class FILE_HELPER:
    def __init__(self, file):
        self.file_name = file
        self.file = open(file, 'r+')
        self.seek_zero()

    def content(self):
        content = self.file.read()
        self.file.close()
        self.file = open(self.file_name, 'r+')
        return content

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
        self.file.close()
        self.file = open(self.file_name, 'r+')

    def find_and_write(self, search, add):
        self.seek_zero()
        lines = self.file.readlines()
        find_line = self.find_line(search, lines)
        lines.insert(find_line, add)
        self.seek_zero()
        self.file.write("".join(lines))

    def find_and_write_with_delete(self, search, add):
        self.find_and_write(search, add+"\n")
        self.remove_from_file(search)
        self.file.close()
        self.file = open(self.file_name, 'r+')

    def find(self, search):
        self.seek_zero()
        lines = self.file.readlines()
        find_line = self.find_line(search, lines)
        return lines[find_line]


def create_template(recreate=False):
    if not FILE:
        print("create option needs file option!")
        sys.exit(0)
    if not name:
        print("create option needs name option!")
        sys.exit(0)
    #gInterpreter.AddIncludePath(workPath+"/analysis_core/")
    #gSystem.AddIncludePath("-I. -I"+workPath+"/analysis_core")
    #gROOT.LoadMacro(workPath+"/analysis_core/dbx_electron.h")
    #gSystem.Load(workPath+"/analysis_core/dbx_electron_h.so")
    #gROOT.LoadMacro(workPath+"/analysis_core/dbx_muon.h")
    #gSystem.Load(workPath+"/analysis_core/dbx_muon_h.so")
    #gROOT.LoadMacro(workPath+"/analysis_core/dbx_jet.h")
    #gSystem.Load(workPath+"/analysis_core/dbx_jet_h.so")
    #gROOT.LoadMacro(workPath+"/analysis_core/dbx_tau.h")
    #gSystem.Load(workPath+"/analysis_core/dbx_tau_h.so")
    #gROOT.LoadMacro(workPath+"/analysis_core/dbx_a.h")
    #gSystem.Load(workPath+"/analysis_core/dbx_a")
    #gROOT.LoadMacro(workPath+"/analysis_core/DBXNtuple.h")
    #gSystem.Load(workPath+"/analysis_core/DBXNtuple")
    #gROOT.LoadMacro(workPath+"/analysis_core/analysis_core.h")
    ##gSystem.Load(workPath+"/analysis_core/analysis_core.so")
    #gROOT.LoadMacro(workPath+"/analysis_core/AnalysisController.h")
    #gSystem.Load(workPath+"/analysis_core/AnalysisController")

    if os.path.exists(templates_dir_with_name+"/"+name+".C") and recreate == False:
        question = 'Ntuple template for ' + name + \
            ' already exists.  Do you want to recreate it?'
        yes = {'yes', 'y', 'ye', ''}
        no = {'no', 'n'}
        ianswer = -1
        while ianswer == -1:
            answer = str(input(question+' (y/n): ')).lower().strip()
            if answer[0] in yes:
                print('Recreating '+templates_dir_with_name+"/"+name+".C")
                ianswer = 1
                file_names = os.listdir(templates_dir_with_name)
                for file_name in file_names:
                    if file_name != "history":
                        if not os.path.exists(templates_dir_with_name+"/history/"+dateNow):
                            os.makedirs(templates_dir_with_name +
                                        "/history/"+dateNow)
                        os.rename(templates_dir_with_name+"/"+file_name,
                                  templates_dir_with_name+"/history/"+dateNow+"/"+file_name)
                create_template(True)
                sys.exit(0)
            if answer[0] in no:
                print('Keeping '+templates_dir_with_name +
                      "/"+name+".C"+' and exiting.')
                ianswer = 0
                sys.exit(0)

    f = TFile(FILE)
    listKeys = f.GetListOfKeys()

    leaves = ""
    branchName = ""
    tree = ""
    treeName = ""
    treeTitle = ""

    if branchname:
        try:
            tree = f.Get(branchname)
            treeName = tree.GetName()
            treeTitle = tree.GetTitle()
        except:
            print("Tree name is incorrect")
            sys.exit(0)
        try:
            leaves = tree.GetListOfLeaves()
            branchName = branchname
            print("Selected branch name: "+branchName)
        except:
            print(branchname+" has no leaf, so it was skipped")
    else:
        for key in listKeys:
            try:
                tree = f.Get(key.GetName())
                treeName = tree.GetName()
                treeTitle = tree.GetTitle()
            except:
                print("Tree name is incorrect")
                sys.exit(0)

            try:
                leaves = tree.GetListOfLeaves()
                branchName = key.GetName()
                print("Selected branch name: "+branchName)
            except:
                print(key.GetName()+" has no leaf, so it was skipped")
                continue
            break

    if branchName == "":
        print("Please select true type")
        sys.exit(0)

    fieldnames = ['type_name', 'branch_name',
                  'name', 'title', 'title_type', 'n_data']
    rows = []

    leafTitleType = ""
    for leaf in leaves:
        leafTypeName = leaf.GetTypeName()
        leafBranchName = branchName
        leafName = leaf.GetName()
        leafTitle = leaf.GetTitle()
        if "[" in leafTitle and "]" in leafTitle:
            leafTitleType = str(leaf.GetTitle()).split("[")[-1].split("]")[0]
        elif "_" in leafTitle:
            leafTitleType = "___NONE___" + str(leaf.GetTitle()).split("_")[0]
        elif "." in leafTitle:
            leafTitleType = "___NONE___" + str(leaf.GetTitle()).split(".")[0]
        else:
            leafTitleType = "___NONE___"
        leafNData = leaf.GetNdata()
        rows.append({'type_name': leafTypeName, 'branch_name': leafBranchName, 'name': leafName,
                     'title': leafTitle, 'title_type': leafTitleType, 'n_data': leafNData})

    if not os.path.exists(templates_dir):
        os.makedirs(templates_dir)
    if not os.path.exists(templates_dir_with_name):
        os.makedirs(templates_dir_with_name)
    if not os.path.exists(templates_dir_with_name+"/history"):
        os.makedirs(templates_dir_with_name+"/history")
        history_gitkeepF = open(
            templates_dir_with_name+"/history/.gitkeep", "w")
        history_gitkeepF.close()

    tree.MakeClass(name)
    os.rename(os.getcwd()+"/"+name+".C", templates_dir_with_name+"/"+name+".C")
    os.rename(os.getcwd()+"/"+name+".h", templates_dir_with_name+"/"+name+".h")

    fC = FILE_HELPER(templates_dir_with_name+"/"+name+".C")

    content = fC.content()
    fC.file.write(
        '''//////////////////////////////////////////////////////////
// This file has been automatically generated on
// {now} by CutLang
// from TTree {treeName}/{treeTitle}
// found on file: {file}
//////////////////////////////////////////////////////////
'''.format(file=FILE, treeName=treeName, treeTitle=treeTitle, now=dateNow)+content)

    loop_selector = "void "+name+"::Loop()"

    fC.find_and_write(loop_selector, '''
// >>> "include" anchor >>>
#include <signal.h>
#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_truth.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern void _fsig_handler (int) ;
extern bool fctrlc;
// <<< "include" anchor <<<
    ''')
    fC.find_and_write(loop_selector, '''   
void {name}::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0, Long64_t nentries )
{{

    // >>> GetPhysicsObjects >>>

    fChain->GetEntry(j);
    vector<dbxMuon>     muons;
    vector<dbxElectron> electrons;
    vector<dbxPhoton>   photons;
    vector<dbxJet>      jets;
    vector<dbxTau>      taus;
    vector<dbxJet>     ljets;
    vector<dbxTruth>    truth;
    vector<dbxParticle> combos;
    vector<dbxParticle> constits;

    map<string, vector<dbxMuon>     > muos_map;
    map<string, vector<dbxElectron> > eles_map;
    map<string, vector<dbxTau>      > taus_map;
    map<string, vector<dbxPhoton>   > gams_map;
    map<string, vector<dbxJet>      > jets_map;
    map<string, vector<dbxJet>     >ljets_map;
    map<string, vector<dbxTruth>    >truth_map;
    map<string, vector<dbxParticle> >combo_map;
    map<string, vector<dbxParticle> >constits_map;
    map<string, TVector2            >  met_map;
    
    evt_data anevt;
    
    //temporary variables
    TVector2 met;

// <<< GetPhysicsObjects <<<

}}

    '''.format(name=name))

    fC.find_and_write_with_delete("if (fChain == 0) return;", '''
    // >>> "if (fChain == 0) return" anchor >>>
    // if(fChain == 0) return;
    cout << "I am in {name}.C " << endl;
    // Signal HANDLER
    signal (SIGINT, _fsig_handler); // signal handler has issues with CINT
    if (fChain == 0) {{
        cout <<"Error opening the data file"<<endl; return;
    }}
    int verboseFreq(aselect.verbfreq);

    map < string, int > syst_names;
    syst_names["01_jes"]       = 2;

    AnalysisController aCtrl(&aselect, syst_names);
    aCtrl.Initialize(extname);
    cout << "End of analysis initialization"<<endl;
    // <<< "if (fChain == 0) return" anchor <<<
    '''.format(name=name))
    fC.find_and_write_with_delete("Long64_t nentries = fChain->GetEntriesFast();", '''
    // >>> "Long64_t nentries" anchor >>>
    // Long64_t nentries =  fChain->GetEntriesFast();
    Long64_t nentries =  fChain->GetEntriesFast();

    if (aselect.maxEvents > 0 ) {
        nentries=aselect.maxEvents;
    }
    cout << "number of entries " << nentries << endl;
    Long64_t startevent = 0;
    if (aselect.startpt > 0 ) {
        startevent=aselect.startpt;
    }
    cout << "starting entry " << startevent << endl;
    Long64_t lastevent = startevent + nentries;
    if (lastevent > fChain->GetEntriesFast() ) {
        lastevent=fChain->GetEntriesFast();
        cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
    }
    cout << "last entry " << lastevent << endl;
    // <<< "Long64_t nentries" anchor <<<
    ''')
    fC.find_and_write_with_delete("for (Long64_t jentry=0; jentry<nentries;jentry++) {", '''
    // >>> "for (Long64_t jentry=0;jentry<nentries;jentry++) {" anchor >>>
    // for (Long64_t jentry=0;jentry<nentries;jentry++) {
    for (Long64_t j=startevent; j<lastevent; ++j) {

        if ( fctrlc ) { cout << "Processed " << j << " events"; break; }
        if (0 > LoadTree (j)) break;
        if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

        AnalysisObjects a0;
        GetPhysicsObjects(j, &a0, nentries);
        aCtrl.RunTasks(a0);
    }// event loop ends.

    aCtrl.Finalize();
        // <<< "for (Long64_t jentry=0;jentry<nentries;jentry++) {" anchor <<<
        /*
    ''')
    content = fC.content()
    fC.file.write(content+'''
*/
}
    ''')

    fC.find_and_write("// <<< GetPhysicsObjects <<<", '''
    DEBUG("Begin filling\\n")

___to_be_filled___

    //------------ auxiliary information -------
    anevt.run_no=runNumber;
    anevt.user_evt_weight=1.0;
    anevt.lumiblk_no=1;
    anevt.top_hfor_type=0;
    anevt.event_no=eventNumber;
    anevt.TRG_e= trigE;
    anevt.TRG_m= trigM;
    anevt.TRG_j= 0;
    anevt.vxp_maxtrk_no= 9;
    anevt.badjet=0;
    anevt.mcevt_weight=mcWeight;
    anevt.pileup_weight=1.0;
    anevt.z_vtx_weight = 1.0;
    anevt.weight_bTagSF_77 = scaleFactor_BTAG;
    anevt.weight_leptonSF = scaleFactor_LepTRIGGER;
    anevt.vxpType=0;
    anevt.lar_Error=0;
    anevt.core_Flags=0;
    anevt.maxEvents=nentries;

    DEBUG("Filling finished\\n")
    
    muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
    eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
    taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
    gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
    jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
    ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
    truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
    combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constits) );
    met_map.insert( pair <string,TVector2>             ("MET",           met) );

    *a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map, anevt};
    
    ''')

    fC.find_and_write_with_delete(
        loop_selector, "void "+name+"::Loop(analy_struct aselect, char *extname)")

    fC.file.close()

    fh = FILE_HELPER(templates_dir_with_name+"/"+name+".h")

    fh.find_and_write(
        "// Header file for the classes stored in the TTree if any.", '#include "dbxParticle.h"\n')

    fh.file.close()

    with open(templates_dir_with_name+"/variables.csv", 'w', encoding='UTF8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)
        f.close()

    variables = {
        'muon': {
            '_fields_': ['muon', 'mu']
        },
        'electron': {
            '_fields_': ['electron', 'ele']
        },
        'photon': {
            '_fields_': ['photon', 'pho']
        },
        'jet': {
            '_fields_': ['jet']
        },
        'tau': {
            '_fields_': ['tau']
        },
        'ljet': {
            '_fields_': ['fatjet']
        },
        'truth': {
            '_fields_': ['genpart']
        },
        'combo': {
            '_fields_': ['_combo_']
        },
        'constits': {
            '_fields_': ['_constits_']
        },
        'met': {
            '_fields_': ['met', 'missinget']
        },
    }
    usedRows = []
    usedRowsName = []  # for print
    unusedRows = []
    unusedRowsName = []  # for print

    with open(templates_dir_with_name+"/variables.csv", newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            isRowUsed = False
            var_typeName = row['type_name']       # example: Double_t
            var_branchName = row['branch_name']   # example: MyTree
            # example: electrons.fUniqueId
            var_name = row['name']
            # example: fUniqueId[electrons_]
            var_title = row['title']
            var_titleType = row['title_type']     # example: electrons_
            var_nData = row['n_data']             # example: 1
            for _var in variables.keys():
                for var in variables[_var]['_fields_']:
                    if var == var_titleType.lower()[1:] or var == var_titleType.lower()[2:] or var == var_titleType.lower()[:-1] or var == var_titleType.lower()[:-2]:
                        varType = var_title.split(
                            "[")[0].split("_")[-1].lower()
                        _varType = var_title.split("[")[0].split("_")
                        if len(_varType) == 1:
                            varType = var_title.split(
                                "[")[0].split(".")[-1].lower()
                            _varType = var_title.split(
                                "[")[0].split(".")
                        if len(_varType) == 1:
                            varType = var_title.split("[")[0].lower()
                            #print("There is a problem", "385743", row)
                            #sys.exit(0)
                        variables[_var][varType] = var_name
                        isRowUsed = True

            if not isRowUsed:
                for _var in variables.keys():
                    for var in variables[_var]['_fields_']:
                        if var == var_title[1:].lower():
                            variables[_var]["___"] = var_title
                            isRowUsed = True
                        elif var == var_title[:-1].lower():
                            variables[_var]["___"] = var_title
                            isRowUsed = True

            if not isRowUsed:
                for _var in variables.keys():
                    for var in variables[_var]['_fields_']:
                        if ("_" in var_title and var == var_title.split("_")[0].lower()) or ("." in var_title and var == var_title.split(".")[0].lower()):
                            varType = var_title.split("_")
                            if len(varType) == 1:
                                varType = var_title.split(".")
                            if len(varType) == 1:
                                print("There is a problem", "45993", row)
                                #sys.exit(0)
                            varType = varType[-1].lower()
                            variables[_var][varType] = var_name
                            isRowUsed = True

            if isRowUsed:
                usedRows.append({'type_name': var_typeName, 'branch_name': var_branchName, 'name': var_name,
                                'title': var_title, 'title_type': var_titleType, 'n_data': var_nData})
                usedRowsName.append(var_name)
            else:
                unusedRows.append({'type_name': var_typeName, 'branch_name': var_branchName,
                                  'name': var_name, 'title': var_title, 'title_type': var_titleType, 'n_data': var_nData})
                unusedRowsName.append(var_name)

        csvfile.close()

    with open(templates_dir_with_name+"/variables_used.csv", 'w', encoding='UTF8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(usedRows)
        f.close()

    with open(templates_dir_with_name+"/variables_unused.csv", 'w', encoding='UTF8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(unusedRows)
        f.close()

    with open(templates_dir_with_name+"/variables_use.json", 'w') as json_file:
        json.dump(variables, json_file, indent=4, sort_keys=True)
        json_file.close()

    #print("\n")
    #print("<<<<<<<<< usedRows <<<<<<<<<")
    #usedRowsName.sort()
    #print(usedRowsName)
    #print(">>>>>>>>> usedRows >>>>>>>>>")
    #print("\n")
    #print("<<<<<<<<< unusedRows <<<<<<<<<")
    #unusedRowsName.sort()
    #print(unusedRowsName)
    #print(">>>>>>>>> unusedRows >>>>>>>>>")
    #print("\n")
    #print("<<<<<<<<< variables <<<<<<<<<")
    #print(json.dumps(variables, sort_keys=True))
    #print(">>>>>>>>> variables >>>>>>>>>")

    fToBeFilled = open(filePath+"/templates/"+name +
                       "/"+name+"_to_be_filled.C", "w")
    fToBeFilled.close()
    fToBeFilled = FILE_HELPER(
        filePath+"/templates/"+name + "/"+name+"_to_be_filled.C")

    fToBeFilled.file.write(
        '''//////////////////////////////////////////////////////////
// This content for filled has been automatically generated on
// {now} by CutLang
// from TTree {treeName}/{treeTitle}
// found on file: {file}
//////////////////////////////////////////////////////////

    //temporary variables
    TLorentzVector  alv;
    //TLorentzVector dummyTlv(0.,0.,0.,0.);
'''.format(file=FILE, treeName=treeName, treeTitle=treeTitle, now=dateNow))

    def TLorentzVectorSetter(particle):
        alvTLorentzVector = ""
        if ("px" in particle and "py" in particle and "pz" in particle and "e" in particle):
            alvTLorentzVector = "alv.SetPxPyPzE("+particle["px"]+"[i], "+particle["py"] + \
                "[i], "+particle["pz"]+"[i], " + \
                particle["e"]+"[i]); // all in GeV"
        elif ("px" in particle and "py" in particle and "pz" in particle and "m" in particle):
            alvTLorentzVector = "alv.SetPxPyPzM("+particle["px"]+"[i], "+particle["py"] + \
                "[i], "+particle["pz"]+"[i], " + \
                particle["m"]+"[i]); // all in GeV"
        elif ("pt" in particle and "eta" in particle and "phi" in particle and "e" in particle):
            alvTLorentzVector = "alv.SetPtEtaPhiE("+particle["pt"]+"[i], "+particle["eta"] + \
                "[i], "+particle["phi"]+"[i], " + \
                particle["e"]+"[i]); // all in GeV"
        elif ("pt" in particle and "eta" in particle and "phi" in particle and "m" in particle):
            alvTLorentzVector = "alv.SetPtEtaPhiM("+particle["pt"]+"[i], "+particle["eta"] + \
                "[i], "+particle["phi"]+"[i],  " + \
                particle["m"]+"[i]); // all in GeV"
        elif ("px" in particle and "py" in particle and "pz" in particle):
            alvTLorentzVector = "alv.SetPxPyPzM("+particle["px"]+"[i], "+particle["py"] + \
                "[i], "+particle["pz"]+"[i],  (105.658/1E3)); // all in GeV"
        elif ("pt" in particle and "eta" in particle and "phi" in particle):
            alvTLorentzVector = "alv.SetPtEtaPhiM("+particle["pt"]+"[i], "+particle["eta"] + \
                "[i], "+particle["phi"]+"[i],  (105.658/1E3)); // all in GeV"
        return alvTLorentzVector

	#int setParticleIndx ( int );
	#int setTlv( TLorentzVector );
    #void setPPPE(float px, float py, float pz, float Ee ){p_lvector.SetPxPyPzE(px, py, pz, Ee ); }
	#void setAttribute(int k, double v) {
    #              if (k>(int)p_attribute.size()) { std::cerr<<"NO Such Attribute! Use addAttribute first.\n";
    #              } else { p_attribute[k]=v; }
    #    }
    dbxParticleSetList = ["Charge", "PdgID", "EtCone", "PtCone", "Flavor", "IsTight", "ScaleFactor", "ScaleFactorReco", "ScaleFactorId", "ScaleFactorTrig", "ScaleFactorTrigMcEff",
                          "ScaleFactorIso", "ScaleFactorUncertainty", "ScaleFactorUncertaintyUp", "ScaleFactorUncertaintyDown", "ScaleFactorUncertaintyDown", "scaleLorentzVector", "Z0"]
    dbxAllParticleSetList = {
        "muon": ["MuTriggerMatch", "MuIdTheta", "MuIdPhi", "TopMuInTrigger", "PtMsup", "PtMsdown", "PtIdup", "PtIddown", "PtScup", "PtScdown",
                 "d0", "delta_z0_sintheta", "true_type", "true_origin", "trigMatch_HLT_mu26_ivarmedium", "trigMatch_HLT_mu50", "trigMatch_HLT_mu20_iloose_L1MU15", "isZCand"],
        "electron": ["ElTriggerDR", "ElTriggerMatch", "TrkTheta", "TrkEta", "TrkPhi", "BestEt", "PtCone30", "EtCone20", "Ep_elE_up", "Ep_elE_down",
                     "ClusterE", "ClusterEta", "d0sig", "delta_z0_sintheta", "true_type", "true_origin", "true_typebkg", "true_originbkg", "trigMatch_HLT_e60_lhmedium_nod0", "trigMatch_HLT_e26_lhtight_nod0_ivarloose", "trigMatch_HLT_e140_lhloose_nod0", "trigMatch_HLT_e60_lhmedium", "trigMatch_HLT_e24_lhmedium_L1EM20VH", "trigMatch_HLT_e120_lhloose", "isZCand"],
        "photon": ["ElTriggerDR", "ElTriggerMatch", "TrkTheta", "TrkEta", "TrkPhi", "BestEt", "PtCone30", "EtCone20", "Ep_elE_up", "Ep_elE_down",
                   "ClusterE", "ClusterEta"],
        #void setNocalibjet       (TLorentzVector lv){p_Nocalibjet=lv; }
        "jet": ["Sv0mass", "Sv0nt2", "Sv0svok", "Sv0ntrk", "Sv0ntrkv", "Sv0ntrkj", "Sv0efrc", "JVtxf", "EmEta", "EmPhi",
                "EtaCorr", "JesuRelativePos", "JesuRelativeNeg", "JerUncert", "JetFrac", "JLabel", "Jee_status", "Calibjetscale", "BJetEscalePos", "BJetEscaleNeg",
                "_isbtagged_77", "_isTautagged", "mv2c00", "mv2c10", "mv2c20", "ip3dsv1", "jvt", "truthflav", "isTrueHS"],
        "tau": ["Isolation"],
        "ljet": [],
        "truth": []
    }

    def adbx_fill(var_particle, particleSize, particleName, _adbxName):
        _adbxSetSomethingOrAddAttribute = ""
        for var in var_particle:
            if var == "_fields_" or var_particle[var] == particleSize:
                continue
            if var in list(map(lambda x: x.lower(), dbxParticleSetList)):
                index = list(
                    map(lambda x: x.lower(), dbxParticleSetList)).index(var)
                _adbxSetSomethingOrAddAttribute += _adbxName+"->set" + \
                    dbxParticleSetList[index] + \
                    "("+var_particle[var]+"[i]);\n\t\t"
            elif var in list(map(lambda x: x.lower(), dbxAllParticleSetList[particleName])):
                index = list(
                    map(lambda x: x.lower(), dbxAllParticleSetList[particleName])).index(var)
                _adbxSetSomethingOrAddAttribute += _adbxName+"->set" + \
                    dbxAllParticleSetList[particleName][index] + \
                    "("+var_particle[var]+"[i]);\n\t\t"
            else:
                if var != "px" and var != "py" and var != "pz" and var != "e" and var != "pt" and var != "eta" and var != "phi" and var != "m":
                    _adbxSetSomethingOrAddAttribute += _adbxName+"->addAttribute(" + \
                        var_particle[var]+"[i]);\n\t\t"
        return _adbxSetSomethingOrAddAttribute

    def fill_something_with_event_size(particleName, __adbxName, _dbxName):
        def getParticleNotFound(message):
            return '''
    /*
    {message}
    // >>> {particleNameUpper} >>>

    {_dbxName} *{__adbxName};
    for (unsigned int i=0; i<n{particleNameUpper}_example; i++) {{
        _alv_example.SetPtEtaPhiM(Muon_pt_example[i], Muon_eta_example[i], Muon_phi_example[i],  (105.658/1E3)_example); // all in GeV

        {__adbxName} = new {_dbxName}(alv);

        {__adbxName}_example->addAttribute(PARTICLE_dxy_example[i]);
        {__adbxName}_example->setCharge(PARTICLE_charge_example[i]);

        {__adbxName}->setParticleIndx(i);
        {particleNameLower}s.push_back(*{__adbxName});
        delete {__adbxName};
    }}

    DEBUG("{particleNameUpper} OK\\n")

    // <<< {particleNameUpper} <<<
    {message}
    */
                    '''.format(message=message, _dbxName=_dbxName, particleNameLower=particleName.lower(), particleNameUpper=particleName.upper(), __adbxName=__adbxName)
        var_particle = variables[particleName]
        if len(var_particle) > 1:
            if ("size" in var_particle or "___" in var_particle):
                particleSize = ""
                if "size" in var_particle:
                    particleSize = var_particle["size"]
                else:
                    particleSize = var_particle["___"]
                if not ("px" not in var_particle and "py" not in var_particle and "pz" not in var_particle and "e" not in var_particle and "eta" not in var_particle and "phi" not in var_particle and "m" not in var_particle):
                    alvTLorentzVector = TLorentzVectorSetter(var_particle)
                    if len(alvTLorentzVector) == 0:
                        print(particleName+" tlorentzvector problem")
                    else:
                        adbxSetSomethingOrAddAttribute = adbx_fill(
                            var_particle, particleSize, particleName, __adbxName)

                        fToBeFilled.file.write('''
    // >>> {particleNameUpper} >>>

    {_dbxName} *{__adbxName};
    for (unsigned int i=0; i<{particleSize}; i++) {{
        {alvTLorentzVector}

        {__adbxName} = new {_dbxName}(alv);

        {adbxSetSomethingOrAddAttribute}

        {__adbxName}->setParticleIndx(i);
        {particleNameLower}s.push_back(*{__adbxName});
        delete {__adbxName};
    }}

    DEBUG("{particleNameUpper} OK\\n")

    // <<< {particleNameUpper} <<<
                        '''.format(_dbxName=_dbxName, particleNameLower=particleName.lower(), particleNameUpper=particleName.upper(), particleSize=particleSize, alvTLorentzVector=alvTLorentzVector, adbxSetSomethingOrAddAttribute=adbxSetSomethingOrAddAttribute, __adbxName=__adbxName))
                else:
                    notFoundMessage = particleName+" px,py,pz,e,eta,phi,m not found!"
                    fToBeFilled.file.write(
                        getParticleNotFound(notFoundMessage))
                    print(notFoundMessage)

            else:
                notFoundMessage = particleName+" size not found!"
                fToBeFilled.file.write(getParticleNotFound(notFoundMessage))
                print(notFoundMessage)
        else:
            notFoundMessage = particleName+" not found!!!"
            fToBeFilled.file.write(getParticleNotFound(notFoundMessage))
            print(notFoundMessage)
    #muon -> muon
    fill_something_with_event_size("muon", "adbxm", "dbxMuon")

    #electron -> electron
    fill_something_with_event_size("electron", "adbxe", "dbxElectron")

    #photon -> photon
    fill_something_with_event_size("photon", "adbxp", "dbxPhoton")

    #jet -> jet
    fill_something_with_event_size("jet", "adbxj", "dbxJet")

    #tau -> tau
    fill_something_with_event_size("tau", "adbxt", "dbxTau")

    #ljet -> fatjet
    fill_something_with_event_size("ljet", "adbxj", "dbxJet")

    #truth -> genPart
    fill_something_with_event_size("truth", "adbxgen", "dbxTruth")

    #combo -> ???

    #constits -> ???

    #met -> met (et,phi | px,py | met,phi | pt,phi)
    var_met = variables["met"]
    if "et" in var_met and "phi" in var_met:
        fToBeFilled.file.write('''
    // >>> MET >>>
    met.SetMagPhi({et},  {phi}); //mev-->gev
    // <<< MET <<<
        '''.format(et=var_met["et"], phi=var_met["phi"]))
    elif "px" in var_met and "py" in var_met:
        fToBeFilled.file.write('''
    // >>> MET >>>
    met.SetMagPhi({px},  {py}); //mev-->gev
    // <<< MET <<<
        '''.format(px=var_met["px"], py=var_met["py"]))
    elif "met" in var_met and "phi" in var_met:
        fToBeFilled.file.write('''
    // >>> MET >>>
    met.SetMagPhi({met},  {phi}); //mev-->gev
    // <<< MET <<<
        '''.format(met=var_met["met"], phi=var_met["phi"]))
    elif "pt" in var_met and "phi" in var_met:
        fToBeFilled.file.write('''
    // >>> MET >>>
    met.SetMagPhi({pt},  {phi}); //mev-->gev
    // <<< MET <<<
        '''.format(pt=var_met["pt"], phi=var_met["phi"]))
    else:
        fToBeFilled.file.write('''
    /*
    Met variables not found!!!
    // >>> MET >>>
    met.SetMagPhi({pt},  {phi}); //mev-->gev
    // <<< MET <<<
    Met variables not found!!!
    */
        '''.format(pt=var_met["pt"], phi=var_met["phi"]))
        print("Met variables not found!!!")

    fToBeFilledContent=fToBeFilled.file.read()
    fToBeFilled.file.write(fToBeFilledContent+"\n// FILLED CONTENT END")

    fToBeFilled.file.close()

    print(" ********** "+name+" template created at " +
          templates_dir_with_name+" ********** ")
    if recreate:
        print(" ********** "+"old template was moved to " +
              templates_dir_with_name+"/history/"+dateNow+" ********** ")


def save_template():
    if not name:
        print("save option needs name option!")
        sys.exit(0)

    fC_to_be_filled = open(filePath+"/templates/"+name +
                           "/"+name+"_to_be_filled.C", "r")
    contentC_to_be_filled = fC_to_be_filled.read()
    fC_to_be_filled.close()

    fC = open(filePath+"/templates/"+name +
                       "/"+name+".C", "r")
    contentC = fC.read()
    contentC = contentC.replace("___to_be_filled___", contentC_to_be_filled)
    fC.close()

    fh = open(filePath+"/templates/"+name +
                       "/"+name+".h", "r")
    contenth = fh.read()
    fh.close()

    fC_new = open(c_file, "w")
    fC_new.write(contentC)
    print("saved "+c_file)
    fC_new.close()

    fC_new = open(h_file, "w")
    fC_new.write(contenth)
    print("saved "+h_file)
    fC_new.close()

def delete_template():
    if not name:
        print("delete option needs name option!")
        sys.exit(0)
    # remove exist c_file
    if os.path.exists(c_file):
        os.remove(c_file)
        print("deleted "+c_file)
    else:
        print("nothing "+c_file)

    # remove exist h_file
    if os.path.exists(h_file):
        os.remove(h_file)
        print("deleted "+h_file)
    else:
        print("nothing "+h_file)

if create:
    create_template()
elif save:
    save_template()
elif delete:
    delete_template()
else:
    print("nothing, please get help from 'python3 addntuple.py -h'")