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
#include "TTreeReader.h"
#include "TTreeReaderArray.h"

using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.


class AtlMin {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

//ttree reader
   vector< TTreeReaderArray<Float_t> > freaders;

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *mc_generator_weights;
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_globalLeptonTriggerSF;
   Float_t         weight_oldTriggerSF;
   Float_t         weight_bTagSF_MV2c10_77;
   Float_t         weight_bTagSF_DL1r_77;
   Float_t         weight_jvt;
   Float_t         weight_pileup_UP;
   Float_t         weight_pileup_DOWN;
   Float_t         weight_leptonSF_EL_SF_Trigger_UP;
   Float_t         weight_leptonSF_EL_SF_Trigger_DOWN;
   Float_t         weight_leptonSF_EL_SF_Reco_UP;
   Float_t         weight_leptonSF_EL_SF_Reco_DOWN;
   Float_t         weight_leptonSF_EL_SF_ID_UP;
   Float_t         weight_leptonSF_EL_SF_ID_DOWN;
   Float_t         weight_leptonSF_EL_SF_Isol_UP;
   Float_t         weight_leptonSF_EL_SF_Isol_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
   Float_t         weight_globalLeptonTriggerSF_EL_Trigger_UP;
   Float_t         weight_globalLeptonTriggerSF_EL_Trigger_DOWN;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN;
   Float_t         weight_oldTriggerSF_EL_Trigger_UP;
   Float_t         weight_oldTriggerSF_EL_Trigger_DOWN;
   Float_t         weight_oldTriggerSF_MU_Trigger_STAT_UP;
   Float_t         weight_oldTriggerSF_MU_Trigger_STAT_DOWN;
   Float_t         weight_oldTriggerSF_MU_Trigger_SYST_UP;
   Float_t         weight_oldTriggerSF_MU_Trigger_SYST_DOWN;
   Float_t         weight_indiv_SF_EL_Reco;
   Float_t         weight_indiv_SF_EL_Reco_UP;
   Float_t         weight_indiv_SF_EL_Reco_DOWN;
   Float_t         weight_indiv_SF_EL_ID;
   Float_t         weight_indiv_SF_EL_ID_UP;
   Float_t         weight_indiv_SF_EL_ID_DOWN;
   Float_t         weight_indiv_SF_EL_Isol;
   Float_t         weight_indiv_SF_EL_Isol_UP;
   Float_t         weight_indiv_SF_EL_Isol_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeID;
   Float_t         weight_indiv_SF_EL_ChargeID_UP;
   Float_t         weight_indiv_SF_EL_ChargeID_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeMisID;
   Float_t         weight_indiv_SF_EL_ChargeMisID_STAT_UP;
   Float_t         weight_indiv_SF_EL_ChargeMisID_STAT_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeMisID_SYST_UP;
   Float_t         weight_indiv_SF_EL_ChargeMisID_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_ID;
   Float_t         weight_indiv_SF_MU_ID_STAT_UP;
   Float_t         weight_indiv_SF_MU_ID_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_ID_SYST_UP;
   Float_t         weight_indiv_SF_MU_ID_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_ID_STAT_LOWPT_UP;
   Float_t         weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN;
   Float_t         weight_indiv_SF_MU_ID_SYST_LOWPT_UP;
   Float_t         weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN;
   Float_t         weight_indiv_SF_MU_Isol;
   Float_t         weight_indiv_SF_MU_Isol_STAT_UP;
   Float_t         weight_indiv_SF_MU_Isol_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_Isol_SYST_UP;
   Float_t         weight_indiv_SF_MU_Isol_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_TTVA;
   Float_t         weight_indiv_SF_MU_TTVA_STAT_UP;
   Float_t         weight_indiv_SF_MU_TTVA_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_TTVA_SYST_UP;
   Float_t         weight_indiv_SF_MU_TTVA_SYST_DOWN;
   Float_t         weight_jvt_UP;
   Float_t         weight_jvt_DOWN;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_B_up;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_C_up;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_Light_up;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_B_down;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_C_down;
   vector<float>   *weight_bTagSF_MV2c10_77_eigenvars_Light_down;
   Float_t         weight_bTagSF_MV2c10_77_extrapolation_up;
   Float_t         weight_bTagSF_MV2c10_77_extrapolation_down;
   Float_t         weight_bTagSF_MV2c10_77_extrapolation_from_charm_up;
   Float_t         weight_bTagSF_MV2c10_77_extrapolation_from_charm_down;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   Float_t         mu_actual;
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
   vector<int>     *el_true_firstEgMotherTruthType;
   vector<int>     *el_true_firstEgMotherTruthOrigin;
   vector<int>     *el_true_firstEgMotherPdgId;
   vector<char>    *el_true_isPrompt;
   vector<char>    *el_true_isChargeFl;

   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_e;
   vector<float>   *mu_charge;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<float>   *jet_jvt;
   vector<float>   *jet_truthflav;
   vector<char>    *jet_isbtagged_DL1r_77;

   vector<float>   *rcjet_pt;
   vector<float>   *rcjet_eta;
   vector<float>   *rcjet_phi;
   vector<float>   *rcjet_e;
   vector<float>   *rcjet_d12;
   vector<float>   *rcjet_d23;
   vector<vector<float> > *rcjetsub_pt;
   vector<vector<float> > *rcjetsub_eta;
   vector<vector<float> > *rcjetsub_phi;
   vector<vector<float> > *rcjetsub_e;
   vector<vector<float> > *rcjetsub_mv2c10;
   vector<float>   *vrcjet_2m_t_pt;
   vector<float>   *vrcjet_2m_t_eta;
   vector<float>   *vrcjet_2m_t_phi;
   vector<float>   *vrcjet_2m_t_e;
   vector<float>   *vrcjet_2m_t_d12;
   vector<float>   *vrcjet_2m_t_d23;
   vector<vector<float> > *vrcjetsub_2m_t_pt;
   vector<vector<float> > *vrcjetsub_2m_t_eta;
   vector<vector<float> > *vrcjetsub_2m_t_phi;
   vector<vector<float> > *vrcjetsub_2m_t_e;
   vector<vector<float> > *vrcjetsub_2m_t_mv2c10;
   vector<float>   *vrrcjet_2m_t_pt;
   vector<float>   *vrrcjet_2m_t_eta;
   vector<float>   *vrrcjet_2m_t_phi;
   vector<float>   *vrrcjet_2m_t_e;
   vector<float>   *vrcjet_2m_t_tau32_clstr;
   vector<float>   *vrcjet_2m_t_tau21_clstr;
   vector<float>   *vrcjet_2m_t_tau3_clstr;
   vector<float>   *vrcjet_2m_t_tau2_clstr;
   vector<float>   *vrcjet_2m_t_tau1_clstr;
   vector<float>   *vrcjet_2m_t_d12_clstr;
   vector<float>   *vrcjet_2m_t_d23_clstr;
   vector<float>   *vrcjet_2m_t_Qw_clstr;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           ee;
   Int_t           mumu;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium_nod0;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium;
   vector<char>    *el_trigMatch_HLT_e120_lhloose;
   vector<char>    *el_trigMatch_HLT_e24_lhmedium_L1EM20VH;
   vector<char>    *el_trigMatch_HLT_e140_lhloose_nod0;
   vector<char>    *el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;
   vector<char>    *mu_trigMatch_HLT_mu50;
   vector<char>    *mu_trigMatch_HLT_mu26_ivarmedium;
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

   // List of branches
   TBranch        *b_mc_generator_weights;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_globalLeptonTriggerSF;   //!
   TBranch        *b_weight_oldTriggerSF;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77;   //!
   TBranch        *b_weight_bTagSF_DL1r_77;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_weight_pileup_UP;   //!
   TBranch        *b_weight_pileup_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Trigger_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Reco_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Reco_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_ID_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_ID_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Isol_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Isol_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_Trigger_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_Trigger_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_EL_Trigger_UP;   //!
   TBranch        *b_weight_oldTriggerSF_EL_Trigger_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_STAT_UP;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_SYST_UP;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ID;   //!
   TBranch        *b_weight_indiv_SF_EL_ID_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ID_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_SYST_DOWN;   //!
   TBranch        *b_weight_jvt_UP;   //!
   TBranch        *b_weight_jvt_DOWN;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_B_up;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_C_up;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_Light_up;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_B_down;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_C_down;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_eigenvars_Light_down;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_extrapolation_up;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_extrapolation_down;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_extrapolation_from_charm_up;   //!
   TBranch        *b_weight_bTagSF_MV2c10_77_extrapolation_from_charm_down;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_mu_actual;   //!
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
   TBranch        *b_el_true_firstEgMotherTruthType;   //!
   TBranch        *b_el_true_firstEgMotherTruthOrigin;   //!
   TBranch        *b_el_true_firstEgMotherPdgId;   //!
   TBranch        *b_el_true_isPrompt;   //!
   TBranch        *b_el_true_isChargeFl;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_isbtagged_DL1r_77;   //!
   TBranch        *b_jet_truthflav;   //!

   TBranch        *b_jet_mv2c00;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_mv2c20;   //!
   TBranch        *b_jet_ip3dsv1;   //!
   TBranch        *b_jet_passfjvt;   //!
   TBranch        *b_jet_truthPartonLabel;   //!
   TBranch        *b_jet_isTrueHS;   //!
   TBranch        *b_jet_truthflavExtended;   //!
   TBranch        *b_jet_MV2r;   //!
   TBranch        *b_jet_MV2rmu;   //!
   TBranch        *b_jet_DL1;   //!
   TBranch        *b_jet_DL1r;   //!
   TBranch        *b_jet_DL1rmu;   //!
   TBranch        *b_jet_MV2cl100;   //!
   TBranch        *b_jet_MV2c100;   //!
   TBranch        *b_jet_DL1_pu;   //!
   TBranch        *b_jet_DL1_pc;   //!
   TBranch        *b_jet_DL1_pb;   //!
   TBranch        *b_jet_DL1r_pu;   //!
   TBranch        *b_jet_DL1r_pc;   //!
   TBranch        *b_jet_DL1r_pb;   //!
   TBranch        *b_jet_DL1rmu_pu;   //!
   TBranch        *b_jet_DL1rmu_pc;   //!
   TBranch        *b_jet_DL1rmu_pb;   //!
   TBranch        *b_rcjet_pt;   //!
   TBranch        *b_rcjet_eta;   //!
   TBranch        *b_rcjet_phi;   //!
   TBranch        *b_rcjet_e;   //!
   TBranch        *b_rcjet_d12;   //!
   TBranch        *b_rcjet_d23;   //!
   TBranch        *b_rcjetsub_pt;   //!
   TBranch        *b_rcjetsub_eta;   //!
   TBranch        *b_rcjetsub_phi;   //!
   TBranch        *b_rcjetsub_e;   //!
   TBranch        *b_rcjetsub_mv2c10;   //!
   TBranch        *b_vrcjet_2m_t_pt;   //!
   TBranch        *b_vrcjet_2m_t_eta;   //!
   TBranch        *b_vrcjet_2m_t_phi;   //!
   TBranch        *b_vrcjet_2m_t_e;   //!
   TBranch        *b_vrcjet_2m_t_d12;   //!
   TBranch        *b_vrcjet_2m_t_d23;   //!
   TBranch        *b_vrcjetsub_2m_t_pt;   //!
   TBranch        *b_vrcjetsub_2m_t_eta;   //!
   TBranch        *b_vrcjetsub_2m_t_phi;   //!
   TBranch        *b_vrcjetsub_2m_t_e;   //!
   TBranch        *b_vrcjetsub_2m_t_mv2c10;   //!
   TBranch        *b_vrrcjet_2m_t_pt;   //!
   TBranch        *b_vrrcjet_2m_t_eta;   //!
   TBranch        *b_vrrcjet_2m_t_phi;   //!
   TBranch        *b_vrrcjet_2m_t_e;   //!
   TBranch        *b_vrcjet_2m_t_tau32_clstr;   //!
   TBranch        *b_vrcjet_2m_t_tau21_clstr;   //!
   TBranch        *b_vrcjet_2m_t_tau3_clstr;   //!
   TBranch        *b_vrcjet_2m_t_tau2_clstr;   //!
   TBranch        *b_vrcjet_2m_t_tau1_clstr;   //!
   TBranch        *b_vrcjet_2m_t_d12_clstr;   //!
   TBranch        *b_vrcjet_2m_t_d23_clstr;   //!
   TBranch        *b_vrcjet_2m_t_Qw_clstr;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_ee;   //!
   TBranch        *b_mumu;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium;   //!
   TBranch        *b_el_trigMatch_HLT_e120_lhloose;   //!
   TBranch        *b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_el_trigMatch_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_mu_trigMatch_HLT_mu50;   //!
   TBranch        *b_mu_trigMatch_HLT_mu26_ivarmedium;   //!
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
AtlMin::AtlMin( char *file_name, TChain *tree, int year) : fChain(0)
{
    TChain* chain;
    if (tree == 0) {
        chain = new TChain("nominal"); 
        chain->Add(file_name);
    }
    if (tree == 0) {
        Init(chain, year);
    } else {
        Init(tree, year);
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
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_generator_weights = 0;
   weight_bTagSF_MV2c10_77_eigenvars_B_up = 0;
   weight_bTagSF_MV2c10_77_eigenvars_C_up = 0;
   weight_bTagSF_MV2c10_77_eigenvars_Light_up = 0;
   weight_bTagSF_MV2c10_77_eigenvars_B_down = 0;
   weight_bTagSF_MV2c10_77_eigenvars_C_down = 0;
   weight_bTagSF_MV2c10_77_eigenvars_Light_down = 0;
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
   el_true_firstEgMotherTruthType = 0;
   el_true_firstEgMotherTruthOrigin = 0;
   el_true_firstEgMotherPdgId = 0;
   el_true_isPrompt = 0;
   el_true_isChargeFl = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_e = 0;
   mu_charge = 0;

   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_jvt = 0;
   jet_truthflav = 0;
   jet_isbtagged_DL1r_77 = 0;

   rcjet_pt = 0;
   rcjet_eta = 0;
   rcjet_phi = 0;
   rcjet_e = 0;
   rcjet_d12 = 0;
   rcjet_d23 = 0;
   rcjetsub_pt = 0;
   rcjetsub_eta = 0;
   rcjetsub_phi = 0;
   rcjetsub_e = 0;
   rcjetsub_mv2c10 = 0;
   vrcjet_2m_t_pt = 0;
   vrcjet_2m_t_eta = 0;
   vrcjet_2m_t_phi = 0;
   vrcjet_2m_t_e = 0;
   vrcjet_2m_t_d12 = 0;
   vrcjet_2m_t_d23 = 0;
   vrcjetsub_2m_t_pt = 0;
   vrcjetsub_2m_t_eta = 0;
   vrcjetsub_2m_t_phi = 0;
   vrcjetsub_2m_t_e = 0;
   vrcjetsub_2m_t_mv2c10 = 0;
   vrrcjet_2m_t_pt = 0;
   vrrcjet_2m_t_eta = 0;
   vrrcjet_2m_t_phi = 0;
   vrrcjet_2m_t_e = 0;
   vrcjet_2m_t_tau32_clstr = 0;
   vrcjet_2m_t_tau21_clstr = 0;
   vrcjet_2m_t_tau3_clstr = 0;
   vrcjet_2m_t_tau2_clstr = 0;
   vrcjet_2m_t_tau1_clstr = 0;
   vrcjet_2m_t_d12_clstr = 0;
   vrcjet_2m_t_d23_clstr = 0;
   vrcjet_2m_t_Qw_clstr = 0;
   el_trigMatch_HLT_e60_lhmedium_nod0 = 0;
   el_trigMatch_HLT_e60_lhmedium = 0;
   el_trigMatch_HLT_e120_lhloose = 0;
   el_trigMatch_HLT_e24_lhmedium_L1EM20VH = 0;
   el_trigMatch_HLT_e140_lhloose_nod0 = 0;
   el_trigMatch_HLT_e26_lhtight_nod0_ivarloose = 0;
   mu_trigMatch_HLT_mu50 = 0;
   mu_trigMatch_HLT_mu26_ivarmedium = 0;
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
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mc_generator_weights", &mc_generator_weights, &b_mc_generator_weights);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF", &weight_globalLeptonTriggerSF, &b_weight_globalLeptonTriggerSF);
   fChain->SetBranchAddress("weight_oldTriggerSF", &weight_oldTriggerSF, &b_weight_oldTriggerSF);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77", &weight_bTagSF_MV2c10_77, &b_weight_bTagSF_MV2c10_77);
   fChain->SetBranchAddress("weight_bTagSF_DL1r_77", &weight_bTagSF_DL1r_77, &b_weight_bTagSF_DL1r_77);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_pileup_UP", &weight_pileup_UP, &b_weight_pileup_UP);
   fChain->SetBranchAddress("weight_pileup_DOWN", &weight_pileup_DOWN, &b_weight_pileup_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Trigger_UP", &weight_leptonSF_EL_SF_Trigger_UP, &b_weight_leptonSF_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Trigger_DOWN", &weight_leptonSF_EL_SF_Trigger_DOWN, &b_weight_leptonSF_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Reco_UP", &weight_leptonSF_EL_SF_Reco_UP, &b_weight_leptonSF_EL_SF_Reco_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Reco_DOWN", &weight_leptonSF_EL_SF_Reco_DOWN, &b_weight_leptonSF_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_ID_UP", &weight_leptonSF_EL_SF_ID_UP, &b_weight_leptonSF_EL_SF_ID_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_ID_DOWN", &weight_leptonSF_EL_SF_ID_DOWN, &b_weight_leptonSF_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Isol_UP", &weight_leptonSF_EL_SF_Isol_UP, &b_weight_leptonSF_EL_SF_Isol_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Isol_DOWN", &weight_leptonSF_EL_SF_Isol_DOWN, &b_weight_leptonSF_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_STAT_UP", &weight_leptonSF_MU_SF_Trigger_STAT_UP, &b_weight_leptonSF_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_STAT_DOWN", &weight_leptonSF_MU_SF_Trigger_STAT_DOWN, &b_weight_leptonSF_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_SYST_UP", &weight_leptonSF_MU_SF_Trigger_SYST_UP, &b_weight_leptonSF_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_SYST_DOWN", &weight_leptonSF_MU_SF_Trigger_SYST_DOWN, &b_weight_leptonSF_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_UP", &weight_leptonSF_MU_SF_ID_STAT_UP, &b_weight_leptonSF_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_DOWN", &weight_leptonSF_MU_SF_ID_STAT_DOWN, &b_weight_leptonSF_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_UP", &weight_leptonSF_MU_SF_ID_SYST_UP, &b_weight_leptonSF_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_DOWN", &weight_leptonSF_MU_SF_ID_SYST_DOWN, &b_weight_leptonSF_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP", &weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP, &b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN", &weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN, &b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP", &weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP, &b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN", &weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN, &b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_STAT_UP", &weight_leptonSF_MU_SF_Isol_STAT_UP, &b_weight_leptonSF_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_STAT_DOWN", &weight_leptonSF_MU_SF_Isol_STAT_DOWN, &b_weight_leptonSF_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_SYST_UP", &weight_leptonSF_MU_SF_Isol_SYST_UP, &b_weight_leptonSF_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_SYST_DOWN", &weight_leptonSF_MU_SF_Isol_SYST_DOWN, &b_weight_leptonSF_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_STAT_UP", &weight_leptonSF_MU_SF_TTVA_STAT_UP, &b_weight_leptonSF_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_STAT_DOWN", &weight_leptonSF_MU_SF_TTVA_STAT_DOWN, &b_weight_leptonSF_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_SYST_UP", &weight_leptonSF_MU_SF_TTVA_SYST_UP, &b_weight_leptonSF_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_SYST_DOWN", &weight_leptonSF_MU_SF_TTVA_SYST_DOWN, &b_weight_leptonSF_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_Trigger_UP", &weight_globalLeptonTriggerSF_EL_Trigger_UP, &b_weight_globalLeptonTriggerSF_EL_Trigger_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_Trigger_DOWN", &weight_globalLeptonTriggerSF_EL_Trigger_DOWN, &b_weight_globalLeptonTriggerSF_EL_Trigger_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP", &weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP, &b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN", &weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN, &b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP", &weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP, &b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN", &weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN, &b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_EL_Trigger_UP", &weight_oldTriggerSF_EL_Trigger_UP, &b_weight_oldTriggerSF_EL_Trigger_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_EL_Trigger_DOWN", &weight_oldTriggerSF_EL_Trigger_DOWN, &b_weight_oldTriggerSF_EL_Trigger_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_STAT_UP", &weight_oldTriggerSF_MU_Trigger_STAT_UP, &b_weight_oldTriggerSF_MU_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_STAT_DOWN", &weight_oldTriggerSF_MU_Trigger_STAT_DOWN, &b_weight_oldTriggerSF_MU_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_SYST_UP", &weight_oldTriggerSF_MU_Trigger_SYST_UP, &b_weight_oldTriggerSF_MU_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_SYST_DOWN", &weight_oldTriggerSF_MU_Trigger_SYST_DOWN, &b_weight_oldTriggerSF_MU_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco", &weight_indiv_SF_EL_Reco, &b_weight_indiv_SF_EL_Reco);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco_UP", &weight_indiv_SF_EL_Reco_UP, &b_weight_indiv_SF_EL_Reco_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco_DOWN", &weight_indiv_SF_EL_Reco_DOWN, &b_weight_indiv_SF_EL_Reco_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID", &weight_indiv_SF_EL_ID, &b_weight_indiv_SF_EL_ID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID_UP", &weight_indiv_SF_EL_ID_UP, &b_weight_indiv_SF_EL_ID_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID_DOWN", &weight_indiv_SF_EL_ID_DOWN, &b_weight_indiv_SF_EL_ID_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol", &weight_indiv_SF_EL_Isol, &b_weight_indiv_SF_EL_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol_UP", &weight_indiv_SF_EL_Isol_UP, &b_weight_indiv_SF_EL_Isol_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol_DOWN", &weight_indiv_SF_EL_Isol_DOWN, &b_weight_indiv_SF_EL_Isol_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID", &weight_indiv_SF_EL_ChargeID, &b_weight_indiv_SF_EL_ChargeID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID_UP", &weight_indiv_SF_EL_ChargeID_UP, &b_weight_indiv_SF_EL_ChargeID_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID_DOWN", &weight_indiv_SF_EL_ChargeID_DOWN, &b_weight_indiv_SF_EL_ChargeID_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID", &weight_indiv_SF_EL_ChargeMisID, &b_weight_indiv_SF_EL_ChargeMisID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_STAT_UP", &weight_indiv_SF_EL_ChargeMisID_STAT_UP, &b_weight_indiv_SF_EL_ChargeMisID_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_STAT_DOWN", &weight_indiv_SF_EL_ChargeMisID_STAT_DOWN, &b_weight_indiv_SF_EL_ChargeMisID_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_SYST_UP", &weight_indiv_SF_EL_ChargeMisID_SYST_UP, &b_weight_indiv_SF_EL_ChargeMisID_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_SYST_DOWN", &weight_indiv_SF_EL_ChargeMisID_SYST_DOWN, &b_weight_indiv_SF_EL_ChargeMisID_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID", &weight_indiv_SF_MU_ID, &b_weight_indiv_SF_MU_ID);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_UP", &weight_indiv_SF_MU_ID_STAT_UP, &b_weight_indiv_SF_MU_ID_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_DOWN", &weight_indiv_SF_MU_ID_STAT_DOWN, &b_weight_indiv_SF_MU_ID_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_UP", &weight_indiv_SF_MU_ID_SYST_UP, &b_weight_indiv_SF_MU_ID_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_DOWN", &weight_indiv_SF_MU_ID_SYST_DOWN, &b_weight_indiv_SF_MU_ID_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_LOWPT_UP", &weight_indiv_SF_MU_ID_STAT_LOWPT_UP, &b_weight_indiv_SF_MU_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN", &weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN, &b_weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_LOWPT_UP", &weight_indiv_SF_MU_ID_SYST_LOWPT_UP, &b_weight_indiv_SF_MU_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN", &weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN, &b_weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol", &weight_indiv_SF_MU_Isol, &b_weight_indiv_SF_MU_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_STAT_UP", &weight_indiv_SF_MU_Isol_STAT_UP, &b_weight_indiv_SF_MU_Isol_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_STAT_DOWN", &weight_indiv_SF_MU_Isol_STAT_DOWN, &b_weight_indiv_SF_MU_Isol_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_SYST_UP", &weight_indiv_SF_MU_Isol_SYST_UP, &b_weight_indiv_SF_MU_Isol_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_SYST_DOWN", &weight_indiv_SF_MU_Isol_SYST_DOWN, &b_weight_indiv_SF_MU_Isol_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA", &weight_indiv_SF_MU_TTVA, &b_weight_indiv_SF_MU_TTVA);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_STAT_UP", &weight_indiv_SF_MU_TTVA_STAT_UP, &b_weight_indiv_SF_MU_TTVA_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_STAT_DOWN", &weight_indiv_SF_MU_TTVA_STAT_DOWN, &b_weight_indiv_SF_MU_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_SYST_UP", &weight_indiv_SF_MU_TTVA_SYST_UP, &b_weight_indiv_SF_MU_TTVA_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_SYST_DOWN", &weight_indiv_SF_MU_TTVA_SYST_DOWN, &b_weight_indiv_SF_MU_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("weight_jvt_UP", &weight_jvt_UP, &b_weight_jvt_UP);
   fChain->SetBranchAddress("weight_jvt_DOWN", &weight_jvt_DOWN, &b_weight_jvt_DOWN);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_B_up", &weight_bTagSF_MV2c10_77_eigenvars_B_up, &b_weight_bTagSF_MV2c10_77_eigenvars_B_up);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_C_up", &weight_bTagSF_MV2c10_77_eigenvars_C_up, &b_weight_bTagSF_MV2c10_77_eigenvars_C_up);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_Light_up", &weight_bTagSF_MV2c10_77_eigenvars_Light_up, &b_weight_bTagSF_MV2c10_77_eigenvars_Light_up);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_B_down", &weight_bTagSF_MV2c10_77_eigenvars_B_down, &b_weight_bTagSF_MV2c10_77_eigenvars_B_down);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_C_down", &weight_bTagSF_MV2c10_77_eigenvars_C_down, &b_weight_bTagSF_MV2c10_77_eigenvars_C_down);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_eigenvars_Light_down", &weight_bTagSF_MV2c10_77_eigenvars_Light_down, &b_weight_bTagSF_MV2c10_77_eigenvars_Light_down);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_extrapolation_up", &weight_bTagSF_MV2c10_77_extrapolation_up, &b_weight_bTagSF_MV2c10_77_extrapolation_up);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_extrapolation_down", &weight_bTagSF_MV2c10_77_extrapolation_down, &b_weight_bTagSF_MV2c10_77_extrapolation_down);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_extrapolation_from_charm_up", &weight_bTagSF_MV2c10_77_extrapolation_from_charm_up, &b_weight_bTagSF_MV2c10_77_extrapolation_from_charm_up);
   fChain->SetBranchAddress("weight_bTagSF_MV2c10_77_extrapolation_from_charm_down", &weight_bTagSF_MV2c10_77_extrapolation_from_charm_down, &b_weight_bTagSF_MV2c10_77_extrapolation_from_charm_down);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("mu_actual", &mu_actual, &b_mu_actual);
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
   fChain->SetBranchAddress("el_true_firstEgMotherTruthType", &el_true_firstEgMotherTruthType, &b_el_true_firstEgMotherTruthType);
   fChain->SetBranchAddress("el_true_firstEgMotherTruthOrigin", &el_true_firstEgMotherTruthOrigin, &b_el_true_firstEgMotherTruthOrigin);
   fChain->SetBranchAddress("el_true_firstEgMotherPdgId", &el_true_firstEgMotherPdgId, &b_el_true_firstEgMotherPdgId);
   fChain->SetBranchAddress("el_true_isPrompt", &el_true_isPrompt, &b_el_true_isPrompt);
   fChain->SetBranchAddress("el_true_isChargeFl", &el_true_isChargeFl, &b_el_true_isChargeFl);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("jet_isbtagged_DL1r_77", &jet_isbtagged_DL1r_77, &b_jet_isbtagged_DL1r_77);

   fChain->SetBranchAddress("rcjet_pt", &rcjet_pt, &b_rcjet_pt);
   fChain->SetBranchAddress("rcjet_eta", &rcjet_eta, &b_rcjet_eta);
   fChain->SetBranchAddress("rcjet_phi", &rcjet_phi, &b_rcjet_phi);
   fChain->SetBranchAddress("rcjet_e", &rcjet_e, &b_rcjet_e);
   fChain->SetBranchAddress("rcjet_d12", &rcjet_d12, &b_rcjet_d12);
   fChain->SetBranchAddress("rcjet_d23", &rcjet_d23, &b_rcjet_d23);
   fChain->SetBranchAddress("rcjetsub_pt", &rcjetsub_pt, &b_rcjetsub_pt);
   fChain->SetBranchAddress("rcjetsub_eta", &rcjetsub_eta, &b_rcjetsub_eta);
   fChain->SetBranchAddress("rcjetsub_phi", &rcjetsub_phi, &b_rcjetsub_phi);
   fChain->SetBranchAddress("rcjetsub_e", &rcjetsub_e, &b_rcjetsub_e);
   fChain->SetBranchAddress("rcjetsub_mv2c10", &rcjetsub_mv2c10, &b_rcjetsub_mv2c10);
   fChain->SetBranchAddress("vrcjet_2m_t_pt", &vrcjet_2m_t_pt, &b_vrcjet_2m_t_pt);
   fChain->SetBranchAddress("vrcjet_2m_t_eta", &vrcjet_2m_t_eta, &b_vrcjet_2m_t_eta);
   fChain->SetBranchAddress("vrcjet_2m_t_phi", &vrcjet_2m_t_phi, &b_vrcjet_2m_t_phi);
   fChain->SetBranchAddress("vrcjet_2m_t_e", &vrcjet_2m_t_e, &b_vrcjet_2m_t_e);
   fChain->SetBranchAddress("vrcjet_2m_t_d12", &vrcjet_2m_t_d12, &b_vrcjet_2m_t_d12);
   fChain->SetBranchAddress("vrcjet_2m_t_d23", &vrcjet_2m_t_d23, &b_vrcjet_2m_t_d23);
   fChain->SetBranchAddress("vrcjetsub_2m_t_pt", &vrcjetsub_2m_t_pt, &b_vrcjetsub_2m_t_pt);
   fChain->SetBranchAddress("vrcjetsub_2m_t_eta", &vrcjetsub_2m_t_eta, &b_vrcjetsub_2m_t_eta);
   fChain->SetBranchAddress("vrcjetsub_2m_t_phi", &vrcjetsub_2m_t_phi, &b_vrcjetsub_2m_t_phi);
   fChain->SetBranchAddress("vrcjetsub_2m_t_e", &vrcjetsub_2m_t_e, &b_vrcjetsub_2m_t_e);
   fChain->SetBranchAddress("vrcjetsub_2m_t_mv2c10", &vrcjetsub_2m_t_mv2c10, &b_vrcjetsub_2m_t_mv2c10);
   fChain->SetBranchAddress("vrrcjet_2m_t_pt", &vrrcjet_2m_t_pt, &b_vrrcjet_2m_t_pt);
   fChain->SetBranchAddress("vrrcjet_2m_t_eta", &vrrcjet_2m_t_eta, &b_vrrcjet_2m_t_eta);
   fChain->SetBranchAddress("vrrcjet_2m_t_phi", &vrrcjet_2m_t_phi, &b_vrrcjet_2m_t_phi);
   fChain->SetBranchAddress("vrrcjet_2m_t_e", &vrrcjet_2m_t_e, &b_vrrcjet_2m_t_e);
   fChain->SetBranchAddress("vrcjet_2m_t_tau32_clstr", &vrcjet_2m_t_tau32_clstr, &b_vrcjet_2m_t_tau32_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_tau21_clstr", &vrcjet_2m_t_tau21_clstr, &b_vrcjet_2m_t_tau21_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_tau3_clstr", &vrcjet_2m_t_tau3_clstr, &b_vrcjet_2m_t_tau3_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_tau2_clstr", &vrcjet_2m_t_tau2_clstr, &b_vrcjet_2m_t_tau2_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_tau1_clstr", &vrcjet_2m_t_tau1_clstr, &b_vrcjet_2m_t_tau1_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_d12_clstr", &vrcjet_2m_t_d12_clstr, &b_vrcjet_2m_t_d12_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_d23_clstr", &vrcjet_2m_t_d23_clstr, &b_vrcjet_2m_t_d23_clstr);
   fChain->SetBranchAddress("vrcjet_2m_t_Qw_clstr", &vrcjet_2m_t_Qw_clstr, &b_vrcjet_2m_t_Qw_clstr);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("ee", &ee, &b_ee);
   fChain->SetBranchAddress("mumu", &mumu, &b_mumu);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium_nod0", &el_trigMatch_HLT_e60_lhmedium_nod0, &b_el_trigMatch_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium", &el_trigMatch_HLT_e60_lhmedium, &b_el_trigMatch_HLT_e60_lhmedium);
   fChain->SetBranchAddress("el_trigMatch_HLT_e120_lhloose", &el_trigMatch_HLT_e120_lhloose, &b_el_trigMatch_HLT_e120_lhloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e24_lhmedium_L1EM20VH", &el_trigMatch_HLT_e24_lhmedium_L1EM20VH, &b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("el_trigMatch_HLT_e140_lhloose_nod0", &el_trigMatch_HLT_e140_lhloose_nod0, &b_el_trigMatch_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e26_lhtight_nod0_ivarloose", &el_trigMatch_HLT_e26_lhtight_nod0_ivarloose, &b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu50", &mu_trigMatch_HLT_mu50, &b_mu_trigMatch_HLT_mu50);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu26_ivarmedium", &mu_trigMatch_HLT_mu26_ivarmedium, &b_mu_trigMatch_HLT_mu26_ivarmedium);
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
