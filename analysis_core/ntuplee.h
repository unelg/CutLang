#ifndef ntuplee_h
#define ntuplee_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"
//#include "ntupleeParticles.h"

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TRefArray.h>
#include <TRef.h>

class ntuplee {
    public:
        TTree *fChain;
        Int_t fCurrent;

        //std::map<std::string, TBranch> b_;

        int NMuon;
        TBranch* b_NMuon;

        ntuplee(TChain *tree=0);
        virtual ~ntuplee();
        virtual Int_t GetEntry(Long64_t entry);
        virtual Long64_t LoadTree(Long64_t entry);
        virtual void Init(TTree *tree);
        virtual void Loop(analy_struct aselect);

};


#endif

#ifdef ntuplee_cxx

ntuplee::ntuplee(TChain *tree)  : fChain(0)
{
    Init(tree);
}

ntuplee::~ntuplee()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ntuplee::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ntuplee::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}
void ntuplee::Init(TTree *tree)
{
    if(!tree) return;
    fChain = tree;
    fCurrent = -1;
    fChain->SetMakeClass(1);
}

#endif