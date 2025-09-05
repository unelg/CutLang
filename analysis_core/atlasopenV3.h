// atlasopenV3.h
#ifndef atlasopenV3_h
#define atlasopenV3_h

#include <TROOT.h>
#include <TChain.h>
#include <TTree.h>
#include <TBranch.h>
#include <ROOT/RVec.hxx>
#include <vector>
#include <string>
#include <map>

#include "dbxParticle.h"   // brings analy_struct, evt_data

class atlasopenV3 {
public:
  // ROOT plumbing
  TTree* fChain = nullptr;
  int    fCurrent = -1;

  // ---- scalars used in Loop ----
  int    runNumber = 0;
  long   eventNumber = 0;
  float  mcWeight = 1.f;
  bool   trigE = false, trigM = false;
  float  met = 0.f, met_phi = 0.f;

  // common scale factors (default 1.0 if not present)
  float  ScaleFactor_PILEUP = 1.f;
  float  ScaleFactor_MUON = 1.f;
  float  ScaleFactor_LepTRIGGER = 1.f;
  float  ScaleFactor_JVT = 1.f;
  float  ScaleFactor_BTAG = 1.f;

  double pt_scale = 1.0; // 1 for GeV, 0.001 for MeV

  // ---- RVec branch pointers ----
  ROOT::VecOps::RVec<float>* lep_pt  = nullptr;
  ROOT::VecOps::RVec<float>* lep_eta = nullptr;
  ROOT::VecOps::RVec<float>* lep_phi = nullptr;
  ROOT::VecOps::RVec<float>* lep_e   = nullptr;
  ROOT::VecOps::RVec<int>*   lep_type   = nullptr;
  ROOT::VecOps::RVec<int>*   lep_charge = nullptr;
  ROOT::VecOps::RVec<float>* lep_ptvarcone30 = nullptr;
  ROOT::VecOps::RVec<float>* lep_topoetcone20 = nullptr;
  ROOT::VecOps::RVec<float>* lep_z0 = nullptr;

  ROOT::VecOps::RVec<float>* jet_pt  = nullptr;
  ROOT::VecOps::RVec<float>* jet_eta = nullptr;
  ROOT::VecOps::RVec<float>* jet_phi = nullptr;
  ROOT::VecOps::RVec<float>* jet_e   = nullptr;
  ROOT::VecOps::RVec<int>*   jet_btag_quantile = nullptr;
  ROOT::VecOps::RVec<bool>*  jet_jvt = nullptr;

  // (optional) branch pointers if you want ROOT to fill them
  TBranch *b_runNumber=nullptr, *b_eventNumber=nullptr, *b_mcWeight=nullptr;
  TBranch *b_trigE=nullptr, *b_trigM=nullptr, *b_met=nullptr, *b_met_phi=nullptr;
  TBranch *b_SF_PILEUP=nullptr, *b_SF_MUON=nullptr, *b_SF_LepTRIGGER=nullptr, *b_SF_JVT=nullptr, *b_SF_BTAG=nullptr;
  TBranch *b_lep_type=nullptr, *b_lep_charge=nullptr, *b_lep_pt=nullptr, *b_lep_eta=nullptr, *b_lep_phi=nullptr, *b_lep_e=nullptr;
  TBranch *b_lep_topoetcone20=nullptr, *b_lep_ptvarcone30=nullptr, *b_lep_z0=nullptr;
  TBranch *b_jet_pt=nullptr, *b_jet_eta=nullptr, *b_jet_phi=nullptr, *b_jet_e=nullptr, *b_jet_btag_quantile=nullptr;

  // ---- methods (declare only; implement in .C) ----
  atlasopenV3(char* file_name, TChain* tree = nullptr);
  virtual ~atlasopenV3();

  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree* tree);
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);

  // main analysis loop
  virtual void     Loop(analy_struct aselect, char* extname);
};

#endif
