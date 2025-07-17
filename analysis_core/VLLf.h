#ifndef VLLf_h
#define VLLf_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"
#include "vector"
#include <iostream>
#include "ROOT/RVec.hxx"
using namespace std;

class VLLf {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         Boson1_jetA_pt;
   Float_t         Boson1_mass;
   Float_t         Boson1_pt;
   Float_t         Boson2_jetC_pt;
   Float_t         Boson2_mass;
   Float_t         Boson2_pt;
   Float_t         DRll01;
   Float_t         DRll02;
   Float_t         DRll03;
   Float_t         DRll12;
   Float_t         DRll13;
   Float_t         DRll23;
   Float_t         DeltaR_min_lep_bjet77;
   Float_t         GenFiltHT;
   Float_t         HT;
   Float_t         HT_jets;
   Float_t         HT_lep;
   Int_t           IFFClass_lep_0;
   Int_t           IFFClass_lep_1;
   Int_t           IFFClass_lep_2;
   Int_t           IFFClass_lep_3;
   Float_t         MTlmet;
   Float_t         Mll01;
   Float_t         Mll02;
   Float_t         Mll03;
   Float_t         Mll12;
   Float_t         Mll13;
   Float_t         Mll23;
   Float_t         Mlll012;
   Float_t         Mlll013;
   Float_t         Mlll023;
   Float_t         Mlll123;
   Int_t           N_IFF_Bdecays;
   Int_t           N_IFF_Cdecays;
   Int_t           N_IFF_EfromMu;
   Int_t           N_IFF_IntConv;
   Int_t           N_IFF_KnownUnknown;
   Int_t           N_IFF_LightHadDecays;
   Int_t           N_IFF_MatConv;
   Int_t           N_IFF_Prompt;
   Int_t           N_IFF_QmisID;
   Int_t           N_IFF_TauDecays;
   Int_t           N_IFF_Unclassified;
   Int_t           RecoRegion;
   Int_t           RunYear;
   Float_t         VLL1_mass;
   Float_t         VLL2_mass;
   Int_t           VLL_decayHdecays;
   Int_t           VLL_decayWdecays;
   Int_t           VLL_decayZdecays;
   Int_t           VLL_decaytype;
   Int_t           VLL_type;
   Float_t         bTagSF_weight_DL1r_60;
   Float_t         bTagSF_weight_DL1r_70;
   Float_t         bTagSF_weight_DL1r_77;
   Float_t         bTagSF_weight_DL1r_85;
   Float_t         bTagSF_weight_DL1r_Continuous;
   Char_t          custTrigMatch_LooseID_FCLooseIso_SLTorDLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Char_t          dilep_type;
   ULong64_t       eventNumber;
   Bool_t          filterDuplicateEvents;
   Char_t          flag_passMETtrig;
   Int_t           hhiggsDecayMode;
   Int_t           higgsDecayMode;
   Float_t         highpt_trubjet;
   Int_t           initial_state;
   Float_t         jet_eta0;
   Float_t         jet_eta1;
   Int_t           jet_pseudoscore_DL1r0;
   Int_t           jet_pseudoscore_DL1r1;
   Int_t           jet_pseudoscore_DL1r2;
   Int_t           jet_pseudoscore_DL1r3;
   Int_t           jet_pseudoscore_DL1r4;
   Float_t         jet_pt0;
   Float_t         jet_pt1;
   ROOT::VecOps::RVec<char> *jets_ConeTruthLabelID;
   ROOT::VecOps::RVec<char> *jets_HadronConeExclExtendedTruthLabelID;
   ROOT::VecOps::RVec<char> *jets_HadronConeExclTruthLabelID;
   ROOT::VecOps::RVec<char> *jets_PartonTruthLabelID;
   ROOT::VecOps::RVec<char> *jets_btagFlag_DL1r_ContinuousBin;
   ROOT::VecOps::RVec<char> *jets_btagFlag_DL1r_FixedCutBEff_60;
   ROOT::VecOps::RVec<char> *jets_btagFlag_DL1r_FixedCutBEff_70;
   ROOT::VecOps::RVec<char> *jets_btagFlag_DL1r_FixedCutBEff_77;
   ROOT::VecOps::RVec<char> *jets_btagFlag_DL1r_FixedCutBEff_85;
   ROOT::VecOps::RVec<float> *jets_btag_JetVertexCharge_discriminant;
   ROOT::VecOps::RVec<float> *jets_e;
   ROOT::VecOps::RVec<float> *jets_eta;
   ROOT::VecOps::RVec<float> *jets_phi;
   ROOT::VecOps::RVec<float> *jets_pt;
   ROOT::VecOps::RVec<float> *jets_score_DL1r;
   ROOT::VecOps::RVec<float> *jets_score_DL1r_pb;
   ROOT::VecOps::RVec<float> *jets_score_DL1r_pc;
   ROOT::VecOps::RVec<float> *jets_score_DL1r_pu;
   Float_t         jvtSF_customOR;
   Float_t         lepSFObjChannelCombined;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSF_PLIV_IFF_Prompt_0;
   Float_t         lepSF_PLIV_IFF_Prompt_1;
   Float_t         lepSF_PLIV_IFF_Prompt_2;
   Float_t         lepSF_PLIV_Prompt_0;
   Float_t         lepSF_PLIV_Prompt_1;
   Float_t         lepSF_PLIV_Prompt_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;
   Int_t           lep_AnpTruthType_0;
   Int_t           lep_AnpTruthType_1;
   Int_t           lep_AnpTruthType_2;
   Int_t           lep_AnpTruthType_3;
   Int_t           lep_DFCommonAddAmbiguity_0;
   Int_t           lep_DFCommonAddAmbiguity_1;
   Int_t           lep_DFCommonAddAmbiguity_2;
   Int_t           lep_DFCommonAddAmbiguity_3;
   Float_t         lep_DFCommonSimpleConvPhi_0;
   Float_t         lep_DFCommonSimpleConvPhi_1;
   Float_t         lep_DFCommonSimpleConvPhi_2;
   Float_t         lep_DFCommonSimpleConvPhi_3;
   Float_t         lep_DFCommonSimpleConvRadius_0;
   Float_t         lep_DFCommonSimpleConvRadius_1;
   Float_t         lep_DFCommonSimpleConvRadius_2;
   Float_t         lep_DFCommonSimpleConvRadius_3;
   Float_t         lep_DFCommonSimpleMeeAtVtx_0;
   Float_t         lep_DFCommonSimpleMeeAtVtx_1;
   Float_t         lep_DFCommonSimpleMeeAtVtx_2;
   Float_t         lep_DFCommonSimpleMeeAtVtx_3;
   Float_t         lep_DFCommonSimpleMee_0;
   Float_t         lep_DFCommonSimpleMee_1;
   Float_t         lep_DFCommonSimpleMee_2;
   Float_t         lep_DFCommonSimpleMee_3;
   Float_t         lep_E_0;
   Float_t         lep_E_1;
   Float_t         lep_E_2;
   Float_t         lep_E_3;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_Eta_0;
   Float_t         lep_Eta_1;
   Float_t         lep_Eta_2;
   Float_t         lep_Eta_3;
   Float_t         lep_ID_0;
   Float_t         lep_ID_1;
   Float_t         lep_ID_2;
   Float_t         lep_ID_3;
   Int_t           lep_Index_0;
   Int_t           lep_Index_1;
   Int_t           lep_Index_2;
   Int_t           lep_Index_3;
   Float_t         lep_Mtrktrk_atConvV_CO_0;
   Float_t         lep_Mtrktrk_atConvV_CO_1;
   Float_t         lep_Mtrktrk_atConvV_CO_2;
   Float_t         lep_Mtrktrk_atConvV_CO_3;
   Float_t         lep_Mtrktrk_atPV_CO_0;
   Float_t         lep_Mtrktrk_atPV_CO_1;
   Float_t         lep_Mtrktrk_atPV_CO_2;
   Float_t         lep_Mtrktrk_atPV_CO_3;
   Float_t         lep_Phi_0;
   Float_t         lep_Phi_1;
   Float_t         lep_Phi_2;
   Float_t         lep_Phi_3;
   Float_t         lep_Pt_0;
   Float_t         lep_Pt_1;
   Float_t         lep_Pt_2;
   Float_t         lep_Pt_3;
   Float_t         lep_RadiusCOX_0;
   Float_t         lep_RadiusCOX_1;
   Float_t         lep_RadiusCOX_2;
   Float_t         lep_RadiusCOX_3;
   Float_t         lep_RadiusCOY_0;
   Float_t         lep_RadiusCOY_1;
   Float_t         lep_RadiusCOY_2;
   Float_t         lep_RadiusCOY_3;
   Float_t         lep_RadiusCO_0;
   Float_t         lep_RadiusCO_1;
   Float_t         lep_RadiusCO_2;
   Float_t         lep_RadiusCO_3;
   Float_t         lep_SF_CombinedLoose_0;
   Float_t         lep_SF_CombinedLoose_1;
   Float_t         lep_SF_CombinedLoose_2;
   Float_t         lep_SF_CombinedLoose_3;
   Float_t         lep_SF_CombinedTight_0;
   Float_t         lep_SF_CombinedTight_1;
   Float_t         lep_SF_CombinedTight_2;
   Float_t         lep_SF_CombinedTight_3;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_0;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_1;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_2;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_3;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_0;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_1;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_2;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_3;
   Float_t         lep_SF_El_ID_MediumLH_0;
   Float_t         lep_SF_El_ID_MediumLH_1;
   Float_t         lep_SF_El_ID_MediumLH_2;
   Float_t         lep_SF_El_ID_MediumLH_3;
   Float_t         lep_SF_El_ID_TightLH_AT_0;
   Float_t         lep_SF_El_ID_TightLH_AT_1;
   Float_t         lep_SF_El_ID_TightLH_AT_2;
   Float_t         lep_SF_El_ID_TightLH_AT_3;
   Float_t         lep_SF_El_Iso_FCLoose_AT_0;
   Float_t         lep_SF_El_Iso_FCLoose_AT_1;
   Float_t         lep_SF_El_Iso_FCLoose_AT_2;
   Float_t         lep_SF_El_Iso_FCLoose_AT_3;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_0;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_1;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_2;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_3;
   Float_t         lep_SF_El_LooseAndBLayerLHQMisID_0;
   Float_t         lep_SF_El_LooseAndBLayerLHQMisID_1;
   Float_t         lep_SF_El_LooseAndBLayerLHQMisID_2;
   Float_t         lep_SF_El_LooseAndBLayerLHQMisID_3;
   Float_t         lep_SF_El_MediumFCLooseQMisID_0;
   Float_t         lep_SF_El_MediumFCLooseQMisID_1;
   Float_t         lep_SF_El_MediumFCLooseQMisID_2;
   Float_t         lep_SF_El_MediumFCLooseQMisID_3;
   Float_t         lep_SF_El_MediumFCTightECIDSLooseQMisID_0;
   Float_t         lep_SF_El_MediumFCTightECIDSLooseQMisID_1;
   Float_t         lep_SF_El_MediumFCTightECIDSLooseQMisID_2;
   Float_t         lep_SF_El_MediumFCTightECIDSLooseQMisID_3;
   Float_t         lep_SF_El_MediumGradientQMisID_0;
   Float_t         lep_SF_El_MediumGradientQMisID_1;
   Float_t         lep_SF_El_MediumGradientQMisID_2;
   Float_t         lep_SF_El_MediumGradientQMisID_3;
   Float_t         lep_SF_El_MediumGradienttECIDSLooseQMisID_0;
   Float_t         lep_SF_El_MediumGradienttECIDSLooseQMisID_1;
   Float_t         lep_SF_El_MediumGradienttECIDSLooseQMisID_2;
   Float_t         lep_SF_El_MediumGradienttECIDSLooseQMisID_3;
   Float_t         lep_SF_El_Reco_AT_0;
   Float_t         lep_SF_El_Reco_AT_1;
   Float_t         lep_SF_El_Reco_AT_2;
   Float_t         lep_SF_El_Reco_AT_3;
   Float_t         lep_SF_Mu_ID_Medium_AT_0;
   Float_t         lep_SF_Mu_ID_Medium_AT_1;
   Float_t         lep_SF_Mu_ID_Medium_AT_2;
   Float_t         lep_SF_Mu_ID_Medium_AT_3;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_0;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_1;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_2;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_3;
   Float_t         lep_SF_Mu_PLIV_MnotT_0;
   Float_t         lep_SF_Mu_PLIV_MnotT_1;
   Float_t         lep_SF_Mu_PLIV_MnotT_2;
   Float_t         lep_SF_Mu_PLIV_MnotT_3;
   Float_t         lep_SF_Mu_PLIV_T_0;
   Float_t         lep_SF_Mu_PLIV_T_1;
   Float_t         lep_SF_Mu_PLIV_T_2;
   Float_t         lep_SF_Mu_PLIV_T_3;
   Float_t         lep_SF_Mu_TTVA_AT_0;
   Float_t         lep_SF_Mu_TTVA_AT_1;
   Float_t         lep_SF_Mu_TTVA_AT_2;
   Float_t         lep_SF_Mu_TTVA_AT_3;
   Float_t         lep_SF_VLLem_CombinedFCLoose_0;
   Float_t         lep_SF_VLLem_CombinedFCLoose_1;
   Float_t         lep_SF_VLLem_CombinedFCLoose_2;
   Float_t         lep_SF_VLLem_CombinedFCLoose_3;
   Float_t         lep_SF_VLLem_CombinedPLIV_0;
   Float_t         lep_SF_VLLem_CombinedPLIV_1;
   Float_t         lep_SF_VLLem_CombinedPLIV_2;
   Float_t         lep_SF_VLLem_CombinedPLIV_3;
   Float_t         lep_SeparationMinDCT_0;
   Float_t         lep_SeparationMinDCT_1;
   Float_t         lep_SeparationMinDCT_2;
   Float_t         lep_SeparationMinDCT_3;
   Float_t         lep_Z0SinTheta_0;
   Float_t         lep_Z0SinTheta_1;
   Float_t         lep_Z0SinTheta_2;
   Float_t         lep_Z0SinTheta_3;
   UChar_t         lep_ambiguityType_0;
   UChar_t         lep_ambiguityType_1;
   UChar_t         lep_ambiguityType_2;
   UChar_t         lep_ambiguityType_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_3;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;
   Float_t         lep_d0_0;
   Float_t         lep_d0_1;
   Float_t         lep_d0_2;
   Float_t         lep_d0_3;
   Float_t         lep_deltaz0_0;
   Float_t         lep_deltaz0_1;
   Float_t         lep_deltaz0_2;
   Float_t         lep_deltaz0_3;
   Int_t           lep_firstEgMotherPdgId_0;
   Int_t           lep_firstEgMotherPdgId_1;
   Int_t           lep_firstEgMotherPdgId_2;
   Int_t           lep_firstEgMotherPdgId_3;
   Int_t           lep_firstEgMotherTruthOrigin_0;
   Int_t           lep_firstEgMotherTruthOrigin_1;
   Int_t           lep_firstEgMotherTruthOrigin_2;
   Int_t           lep_firstEgMotherTruthOrigin_3;
   Int_t           lep_firstEgMotherTruthType_0;
   Int_t           lep_firstEgMotherTruthType_1;
   Int_t           lep_firstEgMotherTruthType_2;
   Int_t           lep_firstEgMotherTruthType_3;
   Int_t           lep_flavour;
   Char_t          lep_isBrems_0;
   Char_t          lep_isBrems_1;
   Char_t          lep_isBrems_2;
   Char_t          lep_isBrems_3;
   Char_t          lep_isConvPh_0;
   Char_t          lep_isConvPh_1;
   Char_t          lep_isConvPh_2;
   Char_t          lep_isConvPh_3;
   Char_t          lep_isExtConvPh_0;
   Char_t          lep_isExtConvPh_1;
   Char_t          lep_isExtConvPh_2;
   Char_t          lep_isExtConvPh_3;
   Char_t          lep_isFakeLep_0;
   Char_t          lep_isFakeLep_1;
   Char_t          lep_isFakeLep_2;
   Char_t          lep_isFakeLep_3;
   Char_t          lep_isISR_FSR_Ph_0;
   Char_t          lep_isISR_FSR_Ph_1;
   Char_t          lep_isISR_FSR_Ph_2;
   Char_t          lep_isISR_FSR_Ph_3;
   Char_t          lep_isIntConvPh_0;
   Char_t          lep_isIntConvPh_1;
   Char_t          lep_isIntConvPh_2;
   Char_t          lep_isIntConvPh_3;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isLooseLH_3;
   Char_t          lep_isMedium_0;
   Char_t          lep_isMedium_1;
   Char_t          lep_isMedium_2;
   Char_t          lep_isMedium_3;
   Char_t          lep_isPrompt_0;
   Char_t          lep_isPrompt_1;
   Char_t          lep_isPrompt_2;
   Char_t          lep_isPrompt_3;
   Char_t          lep_isQMisID_0;
   Char_t          lep_isQMisID_1;
   Char_t          lep_isQMisID_2;
   Char_t          lep_isQMisID_3;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isTrigMatchDLT_0;
   Char_t          lep_isTrigMatchDLT_1;
   Char_t          lep_isTrigMatchDLT_2;
   Char_t          lep_isTrigMatchDLT_3;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_isTruthMatched_0;
   Char_t          lep_isTruthMatched_1;
   Char_t          lep_isTruthMatched_2;
   Char_t          lep_isTruthMatched_3;
   Char_t          lep_isolationPLImprovedTight_0;
   Char_t          lep_isolationPLImprovedTight_1;
   Char_t          lep_isolationPLImprovedTight_2;
   Char_t          lep_isolationPLImprovedTight_3;
   Char_t          lep_isolationPLImprovedVeryTight_0;
   Char_t          lep_isolationPLImprovedVeryTight_1;
   Char_t          lep_isolationPLImprovedVeryTight_2;
   Char_t          lep_isolationPLImprovedVeryTight_3;
   Int_t           lep_lastEgMotherPdgId_0;
   Int_t           lep_lastEgMotherPdgId_1;
   Int_t           lep_lastEgMotherPdgId_2;
   Int_t           lep_lastEgMotherPdgId_3;
   Int_t           lep_lastEgMotherTruthOrigin_0;
   Int_t           lep_lastEgMotherTruthOrigin_1;
   Int_t           lep_lastEgMotherTruthOrigin_2;
   Int_t           lep_lastEgMotherTruthOrigin_3;
   Int_t           lep_lastEgMotherTruthType_0;
   Int_t           lep_lastEgMotherTruthType_1;
   Int_t           lep_lastEgMotherTruthType_2;
   Int_t           lep_lastEgMotherTruthType_3;
   Int_t           lep_nInnerPix_0;
   Int_t           lep_nInnerPix_1;
   Int_t           lep_nInnerPix_2;
   Int_t           lep_nInnerPix_3;
   Int_t           lep_nTrackParticles_0;
   Int_t           lep_nTrackParticles_1;
   Int_t           lep_nTrackParticles_2;
   Int_t           lep_nTrackParticles_3;
   Char_t          lep_plvWP_Loose_0;
   Char_t          lep_plvWP_Loose_1;
   Char_t          lep_plvWP_Loose_2;
   Char_t          lep_plvWP_Loose_3;
   Char_t          lep_plvWP_Tight_0;
   Char_t          lep_plvWP_Tight_1;
   Char_t          lep_plvWP_Tight_2;
   Char_t          lep_plvWP_Tight_3;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_3;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_sigd0PV_3;
   Float_t         lep_truthE_0;
   Float_t         lep_truthE_1;
   Float_t         lep_truthE_2;
   Float_t         lep_truthE_3;
   Float_t         lep_truthEta_0;
   Float_t         lep_truthEta_1;
   Float_t         lep_truthEta_2;
   Float_t         lep_truthEta_3;
   Char_t          lep_truthHasTopInChain_0;
   Char_t          lep_truthHasTopInChain_1;
   Char_t          lep_truthHasTopInChain_2;
   Char_t          lep_truthHasTopInChain_3;
   Float_t         lep_truthM_0;
   Float_t         lep_truthM_1;
   Float_t         lep_truthM_2;
   Float_t         lep_truthM_3;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthOrigin_3;
   Int_t           lep_truthParentBarcode_0;
   Int_t           lep_truthParentBarcode_1;
   Int_t           lep_truthParentBarcode_2;
   Int_t           lep_truthParentBarcode_3;
   Float_t         lep_truthParentEta_0;
   Float_t         lep_truthParentEta_1;
   Float_t         lep_truthParentEta_2;
   Float_t         lep_truthParentEta_3;
   Char_t          lep_truthParentIsBHadron_0;
   Char_t          lep_truthParentIsBHadron_1;
   Char_t          lep_truthParentIsBHadron_2;
   Char_t          lep_truthParentIsBHadron_3;
   Char_t          lep_truthParentIsCHadron_0;
   Char_t          lep_truthParentIsCHadron_1;
   Char_t          lep_truthParentIsCHadron_2;
   Char_t          lep_truthParentIsCHadron_3;
   Int_t           lep_truthParentOrigin_0;
   Int_t           lep_truthParentOrigin_1;
   Int_t           lep_truthParentOrigin_2;
   Int_t           lep_truthParentOrigin_3;
   Int_t           lep_truthParentPdgId_0;
   Int_t           lep_truthParentPdgId_1;
   Int_t           lep_truthParentPdgId_2;
   Int_t           lep_truthParentPdgId_3;
   Float_t         lep_truthParentPt_0;
   Float_t         lep_truthParentPt_1;
   Float_t         lep_truthParentPt_2;
   Float_t         lep_truthParentPt_3;
   Int_t           lep_truthParentRealPdgId_0;
   Int_t           lep_truthParentRealPdgId_1;
   Int_t           lep_truthParentRealPdgId_2;
   Int_t           lep_truthParentRealPdgId_3;
   Int_t           lep_truthParentStatus_0;
   Int_t           lep_truthParentStatus_1;
   Int_t           lep_truthParentStatus_2;
   Int_t           lep_truthParentStatus_3;
   Int_t           lep_truthParentType_0;
   Int_t           lep_truthParentType_1;
   Int_t           lep_truthParentType_2;
   Int_t           lep_truthParentType_3;
   Int_t           lep_truthPdgId_0;
   Int_t           lep_truthPdgId_1;
   Int_t           lep_truthPdgId_2;
   Int_t           lep_truthPdgId_3;
   Float_t         lep_truthPhi_0;
   Float_t         lep_truthPhi_1;
   Float_t         lep_truthPhi_2;
   Float_t         lep_truthPhi_3;
   Float_t         lep_truthPt_0;
   Float_t         lep_truthPt_1;
   Float_t         lep_truthPt_2;
   Float_t         lep_truthPt_3;
   Float_t         lep_truthRapidity_0;
   Float_t         lep_truthRapidity_1;
   Float_t         lep_truthRapidity_2;
   Float_t         lep_truthRapidity_3;
   Int_t           lep_truthStatus_0;
   Int_t           lep_truthStatus_1;
   Int_t           lep_truthStatus_2;
   Int_t           lep_truthStatus_3;
   Int_t           lep_truthType_0;
   Int_t           lep_truthType_1;
   Int_t           lep_truthType_2;
   Int_t           lep_truthType_3;
   Float_t         lep_vz_0;
   Float_t         lep_vz_1;
   Float_t         lep_vz_2;
   Float_t         lep_vz_3;
   Float_t         lep_z0_0;
   Float_t         lep_z0_1;
   Float_t         lep_z0_2;
   Float_t         lep_z0_3;
   Int_t           lqlq_decays;
   Int_t           m_HF_Classification;
   Int_t           m_HF_ClassificationTop;
   Bool_t          m_in_vy_overlap;
   UInt_t          mcChannelNumber;
   Float_t         met_met;
   Float_t         met_phi;
   Float_t         mu;
   Float_t         mu_actual;
   Int_t           nHiggs;
   Char_t          nJets_OR;
   Char_t          nJets_OR_DL1r_60;
   Char_t          nJets_OR_DL1r_77;
   Char_t          nJets_OR_DL1r_85;
   Int_t           nWZhad;
   Int_t           nZee;
   Int_t           nZmm;
   Bool_t          passPLIVTight_0;
   Bool_t          passPLIVTight_1;
   Bool_t          passPLIVTight_2;
   Bool_t          passPLIVVeryTight_0;
   Bool_t          passPLIVVeryTight_1;
   Bool_t          passPLIVVeryTight_2;
   Char_t          quadlep_type;
   UInt_t          randomRunNumber;
   UInt_t          runNumber;
   Int_t           sumPsbtag;
   Int_t           top_dilep_filter;
   Float_t         totalEventsWeighted;
   Float_t         totalEventsWeighted_weight_EW_LO1;
   Float_t         totalEventsWeighted_weight_EW_LO1LO2LO3;
   Float_t         totalEventsWeighted_weight_EW_exp_LO1;
   Float_t         totalEventsWeighted_weight_EW_exp_LO1LO2LO3;
   Float_t         totalEventsWeighted_weight_EW_mult_LO1;
   Float_t         totalEventsWeighted_weight_EW_mult_LO1LO2LO3;
   Float_t         totalEventsWeighted_weight_FSR0625__1down;
   Float_t         totalEventsWeighted_weight_FSR__1down;
   Float_t         totalEventsWeighted_weight_FSR__1up;
   Float_t         totalEventsWeighted_weight_MUF_ME__1down;
   Float_t         totalEventsWeighted_weight_MUF_ME__1up;
   Float_t         totalEventsWeighted_weight_MUF__1down;
   Float_t         totalEventsWeighted_weight_MUF__1up;
   Float_t         totalEventsWeighted_weight_MUR_ME__1down;
   Float_t         totalEventsWeighted_weight_MUR_ME__1up;
   Float_t         totalEventsWeighted_weight_MUR_MUF_ME__1down;
   Float_t         totalEventsWeighted_weight_MUR_MUF_ME__1up;
   Float_t         totalEventsWeighted_weight_MUR_MUF__1down;
   Float_t         totalEventsWeighted_weight_MUR_MUF__1up;
   Float_t         totalEventsWeighted_weight_MUR__1down;
   Float_t         totalEventsWeighted_weight_MUR__1up;
   Float_t         totalEventsWeighted_weight_PDF13000;
   Float_t         totalEventsWeighted_weight_PDF13100;
   Float_t         totalEventsWeighted_weight_PDF25200;
   Float_t         totalEventsWeighted_weight_PDF25300;
   Float_t         totalEventsWeighted_weight_PDF265000;
   Float_t         totalEventsWeighted_weight_PDF266000;
   Float_t         totalEventsWeighted_weight_PDF269000;
   Float_t         totalEventsWeighted_weight_PDF270000;
   Float_t         totalEventsWeighted_weight_Var3cDown;
   Float_t         totalEventsWeighted_weight_Var3cUp;
   Char_t          total_charge;
   Char_t          total_leptons;
   Float_t         totchi_X1X2;
   Char_t          trilep_type;
   Int_t           ttHMLClass_lep_0;
   Int_t           ttHMLClass_lep_1;
   Int_t           ttHMLClass_lep_2;
   Int_t           ttbarDecayMode;
   Float_t         weight_MUR_MUF__1down;
   Float_t         weight_PDF13100;
   Float_t         weight_PDF25200;
   Float_t         weight_PDF266000;
   Float_t         weight_bTagSF_DL1r_70;
   Float_t         weight_bTagSF_DL1r_Continuous;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1up;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1down;
   Float_t         weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1up;
   Float_t         weight_globalLeptonTriggerSF;
   Float_t         weight_globalLeptonTriggerSF_CWP;
   Float_t         weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         weight_jvt;
   Float_t         weight_jvt__1down;
   Float_t         weight_jvt__1up;
   Float_t         weight_leptonSF;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT;
   Float_t         weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT;
   Float_t         weight_leptonSF_El_ID_TightLH_DOWN_AT;
   Float_t         weight_leptonSF_El_ID_TightLH_UP_AT;
   Float_t         weight_leptonSF_El_Iso_FCLoose_DOWN_AT;
   Float_t         weight_leptonSF_El_Iso_FCLoose_UP_AT;
   Float_t         weight_leptonSF_El_Reco_DOWN_AT;
   Float_t         weight_leptonSF_El_Reco_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_TTVA_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_TTVA_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_TTVA_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_TTVA_SYST_UP_AT;
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_pileup_DOWN;
   Float_t         weight_pileup_UP;
   Float_t         xs;

   // List of branches
   TBranch        *b_Boson1_jetA_pt;   //!
   TBranch        *b_Boson1_mass;   //!
   TBranch        *b_Boson1_pt;   //!
   TBranch        *b_Boson2_jetC_pt;   //!
   TBranch        *b_Boson2_mass;   //!
   TBranch        *b_Boson2_pt;   //!
   TBranch        *b_DRll01;   //!
   TBranch        *b_DRll02;   //!
   TBranch        *b_DRll03;   //!
   TBranch        *b_DRll12;   //!
   TBranch        *b_DRll13;   //!
   TBranch        *b_DRll23;   //!
   TBranch        *b_DeltaR_min_lep_bjet77;   //!
   TBranch        *b_GenFiltHT;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_IFFClass_lep_0;   //!
   TBranch        *b_IFFClass_lep_1;   //!
   TBranch        *b_IFFClass_lep_2;   //!
   TBranch        *b_IFFClass_lep_3;   //!
   TBranch        *b_MTlmet;   //!
   TBranch        *b_Mll01;   //!
   TBranch        *b_Mll02;   //!
   TBranch        *b_Mll03;   //!
   TBranch        *b_Mll12;   //!
   TBranch        *b_Mll13;   //!
   TBranch        *b_Mll23;   //!
   TBranch        *b_Mlll012;   //!
   TBranch        *b_Mlll013;   //!
   TBranch        *b_Mlll023;   //!
   TBranch        *b_Mlll123;   //!
   TBranch        *b_N_IFF_Bdecays;   //!
   TBranch        *b_N_IFF_Cdecays;   //!
   TBranch        *b_N_IFF_EfromMu;   //!
   TBranch        *b_N_IFF_IntConv;   //!
   TBranch        *b_N_IFF_KnownUnknown;   //!
   TBranch        *b_N_IFF_LightHadDecays;   //!
   TBranch        *b_N_IFF_MatConv;   //!
   TBranch        *b_N_IFF_Prompt;   //!
   TBranch        *b_N_IFF_QmisID;   //!
   TBranch        *b_N_IFF_TauDecays;   //!
   TBranch        *b_N_IFF_Unclassified;   //!
   TBranch        *b_RecoRegion;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_VLL1_mass;   //!
   TBranch        *b_VLL2_mass;   //!
   TBranch        *b_VLL_decayHdecays;   //!
   TBranch        *b_VLL_decayWdecays;   //!
   TBranch        *b_VLL_decayZdecays;   //!
   TBranch        *b_VLL_decaytype;   //!
   TBranch        *b_VLL_type;   //!
   TBranch        *b_bTagSF_weight_DL1r_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_70;   //!
   TBranch        *b_bTagSF_weight_DL1r_77;   //!
   TBranch        *b_bTagSF_weight_DL1r_85;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_filterDuplicateEvents;   //!
   TBranch        *b_flag_passMETtrig;   //!
   TBranch        *b_hhiggsDecayMode;   //!
   TBranch        *b_higgsDecayMode;   //!
   TBranch        *b_highpt_trubjet;   //!
   TBranch        *b_initial_state;   //!
   TBranch        *b_jet_eta0;   //!
   TBranch        *b_jet_eta1;   //!
   TBranch        *b_jet_pseudoscore_DL1r0;   //!
   TBranch        *b_jet_pseudoscore_DL1r1;   //!
   TBranch        *b_jet_pseudoscore_DL1r2;   //!
   TBranch        *b_jet_pseudoscore_DL1r3;   //!
   TBranch        *b_jet_pseudoscore_DL1r4;   //!
   TBranch        *b_jet_pt0;   //!
   TBranch        *b_jet_pt1;   //!
   TBranch        *b_jets_ConeTruthLabelID;   //!
   TBranch        *b_jets_HadronConeExclExtendedTruthLabelID;   //!
   TBranch        *b_jets_HadronConeExclTruthLabelID;   //!
   TBranch        *b_jets_PartonTruthLabelID;   //!
   TBranch        *b_jets_btagFlag_DL1r_ContinuousBin;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_60;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_77;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jets_btag_JetVertexCharge_discriminant;   //!
   TBranch        *b_jets_e;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_score_DL1r;   //!
   TBranch        *b_jets_score_DL1r_pb;   //!
   TBranch        *b_jets_score_DL1r_pc;   //!
   TBranch        *b_jets_score_DL1r_pu;   //!
   TBranch        *b_jvtSF_customOR;   //!
   TBranch        *b_lepSFObjChannelCombined;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSF_PLIV_IFF_Prompt_0;   //!
   TBranch        *b_lepSF_PLIV_IFF_Prompt_1;   //!
   TBranch        *b_lepSF_PLIV_IFF_Prompt_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lep_AnpTruthType_0;   //!
   TBranch        *b_lep_AnpTruthType_1;   //!
   TBranch        *b_lep_AnpTruthType_2;   //!
   TBranch        *b_lep_AnpTruthType_3;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_0;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_1;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_2;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_3;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_0;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_1;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_2;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_3;   //!
   TBranch        *b_lep_DFCommonSimpleMee_0;   //!
   TBranch        *b_lep_DFCommonSimpleMee_1;   //!
   TBranch        *b_lep_DFCommonSimpleMee_2;   //!
   TBranch        *b_lep_DFCommonSimpleMee_3;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Index_0;   //!
   TBranch        *b_lep_Index_1;   //!
   TBranch        *b_lep_Index_2;   //!
   TBranch        *b_lep_Index_3;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_0;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_1;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_2;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_3;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_0;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_1;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_2;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_3;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_RadiusCOX_0;   //!
   TBranch        *b_lep_RadiusCOX_1;   //!
   TBranch        *b_lep_RadiusCOX_2;   //!
   TBranch        *b_lep_RadiusCOX_3;   //!
   TBranch        *b_lep_RadiusCOY_0;   //!
   TBranch        *b_lep_RadiusCOY_1;   //!
   TBranch        *b_lep_RadiusCOY_2;   //!
   TBranch        *b_lep_RadiusCOY_3;   //!
   TBranch        *b_lep_RadiusCO_0;   //!
   TBranch        *b_lep_RadiusCO_1;   //!
   TBranch        *b_lep_RadiusCO_2;   //!
   TBranch        *b_lep_RadiusCO_3;   //!
   TBranch        *b_lep_SF_CombinedLoose_0;   //!
   TBranch        *b_lep_SF_CombinedLoose_1;   //!
   TBranch        *b_lep_SF_CombinedLoose_2;   //!
   TBranch        *b_lep_SF_CombinedLoose_3;   //!
   TBranch        *b_lep_SF_CombinedTight_0;   //!
   TBranch        *b_lep_SF_CombinedTight_1;   //!
   TBranch        *b_lep_SF_CombinedTight_2;   //!
   TBranch        *b_lep_SF_CombinedTight_3;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_0;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_1;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_2;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_3;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_0;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_1;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_2;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_3;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_3;   //!
   TBranch        *b_lep_SF_El_LooseAndBLayerLHQMisID_0;   //!
   TBranch        *b_lep_SF_El_LooseAndBLayerLHQMisID_1;   //!
   TBranch        *b_lep_SF_El_LooseAndBLayerLHQMisID_2;   //!
   TBranch        *b_lep_SF_El_LooseAndBLayerLHQMisID_3;   //!
   TBranch        *b_lep_SF_El_MediumFCLooseQMisID_0;   //!
   TBranch        *b_lep_SF_El_MediumFCLooseQMisID_1;   //!
   TBranch        *b_lep_SF_El_MediumFCLooseQMisID_2;   //!
   TBranch        *b_lep_SF_El_MediumFCLooseQMisID_3;   //!
   TBranch        *b_lep_SF_El_MediumFCTightECIDSLooseQMisID_0;   //!
   TBranch        *b_lep_SF_El_MediumFCTightECIDSLooseQMisID_1;   //!
   TBranch        *b_lep_SF_El_MediumFCTightECIDSLooseQMisID_2;   //!
   TBranch        *b_lep_SF_El_MediumFCTightECIDSLooseQMisID_3;   //!
   TBranch        *b_lep_SF_El_MediumGradientQMisID_0;   //!
   TBranch        *b_lep_SF_El_MediumGradientQMisID_1;   //!
   TBranch        *b_lep_SF_El_MediumGradientQMisID_2;   //!
   TBranch        *b_lep_SF_El_MediumGradientQMisID_3;   //!
   TBranch        *b_lep_SF_El_MediumGradienttECIDSLooseQMisID_0;   //!
   TBranch        *b_lep_SF_El_MediumGradienttECIDSLooseQMisID_1;   //!
   TBranch        *b_lep_SF_El_MediumGradienttECIDSLooseQMisID_2;   //!
   TBranch        *b_lep_SF_El_MediumGradienttECIDSLooseQMisID_3;   //!
   TBranch        *b_lep_SF_El_Reco_AT_0;   //!
   TBranch        *b_lep_SF_El_Reco_AT_1;   //!
   TBranch        *b_lep_SF_El_Reco_AT_2;   //!
   TBranch        *b_lep_SF_El_Reco_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_0;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_1;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_2;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_3;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_0;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_1;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_2;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_3;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_0;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_1;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_2;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_3;   //!
   TBranch        *b_lep_SF_VLLem_CombinedFCLoose_0;   //!
   TBranch        *b_lep_SF_VLLem_CombinedFCLoose_1;   //!
   TBranch        *b_lep_SF_VLLem_CombinedFCLoose_2;   //!
   TBranch        *b_lep_SF_VLLem_CombinedFCLoose_3;   //!
   TBranch        *b_lep_SF_VLLem_CombinedPLIV_0;   //!
   TBranch        *b_lep_SF_VLLem_CombinedPLIV_1;   //!
   TBranch        *b_lep_SF_VLLem_CombinedPLIV_2;   //!
   TBranch        *b_lep_SF_VLLem_CombinedPLIV_3;   //!
   TBranch        *b_lep_SeparationMinDCT_0;   //!
   TBranch        *b_lep_SeparationMinDCT_1;   //!
   TBranch        *b_lep_SeparationMinDCT_2;   //!
   TBranch        *b_lep_SeparationMinDCT_3;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_Z0SinTheta_3;   //!
   TBranch        *b_lep_ambiguityType_0;   //!
   TBranch        *b_lep_ambiguityType_1;   //!
   TBranch        *b_lep_ambiguityType_2;   //!
   TBranch        *b_lep_ambiguityType_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_3;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;   //!
   TBranch        *b_lep_d0_0;   //!
   TBranch        *b_lep_d0_1;   //!
   TBranch        *b_lep_d0_2;   //!
   TBranch        *b_lep_d0_3;   //!
   TBranch        *b_lep_deltaz0_0;   //!
   TBranch        *b_lep_deltaz0_1;   //!
   TBranch        *b_lep_deltaz0_2;   //!
   TBranch        *b_lep_deltaz0_3;   //!
   TBranch        *b_lep_firstEgMotherPdgId_0;   //!
   TBranch        *b_lep_firstEgMotherPdgId_1;   //!
   TBranch        *b_lep_firstEgMotherPdgId_2;   //!
   TBranch        *b_lep_firstEgMotherPdgId_3;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_firstEgMotherTruthType_0;   //!
   TBranch        *b_lep_firstEgMotherTruthType_1;   //!
   TBranch        *b_lep_firstEgMotherTruthType_2;   //!
   TBranch        *b_lep_firstEgMotherTruthType_3;   //!
   TBranch        *b_lep_flavour;   //!
   TBranch        *b_lep_isBrems_0;   //!
   TBranch        *b_lep_isBrems_1;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_isBrems_3;   //!
   TBranch        *b_lep_isConvPh_0;   //!
   TBranch        *b_lep_isConvPh_1;   //!
   TBranch        *b_lep_isConvPh_2;   //!
   TBranch        *b_lep_isConvPh_3;   //!
   TBranch        *b_lep_isExtConvPh_0;   //!
   TBranch        *b_lep_isExtConvPh_1;   //!
   TBranch        *b_lep_isExtConvPh_2;   //!
   TBranch        *b_lep_isExtConvPh_3;   //!
   TBranch        *b_lep_isFakeLep_0;   //!
   TBranch        *b_lep_isFakeLep_1;   //!
   TBranch        *b_lep_isFakeLep_2;   //!
   TBranch        *b_lep_isFakeLep_3;   //!
   TBranch        *b_lep_isISR_FSR_Ph_0;   //!
   TBranch        *b_lep_isISR_FSR_Ph_1;   //!
   TBranch        *b_lep_isISR_FSR_Ph_2;   //!
   TBranch        *b_lep_isISR_FSR_Ph_3;   //!
   TBranch        *b_lep_isIntConvPh_0;   //!
   TBranch        *b_lep_isIntConvPh_1;   //!
   TBranch        *b_lep_isIntConvPh_2;   //!
   TBranch        *b_lep_isIntConvPh_3;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isLooseLH_3;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isPrompt_0;   //!
   TBranch        *b_lep_isPrompt_1;   //!
   TBranch        *b_lep_isPrompt_2;   //!
   TBranch        *b_lep_isPrompt_3;   //!
   TBranch        *b_lep_isQMisID_0;   //!
   TBranch        *b_lep_isQMisID_1;   //!
   TBranch        *b_lep_isQMisID_2;   //!
   TBranch        *b_lep_isQMisID_3;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isTrigMatchDLT_0;   //!
   TBranch        *b_lep_isTrigMatchDLT_1;   //!
   TBranch        *b_lep_isTrigMatchDLT_2;   //!
   TBranch        *b_lep_isTrigMatchDLT_3;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_isTruthMatched_3;   //!
   TBranch        *b_lep_isolationPLImprovedTight_0;   //!
   TBranch        *b_lep_isolationPLImprovedTight_1;   //!
   TBranch        *b_lep_isolationPLImprovedTight_2;   //!
   TBranch        *b_lep_isolationPLImprovedTight_3;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_0;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_1;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_2;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_3;   //!
   TBranch        *b_lep_lastEgMotherPdgId_0;   //!
   TBranch        *b_lep_lastEgMotherPdgId_1;   //!
   TBranch        *b_lep_lastEgMotherPdgId_2;   //!
   TBranch        *b_lep_lastEgMotherPdgId_3;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_lastEgMotherTruthType_0;   //!
   TBranch        *b_lep_lastEgMotherTruthType_1;   //!
   TBranch        *b_lep_lastEgMotherTruthType_2;   //!
   TBranch        *b_lep_lastEgMotherTruthType_3;   //!
   TBranch        *b_lep_nInnerPix_0;   //!
   TBranch        *b_lep_nInnerPix_1;   //!
   TBranch        *b_lep_nInnerPix_2;   //!
   TBranch        *b_lep_nInnerPix_3;   //!
   TBranch        *b_lep_nTrackParticles_0;   //!
   TBranch        *b_lep_nTrackParticles_1;   //!
   TBranch        *b_lep_nTrackParticles_2;   //!
   TBranch        *b_lep_nTrackParticles_3;   //!
   TBranch        *b_lep_plvWP_Loose_0;   //!
   TBranch        *b_lep_plvWP_Loose_1;   //!
   TBranch        *b_lep_plvWP_Loose_2;   //!
   TBranch        *b_lep_plvWP_Loose_3;   //!
   TBranch        *b_lep_plvWP_Tight_0;   //!
   TBranch        *b_lep_plvWP_Tight_1;   //!
   TBranch        *b_lep_plvWP_Tight_2;   //!
   TBranch        *b_lep_plvWP_Tight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_3;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_sigd0PV_3;   //!
   TBranch        *b_lep_truthE_0;   //!
   TBranch        *b_lep_truthE_1;   //!
   TBranch        *b_lep_truthE_2;   //!
   TBranch        *b_lep_truthE_3;   //!
   TBranch        *b_lep_truthEta_0;   //!
   TBranch        *b_lep_truthEta_1;   //!
   TBranch        *b_lep_truthEta_2;   //!
   TBranch        *b_lep_truthEta_3;   //!
   TBranch        *b_lep_truthHasTopInChain_0;   //!
   TBranch        *b_lep_truthHasTopInChain_1;   //!
   TBranch        *b_lep_truthHasTopInChain_2;   //!
   TBranch        *b_lep_truthHasTopInChain_3;   //!
   TBranch        *b_lep_truthM_0;   //!
   TBranch        *b_lep_truthM_1;   //!
   TBranch        *b_lep_truthM_2;   //!
   TBranch        *b_lep_truthM_3;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthOrigin_3;   //!
   TBranch        *b_lep_truthParentBarcode_0;   //!
   TBranch        *b_lep_truthParentBarcode_1;   //!
   TBranch        *b_lep_truthParentBarcode_2;   //!
   TBranch        *b_lep_truthParentBarcode_3;   //!
   TBranch        *b_lep_truthParentEta_0;   //!
   TBranch        *b_lep_truthParentEta_1;   //!
   TBranch        *b_lep_truthParentEta_2;   //!
   TBranch        *b_lep_truthParentEta_3;   //!
   TBranch        *b_lep_truthParentIsBHadron_0;   //!
   TBranch        *b_lep_truthParentIsBHadron_1;   //!
   TBranch        *b_lep_truthParentIsBHadron_2;   //!
   TBranch        *b_lep_truthParentIsBHadron_3;   //!
   TBranch        *b_lep_truthParentIsCHadron_0;   //!
   TBranch        *b_lep_truthParentIsCHadron_1;   //!
   TBranch        *b_lep_truthParentIsCHadron_2;   //!
   TBranch        *b_lep_truthParentIsCHadron_3;   //!
   TBranch        *b_lep_truthParentOrigin_0;   //!
   TBranch        *b_lep_truthParentOrigin_1;   //!
   TBranch        *b_lep_truthParentOrigin_2;   //!
   TBranch        *b_lep_truthParentOrigin_3;   //!
   TBranch        *b_lep_truthParentPdgId_0;   //!
   TBranch        *b_lep_truthParentPdgId_1;   //!
   TBranch        *b_lep_truthParentPdgId_2;   //!
   TBranch        *b_lep_truthParentPdgId_3;   //!
   TBranch        *b_lep_truthParentPt_0;   //!
   TBranch        *b_lep_truthParentPt_1;   //!
   TBranch        *b_lep_truthParentPt_2;   //!
   TBranch        *b_lep_truthParentPt_3;   //!
   TBranch        *b_lep_truthParentRealPdgId_0;   //!
   TBranch        *b_lep_truthParentRealPdgId_1;   //!
   TBranch        *b_lep_truthParentRealPdgId_2;   //!
   TBranch        *b_lep_truthParentRealPdgId_3;   //!
   TBranch        *b_lep_truthParentStatus_0;   //!
   TBranch        *b_lep_truthParentStatus_1;   //!
   TBranch        *b_lep_truthParentStatus_2;   //!
   TBranch        *b_lep_truthParentStatus_3;   //!
   TBranch        *b_lep_truthParentType_0;   //!
   TBranch        *b_lep_truthParentType_1;   //!
   TBranch        *b_lep_truthParentType_2;   //!
   TBranch        *b_lep_truthParentType_3;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_truthPdgId_3;   //!
   TBranch        *b_lep_truthPhi_0;   //!
   TBranch        *b_lep_truthPhi_1;   //!
   TBranch        *b_lep_truthPhi_2;   //!
   TBranch        *b_lep_truthPhi_3;   //!
   TBranch        *b_lep_truthPt_0;   //!
   TBranch        *b_lep_truthPt_1;   //!
   TBranch        *b_lep_truthPt_2;   //!
   TBranch        *b_lep_truthPt_3;   //!
   TBranch        *b_lep_truthRapidity_0;   //!
   TBranch        *b_lep_truthRapidity_1;   //!
   TBranch        *b_lep_truthRapidity_2;   //!
   TBranch        *b_lep_truthRapidity_3;   //!
   TBranch        *b_lep_truthStatus_0;   //!
   TBranch        *b_lep_truthStatus_1;   //!
   TBranch        *b_lep_truthStatus_2;   //!
   TBranch        *b_lep_truthStatus_3;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthType_3;   //!
   TBranch        *b_lep_vz_0;   //!
   TBranch        *b_lep_vz_1;   //!
   TBranch        *b_lep_vz_2;   //!
   TBranch        *b_lep_vz_3;   //!
   TBranch        *b_lep_z0_0;   //!
   TBranch        *b_lep_z0_1;   //!
   TBranch        *b_lep_z0_2;   //!
   TBranch        *b_lep_z0_3;   //!
   TBranch        *b_lqlq_decays;   //!
   TBranch        *b_m_HF_Classification;   //!
   TBranch        *b_m_HF_ClassificationTop;   //!
   TBranch        *b_m_in_vy_overlap;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_mu_actual;   //!
   TBranch        *b_nHiggs;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nJets_OR_DL1r_60;   //!
   TBranch        *b_nJets_OR_DL1r_77;   //!
   TBranch        *b_nJets_OR_DL1r_85;   //!
   TBranch        *b_nWZhad;   //!
   TBranch        *b_nZee;   //!
   TBranch        *b_nZmm;   //!
   TBranch        *b_passPLIVTight_0;   //!
   TBranch        *b_passPLIVTight_1;   //!
   TBranch        *b_passPLIVTight_2;   //!
   TBranch        *b_passPLIVVeryTight_0;   //!
   TBranch        *b_passPLIVVeryTight_1;   //!
   TBranch        *b_passPLIVVeryTight_2;   //!
   TBranch        *b_quadlep_type;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_sumPsbtag;   //!
   TBranch        *b_top_dilep_filter;   //!
   TBranch        *b_totalEventsWeighted;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_LO1;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_LO1LO2LO3;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_exp_LO1;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_exp_LO1LO2LO3;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_mult_LO1;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_mult_LO1LO2LO3;   //!
   TBranch        *b_totalEventsWeighted_weight_FSR0625__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_FSR__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_FSR__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF_ME__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF_ME__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_ME__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_ME__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF_ME__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF_ME__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF13000;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF13100;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF25200;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF25300;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF265000;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF266000;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF269000;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF270000;   //!
   TBranch        *b_totalEventsWeighted_weight_Var3cDown;   //!
   TBranch        *b_totalEventsWeighted_weight_Var3cUp;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_totchi_X1X2;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_ttHMLClass_lep_0;   //!
   TBranch        *b_ttHMLClass_lep_1;   //!
   TBranch        *b_ttHMLClass_lep_2;   //!
   TBranch        *b_ttbarDecayMode;   //!
   TBranch        *b_weight_MUR_MUF__1down;   //!
   TBranch        *b_weight_PDF13100;   //!
   TBranch        *b_weight_PDF25200;   //!
   TBranch        *b_weight_PDF266000;   //!
   TBranch        *b_weight_bTagSF_DL1r_70;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1up;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1down;   //!
   TBranch        *b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_weight_jvt__1down;   //!
   TBranch        *b_weight_jvt__1up;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_TightLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_TightLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_Iso_FCLoose_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_Iso_FCLoose_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_Reco_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_Reco_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_SYST_UP_AT;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_pileup_DOWN;   //!
   TBranch        *b_weight_pileup_UP;   //!
   TBranch        *b_xs;   //!

   VLLf(char *file_name, TChain *tree=0);
   virtual ~VLLf();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);

};

#endif

#ifdef VLLf_cxx
VLLf::VLLf(char *file_name, TChain *tree) : fChain(0)
{
 TChain* chain;
  if (tree == 0) {
     chain = new TChain("nominal");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }

}

VLLf::~VLLf()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLf::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLf::LoadTree(Long64_t entry)
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

void VLLf::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jets_ConeTruthLabelID = 0;
   jets_HadronConeExclExtendedTruthLabelID = 0;
   jets_HadronConeExclTruthLabelID = 0;
   jets_PartonTruthLabelID = 0;
   jets_btagFlag_DL1r_ContinuousBin = 0;
   jets_btagFlag_DL1r_FixedCutBEff_60 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_70 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_77 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_85 = 0;
   jets_btag_JetVertexCharge_discriminant = 0;
   jets_e = 0;
   jets_eta = 0;
   jets_phi = 0;
   jets_pt = 0;
   jets_score_DL1r = 0;
   jets_score_DL1r_pb = 0;
   jets_score_DL1r_pc = 0;
   jets_score_DL1r_pu = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Boson1_jetA_pt", &Boson1_jetA_pt, &b_Boson1_jetA_pt);
   fChain->SetBranchAddress("Boson1_mass", &Boson1_mass, &b_Boson1_mass);
   fChain->SetBranchAddress("Boson1_pt", &Boson1_pt, &b_Boson1_pt);
   fChain->SetBranchAddress("Boson2_jetC_pt", &Boson2_jetC_pt, &b_Boson2_jetC_pt);
   fChain->SetBranchAddress("Boson2_mass", &Boson2_mass, &b_Boson2_mass);
   fChain->SetBranchAddress("Boson2_pt", &Boson2_pt, &b_Boson2_pt);
   fChain->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   fChain->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   fChain->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   fChain->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   fChain->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   fChain->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   fChain->SetBranchAddress("DeltaR_min_lep_bjet77", &DeltaR_min_lep_bjet77, &b_DeltaR_min_lep_bjet77);
   fChain->SetBranchAddress("GenFiltHT", &GenFiltHT, &b_GenFiltHT);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   fChain->SetBranchAddress("IFFClass_lep_0", &IFFClass_lep_0, &b_IFFClass_lep_0);
   fChain->SetBranchAddress("IFFClass_lep_1", &IFFClass_lep_1, &b_IFFClass_lep_1);
   fChain->SetBranchAddress("IFFClass_lep_2", &IFFClass_lep_2, &b_IFFClass_lep_2);
   fChain->SetBranchAddress("IFFClass_lep_3", &IFFClass_lep_3, &b_IFFClass_lep_3);
   fChain->SetBranchAddress("MTlmet", &MTlmet, &b_MTlmet);
   fChain->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   fChain->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   fChain->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   fChain->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   fChain->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   fChain->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   fChain->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   fChain->SetBranchAddress("Mlll013", &Mlll013, &b_Mlll013);
   fChain->SetBranchAddress("Mlll023", &Mlll023, &b_Mlll023);
   fChain->SetBranchAddress("Mlll123", &Mlll123, &b_Mlll123);
   fChain->SetBranchAddress("N_IFF_Bdecays", &N_IFF_Bdecays, &b_N_IFF_Bdecays);
   fChain->SetBranchAddress("N_IFF_Cdecays", &N_IFF_Cdecays, &b_N_IFF_Cdecays);
   fChain->SetBranchAddress("N_IFF_EfromMu", &N_IFF_EfromMu, &b_N_IFF_EfromMu);
   fChain->SetBranchAddress("N_IFF_IntConv", &N_IFF_IntConv, &b_N_IFF_IntConv);
   fChain->SetBranchAddress("N_IFF_KnownUnknown", &N_IFF_KnownUnknown, &b_N_IFF_KnownUnknown);
   fChain->SetBranchAddress("N_IFF_LightHadDecays", &N_IFF_LightHadDecays, &b_N_IFF_LightHadDecays);
   fChain->SetBranchAddress("N_IFF_MatConv", &N_IFF_MatConv, &b_N_IFF_MatConv);
   fChain->SetBranchAddress("N_IFF_Prompt", &N_IFF_Prompt, &b_N_IFF_Prompt);
   fChain->SetBranchAddress("N_IFF_QmisID", &N_IFF_QmisID, &b_N_IFF_QmisID);
   fChain->SetBranchAddress("N_IFF_TauDecays", &N_IFF_TauDecays, &b_N_IFF_TauDecays);
   fChain->SetBranchAddress("N_IFF_Unclassified", &N_IFF_Unclassified, &b_N_IFF_Unclassified);
   fChain->SetBranchAddress("RecoRegion", &RecoRegion, &b_RecoRegion);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("VLL1_mass", &VLL1_mass, &b_VLL1_mass);
   fChain->SetBranchAddress("VLL2_mass", &VLL2_mass, &b_VLL2_mass);
   fChain->SetBranchAddress("VLL_decayHdecays", &VLL_decayHdecays, &b_VLL_decayHdecays);
   fChain->SetBranchAddress("VLL_decayWdecays", &VLL_decayWdecays, &b_VLL_decayWdecays);
   fChain->SetBranchAddress("VLL_decayZdecays", &VLL_decayZdecays, &b_VLL_decayZdecays);
   fChain->SetBranchAddress("VLL_decaytype", &VLL_decaytype, &b_VLL_decaytype);
   fChain->SetBranchAddress("VLL_type", &VLL_type, &b_VLL_type);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_60", &bTagSF_weight_DL1r_60, &b_bTagSF_weight_DL1r_60);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_70", &bTagSF_weight_DL1r_70, &b_bTagSF_weight_DL1r_70);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_77", &bTagSF_weight_DL1r_77, &b_bTagSF_weight_DL1r_77);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_85", &bTagSF_weight_DL1r_85, &b_bTagSF_weight_DL1r_85);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_Continuous", &bTagSF_weight_DL1r_Continuous, &b_bTagSF_weight_DL1r_Continuous);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_SLTorDLT", &custTrigMatch_LooseID_FCLooseIso_SLTorDLT, &b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_SLTorDLT", &custTrigSF_LooseID_FCLooseIso_SLTorDLT, &b_custTrigSF_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("filterDuplicateEvents", &filterDuplicateEvents, &b_filterDuplicateEvents);
   fChain->SetBranchAddress("flag_passMETtrig", &flag_passMETtrig, &b_flag_passMETtrig);
   fChain->SetBranchAddress("hhiggsDecayMode", &hhiggsDecayMode, &b_hhiggsDecayMode);
   fChain->SetBranchAddress("higgsDecayMode", &higgsDecayMode, &b_higgsDecayMode);
   fChain->SetBranchAddress("highpt_trubjet", &highpt_trubjet, &b_highpt_trubjet);
   fChain->SetBranchAddress("initial_state", &initial_state, &b_initial_state);
   fChain->SetBranchAddress("jet_eta0", &jet_eta0, &b_jet_eta0);
   fChain->SetBranchAddress("jet_eta1", &jet_eta1, &b_jet_eta1);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r0", &jet_pseudoscore_DL1r0, &b_jet_pseudoscore_DL1r0);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r1", &jet_pseudoscore_DL1r1, &b_jet_pseudoscore_DL1r1);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r2", &jet_pseudoscore_DL1r2, &b_jet_pseudoscore_DL1r2);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r3", &jet_pseudoscore_DL1r3, &b_jet_pseudoscore_DL1r3);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r4", &jet_pseudoscore_DL1r4, &b_jet_pseudoscore_DL1r4);
   fChain->SetBranchAddress("jet_pt0", &jet_pt0, &b_jet_pt0);
   fChain->SetBranchAddress("jet_pt1", &jet_pt1, &b_jet_pt1);
   fChain->SetBranchAddress("jets_ConeTruthLabelID", &jets_ConeTruthLabelID, &b_jets_ConeTruthLabelID);
   fChain->SetBranchAddress("jets_HadronConeExclExtendedTruthLabelID", &jets_HadronConeExclExtendedTruthLabelID, &b_jets_HadronConeExclExtendedTruthLabelID);
   fChain->SetBranchAddress("jets_HadronConeExclTruthLabelID", &jets_HadronConeExclTruthLabelID, &b_jets_HadronConeExclTruthLabelID);
   fChain->SetBranchAddress("jets_PartonTruthLabelID", &jets_PartonTruthLabelID, &b_jets_PartonTruthLabelID);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_ContinuousBin", &jets_btagFlag_DL1r_ContinuousBin, &b_jets_btagFlag_DL1r_ContinuousBin);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_60", &jets_btagFlag_DL1r_FixedCutBEff_60, &b_jets_btagFlag_DL1r_FixedCutBEff_60);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_70", &jets_btagFlag_DL1r_FixedCutBEff_70, &b_jets_btagFlag_DL1r_FixedCutBEff_70);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_77", &jets_btagFlag_DL1r_FixedCutBEff_77, &b_jets_btagFlag_DL1r_FixedCutBEff_77);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_85", &jets_btagFlag_DL1r_FixedCutBEff_85, &b_jets_btagFlag_DL1r_FixedCutBEff_85);
   fChain->SetBranchAddress("jets_btag_JetVertexCharge_discriminant", &jets_btag_JetVertexCharge_discriminant, &b_jets_btag_JetVertexCharge_discriminant);
   fChain->SetBranchAddress("jets_e", &jets_e, &b_jets_e);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_score_DL1r", &jets_score_DL1r, &b_jets_score_DL1r);
   fChain->SetBranchAddress("jets_score_DL1r_pb", &jets_score_DL1r_pb, &b_jets_score_DL1r_pb);
   fChain->SetBranchAddress("jets_score_DL1r_pc", &jets_score_DL1r_pc, &b_jets_score_DL1r_pc);
   fChain->SetBranchAddress("jets_score_DL1r_pu", &jets_score_DL1r_pu, &b_jets_score_DL1r_pu);
   fChain->SetBranchAddress("jvtSF_customOR", &jvtSF_customOR, &b_jvtSF_customOR);
   fChain->SetBranchAddress("lepSFObjChannelCombined", &lepSFObjChannelCombined, &b_lepSFObjChannelCombined);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("lepSF_PLIV_IFF_Prompt_0", &lepSF_PLIV_IFF_Prompt_0, &b_lepSF_PLIV_IFF_Prompt_0);
   fChain->SetBranchAddress("lepSF_PLIV_IFF_Prompt_1", &lepSF_PLIV_IFF_Prompt_1, &b_lepSF_PLIV_IFF_Prompt_1);
   fChain->SetBranchAddress("lepSF_PLIV_IFF_Prompt_2", &lepSF_PLIV_IFF_Prompt_2, &b_lepSF_PLIV_IFF_Prompt_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_0", &lepSF_PLIV_Prompt_0, &b_lepSF_PLIV_Prompt_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_1", &lepSF_PLIV_Prompt_1, &b_lepSF_PLIV_Prompt_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_2", &lepSF_PLIV_Prompt_2, &b_lepSF_PLIV_Prompt_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_statError_0", &lepSF_PLIV_Prompt_IFF_Tight_El_statError_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_statError_1", &lepSF_PLIV_Prompt_IFF_Tight_El_statError_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_statError_2", &lepSF_PLIV_Prompt_IFF_Tight_El_statError_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalError_0", &lepSF_PLIV_Prompt_IFF_Tight_El_totalError_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalError_1", &lepSF_PLIV_Prompt_IFF_Tight_El_totalError_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalError_2", &lepSF_PLIV_Prompt_IFF_Tight_El_totalError_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_0", &lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_1", &lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_2", &lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_IFF_Tight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_IFF_Tight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_0", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_1", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_2", &lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_IFF_VeryTight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_0", &lepSF_PLIV_Prompt_Tight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_1", &lepSF_PLIV_Prompt_Tight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_2", &lepSF_PLIV_Prompt_Tight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_0", &lepSF_PLIV_Prompt_Tight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_1", &lepSF_PLIV_Prompt_Tight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_2", &lepSF_PLIV_Prompt_Tight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_0", &lepSF_PLIV_Prompt_Tight_El_muSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_1", &lepSF_PLIV_Prompt_Tight_El_muSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_2", &lepSF_PLIV_Prompt_Tight_El_muSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_0", &lepSF_PLIV_Prompt_Tight_El_statError_0, &b_lepSF_PLIV_Prompt_Tight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_1", &lepSF_PLIV_Prompt_Tight_El_statError_1, &b_lepSF_PLIV_Prompt_Tight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_2", &lepSF_PLIV_Prompt_Tight_El_statError_2, &b_lepSF_PLIV_Prompt_Tight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_0", &lepSF_PLIV_Prompt_Tight_El_totalError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_1", &lepSF_PLIV_Prompt_Tight_El_totalError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_2", &lepSF_PLIV_Prompt_Tight_El_totalError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_0", &lepSF_PLIV_Prompt_Tight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_1", &lepSF_PLIV_Prompt_Tight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_2", &lepSF_PLIV_Prompt_Tight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_0", &lepSF_PLIV_Prompt_VeryTight_El_statError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_1", &lepSF_PLIV_Prompt_VeryTight_El_statError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_2", &lepSF_PLIV_Prompt_VeryTight_El_statError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lep_AnpTruthType_0", &lep_AnpTruthType_0, &b_lep_AnpTruthType_0);
   fChain->SetBranchAddress("lep_AnpTruthType_1", &lep_AnpTruthType_1, &b_lep_AnpTruthType_1);
   fChain->SetBranchAddress("lep_AnpTruthType_2", &lep_AnpTruthType_2, &b_lep_AnpTruthType_2);
   fChain->SetBranchAddress("lep_AnpTruthType_3", &lep_AnpTruthType_3, &b_lep_AnpTruthType_3);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_0", &lep_DFCommonAddAmbiguity_0, &b_lep_DFCommonAddAmbiguity_0);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_1", &lep_DFCommonAddAmbiguity_1, &b_lep_DFCommonAddAmbiguity_1);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_2", &lep_DFCommonAddAmbiguity_2, &b_lep_DFCommonAddAmbiguity_2);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_3", &lep_DFCommonAddAmbiguity_3, &b_lep_DFCommonAddAmbiguity_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_0", &lep_DFCommonSimpleConvPhi_0, &b_lep_DFCommonSimpleConvPhi_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_1", &lep_DFCommonSimpleConvPhi_1, &b_lep_DFCommonSimpleConvPhi_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_2", &lep_DFCommonSimpleConvPhi_2, &b_lep_DFCommonSimpleConvPhi_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_3", &lep_DFCommonSimpleConvPhi_3, &b_lep_DFCommonSimpleConvPhi_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_0", &lep_DFCommonSimpleConvRadius_0, &b_lep_DFCommonSimpleConvRadius_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_1", &lep_DFCommonSimpleConvRadius_1, &b_lep_DFCommonSimpleConvRadius_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_2", &lep_DFCommonSimpleConvRadius_2, &b_lep_DFCommonSimpleConvRadius_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_3", &lep_DFCommonSimpleConvRadius_3, &b_lep_DFCommonSimpleConvRadius_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_0", &lep_DFCommonSimpleMeeAtVtx_0, &b_lep_DFCommonSimpleMeeAtVtx_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_1", &lep_DFCommonSimpleMeeAtVtx_1, &b_lep_DFCommonSimpleMeeAtVtx_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_2", &lep_DFCommonSimpleMeeAtVtx_2, &b_lep_DFCommonSimpleMeeAtVtx_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_3", &lep_DFCommonSimpleMeeAtVtx_3, &b_lep_DFCommonSimpleMeeAtVtx_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_0", &lep_DFCommonSimpleMee_0, &b_lep_DFCommonSimpleMee_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_1", &lep_DFCommonSimpleMee_1, &b_lep_DFCommonSimpleMee_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_2", &lep_DFCommonSimpleMee_2, &b_lep_DFCommonSimpleMee_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_3", &lep_DFCommonSimpleMee_3, &b_lep_DFCommonSimpleMee_3);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   fChain->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   fChain->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   fChain->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Index_0", &lep_Index_0, &b_lep_Index_0);
   fChain->SetBranchAddress("lep_Index_1", &lep_Index_1, &b_lep_Index_1);
   fChain->SetBranchAddress("lep_Index_2", &lep_Index_2, &b_lep_Index_2);
   fChain->SetBranchAddress("lep_Index_3", &lep_Index_3, &b_lep_Index_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_0", &lep_Mtrktrk_atConvV_CO_0, &b_lep_Mtrktrk_atConvV_CO_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_1", &lep_Mtrktrk_atConvV_CO_1, &b_lep_Mtrktrk_atConvV_CO_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_2", &lep_Mtrktrk_atConvV_CO_2, &b_lep_Mtrktrk_atConvV_CO_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_3", &lep_Mtrktrk_atConvV_CO_3, &b_lep_Mtrktrk_atConvV_CO_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_0", &lep_Mtrktrk_atPV_CO_0, &b_lep_Mtrktrk_atPV_CO_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_1", &lep_Mtrktrk_atPV_CO_1, &b_lep_Mtrktrk_atPV_CO_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_2", &lep_Mtrktrk_atPV_CO_2, &b_lep_Mtrktrk_atPV_CO_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_3", &lep_Mtrktrk_atPV_CO_3, &b_lep_Mtrktrk_atPV_CO_3);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_RadiusCOX_0", &lep_RadiusCOX_0, &b_lep_RadiusCOX_0);
   fChain->SetBranchAddress("lep_RadiusCOX_1", &lep_RadiusCOX_1, &b_lep_RadiusCOX_1);
   fChain->SetBranchAddress("lep_RadiusCOX_2", &lep_RadiusCOX_2, &b_lep_RadiusCOX_2);
   fChain->SetBranchAddress("lep_RadiusCOX_3", &lep_RadiusCOX_3, &b_lep_RadiusCOX_3);
   fChain->SetBranchAddress("lep_RadiusCOY_0", &lep_RadiusCOY_0, &b_lep_RadiusCOY_0);
   fChain->SetBranchAddress("lep_RadiusCOY_1", &lep_RadiusCOY_1, &b_lep_RadiusCOY_1);
   fChain->SetBranchAddress("lep_RadiusCOY_2", &lep_RadiusCOY_2, &b_lep_RadiusCOY_2);
   fChain->SetBranchAddress("lep_RadiusCOY_3", &lep_RadiusCOY_3, &b_lep_RadiusCOY_3);
   fChain->SetBranchAddress("lep_RadiusCO_0", &lep_RadiusCO_0, &b_lep_RadiusCO_0);
   fChain->SetBranchAddress("lep_RadiusCO_1", &lep_RadiusCO_1, &b_lep_RadiusCO_1);
   fChain->SetBranchAddress("lep_RadiusCO_2", &lep_RadiusCO_2, &b_lep_RadiusCO_2);
   fChain->SetBranchAddress("lep_RadiusCO_3", &lep_RadiusCO_3, &b_lep_RadiusCO_3);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_0", &lep_SF_CombinedLoose_0, &b_lep_SF_CombinedLoose_0);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_1", &lep_SF_CombinedLoose_1, &b_lep_SF_CombinedLoose_1);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_2", &lep_SF_CombinedLoose_2, &b_lep_SF_CombinedLoose_2);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_3", &lep_SF_CombinedLoose_3, &b_lep_SF_CombinedLoose_3);
   fChain->SetBranchAddress("lep_SF_CombinedTight_0", &lep_SF_CombinedTight_0, &b_lep_SF_CombinedTight_0);
   fChain->SetBranchAddress("lep_SF_CombinedTight_1", &lep_SF_CombinedTight_1, &b_lep_SF_CombinedTight_1);
   fChain->SetBranchAddress("lep_SF_CombinedTight_2", &lep_SF_CombinedTight_2, &b_lep_SF_CombinedTight_2);
   fChain->SetBranchAddress("lep_SF_CombinedTight_3", &lep_SF_CombinedTight_3, &b_lep_SF_CombinedTight_3);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_0", &lep_SF_El_FCLooseTightLHQMisID_0, &b_lep_SF_El_FCLooseTightLHQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_1", &lep_SF_El_FCLooseTightLHQMisID_1, &b_lep_SF_El_FCLooseTightLHQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_2", &lep_SF_El_FCLooseTightLHQMisID_2, &b_lep_SF_El_FCLooseTightLHQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_3", &lep_SF_El_FCLooseTightLHQMisID_3, &b_lep_SF_El_FCLooseTightLHQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_0", &lep_SF_El_ID_LooseAndBLayerLH_AT_0, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_1", &lep_SF_El_ID_LooseAndBLayerLH_AT_1, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_2", &lep_SF_El_ID_LooseAndBLayerLH_AT_2, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_3", &lep_SF_El_ID_LooseAndBLayerLH_AT_3, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_0", &lep_SF_El_ID_MediumLH_0, &b_lep_SF_El_ID_MediumLH_0);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_1", &lep_SF_El_ID_MediumLH_1, &b_lep_SF_El_ID_MediumLH_1);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_2", &lep_SF_El_ID_MediumLH_2, &b_lep_SF_El_ID_MediumLH_2);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_3", &lep_SF_El_ID_MediumLH_3, &b_lep_SF_El_ID_MediumLH_3);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_0", &lep_SF_El_ID_TightLH_AT_0, &b_lep_SF_El_ID_TightLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_1", &lep_SF_El_ID_TightLH_AT_1, &b_lep_SF_El_ID_TightLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_2", &lep_SF_El_ID_TightLH_AT_2, &b_lep_SF_El_ID_TightLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_3", &lep_SF_El_ID_TightLH_AT_3, &b_lep_SF_El_ID_TightLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_0", &lep_SF_El_Iso_FCLoose_AT_0, &b_lep_SF_El_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_1", &lep_SF_El_Iso_FCLoose_AT_1, &b_lep_SF_El_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_2", &lep_SF_El_Iso_FCLoose_AT_2, &b_lep_SF_El_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_3", &lep_SF_El_Iso_FCLoose_AT_3, &b_lep_SF_El_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_0", &lep_SF_El_Iso_FCLoose_TightLH_0, &b_lep_SF_El_Iso_FCLoose_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_1", &lep_SF_El_Iso_FCLoose_TightLH_1, &b_lep_SF_El_Iso_FCLoose_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_2", &lep_SF_El_Iso_FCLoose_TightLH_2, &b_lep_SF_El_Iso_FCLoose_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_3", &lep_SF_El_Iso_FCLoose_TightLH_3, &b_lep_SF_El_Iso_FCLoose_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_LooseAndBLayerLHQMisID_0", &lep_SF_El_LooseAndBLayerLHQMisID_0, &b_lep_SF_El_LooseAndBLayerLHQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_LooseAndBLayerLHQMisID_1", &lep_SF_El_LooseAndBLayerLHQMisID_1, &b_lep_SF_El_LooseAndBLayerLHQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_LooseAndBLayerLHQMisID_2", &lep_SF_El_LooseAndBLayerLHQMisID_2, &b_lep_SF_El_LooseAndBLayerLHQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_LooseAndBLayerLHQMisID_3", &lep_SF_El_LooseAndBLayerLHQMisID_3, &b_lep_SF_El_LooseAndBLayerLHQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_MediumFCLooseQMisID_0", &lep_SF_El_MediumFCLooseQMisID_0, &b_lep_SF_El_MediumFCLooseQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_MediumFCLooseQMisID_1", &lep_SF_El_MediumFCLooseQMisID_1, &b_lep_SF_El_MediumFCLooseQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_MediumFCLooseQMisID_2", &lep_SF_El_MediumFCLooseQMisID_2, &b_lep_SF_El_MediumFCLooseQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_MediumFCLooseQMisID_3", &lep_SF_El_MediumFCLooseQMisID_3, &b_lep_SF_El_MediumFCLooseQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_MediumFCTightECIDSLooseQMisID_0", &lep_SF_El_MediumFCTightECIDSLooseQMisID_0, &b_lep_SF_El_MediumFCTightECIDSLooseQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_MediumFCTightECIDSLooseQMisID_1", &lep_SF_El_MediumFCTightECIDSLooseQMisID_1, &b_lep_SF_El_MediumFCTightECIDSLooseQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_MediumFCTightECIDSLooseQMisID_2", &lep_SF_El_MediumFCTightECIDSLooseQMisID_2, &b_lep_SF_El_MediumFCTightECIDSLooseQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_MediumFCTightECIDSLooseQMisID_3", &lep_SF_El_MediumFCTightECIDSLooseQMisID_3, &b_lep_SF_El_MediumFCTightECIDSLooseQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_MediumGradientQMisID_0", &lep_SF_El_MediumGradientQMisID_0, &b_lep_SF_El_MediumGradientQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_MediumGradientQMisID_1", &lep_SF_El_MediumGradientQMisID_1, &b_lep_SF_El_MediumGradientQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_MediumGradientQMisID_2", &lep_SF_El_MediumGradientQMisID_2, &b_lep_SF_El_MediumGradientQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_MediumGradientQMisID_3", &lep_SF_El_MediumGradientQMisID_3, &b_lep_SF_El_MediumGradientQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_MediumGradienttECIDSLooseQMisID_0", &lep_SF_El_MediumGradienttECIDSLooseQMisID_0, &b_lep_SF_El_MediumGradienttECIDSLooseQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_MediumGradienttECIDSLooseQMisID_1", &lep_SF_El_MediumGradienttECIDSLooseQMisID_1, &b_lep_SF_El_MediumGradienttECIDSLooseQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_MediumGradienttECIDSLooseQMisID_2", &lep_SF_El_MediumGradienttECIDSLooseQMisID_2, &b_lep_SF_El_MediumGradienttECIDSLooseQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_MediumGradienttECIDSLooseQMisID_3", &lep_SF_El_MediumGradienttECIDSLooseQMisID_3, &b_lep_SF_El_MediumGradienttECIDSLooseQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_0", &lep_SF_El_Reco_AT_0, &b_lep_SF_El_Reco_AT_0);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_1", &lep_SF_El_Reco_AT_1, &b_lep_SF_El_Reco_AT_1);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_2", &lep_SF_El_Reco_AT_2, &b_lep_SF_El_Reco_AT_2);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_3", &lep_SF_El_Reco_AT_3, &b_lep_SF_El_Reco_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_0", &lep_SF_Mu_ID_Medium_AT_0, &b_lep_SF_Mu_ID_Medium_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_1", &lep_SF_Mu_ID_Medium_AT_1, &b_lep_SF_Mu_ID_Medium_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_2", &lep_SF_Mu_ID_Medium_AT_2, &b_lep_SF_Mu_ID_Medium_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_3", &lep_SF_Mu_ID_Medium_AT_3, &b_lep_SF_Mu_ID_Medium_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_0", &lep_SF_Mu_Iso_FCLoose_AT_0, &b_lep_SF_Mu_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_1", &lep_SF_Mu_Iso_FCLoose_AT_1, &b_lep_SF_Mu_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_2", &lep_SF_Mu_Iso_FCLoose_AT_2, &b_lep_SF_Mu_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_3", &lep_SF_Mu_Iso_FCLoose_AT_3, &b_lep_SF_Mu_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_0", &lep_SF_Mu_PLIV_MnotT_0, &b_lep_SF_Mu_PLIV_MnotT_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_1", &lep_SF_Mu_PLIV_MnotT_1, &b_lep_SF_Mu_PLIV_MnotT_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_2", &lep_SF_Mu_PLIV_MnotT_2, &b_lep_SF_Mu_PLIV_MnotT_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_3", &lep_SF_Mu_PLIV_MnotT_3, &b_lep_SF_Mu_PLIV_MnotT_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_0", &lep_SF_Mu_PLIV_T_0, &b_lep_SF_Mu_PLIV_T_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_1", &lep_SF_Mu_PLIV_T_1, &b_lep_SF_Mu_PLIV_T_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_2", &lep_SF_Mu_PLIV_T_2, &b_lep_SF_Mu_PLIV_T_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_3", &lep_SF_Mu_PLIV_T_3, &b_lep_SF_Mu_PLIV_T_3);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_0", &lep_SF_Mu_TTVA_AT_0, &b_lep_SF_Mu_TTVA_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_1", &lep_SF_Mu_TTVA_AT_1, &b_lep_SF_Mu_TTVA_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_2", &lep_SF_Mu_TTVA_AT_2, &b_lep_SF_Mu_TTVA_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_3", &lep_SF_Mu_TTVA_AT_3, &b_lep_SF_Mu_TTVA_AT_3);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedFCLoose_0", &lep_SF_VLLem_CombinedFCLoose_0, &b_lep_SF_VLLem_CombinedFCLoose_0);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedFCLoose_1", &lep_SF_VLLem_CombinedFCLoose_1, &b_lep_SF_VLLem_CombinedFCLoose_1);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedFCLoose_2", &lep_SF_VLLem_CombinedFCLoose_2, &b_lep_SF_VLLem_CombinedFCLoose_2);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedFCLoose_3", &lep_SF_VLLem_CombinedFCLoose_3, &b_lep_SF_VLLem_CombinedFCLoose_3);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedPLIV_0", &lep_SF_VLLem_CombinedPLIV_0, &b_lep_SF_VLLem_CombinedPLIV_0);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedPLIV_1", &lep_SF_VLLem_CombinedPLIV_1, &b_lep_SF_VLLem_CombinedPLIV_1);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedPLIV_2", &lep_SF_VLLem_CombinedPLIV_2, &b_lep_SF_VLLem_CombinedPLIV_2);
   fChain->SetBranchAddress("lep_SF_VLLem_CombinedPLIV_3", &lep_SF_VLLem_CombinedPLIV_3, &b_lep_SF_VLLem_CombinedPLIV_3);
   fChain->SetBranchAddress("lep_SeparationMinDCT_0", &lep_SeparationMinDCT_0, &b_lep_SeparationMinDCT_0);
   fChain->SetBranchAddress("lep_SeparationMinDCT_1", &lep_SeparationMinDCT_1, &b_lep_SeparationMinDCT_1);
   fChain->SetBranchAddress("lep_SeparationMinDCT_2", &lep_SeparationMinDCT_2, &b_lep_SeparationMinDCT_2);
   fChain->SetBranchAddress("lep_SeparationMinDCT_3", &lep_SeparationMinDCT_3, &b_lep_SeparationMinDCT_3);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   fChain->SetBranchAddress("lep_ambiguityType_0", &lep_ambiguityType_0, &b_lep_ambiguityType_0);
   fChain->SetBranchAddress("lep_ambiguityType_1", &lep_ambiguityType_1, &b_lep_ambiguityType_1);
   fChain->SetBranchAddress("lep_ambiguityType_2", &lep_ambiguityType_2, &b_lep_ambiguityType_2);
   fChain->SetBranchAddress("lep_ambiguityType_3", &lep_ambiguityType_3, &b_lep_ambiguityType_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_0", &lep_chargeIDBDTResult_recalc_rel207_tight_0, &b_lep_chargeIDBDTResult_recalc_rel207_tight_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_1", &lep_chargeIDBDTResult_recalc_rel207_tight_1, &b_lep_chargeIDBDTResult_recalc_rel207_tight_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_2", &lep_chargeIDBDTResult_recalc_rel207_tight_2, &b_lep_chargeIDBDTResult_recalc_rel207_tight_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_3", &lep_chargeIDBDTResult_recalc_rel207_tight_3, &b_lep_chargeIDBDTResult_recalc_rel207_tight_3);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_0", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_0, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_1", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_1, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_2", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_2, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_3", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_3, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_3);
   fChain->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   fChain->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   fChain->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   fChain->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   fChain->SetBranchAddress("lep_deltaz0_0", &lep_deltaz0_0, &b_lep_deltaz0_0);
   fChain->SetBranchAddress("lep_deltaz0_1", &lep_deltaz0_1, &b_lep_deltaz0_1);
   fChain->SetBranchAddress("lep_deltaz0_2", &lep_deltaz0_2, &b_lep_deltaz0_2);
   fChain->SetBranchAddress("lep_deltaz0_3", &lep_deltaz0_3, &b_lep_deltaz0_3);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_0", &lep_firstEgMotherPdgId_0, &b_lep_firstEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_1", &lep_firstEgMotherPdgId_1, &b_lep_firstEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_2", &lep_firstEgMotherPdgId_2, &b_lep_firstEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_3", &lep_firstEgMotherPdgId_3, &b_lep_firstEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_0", &lep_firstEgMotherTruthOrigin_0, &b_lep_firstEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_1", &lep_firstEgMotherTruthOrigin_1, &b_lep_firstEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_2", &lep_firstEgMotherTruthOrigin_2, &b_lep_firstEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_3", &lep_firstEgMotherTruthOrigin_3, &b_lep_firstEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_0", &lep_firstEgMotherTruthType_0, &b_lep_firstEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_1", &lep_firstEgMotherTruthType_1, &b_lep_firstEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_2", &lep_firstEgMotherTruthType_2, &b_lep_firstEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_3", &lep_firstEgMotherTruthType_3, &b_lep_firstEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_flavour", &lep_flavour, &b_lep_flavour);
   fChain->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   fChain->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   fChain->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
   fChain->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
   fChain->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   fChain->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   fChain->SetBranchAddress("lep_isExtConvPh_0", &lep_isExtConvPh_0, &b_lep_isExtConvPh_0);
   fChain->SetBranchAddress("lep_isExtConvPh_1", &lep_isExtConvPh_1, &b_lep_isExtConvPh_1);
   fChain->SetBranchAddress("lep_isExtConvPh_2", &lep_isExtConvPh_2, &b_lep_isExtConvPh_2);
   fChain->SetBranchAddress("lep_isExtConvPh_3", &lep_isExtConvPh_3, &b_lep_isExtConvPh_3);
   fChain->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   fChain->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   fChain->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   fChain->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   fChain->SetBranchAddress("lep_isIntConvPh_0", &lep_isIntConvPh_0, &b_lep_isIntConvPh_0);
   fChain->SetBranchAddress("lep_isIntConvPh_1", &lep_isIntConvPh_1, &b_lep_isIntConvPh_1);
   fChain->SetBranchAddress("lep_isIntConvPh_2", &lep_isIntConvPh_2, &b_lep_isIntConvPh_2);
   fChain->SetBranchAddress("lep_isIntConvPh_3", &lep_isIntConvPh_3, &b_lep_isIntConvPh_3);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   fChain->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   fChain->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   fChain->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   fChain->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   fChain->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_0", &lep_isolationPLImprovedTight_0, &b_lep_isolationPLImprovedTight_0);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_1", &lep_isolationPLImprovedTight_1, &b_lep_isolationPLImprovedTight_1);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_2", &lep_isolationPLImprovedTight_2, &b_lep_isolationPLImprovedTight_2);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_3", &lep_isolationPLImprovedTight_3, &b_lep_isolationPLImprovedTight_3);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_0", &lep_isolationPLImprovedVeryTight_0, &b_lep_isolationPLImprovedVeryTight_0);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_1", &lep_isolationPLImprovedVeryTight_1, &b_lep_isolationPLImprovedVeryTight_1);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_2", &lep_isolationPLImprovedVeryTight_2, &b_lep_isolationPLImprovedVeryTight_2);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_3", &lep_isolationPLImprovedVeryTight_3, &b_lep_isolationPLImprovedVeryTight_3);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_0", &lep_lastEgMotherPdgId_0, &b_lep_lastEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_1", &lep_lastEgMotherPdgId_1, &b_lep_lastEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_2", &lep_lastEgMotherPdgId_2, &b_lep_lastEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_3", &lep_lastEgMotherPdgId_3, &b_lep_lastEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_0", &lep_lastEgMotherTruthOrigin_0, &b_lep_lastEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_1", &lep_lastEgMotherTruthOrigin_1, &b_lep_lastEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_2", &lep_lastEgMotherTruthOrigin_2, &b_lep_lastEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_3", &lep_lastEgMotherTruthOrigin_3, &b_lep_lastEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_0", &lep_lastEgMotherTruthType_0, &b_lep_lastEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_1", &lep_lastEgMotherTruthType_1, &b_lep_lastEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_2", &lep_lastEgMotherTruthType_2, &b_lep_lastEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_3", &lep_lastEgMotherTruthType_3, &b_lep_lastEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_nInnerPix_0", &lep_nInnerPix_0, &b_lep_nInnerPix_0);
   fChain->SetBranchAddress("lep_nInnerPix_1", &lep_nInnerPix_1, &b_lep_nInnerPix_1);
   fChain->SetBranchAddress("lep_nInnerPix_2", &lep_nInnerPix_2, &b_lep_nInnerPix_2);
   fChain->SetBranchAddress("lep_nInnerPix_3", &lep_nInnerPix_3, &b_lep_nInnerPix_3);
   fChain->SetBranchAddress("lep_nTrackParticles_0", &lep_nTrackParticles_0, &b_lep_nTrackParticles_0);
   fChain->SetBranchAddress("lep_nTrackParticles_1", &lep_nTrackParticles_1, &b_lep_nTrackParticles_1);
   fChain->SetBranchAddress("lep_nTrackParticles_2", &lep_nTrackParticles_2, &b_lep_nTrackParticles_2);
   fChain->SetBranchAddress("lep_nTrackParticles_3", &lep_nTrackParticles_3, &b_lep_nTrackParticles_3);
   fChain->SetBranchAddress("lep_plvWP_Loose_0", &lep_plvWP_Loose_0, &b_lep_plvWP_Loose_0);
   fChain->SetBranchAddress("lep_plvWP_Loose_1", &lep_plvWP_Loose_1, &b_lep_plvWP_Loose_1);
   fChain->SetBranchAddress("lep_plvWP_Loose_2", &lep_plvWP_Loose_2, &b_lep_plvWP_Loose_2);
   fChain->SetBranchAddress("lep_plvWP_Loose_3", &lep_plvWP_Loose_3, &b_lep_plvWP_Loose_3);
   fChain->SetBranchAddress("lep_plvWP_Tight_0", &lep_plvWP_Tight_0, &b_lep_plvWP_Tight_0);
   fChain->SetBranchAddress("lep_plvWP_Tight_1", &lep_plvWP_Tight_1, &b_lep_plvWP_Tight_1);
   fChain->SetBranchAddress("lep_plvWP_Tight_2", &lep_plvWP_Tight_2, &b_lep_plvWP_Tight_2);
   fChain->SetBranchAddress("lep_plvWP_Tight_3", &lep_plvWP_Tight_3, &b_lep_plvWP_Tight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_0", &lep_promptLeptonImprovedVetoBARR_TagWeight_0, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_1", &lep_promptLeptonImprovedVetoBARR_TagWeight_1, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_2", &lep_promptLeptonImprovedVetoBARR_TagWeight_2, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_3", &lep_promptLeptonImprovedVetoBARR_TagWeight_3, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_0", &lep_promptLeptonImprovedVetoECAP_TagWeight_0, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_1", &lep_promptLeptonImprovedVetoECAP_TagWeight_1, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_2", &lep_promptLeptonImprovedVetoECAP_TagWeight_2, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_3", &lep_promptLeptonImprovedVetoECAP_TagWeight_3, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_0", &lep_promptLeptonImprovedVeto_TagWeight_0, &b_lep_promptLeptonImprovedVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_1", &lep_promptLeptonImprovedVeto_TagWeight_1, &b_lep_promptLeptonImprovedVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_2", &lep_promptLeptonImprovedVeto_TagWeight_2, &b_lep_promptLeptonImprovedVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_3", &lep_promptLeptonImprovedVeto_TagWeight_3, &b_lep_promptLeptonImprovedVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   fChain->SetBranchAddress("lep_truthE_0", &lep_truthE_0, &b_lep_truthE_0);
   fChain->SetBranchAddress("lep_truthE_1", &lep_truthE_1, &b_lep_truthE_1);
   fChain->SetBranchAddress("lep_truthE_2", &lep_truthE_2, &b_lep_truthE_2);
   fChain->SetBranchAddress("lep_truthE_3", &lep_truthE_3, &b_lep_truthE_3);
   fChain->SetBranchAddress("lep_truthEta_0", &lep_truthEta_0, &b_lep_truthEta_0);
   fChain->SetBranchAddress("lep_truthEta_1", &lep_truthEta_1, &b_lep_truthEta_1);
   fChain->SetBranchAddress("lep_truthEta_2", &lep_truthEta_2, &b_lep_truthEta_2);
   fChain->SetBranchAddress("lep_truthEta_3", &lep_truthEta_3, &b_lep_truthEta_3);
   fChain->SetBranchAddress("lep_truthHasTopInChain_0", &lep_truthHasTopInChain_0, &b_lep_truthHasTopInChain_0);
   fChain->SetBranchAddress("lep_truthHasTopInChain_1", &lep_truthHasTopInChain_1, &b_lep_truthHasTopInChain_1);
   fChain->SetBranchAddress("lep_truthHasTopInChain_2", &lep_truthHasTopInChain_2, &b_lep_truthHasTopInChain_2);
   fChain->SetBranchAddress("lep_truthHasTopInChain_3", &lep_truthHasTopInChain_3, &b_lep_truthHasTopInChain_3);
   fChain->SetBranchAddress("lep_truthM_0", &lep_truthM_0, &b_lep_truthM_0);
   fChain->SetBranchAddress("lep_truthM_1", &lep_truthM_1, &b_lep_truthM_1);
   fChain->SetBranchAddress("lep_truthM_2", &lep_truthM_2, &b_lep_truthM_2);
   fChain->SetBranchAddress("lep_truthM_3", &lep_truthM_3, &b_lep_truthM_3);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   fChain->SetBranchAddress("lep_truthParentBarcode_0", &lep_truthParentBarcode_0, &b_lep_truthParentBarcode_0);
   fChain->SetBranchAddress("lep_truthParentBarcode_1", &lep_truthParentBarcode_1, &b_lep_truthParentBarcode_1);
   fChain->SetBranchAddress("lep_truthParentBarcode_2", &lep_truthParentBarcode_2, &b_lep_truthParentBarcode_2);
   fChain->SetBranchAddress("lep_truthParentBarcode_3", &lep_truthParentBarcode_3, &b_lep_truthParentBarcode_3);
   fChain->SetBranchAddress("lep_truthParentEta_0", &lep_truthParentEta_0, &b_lep_truthParentEta_0);
   fChain->SetBranchAddress("lep_truthParentEta_1", &lep_truthParentEta_1, &b_lep_truthParentEta_1);
   fChain->SetBranchAddress("lep_truthParentEta_2", &lep_truthParentEta_2, &b_lep_truthParentEta_2);
   fChain->SetBranchAddress("lep_truthParentEta_3", &lep_truthParentEta_3, &b_lep_truthParentEta_3);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_0", &lep_truthParentIsBHadron_0, &b_lep_truthParentIsBHadron_0);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_1", &lep_truthParentIsBHadron_1, &b_lep_truthParentIsBHadron_1);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_2", &lep_truthParentIsBHadron_2, &b_lep_truthParentIsBHadron_2);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_3", &lep_truthParentIsBHadron_3, &b_lep_truthParentIsBHadron_3);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_0", &lep_truthParentIsCHadron_0, &b_lep_truthParentIsCHadron_0);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_1", &lep_truthParentIsCHadron_1, &b_lep_truthParentIsCHadron_1);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_2", &lep_truthParentIsCHadron_2, &b_lep_truthParentIsCHadron_2);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_3", &lep_truthParentIsCHadron_3, &b_lep_truthParentIsCHadron_3);
   fChain->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   fChain->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   fChain->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   fChain->SetBranchAddress("lep_truthParentOrigin_3", &lep_truthParentOrigin_3, &b_lep_truthParentOrigin_3);
   fChain->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   fChain->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   fChain->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   fChain->SetBranchAddress("lep_truthParentPdgId_3", &lep_truthParentPdgId_3, &b_lep_truthParentPdgId_3);
   fChain->SetBranchAddress("lep_truthParentPt_0", &lep_truthParentPt_0, &b_lep_truthParentPt_0);
   fChain->SetBranchAddress("lep_truthParentPt_1", &lep_truthParentPt_1, &b_lep_truthParentPt_1);
   fChain->SetBranchAddress("lep_truthParentPt_2", &lep_truthParentPt_2, &b_lep_truthParentPt_2);
   fChain->SetBranchAddress("lep_truthParentPt_3", &lep_truthParentPt_3, &b_lep_truthParentPt_3);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_0", &lep_truthParentRealPdgId_0, &b_lep_truthParentRealPdgId_0);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_1", &lep_truthParentRealPdgId_1, &b_lep_truthParentRealPdgId_1);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_2", &lep_truthParentRealPdgId_2, &b_lep_truthParentRealPdgId_2);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_3", &lep_truthParentRealPdgId_3, &b_lep_truthParentRealPdgId_3);
   fChain->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   fChain->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   fChain->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   fChain->SetBranchAddress("lep_truthParentStatus_3", &lep_truthParentStatus_3, &b_lep_truthParentStatus_3);
   fChain->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   fChain->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   fChain->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   fChain->SetBranchAddress("lep_truthParentType_3", &lep_truthParentType_3, &b_lep_truthParentType_3);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   fChain->SetBranchAddress("lep_truthPhi_0", &lep_truthPhi_0, &b_lep_truthPhi_0);
   fChain->SetBranchAddress("lep_truthPhi_1", &lep_truthPhi_1, &b_lep_truthPhi_1);
   fChain->SetBranchAddress("lep_truthPhi_2", &lep_truthPhi_2, &b_lep_truthPhi_2);
   fChain->SetBranchAddress("lep_truthPhi_3", &lep_truthPhi_3, &b_lep_truthPhi_3);
   fChain->SetBranchAddress("lep_truthPt_0", &lep_truthPt_0, &b_lep_truthPt_0);
   fChain->SetBranchAddress("lep_truthPt_1", &lep_truthPt_1, &b_lep_truthPt_1);
   fChain->SetBranchAddress("lep_truthPt_2", &lep_truthPt_2, &b_lep_truthPt_2);
   fChain->SetBranchAddress("lep_truthPt_3", &lep_truthPt_3, &b_lep_truthPt_3);
   fChain->SetBranchAddress("lep_truthRapidity_0", &lep_truthRapidity_0, &b_lep_truthRapidity_0);
   fChain->SetBranchAddress("lep_truthRapidity_1", &lep_truthRapidity_1, &b_lep_truthRapidity_1);
   fChain->SetBranchAddress("lep_truthRapidity_2", &lep_truthRapidity_2, &b_lep_truthRapidity_2);
   fChain->SetBranchAddress("lep_truthRapidity_3", &lep_truthRapidity_3, &b_lep_truthRapidity_3);
   fChain->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   fChain->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   fChain->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   fChain->SetBranchAddress("lep_truthStatus_3", &lep_truthStatus_3, &b_lep_truthStatus_3);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   fChain->SetBranchAddress("lep_vz_0", &lep_vz_0, &b_lep_vz_0);
   fChain->SetBranchAddress("lep_vz_1", &lep_vz_1, &b_lep_vz_1);
   fChain->SetBranchAddress("lep_vz_2", &lep_vz_2, &b_lep_vz_2);
   fChain->SetBranchAddress("lep_vz_3", &lep_vz_3, &b_lep_vz_3);
   fChain->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   fChain->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   fChain->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   fChain->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   fChain->SetBranchAddress("lqlq_decays", &lqlq_decays, &b_lqlq_decays);
   fChain->SetBranchAddress("m_HF_Classification", &m_HF_Classification, &b_m_HF_Classification);
   fChain->SetBranchAddress("m_HF_ClassificationTop", &m_HF_ClassificationTop, &b_m_HF_ClassificationTop);
   fChain->SetBranchAddress("m_in_vy_overlap", &m_in_vy_overlap, &b_m_in_vy_overlap);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("mu_actual", &mu_actual, &b_mu_actual);
   fChain->SetBranchAddress("nHiggs", &nHiggs, &b_nHiggs);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("nJets_OR_DL1r_60", &nJets_OR_DL1r_60, &b_nJets_OR_DL1r_60);
   fChain->SetBranchAddress("nJets_OR_DL1r_77", &nJets_OR_DL1r_77, &b_nJets_OR_DL1r_77);
   fChain->SetBranchAddress("nJets_OR_DL1r_85", &nJets_OR_DL1r_85, &b_nJets_OR_DL1r_85);
   fChain->SetBranchAddress("nWZhad", &nWZhad, &b_nWZhad);
   fChain->SetBranchAddress("nZee", &nZee, &b_nZee);
   fChain->SetBranchAddress("nZmm", &nZmm, &b_nZmm);
   fChain->SetBranchAddress("passPLIVTight_0", &passPLIVTight_0, &b_passPLIVTight_0);
   fChain->SetBranchAddress("passPLIVTight_1", &passPLIVTight_1, &b_passPLIVTight_1);
   fChain->SetBranchAddress("passPLIVTight_2", &passPLIVTight_2, &b_passPLIVTight_2);
   fChain->SetBranchAddress("passPLIVVeryTight_0", &passPLIVVeryTight_0, &b_passPLIVVeryTight_0);
   fChain->SetBranchAddress("passPLIVVeryTight_1", &passPLIVVeryTight_1, &b_passPLIVVeryTight_1);
   fChain->SetBranchAddress("passPLIVVeryTight_2", &passPLIVVeryTight_2, &b_passPLIVVeryTight_2);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("sumPsbtag", &sumPsbtag, &b_sumPsbtag);
   fChain->SetBranchAddress("top_dilep_filter", &top_dilep_filter, &b_top_dilep_filter);
   fChain->SetBranchAddress("totalEventsWeighted", &totalEventsWeighted, &b_totalEventsWeighted);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_LO1", &totalEventsWeighted_weight_EW_LO1, &b_totalEventsWeighted_weight_EW_LO1);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_LO1LO2LO3", &totalEventsWeighted_weight_EW_LO1LO2LO3, &b_totalEventsWeighted_weight_EW_LO1LO2LO3);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_exp_LO1", &totalEventsWeighted_weight_EW_exp_LO1, &b_totalEventsWeighted_weight_EW_exp_LO1);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_exp_LO1LO2LO3", &totalEventsWeighted_weight_EW_exp_LO1LO2LO3, &b_totalEventsWeighted_weight_EW_exp_LO1LO2LO3);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_mult_LO1", &totalEventsWeighted_weight_EW_mult_LO1, &b_totalEventsWeighted_weight_EW_mult_LO1);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_mult_LO1LO2LO3", &totalEventsWeighted_weight_EW_mult_LO1LO2LO3, &b_totalEventsWeighted_weight_EW_mult_LO1LO2LO3);
   fChain->SetBranchAddress("totalEventsWeighted_weight_FSR0625__1down", &totalEventsWeighted_weight_FSR0625__1down, &b_totalEventsWeighted_weight_FSR0625__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_FSR__1down", &totalEventsWeighted_weight_FSR__1down, &b_totalEventsWeighted_weight_FSR__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_FSR__1up", &totalEventsWeighted_weight_FSR__1up, &b_totalEventsWeighted_weight_FSR__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF_ME__1down", &totalEventsWeighted_weight_MUF_ME__1down, &b_totalEventsWeighted_weight_MUF_ME__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF_ME__1up", &totalEventsWeighted_weight_MUF_ME__1up, &b_totalEventsWeighted_weight_MUF_ME__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF__1down", &totalEventsWeighted_weight_MUF__1down, &b_totalEventsWeighted_weight_MUF__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF__1up", &totalEventsWeighted_weight_MUF__1up, &b_totalEventsWeighted_weight_MUF__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_ME__1down", &totalEventsWeighted_weight_MUR_ME__1down, &b_totalEventsWeighted_weight_MUR_ME__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_ME__1up", &totalEventsWeighted_weight_MUR_ME__1up, &b_totalEventsWeighted_weight_MUR_ME__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF_ME__1down", &totalEventsWeighted_weight_MUR_MUF_ME__1down, &b_totalEventsWeighted_weight_MUR_MUF_ME__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF_ME__1up", &totalEventsWeighted_weight_MUR_MUF_ME__1up, &b_totalEventsWeighted_weight_MUR_MUF_ME__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF__1down", &totalEventsWeighted_weight_MUR_MUF__1down, &b_totalEventsWeighted_weight_MUR_MUF__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF__1up", &totalEventsWeighted_weight_MUR_MUF__1up, &b_totalEventsWeighted_weight_MUR_MUF__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR__1down", &totalEventsWeighted_weight_MUR__1down, &b_totalEventsWeighted_weight_MUR__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR__1up", &totalEventsWeighted_weight_MUR__1up, &b_totalEventsWeighted_weight_MUR__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF13000", &totalEventsWeighted_weight_PDF13000, &b_totalEventsWeighted_weight_PDF13000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF13100", &totalEventsWeighted_weight_PDF13100, &b_totalEventsWeighted_weight_PDF13100);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF25200", &totalEventsWeighted_weight_PDF25200, &b_totalEventsWeighted_weight_PDF25200);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF25300", &totalEventsWeighted_weight_PDF25300, &b_totalEventsWeighted_weight_PDF25300);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF265000", &totalEventsWeighted_weight_PDF265000, &b_totalEventsWeighted_weight_PDF265000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF266000", &totalEventsWeighted_weight_PDF266000, &b_totalEventsWeighted_weight_PDF266000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF269000", &totalEventsWeighted_weight_PDF269000, &b_totalEventsWeighted_weight_PDF269000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF270000", &totalEventsWeighted_weight_PDF270000, &b_totalEventsWeighted_weight_PDF270000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_Var3cDown", &totalEventsWeighted_weight_Var3cDown, &b_totalEventsWeighted_weight_Var3cDown);
   fChain->SetBranchAddress("totalEventsWeighted_weight_Var3cUp", &totalEventsWeighted_weight_Var3cUp, &b_totalEventsWeighted_weight_Var3cUp);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("totchi_X1X2", &totchi_X1X2, &b_totchi_X1X2);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("ttHMLClass_lep_0", &ttHMLClass_lep_0, &b_ttHMLClass_lep_0);
   fChain->SetBranchAddress("ttHMLClass_lep_1", &ttHMLClass_lep_1, &b_ttHMLClass_lep_1);
   fChain->SetBranchAddress("ttHMLClass_lep_2", &ttHMLClass_lep_2, &b_ttHMLClass_lep_2);
   fChain->SetBranchAddress("ttbarDecayMode", &ttbarDecayMode, &b_ttbarDecayMode);
   fChain->SetBranchAddress("weight_MUR_MUF__1down", &weight_MUR_MUF__1down, &b_weight_MUR_MUF__1down);
   fChain->SetBranchAddress("weight_PDF13100", &weight_PDF13100, &b_weight_PDF13100);
   fChain->SetBranchAddress("weight_PDF25200", &weight_PDF25200, &b_weight_PDF25200);
   fChain->SetBranchAddress("weight_PDF266000", &weight_PDF266000, &b_weight_PDF266000);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_70", &weight_bTagSF_DL1r_70, &b_weight_bTagSF_DL1r_70);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous", &weight_bTagSF_DL1r_Continuous, &b_weight_bTagSF_DL1r_Continuous);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_10__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_11__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_12__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_13__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_14__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_15__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_16__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_17__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_18__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_19__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_20__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_21__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_22__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_23__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_24__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_25__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_26__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_27__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_28__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_29__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_2__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_30__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_31__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_32__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_33__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_34__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_35__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_36__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_37__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_38__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_39__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_3__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_40__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_41__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_42__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_43__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_44__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_4__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_5__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_6__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_7__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_8__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_B_9__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_10__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_11__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_12__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_13__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_14__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_15__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_16__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_17__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_18__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_19__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_2__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_3__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_4__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_5__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_6__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_7__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_8__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_C_9__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_10__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_11__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_12__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_13__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_14__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_15__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_16__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_17__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_18__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_19__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_2__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_3__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_4__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_5__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_6__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_7__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_8__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up", &weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up, &b_weight_bTagSF_DL1r_Continuous_FT_EFF_Eigen_Light_9__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_2__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_b_Eigen_3__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_c_Eigen_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_0__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_1__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_2__1up);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1down", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1down, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1down);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1up", &weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1up, &b_weight_bTagSF_DL1r_Continuous_extrapolation_pt_l_Eigen_5__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF", &weight_globalLeptonTriggerSF, &b_weight_globalLeptonTriggerSF);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP", &weight_globalLeptonTriggerSF_CWP, &b_weight_globalLeptonTriggerSF_CWP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_jvt__1down", &weight_jvt__1down, &b_weight_jvt__1down);
   fChain->SetBranchAddress("weight_jvt__1up", &weight_jvt__1up, &b_weight_jvt__1up);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT", &weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT, &b_weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT", &weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT, &b_weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_TightLH_DOWN_AT", &weight_leptonSF_El_ID_TightLH_DOWN_AT, &b_weight_leptonSF_El_ID_TightLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_TightLH_UP_AT", &weight_leptonSF_El_ID_TightLH_UP_AT, &b_weight_leptonSF_El_ID_TightLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Iso_FCLoose_DOWN_AT", &weight_leptonSF_El_Iso_FCLoose_DOWN_AT, &b_weight_leptonSF_El_Iso_FCLoose_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Iso_FCLoose_UP_AT", &weight_leptonSF_El_Iso_FCLoose_UP_AT, &b_weight_leptonSF_El_Iso_FCLoose_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Reco_DOWN_AT", &weight_leptonSF_El_Reco_DOWN_AT, &b_weight_leptonSF_El_Reco_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Reco_UP_AT", &weight_leptonSF_El_Reco_UP_AT, &b_weight_leptonSF_El_Reco_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_UP_AT", &weight_leptonSF_Mu_ID_Loose_STAT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_UP_AT", &weight_leptonSF_Mu_ID_Loose_SYST_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_UP_AT", &weight_leptonSF_Mu_ID_Medium_STAT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_UP_AT", &weight_leptonSF_Mu_ID_Medium_SYST_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT", &weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT", &weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT", &weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT", &weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_STAT_DOWN_AT", &weight_leptonSF_Mu_TTVA_STAT_DOWN_AT, &b_weight_leptonSF_Mu_TTVA_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_STAT_UP_AT", &weight_leptonSF_Mu_TTVA_STAT_UP_AT, &b_weight_leptonSF_Mu_TTVA_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_SYST_DOWN_AT", &weight_leptonSF_Mu_TTVA_SYST_DOWN_AT, &b_weight_leptonSF_Mu_TTVA_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_SYST_UP_AT", &weight_leptonSF_Mu_TTVA_SYST_UP_AT, &b_weight_leptonSF_Mu_TTVA_SYST_UP_AT);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_pileup_DOWN", &weight_pileup_DOWN, &b_weight_pileup_DOWN);
   fChain->SetBranchAddress("weight_pileup_UP", &weight_pileup_UP, &b_weight_pileup_UP);
   fChain->SetBranchAddress("xs", &xs, &b_xs);
}

#endif // #ifdef VLLf_cxx
