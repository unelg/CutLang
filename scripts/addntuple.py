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
from ROOT import TFile, gInterpreter, gSystem, gROOT
import csv
import os
import datetime
import json

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

full_path = os.path.realpath(__file__)
filePath, fileName = os.path.split(full_path)
workPath = os.path.dirname(filePath)

# Create (or delete) the c file for the new ntuple
c_file = workPath+'/CLA/'+name+'.C'
h_file = workPath+'/analysis_core/'+name+'.h'

templates_dir = filePath+'/templates'
templates_dir_with_name = filePath+'/templates/'+name


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


def create_template():
    if not FILE:
        print("create option needs file option!")
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
'''.format(file=FILE, treeName=treeName, treeTitle=treeTitle, now=datetime.datetime.now())+content)

    loop_selector = "void "+name+"::Loop()"

    fC.find_and_write(loop_selector, '''
// >>> "include" anchor >>>
#include <signal.h>
#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
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
void {name}::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0 )
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
    TLorentzVector  alv;
    //TLorentzVector dummyTlv(0.,0.,0.,0.);
    TVector2 met;
    dbxJet      *adbxj;
    dbxElectron *adbxe;
    dbxMuon     *adbxm;
    dbxPhoton   *adbxp;

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
        GetPhysicsObjects(j, &a0);
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

    {to_be_filled}

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

    #muon -> muon
    #electron -> electron
    #photon -> photon
    #jet -> jet
    #tau -> tau
    #ljet -> fatjet
    #truth -> genPart
    #combo ->
    #constits ->
    #met -> met

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
                        if len(varType) == 1:
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

    print("\n")
    print("<<<<<<<<< usedRows <<<<<<<<<")
    usedRowsName.sort()
    print(usedRowsName)
    print(">>>>>>>>> usedRows >>>>>>>>>")
    print("\n")
    print("<<<<<<<<< unusedRows <<<<<<<<<")
    unusedRowsName.sort()
    print(unusedRowsName)
    print(">>>>>>>>> unusedRows >>>>>>>>>")
    print("\n")
    print("<<<<<<<<< variables <<<<<<<<<")
    print(json.dumps(variables, sort_keys=True))
    print(">>>>>>>>> variables >>>>>>>>>")

    fToBeFilled = open(filePath+"/templates/"+name +
                       "/"+name+"_to_be_filled.C", "w")
    fToBeFilled.close()
    fToBeFilled = FILE_HELPER(
        filePath+"/templates/"+name + "/"+name+"_to_be_filled.C")

    fToBeFilled.file.write(
        '''
// !!!TEMP!!!
#ifdef __DEBUG__
std::cout << "FatJets:"<<nFatJet<<std::endl;
#endif
// !!!TEMP!!!
'''
    )

    fToBeFilled.file.close()


if create:
    create_template()
