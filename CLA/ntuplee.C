#define ntuplee_cxx
#include "ntuplee.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <signal.h>

#include <TObject.h>
#include <TBranchElement.h>

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

std::map<std::string, std::string> mapOfCommonLeaves;

std::map<std::string, std::string> mapOfLeavesTypes;
std::map<std::string, Int_t *> mapOfLeavesInt_t;
std::map<std::string, Float_t *> mapOfLeavesFloat_t;
std::map<std::string, Bool_t *> mapOfLeavesBool_t;

template <typename T>
void SetBranch(const char *branchName, TTree *fChain, std::string token_type){
       TBranch* b_branchGetter;
       //T branchGetter[50];
       Int_t branchGetter[50];
       /*if(token_type == "F")
              if(mapOfLeavesFloat_t.count(branchName)!=0) return mapOfLeavesFloat_t[branchName];
       else if(token_type == "I")
              if(mapOfLeavesInt_t.count(branchName)!=0) return mapOfLeavesInt_t[branchName];
       else if(token_type == "O")
              if(mapOfLeavesBool_t.count(branchName)!=0) return mapOfLeavesBool_t[branchName];*/
       fChain->SetBranchAddress(branchName, branchGetter, &b_branchGetter);
       if(token_type == "F")
              mapOfLeavesInt_t[branchName]=branchGetter;
       else if(token_type == "I")
              mapOfLeavesInt_t[branchName]=branchGetter;
       else if(token_type == "O")
              mapOfLeavesInt_t[branchName]=branchGetter;
       //std::cout << *b_branchGetter->GetName();
};

template <typename T>
void setBranchAddress(const char *branchName, TTree *fChain, T branchGetter, TBranch *b_branchGetter){
       fChain->SetBranchAddress(branchName, branchGetter, &b_branchGetter);
}

void setBranchAddressa(){
       int a;
}

void ntuplee::Loop(analy_struct aselect)
{
       // Signal HANDLER
       signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

       int verboseFreq(aselect.verbfreq);
       evt_data anevt;
       map<string, string> syst_names;

       AnalysisController aCtrl(&aselect, syst_names);
       aCtrl.Initialize();
       cout << "End of analysis initialization" << endl;

       // >>>AUTO
       if (fChain == 0) return;

       Long64_t nentries = fChain->GetEntriesFast();

       Long64_t nbytes = 0, nb = 0;
       // <<<AUTO
       
       Long64_t nentinfile=nentries;
       cout << "number of entries " << nentries << endl;
       if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
       cout << "Forced number of entries " << nentries << endl;
       Long64_t startevent = 0;
       if (aselect.startpt>0 ) startevent=aselect.startpt;
       cout << "starting entry " << startevent << endl;
       Long64_t lastevent = startevent + nentries;
       if (lastevent > nentinfile ) { lastevent=nentinfile;
              cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
       }

       // >>>MAPFILLER
       TObjArray *fChainList = fChain->GetListOfBranches(); // NMuon, NElectron, etc.
       for (int i = 0; i < fChainList->GetEntriesFast(); i++)
       {
              TObject *fChainObj = fChainList->At(i);

              std::string name = fChainObj->GetName(); // Photon_E
              std::string title = fChainObj->GetTitle(); // Photon_E[NPhoton]/F

              //std::cout << "fast " << name << " " << title << " fast" << std::endl;

              std::string delimiter = "/";
              std::string token_first_first = title.substr(0, title.find(delimiter)); // Photon_E[NPhoton]/F -> Photon_E[NPhoton]
              std::string token_type = title.substr(title.find(delimiter)+1); // Photon_E[NPhoton]/F -> F
              std::string delimiter2 = "[";
              std::string token_first_second = token_first_first.substr(0, token_first_first.find(delimiter2)); // Photon_E[NPhoton] -> Photon_E
              if (token_first_first.find(delimiter2) != std::string::npos){
                     std::string token_second = token_first_first.substr(token_first_first.find(delimiter2)+1, token_first_first.length()-token_first_second.length()-2); // Photon_E[NPhoton] -> NPhoton
                     //std::cout << "token_second " << token_second << " token_second " << token_first_first.length() << std::endl;
              }
              //std::cout << "token_first_first " << token_first_first << " " << token_type << " " << token_first_second << " token_first_first" << std::endl;

              if(token_type=="F"){
                     //SetBranch<Float_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesFloat_t[token_first_second];
              }else if(token_type=="I"){
                     //SetBranch<Int_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesInt_t[token_first_second];

                     /*TBranch* b_branchGetter;
                     Int_t branchGetter[50];
                     fChain->SetBranchAddress(token_first_second.c_str(), branchGetter, &b_branchGetter);
                     mapOfLeavesInt_t[token_first_second.c_str()]=branchGetter;*/
              }else if(token_type=="O"){
                     //SetBranch<Bool_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesBool_t[token_first_second];
              }else{
                     std::cout << "!!!! Token type not found, TOKEN TYPE=" << token_type << " TOKEN TITLE=" << title << std::endl;
              }
       }
       // <<<MAPFILLER

       int n=0;
       label:
              TObject *fChainObj = fChainList->At(n);

              std::string name = fChainObj->GetName(); // Photon_E
              std::string title = fChainObj->GetTitle(); // Photon_E[NPhoton]/F
              
              //std::cout << "fast " << name << " " << title << " fast" << std::endl;

              std::string delimiter = "/";
              std::string token_first_first = title.substr(0, title.find(delimiter)); // Photon_E[NPhoton]/F -> Photon_E[NPhoton]
              std::string token_type = title.substr(title.find(delimiter)+1); // Photon_E[NPhoton]/F -> F
              std::string delimiter2 = "[";
              std::string token_first_second = token_first_first.substr(0, token_first_first.find(delimiter2)); // Photon_E[NPhoton] -> Photon_E
              int tkn_scnd=0;
              if (token_first_first.find(delimiter2) != std::string::npos){
                     tkn_scnd=1;
                     std::string token_second = token_first_first.substr(token_first_first.find(delimiter2)+1, token_first_first.length()-token_first_second.length()-2); // Photon_E[NPhoton] -> NPhoton
                     //std::cout << "token_second " << token_second << " token_second " << token_first_first.length() << std::endl;
              }
              //std::cout << "token_first_first " << token_first_first << " " << token_type << " " << token_first_second << " token_first_first" << std::endl;

              int _F=0;
              int _I=0;
              int _O=0;
              if(token_type=="F") _F=0;
              if(token_type=="I") _I=1;
              if(token_type=="O") _O=1;

              /*TBranch* b_branchGetter_Float_t_;
              Float_t branchGetter_Float_t_[50];
              cout << token_first_second.c_str() << " branchi eklendi" << endl;
              (_I == 1) ? setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Float_t_, b_branchGetter_Float_t_) : setBranchAddressa();
              mapOfLeavesFloat_t[token_first_second.c_str()]=branchGetter_Float_t_;

              TBranch* b_branchGetter_Int_t_;
              Int_t branchGetter_Int_t_[50];
              (_I == 1) ? setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Int_t_, b_branchGetter_Int_t_) : setBranchAddressa();
              mapOfLeavesInt_t[token_first_second.c_str()]=branchGetter_Int_t_;

              TBranch* b_branchGetter_Bool_t_;
              Bool_t branchGetter_Bool_t_[50];
              (_I == 1) ? setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Bool_t_, b_branchGetter_Bool_t_) : setBranchAddressa();
              mapOfLeavesBool_t[token_first_second.c_str()]=branchGetter_Bool_t_;*/
              
              
              TBranch* b_branchGetter_Int_t_;
              Int_t branchGetter_Int_t_[50];
              (_I == 1) ? setBranchAddress("Electron_Charge", fChain, branchGetter_Int_t_, b_branchGetter_Int_t_) : setBranchAddressa();
              mapOfLeavesInt_t[token_first_second.c_str()]=branchGetter_Int_t_;

              if(token_type=="F"){
                     //SetBranch<Float_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesFloat_t[token_first_second];
                     /*TBranch* b_branchGetter_Float_t_;
                     Float_t branchGetter_Float_t_[50];
                     setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Float_t_, b_branchGetter_Float_t_);
                     mapOfLeavesFloat_t[token_first_second.c_str()]=branchGetter_Float_t_;*/
              }else if(token_type=="I"){
                     //SetBranch<Int_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesInt_t[token_first_second];

                     /*TBranch* b_branchGetter_Int_t_;
                     Int_t branchGetter_Int_t_[50];
                     setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Int_t_, b_branchGetter_Int_t_);
                     mapOfLeavesInt_t[token_first_second.c_str()]=branchGetter_Int_t_;*/
              }else if(token_type=="O"){
                     //SetBranch<Bool_t>(token_first_second.c_str(), fChain, token_type);
                     //std::cout << mapOfLeavesBool_t[token_first_second];
                     /*TBranch* b_branchGetter_Bool_t_;
                     Bool_t branchGetter_Bool_t_[50];
                     setBranchAddress(token_first_second.c_str(), fChain, branchGetter_Bool_t_, b_branchGetter_Bool_t_);
                     mapOfLeavesBool_t[token_first_second.c_str()]=branchGetter_Bool_t_;*/
              }else{
                     std::cout << "!!!! Token type not found, TOKEN TYPE=" << token_type << " TOKEN TITLE=" << title << std::endl;
              }
              
              /*string token;
              TBranch* b_NMuon;
              Int_t NMuon[20];
              token = "NMuon";
              fChain->SetBranchAddress(token.c_str(), NMuon, &b_NMuon);
              mapOfLeavesInt_t[token.c_str()]=NMuon;*/
              n++;
              if (n < fChainList->GetEntriesFast())
                     goto label;
       
       //SetBranch<Int_t>("NMuon", fChain, "I");

       // >>>AUTO
       //for (Long64_t jentry=0; jentry<nentries;jentry++) {
       for (Long64_t je=startevent; je<lastevent; ++je) {
              
              if ( fctrlc ) { cout << "Processed " << je << " events\n"; break; }
              if ( je%verboseFreq == 0 ) cout << "Processing event " << je << endl;
              DEBUG("Read Event"<<std::endl);

              // >>>AUTO
              /*
              Long64_t ientry = LoadTree(jentry);
              if (ientry < 0) break;
              nb = fChain->GetEntry(jentry);   nbytes += nb;
              // if (Cut(ientry) < 0) continue;
              */
              // <<<AUTO

              fChain->GetEntry(je);

              vector<dbxMuon> muons;
              vector<dbxElectron> electrons;
              vector<dbxTau> taus;
              vector<dbxPhoton> photons;
              vector<dbxJet> jets;
              vector<dbxJet> ljets;
              vector<dbxTruth> truth;
              vector<dbxTrack> track;
              vector<dbxParticle> combos;
              vector<dbxParticle> constis;
              TVector2 met;

              map<string, vector<dbxMuon>> muos_map;
              map<string, vector<dbxElectron>> eles_map;
              map<string, vector<dbxTau>> taus_map;
              map<string, vector<dbxPhoton>> gams_map;
              map<string, vector<dbxJet>> jets_map;
              map<string, vector<dbxJet>> ljets_map;
              map<string, vector<dbxTruth>> truth_map;
              map<string, vector<dbxTrack>> track_map;
              map<string, vector<dbxParticle>> combo_map;
              map<string, vector<dbxParticle>> constits_map;
              map<string, TVector2>  met_map;

              TLorentzVector alv;

              dbxJet *adbxj;
              dbxElectron *adbxe;
              dbxMuon *adbxm;
              dbxTau *adbxt;
              dbxPhoton *adbxp;
              //dbxTruth *adbxgen;

              DEBUG("Begin Filling"<<std::endl);


              cout << mapOfLeavesInt_t["Electron_Charge"][0];
              //       



       }
       //}
       // <<<AUTO
}
