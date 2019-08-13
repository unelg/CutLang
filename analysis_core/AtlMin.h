//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Nov 14 17:40:12 2018 by ROOT version 6.11/02
// from TTree nominal/tree
// found on file: user.nikiforo.11699360._000001.output.root
//////////////////////////////////////////////////////////

#ifndef AtlMin_h
#define AtlMin_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "dbxParticle.h"
#include "Node.h"

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "vector"

using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.


class AtlMin {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_bTagSF_MV2c10_77;
   Float_t         weight_jvt;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   UInt_t          backgroundFlags;
   UInt_t          hasBadMuon;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_cl_eta;
   vector<float>   *el_phi;
   vector<float>   *el_e;
   vector<float>   *el_charge;
   vector<float>   *el_topoetcone20;
   vector<float>   *el_ptvarcone20;
   vector<char>    *el_CF;
   vector<float>   *el_d0sig;
   vector<float>   *el_delta_z0_sintheta;
   vector<int>     *el_true_type;
   vector<int>     *el_true_origin;
   vector<int>     *el_true_typebkg;
   vector<int>     *el_true_originbkg;
   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_e;
   vector<float>   *mu_charge;
   vector<float>   *mu_topoetcone20;
   vector<float>   *mu_ptvarcone30;
   vector<float>   *mu_d0sig;
   vector<float>   *mu_delta_z0_sintheta;
   vector<int>     *mu_true_type;
   vector<int>     *mu_true_origin;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<float>   *jet_mv2c00;
   vector<float>   *jet_mv2c10;
   vector<float>   *jet_mv2c20;
   vector<float>   *jet_ip3dsv1;
   vector<float>   *jet_jvt;
   vector<char>    *jet_passfjvt;
   vector<int>     *jet_truthflav;
   vector<int>     *jet_truthPartonLabel;
   vector<char>    *jet_isTrueHS;
   vector<char>    *jet_isbtagged_MV2c10_77;
   vector<float>   *ljet_pt;
   vector<float>   *ljet_eta;
   vector<float>   *ljet_phi;
   vector<float>   *ljet_e;
   vector<float>   *ljet_m;
   vector<float>   *ljet_sd12;
   vector<char>    *ljet_isTopTagged_50;
   vector<char>    *ljet_isTopTagged_80;
   vector<char>    *ljet_isWTagged_80;
   vector<char>    *ljet_isWTagged_50;
   vector<char>    *ljet_isZTagged_80;
   vector<char>    *ljet_isZTagged_50;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           ee_2015;
   Int_t           ee_2016;
   Int_t           mumu_2015;
   Int_t           mumu_2016;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_e120_lhloose;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium_nod0;
   vector<char>    *el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;
   vector<char>    *el_trigMatch_HLT_e140_lhloose_nod0;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium;
   vector<char>    *el_trigMatch_HLT_e24_lhmedium_L1EM20VH;
   vector<char>    *el_trigMatch_HLT_e120_lhloose;
   vector<char>    *mu_trigMatch_HLT_mu26_ivarmedium;
   vector<char>    *mu_trigMatch_HLT_mu50;
   vector<char>    *mu_trigMatch_HLT_mu20_iloose_L1MU15;
   Int_t           vlq_truth_type;
   Int_t           vlq_truth_channel;
   vector<int>     *truth_pdgID;
   vector<double>  *truth_pt;
   vector<double>  *truth_eta;
   vector<double>  *truth_phi;
   vector<double>  *truth_e;
   vector<double>  *truth_m;
   vector<int>     *truth_charge;
   vector<unsigned int> *truth_parentIndex;
   vector<vector<unsigned int> > *truth_childIndex;
   Int_t           truthjet_n;
   Double_t        Z_pt;
   Double_t        Z_eta;
   Double_t        Z_phi;
   Double_t        Z_e;
   Double_t        Z_m;
   vector<int>     *el_isZCand;
   vector<int>     *mu_isZCand;
   vector<double>  *ljet_sd23;
   vector<double>  *ljet_sd34;
   vector<double>  *ljet_C2;
   vector<double>  *ljet_D2;
   vector<double>  *ljet_ECF1;
   vector<double>  *ljet_ECF2;
   vector<double>  *ljet_ECF3;
   vector<double>  *ljet_Tau1;
   vector<double>  *ljet_Tau2;
   vector<double>  *ljet_Tau3;
   vector<double>  *ljet_Tau21;
   vector<double>  *ljet_Tau32;
   vector<double>  *ljet_Tau1_wta;
   vector<double>  *ljet_Tau2_wta;
   vector<double>  *ljet_Tau3_wta;
   vector<double>  *ljet_Tau21_wta;
   vector<double>  *ljet_Tau32_wta;
   vector<int>     *ljet_istTagged_L;
   vector<int>     *ljet_istTagged_T;
   vector<int>     *ljet_isWTagged_M;
   vector<int>     *ljet_isWTagged_T;
   vector<int>     *ljet_isZTagged_M;
   vector<int>     *ljet_isZTagged_T;
   vector<int>     *ljet_numConstituents;

   // List of branches
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_backgroundFlags;   //!
   TBranch        *b_hasBadMuon;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_e;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_topoetcone20;   //!
   TBranch        *b_el_ptvarcone20;   //!
   TBranch        *b_el_CF;   //!
   TBranch        *b_el_d0sig;   //!
   TBranch        *b_el_delta_z0_sintheta;   //!
   TBranch        *b_el_true_type;   //!
   TBranch        *b_el_true_origin;   //!
   TBranch        *b_el_true_typebkg;   //!
   TBranch        *b_el_true_originbkg;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_topoetcone20;   //!
   TBranch        *b_mu_ptvarcone30;   //!
   TBranch        *b_mu_d0sig;   //!
   TBranch        *b_mu_delta_z0_sintheta;   //!
   TBranch        *b_mu_true_type;   //!
   TBranch        *b_mu_true_origin;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_mv2c00;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_mv2c20;   //!
   TBranch        *b_jet_ip3dsv1;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_passfjvt;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_jet_truthPartonLabel;   //!
   TBranch        *b_jet_isTrueHS;   //!
   TBranch        *b_jet_isbtagged_MV2c10_77;   //!
   TBranch        *b_ljet_pt;   //!
   TBranch        *b_ljet_eta;   //!
   TBranch        *b_ljet_phi;   //!
   TBranch        *b_ljet_e;   //!
   TBranch        *b_ljet_m;   //!
   TBranch        *b_ljet_sd12;   //!
   TBranch        *b_ljet_isTopTagged_50;   //!
   TBranch        *b_ljet_isTopTagged_80;   //!
   TBranch        *b_ljet_isWTagged_80;   //!
   TBranch        *b_ljet_isWTagged_50;   //!
   TBranch        *b_ljet_isZTagged_80;   //!
   TBranch        *b_ljet_isZTagged_50;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_ee_2015;   //!
   TBranch        *b_ee_2016;   //!
   TBranch        *b_mumu_2015;   //!
   TBranch        *b_mumu_2016;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_el_trigMatch_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium;   //!
   TBranch        *b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_el_trigMatch_HLT_e120_lhloose;   //!
   TBranch        *b_mu_trigMatch_HLT_mu26_ivarmedium;   //!
   TBranch        *b_mu_trigMatch_HLT_mu50;   //!
   TBranch        *b_mu_trigMatch_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_vlq_truth_type;   //!
   TBranch        *b_vlq_truth_channel;   //!
   TBranch        *b_truth_pdgID;   //!
   TBranch        *b_truth_pt;   //!
   TBranch        *b_truth_eta;   //!
   TBranch        *b_truth_phi;   //!
   TBranch        *b_truth_e;   //!
   TBranch        *b_truth_m;   //!
   TBranch        *b_truth_charge;   //!
   TBranch        *b_truth_parentIndex;   //!
   TBranch        *b_truth_childIndex;   //!
   TBranch        *b_truthjet_n;   //!
   TBranch        *b_Z_pt;   //!
   TBranch        *b_Z_eta;   //!
   TBranch        *b_Z_phi;   //!
   TBranch        *b_Z_e;   //!
   TBranch        *b_Z_m;   //!
   TBranch        *b_el_isZCand;   //!
   TBranch        *b_mu_isZCand;   //!
   TBranch        *b_ljet_sd23;   //!
   TBranch        *b_ljet_sd34;   //!
   TBranch        *b_ljet_C2;   //!
   TBranch        *b_ljet_D2;   //!
   TBranch        *b_ljet_ECF1;   //!
   TBranch        *b_ljet_ECF2;   //!
   TBranch        *b_ljet_ECF3;   //!
   TBranch        *b_ljet_Tau1;   //!
   TBranch        *b_ljet_Tau2;   //!
   TBranch        *b_ljet_Tau3;   //!
   TBranch        *b_ljet_Tau21;   //!
   TBranch        *b_ljet_Tau32;   //!
   TBranch        *b_ljet_Tau1_wta;   //!
   TBranch        *b_ljet_Tau2_wta;   //!
   TBranch        *b_ljet_Tau3_wta;   //!
   TBranch        *b_ljet_Tau21_wta;   //!
   TBranch        *b_ljet_Tau32_wta;   //!
   TBranch        *b_ljet_istTagged_L;   //!
   TBranch        *b_ljet_istTagged_T;   //!
   TBranch        *b_ljet_isWTagged_M;   //!
   TBranch        *b_ljet_isWTagged_T;   //!
   TBranch        *b_ljet_isZTagged_M;   //!
   TBranch        *b_ljet_isZTagged_T;   //!
   TBranch        *b_ljet_numConstituents;   //!

   AtlMin(char *file_name, TChain *tree=0, int year=2012);
   virtual ~AtlMin();
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

#ifdef AtlMin_cxx
AtlMin::AtlMin(char *file_name, TChain *tree, int year) : fChain(0) 
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("nominal");
     chain->Add(file_name);
     std::cout << "NOMINAL:"<<file_name <<"\n";
  }
  if (tree == 0) {
   Init(chain, year);
     std::cout << "CHAIN"<<chain->GetName() <<"\n";
  } else {
   Init(tree, year);
     std::cout << "TREE\n";
  }

}

AtlMin::~AtlMin()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AtlMin::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AtlMin::LoadTree(Long64_t entry)
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

void AtlMin::Init(TTree *tree, int year)
{
     std::cout << "--------"<<tree->GetName()<<"\n";
   // Set object pointer
   el_pt = 0;
   el_eta = 0;
   el_cl_eta = 0;
   el_phi = 0;
   el_e = 0;
   el_charge = 0;
   el_topoetcone20 = 0;
   el_ptvarcone20 = 0;
   el_CF = 0;
   el_d0sig = 0;
   el_delta_z0_sintheta = 0;
   el_true_type = 0;
   el_true_origin = 0;
   el_true_typebkg = 0;
   el_true_originbkg = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_e = 0;
   mu_charge = 0;
   mu_topoetcone20 = 0;
   mu_ptvarcone30 = 0;
   mu_d0sig = 0;
   mu_delta_z0_sintheta = 0;
   mu_true_type = 0;
   mu_true_origin = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_mv2c00 = 0;
   jet_mv2c10 = 0;
   jet_mv2c20 = 0;
   jet_ip3dsv1 = 0;
   jet_jvt = 0;
   jet_passfjvt = 0;
   jet_truthflav = 0;
   jet_truthPartonLabel = 0;
   jet_isTrueHS = 0;
   jet_isbtagged_MV2c10_77 = 0;
   ljet_pt = 0;
   ljet_eta = 0;
   ljet_phi = 0;
   ljet_e = 0;
   ljet_m = 0;
   ljet_sd12 = 0;
   ljet_isTopTagged_50 = 0;
   ljet_isTopTagged_80 = 0;
   ljet_isWTagged_80 = 0;
   ljet_isWTagged_50 = 0;
   ljet_isZTagged_80 = 0;
   ljet_isZTagged_50 = 0;
   el_trigMatch_HLT_e60_lhmedium_nod0 = 0;
   el_trigMatch_HLT_e26_lhtight_nod0_ivarloose = 0;
   el_trigMatch_HLT_e140_lhloose_nod0 = 0;
   el_trigMatch_HLT_e60_lhmedium = 0;
   el_trigMatch_HLT_e24_lhmedium_L1EM20VH = 0;
   el_trigMatch_HLT_e120_lhloose = 0;
   mu_trigMatch_HLT_mu26_ivarmedium = 0;
   mu_trigMatch_HLT_mu50 = 0;
   mu_trigMatch_HLT_mu20_iloose_L1MU15 = 0;
   truth_pdgID = 0;
   truth_pt = 0;
   truth_eta = 0;
   truth_phi = 0;
   truth_e = 0;
   truth_m = 0;
   truth_charge = 0;
   truth_parentIndex = 0;
   truth_childIndex = 0;
   el_isZCand = 0;
   mu_isZCand = 0;
   ljet_sd23 = 0;
   ljet_sd34 = 0;
   ljet_C2 = 0;
   ljet_D2 = 0;
   ljet_ECF1 = 0;
   ljet_ECF2 = 0;
   ljet_ECF3 = 0;
   ljet_Tau1 = 0;
   ljet_Tau2 = 0;
   ljet_Tau3 = 0;
   ljet_Tau21 = 0;
   ljet_Tau32 = 0;
   ljet_Tau1_wta = 0;
   ljet_Tau2_wta = 0;
   ljet_Tau3_wta = 0;
   ljet_Tau21_wta = 0;
   ljet_Tau32_wta = 0;
   ljet_istTagged_L = 0;
   ljet_istTagged_T = 0;
   ljet_isWTagged_M = 0;
   ljet_isWTagged_T = 0;
   ljet_isZTagged_M = 0;
   ljet_isZTagged_T = 0;
   ljet_numConstituents = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
  // fChain=(TTree*)(fChain->GetCurrentFile())->Get("nominal");
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77", &weight_bTagSF_MV2c10_77, &b_weight_bTagSF_MV2c10_77);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("backgroundFlags", &backgroundFlags, &b_backgroundFlags);
   fChain->SetBranchAddress("hasBadMuon", &hasBadMuon, &b_hasBadMuon);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_e", &el_e, &b_el_e);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_topoetcone20", &el_topoetcone20, &b_el_topoetcone20);
   fChain->SetBranchAddress("el_ptvarcone20", &el_ptvarcone20, &b_el_ptvarcone20);
   fChain->SetBranchAddress("el_CF", &el_CF, &b_el_CF);
   fChain->SetBranchAddress("el_d0sig", &el_d0sig, &b_el_d0sig);
   fChain->SetBranchAddress("el_delta_z0_sintheta", &el_delta_z0_sintheta, &b_el_delta_z0_sintheta);
   fChain->SetBranchAddress("el_true_type", &el_true_type, &b_el_true_type);
   fChain->SetBranchAddress("el_true_origin", &el_true_origin, &b_el_true_origin);
   fChain->SetBranchAddress("el_true_typebkg", &el_true_typebkg, &b_el_true_typebkg);
   fChain->SetBranchAddress("el_true_originbkg", &el_true_originbkg, &b_el_true_originbkg);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_topoetcone20", &mu_topoetcone20, &b_mu_topoetcone20);
   fChain->SetBranchAddress("mu_ptvarcone30", &mu_ptvarcone30, &b_mu_ptvarcone30);
   fChain->SetBranchAddress("mu_d0sig", &mu_d0sig, &b_mu_d0sig);
   fChain->SetBranchAddress("mu_delta_z0_sintheta", &mu_delta_z0_sintheta, &b_mu_delta_z0_sintheta);
   fChain->SetBranchAddress("mu_true_type", &mu_true_type, &b_mu_true_type);
   fChain->SetBranchAddress("mu_true_origin", &mu_true_origin, &b_mu_true_origin);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_mv2c00", &jet_mv2c00, &b_jet_mv2c00);
   fChain->SetBranchAddress("jet_mv2c10", &jet_mv2c10, &b_jet_mv2c10);
   fChain->SetBranchAddress("jet_mv2c20", &jet_mv2c20, &b_jet_mv2c20);
   fChain->SetBranchAddress("jet_ip3dsv1", &jet_ip3dsv1, &b_jet_ip3dsv1);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_passfjvt", &jet_passfjvt, &b_jet_passfjvt);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("jet_truthPartonLabel", &jet_truthPartonLabel, &b_jet_truthPartonLabel);
   fChain->SetBranchAddress("jet_isTrueHS", &jet_isTrueHS, &b_jet_isTrueHS);
   fChain->SetBranchAddress("jet_isbtagged_MV2c10_77", &jet_isbtagged_MV2c10_77, &b_jet_isbtagged_MV2c10_77);
   fChain->SetBranchAddress("ljet_pt", &ljet_pt, &b_ljet_pt);
   fChain->SetBranchAddress("ljet_eta", &ljet_eta, &b_ljet_eta);
   fChain->SetBranchAddress("ljet_phi", &ljet_phi, &b_ljet_phi);
   fChain->SetBranchAddress("ljet_e", &ljet_e, &b_ljet_e);
   fChain->SetBranchAddress("ljet_m", &ljet_m, &b_ljet_m);
   fChain->SetBranchAddress("ljet_sd12", &ljet_sd12, &b_ljet_sd12);
   fChain->SetBranchAddress("ljet_isTopTagged_50", &ljet_isTopTagged_50, &b_ljet_isTopTagged_50);
   fChain->SetBranchAddress("ljet_isTopTagged_80", &ljet_isTopTagged_80, &b_ljet_isTopTagged_80);
   fChain->SetBranchAddress("ljet_isWTagged_80", &ljet_isWTagged_80, &b_ljet_isWTagged_80);
   fChain->SetBranchAddress("ljet_isWTagged_50", &ljet_isWTagged_50, &b_ljet_isWTagged_50);
   fChain->SetBranchAddress("ljet_isZTagged_80", &ljet_isZTagged_80, &b_ljet_isZTagged_80);
   fChain->SetBranchAddress("ljet_isZTagged_50", &ljet_isZTagged_50, &b_ljet_isZTagged_50);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("ee_2015", &ee_2015, &b_ee_2015);
   fChain->SetBranchAddress("ee_2016", &ee_2016, &b_ee_2016);
   fChain->SetBranchAddress("mumu_2015", &mumu_2015, &b_mumu_2015);
   fChain->SetBranchAddress("mumu_2016", &mumu_2016, &b_mumu_2016);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium_nod0", &el_trigMatch_HLT_e60_lhmedium_nod0, &b_el_trigMatch_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e26_lhtight_nod0_ivarloose", &el_trigMatch_HLT_e26_lhtight_nod0_ivarloose, &b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e140_lhloose_nod0", &el_trigMatch_HLT_e140_lhloose_nod0, &b_el_trigMatch_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium", &el_trigMatch_HLT_e60_lhmedium, &b_el_trigMatch_HLT_e60_lhmedium);
   fChain->SetBranchAddress("el_trigMatch_HLT_e24_lhmedium_L1EM20VH", &el_trigMatch_HLT_e24_lhmedium_L1EM20VH, &b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("el_trigMatch_HLT_e120_lhloose", &el_trigMatch_HLT_e120_lhloose, &b_el_trigMatch_HLT_e120_lhloose);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu26_ivarmedium", &mu_trigMatch_HLT_mu26_ivarmedium, &b_mu_trigMatch_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu50", &mu_trigMatch_HLT_mu50, &b_mu_trigMatch_HLT_mu50);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu20_iloose_L1MU15", &mu_trigMatch_HLT_mu20_iloose_L1MU15, &b_mu_trigMatch_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("vlq_truth_type", &vlq_truth_type, &b_vlq_truth_type);
   fChain->SetBranchAddress("vlq_truth_channel", &vlq_truth_channel, &b_vlq_truth_channel);
   fChain->SetBranchAddress("truth_pdgID", &truth_pdgID, &b_truth_pdgID);
   fChain->SetBranchAddress("truth_pt", &truth_pt, &b_truth_pt);
   fChain->SetBranchAddress("truth_eta", &truth_eta, &b_truth_eta);
   fChain->SetBranchAddress("truth_phi", &truth_phi, &b_truth_phi);
   fChain->SetBranchAddress("truth_e", &truth_e, &b_truth_e);
   fChain->SetBranchAddress("truth_m", &truth_m, &b_truth_m);
   fChain->SetBranchAddress("truth_charge", &truth_charge, &b_truth_charge);
   fChain->SetBranchAddress("truth_parentIndex", &truth_parentIndex, &b_truth_parentIndex);
   fChain->SetBranchAddress("truth_childIndex", &truth_childIndex, &b_truth_childIndex);
   fChain->SetBranchAddress("truthjet_n", &truthjet_n, &b_truthjet_n);
   fChain->SetBranchAddress("Z_pt", &Z_pt, &b_Z_pt);
   fChain->SetBranchAddress("Z_eta", &Z_eta, &b_Z_eta);
   fChain->SetBranchAddress("Z_phi", &Z_phi, &b_Z_phi);
   fChain->SetBranchAddress("Z_e", &Z_e, &b_Z_e);
   fChain->SetBranchAddress("Z_m", &Z_m, &b_Z_m);
   fChain->SetBranchAddress("el_isZCand", &el_isZCand, &b_el_isZCand);
   fChain->SetBranchAddress("mu_isZCand", &mu_isZCand, &b_mu_isZCand);
   fChain->SetBranchAddress("ljet_sd23", &ljet_sd23, &b_ljet_sd23);
   fChain->SetBranchAddress("ljet_sd34", &ljet_sd34, &b_ljet_sd34);
   fChain->SetBranchAddress("ljet_C2", &ljet_C2, &b_ljet_C2);
   fChain->SetBranchAddress("ljet_D2", &ljet_D2, &b_ljet_D2);
   fChain->SetBranchAddress("ljet_ECF1", &ljet_ECF1, &b_ljet_ECF1);
   fChain->SetBranchAddress("ljet_ECF2", &ljet_ECF2, &b_ljet_ECF2);
   fChain->SetBranchAddress("ljet_ECF3", &ljet_ECF3, &b_ljet_ECF3);
   fChain->SetBranchAddress("ljet_Tau1", &ljet_Tau1, &b_ljet_Tau1);
   fChain->SetBranchAddress("ljet_Tau2", &ljet_Tau2, &b_ljet_Tau2);
   fChain->SetBranchAddress("ljet_Tau3", &ljet_Tau3, &b_ljet_Tau3);
   fChain->SetBranchAddress("ljet_Tau21", &ljet_Tau21, &b_ljet_Tau21);
   fChain->SetBranchAddress("ljet_Tau32", &ljet_Tau32, &b_ljet_Tau32);
   fChain->SetBranchAddress("ljet_Tau1_wta", &ljet_Tau1_wta, &b_ljet_Tau1_wta);
   fChain->SetBranchAddress("ljet_Tau2_wta", &ljet_Tau2_wta, &b_ljet_Tau2_wta);
   fChain->SetBranchAddress("ljet_Tau3_wta", &ljet_Tau3_wta, &b_ljet_Tau3_wta);
   fChain->SetBranchAddress("ljet_Tau21_wta", &ljet_Tau21_wta, &b_ljet_Tau21_wta);
   fChain->SetBranchAddress("ljet_Tau32_wta", &ljet_Tau32_wta, &b_ljet_Tau32_wta);
   fChain->SetBranchAddress("ljet_istTagged_L", &ljet_istTagged_L, &b_ljet_istTagged_L);
   fChain->SetBranchAddress("ljet_istTagged_T", &ljet_istTagged_T, &b_ljet_istTagged_T);
   fChain->SetBranchAddress("ljet_isWTagged_M", &ljet_isWTagged_M, &b_ljet_isWTagged_M);
   fChain->SetBranchAddress("ljet_isWTagged_T", &ljet_isWTagged_T, &b_ljet_isWTagged_T);
   fChain->SetBranchAddress("ljet_isZTagged_M", &ljet_isZTagged_M, &b_ljet_isZTagged_M);
   fChain->SetBranchAddress("ljet_isZTagged_T", &ljet_isZTagged_T, &b_ljet_isZTagged_T);
   fChain->SetBranchAddress("ljet_numConstituents", &ljet_numConstituents, &b_ljet_numConstituents);
   Notify();
}

Bool_t AtlMin::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AtlMin::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AtlMin::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AtlMin_cxx
