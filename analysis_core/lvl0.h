//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul 24 22:29:41 2017 by ROOT version 5.34/18
// from TTree nt_tree/saving data
// found on file: signal/output_3-lvl0.root
//////////////////////////////////////////////////////////

#ifndef lvl0_h
#define lvl0_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>

// Header file for the classes stored in the TTree if any.
#include "DBXNtuple.h"
#include <TObject.h>
#include "dbxParticle.h"
#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_photon.h"
#include "dbx_jet.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxnt_eles = 90;
const Int_t kMaxnt_muos = 90;
const Int_t kMaxnt_jets = 90;

class lvl0 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   DBXNtuple *event;
   TBranch   *b_event; //!

   lvl0(char *file_name, TChain *tree=0);
   virtual ~lvl0();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef lvl0_cxx
lvl0::lvl0(char *file_name, TChain *tree) : fChain(0)
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("nt_tree");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }

}

lvl0::~lvl0()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t lvl0::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t lvl0::LoadTree(Long64_t entry)
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

void lvl0::Init(TTree *tree)
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
   std::cout << "Should be 0:"<< fChain->SetBranchAddress("dbxAsave", &event, &b_event) << std::endl;
   Notify();
}

Bool_t lvl0::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void lvl0::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t lvl0::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef lvl0_cxx
