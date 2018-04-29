//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 24 16:54:02 2017 by ROOT version 5.34/36
// from TTree events/
// found on file: cms_opendata_ttbar.root
//////////////////////////////////////////////////////////

#ifndef cmsod_h
#define cmsod_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class cmsod {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           NJet;
   Float_t         Jet_Px[50];   //[NJet]
   Float_t         Jet_Py[50];   //[NJet]
   Float_t         Jet_Pz[50];   //[NJet]
   Float_t         Jet_E[50];   //[NJet]
   Float_t         Jet_btag[50];   //[NJet]
   Bool_t          Jet_ID[50];   //[NJet]
   Int_t           NMuon;
   Float_t         Muon_Px[20];   //[NMuon]
   Float_t         Muon_Py[20];   //[NMuon]
   Float_t         Muon_Pz[20];   //[NMuon]
   Float_t         Muon_E[20];   //[NMuon]
   Int_t           Muon_Charge[20];   //[NMuon]
   Float_t         Muon_Iso[20];   //[NMuon]
   Int_t           NElectron;
   Float_t         Electron_Px[30];   //[NElectron]
   Float_t         Electron_Py[30];   //[NElectron]
   Float_t         Electron_Pz[30];   //[NElectron]
   Float_t         Electron_E[30];   //[NElectron]
   Int_t           Electron_Charge[30];   //[NElectron]
   Float_t         Electron_Iso[30];   //[NElectron]
   Int_t           NPhoton;
   Float_t         Photon_Px[20];   //[NPhoton]
   Float_t         Photon_Py[20];   //[NPhoton]
   Float_t         Photon_Pz[20];   //[NPhoton]
   Float_t         Photon_E[20];   //[NPhoton]
   Float_t         Photon_Iso[20];   //[NPhoton]
   Float_t         MET_px;
   Float_t         MET_py;
   Float_t         MChadronicBottom_px;
   Float_t         MChadronicBottom_py;
   Float_t         MChadronicBottom_pz;
   Float_t         MCleptonicBottom_px;
   Float_t         MCleptonicBottom_py;
   Float_t         MCleptonicBottom_pz;
   Float_t         MChadronicWDecayQuark_px;
   Float_t         MChadronicWDecayQuark_py;
   Float_t         MChadronicWDecayQuark_pz;
   Float_t         MChadronicWDecayQuarkBar_px;
   Float_t         MChadronicWDecayQuarkBar_py;
   Float_t         MChadronicWDecayQuarkBar_pz;
   Float_t         MClepton_px;
   Float_t         MClepton_py;
   Float_t         MClepton_pz;
   Int_t           MCleptonPDGid;
   Float_t         MCneutrino_px;
   Float_t         MCneutrino_py;
   Float_t         MCneutrino_pz;
   Int_t           NPrimaryVertices;
   Bool_t          triggerIsoMu24;
   Float_t         EventWeight;

   // List of branches
   TBranch        *b_NJet;   //!
   TBranch        *b_Jet_Px;   //!
   TBranch        *b_Jet_Py;   //!
   TBranch        *b_Jet_Pz;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_btag;   //!
   TBranch        *b_Jet_ID;   //!
   TBranch        *b_NMuon;   //!
   TBranch        *b_Muon_Px;   //!
   TBranch        *b_Muon_Py;   //!
   TBranch        *b_Muon_Pz;   //!
   TBranch        *b_Muon_E;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_Iso;   //!
   TBranch        *b_NElectron;   //!
   TBranch        *b_Electron_Px;   //!
   TBranch        *b_Electron_Py;   //!
   TBranch        *b_Electron_Pz;   //!
   TBranch        *b_Electron_E;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_Iso;   //!
   TBranch        *b_NPhoton;   //!
   TBranch        *b_Photon_Px;   //!
   TBranch        *b_Photon_Py;   //!
   TBranch        *b_Photon_Pz;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_Iso;   //!
   TBranch        *b_MET_px;   //!
   TBranch        *b_MET_py;   //!
   TBranch        *b_MChadronicBottom_px;   //!
   TBranch        *b_MChadronicBottom_py;   //!
   TBranch        *b_MChadronicBottom_pz;   //!
   TBranch        *b_MCleptonicBottom_px;   //!
   TBranch        *b_MCleptonicBottom_py;   //!
   TBranch        *b_MCleptonicBottom_pz;   //!
   TBranch        *b_MChadronicWDecayQuark_px;   //!
   TBranch        *b_MChadronicWDecayQuark_py;   //!
   TBranch        *b_MChadronicWDecayQuark_pz;   //!
   TBranch        *b_MChadronicWDecayQuarkBar_px;   //!
   TBranch        *b_MChadronicWDecayQuarkBar_py;   //!
   TBranch        *b_MChadronicWDecayQuarkBar_pz;   //!
   TBranch        *b_MClepton_px;   //!
   TBranch        *b_MClepton_py;   //!
   TBranch        *b_MClepton_pz;   //!
   TBranch        *b_MCleptonPDGid;   //!
   TBranch        *b_MCneutrino_px;   //!
   TBranch        *b_MCneutrino_py;   //!
   TBranch        *b_MCneutrino_pz;   //!
   TBranch        *b_NPrimaryVertices;   //!
   TBranch        *b_triggerIsoMu24;   //!
   TBranch        *b_EventWeight;   //!

   cmsod(char *file_name, TChain *tree=0);
   virtual ~cmsod();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef cmsod_cxx
cmsod::cmsod(char *file_name, TChain *tree) : fChain(0) 
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

cmsod::~cmsod()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t cmsod::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t cmsod::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void cmsod::Init(TTree *tree)
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

   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("Jet_Px", Jet_Px, &b_Jet_Px);
   fChain->SetBranchAddress("Jet_Py", Jet_Py, &b_Jet_Py);
   fChain->SetBranchAddress("Jet_Pz", Jet_Pz, &b_Jet_Pz);
   fChain->SetBranchAddress("Jet_E", Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_btag", Jet_btag, &b_Jet_btag);
   fChain->SetBranchAddress("Jet_ID", Jet_ID, &b_Jet_ID);
   fChain->SetBranchAddress("NMuon", &NMuon, &b_NMuon);
   fChain->SetBranchAddress("Muon_Px", Muon_Px, &b_Muon_Px);
   fChain->SetBranchAddress("Muon_Py", Muon_Py, &b_Muon_Py);
   fChain->SetBranchAddress("Muon_Pz", Muon_Pz, &b_Muon_Pz);
   fChain->SetBranchAddress("Muon_E", Muon_E, &b_Muon_E);
   fChain->SetBranchAddress("Muon_Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon_Iso", Muon_Iso, &b_Muon_Iso);
   fChain->SetBranchAddress("NElectron", &NElectron, &b_NElectron);
   fChain->SetBranchAddress("Electron_Px", Electron_Px, &b_Electron_Px);
   fChain->SetBranchAddress("Electron_Py", Electron_Py, &b_Electron_Py);
   fChain->SetBranchAddress("Electron_Pz", Electron_Pz, &b_Electron_Pz);
   fChain->SetBranchAddress("Electron_E", Electron_E, &b_Electron_E);
   fChain->SetBranchAddress("Electron_Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron_Iso", Electron_Iso, &b_Electron_Iso);
   fChain->SetBranchAddress("NPhoton", &NPhoton, &b_NPhoton);
   fChain->SetBranchAddress("Photon_Px", Photon_Px, &b_Photon_Px);
   fChain->SetBranchAddress("Photon_Py", Photon_Py, &b_Photon_Py);
   fChain->SetBranchAddress("Photon_Pz", Photon_Pz, &b_Photon_Pz);
   fChain->SetBranchAddress("Photon_E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon_Iso", Photon_Iso, &b_Photon_Iso);
   fChain->SetBranchAddress("MET_px", &MET_px, &b_MET_px);
   fChain->SetBranchAddress("MET_py", &MET_py, &b_MET_py);
   fChain->SetBranchAddress("MChadronicBottom_px", &MChadronicBottom_px, &b_MChadronicBottom_px);
   fChain->SetBranchAddress("MChadronicBottom_py", &MChadronicBottom_py, &b_MChadronicBottom_py);
   fChain->SetBranchAddress("MChadronicBottom_pz", &MChadronicBottom_pz, &b_MChadronicBottom_pz);
   fChain->SetBranchAddress("MCleptonicBottom_px", &MCleptonicBottom_px, &b_MCleptonicBottom_px);
   fChain->SetBranchAddress("MCleptonicBottom_py", &MCleptonicBottom_py, &b_MCleptonicBottom_py);
   fChain->SetBranchAddress("MCleptonicBottom_pz", &MCleptonicBottom_pz, &b_MCleptonicBottom_pz);
   fChain->SetBranchAddress("MChadronicWDecayQuark_px", &MChadronicWDecayQuark_px, &b_MChadronicWDecayQuark_px);
   fChain->SetBranchAddress("MChadronicWDecayQuark_py", &MChadronicWDecayQuark_py, &b_MChadronicWDecayQuark_py);
   fChain->SetBranchAddress("MChadronicWDecayQuark_pz", &MChadronicWDecayQuark_pz, &b_MChadronicWDecayQuark_pz);
   fChain->SetBranchAddress("MChadronicWDecayQuarkBar_px", &MChadronicWDecayQuarkBar_px, &b_MChadronicWDecayQuarkBar_px);
   fChain->SetBranchAddress("MChadronicWDecayQuarkBar_py", &MChadronicWDecayQuarkBar_py, &b_MChadronicWDecayQuarkBar_py);
   fChain->SetBranchAddress("MChadronicWDecayQuarkBar_pz", &MChadronicWDecayQuarkBar_pz, &b_MChadronicWDecayQuarkBar_pz);
   fChain->SetBranchAddress("MClepton_px", &MClepton_px, &b_MClepton_px);
   fChain->SetBranchAddress("MClepton_py", &MClepton_py, &b_MClepton_py);
   fChain->SetBranchAddress("MClepton_pz", &MClepton_pz, &b_MClepton_pz);
   fChain->SetBranchAddress("MCleptonPDGid", &MCleptonPDGid, &b_MCleptonPDGid);
   fChain->SetBranchAddress("MCneutrino_px", &MCneutrino_px, &b_MCneutrino_px);
   fChain->SetBranchAddress("MCneutrino_py", &MCneutrino_py, &b_MCneutrino_py);
   fChain->SetBranchAddress("MCneutrino_pz", &MCneutrino_pz, &b_MCneutrino_pz);
   fChain->SetBranchAddress("NPrimaryVertices", &NPrimaryVertices, &b_NPrimaryVertices);
   fChain->SetBranchAddress("triggerIsoMu24", &triggerIsoMu24, &b_triggerIsoMu24);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   Notify();
}

Bool_t cmsod::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void cmsod::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t cmsod::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef cmsod_cxx
