//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug  5 08:20:34 2021 by ROOT version 6.24/00
// from TTree Events/Events
// found on file: /Users/ssekmen/Dropbox/cutlang/ZZTo2e2mushort.root
//////////////////////////////////////////////////////////

#ifndef cmsod2_h
#define cmsod2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"

// Header file for the classes stored in the TTree if any.

class cmsod2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   const static int maxMu=32;
   const static int maxEl=32;

   // Declaration of leaf types
   Int_t           run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Int_t           PV_npvs;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   UInt_t          nMuon;
   Float_t         Muon_pt[maxMu];   //[nMuon]
   Float_t         Muon_eta[maxMu];   //[nMuon]
   Float_t         Muon_phi[maxMu];   //[nMuon]
   Float_t         Muon_mass[maxMu];   //[nMuon]
   Int_t           Muon_charge[maxMu];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[maxMu];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[maxMu];   //[nMuon]
   Float_t         Muon_dxy[maxMu];   //[nMuon]
   Float_t         Muon_dxyErr[maxMu];   //[nMuon]
   Float_t         Muon_dz[maxMu];   //[nMuon]
   Float_t         Muon_dzErr[maxMu];   //[nMuon]
   UInt_t          nElectron;
   Float_t         Electron_pt[maxEl];   //[nElectron]
   Float_t         Electron_eta[maxEl];   //[nElectron]
   Float_t         Electron_phi[maxEl];   //[nElectron]
   Float_t         Electron_mass[maxEl];   //[nElectron]
   Int_t           Electron_charge[maxEl];   //[nElectron]
   Float_t         Electron_pfRelIso03_all[maxEl];   //[nElectron]
   Float_t         Electron_dxy[maxEl];   //[nElectron]
   Float_t         Electron_dxyErr[maxEl];   //[nElectron]
   Float_t         Electron_dz[maxEl];   //[nElectron]
   Float_t         Electron_dzErr[maxEl];   //[nElectron]
   Float_t         MET_pt;
   Float_t         MET_phi;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_pfRelIso03_all;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_phi;   //!

   cmsod2(char *file_name, TChain *tree=0);
   virtual ~cmsod2();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
};

#endif

#ifdef cmsod2_cxx
cmsod2::cmsod2(char *file_name, TChain *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("events");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }

}

cmsod2::~cmsod2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t cmsod2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t cmsod2::LoadTree(Long64_t entry)
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

void cmsod2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_pfRelIso03_all", Electron_pfRelIso03_all, &b_Electron_pfRelIso03_all);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
}

#endif // #ifdef cmsod2_cxx
