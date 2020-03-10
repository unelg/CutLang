//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb  3 22:43:15 2020 by ROOT version 6.18/04
// from TTree Delphes/Analysis tree
// found on file: /Users/ngu/Downloads/cmsfull.root
//////////////////////////////////////////////////////////

#ifndef delphes_h
#define delphes_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTreeReaderArray.h>
#include <TTreeReader.h>

#include "dbxParticle.h"
#include "delphesParticles.h"

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TRefArray.h>
#include <TRef.h>


class delphes {
public :
   typedef std::map<TString, std::pair<TBranch *, TClonesArray *> > TBranchMap;
   TBranchMap fBranchMap; //!
   TTree     *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t      fCurrent; //!current Tree number in a TChain

   delphes(char *file_name, TChain *tree=0);
   virtual ~delphes();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual TClonesArray *UseBranch(const char *branchName, TTree *fChain);
};

#endif

#ifdef delphes_cxx
delphes::delphes(char *file_name, TChain *tree) : fChain(0)
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("Delphes");
     chain->Add(file_name);
  }
  if (tree == 0) {
     Init(chain);
  } else {
     Init(tree);
  }
}

delphes::~delphes()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t delphes::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t delphes::LoadTree(Long64_t entry)
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

void delphes::Init(TTree *tree)
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
}

#endif // #ifdef delphes_cxx
