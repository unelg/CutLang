//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr  2 21:53:28 2019 by ROOT version 5.34/36
// from TTree nominal/nominal
// found on file: SeeSaw_multilep_MC_M300.root
//////////////////////////////////////////////////////////

#ifndef VLLMin_h
#define VLLMin_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

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
#include "string"
/*
// Header file for the classes stored in the TTree if any.
#include "/Volumes/MacintoshHD2/build/electric_commander/build/workspace/root-release-5.34/BUILDTYPE/Release/COMPILER/native/LABEL/mac1011/sources/root_v5.34.36/root/cint/cint/lib/prec_stl/string"
#include "/Volumes/MacintoshHD2/build/electric_commander/build/workspace/root-release-5.34/BUILDTYPE/Release/COMPILER/native/LABEL/mac1011/sources/root_v5.34.36/root/cint/cint/lib/prec_stl/vector"
#include "/Volumes/MacintoshHD2/build/electric_commander/build/workspace/root-release-5.34/BUILDTYPE/Release/COMPILER/native/LABEL/mac1011/sources/root_v5.34.36/root/cint/cint/lib/prec_stl/vector"
#include "/Volumes/MacintoshHD2/build/electric_commander/build/workspace/root-release-5.34/BUILDTYPE/Release/COMPILER/native/LABEL/mac1011/sources/root_v5.34.36/root/cint/cint/lib/prec_stl/vector"
*/

using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.

class VLLMin {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runNumber;
   Long64_t        eventNumber;
   Int_t           lumiBlock;
   UInt_t          coreFlags;
   Int_t           bcid;
   Int_t           mcEventNumber;
   Int_t           mcChannelNumber;
   Float_t         mcEventWeight;
   Int_t           NPV;
   Float_t         actualInteractionsPerCrossing;
   Float_t         averageInteractionsPerCrossing;
   Float_t         weight_pileup;
   Float_t         correctedAverageMu;
   Float_t         correctedAndScaledAverageMu;
   Float_t         correctedActualMu;
   Float_t         correctedAndScaledActualMu;
   Int_t           rand_run_nr;
   Int_t           rand_lumiblock_nr;
   Char_t          isMC;
   Double_t        crossSection;
  // multimap<string,pair<unsigned int,unsigned int> > *trigMatchMapDilep;
  // multimap<string,tuple<unsigned int,unsigned int,unsigned int> > *trigMatchMapTrilep;
   string          *decayType;
   vector<float>   *JvtEff_SF;
   vector<float>   *FTagEff_SF_MV2c10_FixedCutBEff_70;
   vector<float>   *FTagEff_SF_MV2c10_FixedCutBEff_77;
   vector<float>   *FTagEff_SF_MV2c10_FixedCutBEff_85;
   vector<float>   *FTagEff_SF_MV2c10_HybBEff_70;
   vector<float>   *FTagEff_SF_MV2c10_HybBEff_77;
   vector<float>   *FTagEff_SF_MV2c10_HybBEff_85;
   vector<string>  *passedTriggers;
   vector<string>  *disabledTriggers;
   Int_t           nmuon;
   vector<float>   *muon_m;
   vector<float>   *muon_pt;
   vector<float>   *muon_phi;
   vector<float>   *muon_eta;
   vector<float>   *muon_charge;
   vector<int>     *muon_isTrigMatched;
   vector<vector<int> > *muon_isTrigMatchedToChain;
   vector<string>  *muon_listTrigChains;
   vector<int>     *muon_isIsolated_FCTight_FixedRad;
   vector<int>     *muon_isIsolated_FixedCutHighPtTrackOnly;
   vector<int>     *muon_isIsolated_FCLoose_FixedRad;
   vector<int>     *muon_isIsolated_FCTightTrackOnly_FixedRad;
   vector<vector<float> > *muon_RecoEff_SF_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu8noL1_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu8noL1_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu18_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu18_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu10_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu10_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu14_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu14_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu22_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu22_RecoTight;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_RecoTight;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_RecoTight;
   vector<vector<float> > *muon_RecoEff_SF_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu8noL1_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu8noL1_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu18_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu18_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu10_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu10_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu14_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu14_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu22_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu22_RecoMedium;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_RecoMedium;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_RecoMedium;
   vector<vector<float> > *muon_RecoEff_SF_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu8noL1_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu18_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu18_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu10_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu10_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu14_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu14_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu22_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu22_RecoHighPt;
   vector<vector<float> > *muon_TrigEff_SF_HLT_mu20_RecoHighPt;
   vector<vector<float> > *muon_TrigMCEff_HLT_mu20_RecoHighPt;
   vector<vector<float> > *muon_IsoEff_SF_IsoFCTight_FixedRad;
   vector<vector<float> > *muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly;
   vector<vector<float> > *muon_IsoEff_SF_IsoFCLoose_FixedRad;
   vector<vector<float> > *muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad;
   vector<vector<float> > *muon_TTVAEff_SF;
   vector<int>     *muon_isTight;
   vector<int>     *muon_isMedium;
   vector<int>     *muon_isHighPt;
   vector<int>     *muon_truthClassification;
   vector<int>     *muon_truthType;
   vector<int>     *muon_truthOrigin;
   vector<int>     *muon_truthSignal;
   Int_t           nel;
   vector<float>   *el_m;
   vector<float>   *el_pt;
   vector<float>   *el_phi;
   vector<float>   *el_eta;
   vector<float>   *el_caloCluster_eta;
   vector<float>   *el_charge;
   vector<int>     *el_isTrigMatched;
   vector<vector<int> > *el_isTrigMatchedToChain;
   vector<string>  *el_listTrigChains;
   vector<int>     *el_isIsolated_FCTight;
   vector<int>     *el_isIsolated_FCHighPtCaloOnly;
   vector<int>     *el_isIsolated_FCLoose;
   vector<int>     *el_isIsolated_Gradient;
   vector<int>     *el_LHLooseBL;
   vector<int>     *el_LHTight;
   vector<int>     *el_LHMedium;
   vector<vector<float> > *el_PIDEff_SF_Tight;
   vector<vector<float> > *el_IsoEff_SF_Tight_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;
   vector<vector<float> > *el_ChflipEff_SF_Tight_isolFCTight;
   vector<vector<float> > *el_IsoEff_SF_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;
   vector<vector<float> > *el_ChflipEff_SF_Tight;
   vector<vector<float> > *el_IsoEff_SF_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;
   vector<vector<float> > *el_ChflipEff_SF_Tight_isolFCLoose;
   vector<vector<float> > *el_IsoEff_SF_Tight_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;
   vector<vector<float> > *el_ChflipEff_SF_Tight_isolGradient;
   vector<vector<float> > *el_PIDEff_SF_Medium;
   vector<vector<float> > *el_IsoEff_SF_Medium_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;
   vector<vector<float> > *el_ChflipEff_SF_Medium_isolFCTight;
   vector<vector<float> > *el_IsoEff_SF_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;
   vector<vector<float> > *el_ChflipEff_SF_Medium;
   vector<vector<float> > *el_IsoEff_SF_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;
   vector<vector<float> > *el_ChflipEff_SF_Medium_isolFCLoose;
   vector<vector<float> > *el_IsoEff_SF_Medium_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient;
   vector<vector<float> > *el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;
   vector<vector<float> > *el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;
   vector<vector<float> > *el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;
   vector<vector<float> > *el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;
   vector<vector<float> > *el_ChflipEff_SF_Medium_isolGradient;
   vector<vector<float> > *el_RecoEff_SF;
   vector<int>     *el_truthClassification;
   vector<int>     *el_truthType;
   vector<int>     *el_truthOrigin;
   vector<int>     *el_truthSignal;
   vector<int>     *el_firstEgMotherTruthType;
   vector<int>     *el_firstEgMotherTruthOrigin;
   vector<int>     *el_firstEgMotherPdgId;
   Int_t           njet;
   vector<float>   *jet_E;
   vector<float>   *jet_pt;
   vector<float>   *jet_phi;
   vector<float>   *jet_eta;
   vector<int>     *jet_is_MV2c10_FixedCutBEff_77;
   vector<int>     *jet_is_MV2c10_FixedCutBEff_85;
   vector<int>     *jet_is_MV2c10_FixedCutBEff_70;
   vector<int>     *jet_is_MV2c10_HybBEff_77;
   vector<int>     *jet_is_MV2c10_HybBEff_85;
   vector<int>     *jet_is_MV2c10_HybBEff_70;
   Int_t           ntau;
   vector<float>   *tau_m;
   vector<float>   *tau_pt;
   vector<float>   *tau_phi;
   vector<float>   *tau_eta;
   vector<int>     *tau_isTrigMatched;
   vector<vector<int> > *tau_isTrigMatchedToChain;
   vector<string>  *tau_listTrigChains;
   vector<int>     *tau_ntrk;
   vector<float>   *tau_charge;
   vector<int>     *tau_isJetBDTSigVeryLoose;
   vector<int>     *tau_isJetBDTSigLoose;
   vector<int>     *tau_isJetBDTSigMedium;
   vector<int>     *tau_isJetBDTSigTight;
   vector<float>   *tau_JetBDTScore;
   vector<float>   *tau_JetBDTScoreSigTrans;
   vector<int>     *tau_isEleBDTLoose;
   vector<int>     *tau_isEleBDTMedium;
   vector<int>     *tau_isEleBDTTight;
   vector<float>   *tau_EleBDTScore;
   vector<int>     *tau_passEleOLR;
   vector<float>   *tau_seedJetWidth;
   vector<float>   *tau_seedJetJvt;
   vector<int>     *tau_truthClassification;
   vector<int>     *tau_isTruthMatched;
   vector<int>     *tau_isTrueHadronicTau;
   vector<int>     *tau_truthPdgId;
   vector<int>     *tau_truthOrigin;
   vector<int>     *tau_truthType;
   vector<int>     *tau_truthSignal;
   vector<int>     *tau_truthStatus;
   vector<int>     *tau_PartonTruthLabelID;
   Float_t         metFinalTrk;
   Float_t         metFinalTrkPx;
   Float_t         metFinalTrkPy;
   Float_t         metFinalTrkSumEt;
   Float_t         metFinalTrkPhi;
   Float_t         metFinalTrkOverSqrtSumEt;
   Float_t         metFinalTrkOverSqrtHt;
   Float_t         metFinalTrkSignificance;
   Float_t         metFinalTrkSigDirectional;
   Float_t         metSoftTrk;
   Float_t         metSoftTrkSumEt;
   Float_t         metSoftTrkPhi;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_coreFlags;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_mcEventNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mcEventWeight;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_actualInteractionsPerCrossing;   //!
   TBranch        *b_averageInteractionsPerCrossing;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_correctedAverageMu;   //!
   TBranch        *b_correctedAndScaledAverageMu;   //!
   TBranch        *b_correctedActualMu;   //!
   TBranch        *b_correctedAndScaledActualMu;   //!
   TBranch        *b_rand_run_nr;   //!
   TBranch        *b_rand_lumiblock_nr;   //!
   TBranch        *b_isMC;   //!
   TBranch        *b_crossSection;   //!
   TBranch        *b_trigMatchMapDilep;   //!
   TBranch        *b_trigMatchMapTrilep;   //!
   TBranch        *b_decayType;   //!
   TBranch        *b_JvtEff_SF;   //!
   TBranch        *b_FTagEff_SF_MV2c10_FixedCutBEff_70;   //!
   TBranch        *b_FTagEff_SF_MV2c10_FixedCutBEff_77;   //!
   TBranch        *b_FTagEff_SF_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_FTagEff_SF_MV2c10_HybBEff_70;   //!
   TBranch        *b_FTagEff_SF_MV2c10_HybBEff_77;   //!
   TBranch        *b_FTagEff_SF_MV2c10_HybBEff_85;   //!
   TBranch        *b_passedTriggers;   //!
   TBranch        *b_disabledTriggers;   //!
   TBranch        *b_nmuon;   //!
   TBranch        *b_muon_m;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_muon_phi;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_charge;   //!
   TBranch        *b_muon_isTrigMatched;   //!
   TBranch        *b_muon_isTrigMatchedToChain;   //!
   TBranch        *b_muon_listTrigChains;   //!
   TBranch        *b_muon_isIsolated_FCTight_FixedRad;   //!
   TBranch        *b_muon_isIsolated_FixedCutHighPtTrackOnly;   //!
   TBranch        *b_muon_isIsolated_FCLoose_FixedRad;   //!
   TBranch        *b_muon_isIsolated_FCTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_RecoEff_SF_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu8noL1_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu8noL1_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu18_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu18_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu10_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu10_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu14_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu14_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu22_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu22_RecoTight;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_RecoTight;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_RecoTight;   //!
   TBranch        *b_muon_RecoEff_SF_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu8noL1_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu8noL1_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu18_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu18_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu10_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu10_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu14_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu14_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu22_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu22_RecoMedium;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_RecoMedium;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_RecoMedium;   //!
   TBranch        *b_muon_RecoEff_SF_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu8noL1_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu18_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu18_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu10_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu10_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu14_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu14_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu22_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu22_RecoHighPt;   //!
   TBranch        *b_muon_TrigEff_SF_HLT_mu20_RecoHighPt;   //!
   TBranch        *b_muon_TrigMCEff_HLT_mu20_RecoHighPt;   //!
   TBranch        *b_muon_IsoEff_SF_IsoFCTight_FixedRad;   //!
   TBranch        *b_muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly;   //!
   TBranch        *b_muon_IsoEff_SF_IsoFCLoose_FixedRad;   //!
   TBranch        *b_muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad;   //!
   TBranch        *b_muon_TTVAEff_SF;   //!
   TBranch        *b_muon_isTight;   //!
   TBranch        *b_muon_isMedium;   //!
   TBranch        *b_muon_isHighPt;   //!
   TBranch        *b_muon_truthClassification;   //!
   TBranch        *b_muon_truthType;   //!
   TBranch        *b_muon_truthOrigin;   //!
   TBranch        *b_muon_truthSignal;   //!
   TBranch        *b_nel;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_caloCluster_eta;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_isTrigMatched;   //!
   TBranch        *b_el_isTrigMatchedToChain;   //!
   TBranch        *b_el_listTrigChains;   //!
   TBranch        *b_el_isIsolated_FCTight;   //!
   TBranch        *b_el_isIsolated_FCHighPtCaloOnly;   //!
   TBranch        *b_el_isIsolated_FCLoose;   //!
   TBranch        *b_el_isIsolated_Gradient;   //!
   TBranch        *b_el_LHLooseBL;   //!
   TBranch        *b_el_LHTight;   //!
   TBranch        *b_el_LHMedium;   //!
   TBranch        *b_el_PIDEff_SF_Tight;   //!
   TBranch        *b_el_IsoEff_SF_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight;   //!
   TBranch        *b_el_ChflipEff_SF_Tight_isolFCTight;   //!
   TBranch        *b_el_IsoEff_SF_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight;   //!
   TBranch        *b_el_ChflipEff_SF_Tight;   //!
   TBranch        *b_el_IsoEff_SF_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose;   //!
   TBranch        *b_el_ChflipEff_SF_Tight_isolFCLoose;   //!
   TBranch        *b_el_IsoEff_SF_Tight_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient;   //!
   TBranch        *b_el_ChflipEff_SF_Tight_isolGradient;   //!
   TBranch        *b_el_PIDEff_SF_Medium;   //!
   TBranch        *b_el_IsoEff_SF_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight;   //!
   TBranch        *b_el_ChflipEff_SF_Medium_isolFCTight;   //!
   TBranch        *b_el_IsoEff_SF_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium;   //!
   TBranch        *b_el_ChflipEff_SF_Medium;   //!
   TBranch        *b_el_IsoEff_SF_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose;   //!
   TBranch        *b_el_ChflipEff_SF_Medium_isolFCLoose;   //!
   TBranch        *b_el_IsoEff_SF_Medium_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;   //!
   TBranch        *b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;   //!
   TBranch        *b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient;   //!
   TBranch        *b_el_ChflipEff_SF_Medium_isolGradient;   //!
   TBranch        *b_el_RecoEff_SF;   //!
   TBranch        *b_el_truthClassification;   //!
   TBranch        *b_el_truthType;   //!
   TBranch        *b_el_truthOrigin;   //!
   TBranch        *b_el_truthSignal;   //!
   TBranch        *b_el_firstEgMotherTruthType;   //!
   TBranch        *b_el_firstEgMotherTruthOrigin;   //!
   TBranch        *b_el_firstEgMotherPdgId;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_is_MV2c10_FixedCutBEff_77;   //!
   TBranch        *b_jet_is_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_jet_is_MV2c10_FixedCutBEff_70;   //!
   TBranch        *b_jet_is_MV2c10_HybBEff_77;   //!
   TBranch        *b_jet_is_MV2c10_HybBEff_85;   //!
   TBranch        *b_jet_is_MV2c10_HybBEff_70;   //!
   TBranch        *b_ntau;   //!
   TBranch        *b_tau_m;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_isTrigMatched;   //!
   TBranch        *b_tau_isTrigMatchedToChain;   //!
   TBranch        *b_tau_listTrigChains;   //!
   TBranch        *b_tau_ntrk;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_tau_isJetBDTSigVeryLoose;   //!
   TBranch        *b_tau_isJetBDTSigLoose;   //!
   TBranch        *b_tau_isJetBDTSigMedium;   //!
   TBranch        *b_tau_isJetBDTSigTight;   //!
   TBranch        *b_tau_JetBDTScore;   //!
   TBranch        *b_tau_JetBDTScoreSigTrans;   //!
   TBranch        *b_tau_isEleBDTLoose;   //!
   TBranch        *b_tau_isEleBDTMedium;   //!
   TBranch        *b_tau_isEleBDTTight;   //!
   TBranch        *b_tau_EleBDTScore;   //!
   TBranch        *b_tau_passEleOLR;   //!
   TBranch        *b_tau_seedJetWidth;   //!
   TBranch        *b_tau_seedJetJvt;   //!
   TBranch        *b_tau_truthClassification;   //!
   TBranch        *b_tau_isTruthMatched;   //!
   TBranch        *b_tau_isTrueHadronicTau;   //!
   TBranch        *b_tau_truthPdgId;   //!
   TBranch        *b_tau_truthOrigin;   //!
   TBranch        *b_tau_truthType;   //!
   TBranch        *b_tau_truthSignal;   //!
   TBranch        *b_tau_truthStatus;   //!
   TBranch        *b_tau_PartonTruthLabelID;   //!
   TBranch        *b_metFinalTrk;   //!
   TBranch        *b_metFinalTrkPx;   //!
   TBranch        *b_metFinalTrkPy;   //!
   TBranch        *b_metFinalTrkSumEt;   //!
   TBranch        *b_metFinalTrkPhi;   //!
   TBranch        *b_metFinalTrkOverSqrtSumEt;   //!
   TBranch        *b_metFinalTrkOverSqrtHt;   //!
   TBranch        *b_metFinalTrkSignificance;   //!
   TBranch        *b_metFinalTrkSigDirectional;   //!
   TBranch        *b_metSoftTrk;   //!
   TBranch        *b_metSoftTrkSumEt;   //!
   TBranch        *b_metSoftTrkPhi;   //!

   VLLMin(char *file_name, TChain *tree=0, int year=2012);
   virtual ~VLLMin();
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

#ifdef VLLMin_cxx
VLLMin::VLLMin( char *file_name, TChain *tree, int year) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

    TChain* chain;
    if (tree == 0) {
        chain = new TChain("/physics/nominal");
        chain->Add(file_name);
    }
    if (tree == 0) {
        Init(chain, year);
    } else {
        Init(tree, year);
    }
}

VLLMin::~VLLMin()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLMin::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLMin::LoadTree(Long64_t entry)
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

void VLLMin::Init(TTree *tree, int year)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
//   trigMatchMapDilep = 0;
//   trigMatchMapTrilep = 0;
   decayType = 0;
   JvtEff_SF = 0;
   FTagEff_SF_MV2c10_FixedCutBEff_70 = 0;
   FTagEff_SF_MV2c10_FixedCutBEff_77 = 0;
   FTagEff_SF_MV2c10_FixedCutBEff_85 = 0;
   FTagEff_SF_MV2c10_HybBEff_70 = 0;
   FTagEff_SF_MV2c10_HybBEff_77 = 0;
   FTagEff_SF_MV2c10_HybBEff_85 = 0;
   passedTriggers = 0;
   disabledTriggers = 0;
   muon_m = 0;
   muon_pt = 0;
   muon_phi = 0;
   muon_eta = 0;
   muon_charge = 0;
   muon_isTrigMatched = 0;
   muon_isTrigMatchedToChain = 0;
   muon_listTrigChains = 0;
   muon_isIsolated_FCTight_FixedRad = 0;
   muon_isIsolated_FixedCutHighPtTrackOnly = 0;
   muon_isIsolated_FCLoose_FixedRad = 0;
   muon_isIsolated_FCTightTrackOnly_FixedRad = 0;
   muon_RecoEff_SF_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu8noL1_RecoTight = 0;
   muon_TrigMCEff_HLT_mu8noL1_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu18_RecoTight = 0;
   muon_TrigMCEff_HLT_mu18_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight = 0;
   muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight = 0;
   muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu10_RecoTight = 0;
   muon_TrigMCEff_HLT_mu10_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu14_RecoTight = 0;
   muon_TrigMCEff_HLT_mu14_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu22_RecoTight = 0;
   muon_TrigMCEff_HLT_mu22_RecoTight = 0;
   muon_TrigEff_SF_HLT_mu20_RecoTight = 0;
   muon_TrigMCEff_HLT_mu20_RecoTight = 0;
   muon_RecoEff_SF_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu8noL1_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu8noL1_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu18_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu18_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu10_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu10_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu14_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu14_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu22_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu22_RecoMedium = 0;
   muon_TrigEff_SF_HLT_mu20_RecoMedium = 0;
   muon_TrigMCEff_HLT_mu20_RecoMedium = 0;
   muon_RecoEff_SF_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu8noL1_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu18_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu18_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu10_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu10_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu14_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu14_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu22_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu22_RecoHighPt = 0;
   muon_TrigEff_SF_HLT_mu20_RecoHighPt = 0;
   muon_TrigMCEff_HLT_mu20_RecoHighPt = 0;
   muon_IsoEff_SF_IsoFCTight_FixedRad = 0;
   muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly = 0;
   muon_IsoEff_SF_IsoFCLoose_FixedRad = 0;
   muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad = 0;
   muon_TTVAEff_SF = 0;
   muon_isTight = 0;
   muon_isMedium = 0;
   muon_isHighPt = 0;
   muon_truthClassification = 0;
   muon_truthType = 0;
   muon_truthOrigin = 0;
   muon_truthSignal = 0;
   el_m = 0;
   el_pt = 0;
   el_phi = 0;
   el_eta = 0;
   el_caloCluster_eta = 0;
   el_charge = 0;
   el_isTrigMatched = 0;
   el_isTrigMatchedToChain = 0;
   el_listTrigChains = 0;
   el_isIsolated_FCTight = 0;
   el_isIsolated_FCHighPtCaloOnly = 0;
   el_isIsolated_FCLoose = 0;
   el_isIsolated_Gradient = 0;
   el_LHLooseBL = 0;
   el_LHTight = 0;
   el_LHMedium = 0;
   el_PIDEff_SF_Tight = 0;
   el_IsoEff_SF_Tight_isolFCTight = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight = 0;
   el_ChflipEff_SF_Tight_isolFCTight = 0;
   el_IsoEff_SF_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly = 0;
   el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight = 0;
   el_ChflipEff_SF_Tight = 0;
   el_IsoEff_SF_Tight_isolFCLoose = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose = 0;
   el_ChflipEff_SF_Tight_isolFCLoose = 0;
   el_IsoEff_SF_Tight_isolGradient = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient = 0;
   el_ChflipEff_SF_Tight_isolGradient = 0;
   el_PIDEff_SF_Medium = 0;
   el_IsoEff_SF_Medium_isolFCTight = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight = 0;
   el_ChflipEff_SF_Medium_isolFCTight = 0;
   el_IsoEff_SF_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly = 0;
   el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium = 0;
   el_ChflipEff_SF_Medium = 0;
   el_IsoEff_SF_Medium_isolFCLoose = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose = 0;
   el_ChflipEff_SF_Medium_isolFCLoose = 0;
   el_IsoEff_SF_Medium_isolGradient = 0;
   el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient = 0;
   el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient = 0;
   el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient = 0;
   el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient = 0;
   el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient = 0;
   el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient = 0;
   el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient = 0;
   el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient = 0;
   el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient = 0;
   el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient = 0;
   el_ChflipEff_SF_Medium_isolGradient = 0;
   el_RecoEff_SF = 0;
   el_truthClassification = 0;
   el_truthType = 0;
   el_truthOrigin = 0;
   el_truthSignal = 0;
   el_firstEgMotherTruthType = 0;
   el_firstEgMotherTruthOrigin = 0;
   el_firstEgMotherPdgId = 0;
   jet_E = 0;
   jet_pt = 0;
   jet_phi = 0;
   jet_eta = 0;
   jet_is_MV2c10_FixedCutBEff_77 = 0;
   jet_is_MV2c10_FixedCutBEff_85 = 0;
   jet_is_MV2c10_FixedCutBEff_70 = 0;
   jet_is_MV2c10_HybBEff_77 = 0;
   jet_is_MV2c10_HybBEff_85 = 0;
   jet_is_MV2c10_HybBEff_70 = 0;
   tau_m = 0;
   tau_pt = 0;
   tau_phi = 0;
   tau_eta = 0;
   tau_isTrigMatched = 0;
   tau_isTrigMatchedToChain = 0;
   tau_listTrigChains = 0;
   tau_ntrk = 0;
   tau_charge = 0;
   tau_isJetBDTSigVeryLoose = 0;
   tau_isJetBDTSigLoose = 0;
   tau_isJetBDTSigMedium = 0;
   tau_isJetBDTSigTight = 0;
   tau_JetBDTScore = 0;
   tau_JetBDTScoreSigTrans = 0;
   tau_isEleBDTLoose = 0;
   tau_isEleBDTMedium = 0;
   tau_isEleBDTTight = 0;
   tau_EleBDTScore = 0;
   tau_passEleOLR = 0;
   tau_seedJetWidth = 0;
   tau_seedJetJvt = 0;
   tau_truthClassification = 0;
   tau_isTruthMatched = 0;
   tau_isTrueHadronicTau = 0;
   tau_truthPdgId = 0;
   tau_truthOrigin = 0;
   tau_truthType = 0;
   tau_truthSignal = 0;
   tau_truthStatus = 0;
   tau_PartonTruthLabelID = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("coreFlags", &coreFlags, &b_coreFlags);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("mcEventNumber", &mcEventNumber, &b_mcEventNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing, &b_actualInteractionsPerCrossing);
   fChain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing, &b_averageInteractionsPerCrossing);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("correctedAverageMu", &correctedAverageMu, &b_correctedAverageMu);
   fChain->SetBranchAddress("correctedAndScaledAverageMu", &correctedAndScaledAverageMu, &b_correctedAndScaledAverageMu);
   fChain->SetBranchAddress("correctedActualMu", &correctedActualMu, &b_correctedActualMu);
   fChain->SetBranchAddress("correctedAndScaledActualMu", &correctedAndScaledActualMu, &b_correctedAndScaledActualMu);
   fChain->SetBranchAddress("rand_run_nr", &rand_run_nr, &b_rand_run_nr);
   fChain->SetBranchAddress("rand_lumiblock_nr", &rand_lumiblock_nr, &b_rand_lumiblock_nr);
   fChain->SetBranchAddress("isMC", &isMC, &b_isMC);
   fChain->SetBranchAddress("crossSection", &crossSection, &b_crossSection);
//   fChain->SetBranchAddress("trigMatchMapDilep", &trigMatchMapDilep, &b_trigMatchMapDilep);
//   fChain->SetBranchAddress("trigMatchMapTrilep", &trigMatchMapTrilep, &b_trigMatchMapTrilep);
   fChain->SetBranchAddress("decayType", &decayType, &b_decayType);
   fChain->SetBranchAddress("JvtEff_SF", &JvtEff_SF, &b_JvtEff_SF);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_FixedCutBEff_70", &FTagEff_SF_MV2c10_FixedCutBEff_70, &b_FTagEff_SF_MV2c10_FixedCutBEff_70);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_FixedCutBEff_77", &FTagEff_SF_MV2c10_FixedCutBEff_77, &b_FTagEff_SF_MV2c10_FixedCutBEff_77);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_FixedCutBEff_85", &FTagEff_SF_MV2c10_FixedCutBEff_85, &b_FTagEff_SF_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_HybBEff_70", &FTagEff_SF_MV2c10_HybBEff_70, &b_FTagEff_SF_MV2c10_HybBEff_70);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_HybBEff_77", &FTagEff_SF_MV2c10_HybBEff_77, &b_FTagEff_SF_MV2c10_HybBEff_77);
   fChain->SetBranchAddress("FTagEff_SF_MV2c10_HybBEff_85", &FTagEff_SF_MV2c10_HybBEff_85, &b_FTagEff_SF_MV2c10_HybBEff_85);
   fChain->SetBranchAddress("passedTriggers", &passedTriggers, &b_passedTriggers);
   fChain->SetBranchAddress("disabledTriggers", &disabledTriggers, &b_disabledTriggers);
   fChain->SetBranchAddress("nmuon", &nmuon, &b_nmuon);
   fChain->SetBranchAddress("muon_m", &muon_m, &b_muon_m);
   fChain->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
   fChain->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
   fChain->SetBranchAddress("muon_charge", &muon_charge, &b_muon_charge);
   fChain->SetBranchAddress("muon_isTrigMatched", &muon_isTrigMatched, &b_muon_isTrigMatched);
   fChain->SetBranchAddress("muon_isTrigMatchedToChain", &muon_isTrigMatchedToChain, &b_muon_isTrigMatchedToChain);
   fChain->SetBranchAddress("muon_listTrigChains", &muon_listTrigChains, &b_muon_listTrigChains);
   fChain->SetBranchAddress("muon_isIsolated_FCTight_FixedRad", &muon_isIsolated_FCTight_FixedRad, &b_muon_isIsolated_FCTight_FixedRad);
   fChain->SetBranchAddress("muon_isIsolated_FixedCutHighPtTrackOnly", &muon_isIsolated_FixedCutHighPtTrackOnly, &b_muon_isIsolated_FixedCutHighPtTrackOnly);
   fChain->SetBranchAddress("muon_isIsolated_FCLoose_FixedRad", &muon_isIsolated_FCLoose_FixedRad, &b_muon_isIsolated_FCLoose_FixedRad);
   fChain->SetBranchAddress("muon_isIsolated_FCTightTrackOnly_FixedRad", &muon_isIsolated_FCTightTrackOnly_FixedRad, &b_muon_isIsolated_FCTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_RecoEff_SF_RecoTight", &muon_RecoEff_SF_RecoTight, &b_muon_RecoEff_SF_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu8noL1_RecoTight", &muon_TrigEff_SF_HLT_mu8noL1_RecoTight, &b_muon_TrigEff_SF_HLT_mu8noL1_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu8noL1_RecoTight", &muon_TrigMCEff_HLT_mu8noL1_RecoTight, &b_muon_TrigMCEff_HLT_mu8noL1_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu18_RecoTight", &muon_TrigEff_SF_HLT_mu18_RecoTight, &b_muon_TrigEff_SF_HLT_mu18_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu18_RecoTight", &muon_TrigMCEff_HLT_mu18_RecoTight, &b_muon_TrigMCEff_HLT_mu18_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight", &muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight, &b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight", &muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight, &b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight", &muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight, &b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight", &muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight, &b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu10_RecoTight", &muon_TrigEff_SF_HLT_mu10_RecoTight, &b_muon_TrigEff_SF_HLT_mu10_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu10_RecoTight", &muon_TrigMCEff_HLT_mu10_RecoTight, &b_muon_TrigMCEff_HLT_mu10_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu14_RecoTight", &muon_TrigEff_SF_HLT_mu14_RecoTight, &b_muon_TrigEff_SF_HLT_mu14_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu14_RecoTight", &muon_TrigMCEff_HLT_mu14_RecoTight, &b_muon_TrigMCEff_HLT_mu14_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu22_RecoTight", &muon_TrigEff_SF_HLT_mu22_RecoTight, &b_muon_TrigEff_SF_HLT_mu22_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu22_RecoTight", &muon_TrigMCEff_HLT_mu22_RecoTight, &b_muon_TrigMCEff_HLT_mu22_RecoTight);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_RecoTight", &muon_TrigEff_SF_HLT_mu20_RecoTight, &b_muon_TrigEff_SF_HLT_mu20_RecoTight);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_RecoTight", &muon_TrigMCEff_HLT_mu20_RecoTight, &b_muon_TrigMCEff_HLT_mu20_RecoTight);
   fChain->SetBranchAddress("muon_RecoEff_SF_RecoMedium", &muon_RecoEff_SF_RecoMedium, &b_muon_RecoEff_SF_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu8noL1_RecoMedium", &muon_TrigEff_SF_HLT_mu8noL1_RecoMedium, &b_muon_TrigEff_SF_HLT_mu8noL1_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu8noL1_RecoMedium", &muon_TrigMCEff_HLT_mu8noL1_RecoMedium, &b_muon_TrigMCEff_HLT_mu8noL1_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu18_RecoMedium", &muon_TrigEff_SF_HLT_mu18_RecoMedium, &b_muon_TrigEff_SF_HLT_mu18_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu18_RecoMedium", &muon_TrigMCEff_HLT_mu18_RecoMedium, &b_muon_TrigMCEff_HLT_mu18_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium", &muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium, &b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium", &muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium, &b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium", &muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium, &b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium", &muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium, &b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu10_RecoMedium", &muon_TrigEff_SF_HLT_mu10_RecoMedium, &b_muon_TrigEff_SF_HLT_mu10_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu10_RecoMedium", &muon_TrigMCEff_HLT_mu10_RecoMedium, &b_muon_TrigMCEff_HLT_mu10_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu14_RecoMedium", &muon_TrigEff_SF_HLT_mu14_RecoMedium, &b_muon_TrigEff_SF_HLT_mu14_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu14_RecoMedium", &muon_TrigMCEff_HLT_mu14_RecoMedium, &b_muon_TrigMCEff_HLT_mu14_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu22_RecoMedium", &muon_TrigEff_SF_HLT_mu22_RecoMedium, &b_muon_TrigEff_SF_HLT_mu22_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu22_RecoMedium", &muon_TrigMCEff_HLT_mu22_RecoMedium, &b_muon_TrigMCEff_HLT_mu22_RecoMedium);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_RecoMedium", &muon_TrigEff_SF_HLT_mu20_RecoMedium, &b_muon_TrigEff_SF_HLT_mu20_RecoMedium);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_RecoMedium", &muon_TrigMCEff_HLT_mu20_RecoMedium, &b_muon_TrigMCEff_HLT_mu20_RecoMedium);
   fChain->SetBranchAddress("muon_RecoEff_SF_RecoHighPt", &muon_RecoEff_SF_RecoHighPt, &b_muon_RecoEff_SF_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt", &muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu8noL1_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu8noL1_RecoHighPt", &muon_TrigMCEff_HLT_mu8noL1_RecoHighPt, &b_muon_TrigMCEff_HLT_mu8noL1_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu18_RecoHighPt", &muon_TrigEff_SF_HLT_mu18_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu18_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu18_RecoHighPt", &muon_TrigMCEff_HLT_mu18_RecoHighPt, &b_muon_TrigMCEff_HLT_mu18_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt", &muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt", &muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt, &b_muon_TrigMCEff_HLT_mu20_iloose_L1MU15_OR_HLT_mu50_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt", &muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt", &muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt, &b_muon_TrigMCEff_HLT_mu26_ivarmedium_OR_HLT_mu50_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu10_RecoHighPt", &muon_TrigEff_SF_HLT_mu10_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu10_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu10_RecoHighPt", &muon_TrigMCEff_HLT_mu10_RecoHighPt, &b_muon_TrigMCEff_HLT_mu10_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu14_RecoHighPt", &muon_TrigEff_SF_HLT_mu14_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu14_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu14_RecoHighPt", &muon_TrigMCEff_HLT_mu14_RecoHighPt, &b_muon_TrigMCEff_HLT_mu14_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu22_RecoHighPt", &muon_TrigEff_SF_HLT_mu22_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu22_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu22_RecoHighPt", &muon_TrigMCEff_HLT_mu22_RecoHighPt, &b_muon_TrigMCEff_HLT_mu22_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigEff_SF_HLT_mu20_RecoHighPt", &muon_TrigEff_SF_HLT_mu20_RecoHighPt, &b_muon_TrigEff_SF_HLT_mu20_RecoHighPt);
   fChain->SetBranchAddress("muon_TrigMCEff_HLT_mu20_RecoHighPt", &muon_TrigMCEff_HLT_mu20_RecoHighPt, &b_muon_TrigMCEff_HLT_mu20_RecoHighPt);
   fChain->SetBranchAddress("muon_IsoEff_SF_IsoFCTight_FixedRad", &muon_IsoEff_SF_IsoFCTight_FixedRad, &b_muon_IsoEff_SF_IsoFCTight_FixedRad);
   fChain->SetBranchAddress("muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly", &muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly, &b_muon_IsoEff_SF_IsoFixedCutHighPtTrackOnly);
   fChain->SetBranchAddress("muon_IsoEff_SF_IsoFCLoose_FixedRad", &muon_IsoEff_SF_IsoFCLoose_FixedRad, &b_muon_IsoEff_SF_IsoFCLoose_FixedRad);
   fChain->SetBranchAddress("muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad", &muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad, &b_muon_IsoEff_SF_IsoFCTightTrackOnly_FixedRad);
   fChain->SetBranchAddress("muon_TTVAEff_SF", &muon_TTVAEff_SF, &b_muon_TTVAEff_SF);
   fChain->SetBranchAddress("muon_isTight", &muon_isTight, &b_muon_isTight);
   fChain->SetBranchAddress("muon_isMedium", &muon_isMedium, &b_muon_isMedium);
   fChain->SetBranchAddress("muon_isHighPt", &muon_isHighPt, &b_muon_isHighPt);
   fChain->SetBranchAddress("muon_truthClassification", &muon_truthClassification, &b_muon_truthClassification);
   fChain->SetBranchAddress("muon_truthType", &muon_truthType, &b_muon_truthType);
   fChain->SetBranchAddress("muon_truthOrigin", &muon_truthOrigin, &b_muon_truthOrigin);
   fChain->SetBranchAddress("muon_truthSignal", &muon_truthSignal, &b_muon_truthSignal);
   fChain->SetBranchAddress("nel", &nel, &b_nel);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_caloCluster_eta", &el_caloCluster_eta, &b_el_caloCluster_eta);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_isTrigMatched", &el_isTrigMatched, &b_el_isTrigMatched);
   fChain->SetBranchAddress("el_isTrigMatchedToChain", &el_isTrigMatchedToChain, &b_el_isTrigMatchedToChain);
   fChain->SetBranchAddress("el_listTrigChains", &el_listTrigChains, &b_el_listTrigChains);
   fChain->SetBranchAddress("el_isIsolated_FCTight", &el_isIsolated_FCTight, &b_el_isIsolated_FCTight);
   fChain->SetBranchAddress("el_isIsolated_FCHighPtCaloOnly", &el_isIsolated_FCHighPtCaloOnly, &b_el_isIsolated_FCHighPtCaloOnly);
   fChain->SetBranchAddress("el_isIsolated_FCLoose", &el_isIsolated_FCLoose, &b_el_isIsolated_FCLoose);
   fChain->SetBranchAddress("el_isIsolated_Gradient", &el_isIsolated_Gradient, &b_el_isIsolated_Gradient);
   fChain->SetBranchAddress("el_LHLooseBL", &el_LHLooseBL, &b_el_LHLooseBL);
   fChain->SetBranchAddress("el_LHTight", &el_LHTight, &b_el_LHTight);
   fChain->SetBranchAddress("el_LHMedium", &el_LHMedium, &b_el_LHMedium);
   fChain->SetBranchAddress("el_PIDEff_SF_Tight", &el_PIDEff_SF_Tight, &b_el_PIDEff_SF_Tight);
   fChain->SetBranchAddress("el_IsoEff_SF_Tight_isolFCTight", &el_IsoEff_SF_Tight_isolFCTight, &b_el_IsoEff_SF_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCTight);
   fChain->SetBranchAddress("el_ChflipEff_SF_Tight_isolFCTight", &el_ChflipEff_SF_Tight_isolFCTight, &b_el_ChflipEff_SF_Tight_isolFCTight);
   fChain->SetBranchAddress("el_IsoEff_SF_Tight_isolFCHighPtCaloOnly", &el_IsoEff_SF_Tight_isolFCHighPtCaloOnly, &b_el_IsoEff_SF_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly", &el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly, &b_el_ChflipEff_SF_Tight_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight);
   fChain->SetBranchAddress("el_ChflipEff_SF_Tight", &el_ChflipEff_SF_Tight, &b_el_ChflipEff_SF_Tight);
   fChain->SetBranchAddress("el_IsoEff_SF_Tight_isolFCLoose", &el_IsoEff_SF_Tight_isolFCLoose, &b_el_IsoEff_SF_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_ChflipEff_SF_Tight_isolFCLoose", &el_ChflipEff_SF_Tight_isolFCLoose, &b_el_ChflipEff_SF_Tight_isolFCLoose);
   fChain->SetBranchAddress("el_IsoEff_SF_Tight_isolGradient", &el_IsoEff_SF_Tight_isolGradient, &b_el_IsoEff_SF_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Tight_isolGradient);
   fChain->SetBranchAddress("el_ChflipEff_SF_Tight_isolGradient", &el_ChflipEff_SF_Tight_isolGradient, &b_el_ChflipEff_SF_Tight_isolGradient);
   fChain->SetBranchAddress("el_PIDEff_SF_Medium", &el_PIDEff_SF_Medium, &b_el_PIDEff_SF_Medium);
   fChain->SetBranchAddress("el_IsoEff_SF_Medium_isolFCTight", &el_IsoEff_SF_Medium_isolFCTight, &b_el_IsoEff_SF_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCTight);
   fChain->SetBranchAddress("el_ChflipEff_SF_Medium_isolFCTight", &el_ChflipEff_SF_Medium_isolFCTight, &b_el_ChflipEff_SF_Medium_isolFCTight);
   fChain->SetBranchAddress("el_IsoEff_SF_Medium_isolFCHighPtCaloOnly", &el_IsoEff_SF_Medium_isolFCHighPtCaloOnly, &b_el_IsoEff_SF_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly", &el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly, &b_el_ChflipEff_SF_Medium_isolFCHighPtCaloOnly);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium);
   fChain->SetBranchAddress("el_ChflipEff_SF_Medium", &el_ChflipEff_SF_Medium, &b_el_ChflipEff_SF_Medium);
   fChain->SetBranchAddress("el_IsoEff_SF_Medium_isolFCLoose", &el_IsoEff_SF_Medium_isolFCLoose, &b_el_IsoEff_SF_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_ChflipEff_SF_Medium_isolFCLoose", &el_ChflipEff_SF_Medium_isolFCLoose, &b_el_ChflipEff_SF_Medium_isolFCLoose);
   fChain->SetBranchAddress("el_IsoEff_SF_Medium_isolGradient", &el_IsoEff_SF_Medium_isolGradient, &b_el_IsoEff_SF_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient", &el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient, &b_el_TrigEff_SF_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient", &el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient, &b_el_TrigMCEff_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient", &el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient, &b_el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient", &el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient, &b_el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_2018_e12_lhloose_nod0_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient", &el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient, &b_el_TrigEff_SF_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient", &el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient, &b_el_TrigMCEff_TRI_E_2015_e9_lhloose_2016_e9_lhloose_nod0_2017_2018_e12_lhvloose_nod0_L1EM10VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient", &el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient, &b_el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient", &el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient, &b_el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient", &el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient, &b_el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient", &el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient, &b_el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_Medium_isolGradient);
   fChain->SetBranchAddress("el_ChflipEff_SF_Medium_isolGradient", &el_ChflipEff_SF_Medium_isolGradient, &b_el_ChflipEff_SF_Medium_isolGradient);
   fChain->SetBranchAddress("el_RecoEff_SF", &el_RecoEff_SF, &b_el_RecoEff_SF);
   fChain->SetBranchAddress("el_truthClassification", &el_truthClassification, &b_el_truthClassification);
   fChain->SetBranchAddress("el_truthType", &el_truthType, &b_el_truthType);
   fChain->SetBranchAddress("el_truthOrigin", &el_truthOrigin, &b_el_truthOrigin);
   fChain->SetBranchAddress("el_truthSignal", &el_truthSignal, &b_el_truthSignal);
   fChain->SetBranchAddress("el_firstEgMotherTruthType", &el_firstEgMotherTruthType, &b_el_firstEgMotherTruthType);
   fChain->SetBranchAddress("el_firstEgMotherTruthOrigin", &el_firstEgMotherTruthOrigin, &b_el_firstEgMotherTruthOrigin);
   fChain->SetBranchAddress("el_firstEgMotherPdgId", &el_firstEgMotherPdgId, &b_el_firstEgMotherPdgId);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_is_MV2c10_FixedCutBEff_77", &jet_is_MV2c10_FixedCutBEff_77, &b_jet_is_MV2c10_FixedCutBEff_77);
   fChain->SetBranchAddress("jet_is_MV2c10_FixedCutBEff_85", &jet_is_MV2c10_FixedCutBEff_85, &b_jet_is_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("jet_is_MV2c10_FixedCutBEff_70", &jet_is_MV2c10_FixedCutBEff_70, &b_jet_is_MV2c10_FixedCutBEff_70);
   fChain->SetBranchAddress("jet_is_MV2c10_HybBEff_77", &jet_is_MV2c10_HybBEff_77, &b_jet_is_MV2c10_HybBEff_77);
   fChain->SetBranchAddress("jet_is_MV2c10_HybBEff_85", &jet_is_MV2c10_HybBEff_85, &b_jet_is_MV2c10_HybBEff_85);
   fChain->SetBranchAddress("jet_is_MV2c10_HybBEff_70", &jet_is_MV2c10_HybBEff_70, &b_jet_is_MV2c10_HybBEff_70);
   fChain->SetBranchAddress("ntau", &ntau, &b_ntau);
   fChain->SetBranchAddress("tau_m", &tau_m, &b_tau_m);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_isTrigMatched", &tau_isTrigMatched, &b_tau_isTrigMatched);
   fChain->SetBranchAddress("tau_isTrigMatchedToChain", &tau_isTrigMatchedToChain, &b_tau_isTrigMatchedToChain);
   fChain->SetBranchAddress("tau_listTrigChains", &tau_listTrigChains, &b_tau_listTrigChains);
   fChain->SetBranchAddress("tau_ntrk", &tau_ntrk, &b_tau_ntrk);
   fChain->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
   fChain->SetBranchAddress("tau_isJetBDTSigVeryLoose", &tau_isJetBDTSigVeryLoose, &b_tau_isJetBDTSigVeryLoose);
   fChain->SetBranchAddress("tau_isJetBDTSigLoose", &tau_isJetBDTSigLoose, &b_tau_isJetBDTSigLoose);
   fChain->SetBranchAddress("tau_isJetBDTSigMedium", &tau_isJetBDTSigMedium, &b_tau_isJetBDTSigMedium);
   fChain->SetBranchAddress("tau_isJetBDTSigTight", &tau_isJetBDTSigTight, &b_tau_isJetBDTSigTight);
   fChain->SetBranchAddress("tau_JetBDTScore", &tau_JetBDTScore, &b_tau_JetBDTScore);
   fChain->SetBranchAddress("tau_JetBDTScoreSigTrans", &tau_JetBDTScoreSigTrans, &b_tau_JetBDTScoreSigTrans);
   fChain->SetBranchAddress("tau_isEleBDTLoose", &tau_isEleBDTLoose, &b_tau_isEleBDTLoose);
   fChain->SetBranchAddress("tau_isEleBDTMedium", &tau_isEleBDTMedium, &b_tau_isEleBDTMedium);
   fChain->SetBranchAddress("tau_isEleBDTTight", &tau_isEleBDTTight, &b_tau_isEleBDTTight);
   fChain->SetBranchAddress("tau_EleBDTScore", &tau_EleBDTScore, &b_tau_EleBDTScore);
   fChain->SetBranchAddress("tau_passEleOLR", &tau_passEleOLR, &b_tau_passEleOLR);
   fChain->SetBranchAddress("tau_seedJetWidth", &tau_seedJetWidth, &b_tau_seedJetWidth);
   fChain->SetBranchAddress("tau_seedJetJvt", &tau_seedJetJvt, &b_tau_seedJetJvt);
   fChain->SetBranchAddress("tau_truthClassification", &tau_truthClassification, &b_tau_truthClassification);
   fChain->SetBranchAddress("tau_isTruthMatched", &tau_isTruthMatched, &b_tau_isTruthMatched);
   fChain->SetBranchAddress("tau_isTrueHadronicTau", &tau_isTrueHadronicTau, &b_tau_isTrueHadronicTau);
   fChain->SetBranchAddress("tau_truthPdgId", &tau_truthPdgId, &b_tau_truthPdgId);
   fChain->SetBranchAddress("tau_truthOrigin", &tau_truthOrigin, &b_tau_truthOrigin);
   fChain->SetBranchAddress("tau_truthType", &tau_truthType, &b_tau_truthType);
   fChain->SetBranchAddress("tau_truthSignal", &tau_truthSignal, &b_tau_truthSignal);
   fChain->SetBranchAddress("tau_truthStatus", &tau_truthStatus, &b_tau_truthStatus);
   fChain->SetBranchAddress("tau_PartonTruthLabelID", &tau_PartonTruthLabelID, &b_tau_PartonTruthLabelID);
   fChain->SetBranchAddress("metFinalTrk", &metFinalTrk, &b_metFinalTrk);
   fChain->SetBranchAddress("metFinalTrkPx", &metFinalTrkPx, &b_metFinalTrkPx);
   fChain->SetBranchAddress("metFinalTrkPy", &metFinalTrkPy, &b_metFinalTrkPy);
   fChain->SetBranchAddress("metFinalTrkSumEt", &metFinalTrkSumEt, &b_metFinalTrkSumEt);
   fChain->SetBranchAddress("metFinalTrkPhi", &metFinalTrkPhi, &b_metFinalTrkPhi);
   fChain->SetBranchAddress("metFinalTrkOverSqrtSumEt", &metFinalTrkOverSqrtSumEt, &b_metFinalTrkOverSqrtSumEt);
   fChain->SetBranchAddress("metFinalTrkOverSqrtHt", &metFinalTrkOverSqrtHt, &b_metFinalTrkOverSqrtHt);
   fChain->SetBranchAddress("metFinalTrkSignificance", &metFinalTrkSignificance, &b_metFinalTrkSignificance);
   fChain->SetBranchAddress("metFinalTrkSigDirectional", &metFinalTrkSigDirectional, &b_metFinalTrkSigDirectional);
   fChain->SetBranchAddress("metSoftTrk", &metSoftTrk, &b_metSoftTrk);
   fChain->SetBranchAddress("metSoftTrkSumEt", &metSoftTrkSumEt, &b_metSoftTrkSumEt);
   fChain->SetBranchAddress("metSoftTrkPhi", &metSoftTrkPhi, &b_metSoftTrkPhi);
   Notify();
}

Bool_t VLLMin::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void VLLMin::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t VLLMin::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef VLLMin_cxx
