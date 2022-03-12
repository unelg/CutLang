#ifndef VLLg_h
#define VLLg_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"

// Header file for the classes stored in the TTree if any.

class VLLg {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         totalEventsWeighted;
   Float_t         totalEventsWeighted_weight_MUF__1down;
   Float_t         totalEventsWeighted_weight_MUF__1up;
   Float_t         totalEventsWeighted_weight_MUR_MUF__1down;
   Float_t         totalEventsWeighted_weight_MUR_MUF__1up;
   Float_t         totalEventsWeighted_weight_MUR__1down;
   Float_t         totalEventsWeighted_weight_MUR__1up;
   Float_t         totalEventsWeighted_weight_PDF13000;
   Float_t         totalEventsWeighted_weight_PDF25300;
   Float_t         xs;
   Float_t         lep_pT_new_1;
   Float_t         lep_pT_new_2;
   Float_t         lep_eta_new_1;
   Float_t         lep_eta_new_2;
   Float_t         jet_pt0;
   Float_t         jet_eta0;
   Float_t         jet_pt1;
   Float_t         jet_eta1;
   Float_t         jet_pt2;
   Float_t         jet_eta2;
   Float_t         DeltaR_min_lep_jet;
   Float_t         DeltaR_min_lep_jet_fwd;
   Float_t         minDeltaR_LJ_0;
   Float_t         minDeltaR_LJ_1;
   Float_t         minDeltaR_LJ_2;
   Float_t         bjet_pt0;
   Float_t         bjet_eta0;
   Float_t         HT_vis_min;
   Float_t         HT_vis;
   Float_t         Mlb;
   Float_t         DRlb;
   Float_t         DeltaR_max_lep_bjet77;
   Float_t         DeltaR_min_lep_bjet77;
   Float_t         RecoLepTopMass85;
   Float_t         RecoLepTopMass77;
   Float_t         RecoLepTopMass70;
   Float_t         RecoLepTopMass60;
   Float_t         Mbblead;
   Float_t         MLepMet;
   Float_t         MtLepMet;
   Float_t         MtLep0Met;
   Float_t         mjjMax_frwdJet;
   Float_t         DRjj_lead;
   Float_t         mjj_lead;
   Float_t         mjjj_lead;
   Float_t         eta_frwdjet;
   Float_t         dEta_maxMjj_frwdjet;
   Int_t           lep_flavour;
   Float_t         max_eta;
   Float_t         DEtall_SS;
   Float_t         DEtall_OS_0;
   Float_t         DEtall_OS_1;
   Float_t         DPhill_SS;
   Float_t         DPhill_OS_0;
   Float_t         DPhill_OS_1;
   Float_t         Mll_SS;
   Float_t         Mll_OS_0;
   Float_t         Mll_OS_1;
   Bool_t          passPLIVTight_0;
   Bool_t          passPLIVVeryTight_0;
   Bool_t          passPLIVTight_1;
   Bool_t          passPLIVVeryTight_1;
   Bool_t          passPLIVTight_2;
   Bool_t          passPLIVVeryTight_2;
   Int_t           jet_pseudoscore_DL1r0;
   Int_t           jet_pseudoscore_DL1r1;
   Int_t           jet_pseudoscore_DL1r2;
   Int_t           jet_pseudoscore_DL1r3;
   Int_t           jet_pseudoscore_DL1r4;
   Int_t           sumPsbtag;
   Int_t           sumPsbtag77;
   Float_t         jet_pt0_nofwd;
   Float_t         jet_pt1_nofwd;
   Float_t         jet_pt6_nofwd;
   Float_t         jet_pt0_nonbtag;
   Float_t         minDeltaR_J_bJ;
   Bool_t          l2SS1tau;
   Int_t           IFFClass_lep_0;
   Int_t           IFFClass_lep_1;
   Int_t           IFFClass_lep_2;
   Int_t           ttHMLClass_lep_0;
   Int_t           ttHMLClass_lep_1;
   Int_t           ttHMLClass_lep_2;
   Float_t         HT_fixed;
   Float_t         HT_inclFwdJets_fixed;
   Float_t         lepSF_PLIV_Prompt_0;
   Float_t         lepSF_PLIV_NonPrompt_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalError_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalSystError_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_statError_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_IDSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_muSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_El_isoSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_1;
   Float_t         lepSF_PLIV_NonPrompt_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalError_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalSystError_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_statError_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_IDSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_muSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_El_isoSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_2;
   Float_t         lepSF_PLIV_NonPrompt_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalError_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_totalSystError_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_statError_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_IDSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_muSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_El_isoSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         weight_MUF__1up;
   Float_t         weight_MUR_MUF__1up;
   Float_t         weight_MUR__1up;
   Float_t         weight_PDF13000;
   Float_t         weight_MUR__1down;
   Float_t         weight_MUR_MUF__1down;
   Float_t         weight_PDF25300;
   Float_t         weight_MUF__1down;
   Float_t         weight_jvt;
   Float_t         weight_jvt__1up;
   Float_t         weight_jvt__1down;
   Float_t         weight_fjvt;
   Float_t         weight_fjvt__1up;
   Float_t         weight_fjvt__1down;
   Float_t         weight_leptonSF;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_El_Reco_UP_AT;
   Float_t         weight_leptonSF_El_Reco_DOWN_AT;
   Float_t         weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT;
   Float_t         weight_leptonSF_El_ID_TightLH_UP_AT;
   Float_t         weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT;
   Float_t         weight_leptonSF_El_ID_TightLH_DOWN_AT;
   Float_t         weight_leptonSF_El_Iso_FCLoose_UP_AT;
   Float_t         weight_leptonSF_El_Iso_FCLoose_DOWN_AT;
   Float_t         weight_leptonSF_Mu_TTVA_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_TTVA_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_TTVA_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_TTVA_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT;
   Float_t         weight_globalLeptonTriggerSF;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;
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
   Int_t           m_HF_Classification;
   Int_t           m_HF_ClassificationTop;
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_pileup_UP;
   Float_t         weight_pileup_DOWN;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   Float_t         mu_actual;
   Float_t         met_met;
   Float_t         met_phi;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_mu22_mu8noL1;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu18_mu8noL1;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_2e12_lhloose_L12EM10VH;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_2e17_lhvloose_nod0;
   Char_t          HLT_e17_lhloose_mu14;
   Char_t          onelep_type;
   Char_t          dilep_type;
   Char_t          trilep_type;
   Char_t          quadlep_type;
   Char_t          total_charge;
   Char_t          total_leptons;
   Float_t         Mll01;
   Float_t         Ptll01;
   Float_t         DRll01;
   Float_t         Mlll012;
   Float_t         Mllll0123;
   Float_t         Mll02;
   Float_t         Ptll02;
   Float_t         DRll02;
   Float_t         Mll03;
   Float_t         DRll03;
   Float_t         Mll12;
   Float_t         Ptll12;
   Float_t         DRll12;
   Float_t         Mll13;
   Float_t         DRll13;
   Float_t         Mll23;
   Float_t         DRll23;
   Float_t         best_Z_Mll;
   Float_t         best_Z_other_MtLepMet;
   Float_t         best_Z_other_Mll;
   Float_t         minOSSFMll;
   Float_t         minOSMll;
   Char_t          nJets_OR;
   Char_t          nJets_OR_TauOR;
   Char_t          nFwdJets_OR;
   Char_t          nFwdJets_OR_TauOR;
   Char_t          nJets_OR_DL1r_85;
   Char_t          nJets_OR_DL1r_60;
   Char_t          nJets_OR_DL1r_77;
   Char_t          nJets_OR_DL1r_70;
   Char_t          nTaus_OR_Pt25;
   Char_t          nTaus_OR;
   Float_t         HT;
   Float_t         HT_inclFwdJets;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Float_t         HT_fwdJets;
   Int_t           RunYear;
   Float_t         lep_ID_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_Phi_0;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_Z0SinTheta_0;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isMediumLH_0;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isTight_0;
   Char_t          lep_isMedium_0;
   Char_t          lep_isLoose_0;
   Char_t          lep_isolationFCTight_0;
   Char_t          lep_isolationFCLoose_0;
   Char_t          lep_plvWP_Loose_0;
   Char_t          lep_plvWP_Tight_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;
   Char_t          lep_isPrompt_0;
   Char_t          lep_isFakeLep_0;
   Char_t          lep_isQMisID_0;
   Char_t          lep_isConvPh_0;
   Char_t          lep_isExtConvPh_0;
   Char_t          lep_isIntConvPh_0;
   Char_t          lep_isISR_FSR_Ph_0;
   Char_t          lep_isBrems_0;
   Int_t           lep_nTrackParticles_0;
   Float_t         lep_Mtrktrk_atPV_CO_0;
   Float_t         lep_Mtrktrk_atConvV_CO_0;
   Float_t         lep_RadiusCO_0;
   Float_t         lep_RadiusCOX_0;
   Float_t         lep_RadiusCOY_0;
   Int_t           lep_DFCommonAddAmbiguity_0;
   Float_t         lep_DFCommonProdTrueRadius_0;
   Double_t        lep_chargeIDBDTResult_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_0;
   Float_t         lep_promptLeptonVeto_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_0;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_0;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_0;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_0;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_0;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_0;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_0;
   Float_t         lep_PromptLeptonRNN_prompt_0;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_0;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_0;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_0;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0;
   Char_t          lep_isTruthMatched_0;
   Int_t           lep_truthType_0;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthPdgId_0;
   Int_t           lep_truthStatus_0;
   Int_t           lep_truthParentType_0;
   Int_t           lep_truthParentOrigin_0;
   Int_t           lep_truthParentPdgId_0;
   Int_t           lep_truthParentStatus_0;
   Float_t         lep_truthPt_0;
   Float_t         lep_truthEta_0;
   Float_t         lep_truthPhi_0;
   Float_t         lep_truthM_0;
   Float_t         lep_truthE_0;
   Float_t         lep_truthRapidity_0;
   UChar_t         lep_ambiguityType_0;
   Int_t           lep_nInnerPix_0;
   Int_t           lep_firstEgMotherPdgId_0;
   Int_t           lep_firstEgMotherTruthType_0;
   Int_t           lep_firstEgMotherTruthOrigin_0;
   Int_t           lep_lastEgMotherPdgId_0;
   Int_t           lep_lastEgMotherTruthType_0;
   Int_t           lep_lastEgMotherTruthOrigin_0;
   Float_t         lep_SF_El_Reco_AT_0;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_0;
   Float_t         lep_SF_El_ID_TightLH_AT_0;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_0;
   Float_t         lep_SF_El_ID_MediumLH_0;
   Float_t         lep_SF_Mu_TTVA_AT_0;
   Float_t         lep_SF_Mu_ID_Loose_AT_0;
   Float_t         lep_SF_Mu_ID_Medium_AT_0;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_0;
   Float_t         lep_SF_Mu_ID_Tight_0;
   Float_t         lep_SF_CombinedLoose_0;
   Float_t         lep_SF_CombinedTight_0;
   Float_t         lep_ID_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_Phi_1;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_Z0SinTheta_1;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isMediumLH_1;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isTight_1;
   Char_t          lep_isMedium_1;
   Char_t          lep_isLoose_1;
   Char_t          lep_isolationFCTight_1;
   Char_t          lep_isolationFCLoose_1;
   Char_t          lep_plvWP_Loose_1;
   Char_t          lep_plvWP_Tight_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;
   Char_t          lep_isPrompt_1;
   Char_t          lep_isFakeLep_1;
   Char_t          lep_isQMisID_1;
   Char_t          lep_isConvPh_1;
   Char_t          lep_isExtConvPh_1;
   Char_t          lep_isIntConvPh_1;
   Char_t          lep_isISR_FSR_Ph_1;
   Char_t          lep_isBrems_1;
   Int_t           lep_nTrackParticles_1;
   Float_t         lep_Mtrktrk_atPV_CO_1;
   Float_t         lep_Mtrktrk_atConvV_CO_1;
   Float_t         lep_RadiusCO_1;
   Float_t         lep_RadiusCOX_1;
   Float_t         lep_RadiusCOY_1;
   Int_t           lep_DFCommonAddAmbiguity_1;
   Float_t         lep_DFCommonProdTrueRadius_1;
   Double_t        lep_chargeIDBDTResult_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_1;
   Float_t         lep_promptLeptonVeto_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_1;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_1;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_1;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_1;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_1;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_1;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_1;
   Float_t         lep_PromptLeptonRNN_prompt_1;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_1;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_1;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_1;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1;
   Char_t          lep_isTruthMatched_1;
   Int_t           lep_truthType_1;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthPdgId_1;
   Int_t           lep_truthStatus_1;
   Int_t           lep_truthParentType_1;
   Int_t           lep_truthParentOrigin_1;
   Int_t           lep_truthParentPdgId_1;
   Int_t           lep_truthParentStatus_1;
   Float_t         lep_truthPt_1;
   Float_t         lep_truthEta_1;
   Float_t         lep_truthPhi_1;
   Float_t         lep_truthM_1;
   Float_t         lep_truthE_1;
   Float_t         lep_truthRapidity_1;
   UChar_t         lep_ambiguityType_1;
   Int_t           lep_nInnerPix_1;
   Int_t           lep_firstEgMotherPdgId_1;
   Int_t           lep_firstEgMotherTruthType_1;
   Int_t           lep_firstEgMotherTruthOrigin_1;
   Int_t           lep_lastEgMotherPdgId_1;
   Int_t           lep_lastEgMotherTruthType_1;
   Int_t           lep_lastEgMotherTruthOrigin_1;
   Float_t         lep_SF_El_Reco_AT_1;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_1;
   Float_t         lep_SF_El_ID_TightLH_AT_1;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_1;
   Float_t         lep_SF_El_ID_MediumLH_1;
   Float_t         lep_SF_Mu_TTVA_AT_1;
   Float_t         lep_SF_Mu_ID_Loose_AT_1;
   Float_t         lep_SF_Mu_ID_Medium_AT_1;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_1;
   Float_t         lep_SF_Mu_ID_Tight_1;
   Float_t         lep_SF_CombinedLoose_1;
   Float_t         lep_SF_CombinedTight_1;
   Float_t         lep_ID_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_Phi_2;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_Z0SinTheta_2;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isMediumLH_2;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isTight_2;
   Char_t          lep_isMedium_2;
   Char_t          lep_isLoose_2;
   Char_t          lep_isolationFCTight_2;
   Char_t          lep_isolationFCLoose_2;
   Char_t          lep_plvWP_Loose_2;
   Char_t          lep_plvWP_Tight_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;
   Char_t          lep_isPrompt_2;
   Char_t          lep_isFakeLep_2;
   Char_t          lep_isQMisID_2;
   Char_t          lep_isConvPh_2;
   Char_t          lep_isExtConvPh_2;
   Char_t          lep_isIntConvPh_2;
   Char_t          lep_isISR_FSR_Ph_2;
   Char_t          lep_isBrems_2;
   Int_t           lep_nTrackParticles_2;
   Float_t         lep_Mtrktrk_atPV_CO_2;
   Float_t         lep_Mtrktrk_atConvV_CO_2;
   Float_t         lep_RadiusCO_2;
   Float_t         lep_RadiusCOX_2;
   Float_t         lep_RadiusCOY_2;
   Int_t           lep_DFCommonAddAmbiguity_2;
   Float_t         lep_DFCommonProdTrueRadius_2;
   Double_t        lep_chargeIDBDTResult_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_2;
   Float_t         lep_promptLeptonVeto_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_2;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_2;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_2;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_2;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_2;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_2;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_2;
   Float_t         lep_PromptLeptonRNN_prompt_2;
   Short_t         lep_PromptLeptonImprovedInput_TrackJetNTrack_2;
   Float_t         lep_PromptLeptonImprovedInput_RelPt_2;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2;
   Float_t         lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2;
   Float_t         lep_PromptLeptonImprovedInput_RelCaloClusterE_2;
   Float_t         lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2;
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Int_t           lep_truthStatus_2;
   Int_t           lep_truthParentType_2;
   Int_t           lep_truthParentOrigin_2;
   Int_t           lep_truthParentPdgId_2;
   Int_t           lep_truthParentStatus_2;
   Float_t         lep_truthPt_2;
   Float_t         lep_truthEta_2;
   Float_t         lep_truthPhi_2;
   Float_t         lep_truthM_2;
   Float_t         lep_truthE_2;
   Float_t         lep_truthRapidity_2;
   UChar_t         lep_ambiguityType_2;
   Int_t           lep_nInnerPix_2;
   Int_t           lep_firstEgMotherPdgId_2;
   Int_t           lep_firstEgMotherTruthType_2;
   Int_t           lep_firstEgMotherTruthOrigin_2;
   Int_t           lep_lastEgMotherPdgId_2;
   Int_t           lep_lastEgMotherTruthType_2;
   Int_t           lep_lastEgMotherTruthOrigin_2;
   Float_t         lep_SF_El_Reco_AT_2;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_2;
   Float_t         lep_SF_El_ID_TightLH_AT_2;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_2;
   Float_t         lep_SF_El_ID_MediumLH_2;
   Float_t         lep_SF_Mu_TTVA_AT_2;
   Float_t         lep_SF_Mu_ID_Loose_AT_2;
   Float_t         lep_SF_Mu_ID_Medium_AT_2;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_2;
   Float_t         lep_SF_Mu_ID_Tight_2;
   Float_t         lep_SF_CombinedLoose_2;
   Float_t         lep_SF_CombinedTight_2;
   Float_t         lep_ID_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_Phi_3;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isMedium_3;
   Char_t          lep_isolationFCLoose_3;
   Float_t         lep_promptLeptonVeto_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_3;
   Float_t         lep_SF_El_Reco_AT_3;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_3;
   Float_t         lep_SF_El_ID_TightLH_AT_3;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_3;
   Float_t         lep_SF_El_ID_MediumLH_3;
   Float_t         lep_SF_Mu_TTVA_AT_3;
   Float_t         lep_SF_Mu_ID_Loose_AT_3;
   Float_t         lep_SF_Mu_ID_Medium_AT_3;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_3;
   Float_t         lep_SF_Mu_ID_Tight_3;
   Float_t         lep_SF_CombinedLoose_3;
   Float_t         lep_SF_CombinedTight_3;
   Int_t           flag_JetCleaning_LooseBad;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_SLT;
   Float_t         custTrigSF_LooseID_FCLooseIso_DLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_SLTorDLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_SLT;
   Char_t          custTrigMatch_LooseID_FCLooseIso_DLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_SLT;
   Float_t         custTrigSF_TightElMediumMuID_FCLooseIso_DLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_SLT;
   Char_t          custTrigMatch_TightElMediumMuID_FCLooseIso_DLT;
   Char_t          GlobalTrigDecision_2e12_lhloose_L12EM10VH;
   Char_t          GlobalTrigDecision_2e17_lhvloose_nod0;
   Char_t          GlobalTrigDecision_2e24_lhvloose_nod0;
   Char_t          GlobalTrigDecision_e120_lhloose;
   Char_t          GlobalTrigDecision_e140_lhloose_nod0;
   Char_t          GlobalTrigDecision_e17_lhloose_mu14;
   Char_t          GlobalTrigDecision_e17_lhloose_nod0_mu14;
   Char_t          GlobalTrigDecision_e24_lhmedium_L1EM20VH;
   Char_t          GlobalTrigDecision_e26_lhtight_nod0_ivarloose;
   Char_t          GlobalTrigDecision_e60_lhmedium;
   Char_t          GlobalTrigDecision_e60_lhmedium_nod0;
   Char_t          GlobalTrigDecision_mu18_mu8noL1;
   Char_t          GlobalTrigDecision_mu20_iloose_L1MU15;
   Char_t          GlobalTrigDecision_mu22_mu8noL1;
   Char_t          GlobalTrigDecision_mu26_ivarmedium;
   Char_t          GlobalTrigDecision_mu50;
   Int_t           higgsDecayMode;
   Int_t           hhiggsDecayMode;
   Int_t           initial_state;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSFObjChannelCombined;
   Float_t         jvtSF_customOR;
   Float_t         fjvtSF_customOR;
   Float_t         bTagSF_weight_DL1r_60;
   Float_t         bTagSF_weight_DL1r_70;
   Float_t         bTagSF_weight_DL1r_77;
   Float_t         bTagSF_weight_DL1r_85;
   Float_t         bTagSF_weight_DL1r_Continuous;

   // List of branches
   TBranch        *b_totalEventsWeighted;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUF__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR_MUF__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR__1down;   //!
   TBranch        *b_totalEventsWeighted_weight_MUR__1up;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF13000;   //!
   TBranch        *b_totalEventsWeighted_weight_PDF25300;   //!
   TBranch        *b_xs;   //!
   TBranch        *b_lep_pT_new_1;   //!
   TBranch        *b_lep_pT_new_2;   //!
   TBranch        *b_lep_eta_new_1;   //!
   TBranch        *b_lep_eta_new_2;   //!
   TBranch        *b_jet_pt0;   //!
   TBranch        *b_jet_eta0;   //!
   TBranch        *b_jet_pt1;   //!
   TBranch        *b_jet_eta1;   //!
   TBranch        *b_jet_pt2;   //!
   TBranch        *b_jet_eta2;   //!
   TBranch        *b_DeltaR_min_lep_jet;   //!
   TBranch        *b_DeltaR_min_lep_jet_fwd;   //!
   TBranch        *b_minDeltaR_LJ_0;   //!
   TBranch        *b_minDeltaR_LJ_1;   //!
   TBranch        *b_minDeltaR_LJ_2;   //!
   TBranch        *b_bjet_pt0;   //!
   TBranch        *b_bjet_eta0;   //!
   TBranch        *b_HT_vis_min;   //!
   TBranch        *b_HT_vis;   //!
   TBranch        *b_Mlb;   //!
   TBranch        *b_DRlb;   //!
   TBranch        *b_DeltaR_max_lep_bjet77;   //!
   TBranch        *b_DeltaR_min_lep_bjet77;   //!
   TBranch        *b_RecoLepTopMass85;   //!
   TBranch        *b_RecoLepTopMass77;   //!
   TBranch        *b_RecoLepTopMass70;   //!
   TBranch        *b_RecoLepTopMass60;   //!
   TBranch        *b_Mbblead;   //!
   TBranch        *b_MLepMet;   //!
   TBranch        *b_MtLepMet;   //!
   TBranch        *b_MtLep0Met;   //!
   TBranch        *b_mjjMax_frwdJet;   //!
   TBranch        *b_DRjj_lead;   //!
   TBranch        *b_mjj_lead;   //!
   TBranch        *b_mjjj_lead;   //!
   TBranch        *b_eta_frwdjet;   //!
   TBranch        *b_dEta_maxMjj_frwdjet;   //!
   TBranch        *b_lep_flavour;   //!
   TBranch        *b_max_eta;   //!
   TBranch        *b_DEtall_SS;   //!
   TBranch        *b_DEtall_OS_0;   //!
   TBranch        *b_DEtall_OS_1;   //!
   TBranch        *b_DPhill_SS;   //!
   TBranch        *b_DPhill_OS_0;   //!
   TBranch        *b_DPhill_OS_1;   //!
   TBranch        *b_Mll_SS;   //!
   TBranch        *b_Mll_OS_0;   //!
   TBranch        *b_Mll_OS_1;   //!
   TBranch        *b_passPLIVTight_0;   //!
   TBranch        *b_passPLIVVeryTight_0;   //!
   TBranch        *b_passPLIVTight_1;   //!
   TBranch        *b_passPLIVVeryTight_1;   //!
   TBranch        *b_passPLIVTight_2;   //!
   TBranch        *b_passPLIVVeryTight_2;   //!
   TBranch        *b_jet_pseudoscore_DL1r0;   //!
   TBranch        *b_jet_pseudoscore_DL1r1;   //!
   TBranch        *b_jet_pseudoscore_DL1r2;   //!
   TBranch        *b_jet_pseudoscore_DL1r3;   //!
   TBranch        *b_jet_pseudoscore_DL1r4;   //!
   TBranch        *b_sumPsbtag;   //!
   TBranch        *b_sumPsbtag77;   //!
   TBranch        *b_jet_pt0_nofwd;   //!
   TBranch        *b_jet_pt1_nofwd;   //!
   TBranch        *b_jet_pt6_nofwd;   //!
   TBranch        *b_jet_pt0_nonbtag;   //!
   TBranch        *b_minDeltaR_J_bJ;   //!
   TBranch        *b_l2SS1tau;   //!
   TBranch        *b_IFFClass_lep_0;   //!
   TBranch        *b_IFFClass_lep_1;   //!
   TBranch        *b_IFFClass_lep_2;   //!
   TBranch        *b_ttHMLClass_lep_0;   //!
   TBranch        *b_ttHMLClass_lep_1;   //!
   TBranch        *b_ttHMLClass_lep_2;   //!
   TBranch        *b_HT_fixed;   //!
   TBranch        *b_HT_inclFwdJets_fixed;   //!
   TBranch        *b_lepSF_PLIV_Prompt_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_weight_MUF__1up;   //!
   TBranch        *b_weight_MUR_MUF__1up;   //!
   TBranch        *b_weight_MUR__1up;   //!
   TBranch        *b_weight_PDF13000;   //!
   TBranch        *b_weight_MUR__1down;   //!
   TBranch        *b_weight_MUR_MUF__1down;   //!
   TBranch        *b_weight_PDF25300;   //!
   TBranch        *b_weight_MUF__1down;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_weight_jvt__1up;   //!
   TBranch        *b_weight_jvt__1down;   //!
   TBranch        *b_weight_fjvt;   //!
   TBranch        *b_weight_fjvt__1up;   //!
   TBranch        *b_weight_fjvt__1down;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_Reco_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_Reco_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_TightLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_ID_TightLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_El_Iso_FCLoose_UP_AT;   //!
   TBranch        *b_weight_leptonSF_El_Iso_FCLoose_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_TTVA_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_globalLeptonTriggerSF;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;   //!
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
   TBranch        *b_m_HF_Classification;   //!
   TBranch        *b_m_HF_ClassificationTop;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_pileup_UP;   //!
   TBranch        *b_weight_pileup_DOWN;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_mu_actual;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_onelep_type;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_quadlep_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_Mll01;   //!
   TBranch        *b_Ptll01;   //!
   TBranch        *b_DRll01;   //!
   TBranch        *b_Mlll012;   //!
   TBranch        *b_Mllll0123;   //!
   TBranch        *b_Mll02;   //!
   TBranch        *b_Ptll02;   //!
   TBranch        *b_DRll02;   //!
   TBranch        *b_Mll03;   //!
   TBranch        *b_DRll03;   //!
   TBranch        *b_Mll12;   //!
   TBranch        *b_Ptll12;   //!
   TBranch        *b_DRll12;   //!
   TBranch        *b_Mll13;   //!
   TBranch        *b_DRll13;   //!
   TBranch        *b_Mll23;   //!
   TBranch        *b_DRll23;   //!
   TBranch        *b_best_Z_Mll;   //!
   TBranch        *b_best_Z_other_MtLepMet;   //!
   TBranch        *b_best_Z_other_Mll;   //!
   TBranch        *b_minOSSFMll;   //!
   TBranch        *b_minOSMll;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nJets_OR_TauOR;   //!
   TBranch        *b_nFwdJets_OR;   //!
   TBranch        *b_nFwdJets_OR_TauOR;   //!
   TBranch        *b_nJets_OR_DL1r_85;   //!
   TBranch        *b_nJets_OR_DL1r_60;   //!
   TBranch        *b_nJets_OR_DL1r_77;   //!
   TBranch        *b_nJets_OR_DL1r_70;   //!
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_nTaus_OR;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_inclFwdJets;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_HT_fwdJets;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isMediumLH_0;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isTight_0;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isLoose_0;   //!
   TBranch        *b_lep_isolationFCTight_0;   //!
   TBranch        *b_lep_isolationFCLoose_0;   //!
   TBranch        *b_lep_plvWP_Loose_0;   //!
   TBranch        *b_lep_plvWP_Tight_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;   //!
   TBranch        *b_lep_isPrompt_0;   //!
   TBranch        *b_lep_isFakeLep_0;   //!
   TBranch        *b_lep_isQMisID_0;   //!
   TBranch        *b_lep_isConvPh_0;   //!
   TBranch        *b_lep_isExtConvPh_0;   //!
   TBranch        *b_lep_isIntConvPh_0;   //!
   TBranch        *b_lep_isISR_FSR_Ph_0;   //!
   TBranch        *b_lep_isBrems_0;   //!
   TBranch        *b_lep_nTrackParticles_0;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_0;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_0;   //!
   TBranch        *b_lep_RadiusCO_0;   //!
   TBranch        *b_lep_RadiusCOX_0;   //!
   TBranch        *b_lep_RadiusCOY_0;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_0;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_0;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_0;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_0;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_0;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0;   //!
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_truthStatus_0;   //!
   TBranch        *b_lep_truthParentType_0;   //!
   TBranch        *b_lep_truthParentOrigin_0;   //!
   TBranch        *b_lep_truthParentPdgId_0;   //!
   TBranch        *b_lep_truthParentStatus_0;   //!
   TBranch        *b_lep_truthPt_0;   //!
   TBranch        *b_lep_truthEta_0;   //!
   TBranch        *b_lep_truthPhi_0;   //!
   TBranch        *b_lep_truthM_0;   //!
   TBranch        *b_lep_truthE_0;   //!
   TBranch        *b_lep_truthRapidity_0;   //!
   TBranch        *b_lep_ambiguityType_0;   //!
   TBranch        *b_lep_nInnerPix_0;   //!
   TBranch        *b_lep_firstEgMotherPdgId_0;   //!
   TBranch        *b_lep_firstEgMotherTruthType_0;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_lastEgMotherPdgId_0;   //!
   TBranch        *b_lep_lastEgMotherTruthType_0;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_0;   //!
   TBranch        *b_lep_SF_El_Reco_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_0;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_0;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_0;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_0;   //!
   TBranch        *b_lep_SF_CombinedLoose_0;   //!
   TBranch        *b_lep_SF_CombinedTight_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isMediumLH_1;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isTight_1;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isLoose_1;   //!
   TBranch        *b_lep_isolationFCTight_1;   //!
   TBranch        *b_lep_isolationFCLoose_1;   //!
   TBranch        *b_lep_plvWP_Loose_1;   //!
   TBranch        *b_lep_plvWP_Tight_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;   //!
   TBranch        *b_lep_isPrompt_1;   //!
   TBranch        *b_lep_isFakeLep_1;   //!
   TBranch        *b_lep_isQMisID_1;   //!
   TBranch        *b_lep_isConvPh_1;   //!
   TBranch        *b_lep_isExtConvPh_1;   //!
   TBranch        *b_lep_isIntConvPh_1;   //!
   TBranch        *b_lep_isISR_FSR_Ph_1;   //!
   TBranch        *b_lep_isBrems_1;   //!
   TBranch        *b_lep_nTrackParticles_1;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_1;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_1;   //!
   TBranch        *b_lep_RadiusCO_1;   //!
   TBranch        *b_lep_RadiusCOX_1;   //!
   TBranch        *b_lep_RadiusCOY_1;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_1;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_1;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_1;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_1;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_1;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1;   //!
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_truthStatus_1;   //!
   TBranch        *b_lep_truthParentType_1;   //!
   TBranch        *b_lep_truthParentOrigin_1;   //!
   TBranch        *b_lep_truthParentPdgId_1;   //!
   TBranch        *b_lep_truthParentStatus_1;   //!
   TBranch        *b_lep_truthPt_1;   //!
   TBranch        *b_lep_truthEta_1;   //!
   TBranch        *b_lep_truthPhi_1;   //!
   TBranch        *b_lep_truthM_1;   //!
   TBranch        *b_lep_truthE_1;   //!
   TBranch        *b_lep_truthRapidity_1;   //!
   TBranch        *b_lep_ambiguityType_1;   //!
   TBranch        *b_lep_nInnerPix_1;   //!
   TBranch        *b_lep_firstEgMotherPdgId_1;   //!
   TBranch        *b_lep_firstEgMotherTruthType_1;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_lastEgMotherPdgId_1;   //!
   TBranch        *b_lep_lastEgMotherTruthType_1;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_1;   //!
   TBranch        *b_lep_SF_El_Reco_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_1;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_1;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_1;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_1;   //!
   TBranch        *b_lep_SF_CombinedLoose_1;   //!
   TBranch        *b_lep_SF_CombinedTight_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isMediumLH_2;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isTight_2;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isLoose_2;   //!
   TBranch        *b_lep_isolationFCTight_2;   //!
   TBranch        *b_lep_isolationFCLoose_2;   //!
   TBranch        *b_lep_plvWP_Loose_2;   //!
   TBranch        *b_lep_plvWP_Tight_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;   //!
   TBranch        *b_lep_isPrompt_2;   //!
   TBranch        *b_lep_isFakeLep_2;   //!
   TBranch        *b_lep_isQMisID_2;   //!
   TBranch        *b_lep_isConvPh_2;   //!
   TBranch        *b_lep_isExtConvPh_2;   //!
   TBranch        *b_lep_isIntConvPh_2;   //!
   TBranch        *b_lep_isISR_FSR_Ph_2;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_nTrackParticles_2;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_2;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_2;   //!
   TBranch        *b_lep_RadiusCO_2;   //!
   TBranch        *b_lep_RadiusCOX_2;   //!
   TBranch        *b_lep_RadiusCOY_2;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_2;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_2;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_2;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_2;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_TrackJetNTrack_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelPt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_RelCaloClusterE_2;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_truthStatus_2;   //!
   TBranch        *b_lep_truthParentType_2;   //!
   TBranch        *b_lep_truthParentOrigin_2;   //!
   TBranch        *b_lep_truthParentPdgId_2;   //!
   TBranch        *b_lep_truthParentStatus_2;   //!
   TBranch        *b_lep_truthPt_2;   //!
   TBranch        *b_lep_truthEta_2;   //!
   TBranch        *b_lep_truthPhi_2;   //!
   TBranch        *b_lep_truthM_2;   //!
   TBranch        *b_lep_truthE_2;   //!
   TBranch        *b_lep_truthRapidity_2;   //!
   TBranch        *b_lep_ambiguityType_2;   //!
   TBranch        *b_lep_nInnerPix_2;   //!
   TBranch        *b_lep_firstEgMotherPdgId_2;   //!
   TBranch        *b_lep_firstEgMotherTruthType_2;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_lastEgMotherPdgId_2;   //!
   TBranch        *b_lep_lastEgMotherTruthType_2;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_2;   //!
   TBranch        *b_lep_SF_El_Reco_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_2;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_2;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_2;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_2;   //!
   TBranch        *b_lep_SF_CombinedLoose_2;   //!
   TBranch        *b_lep_SF_CombinedTight_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isolationFCLoose_3;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_3;   //!
   TBranch        *b_lep_SF_El_Reco_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_3;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_3;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_3;   //!
   TBranch        *b_lep_SF_CombinedLoose_3;   //!
   TBranch        *b_lep_SF_CombinedTight_3;   //!
   TBranch        *b_flag_JetCleaning_LooseBad;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigSF_LooseID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigMatch_LooseID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLT;   //!
   TBranch        *b_custTrigMatch_TightElMediumMuID_FCLooseIso_DLT;   //!
   TBranch        *b_GlobalTrigDecision_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_GlobalTrigDecision_2e17_lhvloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_2e24_lhvloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_e120_lhloose;   //!
   TBranch        *b_GlobalTrigDecision_e140_lhloose_nod0;   //!
   TBranch        *b_GlobalTrigDecision_e17_lhloose_mu14;   //!
   TBranch        *b_GlobalTrigDecision_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_GlobalTrigDecision_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_GlobalTrigDecision_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_GlobalTrigDecision_e60_lhmedium;   //!
   TBranch        *b_GlobalTrigDecision_e60_lhmedium_nod0;   //!
   TBranch        *b_GlobalTrigDecision_mu18_mu8noL1;   //!
   TBranch        *b_GlobalTrigDecision_mu20_iloose_L1MU15;   //!
   TBranch        *b_GlobalTrigDecision_mu22_mu8noL1;   //!
   TBranch        *b_GlobalTrigDecision_mu26_ivarmedium;   //!
   TBranch        *b_GlobalTrigDecision_mu50;   //!
   TBranch        *b_higgsDecayMode;   //!
   TBranch        *b_hhiggsDecayMode;   //!
   TBranch        *b_initial_state;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSFObjChannelCombined;   //!
   TBranch        *b_jvtSF_customOR;   //!
   TBranch        *b_fjvtSF_customOR;   //!
   TBranch        *b_bTagSF_weight_DL1r_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_70;   //!
   TBranch        *b_bTagSF_weight_DL1r_77;   //!
   TBranch        *b_bTagSF_weight_DL1r_85;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous;   //!

   VLLg(char *file_name, TChain *tree=0);
   virtual ~VLLg();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
};

#endif

#ifdef VLLg_cxx
VLLg::VLLg(char *file_name, TChain *tree) : fChain(0) 
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

VLLg::~VLLg()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLg::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLg::LoadTree(Long64_t entry)
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

void VLLg::Init(TTree *tree)
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

   fChain->SetBranchAddress("totalEventsWeighted", &totalEventsWeighted, &b_totalEventsWeighted);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF__1down", &totalEventsWeighted_weight_MUF__1down, &b_totalEventsWeighted_weight_MUF__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUF__1up", &totalEventsWeighted_weight_MUF__1up, &b_totalEventsWeighted_weight_MUF__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF__1down", &totalEventsWeighted_weight_MUR_MUF__1down, &b_totalEventsWeighted_weight_MUR_MUF__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR_MUF__1up", &totalEventsWeighted_weight_MUR_MUF__1up, &b_totalEventsWeighted_weight_MUR_MUF__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR__1down", &totalEventsWeighted_weight_MUR__1down, &b_totalEventsWeighted_weight_MUR__1down);
   fChain->SetBranchAddress("totalEventsWeighted_weight_MUR__1up", &totalEventsWeighted_weight_MUR__1up, &b_totalEventsWeighted_weight_MUR__1up);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF13000", &totalEventsWeighted_weight_PDF13000, &b_totalEventsWeighted_weight_PDF13000);
   fChain->SetBranchAddress("totalEventsWeighted_weight_PDF25300", &totalEventsWeighted_weight_PDF25300, &b_totalEventsWeighted_weight_PDF25300);
   fChain->SetBranchAddress("xs", &xs, &b_xs);
   fChain->SetBranchAddress("lep_pT_new_1", &lep_pT_new_1, &b_lep_pT_new_1);
   fChain->SetBranchAddress("lep_pT_new_2", &lep_pT_new_2, &b_lep_pT_new_2);
   fChain->SetBranchAddress("lep_eta_new_1", &lep_eta_new_1, &b_lep_eta_new_1);
   fChain->SetBranchAddress("lep_eta_new_2", &lep_eta_new_2, &b_lep_eta_new_2);
   fChain->SetBranchAddress("jet_pt0", &jet_pt0, &b_jet_pt0);
   fChain->SetBranchAddress("jet_eta0", &jet_eta0, &b_jet_eta0);
   fChain->SetBranchAddress("jet_pt1", &jet_pt1, &b_jet_pt1);
   fChain->SetBranchAddress("jet_eta1", &jet_eta1, &b_jet_eta1);
   fChain->SetBranchAddress("jet_pt2", &jet_pt2, &b_jet_pt2);
   fChain->SetBranchAddress("jet_eta2", &jet_eta2, &b_jet_eta2);
   fChain->SetBranchAddress("DeltaR_min_lep_jet", &DeltaR_min_lep_jet, &b_DeltaR_min_lep_jet);
   fChain->SetBranchAddress("DeltaR_min_lep_jet_fwd", &DeltaR_min_lep_jet_fwd, &b_DeltaR_min_lep_jet_fwd);
   fChain->SetBranchAddress("minDeltaR_LJ_0", &minDeltaR_LJ_0, &b_minDeltaR_LJ_0);
   fChain->SetBranchAddress("minDeltaR_LJ_1", &minDeltaR_LJ_1, &b_minDeltaR_LJ_1);
   fChain->SetBranchAddress("minDeltaR_LJ_2", &minDeltaR_LJ_2, &b_minDeltaR_LJ_2);
   fChain->SetBranchAddress("bjet_pt0", &bjet_pt0, &b_bjet_pt0);
   fChain->SetBranchAddress("bjet_eta0", &bjet_eta0, &b_bjet_eta0);
   fChain->SetBranchAddress("HT_vis_min", &HT_vis_min, &b_HT_vis_min);
   fChain->SetBranchAddress("HT_vis", &HT_vis, &b_HT_vis);
   fChain->SetBranchAddress("Mlb", &Mlb, &b_Mlb);
   fChain->SetBranchAddress("DRlb", &DRlb, &b_DRlb);
   fChain->SetBranchAddress("DeltaR_max_lep_bjet77", &DeltaR_max_lep_bjet77, &b_DeltaR_max_lep_bjet77);
   fChain->SetBranchAddress("DeltaR_min_lep_bjet77", &DeltaR_min_lep_bjet77, &b_DeltaR_min_lep_bjet77);
   fChain->SetBranchAddress("RecoLepTopMass85", &RecoLepTopMass85, &b_RecoLepTopMass85);
   fChain->SetBranchAddress("RecoLepTopMass77", &RecoLepTopMass77, &b_RecoLepTopMass77);
   fChain->SetBranchAddress("RecoLepTopMass70", &RecoLepTopMass70, &b_RecoLepTopMass70);
   fChain->SetBranchAddress("RecoLepTopMass60", &RecoLepTopMass60, &b_RecoLepTopMass60);
   fChain->SetBranchAddress("Mbblead", &Mbblead, &b_Mbblead);
   fChain->SetBranchAddress("MLepMet", &MLepMet, &b_MLepMet);
   fChain->SetBranchAddress("MtLepMet", &MtLepMet, &b_MtLepMet);
   fChain->SetBranchAddress("MtLep0Met", &MtLep0Met, &b_MtLep0Met);
   fChain->SetBranchAddress("mjjMax_frwdJet", &mjjMax_frwdJet, &b_mjjMax_frwdJet);
   fChain->SetBranchAddress("DRjj_lead", &DRjj_lead, &b_DRjj_lead);
   fChain->SetBranchAddress("mjj_lead", &mjj_lead, &b_mjj_lead);
   fChain->SetBranchAddress("mjjj_lead", &mjjj_lead, &b_mjjj_lead);
   fChain->SetBranchAddress("eta_frwdjet", &eta_frwdjet, &b_eta_frwdjet);
   fChain->SetBranchAddress("dEta_maxMjj_frwdjet", &dEta_maxMjj_frwdjet, &b_dEta_maxMjj_frwdjet);
   fChain->SetBranchAddress("lep_flavour", &lep_flavour, &b_lep_flavour);
   fChain->SetBranchAddress("max_eta", &max_eta, &b_max_eta);
   fChain->SetBranchAddress("DEtall_SS", &DEtall_SS, &b_DEtall_SS);
   fChain->SetBranchAddress("DEtall_OS_0", &DEtall_OS_0, &b_DEtall_OS_0);
   fChain->SetBranchAddress("DEtall_OS_1", &DEtall_OS_1, &b_DEtall_OS_1);
   fChain->SetBranchAddress("DPhill_SS", &DPhill_SS, &b_DPhill_SS);
   fChain->SetBranchAddress("DPhill_OS_0", &DPhill_OS_0, &b_DPhill_OS_0);
   fChain->SetBranchAddress("DPhill_OS_1", &DPhill_OS_1, &b_DPhill_OS_1);
   fChain->SetBranchAddress("Mll_SS", &Mll_SS, &b_Mll_SS);
   fChain->SetBranchAddress("Mll_OS_0", &Mll_OS_0, &b_Mll_OS_0);
   fChain->SetBranchAddress("Mll_OS_1", &Mll_OS_1, &b_Mll_OS_1);
   fChain->SetBranchAddress("passPLIVTight_0", &passPLIVTight_0, &b_passPLIVTight_0);
   fChain->SetBranchAddress("passPLIVVeryTight_0", &passPLIVVeryTight_0, &b_passPLIVVeryTight_0);
   fChain->SetBranchAddress("passPLIVTight_1", &passPLIVTight_1, &b_passPLIVTight_1);
   fChain->SetBranchAddress("passPLIVVeryTight_1", &passPLIVVeryTight_1, &b_passPLIVVeryTight_1);
   fChain->SetBranchAddress("passPLIVTight_2", &passPLIVTight_2, &b_passPLIVTight_2);
   fChain->SetBranchAddress("passPLIVVeryTight_2", &passPLIVVeryTight_2, &b_passPLIVVeryTight_2);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r0", &jet_pseudoscore_DL1r0, &b_jet_pseudoscore_DL1r0);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r1", &jet_pseudoscore_DL1r1, &b_jet_pseudoscore_DL1r1);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r2", &jet_pseudoscore_DL1r2, &b_jet_pseudoscore_DL1r2);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r3", &jet_pseudoscore_DL1r3, &b_jet_pseudoscore_DL1r3);
   fChain->SetBranchAddress("jet_pseudoscore_DL1r4", &jet_pseudoscore_DL1r4, &b_jet_pseudoscore_DL1r4);
   fChain->SetBranchAddress("sumPsbtag", &sumPsbtag, &b_sumPsbtag);
   fChain->SetBranchAddress("sumPsbtag77", &sumPsbtag77, &b_sumPsbtag77);
   fChain->SetBranchAddress("jet_pt0_nofwd", &jet_pt0_nofwd, &b_jet_pt0_nofwd);
   fChain->SetBranchAddress("jet_pt1_nofwd", &jet_pt1_nofwd, &b_jet_pt1_nofwd);
   fChain->SetBranchAddress("jet_pt6_nofwd", &jet_pt6_nofwd, &b_jet_pt6_nofwd);
   fChain->SetBranchAddress("jet_pt0_nonbtag", &jet_pt0_nonbtag, &b_jet_pt0_nonbtag);
   fChain->SetBranchAddress("minDeltaR_J_bJ", &minDeltaR_J_bJ, &b_minDeltaR_J_bJ);
   fChain->SetBranchAddress("l2SS1tau", &l2SS1tau, &b_l2SS1tau);
   fChain->SetBranchAddress("IFFClass_lep_0", &IFFClass_lep_0, &b_IFFClass_lep_0);
   fChain->SetBranchAddress("IFFClass_lep_1", &IFFClass_lep_1, &b_IFFClass_lep_1);
   fChain->SetBranchAddress("IFFClass_lep_2", &IFFClass_lep_2, &b_IFFClass_lep_2);
   fChain->SetBranchAddress("ttHMLClass_lep_0", &ttHMLClass_lep_0, &b_ttHMLClass_lep_0);
   fChain->SetBranchAddress("ttHMLClass_lep_1", &ttHMLClass_lep_1, &b_ttHMLClass_lep_1);
   fChain->SetBranchAddress("ttHMLClass_lep_2", &ttHMLClass_lep_2, &b_ttHMLClass_lep_2);
   fChain->SetBranchAddress("HT_fixed", &HT_fixed, &b_HT_fixed);
   fChain->SetBranchAddress("HT_inclFwdJets_fixed", &HT_inclFwdJets_fixed, &b_HT_inclFwdJets_fixed);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_0", &lepSF_PLIV_Prompt_0, &b_lepSF_PLIV_Prompt_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_0", &lepSF_PLIV_NonPrompt_0, &b_lepSF_PLIV_NonPrompt_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalError_0", &lepSF_PLIV_Prompt_Cor_El_totalError_0, &b_lepSF_PLIV_Prompt_Cor_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalError_0", &lepSF_PLIV_NonPrompt_Cor_El_totalError_0, &b_lepSF_PLIV_NonPrompt_Cor_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalError_0", &lepSF_PLIV_NonPrompt_VeryTight_El_totalError_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_0", &lepSF_PLIV_Prompt_Tight_El_totalError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalError_0", &lepSF_PLIV_NonPrompt_Tight_El_totalError_0, &b_lepSF_PLIV_NonPrompt_Tight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalSystError_0", &lepSF_PLIV_Prompt_Cor_El_totalSystError_0, &b_lepSF_PLIV_Prompt_Cor_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalSystError_0", &lepSF_PLIV_NonPrompt_Cor_El_totalSystError_0, &b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_0", &lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_0", &lepSF_PLIV_Prompt_Tight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalSystError_0", &lepSF_PLIV_NonPrompt_Tight_El_totalSystError_0, &b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_statError_0", &lepSF_PLIV_Prompt_Cor_El_statError_0, &b_lepSF_PLIV_Prompt_Cor_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_statError_0", &lepSF_PLIV_NonPrompt_Cor_El_statError_0, &b_lepSF_PLIV_NonPrompt_Cor_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_0", &lepSF_PLIV_Prompt_VeryTight_El_statError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_statError_0", &lepSF_PLIV_NonPrompt_VeryTight_El_statError_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_0", &lepSF_PLIV_Prompt_Tight_El_statError_0, &b_lepSF_PLIV_Prompt_Tight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_statError_0", &lepSF_PLIV_NonPrompt_Tight_El_statError_0, &b_lepSF_PLIV_NonPrompt_Tight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_jetModelSyst_0", &lepSF_PLIV_Prompt_Cor_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_templateCutSyst_0", &lepSF_PLIV_Prompt_Cor_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_IDSyst_0", &lepSF_PLIV_Prompt_Cor_El_IDSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_IDSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_IDSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_0", &lepSF_PLIV_Prompt_Tight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_IDSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_IDSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_muSyst_0", &lepSF_PLIV_Prompt_Cor_El_muSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_muSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_muSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_0", &lepSF_PLIV_Prompt_Tight_El_muSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_muSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_muSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_isoSyst_0", &lepSF_PLIV_Prompt_Cor_El_isoSyst_0, &b_lepSF_PLIV_Prompt_Cor_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_isoSyst_0", &lepSF_PLIV_NonPrompt_Cor_El_isoSyst_0, &b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_0", &lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_0, &b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_0", &lepSF_PLIV_Prompt_Tight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_isoSyst_0", &lepSF_PLIV_NonPrompt_Tight_El_isoSyst_0, &b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_0", &lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_0", &lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_0", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_0", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_0", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_0", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_1", &lepSF_PLIV_Prompt_1, &b_lepSF_PLIV_Prompt_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_1", &lepSF_PLIV_NonPrompt_1, &b_lepSF_PLIV_NonPrompt_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalError_1", &lepSF_PLIV_Prompt_Cor_El_totalError_1, &b_lepSF_PLIV_Prompt_Cor_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalError_1", &lepSF_PLIV_NonPrompt_Cor_El_totalError_1, &b_lepSF_PLIV_NonPrompt_Cor_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalError_1", &lepSF_PLIV_NonPrompt_VeryTight_El_totalError_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_1", &lepSF_PLIV_Prompt_Tight_El_totalError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalError_1", &lepSF_PLIV_NonPrompt_Tight_El_totalError_1, &b_lepSF_PLIV_NonPrompt_Tight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalSystError_1", &lepSF_PLIV_Prompt_Cor_El_totalSystError_1, &b_lepSF_PLIV_Prompt_Cor_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalSystError_1", &lepSF_PLIV_NonPrompt_Cor_El_totalSystError_1, &b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_1", &lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_1", &lepSF_PLIV_Prompt_Tight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalSystError_1", &lepSF_PLIV_NonPrompt_Tight_El_totalSystError_1, &b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_statError_1", &lepSF_PLIV_Prompt_Cor_El_statError_1, &b_lepSF_PLIV_Prompt_Cor_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_statError_1", &lepSF_PLIV_NonPrompt_Cor_El_statError_1, &b_lepSF_PLIV_NonPrompt_Cor_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_1", &lepSF_PLIV_Prompt_VeryTight_El_statError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_statError_1", &lepSF_PLIV_NonPrompt_VeryTight_El_statError_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_1", &lepSF_PLIV_Prompt_Tight_El_statError_1, &b_lepSF_PLIV_Prompt_Tight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_statError_1", &lepSF_PLIV_NonPrompt_Tight_El_statError_1, &b_lepSF_PLIV_NonPrompt_Tight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_jetModelSyst_1", &lepSF_PLIV_Prompt_Cor_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_templateCutSyst_1", &lepSF_PLIV_Prompt_Cor_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_IDSyst_1", &lepSF_PLIV_Prompt_Cor_El_IDSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_IDSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_IDSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_1", &lepSF_PLIV_Prompt_Tight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_IDSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_IDSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_muSyst_1", &lepSF_PLIV_Prompt_Cor_El_muSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_muSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_muSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_1", &lepSF_PLIV_Prompt_Tight_El_muSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_muSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_muSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_isoSyst_1", &lepSF_PLIV_Prompt_Cor_El_isoSyst_1, &b_lepSF_PLIV_Prompt_Cor_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_isoSyst_1", &lepSF_PLIV_NonPrompt_Cor_El_isoSyst_1, &b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_1", &lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_1, &b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_1", &lepSF_PLIV_Prompt_Tight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_isoSyst_1", &lepSF_PLIV_NonPrompt_Tight_El_isoSyst_1, &b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_1", &lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_1", &lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_1", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_1", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_1", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_1", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_2", &lepSF_PLIV_Prompt_2, &b_lepSF_PLIV_Prompt_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_2", &lepSF_PLIV_NonPrompt_2, &b_lepSF_PLIV_NonPrompt_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalError_2", &lepSF_PLIV_Prompt_Cor_El_totalError_2, &b_lepSF_PLIV_Prompt_Cor_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalError_2", &lepSF_PLIV_NonPrompt_Cor_El_totalError_2, &b_lepSF_PLIV_NonPrompt_Cor_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalError_2", &lepSF_PLIV_NonPrompt_VeryTight_El_totalError_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_2", &lepSF_PLIV_Prompt_Tight_El_totalError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalError_2", &lepSF_PLIV_NonPrompt_Tight_El_totalError_2, &b_lepSF_PLIV_NonPrompt_Tight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_totalSystError_2", &lepSF_PLIV_Prompt_Cor_El_totalSystError_2, &b_lepSF_PLIV_Prompt_Cor_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_totalSystError_2", &lepSF_PLIV_NonPrompt_Cor_El_totalSystError_2, &b_lepSF_PLIV_NonPrompt_Cor_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_2", &lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_2", &lepSF_PLIV_Prompt_Tight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_totalSystError_2", &lepSF_PLIV_NonPrompt_Tight_El_totalSystError_2, &b_lepSF_PLIV_NonPrompt_Tight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_statError_2", &lepSF_PLIV_Prompt_Cor_El_statError_2, &b_lepSF_PLIV_Prompt_Cor_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_statError_2", &lepSF_PLIV_NonPrompt_Cor_El_statError_2, &b_lepSF_PLIV_NonPrompt_Cor_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_2", &lepSF_PLIV_Prompt_VeryTight_El_statError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_statError_2", &lepSF_PLIV_NonPrompt_VeryTight_El_statError_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_2", &lepSF_PLIV_Prompt_Tight_El_statError_2, &b_lepSF_PLIV_Prompt_Tight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_statError_2", &lepSF_PLIV_NonPrompt_Tight_El_statError_2, &b_lepSF_PLIV_NonPrompt_Tight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_jetModelSyst_2", &lepSF_PLIV_Prompt_Cor_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_templateCutSyst_2", &lepSF_PLIV_Prompt_Cor_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_IDSyst_2", &lepSF_PLIV_Prompt_Cor_El_IDSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_IDSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_IDSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_2", &lepSF_PLIV_Prompt_Tight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_IDSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_IDSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_muSyst_2", &lepSF_PLIV_Prompt_Cor_El_muSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_muSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_muSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_2", &lepSF_PLIV_Prompt_Tight_El_muSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_muSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_muSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_El_isoSyst_2", &lepSF_PLIV_Prompt_Cor_El_isoSyst_2, &b_lepSF_PLIV_Prompt_Cor_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_El_isoSyst_2", &lepSF_PLIV_NonPrompt_Cor_El_isoSyst_2, &b_lepSF_PLIV_NonPrompt_Cor_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_2", &lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_2, &b_lepSF_PLIV_NonPrompt_VeryTight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_2", &lepSF_PLIV_Prompt_Tight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_El_isoSyst_2", &lepSF_PLIV_NonPrompt_Tight_El_isoSyst_2, &b_lepSF_PLIV_NonPrompt_Tight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_Cor_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_2", &lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_Cor_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_2", &lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_2", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_2", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_Cor_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_2", &lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_2", &lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_Cor_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_NonPrompt_Cor_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_NonPrompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_NonPrompt_Tight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("weight_MUF__1up", &weight_MUF__1up, &b_weight_MUF__1up);
   fChain->SetBranchAddress("weight_MUR_MUF__1up", &weight_MUR_MUF__1up, &b_weight_MUR_MUF__1up);
   fChain->SetBranchAddress("weight_MUR__1up", &weight_MUR__1up, &b_weight_MUR__1up);
   fChain->SetBranchAddress("weight_PDF13000", &weight_PDF13000, &b_weight_PDF13000);
   fChain->SetBranchAddress("weight_MUR__1down", &weight_MUR__1down, &b_weight_MUR__1down);
   fChain->SetBranchAddress("weight_MUR_MUF__1down", &weight_MUR_MUF__1down, &b_weight_MUR_MUF__1down);
   fChain->SetBranchAddress("weight_PDF25300", &weight_PDF25300, &b_weight_PDF25300);
   fChain->SetBranchAddress("weight_MUF__1down", &weight_MUF__1down, &b_weight_MUF__1down);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_jvt__1up", &weight_jvt__1up, &b_weight_jvt__1up);
   fChain->SetBranchAddress("weight_jvt__1down", &weight_jvt__1down, &b_weight_jvt__1down);
   fChain->SetBranchAddress("weight_fjvt", &weight_fjvt, &b_weight_fjvt);
   fChain->SetBranchAddress("weight_fjvt__1up", &weight_fjvt__1up, &b_weight_fjvt__1up);
   fChain->SetBranchAddress("weight_fjvt__1down", &weight_fjvt__1down, &b_weight_fjvt__1down);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Reco_UP_AT", &weight_leptonSF_El_Reco_UP_AT, &b_weight_leptonSF_El_Reco_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Reco_DOWN_AT", &weight_leptonSF_El_Reco_DOWN_AT, &b_weight_leptonSF_El_Reco_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT", &weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT, &b_weight_leptonSF_El_ID_LooseAndBLayerLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_TightLH_UP_AT", &weight_leptonSF_El_ID_TightLH_UP_AT, &b_weight_leptonSF_El_ID_TightLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT", &weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT, &b_weight_leptonSF_El_ID_LooseAndBLayerLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_ID_TightLH_DOWN_AT", &weight_leptonSF_El_ID_TightLH_DOWN_AT, &b_weight_leptonSF_El_ID_TightLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Iso_FCLoose_UP_AT", &weight_leptonSF_El_Iso_FCLoose_UP_AT, &b_weight_leptonSF_El_Iso_FCLoose_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_El_Iso_FCLoose_DOWN_AT", &weight_leptonSF_El_Iso_FCLoose_DOWN_AT, &b_weight_leptonSF_El_Iso_FCLoose_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_STAT_UP_AT", &weight_leptonSF_Mu_TTVA_STAT_UP_AT, &b_weight_leptonSF_Mu_TTVA_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_STAT_DOWN_AT", &weight_leptonSF_Mu_TTVA_STAT_DOWN_AT, &b_weight_leptonSF_Mu_TTVA_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_SYST_UP_AT", &weight_leptonSF_Mu_TTVA_SYST_UP_AT, &b_weight_leptonSF_Mu_TTVA_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_TTVA_SYST_DOWN_AT", &weight_leptonSF_Mu_TTVA_SYST_DOWN_AT, &b_weight_leptonSF_Mu_TTVA_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_UP_AT", &weight_leptonSF_Mu_ID_Loose_STAT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_UP_AT", &weight_leptonSF_Mu_ID_Medium_STAT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_UP_AT", &weight_leptonSF_Mu_ID_Loose_SYST_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_UP_AT", &weight_leptonSF_Mu_ID_Medium_SYST_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT", &weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Loose_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT", &weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_Mu_ID_Medium_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT", &weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT", &weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT", &weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT", &weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_Mu_Iso_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF", &weight_globalLeptonTriggerSF, &b_weight_globalLeptonTriggerSF);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down);
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
   fChain->SetBranchAddress("m_HF_Classification", &m_HF_Classification, &b_m_HF_Classification);
   fChain->SetBranchAddress("m_HF_ClassificationTop", &m_HF_ClassificationTop, &b_m_HF_ClassificationTop);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_pileup_UP", &weight_pileup_UP, &b_weight_pileup_UP);
   fChain->SetBranchAddress("weight_pileup_DOWN", &weight_pileup_DOWN, &b_weight_pileup_DOWN);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("mu_actual", &mu_actual, &b_mu_actual);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH, &b_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_2e17_lhvloose_nod0", &HLT_2e17_lhvloose_nod0, &b_HLT_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("onelep_type", &onelep_type, &b_onelep_type);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   fChain->SetBranchAddress("Ptll01", &Ptll01, &b_Ptll01);
   fChain->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   fChain->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   fChain->SetBranchAddress("Mllll0123", &Mllll0123, &b_Mllll0123);
   fChain->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   fChain->SetBranchAddress("Ptll02", &Ptll02, &b_Ptll02);
   fChain->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   fChain->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   fChain->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   fChain->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   fChain->SetBranchAddress("Ptll12", &Ptll12, &b_Ptll12);
   fChain->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   fChain->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   fChain->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   fChain->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   fChain->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   fChain->SetBranchAddress("best_Z_Mll", &best_Z_Mll, &b_best_Z_Mll);
   fChain->SetBranchAddress("best_Z_other_MtLepMet", &best_Z_other_MtLepMet, &b_best_Z_other_MtLepMet);
   fChain->SetBranchAddress("best_Z_other_Mll", &best_Z_other_Mll, &b_best_Z_other_Mll);
   fChain->SetBranchAddress("minOSSFMll", &minOSSFMll, &b_minOSSFMll);
   fChain->SetBranchAddress("minOSMll", &minOSMll, &b_minOSMll);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("nJets_OR_TauOR", &nJets_OR_TauOR, &b_nJets_OR_TauOR);
   fChain->SetBranchAddress("nFwdJets_OR", &nFwdJets_OR, &b_nFwdJets_OR);
   fChain->SetBranchAddress("nFwdJets_OR_TauOR", &nFwdJets_OR_TauOR, &b_nFwdJets_OR_TauOR);
   fChain->SetBranchAddress("nJets_OR_DL1r_85", &nJets_OR_DL1r_85, &b_nJets_OR_DL1r_85);
   fChain->SetBranchAddress("nJets_OR_DL1r_60", &nJets_OR_DL1r_60, &b_nJets_OR_DL1r_60);
   fChain->SetBranchAddress("nJets_OR_DL1r_77", &nJets_OR_DL1r_77, &b_nJets_OR_DL1r_77);
   fChain->SetBranchAddress("nJets_OR_DL1r_70", &nJets_OR_DL1r_70, &b_nJets_OR_DL1r_70);
   fChain->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25, &b_nTaus_OR_Pt25);
   fChain->SetBranchAddress("nTaus_OR", &nTaus_OR, &b_nTaus_OR);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT_inclFwdJets", &HT_inclFwdJets, &b_HT_inclFwdJets);
   fChain->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("HT_fwdJets", &HT_fwdJets, &b_HT_fwdJets);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   fChain->SetBranchAddress("lep_isolationFCTight_0", &lep_isolationFCTight_0, &b_lep_isolationFCTight_0);
   fChain->SetBranchAddress("lep_isolationFCLoose_0", &lep_isolationFCLoose_0, &b_lep_isolationFCLoose_0);
   fChain->SetBranchAddress("lep_plvWP_Loose_0", &lep_plvWP_Loose_0, &b_lep_plvWP_Loose_0);
   fChain->SetBranchAddress("lep_plvWP_Tight_0", &lep_plvWP_Tight_0, &b_lep_plvWP_Tight_0);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_0", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_0, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0);
   fChain->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   fChain->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   fChain->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
   fChain->SetBranchAddress("lep_isExtConvPh_0", &lep_isExtConvPh_0, &b_lep_isExtConvPh_0);
   fChain->SetBranchAddress("lep_isIntConvPh_0", &lep_isIntConvPh_0, &b_lep_isIntConvPh_0);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   fChain->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   fChain->SetBranchAddress("lep_nTrackParticles_0", &lep_nTrackParticles_0, &b_lep_nTrackParticles_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_0", &lep_Mtrktrk_atPV_CO_0, &b_lep_Mtrktrk_atPV_CO_0);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_0", &lep_Mtrktrk_atConvV_CO_0, &b_lep_Mtrktrk_atConvV_CO_0);
   fChain->SetBranchAddress("lep_RadiusCO_0", &lep_RadiusCO_0, &b_lep_RadiusCO_0);
   fChain->SetBranchAddress("lep_RadiusCOX_0", &lep_RadiusCOX_0, &b_lep_RadiusCOX_0);
   fChain->SetBranchAddress("lep_RadiusCOY_0", &lep_RadiusCOY_0, &b_lep_RadiusCOY_0);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_0", &lep_DFCommonAddAmbiguity_0, &b_lep_DFCommonAddAmbiguity_0);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_0", &lep_DFCommonProdTrueRadius_0, &b_lep_DFCommonProdTrueRadius_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_0", &lep_chargeIDBDTResult_0, &b_lep_chargeIDBDTResult_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_0", &lep_chargeIDBDTResult_recalc_rel207_tight_0, &b_lep_chargeIDBDTResult_recalc_rel207_tight_0);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_0", &lep_promptLeptonVeto_TagWeight_0, &b_lep_promptLeptonVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_0", &lep_promptLeptonImprovedVeto_TagWeight_0, &b_lep_promptLeptonImprovedVeto_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_0", &lep_promptLeptonImprovedVetoBARR_TagWeight_0, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_0);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_0", &lep_promptLeptonImprovedVetoECAP_TagWeight_0, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_0", &lep_PromptLeptonImprovedInput_MVAXBin_0, &b_lep_PromptLeptonImprovedInput_MVAXBin_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_0", &lep_PromptLeptonImprovedInput_PtFrac_0, &b_lep_PromptLeptonImprovedInput_PtFrac_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_0", &lep_PromptLeptonImprovedInput_DRlj_0, &b_lep_PromptLeptonImprovedInput_DRlj_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_0", &lep_PromptLeptonImprovedInput_reltopoetcone30_0, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_0", &lep_PromptLeptonImprovedInput_relptvarcone30_0, &b_lep_PromptLeptonImprovedInput_relptvarcone30_0);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_0", &lep_PromptLeptonRNN_prompt_0, &b_lep_PromptLeptonRNN_prompt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_0", &lep_PromptLeptonImprovedInput_TrackJetNTrack_0, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_0", &lep_PromptLeptonImprovedInput_RelPt_0, &b_lep_PromptLeptonImprovedInput_RelPt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_0", &lep_PromptLeptonImprovedInput_RelCaloClusterE_0, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_0);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_0);
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   fChain->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   fChain->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   fChain->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   fChain->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   fChain->SetBranchAddress("lep_truthPt_0", &lep_truthPt_0, &b_lep_truthPt_0);
   fChain->SetBranchAddress("lep_truthEta_0", &lep_truthEta_0, &b_lep_truthEta_0);
   fChain->SetBranchAddress("lep_truthPhi_0", &lep_truthPhi_0, &b_lep_truthPhi_0);
   fChain->SetBranchAddress("lep_truthM_0", &lep_truthM_0, &b_lep_truthM_0);
   fChain->SetBranchAddress("lep_truthE_0", &lep_truthE_0, &b_lep_truthE_0);
   fChain->SetBranchAddress("lep_truthRapidity_0", &lep_truthRapidity_0, &b_lep_truthRapidity_0);
   fChain->SetBranchAddress("lep_ambiguityType_0", &lep_ambiguityType_0, &b_lep_ambiguityType_0);
   fChain->SetBranchAddress("lep_nInnerPix_0", &lep_nInnerPix_0, &b_lep_nInnerPix_0);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_0", &lep_firstEgMotherPdgId_0, &b_lep_firstEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_0", &lep_firstEgMotherTruthType_0, &b_lep_firstEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_0", &lep_firstEgMotherTruthOrigin_0, &b_lep_firstEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_0", &lep_lastEgMotherPdgId_0, &b_lep_lastEgMotherPdgId_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_0", &lep_lastEgMotherTruthType_0, &b_lep_lastEgMotherTruthType_0);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_0", &lep_lastEgMotherTruthOrigin_0, &b_lep_lastEgMotherTruthOrigin_0);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_0", &lep_SF_El_Reco_AT_0, &b_lep_SF_El_Reco_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_0", &lep_SF_El_ID_LooseAndBLayerLH_AT_0, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_0", &lep_SF_El_ID_TightLH_AT_0, &b_lep_SF_El_ID_TightLH_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_0", &lep_SF_El_Iso_FCLoose_TightLH_0, &b_lep_SF_El_Iso_FCLoose_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_0", &lep_SF_El_ID_MediumLH_0, &b_lep_SF_El_ID_MediumLH_0);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_0", &lep_SF_Mu_TTVA_AT_0, &b_lep_SF_Mu_TTVA_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_0", &lep_SF_Mu_ID_Loose_AT_0, &b_lep_SF_Mu_ID_Loose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_0", &lep_SF_Mu_ID_Medium_AT_0, &b_lep_SF_Mu_ID_Medium_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_0", &lep_SF_Mu_Iso_FCLoose_AT_0, &b_lep_SF_Mu_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_0", &lep_SF_Mu_ID_Tight_0, &b_lep_SF_Mu_ID_Tight_0);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_0", &lep_SF_CombinedLoose_0, &b_lep_SF_CombinedLoose_0);
   fChain->SetBranchAddress("lep_SF_CombinedTight_0", &lep_SF_CombinedTight_0, &b_lep_SF_CombinedTight_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   fChain->SetBranchAddress("lep_isolationFCTight_1", &lep_isolationFCTight_1, &b_lep_isolationFCTight_1);
   fChain->SetBranchAddress("lep_isolationFCLoose_1", &lep_isolationFCLoose_1, &b_lep_isolationFCLoose_1);
   fChain->SetBranchAddress("lep_plvWP_Loose_1", &lep_plvWP_Loose_1, &b_lep_plvWP_Loose_1);
   fChain->SetBranchAddress("lep_plvWP_Tight_1", &lep_plvWP_Tight_1, &b_lep_plvWP_Tight_1);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_1", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_1, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1);
   fChain->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   fChain->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   fChain->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
   fChain->SetBranchAddress("lep_isExtConvPh_1", &lep_isExtConvPh_1, &b_lep_isExtConvPh_1);
   fChain->SetBranchAddress("lep_isIntConvPh_1", &lep_isIntConvPh_1, &b_lep_isIntConvPh_1);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   fChain->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   fChain->SetBranchAddress("lep_nTrackParticles_1", &lep_nTrackParticles_1, &b_lep_nTrackParticles_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_1", &lep_Mtrktrk_atPV_CO_1, &b_lep_Mtrktrk_atPV_CO_1);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_1", &lep_Mtrktrk_atConvV_CO_1, &b_lep_Mtrktrk_atConvV_CO_1);
   fChain->SetBranchAddress("lep_RadiusCO_1", &lep_RadiusCO_1, &b_lep_RadiusCO_1);
   fChain->SetBranchAddress("lep_RadiusCOX_1", &lep_RadiusCOX_1, &b_lep_RadiusCOX_1);
   fChain->SetBranchAddress("lep_RadiusCOY_1", &lep_RadiusCOY_1, &b_lep_RadiusCOY_1);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_1", &lep_DFCommonAddAmbiguity_1, &b_lep_DFCommonAddAmbiguity_1);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_1", &lep_DFCommonProdTrueRadius_1, &b_lep_DFCommonProdTrueRadius_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_1", &lep_chargeIDBDTResult_1, &b_lep_chargeIDBDTResult_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_1", &lep_chargeIDBDTResult_recalc_rel207_tight_1, &b_lep_chargeIDBDTResult_recalc_rel207_tight_1);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_1", &lep_promptLeptonVeto_TagWeight_1, &b_lep_promptLeptonVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_1", &lep_promptLeptonImprovedVeto_TagWeight_1, &b_lep_promptLeptonImprovedVeto_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_1", &lep_promptLeptonImprovedVetoBARR_TagWeight_1, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_1);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_1", &lep_promptLeptonImprovedVetoECAP_TagWeight_1, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_1", &lep_PromptLeptonImprovedInput_MVAXBin_1, &b_lep_PromptLeptonImprovedInput_MVAXBin_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_1", &lep_PromptLeptonImprovedInput_PtFrac_1, &b_lep_PromptLeptonImprovedInput_PtFrac_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_1", &lep_PromptLeptonImprovedInput_DRlj_1, &b_lep_PromptLeptonImprovedInput_DRlj_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_1", &lep_PromptLeptonImprovedInput_reltopoetcone30_1, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_1", &lep_PromptLeptonImprovedInput_relptvarcone30_1, &b_lep_PromptLeptonImprovedInput_relptvarcone30_1);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_1", &lep_PromptLeptonRNN_prompt_1, &b_lep_PromptLeptonRNN_prompt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_1", &lep_PromptLeptonImprovedInput_TrackJetNTrack_1, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_1", &lep_PromptLeptonImprovedInput_RelPt_1, &b_lep_PromptLeptonImprovedInput_RelPt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_1", &lep_PromptLeptonImprovedInput_RelCaloClusterE_1, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_1);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_1);
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   fChain->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   fChain->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   fChain->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   fChain->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   fChain->SetBranchAddress("lep_truthPt_1", &lep_truthPt_1, &b_lep_truthPt_1);
   fChain->SetBranchAddress("lep_truthEta_1", &lep_truthEta_1, &b_lep_truthEta_1);
   fChain->SetBranchAddress("lep_truthPhi_1", &lep_truthPhi_1, &b_lep_truthPhi_1);
   fChain->SetBranchAddress("lep_truthM_1", &lep_truthM_1, &b_lep_truthM_1);
   fChain->SetBranchAddress("lep_truthE_1", &lep_truthE_1, &b_lep_truthE_1);
   fChain->SetBranchAddress("lep_truthRapidity_1", &lep_truthRapidity_1, &b_lep_truthRapidity_1);
   fChain->SetBranchAddress("lep_ambiguityType_1", &lep_ambiguityType_1, &b_lep_ambiguityType_1);
   fChain->SetBranchAddress("lep_nInnerPix_1", &lep_nInnerPix_1, &b_lep_nInnerPix_1);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_1", &lep_firstEgMotherPdgId_1, &b_lep_firstEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_1", &lep_firstEgMotherTruthType_1, &b_lep_firstEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_1", &lep_firstEgMotherTruthOrigin_1, &b_lep_firstEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_1", &lep_lastEgMotherPdgId_1, &b_lep_lastEgMotherPdgId_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_1", &lep_lastEgMotherTruthType_1, &b_lep_lastEgMotherTruthType_1);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_1", &lep_lastEgMotherTruthOrigin_1, &b_lep_lastEgMotherTruthOrigin_1);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_1", &lep_SF_El_Reco_AT_1, &b_lep_SF_El_Reco_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_1", &lep_SF_El_ID_LooseAndBLayerLH_AT_1, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_1", &lep_SF_El_ID_TightLH_AT_1, &b_lep_SF_El_ID_TightLH_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_1", &lep_SF_El_Iso_FCLoose_TightLH_1, &b_lep_SF_El_Iso_FCLoose_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_1", &lep_SF_El_ID_MediumLH_1, &b_lep_SF_El_ID_MediumLH_1);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_1", &lep_SF_Mu_TTVA_AT_1, &b_lep_SF_Mu_TTVA_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_1", &lep_SF_Mu_ID_Loose_AT_1, &b_lep_SF_Mu_ID_Loose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_1", &lep_SF_Mu_ID_Medium_AT_1, &b_lep_SF_Mu_ID_Medium_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_1", &lep_SF_Mu_Iso_FCLoose_AT_1, &b_lep_SF_Mu_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_1", &lep_SF_Mu_ID_Tight_1, &b_lep_SF_Mu_ID_Tight_1);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_1", &lep_SF_CombinedLoose_1, &b_lep_SF_CombinedLoose_1);
   fChain->SetBranchAddress("lep_SF_CombinedTight_1", &lep_SF_CombinedTight_1, &b_lep_SF_CombinedTight_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   fChain->SetBranchAddress("lep_isolationFCTight_2", &lep_isolationFCTight_2, &b_lep_isolationFCTight_2);
   fChain->SetBranchAddress("lep_isolationFCLoose_2", &lep_isolationFCLoose_2, &b_lep_isolationFCLoose_2);
   fChain->SetBranchAddress("lep_plvWP_Loose_2", &lep_plvWP_Loose_2, &b_lep_plvWP_Loose_2);
   fChain->SetBranchAddress("lep_plvWP_Tight_2", &lep_plvWP_Tight_2, &b_lep_plvWP_Tight_2);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_2", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_2, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2);
   fChain->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   fChain->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   fChain->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   fChain->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   fChain->SetBranchAddress("lep_isExtConvPh_2", &lep_isExtConvPh_2, &b_lep_isExtConvPh_2);
   fChain->SetBranchAddress("lep_isIntConvPh_2", &lep_isIntConvPh_2, &b_lep_isIntConvPh_2);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_nTrackParticles_2", &lep_nTrackParticles_2, &b_lep_nTrackParticles_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_2", &lep_Mtrktrk_atPV_CO_2, &b_lep_Mtrktrk_atPV_CO_2);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_2", &lep_Mtrktrk_atConvV_CO_2, &b_lep_Mtrktrk_atConvV_CO_2);
   fChain->SetBranchAddress("lep_RadiusCO_2", &lep_RadiusCO_2, &b_lep_RadiusCO_2);
   fChain->SetBranchAddress("lep_RadiusCOX_2", &lep_RadiusCOX_2, &b_lep_RadiusCOX_2);
   fChain->SetBranchAddress("lep_RadiusCOY_2", &lep_RadiusCOY_2, &b_lep_RadiusCOY_2);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_2", &lep_DFCommonAddAmbiguity_2, &b_lep_DFCommonAddAmbiguity_2);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_2", &lep_DFCommonProdTrueRadius_2, &b_lep_DFCommonProdTrueRadius_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_2", &lep_chargeIDBDTResult_2, &b_lep_chargeIDBDTResult_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_2", &lep_chargeIDBDTResult_recalc_rel207_tight_2, &b_lep_chargeIDBDTResult_recalc_rel207_tight_2);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_2", &lep_promptLeptonVeto_TagWeight_2, &b_lep_promptLeptonVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_2", &lep_promptLeptonImprovedVeto_TagWeight_2, &b_lep_promptLeptonImprovedVeto_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_2", &lep_promptLeptonImprovedVetoBARR_TagWeight_2, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_2);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_2", &lep_promptLeptonImprovedVetoECAP_TagWeight_2, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_2", &lep_PromptLeptonImprovedInput_MVAXBin_2, &b_lep_PromptLeptonImprovedInput_MVAXBin_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_2", &lep_PromptLeptonImprovedInput_PtFrac_2, &b_lep_PromptLeptonImprovedInput_PtFrac_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_2", &lep_PromptLeptonImprovedInput_DRlj_2, &b_lep_PromptLeptonImprovedInput_DRlj_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_2", &lep_PromptLeptonImprovedInput_reltopoetcone30_2, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_2", &lep_PromptLeptonImprovedInput_relptvarcone30_2, &b_lep_PromptLeptonImprovedInput_relptvarcone30_2);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_2", &lep_PromptLeptonRNN_prompt_2, &b_lep_PromptLeptonRNN_prompt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_TrackJetNTrack_2", &lep_PromptLeptonImprovedInput_TrackJetNTrack_2, &b_lep_PromptLeptonImprovedInput_TrackJetNTrack_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelPt_2", &lep_PromptLeptonImprovedInput_RelPt_2, &b_lep_PromptLeptonImprovedInput_RelPt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2", &lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2, &b_lep_PromptLeptonImprovedInput_RelCaloClusterSumEt_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_ThetaCutVtx_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2", &lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2, &b_lep_PromptLeptonImprovedInput_ptvarcone30_TightTTVA_relpt500_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_RelCaloClusterE_2", &lep_PromptLeptonImprovedInput_RelCaloClusterE_2, &b_lep_PromptLeptonImprovedInput_RelCaloClusterE_2);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2", &lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2, &b_lep_PromptLeptonImprovedInput_CandVertex_normDistToPriVtxLongitudinalBest_2);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   fChain->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   fChain->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   fChain->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   fChain->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   fChain->SetBranchAddress("lep_truthPt_2", &lep_truthPt_2, &b_lep_truthPt_2);
   fChain->SetBranchAddress("lep_truthEta_2", &lep_truthEta_2, &b_lep_truthEta_2);
   fChain->SetBranchAddress("lep_truthPhi_2", &lep_truthPhi_2, &b_lep_truthPhi_2);
   fChain->SetBranchAddress("lep_truthM_2", &lep_truthM_2, &b_lep_truthM_2);
   fChain->SetBranchAddress("lep_truthE_2", &lep_truthE_2, &b_lep_truthE_2);
   fChain->SetBranchAddress("lep_truthRapidity_2", &lep_truthRapidity_2, &b_lep_truthRapidity_2);
   fChain->SetBranchAddress("lep_ambiguityType_2", &lep_ambiguityType_2, &b_lep_ambiguityType_2);
   fChain->SetBranchAddress("lep_nInnerPix_2", &lep_nInnerPix_2, &b_lep_nInnerPix_2);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_2", &lep_firstEgMotherPdgId_2, &b_lep_firstEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_2", &lep_firstEgMotherTruthType_2, &b_lep_firstEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_2", &lep_firstEgMotherTruthOrigin_2, &b_lep_firstEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_2", &lep_lastEgMotherPdgId_2, &b_lep_lastEgMotherPdgId_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_2", &lep_lastEgMotherTruthType_2, &b_lep_lastEgMotherTruthType_2);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_2", &lep_lastEgMotherTruthOrigin_2, &b_lep_lastEgMotherTruthOrigin_2);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_2", &lep_SF_El_Reco_AT_2, &b_lep_SF_El_Reco_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_2", &lep_SF_El_ID_LooseAndBLayerLH_AT_2, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_2", &lep_SF_El_ID_TightLH_AT_2, &b_lep_SF_El_ID_TightLH_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_2", &lep_SF_El_Iso_FCLoose_TightLH_2, &b_lep_SF_El_Iso_FCLoose_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_2", &lep_SF_El_ID_MediumLH_2, &b_lep_SF_El_ID_MediumLH_2);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_2", &lep_SF_Mu_TTVA_AT_2, &b_lep_SF_Mu_TTVA_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_2", &lep_SF_Mu_ID_Loose_AT_2, &b_lep_SF_Mu_ID_Loose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_2", &lep_SF_Mu_ID_Medium_AT_2, &b_lep_SF_Mu_ID_Medium_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_2", &lep_SF_Mu_Iso_FCLoose_AT_2, &b_lep_SF_Mu_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_2", &lep_SF_Mu_ID_Tight_2, &b_lep_SF_Mu_ID_Tight_2);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_2", &lep_SF_CombinedLoose_2, &b_lep_SF_CombinedLoose_2);
   fChain->SetBranchAddress("lep_SF_CombinedTight_2", &lep_SF_CombinedTight_2, &b_lep_SF_CombinedTight_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isolationFCLoose_3", &lep_isolationFCLoose_3, &b_lep_isolationFCLoose_3);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_3", &lep_promptLeptonVeto_TagWeight_3, &b_lep_promptLeptonVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_3", &lep_promptLeptonImprovedVeto_TagWeight_3, &b_lep_promptLeptonImprovedVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_3", &lep_promptLeptonImprovedVetoBARR_TagWeight_3, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_3", &lep_promptLeptonImprovedVetoECAP_TagWeight_3, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_3);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_3", &lep_SF_El_Reco_AT_3, &b_lep_SF_El_Reco_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_3", &lep_SF_El_ID_LooseAndBLayerLH_AT_3, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_3", &lep_SF_El_ID_TightLH_AT_3, &b_lep_SF_El_ID_TightLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_3", &lep_SF_El_Iso_FCLoose_TightLH_3, &b_lep_SF_El_Iso_FCLoose_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_3", &lep_SF_El_ID_MediumLH_3, &b_lep_SF_El_ID_MediumLH_3);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_3", &lep_SF_Mu_TTVA_AT_3, &b_lep_SF_Mu_TTVA_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_3", &lep_SF_Mu_ID_Loose_AT_3, &b_lep_SF_Mu_ID_Loose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_3", &lep_SF_Mu_ID_Medium_AT_3, &b_lep_SF_Mu_ID_Medium_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_3", &lep_SF_Mu_Iso_FCLoose_AT_3, &b_lep_SF_Mu_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_3", &lep_SF_Mu_ID_Tight_3, &b_lep_SF_Mu_ID_Tight_3);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_3", &lep_SF_CombinedLoose_3, &b_lep_SF_CombinedLoose_3);
   fChain->SetBranchAddress("lep_SF_CombinedTight_3", &lep_SF_CombinedTight_3, &b_lep_SF_CombinedTight_3);
   fChain->SetBranchAddress("flag_JetCleaning_LooseBad", &flag_JetCleaning_LooseBad, &b_flag_JetCleaning_LooseBad);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_SLTorDLT", &custTrigSF_LooseID_FCLooseIso_SLTorDLT, &b_custTrigSF_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_SLT", &custTrigSF_LooseID_FCLooseIso_SLT, &b_custTrigSF_LooseID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigSF_LooseID_FCLooseIso_DLT", &custTrigSF_LooseID_FCLooseIso_DLT, &b_custTrigSF_LooseID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_SLTorDLT", &custTrigMatch_LooseID_FCLooseIso_SLTorDLT, &b_custTrigMatch_LooseID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_SLT", &custTrigMatch_LooseID_FCLooseIso_SLT, &b_custTrigMatch_LooseID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigMatch_LooseID_FCLooseIso_DLT", &custTrigMatch_LooseID_FCLooseIso_DLT, &b_custTrigMatch_LooseID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_SLT", &custTrigSF_TightElMediumMuID_FCLooseIso_SLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigSF_TightElMediumMuID_FCLooseIso_DLT", &custTrigSF_TightElMediumMuID_FCLooseIso_DLT, &b_custTrigSF_TightElMediumMuID_FCLooseIso_DLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_SLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_SLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_SLT);
   fChain->SetBranchAddress("custTrigMatch_TightElMediumMuID_FCLooseIso_DLT", &custTrigMatch_TightElMediumMuID_FCLooseIso_DLT, &b_custTrigMatch_TightElMediumMuID_FCLooseIso_DLT);
   fChain->SetBranchAddress("GlobalTrigDecision_2e12_lhloose_L12EM10VH", &GlobalTrigDecision_2e12_lhloose_L12EM10VH, &b_GlobalTrigDecision_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("GlobalTrigDecision_2e17_lhvloose_nod0", &GlobalTrigDecision_2e17_lhvloose_nod0, &b_GlobalTrigDecision_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_2e24_lhvloose_nod0", &GlobalTrigDecision_2e24_lhvloose_nod0, &b_GlobalTrigDecision_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_e120_lhloose", &GlobalTrigDecision_e120_lhloose, &b_GlobalTrigDecision_e120_lhloose);
   fChain->SetBranchAddress("GlobalTrigDecision_e140_lhloose_nod0", &GlobalTrigDecision_e140_lhloose_nod0, &b_GlobalTrigDecision_e140_lhloose_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_e17_lhloose_mu14", &GlobalTrigDecision_e17_lhloose_mu14, &b_GlobalTrigDecision_e17_lhloose_mu14);
   fChain->SetBranchAddress("GlobalTrigDecision_e17_lhloose_nod0_mu14", &GlobalTrigDecision_e17_lhloose_nod0_mu14, &b_GlobalTrigDecision_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("GlobalTrigDecision_e24_lhmedium_L1EM20VH", &GlobalTrigDecision_e24_lhmedium_L1EM20VH, &b_GlobalTrigDecision_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("GlobalTrigDecision_e26_lhtight_nod0_ivarloose", &GlobalTrigDecision_e26_lhtight_nod0_ivarloose, &b_GlobalTrigDecision_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("GlobalTrigDecision_e60_lhmedium", &GlobalTrigDecision_e60_lhmedium, &b_GlobalTrigDecision_e60_lhmedium);
   fChain->SetBranchAddress("GlobalTrigDecision_e60_lhmedium_nod0", &GlobalTrigDecision_e60_lhmedium_nod0, &b_GlobalTrigDecision_e60_lhmedium_nod0);
   fChain->SetBranchAddress("GlobalTrigDecision_mu18_mu8noL1", &GlobalTrigDecision_mu18_mu8noL1, &b_GlobalTrigDecision_mu18_mu8noL1);
   fChain->SetBranchAddress("GlobalTrigDecision_mu20_iloose_L1MU15", &GlobalTrigDecision_mu20_iloose_L1MU15, &b_GlobalTrigDecision_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("GlobalTrigDecision_mu22_mu8noL1", &GlobalTrigDecision_mu22_mu8noL1, &b_GlobalTrigDecision_mu22_mu8noL1);
   fChain->SetBranchAddress("GlobalTrigDecision_mu26_ivarmedium", &GlobalTrigDecision_mu26_ivarmedium, &b_GlobalTrigDecision_mu26_ivarmedium);
   fChain->SetBranchAddress("GlobalTrigDecision_mu50", &GlobalTrigDecision_mu50, &b_GlobalTrigDecision_mu50);
   fChain->SetBranchAddress("higgsDecayMode", &higgsDecayMode, &b_higgsDecayMode);
   fChain->SetBranchAddress("hhiggsDecayMode", &hhiggsDecayMode, &b_hhiggsDecayMode);
   fChain->SetBranchAddress("initial_state", &initial_state, &b_initial_state);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("lepSFObjChannelCombined", &lepSFObjChannelCombined, &b_lepSFObjChannelCombined);
   fChain->SetBranchAddress("jvtSF_customOR", &jvtSF_customOR, &b_jvtSF_customOR);
   fChain->SetBranchAddress("fjvtSF_customOR", &fjvtSF_customOR, &b_fjvtSF_customOR);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_60", &bTagSF_weight_DL1r_60, &b_bTagSF_weight_DL1r_60);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_70", &bTagSF_weight_DL1r_70, &b_bTagSF_weight_DL1r_70);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_77", &bTagSF_weight_DL1r_77, &b_bTagSF_weight_DL1r_77);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_85", &bTagSF_weight_DL1r_85, &b_bTagSF_weight_DL1r_85);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_Continuous", &bTagSF_weight_DL1r_Continuous, &b_bTagSF_weight_DL1r_Continuous);
}

#endif // #ifdef VLLg_cxx
