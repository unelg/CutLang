#ifndef VLLf_h
#define VLLf_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"
#include "vector"
#include <iostream>
using namespace std;

class VLLf {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Bool_t          filterDuplicateEvents;
   Float_t         totalEventsWeighted;
   Float_t         totalEventsWeighted_weight_EW;
   Float_t         totalEventsWeighted_weight_EW_mult;
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
   Float_t         xs;
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
   Float_t         MtauMet;
   Int_t           NtauJet;
   Float_t         bjet_pt0;
   Float_t         bjet_eta0;
   Float_t         HT_vis_min;
   Float_t         HT_vis;
   Float_t         Mlb;
   Float_t         Mlb_OLD;
   Float_t         DRlb;
   Float_t         DRlb_OLD;
   Float_t         DeltaR_max_lep_bjet77;
   Float_t         DeltaR_min_lep_bjet77;
   Float_t         Mbblead;
   Float_t         Mbbtau;
   Float_t         Mbtaul;
   Float_t         Mbbmet;
   Float_t         Mtautau01;
   Float_t         Mltau00;
   Float_t         Mltau01;
   Float_t         Mltau10;
   Float_t         Mltau11;
   Int_t           nHiggs;
   Int_t           nWZhad;
   Int_t           nZee;
   Int_t           nZmm;
   Float_t         bjet_pt0_nofwd;
   Float_t         Mtaub;
   Int_t           nJets_OR_DL1r_77_pt40;
   Int_t           nJets_OR_nTaus_OR_pt40;
   Float_t         MLepMet;
   Float_t         MtLepMet;
   Float_t         MtLep0Met;
   Float_t         DRjj_lead;
   Float_t         mjj_lead;
   Float_t         mjjj_lead;
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
   Float_t         Mllmet;
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
   Int_t           sumPsbtag85;
   Float_t         jet_pt0_nofwd;
   Float_t         jet_pt1_nofwd;
   Float_t         jet_pt6_nofwd;
   Float_t         jet_pt0_nonbtag;
   Float_t         minDeltaR_J_bJ;
   Bool_t          l2SS1tau;
   Int_t           IFFClass_lep_0;
   Int_t           IFFClass_lep_1;
   Int_t           IFFClass_lep_2;
   Int_t           IFFClass_lep_3;
   Int_t           IFFClass_lep_4;
   Int_t           IFFClass_lep_5;
   Int_t           ttHMLClass_lep_0;
   Int_t           ttHMLClass_lep_1;
   Int_t           ttHMLClass_lep_2;
   Int_t           N_IFF_Unclassified;
   Int_t           N_IFF_KnownUnknown;
   Int_t           N_IFF_Prompt;
   Int_t           N_IFF_QmisID;
   Int_t           N_IFF_MatConv;
   Int_t           N_IFF_IntConv;
   Int_t           N_IFF_Bdecays;
   Int_t           N_IFF_Cdecays;
   Int_t           N_IFF_LightHadDecays;
   Int_t           N_IFF_EfromMu;
   Int_t           N_IFF_TauDecays;
   Int_t           num_Zee_best;
   Int_t           num_Zmm_best;
   Float_t         lepSF_PLIV_Prompt_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;
   Float_t         lepSF_PLIV_Prompt_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;
   Float_t         lepSF_PLIV_Prompt_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_totalSystError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_statError_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_IDSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_muSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_Tight_El_isoSyst_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;
   Float_t         lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;
   Float_t         weight_jvt;
   Float_t         weight_jvt__1up;
   Float_t         weight_jvt__1down;
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
   Float_t         weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_Reco_UP_AT;
   Float_t         weight_leptonSF_CC_El_Reco_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_ID_LooseAndBLayerLH_UP_AT;
   Float_t         weight_leptonSF_CC_El_ID_TightLH_UP_AT;
   Float_t         weight_leptonSF_CC_El_ID_LooseAndBLayerLH_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_ID_TightLH_DOWN_AT;
   Float_t         weight_leptonSF_CC_El_Iso_FCLoose_UP_AT;
   Float_t         weight_leptonSF_CC_El_Iso_FCLoose_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_TTVA_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_TTVA_STAT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_TTVA_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_TTVA_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_STAT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_STAT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_DOWN_AT;
   Float_t         weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_UP_AT;
   Float_t         weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_DOWN_AT;
   Float_t         weight_globalLeptonTriggerSF_CWP;
   Float_t         weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down;
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
   Float_t         weight_tauSFRNNMedium_TAU_SF_NOMINAL;
   Float_t         weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP;
   Float_t         weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN;
   Float_t         weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP;
   Float_t         weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN;
   Float_t         weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP;
   Float_t         weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_SYST_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RNNID_SYST_DOWN;
   Float_t         weight_tauSFRNNMedium_EFF_RECO_TOTAL_UP;
   Float_t         weight_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN;
   Float_t         weight_tauSFRNNLoose_TAU_SF_NOMINAL;
   Float_t         weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP;
   Float_t         weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN;
   Float_t         weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP;
   Float_t         weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN;
   Float_t         weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP;
   Float_t         weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_SYST_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RNNID_SYST_DOWN;
   Float_t         weight_tauSFRNNLoose_EFF_RECO_TOTAL_UP;
   Float_t         weight_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN;
   Float_t         weight_globalLeptonTriggerSF;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;
   Float_t         weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;
   Float_t         weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;
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
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e17_lhloose_nod0_mu14;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   Char_t          HLT_2e24_lhvloose_nod0;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu22_mu8noL1;
   Char_t          onelep_type;
   Char_t          dilep_type;
   Char_t          trilep_type;
   Char_t          quadlep_type;
   Char_t          fivelep_type;
   Char_t          sixlep_type;
   Char_t          multilepornone_type;
   Char_t          total_charge;
   Char_t          total_leptons;
   Float_t         Mll01;
   Float_t         Ptll01;
   Float_t         DRll01;
   Float_t         Mlll012;
   Float_t         Mllll0123;
   Float_t         Mllll0124;
   Float_t         Mllll0125;
   Float_t         Mlll013;
   Float_t         Mllll0134;
   Float_t         Mllll0135;
   Float_t         Mlll014;
   Float_t         Mllll0145;
   Float_t         Mlll015;
   Float_t         Mll02;
   Float_t         Ptll02;
   Float_t         DRll02;
   Float_t         Mlll023;
   Float_t         Mllll0234;
   Float_t         Mllll0235;
   Float_t         Mlll024;
   Float_t         Mllll0245;
   Float_t         Mlll025;
   Float_t         Mll03;
   Float_t         Ptll03;
   Float_t         DRll03;
   Float_t         Mlll034;
   Float_t         Mllll0345;
   Float_t         Mlll035;
   Float_t         Mll04;
   Float_t         Ptll04;
   Float_t         DRll04;
   Float_t         Mlll045;
   Float_t         Mll05;
   Float_t         Ptll05;
   Float_t         DRll05;
   Float_t         Mll12;
   Float_t         Ptll12;
   Float_t         DRll12;
   Float_t         Mlll123;
   Float_t         Mllll1234;
   Float_t         Mllll1235;
   Float_t         Mlll124;
   Float_t         Mllll1245;
   Float_t         Mlll125;
   Float_t         Mll13;
   Float_t         Ptll13;
   Float_t         DRll13;
   Float_t         Mlll134;
   Float_t         Mllll1345;
   Float_t         Mlll135;
   Float_t         Mll14;
   Float_t         Ptll14;
   Float_t         DRll14;
   Float_t         Mlll145;
   Float_t         Mll15;
   Float_t         Ptll15;
   Float_t         DRll15;
   Float_t         Mll23;
   Float_t         Ptll23;
   Float_t         DRll23;
   Float_t         Mlll234;
   Float_t         Mllll2345;
   Float_t         Mlll235;
   Float_t         Mll24;
   Float_t         Ptll24;
   Float_t         DRll24;
   Float_t         Mlll245;
   Float_t         Mll25;
   Float_t         Ptll25;
   Float_t         DRll25;
   Float_t         Mll34;
   Float_t         Ptll34;
   Float_t         DRll34;
   Float_t         Mlll345;
   Float_t         Mll35;
   Float_t         Ptll35;
   Float_t         DRll35;
   Float_t         Mll45;
   Float_t         Ptll45;
   Float_t         DRll45;
   Float_t         best_Z_Mll;
   Float_t         best_Z_other_MtLepMet;
   Float_t         best_Z_other_Mll;
   Float_t         minOSSFMll;
   Float_t         minOSMll;
   Float_t         Mlt00;
   Float_t         Mlt01;
   Float_t         Mlt10;
   Float_t         Mlt11;
   Float_t         Mtt01;
   Float_t         MTlmet;
   Char_t          nJets_OR;
   Char_t          nJets_OR_DL1r_85;
   Char_t          nJets_OR_DL1r_60;
   Char_t          nJets_OR_DL1r_77;
   Char_t          nJets_OR_DL1r_70;
   Char_t          nTaus_OR_Pt25;
   Char_t          nTaus_OR;
   Char_t          nTaus_OR_Medium;
   Char_t          nTaus_OR_Tight;
   Float_t         HT;
   Float_t         HT_lep;
   Float_t         HT_jets;
   Float_t         HT_taus;
   Int_t           RunYear;
   Float_t         lep_ID_0;
   Int_t           lep_Index_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_EtaBE2_0;
   Float_t         lep_Phi_0;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_Z0SinTheta_0;
   Float_t         lep_d0_0;
   Float_t         lep_z0_0;
   Float_t         lep_vz_0;
   Float_t         lep_deltaz0_0;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isMediumLH_0;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isTight_0;
   Char_t          lep_isMedium_0;
   Char_t          lep_isLoose_0;
   Char_t          lep_isHighPt_0;
   Char_t          lep_isolationFCLoose_0;
   Char_t          lep_isolationPLImprovedTight_0;
   Char_t          lep_isolationPLImprovedVeryTight_0;
   Char_t          lep_isolationFCTight_0;
   Char_t          lep_isolationLoose_0;
   Char_t          lep_isolationGradient_0;
   Char_t          lep_isolationGradientLoose_0;
   Char_t          lep_isolationTightTrackOnly_0;
   Char_t          lep_isolationHighPtCaloOnly_0;
   Char_t          lep_isolationPflowTight_0;
   Char_t          lep_isolationPflowLoose_0;
   Char_t          lep_isolationPflowTight_VarRad_0;
   Char_t          lep_isolationPflowTight_FixedRad_0;
   Char_t          lep_isolationPflowLoose_VarRad_0;
   Char_t          lep_isolationPflowLoose_FixedRad_0;
   Char_t          lep_isolationHighPtTrackOnly_0;
   Char_t          lep_isolationTight_FixedRad_0;
   Char_t          lep_isolationLoose_FixedRad_0;
   Char_t          lep_isolationTightTrackOnly_VarRad_0;
   Char_t          lep_isolationTightTrackOnly_FixedRad_0;
   Char_t          lep_isolationTight_VarRad_0;
   Char_t          lep_isolationLoose_VarRad_0;
   Char_t          lep_plvWP_Loose_0;
   Char_t          lep_plvWP_Tight_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;
   Char_t          lep_isTrigMatchDLT_0;
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
   Float_t         lep_SeparationMinDCT_0;
   Float_t         lep_DFCommonSimpleConvRadius_0;
   Float_t         lep_DFCommonSimpleConvPhi_0;
   Float_t         lep_DFCommonSimpleMee_0;
   Float_t         lep_DFCommonSimpleMeeAtVtx_0;
   Float_t         lep_DFCommonSimpleSeparation_0;
   Int_t           lep_DFCommonAddAmbiguity_0;
   Float_t         lep_DFCommonProdTrueRadius_0;
   Float_t         lep_DFCommonProdTruePhi_0;
   Float_t         lep_DFCommonProdTrueZ_0;
   Float_t         lep_DFCommonJetDr_0;
   Char_t          lep_chargeIDBDTLoose_0;
   Double_t        lep_chargeIDBDTResult_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_0;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_0;
   Float_t         lep_promptLeptonIso_TagWeight_0;
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
   Char_t          lep_isTruthMatched_0;
   Int_t           lep_AnpTruthType_0;
   Int_t           lep_truthType_0;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthPdgId_0;
   Int_t           lep_truthStatus_0;
   Int_t           lep_truthParentType_0;
   Int_t           lep_truthParentOrigin_0;
   Int_t           lep_truthParentPdgId_0;
   Int_t           lep_truthParentRealPdgId_0;
   Int_t           lep_truthParentStatus_0;
   Int_t           lep_truthParentBarcode_0;
   Char_t          lep_truthParentIsCHadron_0;
   Char_t          lep_truthParentIsBHadron_0;
   Char_t          lep_truthHasTopInChain_0;
   Float_t         lep_truthParentPt_0;
   Float_t         lep_truthParentEta_0;
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
   Float_t         lep_SF_El_Iso_FCLoose_AT_0;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_0;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_0;
   Float_t         lep_SF_El_PLVTight_QmisID_0;
   Float_t         lep_SF_El_PLVTight_0;
   Float_t         lep_SF_El_PLVLoose_0;
   Float_t         lep_SF_El_ID_MediumLH_0;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_0;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_0;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_0;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_0;
   Float_t         lep_SF_Mu_TTVA_AT_0;
   Float_t         lep_SF_Mu_ID_Loose_AT_0;
   Float_t         lep_SF_Mu_ID_Medium_AT_0;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_0;
   Float_t         lep_SF_Mu_ID_Tight_0;
   Float_t         lep_SF_Mu_ID_HighPt_0;
   Float_t         lep_SF_Mu_PLVTight_0;
   Float_t         lep_SF_Mu_PLVLoose_0;
   Float_t         lep_SF_Mu_PLIV_MnotT_0;
   Float_t         lep_SF_Mu_PLIV_T_0;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_0;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_0;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_0;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_0;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_0;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_0;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_0;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_0;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_0;
   Float_t         lep_SF_CombinedLoose_0;
   Float_t         lep_SF_CombinedTight_0;
   Float_t         lep_ID_1;
   Int_t           lep_Index_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_EtaBE2_1;
   Float_t         lep_Phi_1;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_Z0SinTheta_1;
   Float_t         lep_d0_1;
   Float_t         lep_z0_1;
   Float_t         lep_vz_1;
   Float_t         lep_deltaz0_1;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isMediumLH_1;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isTight_1;
   Char_t          lep_isMedium_1;
   Char_t          lep_isLoose_1;
   Char_t          lep_isHighPt_1;
   Char_t          lep_isolationFCLoose_1;
   Char_t          lep_isolationPLImprovedTight_1;
   Char_t          lep_isolationPLImprovedVeryTight_1;
   Char_t          lep_isolationFCTight_1;
   Char_t          lep_isolationLoose_1;
   Char_t          lep_isolationGradient_1;
   Char_t          lep_isolationGradientLoose_1;
   Char_t          lep_isolationTightTrackOnly_1;
   Char_t          lep_isolationHighPtCaloOnly_1;
   Char_t          lep_isolationPflowTight_1;
   Char_t          lep_isolationPflowLoose_1;
   Char_t          lep_isolationPflowTight_VarRad_1;
   Char_t          lep_isolationPflowTight_FixedRad_1;
   Char_t          lep_isolationPflowLoose_VarRad_1;
   Char_t          lep_isolationPflowLoose_FixedRad_1;
   Char_t          lep_isolationHighPtTrackOnly_1;
   Char_t          lep_isolationTight_FixedRad_1;
   Char_t          lep_isolationLoose_FixedRad_1;
   Char_t          lep_isolationTightTrackOnly_VarRad_1;
   Char_t          lep_isolationTightTrackOnly_FixedRad_1;
   Char_t          lep_isolationTight_VarRad_1;
   Char_t          lep_isolationLoose_VarRad_1;
   Char_t          lep_plvWP_Loose_1;
   Char_t          lep_plvWP_Tight_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;
   Char_t          lep_isTrigMatchDLT_1;
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
   Float_t         lep_SeparationMinDCT_1;
   Float_t         lep_DFCommonSimpleConvRadius_1;
   Float_t         lep_DFCommonSimpleConvPhi_1;
   Float_t         lep_DFCommonSimpleMee_1;
   Float_t         lep_DFCommonSimpleMeeAtVtx_1;
   Float_t         lep_DFCommonSimpleSeparation_1;
   Int_t           lep_DFCommonAddAmbiguity_1;
   Float_t         lep_DFCommonProdTrueRadius_1;
   Float_t         lep_DFCommonProdTruePhi_1;
   Float_t         lep_DFCommonProdTrueZ_1;
   Float_t         lep_DFCommonJetDr_1;
   Char_t          lep_chargeIDBDTLoose_1;
   Double_t        lep_chargeIDBDTResult_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_1;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_1;
   Float_t         lep_promptLeptonIso_TagWeight_1;
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
   Char_t          lep_isTruthMatched_1;
   Int_t           lep_AnpTruthType_1;
   Int_t           lep_truthType_1;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthPdgId_1;
   Int_t           lep_truthStatus_1;
   Int_t           lep_truthParentType_1;
   Int_t           lep_truthParentOrigin_1;
   Int_t           lep_truthParentPdgId_1;
   Int_t           lep_truthParentRealPdgId_1;
   Int_t           lep_truthParentStatus_1;
   Int_t           lep_truthParentBarcode_1;
   Char_t          lep_truthParentIsCHadron_1;
   Char_t          lep_truthParentIsBHadron_1;
   Char_t          lep_truthHasTopInChain_1;
   Float_t         lep_truthParentPt_1;
   Float_t         lep_truthParentEta_1;
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
   Float_t         lep_SF_El_Iso_FCLoose_AT_1;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_1;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_1;
   Float_t         lep_SF_El_PLVTight_QmisID_1;
   Float_t         lep_SF_El_PLVTight_1;
   Float_t         lep_SF_El_PLVLoose_1;
   Float_t         lep_SF_El_ID_MediumLH_1;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_1;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_1;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_1;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_1;
   Float_t         lep_SF_Mu_TTVA_AT_1;
   Float_t         lep_SF_Mu_ID_Loose_AT_1;
   Float_t         lep_SF_Mu_ID_Medium_AT_1;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_1;
   Float_t         lep_SF_Mu_ID_Tight_1;
   Float_t         lep_SF_Mu_ID_HighPt_1;
   Float_t         lep_SF_Mu_PLVTight_1;
   Float_t         lep_SF_Mu_PLVLoose_1;
   Float_t         lep_SF_Mu_PLIV_MnotT_1;
   Float_t         lep_SF_Mu_PLIV_T_1;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_1;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_1;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_1;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_1;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_1;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_1;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_1;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_1;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_1;
   Float_t         lep_SF_CombinedLoose_1;
   Float_t         lep_SF_CombinedTight_1;
   Float_t         lep_ID_2;
   Int_t           lep_Index_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_EtaBE2_2;
   Float_t         lep_Phi_2;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_Z0SinTheta_2;
   Float_t         lep_d0_2;
   Float_t         lep_z0_2;
   Float_t         lep_vz_2;
   Float_t         lep_deltaz0_2;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isMediumLH_2;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isTight_2;
   Char_t          lep_isMedium_2;
   Char_t          lep_isLoose_2;
   Char_t          lep_isHighPt_2;
   Char_t          lep_isolationFCLoose_2;
   Char_t          lep_isolationPLImprovedTight_2;
   Char_t          lep_isolationPLImprovedVeryTight_2;
   Char_t          lep_isolationFCTight_2;
   Char_t          lep_isolationLoose_2;
   Char_t          lep_isolationGradient_2;
   Char_t          lep_isolationGradientLoose_2;
   Char_t          lep_isolationTightTrackOnly_2;
   Char_t          lep_isolationHighPtCaloOnly_2;
   Char_t          lep_isolationPflowTight_2;
   Char_t          lep_isolationPflowLoose_2;
   Char_t          lep_isolationPflowTight_VarRad_2;
   Char_t          lep_isolationPflowTight_FixedRad_2;
   Char_t          lep_isolationPflowLoose_VarRad_2;
   Char_t          lep_isolationPflowLoose_FixedRad_2;
   Char_t          lep_isolationHighPtTrackOnly_2;
   Char_t          lep_isolationTight_FixedRad_2;
   Char_t          lep_isolationLoose_FixedRad_2;
   Char_t          lep_isolationTightTrackOnly_VarRad_2;
   Char_t          lep_isolationTightTrackOnly_FixedRad_2;
   Char_t          lep_isolationTight_VarRad_2;
   Char_t          lep_isolationLoose_VarRad_2;
   Char_t          lep_plvWP_Loose_2;
   Char_t          lep_plvWP_Tight_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;
   Char_t          lep_isTrigMatchDLT_2;
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
   Float_t         lep_SeparationMinDCT_2;
   Float_t         lep_DFCommonSimpleConvRadius_2;
   Float_t         lep_DFCommonSimpleConvPhi_2;
   Float_t         lep_DFCommonSimpleMee_2;
   Float_t         lep_DFCommonSimpleMeeAtVtx_2;
   Float_t         lep_DFCommonSimpleSeparation_2;
   Int_t           lep_DFCommonAddAmbiguity_2;
   Float_t         lep_DFCommonProdTrueRadius_2;
   Float_t         lep_DFCommonProdTruePhi_2;
   Float_t         lep_DFCommonProdTrueZ_2;
   Float_t         lep_DFCommonJetDr_2;
   Char_t          lep_chargeIDBDTLoose_2;
   Double_t        lep_chargeIDBDTResult_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_2;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_2;
   Float_t         lep_promptLeptonIso_TagWeight_2;
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
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_AnpTruthType_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Int_t           lep_truthStatus_2;
   Int_t           lep_truthParentType_2;
   Int_t           lep_truthParentOrigin_2;
   Int_t           lep_truthParentPdgId_2;
   Int_t           lep_truthParentRealPdgId_2;
   Int_t           lep_truthParentStatus_2;
   Int_t           lep_truthParentBarcode_2;
   Char_t          lep_truthParentIsCHadron_2;
   Char_t          lep_truthParentIsBHadron_2;
   Char_t          lep_truthHasTopInChain_2;
   Float_t         lep_truthParentPt_2;
   Float_t         lep_truthParentEta_2;
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
   Float_t         lep_SF_El_Iso_FCLoose_AT_2;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_2;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_2;
   Float_t         lep_SF_El_PLVTight_QmisID_2;
   Float_t         lep_SF_El_PLVTight_2;
   Float_t         lep_SF_El_PLVLoose_2;
   Float_t         lep_SF_El_ID_MediumLH_2;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_2;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_2;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_2;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_2;
   Float_t         lep_SF_Mu_TTVA_AT_2;
   Float_t         lep_SF_Mu_ID_Loose_AT_2;
   Float_t         lep_SF_Mu_ID_Medium_AT_2;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_2;
   Float_t         lep_SF_Mu_ID_Tight_2;
   Float_t         lep_SF_Mu_ID_HighPt_2;
   Float_t         lep_SF_Mu_PLVTight_2;
   Float_t         lep_SF_Mu_PLVLoose_2;
   Float_t         lep_SF_Mu_PLIV_MnotT_2;
   Float_t         lep_SF_Mu_PLIV_T_2;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_2;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_2;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_2;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_2;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_2;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_2;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_2;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_2;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_2;
   Float_t         lep_SF_CombinedLoose_2;
   Float_t         lep_SF_CombinedTight_2;
   Float_t         lep_ID_3;
   Int_t           lep_Index_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_EtaBE2_3;
   Float_t         lep_Phi_3;
   Float_t         lep_sigd0PV_3;
   Float_t         lep_Z0SinTheta_3;
   Float_t         lep_d0_3;
   Float_t         lep_z0_3;
   Float_t         lep_vz_3;
   Float_t         lep_deltaz0_3;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isMediumLH_3;
   Char_t          lep_isLooseLH_3;
   Char_t          lep_isTight_3;
   Char_t          lep_isMedium_3;
   Char_t          lep_isLoose_3;
   Char_t          lep_isHighPt_3;
   Char_t          lep_isolationFCLoose_3;
   Char_t          lep_isolationPLImprovedTight_3;
   Char_t          lep_isolationPLImprovedVeryTight_3;
   Char_t          lep_isolationFCTight_3;
   Char_t          lep_isolationLoose_3;
   Char_t          lep_isolationGradient_3;
   Char_t          lep_isolationGradientLoose_3;
   Char_t          lep_isolationTightTrackOnly_3;
   Char_t          lep_isolationHighPtCaloOnly_3;
   Char_t          lep_isolationPflowTight_3;
   Char_t          lep_isolationPflowLoose_3;
   Char_t          lep_isolationPflowTight_VarRad_3;
   Char_t          lep_isolationPflowTight_FixedRad_3;
   Char_t          lep_isolationPflowLoose_VarRad_3;
   Char_t          lep_isolationPflowLoose_FixedRad_3;
   Char_t          lep_isolationHighPtTrackOnly_3;
   Char_t          lep_isolationTight_FixedRad_3;
   Char_t          lep_isolationLoose_FixedRad_3;
   Char_t          lep_isolationTightTrackOnly_VarRad_3;
   Char_t          lep_isolationTightTrackOnly_FixedRad_3;
   Char_t          lep_isolationTight_VarRad_3;
   Char_t          lep_isolationLoose_VarRad_3;
   Char_t          lep_plvWP_Loose_3;
   Char_t          lep_plvWP_Tight_3;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;
   Char_t          lep_isTrigMatchDLT_3;
   Char_t          lep_isPrompt_3;
   Char_t          lep_isFakeLep_3;
   Char_t          lep_isQMisID_3;
   Char_t          lep_isConvPh_3;
   Char_t          lep_isExtConvPh_3;
   Char_t          lep_isIntConvPh_3;
   Char_t          lep_isISR_FSR_Ph_3;
   Char_t          lep_isBrems_3;
   Int_t           lep_nTrackParticles_3;
   Float_t         lep_Mtrktrk_atPV_CO_3;
   Float_t         lep_Mtrktrk_atConvV_CO_3;
   Float_t         lep_RadiusCO_3;
   Float_t         lep_RadiusCOX_3;
   Float_t         lep_RadiusCOY_3;
   Float_t         lep_SeparationMinDCT_3;
   Float_t         lep_DFCommonSimpleConvRadius_3;
   Float_t         lep_DFCommonSimpleConvPhi_3;
   Float_t         lep_DFCommonSimpleMee_3;
   Float_t         lep_DFCommonSimpleMeeAtVtx_3;
   Float_t         lep_DFCommonSimpleSeparation_3;
   Int_t           lep_DFCommonAddAmbiguity_3;
   Float_t         lep_DFCommonProdTrueRadius_3;
   Float_t         lep_DFCommonProdTruePhi_3;
   Float_t         lep_DFCommonProdTrueZ_3;
   Float_t         lep_DFCommonJetDr_3;
   Char_t          lep_chargeIDBDTLoose_3;
   Double_t        lep_chargeIDBDTResult_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_3;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_3;
   Float_t         lep_promptLeptonIso_TagWeight_3;
   Float_t         lep_promptLeptonVeto_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_3;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_3;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_3;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_3;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_3;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_3;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_3;
   Float_t         lep_PromptLeptonRNN_prompt_3;
   Char_t          lep_isTruthMatched_3;
   Int_t           lep_AnpTruthType_3;
   Int_t           lep_truthType_3;
   Int_t           lep_truthOrigin_3;
   Int_t           lep_truthPdgId_3;
   Int_t           lep_truthStatus_3;
   Int_t           lep_truthParentType_3;
   Int_t           lep_truthParentOrigin_3;
   Int_t           lep_truthParentPdgId_3;
   Int_t           lep_truthParentRealPdgId_3;
   Int_t           lep_truthParentStatus_3;
   Int_t           lep_truthParentBarcode_3;
   Char_t          lep_truthParentIsCHadron_3;
   Char_t          lep_truthParentIsBHadron_3;
   Char_t          lep_truthHasTopInChain_3;
   Float_t         lep_truthParentPt_3;
   Float_t         lep_truthParentEta_3;
   Float_t         lep_truthPt_3;
   Float_t         lep_truthEta_3;
   Float_t         lep_truthPhi_3;
   Float_t         lep_truthM_3;
   Float_t         lep_truthE_3;
   Float_t         lep_truthRapidity_3;
   UChar_t         lep_ambiguityType_3;
   Int_t           lep_nInnerPix_3;
   Int_t           lep_firstEgMotherPdgId_3;
   Int_t           lep_firstEgMotherTruthType_3;
   Int_t           lep_firstEgMotherTruthOrigin_3;
   Int_t           lep_lastEgMotherPdgId_3;
   Int_t           lep_lastEgMotherTruthType_3;
   Int_t           lep_lastEgMotherTruthOrigin_3;
   Float_t         lep_SF_El_Reco_AT_3;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_3;
   Float_t         lep_SF_El_ID_TightLH_AT_3;
   Float_t         lep_SF_El_Iso_FCLoose_AT_3;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_3;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_3;
   Float_t         lep_SF_El_PLVTight_QmisID_3;
   Float_t         lep_SF_El_PLVTight_3;
   Float_t         lep_SF_El_PLVLoose_3;
   Float_t         lep_SF_El_ID_MediumLH_3;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_3;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_3;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_3;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_3;
   Float_t         lep_SF_Mu_TTVA_AT_3;
   Float_t         lep_SF_Mu_ID_Loose_AT_3;
   Float_t         lep_SF_Mu_ID_Medium_AT_3;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_3;
   Float_t         lep_SF_Mu_ID_Tight_3;
   Float_t         lep_SF_Mu_ID_HighPt_3;
   Float_t         lep_SF_Mu_PLVTight_3;
   Float_t         lep_SF_Mu_PLVLoose_3;
   Float_t         lep_SF_Mu_PLIV_MnotT_3;
   Float_t         lep_SF_Mu_PLIV_T_3;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_3;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_3;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_3;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_3;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_3;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_3;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_3;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_3;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_3;
   Float_t         lep_SF_CombinedLoose_3;
   Float_t         lep_SF_CombinedTight_3;
   Float_t         lep_ID_4;
   Int_t           lep_Index_4;
   Float_t         lep_Pt_4;
   Float_t         lep_E_4;
   Float_t         lep_Eta_4;
   Float_t         lep_EtaBE2_4;
   Float_t         lep_Phi_4;
   Float_t         lep_sigd0PV_4;
   Float_t         lep_Z0SinTheta_4;
   Float_t         lep_d0_4;
   Float_t         lep_z0_4;
   Float_t         lep_vz_4;
   Float_t         lep_deltaz0_4;
   Char_t          lep_isTightLH_4;
   Char_t          lep_isMediumLH_4;
   Char_t          lep_isLooseLH_4;
   Char_t          lep_isTight_4;
   Char_t          lep_isMedium_4;
   Char_t          lep_isLoose_4;
   Char_t          lep_isHighPt_4;
   Char_t          lep_isolationFCLoose_4;
   Char_t          lep_isolationPLImprovedTight_4;
   Char_t          lep_isolationPLImprovedVeryTight_4;
   Char_t          lep_isolationFCTight_4;
   Char_t          lep_isolationLoose_4;
   Char_t          lep_isolationGradient_4;
   Char_t          lep_isolationGradientLoose_4;
   Char_t          lep_isolationTightTrackOnly_4;
   Char_t          lep_isolationHighPtCaloOnly_4;
   Char_t          lep_isolationPflowTight_4;
   Char_t          lep_isolationPflowLoose_4;
   Char_t          lep_isolationPflowTight_VarRad_4;
   Char_t          lep_isolationPflowTight_FixedRad_4;
   Char_t          lep_isolationPflowLoose_VarRad_4;
   Char_t          lep_isolationPflowLoose_FixedRad_4;
   Char_t          lep_isolationHighPtTrackOnly_4;
   Char_t          lep_isolationTight_FixedRad_4;
   Char_t          lep_isolationLoose_FixedRad_4;
   Char_t          lep_isolationTightTrackOnly_VarRad_4;
   Char_t          lep_isolationTightTrackOnly_FixedRad_4;
   Char_t          lep_isolationTight_VarRad_4;
   Char_t          lep_isolationLoose_VarRad_4;
   Char_t          lep_plvWP_Loose_4;
   Char_t          lep_plvWP_Tight_4;
   Char_t          lep_isTrigMatch_4;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_4;
   Char_t          lep_isTrigMatchDLT_4;
   Char_t          lep_isPrompt_4;
   Char_t          lep_isFakeLep_4;
   Char_t          lep_isQMisID_4;
   Char_t          lep_isConvPh_4;
   Char_t          lep_isExtConvPh_4;
   Char_t          lep_isIntConvPh_4;
   Char_t          lep_isISR_FSR_Ph_4;
   Char_t          lep_isBrems_4;
   Int_t           lep_nTrackParticles_4;
   Float_t         lep_Mtrktrk_atPV_CO_4;
   Float_t         lep_Mtrktrk_atConvV_CO_4;
   Float_t         lep_RadiusCO_4;
   Float_t         lep_RadiusCOX_4;
   Float_t         lep_RadiusCOY_4;
   Float_t         lep_SeparationMinDCT_4;
   Float_t         lep_DFCommonSimpleConvRadius_4;
   Float_t         lep_DFCommonSimpleConvPhi_4;
   Float_t         lep_DFCommonSimpleMee_4;
   Float_t         lep_DFCommonSimpleMeeAtVtx_4;
   Float_t         lep_DFCommonSimpleSeparation_4;
   Int_t           lep_DFCommonAddAmbiguity_4;
   Float_t         lep_DFCommonProdTrueRadius_4;
   Float_t         lep_DFCommonProdTruePhi_4;
   Float_t         lep_DFCommonProdTrueZ_4;
   Float_t         lep_DFCommonJetDr_4;
   Char_t          lep_chargeIDBDTLoose_4;
   Double_t        lep_chargeIDBDTResult_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_4;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_4;
   Float_t         lep_promptLeptonIso_TagWeight_4;
   Float_t         lep_promptLeptonVeto_TagWeight_4;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_4;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_4;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_4;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_4;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_4;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_4;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_4;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_4;
   Float_t         lep_PromptLeptonRNN_prompt_4;
   Char_t          lep_isTruthMatched_4;
   Int_t           lep_AnpTruthType_4;
   Int_t           lep_truthType_4;
   Int_t           lep_truthOrigin_4;
   Int_t           lep_truthPdgId_4;
   Int_t           lep_truthStatus_4;
   Int_t           lep_truthParentType_4;
   Int_t           lep_truthParentOrigin_4;
   Int_t           lep_truthParentPdgId_4;
   Int_t           lep_truthParentRealPdgId_4;
   Int_t           lep_truthParentStatus_4;
   Int_t           lep_truthParentBarcode_4;
   Char_t          lep_truthParentIsCHadron_4;
   Char_t          lep_truthParentIsBHadron_4;
   Char_t          lep_truthHasTopInChain_4;
   Float_t         lep_truthParentPt_4;
   Float_t         lep_truthParentEta_4;
   Float_t         lep_truthPt_4;
   Float_t         lep_truthEta_4;
   Float_t         lep_truthPhi_4;
   Float_t         lep_truthM_4;
   Float_t         lep_truthE_4;
   Float_t         lep_truthRapidity_4;
   UChar_t         lep_ambiguityType_4;
   Int_t           lep_nInnerPix_4;
   Int_t           lep_firstEgMotherPdgId_4;
   Int_t           lep_firstEgMotherTruthType_4;
   Int_t           lep_firstEgMotherTruthOrigin_4;
   Int_t           lep_lastEgMotherPdgId_4;
   Int_t           lep_lastEgMotherTruthType_4;
   Int_t           lep_lastEgMotherTruthOrigin_4;
   Float_t         lep_SF_El_Reco_AT_4;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_4;
   Float_t         lep_SF_El_ID_TightLH_AT_4;
   Float_t         lep_SF_El_Iso_FCLoose_AT_4;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_4;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_4;
   Float_t         lep_SF_El_PLVTight_QmisID_4;
   Float_t         lep_SF_El_PLVTight_4;
   Float_t         lep_SF_El_PLVLoose_4;
   Float_t         lep_SF_El_ID_MediumLH_4;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_4;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_4;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_4;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_4;
   Float_t         lep_SF_Mu_TTVA_AT_4;
   Float_t         lep_SF_Mu_ID_Loose_AT_4;
   Float_t         lep_SF_Mu_ID_Medium_AT_4;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_4;
   Float_t         lep_SF_Mu_ID_Tight_4;
   Float_t         lep_SF_Mu_ID_HighPt_4;
   Float_t         lep_SF_Mu_PLVTight_4;
   Float_t         lep_SF_Mu_PLVLoose_4;
   Float_t         lep_SF_Mu_PLIV_MnotT_4;
   Float_t         lep_SF_Mu_PLIV_T_4;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_4;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_4;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_4;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_4;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_4;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_4;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_4;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_4;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_4;
   Float_t         lep_SF_CombinedLoose_4;
   Float_t         lep_SF_CombinedTight_4;
   Float_t         lep_ID_5;
   Int_t           lep_Index_5;
   Float_t         lep_Pt_5;
   Float_t         lep_E_5;
   Float_t         lep_Eta_5;
   Float_t         lep_EtaBE2_5;
   Float_t         lep_Phi_5;
   Float_t         lep_sigd0PV_5;
   Float_t         lep_Z0SinTheta_5;
   Float_t         lep_d0_5;
   Float_t         lep_z0_5;
   Float_t         lep_vz_5;
   Float_t         lep_deltaz0_5;
   Char_t          lep_isTightLH_5;
   Char_t          lep_isMediumLH_5;
   Char_t          lep_isLooseLH_5;
   Char_t          lep_isTight_5;
   Char_t          lep_isMedium_5;
   Char_t          lep_isLoose_5;
   Char_t          lep_isHighPt_5;
   Char_t          lep_isolationFCLoose_5;
   Char_t          lep_isolationPLImprovedTight_5;
   Char_t          lep_isolationPLImprovedVeryTight_5;
   Char_t          lep_isolationFCTight_5;
   Char_t          lep_isolationLoose_5;
   Char_t          lep_isolationGradient_5;
   Char_t          lep_isolationGradientLoose_5;
   Char_t          lep_isolationTightTrackOnly_5;
   Char_t          lep_isolationHighPtCaloOnly_5;
   Char_t          lep_isolationPflowTight_5;
   Char_t          lep_isolationPflowLoose_5;
   Char_t          lep_isolationPflowTight_VarRad_5;
   Char_t          lep_isolationPflowTight_FixedRad_5;
   Char_t          lep_isolationPflowLoose_VarRad_5;
   Char_t          lep_isolationPflowLoose_FixedRad_5;
   Char_t          lep_isolationHighPtTrackOnly_5;
   Char_t          lep_isolationTight_FixedRad_5;
   Char_t          lep_isolationLoose_FixedRad_5;
   Char_t          lep_isolationTightTrackOnly_VarRad_5;
   Char_t          lep_isolationTightTrackOnly_FixedRad_5;
   Char_t          lep_isolationTight_VarRad_5;
   Char_t          lep_isolationLoose_VarRad_5;
   Char_t          lep_plvWP_Loose_5;
   Char_t          lep_plvWP_Tight_5;
   Char_t          lep_isTrigMatch_5;
   Char_t          lep_custTrigMatch_LooseID_FCLooseIso_SLT_5;
   Char_t          lep_isTrigMatchDLT_5;
   Char_t          lep_isPrompt_5;
   Char_t          lep_isFakeLep_5;
   Char_t          lep_isQMisID_5;
   Char_t          lep_isConvPh_5;
   Char_t          lep_isExtConvPh_5;
   Char_t          lep_isIntConvPh_5;
   Char_t          lep_isISR_FSR_Ph_5;
   Char_t          lep_isBrems_5;
   Int_t           lep_nTrackParticles_5;
   Float_t         lep_Mtrktrk_atPV_CO_5;
   Float_t         lep_Mtrktrk_atConvV_CO_5;
   Float_t         lep_RadiusCO_5;
   Float_t         lep_RadiusCOX_5;
   Float_t         lep_RadiusCOY_5;
   Float_t         lep_SeparationMinDCT_5;
   Float_t         lep_DFCommonSimpleConvRadius_5;
   Float_t         lep_DFCommonSimpleConvPhi_5;
   Float_t         lep_DFCommonSimpleMee_5;
   Float_t         lep_DFCommonSimpleMeeAtVtx_5;
   Float_t         lep_DFCommonSimpleSeparation_5;
   Int_t           lep_DFCommonAddAmbiguity_5;
   Float_t         lep_DFCommonProdTrueRadius_5;
   Float_t         lep_DFCommonProdTruePhi_5;
   Float_t         lep_DFCommonProdTrueZ_5;
   Float_t         lep_DFCommonJetDr_5;
   Char_t          lep_chargeIDBDTLoose_5;
   Double_t        lep_chargeIDBDTResult_5;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_loose_5;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_medium_5;
   Double_t        lep_chargeIDBDTResult_recalc_rel207_tight_5;
   Float_t         lep_promptLeptonIso_TagWeight_5;
   Float_t         lep_promptLeptonVeto_TagWeight_5;
   Float_t         lep_promptLeptonImprovedVeto_TagWeight_5;
   Float_t         lep_promptLeptonImprovedVetoBARR_TagWeight_5;
   Float_t         lep_promptLeptonImprovedVetoECAP_TagWeight_5;
   Short_t         lep_PromptLeptonImprovedInput_MVAXBin_5;
   Float_t         lep_PromptLeptonImprovedInput_PtFrac_5;
   Float_t         lep_PromptLeptonImprovedInput_DRlj_5;
   Float_t         lep_PromptLeptonImprovedInput_reltopoetcone30_5;
   Float_t         lep_PromptLeptonImprovedInput_relptvarcone30_5;
   Float_t         lep_PromptLeptonRNN_prompt_5;
   Char_t          lep_isTruthMatched_5;
   Int_t           lep_AnpTruthType_5;
   Int_t           lep_truthType_5;
   Int_t           lep_truthOrigin_5;
   Int_t           lep_truthPdgId_5;
   Int_t           lep_truthStatus_5;
   Int_t           lep_truthParentType_5;
   Int_t           lep_truthParentOrigin_5;
   Int_t           lep_truthParentPdgId_5;
   Int_t           lep_truthParentRealPdgId_5;
   Int_t           lep_truthParentStatus_5;
   Int_t           lep_truthParentBarcode_5;
   Char_t          lep_truthParentIsCHadron_5;
   Char_t          lep_truthParentIsBHadron_5;
   Char_t          lep_truthHasTopInChain_5;
   Float_t         lep_truthParentPt_5;
   Float_t         lep_truthParentEta_5;
   Float_t         lep_truthPt_5;
   Float_t         lep_truthEta_5;
   Float_t         lep_truthPhi_5;
   Float_t         lep_truthM_5;
   Float_t         lep_truthE_5;
   Float_t         lep_truthRapidity_5;
   UChar_t         lep_ambiguityType_5;
   Int_t           lep_nInnerPix_5;
   Int_t           lep_firstEgMotherPdgId_5;
   Int_t           lep_firstEgMotherTruthType_5;
   Int_t           lep_firstEgMotherTruthOrigin_5;
   Int_t           lep_lastEgMotherPdgId_5;
   Int_t           lep_lastEgMotherTruthType_5;
   Int_t           lep_lastEgMotherTruthOrigin_5;
   Float_t         lep_SF_El_Reco_AT_5;
   Float_t         lep_SF_El_ID_LooseAndBLayerLH_AT_5;
   Float_t         lep_SF_El_ID_TightLH_AT_5;
   Float_t         lep_SF_El_Iso_FCLoose_AT_5;
   Float_t         lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_5;
   Float_t         lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_5;
   Float_t         lep_SF_El_FCLooseTightLHQMisID_5;
   Float_t         lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_5;
   Float_t         lep_SF_El_Iso_FCLoose_TightLH_5;
   Float_t         lep_SF_El_PLVTight_QmisID_5;
   Float_t         lep_SF_El_PLVTight_5;
   Float_t         lep_SF_El_PLVLoose_5;
   Float_t         lep_SF_El_ID_MediumLH_5;
   Float_t         lep_SF_El_Iso_PLImprovedTight_TightLH_5;
   Float_t         lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_5;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTight_TightLH_5;
   Float_t         lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_5;
   Float_t         lep_SF_Mu_TTVA_AT_5;
   Float_t         lep_SF_Mu_ID_Loose_AT_5;
   Float_t         lep_SF_Mu_ID_Medium_AT_5;
   Float_t         lep_SF_Mu_Iso_FCLoose_AT_5;
   Float_t         lep_SF_Mu_ID_Tight_5;
   Float_t         lep_SF_Mu_ID_HighPt_5;
   Float_t         lep_SF_Mu_PLVTight_5;
   Float_t         lep_SF_Mu_PLVLoose_5;
   Float_t         lep_SF_Mu_PLIV_MnotT_5;
   Float_t         lep_SF_Mu_PLIV_T_5;
   Float_t         lep_SF_Mu_Iso_PflowTight_FixedRad_5;
   Float_t         lep_SF_Mu_Iso_PflowTight_VarRad_5;
   Float_t         lep_SF_Mu_Iso_PflowLoose_VarRad_5;
   Float_t         lep_SF_Mu_Iso_PflowLoose_FixedRad_5;
   Float_t         lep_SF_Mu_Iso_HighPtTrackOnly_5;
   Float_t         lep_SF_Mu_Iso_Tight_FixedRad_5;
   Float_t         lep_SF_Mu_Iso_Loose_FixedRad_5;
   Float_t         lep_SF_Mu_Iso_Loose_VarRad_5;
   Float_t         lep_SF_Mu_Iso_Tight_VarRad_5;
   Float_t         lep_SF_CombinedLoose_5;
   Float_t         lep_SF_CombinedTight_5;
   Float_t         taus_pt_0;
   Float_t         taus_eta_0;
   Float_t         taus_phi_0;
   Float_t         taus_charge_0;
   Float_t         taus_E_0;
   Float_t         taus_width_0;
   Char_t          taus_decayMode_0;
   Double_t        taus_BDTJetScore_0;
   Double_t        taus_BDTJetScoreSigTrans_0;
   Char_t          taus_JetBDTSigLoose_0;
   Char_t          taus_JetBDTSigMedium_0;
   Char_t          taus_JetBDTSigTight_0;
   Double_t        taus_RNNJetScore_0;
   Double_t        taus_RNNJetScoreSigTrans_0;
   Char_t          taus_JetRNNSigLoose_0;
   Char_t          taus_JetRNNSigMedium_0;
   Char_t          taus_JetRNNSigTight_0;
   Char_t          taus_numTrack_0;
   Char_t          taus_isHadronic_0;
   Char_t          taus_tagWeightBin_0;
   Float_t         taus_DL1r_0;
   Char_t          taus_fromPV_0;
   Char_t          taus_passJVT_0;
   Int_t           taus_passEleOLR_0;
   Int_t           taus_passEleBDT_0;
   Int_t           taus_passMuonOLR_0;
   Char_t          taus_isTruthMatched_0;
   Int_t           taus_truthOrigin_0;
   Int_t           taus_truthType_0;
   Int_t           taus_truthJetFlavour_0;
   Int_t           taus_truthNumCharge_0;
   Float_t         taus_truthPt_0;
   Float_t         taus_truthPtVis_0;
   Char_t          taus_passtau80L1TAU60_medium1_tracktwo_0;
   Char_t          taus_passtau125_medium1_tracktwo_0;
   Char_t          taus_passtau160_medium1_tracktwo_0;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwo_0;
   Char_t          taus_passtau25_medium1_tracktwoEF_0;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwoEF_0;
   Char_t          taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_0;
   Float_t         taus_pt_1;
   Float_t         taus_eta_1;
   Float_t         taus_phi_1;
   Float_t         taus_charge_1;
   Float_t         taus_E_1;
   Float_t         taus_width_1;
   Char_t          taus_decayMode_1;
   Double_t        taus_BDTJetScore_1;
   Double_t        taus_BDTJetScoreSigTrans_1;
   Char_t          taus_JetBDTSigLoose_1;
   Char_t          taus_JetBDTSigMedium_1;
   Char_t          taus_JetBDTSigTight_1;
   Double_t        taus_RNNJetScore_1;
   Double_t        taus_RNNJetScoreSigTrans_1;
   Char_t          taus_JetRNNSigLoose_1;
   Char_t          taus_JetRNNSigMedium_1;
   Char_t          taus_JetRNNSigTight_1;
   Char_t          taus_numTrack_1;
   Char_t          taus_isHadronic_1;
   Char_t          taus_tagWeightBin_1;
   Float_t         taus_DL1r_1;
   Char_t          taus_fromPV_1;
   Char_t          taus_passJVT_1;
   Int_t           taus_passEleOLR_1;
   Int_t           taus_passEleBDT_1;
   Int_t           taus_passMuonOLR_1;
   Char_t          taus_isTruthMatched_1;
   Int_t           taus_truthOrigin_1;
   Int_t           taus_truthType_1;
   Int_t           taus_truthJetFlavour_1;
   Int_t           taus_truthNumCharge_1;
   Float_t         taus_truthPt_1;
   Float_t         taus_truthPtVis_1;
   Char_t          taus_passtau80L1TAU60_medium1_tracktwo_1;
   Char_t          taus_passtau125_medium1_tracktwo_1;
   Char_t          taus_passtau160_medium1_tracktwo_1;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwo_1;
   Char_t          taus_passtau25_medium1_tracktwoEF_1;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwoEF_1;
   Char_t          taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_1;
   Float_t         taus_pt_2;
   Float_t         taus_eta_2;
   Float_t         taus_phi_2;
   Float_t         taus_charge_2;
   Float_t         taus_E_2;
   Float_t         taus_width_2;
   Char_t          taus_decayMode_2;
   Double_t        taus_BDTJetScore_2;
   Double_t        taus_BDTJetScoreSigTrans_2;
   Char_t          taus_JetBDTSigLoose_2;
   Char_t          taus_JetBDTSigMedium_2;
   Char_t          taus_JetBDTSigTight_2;
   Double_t        taus_RNNJetScore_2;
   Double_t        taus_RNNJetScoreSigTrans_2;
   Char_t          taus_JetRNNSigLoose_2;
   Char_t          taus_JetRNNSigMedium_2;
   Char_t          taus_JetRNNSigTight_2;
   Char_t          taus_numTrack_2;
   Char_t          taus_isHadronic_2;
   Char_t          taus_tagWeightBin_2;
   Float_t         taus_DL1r_2;
   Char_t          taus_fromPV_2;
   Char_t          taus_passJVT_2;
   Int_t           taus_passEleOLR_2;
   Int_t           taus_passEleBDT_2;
   Int_t           taus_passMuonOLR_2;
   Char_t          taus_isTruthMatched_2;
   Int_t           taus_truthOrigin_2;
   Int_t           taus_truthType_2;
   Int_t           taus_truthJetFlavour_2;
   Int_t           taus_truthNumCharge_2;
   Float_t         taus_truthPt_2;
   Float_t         taus_truthPtVis_2;
   Char_t          taus_passtau80L1TAU60_medium1_tracktwo_2;
   Char_t          taus_passtau125_medium1_tracktwo_2;
   Char_t          taus_passtau160_medium1_tracktwo_2;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwo_2;
   Char_t          taus_passtau25_medium1_tracktwoEF_2;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwoEF_2;
   Char_t          taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_2;
   Float_t         taus_pt_3;
   Float_t         taus_eta_3;
   Float_t         taus_phi_3;
   Float_t         taus_charge_3;
   Float_t         taus_E_3;
   Float_t         taus_width_3;
   Char_t          taus_decayMode_3;
   Double_t        taus_BDTJetScore_3;
   Double_t        taus_BDTJetScoreSigTrans_3;
   Char_t          taus_JetBDTSigLoose_3;
   Char_t          taus_JetBDTSigMedium_3;
   Char_t          taus_JetBDTSigTight_3;
   Double_t        taus_RNNJetScore_3;
   Double_t        taus_RNNJetScoreSigTrans_3;
   Char_t          taus_JetRNNSigLoose_3;
   Char_t          taus_JetRNNSigMedium_3;
   Char_t          taus_JetRNNSigTight_3;
   Char_t          taus_numTrack_3;
   Char_t          taus_isHadronic_3;
   Char_t          taus_tagWeightBin_3;
   Float_t         taus_DL1r_3;
   Char_t          taus_fromPV_3;
   Char_t          taus_passJVT_3;
   Int_t           taus_passEleOLR_3;
   Int_t           taus_passEleBDT_3;
   Int_t           taus_passMuonOLR_3;
   Char_t          taus_isTruthMatched_3;
   Int_t           taus_truthOrigin_3;
   Int_t           taus_truthType_3;
   Int_t           taus_truthJetFlavour_3;
   Int_t           taus_truthNumCharge_3;
   Float_t         taus_truthPt_3;
   Float_t         taus_truthPtVis_3;
   Char_t          taus_passtau80L1TAU60_medium1_tracktwo_3;
   Char_t          taus_passtau125_medium1_tracktwo_3;
   Char_t          taus_passtau160_medium1_tracktwo_3;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwo_3;
   Char_t          taus_passtau25_medium1_tracktwoEF_3;
   Char_t          taus_passtau160L1TAU100_medium1_tracktwoEF_3;
   Char_t          taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_3;
   vector<float>   *jets_pt;
   vector<float>   *jets_e;
   vector<float>   *jets_eta;
   vector<float>   *jets_phi;
   vector<float>   *jets_score_DL1r;
   vector<char>    *jets_btagFlag_DL1r_ContinuousBin;
   vector<float>   *jets_score_DL1r_pu;
   vector<float>   *jets_score_DL1r_pc;
   vector<float>   *jets_score_DL1r_pb;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_60;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_70;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_77;
   vector<char>    *jets_btagFlag_DL1r_FixedCutBEff_85;
   vector<float>   *jets_btag_JetVertexCharge_discriminant;
   vector<char>    *jets_ConeTruthLabelID;
   vector<char>    *jets_PartonTruthLabelID;
   vector<char>    *jets_isQuarkJet;
   vector<char>    *jets_isQuarkJetBDT;
   vector<char>    *jets_HadronConeExclExtendedTruthLabelID;
   vector<char>    *jets_HadronConeExclTruthLabelID;
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
   Float_t         custTrigSF_CombinedWPs_SLTorDLT;
   Float_t         custTrigSF_CombinedWPs_SLT;
   Float_t         custTrigSF_CombinedWPs_DLT;
   Char_t          custTrigMatch_CombinedWPs_SLTorDLT;
   Char_t          custTrigMatch_CombinedWPs_SLT;
   Char_t          custTrigMatch_CombinedWPs_DLT;
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
   Float_t         highpt_trubjet;
   Float_t         mvis_taub;
   Int_t           lqlq_decays;
   Int_t           VLL_type;
   Int_t           VLL_decaytype;
   Int_t           VLL_decayZdecays;
   Int_t           VLL_decayWdecays;
   Int_t           VLL_decayHdecays;
   Int_t           m_HF_Classification;
   Int_t           m_HF_ClassificationTop;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSFObjChannelCombined;
   Float_t         jvtSF_customOR;
   Float_t         bTagSF_weight_DL1r_60;
   Float_t         bTagSF_weight_DL1r_70;
   Float_t         bTagSF_weight_DL1r_77;
   Float_t         bTagSF_weight_DL1r_85;
   Float_t         bTagSF_weight_DL1r_Continuous;

   // List of branches
   TBranch        *b_filterDuplicateEvents;   //!
   TBranch        *b_totalEventsWeighted;   //!
   TBranch        *b_totalEventsWeighted_weight_EW;   //!
   TBranch        *b_totalEventsWeighted_weight_EW_mult;   //!
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
   TBranch        *b_xs;   //!
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
   TBranch        *b_MtauMet;   //!
   TBranch        *b_NtauJet;   //!
   TBranch        *b_bjet_pt0;   //!
   TBranch        *b_bjet_eta0;   //!
   TBranch        *b_HT_vis_min;   //!
   TBranch        *b_HT_vis;   //!
   TBranch        *b_Mlb;   //!
   TBranch        *b_Mlb_OLD;   //!
   TBranch        *b_DRlb;   //!
   TBranch        *b_DRlb_OLD;   //!
   TBranch        *b_DeltaR_max_lep_bjet77;   //!
   TBranch        *b_DeltaR_min_lep_bjet77;   //!
   TBranch        *b_Mbblead;   //!
   TBranch        *b_Mbbtau;   //!
   TBranch        *b_Mbtaul;   //!
   TBranch        *b_Mbbmet;   //!
   TBranch        *b_Mtautau01;   //!
   TBranch        *b_Mltau00;   //!
   TBranch        *b_Mltau01;   //!
   TBranch        *b_Mltau10;   //!
   TBranch        *b_Mltau11;   //!
   TBranch        *b_nHiggs;   //!
   TBranch        *b_nWZhad;   //!
   TBranch        *b_nZee;   //!
   TBranch        *b_nZmm;   //!
   TBranch        *b_bjet_pt0_nofwd;   //!
   TBranch        *b_Mtaub;   //!
   TBranch        *b_nJets_OR_DL1r_77_pt40;   //!
   TBranch        *b_nJets_OR_nTaus_OR_pt40;   //!
   TBranch        *b_MLepMet;   //!
   TBranch        *b_MtLepMet;   //!
   TBranch        *b_MtLep0Met;   //!
   TBranch        *b_DRjj_lead;   //!
   TBranch        *b_mjj_lead;   //!
   TBranch        *b_mjjj_lead;   //!
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
   TBranch        *b_Mllmet;   //!
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
   TBranch        *b_sumPsbtag85;   //!
   TBranch        *b_jet_pt0_nofwd;   //!
   TBranch        *b_jet_pt1_nofwd;   //!
   TBranch        *b_jet_pt6_nofwd;   //!
   TBranch        *b_jet_pt0_nonbtag;   //!
   TBranch        *b_minDeltaR_J_bJ;   //!
   TBranch        *b_l2SS1tau;   //!
   TBranch        *b_IFFClass_lep_0;   //!
   TBranch        *b_IFFClass_lep_1;   //!
   TBranch        *b_IFFClass_lep_2;   //!
   TBranch        *b_IFFClass_lep_3;   //!
   TBranch        *b_IFFClass_lep_4;   //!
   TBranch        *b_IFFClass_lep_5;   //!
   TBranch        *b_ttHMLClass_lep_0;   //!
   TBranch        *b_ttHMLClass_lep_1;   //!
   TBranch        *b_ttHMLClass_lep_2;   //!
   TBranch        *b_N_IFF_Unclassified;   //!
   TBranch        *b_N_IFF_KnownUnknown;   //!
   TBranch        *b_N_IFF_Prompt;   //!
   TBranch        *b_N_IFF_QmisID;   //!
   TBranch        *b_N_IFF_MatConv;   //!
   TBranch        *b_N_IFF_IntConv;   //!
   TBranch        *b_N_IFF_Bdecays;   //!
   TBranch        *b_N_IFF_Cdecays;   //!
   TBranch        *b_N_IFF_LightHadDecays;   //!
   TBranch        *b_N_IFF_EfromMu;   //!
   TBranch        *b_N_IFF_TauDecays;   //!
   TBranch        *b_num_Zee_best;   //!
   TBranch        *b_num_Zmm_best;   //!
   TBranch        *b_lepSF_PLIV_Prompt_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0;   //!
   TBranch        *b_lepSF_PLIV_Prompt_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1;   //!
   TBranch        *b_lepSF_PLIV_Prompt_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_statError_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_muSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_weight_jvt__1up;   //!
   TBranch        *b_weight_jvt__1down;   //!
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
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_Reco_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_Reco_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ID_LooseAndBLayerLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ID_TightLH_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ID_LooseAndBLayerLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_ID_TightLH_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_Iso_FCLoose_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_El_Iso_FCLoose_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_TTVA_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_TTVA_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_TTVA_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_TTVA_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_STAT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_DOWN_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_UP_AT;   //!
   TBranch        *b_weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_DOWN_AT;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down;   //!
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
   TBranch        *b_weight_tauSFRNNMedium_TAU_SF_NOMINAL;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_SYST_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RNNID_SYST_DOWN;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RECO_TOTAL_UP;   //!
   TBranch        *b_weight_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_TAU_SF_NOMINAL;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_SYST_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RNNID_SYST_DOWN;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RECO_TOTAL_UP;   //!
   TBranch        *b_weight_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down;   //!
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
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_onelep_type;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_quadlep_type;   //!
   TBranch        *b_fivelep_type;   //!
   TBranch        *b_sixlep_type;   //!
   TBranch        *b_multilepornone_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_Mll01;   //!
   TBranch        *b_Ptll01;   //!
   TBranch        *b_DRll01;   //!
   TBranch        *b_Mlll012;   //!
   TBranch        *b_Mllll0123;   //!
   TBranch        *b_Mllll0124;   //!
   TBranch        *b_Mllll0125;   //!
   TBranch        *b_Mlll013;   //!
   TBranch        *b_Mllll0134;   //!
   TBranch        *b_Mllll0135;   //!
   TBranch        *b_Mlll014;   //!
   TBranch        *b_Mllll0145;   //!
   TBranch        *b_Mlll015;   //!
   TBranch        *b_Mll02;   //!
   TBranch        *b_Ptll02;   //!
   TBranch        *b_DRll02;   //!
   TBranch        *b_Mlll023;   //!
   TBranch        *b_Mllll0234;   //!
   TBranch        *b_Mllll0235;   //!
   TBranch        *b_Mlll024;   //!
   TBranch        *b_Mllll0245;   //!
   TBranch        *b_Mlll025;   //!
   TBranch        *b_Mll03;   //!
   TBranch        *b_Ptll03;   //!
   TBranch        *b_DRll03;   //!
   TBranch        *b_Mlll034;   //!
   TBranch        *b_Mllll0345;   //!
   TBranch        *b_Mlll035;   //!
   TBranch        *b_Mll04;   //!
   TBranch        *b_Ptll04;   //!
   TBranch        *b_DRll04;   //!
   TBranch        *b_Mlll045;   //!
   TBranch        *b_Mll05;   //!
   TBranch        *b_Ptll05;   //!
   TBranch        *b_DRll05;   //!
   TBranch        *b_Mll12;   //!
   TBranch        *b_Ptll12;   //!
   TBranch        *b_DRll12;   //!
   TBranch        *b_Mlll123;   //!
   TBranch        *b_Mllll1234;   //!
   TBranch        *b_Mllll1235;   //!
   TBranch        *b_Mlll124;   //!
   TBranch        *b_Mllll1245;   //!
   TBranch        *b_Mlll125;   //!
   TBranch        *b_Mll13;   //!
   TBranch        *b_Ptll13;   //!
   TBranch        *b_DRll13;   //!
   TBranch        *b_Mlll134;   //!
   TBranch        *b_Mllll1345;   //!
   TBranch        *b_Mlll135;   //!
   TBranch        *b_Mll14;   //!
   TBranch        *b_Ptll14;   //!
   TBranch        *b_DRll14;   //!
   TBranch        *b_Mlll145;   //!
   TBranch        *b_Mll15;   //!
   TBranch        *b_Ptll15;   //!
   TBranch        *b_DRll15;   //!
   TBranch        *b_Mll23;   //!
   TBranch        *b_Ptll23;   //!
   TBranch        *b_DRll23;   //!
   TBranch        *b_Mlll234;   //!
   TBranch        *b_Mllll2345;   //!
   TBranch        *b_Mlll235;   //!
   TBranch        *b_Mll24;   //!
   TBranch        *b_Ptll24;   //!
   TBranch        *b_DRll24;   //!
   TBranch        *b_Mlll245;   //!
   TBranch        *b_Mll25;   //!
   TBranch        *b_Ptll25;   //!
   TBranch        *b_DRll25;   //!
   TBranch        *b_Mll34;   //!
   TBranch        *b_Ptll34;   //!
   TBranch        *b_DRll34;   //!
   TBranch        *b_Mlll345;   //!
   TBranch        *b_Mll35;   //!
   TBranch        *b_Ptll35;   //!
   TBranch        *b_DRll35;   //!
   TBranch        *b_Mll45;   //!
   TBranch        *b_Ptll45;   //!
   TBranch        *b_DRll45;   //!
   TBranch        *b_best_Z_Mll;   //!
   TBranch        *b_best_Z_other_MtLepMet;   //!
   TBranch        *b_best_Z_other_Mll;   //!
   TBranch        *b_minOSSFMll;   //!
   TBranch        *b_minOSMll;   //!
   TBranch        *b_Mlt00;   //!
   TBranch        *b_Mlt01;   //!
   TBranch        *b_Mlt10;   //!
   TBranch        *b_Mlt11;   //!
   TBranch        *b_Mtt01;   //!
   TBranch        *b_MTlmet;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_nJets_OR_DL1r_85;   //!
   TBranch        *b_nJets_OR_DL1r_60;   //!
   TBranch        *b_nJets_OR_DL1r_77;   //!
   TBranch        *b_nJets_OR_DL1r_70;   //!
   TBranch        *b_nTaus_OR_Pt25;   //!
   TBranch        *b_nTaus_OR;   //!
   TBranch        *b_nTaus_OR_Medium;   //!
   TBranch        *b_nTaus_OR_Tight;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_HT_lep;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_HT_taus;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Index_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_EtaBE2_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_d0_0;   //!
   TBranch        *b_lep_z0_0;   //!
   TBranch        *b_lep_vz_0;   //!
   TBranch        *b_lep_deltaz0_0;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isMediumLH_0;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isTight_0;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isLoose_0;   //!
   TBranch        *b_lep_isHighPt_0;   //!
   TBranch        *b_lep_isolationFCLoose_0;   //!
   TBranch        *b_lep_isolationPLImprovedTight_0;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_0;   //!
   TBranch        *b_lep_isolationFCTight_0;   //!
   TBranch        *b_lep_isolationLoose_0;   //!
   TBranch        *b_lep_isolationGradient_0;   //!
   TBranch        *b_lep_isolationGradientLoose_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_0;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_0;   //!
   TBranch        *b_lep_isolationPflowTight_0;   //!
   TBranch        *b_lep_isolationPflowLoose_0;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_0;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_0;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_0;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_0;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_0;   //!
   TBranch        *b_lep_isolationTight_FixedRad_0;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_0;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_0;   //!
   TBranch        *b_lep_isolationTight_VarRad_0;   //!
   TBranch        *b_lep_isolationLoose_VarRad_0;   //!
   TBranch        *b_lep_plvWP_Loose_0;   //!
   TBranch        *b_lep_plvWP_Tight_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0;   //!
   TBranch        *b_lep_isTrigMatchDLT_0;   //!
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
   TBranch        *b_lep_SeparationMinDCT_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_0;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_0;   //!
   TBranch        *b_lep_DFCommonSimpleMee_0;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_0;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_0;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_0;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_0;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_0;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_0;   //!
   TBranch        *b_lep_DFCommonJetDr_0;   //!
   TBranch        *b_lep_chargeIDBDTLoose_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_0;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_0;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_0;   //!
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
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_AnpTruthType_0;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_truthStatus_0;   //!
   TBranch        *b_lep_truthParentType_0;   //!
   TBranch        *b_lep_truthParentOrigin_0;   //!
   TBranch        *b_lep_truthParentPdgId_0;   //!
   TBranch        *b_lep_truthParentRealPdgId_0;   //!
   TBranch        *b_lep_truthParentStatus_0;   //!
   TBranch        *b_lep_truthParentBarcode_0;   //!
   TBranch        *b_lep_truthParentIsCHadron_0;   //!
   TBranch        *b_lep_truthParentIsBHadron_0;   //!
   TBranch        *b_lep_truthHasTopInChain_0;   //!
   TBranch        *b_lep_truthParentPt_0;   //!
   TBranch        *b_lep_truthParentEta_0;   //!
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
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_0;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_0;   //!
   TBranch        *b_lep_SF_El_PLVTight_0;   //!
   TBranch        *b_lep_SF_El_PLVLoose_0;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_0;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_0;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_0;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_0;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_0;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_0;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_0;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_0;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_0;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_0;   //!
   TBranch        *b_lep_SF_CombinedLoose_0;   //!
   TBranch        *b_lep_SF_CombinedTight_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Index_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_EtaBE2_1;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_d0_1;   //!
   TBranch        *b_lep_z0_1;   //!
   TBranch        *b_lep_vz_1;   //!
   TBranch        *b_lep_deltaz0_1;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isMediumLH_1;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isTight_1;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isLoose_1;   //!
   TBranch        *b_lep_isHighPt_1;   //!
   TBranch        *b_lep_isolationFCLoose_1;   //!
   TBranch        *b_lep_isolationPLImprovedTight_1;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_1;   //!
   TBranch        *b_lep_isolationFCTight_1;   //!
   TBranch        *b_lep_isolationLoose_1;   //!
   TBranch        *b_lep_isolationGradient_1;   //!
   TBranch        *b_lep_isolationGradientLoose_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_1;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_1;   //!
   TBranch        *b_lep_isolationPflowTight_1;   //!
   TBranch        *b_lep_isolationPflowLoose_1;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_1;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_1;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_1;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_1;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_1;   //!
   TBranch        *b_lep_isolationTight_FixedRad_1;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_1;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_1;   //!
   TBranch        *b_lep_isolationTight_VarRad_1;   //!
   TBranch        *b_lep_isolationLoose_VarRad_1;   //!
   TBranch        *b_lep_plvWP_Loose_1;   //!
   TBranch        *b_lep_plvWP_Tight_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1;   //!
   TBranch        *b_lep_isTrigMatchDLT_1;   //!
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
   TBranch        *b_lep_SeparationMinDCT_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_1;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_1;   //!
   TBranch        *b_lep_DFCommonSimpleMee_1;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_1;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_1;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_1;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_1;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_1;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_1;   //!
   TBranch        *b_lep_DFCommonJetDr_1;   //!
   TBranch        *b_lep_chargeIDBDTLoose_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_1;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_1;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_1;   //!
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
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_AnpTruthType_1;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_truthStatus_1;   //!
   TBranch        *b_lep_truthParentType_1;   //!
   TBranch        *b_lep_truthParentOrigin_1;   //!
   TBranch        *b_lep_truthParentPdgId_1;   //!
   TBranch        *b_lep_truthParentRealPdgId_1;   //!
   TBranch        *b_lep_truthParentStatus_1;   //!
   TBranch        *b_lep_truthParentBarcode_1;   //!
   TBranch        *b_lep_truthParentIsCHadron_1;   //!
   TBranch        *b_lep_truthParentIsBHadron_1;   //!
   TBranch        *b_lep_truthHasTopInChain_1;   //!
   TBranch        *b_lep_truthParentPt_1;   //!
   TBranch        *b_lep_truthParentEta_1;   //!
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
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_1;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_1;   //!
   TBranch        *b_lep_SF_El_PLVTight_1;   //!
   TBranch        *b_lep_SF_El_PLVLoose_1;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_1;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_1;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_1;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_1;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_1;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_1;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_1;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_1;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_1;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_1;   //!
   TBranch        *b_lep_SF_CombinedLoose_1;   //!
   TBranch        *b_lep_SF_CombinedTight_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Index_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_EtaBE2_2;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_d0_2;   //!
   TBranch        *b_lep_z0_2;   //!
   TBranch        *b_lep_vz_2;   //!
   TBranch        *b_lep_deltaz0_2;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isMediumLH_2;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isTight_2;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isLoose_2;   //!
   TBranch        *b_lep_isHighPt_2;   //!
   TBranch        *b_lep_isolationFCLoose_2;   //!
   TBranch        *b_lep_isolationPLImprovedTight_2;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_2;   //!
   TBranch        *b_lep_isolationFCTight_2;   //!
   TBranch        *b_lep_isolationLoose_2;   //!
   TBranch        *b_lep_isolationGradient_2;   //!
   TBranch        *b_lep_isolationGradientLoose_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_2;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_2;   //!
   TBranch        *b_lep_isolationPflowTight_2;   //!
   TBranch        *b_lep_isolationPflowLoose_2;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_2;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_2;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_2;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_2;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_2;   //!
   TBranch        *b_lep_isolationTight_FixedRad_2;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_2;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_2;   //!
   TBranch        *b_lep_isolationTight_VarRad_2;   //!
   TBranch        *b_lep_isolationLoose_VarRad_2;   //!
   TBranch        *b_lep_plvWP_Loose_2;   //!
   TBranch        *b_lep_plvWP_Tight_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2;   //!
   TBranch        *b_lep_isTrigMatchDLT_2;   //!
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
   TBranch        *b_lep_SeparationMinDCT_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_2;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_2;   //!
   TBranch        *b_lep_DFCommonSimpleMee_2;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_2;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_2;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_2;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_2;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_2;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_2;   //!
   TBranch        *b_lep_DFCommonJetDr_2;   //!
   TBranch        *b_lep_chargeIDBDTLoose_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_2;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_2;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_2;   //!
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
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_AnpTruthType_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_truthStatus_2;   //!
   TBranch        *b_lep_truthParentType_2;   //!
   TBranch        *b_lep_truthParentOrigin_2;   //!
   TBranch        *b_lep_truthParentPdgId_2;   //!
   TBranch        *b_lep_truthParentRealPdgId_2;   //!
   TBranch        *b_lep_truthParentStatus_2;   //!
   TBranch        *b_lep_truthParentBarcode_2;   //!
   TBranch        *b_lep_truthParentIsCHadron_2;   //!
   TBranch        *b_lep_truthParentIsBHadron_2;   //!
   TBranch        *b_lep_truthHasTopInChain_2;   //!
   TBranch        *b_lep_truthParentPt_2;   //!
   TBranch        *b_lep_truthParentEta_2;   //!
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
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_2;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_2;   //!
   TBranch        *b_lep_SF_El_PLVTight_2;   //!
   TBranch        *b_lep_SF_El_PLVLoose_2;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_2;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_2;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_2;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_2;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_2;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_2;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_2;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_2;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_2;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_2;   //!
   TBranch        *b_lep_SF_CombinedLoose_2;   //!
   TBranch        *b_lep_SF_CombinedTight_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Index_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_EtaBE2_3;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_sigd0PV_3;   //!
   TBranch        *b_lep_Z0SinTheta_3;   //!
   TBranch        *b_lep_d0_3;   //!
   TBranch        *b_lep_z0_3;   //!
   TBranch        *b_lep_vz_3;   //!
   TBranch        *b_lep_deltaz0_3;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isMediumLH_3;   //!
   TBranch        *b_lep_isLooseLH_3;   //!
   TBranch        *b_lep_isTight_3;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isLoose_3;   //!
   TBranch        *b_lep_isHighPt_3;   //!
   TBranch        *b_lep_isolationFCLoose_3;   //!
   TBranch        *b_lep_isolationPLImprovedTight_3;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_3;   //!
   TBranch        *b_lep_isolationFCTight_3;   //!
   TBranch        *b_lep_isolationLoose_3;   //!
   TBranch        *b_lep_isolationGradient_3;   //!
   TBranch        *b_lep_isolationGradientLoose_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_3;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_3;   //!
   TBranch        *b_lep_isolationPflowTight_3;   //!
   TBranch        *b_lep_isolationPflowLoose_3;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_3;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_3;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_3;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_3;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_3;   //!
   TBranch        *b_lep_isolationTight_FixedRad_3;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_3;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_3;   //!
   TBranch        *b_lep_isolationTight_VarRad_3;   //!
   TBranch        *b_lep_isolationLoose_VarRad_3;   //!
   TBranch        *b_lep_plvWP_Loose_3;   //!
   TBranch        *b_lep_plvWP_Tight_3;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_3;   //!
   TBranch        *b_lep_isTrigMatchDLT_3;   //!
   TBranch        *b_lep_isPrompt_3;   //!
   TBranch        *b_lep_isFakeLep_3;   //!
   TBranch        *b_lep_isQMisID_3;   //!
   TBranch        *b_lep_isConvPh_3;   //!
   TBranch        *b_lep_isExtConvPh_3;   //!
   TBranch        *b_lep_isIntConvPh_3;   //!
   TBranch        *b_lep_isISR_FSR_Ph_3;   //!
   TBranch        *b_lep_isBrems_3;   //!
   TBranch        *b_lep_nTrackParticles_3;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_3;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_3;   //!
   TBranch        *b_lep_RadiusCO_3;   //!
   TBranch        *b_lep_RadiusCOX_3;   //!
   TBranch        *b_lep_RadiusCOY_3;   //!
   TBranch        *b_lep_SeparationMinDCT_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_3;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_3;   //!
   TBranch        *b_lep_DFCommonSimpleMee_3;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_3;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_3;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_3;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_3;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_3;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_3;   //!
   TBranch        *b_lep_DFCommonJetDr_3;   //!
   TBranch        *b_lep_chargeIDBDTLoose_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_3;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_3;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_3;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_3;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_3;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_3;   //!
   TBranch        *b_lep_isTruthMatched_3;   //!
   TBranch        *b_lep_AnpTruthType_3;   //!
   TBranch        *b_lep_truthType_3;   //!
   TBranch        *b_lep_truthOrigin_3;   //!
   TBranch        *b_lep_truthPdgId_3;   //!
   TBranch        *b_lep_truthStatus_3;   //!
   TBranch        *b_lep_truthParentType_3;   //!
   TBranch        *b_lep_truthParentOrigin_3;   //!
   TBranch        *b_lep_truthParentPdgId_3;   //!
   TBranch        *b_lep_truthParentRealPdgId_3;   //!
   TBranch        *b_lep_truthParentStatus_3;   //!
   TBranch        *b_lep_truthParentBarcode_3;   //!
   TBranch        *b_lep_truthParentIsCHadron_3;   //!
   TBranch        *b_lep_truthParentIsBHadron_3;   //!
   TBranch        *b_lep_truthHasTopInChain_3;   //!
   TBranch        *b_lep_truthParentPt_3;   //!
   TBranch        *b_lep_truthParentEta_3;   //!
   TBranch        *b_lep_truthPt_3;   //!
   TBranch        *b_lep_truthEta_3;   //!
   TBranch        *b_lep_truthPhi_3;   //!
   TBranch        *b_lep_truthM_3;   //!
   TBranch        *b_lep_truthE_3;   //!
   TBranch        *b_lep_truthRapidity_3;   //!
   TBranch        *b_lep_ambiguityType_3;   //!
   TBranch        *b_lep_nInnerPix_3;   //!
   TBranch        *b_lep_firstEgMotherPdgId_3;   //!
   TBranch        *b_lep_firstEgMotherTruthType_3;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_lastEgMotherPdgId_3;   //!
   TBranch        *b_lep_lastEgMotherTruthType_3;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_3;   //!
   TBranch        *b_lep_SF_El_Reco_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_3;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_3;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_3;   //!
   TBranch        *b_lep_SF_El_PLVTight_3;   //!
   TBranch        *b_lep_SF_El_PLVLoose_3;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_3;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_3;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_3;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_3;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_3;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_3;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_3;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_3;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_3;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_3;   //!
   TBranch        *b_lep_SF_CombinedLoose_3;   //!
   TBranch        *b_lep_SF_CombinedTight_3;   //!
   TBranch        *b_lep_ID_4;   //!
   TBranch        *b_lep_Index_4;   //!
   TBranch        *b_lep_Pt_4;   //!
   TBranch        *b_lep_E_4;   //!
   TBranch        *b_lep_Eta_4;   //!
   TBranch        *b_lep_EtaBE2_4;   //!
   TBranch        *b_lep_Phi_4;   //!
   TBranch        *b_lep_sigd0PV_4;   //!
   TBranch        *b_lep_Z0SinTheta_4;   //!
   TBranch        *b_lep_d0_4;   //!
   TBranch        *b_lep_z0_4;   //!
   TBranch        *b_lep_vz_4;   //!
   TBranch        *b_lep_deltaz0_4;   //!
   TBranch        *b_lep_isTightLH_4;   //!
   TBranch        *b_lep_isMediumLH_4;   //!
   TBranch        *b_lep_isLooseLH_4;   //!
   TBranch        *b_lep_isTight_4;   //!
   TBranch        *b_lep_isMedium_4;   //!
   TBranch        *b_lep_isLoose_4;   //!
   TBranch        *b_lep_isHighPt_4;   //!
   TBranch        *b_lep_isolationFCLoose_4;   //!
   TBranch        *b_lep_isolationPLImprovedTight_4;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_4;   //!
   TBranch        *b_lep_isolationFCTight_4;   //!
   TBranch        *b_lep_isolationLoose_4;   //!
   TBranch        *b_lep_isolationGradient_4;   //!
   TBranch        *b_lep_isolationGradientLoose_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_4;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_4;   //!
   TBranch        *b_lep_isolationPflowTight_4;   //!
   TBranch        *b_lep_isolationPflowLoose_4;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_4;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_4;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_4;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_4;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_4;   //!
   TBranch        *b_lep_isolationTight_FixedRad_4;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_4;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_4;   //!
   TBranch        *b_lep_isolationTight_VarRad_4;   //!
   TBranch        *b_lep_isolationLoose_VarRad_4;   //!
   TBranch        *b_lep_plvWP_Loose_4;   //!
   TBranch        *b_lep_plvWP_Tight_4;   //!
   TBranch        *b_lep_isTrigMatch_4;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_4;   //!
   TBranch        *b_lep_isTrigMatchDLT_4;   //!
   TBranch        *b_lep_isPrompt_4;   //!
   TBranch        *b_lep_isFakeLep_4;   //!
   TBranch        *b_lep_isQMisID_4;   //!
   TBranch        *b_lep_isConvPh_4;   //!
   TBranch        *b_lep_isExtConvPh_4;   //!
   TBranch        *b_lep_isIntConvPh_4;   //!
   TBranch        *b_lep_isISR_FSR_Ph_4;   //!
   TBranch        *b_lep_isBrems_4;   //!
   TBranch        *b_lep_nTrackParticles_4;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_4;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_4;   //!
   TBranch        *b_lep_RadiusCO_4;   //!
   TBranch        *b_lep_RadiusCOX_4;   //!
   TBranch        *b_lep_RadiusCOY_4;   //!
   TBranch        *b_lep_SeparationMinDCT_4;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_4;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_4;   //!
   TBranch        *b_lep_DFCommonSimpleMee_4;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_4;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_4;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_4;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_4;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_4;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_4;   //!
   TBranch        *b_lep_DFCommonJetDr_4;   //!
   TBranch        *b_lep_chargeIDBDTLoose_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_4;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_4;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_4;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_4;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_4;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_4;   //!
   TBranch        *b_lep_isTruthMatched_4;   //!
   TBranch        *b_lep_AnpTruthType_4;   //!
   TBranch        *b_lep_truthType_4;   //!
   TBranch        *b_lep_truthOrigin_4;   //!
   TBranch        *b_lep_truthPdgId_4;   //!
   TBranch        *b_lep_truthStatus_4;   //!
   TBranch        *b_lep_truthParentType_4;   //!
   TBranch        *b_lep_truthParentOrigin_4;   //!
   TBranch        *b_lep_truthParentPdgId_4;   //!
   TBranch        *b_lep_truthParentRealPdgId_4;   //!
   TBranch        *b_lep_truthParentStatus_4;   //!
   TBranch        *b_lep_truthParentBarcode_4;   //!
   TBranch        *b_lep_truthParentIsCHadron_4;   //!
   TBranch        *b_lep_truthParentIsBHadron_4;   //!
   TBranch        *b_lep_truthHasTopInChain_4;   //!
   TBranch        *b_lep_truthParentPt_4;   //!
   TBranch        *b_lep_truthParentEta_4;   //!
   TBranch        *b_lep_truthPt_4;   //!
   TBranch        *b_lep_truthEta_4;   //!
   TBranch        *b_lep_truthPhi_4;   //!
   TBranch        *b_lep_truthM_4;   //!
   TBranch        *b_lep_truthE_4;   //!
   TBranch        *b_lep_truthRapidity_4;   //!
   TBranch        *b_lep_ambiguityType_4;   //!
   TBranch        *b_lep_nInnerPix_4;   //!
   TBranch        *b_lep_firstEgMotherPdgId_4;   //!
   TBranch        *b_lep_firstEgMotherTruthType_4;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_4;   //!
   TBranch        *b_lep_lastEgMotherPdgId_4;   //!
   TBranch        *b_lep_lastEgMotherTruthType_4;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_4;   //!
   TBranch        *b_lep_SF_El_Reco_AT_4;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_4;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_4;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_4;   //!
   TBranch        *b_lep_SF_El_PLVTight_4;   //!
   TBranch        *b_lep_SF_El_PLVLoose_4;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_4;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_4;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_4;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_4;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_4;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_4;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_4;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_4;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_4;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_4;   //!
   TBranch        *b_lep_SF_CombinedLoose_4;   //!
   TBranch        *b_lep_SF_CombinedTight_4;   //!
   TBranch        *b_lep_ID_5;   //!
   TBranch        *b_lep_Index_5;   //!
   TBranch        *b_lep_Pt_5;   //!
   TBranch        *b_lep_E_5;   //!
   TBranch        *b_lep_Eta_5;   //!
   TBranch        *b_lep_EtaBE2_5;   //!
   TBranch        *b_lep_Phi_5;   //!
   TBranch        *b_lep_sigd0PV_5;   //!
   TBranch        *b_lep_Z0SinTheta_5;   //!
   TBranch        *b_lep_d0_5;   //!
   TBranch        *b_lep_z0_5;   //!
   TBranch        *b_lep_vz_5;   //!
   TBranch        *b_lep_deltaz0_5;   //!
   TBranch        *b_lep_isTightLH_5;   //!
   TBranch        *b_lep_isMediumLH_5;   //!
   TBranch        *b_lep_isLooseLH_5;   //!
   TBranch        *b_lep_isTight_5;   //!
   TBranch        *b_lep_isMedium_5;   //!
   TBranch        *b_lep_isLoose_5;   //!
   TBranch        *b_lep_isHighPt_5;   //!
   TBranch        *b_lep_isolationFCLoose_5;   //!
   TBranch        *b_lep_isolationPLImprovedTight_5;   //!
   TBranch        *b_lep_isolationPLImprovedVeryTight_5;   //!
   TBranch        *b_lep_isolationFCTight_5;   //!
   TBranch        *b_lep_isolationLoose_5;   //!
   TBranch        *b_lep_isolationGradient_5;   //!
   TBranch        *b_lep_isolationGradientLoose_5;   //!
   TBranch        *b_lep_isolationTightTrackOnly_5;   //!
   TBranch        *b_lep_isolationHighPtCaloOnly_5;   //!
   TBranch        *b_lep_isolationPflowTight_5;   //!
   TBranch        *b_lep_isolationPflowLoose_5;   //!
   TBranch        *b_lep_isolationPflowTight_VarRad_5;   //!
   TBranch        *b_lep_isolationPflowTight_FixedRad_5;   //!
   TBranch        *b_lep_isolationPflowLoose_VarRad_5;   //!
   TBranch        *b_lep_isolationPflowLoose_FixedRad_5;   //!
   TBranch        *b_lep_isolationHighPtTrackOnly_5;   //!
   TBranch        *b_lep_isolationTight_FixedRad_5;   //!
   TBranch        *b_lep_isolationLoose_FixedRad_5;   //!
   TBranch        *b_lep_isolationTightTrackOnly_VarRad_5;   //!
   TBranch        *b_lep_isolationTightTrackOnly_FixedRad_5;   //!
   TBranch        *b_lep_isolationTight_VarRad_5;   //!
   TBranch        *b_lep_isolationLoose_VarRad_5;   //!
   TBranch        *b_lep_plvWP_Loose_5;   //!
   TBranch        *b_lep_plvWP_Tight_5;   //!
   TBranch        *b_lep_isTrigMatch_5;   //!
   TBranch        *b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_5;   //!
   TBranch        *b_lep_isTrigMatchDLT_5;   //!
   TBranch        *b_lep_isPrompt_5;   //!
   TBranch        *b_lep_isFakeLep_5;   //!
   TBranch        *b_lep_isQMisID_5;   //!
   TBranch        *b_lep_isConvPh_5;   //!
   TBranch        *b_lep_isExtConvPh_5;   //!
   TBranch        *b_lep_isIntConvPh_5;   //!
   TBranch        *b_lep_isISR_FSR_Ph_5;   //!
   TBranch        *b_lep_isBrems_5;   //!
   TBranch        *b_lep_nTrackParticles_5;   //!
   TBranch        *b_lep_Mtrktrk_atPV_CO_5;   //!
   TBranch        *b_lep_Mtrktrk_atConvV_CO_5;   //!
   TBranch        *b_lep_RadiusCO_5;   //!
   TBranch        *b_lep_RadiusCOX_5;   //!
   TBranch        *b_lep_RadiusCOY_5;   //!
   TBranch        *b_lep_SeparationMinDCT_5;   //!
   TBranch        *b_lep_DFCommonSimpleConvRadius_5;   //!
   TBranch        *b_lep_DFCommonSimpleConvPhi_5;   //!
   TBranch        *b_lep_DFCommonSimpleMee_5;   //!
   TBranch        *b_lep_DFCommonSimpleMeeAtVtx_5;   //!
   TBranch        *b_lep_DFCommonSimpleSeparation_5;   //!
   TBranch        *b_lep_DFCommonAddAmbiguity_5;   //!
   TBranch        *b_lep_DFCommonProdTrueRadius_5;   //!
   TBranch        *b_lep_DFCommonProdTruePhi_5;   //!
   TBranch        *b_lep_DFCommonProdTrueZ_5;   //!
   TBranch        *b_lep_DFCommonJetDr_5;   //!
   TBranch        *b_lep_chargeIDBDTLoose_5;   //!
   TBranch        *b_lep_chargeIDBDTResult_5;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_loose_5;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_medium_5;   //!
   TBranch        *b_lep_chargeIDBDTResult_recalc_rel207_tight_5;   //!
   TBranch        *b_lep_promptLeptonIso_TagWeight_5;   //!
   TBranch        *b_lep_promptLeptonVeto_TagWeight_5;   //!
   TBranch        *b_lep_promptLeptonImprovedVeto_TagWeight_5;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoBARR_TagWeight_5;   //!
   TBranch        *b_lep_promptLeptonImprovedVetoECAP_TagWeight_5;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_MVAXBin_5;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_PtFrac_5;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_DRlj_5;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_reltopoetcone30_5;   //!
   TBranch        *b_lep_PromptLeptonImprovedInput_relptvarcone30_5;   //!
   TBranch        *b_lep_PromptLeptonRNN_prompt_5;   //!
   TBranch        *b_lep_isTruthMatched_5;   //!
   TBranch        *b_lep_AnpTruthType_5;   //!
   TBranch        *b_lep_truthType_5;   //!
   TBranch        *b_lep_truthOrigin_5;   //!
   TBranch        *b_lep_truthPdgId_5;   //!
   TBranch        *b_lep_truthStatus_5;   //!
   TBranch        *b_lep_truthParentType_5;   //!
   TBranch        *b_lep_truthParentOrigin_5;   //!
   TBranch        *b_lep_truthParentPdgId_5;   //!
   TBranch        *b_lep_truthParentRealPdgId_5;   //!
   TBranch        *b_lep_truthParentStatus_5;   //!
   TBranch        *b_lep_truthParentBarcode_5;   //!
   TBranch        *b_lep_truthParentIsCHadron_5;   //!
   TBranch        *b_lep_truthParentIsBHadron_5;   //!
   TBranch        *b_lep_truthHasTopInChain_5;   //!
   TBranch        *b_lep_truthParentPt_5;   //!
   TBranch        *b_lep_truthParentEta_5;   //!
   TBranch        *b_lep_truthPt_5;   //!
   TBranch        *b_lep_truthEta_5;   //!
   TBranch        *b_lep_truthPhi_5;   //!
   TBranch        *b_lep_truthM_5;   //!
   TBranch        *b_lep_truthE_5;   //!
   TBranch        *b_lep_truthRapidity_5;   //!
   TBranch        *b_lep_ambiguityType_5;   //!
   TBranch        *b_lep_nInnerPix_5;   //!
   TBranch        *b_lep_firstEgMotherPdgId_5;   //!
   TBranch        *b_lep_firstEgMotherTruthType_5;   //!
   TBranch        *b_lep_firstEgMotherTruthOrigin_5;   //!
   TBranch        *b_lep_lastEgMotherPdgId_5;   //!
   TBranch        *b_lep_lastEgMotherTruthType_5;   //!
   TBranch        *b_lep_lastEgMotherTruthOrigin_5;   //!
   TBranch        *b_lep_SF_El_Reco_AT_5;   //!
   TBranch        *b_lep_SF_El_ID_LooseAndBLayerLH_AT_5;   //!
   TBranch        *b_lep_SF_El_ID_TightLH_AT_5;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_AT_5;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_5;   //!
   TBranch        *b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_5;   //!
   TBranch        *b_lep_SF_El_FCLooseTightLHQMisID_5;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_5;   //!
   TBranch        *b_lep_SF_El_Iso_FCLoose_TightLH_5;   //!
   TBranch        *b_lep_SF_El_PLVTight_QmisID_5;   //!
   TBranch        *b_lep_SF_El_PLVTight_5;   //!
   TBranch        *b_lep_SF_El_PLVLoose_5;   //!
   TBranch        *b_lep_SF_El_ID_MediumLH_5;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTight_TightLH_5;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_5;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_5;   //!
   TBranch        *b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_5;   //!
   TBranch        *b_lep_SF_Mu_TTVA_AT_5;   //!
   TBranch        *b_lep_SF_Mu_ID_Loose_AT_5;   //!
   TBranch        *b_lep_SF_Mu_ID_Medium_AT_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_FCLoose_AT_5;   //!
   TBranch        *b_lep_SF_Mu_ID_Tight_5;   //!
   TBranch        *b_lep_SF_Mu_ID_HighPt_5;   //!
   TBranch        *b_lep_SF_Mu_PLVTight_5;   //!
   TBranch        *b_lep_SF_Mu_PLVLoose_5;   //!
   TBranch        *b_lep_SF_Mu_PLIV_MnotT_5;   //!
   TBranch        *b_lep_SF_Mu_PLIV_T_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_FixedRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowTight_VarRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_VarRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_PflowLoose_FixedRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_HighPtTrackOnly_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_FixedRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_FixedRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_Loose_VarRad_5;   //!
   TBranch        *b_lep_SF_Mu_Iso_Tight_VarRad_5;   //!
   TBranch        *b_lep_SF_CombinedLoose_5;   //!
   TBranch        *b_lep_SF_CombinedTight_5;   //!
   TBranch        *b_taus_pt_0;   //!
   TBranch        *b_taus_eta_0;   //!
   TBranch        *b_taus_phi_0;   //!
   TBranch        *b_taus_charge_0;   //!
   TBranch        *b_taus_E_0;   //!
   TBranch        *b_taus_width_0;   //!
   TBranch        *b_taus_decayMode_0;   //!
   TBranch        *b_taus_BDTJetScore_0;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_0;   //!
   TBranch        *b_taus_JetBDTSigLoose_0;   //!
   TBranch        *b_taus_JetBDTSigMedium_0;   //!
   TBranch        *b_taus_JetBDTSigTight_0;   //!
   TBranch        *b_taus_RNNJetScore_0;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_0;   //!
   TBranch        *b_taus_JetRNNSigLoose_0;   //!
   TBranch        *b_taus_JetRNNSigMedium_0;   //!
   TBranch        *b_taus_JetRNNSigTight_0;   //!
   TBranch        *b_taus_numTrack_0;   //!
   TBranch        *b_taus_isHadronic_0;   //!
   TBranch        *b_taus_tagWeightBin_0;   //!
   TBranch        *b_taus_DL1r_0;   //!
   TBranch        *b_taus_fromPV_0;   //!
   TBranch        *b_taus_passJVT_0;   //!
   TBranch        *b_taus_passEleOLR_0;   //!
   TBranch        *b_taus_passEleBDT_0;   //!
   TBranch        *b_taus_passMuonOLR_0;   //!
   TBranch        *b_taus_isTruthMatched_0;   //!
   TBranch        *b_taus_truthOrigin_0;   //!
   TBranch        *b_taus_truthType_0;   //!
   TBranch        *b_taus_truthJetFlavour_0;   //!
   TBranch        *b_taus_truthNumCharge_0;   //!
   TBranch        *b_taus_truthPt_0;   //!
   TBranch        *b_taus_truthPtVis_0;   //!
   TBranch        *b_taus_passtau80L1TAU60_medium1_tracktwo_0;   //!
   TBranch        *b_taus_passtau125_medium1_tracktwo_0;   //!
   TBranch        *b_taus_passtau160_medium1_tracktwo_0;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwo_0;   //!
   TBranch        *b_taus_passtau25_medium1_tracktwoEF_0;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwoEF_0;   //!
   TBranch        *b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_0;   //!
   TBranch        *b_taus_pt_1;   //!
   TBranch        *b_taus_eta_1;   //!
   TBranch        *b_taus_phi_1;   //!
   TBranch        *b_taus_charge_1;   //!
   TBranch        *b_taus_E_1;   //!
   TBranch        *b_taus_width_1;   //!
   TBranch        *b_taus_decayMode_1;   //!
   TBranch        *b_taus_BDTJetScore_1;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_1;   //!
   TBranch        *b_taus_JetBDTSigLoose_1;   //!
   TBranch        *b_taus_JetBDTSigMedium_1;   //!
   TBranch        *b_taus_JetBDTSigTight_1;   //!
   TBranch        *b_taus_RNNJetScore_1;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_1;   //!
   TBranch        *b_taus_JetRNNSigLoose_1;   //!
   TBranch        *b_taus_JetRNNSigMedium_1;   //!
   TBranch        *b_taus_JetRNNSigTight_1;   //!
   TBranch        *b_taus_numTrack_1;   //!
   TBranch        *b_taus_isHadronic_1;   //!
   TBranch        *b_taus_tagWeightBin_1;   //!
   TBranch        *b_taus_DL1r_1;   //!
   TBranch        *b_taus_fromPV_1;   //!
   TBranch        *b_taus_passJVT_1;   //!
   TBranch        *b_taus_passEleOLR_1;   //!
   TBranch        *b_taus_passEleBDT_1;   //!
   TBranch        *b_taus_passMuonOLR_1;   //!
   TBranch        *b_taus_isTruthMatched_1;   //!
   TBranch        *b_taus_truthOrigin_1;   //!
   TBranch        *b_taus_truthType_1;   //!
   TBranch        *b_taus_truthJetFlavour_1;   //!
   TBranch        *b_taus_truthNumCharge_1;   //!
   TBranch        *b_taus_truthPt_1;   //!
   TBranch        *b_taus_truthPtVis_1;   //!
   TBranch        *b_taus_passtau80L1TAU60_medium1_tracktwo_1;   //!
   TBranch        *b_taus_passtau125_medium1_tracktwo_1;   //!
   TBranch        *b_taus_passtau160_medium1_tracktwo_1;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwo_1;   //!
   TBranch        *b_taus_passtau25_medium1_tracktwoEF_1;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwoEF_1;   //!
   TBranch        *b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_1;   //!
   TBranch        *b_taus_pt_2;   //!
   TBranch        *b_taus_eta_2;   //!
   TBranch        *b_taus_phi_2;   //!
   TBranch        *b_taus_charge_2;   //!
   TBranch        *b_taus_E_2;   //!
   TBranch        *b_taus_width_2;   //!
   TBranch        *b_taus_decayMode_2;   //!
   TBranch        *b_taus_BDTJetScore_2;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_2;   //!
   TBranch        *b_taus_JetBDTSigLoose_2;   //!
   TBranch        *b_taus_JetBDTSigMedium_2;   //!
   TBranch        *b_taus_JetBDTSigTight_2;   //!
   TBranch        *b_taus_RNNJetScore_2;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_2;   //!
   TBranch        *b_taus_JetRNNSigLoose_2;   //!
   TBranch        *b_taus_JetRNNSigMedium_2;   //!
   TBranch        *b_taus_JetRNNSigTight_2;   //!
   TBranch        *b_taus_numTrack_2;   //!
   TBranch        *b_taus_isHadronic_2;   //!
   TBranch        *b_taus_tagWeightBin_2;   //!
   TBranch        *b_taus_DL1r_2;   //!
   TBranch        *b_taus_fromPV_2;   //!
   TBranch        *b_taus_passJVT_2;   //!
   TBranch        *b_taus_passEleOLR_2;   //!
   TBranch        *b_taus_passEleBDT_2;   //!
   TBranch        *b_taus_passMuonOLR_2;   //!
   TBranch        *b_taus_isTruthMatched_2;   //!
   TBranch        *b_taus_truthOrigin_2;   //!
   TBranch        *b_taus_truthType_2;   //!
   TBranch        *b_taus_truthJetFlavour_2;   //!
   TBranch        *b_taus_truthNumCharge_2;   //!
   TBranch        *b_taus_truthPt_2;   //!
   TBranch        *b_taus_truthPtVis_2;   //!
   TBranch        *b_taus_passtau80L1TAU60_medium1_tracktwo_2;   //!
   TBranch        *b_taus_passtau125_medium1_tracktwo_2;   //!
   TBranch        *b_taus_passtau160_medium1_tracktwo_2;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwo_2;   //!
   TBranch        *b_taus_passtau25_medium1_tracktwoEF_2;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwoEF_2;   //!
   TBranch        *b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_2;   //!
   TBranch        *b_taus_pt_3;   //!
   TBranch        *b_taus_eta_3;   //!
   TBranch        *b_taus_phi_3;   //!
   TBranch        *b_taus_charge_3;   //!
   TBranch        *b_taus_E_3;   //!
   TBranch        *b_taus_width_3;   //!
   TBranch        *b_taus_decayMode_3;   //!
   TBranch        *b_taus_BDTJetScore_3;   //!
   TBranch        *b_taus_BDTJetScoreSigTrans_3;   //!
   TBranch        *b_taus_JetBDTSigLoose_3;   //!
   TBranch        *b_taus_JetBDTSigMedium_3;   //!
   TBranch        *b_taus_JetBDTSigTight_3;   //!
   TBranch        *b_taus_RNNJetScore_3;   //!
   TBranch        *b_taus_RNNJetScoreSigTrans_3;   //!
   TBranch        *b_taus_JetRNNSigLoose_3;   //!
   TBranch        *b_taus_JetRNNSigMedium_3;   //!
   TBranch        *b_taus_JetRNNSigTight_3;   //!
   TBranch        *b_taus_numTrack_3;   //!
   TBranch        *b_taus_isHadronic_3;   //!
   TBranch        *b_taus_tagWeightBin_3;   //!
   TBranch        *b_taus_DL1r_3;   //!
   TBranch        *b_taus_fromPV_3;   //!
   TBranch        *b_taus_passJVT_3;   //!
   TBranch        *b_taus_passEleOLR_3;   //!
   TBranch        *b_taus_passEleBDT_3;   //!
   TBranch        *b_taus_passMuonOLR_3;   //!
   TBranch        *b_taus_isTruthMatched_3;   //!
   TBranch        *b_taus_truthOrigin_3;   //!
   TBranch        *b_taus_truthType_3;   //!
   TBranch        *b_taus_truthJetFlavour_3;   //!
   TBranch        *b_taus_truthNumCharge_3;   //!
   TBranch        *b_taus_truthPt_3;   //!
   TBranch        *b_taus_truthPtVis_3;   //!
   TBranch        *b_taus_passtau80L1TAU60_medium1_tracktwo_3;   //!
   TBranch        *b_taus_passtau125_medium1_tracktwo_3;   //!
   TBranch        *b_taus_passtau160_medium1_tracktwo_3;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwo_3;   //!
   TBranch        *b_taus_passtau25_medium1_tracktwoEF_3;   //!
   TBranch        *b_taus_passtau160L1TAU100_medium1_tracktwoEF_3;   //!
   TBranch        *b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_3;   //!
   TBranch        *b_jets_pt;   //!
   TBranch        *b_jets_e;   //!
   TBranch        *b_jets_eta;   //!
   TBranch        *b_jets_phi;   //!
   TBranch        *b_jets_score_DL1r;   //!
   TBranch        *b_jets_btagFlag_DL1r_ContinuousBin;   //!
   TBranch        *b_jets_score_DL1r_pu;   //!
   TBranch        *b_jets_score_DL1r_pc;   //!
   TBranch        *b_jets_score_DL1r_pb;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_60;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_70;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_77;   //!
   TBranch        *b_jets_btagFlag_DL1r_FixedCutBEff_85;   //!
   TBranch        *b_jets_btag_JetVertexCharge_discriminant;   //!
   TBranch        *b_jets_ConeTruthLabelID;   //!
   TBranch        *b_jets_PartonTruthLabelID;   //!
   TBranch        *b_jets_isQuarkJet;   //!
   TBranch        *b_jets_isQuarkJetBDT;   //!
   TBranch        *b_jets_HadronConeExclExtendedTruthLabelID;   //!
   TBranch        *b_jets_HadronConeExclTruthLabelID;   //!
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
   TBranch        *b_custTrigSF_CombinedWPs_SLTorDLT;   //!
   TBranch        *b_custTrigSF_CombinedWPs_SLT;   //!
   TBranch        *b_custTrigSF_CombinedWPs_DLT;   //!
   TBranch        *b_custTrigMatch_CombinedWPs_SLTorDLT;   //!
   TBranch        *b_custTrigMatch_CombinedWPs_SLT;   //!
   TBranch        *b_custTrigMatch_CombinedWPs_DLT;   //!
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
   TBranch        *b_highpt_trubjet;   //!
   TBranch        *b_mvis_taub;   //!
   TBranch        *b_lqlq_decays;   //!
   TBranch        *b_VLL_type;   //!
   TBranch        *b_VLL_decaytype;   //!
   TBranch        *b_VLL_decayZdecays;   //!
   TBranch        *b_VLL_decayWdecays;   //!
   TBranch        *b_VLL_decayHdecays;   //!
   TBranch        *b_m_HF_Classification;   //!
   TBranch        *b_m_HF_ClassificationTop;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSFObjChannelCombined;   //!
   TBranch        *b_jvtSF_customOR;   //!
   TBranch        *b_bTagSF_weight_DL1r_60;   //!
   TBranch        *b_bTagSF_weight_DL1r_70;   //!
   TBranch        *b_bTagSF_weight_DL1r_77;   //!
   TBranch        *b_bTagSF_weight_DL1r_85;   //!
   TBranch        *b_bTagSF_weight_DL1r_Continuous;   //!
   
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
   jets_pt = 0;
   jets_e = 0;
   jets_eta = 0;
   jets_phi = 0;
   jets_score_DL1r = 0;
   jets_btagFlag_DL1r_ContinuousBin = 0;
   jets_score_DL1r_pu = 0;
   jets_score_DL1r_pc = 0;
   jets_score_DL1r_pb = 0;
   jets_btagFlag_DL1r_FixedCutBEff_60 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_70 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_77 = 0;
   jets_btagFlag_DL1r_FixedCutBEff_85 = 0;
   jets_btag_JetVertexCharge_discriminant = 0;
   jets_ConeTruthLabelID = 0;
   jets_PartonTruthLabelID = 0;
   jets_isQuarkJet = 0;
   jets_isQuarkJetBDT = 0;
   jets_HadronConeExclExtendedTruthLabelID = 0;
   jets_HadronConeExclTruthLabelID = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("filterDuplicateEvents", &filterDuplicateEvents, &b_filterDuplicateEvents);
   fChain->SetBranchAddress("totalEventsWeighted", &totalEventsWeighted, &b_totalEventsWeighted);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW", &totalEventsWeighted_weight_EW, &b_totalEventsWeighted_weight_EW);
   fChain->SetBranchAddress("totalEventsWeighted_weight_EW_mult", &totalEventsWeighted_weight_EW_mult, &b_totalEventsWeighted_weight_EW_mult);
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
   fChain->SetBranchAddress("xs", &xs, &b_xs);
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
   fChain->SetBranchAddress("MtauMet", &MtauMet, &b_MtauMet);
   fChain->SetBranchAddress("NtauJet", &NtauJet, &b_NtauJet);
   fChain->SetBranchAddress("bjet_pt0", &bjet_pt0, &b_bjet_pt0);
   fChain->SetBranchAddress("bjet_eta0", &bjet_eta0, &b_bjet_eta0);
   fChain->SetBranchAddress("HT_vis_min", &HT_vis_min, &b_HT_vis_min);
   fChain->SetBranchAddress("HT_vis", &HT_vis, &b_HT_vis);
   fChain->SetBranchAddress("Mlb", &Mlb, &b_Mlb);
   fChain->SetBranchAddress("Mlb_OLD", &Mlb_OLD, &b_Mlb_OLD);
   fChain->SetBranchAddress("DRlb", &DRlb, &b_DRlb);
   fChain->SetBranchAddress("DRlb_OLD", &DRlb_OLD, &b_DRlb_OLD);
   fChain->SetBranchAddress("DeltaR_max_lep_bjet77", &DeltaR_max_lep_bjet77, &b_DeltaR_max_lep_bjet77);
   fChain->SetBranchAddress("DeltaR_min_lep_bjet77", &DeltaR_min_lep_bjet77, &b_DeltaR_min_lep_bjet77);
   fChain->SetBranchAddress("Mbblead", &Mbblead, &b_Mbblead);
   fChain->SetBranchAddress("Mbbtau", &Mbbtau, &b_Mbbtau);
   fChain->SetBranchAddress("Mbtaul", &Mbtaul, &b_Mbtaul);
   fChain->SetBranchAddress("Mbbmet", &Mbbmet, &b_Mbbmet);
   fChain->SetBranchAddress("Mtautau01", &Mtautau01, &b_Mtautau01);
   fChain->SetBranchAddress("Mltau00", &Mltau00, &b_Mltau00);
   fChain->SetBranchAddress("Mltau01", &Mltau01, &b_Mltau01);
   fChain->SetBranchAddress("Mltau10", &Mltau10, &b_Mltau10);
   fChain->SetBranchAddress("Mltau11", &Mltau11, &b_Mltau11);
   fChain->SetBranchAddress("nHiggs", &nHiggs, &b_nHiggs);
   fChain->SetBranchAddress("nWZhad", &nWZhad, &b_nWZhad);
   fChain->SetBranchAddress("nZee", &nZee, &b_nZee);
   fChain->SetBranchAddress("nZmm", &nZmm, &b_nZmm);
   fChain->SetBranchAddress("bjet_pt0_nofwd", &bjet_pt0_nofwd, &b_bjet_pt0_nofwd);
   fChain->SetBranchAddress("Mtaub", &Mtaub, &b_Mtaub);
   fChain->SetBranchAddress("nJets_OR_DL1r_77_pt40", &nJets_OR_DL1r_77_pt40, &b_nJets_OR_DL1r_77_pt40);
   fChain->SetBranchAddress("nJets_OR_nTaus_OR_pt40", &nJets_OR_nTaus_OR_pt40, &b_nJets_OR_nTaus_OR_pt40);
   fChain->SetBranchAddress("MLepMet", &MLepMet, &b_MLepMet);
   fChain->SetBranchAddress("MtLepMet", &MtLepMet, &b_MtLepMet);
   fChain->SetBranchAddress("MtLep0Met", &MtLep0Met, &b_MtLep0Met);
   fChain->SetBranchAddress("DRjj_lead", &DRjj_lead, &b_DRjj_lead);
   fChain->SetBranchAddress("mjj_lead", &mjj_lead, &b_mjj_lead);
   fChain->SetBranchAddress("mjjj_lead", &mjjj_lead, &b_mjjj_lead);
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
   fChain->SetBranchAddress("Mllmet", &Mllmet, &b_Mllmet);
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
   fChain->SetBranchAddress("sumPsbtag85", &sumPsbtag85, &b_sumPsbtag85);
   fChain->SetBranchAddress("jet_pt0_nofwd", &jet_pt0_nofwd, &b_jet_pt0_nofwd);
   fChain->SetBranchAddress("jet_pt1_nofwd", &jet_pt1_nofwd, &b_jet_pt1_nofwd);
   fChain->SetBranchAddress("jet_pt6_nofwd", &jet_pt6_nofwd, &b_jet_pt6_nofwd);
   fChain->SetBranchAddress("jet_pt0_nonbtag", &jet_pt0_nonbtag, &b_jet_pt0_nonbtag);
   fChain->SetBranchAddress("minDeltaR_J_bJ", &minDeltaR_J_bJ, &b_minDeltaR_J_bJ);
   fChain->SetBranchAddress("l2SS1tau", &l2SS1tau, &b_l2SS1tau);
   fChain->SetBranchAddress("IFFClass_lep_0", &IFFClass_lep_0, &b_IFFClass_lep_0);
   fChain->SetBranchAddress("IFFClass_lep_1", &IFFClass_lep_1, &b_IFFClass_lep_1);
   fChain->SetBranchAddress("IFFClass_lep_2", &IFFClass_lep_2, &b_IFFClass_lep_2);
   fChain->SetBranchAddress("IFFClass_lep_3", &IFFClass_lep_3, &b_IFFClass_lep_3);
   fChain->SetBranchAddress("IFFClass_lep_4", &IFFClass_lep_4, &b_IFFClass_lep_4);
   fChain->SetBranchAddress("IFFClass_lep_5", &IFFClass_lep_5, &b_IFFClass_lep_5);
   fChain->SetBranchAddress("ttHMLClass_lep_0", &ttHMLClass_lep_0, &b_ttHMLClass_lep_0);
   fChain->SetBranchAddress("ttHMLClass_lep_1", &ttHMLClass_lep_1, &b_ttHMLClass_lep_1);
   fChain->SetBranchAddress("ttHMLClass_lep_2", &ttHMLClass_lep_2, &b_ttHMLClass_lep_2);
   fChain->SetBranchAddress("N_IFF_Unclassified", &N_IFF_Unclassified, &b_N_IFF_Unclassified);
   fChain->SetBranchAddress("N_IFF_KnownUnknown", &N_IFF_KnownUnknown, &b_N_IFF_KnownUnknown);
   fChain->SetBranchAddress("N_IFF_Prompt", &N_IFF_Prompt, &b_N_IFF_Prompt);
   fChain->SetBranchAddress("N_IFF_QmisID", &N_IFF_QmisID, &b_N_IFF_QmisID);
   fChain->SetBranchAddress("N_IFF_MatConv", &N_IFF_MatConv, &b_N_IFF_MatConv);
   fChain->SetBranchAddress("N_IFF_IntConv", &N_IFF_IntConv, &b_N_IFF_IntConv);
   fChain->SetBranchAddress("N_IFF_Bdecays", &N_IFF_Bdecays, &b_N_IFF_Bdecays);
   fChain->SetBranchAddress("N_IFF_Cdecays", &N_IFF_Cdecays, &b_N_IFF_Cdecays);
   fChain->SetBranchAddress("N_IFF_LightHadDecays", &N_IFF_LightHadDecays, &b_N_IFF_LightHadDecays);
   fChain->SetBranchAddress("N_IFF_EfromMu", &N_IFF_EfromMu, &b_N_IFF_EfromMu);
   fChain->SetBranchAddress("N_IFF_TauDecays", &N_IFF_TauDecays, &b_N_IFF_TauDecays);
   fChain->SetBranchAddress("num_Zee_best", &num_Zee_best, &b_num_Zee_best);
   fChain->SetBranchAddress("num_Zmm_best", &num_Zmm_best, &b_num_Zmm_best);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_0", &lepSF_PLIV_Prompt_0, &b_lepSF_PLIV_Prompt_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_0", &lepSF_PLIV_Prompt_Tight_El_totalError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_0", &lepSF_PLIV_Prompt_Tight_El_totalSystError_0, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_0", &lepSF_PLIV_Prompt_VeryTight_El_statError_0, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_0", &lepSF_PLIV_Prompt_Tight_El_statError_0, &b_lepSF_PLIV_Prompt_Tight_El_statError_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_0", &lepSF_PLIV_Prompt_Tight_El_IDSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_0", &lepSF_PLIV_Prompt_Tight_El_muSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_0", &lepSF_PLIV_Prompt_Tight_El_isoSyst_0, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_0);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_1", &lepSF_PLIV_Prompt_1, &b_lepSF_PLIV_Prompt_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_1", &lepSF_PLIV_Prompt_Tight_El_totalError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_1", &lepSF_PLIV_Prompt_Tight_El_totalSystError_1, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_1", &lepSF_PLIV_Prompt_VeryTight_El_statError_1, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_1", &lepSF_PLIV_Prompt_Tight_El_statError_1, &b_lepSF_PLIV_Prompt_Tight_El_statError_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_1", &lepSF_PLIV_Prompt_Tight_El_IDSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_1", &lepSF_PLIV_Prompt_Tight_El_muSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_1", &lepSF_PLIV_Prompt_Tight_El_isoSyst_1, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_1);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_2", &lepSF_PLIV_Prompt_2, &b_lepSF_PLIV_Prompt_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalError_2", &lepSF_PLIV_Prompt_Tight_El_totalError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2", &lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_totalSystError_2", &lepSF_PLIV_Prompt_Tight_El_totalSystError_2, &b_lepSF_PLIV_Prompt_Tight_El_totalSystError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_statError_2", &lepSF_PLIV_Prompt_VeryTight_El_statError_2, &b_lepSF_PLIV_Prompt_VeryTight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_statError_2", &lepSF_PLIV_Prompt_Tight_El_statError_2, &b_lepSF_PLIV_Prompt_Tight_El_statError_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2", &lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_jetModelSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2", &lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_templateCutSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2", &lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_mllWindowSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_IDSyst_2", &lepSF_PLIV_Prompt_Tight_El_IDSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_IDSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_muSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_muSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_muSyst_2", &lepSF_PLIV_Prompt_Tight_El_muSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_muSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2", &lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_VeryTight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_El_isoSyst_2", &lepSF_PLIV_Prompt_Tight_El_isoSyst_2, &b_lepSF_PLIV_Prompt_Tight_El_isoSyst_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MLLWINDOW_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_PROBEQ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_DRMUJ_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_QCDTEMPLATE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_BKGFRACTION_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SUPRESSIONSCALE_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_MCXSEC_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_LUMIUNCERT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SYS_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1DN_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2", &lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2, &b_lepSF_PLIV_Prompt_Tight_Mu_STAT_1UP_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_VeryTight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2", &lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2, &b_lepSF_PLIV_Prompt_Tight_Mu_SHERPA_POWHEG_SYM_2);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_jvt__1up", &weight_jvt__1up, &b_weight_jvt__1up);
   fChain->SetBranchAddress("weight_jvt__1down", &weight_jvt__1down, &b_weight_jvt__1down);
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
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT", &weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT", &weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT, &b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT", &weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT", &weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT", &weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT, &b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_CC_El_ChargeMisID_LooseAndBLayerLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT", &weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_CC_El_ChargeMisID_TightLH_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_Reco_UP_AT", &weight_leptonSF_CC_El_Reco_UP_AT, &b_weight_leptonSF_CC_El_Reco_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_Reco_DOWN_AT", &weight_leptonSF_CC_El_Reco_DOWN_AT, &b_weight_leptonSF_CC_El_Reco_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ID_LooseAndBLayerLH_UP_AT", &weight_leptonSF_CC_El_ID_LooseAndBLayerLH_UP_AT, &b_weight_leptonSF_CC_El_ID_LooseAndBLayerLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ID_TightLH_UP_AT", &weight_leptonSF_CC_El_ID_TightLH_UP_AT, &b_weight_leptonSF_CC_El_ID_TightLH_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ID_LooseAndBLayerLH_DOWN_AT", &weight_leptonSF_CC_El_ID_LooseAndBLayerLH_DOWN_AT, &b_weight_leptonSF_CC_El_ID_LooseAndBLayerLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_ID_TightLH_DOWN_AT", &weight_leptonSF_CC_El_ID_TightLH_DOWN_AT, &b_weight_leptonSF_CC_El_ID_TightLH_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_Iso_FCLoose_UP_AT", &weight_leptonSF_CC_El_Iso_FCLoose_UP_AT, &b_weight_leptonSF_CC_El_Iso_FCLoose_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_El_Iso_FCLoose_DOWN_AT", &weight_leptonSF_CC_El_Iso_FCLoose_DOWN_AT, &b_weight_leptonSF_CC_El_Iso_FCLoose_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_TTVA_STAT_UP_AT", &weight_leptonSF_CC_Mu_TTVA_STAT_UP_AT, &b_weight_leptonSF_CC_Mu_TTVA_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_TTVA_STAT_DOWN_AT", &weight_leptonSF_CC_Mu_TTVA_STAT_DOWN_AT, &b_weight_leptonSF_CC_Mu_TTVA_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_TTVA_SYST_UP_AT", &weight_leptonSF_CC_Mu_TTVA_SYST_UP_AT, &b_weight_leptonSF_CC_Mu_TTVA_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_TTVA_SYST_DOWN_AT", &weight_leptonSF_CC_Mu_TTVA_SYST_DOWN_AT, &b_weight_leptonSF_CC_Mu_TTVA_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_STAT_UP_AT", &weight_leptonSF_CC_Mu_ID_Loose_STAT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_STAT_UP_AT", &weight_leptonSF_CC_Mu_ID_Medium_STAT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_STAT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Loose_STAT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_STAT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Medium_STAT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_SYST_UP_AT", &weight_leptonSF_CC_Mu_ID_Loose_SYST_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_SYST_UP_AT", &weight_leptonSF_CC_Mu_ID_Medium_SYST_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_SYST_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Loose_SYST_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_SYST_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Medium_SYST_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_UP_AT", &weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_UP_AT", &weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_STAT_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_UP_AT", &weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_UP_AT", &weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_UP_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Loose_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_DOWN_AT", &weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_DOWN_AT, &b_weight_leptonSF_CC_Mu_ID_Medium_SYST_LOWPT_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_UP_AT", &weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_UP_AT, &b_weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_DOWN_AT", &weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_DOWN_AT, &b_weight_leptonSF_CC_Mu_Iso_FCLoose_SYST_DOWN_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_UP_AT", &weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_UP_AT, &b_weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_UP_AT);
   fChain->SetBranchAddress("weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_DOWN_AT", &weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_DOWN_AT, &b_weight_leptonSF_CC_Mu_Iso_FCLoose_STAT_DOWN_AT);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP", &weight_globalLeptonTriggerSF_CWP, &b_weight_globalLeptonTriggerSF_CWP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_weight_globalLeptonTriggerSF_CWP_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down", &weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down, &b_weight_globalLeptonTriggerSF_CWP_MUON_EFF_TrigSystUncertainty__1down);
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
   fChain->SetBranchAddress("weight_tauSFRNNMedium_TAU_SF_NOMINAL", &weight_tauSFRNNMedium_TAU_SF_NOMINAL, &b_weight_tauSFRNNMedium_TAU_SF_NOMINAL);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP", &weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP, &b_weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN", &weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN, &b_weight_tauSFRNNMedium_EFF_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP", &weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP, &b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN", &weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN, &b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_STAT_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP", &weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP, &b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN", &weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN, &b_weight_tauSFRNNMedium_ELE_EFF_ELEOLR_SYST_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP", &weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_HIGHPT_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_SYST_UP", &weight_tauSFRNNMedium_EFF_RNNID_SYST_UP, &b_weight_tauSFRNNMedium_EFF_RNNID_SYST_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RNNID_SYST_DOWN", &weight_tauSFRNNMedium_EFF_RNNID_SYST_DOWN, &b_weight_tauSFRNNMedium_EFF_RNNID_SYST_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RECO_TOTAL_UP", &weight_tauSFRNNMedium_EFF_RECO_TOTAL_UP, &b_weight_tauSFRNNMedium_EFF_RECO_TOTAL_UP);
   fChain->SetBranchAddress("weight_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN", &weight_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN, &b_weight_tauSFRNNMedium_EFF_RECO_TOTAL_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_TAU_SF_NOMINAL", &weight_tauSFRNNLoose_TAU_SF_NOMINAL, &b_weight_tauSFRNNLoose_TAU_SF_NOMINAL);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP", &weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP, &b_weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN", &weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN, &b_weight_tauSFRNNLoose_EFF_ELEOLR_TOTAL_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP", &weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP, &b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN", &weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN, &b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_STAT_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP", &weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP, &b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN", &weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN, &b_weight_tauSFRNNLoose_ELE_EFF_ELEOLR_SYST_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2025_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT2530_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPT3040_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_1PRONGSTATSYSTPTGE40_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2025_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT2530_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPT3040_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_3PRONGSTATSYSTPTGE40_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP", &weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_HIGHPT_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_SYST_UP", &weight_tauSFRNNLoose_EFF_RNNID_SYST_UP, &b_weight_tauSFRNNLoose_EFF_RNNID_SYST_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RNNID_SYST_DOWN", &weight_tauSFRNNLoose_EFF_RNNID_SYST_DOWN, &b_weight_tauSFRNNLoose_EFF_RNNID_SYST_DOWN);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RECO_TOTAL_UP", &weight_tauSFRNNLoose_EFF_RECO_TOTAL_UP, &b_weight_tauSFRNNLoose_EFF_RECO_TOTAL_UP);
   fChain->SetBranchAddress("weight_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN", &weight_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN, &b_weight_tauSFRNNLoose_EFF_RECO_TOTAL_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF", &weight_globalLeptonTriggerSF, &b_weight_globalLeptonTriggerSF);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down", &weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down, &b_weight_globalLeptonTriggerSF_EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigStatUncertainty__1down);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1up);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down", &weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down, &b_weight_globalLeptonTriggerSF_MUON_EFF_TrigSystUncertainty__1down);
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
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e17_lhloose_nod0_mu14", &HLT_e17_lhloose_nod0_mu14, &b_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_2e24_lhvloose_nod0", &HLT_2e24_lhvloose_nod0, &b_HLT_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("onelep_type", &onelep_type, &b_onelep_type);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("quadlep_type", &quadlep_type, &b_quadlep_type);
   fChain->SetBranchAddress("fivelep_type", &fivelep_type, &b_fivelep_type);
   fChain->SetBranchAddress("sixlep_type", &sixlep_type, &b_sixlep_type);
   fChain->SetBranchAddress("multilepornone_type", &multilepornone_type, &b_multilepornone_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("Mll01", &Mll01, &b_Mll01);
   fChain->SetBranchAddress("Ptll01", &Ptll01, &b_Ptll01);
   fChain->SetBranchAddress("DRll01", &DRll01, &b_DRll01);
   fChain->SetBranchAddress("Mlll012", &Mlll012, &b_Mlll012);
   fChain->SetBranchAddress("Mllll0123", &Mllll0123, &b_Mllll0123);
   fChain->SetBranchAddress("Mllll0124", &Mllll0124, &b_Mllll0124);
   fChain->SetBranchAddress("Mllll0125", &Mllll0125, &b_Mllll0125);
   fChain->SetBranchAddress("Mlll013", &Mlll013, &b_Mlll013);
   fChain->SetBranchAddress("Mllll0134", &Mllll0134, &b_Mllll0134);
   fChain->SetBranchAddress("Mllll0135", &Mllll0135, &b_Mllll0135);
   fChain->SetBranchAddress("Mlll014", &Mlll014, &b_Mlll014);
   fChain->SetBranchAddress("Mllll0145", &Mllll0145, &b_Mllll0145);
   fChain->SetBranchAddress("Mlll015", &Mlll015, &b_Mlll015);
   fChain->SetBranchAddress("Mll02", &Mll02, &b_Mll02);
   fChain->SetBranchAddress("Ptll02", &Ptll02, &b_Ptll02);
   fChain->SetBranchAddress("DRll02", &DRll02, &b_DRll02);
   fChain->SetBranchAddress("Mlll023", &Mlll023, &b_Mlll023);
   fChain->SetBranchAddress("Mllll0234", &Mllll0234, &b_Mllll0234);
   fChain->SetBranchAddress("Mllll0235", &Mllll0235, &b_Mllll0235);
   fChain->SetBranchAddress("Mlll024", &Mlll024, &b_Mlll024);
   fChain->SetBranchAddress("Mllll0245", &Mllll0245, &b_Mllll0245);
   fChain->SetBranchAddress("Mlll025", &Mlll025, &b_Mlll025);
   fChain->SetBranchAddress("Mll03", &Mll03, &b_Mll03);
   fChain->SetBranchAddress("Ptll03", &Ptll03, &b_Ptll03);
   fChain->SetBranchAddress("DRll03", &DRll03, &b_DRll03);
   fChain->SetBranchAddress("Mlll034", &Mlll034, &b_Mlll034);
   fChain->SetBranchAddress("Mllll0345", &Mllll0345, &b_Mllll0345);
   fChain->SetBranchAddress("Mlll035", &Mlll035, &b_Mlll035);
   fChain->SetBranchAddress("Mll04", &Mll04, &b_Mll04);
   fChain->SetBranchAddress("Ptll04", &Ptll04, &b_Ptll04);
   fChain->SetBranchAddress("DRll04", &DRll04, &b_DRll04);
   fChain->SetBranchAddress("Mlll045", &Mlll045, &b_Mlll045);
   fChain->SetBranchAddress("Mll05", &Mll05, &b_Mll05);
   fChain->SetBranchAddress("Ptll05", &Ptll05, &b_Ptll05);
   fChain->SetBranchAddress("DRll05", &DRll05, &b_DRll05);
   fChain->SetBranchAddress("Mll12", &Mll12, &b_Mll12);
   fChain->SetBranchAddress("Ptll12", &Ptll12, &b_Ptll12);
   fChain->SetBranchAddress("DRll12", &DRll12, &b_DRll12);
   fChain->SetBranchAddress("Mlll123", &Mlll123, &b_Mlll123);
   fChain->SetBranchAddress("Mllll1234", &Mllll1234, &b_Mllll1234);
   fChain->SetBranchAddress("Mllll1235", &Mllll1235, &b_Mllll1235);
   fChain->SetBranchAddress("Mlll124", &Mlll124, &b_Mlll124);
   fChain->SetBranchAddress("Mllll1245", &Mllll1245, &b_Mllll1245);
   fChain->SetBranchAddress("Mlll125", &Mlll125, &b_Mlll125);
   fChain->SetBranchAddress("Mll13", &Mll13, &b_Mll13);
   fChain->SetBranchAddress("Ptll13", &Ptll13, &b_Ptll13);
   fChain->SetBranchAddress("DRll13", &DRll13, &b_DRll13);
   fChain->SetBranchAddress("Mlll134", &Mlll134, &b_Mlll134);
   fChain->SetBranchAddress("Mllll1345", &Mllll1345, &b_Mllll1345);
   fChain->SetBranchAddress("Mlll135", &Mlll135, &b_Mlll135);
   fChain->SetBranchAddress("Mll14", &Mll14, &b_Mll14);
   fChain->SetBranchAddress("Ptll14", &Ptll14, &b_Ptll14);
   fChain->SetBranchAddress("DRll14", &DRll14, &b_DRll14);
   fChain->SetBranchAddress("Mlll145", &Mlll145, &b_Mlll145);
   fChain->SetBranchAddress("Mll15", &Mll15, &b_Mll15);
   fChain->SetBranchAddress("Ptll15", &Ptll15, &b_Ptll15);
   fChain->SetBranchAddress("DRll15", &DRll15, &b_DRll15);
   fChain->SetBranchAddress("Mll23", &Mll23, &b_Mll23);
   fChain->SetBranchAddress("Ptll23", &Ptll23, &b_Ptll23);
   fChain->SetBranchAddress("DRll23", &DRll23, &b_DRll23);
   fChain->SetBranchAddress("Mlll234", &Mlll234, &b_Mlll234);
   fChain->SetBranchAddress("Mllll2345", &Mllll2345, &b_Mllll2345);
   fChain->SetBranchAddress("Mlll235", &Mlll235, &b_Mlll235);
   fChain->SetBranchAddress("Mll24", &Mll24, &b_Mll24);
   fChain->SetBranchAddress("Ptll24", &Ptll24, &b_Ptll24);
   fChain->SetBranchAddress("DRll24", &DRll24, &b_DRll24);
   fChain->SetBranchAddress("Mlll245", &Mlll245, &b_Mlll245);
   fChain->SetBranchAddress("Mll25", &Mll25, &b_Mll25);
   fChain->SetBranchAddress("Ptll25", &Ptll25, &b_Ptll25);
   fChain->SetBranchAddress("DRll25", &DRll25, &b_DRll25);
   fChain->SetBranchAddress("Mll34", &Mll34, &b_Mll34);
   fChain->SetBranchAddress("Ptll34", &Ptll34, &b_Ptll34);
   fChain->SetBranchAddress("DRll34", &DRll34, &b_DRll34);
   fChain->SetBranchAddress("Mlll345", &Mlll345, &b_Mlll345);
   fChain->SetBranchAddress("Mll35", &Mll35, &b_Mll35);
   fChain->SetBranchAddress("Ptll35", &Ptll35, &b_Ptll35);
   fChain->SetBranchAddress("DRll35", &DRll35, &b_DRll35);
   fChain->SetBranchAddress("Mll45", &Mll45, &b_Mll45);
   fChain->SetBranchAddress("Ptll45", &Ptll45, &b_Ptll45);
   fChain->SetBranchAddress("DRll45", &DRll45, &b_DRll45);
   fChain->SetBranchAddress("best_Z_Mll", &best_Z_Mll, &b_best_Z_Mll);
   fChain->SetBranchAddress("best_Z_other_MtLepMet", &best_Z_other_MtLepMet, &b_best_Z_other_MtLepMet);
   fChain->SetBranchAddress("best_Z_other_Mll", &best_Z_other_Mll, &b_best_Z_other_Mll);
   fChain->SetBranchAddress("minOSSFMll", &minOSSFMll, &b_minOSSFMll);
   fChain->SetBranchAddress("minOSMll", &minOSMll, &b_minOSMll);
   fChain->SetBranchAddress("Mlt00", &Mlt00, &b_Mlt00);
   fChain->SetBranchAddress("Mlt01", &Mlt01, &b_Mlt01);
   fChain->SetBranchAddress("Mlt10", &Mlt10, &b_Mlt10);
   fChain->SetBranchAddress("Mlt11", &Mlt11, &b_Mlt11);
   fChain->SetBranchAddress("Mtt01", &Mtt01, &b_Mtt01);
   fChain->SetBranchAddress("MTlmet", &MTlmet, &b_MTlmet);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("nJets_OR_DL1r_85", &nJets_OR_DL1r_85, &b_nJets_OR_DL1r_85);
   fChain->SetBranchAddress("nJets_OR_DL1r_60", &nJets_OR_DL1r_60, &b_nJets_OR_DL1r_60);
   fChain->SetBranchAddress("nJets_OR_DL1r_77", &nJets_OR_DL1r_77, &b_nJets_OR_DL1r_77);
   fChain->SetBranchAddress("nJets_OR_DL1r_70", &nJets_OR_DL1r_70, &b_nJets_OR_DL1r_70);
   fChain->SetBranchAddress("nTaus_OR_Pt25", &nTaus_OR_Pt25, &b_nTaus_OR_Pt25);
   fChain->SetBranchAddress("nTaus_OR", &nTaus_OR, &b_nTaus_OR);
   fChain->SetBranchAddress("nTaus_OR_Medium", &nTaus_OR_Medium, &b_nTaus_OR_Medium);
   fChain->SetBranchAddress("nTaus_OR_Tight", &nTaus_OR_Tight, &b_nTaus_OR_Tight);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("HT_lep", &HT_lep, &b_HT_lep);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("HT_taus", &HT_taus, &b_HT_taus);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Index_0", &lep_Index_0, &b_lep_Index_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_EtaBE2_0", &lep_EtaBE2_0, &b_lep_EtaBE2_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   fChain->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   fChain->SetBranchAddress("lep_vz_0", &lep_vz_0, &b_lep_vz_0);
   fChain->SetBranchAddress("lep_deltaz0_0", &lep_deltaz0_0, &b_lep_deltaz0_0);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   fChain->SetBranchAddress("lep_isHighPt_0", &lep_isHighPt_0, &b_lep_isHighPt_0);
   fChain->SetBranchAddress("lep_isolationFCLoose_0", &lep_isolationFCLoose_0, &b_lep_isolationFCLoose_0);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_0", &lep_isolationPLImprovedTight_0, &b_lep_isolationPLImprovedTight_0);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_0", &lep_isolationPLImprovedVeryTight_0, &b_lep_isolationPLImprovedVeryTight_0);
   fChain->SetBranchAddress("lep_isolationFCTight_0", &lep_isolationFCTight_0, &b_lep_isolationFCTight_0);
   fChain->SetBranchAddress("lep_isolationLoose_0", &lep_isolationLoose_0, &b_lep_isolationLoose_0);
   fChain->SetBranchAddress("lep_isolationGradient_0", &lep_isolationGradient_0, &b_lep_isolationGradient_0);
   fChain->SetBranchAddress("lep_isolationGradientLoose_0", &lep_isolationGradientLoose_0, &b_lep_isolationGradientLoose_0);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_0", &lep_isolationTightTrackOnly_0, &b_lep_isolationTightTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_0", &lep_isolationHighPtCaloOnly_0, &b_lep_isolationHighPtCaloOnly_0);
   fChain->SetBranchAddress("lep_isolationPflowTight_0", &lep_isolationPflowTight_0, &b_lep_isolationPflowTight_0);
   fChain->SetBranchAddress("lep_isolationPflowLoose_0", &lep_isolationPflowLoose_0, &b_lep_isolationPflowLoose_0);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_0", &lep_isolationPflowTight_VarRad_0, &b_lep_isolationPflowTight_VarRad_0);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_0", &lep_isolationPflowTight_FixedRad_0, &b_lep_isolationPflowTight_FixedRad_0);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_0", &lep_isolationPflowLoose_VarRad_0, &b_lep_isolationPflowLoose_VarRad_0);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_0", &lep_isolationPflowLoose_FixedRad_0, &b_lep_isolationPflowLoose_FixedRad_0);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_0", &lep_isolationHighPtTrackOnly_0, &b_lep_isolationHighPtTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_0", &lep_isolationTight_FixedRad_0, &b_lep_isolationTight_FixedRad_0);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_0", &lep_isolationLoose_FixedRad_0, &b_lep_isolationLoose_FixedRad_0);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_0", &lep_isolationTightTrackOnly_VarRad_0, &b_lep_isolationTightTrackOnly_VarRad_0);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_0", &lep_isolationTightTrackOnly_FixedRad_0, &b_lep_isolationTightTrackOnly_FixedRad_0);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_0", &lep_isolationTight_VarRad_0, &b_lep_isolationTight_VarRad_0);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_0", &lep_isolationLoose_VarRad_0, &b_lep_isolationLoose_VarRad_0);
   fChain->SetBranchAddress("lep_plvWP_Loose_0", &lep_plvWP_Loose_0, &b_lep_plvWP_Loose_0);
   fChain->SetBranchAddress("lep_plvWP_Tight_0", &lep_plvWP_Tight_0, &b_lep_plvWP_Tight_0);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_0", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_0, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
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
   fChain->SetBranchAddress("lep_SeparationMinDCT_0", &lep_SeparationMinDCT_0, &b_lep_SeparationMinDCT_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_0", &lep_DFCommonSimpleConvRadius_0, &b_lep_DFCommonSimpleConvRadius_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_0", &lep_DFCommonSimpleConvPhi_0, &b_lep_DFCommonSimpleConvPhi_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_0", &lep_DFCommonSimpleMee_0, &b_lep_DFCommonSimpleMee_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_0", &lep_DFCommonSimpleMeeAtVtx_0, &b_lep_DFCommonSimpleMeeAtVtx_0);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_0", &lep_DFCommonSimpleSeparation_0, &b_lep_DFCommonSimpleSeparation_0);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_0", &lep_DFCommonAddAmbiguity_0, &b_lep_DFCommonAddAmbiguity_0);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_0", &lep_DFCommonProdTrueRadius_0, &b_lep_DFCommonProdTrueRadius_0);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_0", &lep_DFCommonProdTruePhi_0, &b_lep_DFCommonProdTruePhi_0);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_0", &lep_DFCommonProdTrueZ_0, &b_lep_DFCommonProdTrueZ_0);
   fChain->SetBranchAddress("lep_DFCommonJetDr_0", &lep_DFCommonJetDr_0, &b_lep_DFCommonJetDr_0);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_0", &lep_chargeIDBDTLoose_0, &b_lep_chargeIDBDTLoose_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_0", &lep_chargeIDBDTResult_0, &b_lep_chargeIDBDTResult_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_0", &lep_chargeIDBDTResult_recalc_rel207_loose_0, &b_lep_chargeIDBDTResult_recalc_rel207_loose_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_0", &lep_chargeIDBDTResult_recalc_rel207_medium_0, &b_lep_chargeIDBDTResult_recalc_rel207_medium_0);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_0", &lep_chargeIDBDTResult_recalc_rel207_tight_0, &b_lep_chargeIDBDTResult_recalc_rel207_tight_0);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_0", &lep_promptLeptonIso_TagWeight_0, &b_lep_promptLeptonIso_TagWeight_0);
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
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_AnpTruthType_0", &lep_AnpTruthType_0, &b_lep_AnpTruthType_0);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_truthStatus_0", &lep_truthStatus_0, &b_lep_truthStatus_0);
   fChain->SetBranchAddress("lep_truthParentType_0", &lep_truthParentType_0, &b_lep_truthParentType_0);
   fChain->SetBranchAddress("lep_truthParentOrigin_0", &lep_truthParentOrigin_0, &b_lep_truthParentOrigin_0);
   fChain->SetBranchAddress("lep_truthParentPdgId_0", &lep_truthParentPdgId_0, &b_lep_truthParentPdgId_0);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_0", &lep_truthParentRealPdgId_0, &b_lep_truthParentRealPdgId_0);
   fChain->SetBranchAddress("lep_truthParentStatus_0", &lep_truthParentStatus_0, &b_lep_truthParentStatus_0);
   fChain->SetBranchAddress("lep_truthParentBarcode_0", &lep_truthParentBarcode_0, &b_lep_truthParentBarcode_0);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_0", &lep_truthParentIsCHadron_0, &b_lep_truthParentIsCHadron_0);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_0", &lep_truthParentIsBHadron_0, &b_lep_truthParentIsBHadron_0);
   fChain->SetBranchAddress("lep_truthHasTopInChain_0", &lep_truthHasTopInChain_0, &b_lep_truthHasTopInChain_0);
   fChain->SetBranchAddress("lep_truthParentPt_0", &lep_truthParentPt_0, &b_lep_truthParentPt_0);
   fChain->SetBranchAddress("lep_truthParentEta_0", &lep_truthParentEta_0, &b_lep_truthParentEta_0);
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
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_0", &lep_SF_El_Iso_FCLoose_AT_0, &b_lep_SF_El_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_0", &lep_SF_El_FCLooseTightLHQMisID_0, &b_lep_SF_El_FCLooseTightLHQMisID_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_0", &lep_SF_El_Iso_FCLoose_TightLH_0, &b_lep_SF_El_Iso_FCLoose_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_0", &lep_SF_El_PLVTight_QmisID_0, &b_lep_SF_El_PLVTight_QmisID_0);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_0", &lep_SF_El_PLVTight_0, &b_lep_SF_El_PLVTight_0);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_0", &lep_SF_El_PLVLoose_0, &b_lep_SF_El_PLVLoose_0);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_0", &lep_SF_El_ID_MediumLH_0, &b_lep_SF_El_ID_MediumLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_0", &lep_SF_El_Iso_PLImprovedTight_TightLH_0, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_0", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_0, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_0", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_0, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_0);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_0", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_0, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_0);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_0", &lep_SF_Mu_TTVA_AT_0, &b_lep_SF_Mu_TTVA_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_0", &lep_SF_Mu_ID_Loose_AT_0, &b_lep_SF_Mu_ID_Loose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_0", &lep_SF_Mu_ID_Medium_AT_0, &b_lep_SF_Mu_ID_Medium_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_0", &lep_SF_Mu_Iso_FCLoose_AT_0, &b_lep_SF_Mu_Iso_FCLoose_AT_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_0", &lep_SF_Mu_ID_Tight_0, &b_lep_SF_Mu_ID_Tight_0);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_0", &lep_SF_Mu_ID_HighPt_0, &b_lep_SF_Mu_ID_HighPt_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_0", &lep_SF_Mu_PLVTight_0, &b_lep_SF_Mu_PLVTight_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_0", &lep_SF_Mu_PLVLoose_0, &b_lep_SF_Mu_PLVLoose_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_0", &lep_SF_Mu_PLIV_MnotT_0, &b_lep_SF_Mu_PLIV_MnotT_0);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_0", &lep_SF_Mu_PLIV_T_0, &b_lep_SF_Mu_PLIV_T_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_0", &lep_SF_Mu_Iso_PflowTight_FixedRad_0, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_0", &lep_SF_Mu_Iso_PflowTight_VarRad_0, &b_lep_SF_Mu_Iso_PflowTight_VarRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_0", &lep_SF_Mu_Iso_PflowLoose_VarRad_0, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_0", &lep_SF_Mu_Iso_PflowLoose_FixedRad_0, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_0", &lep_SF_Mu_Iso_HighPtTrackOnly_0, &b_lep_SF_Mu_Iso_HighPtTrackOnly_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_0", &lep_SF_Mu_Iso_Tight_FixedRad_0, &b_lep_SF_Mu_Iso_Tight_FixedRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_0", &lep_SF_Mu_Iso_Loose_FixedRad_0, &b_lep_SF_Mu_Iso_Loose_FixedRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_0", &lep_SF_Mu_Iso_Loose_VarRad_0, &b_lep_SF_Mu_Iso_Loose_VarRad_0);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_0", &lep_SF_Mu_Iso_Tight_VarRad_0, &b_lep_SF_Mu_Iso_Tight_VarRad_0);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_0", &lep_SF_CombinedLoose_0, &b_lep_SF_CombinedLoose_0);
   fChain->SetBranchAddress("lep_SF_CombinedTight_0", &lep_SF_CombinedTight_0, &b_lep_SF_CombinedTight_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_Index_1", &lep_Index_1, &b_lep_Index_1);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_EtaBE2_1", &lep_EtaBE2_1, &b_lep_EtaBE2_1);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   fChain->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   fChain->SetBranchAddress("lep_vz_1", &lep_vz_1, &b_lep_vz_1);
   fChain->SetBranchAddress("lep_deltaz0_1", &lep_deltaz0_1, &b_lep_deltaz0_1);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   fChain->SetBranchAddress("lep_isHighPt_1", &lep_isHighPt_1, &b_lep_isHighPt_1);
   fChain->SetBranchAddress("lep_isolationFCLoose_1", &lep_isolationFCLoose_1, &b_lep_isolationFCLoose_1);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_1", &lep_isolationPLImprovedTight_1, &b_lep_isolationPLImprovedTight_1);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_1", &lep_isolationPLImprovedVeryTight_1, &b_lep_isolationPLImprovedVeryTight_1);
   fChain->SetBranchAddress("lep_isolationFCTight_1", &lep_isolationFCTight_1, &b_lep_isolationFCTight_1);
   fChain->SetBranchAddress("lep_isolationLoose_1", &lep_isolationLoose_1, &b_lep_isolationLoose_1);
   fChain->SetBranchAddress("lep_isolationGradient_1", &lep_isolationGradient_1, &b_lep_isolationGradient_1);
   fChain->SetBranchAddress("lep_isolationGradientLoose_1", &lep_isolationGradientLoose_1, &b_lep_isolationGradientLoose_1);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_1", &lep_isolationTightTrackOnly_1, &b_lep_isolationTightTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_1", &lep_isolationHighPtCaloOnly_1, &b_lep_isolationHighPtCaloOnly_1);
   fChain->SetBranchAddress("lep_isolationPflowTight_1", &lep_isolationPflowTight_1, &b_lep_isolationPflowTight_1);
   fChain->SetBranchAddress("lep_isolationPflowLoose_1", &lep_isolationPflowLoose_1, &b_lep_isolationPflowLoose_1);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_1", &lep_isolationPflowTight_VarRad_1, &b_lep_isolationPflowTight_VarRad_1);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_1", &lep_isolationPflowTight_FixedRad_1, &b_lep_isolationPflowTight_FixedRad_1);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_1", &lep_isolationPflowLoose_VarRad_1, &b_lep_isolationPflowLoose_VarRad_1);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_1", &lep_isolationPflowLoose_FixedRad_1, &b_lep_isolationPflowLoose_FixedRad_1);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_1", &lep_isolationHighPtTrackOnly_1, &b_lep_isolationHighPtTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_1", &lep_isolationTight_FixedRad_1, &b_lep_isolationTight_FixedRad_1);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_1", &lep_isolationLoose_FixedRad_1, &b_lep_isolationLoose_FixedRad_1);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_1", &lep_isolationTightTrackOnly_VarRad_1, &b_lep_isolationTightTrackOnly_VarRad_1);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_1", &lep_isolationTightTrackOnly_FixedRad_1, &b_lep_isolationTightTrackOnly_FixedRad_1);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_1", &lep_isolationTight_VarRad_1, &b_lep_isolationTight_VarRad_1);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_1", &lep_isolationLoose_VarRad_1, &b_lep_isolationLoose_VarRad_1);
   fChain->SetBranchAddress("lep_plvWP_Loose_1", &lep_plvWP_Loose_1, &b_lep_plvWP_Loose_1);
   fChain->SetBranchAddress("lep_plvWP_Tight_1", &lep_plvWP_Tight_1, &b_lep_plvWP_Tight_1);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_1", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_1, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
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
   fChain->SetBranchAddress("lep_SeparationMinDCT_1", &lep_SeparationMinDCT_1, &b_lep_SeparationMinDCT_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_1", &lep_DFCommonSimpleConvRadius_1, &b_lep_DFCommonSimpleConvRadius_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_1", &lep_DFCommonSimpleConvPhi_1, &b_lep_DFCommonSimpleConvPhi_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_1", &lep_DFCommonSimpleMee_1, &b_lep_DFCommonSimpleMee_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_1", &lep_DFCommonSimpleMeeAtVtx_1, &b_lep_DFCommonSimpleMeeAtVtx_1);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_1", &lep_DFCommonSimpleSeparation_1, &b_lep_DFCommonSimpleSeparation_1);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_1", &lep_DFCommonAddAmbiguity_1, &b_lep_DFCommonAddAmbiguity_1);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_1", &lep_DFCommonProdTrueRadius_1, &b_lep_DFCommonProdTrueRadius_1);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_1", &lep_DFCommonProdTruePhi_1, &b_lep_DFCommonProdTruePhi_1);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_1", &lep_DFCommonProdTrueZ_1, &b_lep_DFCommonProdTrueZ_1);
   fChain->SetBranchAddress("lep_DFCommonJetDr_1", &lep_DFCommonJetDr_1, &b_lep_DFCommonJetDr_1);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_1", &lep_chargeIDBDTLoose_1, &b_lep_chargeIDBDTLoose_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_1", &lep_chargeIDBDTResult_1, &b_lep_chargeIDBDTResult_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_1", &lep_chargeIDBDTResult_recalc_rel207_loose_1, &b_lep_chargeIDBDTResult_recalc_rel207_loose_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_1", &lep_chargeIDBDTResult_recalc_rel207_medium_1, &b_lep_chargeIDBDTResult_recalc_rel207_medium_1);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_1", &lep_chargeIDBDTResult_recalc_rel207_tight_1, &b_lep_chargeIDBDTResult_recalc_rel207_tight_1);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_1", &lep_promptLeptonIso_TagWeight_1, &b_lep_promptLeptonIso_TagWeight_1);
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
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_AnpTruthType_1", &lep_AnpTruthType_1, &b_lep_AnpTruthType_1);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_truthStatus_1", &lep_truthStatus_1, &b_lep_truthStatus_1);
   fChain->SetBranchAddress("lep_truthParentType_1", &lep_truthParentType_1, &b_lep_truthParentType_1);
   fChain->SetBranchAddress("lep_truthParentOrigin_1", &lep_truthParentOrigin_1, &b_lep_truthParentOrigin_1);
   fChain->SetBranchAddress("lep_truthParentPdgId_1", &lep_truthParentPdgId_1, &b_lep_truthParentPdgId_1);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_1", &lep_truthParentRealPdgId_1, &b_lep_truthParentRealPdgId_1);
   fChain->SetBranchAddress("lep_truthParentStatus_1", &lep_truthParentStatus_1, &b_lep_truthParentStatus_1);
   fChain->SetBranchAddress("lep_truthParentBarcode_1", &lep_truthParentBarcode_1, &b_lep_truthParentBarcode_1);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_1", &lep_truthParentIsCHadron_1, &b_lep_truthParentIsCHadron_1);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_1", &lep_truthParentIsBHadron_1, &b_lep_truthParentIsBHadron_1);
   fChain->SetBranchAddress("lep_truthHasTopInChain_1", &lep_truthHasTopInChain_1, &b_lep_truthHasTopInChain_1);
   fChain->SetBranchAddress("lep_truthParentPt_1", &lep_truthParentPt_1, &b_lep_truthParentPt_1);
   fChain->SetBranchAddress("lep_truthParentEta_1", &lep_truthParentEta_1, &b_lep_truthParentEta_1);
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
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_1", &lep_SF_El_Iso_FCLoose_AT_1, &b_lep_SF_El_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_1", &lep_SF_El_FCLooseTightLHQMisID_1, &b_lep_SF_El_FCLooseTightLHQMisID_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_1", &lep_SF_El_Iso_FCLoose_TightLH_1, &b_lep_SF_El_Iso_FCLoose_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_1", &lep_SF_El_PLVTight_QmisID_1, &b_lep_SF_El_PLVTight_QmisID_1);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_1", &lep_SF_El_PLVTight_1, &b_lep_SF_El_PLVTight_1);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_1", &lep_SF_El_PLVLoose_1, &b_lep_SF_El_PLVLoose_1);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_1", &lep_SF_El_ID_MediumLH_1, &b_lep_SF_El_ID_MediumLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_1", &lep_SF_El_Iso_PLImprovedTight_TightLH_1, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_1", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_1, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_1", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_1, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_1);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_1", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_1, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_1);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_1", &lep_SF_Mu_TTVA_AT_1, &b_lep_SF_Mu_TTVA_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_1", &lep_SF_Mu_ID_Loose_AT_1, &b_lep_SF_Mu_ID_Loose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_1", &lep_SF_Mu_ID_Medium_AT_1, &b_lep_SF_Mu_ID_Medium_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_1", &lep_SF_Mu_Iso_FCLoose_AT_1, &b_lep_SF_Mu_Iso_FCLoose_AT_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_1", &lep_SF_Mu_ID_Tight_1, &b_lep_SF_Mu_ID_Tight_1);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_1", &lep_SF_Mu_ID_HighPt_1, &b_lep_SF_Mu_ID_HighPt_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_1", &lep_SF_Mu_PLVTight_1, &b_lep_SF_Mu_PLVTight_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_1", &lep_SF_Mu_PLVLoose_1, &b_lep_SF_Mu_PLVLoose_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_1", &lep_SF_Mu_PLIV_MnotT_1, &b_lep_SF_Mu_PLIV_MnotT_1);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_1", &lep_SF_Mu_PLIV_T_1, &b_lep_SF_Mu_PLIV_T_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_1", &lep_SF_Mu_Iso_PflowTight_FixedRad_1, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_1", &lep_SF_Mu_Iso_PflowTight_VarRad_1, &b_lep_SF_Mu_Iso_PflowTight_VarRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_1", &lep_SF_Mu_Iso_PflowLoose_VarRad_1, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_1", &lep_SF_Mu_Iso_PflowLoose_FixedRad_1, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_1", &lep_SF_Mu_Iso_HighPtTrackOnly_1, &b_lep_SF_Mu_Iso_HighPtTrackOnly_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_1", &lep_SF_Mu_Iso_Tight_FixedRad_1, &b_lep_SF_Mu_Iso_Tight_FixedRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_1", &lep_SF_Mu_Iso_Loose_FixedRad_1, &b_lep_SF_Mu_Iso_Loose_FixedRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_1", &lep_SF_Mu_Iso_Loose_VarRad_1, &b_lep_SF_Mu_Iso_Loose_VarRad_1);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_1", &lep_SF_Mu_Iso_Tight_VarRad_1, &b_lep_SF_Mu_Iso_Tight_VarRad_1);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_1", &lep_SF_CombinedLoose_1, &b_lep_SF_CombinedLoose_1);
   fChain->SetBranchAddress("lep_SF_CombinedTight_1", &lep_SF_CombinedTight_1, &b_lep_SF_CombinedTight_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_Index_2", &lep_Index_2, &b_lep_Index_2);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_EtaBE2_2", &lep_EtaBE2_2, &b_lep_EtaBE2_2);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   fChain->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   fChain->SetBranchAddress("lep_vz_2", &lep_vz_2, &b_lep_vz_2);
   fChain->SetBranchAddress("lep_deltaz0_2", &lep_deltaz0_2, &b_lep_deltaz0_2);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   fChain->SetBranchAddress("lep_isHighPt_2", &lep_isHighPt_2, &b_lep_isHighPt_2);
   fChain->SetBranchAddress("lep_isolationFCLoose_2", &lep_isolationFCLoose_2, &b_lep_isolationFCLoose_2);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_2", &lep_isolationPLImprovedTight_2, &b_lep_isolationPLImprovedTight_2);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_2", &lep_isolationPLImprovedVeryTight_2, &b_lep_isolationPLImprovedVeryTight_2);
   fChain->SetBranchAddress("lep_isolationFCTight_2", &lep_isolationFCTight_2, &b_lep_isolationFCTight_2);
   fChain->SetBranchAddress("lep_isolationLoose_2", &lep_isolationLoose_2, &b_lep_isolationLoose_2);
   fChain->SetBranchAddress("lep_isolationGradient_2", &lep_isolationGradient_2, &b_lep_isolationGradient_2);
   fChain->SetBranchAddress("lep_isolationGradientLoose_2", &lep_isolationGradientLoose_2, &b_lep_isolationGradientLoose_2);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_2", &lep_isolationTightTrackOnly_2, &b_lep_isolationTightTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_2", &lep_isolationHighPtCaloOnly_2, &b_lep_isolationHighPtCaloOnly_2);
   fChain->SetBranchAddress("lep_isolationPflowTight_2", &lep_isolationPflowTight_2, &b_lep_isolationPflowTight_2);
   fChain->SetBranchAddress("lep_isolationPflowLoose_2", &lep_isolationPflowLoose_2, &b_lep_isolationPflowLoose_2);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_2", &lep_isolationPflowTight_VarRad_2, &b_lep_isolationPflowTight_VarRad_2);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_2", &lep_isolationPflowTight_FixedRad_2, &b_lep_isolationPflowTight_FixedRad_2);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_2", &lep_isolationPflowLoose_VarRad_2, &b_lep_isolationPflowLoose_VarRad_2);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_2", &lep_isolationPflowLoose_FixedRad_2, &b_lep_isolationPflowLoose_FixedRad_2);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_2", &lep_isolationHighPtTrackOnly_2, &b_lep_isolationHighPtTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_2", &lep_isolationTight_FixedRad_2, &b_lep_isolationTight_FixedRad_2);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_2", &lep_isolationLoose_FixedRad_2, &b_lep_isolationLoose_FixedRad_2);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_2", &lep_isolationTightTrackOnly_VarRad_2, &b_lep_isolationTightTrackOnly_VarRad_2);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_2", &lep_isolationTightTrackOnly_FixedRad_2, &b_lep_isolationTightTrackOnly_FixedRad_2);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_2", &lep_isolationTight_VarRad_2, &b_lep_isolationTight_VarRad_2);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_2", &lep_isolationLoose_VarRad_2, &b_lep_isolationLoose_VarRad_2);
   fChain->SetBranchAddress("lep_plvWP_Loose_2", &lep_plvWP_Loose_2, &b_lep_plvWP_Loose_2);
   fChain->SetBranchAddress("lep_plvWP_Tight_2", &lep_plvWP_Tight_2, &b_lep_plvWP_Tight_2);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_2", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_2, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
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
   fChain->SetBranchAddress("lep_SeparationMinDCT_2", &lep_SeparationMinDCT_2, &b_lep_SeparationMinDCT_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_2", &lep_DFCommonSimpleConvRadius_2, &b_lep_DFCommonSimpleConvRadius_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_2", &lep_DFCommonSimpleConvPhi_2, &b_lep_DFCommonSimpleConvPhi_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_2", &lep_DFCommonSimpleMee_2, &b_lep_DFCommonSimpleMee_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_2", &lep_DFCommonSimpleMeeAtVtx_2, &b_lep_DFCommonSimpleMeeAtVtx_2);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_2", &lep_DFCommonSimpleSeparation_2, &b_lep_DFCommonSimpleSeparation_2);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_2", &lep_DFCommonAddAmbiguity_2, &b_lep_DFCommonAddAmbiguity_2);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_2", &lep_DFCommonProdTrueRadius_2, &b_lep_DFCommonProdTrueRadius_2);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_2", &lep_DFCommonProdTruePhi_2, &b_lep_DFCommonProdTruePhi_2);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_2", &lep_DFCommonProdTrueZ_2, &b_lep_DFCommonProdTrueZ_2);
   fChain->SetBranchAddress("lep_DFCommonJetDr_2", &lep_DFCommonJetDr_2, &b_lep_DFCommonJetDr_2);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_2", &lep_chargeIDBDTLoose_2, &b_lep_chargeIDBDTLoose_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_2", &lep_chargeIDBDTResult_2, &b_lep_chargeIDBDTResult_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_2", &lep_chargeIDBDTResult_recalc_rel207_loose_2, &b_lep_chargeIDBDTResult_recalc_rel207_loose_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_2", &lep_chargeIDBDTResult_recalc_rel207_medium_2, &b_lep_chargeIDBDTResult_recalc_rel207_medium_2);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_2", &lep_chargeIDBDTResult_recalc_rel207_tight_2, &b_lep_chargeIDBDTResult_recalc_rel207_tight_2);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_2", &lep_promptLeptonIso_TagWeight_2, &b_lep_promptLeptonIso_TagWeight_2);
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
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_AnpTruthType_2", &lep_AnpTruthType_2, &b_lep_AnpTruthType_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_truthStatus_2", &lep_truthStatus_2, &b_lep_truthStatus_2);
   fChain->SetBranchAddress("lep_truthParentType_2", &lep_truthParentType_2, &b_lep_truthParentType_2);
   fChain->SetBranchAddress("lep_truthParentOrigin_2", &lep_truthParentOrigin_2, &b_lep_truthParentOrigin_2);
   fChain->SetBranchAddress("lep_truthParentPdgId_2", &lep_truthParentPdgId_2, &b_lep_truthParentPdgId_2);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_2", &lep_truthParentRealPdgId_2, &b_lep_truthParentRealPdgId_2);
   fChain->SetBranchAddress("lep_truthParentStatus_2", &lep_truthParentStatus_2, &b_lep_truthParentStatus_2);
   fChain->SetBranchAddress("lep_truthParentBarcode_2", &lep_truthParentBarcode_2, &b_lep_truthParentBarcode_2);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_2", &lep_truthParentIsCHadron_2, &b_lep_truthParentIsCHadron_2);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_2", &lep_truthParentIsBHadron_2, &b_lep_truthParentIsBHadron_2);
   fChain->SetBranchAddress("lep_truthHasTopInChain_2", &lep_truthHasTopInChain_2, &b_lep_truthHasTopInChain_2);
   fChain->SetBranchAddress("lep_truthParentPt_2", &lep_truthParentPt_2, &b_lep_truthParentPt_2);
   fChain->SetBranchAddress("lep_truthParentEta_2", &lep_truthParentEta_2, &b_lep_truthParentEta_2);
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
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_2", &lep_SF_El_Iso_FCLoose_AT_2, &b_lep_SF_El_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_2", &lep_SF_El_FCLooseTightLHQMisID_2, &b_lep_SF_El_FCLooseTightLHQMisID_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_2", &lep_SF_El_Iso_FCLoose_TightLH_2, &b_lep_SF_El_Iso_FCLoose_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_2", &lep_SF_El_PLVTight_QmisID_2, &b_lep_SF_El_PLVTight_QmisID_2);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_2", &lep_SF_El_PLVTight_2, &b_lep_SF_El_PLVTight_2);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_2", &lep_SF_El_PLVLoose_2, &b_lep_SF_El_PLVLoose_2);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_2", &lep_SF_El_ID_MediumLH_2, &b_lep_SF_El_ID_MediumLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_2", &lep_SF_El_Iso_PLImprovedTight_TightLH_2, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_2", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_2, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_2", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_2, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_2);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_2", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_2, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_2);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_2", &lep_SF_Mu_TTVA_AT_2, &b_lep_SF_Mu_TTVA_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_2", &lep_SF_Mu_ID_Loose_AT_2, &b_lep_SF_Mu_ID_Loose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_2", &lep_SF_Mu_ID_Medium_AT_2, &b_lep_SF_Mu_ID_Medium_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_2", &lep_SF_Mu_Iso_FCLoose_AT_2, &b_lep_SF_Mu_Iso_FCLoose_AT_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_2", &lep_SF_Mu_ID_Tight_2, &b_lep_SF_Mu_ID_Tight_2);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_2", &lep_SF_Mu_ID_HighPt_2, &b_lep_SF_Mu_ID_HighPt_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_2", &lep_SF_Mu_PLVTight_2, &b_lep_SF_Mu_PLVTight_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_2", &lep_SF_Mu_PLVLoose_2, &b_lep_SF_Mu_PLVLoose_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_2", &lep_SF_Mu_PLIV_MnotT_2, &b_lep_SF_Mu_PLIV_MnotT_2);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_2", &lep_SF_Mu_PLIV_T_2, &b_lep_SF_Mu_PLIV_T_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_2", &lep_SF_Mu_Iso_PflowTight_FixedRad_2, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_2", &lep_SF_Mu_Iso_PflowTight_VarRad_2, &b_lep_SF_Mu_Iso_PflowTight_VarRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_2", &lep_SF_Mu_Iso_PflowLoose_VarRad_2, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_2", &lep_SF_Mu_Iso_PflowLoose_FixedRad_2, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_2", &lep_SF_Mu_Iso_HighPtTrackOnly_2, &b_lep_SF_Mu_Iso_HighPtTrackOnly_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_2", &lep_SF_Mu_Iso_Tight_FixedRad_2, &b_lep_SF_Mu_Iso_Tight_FixedRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_2", &lep_SF_Mu_Iso_Loose_FixedRad_2, &b_lep_SF_Mu_Iso_Loose_FixedRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_2", &lep_SF_Mu_Iso_Loose_VarRad_2, &b_lep_SF_Mu_Iso_Loose_VarRad_2);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_2", &lep_SF_Mu_Iso_Tight_VarRad_2, &b_lep_SF_Mu_Iso_Tight_VarRad_2);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_2", &lep_SF_CombinedLoose_2, &b_lep_SF_CombinedLoose_2);
   fChain->SetBranchAddress("lep_SF_CombinedTight_2", &lep_SF_CombinedTight_2, &b_lep_SF_CombinedTight_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Index_3", &lep_Index_3, &b_lep_Index_3);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_EtaBE2_3", &lep_EtaBE2_3, &b_lep_EtaBE2_3);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   fChain->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   fChain->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   fChain->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   fChain->SetBranchAddress("lep_vz_3", &lep_vz_3, &b_lep_vz_3);
   fChain->SetBranchAddress("lep_deltaz0_3", &lep_deltaz0_3, &b_lep_deltaz0_3);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isMediumLH_3", &lep_isMediumLH_3, &b_lep_isMediumLH_3);
   fChain->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   fChain->SetBranchAddress("lep_isTight_3", &lep_isTight_3, &b_lep_isTight_3);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isLoose_3", &lep_isLoose_3, &b_lep_isLoose_3);
   fChain->SetBranchAddress("lep_isHighPt_3", &lep_isHighPt_3, &b_lep_isHighPt_3);
   fChain->SetBranchAddress("lep_isolationFCLoose_3", &lep_isolationFCLoose_3, &b_lep_isolationFCLoose_3);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_3", &lep_isolationPLImprovedTight_3, &b_lep_isolationPLImprovedTight_3);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_3", &lep_isolationPLImprovedVeryTight_3, &b_lep_isolationPLImprovedVeryTight_3);
   fChain->SetBranchAddress("lep_isolationFCTight_3", &lep_isolationFCTight_3, &b_lep_isolationFCTight_3);
   fChain->SetBranchAddress("lep_isolationLoose_3", &lep_isolationLoose_3, &b_lep_isolationLoose_3);
   fChain->SetBranchAddress("lep_isolationGradient_3", &lep_isolationGradient_3, &b_lep_isolationGradient_3);
   fChain->SetBranchAddress("lep_isolationGradientLoose_3", &lep_isolationGradientLoose_3, &b_lep_isolationGradientLoose_3);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_3", &lep_isolationTightTrackOnly_3, &b_lep_isolationTightTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_3", &lep_isolationHighPtCaloOnly_3, &b_lep_isolationHighPtCaloOnly_3);
   fChain->SetBranchAddress("lep_isolationPflowTight_3", &lep_isolationPflowTight_3, &b_lep_isolationPflowTight_3);
   fChain->SetBranchAddress("lep_isolationPflowLoose_3", &lep_isolationPflowLoose_3, &b_lep_isolationPflowLoose_3);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_3", &lep_isolationPflowTight_VarRad_3, &b_lep_isolationPflowTight_VarRad_3);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_3", &lep_isolationPflowTight_FixedRad_3, &b_lep_isolationPflowTight_FixedRad_3);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_3", &lep_isolationPflowLoose_VarRad_3, &b_lep_isolationPflowLoose_VarRad_3);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_3", &lep_isolationPflowLoose_FixedRad_3, &b_lep_isolationPflowLoose_FixedRad_3);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_3", &lep_isolationHighPtTrackOnly_3, &b_lep_isolationHighPtTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_3", &lep_isolationTight_FixedRad_3, &b_lep_isolationTight_FixedRad_3);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_3", &lep_isolationLoose_FixedRad_3, &b_lep_isolationLoose_FixedRad_3);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_3", &lep_isolationTightTrackOnly_VarRad_3, &b_lep_isolationTightTrackOnly_VarRad_3);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_3", &lep_isolationTightTrackOnly_FixedRad_3, &b_lep_isolationTightTrackOnly_FixedRad_3);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_3", &lep_isolationTight_VarRad_3, &b_lep_isolationTight_VarRad_3);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_3", &lep_isolationLoose_VarRad_3, &b_lep_isolationLoose_VarRad_3);
   fChain->SetBranchAddress("lep_plvWP_Loose_3", &lep_plvWP_Loose_3, &b_lep_plvWP_Loose_3);
   fChain->SetBranchAddress("lep_plvWP_Tight_3", &lep_plvWP_Tight_3, &b_lep_plvWP_Tight_3);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_3", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_3, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   fChain->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   fChain->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   fChain->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   fChain->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   fChain->SetBranchAddress("lep_isExtConvPh_3", &lep_isExtConvPh_3, &b_lep_isExtConvPh_3);
   fChain->SetBranchAddress("lep_isIntConvPh_3", &lep_isIntConvPh_3, &b_lep_isIntConvPh_3);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   fChain->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   fChain->SetBranchAddress("lep_nTrackParticles_3", &lep_nTrackParticles_3, &b_lep_nTrackParticles_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_3", &lep_Mtrktrk_atPV_CO_3, &b_lep_Mtrktrk_atPV_CO_3);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_3", &lep_Mtrktrk_atConvV_CO_3, &b_lep_Mtrktrk_atConvV_CO_3);
   fChain->SetBranchAddress("lep_RadiusCO_3", &lep_RadiusCO_3, &b_lep_RadiusCO_3);
   fChain->SetBranchAddress("lep_RadiusCOX_3", &lep_RadiusCOX_3, &b_lep_RadiusCOX_3);
   fChain->SetBranchAddress("lep_RadiusCOY_3", &lep_RadiusCOY_3, &b_lep_RadiusCOY_3);
   fChain->SetBranchAddress("lep_SeparationMinDCT_3", &lep_SeparationMinDCT_3, &b_lep_SeparationMinDCT_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_3", &lep_DFCommonSimpleConvRadius_3, &b_lep_DFCommonSimpleConvRadius_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_3", &lep_DFCommonSimpleConvPhi_3, &b_lep_DFCommonSimpleConvPhi_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_3", &lep_DFCommonSimpleMee_3, &b_lep_DFCommonSimpleMee_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_3", &lep_DFCommonSimpleMeeAtVtx_3, &b_lep_DFCommonSimpleMeeAtVtx_3);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_3", &lep_DFCommonSimpleSeparation_3, &b_lep_DFCommonSimpleSeparation_3);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_3", &lep_DFCommonAddAmbiguity_3, &b_lep_DFCommonAddAmbiguity_3);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_3", &lep_DFCommonProdTrueRadius_3, &b_lep_DFCommonProdTrueRadius_3);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_3", &lep_DFCommonProdTruePhi_3, &b_lep_DFCommonProdTruePhi_3);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_3", &lep_DFCommonProdTrueZ_3, &b_lep_DFCommonProdTrueZ_3);
   fChain->SetBranchAddress("lep_DFCommonJetDr_3", &lep_DFCommonJetDr_3, &b_lep_DFCommonJetDr_3);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_3", &lep_chargeIDBDTLoose_3, &b_lep_chargeIDBDTLoose_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_3", &lep_chargeIDBDTResult_3, &b_lep_chargeIDBDTResult_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_3", &lep_chargeIDBDTResult_recalc_rel207_loose_3, &b_lep_chargeIDBDTResult_recalc_rel207_loose_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_3", &lep_chargeIDBDTResult_recalc_rel207_medium_3, &b_lep_chargeIDBDTResult_recalc_rel207_medium_3);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_3", &lep_chargeIDBDTResult_recalc_rel207_tight_3, &b_lep_chargeIDBDTResult_recalc_rel207_tight_3);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_3", &lep_promptLeptonIso_TagWeight_3, &b_lep_promptLeptonIso_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_3", &lep_promptLeptonVeto_TagWeight_3, &b_lep_promptLeptonVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_3", &lep_promptLeptonImprovedVeto_TagWeight_3, &b_lep_promptLeptonImprovedVeto_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_3", &lep_promptLeptonImprovedVetoBARR_TagWeight_3, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_3);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_3", &lep_promptLeptonImprovedVetoECAP_TagWeight_3, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_3", &lep_PromptLeptonImprovedInput_MVAXBin_3, &b_lep_PromptLeptonImprovedInput_MVAXBin_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_3", &lep_PromptLeptonImprovedInput_PtFrac_3, &b_lep_PromptLeptonImprovedInput_PtFrac_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_3", &lep_PromptLeptonImprovedInput_DRlj_3, &b_lep_PromptLeptonImprovedInput_DRlj_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_3", &lep_PromptLeptonImprovedInput_reltopoetcone30_3, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_3);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_3", &lep_PromptLeptonImprovedInput_relptvarcone30_3, &b_lep_PromptLeptonImprovedInput_relptvarcone30_3);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_3", &lep_PromptLeptonRNN_prompt_3, &b_lep_PromptLeptonRNN_prompt_3);
   fChain->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   fChain->SetBranchAddress("lep_AnpTruthType_3", &lep_AnpTruthType_3, &b_lep_AnpTruthType_3);
   fChain->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   fChain->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   fChain->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   fChain->SetBranchAddress("lep_truthStatus_3", &lep_truthStatus_3, &b_lep_truthStatus_3);
   fChain->SetBranchAddress("lep_truthParentType_3", &lep_truthParentType_3, &b_lep_truthParentType_3);
   fChain->SetBranchAddress("lep_truthParentOrigin_3", &lep_truthParentOrigin_3, &b_lep_truthParentOrigin_3);
   fChain->SetBranchAddress("lep_truthParentPdgId_3", &lep_truthParentPdgId_3, &b_lep_truthParentPdgId_3);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_3", &lep_truthParentRealPdgId_3, &b_lep_truthParentRealPdgId_3);
   fChain->SetBranchAddress("lep_truthParentStatus_3", &lep_truthParentStatus_3, &b_lep_truthParentStatus_3);
   fChain->SetBranchAddress("lep_truthParentBarcode_3", &lep_truthParentBarcode_3, &b_lep_truthParentBarcode_3);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_3", &lep_truthParentIsCHadron_3, &b_lep_truthParentIsCHadron_3);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_3", &lep_truthParentIsBHadron_3, &b_lep_truthParentIsBHadron_3);
   fChain->SetBranchAddress("lep_truthHasTopInChain_3", &lep_truthHasTopInChain_3, &b_lep_truthHasTopInChain_3);
   fChain->SetBranchAddress("lep_truthParentPt_3", &lep_truthParentPt_3, &b_lep_truthParentPt_3);
   fChain->SetBranchAddress("lep_truthParentEta_3", &lep_truthParentEta_3, &b_lep_truthParentEta_3);
   fChain->SetBranchAddress("lep_truthPt_3", &lep_truthPt_3, &b_lep_truthPt_3);
   fChain->SetBranchAddress("lep_truthEta_3", &lep_truthEta_3, &b_lep_truthEta_3);
   fChain->SetBranchAddress("lep_truthPhi_3", &lep_truthPhi_3, &b_lep_truthPhi_3);
   fChain->SetBranchAddress("lep_truthM_3", &lep_truthM_3, &b_lep_truthM_3);
   fChain->SetBranchAddress("lep_truthE_3", &lep_truthE_3, &b_lep_truthE_3);
   fChain->SetBranchAddress("lep_truthRapidity_3", &lep_truthRapidity_3, &b_lep_truthRapidity_3);
   fChain->SetBranchAddress("lep_ambiguityType_3", &lep_ambiguityType_3, &b_lep_ambiguityType_3);
   fChain->SetBranchAddress("lep_nInnerPix_3", &lep_nInnerPix_3, &b_lep_nInnerPix_3);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_3", &lep_firstEgMotherPdgId_3, &b_lep_firstEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_3", &lep_firstEgMotherTruthType_3, &b_lep_firstEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_3", &lep_firstEgMotherTruthOrigin_3, &b_lep_firstEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_3", &lep_lastEgMotherPdgId_3, &b_lep_lastEgMotherPdgId_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_3", &lep_lastEgMotherTruthType_3, &b_lep_lastEgMotherTruthType_3);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_3", &lep_lastEgMotherTruthOrigin_3, &b_lep_lastEgMotherTruthOrigin_3);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_3", &lep_SF_El_Reco_AT_3, &b_lep_SF_El_Reco_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_3", &lep_SF_El_ID_LooseAndBLayerLH_AT_3, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_3", &lep_SF_El_ID_TightLH_AT_3, &b_lep_SF_El_ID_TightLH_AT_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_3", &lep_SF_El_Iso_FCLoose_AT_3, &b_lep_SF_El_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_3", &lep_SF_El_FCLooseTightLHQMisID_3, &b_lep_SF_El_FCLooseTightLHQMisID_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_3", &lep_SF_El_Iso_FCLoose_TightLH_3, &b_lep_SF_El_Iso_FCLoose_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_3", &lep_SF_El_PLVTight_QmisID_3, &b_lep_SF_El_PLVTight_QmisID_3);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_3", &lep_SF_El_PLVTight_3, &b_lep_SF_El_PLVTight_3);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_3", &lep_SF_El_PLVLoose_3, &b_lep_SF_El_PLVLoose_3);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_3", &lep_SF_El_ID_MediumLH_3, &b_lep_SF_El_ID_MediumLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_3", &lep_SF_El_Iso_PLImprovedTight_TightLH_3, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_3", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_3, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_3", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_3, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_3);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_3", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_3, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_3);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_3", &lep_SF_Mu_TTVA_AT_3, &b_lep_SF_Mu_TTVA_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_3", &lep_SF_Mu_ID_Loose_AT_3, &b_lep_SF_Mu_ID_Loose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_3", &lep_SF_Mu_ID_Medium_AT_3, &b_lep_SF_Mu_ID_Medium_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_3", &lep_SF_Mu_Iso_FCLoose_AT_3, &b_lep_SF_Mu_Iso_FCLoose_AT_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_3", &lep_SF_Mu_ID_Tight_3, &b_lep_SF_Mu_ID_Tight_3);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_3", &lep_SF_Mu_ID_HighPt_3, &b_lep_SF_Mu_ID_HighPt_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_3", &lep_SF_Mu_PLVTight_3, &b_lep_SF_Mu_PLVTight_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_3", &lep_SF_Mu_PLVLoose_3, &b_lep_SF_Mu_PLVLoose_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_3", &lep_SF_Mu_PLIV_MnotT_3, &b_lep_SF_Mu_PLIV_MnotT_3);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_3", &lep_SF_Mu_PLIV_T_3, &b_lep_SF_Mu_PLIV_T_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_3", &lep_SF_Mu_Iso_PflowTight_FixedRad_3, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_3", &lep_SF_Mu_Iso_PflowTight_VarRad_3, &b_lep_SF_Mu_Iso_PflowTight_VarRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_3", &lep_SF_Mu_Iso_PflowLoose_VarRad_3, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_3", &lep_SF_Mu_Iso_PflowLoose_FixedRad_3, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_3", &lep_SF_Mu_Iso_HighPtTrackOnly_3, &b_lep_SF_Mu_Iso_HighPtTrackOnly_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_3", &lep_SF_Mu_Iso_Tight_FixedRad_3, &b_lep_SF_Mu_Iso_Tight_FixedRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_3", &lep_SF_Mu_Iso_Loose_FixedRad_3, &b_lep_SF_Mu_Iso_Loose_FixedRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_3", &lep_SF_Mu_Iso_Loose_VarRad_3, &b_lep_SF_Mu_Iso_Loose_VarRad_3);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_3", &lep_SF_Mu_Iso_Tight_VarRad_3, &b_lep_SF_Mu_Iso_Tight_VarRad_3);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_3", &lep_SF_CombinedLoose_3, &b_lep_SF_CombinedLoose_3);
   fChain->SetBranchAddress("lep_SF_CombinedTight_3", &lep_SF_CombinedTight_3, &b_lep_SF_CombinedTight_3);
   fChain->SetBranchAddress("lep_ID_4", &lep_ID_4, &b_lep_ID_4);
   fChain->SetBranchAddress("lep_Index_4", &lep_Index_4, &b_lep_Index_4);
   fChain->SetBranchAddress("lep_Pt_4", &lep_Pt_4, &b_lep_Pt_4);
   fChain->SetBranchAddress("lep_E_4", &lep_E_4, &b_lep_E_4);
   fChain->SetBranchAddress("lep_Eta_4", &lep_Eta_4, &b_lep_Eta_4);
   fChain->SetBranchAddress("lep_EtaBE2_4", &lep_EtaBE2_4, &b_lep_EtaBE2_4);
   fChain->SetBranchAddress("lep_Phi_4", &lep_Phi_4, &b_lep_Phi_4);
   fChain->SetBranchAddress("lep_sigd0PV_4", &lep_sigd0PV_4, &b_lep_sigd0PV_4);
   fChain->SetBranchAddress("lep_Z0SinTheta_4", &lep_Z0SinTheta_4, &b_lep_Z0SinTheta_4);
   fChain->SetBranchAddress("lep_d0_4", &lep_d0_4, &b_lep_d0_4);
   fChain->SetBranchAddress("lep_z0_4", &lep_z0_4, &b_lep_z0_4);
   fChain->SetBranchAddress("lep_vz_4", &lep_vz_4, &b_lep_vz_4);
   fChain->SetBranchAddress("lep_deltaz0_4", &lep_deltaz0_4, &b_lep_deltaz0_4);
   fChain->SetBranchAddress("lep_isTightLH_4", &lep_isTightLH_4, &b_lep_isTightLH_4);
   fChain->SetBranchAddress("lep_isMediumLH_4", &lep_isMediumLH_4, &b_lep_isMediumLH_4);
   fChain->SetBranchAddress("lep_isLooseLH_4", &lep_isLooseLH_4, &b_lep_isLooseLH_4);
   fChain->SetBranchAddress("lep_isTight_4", &lep_isTight_4, &b_lep_isTight_4);
   fChain->SetBranchAddress("lep_isMedium_4", &lep_isMedium_4, &b_lep_isMedium_4);
   fChain->SetBranchAddress("lep_isLoose_4", &lep_isLoose_4, &b_lep_isLoose_4);
   fChain->SetBranchAddress("lep_isHighPt_4", &lep_isHighPt_4, &b_lep_isHighPt_4);
   fChain->SetBranchAddress("lep_isolationFCLoose_4", &lep_isolationFCLoose_4, &b_lep_isolationFCLoose_4);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_4", &lep_isolationPLImprovedTight_4, &b_lep_isolationPLImprovedTight_4);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_4", &lep_isolationPLImprovedVeryTight_4, &b_lep_isolationPLImprovedVeryTight_4);
   fChain->SetBranchAddress("lep_isolationFCTight_4", &lep_isolationFCTight_4, &b_lep_isolationFCTight_4);
   fChain->SetBranchAddress("lep_isolationLoose_4", &lep_isolationLoose_4, &b_lep_isolationLoose_4);
   fChain->SetBranchAddress("lep_isolationGradient_4", &lep_isolationGradient_4, &b_lep_isolationGradient_4);
   fChain->SetBranchAddress("lep_isolationGradientLoose_4", &lep_isolationGradientLoose_4, &b_lep_isolationGradientLoose_4);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_4", &lep_isolationTightTrackOnly_4, &b_lep_isolationTightTrackOnly_4);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_4", &lep_isolationHighPtCaloOnly_4, &b_lep_isolationHighPtCaloOnly_4);
   fChain->SetBranchAddress("lep_isolationPflowTight_4", &lep_isolationPflowTight_4, &b_lep_isolationPflowTight_4);
   fChain->SetBranchAddress("lep_isolationPflowLoose_4", &lep_isolationPflowLoose_4, &b_lep_isolationPflowLoose_4);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_4", &lep_isolationPflowTight_VarRad_4, &b_lep_isolationPflowTight_VarRad_4);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_4", &lep_isolationPflowTight_FixedRad_4, &b_lep_isolationPflowTight_FixedRad_4);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_4", &lep_isolationPflowLoose_VarRad_4, &b_lep_isolationPflowLoose_VarRad_4);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_4", &lep_isolationPflowLoose_FixedRad_4, &b_lep_isolationPflowLoose_FixedRad_4);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_4", &lep_isolationHighPtTrackOnly_4, &b_lep_isolationHighPtTrackOnly_4);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_4", &lep_isolationTight_FixedRad_4, &b_lep_isolationTight_FixedRad_4);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_4", &lep_isolationLoose_FixedRad_4, &b_lep_isolationLoose_FixedRad_4);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_4", &lep_isolationTightTrackOnly_VarRad_4, &b_lep_isolationTightTrackOnly_VarRad_4);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_4", &lep_isolationTightTrackOnly_FixedRad_4, &b_lep_isolationTightTrackOnly_FixedRad_4);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_4", &lep_isolationTight_VarRad_4, &b_lep_isolationTight_VarRad_4);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_4", &lep_isolationLoose_VarRad_4, &b_lep_isolationLoose_VarRad_4);
   fChain->SetBranchAddress("lep_plvWP_Loose_4", &lep_plvWP_Loose_4, &b_lep_plvWP_Loose_4);
   fChain->SetBranchAddress("lep_plvWP_Tight_4", &lep_plvWP_Tight_4, &b_lep_plvWP_Tight_4);
   fChain->SetBranchAddress("lep_isTrigMatch_4", &lep_isTrigMatch_4, &b_lep_isTrigMatch_4);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_4", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_4, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_4);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_4", &lep_isTrigMatchDLT_4, &b_lep_isTrigMatchDLT_4);
   fChain->SetBranchAddress("lep_isPrompt_4", &lep_isPrompt_4, &b_lep_isPrompt_4);
   fChain->SetBranchAddress("lep_isFakeLep_4", &lep_isFakeLep_4, &b_lep_isFakeLep_4);
   fChain->SetBranchAddress("lep_isQMisID_4", &lep_isQMisID_4, &b_lep_isQMisID_4);
   fChain->SetBranchAddress("lep_isConvPh_4", &lep_isConvPh_4, &b_lep_isConvPh_4);
   fChain->SetBranchAddress("lep_isExtConvPh_4", &lep_isExtConvPh_4, &b_lep_isExtConvPh_4);
   fChain->SetBranchAddress("lep_isIntConvPh_4", &lep_isIntConvPh_4, &b_lep_isIntConvPh_4);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_4", &lep_isISR_FSR_Ph_4, &b_lep_isISR_FSR_Ph_4);
   fChain->SetBranchAddress("lep_isBrems_4", &lep_isBrems_4, &b_lep_isBrems_4);
   fChain->SetBranchAddress("lep_nTrackParticles_4", &lep_nTrackParticles_4, &b_lep_nTrackParticles_4);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_4", &lep_Mtrktrk_atPV_CO_4, &b_lep_Mtrktrk_atPV_CO_4);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_4", &lep_Mtrktrk_atConvV_CO_4, &b_lep_Mtrktrk_atConvV_CO_4);
   fChain->SetBranchAddress("lep_RadiusCO_4", &lep_RadiusCO_4, &b_lep_RadiusCO_4);
   fChain->SetBranchAddress("lep_RadiusCOX_4", &lep_RadiusCOX_4, &b_lep_RadiusCOX_4);
   fChain->SetBranchAddress("lep_RadiusCOY_4", &lep_RadiusCOY_4, &b_lep_RadiusCOY_4);
   fChain->SetBranchAddress("lep_SeparationMinDCT_4", &lep_SeparationMinDCT_4, &b_lep_SeparationMinDCT_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_4", &lep_DFCommonSimpleConvRadius_4, &b_lep_DFCommonSimpleConvRadius_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_4", &lep_DFCommonSimpleConvPhi_4, &b_lep_DFCommonSimpleConvPhi_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_4", &lep_DFCommonSimpleMee_4, &b_lep_DFCommonSimpleMee_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_4", &lep_DFCommonSimpleMeeAtVtx_4, &b_lep_DFCommonSimpleMeeAtVtx_4);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_4", &lep_DFCommonSimpleSeparation_4, &b_lep_DFCommonSimpleSeparation_4);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_4", &lep_DFCommonAddAmbiguity_4, &b_lep_DFCommonAddAmbiguity_4);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_4", &lep_DFCommonProdTrueRadius_4, &b_lep_DFCommonProdTrueRadius_4);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_4", &lep_DFCommonProdTruePhi_4, &b_lep_DFCommonProdTruePhi_4);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_4", &lep_DFCommonProdTrueZ_4, &b_lep_DFCommonProdTrueZ_4);
   fChain->SetBranchAddress("lep_DFCommonJetDr_4", &lep_DFCommonJetDr_4, &b_lep_DFCommonJetDr_4);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_4", &lep_chargeIDBDTLoose_4, &b_lep_chargeIDBDTLoose_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_4", &lep_chargeIDBDTResult_4, &b_lep_chargeIDBDTResult_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_4", &lep_chargeIDBDTResult_recalc_rel207_loose_4, &b_lep_chargeIDBDTResult_recalc_rel207_loose_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_4", &lep_chargeIDBDTResult_recalc_rel207_medium_4, &b_lep_chargeIDBDTResult_recalc_rel207_medium_4);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_4", &lep_chargeIDBDTResult_recalc_rel207_tight_4, &b_lep_chargeIDBDTResult_recalc_rel207_tight_4);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_4", &lep_promptLeptonIso_TagWeight_4, &b_lep_promptLeptonIso_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_4", &lep_promptLeptonVeto_TagWeight_4, &b_lep_promptLeptonVeto_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_4", &lep_promptLeptonImprovedVeto_TagWeight_4, &b_lep_promptLeptonImprovedVeto_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_4", &lep_promptLeptonImprovedVetoBARR_TagWeight_4, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_4);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_4", &lep_promptLeptonImprovedVetoECAP_TagWeight_4, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_4", &lep_PromptLeptonImprovedInput_MVAXBin_4, &b_lep_PromptLeptonImprovedInput_MVAXBin_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_4", &lep_PromptLeptonImprovedInput_PtFrac_4, &b_lep_PromptLeptonImprovedInput_PtFrac_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_4", &lep_PromptLeptonImprovedInput_DRlj_4, &b_lep_PromptLeptonImprovedInput_DRlj_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_4", &lep_PromptLeptonImprovedInput_reltopoetcone30_4, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_4);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_4", &lep_PromptLeptonImprovedInput_relptvarcone30_4, &b_lep_PromptLeptonImprovedInput_relptvarcone30_4);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_4", &lep_PromptLeptonRNN_prompt_4, &b_lep_PromptLeptonRNN_prompt_4);
   fChain->SetBranchAddress("lep_isTruthMatched_4", &lep_isTruthMatched_4, &b_lep_isTruthMatched_4);
   fChain->SetBranchAddress("lep_AnpTruthType_4", &lep_AnpTruthType_4, &b_lep_AnpTruthType_4);
   fChain->SetBranchAddress("lep_truthType_4", &lep_truthType_4, &b_lep_truthType_4);
   fChain->SetBranchAddress("lep_truthOrigin_4", &lep_truthOrigin_4, &b_lep_truthOrigin_4);
   fChain->SetBranchAddress("lep_truthPdgId_4", &lep_truthPdgId_4, &b_lep_truthPdgId_4);
   fChain->SetBranchAddress("lep_truthStatus_4", &lep_truthStatus_4, &b_lep_truthStatus_4);
   fChain->SetBranchAddress("lep_truthParentType_4", &lep_truthParentType_4, &b_lep_truthParentType_4);
   fChain->SetBranchAddress("lep_truthParentOrigin_4", &lep_truthParentOrigin_4, &b_lep_truthParentOrigin_4);
   fChain->SetBranchAddress("lep_truthParentPdgId_4", &lep_truthParentPdgId_4, &b_lep_truthParentPdgId_4);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_4", &lep_truthParentRealPdgId_4, &b_lep_truthParentRealPdgId_4);
   fChain->SetBranchAddress("lep_truthParentStatus_4", &lep_truthParentStatus_4, &b_lep_truthParentStatus_4);
   fChain->SetBranchAddress("lep_truthParentBarcode_4", &lep_truthParentBarcode_4, &b_lep_truthParentBarcode_4);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_4", &lep_truthParentIsCHadron_4, &b_lep_truthParentIsCHadron_4);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_4", &lep_truthParentIsBHadron_4, &b_lep_truthParentIsBHadron_4);
   fChain->SetBranchAddress("lep_truthHasTopInChain_4", &lep_truthHasTopInChain_4, &b_lep_truthHasTopInChain_4);
   fChain->SetBranchAddress("lep_truthParentPt_4", &lep_truthParentPt_4, &b_lep_truthParentPt_4);
   fChain->SetBranchAddress("lep_truthParentEta_4", &lep_truthParentEta_4, &b_lep_truthParentEta_4);
   fChain->SetBranchAddress("lep_truthPt_4", &lep_truthPt_4, &b_lep_truthPt_4);
   fChain->SetBranchAddress("lep_truthEta_4", &lep_truthEta_4, &b_lep_truthEta_4);
   fChain->SetBranchAddress("lep_truthPhi_4", &lep_truthPhi_4, &b_lep_truthPhi_4);
   fChain->SetBranchAddress("lep_truthM_4", &lep_truthM_4, &b_lep_truthM_4);
   fChain->SetBranchAddress("lep_truthE_4", &lep_truthE_4, &b_lep_truthE_4);
   fChain->SetBranchAddress("lep_truthRapidity_4", &lep_truthRapidity_4, &b_lep_truthRapidity_4);
   fChain->SetBranchAddress("lep_ambiguityType_4", &lep_ambiguityType_4, &b_lep_ambiguityType_4);
   fChain->SetBranchAddress("lep_nInnerPix_4", &lep_nInnerPix_4, &b_lep_nInnerPix_4);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_4", &lep_firstEgMotherPdgId_4, &b_lep_firstEgMotherPdgId_4);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_4", &lep_firstEgMotherTruthType_4, &b_lep_firstEgMotherTruthType_4);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_4", &lep_firstEgMotherTruthOrigin_4, &b_lep_firstEgMotherTruthOrigin_4);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_4", &lep_lastEgMotherPdgId_4, &b_lep_lastEgMotherPdgId_4);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_4", &lep_lastEgMotherTruthType_4, &b_lep_lastEgMotherTruthType_4);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_4", &lep_lastEgMotherTruthOrigin_4, &b_lep_lastEgMotherTruthOrigin_4);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_4", &lep_SF_El_Reco_AT_4, &b_lep_SF_El_Reco_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_4", &lep_SF_El_ID_LooseAndBLayerLH_AT_4, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_4", &lep_SF_El_ID_TightLH_AT_4, &b_lep_SF_El_ID_TightLH_AT_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_4", &lep_SF_El_Iso_FCLoose_AT_4, &b_lep_SF_El_Iso_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_4", &lep_SF_El_FCLooseTightLHQMisID_4, &b_lep_SF_El_FCLooseTightLHQMisID_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_4", &lep_SF_El_Iso_FCLoose_TightLH_4, &b_lep_SF_El_Iso_FCLoose_TightLH_4);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_4", &lep_SF_El_PLVTight_QmisID_4, &b_lep_SF_El_PLVTight_QmisID_4);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_4", &lep_SF_El_PLVTight_4, &b_lep_SF_El_PLVTight_4);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_4", &lep_SF_El_PLVLoose_4, &b_lep_SF_El_PLVLoose_4);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_4", &lep_SF_El_ID_MediumLH_4, &b_lep_SF_El_ID_MediumLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_4", &lep_SF_El_Iso_PLImprovedTight_TightLH_4, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_4", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_4, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_4", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_4, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_4);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_4", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_4, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_4);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_4", &lep_SF_Mu_TTVA_AT_4, &b_lep_SF_Mu_TTVA_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_4", &lep_SF_Mu_ID_Loose_AT_4, &b_lep_SF_Mu_ID_Loose_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_4", &lep_SF_Mu_ID_Medium_AT_4, &b_lep_SF_Mu_ID_Medium_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_4", &lep_SF_Mu_Iso_FCLoose_AT_4, &b_lep_SF_Mu_Iso_FCLoose_AT_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_4", &lep_SF_Mu_ID_Tight_4, &b_lep_SF_Mu_ID_Tight_4);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_4", &lep_SF_Mu_ID_HighPt_4, &b_lep_SF_Mu_ID_HighPt_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_4", &lep_SF_Mu_PLVTight_4, &b_lep_SF_Mu_PLVTight_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_4", &lep_SF_Mu_PLVLoose_4, &b_lep_SF_Mu_PLVLoose_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_4", &lep_SF_Mu_PLIV_MnotT_4, &b_lep_SF_Mu_PLIV_MnotT_4);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_4", &lep_SF_Mu_PLIV_T_4, &b_lep_SF_Mu_PLIV_T_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_4", &lep_SF_Mu_Iso_PflowTight_FixedRad_4, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_4", &lep_SF_Mu_Iso_PflowTight_VarRad_4, &b_lep_SF_Mu_Iso_PflowTight_VarRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_4", &lep_SF_Mu_Iso_PflowLoose_VarRad_4, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_4", &lep_SF_Mu_Iso_PflowLoose_FixedRad_4, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_4", &lep_SF_Mu_Iso_HighPtTrackOnly_4, &b_lep_SF_Mu_Iso_HighPtTrackOnly_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_4", &lep_SF_Mu_Iso_Tight_FixedRad_4, &b_lep_SF_Mu_Iso_Tight_FixedRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_4", &lep_SF_Mu_Iso_Loose_FixedRad_4, &b_lep_SF_Mu_Iso_Loose_FixedRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_4", &lep_SF_Mu_Iso_Loose_VarRad_4, &b_lep_SF_Mu_Iso_Loose_VarRad_4);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_4", &lep_SF_Mu_Iso_Tight_VarRad_4, &b_lep_SF_Mu_Iso_Tight_VarRad_4);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_4", &lep_SF_CombinedLoose_4, &b_lep_SF_CombinedLoose_4);
   fChain->SetBranchAddress("lep_SF_CombinedTight_4", &lep_SF_CombinedTight_4, &b_lep_SF_CombinedTight_4);
   fChain->SetBranchAddress("lep_ID_5", &lep_ID_5, &b_lep_ID_5);
   fChain->SetBranchAddress("lep_Index_5", &lep_Index_5, &b_lep_Index_5);
   fChain->SetBranchAddress("lep_Pt_5", &lep_Pt_5, &b_lep_Pt_5);
   fChain->SetBranchAddress("lep_E_5", &lep_E_5, &b_lep_E_5);
   fChain->SetBranchAddress("lep_Eta_5", &lep_Eta_5, &b_lep_Eta_5);
   fChain->SetBranchAddress("lep_EtaBE2_5", &lep_EtaBE2_5, &b_lep_EtaBE2_5);
   fChain->SetBranchAddress("lep_Phi_5", &lep_Phi_5, &b_lep_Phi_5);
   fChain->SetBranchAddress("lep_sigd0PV_5", &lep_sigd0PV_5, &b_lep_sigd0PV_5);
   fChain->SetBranchAddress("lep_Z0SinTheta_5", &lep_Z0SinTheta_5, &b_lep_Z0SinTheta_5);
   fChain->SetBranchAddress("lep_d0_5", &lep_d0_5, &b_lep_d0_5);
   fChain->SetBranchAddress("lep_z0_5", &lep_z0_5, &b_lep_z0_5);
   fChain->SetBranchAddress("lep_vz_5", &lep_vz_5, &b_lep_vz_5);
   fChain->SetBranchAddress("lep_deltaz0_5", &lep_deltaz0_5, &b_lep_deltaz0_5);
   fChain->SetBranchAddress("lep_isTightLH_5", &lep_isTightLH_5, &b_lep_isTightLH_5);
   fChain->SetBranchAddress("lep_isMediumLH_5", &lep_isMediumLH_5, &b_lep_isMediumLH_5);
   fChain->SetBranchAddress("lep_isLooseLH_5", &lep_isLooseLH_5, &b_lep_isLooseLH_5);
   fChain->SetBranchAddress("lep_isTight_5", &lep_isTight_5, &b_lep_isTight_5);
   fChain->SetBranchAddress("lep_isMedium_5", &lep_isMedium_5, &b_lep_isMedium_5);
   fChain->SetBranchAddress("lep_isLoose_5", &lep_isLoose_5, &b_lep_isLoose_5);
   fChain->SetBranchAddress("lep_isHighPt_5", &lep_isHighPt_5, &b_lep_isHighPt_5);
   fChain->SetBranchAddress("lep_isolationFCLoose_5", &lep_isolationFCLoose_5, &b_lep_isolationFCLoose_5);
   fChain->SetBranchAddress("lep_isolationPLImprovedTight_5", &lep_isolationPLImprovedTight_5, &b_lep_isolationPLImprovedTight_5);
   fChain->SetBranchAddress("lep_isolationPLImprovedVeryTight_5", &lep_isolationPLImprovedVeryTight_5, &b_lep_isolationPLImprovedVeryTight_5);
   fChain->SetBranchAddress("lep_isolationFCTight_5", &lep_isolationFCTight_5, &b_lep_isolationFCTight_5);
   fChain->SetBranchAddress("lep_isolationLoose_5", &lep_isolationLoose_5, &b_lep_isolationLoose_5);
   fChain->SetBranchAddress("lep_isolationGradient_5", &lep_isolationGradient_5, &b_lep_isolationGradient_5);
   fChain->SetBranchAddress("lep_isolationGradientLoose_5", &lep_isolationGradientLoose_5, &b_lep_isolationGradientLoose_5);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_5", &lep_isolationTightTrackOnly_5, &b_lep_isolationTightTrackOnly_5);
   fChain->SetBranchAddress("lep_isolationHighPtCaloOnly_5", &lep_isolationHighPtCaloOnly_5, &b_lep_isolationHighPtCaloOnly_5);
   fChain->SetBranchAddress("lep_isolationPflowTight_5", &lep_isolationPflowTight_5, &b_lep_isolationPflowTight_5);
   fChain->SetBranchAddress("lep_isolationPflowLoose_5", &lep_isolationPflowLoose_5, &b_lep_isolationPflowLoose_5);
   fChain->SetBranchAddress("lep_isolationPflowTight_VarRad_5", &lep_isolationPflowTight_VarRad_5, &b_lep_isolationPflowTight_VarRad_5);
   fChain->SetBranchAddress("lep_isolationPflowTight_FixedRad_5", &lep_isolationPflowTight_FixedRad_5, &b_lep_isolationPflowTight_FixedRad_5);
   fChain->SetBranchAddress("lep_isolationPflowLoose_VarRad_5", &lep_isolationPflowLoose_VarRad_5, &b_lep_isolationPflowLoose_VarRad_5);
   fChain->SetBranchAddress("lep_isolationPflowLoose_FixedRad_5", &lep_isolationPflowLoose_FixedRad_5, &b_lep_isolationPflowLoose_FixedRad_5);
   fChain->SetBranchAddress("lep_isolationHighPtTrackOnly_5", &lep_isolationHighPtTrackOnly_5, &b_lep_isolationHighPtTrackOnly_5);
   fChain->SetBranchAddress("lep_isolationTight_FixedRad_5", &lep_isolationTight_FixedRad_5, &b_lep_isolationTight_FixedRad_5);
   fChain->SetBranchAddress("lep_isolationLoose_FixedRad_5", &lep_isolationLoose_FixedRad_5, &b_lep_isolationLoose_FixedRad_5);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_VarRad_5", &lep_isolationTightTrackOnly_VarRad_5, &b_lep_isolationTightTrackOnly_VarRad_5);
   fChain->SetBranchAddress("lep_isolationTightTrackOnly_FixedRad_5", &lep_isolationTightTrackOnly_FixedRad_5, &b_lep_isolationTightTrackOnly_FixedRad_5);
   fChain->SetBranchAddress("lep_isolationTight_VarRad_5", &lep_isolationTight_VarRad_5, &b_lep_isolationTight_VarRad_5);
   fChain->SetBranchAddress("lep_isolationLoose_VarRad_5", &lep_isolationLoose_VarRad_5, &b_lep_isolationLoose_VarRad_5);
   fChain->SetBranchAddress("lep_plvWP_Loose_5", &lep_plvWP_Loose_5, &b_lep_plvWP_Loose_5);
   fChain->SetBranchAddress("lep_plvWP_Tight_5", &lep_plvWP_Tight_5, &b_lep_plvWP_Tight_5);
   fChain->SetBranchAddress("lep_isTrigMatch_5", &lep_isTrigMatch_5, &b_lep_isTrigMatch_5);
   fChain->SetBranchAddress("lep_custTrigMatch_LooseID_FCLooseIso_SLT_5", &lep_custTrigMatch_LooseID_FCLooseIso_SLT_5, &b_lep_custTrigMatch_LooseID_FCLooseIso_SLT_5);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_5", &lep_isTrigMatchDLT_5, &b_lep_isTrigMatchDLT_5);
   fChain->SetBranchAddress("lep_isPrompt_5", &lep_isPrompt_5, &b_lep_isPrompt_5);
   fChain->SetBranchAddress("lep_isFakeLep_5", &lep_isFakeLep_5, &b_lep_isFakeLep_5);
   fChain->SetBranchAddress("lep_isQMisID_5", &lep_isQMisID_5, &b_lep_isQMisID_5);
   fChain->SetBranchAddress("lep_isConvPh_5", &lep_isConvPh_5, &b_lep_isConvPh_5);
   fChain->SetBranchAddress("lep_isExtConvPh_5", &lep_isExtConvPh_5, &b_lep_isExtConvPh_5);
   fChain->SetBranchAddress("lep_isIntConvPh_5", &lep_isIntConvPh_5, &b_lep_isIntConvPh_5);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_5", &lep_isISR_FSR_Ph_5, &b_lep_isISR_FSR_Ph_5);
   fChain->SetBranchAddress("lep_isBrems_5", &lep_isBrems_5, &b_lep_isBrems_5);
   fChain->SetBranchAddress("lep_nTrackParticles_5", &lep_nTrackParticles_5, &b_lep_nTrackParticles_5);
   fChain->SetBranchAddress("lep_Mtrktrk_atPV_CO_5", &lep_Mtrktrk_atPV_CO_5, &b_lep_Mtrktrk_atPV_CO_5);
   fChain->SetBranchAddress("lep_Mtrktrk_atConvV_CO_5", &lep_Mtrktrk_atConvV_CO_5, &b_lep_Mtrktrk_atConvV_CO_5);
   fChain->SetBranchAddress("lep_RadiusCO_5", &lep_RadiusCO_5, &b_lep_RadiusCO_5);
   fChain->SetBranchAddress("lep_RadiusCOX_5", &lep_RadiusCOX_5, &b_lep_RadiusCOX_5);
   fChain->SetBranchAddress("lep_RadiusCOY_5", &lep_RadiusCOY_5, &b_lep_RadiusCOY_5);
   fChain->SetBranchAddress("lep_SeparationMinDCT_5", &lep_SeparationMinDCT_5, &b_lep_SeparationMinDCT_5);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvRadius_5", &lep_DFCommonSimpleConvRadius_5, &b_lep_DFCommonSimpleConvRadius_5);
   fChain->SetBranchAddress("lep_DFCommonSimpleConvPhi_5", &lep_DFCommonSimpleConvPhi_5, &b_lep_DFCommonSimpleConvPhi_5);
   fChain->SetBranchAddress("lep_DFCommonSimpleMee_5", &lep_DFCommonSimpleMee_5, &b_lep_DFCommonSimpleMee_5);
   fChain->SetBranchAddress("lep_DFCommonSimpleMeeAtVtx_5", &lep_DFCommonSimpleMeeAtVtx_5, &b_lep_DFCommonSimpleMeeAtVtx_5);
   fChain->SetBranchAddress("lep_DFCommonSimpleSeparation_5", &lep_DFCommonSimpleSeparation_5, &b_lep_DFCommonSimpleSeparation_5);
   fChain->SetBranchAddress("lep_DFCommonAddAmbiguity_5", &lep_DFCommonAddAmbiguity_5, &b_lep_DFCommonAddAmbiguity_5);
   fChain->SetBranchAddress("lep_DFCommonProdTrueRadius_5", &lep_DFCommonProdTrueRadius_5, &b_lep_DFCommonProdTrueRadius_5);
   fChain->SetBranchAddress("lep_DFCommonProdTruePhi_5", &lep_DFCommonProdTruePhi_5, &b_lep_DFCommonProdTruePhi_5);
   fChain->SetBranchAddress("lep_DFCommonProdTrueZ_5", &lep_DFCommonProdTrueZ_5, &b_lep_DFCommonProdTrueZ_5);
   fChain->SetBranchAddress("lep_DFCommonJetDr_5", &lep_DFCommonJetDr_5, &b_lep_DFCommonJetDr_5);
   fChain->SetBranchAddress("lep_chargeIDBDTLoose_5", &lep_chargeIDBDTLoose_5, &b_lep_chargeIDBDTLoose_5);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_5", &lep_chargeIDBDTResult_5, &b_lep_chargeIDBDTResult_5);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_loose_5", &lep_chargeIDBDTResult_recalc_rel207_loose_5, &b_lep_chargeIDBDTResult_recalc_rel207_loose_5);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_medium_5", &lep_chargeIDBDTResult_recalc_rel207_medium_5, &b_lep_chargeIDBDTResult_recalc_rel207_medium_5);
   fChain->SetBranchAddress("lep_chargeIDBDTResult_recalc_rel207_tight_5", &lep_chargeIDBDTResult_recalc_rel207_tight_5, &b_lep_chargeIDBDTResult_recalc_rel207_tight_5);
   fChain->SetBranchAddress("lep_promptLeptonIso_TagWeight_5", &lep_promptLeptonIso_TagWeight_5, &b_lep_promptLeptonIso_TagWeight_5);
   fChain->SetBranchAddress("lep_promptLeptonVeto_TagWeight_5", &lep_promptLeptonVeto_TagWeight_5, &b_lep_promptLeptonVeto_TagWeight_5);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVeto_TagWeight_5", &lep_promptLeptonImprovedVeto_TagWeight_5, &b_lep_promptLeptonImprovedVeto_TagWeight_5);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoBARR_TagWeight_5", &lep_promptLeptonImprovedVetoBARR_TagWeight_5, &b_lep_promptLeptonImprovedVetoBARR_TagWeight_5);
   fChain->SetBranchAddress("lep_promptLeptonImprovedVetoECAP_TagWeight_5", &lep_promptLeptonImprovedVetoECAP_TagWeight_5, &b_lep_promptLeptonImprovedVetoECAP_TagWeight_5);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_MVAXBin_5", &lep_PromptLeptonImprovedInput_MVAXBin_5, &b_lep_PromptLeptonImprovedInput_MVAXBin_5);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_PtFrac_5", &lep_PromptLeptonImprovedInput_PtFrac_5, &b_lep_PromptLeptonImprovedInput_PtFrac_5);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_DRlj_5", &lep_PromptLeptonImprovedInput_DRlj_5, &b_lep_PromptLeptonImprovedInput_DRlj_5);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_reltopoetcone30_5", &lep_PromptLeptonImprovedInput_reltopoetcone30_5, &b_lep_PromptLeptonImprovedInput_reltopoetcone30_5);
   fChain->SetBranchAddress("lep_PromptLeptonImprovedInput_relptvarcone30_5", &lep_PromptLeptonImprovedInput_relptvarcone30_5, &b_lep_PromptLeptonImprovedInput_relptvarcone30_5);
   fChain->SetBranchAddress("lep_PromptLeptonRNN_prompt_5", &lep_PromptLeptonRNN_prompt_5, &b_lep_PromptLeptonRNN_prompt_5);
   fChain->SetBranchAddress("lep_isTruthMatched_5", &lep_isTruthMatched_5, &b_lep_isTruthMatched_5);
   fChain->SetBranchAddress("lep_AnpTruthType_5", &lep_AnpTruthType_5, &b_lep_AnpTruthType_5);
   fChain->SetBranchAddress("lep_truthType_5", &lep_truthType_5, &b_lep_truthType_5);
   fChain->SetBranchAddress("lep_truthOrigin_5", &lep_truthOrigin_5, &b_lep_truthOrigin_5);
   fChain->SetBranchAddress("lep_truthPdgId_5", &lep_truthPdgId_5, &b_lep_truthPdgId_5);
   fChain->SetBranchAddress("lep_truthStatus_5", &lep_truthStatus_5, &b_lep_truthStatus_5);
   fChain->SetBranchAddress("lep_truthParentType_5", &lep_truthParentType_5, &b_lep_truthParentType_5);
   fChain->SetBranchAddress("lep_truthParentOrigin_5", &lep_truthParentOrigin_5, &b_lep_truthParentOrigin_5);
   fChain->SetBranchAddress("lep_truthParentPdgId_5", &lep_truthParentPdgId_5, &b_lep_truthParentPdgId_5);
   fChain->SetBranchAddress("lep_truthParentRealPdgId_5", &lep_truthParentRealPdgId_5, &b_lep_truthParentRealPdgId_5);
   fChain->SetBranchAddress("lep_truthParentStatus_5", &lep_truthParentStatus_5, &b_lep_truthParentStatus_5);
   fChain->SetBranchAddress("lep_truthParentBarcode_5", &lep_truthParentBarcode_5, &b_lep_truthParentBarcode_5);
   fChain->SetBranchAddress("lep_truthParentIsCHadron_5", &lep_truthParentIsCHadron_5, &b_lep_truthParentIsCHadron_5);
   fChain->SetBranchAddress("lep_truthParentIsBHadron_5", &lep_truthParentIsBHadron_5, &b_lep_truthParentIsBHadron_5);
   fChain->SetBranchAddress("lep_truthHasTopInChain_5", &lep_truthHasTopInChain_5, &b_lep_truthHasTopInChain_5);
   fChain->SetBranchAddress("lep_truthParentPt_5", &lep_truthParentPt_5, &b_lep_truthParentPt_5);
   fChain->SetBranchAddress("lep_truthParentEta_5", &lep_truthParentEta_5, &b_lep_truthParentEta_5);
   fChain->SetBranchAddress("lep_truthPt_5", &lep_truthPt_5, &b_lep_truthPt_5);
   fChain->SetBranchAddress("lep_truthEta_5", &lep_truthEta_5, &b_lep_truthEta_5);
   fChain->SetBranchAddress("lep_truthPhi_5", &lep_truthPhi_5, &b_lep_truthPhi_5);
   fChain->SetBranchAddress("lep_truthM_5", &lep_truthM_5, &b_lep_truthM_5);
   fChain->SetBranchAddress("lep_truthE_5", &lep_truthE_5, &b_lep_truthE_5);
   fChain->SetBranchAddress("lep_truthRapidity_5", &lep_truthRapidity_5, &b_lep_truthRapidity_5);
   fChain->SetBranchAddress("lep_ambiguityType_5", &lep_ambiguityType_5, &b_lep_ambiguityType_5);
   fChain->SetBranchAddress("lep_nInnerPix_5", &lep_nInnerPix_5, &b_lep_nInnerPix_5);
   fChain->SetBranchAddress("lep_firstEgMotherPdgId_5", &lep_firstEgMotherPdgId_5, &b_lep_firstEgMotherPdgId_5);
   fChain->SetBranchAddress("lep_firstEgMotherTruthType_5", &lep_firstEgMotherTruthType_5, &b_lep_firstEgMotherTruthType_5);
   fChain->SetBranchAddress("lep_firstEgMotherTruthOrigin_5", &lep_firstEgMotherTruthOrigin_5, &b_lep_firstEgMotherTruthOrigin_5);
   fChain->SetBranchAddress("lep_lastEgMotherPdgId_5", &lep_lastEgMotherPdgId_5, &b_lep_lastEgMotherPdgId_5);
   fChain->SetBranchAddress("lep_lastEgMotherTruthType_5", &lep_lastEgMotherTruthType_5, &b_lep_lastEgMotherTruthType_5);
   fChain->SetBranchAddress("lep_lastEgMotherTruthOrigin_5", &lep_lastEgMotherTruthOrigin_5, &b_lep_lastEgMotherTruthOrigin_5);
   fChain->SetBranchAddress("lep_SF_El_Reco_AT_5", &lep_SF_El_Reco_AT_5, &b_lep_SF_El_Reco_AT_5);
   fChain->SetBranchAddress("lep_SF_El_ID_LooseAndBLayerLH_AT_5", &lep_SF_El_ID_LooseAndBLayerLH_AT_5, &b_lep_SF_El_ID_LooseAndBLayerLH_AT_5);
   fChain->SetBranchAddress("lep_SF_El_ID_TightLH_AT_5", &lep_SF_El_ID_TightLH_AT_5, &b_lep_SF_El_ID_TightLH_AT_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_AT_5", &lep_SF_El_Iso_FCLoose_AT_5, &b_lep_SF_El_Iso_FCLoose_AT_5);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_5", &lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_5, &b_lep_SF_El_ChargeMisID_LooseAndBLayerLH_FCLoose_AT_5);
   fChain->SetBranchAddress("lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_5", &lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_5, &b_lep_SF_El_ChargeMisID_TightLH_FCLoose_AT_5);
   fChain->SetBranchAddress("lep_SF_El_FCLooseTightLHQMisID_5", &lep_SF_El_FCLooseTightLHQMisID_5, &b_lep_SF_El_FCLooseTightLHQMisID_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_5", &lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_5, &b_lep_SF_El_Iso_FCLoose_LooseAndBLayerLH_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_FCLoose_TightLH_5", &lep_SF_El_Iso_FCLoose_TightLH_5, &b_lep_SF_El_Iso_FCLoose_TightLH_5);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_QmisID_5", &lep_SF_El_PLVTight_QmisID_5, &b_lep_SF_El_PLVTight_QmisID_5);
   fChain->SetBranchAddress("lep_SF_El_PLVTight_5", &lep_SF_El_PLVTight_5, &b_lep_SF_El_PLVTight_5);
   fChain->SetBranchAddress("lep_SF_El_PLVLoose_5", &lep_SF_El_PLVLoose_5, &b_lep_SF_El_PLVLoose_5);
   fChain->SetBranchAddress("lep_SF_El_ID_MediumLH_5", &lep_SF_El_ID_MediumLH_5, &b_lep_SF_El_ID_MediumLH_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTight_TightLH_5", &lep_SF_El_Iso_PLImprovedTight_TightLH_5, &b_lep_SF_El_Iso_PLImprovedTight_TightLH_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_5", &lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_5, &b_lep_SF_El_Iso_PLImprovedTightECIDS_TightLH_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTight_TightLH_5", &lep_SF_El_Iso_PLImprovedVeryTight_TightLH_5, &b_lep_SF_El_Iso_PLImprovedVeryTight_TightLH_5);
   fChain->SetBranchAddress("lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_5", &lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_5, &b_lep_SF_El_Iso_PLImprovedVeryTightECIDS_TightLH_5);
   fChain->SetBranchAddress("lep_SF_Mu_TTVA_AT_5", &lep_SF_Mu_TTVA_AT_5, &b_lep_SF_Mu_TTVA_AT_5);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Loose_AT_5", &lep_SF_Mu_ID_Loose_AT_5, &b_lep_SF_Mu_ID_Loose_AT_5);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Medium_AT_5", &lep_SF_Mu_ID_Medium_AT_5, &b_lep_SF_Mu_ID_Medium_AT_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_FCLoose_AT_5", &lep_SF_Mu_Iso_FCLoose_AT_5, &b_lep_SF_Mu_Iso_FCLoose_AT_5);
   fChain->SetBranchAddress("lep_SF_Mu_ID_Tight_5", &lep_SF_Mu_ID_Tight_5, &b_lep_SF_Mu_ID_Tight_5);
   fChain->SetBranchAddress("lep_SF_Mu_ID_HighPt_5", &lep_SF_Mu_ID_HighPt_5, &b_lep_SF_Mu_ID_HighPt_5);
   fChain->SetBranchAddress("lep_SF_Mu_PLVTight_5", &lep_SF_Mu_PLVTight_5, &b_lep_SF_Mu_PLVTight_5);
   fChain->SetBranchAddress("lep_SF_Mu_PLVLoose_5", &lep_SF_Mu_PLVLoose_5, &b_lep_SF_Mu_PLVLoose_5);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_MnotT_5", &lep_SF_Mu_PLIV_MnotT_5, &b_lep_SF_Mu_PLIV_MnotT_5);
   fChain->SetBranchAddress("lep_SF_Mu_PLIV_T_5", &lep_SF_Mu_PLIV_T_5, &b_lep_SF_Mu_PLIV_T_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_FixedRad_5", &lep_SF_Mu_Iso_PflowTight_FixedRad_5, &b_lep_SF_Mu_Iso_PflowTight_FixedRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowTight_VarRad_5", &lep_SF_Mu_Iso_PflowTight_VarRad_5, &b_lep_SF_Mu_Iso_PflowTight_VarRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_VarRad_5", &lep_SF_Mu_Iso_PflowLoose_VarRad_5, &b_lep_SF_Mu_Iso_PflowLoose_VarRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_PflowLoose_FixedRad_5", &lep_SF_Mu_Iso_PflowLoose_FixedRad_5, &b_lep_SF_Mu_Iso_PflowLoose_FixedRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_HighPtTrackOnly_5", &lep_SF_Mu_Iso_HighPtTrackOnly_5, &b_lep_SF_Mu_Iso_HighPtTrackOnly_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_FixedRad_5", &lep_SF_Mu_Iso_Tight_FixedRad_5, &b_lep_SF_Mu_Iso_Tight_FixedRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_FixedRad_5", &lep_SF_Mu_Iso_Loose_FixedRad_5, &b_lep_SF_Mu_Iso_Loose_FixedRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Loose_VarRad_5", &lep_SF_Mu_Iso_Loose_VarRad_5, &b_lep_SF_Mu_Iso_Loose_VarRad_5);
   fChain->SetBranchAddress("lep_SF_Mu_Iso_Tight_VarRad_5", &lep_SF_Mu_Iso_Tight_VarRad_5, &b_lep_SF_Mu_Iso_Tight_VarRad_5);
   fChain->SetBranchAddress("lep_SF_CombinedLoose_5", &lep_SF_CombinedLoose_5, &b_lep_SF_CombinedLoose_5);
   fChain->SetBranchAddress("lep_SF_CombinedTight_5", &lep_SF_CombinedTight_5, &b_lep_SF_CombinedTight_5);
   fChain->SetBranchAddress("taus_pt_0", &taus_pt_0, &b_taus_pt_0);
   fChain->SetBranchAddress("taus_eta_0", &taus_eta_0, &b_taus_eta_0);
   fChain->SetBranchAddress("taus_phi_0", &taus_phi_0, &b_taus_phi_0);
   fChain->SetBranchAddress("taus_charge_0", &taus_charge_0, &b_taus_charge_0);
   fChain->SetBranchAddress("taus_E_0", &taus_E_0, &b_taus_E_0);
   fChain->SetBranchAddress("taus_width_0", &taus_width_0, &b_taus_width_0);
   fChain->SetBranchAddress("taus_decayMode_0", &taus_decayMode_0, &b_taus_decayMode_0);
   fChain->SetBranchAddress("taus_BDTJetScore_0", &taus_BDTJetScore_0, &b_taus_BDTJetScore_0);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_0", &taus_BDTJetScoreSigTrans_0, &b_taus_BDTJetScoreSigTrans_0);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_0", &taus_JetBDTSigLoose_0, &b_taus_JetBDTSigLoose_0);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_0", &taus_JetBDTSigMedium_0, &b_taus_JetBDTSigMedium_0);
   fChain->SetBranchAddress("taus_JetBDTSigTight_0", &taus_JetBDTSigTight_0, &b_taus_JetBDTSigTight_0);
   fChain->SetBranchAddress("taus_RNNJetScore_0", &taus_RNNJetScore_0, &b_taus_RNNJetScore_0);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_0", &taus_RNNJetScoreSigTrans_0, &b_taus_RNNJetScoreSigTrans_0);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_0", &taus_JetRNNSigLoose_0, &b_taus_JetRNNSigLoose_0);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_0", &taus_JetRNNSigMedium_0, &b_taus_JetRNNSigMedium_0);
   fChain->SetBranchAddress("taus_JetRNNSigTight_0", &taus_JetRNNSigTight_0, &b_taus_JetRNNSigTight_0);
   fChain->SetBranchAddress("taus_numTrack_0", &taus_numTrack_0, &b_taus_numTrack_0);
   fChain->SetBranchAddress("taus_isHadronic_0", &taus_isHadronic_0, &b_taus_isHadronic_0);
   fChain->SetBranchAddress("taus_tagWeightBin_0", &taus_tagWeightBin_0, &b_taus_tagWeightBin_0);
   fChain->SetBranchAddress("taus_DL1r_0", &taus_DL1r_0, &b_taus_DL1r_0);
   fChain->SetBranchAddress("taus_fromPV_0", &taus_fromPV_0, &b_taus_fromPV_0);
   fChain->SetBranchAddress("taus_passJVT_0", &taus_passJVT_0, &b_taus_passJVT_0);
   fChain->SetBranchAddress("taus_passEleOLR_0", &taus_passEleOLR_0, &b_taus_passEleOLR_0);
   fChain->SetBranchAddress("taus_passEleBDT_0", &taus_passEleBDT_0, &b_taus_passEleBDT_0);
   fChain->SetBranchAddress("taus_passMuonOLR_0", &taus_passMuonOLR_0, &b_taus_passMuonOLR_0);
   fChain->SetBranchAddress("taus_isTruthMatched_0", &taus_isTruthMatched_0, &b_taus_isTruthMatched_0);
   fChain->SetBranchAddress("taus_truthOrigin_0", &taus_truthOrigin_0, &b_taus_truthOrigin_0);
   fChain->SetBranchAddress("taus_truthType_0", &taus_truthType_0, &b_taus_truthType_0);
   fChain->SetBranchAddress("taus_truthJetFlavour_0", &taus_truthJetFlavour_0, &b_taus_truthJetFlavour_0);
   fChain->SetBranchAddress("taus_truthNumCharge_0", &taus_truthNumCharge_0, &b_taus_truthNumCharge_0);
   fChain->SetBranchAddress("taus_truthPt_0", &taus_truthPt_0, &b_taus_truthPt_0);
   fChain->SetBranchAddress("taus_truthPtVis_0", &taus_truthPtVis_0, &b_taus_truthPtVis_0);
   fChain->SetBranchAddress("taus_passtau80L1TAU60_medium1_tracktwo_0", &taus_passtau80L1TAU60_medium1_tracktwo_0, &b_taus_passtau80L1TAU60_medium1_tracktwo_0);
   fChain->SetBranchAddress("taus_passtau125_medium1_tracktwo_0", &taus_passtau125_medium1_tracktwo_0, &b_taus_passtau125_medium1_tracktwo_0);
   fChain->SetBranchAddress("taus_passtau160_medium1_tracktwo_0", &taus_passtau160_medium1_tracktwo_0, &b_taus_passtau160_medium1_tracktwo_0);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwo_0", &taus_passtau160L1TAU100_medium1_tracktwo_0, &b_taus_passtau160L1TAU100_medium1_tracktwo_0);
   fChain->SetBranchAddress("taus_passtau25_medium1_tracktwoEF_0", &taus_passtau25_medium1_tracktwoEF_0, &b_taus_passtau25_medium1_tracktwoEF_0);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwoEF_0", &taus_passtau160L1TAU100_medium1_tracktwoEF_0, &b_taus_passtau160L1TAU100_medium1_tracktwoEF_0);
   fChain->SetBranchAddress("taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_0", &taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_0, &b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_0);
   fChain->SetBranchAddress("taus_pt_1", &taus_pt_1, &b_taus_pt_1);
   fChain->SetBranchAddress("taus_eta_1", &taus_eta_1, &b_taus_eta_1);
   fChain->SetBranchAddress("taus_phi_1", &taus_phi_1, &b_taus_phi_1);
   fChain->SetBranchAddress("taus_charge_1", &taus_charge_1, &b_taus_charge_1);
   fChain->SetBranchAddress("taus_E_1", &taus_E_1, &b_taus_E_1);
   fChain->SetBranchAddress("taus_width_1", &taus_width_1, &b_taus_width_1);
   fChain->SetBranchAddress("taus_decayMode_1", &taus_decayMode_1, &b_taus_decayMode_1);
   fChain->SetBranchAddress("taus_BDTJetScore_1", &taus_BDTJetScore_1, &b_taus_BDTJetScore_1);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_1", &taus_BDTJetScoreSigTrans_1, &b_taus_BDTJetScoreSigTrans_1);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_1", &taus_JetBDTSigLoose_1, &b_taus_JetBDTSigLoose_1);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_1", &taus_JetBDTSigMedium_1, &b_taus_JetBDTSigMedium_1);
   fChain->SetBranchAddress("taus_JetBDTSigTight_1", &taus_JetBDTSigTight_1, &b_taus_JetBDTSigTight_1);
   fChain->SetBranchAddress("taus_RNNJetScore_1", &taus_RNNJetScore_1, &b_taus_RNNJetScore_1);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_1", &taus_RNNJetScoreSigTrans_1, &b_taus_RNNJetScoreSigTrans_1);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_1", &taus_JetRNNSigLoose_1, &b_taus_JetRNNSigLoose_1);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_1", &taus_JetRNNSigMedium_1, &b_taus_JetRNNSigMedium_1);
   fChain->SetBranchAddress("taus_JetRNNSigTight_1", &taus_JetRNNSigTight_1, &b_taus_JetRNNSigTight_1);
   fChain->SetBranchAddress("taus_numTrack_1", &taus_numTrack_1, &b_taus_numTrack_1);
   fChain->SetBranchAddress("taus_isHadronic_1", &taus_isHadronic_1, &b_taus_isHadronic_1);
   fChain->SetBranchAddress("taus_tagWeightBin_1", &taus_tagWeightBin_1, &b_taus_tagWeightBin_1);
   fChain->SetBranchAddress("taus_DL1r_1", &taus_DL1r_1, &b_taus_DL1r_1);
   fChain->SetBranchAddress("taus_fromPV_1", &taus_fromPV_1, &b_taus_fromPV_1);
   fChain->SetBranchAddress("taus_passJVT_1", &taus_passJVT_1, &b_taus_passJVT_1);
   fChain->SetBranchAddress("taus_passEleOLR_1", &taus_passEleOLR_1, &b_taus_passEleOLR_1);
   fChain->SetBranchAddress("taus_passEleBDT_1", &taus_passEleBDT_1, &b_taus_passEleBDT_1);
   fChain->SetBranchAddress("taus_passMuonOLR_1", &taus_passMuonOLR_1, &b_taus_passMuonOLR_1);
   fChain->SetBranchAddress("taus_isTruthMatched_1", &taus_isTruthMatched_1, &b_taus_isTruthMatched_1);
   fChain->SetBranchAddress("taus_truthOrigin_1", &taus_truthOrigin_1, &b_taus_truthOrigin_1);
   fChain->SetBranchAddress("taus_truthType_1", &taus_truthType_1, &b_taus_truthType_1);
   fChain->SetBranchAddress("taus_truthJetFlavour_1", &taus_truthJetFlavour_1, &b_taus_truthJetFlavour_1);
   fChain->SetBranchAddress("taus_truthNumCharge_1", &taus_truthNumCharge_1, &b_taus_truthNumCharge_1);
   fChain->SetBranchAddress("taus_truthPt_1", &taus_truthPt_1, &b_taus_truthPt_1);
   fChain->SetBranchAddress("taus_truthPtVis_1", &taus_truthPtVis_1, &b_taus_truthPtVis_1);
   fChain->SetBranchAddress("taus_passtau80L1TAU60_medium1_tracktwo_1", &taus_passtau80L1TAU60_medium1_tracktwo_1, &b_taus_passtau80L1TAU60_medium1_tracktwo_1);
   fChain->SetBranchAddress("taus_passtau125_medium1_tracktwo_1", &taus_passtau125_medium1_tracktwo_1, &b_taus_passtau125_medium1_tracktwo_1);
   fChain->SetBranchAddress("taus_passtau160_medium1_tracktwo_1", &taus_passtau160_medium1_tracktwo_1, &b_taus_passtau160_medium1_tracktwo_1);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwo_1", &taus_passtau160L1TAU100_medium1_tracktwo_1, &b_taus_passtau160L1TAU100_medium1_tracktwo_1);
   fChain->SetBranchAddress("taus_passtau25_medium1_tracktwoEF_1", &taus_passtau25_medium1_tracktwoEF_1, &b_taus_passtau25_medium1_tracktwoEF_1);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwoEF_1", &taus_passtau160L1TAU100_medium1_tracktwoEF_1, &b_taus_passtau160L1TAU100_medium1_tracktwoEF_1);
   fChain->SetBranchAddress("taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_1", &taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_1, &b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_1);
   fChain->SetBranchAddress("taus_pt_2", &taus_pt_2, &b_taus_pt_2);
   fChain->SetBranchAddress("taus_eta_2", &taus_eta_2, &b_taus_eta_2);
   fChain->SetBranchAddress("taus_phi_2", &taus_phi_2, &b_taus_phi_2);
   fChain->SetBranchAddress("taus_charge_2", &taus_charge_2, &b_taus_charge_2);
   fChain->SetBranchAddress("taus_E_2", &taus_E_2, &b_taus_E_2);
   fChain->SetBranchAddress("taus_width_2", &taus_width_2, &b_taus_width_2);
   fChain->SetBranchAddress("taus_decayMode_2", &taus_decayMode_2, &b_taus_decayMode_2);
   fChain->SetBranchAddress("taus_BDTJetScore_2", &taus_BDTJetScore_2, &b_taus_BDTJetScore_2);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_2", &taus_BDTJetScoreSigTrans_2, &b_taus_BDTJetScoreSigTrans_2);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_2", &taus_JetBDTSigLoose_2, &b_taus_JetBDTSigLoose_2);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_2", &taus_JetBDTSigMedium_2, &b_taus_JetBDTSigMedium_2);
   fChain->SetBranchAddress("taus_JetBDTSigTight_2", &taus_JetBDTSigTight_2, &b_taus_JetBDTSigTight_2);
   fChain->SetBranchAddress("taus_RNNJetScore_2", &taus_RNNJetScore_2, &b_taus_RNNJetScore_2);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_2", &taus_RNNJetScoreSigTrans_2, &b_taus_RNNJetScoreSigTrans_2);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_2", &taus_JetRNNSigLoose_2, &b_taus_JetRNNSigLoose_2);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_2", &taus_JetRNNSigMedium_2, &b_taus_JetRNNSigMedium_2);
   fChain->SetBranchAddress("taus_JetRNNSigTight_2", &taus_JetRNNSigTight_2, &b_taus_JetRNNSigTight_2);
   fChain->SetBranchAddress("taus_numTrack_2", &taus_numTrack_2, &b_taus_numTrack_2);
   fChain->SetBranchAddress("taus_isHadronic_2", &taus_isHadronic_2, &b_taus_isHadronic_2);
   fChain->SetBranchAddress("taus_tagWeightBin_2", &taus_tagWeightBin_2, &b_taus_tagWeightBin_2);
   fChain->SetBranchAddress("taus_DL1r_2", &taus_DL1r_2, &b_taus_DL1r_2);
   fChain->SetBranchAddress("taus_fromPV_2", &taus_fromPV_2, &b_taus_fromPV_2);
   fChain->SetBranchAddress("taus_passJVT_2", &taus_passJVT_2, &b_taus_passJVT_2);
   fChain->SetBranchAddress("taus_passEleOLR_2", &taus_passEleOLR_2, &b_taus_passEleOLR_2);
   fChain->SetBranchAddress("taus_passEleBDT_2", &taus_passEleBDT_2, &b_taus_passEleBDT_2);
   fChain->SetBranchAddress("taus_passMuonOLR_2", &taus_passMuonOLR_2, &b_taus_passMuonOLR_2);
   fChain->SetBranchAddress("taus_isTruthMatched_2", &taus_isTruthMatched_2, &b_taus_isTruthMatched_2);
   fChain->SetBranchAddress("taus_truthOrigin_2", &taus_truthOrigin_2, &b_taus_truthOrigin_2);
   fChain->SetBranchAddress("taus_truthType_2", &taus_truthType_2, &b_taus_truthType_2);
   fChain->SetBranchAddress("taus_truthJetFlavour_2", &taus_truthJetFlavour_2, &b_taus_truthJetFlavour_2);
   fChain->SetBranchAddress("taus_truthNumCharge_2", &taus_truthNumCharge_2, &b_taus_truthNumCharge_2);
   fChain->SetBranchAddress("taus_truthPt_2", &taus_truthPt_2, &b_taus_truthPt_2);
   fChain->SetBranchAddress("taus_truthPtVis_2", &taus_truthPtVis_2, &b_taus_truthPtVis_2);
   fChain->SetBranchAddress("taus_passtau80L1TAU60_medium1_tracktwo_2", &taus_passtau80L1TAU60_medium1_tracktwo_2, &b_taus_passtau80L1TAU60_medium1_tracktwo_2);
   fChain->SetBranchAddress("taus_passtau125_medium1_tracktwo_2", &taus_passtau125_medium1_tracktwo_2, &b_taus_passtau125_medium1_tracktwo_2);
   fChain->SetBranchAddress("taus_passtau160_medium1_tracktwo_2", &taus_passtau160_medium1_tracktwo_2, &b_taus_passtau160_medium1_tracktwo_2);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwo_2", &taus_passtau160L1TAU100_medium1_tracktwo_2, &b_taus_passtau160L1TAU100_medium1_tracktwo_2);
   fChain->SetBranchAddress("taus_passtau25_medium1_tracktwoEF_2", &taus_passtau25_medium1_tracktwoEF_2, &b_taus_passtau25_medium1_tracktwoEF_2);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwoEF_2", &taus_passtau160L1TAU100_medium1_tracktwoEF_2, &b_taus_passtau160L1TAU100_medium1_tracktwoEF_2);
   fChain->SetBranchAddress("taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_2", &taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_2, &b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_2);
   fChain->SetBranchAddress("taus_pt_3", &taus_pt_3, &b_taus_pt_3);
   fChain->SetBranchAddress("taus_eta_3", &taus_eta_3, &b_taus_eta_3);
   fChain->SetBranchAddress("taus_phi_3", &taus_phi_3, &b_taus_phi_3);
   fChain->SetBranchAddress("taus_charge_3", &taus_charge_3, &b_taus_charge_3);
   fChain->SetBranchAddress("taus_E_3", &taus_E_3, &b_taus_E_3);
   fChain->SetBranchAddress("taus_width_3", &taus_width_3, &b_taus_width_3);
   fChain->SetBranchAddress("taus_decayMode_3", &taus_decayMode_3, &b_taus_decayMode_3);
   fChain->SetBranchAddress("taus_BDTJetScore_3", &taus_BDTJetScore_3, &b_taus_BDTJetScore_3);
   fChain->SetBranchAddress("taus_BDTJetScoreSigTrans_3", &taus_BDTJetScoreSigTrans_3, &b_taus_BDTJetScoreSigTrans_3);
   fChain->SetBranchAddress("taus_JetBDTSigLoose_3", &taus_JetBDTSigLoose_3, &b_taus_JetBDTSigLoose_3);
   fChain->SetBranchAddress("taus_JetBDTSigMedium_3", &taus_JetBDTSigMedium_3, &b_taus_JetBDTSigMedium_3);
   fChain->SetBranchAddress("taus_JetBDTSigTight_3", &taus_JetBDTSigTight_3, &b_taus_JetBDTSigTight_3);
   fChain->SetBranchAddress("taus_RNNJetScore_3", &taus_RNNJetScore_3, &b_taus_RNNJetScore_3);
   fChain->SetBranchAddress("taus_RNNJetScoreSigTrans_3", &taus_RNNJetScoreSigTrans_3, &b_taus_RNNJetScoreSigTrans_3);
   fChain->SetBranchAddress("taus_JetRNNSigLoose_3", &taus_JetRNNSigLoose_3, &b_taus_JetRNNSigLoose_3);
   fChain->SetBranchAddress("taus_JetRNNSigMedium_3", &taus_JetRNNSigMedium_3, &b_taus_JetRNNSigMedium_3);
   fChain->SetBranchAddress("taus_JetRNNSigTight_3", &taus_JetRNNSigTight_3, &b_taus_JetRNNSigTight_3);
   fChain->SetBranchAddress("taus_numTrack_3", &taus_numTrack_3, &b_taus_numTrack_3);
   fChain->SetBranchAddress("taus_isHadronic_3", &taus_isHadronic_3, &b_taus_isHadronic_3);
   fChain->SetBranchAddress("taus_tagWeightBin_3", &taus_tagWeightBin_3, &b_taus_tagWeightBin_3);
   fChain->SetBranchAddress("taus_DL1r_3", &taus_DL1r_3, &b_taus_DL1r_3);
   fChain->SetBranchAddress("taus_fromPV_3", &taus_fromPV_3, &b_taus_fromPV_3);
   fChain->SetBranchAddress("taus_passJVT_3", &taus_passJVT_3, &b_taus_passJVT_3);
   fChain->SetBranchAddress("taus_passEleOLR_3", &taus_passEleOLR_3, &b_taus_passEleOLR_3);
   fChain->SetBranchAddress("taus_passEleBDT_3", &taus_passEleBDT_3, &b_taus_passEleBDT_3);
   fChain->SetBranchAddress("taus_passMuonOLR_3", &taus_passMuonOLR_3, &b_taus_passMuonOLR_3);
   fChain->SetBranchAddress("taus_isTruthMatched_3", &taus_isTruthMatched_3, &b_taus_isTruthMatched_3);
   fChain->SetBranchAddress("taus_truthOrigin_3", &taus_truthOrigin_3, &b_taus_truthOrigin_3);
   fChain->SetBranchAddress("taus_truthType_3", &taus_truthType_3, &b_taus_truthType_3);
   fChain->SetBranchAddress("taus_truthJetFlavour_3", &taus_truthJetFlavour_3, &b_taus_truthJetFlavour_3);
   fChain->SetBranchAddress("taus_truthNumCharge_3", &taus_truthNumCharge_3, &b_taus_truthNumCharge_3);
   fChain->SetBranchAddress("taus_truthPt_3", &taus_truthPt_3, &b_taus_truthPt_3);
   fChain->SetBranchAddress("taus_truthPtVis_3", &taus_truthPtVis_3, &b_taus_truthPtVis_3);
   fChain->SetBranchAddress("taus_passtau80L1TAU60_medium1_tracktwo_3", &taus_passtau80L1TAU60_medium1_tracktwo_3, &b_taus_passtau80L1TAU60_medium1_tracktwo_3);
   fChain->SetBranchAddress("taus_passtau125_medium1_tracktwo_3", &taus_passtau125_medium1_tracktwo_3, &b_taus_passtau125_medium1_tracktwo_3);
   fChain->SetBranchAddress("taus_passtau160_medium1_tracktwo_3", &taus_passtau160_medium1_tracktwo_3, &b_taus_passtau160_medium1_tracktwo_3);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwo_3", &taus_passtau160L1TAU100_medium1_tracktwo_3, &b_taus_passtau160L1TAU100_medium1_tracktwo_3);
   fChain->SetBranchAddress("taus_passtau25_medium1_tracktwoEF_3", &taus_passtau25_medium1_tracktwoEF_3, &b_taus_passtau25_medium1_tracktwoEF_3);
   fChain->SetBranchAddress("taus_passtau160L1TAU100_medium1_tracktwoEF_3", &taus_passtau160L1TAU100_medium1_tracktwoEF_3, &b_taus_passtau160L1TAU100_medium1_tracktwoEF_3);
   fChain->SetBranchAddress("taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_3", &taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_3, &b_taus_passtau160_mediumRNN_tracktwoMVA_L1TAU100_3);
   fChain->SetBranchAddress("jets_pt", &jets_pt, &b_jets_pt);
   fChain->SetBranchAddress("jets_e", &jets_e, &b_jets_e);
   fChain->SetBranchAddress("jets_eta", &jets_eta, &b_jets_eta);
   fChain->SetBranchAddress("jets_phi", &jets_phi, &b_jets_phi);
   fChain->SetBranchAddress("jets_score_DL1r", &jets_score_DL1r, &b_jets_score_DL1r);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_ContinuousBin", &jets_btagFlag_DL1r_ContinuousBin, &b_jets_btagFlag_DL1r_ContinuousBin);
   fChain->SetBranchAddress("jets_score_DL1r_pu", &jets_score_DL1r_pu, &b_jets_score_DL1r_pu);
   fChain->SetBranchAddress("jets_score_DL1r_pc", &jets_score_DL1r_pc, &b_jets_score_DL1r_pc);
   fChain->SetBranchAddress("jets_score_DL1r_pb", &jets_score_DL1r_pb, &b_jets_score_DL1r_pb);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_60", &jets_btagFlag_DL1r_FixedCutBEff_60, &b_jets_btagFlag_DL1r_FixedCutBEff_60);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_70", &jets_btagFlag_DL1r_FixedCutBEff_70, &b_jets_btagFlag_DL1r_FixedCutBEff_70);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_77", &jets_btagFlag_DL1r_FixedCutBEff_77, &b_jets_btagFlag_DL1r_FixedCutBEff_77);
   fChain->SetBranchAddress("jets_btagFlag_DL1r_FixedCutBEff_85", &jets_btagFlag_DL1r_FixedCutBEff_85, &b_jets_btagFlag_DL1r_FixedCutBEff_85);
   fChain->SetBranchAddress("jets_btag_JetVertexCharge_discriminant", &jets_btag_JetVertexCharge_discriminant, &b_jets_btag_JetVertexCharge_discriminant);
   fChain->SetBranchAddress("jets_ConeTruthLabelID", &jets_ConeTruthLabelID, &b_jets_ConeTruthLabelID);
   fChain->SetBranchAddress("jets_PartonTruthLabelID", &jets_PartonTruthLabelID, &b_jets_PartonTruthLabelID);
   fChain->SetBranchAddress("jets_isQuarkJet", &jets_isQuarkJet, &b_jets_isQuarkJet);
   fChain->SetBranchAddress("jets_isQuarkJetBDT", &jets_isQuarkJetBDT, &b_jets_isQuarkJetBDT);
   fChain->SetBranchAddress("jets_HadronConeExclExtendedTruthLabelID", &jets_HadronConeExclExtendedTruthLabelID, &b_jets_HadronConeExclExtendedTruthLabelID);
   fChain->SetBranchAddress("jets_HadronConeExclTruthLabelID", &jets_HadronConeExclTruthLabelID, &b_jets_HadronConeExclTruthLabelID);
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
   fChain->SetBranchAddress("custTrigSF_CombinedWPs_SLTorDLT", &custTrigSF_CombinedWPs_SLTorDLT, &b_custTrigSF_CombinedWPs_SLTorDLT);
   fChain->SetBranchAddress("custTrigSF_CombinedWPs_SLT", &custTrigSF_CombinedWPs_SLT, &b_custTrigSF_CombinedWPs_SLT);
   fChain->SetBranchAddress("custTrigSF_CombinedWPs_DLT", &custTrigSF_CombinedWPs_DLT, &b_custTrigSF_CombinedWPs_DLT);
   fChain->SetBranchAddress("custTrigMatch_CombinedWPs_SLTorDLT", &custTrigMatch_CombinedWPs_SLTorDLT, &b_custTrigMatch_CombinedWPs_SLTorDLT);
   fChain->SetBranchAddress("custTrigMatch_CombinedWPs_SLT", &custTrigMatch_CombinedWPs_SLT, &b_custTrigMatch_CombinedWPs_SLT);
   fChain->SetBranchAddress("custTrigMatch_CombinedWPs_DLT", &custTrigMatch_CombinedWPs_DLT, &b_custTrigMatch_CombinedWPs_DLT);
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
   fChain->SetBranchAddress("highpt_trubjet", &highpt_trubjet, &b_highpt_trubjet);
   fChain->SetBranchAddress("mvis_taub", &mvis_taub, &b_mvis_taub);
   fChain->SetBranchAddress("lqlq_decays", &lqlq_decays, &b_lqlq_decays);
   fChain->SetBranchAddress("VLL_type", &VLL_type, &b_VLL_type);
   fChain->SetBranchAddress("VLL_decaytype", &VLL_decaytype, &b_VLL_decaytype);
   fChain->SetBranchAddress("VLL_decayZdecays", &VLL_decayZdecays, &b_VLL_decayZdecays);
   fChain->SetBranchAddress("VLL_decayWdecays", &VLL_decayWdecays, &b_VLL_decayWdecays);
   fChain->SetBranchAddress("VLL_decayHdecays", &VLL_decayHdecays, &b_VLL_decayHdecays);
   fChain->SetBranchAddress("m_HF_Classification", &m_HF_Classification, &b_m_HF_Classification);
   fChain->SetBranchAddress("m_HF_ClassificationTop", &m_HF_ClassificationTop, &b_m_HF_ClassificationTop);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("lepSFObjChannelCombined", &lepSFObjChannelCombined, &b_lepSFObjChannelCombined);
   fChain->SetBranchAddress("jvtSF_customOR", &jvtSF_customOR, &b_jvtSF_customOR);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_60", &bTagSF_weight_DL1r_60, &b_bTagSF_weight_DL1r_60);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_70", &bTagSF_weight_DL1r_70, &b_bTagSF_weight_DL1r_70);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_77", &bTagSF_weight_DL1r_77, &b_bTagSF_weight_DL1r_77);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_85", &bTagSF_weight_DL1r_85, &b_bTagSF_weight_DL1r_85);
   fChain->SetBranchAddress("bTagSF_weight_DL1r_Continuous", &bTagSF_weight_DL1r_Continuous, &b_bTagSF_weight_DL1r_Continuous);
   //Notify();
}

#endif // #ifdef VLLf_cxx

   
   
