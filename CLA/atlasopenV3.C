// atlasopenV3.C
#define atlasopenV3_cxx
#include "atlasopenV3.h"

#include <TH2.h>
#include <signal.h>
#include <algorithm>
#include <cmath>
#include <iostream>

#include <TLorentzVector.h>
#include <TVector2.h>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"
#include "TTreeReader.h"

// external bits provided elsewhere in CutLang
extern void _fsig_handler (int);
extern bool fctrlc;
extern std::map<std::string, TTreeReader*> ttr_map;

// ------------------------------
//  ROOT plumbing (ctor/dtor/etc)
// ------------------------------
atlasopenV3::atlasopenV3(char *file_name, TChain *tree)
{
  TChain *chain = nullptr;
  if (tree == nullptr) {
    chain = new TChain("analysis");          // v3 tree name
    chain->Add(file_name);
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
    Notify();
  }
  return centry;
}

void atlasopenV3::Init(TTree *tree)
{
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;

  // IMPORTANT: do NOT call SetMakeClass(1) for RVec branches.

  // scalars
  fChain->SetBranchAddress("runNumber",   &runNumber,   &b_runNumber);
  fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
  fChain->SetBranchAddress("mcWeight",    &mcWeight,    &b_mcWeight);
  fChain->SetBranchAddress("trigE",       &trigE,       &b_trigE);
  fChain->SetBranchAddress("trigM",       &trigM,       &b_trigM);
  fChain->SetBranchAddress("met",         &met,         &b_met);
  fChain->SetBranchAddress("met_phi",     &met_phi,     &b_met_phi);

  // common SFs — if your file lacks any of these, ROOT will just keep defaults
  fChain->SetBranchAddress("ScaleFactor_PILEUP",     &ScaleFactor_PILEUP,     &b_SF_PILEUP);
  fChain->SetBranchAddress("ScaleFactor_MUON",       &ScaleFactor_MUON,       &b_SF_MUON);
  fChain->SetBranchAddress("ScaleFactor_LepTRIGGER", &ScaleFactor_LepTRIGGER, &b_SF_LepTRIGGER);
  fChain->SetBranchAddress("ScaleFactor_JVT",        &ScaleFactor_JVT,        &b_SF_JVT);
  fChain->SetBranchAddress("ScaleFactor_BTAG",       &ScaleFactor_BTAG,       &b_SF_BTAG);

  // leptons (RVec*)
  fChain->SetBranchAddress("lep_pt",           &lep_pt,           &b_lep_pt);
  fChain->SetBranchAddress("lep_eta",          &lep_eta,          &b_lep_eta);
  fChain->SetBranchAddress("lep_phi",          &lep_phi,          &b_lep_phi);
  fChain->SetBranchAddress("lep_e",            &lep_e,            &b_lep_e);
  fChain->SetBranchAddress("lep_type",         &lep_type,         &b_lep_type);
  fChain->SetBranchAddress("lep_charge",       &lep_charge,       &b_lep_charge);
  fChain->SetBranchAddress("lep_ptvarcone30",  &lep_ptvarcone30,  &b_lep_ptvarcone30);
  fChain->SetBranchAddress("lep_topoetcone20", &lep_topoetcone20, &b_lep_topoetcone20);
  fChain->SetBranchAddress("lep_z0",           &lep_z0,           &b_lep_z0);

  // jets (RVec*)
  fChain->SetBranchAddress("jet_pt",            &jet_pt,            &b_jet_pt);
  fChain->SetBranchAddress("jet_eta",           &jet_eta,           &b_jet_eta);
  fChain->SetBranchAddress("jet_phi",           &jet_phi,           &b_jet_phi);
  fChain->SetBranchAddress("jet_e",             &jet_e,             &b_jet_e);
  fChain->SetBranchAddress("jet_btag_quantile", &jet_btag_quantile, &b_jet_btag_quantile);

  Notify();
}

Bool_t atlasopenV3::Notify()
{
  return kTRUE;
}

void atlasopenV3::Show(Long64_t entry)
{
  if (!fChain) return;
  fChain->Show(entry);
}

// ------------------------------
//  Main analysis loop
// ------------------------------
void atlasopenV3::Loop(analy_struct aselect, char *extname)
{
  // CTRL-C handler (same style as other readers)
  signal(SIGINT, _fsig_handler);

  if (!fChain) {
    std::cout << "Error opening the data file\n";
    return;
  }

  const int verboseFreq = aselect.verbfreq;

  // Bootstrap CutLang controller
  std::map<std::string, std::string> syst_names; // keep empty unless wiring systs
  AnalysisController aCtrl(&aselect, syst_names);
  aCtrl.Initialize(extname);
  std::cout << "End of analysis initialization\n";

  // Detect unit scale (GeV vs MeV) using a tiny probe
  pt_scale = 1.0;
  {
    std::vector<float> probe;
    const Long64_t nprobe = std::min<Long64_t>(fChain->GetEntriesFast(), 50);
    for (Long64_t j = 0; j < nprobe; ++j) {
      LoadTree(j);
      fChain->GetEntry(j);
      if (lep_pt && !lep_pt->empty()) probe.push_back((*lep_pt)[0]);
    }
    if (!probe.empty()) {
      std::nth_element(probe.begin(), probe.begin()+probe.size()/2, probe.end());
      const double med = probe[probe.size()/2];
      if (med > 1000.0) pt_scale = 0.001; // MeV → GeV
    }
  }

  // Entry window
  Long64_t nentries = fChain->GetEntriesFast();
  if (aselect.maxEvents > 0) nentries = aselect.maxEvents;
  std::cout << "number of entries " << nentries << "\n";

  Long64_t startevent = 0;
  if (aselect.startpt > 0) startevent = aselect.startpt;
  std::cout << "starting entry " << startevent << "\n";

  Long64_t lastevent = startevent + nentries;
  const Long64_t nall = fChain->GetEntriesFast();
  if (lastevent > nall) {
    lastevent = nall;
    std::cout << "Interval exceeds tree. Analysis is done on max available events starting from event : "
              << startevent << "\n";
  }

  // Event loop
  for (Long64_t j = startevent; j < lastevent; ++j) {
    if (fctrlc) { std::cout << "Processed " << j << " events\n"; break; }
    if (verboseFreq > 0 && (j % verboseFreq) == 0) std::cout << "Processing event " << j << "\n";

    fChain->GetEntry(j);

    // Collections
    std::vector<dbxMuon>     muons;
    std::vector<dbxElectron> electrons;
    std::vector<dbxTau>      taus;
    std::vector<dbxPhoton>   photons;   // not filled here, reserved
    std::vector<dbxJet>      jets;
    std::vector<dbxJet>      ljets;     // not filled here
    std::vector<dbxTruth>    truth;     // not filled here
    std::vector<dbxTrack>    track;     // not filled here
    std::vector<dbxParticle> combos;    // not filled here
    std::vector<dbxParticle> constis;   // not filled here

    std::map<std::string, std::vector<dbxMuon>     > muos_map;
    std::map<std::string, std::vector<dbxElectron> > eles_map;
    std::map<std::string, std::vector<dbxTau>      > taus_map;
    std::map<std::string, std::vector<dbxPhoton>   > gams_map;
    std::map<std::string, std::vector<dbxJet>      > jets_map;
    std::map<std::string, std::vector<dbxJet>      > ljets_map;
    std::map<std::string, std::vector<dbxTruth>    > truth_map;
    std::map<std::string, std::vector<dbxTrack>    > track_map;
    std::map<std::string, std::vector<dbxParticle> > combo_map;
    std::map<std::string, std::vector<dbxParticle> > constits_map;
    std::map<std::string, TVector2>                  met_map;

    TLorentzVector alv;
    TVector2 metvec;

    // ---- Leptons ----
    if (lep_type && lep_pt && lep_eta && lep_phi && lep_e) {
      const size_t nlep = lep_pt->size();
      for (size_t i = 0; i < nlep; ++i) {
        alv.SetPtEtaPhiE((*lep_pt)[i]*pt_scale,
                         (*lep_eta)[i],
                         (*lep_phi)[i],
                         (*lep_e)[i]*pt_scale);

        const int q    = (lep_charge && lep_charge->size() > i) ? (*lep_charge)[i] : 0;
        const int type = (*lep_type)[i];

        if (std::abs(type) == 13) {
          dbxMuon m(alv);
          m.setCharge(q);
          m.setPdgID(-13 * q);
          if (lep_topoetcone20 && lep_topoetcone20->size() > i) m.setEtCone((*lep_topoetcone20)[i]);
          if (lep_ptvarcone30  && lep_ptvarcone30->size()  > i) m.setPtCone((*lep_ptvarcone30)[i]);
          if (lep_z0           && lep_z0->size()           > i) m.setZ0((*lep_z0)[i]);
          muons.push_back(m);
        } else if (std::abs(type) == 11) {
          dbxElectron e(alv);
          e.setCharge(q);
          e.setPdgID(-11 * q);
          if (lep_topoetcone20 && lep_topoetcone20->size() > i) e.setEtCone((*lep_topoetcone20)[i]);
          if (lep_ptvarcone30  && lep_ptvarcone30->size()  > i) e.setPtCone((*lep_ptvarcone30)[i]);
          if (lep_z0           && lep_z0->size()           > i) e.setZ0((*lep_z0)[i]);
          electrons.push_back(e);
        } else if (std::abs(type) == 15) {
          dbxTau t(alv);
          t.setCharge(q);
          t.setPdgID(-15 * q);
          if (lep_topoetcone20 && lep_topoetcone20->size() > i) t.setEtCone((*lep_topoetcone20)[i]);
          if (lep_ptvarcone30  && lep_ptvarcone30->size()  > i) t.setPtCone((*lep_ptvarcone30)[i]);
          if (lep_z0           && lep_z0->size()           > i) t.setZ0((*lep_z0)[i]);
          taus.push_back(t);
        }
      }
    }

    // ---- Jets ----
    if (jet_pt && jet_eta && jet_phi && jet_e) {
      for (size_t i = 0; i < jet_pt->size(); ++i) {
        alv.SetPtEtaPhiE((*jet_pt)[i]*pt_scale,
                         (*jet_eta)[i],
                         (*jet_phi)[i],
                         (*jet_e)[i]*pt_scale);

        dbxJet jtmp(alv);
        jtmp.setCharge(-99);

        // store quantile in "flavor" slot for continuity and mark 77% WP
        if (jet_btag_quantile && jet_btag_quantile->size() > i) {
          const double q = (*jet_btag_quantile)[i];
          jtmp.setFlavor(q);
          jtmp.set_isbtagged_77(q >= 0.77);
        }
        jets.push_back(jtmp);
      }
    }

    // ---- MET ----
    metvec.SetMagPhi(double(met)*pt_scale, double(met_phi));

    // ---- Event-level info ----
    auto sf = [](float x){ return (std::isfinite(x) && x != 0.0f) ? double(x) : 1.0; };

    evt_data anevt{};
    anevt.run_no          = runNumber;
    anevt.event_no        = eventNumber;
    anevt.user_evt_weight = sf(mcWeight)
                            * sf(ScaleFactor_PILEUP)
                            * sf(ScaleFactor_MUON)
                            * sf(ScaleFactor_LepTRIGGER)
                            * sf(ScaleFactor_JVT)
                            * sf(ScaleFactor_BTAG);
    anevt.mcevt_weight    = sf(mcWeight);
    anevt.TRG_e           = trigE;
    anevt.TRG_m           = trigM;
    anevt.maxEvents       = fChain->GetEntriesFast();

    // ---- Pack into maps (CutLang expects these keys) ----
    muos_map.insert( std::make_pair("MUO",      muons) );
    eles_map.insert( std::make_pair("ELE",      electrons) );
    taus_map.insert( std::make_pair("TAU",      taus) );
    gams_map.insert( std::make_pair("PHO",      photons) );
    jets_map.insert( std::make_pair("JET",      jets) );
    ljets_map.insert( std::make_pair("FJET",    ljets) );
    truth_map.insert( std::make_pair("Truth",   truth) );
    track_map.insert( std::make_pair("Track",   track) );
    combo_map.insert( std::make_pair("Combo",   combos) );
    constits_map.insert( std::make_pair("Constits", constis) );
    met_map.insert( std::make_pair("MET",       metvec) );

    AnalysisObjects a0 = { muos_map, eles_map, taus_map, gams_map,
                           jets_map, ljets_map, truth_map, track_map,
                           combo_map, constits_map, met_map, anevt };

    // keep the TTreeReader in sync if the framework created one
    auto it = ttr_map.find("analysis");
    if (it != ttr_map.end() && it->second) it->second->SetEntry(j);

    // run CutLang tasks
    aCtrl.RunTasks(a0);
  }

  aCtrl.Finalize();
}
