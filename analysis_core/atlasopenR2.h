//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun 21 10:57:18 2021 by ROOT version 6.22/02
// from TTree mini/mini
// found on file: data_A.GamGam.root
//////////////////////////////////////////////////////////

#ifndef atlasopenR2_h
#define atlasopenR2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "dbxParticle.h"

#include <iostream>
using namespace std;

class atlasopenR2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runNumber;
   Int_t           eventNumber;
   Int_t           channelNumber;
   Float_t         mcWeight;
   Float_t         scaleFactor_PILEUP;
   Float_t         scaleFactor_ELE;
   Float_t         scaleFactor_MUON;
   Float_t         scaleFactor_PHOTON;
   Float_t         scaleFactor_TAU;
   Float_t         scaleFactor_BTAG;
   Float_t         scaleFactor_LepTRIGGER;
   Float_t         scaleFactor_PhotonTRIGGER;
   Bool_t          trigE;
   Bool_t          trigM;
   Bool_t          trigP;
   UInt_t          lep_n;
   vector<bool>    *lep_truthMatched;
   vector<bool>    *lep_trigMatched;
   vector<float>   *lep_pt;
   vector<float>   *lep_eta;
   vector<float>   *lep_phi;
   vector<float>   *lep_E;
   vector<float>   *lep_z0;
   vector<int>     *lep_charge;
   vector<unsigned int> *lep_type;
   vector<bool>    *lep_isTightID;
   vector<float>   *lep_ptcone30;
   vector<float>   *lep_etcone20;
   vector<float>   *lep_trackd0pvunbiased;
   vector<float>   *lep_tracksigd0pvunbiased;
   Float_t         met_et;
   Float_t         met_phi;
   UInt_t          jet_n;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_E;
   vector<float>   *jet_jvt;
   vector<int>     *jet_trueflav;
   vector<bool>    *jet_truthMatched;
   vector<float>   *jet_MV2c10;
   UInt_t          photon_n;
   vector<bool>    *photon_truthMatched;
   vector<bool>    *photon_trigMatched;
   vector<float>   *photon_pt;
   vector<float>   *photon_eta;
   vector<float>   *photon_phi;
   vector<float>   *photon_E;
   vector<bool>    *photon_isTightID;
   vector<float>   *photon_ptcone30;
   vector<float>   *photon_etcone20;
   vector<int>     *photon_convType;
   UInt_t          tau_n;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_E;
   vector<bool>    *tau_isTightID;
   vector<bool>    *tau_truthMatched;
   vector<bool>    *tau_trigMatched;
   vector<int>     *tau_nTracks;
   vector<float>   *tau_BDTid;
   Float_t         ditau_m;
   vector<float>   *lep_pt_syst;
   Float_t         met_et_syst;
   vector<float>   *jet_pt_syst;
   vector<float>   *photon_pt_syst;
   vector<float>   *tau_pt_syst;
   Float_t         XSection;
   Float_t         SumWeights;
   UInt_t          largeRjet_n;
   vector<float>   *largeRjet_pt;
   vector<float>   *largeRjet_eta;
   vector<float>   *largeRjet_phi;
   vector<float>   *largeRjet_E;
   vector<float>   *largeRjet_m;
   vector<float>   *largeRjet_truthMatched;
   vector<float>   *largeRjet_D2;
   vector<float>   *largeRjet_tau32;
   vector<float>   *largeRjet_pt_syst;
   vector<int>     *tau_charge;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_channelNumber;   //!
   TBranch        *b_mcWeight;   //!
   TBranch        *b_scaleFactor_PILEUP;   //!
   TBranch        *b_scaleFactor_ELE;   //!
   TBranch        *b_scaleFactor_MUON;   //!
   TBranch        *b_scaleFactor_PHOTON;   //!
   TBranch        *b_scaleFactor_TAU;   //!
   TBranch        *b_scaleFactor_BTAG;   //!
   TBranch        *b_scaleFactor_LepTRIGGER;   //!
   TBranch        *b_scaleFactor_PhotonTRIGGER;   //!
   TBranch        *b_trigE;   //!
   TBranch        *b_trigM;   //!
   TBranch        *b_trigP;   //!
   TBranch        *b_lep_n;   //!
   TBranch        *b_lep_truthMatched;   //!
   TBranch        *b_lep_trigMatched;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_E;   //!
   TBranch        *b_lep_z0;   //!
   TBranch        *b_lep_charge;   //!
   TBranch        *b_lep_type;   //!
   TBranch        *b_lep_isTightID;   //!
   TBranch        *b_lep_ptcone30;   //!
   TBranch        *b_lep_etcone20;   //!
   TBranch        *b_lep_trackd0pvunbiased;   //!
   TBranch        *b_lep_tracksigd0pvunbiased;   //!
   TBranch        *b_met_et;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_jet_n;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_trueflav;   //!
   TBranch        *b_jet_truthMatched;   //!
   TBranch        *b_jet_MV2c10;   //!
   TBranch        *b_photon_n;   //!
   TBranch        *b_photon_truthMatched;   //!
   TBranch        *b_photon_trigMatched;   //!
   TBranch        *b_photon_pt;   //!
   TBranch        *b_photon_eta;   //!
   TBranch        *b_photon_phi;   //!
   TBranch        *b_photon_E;   //!
   TBranch        *b_photon_isTightID;   //!
   TBranch        *b_photon_ptcone30;   //!
   TBranch        *b_photon_etcone20;   //!
   TBranch        *b_photon_convType;   //!
   TBranch        *b_tau_n;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_E;   //!
   TBranch        *b_tau_isTightID;   //!
   TBranch        *b_tau_truthMatched;   //!
   TBranch        *b_tau_trigMatched;   //!
   TBranch        *b_tau_nTracks;   //!
   TBranch        *b_tau_BDTid;   //!
   TBranch        *b_ditau_m;   //!
   TBranch        *b_lep_pt_syst;   //!
   TBranch        *b_met_et_syst;   //!
   TBranch        *b_jet_pt_syst;   //!
   TBranch        *b_photon_pt_syst;   //!
   TBranch        *b_tau_pt_syst;   //!
   TBranch        *b_XSection;   //!
   TBranch        *b_SumWeights;   //!
   TBranch        *b_largeRjet_n;   //!
   TBranch        *b_largeRjet_pt;   //!
   TBranch        *b_largeRjet_eta;   //!
   TBranch        *b_largeRjet_phi;   //!
   TBranch        *b_largeRjet_E;   //!
   TBranch        *b_largeRjet_m;   //!
   TBranch        *b_largeRjet_truthMatched;   //!
   TBranch        *b_largeRjet_D2;   //!
   TBranch        *b_largeRjet_tau32;   //!
   TBranch        *b_largeRjet_pt_syst;   //!
   TBranch        *b_tau_charge;   //!

   atlasopenR2(char *file_name, TChain *tree=0);
   virtual ~atlasopenR2();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
};

#endif

#ifdef atlasopenR2_cxx
atlasopenR2::atlasopenR2(char *file_name, TChain *tree) : fChain(0)
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("mini");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }
}

atlasopenR2::~atlasopenR2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t atlasopenR2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t atlasopenR2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void atlasopenR2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   lep_truthMatched = 0;
   lep_trigMatched = 0;
   lep_pt = 0;
   lep_eta = 0;
   lep_phi = 0;
   lep_E = 0;
   lep_z0 = 0;
   lep_charge = 0;
   lep_type = 0;
   lep_isTightID = 0;
   lep_ptcone30 = 0;
   lep_etcone20 = 0;
   lep_trackd0pvunbiased = 0;
   lep_tracksigd0pvunbiased = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_E = 0;
   jet_jvt = 0;
   jet_trueflav = 0;
   jet_truthMatched = 0;
   jet_MV2c10 = 0;
   photon_truthMatched = 0;
   photon_trigMatched = 0;
   photon_pt = 0;
   photon_eta = 0;
   photon_phi = 0;
   photon_E = 0;
   photon_isTightID = 0;
   photon_ptcone30 = 0;
   photon_etcone20 = 0;
   photon_convType = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_E = 0;
   tau_isTightID = 0;
   tau_truthMatched = 0;
   tau_trigMatched = 0;
   tau_nTracks = 0;
   tau_BDTid = 0;
   lep_pt_syst = 0;
   jet_pt_syst = 0;
   photon_pt_syst = 0;
   tau_pt_syst = 0;
   largeRjet_pt = 0;
   largeRjet_eta = 0;
   largeRjet_phi = 0;
   largeRjet_E = 0;
   largeRjet_m = 0;
   largeRjet_truthMatched = 0;
   largeRjet_D2 = 0;
   largeRjet_tau32 = 0;
   largeRjet_pt_syst = 0;
   tau_charge = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("channelNumber", &channelNumber, &b_channelNumber);
   fChain->SetBranchAddress("mcWeight", &mcWeight, &b_mcWeight);
   fChain->SetBranchAddress("scaleFactor_PILEUP", &scaleFactor_PILEUP, &b_scaleFactor_PILEUP);
   fChain->SetBranchAddress("scaleFactor_ELE", &scaleFactor_ELE, &b_scaleFactor_ELE);
   fChain->SetBranchAddress("scaleFactor_MUON", &scaleFactor_MUON, &b_scaleFactor_MUON);
   fChain->SetBranchAddress("scaleFactor_PHOTON", &scaleFactor_PHOTON, &b_scaleFactor_PHOTON);
   fChain->SetBranchAddress("scaleFactor_TAU", &scaleFactor_TAU, &b_scaleFactor_TAU);
   fChain->SetBranchAddress("scaleFactor_BTAG", &scaleFactor_BTAG, &b_scaleFactor_BTAG);
   fChain->SetBranchAddress("scaleFactor_LepTRIGGER", &scaleFactor_LepTRIGGER, &b_scaleFactor_LepTRIGGER);
   fChain->SetBranchAddress("scaleFactor_PhotonTRIGGER", &scaleFactor_PhotonTRIGGER, &b_scaleFactor_PhotonTRIGGER);
   fChain->SetBranchAddress("trigE", &trigE, &b_trigE);
   fChain->SetBranchAddress("trigM", &trigM, &b_trigM);
   fChain->SetBranchAddress("trigP", &trigP, &b_trigP);
   fChain->SetBranchAddress("lep_n", &lep_n, &b_lep_n);
   fChain->SetBranchAddress("lep_truthMatched", &lep_truthMatched, &b_lep_truthMatched);
   fChain->SetBranchAddress("lep_trigMatched", &lep_trigMatched, &b_lep_trigMatched);
   fChain->SetBranchAddress("lep_pt", &lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_E", &lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_z0", &lep_z0, &b_lep_z0);
   fChain->SetBranchAddress("lep_charge", &lep_charge, &b_lep_charge);
   fChain->SetBranchAddress("lep_type", &lep_type, &b_lep_type);
   fChain->SetBranchAddress("lep_isTightID", &lep_isTightID, &b_lep_isTightID);
   fChain->SetBranchAddress("lep_ptcone30", &lep_ptcone30, &b_lep_ptcone30);
   fChain->SetBranchAddress("lep_etcone20", &lep_etcone20, &b_lep_etcone20);
   fChain->SetBranchAddress("lep_trackd0pvunbiased", &lep_trackd0pvunbiased, &b_lep_trackd0pvunbiased);
   fChain->SetBranchAddress("lep_tracksigd0pvunbiased", &lep_tracksigd0pvunbiased, &b_lep_tracksigd0pvunbiased);
   fChain->SetBranchAddress("met_et", &met_et, &b_met_et);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("jet_n", &jet_n, &b_jet_n);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_trueflav", &jet_trueflav, &b_jet_trueflav);
   fChain->SetBranchAddress("jet_truthMatched", &jet_truthMatched, &b_jet_truthMatched);
   fChain->SetBranchAddress("jet_MV2c10", &jet_MV2c10, &b_jet_MV2c10);
   fChain->SetBranchAddress("photon_n", &photon_n, &b_photon_n);
   fChain->SetBranchAddress("photon_truthMatched", &photon_truthMatched, &b_photon_truthMatched);
   fChain->SetBranchAddress("photon_trigMatched", &photon_trigMatched, &b_photon_trigMatched);
   fChain->SetBranchAddress("photon_pt", &photon_pt, &b_photon_pt);
   fChain->SetBranchAddress("photon_eta", &photon_eta, &b_photon_eta);
   fChain->SetBranchAddress("photon_phi", &photon_phi, &b_photon_phi);
   fChain->SetBranchAddress("photon_E", &photon_E, &b_photon_E);
   fChain->SetBranchAddress("photon_isTightID", &photon_isTightID, &b_photon_isTightID);
   fChain->SetBranchAddress("photon_ptcone30", &photon_ptcone30, &b_photon_ptcone30);
   fChain->SetBranchAddress("photon_etcone20", &photon_etcone20, &b_photon_etcone20);
   fChain->SetBranchAddress("photon_convType", &photon_convType, &b_photon_convType);
   fChain->SetBranchAddress("tau_n", &tau_n, &b_tau_n);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_E", &tau_E, &b_tau_E);
   fChain->SetBranchAddress("tau_isTightID", &tau_isTightID, &b_tau_isTightID);
   fChain->SetBranchAddress("tau_truthMatched", &tau_truthMatched, &b_tau_truthMatched);
   fChain->SetBranchAddress("tau_trigMatched", &tau_trigMatched, &b_tau_trigMatched);
   fChain->SetBranchAddress("tau_nTracks", &tau_nTracks, &b_tau_nTracks);
   fChain->SetBranchAddress("tau_BDTid", &tau_BDTid, &b_tau_BDTid);
   fChain->SetBranchAddress("ditau_m", &ditau_m, &b_ditau_m);
   fChain->SetBranchAddress("lep_pt_syst", &lep_pt_syst, &b_lep_pt_syst);
   fChain->SetBranchAddress("met_et_syst", &met_et_syst, &b_met_et_syst);
   fChain->SetBranchAddress("jet_pt_syst", &jet_pt_syst, &b_jet_pt_syst);
   fChain->SetBranchAddress("photon_pt_syst", &photon_pt_syst, &b_photon_pt_syst);
   fChain->SetBranchAddress("tau_pt_syst", &tau_pt_syst, &b_tau_pt_syst);
   fChain->SetBranchAddress("XSection", &XSection, &b_XSection);
   fChain->SetBranchAddress("SumWeights", &SumWeights, &b_SumWeights);
   fChain->SetBranchAddress("largeRjet_n", &largeRjet_n, &b_largeRjet_n);
   fChain->SetBranchAddress("largeRjet_pt", &largeRjet_pt, &b_largeRjet_pt);
   fChain->SetBranchAddress("largeRjet_eta", &largeRjet_eta, &b_largeRjet_eta);
   fChain->SetBranchAddress("largeRjet_phi", &largeRjet_phi, &b_largeRjet_phi);
   fChain->SetBranchAddress("largeRjet_E", &largeRjet_E, &b_largeRjet_E);
   fChain->SetBranchAddress("largeRjet_m", &largeRjet_m, &b_largeRjet_m);
   fChain->SetBranchAddress("largeRjet_truthMatched", &largeRjet_truthMatched, &b_largeRjet_truthMatched);
   fChain->SetBranchAddress("largeRjet_D2", &largeRjet_D2, &b_largeRjet_D2);
   fChain->SetBranchAddress("largeRjet_tau32", &largeRjet_tau32, &b_largeRjet_tau32);
   fChain->SetBranchAddress("largeRjet_pt_syst", &largeRjet_pt_syst, &b_largeRjet_pt_syst);
   fChain->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
}

#endif // #ifdef atlasopenR2_cxx
