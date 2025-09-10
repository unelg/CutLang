//////////////////////////////////////////////////////////
// MakeClass-style reader for ATLAS Open Data V3 (“analysis”)
// R2-style layout: inline Init/ctor/dtor in this header,
// Loop() is implemented in atlasopenV3.C.
//
// Notes:
//  * SetMakeClass(1) in Init().
//  * Keep analysis weights out of C++; apply in .adl.
//  * Branch names/types match your TTree::Print().
//  * Future collections (photons, large-R, truth) wired.
//////////////////////////////////////////////////////////

#ifndef atlasopenV3_h
#define atlasopenV3_h

#include <TROOT.h>
#include <TChain.h>
#include <TTree.h>
#include <TFile.h>
#include <TBranch.h>
#include <ROOT/RVec.hxx>      // ROOT::VecOps::RVec<T>
#include <vector>
#include <string>

// CutLang core types come from dbxParticle.h (evt_data, etc.)
#include "dbxParticle.h"

class atlasopenV3 {
public:
   // --- MakeClass members ---
   TTree  *fChain;  //! analyzed tree/chain
   Int_t   fCurrent;     //! current tree number in a TChain

   // --- Event-level scalars ---
   Int_t      runNumber;
   Long64_t   eventNumber;
   Float_t    mcWeight;

   // Triggers
   Bool_t trigE, trigM;

   // MET
   Float_t met, met_phi;

   // Scale factors (raw; applied in ADL)
   Float_t ScaleFactor_PILEUP;
   Float_t ScaleFactor_MUON;
   Float_t ScaleFactor_LepTRIGGER;
   Float_t ScaleFactor_JVT;
   Float_t ScaleFactor_BTAG;

   // bookkeeping (double in your file)
   Double_t num_events;
   Double_t sum_of_weights;
   Double_t sum_of_weights_squared;
   Double_t xsec, kfac, filteff;

   // shorthand
   template <typename T> using RVec = ROOT::VecOps::RVec<T>;

   // --- Leptons ---
   RVec<float> *lep_pt  = nullptr;
   RVec<float> *lep_eta = nullptr;
   RVec<float> *lep_phi = nullptr;
   RVec<float> *lep_e   = nullptr;
   RVec<int>   *lep_type   = nullptr;   // PDG sign (±11/±13)
   RVec<int>   *lep_charge = nullptr;
   RVec<float> *lep_d0sig  = nullptr;
   RVec<float> *lep_topoetcone20 = nullptr;
   RVec<float> *lep_z0 = nullptr;
   RVec<float> *lep_ptvarcone30 = nullptr; // optional

   // --- Small-R jets ---
   RVec<float> *jet_pt  = nullptr;
   RVec<float> *jet_eta = nullptr;
   RVec<float> *jet_phi = nullptr;
   RVec<float> *jet_e   = nullptr;
   RVec<int>   *jet_btag_quantile = nullptr; // INT 1..5 → {100,85,77,70,60}%
   RVec<bool>  *jet_jvt = nullptr;

   // systematics placeholders present in file
   RVec<float> *jet_pt_jer1 = nullptr;
   RVec<float> *jet_pt_jer2 = nullptr;

   // --- Photons (photon_*) ---
   RVec<float> *photon_pt  = nullptr;
   RVec<float> *photon_eta = nullptr;
   RVec<float> *photon_phi = nullptr;
   RVec<float> *photon_e   = nullptr;
   // ID / isolation (present in file)
   RVec<bool>  *photon_isLooseID   = nullptr;
   RVec<bool>  *photon_isTightID   = nullptr;
   RVec<bool>  *photon_isLooseIso  = nullptr;
   RVec<bool>  *photon_isTightIso  = nullptr;
   RVec<float> *photon_ptcone20    = nullptr;
   RVec<float> *photon_topoetcone40 = nullptr;

   // --- Large-R jets (largeRJet_*) ---
   RVec<float> *largeRJet_pt  = nullptr;
   RVec<float> *largeRJet_eta = nullptr;
   RVec<float> *largeRJet_phi = nullptr;
   RVec<float> *largeRJet_e   = nullptr;
   // extras
   RVec<float> *largeRJet_m   = nullptr;
   RVec<float> *largeRJet_D2  = nullptr;

   // --- Truth (truth_* subsets) ---
   RVec<float> *truth_jet_pt   = nullptr;
   RVec<float> *truth_jet_eta  = nullptr;
   RVec<float> *truth_jet_phi  = nullptr;
   RVec<float> *truth_jet_m    = nullptr;

   RVec<float> *truth_muon_pt  = nullptr;
   RVec<float> *truth_muon_eta = nullptr;
   RVec<float> *truth_muon_phi = nullptr;

   RVec<float> *truth_elec_pt  = nullptr;
   RVec<float> *truth_elec_eta = nullptr;
   RVec<float> *truth_elec_phi = nullptr;

   RVec<float> *truth_tau_pt   = nullptr;
   RVec<float> *truth_tau_eta  = nullptr;
   RVec<float> *truth_tau_phi  = nullptr;

   RVec<float> *truth_photon_pt  = nullptr;
   RVec<float> *truth_photon_eta = nullptr;
   RVec<float> *truth_photon_phi = nullptr;

   Float_t truth_met, truth_met_phi;

   // --- Branch pointers (MakeClass style) ---
   TBranch *b_runNumber=nullptr, *b_eventNumber=nullptr, *b_mcWeight=nullptr;
   TBranch *b_trigE=nullptr, *b_trigM=nullptr;
   TBranch *b_met=nullptr, *b_met_phi=nullptr;

   TBranch *b_SF_PILEUP=nullptr, *b_SF_MUON=nullptr, *b_SF_LepTRIGGER=nullptr, *b_SF_JVT=nullptr, *b_SF_BTAG=nullptr;

   TBranch *b_num_events=nullptr, *b_sum_of_weights=nullptr, *b_sum_of_weights_squared=nullptr,
           *b_xsec=nullptr, *b_kfac=nullptr, *b_filteff=nullptr;

   // leptons
   TBranch *b_lep_pt=nullptr, *b_lep_eta=nullptr, *b_lep_phi=nullptr, *b_lep_e=nullptr;
   TBranch *b_lep_type=nullptr, *b_lep_charge=nullptr, *b_lep_d0sig=nullptr, *b_lep_topoetcone20=nullptr, *b_lep_z0=nullptr, *b_lep_ptvarcone30=nullptr;

   // jets
   TBranch *b_jet_pt=nullptr, *b_jet_eta=nullptr, *b_jet_phi=nullptr, *b_jet_e=nullptr;
   TBranch *b_jet_btag_quantile=nullptr, *b_jet_jvt=nullptr;
   TBranch *b_jet_pt_jer1=nullptr, *b_jet_pt_jer2=nullptr;

   // photons
   TBranch *b_photon_pt=nullptr, *b_photon_eta=nullptr, *b_photon_phi=nullptr, *b_photon_e=nullptr;
   TBranch *b_photon_isLooseID=nullptr, *b_photon_isTightID=nullptr, *b_photon_isLooseIso=nullptr, *b_photon_isTightIso=nullptr,
           *b_photon_ptcone20=nullptr, *b_photon_topoetcone40=nullptr;

   // large-R jets
   TBranch *b_largeRJet_pt=nullptr, *b_largeRJet_eta=nullptr, *b_largeRJet_phi=nullptr, *b_largeRJet_e=nullptr;
   TBranch *b_largeRJet_m=nullptr, *b_largeRJet_D2=nullptr;

   // truth
   TBranch *b_truth_jet_pt=nullptr, *b_truth_jet_eta=nullptr, *b_truth_jet_phi=nullptr, *b_truth_jet_m=nullptr;
   TBranch *b_truth_muon_pt=nullptr, *b_truth_muon_eta=nullptr, *b_truth_muon_phi=nullptr;
   TBranch *b_truth_elec_pt=nullptr, *b_truth_elec_eta=nullptr, *b_truth_elec_phi=nullptr;
   TBranch *b_truth_tau_pt=nullptr,  *b_truth_tau_eta=nullptr,  *b_truth_tau_phi=nullptr;
   TBranch *b_truth_photon_pt=nullptr, *b_truth_photon_eta=nullptr, *b_truth_photon_phi=nullptr;
   TBranch *b_truth_met=nullptr, *b_truth_met_phi=nullptr;

   // --- Methods ---
   atlasopenV3(char* file_name, TChain* tree = 0);
   virtual ~atlasopenV3();

   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree* tree);

   // main analysis loop (CutLang entry point) — defined in .C
   virtual void     Loop(analy_struct aselect, char* extname);
};

#endif  // atlasopenV3_h

// ======================= R2-style inline implementations =====================
#ifdef atlasopenV3_cxx
#include <map>

atlasopenV3::atlasopenV3(char* file_name, TChain* tree) : fChain(0)
{
   TChain* chain;
   if (tree == 0) {
     chain = new TChain("analysis");
     chain->Add(file_name);
   }
   if (tree == 0) {
    Init(chain);
   } else {
    Init(tree);
   }
}

atlasopenV3::~atlasopenV3()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t atlasopenV3::GetEntry(Long64_t entry)
{
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Long64_t atlasopenV3::LoadTree(Long64_t entry)
{
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
  }
  return centry;
}

void atlasopenV3::Init(TTree* tree)
{
  // Zero object pointers (R2 habit)
  lep_pt = lep_eta = lep_phi = lep_e = nullptr;
  lep_type = lep_charge = nullptr;
  lep_d0sig = lep_topoetcone20 = lep_z0 = nullptr;
  lep_ptvarcone30 = nullptr;

  jet_pt = jet_eta = jet_phi = jet_e = nullptr;
  jet_btag_quantile = nullptr;
  jet_jvt = nullptr;
  jet_pt_jer1 = jet_pt_jer2 = nullptr;

  photon_pt = photon_eta = photon_phi = photon_e = nullptr;
  photon_isLooseID = photon_isTightID = nullptr;
  photon_isLooseIso = photon_isTightIso = nullptr;
  photon_ptcone20 = photon_topoetcone40 = nullptr;

  largeRJet_pt = largeRJet_eta = largeRJet_phi = largeRJet_e = nullptr;
  largeRJet_m = largeRJet_D2 = nullptr;

  truth_jet_pt = truth_jet_eta = truth_jet_phi = truth_jet_m = nullptr;
  truth_muon_pt = truth_muon_eta = truth_muon_phi = nullptr;
  truth_elec_pt = truth_elec_eta = truth_elec_phi = nullptr;
  truth_tau_pt  = truth_tau_eta  = truth_tau_phi  = nullptr;
  truth_photon_pt = truth_photon_eta = truth_photon_phi = nullptr;

  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);  // MakeClass mode (R2-style, in header)

  // --- Scalars ---
  fChain->SetBranchAddress("runNumber",   &runNumber,   &b_runNumber);
  fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
  fChain->SetBranchAddress("mcWeight",    &mcWeight,    &b_mcWeight);

  fChain->SetBranchAddress("trigE", &trigE, &b_trigE);
  fChain->SetBranchAddress("trigM", &trigM, &b_trigM);

  fChain->SetBranchAddress("met",     &met,     &b_met);
  fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);

  fChain->SetBranchAddress("ScaleFactor_PILEUP",     &ScaleFactor_PILEUP,     &b_SF_PILEUP);
  fChain->SetBranchAddress("ScaleFactor_MUON",       &ScaleFactor_MUON,       &b_SF_MUON);
  fChain->SetBranchAddress("ScaleFactor_LepTRIGGER", &ScaleFactor_LepTRIGGER, &b_SF_LepTRIGGER);
  fChain->SetBranchAddress("ScaleFactor_JVT",        &ScaleFactor_JVT,        &b_SF_JVT);
  fChain->SetBranchAddress("ScaleFactor_BTAG",       &ScaleFactor_BTAG,       &b_SF_BTAG);

  // bookkeeping
  if (fChain->GetBranch("num_events"))
    fChain->SetBranchAddress("num_events", &num_events, &b_num_events);
  if (fChain->GetBranch("sum_of_weights"))
    fChain->SetBranchAddress("sum_of_weights", &sum_of_weights, &b_sum_of_weights);
  if (fChain->GetBranch("sum_of_weights_squared"))
    fChain->SetBranchAddress("sum_of_weights_squared", &sum_of_weights_squared, &b_sum_of_weights_squared);
  if (fChain->GetBranch("xsec"))
    fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
  if (fChain->GetBranch("kfac"))
    fChain->SetBranchAddress("kfac", &kfac, &b_kfac);
  if (fChain->GetBranch("filteff"))
    fChain->SetBranchAddress("filteff", &filteff, &b_filteff);

  // --- Leptons ---
  fChain->SetBranchAddress("lep_pt",  &lep_pt,  &b_lep_pt);
  fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
  fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
  fChain->SetBranchAddress("lep_e",   &lep_e,   &b_lep_e);

  fChain->SetBranchAddress("lep_type",   &lep_type,   &b_lep_type);
  fChain->SetBranchAddress("lep_charge", &lep_charge, &b_lep_charge);

  fChain->SetBranchAddress("lep_d0sig",        &lep_d0sig,        &b_lep_d0sig);
  fChain->SetBranchAddress("lep_topoetcone20", &lep_topoetcone20, &b_lep_topoetcone20);
  fChain->SetBranchAddress("lep_z0",           &lep_z0,           &b_lep_z0);

  if (fChain->GetBranch("lep_ptvarcone30"))
    fChain->SetBranchAddress("lep_ptvarcone30", &lep_ptvarcone30, &b_lep_ptvarcone30);

  // --- Small-R jets ---
  fChain->SetBranchAddress("jet_pt",  &jet_pt,  &b_jet_pt);
  fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
  fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
  fChain->SetBranchAddress("jet_e",   &jet_e,   &b_jet_e);
  fChain->SetBranchAddress("jet_btag_quantile", &jet_btag_quantile, &b_jet_btag_quantile);
  if (fChain->GetBranch("jet_jvt"))
    fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);

  // systematics
  if (fChain->GetBranch("jet_pt_jer1"))
    fChain->SetBranchAddress("jet_pt_jer1", &jet_pt_jer1, &b_jet_pt_jer1);
  if (fChain->GetBranch("jet_pt_jer2"))
    fChain->SetBranchAddress("jet_pt_jer2", &jet_pt_jer2, &b_jet_pt_jer2);

  // --- Photons (photon_*) ---
  if (fChain->GetBranch("photon_pt")) {
    fChain->SetBranchAddress("photon_pt",  &photon_pt,  &b_photon_pt);
    fChain->SetBranchAddress("photon_eta", &photon_eta, &b_photon_eta);
    fChain->SetBranchAddress("photon_phi", &photon_phi, &b_photon_phi);
    fChain->SetBranchAddress("photon_e",   &photon_e,   &b_photon_e);

    if (fChain->GetBranch("photon_isLooseID"))
      fChain->SetBranchAddress("photon_isLooseID", &photon_isLooseID, &b_photon_isLooseID);
    if (fChain->GetBranch("photon_isTightID"))
      fChain->SetBranchAddress("photon_isTightID", &photon_isTightID, &b_photon_isTightID);
    if (fChain->GetBranch("photon_isLooseIso"))
      fChain->SetBranchAddress("photon_isLooseIso", &photon_isLooseIso, &b_photon_isLooseIso);
    if (fChain->GetBranch("photon_isTightIso"))
      fChain->SetBranchAddress("photon_isTightIso", &photon_isTightIso, &b_photon_isTightIso);
    if (fChain->GetBranch("photon_ptcone20"))
      fChain->SetBranchAddress("photon_ptcone20", &photon_ptcone20, &b_photon_ptcone20);
    if (fChain->GetBranch("photon_topoetcone40"))
      fChain->SetBranchAddress("photon_topoetcone40", &photon_topoetcone40, &b_photon_topoetcone40);
  }

  // --- Large-R jets (largeRJet_*) ---
  if (fChain->GetBranch("largeRJet_pt")) {
    fChain->SetBranchAddress("largeRJet_pt",  &largeRJet_pt,  &b_largeRJet_pt);
    fChain->SetBranchAddress("largeRJet_eta", &largeRJet_eta, &b_largeRJet_eta);
    fChain->SetBranchAddress("largeRJet_phi", &largeRJet_phi, &b_largeRJet_phi);
    fChain->SetBranchAddress("largeRJet_e",   &largeRJet_e,   &b_largeRJet_e);
  }
  if (fChain->GetBranch("largeRJet_m"))
    fChain->SetBranchAddress("largeRJet_m", &largeRJet_m, &b_largeRJet_m);
  if (fChain->GetBranch("largeRJet_D2"))
    fChain->SetBranchAddress("largeRJet_D2", &largeRJet_D2, &b_largeRJet_D2);

  // --- Truth (truth_* subsets) ---
  if (fChain->GetBranch("truth_jet_pt")) {
    fChain->SetBranchAddress("truth_jet_pt",  &truth_jet_pt,  &b_truth_jet_pt);
    fChain->SetBranchAddress("truth_jet_eta", &truth_jet_eta, &b_truth_jet_eta);
    fChain->SetBranchAddress("truth_jet_phi", &truth_jet_phi, &b_truth_jet_phi);
    fChain->SetBranchAddress("truth_jet_m",   &truth_jet_m,   &b_truth_jet_m);
  }
  if (fChain->GetBranch("truth_muon_pt")) {
    fChain->SetBranchAddress("truth_muon_pt",  &truth_muon_pt,  &b_truth_muon_pt);
    fChain->SetBranchAddress("truth_muon_eta", &truth_muon_eta, &b_truth_muon_eta);
    fChain->SetBranchAddress("truth_muon_phi", &truth_muon_phi, &b_truth_muon_phi);
  }
  if (fChain->GetBranch("truth_elec_pt")) {
    fChain->SetBranchAddress("truth_elec_pt",  &truth_elec_pt,  &b_truth_elec_pt);
    fChain->SetBranchAddress("truth_elec_eta", &truth_elec_eta, &b_truth_elec_eta);
    fChain->SetBranchAddress("truth_elec_phi", &truth_elec_phi, &b_truth_elec_phi);
  }
  if (fChain->GetBranch("truth_tau_pt")) {
    fChain->SetBranchAddress("truth_tau_pt",  &truth_tau_pt,  &b_truth_tau_pt);
    fChain->SetBranchAddress("truth_tau_eta", &truth_tau_eta, &b_truth_tau_eta);
    fChain->SetBranchAddress("truth_tau_phi", &truth_tau_phi, &b_truth_tau_phi);
  }
  if (fChain->GetBranch("truth_photon_pt")) {
    fChain->SetBranchAddress("truth_photon_pt",  &truth_photon_pt,  &b_truth_photon_pt);
    fChain->SetBranchAddress("truth_photon_eta", &truth_photon_eta, &b_truth_photon_eta);
    fChain->SetBranchAddress("truth_photon_phi", &truth_photon_phi, &b_truth_photon_phi);
  }
  if (fChain->GetBranch("truth_met"))
    fChain->SetBranchAddress("truth_met", &truth_met, &b_truth_met);
  if (fChain->GetBranch("truth_met_phi"))
    fChain->SetBranchAddress("truth_met_phi", &truth_met_phi, &b_truth_met_phi);
}

#endif  // atlasopenV3_cxx
