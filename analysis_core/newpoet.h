#ifndef newpoet_h
#define newpoet_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "Node.h"
#include "TRefArray.h"
#include "TRef.h"
// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class newpoet {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

#define  NNN  50
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           numberelectron;
   Int_t           nelectron_e;
   Float_t         electron_e[NNN];   //[nelectron_e]
   Int_t           nelectron_pt;
   Float_t         electron_pt[NNN];   //[nelectron_pt]
   Int_t           nelectron_px;
   Float_t         electron_px[NNN];   //[nelectron_px]
   Int_t           nelectron_py;
   Float_t         electron_py[NNN];   //[nelectron_py]
   Int_t           nelectron_pz;
   Float_t         electron_pz[NNN];   //[nelectron_pz]
   Int_t           nelectron_eta;
   Float_t         electron_eta[NNN];   //[nelectron_eta]
   Int_t           nelectron_phi;
   Float_t         electron_phi[NNN];   //[nelectron_phi]
   Int_t           nelectron_ch;
   Float_t         electron_ch[NNN];   //[nelectron_ch]
   Int_t           nelectron_iso;
   Float_t         electron_iso[NNN];   //[nelectron_iso]
   Int_t           nelectron_veto;
   Bool_t          electron_veto[NNN];   //[nelectron_veto]
   Int_t           nelectron_isLoose;
   Bool_t          electron_isLoose[NNN];   //[nelectron_isLoose]
   Int_t           nelectron_isMedium;
   Bool_t          electron_isMedium[NNN];   //[nelectron_isMedium]
   Int_t           nelectron_isTight;
   Bool_t          electron_isTight[NNN];   //[nelectron_isTight]
   Int_t           nelectron_dxy;
   Float_t         electron_dxy[NNN];   //[nelectron_dxy]
   Int_t           nelectron_dz;
   Float_t         electron_dz[NNN];   //[nelectron_dz]
   Int_t           nelectron_dxyError;
   Float_t         electron_dxyError[NNN];   //[nelectron_dxyError]
   Int_t           nelectron_dzError;
   Float_t         electron_dzError[NNN];   //[nelectron_dzError]
   Int_t           nelectron_ismvaLoose;
   Int_t           electron_ismvaLoose[NNN];   //[nelectron_ismvaLoose]
   Int_t           nelectron_ismvaTight;
   Int_t           electron_ismvaTight[NNN];   //[nelectron_ismvaTight]
   Int_t           nelectron_ip3d;
   Double_t        electron_ip3d[NNN];   //[nelectron_ip3d]
   Int_t           nelectron_sip3d;
   Double_t        electron_sip3d[NNN];   //[nelectron_sip3d]
   Int_t           numberfatjet;
   Int_t           nfatjet_pt;
   Float_t         fatjet_pt[NNN];   //[nfatjet_pt]
   Int_t           nfatjet_eta;
   Float_t         fatjet_eta[NNN];   //[nfatjet_eta]
   Int_t           nfatjet_phi;
   Float_t         fatjet_phi[NNN];   //[nfatjet_phi]
   Int_t           nfatjet_ch;
   Float_t         fatjet_ch[NNN];   //[nfatjet_ch]
   Int_t           nfatjet_mass;
   Float_t         fatjet_mass[NNN];   //[nfatjet_mass]
   Int_t           ncorr_fatjet_pt;
   Float_t         corr_fatjet_pt[NNN];   //[ncorr_fatjet_pt]
   Int_t           ncorr_fatjet_ptUp;
   Float_t         corr_fatjet_ptUp[NNN];   //[ncorr_fatjet_ptUp]
   Int_t           ncorr_fatjet_ptDown;
   Float_t         corr_fatjet_ptDown[NNN];   //[ncorr_fatjet_ptDown]
   Int_t           ncorr_fatjet_ptSmearUp;
   Float_t         corr_fatjet_ptSmearUp[NNN];   //[ncorr_fatjet_ptSmearUp]
   Int_t           ncorr_fatjet_ptSmearDown;
   Float_t         corr_fatjet_ptSmearDown[NNN];   //[ncorr_fatjet_ptSmearDown]
   Int_t           ncorr_fatjet_mass;
   Float_t         corr_fatjet_mass[NNN];   //[ncorr_fatjet_mass]
   Int_t           ncorr_fatjet_e;
   Float_t         corr_fatjet_e[NNN];   //[ncorr_fatjet_e]
   Int_t           ncorr_fatjet_px;
   Float_t         corr_fatjet_px[NNN];   //[ncorr_fatjet_px]
   Int_t           ncorr_fatjet_py;
   Float_t         corr_fatjet_py[NNN];   //[ncorr_fatjet_py]
   Int_t           ncorr_fatjet_pz;
   Float_t         corr_fatjet_pz[NNN];   //[ncorr_fatjet_pz]
   Int_t           nfatjet_prunedmass;
   Float_t         fatjet_prunedmass[NNN];   //[nfatjet_prunedmass]
   Int_t           nfatjet_softdropmass;
   Float_t         fatjet_softdropmass[NNN];   //[nfatjet_softdropmass]
   Int_t           nfatjet_tau1;
   Float_t         fatjet_tau1[NNN];   //[nfatjet_tau1]
   Int_t           nfatjet_tau2;
   Float_t         fatjet_tau2[NNN];   //[nfatjet_tau2]
   Int_t           nfatjet_tau3;
   Float_t         fatjet_tau3[NNN];   //[nfatjet_tau3]
   Int_t           nfatjet_subjet1_btag;
   Float_t         fatjet_subjet1_btag[NNN];   //[nfatjet_subjet1_btag]
   Int_t           nfatjet_subjet2_btag;
   Float_t         fatjet_subjet2_btag[NNN];   //[nfatjet_subjet2_btag]
   Int_t           nfatjet_subjet1_hflav;
   Float_t         fatjet_subjet1_hflav[NNN];   //[nfatjet_subjet1_hflav]
   Int_t           nfatjet_subjet2_hflav;
   Float_t         fatjet_subjet2_hflav[NNN];   //[nfatjet_subjet2_hflav]
   Int_t           numberjet;
   Int_t           njet_pt;
   Float_t         jet_pt[NNN];   //[njet_pt]
   Int_t           njet_eta;
   Float_t         jet_eta[NNN];   //[njet_eta]
   Int_t           njet_phi;
   Float_t         jet_phi[NNN];   //[njet_phi]
   Int_t           njet_ch;
   Float_t         jet_ch[NNN];   //[njet_ch]
   Int_t           njet_mass;
   Float_t         jet_mass[NNN];   //[njet_mass]
   Int_t           njet_btag;
   Double_t        jet_btag[NNN];   //[njet_btag]
   Int_t           njet_hflav;
   Int_t           jet_hflav[NNN];   //[njet_hflav]
   Int_t           ncorr_jet_pt;
   Float_t         corr_jet_pt[NNN];   //[ncorr_jet_pt]
   Int_t           ncorr_jet_ptUp;
   Float_t         corr_jet_ptUp[NNN];   //[ncorr_jet_ptUp]
   Int_t           ncorr_jet_ptDown;
   Float_t         corr_jet_ptDown[NNN];   //[ncorr_jet_ptDown]
   Int_t           ncorr_jet_ptSmearUp;
   Float_t         corr_jet_ptSmearUp[NNN];   //[ncorr_jet_ptSmearUp]
   Int_t           ncorr_jet_ptSmearDown;
   Float_t         corr_jet_ptSmearDown[NNN];   //[ncorr_jet_ptSmearDown]
   Int_t           ncorr_jet_mass;
   Float_t         corr_jet_mass[NNN];   //[ncorr_jet_mass]
   Int_t           ncorr_jet_e;
   Float_t         corr_jet_e[NNN];   //[ncorr_jet_e]
   Int_t           ncorr_jet_px;
   Float_t         corr_jet_px[NNN];   //[ncorr_jet_px]
   Int_t           ncorr_jet_py;
   Float_t         corr_jet_py[NNN];   //[ncorr_jet_py]
   Int_t           ncorr_jet_pz;
   Float_t         corr_jet_pz[NNN];   //[ncorr_jet_pz]
   Float_t         btag_Weight;
   Float_t         btag_WeightUp;
   Float_t         btag_WeightDn;
   Float_t         met_e;
   Float_t         met_pt;
   Float_t         met_px;
   Float_t         met_py;
   Float_t         met_phi;
   Float_t         met_significance;
   Float_t         met_rawpt;
   Float_t         met_rawphi;
   Float_t         met_rawe;
   Int_t           numbermuon;
   Int_t           nmuon_e;
   Float_t         muon_e[NNN];   //[nmuon_e]
   Int_t           nmuon_pt;
   Float_t         muon_pt[NNN];   //[nmuon_pt]
   Int_t           nmuon_px;
   Float_t         muon_px[NNN];   //[nmuon_px]
   Int_t           nmuon_py;
   Float_t         muon_py[NNN];   //[nmuon_py]
   Int_t           nmuon_pz;
   Float_t         muon_pz[NNN];   //[nmuon_pz]
   Int_t           nmuon_eta;
   Float_t         muon_eta[NNN];   //[nmuon_eta]
   Int_t           nmuon_phi;
   Float_t         muon_phi[NNN];   //[nmuon_phi]
   Int_t           nmuon_ch;
   Float_t         muon_ch[NNN];   //[nmuon_ch]
   Int_t           nmuon_isLoose;
   Int_t           muon_isLoose[NNN];   //[nmuon_isLoose]
   Int_t           nmuon_isMedium;
   Int_t           muon_isMedium[NNN];   //[nmuon_isMedium]
   Int_t           nmuon_isTight;
   Int_t           muon_isTight[NNN];   //[nmuon_isTight]
   Int_t           nmuon_isSoft;
   Int_t           muon_isSoft[NNN];   //[nmuon_isSoft]
   Int_t           nmuon_isHighPt;
   Int_t           muon_isHighPt[NNN];   //[nmuon_isHighPt]
   Int_t           nmuon_dxy;
   Float_t         muon_dxy[NNN];   //[nmuon_dxy]
   Int_t           nmuon_dz;
   Float_t         muon_dz[NNN];   //[nmuon_dz]
   Int_t           nmuon_dxyError;
   Float_t         muon_dxyError[NNN];   //[nmuon_dxyError]
   Int_t           nmuon_dzError;
   Float_t         muon_dzError[NNN];   //[nmuon_dzError]
   Int_t           nmuon_pfreliso03all;
   Float_t         muon_pfreliso03all[NNN];   //[nmuon_pfreliso03all]
   Int_t           nmuon_pfreliso04all;
   Float_t         muon_pfreliso04all[NNN];   //[nmuon_pfreliso04all]
   Int_t           nmuon_pfreliso04DBCorr;
   Float_t         muon_pfreliso04DBCorr[NNN];   //[nmuon_pfreliso04DBCorr]
   Int_t           nmuon_TkIso03;
   Float_t         muon_TkIso03[NNN];   //[nmuon_TkIso03]
   Int_t           nmuon_jetidx;
   Float_t         muon_jetidx[NNN];   //[nmuon_jetidx]
   Int_t           nmuon_genpartidx;
   Float_t         muon_genpartidx[NNN];   //[nmuon_genpartidx]
   Int_t           nmuon_ip3d;
   Float_t         muon_ip3d[NNN];   //[nmuon_ip3d]
   Int_t           nmuon_sip3d;
   Float_t         muon_sip3d[NNN];   //[nmuon_sip3d]
   Int_t           numberphoton;
   Int_t           nphoton_e;
   Float_t         photon_e[NNN];   //[nphoton_e]
   Int_t           nphoton_pt;
   Float_t         photon_pt[NNN];   //[nphoton_pt]
   Int_t           nphoton_px;
   Float_t         photon_px[NNN];   //[nphoton_px]
   Int_t           nphoton_py;
   Float_t         photon_py[NNN];   //[nphoton_py]
   Int_t           nphoton_pz;
   Float_t         photon_pz[NNN];   //[nphoton_pz]
   Int_t           nphoton_eta;
   Float_t         photon_eta[NNN];   //[nphoton_eta]
   Int_t           nphoton_phi;
   Float_t         photon_phi[NNN];   //[nphoton_phi]
   Int_t           nphoton_ch;
   Float_t         photon_ch[NNN];   //[nphoton_ch]
   Int_t           nphoton_chIso;
   Float_t         photon_chIso[NNN];   //[nphoton_chIso]
   Int_t           nphoton_nhIso;
   Float_t         photon_nhIso[NNN];   //[nphoton_nhIso]
   Int_t           nphoton_phIso;
   Float_t         photon_phIso[NNN];   //[nphoton_phIso]
   Int_t           nphoton_isLoose;
   Bool_t          photon_isLoose[NNN];   //[nphoton_isLoose]
   Int_t           nphoton_isMedium;
   Bool_t          photon_isMedium[NNN];   //[nphoton_isMedium]
   Int_t           nphoton_isTight;
   Bool_t          photon_isTight[NNN];   //[nphoton_isTight]
   Int_t           nPV_chi2;
   Float_t         PV_chi2[NNN];   //[nPV_chi2]
   Int_t           nPV_ndof;
   Float_t         PV_ndof[NNN];   //[nPV_ndof]
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   Int_t           nPV_x;
   Float_t         PV_x[NNN];   //[nPV_x]
   Int_t           nPV_y;
   Float_t         PV_y[NNN];   //[nPV_y]
   Int_t           nPV_z;
   Float_t         PV_z[NNN];   //[nPV_z]
   Bool_t          trig_Ele22_eta2p1_WPLoose_Gsf;
   Bool_t          trig_IsoMu20;
   Bool_t          trig_IsoTkMu20;
   Int_t           numbertau;
   Int_t           ntau_e;
   Float_t         tau_e[NNN];   //[ntau_e]
   Int_t           ntau_pt;
   Float_t         tau_pt[NNN];   //[ntau_pt]
   Int_t           ntau_px;
   Float_t         tau_px[NNN];   //[ntau_px]
   Int_t           ntau_py;
   Float_t         tau_py[NNN];   //[ntau_py]
   Int_t           ntau_pz;
   Float_t         tau_pz[NNN];   //[ntau_pz]
   Int_t           ntau_eta;
   Float_t         tau_eta[NNN];   //[ntau_eta]
   Int_t           ntau_phi;
   Float_t         tau_phi[NNN];   //[ntau_phi]
   Int_t           ntau_ch;
   Float_t         tau_ch[NNN];   //[ntau_ch]
   Int_t           ntau_mass;
   Float_t         tau_mass[NNN];   //[ntau_mass]
   Int_t           ntau_decaymode;
   Float_t         tau_decaymode[NNN];   //[ntau_decaymode]
   Int_t           ntau_iddecaymode;
   Float_t         tau_iddecaymode[NNN];   //[ntau_iddecaymode]
   Int_t           ntau_idisoraw;
   Float_t         tau_idisoraw[NNN];   //[ntau_idisoraw]
   Int_t           ntau_idisovloose;
   Float_t         tau_idisovloose[NNN];   //[ntau_idisovloose]
   Int_t           ntau_idisoloose;
   Float_t         tau_idisoloose[NNN];   //[ntau_idisoloose]
   Int_t           ntau_idisomedium;
   Float_t         tau_idisomedium[NNN];   //[ntau_idisomedium]
   Int_t           ntau_idisotight;
   Float_t         tau_idisotight[NNN];   //[ntau_idisotight]
   Int_t           ntau_idantieletight;
   Float_t         tau_idantieletight[NNN];   //[ntau_idantieletight]
   Int_t           ntau_idantimutight;
   Float_t         tau_idantimutight[NNN];   //[ntau_idantimutight]

   // List of branches
   TBranch        *b_numberelectron;   //!
   TBranch        *b_nelectron_e;   //!
   TBranch        *b_electron_e;   //!
   TBranch        *b_nelectron_pt;   //!
   TBranch        *b_electron_pt;   //!
   TBranch        *b_nelectron_px;   //!
   TBranch        *b_electron_px;   //!
   TBranch        *b_nelectron_py;   //!
   TBranch        *b_electron_py;   //!
   TBranch        *b_nelectron_pz;   //!
   TBranch        *b_electron_pz;   //!
   TBranch        *b_nelectron_eta;   //!
   TBranch        *b_electron_eta;   //!
   TBranch        *b_nelectron_phi;   //!
   TBranch        *b_electron_phi;   //!
   TBranch        *b_nelectron_ch;   //!
   TBranch        *b_electron_ch;   //!
   TBranch        *b_nelectron_iso;   //!
   TBranch        *b_electron_iso;   //!
   TBranch        *b_nelectron_veto;   //!
   TBranch        *b_electron_veto;   //!
   TBranch        *b_nelectron_isLoose;   //!
   TBranch        *b_electron_isLoose;   //!
   TBranch        *b_nelectron_isMedium;   //!
   TBranch        *b_electron_isMedium;   //!
   TBranch        *b_nelectron_isTight;   //!
   TBranch        *b_electron_isTight;   //!
   TBranch        *b_nelectron_dxy;   //!
   TBranch        *b_electron_dxy;   //!
   TBranch        *b_nelectron_dz;   //!
   TBranch        *b_electron_dz;   //!
   TBranch        *b_nelectron_dxyError;   //!
   TBranch        *b_electron_dxyError;   //!
   TBranch        *b_nelectron_dzError;   //!
   TBranch        *b_electron_dzError;   //!
   TBranch        *b_nelectron_ismvaLoose;   //!
   TBranch        *b_electron_ismvaLoose;   //!
   TBranch        *b_nelectron_ismvaTight;   //!
   TBranch        *b_electron_ismvaTight;   //!
   TBranch        *b_nelectron_ip3d;   //!
   TBranch        *b_electron_ip3d;   //!
   TBranch        *b_nelectron_sip3d;   //!
   TBranch        *b_electron_sip3d;   //!
   TBranch        *b_numberfatjet;   //!
   TBranch        *b_nfatjet_pt;   //!
   TBranch        *b_fatjet_pt;   //!
   TBranch        *b_nfatjet_eta;   //!
   TBranch        *b_fatjet_eta;   //!
   TBranch        *b_nfatjet_phi;   //!
   TBranch        *b_fatjet_phi;   //!
   TBranch        *b_nfatjet_ch;   //!
   TBranch        *b_fatjet_ch;   //!
   TBranch        *b_nfatjet_mass;   //!
   TBranch        *b_fatjet_mass;   //!
   TBranch        *b_ncorr_fatjet_pt;   //!
   TBranch        *b_corr_fatjet_pt;   //!
   TBranch        *b_ncorr_fatjet_ptUp;   //!
   TBranch        *b_corr_fatjet_ptUp;   //!
   TBranch        *b_ncorr_fatjet_ptDown;   //!
   TBranch        *b_corr_fatjet_ptDown;   //!
   TBranch        *b_ncorr_fatjet_ptSmearUp;   //!
   TBranch        *b_corr_fatjet_ptSmearUp;   //!
   TBranch        *b_ncorr_fatjet_ptSmearDown;   //!
   TBranch        *b_corr_fatjet_ptSmearDown;   //!
   TBranch        *b_ncorr_fatjet_mass;   //!
   TBranch        *b_corr_fatjet_mass;   //!
   TBranch        *b_ncorr_fatjet_e;   //!
   TBranch        *b_corr_fatjet_e;   //!
   TBranch        *b_ncorr_fatjet_px;   //!
   TBranch        *b_corr_fatjet_px;   //!
   TBranch        *b_ncorr_fatjet_py;   //!
   TBranch        *b_corr_fatjet_py;   //!
   TBranch        *b_ncorr_fatjet_pz;   //!
   TBranch        *b_corr_fatjet_pz;   //!
   TBranch        *b_nfatjet_prunedmass;   //!
   TBranch        *b_fatjet_prunedmass;   //!
   TBranch        *b_nfatjet_softdropmass;   //!
   TBranch        *b_fatjet_softdropmass;   //!
   TBranch        *b_nfatjet_tau1;   //!
   TBranch        *b_fatjet_tau1;   //!
   TBranch        *b_nfatjet_tau2;   //!
   TBranch        *b_fatjet_tau2;   //!
   TBranch        *b_nfatjet_tau3;   //!
   TBranch        *b_fatjet_tau3;   //!
   TBranch        *b_nfatjet_subjet1_btag;   //!
   TBranch        *b_fatjet_subjet1_btag;   //!
   TBranch        *b_nfatjet_subjet2_btag;   //!
   TBranch        *b_fatjet_subjet2_btag;   //!
   TBranch        *b_nfatjet_subjet1_hflav;   //!
   TBranch        *b_fatjet_subjet1_hflav;   //!
   TBranch        *b_nfatjet_subjet2_hflav;   //!
   TBranch        *b_fatjet_subjet2_hflav;   //!
   TBranch        *b_numberjet;   //!
   TBranch        *b_njet_pt;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_njet_eta;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_njet_phi;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_njet_ch;   //!
   TBranch        *b_jet_ch;   //!
   TBranch        *b_njet_mass;   //!
   TBranch        *b_jet_mass;   //!
   TBranch        *b_njet_btag;   //!
   TBranch        *b_jet_btag;   //!
   TBranch        *b_njet_hflav;   //!
   TBranch        *b_jet_hflav;   //!
   TBranch        *b_ncorr_jet_pt;   //!
   TBranch        *b_corr_jet_pt;   //!
   TBranch        *b_ncorr_jet_ptUp;   //!
   TBranch        *b_corr_jet_ptUp;   //!
   TBranch        *b_ncorr_jet_ptDown;   //!
   TBranch        *b_corr_jet_ptDown;   //!
   TBranch        *b_ncorr_jet_ptSmearUp;   //!
   TBranch        *b_corr_jet_ptSmearUp;   //!
   TBranch        *b_ncorr_jet_ptSmearDown;   //!
   TBranch        *b_corr_jet_ptSmearDown;   //!
   TBranch        *b_ncorr_jet_mass;   //!
   TBranch        *b_corr_jet_mass;   //!
   TBranch        *b_ncorr_jet_e;   //!
   TBranch        *b_corr_jet_e;   //!
   TBranch        *b_ncorr_jet_px;   //!
   TBranch        *b_corr_jet_px;   //!
   TBranch        *b_ncorr_jet_py;   //!
   TBranch        *b_corr_jet_py;   //!
   TBranch        *b_ncorr_jet_pz;   //!
   TBranch        *b_corr_jet_pz;   //!
   TBranch        *b_btag_Weight;   //!
   TBranch        *b_btag_WeightUp;   //!
   TBranch        *b_btag_WeightDn;   //!
   TBranch        *b_met_e;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_px;   //!
   TBranch        *b_met_py;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_significance;   //!
   TBranch        *b_met_rawpt;   //!
   TBranch        *b_met_rawphi;   //!
   TBranch        *b_met_rawe;   //!
   TBranch        *b_numbermuon;   //!
   TBranch        *b_nmuon_e;   //!
   TBranch        *b_muon_e;   //!
   TBranch        *b_nmuon_pt;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_nmuon_px;   //!
   TBranch        *b_muon_px;   //!
   TBranch        *b_nmuon_py;   //!
   TBranch        *b_muon_py;   //!
   TBranch        *b_nmuon_pz;   //!
   TBranch        *b_muon_pz;   //!
   TBranch        *b_nmuon_eta;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_nmuon_phi;   //!
   TBranch        *b_muon_phi;   //!
   TBranch        *b_nmuon_ch;   //!
   TBranch        *b_muon_ch;   //!
   TBranch        *b_nmuon_isLoose;   //!
   TBranch        *b_muon_isLoose;   //!
   TBranch        *b_nmuon_isMedium;   //!
   TBranch        *b_muon_isMedium;   //!
   TBranch        *b_nmuon_isTight;   //!
   TBranch        *b_muon_isTight;   //!
   TBranch        *b_nmuon_isSoft;   //!
   TBranch        *b_muon_isSoft;   //!
   TBranch        *b_nmuon_isHighPt;   //!
   TBranch        *b_muon_isHighPt;   //!
   TBranch        *b_nmuon_dxy;   //!
   TBranch        *b_muon_dxy;   //!
   TBranch        *b_nmuon_dz;   //!
   TBranch        *b_muon_dz;   //!
   TBranch        *b_nmuon_dxyError;   //!
   TBranch        *b_muon_dxyError;   //!
   TBranch        *b_nmuon_dzError;   //!
   TBranch        *b_muon_dzError;   //!
   TBranch        *b_nmuon_pfreliso03all;   //!
   TBranch        *b_muon_pfreliso03all;   //!
   TBranch        *b_nmuon_pfreliso04all;   //!
   TBranch        *b_muon_pfreliso04all;   //!
   TBranch        *b_nmuon_pfreliso04DBCorr;   //!
   TBranch        *b_muon_pfreliso04DBCorr;   //!
   TBranch        *b_nmuon_TkIso03;   //!
   TBranch        *b_muon_TkIso03;   //!
   TBranch        *b_nmuon_jetidx;   //!
   TBranch        *b_muon_jetidx;   //!
   TBranch        *b_nmuon_genpartidx;   //!
   TBranch        *b_muon_genpartidx;   //!
   TBranch        *b_nmuon_ip3d;   //!
   TBranch        *b_muon_ip3d;   //!
   TBranch        *b_nmuon_sip3d;   //!
   TBranch        *b_muon_sip3d;   //!
   TBranch        *b_numberphoton;   //!
   TBranch        *b_nphoton_e;   //!
   TBranch        *b_photon_e;   //!
   TBranch        *b_nphoton_pt;   //!
   TBranch        *b_photon_pt;   //!
   TBranch        *b_nphoton_px;   //!
   TBranch        *b_photon_px;   //!
   TBranch        *b_nphoton_py;   //!
   TBranch        *b_photon_py;   //!
   TBranch        *b_nphoton_pz;   //!
   TBranch        *b_photon_pz;   //!
   TBranch        *b_nphoton_eta;   //!
   TBranch        *b_photon_eta;   //!
   TBranch        *b_nphoton_phi;   //!
   TBranch        *b_photon_phi;   //!
   TBranch        *b_nphoton_ch;   //!
   TBranch        *b_photon_ch;   //!
   TBranch        *b_nphoton_chIso;   //!
   TBranch        *b_photon_chIso;   //!
   TBranch        *b_nphoton_nhIso;   //!
   TBranch        *b_photon_nhIso;   //!
   TBranch        *b_nphoton_phIso;   //!
   TBranch        *b_photon_phIso;   //!
   TBranch        *b_nphoton_isLoose;   //!
   TBranch        *b_photon_isLoose;   //!
   TBranch        *b_nphoton_isMedium;   //!
   TBranch        *b_photon_isMedium;   //!
   TBranch        *b_nphoton_isTight;   //!
   TBranch        *b_photon_isTight;   //!
   TBranch        *b_nPV_chi2;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_nPV_ndof;   //!
   TBranch        *b_PV_ndof;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_nPV_x;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_nPV_y;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_nPV_z;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_trig_Ele22_eta2p1_WPLoose_Gsf;   //!
   TBranch        *b_trig_IsoMu20;   //!
   TBranch        *b_trig_IsoTkMu20;   //!
   TBranch        *b_numbertau;   //!
   TBranch        *b_ntau_e;   //!
   TBranch        *b_tau_e;   //!
   TBranch        *b_ntau_pt;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_ntau_px;   //!
   TBranch        *b_tau_px;   //!
   TBranch        *b_ntau_py;   //!
   TBranch        *b_tau_py;   //!
   TBranch        *b_ntau_pz;   //!
   TBranch        *b_tau_pz;   //!
   TBranch        *b_ntau_eta;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_ntau_phi;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_ntau_ch;   //!
   TBranch        *b_tau_ch;   //!
   TBranch        *b_ntau_mass;   //!
   TBranch        *b_tau_mass;   //!
   TBranch        *b_ntau_decaymode;   //!
   TBranch        *b_tau_decaymode;   //!
   TBranch        *b_ntau_iddecaymode;   //!
   TBranch        *b_tau_iddecaymode;   //!
   TBranch        *b_ntau_idisoraw;   //!
   TBranch        *b_tau_idisoraw;   //!
   TBranch        *b_ntau_idisovloose;   //!
   TBranch        *b_tau_idisovloose;   //!
   TBranch        *b_ntau_idisoloose;   //!
   TBranch        *b_tau_idisoloose;   //!
   TBranch        *b_ntau_idisomedium;   //!
   TBranch        *b_tau_idisomedium;   //!
   TBranch        *b_ntau_idisotight;   //!
   TBranch        *b_tau_idisotight;   //!
   TBranch        *b_ntau_idantieletight;   //!
   TBranch        *b_tau_idantieletight;   //!
   TBranch        *b_ntau_idantimutight;   //!
   TBranch        *b_tau_idantimutight;   //!

   newpoet(char *file_name, TChain *tree=0);
   virtual ~newpoet();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop(analy_struct aselect, char *extname);
   virtual void GetPhysicsObjects( Long64_t j, AnalysisObjects *a0, Long64_t nentries );
};

#endif

#ifdef newpoet_cxx
newpoet::newpoet(char *file_name, TChain *tree) : fChain(0)
{
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

newpoet::~newpoet()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t newpoet::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t newpoet::LoadTree(Long64_t entry)
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

void newpoet::Init(TChain *tree)
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

   fChain->SetBranchAddress("numberelectron", &numberelectron, &b_numberelectron);
   fChain->SetBranchAddress("nelectron_e", &nelectron_e, &b_nelectron_e);
   fChain->SetBranchAddress("electron_e", electron_e, &b_electron_e);
   fChain->SetBranchAddress("nelectron_pt", &nelectron_pt, &b_nelectron_pt);
   fChain->SetBranchAddress("electron_pt", electron_pt, &b_electron_pt);
   fChain->SetBranchAddress("nelectron_px", &nelectron_px, &b_nelectron_px);
   fChain->SetBranchAddress("electron_px", electron_px, &b_electron_px);
   fChain->SetBranchAddress("nelectron_py", &nelectron_py, &b_nelectron_py);
   fChain->SetBranchAddress("electron_py", electron_py, &b_electron_py);
   fChain->SetBranchAddress("nelectron_pz", &nelectron_pz, &b_nelectron_pz);
   fChain->SetBranchAddress("electron_pz", electron_pz, &b_electron_pz);
   fChain->SetBranchAddress("nelectron_eta", &nelectron_eta, &b_nelectron_eta);
   fChain->SetBranchAddress("electron_eta", electron_eta, &b_electron_eta);
   fChain->SetBranchAddress("nelectron_phi", &nelectron_phi, &b_nelectron_phi);
   fChain->SetBranchAddress("electron_phi", electron_phi, &b_electron_phi);
   fChain->SetBranchAddress("nelectron_ch", &nelectron_ch, &b_nelectron_ch);
   fChain->SetBranchAddress("electron_ch", electron_ch, &b_electron_ch);
   fChain->SetBranchAddress("nelectron_iso", &nelectron_iso, &b_nelectron_iso);
   fChain->SetBranchAddress("electron_iso", electron_iso, &b_electron_iso);
   fChain->SetBranchAddress("nelectron_veto", &nelectron_veto, &b_nelectron_veto);
   fChain->SetBranchAddress("electron_veto", electron_veto, &b_electron_veto);
   fChain->SetBranchAddress("nelectron_isLoose", &nelectron_isLoose, &b_nelectron_isLoose);
   fChain->SetBranchAddress("electron_isLoose", electron_isLoose, &b_electron_isLoose);
   fChain->SetBranchAddress("nelectron_isMedium", &nelectron_isMedium, &b_nelectron_isMedium);
   fChain->SetBranchAddress("electron_isMedium", electron_isMedium, &b_electron_isMedium);
   fChain->SetBranchAddress("nelectron_isTight", &nelectron_isTight, &b_nelectron_isTight);
   fChain->SetBranchAddress("electron_isTight", electron_isTight, &b_electron_isTight);
   fChain->SetBranchAddress("nelectron_dxy", &nelectron_dxy, &b_nelectron_dxy);
   fChain->SetBranchAddress("electron_dxy", electron_dxy, &b_electron_dxy);
   fChain->SetBranchAddress("nelectron_dz", &nelectron_dz, &b_nelectron_dz);
   fChain->SetBranchAddress("electron_dz", electron_dz, &b_electron_dz);
   fChain->SetBranchAddress("nelectron_dxyError", &nelectron_dxyError, &b_nelectron_dxyError);
   fChain->SetBranchAddress("electron_dxyError", electron_dxyError, &b_electron_dxyError);
   fChain->SetBranchAddress("nelectron_dzError", &nelectron_dzError, &b_nelectron_dzError);
   fChain->SetBranchAddress("electron_dzError", electron_dzError, &b_electron_dzError);
   fChain->SetBranchAddress("nelectron_ismvaLoose", &nelectron_ismvaLoose, &b_nelectron_ismvaLoose);
   fChain->SetBranchAddress("electron_ismvaLoose", electron_ismvaLoose, &b_electron_ismvaLoose);
   fChain->SetBranchAddress("nelectron_ismvaTight", &nelectron_ismvaTight, &b_nelectron_ismvaTight);
   fChain->SetBranchAddress("electron_ismvaTight", electron_ismvaTight, &b_electron_ismvaTight);
   fChain->SetBranchAddress("nelectron_ip3d", &nelectron_ip3d, &b_nelectron_ip3d);
   fChain->SetBranchAddress("electron_ip3d", electron_ip3d, &b_electron_ip3d);
   fChain->SetBranchAddress("nelectron_sip3d", &nelectron_sip3d, &b_nelectron_sip3d);
   fChain->SetBranchAddress("electron_sip3d", electron_sip3d, &b_electron_sip3d);
   fChain->SetBranchAddress("numberfatjet", &numberfatjet, &b_numberfatjet);
   fChain->SetBranchAddress("nfatjet_pt", &nfatjet_pt, &b_nfatjet_pt);
   fChain->SetBranchAddress("fatjet_pt", fatjet_pt, &b_fatjet_pt);
   fChain->SetBranchAddress("nfatjet_eta", &nfatjet_eta, &b_nfatjet_eta);
   fChain->SetBranchAddress("fatjet_eta", fatjet_eta, &b_fatjet_eta);
   fChain->SetBranchAddress("nfatjet_phi", &nfatjet_phi, &b_nfatjet_phi);
   fChain->SetBranchAddress("fatjet_phi", fatjet_phi, &b_fatjet_phi);
   fChain->SetBranchAddress("nfatjet_ch", &nfatjet_ch, &b_nfatjet_ch);
   fChain->SetBranchAddress("fatjet_ch", fatjet_ch, &b_fatjet_ch);
   fChain->SetBranchAddress("nfatjet_mass", &nfatjet_mass, &b_nfatjet_mass);
   fChain->SetBranchAddress("fatjet_mass", fatjet_mass, &b_fatjet_mass);
   fChain->SetBranchAddress("ncorr_fatjet_pt", &ncorr_fatjet_pt, &b_ncorr_fatjet_pt);
   fChain->SetBranchAddress("corr_fatjet_pt", corr_fatjet_pt, &b_corr_fatjet_pt);
   fChain->SetBranchAddress("ncorr_fatjet_ptUp", &ncorr_fatjet_ptUp, &b_ncorr_fatjet_ptUp);
   fChain->SetBranchAddress("corr_fatjet_ptUp", corr_fatjet_ptUp, &b_corr_fatjet_ptUp);
   fChain->SetBranchAddress("ncorr_fatjet_ptDown", &ncorr_fatjet_ptDown, &b_ncorr_fatjet_ptDown);
   fChain->SetBranchAddress("corr_fatjet_ptDown", corr_fatjet_ptDown, &b_corr_fatjet_ptDown);
   fChain->SetBranchAddress("ncorr_fatjet_ptSmearUp", &ncorr_fatjet_ptSmearUp, &b_ncorr_fatjet_ptSmearUp);
   fChain->SetBranchAddress("corr_fatjet_ptSmearUp", corr_fatjet_ptSmearUp, &b_corr_fatjet_ptSmearUp);
   fChain->SetBranchAddress("ncorr_fatjet_ptSmearDown", &ncorr_fatjet_ptSmearDown, &b_ncorr_fatjet_ptSmearDown);
   fChain->SetBranchAddress("corr_fatjet_ptSmearDown", corr_fatjet_ptSmearDown, &b_corr_fatjet_ptSmearDown);
   fChain->SetBranchAddress("ncorr_fatjet_mass", &ncorr_fatjet_mass, &b_ncorr_fatjet_mass);
   fChain->SetBranchAddress("corr_fatjet_mass", corr_fatjet_mass, &b_corr_fatjet_mass);
   fChain->SetBranchAddress("ncorr_fatjet_e", &ncorr_fatjet_e, &b_ncorr_fatjet_e);
   fChain->SetBranchAddress("corr_fatjet_e", corr_fatjet_e, &b_corr_fatjet_e);
   fChain->SetBranchAddress("ncorr_fatjet_px", &ncorr_fatjet_px, &b_ncorr_fatjet_px);
   fChain->SetBranchAddress("corr_fatjet_px", corr_fatjet_px, &b_corr_fatjet_px);
   fChain->SetBranchAddress("ncorr_fatjet_py", &ncorr_fatjet_py, &b_ncorr_fatjet_py);
   fChain->SetBranchAddress("corr_fatjet_py", corr_fatjet_py, &b_corr_fatjet_py);
   fChain->SetBranchAddress("ncorr_fatjet_pz", &ncorr_fatjet_pz, &b_ncorr_fatjet_pz);
   fChain->SetBranchAddress("corr_fatjet_pz", corr_fatjet_pz, &b_corr_fatjet_pz);
   fChain->SetBranchAddress("nfatjet_prunedmass", &nfatjet_prunedmass, &b_nfatjet_prunedmass);
   fChain->SetBranchAddress("fatjet_prunedmass", fatjet_prunedmass, &b_fatjet_prunedmass);
   fChain->SetBranchAddress("nfatjet_softdropmass", &nfatjet_softdropmass, &b_nfatjet_softdropmass);
   fChain->SetBranchAddress("fatjet_softdropmass", fatjet_softdropmass, &b_fatjet_softdropmass);
   fChain->SetBranchAddress("nfatjet_tau1", &nfatjet_tau1, &b_nfatjet_tau1);
   fChain->SetBranchAddress("fatjet_tau1", fatjet_tau1, &b_fatjet_tau1);
   fChain->SetBranchAddress("nfatjet_tau2", &nfatjet_tau2, &b_nfatjet_tau2);
   fChain->SetBranchAddress("fatjet_tau2", fatjet_tau2, &b_fatjet_tau2);
   fChain->SetBranchAddress("nfatjet_tau3", &nfatjet_tau3, &b_nfatjet_tau3);
   fChain->SetBranchAddress("fatjet_tau3", fatjet_tau3, &b_fatjet_tau3);
   fChain->SetBranchAddress("nfatjet_subjet1_btag", &nfatjet_subjet1_btag, &b_nfatjet_subjet1_btag);
   fChain->SetBranchAddress("fatjet_subjet1_btag", fatjet_subjet1_btag, &b_fatjet_subjet1_btag);
   fChain->SetBranchAddress("nfatjet_subjet2_btag", &nfatjet_subjet2_btag, &b_nfatjet_subjet2_btag);
   fChain->SetBranchAddress("fatjet_subjet2_btag", fatjet_subjet2_btag, &b_fatjet_subjet2_btag);
   fChain->SetBranchAddress("nfatjet_subjet1_hflav", &nfatjet_subjet1_hflav, &b_nfatjet_subjet1_hflav);
   fChain->SetBranchAddress("fatjet_subjet1_hflav", fatjet_subjet1_hflav, &b_fatjet_subjet1_hflav);
   fChain->SetBranchAddress("nfatjet_subjet2_hflav", &nfatjet_subjet2_hflav, &b_nfatjet_subjet2_hflav);
   fChain->SetBranchAddress("fatjet_subjet2_hflav", fatjet_subjet2_hflav, &b_fatjet_subjet2_hflav);
   fChain->SetBranchAddress("numberjet", &numberjet, &b_numberjet);
   fChain->SetBranchAddress("njet_pt", &njet_pt, &b_njet_pt);
   fChain->SetBranchAddress("jet_pt", jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("njet_eta", &njet_eta, &b_njet_eta);
   fChain->SetBranchAddress("jet_eta", jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("njet_phi", &njet_phi, &b_njet_phi);
   fChain->SetBranchAddress("jet_phi", jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("njet_ch", &njet_ch, &b_njet_ch);
   fChain->SetBranchAddress("jet_ch", jet_ch, &b_jet_ch);
   fChain->SetBranchAddress("njet_mass", &njet_mass, &b_njet_mass);
   fChain->SetBranchAddress("jet_mass", jet_mass, &b_jet_mass);
   fChain->SetBranchAddress("njet_btag", &njet_btag, &b_njet_btag);
   fChain->SetBranchAddress("jet_btag", jet_btag, &b_jet_btag);
   fChain->SetBranchAddress("njet_hflav", &njet_hflav, &b_njet_hflav);
   fChain->SetBranchAddress("jet_hflav", jet_hflav, &b_jet_hflav);
   fChain->SetBranchAddress("ncorr_jet_pt", &ncorr_jet_pt, &b_ncorr_jet_pt);
   fChain->SetBranchAddress("corr_jet_pt", corr_jet_pt, &b_corr_jet_pt);
   fChain->SetBranchAddress("ncorr_jet_ptUp", &ncorr_jet_ptUp, &b_ncorr_jet_ptUp);
   fChain->SetBranchAddress("corr_jet_ptUp", corr_jet_ptUp, &b_corr_jet_ptUp);
   fChain->SetBranchAddress("ncorr_jet_ptDown", &ncorr_jet_ptDown, &b_ncorr_jet_ptDown);
   fChain->SetBranchAddress("corr_jet_ptDown", corr_jet_ptDown, &b_corr_jet_ptDown);
   fChain->SetBranchAddress("ncorr_jet_ptSmearUp", &ncorr_jet_ptSmearUp, &b_ncorr_jet_ptSmearUp);
   fChain->SetBranchAddress("corr_jet_ptSmearUp", corr_jet_ptSmearUp, &b_corr_jet_ptSmearUp);
   fChain->SetBranchAddress("ncorr_jet_ptSmearDown", &ncorr_jet_ptSmearDown, &b_ncorr_jet_ptSmearDown);
   fChain->SetBranchAddress("corr_jet_ptSmearDown", corr_jet_ptSmearDown, &b_corr_jet_ptSmearDown);
   fChain->SetBranchAddress("ncorr_jet_mass", &ncorr_jet_mass, &b_ncorr_jet_mass);
   fChain->SetBranchAddress("corr_jet_mass", corr_jet_mass, &b_corr_jet_mass);
   fChain->SetBranchAddress("ncorr_jet_e", &ncorr_jet_e, &b_ncorr_jet_e);
   fChain->SetBranchAddress("corr_jet_e", corr_jet_e, &b_corr_jet_e);
   fChain->SetBranchAddress("ncorr_jet_px", &ncorr_jet_px, &b_ncorr_jet_px);
   fChain->SetBranchAddress("corr_jet_px", corr_jet_px, &b_corr_jet_px);
   fChain->SetBranchAddress("ncorr_jet_py", &ncorr_jet_py, &b_ncorr_jet_py);
   fChain->SetBranchAddress("corr_jet_py", corr_jet_py, &b_corr_jet_py);
   fChain->SetBranchAddress("ncorr_jet_pz", &ncorr_jet_pz, &b_ncorr_jet_pz);
   fChain->SetBranchAddress("corr_jet_pz", corr_jet_pz, &b_corr_jet_pz);
   fChain->SetBranchAddress("btag_Weight", &btag_Weight, &b_btag_Weight);
   fChain->SetBranchAddress("btag_WeightUp", &btag_WeightUp, &b_btag_WeightUp);
   fChain->SetBranchAddress("btag_WeightDn", &btag_WeightDn, &b_btag_WeightDn);
   fChain->SetBranchAddress("met_e", &met_e, &b_met_e);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_px", &met_px, &b_met_px);
   fChain->SetBranchAddress("met_py", &met_py, &b_met_py);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_significance", &met_significance, &b_met_significance);
   fChain->SetBranchAddress("met_rawpt", &met_rawpt, &b_met_rawpt);
   fChain->SetBranchAddress("met_rawphi", &met_rawphi, &b_met_rawphi);
   fChain->SetBranchAddress("met_rawe", &met_rawe, &b_met_rawe);
   fChain->SetBranchAddress("numbermuon", &numbermuon, &b_numbermuon);
   fChain->SetBranchAddress("nmuon_e", &nmuon_e, &b_nmuon_e);
   fChain->SetBranchAddress("muon_e", muon_e, &b_muon_e);
   fChain->SetBranchAddress("nmuon_pt", &nmuon_pt, &b_nmuon_pt);
   fChain->SetBranchAddress("muon_pt", muon_pt, &b_muon_pt);
   fChain->SetBranchAddress("nmuon_px", &nmuon_px, &b_nmuon_px);
   fChain->SetBranchAddress("muon_px", muon_px, &b_muon_px);
   fChain->SetBranchAddress("nmuon_py", &nmuon_py, &b_nmuon_py);
   fChain->SetBranchAddress("muon_py", muon_py, &b_muon_py);
   fChain->SetBranchAddress("nmuon_pz", &nmuon_pz, &b_nmuon_pz);
   fChain->SetBranchAddress("muon_pz", muon_pz, &b_muon_pz);
   fChain->SetBranchAddress("nmuon_eta", &nmuon_eta, &b_nmuon_eta);
   fChain->SetBranchAddress("muon_eta", muon_eta, &b_muon_eta);
   fChain->SetBranchAddress("nmuon_phi", &nmuon_phi, &b_nmuon_phi);
   fChain->SetBranchAddress("muon_phi", muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("nmuon_ch", &nmuon_ch, &b_nmuon_ch);
   fChain->SetBranchAddress("muon_ch", muon_ch, &b_muon_ch);
   fChain->SetBranchAddress("nmuon_isLoose", &nmuon_isLoose, &b_nmuon_isLoose);
   fChain->SetBranchAddress("muon_isLoose", muon_isLoose, &b_muon_isLoose);
   fChain->SetBranchAddress("nmuon_isMedium", &nmuon_isMedium, &b_nmuon_isMedium);
   fChain->SetBranchAddress("muon_isMedium", muon_isMedium, &b_muon_isMedium);
   fChain->SetBranchAddress("nmuon_isTight", &nmuon_isTight, &b_nmuon_isTight);
   fChain->SetBranchAddress("muon_isTight", muon_isTight, &b_muon_isTight);
   fChain->SetBranchAddress("nmuon_isSoft", &nmuon_isSoft, &b_nmuon_isSoft);
   fChain->SetBranchAddress("muon_isSoft", muon_isSoft, &b_muon_isSoft);
   fChain->SetBranchAddress("nmuon_isHighPt", &nmuon_isHighPt, &b_nmuon_isHighPt);
   fChain->SetBranchAddress("muon_isHighPt", muon_isHighPt, &b_muon_isHighPt);
   fChain->SetBranchAddress("nmuon_dxy", &nmuon_dxy, &b_nmuon_dxy);
   fChain->SetBranchAddress("muon_dxy", muon_dxy, &b_muon_dxy);
   fChain->SetBranchAddress("nmuon_dz", &nmuon_dz, &b_nmuon_dz);
   fChain->SetBranchAddress("muon_dz", muon_dz, &b_muon_dz);
   fChain->SetBranchAddress("nmuon_dxyError", &nmuon_dxyError, &b_nmuon_dxyError);
   fChain->SetBranchAddress("muon_dxyError", muon_dxyError, &b_muon_dxyError);
   fChain->SetBranchAddress("nmuon_dzError", &nmuon_dzError, &b_nmuon_dzError);
   fChain->SetBranchAddress("muon_dzError", muon_dzError, &b_muon_dzError);
   fChain->SetBranchAddress("nmuon_pfreliso03all", &nmuon_pfreliso03all, &b_nmuon_pfreliso03all);
   fChain->SetBranchAddress("muon_pfreliso03all", muon_pfreliso03all, &b_muon_pfreliso03all);
   fChain->SetBranchAddress("nmuon_pfreliso04all", &nmuon_pfreliso04all, &b_nmuon_pfreliso04all);
   fChain->SetBranchAddress("muon_pfreliso04all", muon_pfreliso04all, &b_muon_pfreliso04all);
   fChain->SetBranchAddress("nmuon_pfreliso04DBCorr", &nmuon_pfreliso04DBCorr, &b_nmuon_pfreliso04DBCorr);
   fChain->SetBranchAddress("muon_pfreliso04DBCorr", muon_pfreliso04DBCorr, &b_muon_pfreliso04DBCorr);
   fChain->SetBranchAddress("nmuon_TkIso03", &nmuon_TkIso03, &b_nmuon_TkIso03);
   fChain->SetBranchAddress("muon_TkIso03", muon_TkIso03, &b_muon_TkIso03);
   fChain->SetBranchAddress("nmuon_jetidx", &nmuon_jetidx, &b_nmuon_jetidx);
   fChain->SetBranchAddress("muon_jetidx", muon_jetidx, &b_muon_jetidx);
   fChain->SetBranchAddress("nmuon_genpartidx", &nmuon_genpartidx, &b_nmuon_genpartidx);
   fChain->SetBranchAddress("muon_genpartidx", muon_genpartidx, &b_muon_genpartidx);
   fChain->SetBranchAddress("nmuon_ip3d", &nmuon_ip3d, &b_nmuon_ip3d);
   fChain->SetBranchAddress("muon_ip3d", muon_ip3d, &b_muon_ip3d);
   fChain->SetBranchAddress("nmuon_sip3d", &nmuon_sip3d, &b_nmuon_sip3d);
   fChain->SetBranchAddress("muon_sip3d", muon_sip3d, &b_muon_sip3d);
   fChain->SetBranchAddress("numberphoton", &numberphoton, &b_numberphoton);
   fChain->SetBranchAddress("nphoton_e", &nphoton_e, &b_nphoton_e);
   fChain->SetBranchAddress("photon_e", photon_e, &b_photon_e);
   fChain->SetBranchAddress("nphoton_pt", &nphoton_pt, &b_nphoton_pt);
   fChain->SetBranchAddress("photon_pt", photon_pt, &b_photon_pt);
   fChain->SetBranchAddress("nphoton_px", &nphoton_px, &b_nphoton_px);
   fChain->SetBranchAddress("photon_px", photon_px, &b_photon_px);
   fChain->SetBranchAddress("nphoton_py", &nphoton_py, &b_nphoton_py);
   fChain->SetBranchAddress("photon_py", photon_py, &b_photon_py);
   fChain->SetBranchAddress("nphoton_pz", &nphoton_pz, &b_nphoton_pz);
   fChain->SetBranchAddress("photon_pz", photon_pz, &b_photon_pz);
   fChain->SetBranchAddress("nphoton_eta", &nphoton_eta, &b_nphoton_eta);
   fChain->SetBranchAddress("photon_eta", photon_eta, &b_photon_eta);
   fChain->SetBranchAddress("nphoton_phi", &nphoton_phi, &b_nphoton_phi);
   fChain->SetBranchAddress("photon_phi", photon_phi, &b_photon_phi);
   fChain->SetBranchAddress("nphoton_ch", &nphoton_ch, &b_nphoton_ch);
   fChain->SetBranchAddress("photon_ch", photon_ch, &b_photon_ch);
   fChain->SetBranchAddress("nphoton_chIso", &nphoton_chIso, &b_nphoton_chIso);
   fChain->SetBranchAddress("photon_chIso", photon_chIso, &b_photon_chIso);
   fChain->SetBranchAddress("nphoton_nhIso", &nphoton_nhIso, &b_nphoton_nhIso);
   fChain->SetBranchAddress("photon_nhIso", photon_nhIso, &b_photon_nhIso);
   fChain->SetBranchAddress("nphoton_phIso", &nphoton_phIso, &b_nphoton_phIso);
   fChain->SetBranchAddress("photon_phIso", photon_phIso, &b_photon_phIso);
   fChain->SetBranchAddress("nphoton_isLoose", &nphoton_isLoose, &b_nphoton_isLoose);
   fChain->SetBranchAddress("photon_isLoose", photon_isLoose, &b_photon_isLoose);
   fChain->SetBranchAddress("nphoton_isMedium", &nphoton_isMedium, &b_nphoton_isMedium);
   fChain->SetBranchAddress("photon_isMedium", photon_isMedium, &b_photon_isMedium);
   fChain->SetBranchAddress("nphoton_isTight", &nphoton_isTight, &b_nphoton_isTight);
   fChain->SetBranchAddress("photon_isTight", photon_isTight, &b_photon_isTight);
   fChain->SetBranchAddress("nPV_chi2", &nPV_chi2, &b_nPV_chi2);
   fChain->SetBranchAddress("PV_chi2", PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("nPV_ndof", &nPV_ndof, &b_nPV_ndof);
   fChain->SetBranchAddress("PV_ndof", PV_ndof, &b_PV_ndof);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("nPV_x", &nPV_x, &b_nPV_x);
   fChain->SetBranchAddress("PV_x", PV_x, &b_PV_x);
   fChain->SetBranchAddress("nPV_y", &nPV_y, &b_nPV_y);
   fChain->SetBranchAddress("PV_y", PV_y, &b_PV_y);
   fChain->SetBranchAddress("nPV_z", &nPV_z, &b_nPV_z);
   fChain->SetBranchAddress("PV_z", PV_z, &b_PV_z);
   fChain->SetBranchAddress("trig_Ele22_eta2p1_WPLoose_Gsf", &trig_Ele22_eta2p1_WPLoose_Gsf, &b_trig_Ele22_eta2p1_WPLoose_Gsf);
   fChain->SetBranchAddress("trig_IsoMu20", &trig_IsoMu20, &b_trig_IsoMu20);
   fChain->SetBranchAddress("trig_IsoTkMu20", &trig_IsoTkMu20, &b_trig_IsoTkMu20);
   fChain->SetBranchAddress("numbertau", &numbertau, &b_numbertau);
   fChain->SetBranchAddress("ntau_e", &ntau_e, &b_ntau_e);
   fChain->SetBranchAddress("tau_e", tau_e, &b_tau_e);
   fChain->SetBranchAddress("ntau_pt", &ntau_pt, &b_ntau_pt);
   fChain->SetBranchAddress("tau_pt", tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("ntau_px", &ntau_px, &b_ntau_px);
   fChain->SetBranchAddress("tau_px", tau_px, &b_tau_px);
   fChain->SetBranchAddress("ntau_py", &ntau_py, &b_ntau_py);
   fChain->SetBranchAddress("tau_py", tau_py, &b_tau_py);
   fChain->SetBranchAddress("ntau_pz", &ntau_pz, &b_ntau_pz);
   fChain->SetBranchAddress("tau_pz", tau_pz, &b_tau_pz);
   fChain->SetBranchAddress("ntau_eta", &ntau_eta, &b_ntau_eta);
   fChain->SetBranchAddress("tau_eta", tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("ntau_phi", &ntau_phi, &b_ntau_phi);
   fChain->SetBranchAddress("tau_phi", tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("ntau_ch", &ntau_ch, &b_ntau_ch);
   fChain->SetBranchAddress("tau_ch", tau_ch, &b_tau_ch);
   fChain->SetBranchAddress("ntau_mass", &ntau_mass, &b_ntau_mass);
   fChain->SetBranchAddress("tau_mass", tau_mass, &b_tau_mass);
   fChain->SetBranchAddress("ntau_decaymode", &ntau_decaymode, &b_ntau_decaymode);
   fChain->SetBranchAddress("tau_decaymode", tau_decaymode, &b_tau_decaymode);
   fChain->SetBranchAddress("ntau_iddecaymode", &ntau_iddecaymode, &b_ntau_iddecaymode);
   fChain->SetBranchAddress("tau_iddecaymode", tau_iddecaymode, &b_tau_iddecaymode);
   fChain->SetBranchAddress("ntau_idisoraw", &ntau_idisoraw, &b_ntau_idisoraw);
   fChain->SetBranchAddress("tau_idisoraw", tau_idisoraw, &b_tau_idisoraw);
   fChain->SetBranchAddress("ntau_idisovloose", &ntau_idisovloose, &b_ntau_idisovloose);
   fChain->SetBranchAddress("tau_idisovloose", tau_idisovloose, &b_tau_idisovloose);
   fChain->SetBranchAddress("ntau_idisoloose", &ntau_idisoloose, &b_ntau_idisoloose);
   fChain->SetBranchAddress("tau_idisoloose", tau_idisoloose, &b_tau_idisoloose);
   fChain->SetBranchAddress("ntau_idisomedium", &ntau_idisomedium, &b_ntau_idisomedium);
   fChain->SetBranchAddress("tau_idisomedium", tau_idisomedium, &b_tau_idisomedium);
   fChain->SetBranchAddress("ntau_idisotight", &ntau_idisotight, &b_ntau_idisotight);
   fChain->SetBranchAddress("tau_idisotight", tau_idisotight, &b_tau_idisotight);
   fChain->SetBranchAddress("ntau_idantieletight", &ntau_idantieletight, &b_ntau_idantieletight);
   fChain->SetBranchAddress("tau_idantieletight", tau_idantieletight, &b_tau_idantieletight);
   fChain->SetBranchAddress("ntau_idantimutight", &ntau_idantimutight, &b_ntau_idantimutight);
   fChain->SetBranchAddress("tau_idantimutight", tau_idantimutight, &b_tau_idantimutight);
}
#endif
