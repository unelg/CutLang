#ifndef VLLt_h
#define VLLt_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"
#include "vector"
#include <iostream>
using namespace std;

class VLLt {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         actualInteractionsPerCrossing;
   Float_t         averageInteractionsPerCrossing;
   vector<int>     *el_IFFClass;
   vector<float>   *el_charge;
   vector<float>   *el_eta;
   vector<float>   *el_phi;
   ULong64_t       eventNumber;
   vector<int>     *jet_GN2v01_Continuous_quantile;
   vector<char>    *jet_GN2v01_FixedCutBEff_65_select;
   vector<char>    *jet_GN2v01_FixedCutBEff_70_select;
   vector<char>    *jet_GN2v01_FixedCutBEff_77_select;
   vector<char>    *jet_GN2v01_FixedCutBEff_85_select;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   UInt_t          mcChannelNumber;
   vector<int>     *mu_IFFClass;
   vector<float>   *mu_charge;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_ptvarcone20;
   vector<float>   *ph_eta;
   vector<float>   *ph_phi;
   UInt_t          runNumber;
   Bool_t          trigPassed_HLT_2mu10_l2mt_L1MU10BOM;
   Bool_t          trigPassed_HLT_2mu14_L12MU8F;
   Bool_t          trigPassed_HLT_e26_lhtight_ivarloose_L1eEM26M;
   Bool_t          trigPassed_HLT_e60_lhmedium_L1eEM26M;
   Bool_t          trigPassed_HLT_g140_loose_L1EM22VHI;
   Bool_t          trigPassed_HLT_g140_loose_L1eEM26M;
   Bool_t          trigPassed_HLT_g300_etcut_L1EM22VHI;
   Bool_t          trigPassed_HLT_g300_etcut_L1eEM26M;
   Bool_t          trigPassed_HLT_j400_pf_ftf_preselj225_L1J100;
   Bool_t          trigPassed_HLT_j420_pf_ftf_preselj225_L1J100;
   Bool_t          trigPassed_HLT_mu20_LRT_d0loose_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu20_ivarmedium_mu8noL1_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu22_mu8noL1_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu24_ivarmedium_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu50_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu60_0eta105_msonly_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu60_L1MU14FCH;
   Bool_t          trigPassed_HLT_mu80_msonly_3layersEC_L1MU14FCH;
   vector<float>   *el_e_NOSYS;
   vector<float>   *el_id_effSF_loose_NOSYS;
   vector<float>   *el_id_effSF_tight_NOSYS;
   vector<float>   *el_isol_effSF_tight_NOSYS;
   vector<float>   *el_pt_NOSYS;
   vector<float>   *el_reco_effSF_loose_NOSYS;
   vector<float>   *el_reco_effSF_tight_NOSYS;
   vector<char>    *el_select_loose_NOSYS;
   vector<char>    *el_select_outputSelect_NOSYS;
   vector<char>    *el_select_tight_NOSYS;
   vector<float>   *jet_e_NOSYS;
   vector<float>   *jet_pt_NOSYS;
   vector<char>    *jet_select_GN2v01_FixedCutBEff_65_NOSYS;
   vector<char>    *jet_select_GN2v01_FixedCutBEff_70_NOSYS;
   vector<char>    *jet_select_GN2v01_FixedCutBEff_77_NOSYS;
   vector<char>    *jet_select_GN2v01_FixedCutBEff_85_NOSYS;
   vector<char>    *jet_select_baselineJvt_NOSYS;
   vector<char>    *jet_select_outputSelect_NOSYS;
   vector<float>   *mu_TTVA_effSF_tight_NOSYS;
   vector<float>   *mu_e_NOSYS;
   vector<float>   *mu_isol_effSF_tight_NOSYS;
   vector<float>   *mu_pt_NOSYS;
   vector<float>   *mu_reco_effSF_tight_NOSYS;
   vector<char>    *mu_select_outputSelect_NOSYS;
   vector<char>    *mu_select_tight_NOSYS;
   Char_t          pass_SUBcommon_NOSYS;
   vector<float>   *ph_e_NOSYS;
   vector<float>   *ph_id_effSF_loose_NOSYS;
   vector<float>   *ph_id_effSF_tight_NOSYS;
   vector<float>   *ph_isol_effSF_tight_NOSYS;
   vector<float>   *ph_pt_NOSYS;
   vector<char>    *ph_select_loose_NOSYS;
   vector<char>    *ph_select_outputSelect_NOSYS;
   vector<char>    *ph_select_tight_NOSYS;
   Float_t         weight_ftag_effSF_GN2v01_Continuous_NOSYS;
   Float_t         weight_jvt_effSF_NOSYS;
   Float_t         weight_mc_NOSYS;
   Float_t         weight_pileup_NOSYS;
   Float_t         met_met_NOSYS;
   Float_t         met_phi_NOSYS;
   Float_t         met_significance_NOSYS;
   Float_t         met_sumet_NOSYS;

   // List of branches
   TBranch        *b_actualInteractionsPerCrossing;   //!
   TBranch        *b_averageInteractionsPerCrossing;   //!
   TBranch        *b_el_IFFClass;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_jet_GN2v01_Continuous_quantile;   //!
   TBranch        *b_jet_GN2v01_FixedCutBEff_65_select;   //!
   TBranch        *b_jet_GN2v01_FixedCutBEff_70_select;   //!
   TBranch        *b_jet_GN2v01_FixedCutBEff_77_select;   //!
   TBranch        *b_jet_GN2v01_FixedCutBEff_85_select;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu_IFFClass;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_ptvarcone20;   //!
   TBranch        *b_ph_eta;   //!
   TBranch        *b_ph_phi;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_trigPassed_HLT_2mu10_l2mt_L1MU10BOM;   //!
   TBranch        *b_trigPassed_HLT_2mu14_L12MU8F;   //!
   TBranch        *b_trigPassed_HLT_e26_lhtight_ivarloose_L1eEM26M;   //!
   TBranch        *b_trigPassed_HLT_e60_lhmedium_L1eEM26M;   //!
   TBranch        *b_trigPassed_HLT_g140_loose_L1EM22VHI;   //!
   TBranch        *b_trigPassed_HLT_g140_loose_L1eEM26M;   //!
   TBranch        *b_trigPassed_HLT_g300_etcut_L1EM22VHI;   //!
   TBranch        *b_trigPassed_HLT_g300_etcut_L1eEM26M;   //!
   TBranch        *b_trigPassed_HLT_j400_pf_ftf_preselj225_L1J100;   //!
   TBranch        *b_trigPassed_HLT_j420_pf_ftf_preselj225_L1J100;   //!
   TBranch        *b_trigPassed_HLT_mu20_LRT_d0loose_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu20_ivarmedium_mu8noL1_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu22_mu8noL1_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu24_ivarmedium_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu50_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu60_0eta105_msonly_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu60_L1MU14FCH;   //!
   TBranch        *b_trigPassed_HLT_mu80_msonly_3layersEC_L1MU14FCH;   //!
   TBranch        *b_el_e_NOSYS;   //!
   TBranch        *b_el_id_effSF_loose_NOSYS;   //!
   TBranch        *b_el_id_effSF_tight_NOSYS;   //!
   TBranch        *b_el_isol_effSF_tight_NOSYS;   //!
   TBranch        *b_el_pt_NOSYS;   //!
   TBranch        *b_el_reco_effSF_loose_NOSYS;   //!
   TBranch        *b_el_reco_effSF_tight_NOSYS;   //!
   TBranch        *b_el_select_loose_NOSYS;   //!
   TBranch        *b_el_select_outputSelect_NOSYS;   //!
   TBranch        *b_el_select_tight_NOSYS;   //!
   TBranch        *b_jet_e_NOSYS;   //!
   TBranch        *b_jet_pt_NOSYS;   //!
   TBranch        *b_jet_select_GN2v01_FixedCutBEff_65_NOSYS;   //!
   TBranch        *b_jet_select_GN2v01_FixedCutBEff_70_NOSYS;   //!
   TBranch        *b_jet_select_GN2v01_FixedCutBEff_77_NOSYS;   //!
   TBranch        *b_jet_select_GN2v01_FixedCutBEff_85_NOSYS;   //!
   TBranch        *b_jet_select_baselineJvt_NOSYS;   //!
   TBranch        *b_jet_select_outputSelect_NOSYS;   //!
   TBranch        *b_mu_TTVA_effSF_tight_NOSYS;   //!
   TBranch        *b_mu_e_NOSYS;   //!
   TBranch        *b_mu_isol_effSF_tight_NOSYS;   //!
   TBranch        *b_mu_pt_NOSYS;   //!
   TBranch        *b_mu_reco_effSF_tight_NOSYS;   //!
   TBranch        *b_mu_select_outputSelect_NOSYS;   //!
   TBranch        *b_mu_select_tight_NOSYS;   //!
   TBranch        *b_pass_SUBcommon_NOSYS;   //!
   TBranch        *b_ph_e_NOSYS;   //!
   TBranch        *b_ph_id_effSF_loose_NOSYS;   //!
   TBranch        *b_ph_id_effSF_tight_NOSYS;   //!
   TBranch        *b_ph_isol_effSF_tight_NOSYS;   //!
   TBranch        *b_ph_pt_NOSYS;   //!
   TBranch        *b_ph_select_loose_NOSYS;   //!
   TBranch        *b_ph_select_outputSelect_NOSYS;   //!
   TBranch        *b_ph_select_tight_NOSYS;   //!
   TBranch        *b_weight_ftag_effSF_GN2v01_Continuous_NOSYS;   //!
   TBranch        *b_weight_jvt_effSF_NOSYS;   //!
   TBranch        *b_weight_mc_NOSYS;   //!
   TBranch        *b_weight_pileup_NOSYS;   //!
   TBranch        *b_met_met_NOSYS;   //!
   TBranch        *b_met_phi_NOSYS;   //!
   TBranch        *b_met_significance_NOSYS;   //!
   TBranch        *b_met_sumet_NOSYS;   //!

   VLLt(char *file_name, TChain *tree=0);
   virtual ~VLLt();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
};

#endif

#ifdef VLLt_cxx
VLLt::VLLt(char *file_name, TChain *tree) : fChain(0) 
{
   TChain* chain;
   if (tree == 0) {
      chain = new TChain("reco");
      chain->Add(file_name);
   }
   if (tree == 0) {
      Init(chain);
   } else {
      Init(tree);
   }
}

VLLt::~VLLt()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLt::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLt::LoadTree(Long64_t entry)
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

void VLLt::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   el_IFFClass = 0;
   el_charge = 0;
   el_eta = 0;
   el_phi = 0;
   jet_GN2v01_Continuous_quantile = 0;
   jet_GN2v01_FixedCutBEff_65_select = 0;
   jet_GN2v01_FixedCutBEff_70_select = 0;
   jet_GN2v01_FixedCutBEff_77_select = 0;
   jet_GN2v01_FixedCutBEff_85_select = 0;
   jet_eta = 0;
   jet_phi = 0;
   mu_IFFClass = 0;
   mu_charge = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_ptvarcone20 = 0;
   ph_eta = 0;
   ph_phi = 0;
   el_e_NOSYS = 0;
   el_id_effSF_loose_NOSYS = 0;
   el_id_effSF_tight_NOSYS = 0;
   el_isol_effSF_tight_NOSYS = 0;
   el_pt_NOSYS = 0;
   el_reco_effSF_loose_NOSYS = 0;
   el_reco_effSF_tight_NOSYS = 0;
   el_select_loose_NOSYS = 0;
   el_select_outputSelect_NOSYS = 0;
   el_select_tight_NOSYS = 0;
   jet_e_NOSYS = 0;
   jet_pt_NOSYS = 0;
   jet_select_GN2v01_FixedCutBEff_65_NOSYS = 0;
   jet_select_GN2v01_FixedCutBEff_70_NOSYS = 0;
   jet_select_GN2v01_FixedCutBEff_77_NOSYS = 0;
   jet_select_GN2v01_FixedCutBEff_85_NOSYS = 0;
   jet_select_baselineJvt_NOSYS = 0;
   jet_select_outputSelect_NOSYS = 0;
   mu_TTVA_effSF_tight_NOSYS = 0;
   mu_e_NOSYS = 0;
   mu_isol_effSF_tight_NOSYS = 0;
   mu_pt_NOSYS = 0;
   mu_reco_effSF_tight_NOSYS = 0;
   mu_select_outputSelect_NOSYS = 0;
   mu_select_tight_NOSYS = 0;
   ph_e_NOSYS = 0;
   ph_id_effSF_loose_NOSYS = 0;
   ph_id_effSF_tight_NOSYS = 0;
   ph_isol_effSF_tight_NOSYS = 0;
   ph_pt_NOSYS = 0;
   ph_select_loose_NOSYS = 0;
   ph_select_outputSelect_NOSYS = 0;
   ph_select_tight_NOSYS = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing, &b_actualInteractionsPerCrossing);
   fChain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing, &b_averageInteractionsPerCrossing);
   fChain->SetBranchAddress("el_IFFClass", &el_IFFClass, &b_el_IFFClass);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("jet_GN2v01_Continuous_quantile", &jet_GN2v01_Continuous_quantile, &b_jet_GN2v01_Continuous_quantile);
   fChain->SetBranchAddress("jet_GN2v01_FixedCutBEff_65_select", &jet_GN2v01_FixedCutBEff_65_select, &b_jet_GN2v01_FixedCutBEff_65_select);
   fChain->SetBranchAddress("jet_GN2v01_FixedCutBEff_70_select", &jet_GN2v01_FixedCutBEff_70_select, &b_jet_GN2v01_FixedCutBEff_70_select);
   fChain->SetBranchAddress("jet_GN2v01_FixedCutBEff_77_select", &jet_GN2v01_FixedCutBEff_77_select, &b_jet_GN2v01_FixedCutBEff_77_select);
   fChain->SetBranchAddress("jet_GN2v01_FixedCutBEff_85_select", &jet_GN2v01_FixedCutBEff_85_select, &b_jet_GN2v01_FixedCutBEff_85_select);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu_IFFClass", &mu_IFFClass, &b_mu_IFFClass);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_ptvarcone20", &mu_ptvarcone20, &b_mu_ptvarcone20);
   fChain->SetBranchAddress("ph_eta", &ph_eta, &b_ph_eta);
   fChain->SetBranchAddress("ph_phi", &ph_phi, &b_ph_phi);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("trigPassed_HLT_2mu10_l2mt_L1MU10BOM", &trigPassed_HLT_2mu10_l2mt_L1MU10BOM, &b_trigPassed_HLT_2mu10_l2mt_L1MU10BOM);
   fChain->SetBranchAddress("trigPassed_HLT_2mu14_L12MU8F", &trigPassed_HLT_2mu14_L12MU8F, &b_trigPassed_HLT_2mu14_L12MU8F);
   fChain->SetBranchAddress("trigPassed_HLT_e26_lhtight_ivarloose_L1eEM26M", &trigPassed_HLT_e26_lhtight_ivarloose_L1eEM26M, &b_trigPassed_HLT_e26_lhtight_ivarloose_L1eEM26M);
   fChain->SetBranchAddress("trigPassed_HLT_e60_lhmedium_L1eEM26M", &trigPassed_HLT_e60_lhmedium_L1eEM26M, &b_trigPassed_HLT_e60_lhmedium_L1eEM26M);
   fChain->SetBranchAddress("trigPassed_HLT_g140_loose_L1EM22VHI", &trigPassed_HLT_g140_loose_L1EM22VHI, &b_trigPassed_HLT_g140_loose_L1EM22VHI);
   fChain->SetBranchAddress("trigPassed_HLT_g140_loose_L1eEM26M", &trigPassed_HLT_g140_loose_L1eEM26M, &b_trigPassed_HLT_g140_loose_L1eEM26M);
   fChain->SetBranchAddress("trigPassed_HLT_g300_etcut_L1EM22VHI", &trigPassed_HLT_g300_etcut_L1EM22VHI, &b_trigPassed_HLT_g300_etcut_L1EM22VHI);
   fChain->SetBranchAddress("trigPassed_HLT_g300_etcut_L1eEM26M", &trigPassed_HLT_g300_etcut_L1eEM26M, &b_trigPassed_HLT_g300_etcut_L1eEM26M);
   fChain->SetBranchAddress("trigPassed_HLT_j400_pf_ftf_preselj225_L1J100", &trigPassed_HLT_j400_pf_ftf_preselj225_L1J100, &b_trigPassed_HLT_j400_pf_ftf_preselj225_L1J100);
   fChain->SetBranchAddress("trigPassed_HLT_j420_pf_ftf_preselj225_L1J100", &trigPassed_HLT_j420_pf_ftf_preselj225_L1J100, &b_trigPassed_HLT_j420_pf_ftf_preselj225_L1J100);
   fChain->SetBranchAddress("trigPassed_HLT_mu20_LRT_d0loose_L1MU14FCH", &trigPassed_HLT_mu20_LRT_d0loose_L1MU14FCH, &b_trigPassed_HLT_mu20_LRT_d0loose_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu20_ivarmedium_mu8noL1_L1MU14FCH", &trigPassed_HLT_mu20_ivarmedium_mu8noL1_L1MU14FCH, &b_trigPassed_HLT_mu20_ivarmedium_mu8noL1_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu22_mu8noL1_L1MU14FCH", &trigPassed_HLT_mu22_mu8noL1_L1MU14FCH, &b_trigPassed_HLT_mu22_mu8noL1_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu24_ivarmedium_L1MU14FCH", &trigPassed_HLT_mu24_ivarmedium_L1MU14FCH, &b_trigPassed_HLT_mu24_ivarmedium_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu50_L1MU14FCH", &trigPassed_HLT_mu50_L1MU14FCH, &b_trigPassed_HLT_mu50_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu60_0eta105_msonly_L1MU14FCH", &trigPassed_HLT_mu60_0eta105_msonly_L1MU14FCH, &b_trigPassed_HLT_mu60_0eta105_msonly_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu60_L1MU14FCH", &trigPassed_HLT_mu60_L1MU14FCH, &b_trigPassed_HLT_mu60_L1MU14FCH);
   fChain->SetBranchAddress("trigPassed_HLT_mu80_msonly_3layersEC_L1MU14FCH", &trigPassed_HLT_mu80_msonly_3layersEC_L1MU14FCH, &b_trigPassed_HLT_mu80_msonly_3layersEC_L1MU14FCH);
   fChain->SetBranchAddress("el_e_NOSYS", &el_e_NOSYS, &b_el_e_NOSYS);
   fChain->SetBranchAddress("el_id_effSF_loose_NOSYS", &el_id_effSF_loose_NOSYS, &b_el_id_effSF_loose_NOSYS);
   fChain->SetBranchAddress("el_id_effSF_tight_NOSYS", &el_id_effSF_tight_NOSYS, &b_el_id_effSF_tight_NOSYS);
   fChain->SetBranchAddress("el_isol_effSF_tight_NOSYS", &el_isol_effSF_tight_NOSYS, &b_el_isol_effSF_tight_NOSYS);
   fChain->SetBranchAddress("el_pt_NOSYS", &el_pt_NOSYS, &b_el_pt_NOSYS);
   fChain->SetBranchAddress("el_reco_effSF_loose_NOSYS", &el_reco_effSF_loose_NOSYS, &b_el_reco_effSF_loose_NOSYS);
   fChain->SetBranchAddress("el_reco_effSF_tight_NOSYS", &el_reco_effSF_tight_NOSYS, &b_el_reco_effSF_tight_NOSYS);
   fChain->SetBranchAddress("el_select_loose_NOSYS", &el_select_loose_NOSYS, &b_el_select_loose_NOSYS);
   fChain->SetBranchAddress("el_select_outputSelect_NOSYS", &el_select_outputSelect_NOSYS, &b_el_select_outputSelect_NOSYS);
   fChain->SetBranchAddress("el_select_tight_NOSYS", &el_select_tight_NOSYS, &b_el_select_tight_NOSYS);
   fChain->SetBranchAddress("jet_e_NOSYS", &jet_e_NOSYS, &b_jet_e_NOSYS);
   fChain->SetBranchAddress("jet_pt_NOSYS", &jet_pt_NOSYS, &b_jet_pt_NOSYS);
   fChain->SetBranchAddress("jet_select_GN2v01_FixedCutBEff_65_NOSYS", &jet_select_GN2v01_FixedCutBEff_65_NOSYS, &b_jet_select_GN2v01_FixedCutBEff_65_NOSYS);
   fChain->SetBranchAddress("jet_select_GN2v01_FixedCutBEff_70_NOSYS", &jet_select_GN2v01_FixedCutBEff_70_NOSYS, &b_jet_select_GN2v01_FixedCutBEff_70_NOSYS);
   fChain->SetBranchAddress("jet_select_GN2v01_FixedCutBEff_77_NOSYS", &jet_select_GN2v01_FixedCutBEff_77_NOSYS, &b_jet_select_GN2v01_FixedCutBEff_77_NOSYS);
   fChain->SetBranchAddress("jet_select_GN2v01_FixedCutBEff_85_NOSYS", &jet_select_GN2v01_FixedCutBEff_85_NOSYS, &b_jet_select_GN2v01_FixedCutBEff_85_NOSYS);
   fChain->SetBranchAddress("jet_select_baselineJvt_NOSYS", &jet_select_baselineJvt_NOSYS, &b_jet_select_baselineJvt_NOSYS);
   fChain->SetBranchAddress("jet_select_outputSelect_NOSYS", &jet_select_outputSelect_NOSYS, &b_jet_select_outputSelect_NOSYS);
   fChain->SetBranchAddress("mu_TTVA_effSF_tight_NOSYS", &mu_TTVA_effSF_tight_NOSYS, &b_mu_TTVA_effSF_tight_NOSYS);
   fChain->SetBranchAddress("mu_e_NOSYS", &mu_e_NOSYS, &b_mu_e_NOSYS);
   fChain->SetBranchAddress("mu_isol_effSF_tight_NOSYS", &mu_isol_effSF_tight_NOSYS, &b_mu_isol_effSF_tight_NOSYS);
   fChain->SetBranchAddress("mu_pt_NOSYS", &mu_pt_NOSYS, &b_mu_pt_NOSYS);
   fChain->SetBranchAddress("mu_reco_effSF_tight_NOSYS", &mu_reco_effSF_tight_NOSYS, &b_mu_reco_effSF_tight_NOSYS);
   fChain->SetBranchAddress("mu_select_outputSelect_NOSYS", &mu_select_outputSelect_NOSYS, &b_mu_select_outputSelect_NOSYS);
   fChain->SetBranchAddress("mu_select_tight_NOSYS", &mu_select_tight_NOSYS, &b_mu_select_tight_NOSYS);
   fChain->SetBranchAddress("pass_SUBcommon_NOSYS", &pass_SUBcommon_NOSYS, &b_pass_SUBcommon_NOSYS);
   fChain->SetBranchAddress("ph_e_NOSYS", &ph_e_NOSYS, &b_ph_e_NOSYS);
   fChain->SetBranchAddress("ph_id_effSF_loose_NOSYS", &ph_id_effSF_loose_NOSYS, &b_ph_id_effSF_loose_NOSYS);
   fChain->SetBranchAddress("ph_id_effSF_tight_NOSYS", &ph_id_effSF_tight_NOSYS, &b_ph_id_effSF_tight_NOSYS);
   fChain->SetBranchAddress("ph_isol_effSF_tight_NOSYS", &ph_isol_effSF_tight_NOSYS, &b_ph_isol_effSF_tight_NOSYS);
   fChain->SetBranchAddress("ph_pt_NOSYS", &ph_pt_NOSYS, &b_ph_pt_NOSYS);
   fChain->SetBranchAddress("ph_select_loose_NOSYS", &ph_select_loose_NOSYS, &b_ph_select_loose_NOSYS);
   fChain->SetBranchAddress("ph_select_outputSelect_NOSYS", &ph_select_outputSelect_NOSYS, &b_ph_select_outputSelect_NOSYS);
   fChain->SetBranchAddress("ph_select_tight_NOSYS", &ph_select_tight_NOSYS, &b_ph_select_tight_NOSYS);
   fChain->SetBranchAddress("weight_ftag_effSF_GN2v01_Continuous_NOSYS", &weight_ftag_effSF_GN2v01_Continuous_NOSYS, &b_weight_ftag_effSF_GN2v01_Continuous_NOSYS);
   fChain->SetBranchAddress("weight_jvt_effSF_NOSYS", &weight_jvt_effSF_NOSYS, &b_weight_jvt_effSF_NOSYS);
   fChain->SetBranchAddress("weight_mc_NOSYS", &weight_mc_NOSYS, &b_weight_mc_NOSYS);
   fChain->SetBranchAddress("weight_pileup_NOSYS", &weight_pileup_NOSYS, &b_weight_pileup_NOSYS);
   fChain->SetBranchAddress("met_met_NOSYS", &met_met_NOSYS, &b_met_met_NOSYS);
   fChain->SetBranchAddress("met_phi_NOSYS", &met_phi_NOSYS, &b_met_phi_NOSYS);
   fChain->SetBranchAddress("met_significance_NOSYS", &met_significance_NOSYS, &b_met_significance_NOSYS);
   fChain->SetBranchAddress("met_sumet_NOSYS", &met_sumet_NOSYS, &b_met_sumet_NOSYS);
}

#endif // #ifdef VLLt_cxx
