#define atlasopenV3_cxx
#include "atlasopenV3.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>

#include <TLorentzVector.h>
#include <TVector2.h>
#include <signal.h>

#include "dbx_muon.h"
#include "dbx_electron.h"
#include "dbx_jet.h"
#include "dbx_photon.h"
#include "dbx_tau.h"
#include "dbx_truth.h"
#include "dbx_track.h"

#include "analysis_core.h"         // AnalysisObjects, evt_data
#include "AnalysisController.h"   // AnalysisController::Initialize/RunTasks/Finalize

using std::cout;
using std::endl;

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern void _fsig_handler (int);
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;

// ---------------------------------------------------------
// Loop (CutLang entry point)
// ---------------------------------------------------------

void atlasopenV3::Loop(analy_struct aselect, char* extname) {
  signal(SIGINT, _fsig_handler);
  if (!fChain) { cout << "Error opening the data file" << endl; return; }

  // We use the controller (as in other readers)

  int verboseFreq(aselect.verbfreq);
  map < string, string > syst_names;
  AnalysisController controller(&aselect, syst_names);
  controller.Initialize(extname);
  std::cout << "End of analysis initialization" << std::endl;

  Long64_t nentries = fChain->GetEntriesFast();
  if (aselect.maxEvents > 0) nentries = aselect.maxEvents;
  std::cout << "number of entries " << nentries << std::endl;
  Long64_t startevent = 0;
  if (aselect.startpt > 0) startevent = aselect.startpt;
  std::cout << "starting entry " << startevent << std::endl;
  Long64_t lastevent = startevent + nentries;
  if (lastevent > fChain->GetEntriesFast()) { lastevent = fChain->GetEntriesFast();
    std::cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << std::endl;
  }

  for (Long64_t j = startevent; j < lastevent; ++j) {
    if (fctrlc) { cout << "Processed " << j << " events\n"; break; }  
    if (j % verboseFreq == 0) cout << "Processing event " << j << endl;  
#ifdef __DEBUG__
    std::cout << "Read Event" << std::endl;  // :contentReference[oaicite:7]{index=7}
#endif
    Long64_t ientry = LoadTree(j);
    if (ientry < 0) break;
    GetEntry(j);

    // --- Event bookkeeping ---
    evt_data anevt{};
    anevt.run_no          = runNumber;
    anevt.event_no        = eventNumber;
    anevt.user_evt_weight = 1.0;      // weights are applied in ADL
    anevt.mcevt_weight    = mcWeight; // raw generator weight

    // --- Build objects ---
    std::vector<dbxMuon>     muos;
    std::vector<dbxElectron> eles;
    std::vector<dbxTau>      taus;   // present but not filled here
    std::vector<dbxPhoton>   gams;
    std::vector<dbxJet>      jets;
    std::vector<dbxJet>      ljets;  // large-R represented as dbxJet
    std::vector<dbxTruth>    truth;
    std::vector<dbxParticle> combos;

    DEBUG("Begin Filling\n");

    // leptons (mu/e)
    const size_t nlep = lep_pt ? lep_pt->size() : 0u;
    muos.reserve(nlep);
    eles.reserve(nlep);
    for (size_t i = 0; i < nlep; ++i) {
      TLorentzVector p4; p4.SetPtEtaPhiE((*lep_pt)[i], (*lep_eta)[i], (*lep_phi)[i], (*lep_e)[i]);
      const int ltype = lep_type ? (*lep_type)[i] : 0;
      const int q     = lep_charge ? (*lep_charge)[i] : 0;

      if (std::abs(ltype) == 13) {
        dbxMuon m(p4);
        if (lep_d0sig)        m.setd0((*lep_d0sig)[i]);
        if (lep_ptvarcone30)  m.setPtCone((*lep_ptvarcone30)[i]);
        if (lep_topoetcone20) m.setEtCone((*lep_topoetcone20)[i]);
        if (lep_z0)           m.setZ0((*lep_z0)[i]);
        m.setCharge(q);
        muos.push_back(m);
      } else if (std::abs(ltype) == 11) {
        dbxElectron el(p4);
        el.setCharge(q);
        if (lep_d0sig)        el.setd0sig((*lep_d0sig)[i]);
        if (lep_topoetcone20) el.setEtCone20((*lep_topoetcone20)[i]);
        if (lep_z0)           el.setZ0((*lep_z0)[i]);
        eles.push_back(el);
      }
    }

    DEBUG("Muons, Electrons OK\n");
    
    // small-R jets
    const size_t nj = jet_pt ? jet_pt->size() : 0u;
    jets.reserve(nj);
    for (size_t i = 0; i < nj; ++i) {
      TLorentzVector p4; p4.SetPtEtaPhiE((*jet_pt)[i], (*jet_eta)[i], (*jet_phi)[i], (*jet_e)[i]);
      dbxJet jtmp(p4);

      // 77% WP: integer quantile 1..5; 77% ↔ q>=3
      int q = 0;
      if (jet_btag_quantile) {
        q = (*jet_btag_quantile)[i];
        jtmp.setFlavor(q);             // store discrete quantile (optional)
        jtmp.set_isbtagged_77(q >= 3);
      } else {
        jtmp.set_isbtagged_77(false);
      }
      if (jet_jvt && i < jet_jvt->size()) jtmp.setjvt((*jet_jvt)[i]);
      jets.push_back(jtmp);
    }

    // large-R jets (export as "FJET")
    const size_t nfj = largeRJet_pt ? largeRJet_pt->size() : 0u;
    ljets.reserve(nfj);
    for (size_t i = 0; i < nfj; ++i) {
      TLorentzVector p4; p4.SetPtEtaPhiE((*largeRJet_pt)[i], (*largeRJet_eta)[i], (*largeRJet_phi)[i], (*largeRJet_e)[i]);
      dbxJet l(p4);
      ljets.push_back(l);
    }

    DEBUG("Jets ok\n");

    // photons
    const size_t ng = photon_pt ? photon_pt->size() : 0u;
    gams.reserve(ng);
    for (size_t i = 0; i < ng; ++i) {
      TLorentzVector p4; p4.SetPtEtaPhiE((*photon_pt)[i], (*photon_eta)[i], (*photon_phi)[i], (*photon_e)[i]);
      dbxPhoton g(p4);
      if (photon_isTightID && i < photon_isTightID->size()) g.setIsTight((*photon_isTightID)[i]);
      if (photon_ptcone20 && i < photon_ptcone20->size()) g.setPtCone((*photon_ptcone20)[i]);
      if (photon_topoetcone40 && i < photon_topoetcone40->size()) g.setEtCone((*photon_topoetcone40)[i]);
      gams.push_back(g);
    }
    
    DEBUG("Photons OK\n");

    // ---- Truth collections (PDG IDs) ----
    if (truth_muon_pt) {
      const size_t ntm = truth_muon_pt->size();
      for (size_t i = 0; i < ntm; ++i) {
        TLorentzVector p4; p4.SetPtEtaPhiM((*truth_muon_pt)[i], (*truth_muon_eta)[i], (*truth_muon_phi)[i], 0.10566);
        dbxTruth t(p4); t.setPdgID(13);
        truth.push_back(t);
      }
    }
    if (truth_elec_pt) {
      const size_t nte = truth_elec_pt->size();
      for (size_t i = 0; i < nte; ++i) {
        TLorentzVector p4; p4.SetPtEtaPhiM((*truth_elec_pt)[i], (*truth_elec_eta)[i], (*truth_elec_phi)[i], 0.000511);
        dbxTruth t(p4); t.setPdgID(11);
        truth.push_back(t);
      }
    }
    if (truth_tau_pt) {
      const size_t ntt = truth_tau_pt->size();
      for (size_t i = 0; i < ntt; ++i) {
        TLorentzVector p4; p4.SetPtEtaPhiM((*truth_tau_pt)[i], (*truth_tau_eta)[i], (*truth_tau_phi)[i], 1.77686);
        dbxTruth t(p4); t.setPdgID(15);
        truth.push_back(t);
      }
    }
    if (truth_photon_pt) {
      const size_t ntg = truth_photon_pt->size();
      for (size_t i = 0; i < ntg; ++i) {
        TLorentzVector p4; p4.SetPtEtaPhiM((*truth_photon_pt)[i], (*truth_photon_eta)[i], (*truth_photon_phi)[i], 0.0);
        dbxTruth t(p4); t.setPdgID(22);
        truth.push_back(t);
      }
    }
    if (truth_jet_pt) {
      const size_t ntj = truth_jet_pt->size();
      for (size_t i = 0; i < ntj; ++i) {
        const float mj = (truth_jet_m && i < truth_jet_m->size()) ? (*truth_jet_m)[i] : 0.0f;
        TLorentzVector p4; p4.SetPtEtaPhiM((*truth_jet_pt)[i], (*truth_jet_eta)[i], (*truth_jet_phi)[i], mj);
        dbxTruth t(p4); t.setPdgID(0);   // 0 = generic truth jet (no PDG)
        truth.push_back(t);
      }
    }

    for (size_t i = 0; i < muos.size(); ++i) muos[i].setParticleIndx(i);
    for (size_t i = 0; i < eles.size(); ++i) eles[i].setParticleIndx(i);
    for (size_t i = 0; i < taus.size(); ++i) taus[i].setParticleIndx(i);
    for (size_t i = 0; i < gams.size(); ++i) gams[i].setParticleIndx(i);
    for (size_t i = 0; i < jets.size(); ++i) jets[i].setParticleIndx(i);
    for (size_t i = 0; i < ljets.size(); ++i) ljets[i].setParticleIndx(i);

    // --- Package for CutLang ---
    std::map<std::string, std::vector<dbxMuon>>     muos_map { {"MUO", muos} };
    std::map<std::string, std::vector<dbxElectron>> eles_map { {"ELE", eles} };
    std::map<std::string, std::vector<dbxTau>>      taus_map { {"TAU", taus} };
    std::map<std::string, std::vector<dbxPhoton>>   gams_map { {"PHO", gams} };
    std::map<std::string, std::vector<dbxJet>>      jets_map { {"JET", jets} };
    std::map<std::string, std::vector<dbxJet>>      ljets_map{ {"FJET", ljets} };
    std::map<std::string, std::vector<dbxTruth>>    truth_map{ {"Truth", truth} };
    std::map<std::string, std::vector<dbxTrack>>    track_map;        //empty
    std::map<std::string, std::vector<dbxParticle>> combo_map{ {"Combo", combos} };
    std::map<std::string, std::vector<dbxParticle>> constits_map;   //empty

    std::map<std::string, TVector2> met_map;    //R2-style
    
    // MET object (R2-style TVector2)
    {
      TVector2 v;
      v.SetMagPhi(met, met_phi);
      met_map.insert(std::make_pair("MET", v));
    }

    DEBUG("MET ok\n");

    AnalysisObjects a0 = { muos_map, eles_map, taus_map, gams_map,
                           jets_map, ljets_map, truth_map, track_map,
                           combo_map, constits_map, met_map, anevt };

    DEBUG("Filling finished\n");

    // Controller runs the tasks
    ttr_map["analysis"]->SetEntry(j);
    controller.RunTasks(a0);
  }

  controller.Finalize();
}
