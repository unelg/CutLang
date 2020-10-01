//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 16 13:47:09 2019 by ROOT version 6.16/00
// from TTree Events/Events
// found on file: /Users/ngu/Dropbox/cutlang/ttjets_NANOAOD.root
//////////////////////////////////////////////////////////

#ifndef CMSnanoAOD_h
#define CMSnanoAOD_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "dbxParticle.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t nElectron_ = 50;
const Int_t nFatJet_   = 50; // SEZEN beni unutma
const Int_t nGenJetAK8_ = 50;
const Int_t nGenJet_ = 50;
const Int_t nGenPart_ = 200;
const Int_t nMuon_ = 100;
const Int_t nTau_ = 100;
const Int_t nPhoton_ = 50;
const Int_t nJet_ = 150;


class CMSnanoAOD {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Bool_t          HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   Float_t         CaloMET_phi;
   Float_t         CaloMET_pt;
   Float_t         CaloMET_sumEt;
   UInt_t          nElectron;
   Float_t         Electron_deltaEtaSC[nElectron_];   //[nElectron]
   Float_t         Electron_dr03EcalRecHitSumEt[nElectron_];   //[nElectron]
   Float_t         Electron_dr03HcalDepth1TowerSumEt[nElectron_];   //[nElectron]
   Float_t         Electron_dr03TkSumPt[nElectron_];   //[nElectron_]
   Float_t         Electron_dxy[nElectron_];   //[nElectron]
   Float_t         Electron_dxyErr[nElectron_];   //[nElectron]
   Float_t         Electron_dz[nElectron_];   //[nElectron]
   Float_t         Electron_dzErr[nElectron_];   //[nElectron]
   Float_t         Electron_eCorr[nElectron_];   //[nElectron]
   Float_t         Electron_eInvMinusPInv[nElectron_];   //[nElectron]
   Float_t         Electron_energyErr[nElectron_];   //[nElectron]
   Float_t         Electron_eta[nElectron_];   //[nElectron]
   Float_t         Electron_hoe[nElectron_];   //[nElectron]
   Float_t         Electron_ip3d[nElectron_];   //[nElectron]
   Float_t         Electron_mass[nElectron_];   //[nElectron]
   Float_t         Electron_miniPFRelIso_all[nElectron_];   //[nElectron]
   Float_t         Electron_miniPFRelIso_chg[nElectron_];   //[nElectron]
   Float_t         Electron_mvaFall17Iso[nElectron_];   //[nElectron]
   Float_t         Electron_mvaFall17noIso[nElectron_];   //[nElectron]
   Float_t         Electron_pfRelIso03_all[nElectron_];   //[nElectron]
   Float_t         Electron_pfRelIso03_chg[nElectron_];   //[nElectron]
   Float_t         Electron_phi[nElectron_];   //[nElectron]
   Float_t         Electron_pt[nElectron_];   //[nElectron]
   Float_t         Electron_r9[nElectron_];   //[nElectron]
   Float_t         Electron_sieie[nElectron_];   //[nElectron]
   Float_t         Electron_sip3d[nElectron_];   //[nElectron]
   Float_t         Electron_mvaTTH[nElectron_];   //[nElectron]
   Int_t           Electron_charge[nElectron_];   //[nElectron]
   Int_t           Electron_cutBased[nElectron_];   //[nElectron]
   Int_t           Electron_jetIdx[nElectron_];   //[nElectron]
   Int_t           Electron_pdgId[nElectron_];   //[nElectron]
   Int_t           Electron_photonIdx[nElectron_];   //[nElectron]
   Int_t           Electron_tightCharge[nElectron_];   //[nElectron]
   Int_t           Electron_vidNestedWPBitmap[nElectron_];   //[nElectron]
   Bool_t          Electron_convVeto[nElectron_];   //[nElectron]
   Bool_t          Electron_cutBased_HEEP[nElectron_];   //[nElectron]
   Bool_t          Electron_isPFcand[nElectron_];   //[nElectron]
   UChar_t         Electron_lostHits[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17Iso_WP80[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17Iso_WP90[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17Iso_WPL[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17noIso_WP80[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17noIso_WP90[nElectron_];   //[nElectron]
   Bool_t          Electron_mvaFall17noIso_WPL[nElectron_];   //[nElectron]

   UInt_t          nFatJet;
   Float_t         FatJet_area[nFatJet_];   //[nFatJet]
   Float_t         FatJet_btagCMVA[nFatJet_];   //[nFatJet]
   Float_t         FatJet_btagCSVV2[nFatJet_];   //[nFatJet]
   Float_t         FatJet_btagDeepB[nFatJet_];   //[nFatJet]
   Float_t         FatJet_btagHbb[nFatJet_];   //[nFatJet]
   Float_t         FatJet_eta[nFatJet_];   //[nFatJet]
   Float_t         FatJet_mass[nFatJet_];   //[nFatJet]
   Float_t         FatJet_msoftdrop[nFatJet_];   //[nFatJet]
   Float_t         FatJet_n2b1[nFatJet_];   //[nFatJet]
   Float_t         FatJet_n3b1[nFatJet_];   //[nFatJet]
   Float_t         FatJet_phi[nFatJet_];   //[nFatJet]
   Float_t         FatJet_pt[nFatJet_];   //[nFatJet]
   Float_t         FatJet_tau1[nFatJet_];   //[nFatJet]
   Float_t         FatJet_tau2[nFatJet_];   //[nFatJet]
   Float_t         FatJet_tau3[nFatJet_];   //[nFatJet]
   Float_t         FatJet_tau4[nFatJet_];   //[nFatJet]
   Int_t           FatJet_jetId[nFatJet_];   //[nFatJet]
   Int_t           FatJet_subJetIdx1[nFatJet_];   //[nFatJet]
   Int_t           FatJet_subJetIdx2[nFatJet_];   //[nFatJet]

   UInt_t          nGenJetAK8;
   Float_t         GenJetAK8_eta[nGenJetAK8_];   //[nGenJetAK8]
   Float_t         GenJetAK8_mass[nGenJetAK8_];   //[nGenJetAK8]
   Float_t         GenJetAK8_phi[nGenJetAK8_];   //[nGenJetAK8]
   Float_t         GenJetAK8_pt[nGenJetAK8_];   //[nGenJetAK8]
   UInt_t          nGenJet;
   Float_t         GenJet_eta[nGenJet_];   //[nGenJet]
   Float_t         GenJet_mass[nGenJet_];   //[nGenJet]
   Float_t         GenJet_phi[nGenJet_];   //[nGenJet]
   Float_t         GenJet_pt[nGenJet_];   //[nGenJet]
   UInt_t          nGenPart;
   Float_t         GenPart_eta[nGenPart_];   //[nGenPart]
   Float_t         GenPart_mass[nGenPart_];   //[nGenPart]
   Float_t         GenPart_phi[nGenPart_];   //[nGenPart]
   Float_t         GenPart_pt[nGenPart_];   //[nGenPart]
   Int_t           GenPart_genPartIdxMother[nGenPart_];   //[nGenPart]
   Int_t           GenPart_pdgId[nGenPart_];   //[nGenPart]
   Int_t           GenPart_status[nGenPart_];   //[nGenPart]
   Int_t           GenPart_statusFlags[nGenPart_];   //[nGenPart]
   UInt_t          nSubGenJetAK8;
   Float_t         SubGenJetAK8_eta[12];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_mass[12];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_phi[12];   //[nSubGenJetAK8]
   Float_t         SubGenJetAK8_pt[12];   //[nSubGenJetAK8]
   Float_t         Generator_binvar;
   Float_t         Generator_scalePDF;
   Float_t         Generator_weight;
   Float_t         Generator_x1;
   Float_t         Generator_x2;
   Float_t         Generator_xpdf1;
   Float_t         Generator_xpdf2;
   Int_t           Generator_id1;
   Int_t           Generator_id2;
   UInt_t          nGenVisTau;
   Float_t         GenVisTau_eta[3];   //[nGenVisTau]
   Float_t         GenVisTau_mass[3];   //[nGenVisTau]
   Float_t         GenVisTau_phi[3];   //[nGenVisTau]
   Float_t         GenVisTau_pt[3];   //[nGenVisTau]
   Int_t           GenVisTau_charge[3];   //[nGenVisTau]
   Int_t           GenVisTau_genPartIdxMother[3];   //[nGenVisTau]
   Int_t           GenVisTau_status[3];   //[nGenVisTau]
   Float_t         genWeight;
   Float_t         LHEWeight_originalXWGTUP;
   UInt_t          nLHEPdfWeight;
   Float_t         LHEPdfWeight[1];   //[nLHEPdfWeight]
   UInt_t          nLHEScaleWeight;
   Float_t         LHEScaleWeight[1];   //[nLHEScaleWeight]
   UInt_t          nIsoTrack;
   Float_t         IsoTrack_dxy[5];   //[nIsoTrack]
   Float_t         IsoTrack_dz[5];   //[nIsoTrack]
   Float_t         IsoTrack_eta[5];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_all[5];   //[nIsoTrack]
   Float_t         IsoTrack_pfRelIso03_chg[5];   //[nIsoTrack]
   Float_t         IsoTrack_phi[5];   //[nIsoTrack]
   Float_t         IsoTrack_pt[5];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_all[5];   //[nIsoTrack]
   Float_t         IsoTrack_miniPFRelIso_chg[5];   //[nIsoTrack]
   Int_t           IsoTrack_pdgId[5];   //[nIsoTrack]
   Bool_t          IsoTrack_isHighPurityTrack[5];   //[nIsoTrack]
   Bool_t          IsoTrack_isPFcand[5];   //[nIsoTrack]
   UInt_t          nJet;
   Float_t         Jet_area[nJet_];   //[nJet]
   Float_t         Jet_btagCMVA[nJet_];   //[nJet]
   Float_t         Jet_btagCSVV2[nJet_];   //[nJet]
   Float_t         Jet_btagDeepB[nJet_];   //[nJet]
   Float_t         Jet_btagDeepC[nJet_];   //[nJet]
   Float_t         Jet_btagDeepFlavB[nJet_];   //[nJet]
   Float_t         Jet_chEmEF[nJet_];   //[nJet]
   Float_t         Jet_chHEF[nJet_];   //[nJet]
   Float_t         Jet_eta[nJet_];   //[nJet]
   Float_t         Jet_mass[nJet_];   //[nJet]
   Float_t         Jet_neEmEF[nJet_];   //[nJet]
   Float_t         Jet_neHEF[nJet_];   //[nJet]
   Float_t         Jet_phi[nJet_];   //[nJet]
   Float_t         Jet_pt[nJet_];   //[nJet]
   Float_t         Jet_qgl[nJet_];   //[nJet]
   Float_t         Jet_rawFactor[nJet_];   //[nJet]
   Float_t         Jet_bReg[nJet_];   //[nJet]
   Int_t           Jet_electronIdx1[nJet_];   //[nJet]
   Int_t           Jet_electronIdx2[nJet_];   //[nJet]
   Int_t           Jet_jetId[nJet_];   //[nJet]
   Int_t           Jet_muonIdx1[nJet_];   //[nJet]
   Int_t           Jet_muonIdx2[nJet_];   //[nJet]
   Int_t           Jet_nConstituents[nJet_];   //[nJet]
   Int_t           Jet_nElectrons[nJet_];   //[nJet]
   Int_t           Jet_nMuons[nJet_];   //[nJet]
   Bool_t          Jet_puId[nJet_];   //[nJet]
   Float_t         LHE_HT;
   Float_t         LHE_HTIncoming;
   Float_t         LHE_Vpt;
   UChar_t         LHE_Njets;
   UChar_t         LHE_Nb;
   UChar_t         LHE_Nc;
   UChar_t         LHE_Nuds;
   UChar_t         LHE_Nglu;
   UChar_t         LHE_NpNLO;
   UChar_t         LHE_NpLO;
   UInt_t          nLHEPart;
   Float_t         LHEPart_pt[9];   //[nLHEPart]
   Float_t         LHEPart_eta[9];   //[nLHEPart]
   Float_t         LHEPart_phi[9];   //[nLHEPart]
   Float_t         LHEPart_mass[9];   //[nLHEPart]
   Int_t           LHEPart_pdgId[9];   //[nLHEPart]
   Float_t         GenMET_phi;
   Float_t         GenMET_pt;
   Float_t         MET_MetUnclustEnUpDeltaX;
   Float_t         MET_MetUnclustEnUpDeltaY;
   Float_t         MET_covXX;
   Float_t         MET_covXY;
   Float_t         MET_covYY;
   Float_t         MET_phi;
   Float_t         MET_pt;
   Float_t         MET_significance;
   Float_t         MET_sumEt;
   UInt_t          nMuon;
   Float_t         Muon_dxy[nMuon_];   //[nMuon]
   Float_t         Muon_dxyErr[nMuon_];   //[nMuon]
   Float_t         Muon_dz[nMuon_];   //[nMuon]
   Float_t         Muon_dzErr[nMuon_];   //[nMuon]
   Float_t         Muon_eta[nMuon_];   //[nMuon]
   Float_t         Muon_ip3d[nMuon_];   //[nMuon]
   Float_t         Muon_mass[nMuon_];   //[nMuon]
   Float_t         Muon_miniPFRelIso_all[nMuon_];   //[nMuon]
   Float_t         Muon_miniPFRelIso_chg[nMuon_];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[nMuon_];   //[nMuon]
   Float_t         Muon_pfRelIso03_chg[nMuon_];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[nMuon_];   //[nMuon]
   Float_t         Muon_phi[nMuon_];   //[nMuon]
   Float_t         Muon_pt[nMuon_];   //[nMuon]
   Float_t         Muon_ptErr[nMuon_];   //[nMuon]
   Float_t         Muon_segmentComp[nMuon_];   //[nMuon]
   Float_t         Muon_sip3d[nMuon_];   //[nMuon]
   Float_t         Muon_mvaTTH[nMuon_];   //[nMuon]
   Int_t           Muon_charge[nMuon_];   //[nMuon]
   Int_t           Muon_jetIdx[nMuon_];   //[nMuon]
   Int_t           Muon_nStations[nMuon_];   //[nMuon]
   Int_t           Muon_nTrackerLayers[nMuon_];   //[nMuon]
   Int_t           Muon_pdgId[nMuon_];   //[nMuon]
   Int_t           Muon_tightCharge[nMuon_];   //[nMuon]
   UChar_t         Muon_highPtId[nMuon_];   //[nMuon]
   Bool_t          Muon_isPFcand[nMuon_];   //[nMuon]
   Bool_t          Muon_mediumId[nMuon_];   //[nMuon]
   Bool_t          Muon_softId[nMuon_];   //[nMuon]
   Bool_t          Muon_tightId[nMuon_];   //[nMuon]
   UInt_t          nPhoton;
   Float_t         Photon_eCorr[nPhoton_];   //[nPhoton]
   Float_t         Photon_energyErr[nPhoton_];   //[nPhoton]
   Float_t         Photon_eta[nPhoton_];   //[nPhoton]
   Float_t         Photon_hoe[nPhoton_];   //[nPhoton]
   Float_t         Photon_mass[nPhoton_];   //[nPhoton]
   Float_t         Photon_mvaID[nPhoton_];   //[nPhoton]
   Float_t         Photon_pfRelIso03_all[nPhoton_];   //[nPhoton]
   Float_t         Photon_pfRelIso03_chg[nPhoton_];   //[nPhoton]
   Float_t         Photon_phi[nPhoton_];   //[nPhoton]
   Float_t         Photon_pt[nPhoton_];   //[nPhoton]
   Float_t         Photon_r9[nPhoton_];   //[nPhoton]
   Float_t         Photon_sieie[nPhoton_];   //[nPhoton]
   Int_t           Photon_charge[nPhoton_];   //[nPhoton]
   Int_t           Photon_cutBasedBitmap[nPhoton_];   //[nPhoton]
   Int_t           Photon_electronIdx[nPhoton_];   //[nPhoton]
   Int_t           Photon_jetIdx[nPhoton_];   //[nPhoton]
   Int_t           Photon_pdgId[nPhoton_];   //[nPhoton]
   Int_t           Photon_vidNestedWPBitmap[nPhoton_];   //[nPhoton]
   Bool_t          Photon_electronVeto[nPhoton_];   //[nPhoton]
   Bool_t          Photon_isScEtaEB[nPhoton_];   //[nPhoton]
   Bool_t          Photon_isScEtaEE[nPhoton_];   //[nPhoton]
   Bool_t          Photon_mvaID_WP80[nPhoton_];   //[nPhoton]
   Bool_t          Photon_mvaID_WP90[nPhoton_];   //[nPhoton]
   Bool_t          Photon_pixelSeed[nPhoton_];   //[nPhoton]
   Float_t         Pileup_nTrueInt;
   Int_t           Pileup_nPU;
   Int_t           Pileup_sumEOOT;
   Int_t           Pileup_sumLOOT;
   Float_t         PuppiMET_phi;
   Float_t         PuppiMET_pt;
   Float_t         PuppiMET_sumEt;
   Float_t         RawMET_phi;
   Float_t         RawMET_pt;
   Float_t         RawMET_sumEt;
   Float_t         fixedGridRhoFastjetAll;
   Float_t         fixedGridRhoFastjetCentralCalo;
   Float_t         fixedGridRhoFastjetCentralNeutral;
   UInt_t          nGenDressedLepton;
   Float_t         GenDressedLepton_eta[3];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_mass[3];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_phi[3];   //[nGenDressedLepton]
   Float_t         GenDressedLepton_pt[3];   //[nGenDressedLepton]
   Int_t           GenDressedLepton_pdgId[3];   //[nGenDressedLepton]
   UInt_t          nSoftActivityJet;
   Float_t         SoftActivityJet_eta[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_phi[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJet_pt[6];   //[nSoftActivityJet]
   Float_t         SoftActivityJetHT;
   Float_t         SoftActivityJetHT10;
   Float_t         SoftActivityJetHT2;
   Float_t         SoftActivityJetHT5;
   Int_t           SoftActivityJetNjets10;
   Int_t           SoftActivityJetNjets2;
   Int_t           SoftActivityJetNjets5;
   UInt_t          nSubJet;
   Float_t         SubJet_btagCMVA[10];   //[nSubJet]
   Float_t         SubJet_btagCSVV2[10];   //[nSubJet]
   Float_t         SubJet_btagDeepB[10];   //[nSubJet]
   Float_t         SubJet_eta[10];   //[nSubJet]
   Float_t         SubJet_mass[10];   //[nSubJet]
   Float_t         SubJet_n2b1[10];   //[nSubJet]
   Float_t         SubJet_n3b1[10];   //[nSubJet]
   Float_t         SubJet_phi[10];   //[nSubJet]
   Float_t         SubJet_pt[10];   //[nSubJet]
   Float_t         SubJet_tau1[10];   //[nSubJet]
   Float_t         SubJet_tau2[10];   //[nSubJet]
   Float_t         SubJet_tau3[10];   //[nSubJet]
   Float_t         SubJet_tau4[10];   //[nSubJet]
   UInt_t          nTau;
   Float_t         Tau_chargedIso[nTau_];   //[nTau]
   Float_t         Tau_dxy[nTau_];   //[nTau]
   Float_t         Tau_dz[nTau_];   //[nTau]
   Float_t         Tau_eta[nTau_];   //[nTau]
   Float_t         Tau_leadTkDeltaEta[nTau_];   //[nTau]
   Float_t         Tau_leadTkDeltaPhi[nTau_];   //[nTau]
   Float_t         Tau_leadTkPtOverTauPt[nTau_];   //[nTau]
   Float_t         Tau_mass[nTau_];   //[nTau]
   Float_t         Tau_neutralIso[nTau_];   //[nTau]
   Float_t         Tau_phi[nTau_];   //[nTau]
   Float_t         Tau_photonsOutsideSignalCone[nTau_];   //[nTau]
   Float_t         Tau_pt[nTau_];   //[nTau]
   Float_t         Tau_puCorr[nTau_];   //[nTau]
   Float_t         Tau_rawAntiEle[nTau_];   //[nTau]
   Float_t         Tau_rawIso[nTau_];   //[nTau]
   Float_t         Tau_rawIsodR03[nTau_];   //[nTau]
   Float_t         Tau_rawMVAnewDM2017v2[nTau_];   //[nTau]
   Float_t         Tau_rawMVAoldDM[nTau_];   //[nTau]
   Float_t         Tau_rawMVAoldDM2017v1[nTau_];   //[nTau]
   Float_t         Tau_rawMVAoldDM2017v2[nTau_];   //[nTau]
   Float_t         Tau_rawMVAoldDMdR032017v2[nTau_];   //[nTau]
   Int_t           Tau_charge[nTau_];   //[nTau]
   Int_t           Tau_decayMode[nTau_];   //[nTau]
   Int_t           Tau_jetIdx[nTau_];   //[nTau]
   Int_t           Tau_rawAntiEleCat[nTau_];   //[nTau]
   UChar_t         Tau_idAntiEle[nTau_];   //[nTau]
   UChar_t         Tau_idAntiMu[nTau_];   //[nTau]
   Bool_t          Tau_idDecayMode[nTau_];   //[nTau]
   Bool_t          Tau_idDecayModeNewDMs[nTau_];   //[nTau]
   UChar_t         Tau_idMVAnewDM2017v2[nTau_];   //[nTau]
   UChar_t         Tau_idMVAoldDM[nTau_];   //[nTau]
   UChar_t         Tau_idMVAoldDM2017v1[nTau_];   //[nTau]
   UChar_t         Tau_idMVAoldDM2017v2[nTau_];   //[nTau]
   UChar_t         Tau_idMVAoldDMdR032017v2[nTau_];   //[nTau]
//----------------new variables
   Float_t         Tau_relIso_all[nTau_];   //[nTau]
   Float_t         Tau_idIsoRaw[nTau_];   //[nTau]
   Bool_t          Tau_idIsoVLoose[nTau_];   //[nTau]
   Bool_t          Tau_idIsoLoose[nTau_];   //[nTau]
   Bool_t          Tau_idIsoMedium[nTau_];   //[nTau]
   Bool_t          Tau_idIsoTight[nTau_];   //[nTau]
   Bool_t          Tau_idAntiEleLoose[nTau_];   //[nTau]
   Bool_t          Tau_idAntiEleMedium[nTau_];   //[nTau]
   Bool_t          Tau_idAntiEleTight[nTau_];   //[nTau]
   Bool_t          Tau_idAntiMuLoose[nTau_];   //[nTau]
   Bool_t          Tau_idAntiMuMedium[nTau_];   //[nTau]
   Bool_t          Tau_idAntiMuTight[nTau_];   //[nTau]


   Float_t         TkMET_phi;
   Float_t         TkMET_pt;
   Float_t         TkMET_sumEt;
   UInt_t          nTrigObj;
   Float_t         TrigObj_pt[34];   //[nTrigObj]
   Float_t         TrigObj_eta[34];   //[nTrigObj]
   Float_t         TrigObj_phi[34];   //[nTrigObj]
   Float_t         TrigObj_l1pt[34];   //[nTrigObj]
   Float_t         TrigObj_l1pt_2[34];   //[nTrigObj]
   Float_t         TrigObj_l2pt[34];   //[nTrigObj]
   Int_t           TrigObj_id[34];   //[nTrigObj]
   Int_t           TrigObj_l1iso[34];   //[nTrigObj]
   Int_t           TrigObj_l1charge[34];   //[nTrigObj]
   Int_t           TrigObj_filterBits[34];   //[nTrigObj]
   Int_t           genTtbarId;
   UInt_t          nOtherPV;
   Float_t         OtherPV_z[3];   //[nOtherPV]
   Float_t         PV_ndof;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   Float_t         PV_chi2;
   Float_t         PV_score;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   UInt_t          nSV;
   Float_t         SV_dlen[13];   //[nSV]
   Float_t         SV_dlenSig[13];   //[nSV]
   Float_t         SV_pAngle[13];   //[nSV]
   Int_t           Electron_genPartIdx[nElectron_];   //[nElectron]
   UChar_t         Electron_genPartFlav[nElectron_];   //[nElectron]
   Int_t           GenJetAK8_partonFlavour[nGenJetAK8_];   //[nGenJetAK8]
   UChar_t         GenJetAK8_hadronFlavour[nGenJetAK8_];   //[nGenJetAK8]
   Int_t           GenJet_partonFlavour[nGenJet_];   //[nGenJet]
   UChar_t         GenJet_hadronFlavour[nGenJet_];   //[nGenJet]
   Int_t           Jet_genJetIdx[nJet_];   //[nJet]
   Int_t           Jet_hadronFlavour[nJet_];   //[nJet]
   Int_t           Jet_partonFlavour[nJet_];   //[nJet]
   Int_t           Muon_genPartIdx[nMuon_];   //[nMuon]
   UChar_t         Muon_genPartFlav[nMuon_];   //[nMuon]
   Int_t           Photon_genPartIdx[nPhoton_];   //[nPhoton]
   UChar_t         Photon_genPartFlav[nPhoton_];   //[nPhoton]
   Float_t         MET_fiducialGenPhi;
   Float_t         MET_fiducialGenPt;
   UChar_t         Electron_cleanmask[nElectron_];   //[nElectron]
   UChar_t         Jet_cleanmask[nJet_];   //[nJet]
   UChar_t         Muon_cleanmask[nMuon_];   //[nMuon]
   UChar_t         Photon_cleanmask[nPhoton_];   //[nPhoton]
   UChar_t         Tau_cleanmask[nTau_];   //[nTau]
   Float_t         SV_chi2[13];   //[nSV]
   Float_t         SV_eta[13];   //[nSV]
   Float_t         SV_mass[13];   //[nSV]
   Float_t         SV_ndof[13];   //[nSV]
   Float_t         SV_phi[13];   //[nSV]
   Float_t         SV_pt[13];   //[nSV]
   Float_t         SV_x[13];   //[nSV]
   Float_t         SV_y[13];   //[nSV]
   Float_t         SV_z[13];   //[nSV]
   Int_t           Tau_genPartIdx[nTau_];   //[nTau]
   UChar_t         Tau_genPartFlav[nTau_];   //[nTau]
   Bool_t          L1simulation_step;
   Bool_t          HLTriggerFirstPath;
   Bool_t          HLT_AK8PFJet360_TrimMass30;
   Bool_t          HLT_AK8PFJet380_TrimMass30;
   Bool_t          HLT_AK8PFJet400_TrimMass30;
   Bool_t          HLT_AK8PFJet420_TrimMass30;
   Bool_t          HLT_AK8PFHT750_TrimMass50;
   Bool_t          HLT_AK8PFHT800_TrimMass50;
   Bool_t          HLT_AK8PFHT850_TrimMass50;
   Bool_t          HLT_AK8PFHT900_TrimMass50;
   Bool_t          HLT_CaloJet500_NoJetID;
   Bool_t          HLT_CaloJet550_NoJetID;
   Bool_t          HLT_Trimuon5_3p5_2_Upsilon_Muon;
   Bool_t          HLT_DoubleEle25_CaloIdL_MW;
   Bool_t          HLT_DoubleEle27_CaloIdL_MW;
   Bool_t          HLT_DoubleEle33_CaloIdL_MW;
   Bool_t          HLT_DoubleEle24_eta2p1_WPTight_Gsf;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;
   Bool_t          HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Ele27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu27_Ele37_CaloIdL_MW;
   Bool_t          HLT_Mu37_Ele27_CaloIdL_MW;
   Bool_t          HLT_Mu37_TkMu27;
   Bool_t          HLT_DoubleMu4_3_Bs;
   Bool_t          HLT_DoubleMu4_3_Jpsi_Displaced;
   Bool_t          HLT_DoubleMu4_JpsiTrk_Displaced;
   Bool_t          HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu;
   Bool_t          HLT_DoubleMu4_PsiPrimeTrk_Displaced;
   Bool_t          HLT_DoubleMu4_Mass8_DZ_PFHT350;
   Bool_t          HLT_DoubleMu8_Mass8_PFHT350;
   Bool_t          HLT_Mu3_PFJet40;
   Bool_t          HLT_Mu7p5_L2Mu2_Jpsi;
   Bool_t          HLT_Mu7p5_L2Mu2_Upsilon;
   Bool_t          HLT_Mu7p5_Track2_Jpsi;
   Bool_t          HLT_Mu7p5_Track3p5_Jpsi;
   Bool_t          HLT_Mu7p5_Track7_Jpsi;
   Bool_t          HLT_Mu7p5_Track2_Upsilon;
   Bool_t          HLT_Mu7p5_Track3p5_Upsilon;
   Bool_t          HLT_Mu7p5_Track7_Upsilon;
   Bool_t          HLT_DoublePhoton33_CaloIdL;
   Bool_t          HLT_DoublePhoton70;
   Bool_t          HLT_DoublePhoton85;
   Bool_t          HLT_Ele20_WPTight_Gsf;
   Bool_t          HLT_Ele20_WPLoose_Gsf;
   Bool_t          HLT_Ele20_eta2p1_WPLoose_Gsf;
   Bool_t          HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;
   Bool_t          HLT_Ele27_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf_L1EGMT;
   Bool_t          HLT_Ele38_WPTight_Gsf;
   Bool_t          HLT_Ele40_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf_L1DoubleEG;
   Bool_t          HLT_HT450_Beamspot;
   Bool_t          HLT_HT300_Beamspot;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1;
   Bool_t          HLT_IsoMu20;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu24_eta2p1;
   Bool_t          HLT_IsoMu27;
   Bool_t          HLT_IsoMu30;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX;
   Bool_t          HLT_UncorrectedJetE30_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE60_NoBPTX3BX;
   Bool_t          HLT_UncorrectedJetE70_NoBPTX3BX;
   Bool_t          HLT_L1SingleMu18;
   Bool_t          HLT_L1SingleMu25;
   Bool_t          HLT_L2Mu10;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX3BX;
   Bool_t          HLT_L2Mu10_NoVertex_NoBPTX;
   Bool_t          HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;
   Bool_t          HLT_L2Mu50;
   Bool_t          HLT_DoubleL2Mu50;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;
   Bool_t          HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;
   Bool_t          HLT_Mu25_TkMu0_Onia;
   Bool_t          HLT_Mu30_TkMu0_Onia;
   Bool_t          HLT_Mu20_TkMu0_Phi;
   Bool_t          HLT_Mu25_TkMu0_Phi;
   Bool_t          HLT_Mu20;
   Bool_t          HLT_Mu27;
   Bool_t          HLT_Mu50;
   Bool_t          HLT_Mu55;
   Bool_t          HLT_OldMu100;
   Bool_t          HLT_TkMu100;
   Bool_t          HLT_DiPFJet15_NoCaloMatched;
   Bool_t          HLT_DiPFJet25_NoCaloMatched;
   Bool_t          HLT_DiPFJet15_FBEta3_NoCaloMatched;
   Bool_t          HLT_DiPFJet25_FBEta3_NoCaloMatched;
   Bool_t          HLT_DiPFJetAve40;
   Bool_t          HLT_DiPFJetAve60;
   Bool_t          HLT_DiPFJetAve80;
   Bool_t          HLT_DiPFJetAve140;
   Bool_t          HLT_DiPFJetAve200;
   Bool_t          HLT_DiPFJetAve260;
   Bool_t          HLT_DiPFJetAve320;
   Bool_t          HLT_DiPFJetAve400;
   Bool_t          HLT_DiPFJetAve500;
   Bool_t          HLT_DiPFJetAve15_HFJEC;
   Bool_t          HLT_DiPFJetAve25_HFJEC;
   Bool_t          HLT_DiPFJetAve35_HFJEC;
   Bool_t          HLT_DiPFJetAve60_HFJEC;
   Bool_t          HLT_DiPFJetAve80_HFJEC;
   Bool_t          HLT_DiPFJetAve100_HFJEC;
   Bool_t          HLT_DiPFJetAve160_HFJEC;
   Bool_t          HLT_DiPFJetAve220_HFJEC;
   Bool_t          HLT_DiPFJetAve300_HFJEC;
   Bool_t          HLT_AK8PFJet40;
   Bool_t          HLT_AK8PFJet60;
   Bool_t          HLT_AK8PFJet80;
   Bool_t          HLT_AK8PFJet140;
   Bool_t          HLT_AK8PFJet200;
   Bool_t          HLT_AK8PFJet260;
   Bool_t          HLT_AK8PFJet320;
   Bool_t          HLT_AK8PFJet400;
   Bool_t          HLT_AK8PFJet450;
   Bool_t          HLT_AK8PFJet500;
   Bool_t          HLT_AK8PFJet550;
   Bool_t          HLT_PFJet40;
   Bool_t          HLT_PFJet60;
   Bool_t          HLT_PFJet80;
   Bool_t          HLT_PFJet140;
   Bool_t          HLT_PFJet200;
   Bool_t          HLT_PFJet260;
   Bool_t          HLT_PFJet320;
   Bool_t          HLT_PFJet400;
   Bool_t          HLT_PFJet450;
   Bool_t          HLT_PFJet500;
   Bool_t          HLT_PFJet550;
   Bool_t          HLT_PFJetFwd40;
   Bool_t          HLT_PFJetFwd60;
   Bool_t          HLT_PFJetFwd80;
   Bool_t          HLT_PFJetFwd140;
   Bool_t          HLT_PFJetFwd200;
   Bool_t          HLT_PFJetFwd260;
   Bool_t          HLT_PFJetFwd320;
   Bool_t          HLT_PFJetFwd400;
   Bool_t          HLT_PFJetFwd450;
   Bool_t          HLT_PFJetFwd500;
   Bool_t          HLT_AK8PFJetFwd40;
   Bool_t          HLT_AK8PFJetFwd60;
   Bool_t          HLT_AK8PFJetFwd80;
   Bool_t          HLT_AK8PFJetFwd140;
   Bool_t          HLT_AK8PFJetFwd200;
   Bool_t          HLT_AK8PFJetFwd260;
   Bool_t          HLT_AK8PFJetFwd320;
   Bool_t          HLT_AK8PFJetFwd400;
   Bool_t          HLT_AK8PFJetFwd450;
   Bool_t          HLT_AK8PFJetFwd500;
   Bool_t          HLT_PFHT180;
   Bool_t          HLT_PFHT250;
   Bool_t          HLT_PFHT370;
   Bool_t          HLT_PFHT430;
   Bool_t          HLT_PFHT510;
   Bool_t          HLT_PFHT590;
   Bool_t          HLT_PFHT680;
   Bool_t          HLT_PFHT780;
   Bool_t          HLT_PFHT890;
   Bool_t          HLT_PFHT1050;
   Bool_t          HLT_PFHT500_PFMET100_PFMHT100_IDTight;
   Bool_t          HLT_PFHT500_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFHT700_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFHT700_PFMET95_PFMHT95_IDTight;
   Bool_t          HLT_PFHT800_PFMET75_PFMHT75_IDTight;
   Bool_t          HLT_PFHT800_PFMET85_PFMHT85_IDTight;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne110_PFMHT110_IDTight;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight;
   Bool_t          HLT_PFMETTypeOne130_PFMHT130_IDTight;
   Bool_t          HLT_PFMETTypeOne140_PFMHT140_IDTight;
   Bool_t          HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_L1ETMHadSeeds;
   Bool_t          HLT_CaloMHT90;
   Bool_t          HLT_CaloMET80_NotCleaned;
   Bool_t          HLT_CaloMET90_NotCleaned;
   Bool_t          HLT_CaloMET100_NotCleaned;
   Bool_t          HLT_CaloMET110_NotCleaned;
   Bool_t          HLT_CaloMET250_NotCleaned;
   Bool_t          HLT_CaloMET70_HBHECleaned;
   Bool_t          HLT_CaloMET80_HBHECleaned;
   Bool_t          HLT_CaloMET90_HBHECleaned;
   Bool_t          HLT_CaloMET100_HBHECleaned;
   Bool_t          HLT_CaloMET250_HBHECleaned;
   Bool_t          HLT_CaloMET300_HBHECleaned;
   Bool_t          HLT_CaloMET350_HBHECleaned;
   Bool_t          HLT_PFMET200_NotCleaned;
   Bool_t          HLT_PFMET200_HBHECleaned;
   Bool_t          HLT_PFMET250_HBHECleaned;
   Bool_t          HLT_PFMET300_HBHECleaned;
   Bool_t          HLT_PFMET200_HBHE_BeamHaloCleaned;
   Bool_t          HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned;
   Bool_t          HLT_MET105_IsoTrk50;
   Bool_t          HLT_MET120_IsoTrk50;
   Bool_t          HLT_SingleJet30_Mu12_SinglePFJet40;
   Bool_t          HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets40_CaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets100_CaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets200_CaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets350_CaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33;
   Bool_t          HLT_Photon300_NoHE;
   Bool_t          HLT_Mu8_TrkIsoVVL;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_Mu8_DiEle12_CaloIdL_TrackIdL;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;
   Bool_t          HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu17_TrkIsoVVL;
   Bool_t          HLT_Mu19_TrkIsoVVL;
   Bool_t          HLT_BTagMu_AK4DiJet20_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet40_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet70_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet110_Mu5;
   Bool_t          HLT_BTagMu_AK4DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK4Jet300_Mu5;
   Bool_t          HLT_BTagMu_AK8DiJet170_Mu5;
   Bool_t          HLT_BTagMu_AK8Jet300_Mu5;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;
   Bool_t          HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
   Bool_t          HLT_Mu12_DoublePhoton20;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2;
   Bool_t          HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;
   Bool_t          HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;
   Bool_t          HLT_Photon25;
   Bool_t          HLT_Photon33;
   Bool_t          HLT_Photon50;
   Bool_t          HLT_Photon75;
   Bool_t          HLT_Photon90;
   Bool_t          HLT_Photon120;
   Bool_t          HLT_Photon150;
   Bool_t          HLT_Photon175;
   Bool_t          HLT_Photon200;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon90_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon120_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon165_R9Id90_HE10_IsoM;
   Bool_t          HLT_Photon90_CaloIdL_PFHT700;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;
   Bool_t          HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
   Bool_t          HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
   Bool_t          HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
   Bool_t          HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
   Bool_t          HLT_Dimuon0_Jpsi_L1_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_NoOS;
   Bool_t          HLT_Dimuon0_Jpsi;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing;
   Bool_t          HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;
   Bool_t          HLT_Dimuon0_Jpsi3p5_Muon2;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5NoOS;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0;
   Bool_t          HLT_Dimuon0_Upsilon_L1_4p5er2p0M;
   Bool_t          HLT_Dimuon0_Upsilon_NoVertexing;
   Bool_t          HLT_Dimuon0_Upsilon_L1_5M;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5R;
   Bool_t          HLT_Dimuon0_LowMass_L1_0er1p5;
   Bool_t          HLT_Dimuon0_LowMass;
   Bool_t          HLT_Dimuon0_LowMass_L1_4;
   Bool_t          HLT_Dimuon0_LowMass_L1_4R;
   Bool_t          HLT_Dimuon0_LowMass_L1_TM530;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_L1_TM0;
   Bool_t          HLT_Dimuon0_Upsilon_Muon_NoL1Mass;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8to60_DZ;
   Bool_t          HLT_TripleMu_10_5_5_DZ;
   Bool_t          HLT_TripleMu_12_10_5;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;
   Bool_t          HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;
   Bool_t          HLT_DoubleMu3_DZ_PFMET50_PFMHT60;
   Bool_t          HLT_DoubleMu3_DZ_PFMET70_PFMHT70;
   Bool_t          HLT_DoubleMu3_DZ_PFMET90_PFMHT90;
   Bool_t          HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;
   Bool_t          HLT_DoubleMu4_Jpsi_Displaced;
   Bool_t          HLT_DoubleMu4_Jpsi_NoVertexing;
   Bool_t          HLT_DoubleMu4_JpsiTrkTrk_Displaced;
   Bool_t          HLT_DoubleMu43NoFiltersNoVtx;
   Bool_t          HLT_DoubleMu48NoFiltersNoVtx;
   Bool_t          HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;
   Bool_t          HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;
   Bool_t          HLT_HT425;
   Bool_t          HLT_HT430_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT430_DisplacedDijet60_DisplacedTrack;
   Bool_t          HLT_HT430_DisplacedDijet80_DisplacedTrack;
   Bool_t          HLT_HT400_DisplacedDijet40_DisplacedTrack;
   Bool_t          HLT_HT650_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT550_DisplacedDijet80_Inclusive;
   Bool_t          HLT_HT550_DisplacedDijet60_Inclusive;
   Bool_t          HLT_HT650_DisplacedDijet80_Inclusive;
   Bool_t          HLT_HT750_DisplacedDijet80_Inclusive;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET110;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET120;
   Bool_t          HLT_DiJet110_35_Mjj650_PFMET130;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET110;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET120;
   Bool_t          HLT_TripleJet110_35_35_Mjj650_PFMET130;
   Bool_t          HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg;
   Bool_t          HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg;
   Bool_t          HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg;
   Bool_t          HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;
   Bool_t          HLT_Ele28_eta2p1_WPTight_Gsf_HT150;
   Bool_t          HLT_Ele28_HighEta_SC20_Mass55;
   Bool_t          HLT_DoubleMu20_7_Mass0to30_Photon23;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele50_IsoVVVL_PFHT450;
   Bool_t          HLT_Ele15_IsoVVVL_PFHT600;
   Bool_t          HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;
   Bool_t          HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450_PFMET50;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu50_IsoVVVL_PFHT450;
   Bool_t          HLT_Mu15_IsoVVVL_PFHT600;
   Bool_t          HLT_Dimuon10_PsiPrime_Barrel_Seagulls;
   Bool_t          HLT_Dimuon20_Jpsi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon10_Upsilon_Barrel_Seagulls;
   Bool_t          HLT_Dimuon12_Upsilon_eta1p5;
   Bool_t          HLT_Dimuon14_Phi_Barrel_Seagulls;
   Bool_t          HLT_Dimuon18_PsiPrime;
   Bool_t          HLT_Dimuon25_Jpsi;
   Bool_t          HLT_Dimuon18_PsiPrime_noCorrL1;
   Bool_t          HLT_Dimuon24_Upsilon_noCorrL1;
   Bool_t          HLT_Dimuon24_Phi_noCorrL1;
   Bool_t          HLT_Dimuon25_Jpsi_noCorrL1;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;
   Bool_t          HLT_DiMu9_Ele9_CaloIdL_TrackIdL;
   Bool_t          HLT_DoubleIsoMu20_eta2p1;
   Bool_t          HLT_DoubleIsoMu24_eta2p1;
   Bool_t          HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;
   Bool_t          HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;
   Bool_t          HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;
   Bool_t          HLT_Mu8;
   Bool_t          HLT_Mu17;
   Bool_t          HLT_Mu19;
   Bool_t          HLT_Mu17_Photon30_IsoCaloId;
   Bool_t          HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
   Bool_t          HLT_Ele8_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele17_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele23_CaloIdM_TrackIdM_PFJet30;
   Bool_t          HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;
   Bool_t          HLT_Ele115_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele135_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele145_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele200_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele250_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_Ele300_CaloIdVT_GsfTrkIdT;
   Bool_t          HLT_PFHT300PT30_QuadPFJet_75_60_45_40;
   Bool_t          HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0;
   Bool_t          HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2;
   Bool_t          HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2;
   Bool_t          HLT_PFHT380_SixPFJet32;
   Bool_t          HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5;
   Bool_t          HLT_PFHT430_SixPFJet40;
   Bool_t          HLT_PFHT350;
   Bool_t          HLT_PFHT350MinPFJet15;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;
   Bool_t          HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;
   Bool_t          HLT_FullTrack_Multiplicity85;
   Bool_t          HLT_FullTrack_Multiplicity100;
   Bool_t          HLT_FullTrack_Multiplicity130;
   Bool_t          HLT_FullTrack_Multiplicity155;
   Bool_t          HLT_ECALHT800;
   Bool_t          HLT_DiSC30_18_EIso_AND_HE_Mass70;
   Bool_t          HLT_Physics;
   Bool_t          HLT_Physics_part0;
   Bool_t          HLT_Physics_part1;
   Bool_t          HLT_Physics_part2;
   Bool_t          HLT_Physics_part3;
   Bool_t          HLT_Physics_part4;
   Bool_t          HLT_Physics_part5;
   Bool_t          HLT_Physics_part6;
   Bool_t          HLT_Physics_part7;
   Bool_t          HLT_Random;
   Bool_t          HLT_ZeroBias;
   Bool_t          HLT_ZeroBias_part0;
   Bool_t          HLT_ZeroBias_part1;
   Bool_t          HLT_ZeroBias_part2;
   Bool_t          HLT_ZeroBias_part3;
   Bool_t          HLT_ZeroBias_part4;
   Bool_t          HLT_ZeroBias_part5;
   Bool_t          HLT_ZeroBias_part6;
   Bool_t          HLT_ZeroBias_part7;
   Bool_t          HLT_AK4CaloJet30;
   Bool_t          HLT_AK4CaloJet40;
   Bool_t          HLT_AK4CaloJet50;
   Bool_t          HLT_AK4CaloJet80;
   Bool_t          HLT_AK4CaloJet100;
   Bool_t          HLT_AK4CaloJet120;
   Bool_t          HLT_AK4PFJet30;
   Bool_t          HLT_AK4PFJet50;
   Bool_t          HLT_AK4PFJet80;
   Bool_t          HLT_AK4PFJet100;
   Bool_t          HLT_AK4PFJet120;
   Bool_t          HLT_HISinglePhoton10_Eta3p1ForPPRef;
   Bool_t          HLT_HISinglePhoton20_Eta3p1ForPPRef;
   Bool_t          HLT_HISinglePhoton30_Eta3p1ForPPRef;
   Bool_t          HLT_HISinglePhoton40_Eta3p1ForPPRef;
   Bool_t          HLT_HISinglePhoton50_Eta3p1ForPPRef;
   Bool_t          HLT_HISinglePhoton60_Eta3p1ForPPRef;
   Bool_t          HLT_Photon20_HoverELoose;
   Bool_t          HLT_Photon30_HoverELoose;
   Bool_t          HLT_Photon40_HoverELoose;
   Bool_t          HLT_Photon50_HoverELoose;
   Bool_t          HLT_Photon60_HoverELoose;
   Bool_t          HLT_EcalCalibration;
   Bool_t          HLT_HcalCalibration;
   Bool_t          HLT_L1UnpairedBunchBptxMinus;
   Bool_t          HLT_L1UnpairedBunchBptxPlus;
   Bool_t          HLT_L1NotBptxOR;
   Bool_t          HLT_L1MinimumBiasHF_OR;
   Bool_t          HLT_L1MinimumBiasHF0OR;
   Bool_t          HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;
   Bool_t          HLT_HcalNZS;
   Bool_t          HLT_HcalPhiSym;
   Bool_t          HLT_HcalIsolatedbunch;
   Bool_t          HLT_IsoTrackHB;
   Bool_t          HLT_IsoTrackHE;
   Bool_t          HLT_ZeroBias_FirstCollisionAfterAbortGap;
   Bool_t          HLT_ZeroBias_IsolatedBunches;
   Bool_t          HLT_ZeroBias_FirstCollisionInTrain;
   Bool_t          HLT_ZeroBias_LastCollisionInTrain;
   Bool_t          HLT_ZeroBias_FirstBXAfterTrain;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1;
   Bool_t          HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg;
   Bool_t          HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;
   Bool_t          HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;
   Bool_t          HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;
   Bool_t          HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;
   Bool_t          HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;
   Bool_t          HLT_Rsq0p35;
   Bool_t          HLT_Rsq0p40;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200;
   Bool_t          HLT_RsqMR300_Rsq0p09_MR200_4jet;
   Bool_t          HLT_RsqMR320_Rsq0p09_MR200_4jet;
   Bool_t          HLT_L1_DoubleJet30_Mass_Min400_Mu10;
   Bool_t          HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1;
   Bool_t          HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;
   Bool_t          HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_Mu18_Mu9_SameSign;
   Bool_t          HLT_Mu18_Mu9_SameSign_DZ;
   Bool_t          HLT_Mu18_Mu9;
   Bool_t          HLT_Mu18_Mu9_DZ;
   Bool_t          HLT_Mu20_Mu10_SameSign;
   Bool_t          HLT_Mu20_Mu10_SameSign_DZ;
   Bool_t          HLT_Mu20_Mu10;
   Bool_t          HLT_Mu20_Mu10_DZ;
   Bool_t          HLT_Mu23_Mu12_SameSign;
   Bool_t          HLT_Mu23_Mu12_SameSign_DZ;
   Bool_t          HLT_Mu23_Mu12;
   Bool_t          HLT_Mu23_Mu12_DZ;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi;
   Bool_t          HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;
   Bool_t          HLT_DoubleMu3_DCA_PFMET50_PFMHT60;
   Bool_t          HLT_TripleMu_5_3_3_Mass3p8to60_DCA;
   Bool_t          HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1;
   Bool_t          HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1;
   Bool_t          HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1;
   Bool_t          HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1;
   Bool_t          HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2;
   Bool_t          HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2;
   Bool_t          HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2;
   Bool_t          HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2;
   Bool_t          HLT_QuadPFJet98_83_71_15;
   Bool_t          HLT_QuadPFJet103_88_75_15;
   Bool_t          HLT_QuadPFJet105_88_76_15;
   Bool_t          HLT_QuadPFJet111_90_80_15;
   Bool_t          HLT_AK8PFJet330_PFAK8BTagCSV_p17;
   Bool_t          HLT_AK8PFJet330_PFAK8BTagCSV_p1;
   Bool_t          HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;
   Bool_t          HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;
   Bool_t          HLTriggerFinalPath;
   Bool_t          Flag_HBHENoiseFilter;
   Bool_t          Flag_HBHENoiseIsoFilter;
   Bool_t          Flag_CSCTightHaloFilter;
   Bool_t          Flag_CSCTightHaloTrkMuUnvetoFilter;
   Bool_t          Flag_CSCTightHalo2015Filter;
   Bool_t          Flag_globalTightHalo2016Filter;
   Bool_t          Flag_globalSuperTightHalo2016Filter;
   Bool_t          Flag_HcalStripHaloFilter;
   Bool_t          Flag_hcalLaserEventFilter;
   Bool_t          Flag_EcalDeadCellTriggerPrimitiveFilter;
   Bool_t          Flag_EcalDeadCellBoundaryEnergyFilter;
   Bool_t          Flag_ecalBadCalibFilter;
   Bool_t          Flag_goodVertices;
   Bool_t          Flag_eeBadScFilter;
   Bool_t          Flag_ecalLaserCorrFilter;
   Bool_t          Flag_trkPOGFilters;
   Bool_t          Flag_chargedHadronTrackResolutionFilter;
   Bool_t          Flag_muonBadTrackFilter;
   Bool_t          Flag_BadChargedCandidateFilter;
   Bool_t          Flag_BadPFMuonFilter;
   Bool_t          Flag_BadChargedCandidateSummer16Filter;
   Bool_t          Flag_BadPFMuonSummer16Filter;
   Bool_t          Flag_trkPOG_manystripclus53X;
   Bool_t          Flag_trkPOG_toomanystripclus53X;
   Bool_t          Flag_trkPOG_logErrorTooManyClusters;
   Bool_t          Flag_METFilters;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20;   //!
   TBranch        *b_CaloMET_phi;   //!
   TBranch        *b_CaloMET_pt;   //!
   TBranch        *b_CaloMET_sumEt;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_Electron_deltaEtaSC;   //!
   TBranch        *b_Electron_dr03EcalRecHitSumEt;   //!
   TBranch        *b_Electron_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_Electron_dr03TkSumPt;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dxyErr;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dzErr;   //!
   TBranch        *b_Electron_eCorr;   //!
   TBranch        *b_Electron_eInvMinusPInv;   //!
   TBranch        *b_Electron_energyErr;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_hoe;   //!
   TBranch        *b_Electron_ip3d;   //!
   TBranch        *b_Electron_mass;   //!
   TBranch        *b_Electron_miniPFRelIso_all;   //!
   TBranch        *b_Electron_miniPFRelIso_chg;   //!
   TBranch        *b_Electron_mvaFall17Iso;   //!
   TBranch        *b_Electron_mvaFall17noIso;   //!
   TBranch        *b_Electron_pfRelIso03_all;   //!
   TBranch        *b_Electron_pfRelIso03_chg;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_sieie;   //!
   TBranch        *b_Electron_sip3d;   //!
   TBranch        *b_Electron_mvaTTH;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_cutBased;   //!
   TBranch        *b_Electron_jetIdx;   //!
   TBranch        *b_Electron_pdgId;   //!
   TBranch        *b_Electron_photonIdx;   //!
   TBranch        *b_Electron_tightCharge;   //!
   TBranch        *b_Electron_vidNestedWPBitmap;   //!
   TBranch        *b_Electron_convVeto;   //!
   TBranch        *b_Electron_cutBased_HEEP;   //!
   TBranch        *b_Electron_isPFcand;   //!
   TBranch        *b_Electron_lostHits;   //!
   TBranch        *b_Electron_mvaFall17Iso_WP80;   //!
   TBranch        *b_Electron_mvaFall17Iso_WP90;   //!
   TBranch        *b_Electron_mvaFall17Iso_WPL;   //!
   TBranch        *b_Electron_mvaFall17noIso_WP80;   //!
   TBranch        *b_Electron_mvaFall17noIso_WP90;   //!
   TBranch        *b_Electron_mvaFall17noIso_WPL;   //!
   TBranch        *b_nFatJet;   //!
   TBranch        *b_FatJet_area;   //!
   TBranch        *b_FatJet_btagCMVA;   //!
   TBranch        *b_FatJet_btagCSVV2;   //!
   TBranch        *b_FatJet_btagDeepB;   //!
   TBranch        *b_FatJet_btagHbb;   //!
   TBranch        *b_FatJet_eta;   //!
   TBranch        *b_FatJet_mass;   //!
   TBranch        *b_FatJet_msoftdrop;   //!
   TBranch        *b_FatJet_n2b1;   //!
   TBranch        *b_FatJet_n3b1;   //!
   TBranch        *b_FatJet_phi;   //!
   TBranch        *b_FatJet_pt;   //!
   TBranch        *b_FatJet_tau1;   //!
   TBranch        *b_FatJet_tau2;   //!
   TBranch        *b_FatJet_tau3;   //!
   TBranch        *b_FatJet_tau4;   //!
   TBranch        *b_FatJet_jetId;   //!
   TBranch        *b_FatJet_subJetIdx1;   //!
   TBranch        *b_FatJet_subJetIdx2;   //!
   TBranch        *b_nGenJetAK8;   //!
   TBranch        *b_GenJetAK8_eta;   //!
   TBranch        *b_GenJetAK8_mass;   //!
   TBranch        *b_GenJetAK8_phi;   //!
   TBranch        *b_GenJetAK8_pt;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_GenJet_eta;   //!
   TBranch        *b_GenJet_mass;   //!
   TBranch        *b_GenJet_phi;   //!
   TBranch        *b_GenJet_pt;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_genPartIdxMother;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!
   TBranch        *b_GenPart_statusFlags;   //!
   TBranch        *b_nSubGenJetAK8;   //!
   TBranch        *b_SubGenJetAK8_eta;   //!
   TBranch        *b_SubGenJetAK8_mass;   //!
   TBranch        *b_SubGenJetAK8_phi;   //!
   TBranch        *b_SubGenJetAK8_pt;   //!
   TBranch        *b_Generator_binvar;   //!
   TBranch        *b_Generator_scalePDF;   //!
   TBranch        *b_Generator_weight;   //!
   TBranch        *b_Generator_x1;   //!
   TBranch        *b_Generator_x2;   //!
   TBranch        *b_Generator_xpdf1;   //!
   TBranch        *b_Generator_xpdf2;   //!
   TBranch        *b_Generator_id1;   //!
   TBranch        *b_Generator_id2;   //!
   TBranch        *b_nGenVisTau;   //!
   TBranch        *b_GenVisTau_eta;   //!
   TBranch        *b_GenVisTau_mass;   //!
   TBranch        *b_GenVisTau_phi;   //!
   TBranch        *b_GenVisTau_pt;   //!
   TBranch        *b_GenVisTau_charge;   //!
   TBranch        *b_GenVisTau_genPartIdxMother;   //!
   TBranch        *b_GenVisTau_status;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_LHEWeight_originalXWGTUP;   //!
   TBranch        *b_nLHEPdfWeight;   //!
   TBranch        *b_LHEPdfWeight;   //!
   TBranch        *b_nLHEScaleWeight;   //!
   TBranch        *b_LHEScaleWeight;   //!
   TBranch        *b_nIsoTrack;   //!
   TBranch        *b_IsoTrack_dxy;   //!
   TBranch        *b_IsoTrack_dz;   //!
   TBranch        *b_IsoTrack_eta;   //!
   TBranch        *b_IsoTrack_pfRelIso03_all;   //!
   TBranch        *b_IsoTrack_pfRelIso03_chg;   //!
   TBranch        *b_IsoTrack_phi;   //!
   TBranch        *b_IsoTrack_pt;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_all;   //!
   TBranch        *b_IsoTrack_miniPFRelIso_chg;   //!
   TBranch        *b_IsoTrack_pdgId;   //!
   TBranch        *b_IsoTrack_isHighPurityTrack;   //!
   TBranch        *b_IsoTrack_isPFcand;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_btagCMVA;   //!
   TBranch        *b_Jet_btagCSVV2;   //!
   TBranch        *b_Jet_btagDeepB;   //!
   TBranch        *b_Jet_btagDeepC;   //!
   TBranch        *b_Jet_btagDeepFlavB;   //!
   TBranch        *b_Jet_chEmEF;   //!
   TBranch        *b_Jet_chHEF;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_neEmEF;   //!
   TBranch        *b_Jet_neHEF;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_qgl;   //!
   TBranch        *b_Jet_rawFactor;   //!
   TBranch        *b_Jet_bReg;   //!
   TBranch        *b_Jet_electronIdx1;   //!
   TBranch        *b_Jet_electronIdx2;   //!
   TBranch        *b_Jet_jetId;   //!
   TBranch        *b_Jet_muonIdx1;   //!
   TBranch        *b_Jet_muonIdx2;   //!
   TBranch        *b_Jet_nConstituents;   //!
   TBranch        *b_Jet_nElectrons;   //!
   TBranch        *b_Jet_nMuons;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_LHE_HT;   //!
   TBranch        *b_LHE_HTIncoming;   //!
   TBranch        *b_LHE_Vpt;   //!
   TBranch        *b_LHE_Njets;   //!
   TBranch        *b_LHE_Nb;   //!
   TBranch        *b_LHE_Nc;   //!
   TBranch        *b_LHE_Nuds;   //!
   TBranch        *b_LHE_Nglu;   //!
   TBranch        *b_LHE_NpNLO;   //!
   TBranch        *b_LHE_NpLO;   //!
   TBranch        *b_nLHEPart;   //!
   TBranch        *b_LHEPart_pt;   //!
   TBranch        *b_LHEPart_eta;   //!
   TBranch        *b_LHEPart_phi;   //!
   TBranch        *b_LHEPart_mass;   //!
   TBranch        *b_LHEPart_pdgId;   //!
   TBranch        *b_GenMET_phi;   //!
   TBranch        *b_GenMET_pt;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaX;   //!
   TBranch        *b_MET_MetUnclustEnUpDeltaY;   //!
   TBranch        *b_MET_covXX;   //!
   TBranch        *b_MET_covXY;   //!
   TBranch        *b_MET_covYY;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_significance;   //!
   TBranch        *b_MET_sumEt;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_ip3d;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_miniPFRelIso_all;   //!
   TBranch        *b_Muon_miniPFRelIso_chg;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso03_chg;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_ptErr;   //!
   TBranch        *b_Muon_segmentComp;   //!
   TBranch        *b_Muon_sip3d;   //!
   TBranch        *b_Muon_mvaTTH;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_nStations;   //!
   TBranch        *b_Muon_nTrackerLayers;   //!
   TBranch        *b_Muon_pdgId;   //!
   TBranch        *b_Muon_tightCharge;   //!
   TBranch        *b_Muon_highPtId;   //!
   TBranch        *b_Muon_isPFcand;   //!
   TBranch        *b_Muon_mediumId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_nPhoton;   //!
   TBranch        *b_Photon_eCorr;   //!
   TBranch        *b_Photon_energyErr;   //!
   TBranch        *b_Photon_eta;   //!
   TBranch        *b_Photon_hoe;   //!
   TBranch        *b_Photon_mass;   //!
   TBranch        *b_Photon_mvaID;   //!
   TBranch        *b_Photon_pfRelIso03_all;   //!
   TBranch        *b_Photon_pfRelIso03_chg;   //!
   TBranch        *b_Photon_phi;   //!
   TBranch        *b_Photon_pt;   //!
   TBranch        *b_Photon_r9;   //!
   TBranch        *b_Photon_sieie;   //!
   TBranch        *b_Photon_charge;   //!
   TBranch        *b_Photon_cutBasedBitmap;   //!
   TBranch        *b_Photon_electronIdx;   //!
   TBranch        *b_Photon_jetIdx;   //!
   TBranch        *b_Photon_pdgId;   //!
   TBranch        *b_Photon_vidNestedWPBitmap;   //!
   TBranch        *b_Photon_electronVeto;   //!
   TBranch        *b_Photon_isScEtaEB;   //!
   TBranch        *b_Photon_isScEtaEE;   //!
   TBranch        *b_Photon_mvaID_WP80;   //!
   TBranch        *b_Photon_mvaID_WP90;   //!
   TBranch        *b_Photon_pixelSeed;   //!
   TBranch        *b_Pileup_nTrueInt;   //!
   TBranch        *b_Pileup_nPU;   //!
   TBranch        *b_Pileup_sumEOOT;   //!
   TBranch        *b_Pileup_sumLOOT;   //!
   TBranch        *b_PuppiMET_phi;   //!
   TBranch        *b_PuppiMET_pt;   //!
   TBranch        *b_PuppiMET_sumEt;   //!
   TBranch        *b_RawMET_phi;   //!
   TBranch        *b_RawMET_pt;   //!
   TBranch        *b_RawMET_sumEt;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_fixedGridRhoFastjetCentralCalo;   //!
   TBranch        *b_fixedGridRhoFastjetCentralNeutral;   //!
   TBranch        *b_nGenDressedLepton;   //!
   TBranch        *b_GenDressedLepton_eta;   //!
   TBranch        *b_GenDressedLepton_mass;   //!
   TBranch        *b_GenDressedLepton_phi;   //!
   TBranch        *b_GenDressedLepton_pt;   //!
   TBranch        *b_GenDressedLepton_pdgId;   //!
   TBranch        *b_nSoftActivityJet;   //!
   TBranch        *b_SoftActivityJet_eta;   //!
   TBranch        *b_SoftActivityJet_phi;   //!
   TBranch        *b_SoftActivityJet_pt;   //!
   TBranch        *b_SoftActivityJetHT;   //!
   TBranch        *b_SoftActivityJetHT10;   //!
   TBranch        *b_SoftActivityJetHT2;   //!
   TBranch        *b_SoftActivityJetHT5;   //!
   TBranch        *b_SoftActivityJetNjets10;   //!
   TBranch        *b_SoftActivityJetNjets2;   //!
   TBranch        *b_SoftActivityJetNjets5;   //!
   TBranch        *b_nSubJet;   //!
   TBranch        *b_SubJet_btagCMVA;   //!
   TBranch        *b_SubJet_btagCSVV2;   //!
   TBranch        *b_SubJet_btagDeepB;   //!
   TBranch        *b_SubJet_eta;   //!
   TBranch        *b_SubJet_mass;   //!
   TBranch        *b_SubJet_n2b1;   //!
   TBranch        *b_SubJet_n3b1;   //!
   TBranch        *b_SubJet_phi;   //!
   TBranch        *b_SubJet_pt;   //!
   TBranch        *b_SubJet_tau1;   //!
   TBranch        *b_SubJet_tau2;   //!
   TBranch        *b_SubJet_tau3;   //!
   TBranch        *b_SubJet_tau4;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_Tau_chargedIso;   //!
   TBranch        *b_Tau_dxy;   //!
   TBranch        *b_Tau_dz;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_leadTkDeltaEta;   //!
   TBranch        *b_Tau_leadTkDeltaPhi;   //!
   TBranch        *b_Tau_leadTkPtOverTauPt;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_neutralIso;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_photonsOutsideSignalCone;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_puCorr;   //!
   TBranch        *b_Tau_rawAntiEle;   //!
   TBranch        *b_Tau_rawIso;   //!
   TBranch        *b_Tau_rawIsodR03;   //!
   TBranch        *b_Tau_rawMVAnewDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDM;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v1;   //!
   TBranch        *b_Tau_rawMVAoldDM2017v2;   //!
   TBranch        *b_Tau_rawMVAoldDMdR032017v2;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_decayMode;   //!
   TBranch        *b_Tau_jetIdx;   //!
   TBranch        *b_Tau_rawAntiEleCat;   //!
   TBranch        *b_Tau_idAntiEle;   //!
   TBranch        *b_Tau_idAntiMu;   //!
   TBranch        *b_Tau_idDecayMode;   //!
   TBranch        *b_Tau_idDecayModeNewDMs;   //!
   TBranch        *b_Tau_idMVAnewDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDM;   //!
   TBranch        *b_Tau_idMVAoldDM2017v1;   //!
   TBranch        *b_Tau_idMVAoldDM2017v2;   //!
   TBranch        *b_Tau_idMVAoldDMdR032017v2;   //!
   TBranch        *b_Tau_relIso_all;         //!
   TBranch        *b_Tau_idIsoRaw;   //!
   TBranch        *b_Tau_idIsoVLoose;   //!
   TBranch        *b_Tau_idIsoLoose;   //!
   TBranch        *b_Tau_idIsoMedium;   //!
   TBranch        *b_Tau_idIsoTight;   //!
   TBranch        *b_Tau_idAntiEleLoose;   //!
   TBranch        *b_Tau_idAntiEleMedium;   //!
   TBranch        *b_Tau_idAntiEleTight;   //!
   TBranch        *b_Tau_idAntiMuLoose;   //!
   TBranch        *b_Tau_idAntiMuMedium;   //!
   TBranch        *b_Tau_idAntiMuTight;   //!

   TBranch        *b_TkMET_phi;   //!
   TBranch        *b_TkMET_pt;   //!
   TBranch        *b_TkMET_sumEt;   //!
   TBranch        *b_nTrigObj;   //!
   TBranch        *b_TrigObj_pt;   //!
   TBranch        *b_TrigObj_eta;   //!
   TBranch        *b_TrigObj_phi;   //!
   TBranch        *b_TrigObj_l1pt;   //!
   TBranch        *b_TrigObj_l1pt_2;   //!
   TBranch        *b_TrigObj_l2pt;   //!
   TBranch        *b_TrigObj_id;   //!
   TBranch        *b_TrigObj_l1iso;   //!
   TBranch        *b_TrigObj_l1charge;   //!
   TBranch        *b_TrigObj_filterBits;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_nOtherPV;   //!
   TBranch        *b_OtherPV_z;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_score;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_dlen;   //!
   TBranch        *b_SV_dlenSig;   //!
   TBranch        *b_SV_pAngle;   //!
   TBranch        *b_Electron_genPartIdx;   //!
   TBranch        *b_Electron_genPartFlav;   //!
   TBranch        *b_GenJetAK8_partonFlavour;   //!
   TBranch        *b_GenJetAK8_hadronFlavour;   //!
   TBranch        *b_GenJet_partonFlavour;   //!
   TBranch        *b_GenJet_hadronFlavour;   //!
   TBranch        *b_Jet_genJetIdx;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_Muon_genPartFlav;   //!
   TBranch        *b_Photon_genPartIdx;   //!
   TBranch        *b_Photon_genPartFlav;   //!
   TBranch        *b_MET_fiducialGenPhi;   //!
   TBranch        *b_MET_fiducialGenPt;   //!
   TBranch        *b_Electron_cleanmask;   //!
   TBranch        *b_Jet_cleanmask;   //!
   TBranch        *b_Muon_cleanmask;   //!
   TBranch        *b_Photon_cleanmask;   //!
   TBranch        *b_Tau_cleanmask;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_eta;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_ndof;   //!
   TBranch        *b_SV_phi;   //!
   TBranch        *b_SV_pt;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_Tau_genPartIdx;   //!
   TBranch        *b_Tau_genPartFlav;   //!
   TBranch        *b_L1simulation_step;   //!
   TBranch        *b_HLTriggerFirstPath;   //!
   TBranch        *b_HLT_AK8PFJet360_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet380_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet400_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFJet420_TrimMass30;   //!
   TBranch        *b_HLT_AK8PFHT750_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT800_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT850_TrimMass50;   //!
   TBranch        *b_HLT_AK8PFHT900_TrimMass50;   //!
   TBranch        *b_HLT_CaloJet500_NoJetID;   //!
   TBranch        *b_HLT_CaloJet550_NoJetID;   //!
   TBranch        *b_HLT_Trimuon5_3p5_2_Upsilon_Muon;   //!
   TBranch        *b_HLT_DoubleEle25_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle27_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle33_CaloIdL_MW;   //!
   TBranch        *b_HLT_DoubleEle24_eta2p1_WPTight_Gsf;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350;   //!
   TBranch        *b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Ele27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu27_Ele37_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_Ele27_CaloIdL_MW;   //!
   TBranch        *b_HLT_Mu37_TkMu27;   //!
   TBranch        *b_HLT_DoubleMu4_3_Bs;   //!
   TBranch        *b_HLT_DoubleMu4_3_Jpsi_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu;   //!
   TBranch        *b_HLT_DoubleMu4_PsiPrimeTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Mass8_DZ_PFHT350;   //!
   TBranch        *b_HLT_DoubleMu8_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Mu3_PFJet40;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_L2Mu2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Jpsi;   //!
   TBranch        *b_HLT_Mu7p5_Track2_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track3p5_Upsilon;   //!
   TBranch        *b_HLT_Mu7p5_Track7_Upsilon;   //!
   TBranch        *b_HLT_DoublePhoton33_CaloIdL;   //!
   TBranch        *b_HLT_DoublePhoton70;   //!
   TBranch        *b_HLT_DoublePhoton85;   //!
   TBranch        *b_HLT_Ele20_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele20_WPLoose_Gsf;   //!
   TBranch        *b_HLT_Ele20_eta2p1_WPLoose_Gsf;   //!
   TBranch        *b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG;   //!
   TBranch        *b_HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf_L1EGMT;   //!
   TBranch        *b_HLT_Ele38_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele40_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf_L1DoubleEG;   //!
   TBranch        *b_HLT_HT450_Beamspot;   //!
   TBranch        *b_HLT_HT300_Beamspot;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1;   //!
   TBranch        *b_HLT_IsoMu20;   //!
   TBranch        *b_HLT_IsoMu24;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1;   //!
   TBranch        *b_HLT_IsoMu27;   //!
   TBranch        *b_HLT_IsoMu30;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX;   //!
   TBranch        *b_HLT_UncorrectedJetE30_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE60_NoBPTX3BX;   //!
   TBranch        *b_HLT_UncorrectedJetE70_NoBPTX3BX;   //!
   TBranch        *b_HLT_L1SingleMu18;   //!
   TBranch        *b_HLT_L1SingleMu25;   //!
   TBranch        *b_HLT_L2Mu10;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu10_NoVertex_NoBPTX;   //!
   TBranch        *b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;   //!
   TBranch        *b_HLT_L2Mu50;   //!
   TBranch        *b_HLT_DoubleL2Mu50;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Onia;   //!
   TBranch        *b_HLT_Mu30_TkMu0_Onia;   //!
   TBranch        *b_HLT_Mu20_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu25_TkMu0_Phi;   //!
   TBranch        *b_HLT_Mu20;   //!
   TBranch        *b_HLT_Mu27;   //!
   TBranch        *b_HLT_Mu50;   //!
   TBranch        *b_HLT_Mu55;   //!
   TBranch        *b_HLT_OldMu100;   //!
   TBranch        *b_HLT_TkMu100;   //!
   TBranch        *b_HLT_DiPFJet15_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet25_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet15_FBEta3_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJet25_FBEta3_NoCaloMatched;   //!
   TBranch        *b_HLT_DiPFJetAve40;   //!
   TBranch        *b_HLT_DiPFJetAve60;   //!
   TBranch        *b_HLT_DiPFJetAve80;   //!
   TBranch        *b_HLT_DiPFJetAve140;   //!
   TBranch        *b_HLT_DiPFJetAve200;   //!
   TBranch        *b_HLT_DiPFJetAve260;   //!
   TBranch        *b_HLT_DiPFJetAve320;   //!
   TBranch        *b_HLT_DiPFJetAve400;   //!
   TBranch        *b_HLT_DiPFJetAve500;   //!
   TBranch        *b_HLT_DiPFJetAve15_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve25_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve35_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve60_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve80_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve100_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve160_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve220_HFJEC;   //!
   TBranch        *b_HLT_DiPFJetAve300_HFJEC;   //!
   TBranch        *b_HLT_AK8PFJet40;   //!
   TBranch        *b_HLT_AK8PFJet60;   //!
   TBranch        *b_HLT_AK8PFJet80;   //!
   TBranch        *b_HLT_AK8PFJet140;   //!
   TBranch        *b_HLT_AK8PFJet200;   //!
   TBranch        *b_HLT_AK8PFJet260;   //!
   TBranch        *b_HLT_AK8PFJet320;   //!
   TBranch        *b_HLT_AK8PFJet400;   //!
   TBranch        *b_HLT_AK8PFJet450;   //!
   TBranch        *b_HLT_AK8PFJet500;   //!
   TBranch        *b_HLT_AK8PFJet550;   //!
   TBranch        *b_HLT_PFJet40;   //!
   TBranch        *b_HLT_PFJet60;   //!
   TBranch        *b_HLT_PFJet80;   //!
   TBranch        *b_HLT_PFJet140;   //!
   TBranch        *b_HLT_PFJet200;   //!
   TBranch        *b_HLT_PFJet260;   //!
   TBranch        *b_HLT_PFJet320;   //!
   TBranch        *b_HLT_PFJet400;   //!
   TBranch        *b_HLT_PFJet450;   //!
   TBranch        *b_HLT_PFJet500;   //!
   TBranch        *b_HLT_PFJet550;   //!
   TBranch        *b_HLT_PFJetFwd40;   //!
   TBranch        *b_HLT_PFJetFwd60;   //!
   TBranch        *b_HLT_PFJetFwd80;   //!
   TBranch        *b_HLT_PFJetFwd140;   //!
   TBranch        *b_HLT_PFJetFwd200;   //!
   TBranch        *b_HLT_PFJetFwd260;   //!
   TBranch        *b_HLT_PFJetFwd320;   //!
   TBranch        *b_HLT_PFJetFwd400;   //!
   TBranch        *b_HLT_PFJetFwd450;   //!
   TBranch        *b_HLT_PFJetFwd500;   //!
   TBranch        *b_HLT_AK8PFJetFwd40;   //!
   TBranch        *b_HLT_AK8PFJetFwd60;   //!
   TBranch        *b_HLT_AK8PFJetFwd80;   //!
   TBranch        *b_HLT_AK8PFJetFwd140;   //!
   TBranch        *b_HLT_AK8PFJetFwd200;   //!
   TBranch        *b_HLT_AK8PFJetFwd260;   //!
   TBranch        *b_HLT_AK8PFJetFwd320;   //!
   TBranch        *b_HLT_AK8PFJetFwd400;   //!
   TBranch        *b_HLT_AK8PFJetFwd450;   //!
   TBranch        *b_HLT_AK8PFJetFwd500;   //!
   TBranch        *b_HLT_PFHT180;   //!
   TBranch        *b_HLT_PFHT250;   //!
   TBranch        *b_HLT_PFHT370;   //!
   TBranch        *b_HLT_PFHT430;   //!
   TBranch        *b_HLT_PFHT510;   //!
   TBranch        *b_HLT_PFHT590;   //!
   TBranch        *b_HLT_PFHT680;   //!
   TBranch        *b_HLT_PFHT780;   //!
   TBranch        *b_HLT_PFHT890;   //!
   TBranch        *b_HLT_PFHT1050;   //!
   TBranch        *b_HLT_PFHT500_PFMET100_PFMHT100_IDTight;   //!
   TBranch        *b_HLT_PFHT500_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFHT700_PFMET95_PFMHT95_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET75_PFMHT75_IDTight;   //!
   TBranch        *b_HLT_PFHT800_PFMET85_PFMHT85_IDTight;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_L1ETMHadSeeds;   //!
   TBranch        *b_HLT_CaloMHT90;   //!
   TBranch        *b_HLT_CaloMET80_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET90_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET100_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET110_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET250_NotCleaned;   //!
   TBranch        *b_HLT_CaloMET70_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET80_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET90_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET100_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET250_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET300_HBHECleaned;   //!
   TBranch        *b_HLT_CaloMET350_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET200_NotCleaned;   //!
   TBranch        *b_HLT_PFMET200_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET250_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET300_HBHECleaned;   //!
   TBranch        *b_HLT_PFMET200_HBHE_BeamHaloCleaned;   //!
   TBranch        *b_HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned;   //!
   TBranch        *b_HLT_MET105_IsoTrk50;   //!
   TBranch        *b_HLT_MET120_IsoTrk50;   //!
   TBranch        *b_HLT_SingleJet30_Mu12_SinglePFJet40;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets40_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets100_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets200_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets350_CaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33;   //!
   TBranch        *b_HLT_Photon300_NoHE;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ;   //!
   TBranch        *b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu17_TrkIsoVVL;   //!
   TBranch        *b_HLT_Mu19_TrkIsoVVL;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet20_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet40_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet70_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet110_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK4Jet300_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8DiJet170_Mu5;   //!
   TBranch        *b_HLT_BTagMu_AK8Jet300_Mu5;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL;   //!
   TBranch        *b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;   //!
   TBranch        *b_HLT_Mu12_DoublePhoton20;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2;   //!
   TBranch        *b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL;   //!
   TBranch        *b_HLT_Photon25;   //!
   TBranch        *b_HLT_Photon33;   //!
   TBranch        *b_HLT_Photon50;   //!
   TBranch        *b_HLT_Photon75;   //!
   TBranch        *b_HLT_Photon90;   //!
   TBranch        *b_HLT_Photon120;   //!
   TBranch        *b_HLT_Photon150;   //!
   TBranch        *b_HLT_Photon175;   //!
   TBranch        *b_HLT_Photon200;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon90_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon120_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon165_R9Id90_HE10_IsoM;   //!
   TBranch        *b_HLT_Photon90_CaloIdL_PFHT700;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90;   //!
   TBranch        *b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_Jpsi3p5_Muon2;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5NoOS;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_NoVertexing;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_L1_5M;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_0er1p5;   //!
   TBranch        *b_HLT_Dimuon0_LowMass;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_4R;   //!
   TBranch        *b_HLT_Dimuon0_LowMass_L1_TM530;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_L1_TM0;   //!
   TBranch        *b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8to60_DZ;   //!
   TBranch        *b_HLT_TripleMu_10_5_5_DZ;   //!
   TBranch        *b_HLT_TripleMu_12_10_5;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15;   //!
   TBranch        *b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70;   //!
   TBranch        *b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90;   //!
   TBranch        *b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_Displaced;   //!
   TBranch        *b_HLT_DoubleMu4_Jpsi_NoVertexing;   //!
   TBranch        *b_HLT_DoubleMu4_JpsiTrkTrk_Displaced;   //!
   TBranch        *b_HLT_DoubleMu43NoFiltersNoVtx;   //!
   TBranch        *b_HLT_DoubleMu48NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL;   //!
   TBranch        *b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG;   //!
   TBranch        *b_HLT_HT425;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet60_DisplacedTrack;   //!
   TBranch        *b_HLT_HT430_DisplacedDijet80_DisplacedTrack;   //!
   TBranch        *b_HLT_HT400_DisplacedDijet40_DisplacedTrack;   //!
   TBranch        *b_HLT_HT650_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_HT550_DisplacedDijet80_Inclusive;   //!
   TBranch        *b_HLT_HT550_DisplacedDijet60_Inclusive;   //!
   TBranch        *b_HLT_HT650_DisplacedDijet80_Inclusive;   //!
   TBranch        *b_HLT_HT750_DisplacedDijet80_Inclusive;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_DiJet110_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET110;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET120;   //!
   TBranch        *b_HLT_TripleJet110_35_35_Mjj650_PFMET130;   //!
   TBranch        *b_HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned;   //!
   TBranch        *b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150;   //!
   TBranch        *b_HLT_Ele28_HighEta_SC20_Mass55;   //!
   TBranch        *b_HLT_DoubleMu20_7_Mass0to30_Photon23;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Ele15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu50_IsoVVVL_PFHT450;   //!
   TBranch        *b_HLT_Mu15_IsoVVVL_PFHT600;   //!
   TBranch        *b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon20_Jpsi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon10_Upsilon_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon12_Upsilon_eta1p5;   //!
   TBranch        *b_HLT_Dimuon14_Phi_Barrel_Seagulls;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi;   //!
   TBranch        *b_HLT_Dimuon18_PsiPrime_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Upsilon_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon24_Phi_noCorrL1;   //!
   TBranch        *b_HLT_Dimuon25_Jpsi_noCorrL1;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ;   //!
   TBranch        *b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_DoubleIsoMu20_eta2p1;   //!
   TBranch        *b_HLT_DoubleIsoMu24_eta2p1;   //!
   TBranch        *b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx;   //!
   TBranch        *b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx;   //!
   TBranch        *b_HLT_Mu8;   //!
   TBranch        *b_HLT_Mu17;   //!
   TBranch        *b_HLT_Mu19;   //!
   TBranch        *b_HLT_Mu17_Photon30_IsoCaloId;   //!
   TBranch        *b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;   //!
   TBranch        *b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30;   //!
   TBranch        *b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165;   //!
   TBranch        *b_HLT_Ele115_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele135_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele145_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele200_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele250_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_Ele300_CaloIdVT_GsfTrkIdT;   //!
   TBranch        *b_HLT_PFHT300PT30_QuadPFJet_75_60_45_40;   //!
   TBranch        *b_HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0;   //!
   TBranch        *b_HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2;   //!
   TBranch        *b_HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2;   //!
   TBranch        *b_HLT_PFHT380_SixPFJet32;   //!
   TBranch        *b_HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5;   //!
   TBranch        *b_HLT_PFHT430_SixPFJet40;   //!
   TBranch        *b_HLT_PFHT350;   //!
   TBranch        *b_HLT_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL;   //!
   TBranch        *b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15;   //!
   TBranch        *b_HLT_FullTrack_Multiplicity85;   //!
   TBranch        *b_HLT_FullTrack_Multiplicity100;   //!
   TBranch        *b_HLT_FullTrack_Multiplicity130;   //!
   TBranch        *b_HLT_FullTrack_Multiplicity155;   //!
   TBranch        *b_HLT_ECALHT800;   //!
   TBranch        *b_HLT_DiSC30_18_EIso_AND_HE_Mass70;   //!
   TBranch        *b_HLT_Physics;   //!
   TBranch        *b_HLT_Physics_part0;   //!
   TBranch        *b_HLT_Physics_part1;   //!
   TBranch        *b_HLT_Physics_part2;   //!
   TBranch        *b_HLT_Physics_part3;   //!
   TBranch        *b_HLT_Physics_part4;   //!
   TBranch        *b_HLT_Physics_part5;   //!
   TBranch        *b_HLT_Physics_part6;   //!
   TBranch        *b_HLT_Physics_part7;   //!
   TBranch        *b_HLT_Random;   //!
   TBranch        *b_HLT_ZeroBias;   //!
   TBranch        *b_HLT_ZeroBias_part0;   //!
   TBranch        *b_HLT_ZeroBias_part1;   //!
   TBranch        *b_HLT_ZeroBias_part2;   //!
   TBranch        *b_HLT_ZeroBias_part3;   //!
   TBranch        *b_HLT_ZeroBias_part4;   //!
   TBranch        *b_HLT_ZeroBias_part5;   //!
   TBranch        *b_HLT_ZeroBias_part6;   //!
   TBranch        *b_HLT_ZeroBias_part7;   //!
   TBranch        *b_HLT_AK4CaloJet30;   //!
   TBranch        *b_HLT_AK4CaloJet40;   //!
   TBranch        *b_HLT_AK4CaloJet50;   //!
   TBranch        *b_HLT_AK4CaloJet80;   //!
   TBranch        *b_HLT_AK4CaloJet100;   //!
   TBranch        *b_HLT_AK4CaloJet120;   //!
   TBranch        *b_HLT_AK4PFJet30;   //!
   TBranch        *b_HLT_AK4PFJet50;   //!
   TBranch        *b_HLT_AK4PFJet80;   //!
   TBranch        *b_HLT_AK4PFJet100;   //!
   TBranch        *b_HLT_AK4PFJet120;   //!
   TBranch        *b_HLT_HISinglePhoton10_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_HISinglePhoton20_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_HISinglePhoton30_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_HISinglePhoton40_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_HISinglePhoton50_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_HISinglePhoton60_Eta3p1ForPPRef;   //!
   TBranch        *b_HLT_Photon20_HoverELoose;   //!
   TBranch        *b_HLT_Photon30_HoverELoose;   //!
   TBranch        *b_HLT_Photon40_HoverELoose;   //!
   TBranch        *b_HLT_Photon50_HoverELoose;   //!
   TBranch        *b_HLT_Photon60_HoverELoose;   //!
   TBranch        *b_HLT_EcalCalibration;   //!
   TBranch        *b_HLT_HcalCalibration;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxMinus;   //!
   TBranch        *b_HLT_L1UnpairedBunchBptxPlus;   //!
   TBranch        *b_HLT_L1NotBptxOR;   //!
   TBranch        *b_HLT_L1MinimumBiasHF_OR;   //!
   TBranch        *b_HLT_L1MinimumBiasHF0OR;   //!
   TBranch        *b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142;   //!
   TBranch        *b_HLT_HcalNZS;   //!
   TBranch        *b_HLT_HcalPhiSym;   //!
   TBranch        *b_HLT_HcalIsolatedbunch;   //!
   TBranch        *b_HLT_IsoTrackHB;   //!
   TBranch        *b_HLT_IsoTrackHE;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionAfterAbortGap;   //!
   TBranch        *b_HLT_ZeroBias_IsolatedBunches;   //!
   TBranch        *b_HLT_ZeroBias_FirstCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_LastCollisionInTrain;   //!
   TBranch        *b_HLT_ZeroBias_FirstBXAfterTrain;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1;   //!
   TBranch        *b_HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr;   //!
   TBranch        *b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1;   //!
   TBranch        *b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL;   //!
   TBranch        *b_HLT_Rsq0p35;   //!
   TBranch        *b_HLT_Rsq0p40;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200;   //!
   TBranch        *b_HLT_RsqMR300_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_RsqMR320_Rsq0p09_MR200_4jet;   //!
   TBranch        *b_HLT_L1_DoubleJet30_Mass_Min400_Mu10;   //!
   TBranch        *b_HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1;   //!
   TBranch        *b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3;   //!
   TBranch        *b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign;   //!
   TBranch        *b_HLT_Mu18_Mu9_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu18_Mu9;   //!
   TBranch        *b_HLT_Mu18_Mu9_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign;   //!
   TBranch        *b_HLT_Mu20_Mu10_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu20_Mu10;   //!
   TBranch        *b_HLT_Mu20_Mu10_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign;   //!
   TBranch        *b_HLT_Mu23_Mu12_SameSign_DZ;   //!
   TBranch        *b_HLT_Mu23_Mu12;   //!
   TBranch        *b_HLT_Mu23_Mu12_DZ;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi;   //!
   TBranch        *b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi;   //!
   TBranch        *b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60;   //!
   TBranch        *b_HLT_TripleMu_5_3_3_Mass3p8to60_DCA;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2;   //!
   TBranch        *b_HLT_QuadPFJet98_83_71_15;   //!
   TBranch        *b_HLT_QuadPFJet103_88_75_15;   //!
   TBranch        *b_HLT_QuadPFJet105_88_76_15;   //!
   TBranch        *b_HLT_QuadPFJet111_90_80_15;   //!
   TBranch        *b_HLT_AK8PFJet330_PFAK8BTagCSV_p17;   //!
   TBranch        *b_HLT_AK8PFJet330_PFAK8BTagCSV_p1;   //!
   TBranch        *b_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55;   //!
   TBranch        *b_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55;   //!
   TBranch        *b_HLTriggerFinalPath;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_CSCTightHaloFilter;   //!
   TBranch        *b_Flag_CSCTightHaloTrkMuUnvetoFilter;   //!
   TBranch        *b_Flag_CSCTightHalo2015Filter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_globalSuperTightHalo2016Filter;   //!
   TBranch        *b_Flag_HcalStripHaloFilter;   //!
   TBranch        *b_Flag_hcalLaserEventFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_EcalDeadCellBoundaryEnergyFilter;   //!
   TBranch        *b_Flag_ecalBadCalibFilter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_ecalLaserCorrFilter;   //!
   TBranch        *b_Flag_trkPOGFilters;   //!
   TBranch        *b_Flag_chargedHadronTrackResolutionFilter;   //!
   TBranch        *b_Flag_muonBadTrackFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_BadChargedCandidateSummer16Filter;   //!
   TBranch        *b_Flag_BadPFMuonSummer16Filter;   //!
   TBranch        *b_Flag_trkPOG_manystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_toomanystripclus53X;   //!
   TBranch        *b_Flag_trkPOG_logErrorTooManyClusters;   //!
   TBranch        *b_Flag_METFilters;   //!

   CMSnanoAOD(char *file_name, TChain *tree=0);
   virtual ~CMSnanoAOD();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CMSnanoAOD_cxx
CMSnanoAOD::CMSnanoAOD(char *file_name, TChain *tree) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.

  TChain* chain; 
  if (tree == 0) {
     chain = new TChain("Events");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }

}

CMSnanoAOD::~CMSnanoAOD()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CMSnanoAOD::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CMSnanoAOD::LoadTree(Long64_t entry)
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

void CMSnanoAOD::Init(TTree *tree)
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

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20", &HLT_IsoMu17_eta2p1_LooseIsoPFTau20, &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20);

   fChain->SetBranchAddress("CaloMET_phi", &CaloMET_phi, &b_CaloMET_phi);
   fChain->SetBranchAddress("CaloMET_pt", &CaloMET_pt, &b_CaloMET_pt);
   fChain->SetBranchAddress("CaloMET_sumEt", &CaloMET_sumEt, &b_CaloMET_sumEt);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("Electron_deltaEtaSC", Electron_deltaEtaSC, &b_Electron_deltaEtaSC);
   fChain->SetBranchAddress("Electron_dr03EcalRecHitSumEt", Electron_dr03EcalRecHitSumEt, &b_Electron_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("Electron_dr03HcalDepth1TowerSumEt", Electron_dr03HcalDepth1TowerSumEt, &b_Electron_dr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("Electron_dr03TkSumPt", Electron_dr03TkSumPt, &b_Electron_dr03TkSumPt);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dxyErr", Electron_dxyErr, &b_Electron_dxyErr);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dzErr", Electron_dzErr, &b_Electron_dzErr);
   fChain->SetBranchAddress("Electron_eCorr", Electron_eCorr, &b_Electron_eCorr);
   fChain->SetBranchAddress("Electron_eInvMinusPInv", Electron_eInvMinusPInv, &b_Electron_eInvMinusPInv);
   fChain->SetBranchAddress("Electron_energyErr", Electron_energyErr, &b_Electron_energyErr);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_hoe", Electron_hoe, &b_Electron_hoe);
   fChain->SetBranchAddress("Electron_ip3d", Electron_ip3d, &b_Electron_ip3d);
   fChain->SetBranchAddress("Electron_mass", Electron_mass, &b_Electron_mass);
   fChain->SetBranchAddress("Electron_miniPFRelIso_all", Electron_miniPFRelIso_all, &b_Electron_miniPFRelIso_all);
   fChain->SetBranchAddress("Electron_miniPFRelIso_chg", Electron_miniPFRelIso_chg, &b_Electron_miniPFRelIso_chg);
   fChain->SetBranchAddress("Electron_mvaFall17Iso", Electron_mvaFall17Iso, &b_Electron_mvaFall17Iso);
   fChain->SetBranchAddress("Electron_mvaFall17noIso", Electron_mvaFall17noIso, &b_Electron_mvaFall17noIso);
   fChain->SetBranchAddress("Electron_pfRelIso03_all", Electron_pfRelIso03_all, &b_Electron_pfRelIso03_all);
   fChain->SetBranchAddress("Electron_pfRelIso03_chg", Electron_pfRelIso03_chg, &b_Electron_pfRelIso03_chg);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_pt", Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_r9", Electron_r9, &b_Electron_r9);
   fChain->SetBranchAddress("Electron_sieie", Electron_sieie, &b_Electron_sieie);
   fChain->SetBranchAddress("Electron_sip3d", Electron_sip3d, &b_Electron_sip3d);
   fChain->SetBranchAddress("Electron_mvaTTH", Electron_mvaTTH, &b_Electron_mvaTTH);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_cutBased", Electron_cutBased, &b_Electron_cutBased);
   fChain->SetBranchAddress("Electron_jetIdx", Electron_jetIdx, &b_Electron_jetIdx);
   fChain->SetBranchAddress("Electron_pdgId", Electron_pdgId, &b_Electron_pdgId);
   fChain->SetBranchAddress("Electron_photonIdx", Electron_photonIdx, &b_Electron_photonIdx);
   fChain->SetBranchAddress("Electron_tightCharge", Electron_tightCharge, &b_Electron_tightCharge);
   fChain->SetBranchAddress("Electron_vidNestedWPBitmap", Electron_vidNestedWPBitmap, &b_Electron_vidNestedWPBitmap);
   fChain->SetBranchAddress("Electron_convVeto", Electron_convVeto, &b_Electron_convVeto);
   fChain->SetBranchAddress("Electron_cutBased_HEEP", Electron_cutBased_HEEP, &b_Electron_cutBased_HEEP);
   fChain->SetBranchAddress("Electron_isPFcand", Electron_isPFcand, &b_Electron_isPFcand);
   fChain->SetBranchAddress("Electron_lostHits", Electron_lostHits, &b_Electron_lostHits);
   fChain->SetBranchAddress("Electron_mvaFall17Iso_WP80", Electron_mvaFall17Iso_WP80, &b_Electron_mvaFall17Iso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17Iso_WP90", Electron_mvaFall17Iso_WP90, &b_Electron_mvaFall17Iso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17Iso_WPL", Electron_mvaFall17Iso_WPL, &b_Electron_mvaFall17Iso_WPL);
   fChain->SetBranchAddress("Electron_mvaFall17noIso_WP80", Electron_mvaFall17noIso_WP80, &b_Electron_mvaFall17noIso_WP80);
   fChain->SetBranchAddress("Electron_mvaFall17noIso_WP90", Electron_mvaFall17noIso_WP90, &b_Electron_mvaFall17noIso_WP90);
   fChain->SetBranchAddress("Electron_mvaFall17noIso_WPL", Electron_mvaFall17noIso_WPL, &b_Electron_mvaFall17noIso_WPL);
   fChain->SetBranchAddress("nFatJet", &nFatJet, &b_nFatJet);
   fChain->SetBranchAddress("FatJet_area", FatJet_area, &b_FatJet_area);
   fChain->SetBranchAddress("FatJet_btagCMVA", FatJet_btagCMVA, &b_FatJet_btagCMVA);
   fChain->SetBranchAddress("FatJet_btagCSVV2", FatJet_btagCSVV2, &b_FatJet_btagCSVV2);
   fChain->SetBranchAddress("FatJet_btagDeepB", FatJet_btagDeepB, &b_FatJet_btagDeepB);
   fChain->SetBranchAddress("FatJet_btagHbb", FatJet_btagHbb, &b_FatJet_btagHbb);
   fChain->SetBranchAddress("FatJet_eta", FatJet_eta, &b_FatJet_eta);
   fChain->SetBranchAddress("FatJet_mass", FatJet_mass, &b_FatJet_mass);
   fChain->SetBranchAddress("FatJet_msoftdrop", FatJet_msoftdrop, &b_FatJet_msoftdrop);
   fChain->SetBranchAddress("FatJet_n2b1", FatJet_n2b1, &b_FatJet_n2b1);
   fChain->SetBranchAddress("FatJet_n3b1", FatJet_n3b1, &b_FatJet_n3b1);
   fChain->SetBranchAddress("FatJet_phi", FatJet_phi, &b_FatJet_phi);
   fChain->SetBranchAddress("FatJet_pt", FatJet_pt, &b_FatJet_pt);
   fChain->SetBranchAddress("FatJet_tau1", FatJet_tau1, &b_FatJet_tau1);
   fChain->SetBranchAddress("FatJet_tau2", FatJet_tau2, &b_FatJet_tau2);
   fChain->SetBranchAddress("FatJet_tau3", FatJet_tau3, &b_FatJet_tau3);
   fChain->SetBranchAddress("FatJet_tau4", FatJet_tau4, &b_FatJet_tau4);
   fChain->SetBranchAddress("FatJet_jetId", FatJet_jetId, &b_FatJet_jetId);
   fChain->SetBranchAddress("FatJet_subJetIdx1", FatJet_subJetIdx1, &b_FatJet_subJetIdx1);
   fChain->SetBranchAddress("FatJet_subJetIdx2", FatJet_subJetIdx2, &b_FatJet_subJetIdx2);
   fChain->SetBranchAddress("nGenJetAK8", &nGenJetAK8, &b_nGenJetAK8);
   fChain->SetBranchAddress("GenJetAK8_eta", GenJetAK8_eta, &b_GenJetAK8_eta);
   fChain->SetBranchAddress("GenJetAK8_mass", GenJetAK8_mass, &b_GenJetAK8_mass);
   fChain->SetBranchAddress("GenJetAK8_phi", GenJetAK8_phi, &b_GenJetAK8_phi);
   fChain->SetBranchAddress("GenJetAK8_pt", GenJetAK8_pt, &b_GenJetAK8_pt);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("GenJet_eta", GenJet_eta, &b_GenJet_eta);
   fChain->SetBranchAddress("GenJet_mass", GenJet_mass, &b_GenJet_mass);
   fChain->SetBranchAddress("GenJet_phi", GenJet_phi, &b_GenJet_phi);
   fChain->SetBranchAddress("GenJet_pt", GenJet_pt, &b_GenJet_pt);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_genPartIdxMother", GenPart_genPartIdxMother, &b_GenPart_genPartIdxMother);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   fChain->SetBranchAddress("GenPart_statusFlags", GenPart_statusFlags, &b_GenPart_statusFlags);
   fChain->SetBranchAddress("nSubGenJetAK8", &nSubGenJetAK8, &b_nSubGenJetAK8);
   fChain->SetBranchAddress("SubGenJetAK8_eta", SubGenJetAK8_eta, &b_SubGenJetAK8_eta);
   fChain->SetBranchAddress("SubGenJetAK8_mass", SubGenJetAK8_mass, &b_SubGenJetAK8_mass);
   fChain->SetBranchAddress("SubGenJetAK8_phi", SubGenJetAK8_phi, &b_SubGenJetAK8_phi);
   fChain->SetBranchAddress("SubGenJetAK8_pt", SubGenJetAK8_pt, &b_SubGenJetAK8_pt);
   fChain->SetBranchAddress("Generator_binvar", &Generator_binvar, &b_Generator_binvar);
   fChain->SetBranchAddress("Generator_scalePDF", &Generator_scalePDF, &b_Generator_scalePDF);
   fChain->SetBranchAddress("Generator_weight", &Generator_weight, &b_Generator_weight);
   fChain->SetBranchAddress("Generator_x1", &Generator_x1, &b_Generator_x1);
   fChain->SetBranchAddress("Generator_x2", &Generator_x2, &b_Generator_x2);
   fChain->SetBranchAddress("Generator_xpdf1", &Generator_xpdf1, &b_Generator_xpdf1);
   fChain->SetBranchAddress("Generator_xpdf2", &Generator_xpdf2, &b_Generator_xpdf2);
   fChain->SetBranchAddress("Generator_id1", &Generator_id1, &b_Generator_id1);
   fChain->SetBranchAddress("Generator_id2", &Generator_id2, &b_Generator_id2);
   fChain->SetBranchAddress("nGenVisTau", &nGenVisTau, &b_nGenVisTau);
   fChain->SetBranchAddress("GenVisTau_eta", GenVisTau_eta, &b_GenVisTau_eta);
   fChain->SetBranchAddress("GenVisTau_mass", GenVisTau_mass, &b_GenVisTau_mass);
   fChain->SetBranchAddress("GenVisTau_phi", GenVisTau_phi, &b_GenVisTau_phi);
   fChain->SetBranchAddress("GenVisTau_pt", GenVisTau_pt, &b_GenVisTau_pt);
   fChain->SetBranchAddress("GenVisTau_charge", GenVisTau_charge, &b_GenVisTau_charge);
   fChain->SetBranchAddress("GenVisTau_genPartIdxMother", GenVisTau_genPartIdxMother, &b_GenVisTau_genPartIdxMother);
   fChain->SetBranchAddress("GenVisTau_status", GenVisTau_status, &b_GenVisTau_status);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("LHEWeight_originalXWGTUP", &LHEWeight_originalXWGTUP, &b_LHEWeight_originalXWGTUP);
   fChain->SetBranchAddress("nLHEPdfWeight", &nLHEPdfWeight, &b_nLHEPdfWeight);
   fChain->SetBranchAddress("LHEPdfWeight", &LHEPdfWeight, &b_LHEPdfWeight);
   fChain->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight, &b_nLHEScaleWeight);
   fChain->SetBranchAddress("LHEScaleWeight", &LHEScaleWeight, &b_LHEScaleWeight);
   fChain->SetBranchAddress("nIsoTrack", &nIsoTrack, &b_nIsoTrack);
   fChain->SetBranchAddress("IsoTrack_dxy", IsoTrack_dxy, &b_IsoTrack_dxy);
   fChain->SetBranchAddress("IsoTrack_dz", IsoTrack_dz, &b_IsoTrack_dz);
   fChain->SetBranchAddress("IsoTrack_eta", IsoTrack_eta, &b_IsoTrack_eta);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_all", IsoTrack_pfRelIso03_all, &b_IsoTrack_pfRelIso03_all);
   fChain->SetBranchAddress("IsoTrack_pfRelIso03_chg", IsoTrack_pfRelIso03_chg, &b_IsoTrack_pfRelIso03_chg);
   fChain->SetBranchAddress("IsoTrack_phi", IsoTrack_phi, &b_IsoTrack_phi);
   fChain->SetBranchAddress("IsoTrack_pt", IsoTrack_pt, &b_IsoTrack_pt);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_all", IsoTrack_miniPFRelIso_all, &b_IsoTrack_miniPFRelIso_all);
   fChain->SetBranchAddress("IsoTrack_miniPFRelIso_chg", IsoTrack_miniPFRelIso_chg, &b_IsoTrack_miniPFRelIso_chg);
   fChain->SetBranchAddress("IsoTrack_pdgId", IsoTrack_pdgId, &b_IsoTrack_pdgId);
   fChain->SetBranchAddress("IsoTrack_isHighPurityTrack", IsoTrack_isHighPurityTrack, &b_IsoTrack_isHighPurityTrack);
   fChain->SetBranchAddress("IsoTrack_isPFcand", IsoTrack_isPFcand, &b_IsoTrack_isPFcand);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_btagCMVA", Jet_btagCMVA, &b_Jet_btagCMVA);
   fChain->SetBranchAddress("Jet_btagCSVV2", Jet_btagCSVV2, &b_Jet_btagCSVV2);
   fChain->SetBranchAddress("Jet_btagDeepB", Jet_btagDeepB, &b_Jet_btagDeepB);
   fChain->SetBranchAddress("Jet_btagDeepC", Jet_btagDeepC, &b_Jet_btagDeepC);
   fChain->SetBranchAddress("Jet_btagDeepFlavB", Jet_btagDeepFlavB, &b_Jet_btagDeepFlavB);
   fChain->SetBranchAddress("Jet_chEmEF", Jet_chEmEF, &b_Jet_chEmEF);
   fChain->SetBranchAddress("Jet_chHEF", Jet_chHEF, &b_Jet_chHEF);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_neEmEF", Jet_neEmEF, &b_Jet_neEmEF);
   fChain->SetBranchAddress("Jet_neHEF", Jet_neHEF, &b_Jet_neHEF);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_qgl", Jet_qgl, &b_Jet_qgl);
   fChain->SetBranchAddress("Jet_rawFactor", Jet_rawFactor, &b_Jet_rawFactor);
   fChain->SetBranchAddress("Jet_bReg", Jet_bReg, &b_Jet_bReg);
   fChain->SetBranchAddress("Jet_electronIdx1", Jet_electronIdx1, &b_Jet_electronIdx1);
   fChain->SetBranchAddress("Jet_electronIdx2", Jet_electronIdx2, &b_Jet_electronIdx2);
   fChain->SetBranchAddress("Jet_jetId", Jet_jetId, &b_Jet_jetId);
   fChain->SetBranchAddress("Jet_muonIdx1", Jet_muonIdx1, &b_Jet_muonIdx1);
   fChain->SetBranchAddress("Jet_muonIdx2", Jet_muonIdx2, &b_Jet_muonIdx2);
   fChain->SetBranchAddress("Jet_nConstituents", Jet_nConstituents, &b_Jet_nConstituents);
   fChain->SetBranchAddress("Jet_nElectrons", Jet_nElectrons, &b_Jet_nElectrons);
   fChain->SetBranchAddress("Jet_nMuons", Jet_nMuons, &b_Jet_nMuons);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("LHE_HT", &LHE_HT, &b_LHE_HT);
   fChain->SetBranchAddress("LHE_HTIncoming", &LHE_HTIncoming, &b_LHE_HTIncoming);
   fChain->SetBranchAddress("LHE_Vpt", &LHE_Vpt, &b_LHE_Vpt);
   fChain->SetBranchAddress("LHE_Njets", &LHE_Njets, &b_LHE_Njets);
   fChain->SetBranchAddress("LHE_Nb", &LHE_Nb, &b_LHE_Nb);
   fChain->SetBranchAddress("LHE_Nc", &LHE_Nc, &b_LHE_Nc);
   fChain->SetBranchAddress("LHE_Nuds", &LHE_Nuds, &b_LHE_Nuds);
   fChain->SetBranchAddress("LHE_Nglu", &LHE_Nglu, &b_LHE_Nglu);
   fChain->SetBranchAddress("LHE_NpNLO", &LHE_NpNLO, &b_LHE_NpNLO);
   fChain->SetBranchAddress("LHE_NpLO", &LHE_NpLO, &b_LHE_NpLO);
   fChain->SetBranchAddress("nLHEPart", &nLHEPart, &b_nLHEPart);
   fChain->SetBranchAddress("LHEPart_pt", LHEPart_pt, &b_LHEPart_pt);
   fChain->SetBranchAddress("LHEPart_eta", LHEPart_eta, &b_LHEPart_eta);
   fChain->SetBranchAddress("LHEPart_phi", LHEPart_phi, &b_LHEPart_phi);
   fChain->SetBranchAddress("LHEPart_mass", LHEPart_mass, &b_LHEPart_mass);
   fChain->SetBranchAddress("LHEPart_pdgId", LHEPart_pdgId, &b_LHEPart_pdgId);
   fChain->SetBranchAddress("GenMET_phi", &GenMET_phi, &b_GenMET_phi);
   fChain->SetBranchAddress("GenMET_pt", &GenMET_pt, &b_GenMET_pt);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaX", &MET_MetUnclustEnUpDeltaX, &b_MET_MetUnclustEnUpDeltaX);
   fChain->SetBranchAddress("MET_MetUnclustEnUpDeltaY", &MET_MetUnclustEnUpDeltaY, &b_MET_MetUnclustEnUpDeltaY);
   fChain->SetBranchAddress("MET_covXX", &MET_covXX, &b_MET_covXX);
   fChain->SetBranchAddress("MET_covXY", &MET_covXY, &b_MET_covXY);
   fChain->SetBranchAddress("MET_covYY", &MET_covYY, &b_MET_covYY);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_significance", &MET_significance, &b_MET_significance);
   fChain->SetBranchAddress("MET_sumEt", &MET_sumEt, &b_MET_sumEt);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_ip3d", Muon_ip3d, &b_Muon_ip3d);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_miniPFRelIso_all", Muon_miniPFRelIso_all, &b_Muon_miniPFRelIso_all);
   fChain->SetBranchAddress("Muon_miniPFRelIso_chg", Muon_miniPFRelIso_chg, &b_Muon_miniPFRelIso_chg);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso03_chg", Muon_pfRelIso03_chg, &b_Muon_pfRelIso03_chg);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_ptErr", Muon_ptErr, &b_Muon_ptErr);
   fChain->SetBranchAddress("Muon_segmentComp", Muon_segmentComp, &b_Muon_segmentComp);
   fChain->SetBranchAddress("Muon_sip3d", Muon_sip3d, &b_Muon_sip3d);
   fChain->SetBranchAddress("Muon_mvaTTH", Muon_mvaTTH, &b_Muon_mvaTTH);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   fChain->SetBranchAddress("Muon_nStations", Muon_nStations, &b_Muon_nStations);
   fChain->SetBranchAddress("Muon_nTrackerLayers", Muon_nTrackerLayers, &b_Muon_nTrackerLayers);
   fChain->SetBranchAddress("Muon_pdgId", Muon_pdgId, &b_Muon_pdgId);
   fChain->SetBranchAddress("Muon_tightCharge", Muon_tightCharge, &b_Muon_tightCharge);
   fChain->SetBranchAddress("Muon_highPtId", Muon_highPtId, &b_Muon_highPtId);
   fChain->SetBranchAddress("Muon_isPFcand", Muon_isPFcand, &b_Muon_isPFcand);
   fChain->SetBranchAddress("Muon_mediumId", Muon_mediumId, &b_Muon_mediumId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("nPhoton", &nPhoton, &b_nPhoton);
   fChain->SetBranchAddress("Photon_eCorr", Photon_eCorr, &b_Photon_eCorr);
   fChain->SetBranchAddress("Photon_energyErr", Photon_energyErr, &b_Photon_energyErr);
   fChain->SetBranchAddress("Photon_eta", Photon_eta, &b_Photon_eta);
   fChain->SetBranchAddress("Photon_hoe", Photon_hoe, &b_Photon_hoe);
   fChain->SetBranchAddress("Photon_mass", Photon_mass, &b_Photon_mass);
   fChain->SetBranchAddress("Photon_mvaID", Photon_mvaID, &b_Photon_mvaID);
   fChain->SetBranchAddress("Photon_pfRelIso03_all", Photon_pfRelIso03_all, &b_Photon_pfRelIso03_all);
   fChain->SetBranchAddress("Photon_pfRelIso03_chg", Photon_pfRelIso03_chg, &b_Photon_pfRelIso03_chg);
   fChain->SetBranchAddress("Photon_phi", Photon_phi, &b_Photon_phi);
   fChain->SetBranchAddress("Photon_pt", Photon_pt, &b_Photon_pt);
   fChain->SetBranchAddress("Photon_r9", Photon_r9, &b_Photon_r9);
   fChain->SetBranchAddress("Photon_sieie", Photon_sieie, &b_Photon_sieie);
   fChain->SetBranchAddress("Photon_charge", Photon_charge, &b_Photon_charge);
   fChain->SetBranchAddress("Photon_cutBasedBitmap", Photon_cutBasedBitmap, &b_Photon_cutBasedBitmap);
   fChain->SetBranchAddress("Photon_electronIdx", Photon_electronIdx, &b_Photon_electronIdx);
   fChain->SetBranchAddress("Photon_jetIdx", Photon_jetIdx, &b_Photon_jetIdx);
   fChain->SetBranchAddress("Photon_pdgId", Photon_pdgId, &b_Photon_pdgId);
   fChain->SetBranchAddress("Photon_vidNestedWPBitmap", Photon_vidNestedWPBitmap, &b_Photon_vidNestedWPBitmap);
   fChain->SetBranchAddress("Photon_electronVeto", Photon_electronVeto, &b_Photon_electronVeto);
   fChain->SetBranchAddress("Photon_isScEtaEB", Photon_isScEtaEB, &b_Photon_isScEtaEB);
   fChain->SetBranchAddress("Photon_isScEtaEE", Photon_isScEtaEE, &b_Photon_isScEtaEE);
   fChain->SetBranchAddress("Photon_mvaID_WP80", Photon_mvaID_WP80, &b_Photon_mvaID_WP80);
   fChain->SetBranchAddress("Photon_mvaID_WP90", Photon_mvaID_WP90, &b_Photon_mvaID_WP90);
   fChain->SetBranchAddress("Photon_pixelSeed", Photon_pixelSeed, &b_Photon_pixelSeed);
   fChain->SetBranchAddress("Pileup_nTrueInt", &Pileup_nTrueInt, &b_Pileup_nTrueInt);
   fChain->SetBranchAddress("Pileup_nPU", &Pileup_nPU, &b_Pileup_nPU);
   fChain->SetBranchAddress("Pileup_sumEOOT", &Pileup_sumEOOT, &b_Pileup_sumEOOT);
   fChain->SetBranchAddress("Pileup_sumLOOT", &Pileup_sumLOOT, &b_Pileup_sumLOOT);
   fChain->SetBranchAddress("PuppiMET_phi", &PuppiMET_phi, &b_PuppiMET_phi);
   fChain->SetBranchAddress("PuppiMET_pt", &PuppiMET_pt, &b_PuppiMET_pt);
   fChain->SetBranchAddress("PuppiMET_sumEt", &PuppiMET_sumEt, &b_PuppiMET_sumEt);
   fChain->SetBranchAddress("RawMET_phi", &RawMET_phi, &b_RawMET_phi);
   fChain->SetBranchAddress("RawMET_pt", &RawMET_pt, &b_RawMET_pt);
   fChain->SetBranchAddress("RawMET_sumEt", &RawMET_sumEt, &b_RawMET_sumEt);
   fChain->SetBranchAddress("fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralCalo", &fixedGridRhoFastjetCentralCalo, &b_fixedGridRhoFastjetCentralCalo);
   fChain->SetBranchAddress("fixedGridRhoFastjetCentralNeutral", &fixedGridRhoFastjetCentralNeutral, &b_fixedGridRhoFastjetCentralNeutral);
   fChain->SetBranchAddress("nGenDressedLepton", &nGenDressedLepton, &b_nGenDressedLepton);
   fChain->SetBranchAddress("GenDressedLepton_eta", GenDressedLepton_eta, &b_GenDressedLepton_eta);
   fChain->SetBranchAddress("GenDressedLepton_mass", GenDressedLepton_mass, &b_GenDressedLepton_mass);
   fChain->SetBranchAddress("GenDressedLepton_phi", GenDressedLepton_phi, &b_GenDressedLepton_phi);
   fChain->SetBranchAddress("GenDressedLepton_pt", GenDressedLepton_pt, &b_GenDressedLepton_pt);
   fChain->SetBranchAddress("GenDressedLepton_pdgId", GenDressedLepton_pdgId, &b_GenDressedLepton_pdgId);
   fChain->SetBranchAddress("nSoftActivityJet", &nSoftActivityJet, &b_nSoftActivityJet);
   fChain->SetBranchAddress("SoftActivityJet_eta", SoftActivityJet_eta, &b_SoftActivityJet_eta);
   fChain->SetBranchAddress("SoftActivityJet_phi", SoftActivityJet_phi, &b_SoftActivityJet_phi);
   fChain->SetBranchAddress("SoftActivityJet_pt", SoftActivityJet_pt, &b_SoftActivityJet_pt);
   fChain->SetBranchAddress("SoftActivityJetHT", &SoftActivityJetHT, &b_SoftActivityJetHT);
   fChain->SetBranchAddress("SoftActivityJetHT10", &SoftActivityJetHT10, &b_SoftActivityJetHT10);
   fChain->SetBranchAddress("SoftActivityJetHT2", &SoftActivityJetHT2, &b_SoftActivityJetHT2);
   fChain->SetBranchAddress("SoftActivityJetHT5", &SoftActivityJetHT5, &b_SoftActivityJetHT5);
   fChain->SetBranchAddress("SoftActivityJetNjets10", &SoftActivityJetNjets10, &b_SoftActivityJetNjets10);
   fChain->SetBranchAddress("SoftActivityJetNjets2", &SoftActivityJetNjets2, &b_SoftActivityJetNjets2);
   fChain->SetBranchAddress("SoftActivityJetNjets5", &SoftActivityJetNjets5, &b_SoftActivityJetNjets5);
   fChain->SetBranchAddress("nSubJet", &nSubJet, &b_nSubJet);
   fChain->SetBranchAddress("SubJet_btagCMVA", SubJet_btagCMVA, &b_SubJet_btagCMVA);
   fChain->SetBranchAddress("SubJet_btagCSVV2", SubJet_btagCSVV2, &b_SubJet_btagCSVV2);
   fChain->SetBranchAddress("SubJet_btagDeepB", SubJet_btagDeepB, &b_SubJet_btagDeepB);
   fChain->SetBranchAddress("SubJet_eta", SubJet_eta, &b_SubJet_eta);
   fChain->SetBranchAddress("SubJet_mass", SubJet_mass, &b_SubJet_mass);
   fChain->SetBranchAddress("SubJet_n2b1", SubJet_n2b1, &b_SubJet_n2b1);
   fChain->SetBranchAddress("SubJet_n3b1", SubJet_n3b1, &b_SubJet_n3b1);
   fChain->SetBranchAddress("SubJet_phi", SubJet_phi, &b_SubJet_phi);
   fChain->SetBranchAddress("SubJet_pt", SubJet_pt, &b_SubJet_pt);
   fChain->SetBranchAddress("SubJet_tau1", SubJet_tau1, &b_SubJet_tau1);
   fChain->SetBranchAddress("SubJet_tau2", SubJet_tau2, &b_SubJet_tau2);
   fChain->SetBranchAddress("SubJet_tau3", SubJet_tau3, &b_SubJet_tau3);
   fChain->SetBranchAddress("SubJet_tau4", SubJet_tau4, &b_SubJet_tau4);
   fChain->SetBranchAddress("nTau", &nTau, &b_nTau);
   fChain->SetBranchAddress("Tau_chargedIso", Tau_chargedIso, &b_Tau_chargedIso);
   fChain->SetBranchAddress("Tau_dxy", Tau_dxy, &b_Tau_dxy);
   fChain->SetBranchAddress("Tau_dz", Tau_dz, &b_Tau_dz);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_leadTkDeltaEta", Tau_leadTkDeltaEta, &b_Tau_leadTkDeltaEta);
   fChain->SetBranchAddress("Tau_leadTkDeltaPhi", Tau_leadTkDeltaPhi, &b_Tau_leadTkDeltaPhi);
   fChain->SetBranchAddress("Tau_leadTkPtOverTauPt", Tau_leadTkPtOverTauPt, &b_Tau_leadTkPtOverTauPt);
   fChain->SetBranchAddress("Tau_mass", Tau_mass, &b_Tau_mass);
   fChain->SetBranchAddress("Tau_neutralIso", Tau_neutralIso, &b_Tau_neutralIso);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_photonsOutsideSignalCone", Tau_photonsOutsideSignalCone, &b_Tau_photonsOutsideSignalCone);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_puCorr", Tau_puCorr, &b_Tau_puCorr);
   fChain->SetBranchAddress("Tau_rawAntiEle", Tau_rawAntiEle, &b_Tau_rawAntiEle);
   fChain->SetBranchAddress("Tau_rawIso", Tau_rawIso, &b_Tau_rawIso);
   fChain->SetBranchAddress("Tau_rawIsodR03", Tau_rawIsodR03, &b_Tau_rawIsodR03);
   fChain->SetBranchAddress("Tau_rawMVAnewDM2017v2", Tau_rawMVAnewDM2017v2, &b_Tau_rawMVAnewDM2017v2);
   fChain->SetBranchAddress("Tau_rawMVAoldDM", Tau_rawMVAoldDM, &b_Tau_rawMVAoldDM);
   fChain->SetBranchAddress("Tau_rawMVAoldDM2017v1", Tau_rawMVAoldDM2017v1, &b_Tau_rawMVAoldDM2017v1);
   fChain->SetBranchAddress("Tau_rawMVAoldDM2017v2", Tau_rawMVAoldDM2017v2, &b_Tau_rawMVAoldDM2017v2);
   fChain->SetBranchAddress("Tau_rawMVAoldDMdR032017v2", Tau_rawMVAoldDMdR032017v2, &b_Tau_rawMVAoldDMdR032017v2);
   fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau_decayMode", Tau_decayMode, &b_Tau_decayMode);
   fChain->SetBranchAddress("Tau_jetIdx", Tau_jetIdx, &b_Tau_jetIdx);
   fChain->SetBranchAddress("Tau_rawAntiEleCat", Tau_rawAntiEleCat, &b_Tau_rawAntiEleCat);
   fChain->SetBranchAddress("Tau_idAntiEle", Tau_idAntiEle, &b_Tau_idAntiEle);
   fChain->SetBranchAddress("Tau_idAntiMu", Tau_idAntiMu, &b_Tau_idAntiMu);
   fChain->SetBranchAddress("Tau_idDecayMode", Tau_idDecayMode, &b_Tau_idDecayMode);
   fChain->SetBranchAddress("Tau_idDecayModeNewDMs", Tau_idDecayModeNewDMs, &b_Tau_idDecayModeNewDMs);
   fChain->SetBranchAddress("Tau_idMVAnewDM2017v2", Tau_idMVAnewDM2017v2, &b_Tau_idMVAnewDM2017v2);
   fChain->SetBranchAddress("Tau_idMVAoldDM", Tau_idMVAoldDM, &b_Tau_idMVAoldDM);
   fChain->SetBranchAddress("Tau_idMVAoldDM2017v1", Tau_idMVAoldDM2017v1, &b_Tau_idMVAoldDM2017v1);
   fChain->SetBranchAddress("Tau_idMVAoldDM2017v2", Tau_idMVAoldDM2017v2, &b_Tau_idMVAoldDM2017v2);
   fChain->SetBranchAddress("Tau_idMVAoldDMdR032017v2", Tau_idMVAoldDMdR032017v2, &b_Tau_idMVAoldDMdR032017v2);
   fChain->SetBranchAddress("Tau_relIso_all", Tau_relIso_all, &b_Tau_relIso_all);
   fChain->SetBranchAddress("Tau_idIsoRaw", Tau_idIsoRaw, &b_Tau_idIsoRaw);
   fChain->SetBranchAddress("Tau_idIsoVLoose", Tau_idIsoVLoose, &b_Tau_idIsoVLoose);
   fChain->SetBranchAddress("Tau_idIsoLoose", Tau_idIsoLoose, &b_Tau_idIsoLoose);
   fChain->SetBranchAddress("Tau_idIsoMedium", Tau_idIsoMedium, &b_Tau_idIsoMedium);
   fChain->SetBranchAddress("Tau_idIsoTight", Tau_idIsoTight, &b_Tau_idIsoTight);
   fChain->SetBranchAddress("Tau_idAntiEleLoose", Tau_idAntiEleLoose, &b_Tau_idAntiEleLoose);
   fChain->SetBranchAddress("Tau_idAntiEleMedium", Tau_idAntiEleMedium, &b_Tau_idAntiEleMedium);
   fChain->SetBranchAddress("Tau_idAntiEleTight", Tau_idAntiEleTight, &b_Tau_idAntiEleTight);
   fChain->SetBranchAddress("Tau_idAntiMuLoose", Tau_idAntiMuLoose, &b_Tau_idAntiMuLoose);
   fChain->SetBranchAddress("Tau_idAntiMuMedium", Tau_idAntiMuMedium, &b_Tau_idAntiMuMedium);
   fChain->SetBranchAddress("Tau_idAntiMuTight", Tau_idAntiMuTight, &b_Tau_idAntiMuTight);

   fChain->SetBranchAddress("TkMET_phi", &TkMET_phi, &b_TkMET_phi);
   fChain->SetBranchAddress("TkMET_pt", &TkMET_pt, &b_TkMET_pt);
   fChain->SetBranchAddress("TkMET_sumEt", &TkMET_sumEt, &b_TkMET_sumEt);
   fChain->SetBranchAddress("nTrigObj", &nTrigObj, &b_nTrigObj);
   fChain->SetBranchAddress("TrigObj_pt", TrigObj_pt, &b_TrigObj_pt);
   fChain->SetBranchAddress("TrigObj_eta", TrigObj_eta, &b_TrigObj_eta);
   fChain->SetBranchAddress("TrigObj_phi", TrigObj_phi, &b_TrigObj_phi);
   fChain->SetBranchAddress("TrigObj_l1pt", TrigObj_l1pt, &b_TrigObj_l1pt);
   fChain->SetBranchAddress("TrigObj_l1pt_2", TrigObj_l1pt_2, &b_TrigObj_l1pt_2);
   fChain->SetBranchAddress("TrigObj_l2pt", TrigObj_l2pt, &b_TrigObj_l2pt);
   fChain->SetBranchAddress("TrigObj_id", TrigObj_id, &b_TrigObj_id);
   fChain->SetBranchAddress("TrigObj_l1iso", TrigObj_l1iso, &b_TrigObj_l1iso);
   fChain->SetBranchAddress("TrigObj_l1charge", TrigObj_l1charge, &b_TrigObj_l1charge);
   fChain->SetBranchAddress("TrigObj_filterBits", TrigObj_filterBits, &b_TrigObj_filterBits);
   fChain->SetBranchAddress("genTtbarId", &genTtbarId, &b_genTtbarId);
   fChain->SetBranchAddress("nOtherPV", &nOtherPV, &b_nOtherPV);
   fChain->SetBranchAddress("OtherPV_z", OtherPV_z, &b_OtherPV_z);
   fChain->SetBranchAddress("PV_ndof", &PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_chi2", &PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_score", &PV_score, &b_PV_score);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_dlen", SV_dlen, &b_SV_dlen);
   fChain->SetBranchAddress("SV_dlenSig", SV_dlenSig, &b_SV_dlenSig);
   fChain->SetBranchAddress("SV_pAngle", SV_pAngle, &b_SV_pAngle);
   fChain->SetBranchAddress("Electron_genPartIdx", Electron_genPartIdx, &b_Electron_genPartIdx);
   fChain->SetBranchAddress("Electron_genPartFlav", Electron_genPartFlav, &b_Electron_genPartFlav);
   fChain->SetBranchAddress("GenJetAK8_partonFlavour", GenJetAK8_partonFlavour, &b_GenJetAK8_partonFlavour);
   fChain->SetBranchAddress("GenJetAK8_hadronFlavour", GenJetAK8_hadronFlavour, &b_GenJetAK8_hadronFlavour);
   fChain->SetBranchAddress("GenJet_partonFlavour", GenJet_partonFlavour, &b_GenJet_partonFlavour);
   fChain->SetBranchAddress("GenJet_hadronFlavour", GenJet_hadronFlavour, &b_GenJet_hadronFlavour);
   fChain->SetBranchAddress("Jet_genJetIdx", Jet_genJetIdx, &b_Jet_genJetIdx);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   fChain->SetBranchAddress("Muon_genPartFlav", Muon_genPartFlav, &b_Muon_genPartFlav);
   fChain->SetBranchAddress("Photon_genPartIdx", Photon_genPartIdx, &b_Photon_genPartIdx);
   fChain->SetBranchAddress("Photon_genPartFlav", Photon_genPartFlav, &b_Photon_genPartFlav);
   fChain->SetBranchAddress("MET_fiducialGenPhi", &MET_fiducialGenPhi, &b_MET_fiducialGenPhi);
   fChain->SetBranchAddress("MET_fiducialGenPt", &MET_fiducialGenPt, &b_MET_fiducialGenPt);
   fChain->SetBranchAddress("Electron_cleanmask", Electron_cleanmask, &b_Electron_cleanmask);
   fChain->SetBranchAddress("Jet_cleanmask", Jet_cleanmask, &b_Jet_cleanmask);
   fChain->SetBranchAddress("Muon_cleanmask", Muon_cleanmask, &b_Muon_cleanmask);
   fChain->SetBranchAddress("Photon_cleanmask", Photon_cleanmask, &b_Photon_cleanmask);
   fChain->SetBranchAddress("Tau_cleanmask", Tau_cleanmask, &b_Tau_cleanmask);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_eta", SV_eta, &b_SV_eta);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_ndof", SV_ndof, &b_SV_ndof);
   fChain->SetBranchAddress("SV_phi", SV_phi, &b_SV_phi);
   fChain->SetBranchAddress("SV_pt", SV_pt, &b_SV_pt);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   fChain->SetBranchAddress("Tau_genPartIdx", Tau_genPartIdx, &b_Tau_genPartIdx);
   fChain->SetBranchAddress("Tau_genPartFlav", Tau_genPartFlav, &b_Tau_genPartFlav);
   fChain->SetBranchAddress("L1simulation_step", &L1simulation_step, &b_L1simulation_step);
   fChain->SetBranchAddress("HLTriggerFirstPath", &HLTriggerFirstPath, &b_HLTriggerFirstPath);
   fChain->SetBranchAddress("HLT_AK8PFJet360_TrimMass30", &HLT_AK8PFJet360_TrimMass30, &b_HLT_AK8PFJet360_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet380_TrimMass30", &HLT_AK8PFJet380_TrimMass30, &b_HLT_AK8PFJet380_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet400_TrimMass30", &HLT_AK8PFJet400_TrimMass30, &b_HLT_AK8PFJet400_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFJet420_TrimMass30", &HLT_AK8PFJet420_TrimMass30, &b_HLT_AK8PFJet420_TrimMass30);
   fChain->SetBranchAddress("HLT_AK8PFHT750_TrimMass50", &HLT_AK8PFHT750_TrimMass50, &b_HLT_AK8PFHT750_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT800_TrimMass50", &HLT_AK8PFHT800_TrimMass50, &b_HLT_AK8PFHT800_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT850_TrimMass50", &HLT_AK8PFHT850_TrimMass50, &b_HLT_AK8PFHT850_TrimMass50);
   fChain->SetBranchAddress("HLT_AK8PFHT900_TrimMass50", &HLT_AK8PFHT900_TrimMass50, &b_HLT_AK8PFHT900_TrimMass50);
   fChain->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID, &b_HLT_CaloJet500_NoJetID);
   fChain->SetBranchAddress("HLT_CaloJet550_NoJetID", &HLT_CaloJet550_NoJetID, &b_HLT_CaloJet550_NoJetID);
   fChain->SetBranchAddress("HLT_Trimuon5_3p5_2_Upsilon_Muon", &HLT_Trimuon5_3p5_2_Upsilon_Muon, &b_HLT_Trimuon5_3p5_2_Upsilon_Muon);
   fChain->SetBranchAddress("HLT_DoubleEle25_CaloIdL_MW", &HLT_DoubleEle25_CaloIdL_MW, &b_HLT_DoubleEle25_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle27_CaloIdL_MW", &HLT_DoubleEle27_CaloIdL_MW, &b_HLT_DoubleEle27_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW", &HLT_DoubleEle33_CaloIdL_MW, &b_HLT_DoubleEle33_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_DoubleEle24_eta2p1_WPTight_Gsf", &HLT_DoubleEle24_eta2p1_WPTight_Gsf, &b_HLT_DoubleEle24_eta2p1_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_DZ_PFHT350);
   fChain->SetBranchAddress("HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT350);
   fChain->SetBranchAddress("HLT_Ele27_Ele37_CaloIdL_MW", &HLT_Ele27_Ele37_CaloIdL_MW, &b_HLT_Ele27_Ele37_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu27_Ele37_CaloIdL_MW", &HLT_Mu27_Ele37_CaloIdL_MW, &b_HLT_Mu27_Ele37_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu37_Ele27_CaloIdL_MW", &HLT_Mu37_Ele27_CaloIdL_MW, &b_HLT_Mu37_Ele27_CaloIdL_MW);
   fChain->SetBranchAddress("HLT_Mu37_TkMu27", &HLT_Mu37_TkMu27, &b_HLT_Mu37_TkMu27);
   fChain->SetBranchAddress("HLT_DoubleMu4_3_Bs", &HLT_DoubleMu4_3_Bs, &b_HLT_DoubleMu4_3_Bs);
   fChain->SetBranchAddress("HLT_DoubleMu4_3_Jpsi_Displaced", &HLT_DoubleMu4_3_Jpsi_Displaced, &b_HLT_DoubleMu4_3_Jpsi_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrk_Displaced", &HLT_DoubleMu4_JpsiTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_LowMassNonResonantTrk_Displaced", &HLT_DoubleMu4_LowMassNonResonantTrk_Displaced, &b_HLT_DoubleMu4_LowMassNonResonantTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu3_Trk_Tau3mu", &HLT_DoubleMu3_Trk_Tau3mu, &b_HLT_DoubleMu3_Trk_Tau3mu);
   fChain->SetBranchAddress("HLT_DoubleMu4_PsiPrimeTrk_Displaced", &HLT_DoubleMu4_PsiPrimeTrk_Displaced, &b_HLT_DoubleMu4_PsiPrimeTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_Mass8_DZ_PFHT350", &HLT_DoubleMu4_Mass8_DZ_PFHT350, &b_HLT_DoubleMu4_Mass8_DZ_PFHT350);
   fChain->SetBranchAddress("HLT_DoubleMu8_Mass8_PFHT350", &HLT_DoubleMu8_Mass8_PFHT350, &b_HLT_DoubleMu8_Mass8_PFHT350);
   fChain->SetBranchAddress("HLT_Mu3_PFJet40", &HLT_Mu3_PFJet40, &b_HLT_Mu3_PFJet40);
   fChain->SetBranchAddress("HLT_Mu7p5_L2Mu2_Jpsi", &HLT_Mu7p5_L2Mu2_Jpsi, &b_HLT_Mu7p5_L2Mu2_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_L2Mu2_Upsilon", &HLT_Mu7p5_L2Mu2_Upsilon, &b_HLT_Mu7p5_L2Mu2_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track2_Jpsi", &HLT_Mu7p5_Track2_Jpsi, &b_HLT_Mu7p5_Track2_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track3p5_Jpsi", &HLT_Mu7p5_Track3p5_Jpsi, &b_HLT_Mu7p5_Track3p5_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track7_Jpsi", &HLT_Mu7p5_Track7_Jpsi, &b_HLT_Mu7p5_Track7_Jpsi);
   fChain->SetBranchAddress("HLT_Mu7p5_Track2_Upsilon", &HLT_Mu7p5_Track2_Upsilon, &b_HLT_Mu7p5_Track2_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track3p5_Upsilon", &HLT_Mu7p5_Track3p5_Upsilon, &b_HLT_Mu7p5_Track3p5_Upsilon);
   fChain->SetBranchAddress("HLT_Mu7p5_Track7_Upsilon", &HLT_Mu7p5_Track7_Upsilon, &b_HLT_Mu7p5_Track7_Upsilon);
   fChain->SetBranchAddress("HLT_DoublePhoton33_CaloIdL", &HLT_DoublePhoton33_CaloIdL, &b_HLT_DoublePhoton33_CaloIdL);
   fChain->SetBranchAddress("HLT_DoublePhoton70", &HLT_DoublePhoton70, &b_HLT_DoublePhoton70);
   fChain->SetBranchAddress("HLT_DoublePhoton85", &HLT_DoublePhoton85, &b_HLT_DoublePhoton85);
   fChain->SetBranchAddress("HLT_Ele20_WPTight_Gsf", &HLT_Ele20_WPTight_Gsf, &b_HLT_Ele20_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele20_WPLoose_Gsf", &HLT_Ele20_WPLoose_Gsf, &b_HLT_Ele20_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_Ele20_eta2p1_WPLoose_Gsf", &HLT_Ele20_eta2p1_WPLoose_Gsf, &b_HLT_Ele20_eta2p1_WPLoose_Gsf);
   fChain->SetBranchAddress("HLT_DiEle27_WPTightCaloOnly_L1DoubleEG", &HLT_DiEle27_WPTightCaloOnly_L1DoubleEG, &b_HLT_DiEle27_WPTightCaloOnly_L1DoubleEG);
   fChain->SetBranchAddress("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, &b_HLT_Ele27_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, &b_HLT_Ele32_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf, &b_HLT_Ele35_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele35_WPTight_Gsf_L1EGMT", &HLT_Ele35_WPTight_Gsf_L1EGMT, &b_HLT_Ele35_WPTight_Gsf_L1EGMT);
   fChain->SetBranchAddress("HLT_Ele38_WPTight_Gsf", &HLT_Ele38_WPTight_Gsf, &b_HLT_Ele38_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele40_WPTight_Gsf", &HLT_Ele40_WPTight_Gsf, &b_HLT_Ele40_WPTight_Gsf);
   fChain->SetBranchAddress("HLT_Ele32_WPTight_Gsf_L1DoubleEG", &HLT_Ele32_WPTight_Gsf_L1DoubleEG, &b_HLT_Ele32_WPTight_Gsf_L1DoubleEG);
   fChain->SetBranchAddress("HLT_HT450_Beamspot", &HLT_HT450_Beamspot, &b_HLT_HT450_Beamspot);
   fChain->SetBranchAddress("HLT_HT300_Beamspot", &HLT_HT300_Beamspot, &b_HLT_HT300_Beamspot);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1", &HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1, &b_HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1", &HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1", &HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1, &b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu20", &HLT_IsoMu20, &b_HLT_IsoMu20);
   fChain->SetBranchAddress("HLT_IsoMu24", &HLT_IsoMu24, &b_HLT_IsoMu24);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, &b_HLT_IsoMu24_eta2p1);
   fChain->SetBranchAddress("HLT_IsoMu27", &HLT_IsoMu27, &b_HLT_IsoMu27);
   fChain->SetBranchAddress("HLT_IsoMu30", &HLT_IsoMu30, &b_HLT_IsoMu30);
   fChain->SetBranchAddress("HLT_UncorrectedJetE30_NoBPTX", &HLT_UncorrectedJetE30_NoBPTX, &b_HLT_UncorrectedJetE30_NoBPTX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE30_NoBPTX3BX", &HLT_UncorrectedJetE30_NoBPTX3BX, &b_HLT_UncorrectedJetE30_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE60_NoBPTX3BX", &HLT_UncorrectedJetE60_NoBPTX3BX, &b_HLT_UncorrectedJetE60_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_UncorrectedJetE70_NoBPTX3BX", &HLT_UncorrectedJetE70_NoBPTX3BX, &b_HLT_UncorrectedJetE70_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L1SingleMu18", &HLT_L1SingleMu18, &b_HLT_L1SingleMu18);
   fChain->SetBranchAddress("HLT_L1SingleMu25", &HLT_L1SingleMu25, &b_HLT_L1SingleMu25);
   fChain->SetBranchAddress("HLT_L2Mu10", &HLT_L2Mu10, &b_HLT_L2Mu10);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX3BX", &HLT_L2Mu10_NoVertex_NoBPTX3BX, &b_HLT_L2Mu10_NoVertex_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu10_NoVertex_NoBPTX", &HLT_L2Mu10_NoVertex_NoBPTX, &b_HLT_L2Mu10_NoVertex_NoBPTX);
   fChain->SetBranchAddress("HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu45_NoVertex_3Sta_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX", &HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX, &b_HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX);
   fChain->SetBranchAddress("HLT_L2Mu50", &HLT_L2Mu50, &b_HLT_L2Mu50);
   fChain->SetBranchAddress("HLT_DoubleL2Mu50", &HLT_DoubleL2Mu50, &b_HLT_DoubleL2Mu50);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass8);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8", &HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8, &b_HLT_Mu19_TrkIsoVVL_Mu9_TrkIsoVVL_DZ_Mass3p8);
   fChain->SetBranchAddress("HLT_Mu25_TkMu0_Onia", &HLT_Mu25_TkMu0_Onia, &b_HLT_Mu25_TkMu0_Onia);
   fChain->SetBranchAddress("HLT_Mu30_TkMu0_Onia", &HLT_Mu30_TkMu0_Onia, &b_HLT_Mu30_TkMu0_Onia);
   fChain->SetBranchAddress("HLT_Mu20_TkMu0_Phi", &HLT_Mu20_TkMu0_Phi, &b_HLT_Mu20_TkMu0_Phi);
   fChain->SetBranchAddress("HLT_Mu25_TkMu0_Phi", &HLT_Mu25_TkMu0_Phi, &b_HLT_Mu25_TkMu0_Phi);
   fChain->SetBranchAddress("HLT_Mu20", &HLT_Mu20, &b_HLT_Mu20);
   fChain->SetBranchAddress("HLT_Mu27", &HLT_Mu27, &b_HLT_Mu27);
   fChain->SetBranchAddress("HLT_Mu50", &HLT_Mu50, &b_HLT_Mu50);
   fChain->SetBranchAddress("HLT_Mu55", &HLT_Mu55, &b_HLT_Mu55);
   fChain->SetBranchAddress("HLT_OldMu100", &HLT_OldMu100, &b_HLT_OldMu100);
   fChain->SetBranchAddress("HLT_TkMu100", &HLT_TkMu100, &b_HLT_TkMu100);
   fChain->SetBranchAddress("HLT_DiPFJet15_NoCaloMatched", &HLT_DiPFJet15_NoCaloMatched, &b_HLT_DiPFJet15_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet25_NoCaloMatched", &HLT_DiPFJet25_NoCaloMatched, &b_HLT_DiPFJet25_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet15_FBEta3_NoCaloMatched", &HLT_DiPFJet15_FBEta3_NoCaloMatched, &b_HLT_DiPFJet15_FBEta3_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJet25_FBEta3_NoCaloMatched", &HLT_DiPFJet25_FBEta3_NoCaloMatched, &b_HLT_DiPFJet25_FBEta3_NoCaloMatched);
   fChain->SetBranchAddress("HLT_DiPFJetAve40", &HLT_DiPFJetAve40, &b_HLT_DiPFJetAve40);
   fChain->SetBranchAddress("HLT_DiPFJetAve60", &HLT_DiPFJetAve60, &b_HLT_DiPFJetAve60);
   fChain->SetBranchAddress("HLT_DiPFJetAve80", &HLT_DiPFJetAve80, &b_HLT_DiPFJetAve80);
   fChain->SetBranchAddress("HLT_DiPFJetAve140", &HLT_DiPFJetAve140, &b_HLT_DiPFJetAve140);
   fChain->SetBranchAddress("HLT_DiPFJetAve200", &HLT_DiPFJetAve200, &b_HLT_DiPFJetAve200);
   fChain->SetBranchAddress("HLT_DiPFJetAve260", &HLT_DiPFJetAve260, &b_HLT_DiPFJetAve260);
   fChain->SetBranchAddress("HLT_DiPFJetAve320", &HLT_DiPFJetAve320, &b_HLT_DiPFJetAve320);
   fChain->SetBranchAddress("HLT_DiPFJetAve400", &HLT_DiPFJetAve400, &b_HLT_DiPFJetAve400);
   fChain->SetBranchAddress("HLT_DiPFJetAve500", &HLT_DiPFJetAve500, &b_HLT_DiPFJetAve500);
   fChain->SetBranchAddress("HLT_DiPFJetAve15_HFJEC", &HLT_DiPFJetAve15_HFJEC, &b_HLT_DiPFJetAve15_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve25_HFJEC", &HLT_DiPFJetAve25_HFJEC, &b_HLT_DiPFJetAve25_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve35_HFJEC", &HLT_DiPFJetAve35_HFJEC, &b_HLT_DiPFJetAve35_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve60_HFJEC", &HLT_DiPFJetAve60_HFJEC, &b_HLT_DiPFJetAve60_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve80_HFJEC", &HLT_DiPFJetAve80_HFJEC, &b_HLT_DiPFJetAve80_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve100_HFJEC", &HLT_DiPFJetAve100_HFJEC, &b_HLT_DiPFJetAve100_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve160_HFJEC", &HLT_DiPFJetAve160_HFJEC, &b_HLT_DiPFJetAve160_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve220_HFJEC", &HLT_DiPFJetAve220_HFJEC, &b_HLT_DiPFJetAve220_HFJEC);
   fChain->SetBranchAddress("HLT_DiPFJetAve300_HFJEC", &HLT_DiPFJetAve300_HFJEC, &b_HLT_DiPFJetAve300_HFJEC);
   fChain->SetBranchAddress("HLT_AK8PFJet40", &HLT_AK8PFJet40, &b_HLT_AK8PFJet40);
   fChain->SetBranchAddress("HLT_AK8PFJet60", &HLT_AK8PFJet60, &b_HLT_AK8PFJet60);
   fChain->SetBranchAddress("HLT_AK8PFJet80", &HLT_AK8PFJet80, &b_HLT_AK8PFJet80);
   fChain->SetBranchAddress("HLT_AK8PFJet140", &HLT_AK8PFJet140, &b_HLT_AK8PFJet140);
   fChain->SetBranchAddress("HLT_AK8PFJet200", &HLT_AK8PFJet200, &b_HLT_AK8PFJet200);
   fChain->SetBranchAddress("HLT_AK8PFJet260", &HLT_AK8PFJet260, &b_HLT_AK8PFJet260);
   fChain->SetBranchAddress("HLT_AK8PFJet320", &HLT_AK8PFJet320, &b_HLT_AK8PFJet320);
   fChain->SetBranchAddress("HLT_AK8PFJet400", &HLT_AK8PFJet400, &b_HLT_AK8PFJet400);
   fChain->SetBranchAddress("HLT_AK8PFJet450", &HLT_AK8PFJet450, &b_HLT_AK8PFJet450);
   fChain->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500, &b_HLT_AK8PFJet500);
   fChain->SetBranchAddress("HLT_AK8PFJet550", &HLT_AK8PFJet550, &b_HLT_AK8PFJet550);
   fChain->SetBranchAddress("HLT_PFJet40", &HLT_PFJet40, &b_HLT_PFJet40);
   fChain->SetBranchAddress("HLT_PFJet60", &HLT_PFJet60, &b_HLT_PFJet60);
   fChain->SetBranchAddress("HLT_PFJet80", &HLT_PFJet80, &b_HLT_PFJet80);
   fChain->SetBranchAddress("HLT_PFJet140", &HLT_PFJet140, &b_HLT_PFJet140);
   fChain->SetBranchAddress("HLT_PFJet200", &HLT_PFJet200, &b_HLT_PFJet200);
   fChain->SetBranchAddress("HLT_PFJet260", &HLT_PFJet260, &b_HLT_PFJet260);
   fChain->SetBranchAddress("HLT_PFJet320", &HLT_PFJet320, &b_HLT_PFJet320);
   fChain->SetBranchAddress("HLT_PFJet400", &HLT_PFJet400, &b_HLT_PFJet400);
   fChain->SetBranchAddress("HLT_PFJet450", &HLT_PFJet450, &b_HLT_PFJet450);
   fChain->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500, &b_HLT_PFJet500);
   fChain->SetBranchAddress("HLT_PFJet550", &HLT_PFJet550, &b_HLT_PFJet550);
   fChain->SetBranchAddress("HLT_PFJetFwd40", &HLT_PFJetFwd40, &b_HLT_PFJetFwd40);
   fChain->SetBranchAddress("HLT_PFJetFwd60", &HLT_PFJetFwd60, &b_HLT_PFJetFwd60);
   fChain->SetBranchAddress("HLT_PFJetFwd80", &HLT_PFJetFwd80, &b_HLT_PFJetFwd80);
   fChain->SetBranchAddress("HLT_PFJetFwd140", &HLT_PFJetFwd140, &b_HLT_PFJetFwd140);
   fChain->SetBranchAddress("HLT_PFJetFwd200", &HLT_PFJetFwd200, &b_HLT_PFJetFwd200);
   fChain->SetBranchAddress("HLT_PFJetFwd260", &HLT_PFJetFwd260, &b_HLT_PFJetFwd260);
   fChain->SetBranchAddress("HLT_PFJetFwd320", &HLT_PFJetFwd320, &b_HLT_PFJetFwd320);
   fChain->SetBranchAddress("HLT_PFJetFwd400", &HLT_PFJetFwd400, &b_HLT_PFJetFwd400);
   fChain->SetBranchAddress("HLT_PFJetFwd450", &HLT_PFJetFwd450, &b_HLT_PFJetFwd450);
   fChain->SetBranchAddress("HLT_PFJetFwd500", &HLT_PFJetFwd500, &b_HLT_PFJetFwd500);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd40", &HLT_AK8PFJetFwd40, &b_HLT_AK8PFJetFwd40);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd60", &HLT_AK8PFJetFwd60, &b_HLT_AK8PFJetFwd60);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd80", &HLT_AK8PFJetFwd80, &b_HLT_AK8PFJetFwd80);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd140", &HLT_AK8PFJetFwd140, &b_HLT_AK8PFJetFwd140);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd200", &HLT_AK8PFJetFwd200, &b_HLT_AK8PFJetFwd200);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd260", &HLT_AK8PFJetFwd260, &b_HLT_AK8PFJetFwd260);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd320", &HLT_AK8PFJetFwd320, &b_HLT_AK8PFJetFwd320);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd400", &HLT_AK8PFJetFwd400, &b_HLT_AK8PFJetFwd400);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd450", &HLT_AK8PFJetFwd450, &b_HLT_AK8PFJetFwd450);
   fChain->SetBranchAddress("HLT_AK8PFJetFwd500", &HLT_AK8PFJetFwd500, &b_HLT_AK8PFJetFwd500);
   fChain->SetBranchAddress("HLT_PFHT180", &HLT_PFHT180, &b_HLT_PFHT180);
   fChain->SetBranchAddress("HLT_PFHT250", &HLT_PFHT250, &b_HLT_PFHT250);
   fChain->SetBranchAddress("HLT_PFHT370", &HLT_PFHT370, &b_HLT_PFHT370);
   fChain->SetBranchAddress("HLT_PFHT430", &HLT_PFHT430, &b_HLT_PFHT430);
   fChain->SetBranchAddress("HLT_PFHT510", &HLT_PFHT510, &b_HLT_PFHT510);
   fChain->SetBranchAddress("HLT_PFHT590", &HLT_PFHT590, &b_HLT_PFHT590);
   fChain->SetBranchAddress("HLT_PFHT680", &HLT_PFHT680, &b_HLT_PFHT680);
   fChain->SetBranchAddress("HLT_PFHT780", &HLT_PFHT780, &b_HLT_PFHT780);
   fChain->SetBranchAddress("HLT_PFHT890", &HLT_PFHT890, &b_HLT_PFHT890);
   fChain->SetBranchAddress("HLT_PFHT1050", &HLT_PFHT1050, &b_HLT_PFHT1050);
   fChain->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
   fChain->SetBranchAddress("HLT_PFHT500_PFMET110_PFMHT110_IDTight", &HLT_PFHT500_PFMET110_PFMHT110_IDTight, &b_HLT_PFHT500_PFMET110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
   fChain->SetBranchAddress("HLT_PFHT700_PFMET95_PFMHT95_IDTight", &HLT_PFHT700_PFMET95_PFMHT95_IDTight, &b_HLT_PFHT700_PFMET95_PFMHT95_IDTight);
   fChain->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
   fChain->SetBranchAddress("HLT_PFHT800_PFMET85_PFMHT85_IDTight", &HLT_PFHT800_PFMET85_PFMHT85_IDTight, &b_HLT_PFHT800_PFMET85_PFMHT85_IDTight);
   fChain->SetBranchAddress("HLT_PFMET110_PFMHT110_IDTight", &HLT_PFMET110_PFMHT110_IDTight, &b_HLT_PFMET110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight, &b_HLT_PFMET120_PFMHT120_IDTight);
   fChain->SetBranchAddress("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight, &b_HLT_PFMET130_PFMHT130_IDTight);
   fChain->SetBranchAddress("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight, &b_HLT_PFMET140_PFMHT140_IDTight);
   fChain->SetBranchAddress("HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1", &HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1, &b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1", &HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1, &b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1", &HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1, &b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1", &HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1, &b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1", &HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1, &b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1);
   fChain->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMET120_PFMHT120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60", &HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne110_PFMHT110_IDTight", &HLT_PFMETTypeOne110_PFMHT110_IDTight, &b_HLT_PFMETTypeOne110_PFMHT110_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne120_PFMHT120_IDTight", &HLT_PFMETTypeOne120_PFMHT120_IDTight, &b_HLT_PFMETTypeOne120_PFMHT120_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne130_PFMHT130_IDTight", &HLT_PFMETTypeOne130_PFMHT130_IDTight, &b_HLT_PFMETTypeOne130_PFMHT130_IDTight);
   fChain->SetBranchAddress("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight, &b_HLT_PFMETTypeOne140_PFMHT140_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight);
   fChain->SetBranchAddress("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu110_PFMHTNoMu110_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu130_PFMHTNoMu130_IDTight);
   fChain->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight, &b_HLT_MonoCentralPFJet80_PFMETNoMu140_PFMHTNoMu140_IDTight);
   fChain->SetBranchAddress("HLT_L1ETMHadSeeds", &HLT_L1ETMHadSeeds, &b_HLT_L1ETMHadSeeds);
   fChain->SetBranchAddress("HLT_CaloMHT90", &HLT_CaloMHT90, &b_HLT_CaloMHT90);
   fChain->SetBranchAddress("HLT_CaloMET80_NotCleaned", &HLT_CaloMET80_NotCleaned, &b_HLT_CaloMET80_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET90_NotCleaned", &HLT_CaloMET90_NotCleaned, &b_HLT_CaloMET90_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET100_NotCleaned", &HLT_CaloMET100_NotCleaned, &b_HLT_CaloMET100_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET110_NotCleaned", &HLT_CaloMET110_NotCleaned, &b_HLT_CaloMET110_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET250_NotCleaned", &HLT_CaloMET250_NotCleaned, &b_HLT_CaloMET250_NotCleaned);
   fChain->SetBranchAddress("HLT_CaloMET70_HBHECleaned", &HLT_CaloMET70_HBHECleaned, &b_HLT_CaloMET70_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET80_HBHECleaned", &HLT_CaloMET80_HBHECleaned, &b_HLT_CaloMET80_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET90_HBHECleaned", &HLT_CaloMET90_HBHECleaned, &b_HLT_CaloMET90_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET100_HBHECleaned", &HLT_CaloMET100_HBHECleaned, &b_HLT_CaloMET100_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET250_HBHECleaned", &HLT_CaloMET250_HBHECleaned, &b_HLT_CaloMET250_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET300_HBHECleaned", &HLT_CaloMET300_HBHECleaned, &b_HLT_CaloMET300_HBHECleaned);
   fChain->SetBranchAddress("HLT_CaloMET350_HBHECleaned", &HLT_CaloMET350_HBHECleaned, &b_HLT_CaloMET350_HBHECleaned);
   fChain->SetBranchAddress("HLT_PFMET200_NotCleaned", &HLT_PFMET200_NotCleaned, &b_HLT_PFMET200_NotCleaned);
   fChain->SetBranchAddress("HLT_PFMET200_HBHECleaned", &HLT_PFMET200_HBHECleaned, &b_HLT_PFMET200_HBHECleaned);
   fChain->SetBranchAddress("HLT_PFMET250_HBHECleaned", &HLT_PFMET250_HBHECleaned, &b_HLT_PFMET250_HBHECleaned);
   fChain->SetBranchAddress("HLT_PFMET300_HBHECleaned", &HLT_PFMET300_HBHECleaned, &b_HLT_PFMET300_HBHECleaned);
   fChain->SetBranchAddress("HLT_PFMET200_HBHE_BeamHaloCleaned", &HLT_PFMET200_HBHE_BeamHaloCleaned, &b_HLT_PFMET200_HBHE_BeamHaloCleaned);
   fChain->SetBranchAddress("HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned", &HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned, &b_HLT_PFMETTypeOne200_HBHE_BeamHaloCleaned);
   fChain->SetBranchAddress("HLT_MET105_IsoTrk50", &HLT_MET105_IsoTrk50, &b_HLT_MET105_IsoTrk50);
   fChain->SetBranchAddress("HLT_MET120_IsoTrk50", &HLT_MET120_IsoTrk50, &b_HLT_MET120_IsoTrk50);
   fChain->SetBranchAddress("HLT_SingleJet30_Mu12_SinglePFJet40", &HLT_SingleJet30_Mu12_SinglePFJet40, &b_HLT_SingleJet30_Mu12_SinglePFJet40);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33", &HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets40_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33", &HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets100_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33", &HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets200_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33", &HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets350_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets40MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets54MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_Mu12_DoublePFJets62MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets40_CaloBTagCSV_p33", &HLT_DoublePFJets40_CaloBTagCSV_p33, &b_HLT_DoublePFJets40_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets100_CaloBTagCSV_p33", &HLT_DoublePFJets100_CaloBTagCSV_p33, &b_HLT_DoublePFJets100_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets200_CaloBTagCSV_p33", &HLT_DoublePFJets200_CaloBTagCSV_p33, &b_HLT_DoublePFJets200_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets350_CaloBTagCSV_p33", &HLT_DoublePFJets350_CaloBTagCSV_p33, &b_HLT_DoublePFJets350_CaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_DoublePFJets100MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_DoublePFJets116MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33", &HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33, &b_HLT_DoublePFJets128MaxDeta1p6_DoubleCaloBTagCSV_p33);
   fChain->SetBranchAddress("HLT_Photon300_NoHE", &HLT_Photon300_NoHE, &b_HLT_Photon300_NoHE);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL", &HLT_Mu8_TrkIsoVVL, &b_HLT_Mu8_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("HLT_Mu8_DiEle12_CaloIdL_TrackIdL", &HLT_Mu8_DiEle12_CaloIdL_TrackIdL, &b_HLT_Mu8_DiEle12_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350_DZ);
   fChain->SetBranchAddress("HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350", &HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350, &b_HLT_Mu8_Ele8_CaloIdM_TrackIdM_Mass8_PFHT350);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu17_TrkIsoVVL", &HLT_Mu17_TrkIsoVVL, &b_HLT_Mu17_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_Mu19_TrkIsoVVL", &HLT_Mu19_TrkIsoVVL, &b_HLT_Mu19_TrkIsoVVL);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet20_Mu5", &HLT_BTagMu_AK4DiJet20_Mu5, &b_HLT_BTagMu_AK4DiJet20_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet40_Mu5", &HLT_BTagMu_AK4DiJet40_Mu5, &b_HLT_BTagMu_AK4DiJet40_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet70_Mu5", &HLT_BTagMu_AK4DiJet70_Mu5, &b_HLT_BTagMu_AK4DiJet70_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet110_Mu5", &HLT_BTagMu_AK4DiJet110_Mu5, &b_HLT_BTagMu_AK4DiJet110_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4DiJet170_Mu5", &HLT_BTagMu_AK4DiJet170_Mu5, &b_HLT_BTagMu_AK4DiJet170_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK4Jet300_Mu5", &HLT_BTagMu_AK4Jet300_Mu5, &b_HLT_BTagMu_AK4Jet300_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK8DiJet170_Mu5", &HLT_BTagMu_AK8DiJet170_Mu5, &b_HLT_BTagMu_AK8DiJet170_Mu5);
   fChain->SetBranchAddress("HLT_BTagMu_AK8Jet300_Mu5", &HLT_BTagMu_AK8Jet300_Mu5, &b_HLT_BTagMu_AK8Jet300_Mu5);
   fChain->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", &HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL);
   fChain->SetBranchAddress("HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", &HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ, &b_HLT_Mu12_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ);
   fChain->SetBranchAddress("HLT_Mu12_DoublePhoton20", &HLT_Mu12_DoublePhoton20, &b_HLT_Mu12_DoublePhoton20);
   fChain->SetBranchAddress("HLT_TriplePhoton_20_20_20_CaloIdLV2", &HLT_TriplePhoton_20_20_20_CaloIdLV2, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2);
   fChain->SetBranchAddress("HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_20_20_20_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_TriplePhoton_30_30_10_CaloIdLV2", &HLT_TriplePhoton_30_30_10_CaloIdLV2, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2);
   fChain->SetBranchAddress("HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_30_30_10_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL", &HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL, &b_HLT_TriplePhoton_35_35_5_CaloIdLV2_R9IdVL);
   fChain->SetBranchAddress("HLT_Photon25", &HLT_Photon25, &b_HLT_Photon25);
   fChain->SetBranchAddress("HLT_Photon33", &HLT_Photon33, &b_HLT_Photon33);
   fChain->SetBranchAddress("HLT_Photon50", &HLT_Photon50, &b_HLT_Photon50);
   fChain->SetBranchAddress("HLT_Photon75", &HLT_Photon75, &b_HLT_Photon75);
   fChain->SetBranchAddress("HLT_Photon90", &HLT_Photon90, &b_HLT_Photon90);
   fChain->SetBranchAddress("HLT_Photon120", &HLT_Photon120, &b_HLT_Photon120);
   fChain->SetBranchAddress("HLT_Photon150", &HLT_Photon150, &b_HLT_Photon150);
   fChain->SetBranchAddress("HLT_Photon175", &HLT_Photon175, &b_HLT_Photon175);
   fChain->SetBranchAddress("HLT_Photon200", &HLT_Photon200, &b_HLT_Photon200);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_IsoM", &HLT_Photon50_R9Id90_HE10_IsoM, &b_HLT_Photon50_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM", &HLT_Photon75_R9Id90_HE10_IsoM, &b_HLT_Photon75_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon90_R9Id90_HE10_IsoM", &HLT_Photon90_R9Id90_HE10_IsoM, &b_HLT_Photon90_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon120_R9Id90_HE10_IsoM", &HLT_Photon120_R9Id90_HE10_IsoM, &b_HLT_Photon120_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon165_R9Id90_HE10_IsoM", &HLT_Photon165_R9Id90_HE10_IsoM, &b_HLT_Photon165_R9Id90_HE10_IsoM);
   fChain->SetBranchAddress("HLT_Photon90_CaloIdL_PFHT700", &HLT_Photon90_CaloIdL_PFHT700, &b_HLT_Photon90_CaloIdL_PFHT700);
   fChain->SetBranchAddress("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass90);
   fChain->SetBranchAddress("HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95", &HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95, &b_HLT_Diphoton30_22_R9Id_OR_IsoCaloId_AND_HE_R9Id_Mass95);
   fChain->SetBranchAddress("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55", &HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55, &b_HLT_Diphoton30PV_18PV_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55", &HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55, &b_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55", &HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55, &b_HLT_Diphoton30EB_18EB_R9Id_OR_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_L1_NoOS", &HLT_Dimuon0_Jpsi_L1_NoOS, &b_HLT_Dimuon0_Jpsi_L1_NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_NoOS", &HLT_Dimuon0_Jpsi_NoVertexing_NoOS, &b_HLT_Dimuon0_Jpsi_NoVertexing_NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi", &HLT_Dimuon0_Jpsi, &b_HLT_Dimuon0_Jpsi);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing", &HLT_Dimuon0_Jpsi_NoVertexing, &b_HLT_Dimuon0_Jpsi_NoVertexing);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_L1_4R_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R", &HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R, &b_HLT_Dimuon0_Jpsi_NoVertexing_L1_4R_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_Jpsi3p5_Muon2", &HLT_Dimuon0_Jpsi3p5_Muon2, &b_HLT_Dimuon0_Jpsi3p5_Muon2);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5", &HLT_Dimuon0_Upsilon_L1_4p5, &b_HLT_Dimuon0_Upsilon_L1_4p5);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_5", &HLT_Dimuon0_Upsilon_L1_5, &b_HLT_Dimuon0_Upsilon_L1_5);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5NoOS", &HLT_Dimuon0_Upsilon_L1_4p5NoOS, &b_HLT_Dimuon0_Upsilon_L1_4p5NoOS);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5er2p0", &HLT_Dimuon0_Upsilon_L1_4p5er2p0, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_4p5er2p0M", &HLT_Dimuon0_Upsilon_L1_4p5er2p0M, &b_HLT_Dimuon0_Upsilon_L1_4p5er2p0M);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_NoVertexing", &HLT_Dimuon0_Upsilon_NoVertexing, &b_HLT_Dimuon0_Upsilon_NoVertexing);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_L1_5M", &HLT_Dimuon0_Upsilon_L1_5M, &b_HLT_Dimuon0_Upsilon_L1_5M);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_0er1p5R", &HLT_Dimuon0_LowMass_L1_0er1p5R, &b_HLT_Dimuon0_LowMass_L1_0er1p5R);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_0er1p5", &HLT_Dimuon0_LowMass_L1_0er1p5, &b_HLT_Dimuon0_LowMass_L1_0er1p5);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass", &HLT_Dimuon0_LowMass, &b_HLT_Dimuon0_LowMass);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_4", &HLT_Dimuon0_LowMass_L1_4, &b_HLT_Dimuon0_LowMass_L1_4);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_4R", &HLT_Dimuon0_LowMass_L1_4R, &b_HLT_Dimuon0_LowMass_L1_4R);
   fChain->SetBranchAddress("HLT_Dimuon0_LowMass_L1_TM530", &HLT_Dimuon0_LowMass_L1_TM530, &b_HLT_Dimuon0_LowMass_L1_TM530);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_L1_TM0", &HLT_Dimuon0_Upsilon_Muon_L1_TM0, &b_HLT_Dimuon0_Upsilon_Muon_L1_TM0);
   fChain->SetBranchAddress("HLT_Dimuon0_Upsilon_Muon_NoL1Mass", &HLT_Dimuon0_Upsilon_Muon_NoL1Mass, &b_HLT_Dimuon0_Upsilon_Muon_NoL1Mass);
   fChain->SetBranchAddress("HLT_TripleMu_5_3_3_Mass3p8to60_DZ", &HLT_TripleMu_5_3_3_Mass3p8to60_DZ, &b_HLT_TripleMu_5_3_3_Mass3p8to60_DZ);
   fChain->SetBranchAddress("HLT_TripleMu_10_5_5_DZ", &HLT_TripleMu_10_5_5_DZ, &b_HLT_TripleMu_10_5_5_DZ);
   fChain->SetBranchAddress("HLT_TripleMu_12_10_5", &HLT_TripleMu_12_10_5, &b_HLT_TripleMu_12_10_5);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_Tau15_Charge1);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15);
   fChain->SetBranchAddress("HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1", &HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1, &b_HLT_Tau3Mu_Mu7_Mu1_TkMu1_IsoTau15_Charge1);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET50_PFMHT60", &HLT_DoubleMu3_DZ_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DZ_PFMET50_PFMHT60);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET70_PFMHT70", &HLT_DoubleMu3_DZ_PFMET70_PFMHT70, &b_HLT_DoubleMu3_DZ_PFMET70_PFMHT70);
   fChain->SetBranchAddress("HLT_DoubleMu3_DZ_PFMET90_PFMHT90", &HLT_DoubleMu3_DZ_PFMET90_PFMHT90, &b_HLT_DoubleMu3_DZ_PFMET90_PFMHT90);
   fChain->SetBranchAddress("HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass", &HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass, &b_HLT_DoubleMu3_Trk_Tau3mu_NoL1Mass);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_Displaced", &HLT_DoubleMu4_Jpsi_Displaced, &b_HLT_DoubleMu4_Jpsi_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu4_Jpsi_NoVertexing", &HLT_DoubleMu4_Jpsi_NoVertexing, &b_HLT_DoubleMu4_Jpsi_NoVertexing);
   fChain->SetBranchAddress("HLT_DoubleMu4_JpsiTrkTrk_Displaced", &HLT_DoubleMu4_JpsiTrkTrk_Displaced, &b_HLT_DoubleMu4_JpsiTrkTrk_Displaced);
   fChain->SetBranchAddress("HLT_DoubleMu43NoFiltersNoVtx", &HLT_DoubleMu43NoFiltersNoVtx, &b_HLT_DoubleMu43NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_DoubleMu48NoFiltersNoVtx", &HLT_DoubleMu48NoFiltersNoVtx, &b_HLT_DoubleMu48NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL", &HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL, &b_HLT_Mu43NoFiltersNoVtx_Photon43_CaloIdL);
   fChain->SetBranchAddress("HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL", &HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL, &b_HLT_Mu48NoFiltersNoVtx_Photon48_CaloIdL);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_L1_DM4", &HLT_DoubleMu20_7_Mass0to30_L1_DM4, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_L1_DM4EG", &HLT_DoubleMu20_7_Mass0to30_L1_DM4EG, &b_HLT_DoubleMu20_7_Mass0to30_L1_DM4EG);
   fChain->SetBranchAddress("HLT_HT425", &HLT_HT425, &b_HLT_HT425);
   fChain->SetBranchAddress("HLT_HT430_DisplacedDijet40_DisplacedTrack", &HLT_HT430_DisplacedDijet40_DisplacedTrack, &b_HLT_HT430_DisplacedDijet40_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT430_DisplacedDijet60_DisplacedTrack", &HLT_HT430_DisplacedDijet60_DisplacedTrack, &b_HLT_HT430_DisplacedDijet60_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT430_DisplacedDijet80_DisplacedTrack", &HLT_HT430_DisplacedDijet80_DisplacedTrack, &b_HLT_HT430_DisplacedDijet80_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT400_DisplacedDijet40_DisplacedTrack", &HLT_HT400_DisplacedDijet40_DisplacedTrack, &b_HLT_HT400_DisplacedDijet40_DisplacedTrack);
   fChain->SetBranchAddress("HLT_HT650_DisplacedDijet60_Inclusive", &HLT_HT650_DisplacedDijet60_Inclusive, &b_HLT_HT650_DisplacedDijet60_Inclusive);
   fChain->SetBranchAddress("HLT_HT550_DisplacedDijet80_Inclusive", &HLT_HT550_DisplacedDijet80_Inclusive, &b_HLT_HT550_DisplacedDijet80_Inclusive);
   fChain->SetBranchAddress("HLT_HT550_DisplacedDijet60_Inclusive", &HLT_HT550_DisplacedDijet60_Inclusive, &b_HLT_HT550_DisplacedDijet60_Inclusive);
   fChain->SetBranchAddress("HLT_HT650_DisplacedDijet80_Inclusive", &HLT_HT650_DisplacedDijet80_Inclusive, &b_HLT_HT650_DisplacedDijet80_Inclusive);
   fChain->SetBranchAddress("HLT_HT750_DisplacedDijet80_Inclusive", &HLT_HT750_DisplacedDijet80_Inclusive, &b_HLT_HT750_DisplacedDijet80_Inclusive);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET110", &HLT_DiJet110_35_Mjj650_PFMET110, &b_HLT_DiJet110_35_Mjj650_PFMET110);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET120", &HLT_DiJet110_35_Mjj650_PFMET120, &b_HLT_DiJet110_35_Mjj650_PFMET120);
   fChain->SetBranchAddress("HLT_DiJet110_35_Mjj650_PFMET130", &HLT_DiJet110_35_Mjj650_PFMET130, &b_HLT_DiJet110_35_Mjj650_PFMET130);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET110", &HLT_TripleJet110_35_35_Mjj650_PFMET110, &b_HLT_TripleJet110_35_35_Mjj650_PFMET110);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET120", &HLT_TripleJet110_35_35_Mjj650_PFMET120, &b_HLT_TripleJet110_35_35_Mjj650_PFMET120);
   fChain->SetBranchAddress("HLT_TripleJet110_35_35_Mjj650_PFMET130", &HLT_TripleJet110_35_35_Mjj650_PFMET130, &b_HLT_TripleJet110_35_35_Mjj650_PFMET130);
   fChain->SetBranchAddress("HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg", &HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg, &b_HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg", &HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg, &b_HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg", &HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg, &b_HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned", &HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned, &b_HLT_Ele30_eta2p1_WPTight_Gsf_CentralPFJet35_EleCleaned);
   fChain->SetBranchAddress("HLT_Ele28_eta2p1_WPTight_Gsf_HT150", &HLT_Ele28_eta2p1_WPTight_Gsf_HT150, &b_HLT_Ele28_eta2p1_WPTight_Gsf_HT150);
   fChain->SetBranchAddress("HLT_Ele28_HighEta_SC20_Mass55", &HLT_Ele28_HighEta_SC20_Mass55, &b_HLT_Ele28_HighEta_SC20_Mass55);
   fChain->SetBranchAddress("HLT_DoubleMu20_7_Mass0to30_Photon23", &HLT_DoubleMu20_7_Mass0to30_Photon23, &b_HLT_DoubleMu20_7_Mass0to30_Photon23);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5", &HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5, &b_HLT_Ele15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450_PFMET50", &HLT_Ele15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Ele15_IsoVVVL_PFHT450_PFMET50);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT450", &HLT_Ele15_IsoVVVL_PFHT450, &b_HLT_Ele15_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Ele50_IsoVVVL_PFHT450", &HLT_Ele50_IsoVVVL_PFHT450, &b_HLT_Ele50_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Ele15_IsoVVVL_PFHT600", &HLT_Ele15_IsoVVVL_PFHT600, &b_HLT_Ele15_IsoVVVL_PFHT600);
   fChain->SetBranchAddress("HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60", &HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60, &b_HLT_Mu8_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT300_PFMETNoMu60);
   fChain->SetBranchAddress("HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60", &HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60, &b_HLT_Mu10_TrkIsoVVL_DiPFJet40_DEta3p5_MJJ750_HTT350_PFMETNoMu60);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5", &HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5, &b_HLT_Mu15_IsoVVVL_PFHT450_CaloBTagCSV_4p5);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450_PFMET50", &HLT_Mu15_IsoVVVL_PFHT450_PFMET50, &b_HLT_Mu15_IsoVVVL_PFHT450_PFMET50);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT450", &HLT_Mu15_IsoVVVL_PFHT450, &b_HLT_Mu15_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Mu50_IsoVVVL_PFHT450", &HLT_Mu50_IsoVVVL_PFHT450, &b_HLT_Mu50_IsoVVVL_PFHT450);
   fChain->SetBranchAddress("HLT_Mu15_IsoVVVL_PFHT600", &HLT_Mu15_IsoVVVL_PFHT600, &b_HLT_Mu15_IsoVVVL_PFHT600);
   fChain->SetBranchAddress("HLT_Dimuon10_PsiPrime_Barrel_Seagulls", &HLT_Dimuon10_PsiPrime_Barrel_Seagulls, &b_HLT_Dimuon10_PsiPrime_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon20_Jpsi_Barrel_Seagulls", &HLT_Dimuon20_Jpsi_Barrel_Seagulls, &b_HLT_Dimuon20_Jpsi_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon10_Upsilon_Barrel_Seagulls", &HLT_Dimuon10_Upsilon_Barrel_Seagulls, &b_HLT_Dimuon10_Upsilon_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon12_Upsilon_eta1p5", &HLT_Dimuon12_Upsilon_eta1p5, &b_HLT_Dimuon12_Upsilon_eta1p5);
   fChain->SetBranchAddress("HLT_Dimuon14_Phi_Barrel_Seagulls", &HLT_Dimuon14_Phi_Barrel_Seagulls, &b_HLT_Dimuon14_Phi_Barrel_Seagulls);
   fChain->SetBranchAddress("HLT_Dimuon18_PsiPrime", &HLT_Dimuon18_PsiPrime, &b_HLT_Dimuon18_PsiPrime);
   fChain->SetBranchAddress("HLT_Dimuon25_Jpsi", &HLT_Dimuon25_Jpsi, &b_HLT_Dimuon25_Jpsi);
   fChain->SetBranchAddress("HLT_Dimuon18_PsiPrime_noCorrL1", &HLT_Dimuon18_PsiPrime_noCorrL1, &b_HLT_Dimuon18_PsiPrime_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon24_Upsilon_noCorrL1", &HLT_Dimuon24_Upsilon_noCorrL1, &b_HLT_Dimuon24_Upsilon_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon24_Phi_noCorrL1", &HLT_Dimuon24_Phi_noCorrL1, &b_HLT_Dimuon24_Phi_noCorrL1);
   fChain->SetBranchAddress("HLT_Dimuon25_Jpsi_noCorrL1", &HLT_Dimuon25_Jpsi_noCorrL1, &b_HLT_Dimuon25_Jpsi_noCorrL1);
   fChain->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL_DZ);
   fChain->SetBranchAddress("HLT_DiMu9_Ele9_CaloIdL_TrackIdL", &HLT_DiMu9_Ele9_CaloIdL_TrackIdL, &b_HLT_DiMu9_Ele9_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_DoubleIsoMu20_eta2p1", &HLT_DoubleIsoMu20_eta2p1, &b_HLT_DoubleIsoMu20_eta2p1);
   fChain->SetBranchAddress("HLT_DoubleIsoMu24_eta2p1", &HLT_DoubleIsoMu24_eta2p1, &b_HLT_DoubleIsoMu24_eta2p1);
   fChain->SetBranchAddress("HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx", &HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx, &b_HLT_TrkMu12_DoubleTrkMu5NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx", &HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx, &b_HLT_TrkMu16_DoubleTrkMu6NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx", &HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx, &b_HLT_TrkMu17_DoubleTrkMu8NoFiltersNoVtx);
   fChain->SetBranchAddress("HLT_Mu8", &HLT_Mu8, &b_HLT_Mu8);
   fChain->SetBranchAddress("HLT_Mu17", &HLT_Mu17, &b_HLT_Mu17);
   fChain->SetBranchAddress("HLT_Mu19", &HLT_Mu19, &b_HLT_Mu19);
   fChain->SetBranchAddress("HLT_Mu17_Photon30_IsoCaloId", &HLT_Mu17_Photon30_IsoCaloId, &b_HLT_Mu17_Photon30_IsoCaloId);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30", &HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30, &b_HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
   fChain->SetBranchAddress("HLT_Ele8_CaloIdM_TrackIdM_PFJet30", &HLT_Ele8_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele8_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele17_CaloIdM_TrackIdM_PFJet30", &HLT_Ele17_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele17_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele23_CaloIdM_TrackIdM_PFJet30", &HLT_Ele23_CaloIdM_TrackIdM_PFJet30, &b_HLT_Ele23_CaloIdM_TrackIdM_PFJet30);
   fChain->SetBranchAddress("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165", &HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165, &b_HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165);
   fChain->SetBranchAddress("HLT_Ele115_CaloIdVT_GsfTrkIdT", &HLT_Ele115_CaloIdVT_GsfTrkIdT, &b_HLT_Ele115_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele135_CaloIdVT_GsfTrkIdT", &HLT_Ele135_CaloIdVT_GsfTrkIdT, &b_HLT_Ele135_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele145_CaloIdVT_GsfTrkIdT", &HLT_Ele145_CaloIdVT_GsfTrkIdT, &b_HLT_Ele145_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele200_CaloIdVT_GsfTrkIdT", &HLT_Ele200_CaloIdVT_GsfTrkIdT, &b_HLT_Ele200_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele250_CaloIdVT_GsfTrkIdT", &HLT_Ele250_CaloIdVT_GsfTrkIdT, &b_HLT_Ele250_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_Ele300_CaloIdVT_GsfTrkIdT", &HLT_Ele300_CaloIdVT_GsfTrkIdT, &b_HLT_Ele300_CaloIdVT_GsfTrkIdT);
   fChain->SetBranchAddress("HLT_PFHT300PT30_QuadPFJet_75_60_45_40", &HLT_PFHT300PT30_QuadPFJet_75_60_45_40, &b_HLT_PFHT300PT30_QuadPFJet_75_60_45_40);
   fChain->SetBranchAddress("HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0", &HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0, &b_HLT_PFHT300PT30_QuadPFJet_75_60_45_40_TriplePFBTagCSV_3p0);
   fChain->SetBranchAddress("HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2", &HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2, &b_HLT_PFHT380_SixPFJet32_DoublePFBTagCSV_2p2);
   fChain->SetBranchAddress("HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2", &HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2, &b_HLT_PFHT380_SixPFJet32_DoublePFBTagDeepCSV_2p2);
   fChain->SetBranchAddress("HLT_PFHT380_SixPFJet32", &HLT_PFHT380_SixPFJet32, &b_HLT_PFHT380_SixPFJet32);
   fChain->SetBranchAddress("HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5", &HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5, &b_HLT_PFHT430_SixPFJet40_PFBTagCSV_1p5);
   fChain->SetBranchAddress("HLT_PFHT430_SixPFJet40", &HLT_PFHT430_SixPFJet40, &b_HLT_PFHT430_SixPFJet40);
   fChain->SetBranchAddress("HLT_PFHT350", &HLT_PFHT350, &b_HLT_PFHT350);
   fChain->SetBranchAddress("HLT_PFHT350MinPFJet15", &HLT_PFHT350MinPFJet15, &b_HLT_PFHT350MinPFJet15);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL", &HLT_Photon60_R9Id90_CaloIdL_IsoL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL);
   fChain->SetBranchAddress("HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15", &HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15, &b_HLT_Photon60_R9Id90_CaloIdL_IsoL_DisplacedIdL_PFHT350MinPFJet15);
   fChain->SetBranchAddress("HLT_FullTrack_Multiplicity85", &HLT_FullTrack_Multiplicity85, &b_HLT_FullTrack_Multiplicity85);
   fChain->SetBranchAddress("HLT_FullTrack_Multiplicity100", &HLT_FullTrack_Multiplicity100, &b_HLT_FullTrack_Multiplicity100);
   fChain->SetBranchAddress("HLT_FullTrack_Multiplicity130", &HLT_FullTrack_Multiplicity130, &b_HLT_FullTrack_Multiplicity130);
   fChain->SetBranchAddress("HLT_FullTrack_Multiplicity155", &HLT_FullTrack_Multiplicity155, &b_HLT_FullTrack_Multiplicity155);
   fChain->SetBranchAddress("HLT_ECALHT800", &HLT_ECALHT800, &b_HLT_ECALHT800);
   fChain->SetBranchAddress("HLT_DiSC30_18_EIso_AND_HE_Mass70", &HLT_DiSC30_18_EIso_AND_HE_Mass70, &b_HLT_DiSC30_18_EIso_AND_HE_Mass70);
   fChain->SetBranchAddress("HLT_Physics", &HLT_Physics, &b_HLT_Physics);
   fChain->SetBranchAddress("HLT_Physics_part0", &HLT_Physics_part0, &b_HLT_Physics_part0);
   fChain->SetBranchAddress("HLT_Physics_part1", &HLT_Physics_part1, &b_HLT_Physics_part1);
   fChain->SetBranchAddress("HLT_Physics_part2", &HLT_Physics_part2, &b_HLT_Physics_part2);
   fChain->SetBranchAddress("HLT_Physics_part3", &HLT_Physics_part3, &b_HLT_Physics_part3);
   fChain->SetBranchAddress("HLT_Physics_part4", &HLT_Physics_part4, &b_HLT_Physics_part4);
   fChain->SetBranchAddress("HLT_Physics_part5", &HLT_Physics_part5, &b_HLT_Physics_part5);
   fChain->SetBranchAddress("HLT_Physics_part6", &HLT_Physics_part6, &b_HLT_Physics_part6);
   fChain->SetBranchAddress("HLT_Physics_part7", &HLT_Physics_part7, &b_HLT_Physics_part7);
   fChain->SetBranchAddress("HLT_Random", &HLT_Random, &b_HLT_Random);
   fChain->SetBranchAddress("HLT_ZeroBias", &HLT_ZeroBias, &b_HLT_ZeroBias);
   fChain->SetBranchAddress("HLT_ZeroBias_part0", &HLT_ZeroBias_part0, &b_HLT_ZeroBias_part0);
   fChain->SetBranchAddress("HLT_ZeroBias_part1", &HLT_ZeroBias_part1, &b_HLT_ZeroBias_part1);
   fChain->SetBranchAddress("HLT_ZeroBias_part2", &HLT_ZeroBias_part2, &b_HLT_ZeroBias_part2);
   fChain->SetBranchAddress("HLT_ZeroBias_part3", &HLT_ZeroBias_part3, &b_HLT_ZeroBias_part3);
   fChain->SetBranchAddress("HLT_ZeroBias_part4", &HLT_ZeroBias_part4, &b_HLT_ZeroBias_part4);
   fChain->SetBranchAddress("HLT_ZeroBias_part5", &HLT_ZeroBias_part5, &b_HLT_ZeroBias_part5);
   fChain->SetBranchAddress("HLT_ZeroBias_part6", &HLT_ZeroBias_part6, &b_HLT_ZeroBias_part6);
   fChain->SetBranchAddress("HLT_ZeroBias_part7", &HLT_ZeroBias_part7, &b_HLT_ZeroBias_part7);
   fChain->SetBranchAddress("HLT_AK4CaloJet30", &HLT_AK4CaloJet30, &b_HLT_AK4CaloJet30);
   fChain->SetBranchAddress("HLT_AK4CaloJet40", &HLT_AK4CaloJet40, &b_HLT_AK4CaloJet40);
   fChain->SetBranchAddress("HLT_AK4CaloJet50", &HLT_AK4CaloJet50, &b_HLT_AK4CaloJet50);
   fChain->SetBranchAddress("HLT_AK4CaloJet80", &HLT_AK4CaloJet80, &b_HLT_AK4CaloJet80);
   fChain->SetBranchAddress("HLT_AK4CaloJet100", &HLT_AK4CaloJet100, &b_HLT_AK4CaloJet100);
   fChain->SetBranchAddress("HLT_AK4CaloJet120", &HLT_AK4CaloJet120, &b_HLT_AK4CaloJet120);
   fChain->SetBranchAddress("HLT_AK4PFJet30", &HLT_AK4PFJet30, &b_HLT_AK4PFJet30);
   fChain->SetBranchAddress("HLT_AK4PFJet50", &HLT_AK4PFJet50, &b_HLT_AK4PFJet50);
   fChain->SetBranchAddress("HLT_AK4PFJet80", &HLT_AK4PFJet80, &b_HLT_AK4PFJet80);
   fChain->SetBranchAddress("HLT_AK4PFJet100", &HLT_AK4PFJet100, &b_HLT_AK4PFJet100);
   fChain->SetBranchAddress("HLT_AK4PFJet120", &HLT_AK4PFJet120, &b_HLT_AK4PFJet120);
   fChain->SetBranchAddress("HLT_HISinglePhoton10_Eta3p1ForPPRef", &HLT_HISinglePhoton10_Eta3p1ForPPRef, &b_HLT_HISinglePhoton10_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_HISinglePhoton20_Eta3p1ForPPRef", &HLT_HISinglePhoton20_Eta3p1ForPPRef, &b_HLT_HISinglePhoton20_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_HISinglePhoton30_Eta3p1ForPPRef", &HLT_HISinglePhoton30_Eta3p1ForPPRef, &b_HLT_HISinglePhoton30_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_HISinglePhoton40_Eta3p1ForPPRef", &HLT_HISinglePhoton40_Eta3p1ForPPRef, &b_HLT_HISinglePhoton40_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_HISinglePhoton50_Eta3p1ForPPRef", &HLT_HISinglePhoton50_Eta3p1ForPPRef, &b_HLT_HISinglePhoton50_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_HISinglePhoton60_Eta3p1ForPPRef", &HLT_HISinglePhoton60_Eta3p1ForPPRef, &b_HLT_HISinglePhoton60_Eta3p1ForPPRef);
   fChain->SetBranchAddress("HLT_Photon20_HoverELoose", &HLT_Photon20_HoverELoose, &b_HLT_Photon20_HoverELoose);
   fChain->SetBranchAddress("HLT_Photon30_HoverELoose", &HLT_Photon30_HoverELoose, &b_HLT_Photon30_HoverELoose);
   fChain->SetBranchAddress("HLT_Photon40_HoverELoose", &HLT_Photon40_HoverELoose, &b_HLT_Photon40_HoverELoose);
   fChain->SetBranchAddress("HLT_Photon50_HoverELoose", &HLT_Photon50_HoverELoose, &b_HLT_Photon50_HoverELoose);
   fChain->SetBranchAddress("HLT_Photon60_HoverELoose", &HLT_Photon60_HoverELoose, &b_HLT_Photon60_HoverELoose);
   fChain->SetBranchAddress("HLT_EcalCalibration", &HLT_EcalCalibration, &b_HLT_EcalCalibration);
   fChain->SetBranchAddress("HLT_HcalCalibration", &HLT_HcalCalibration, &b_HLT_HcalCalibration);
   fChain->SetBranchAddress("HLT_L1UnpairedBunchBptxMinus", &HLT_L1UnpairedBunchBptxMinus, &b_HLT_L1UnpairedBunchBptxMinus);
   fChain->SetBranchAddress("HLT_L1UnpairedBunchBptxPlus", &HLT_L1UnpairedBunchBptxPlus, &b_HLT_L1UnpairedBunchBptxPlus);
   fChain->SetBranchAddress("HLT_L1NotBptxOR", &HLT_L1NotBptxOR, &b_HLT_L1NotBptxOR);
   fChain->SetBranchAddress("HLT_L1MinimumBiasHF_OR", &HLT_L1MinimumBiasHF_OR, &b_HLT_L1MinimumBiasHF_OR);
   fChain->SetBranchAddress("HLT_L1MinimumBiasHF0OR", &HLT_L1MinimumBiasHF0OR, &b_HLT_L1MinimumBiasHF0OR);
   fChain->SetBranchAddress("HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142", &HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142, &b_HLT_L1_CDC_SingleMu_3_er1p2_TOP120_DPHI2p618_3p142);
   fChain->SetBranchAddress("HLT_HcalNZS", &HLT_HcalNZS, &b_HLT_HcalNZS);
   fChain->SetBranchAddress("HLT_HcalPhiSym", &HLT_HcalPhiSym, &b_HLT_HcalPhiSym);
   fChain->SetBranchAddress("HLT_HcalIsolatedbunch", &HLT_HcalIsolatedbunch, &b_HLT_HcalIsolatedbunch);
   fChain->SetBranchAddress("HLT_IsoTrackHB", &HLT_IsoTrackHB, &b_HLT_IsoTrackHB);
   fChain->SetBranchAddress("HLT_IsoTrackHE", &HLT_IsoTrackHE, &b_HLT_IsoTrackHE);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstCollisionAfterAbortGap", &HLT_ZeroBias_FirstCollisionAfterAbortGap, &b_HLT_ZeroBias_FirstCollisionAfterAbortGap);
   fChain->SetBranchAddress("HLT_ZeroBias_IsolatedBunches", &HLT_ZeroBias_IsolatedBunches, &b_HLT_ZeroBias_IsolatedBunches);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstCollisionInTrain", &HLT_ZeroBias_FirstCollisionInTrain, &b_HLT_ZeroBias_FirstCollisionInTrain);
   fChain->SetBranchAddress("HLT_ZeroBias_LastCollisionInTrain", &HLT_ZeroBias_LastCollisionInTrain, &b_HLT_ZeroBias_LastCollisionInTrain);
   fChain->SetBranchAddress("HLT_ZeroBias_FirstBXAfterTrain", &HLT_ZeroBias_FirstBXAfterTrain, &b_HLT_ZeroBias_FirstBXAfterTrain);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1", &HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1, &b_HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1);
   fChain->SetBranchAddress("HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg", &HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg, &b_HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg", &HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg, &b_HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg", &HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg, &b_HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET110);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET120);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET130);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr", &HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_1pr);
   fChain->SetBranchAddress("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1", &HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1, &b_HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1", &HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1, &b_HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1);
   fChain->SetBranchAddress("HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL", &HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL, &b_HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL);
   fChain->SetBranchAddress("HLT_Rsq0p35", &HLT_Rsq0p35, &b_HLT_Rsq0p35);
   fChain->SetBranchAddress("HLT_Rsq0p40", &HLT_Rsq0p40, &b_HLT_Rsq0p40);
   fChain->SetBranchAddress("HLT_RsqMR300_Rsq0p09_MR200", &HLT_RsqMR300_Rsq0p09_MR200, &b_HLT_RsqMR300_Rsq0p09_MR200);
   fChain->SetBranchAddress("HLT_RsqMR320_Rsq0p09_MR200", &HLT_RsqMR320_Rsq0p09_MR200, &b_HLT_RsqMR320_Rsq0p09_MR200);
   fChain->SetBranchAddress("HLT_RsqMR300_Rsq0p09_MR200_4jet", &HLT_RsqMR300_Rsq0p09_MR200_4jet, &b_HLT_RsqMR300_Rsq0p09_MR200_4jet);
   fChain->SetBranchAddress("HLT_RsqMR320_Rsq0p09_MR200_4jet", &HLT_RsqMR320_Rsq0p09_MR200_4jet, &b_HLT_RsqMR320_Rsq0p09_MR200_4jet);
   fChain->SetBranchAddress("HLT_L1_DoubleJet30_Mass_Min400_Mu10", &HLT_L1_DoubleJet30_Mass_Min400_Mu10, &b_HLT_L1_DoubleJet30_Mass_Min400_Mu10);
   fChain->SetBranchAddress("HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1", &HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1", &HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1", &HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1, &b_HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1);
   fChain->SetBranchAddress("HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50", &HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50, &b_HLT_Photon50_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3_PFMET50);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ300DEta3);
   fChain->SetBranchAddress("HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3", &HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3, &b_HLT_Photon75_R9Id90_HE10_IsoM_EBOnly_PFJetsMJJ600DEta3);
   fChain->SetBranchAddress("HLT_PFMET100_PFMHT100_IDTight_PFHT60", &HLT_PFMET100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMET100_PFMHT100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60", &HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60, &b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60", &HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60, &b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_SameSign", &HLT_Mu18_Mu9_SameSign, &b_HLT_Mu18_Mu9_SameSign);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_SameSign_DZ", &HLT_Mu18_Mu9_SameSign_DZ, &b_HLT_Mu18_Mu9_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu18_Mu9", &HLT_Mu18_Mu9, &b_HLT_Mu18_Mu9);
   fChain->SetBranchAddress("HLT_Mu18_Mu9_DZ", &HLT_Mu18_Mu9_DZ, &b_HLT_Mu18_Mu9_DZ);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_SameSign", &HLT_Mu20_Mu10_SameSign, &b_HLT_Mu20_Mu10_SameSign);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_SameSign_DZ", &HLT_Mu20_Mu10_SameSign_DZ, &b_HLT_Mu20_Mu10_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu20_Mu10", &HLT_Mu20_Mu10, &b_HLT_Mu20_Mu10);
   fChain->SetBranchAddress("HLT_Mu20_Mu10_DZ", &HLT_Mu20_Mu10_DZ, &b_HLT_Mu20_Mu10_DZ);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_SameSign", &HLT_Mu23_Mu12_SameSign, &b_HLT_Mu23_Mu12_SameSign);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_SameSign_DZ", &HLT_Mu23_Mu12_SameSign_DZ, &b_HLT_Mu23_Mu12_SameSign_DZ);
   fChain->SetBranchAddress("HLT_Mu23_Mu12", &HLT_Mu23_Mu12, &b_HLT_Mu23_Mu12);
   fChain->SetBranchAddress("HLT_Mu23_Mu12_DZ", &HLT_Mu23_Mu12_DZ, &b_HLT_Mu23_Mu12_DZ);
   fChain->SetBranchAddress("HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi", &HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi, &b_HLT_DoubleMu2_Jpsi_DoubleTrk1_Phi);
   fChain->SetBranchAddress("HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi", &HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi, &b_HLT_DoubleMu2_Jpsi_DoubleTkMu0_Phi);
   fChain->SetBranchAddress("HLT_DoubleMu3_DCA_PFMET50_PFMHT60", &HLT_DoubleMu3_DCA_PFMET50_PFMHT60, &b_HLT_DoubleMu3_DCA_PFMET50_PFMHT60);
   fChain->SetBranchAddress("HLT_TripleMu_5_3_3_Mass3p8to60_DCA", &HLT_TripleMu_5_3_3_Mass3p8to60_DCA, &b_HLT_TripleMu_5_3_3_Mass3p8to60_DCA);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1", &HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1, &b_HLT_QuadPFJet98_83_71_15_DoubleBTagCSV_p013_p08_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1", &HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1, &b_HLT_QuadPFJet103_88_75_15_DoubleBTagCSV_p013_p08_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1", &HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1, &b_HLT_QuadPFJet105_90_76_15_DoubleBTagCSV_p013_p08_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1", &HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1, &b_HLT_QuadPFJet111_90_80_15_DoubleBTagCSV_p013_p08_VBF1);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2", &HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2, &b_HLT_QuadPFJet98_83_71_15_BTagCSV_p013_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2", &HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2, &b_HLT_QuadPFJet103_88_75_15_BTagCSV_p013_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2", &HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2, &b_HLT_QuadPFJet105_88_76_15_BTagCSV_p013_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2", &HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2, &b_HLT_QuadPFJet111_90_80_15_BTagCSV_p013_VBF2);
   fChain->SetBranchAddress("HLT_QuadPFJet98_83_71_15", &HLT_QuadPFJet98_83_71_15, &b_HLT_QuadPFJet98_83_71_15);
   fChain->SetBranchAddress("HLT_QuadPFJet103_88_75_15", &HLT_QuadPFJet103_88_75_15, &b_HLT_QuadPFJet103_88_75_15);
   fChain->SetBranchAddress("HLT_QuadPFJet105_88_76_15", &HLT_QuadPFJet105_88_76_15, &b_HLT_QuadPFJet105_88_76_15);
   fChain->SetBranchAddress("HLT_QuadPFJet111_90_80_15", &HLT_QuadPFJet111_90_80_15, &b_HLT_QuadPFJet111_90_80_15);
   fChain->SetBranchAddress("HLT_AK8PFJet330_PFAK8BTagCSV_p17", &HLT_AK8PFJet330_PFAK8BTagCSV_p17, &b_HLT_AK8PFJet330_PFAK8BTagCSV_p17);
   fChain->SetBranchAddress("HLT_AK8PFJet330_PFAK8BTagCSV_p1", &HLT_AK8PFJet330_PFAK8BTagCSV_p1, &b_HLT_AK8PFJet330_PFAK8BTagCSV_p1);
   fChain->SetBranchAddress("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55", &HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55, &b_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_PixelVeto_Mass55);
   fChain->SetBranchAddress("HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55", &HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55, &b_HLT_Diphoton30_18_PVrealAND_R9Id_AND_IsoCaloId_AND_HE_R9Id_NoPixelVeto_Mass55);
   fChain->SetBranchAddress("HLTriggerFinalPath", &HLTriggerFinalPath, &b_HLTriggerFinalPath);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloFilter", &Flag_CSCTightHaloFilter, &b_Flag_CSCTightHaloFilter);
   fChain->SetBranchAddress("Flag_CSCTightHaloTrkMuUnvetoFilter", &Flag_CSCTightHaloTrkMuUnvetoFilter, &b_Flag_CSCTightHaloTrkMuUnvetoFilter);
   fChain->SetBranchAddress("Flag_CSCTightHalo2015Filter", &Flag_CSCTightHalo2015Filter, &b_Flag_CSCTightHalo2015Filter);
   fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, &b_Flag_globalSuperTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_HcalStripHaloFilter", &Flag_HcalStripHaloFilter, &b_Flag_HcalStripHaloFilter);
   fChain->SetBranchAddress("Flag_hcalLaserEventFilter", &Flag_hcalLaserEventFilter, &b_Flag_hcalLaserEventFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellBoundaryEnergyFilter", &Flag_EcalDeadCellBoundaryEnergyFilter, &b_Flag_EcalDeadCellBoundaryEnergyFilter);
   fChain->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, &b_Flag_ecalBadCalibFilter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_ecalLaserCorrFilter", &Flag_ecalLaserCorrFilter, &b_Flag_ecalLaserCorrFilter);
   fChain->SetBranchAddress("Flag_trkPOGFilters", &Flag_trkPOGFilters, &b_Flag_trkPOGFilters);
   fChain->SetBranchAddress("Flag_chargedHadronTrackResolutionFilter", &Flag_chargedHadronTrackResolutionFilter, &b_Flag_chargedHadronTrackResolutionFilter);
   fChain->SetBranchAddress("Flag_muonBadTrackFilter", &Flag_muonBadTrackFilter, &b_Flag_muonBadTrackFilter);
   fChain->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag_BadChargedCandidateSummer16Filter", &Flag_BadChargedCandidateSummer16Filter, &b_Flag_BadChargedCandidateSummer16Filter);
   fChain->SetBranchAddress("Flag_BadPFMuonSummer16Filter", &Flag_BadPFMuonSummer16Filter, &b_Flag_BadPFMuonSummer16Filter);
   fChain->SetBranchAddress("Flag_trkPOG_manystripclus53X", &Flag_trkPOG_manystripclus53X, &b_Flag_trkPOG_manystripclus53X);
   fChain->SetBranchAddress("Flag_trkPOG_toomanystripclus53X", &Flag_trkPOG_toomanystripclus53X, &b_Flag_trkPOG_toomanystripclus53X);
   fChain->SetBranchAddress("Flag_trkPOG_logErrorTooManyClusters", &Flag_trkPOG_logErrorTooManyClusters, &b_Flag_trkPOG_logErrorTooManyClusters);
   fChain->SetBranchAddress("Flag_METFilters", &Flag_METFilters, &b_Flag_METFilters);
   Notify();
}

Bool_t CMSnanoAOD::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CMSnanoAOD::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CMSnanoAOD::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CMSnanoAOD_cxx
