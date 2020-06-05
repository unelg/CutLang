//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 13 15:09:01 2020 by ROOT version 6.14/06
// from TTree physics/physics
// found on file: Zjets_MC.Nominal.1.root
//////////////////////////////////////////////////////////

#ifndef VLLBG3_h
#define VLLBG3_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "TClonesArray.h"
#include "TObject.h"
#include "dbxParticle.h"
#include "Node.h"

// Header file for the classes stored in the TTree if any.
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "vector"
#include "string"
#include "map"

using namespace std;

class VLLBG3 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxgeneratorWeightMap = 216;

   // Declaration of leaf types
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   Float_t         averageMuScaled;
   Float_t         actualMuScaled;
   Float_t         pileupWeight;
   UInt_t          randomRunNumber;
   Float_t         generatorWeight;
   Int_t           generatorWeightMap_;
   string          generatorWeightMap_first[kMaxgeneratorWeightMap];
   Float_t         generatorWeightMap_second[kMaxgeneratorWeightMap];   //[generatorWeightMap_]
   UInt_t          mcChannelNumber;
   Double_t        correctionWeight;
   Double_t        luminosityWeight;
   vector<double>  *met;
   vector<double>  *met_phi;
   vector<double>  *met_significance;
   vector<float>   *el_charge;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_caloCluster_eta;
   vector<float>   *el_phi;
   vector<int>     *el_type;
   vector<float>   *mu_charge;
   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<int>     *mu_type;
   vector<float>   *mu_momentum_resolution;
   vector<float>   *jet_m;
   vector<bool>    *jet_selected;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<bool>    *jet_isBJet;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_averageMuScaled;   //!
   TBranch        *b_actualMuScaled;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_generatorWeight;   //!
   TBranch        *b_generatorWeightMap_;   //!
   TBranch        *b_generatorWeightMap_first;   //!
   TBranch        *b_generatorWeightMap_second;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_correctionWeight;   //!
   TBranch        *b_luminosityWeight;   //!
   TBranch        *b_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_significance;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_caloCluster_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_type;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_type;   //!
   TBranch        *b_mu_momentum_resolution;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet_selected;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_isBJet;   //!

   VLLBG3(char *file_name, TChain *tree=0, int year=2012);
   virtual ~VLLBG3();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual void     GetPhysicsObjects(Long64_t entry, AnalysisObjects *a0);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree, int year);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef VLLBG3_cxx
VLLBG3::VLLBG3(char *file_name, TChain *tree, int year) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Zjets_MC.Nominal.1.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Zjets_MC.Nominal.1.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("Zjets_MC.Nominal.1.root:/NOSYS");
      dir->GetObject("physics",tree);

   }
   Init(tree);
}
*/
  TChain* chain;
  if (tree == 0) {
      chain = new TChain("NOSYS/physics");
      //strncat(file_name, ":/NOSYS", 7);
      chain->Add(file_name);
  }
  if (tree == 0) {
      Init(chain, year);
  } else {
      Init(tree, year);
  }
}

VLLBG3::~VLLBG3()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLBG3::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLBG3::LoadTree(Long64_t entry)
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

void VLLBG3::Init(TTree *tree, int year)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   met = 0;
   met_phi = 0;
   met_significance = 0;
   el_charge = 0;
   el_pt = 0;
   el_eta = 0;
   el_caloCluster_eta = 0;
   el_phi = 0;
   el_type = 0;
   mu_charge = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_type = 0;
   mu_momentum_resolution = 0;
   jet_m = 0;
   jet_selected = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_isBJet = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("averageMuScaled", &averageMuScaled, &b_averageMuScaled);
   fChain->SetBranchAddress("actualMuScaled", &actualMuScaled, &b_actualMuScaled);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("generatorWeight", &generatorWeight, &b_generatorWeight);
   fChain->SetBranchAddress("generatorWeightMap", &generatorWeightMap_, &b_generatorWeightMap_);
   fChain->SetBranchAddress("generatorWeightMap.first", generatorWeightMap_first, &b_generatorWeightMap_first);
   fChain->SetBranchAddress("generatorWeightMap.second", generatorWeightMap_second, &b_generatorWeightMap_second);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("correctionWeight", &correctionWeight, &b_correctionWeight);
   fChain->SetBranchAddress("luminosityWeight", &luminosityWeight, &b_luminosityWeight);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_significance", &met_significance, &b_met_significance);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_caloCluster_eta", &el_caloCluster_eta, &b_el_caloCluster_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_type", &el_type, &b_el_type);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_type", &mu_type, &b_mu_type);
   fChain->SetBranchAddress("mu_momentum_resolution", &mu_momentum_resolution, &b_mu_momentum_resolution);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet_selected", &jet_selected, &b_jet_selected);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_isBJet", &jet_isBJet, &b_jet_isBJet);
   Notify();
}

Bool_t VLLBG3::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void VLLBG3::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t VLLBG3::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef VLLBG3_cxx
