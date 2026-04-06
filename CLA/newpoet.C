#define newpoet_cxx
#include "newpoet.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


// >>> "include" anchor >>>
#include <signal.h>
#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_truth.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"
#include "TTreeReader.h"
#include <unordered_map>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;

void newpoet::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0, Long64_t nentries )
{
    AnalysisObjects &ao = *a0;

    // >>> GetPhysicsObjects >>>

    fChain->GetEntry(j);
    vector<dbxMuon>     muons;
    vector<dbxElectron> electrons;
    vector<dbxPhoton>   photons;
    vector<dbxJet>      jets;
    vector<dbxTau>      taus;
    vector<dbxJet>     ljets;
    vector<dbxTruth>    truths;
    vector<dbxTrack>   track;
    vector<dbxParticle> combos;
    vector<dbxParticle> constits;

    unordered_map<string, vector<dbxMuon> > muos_map;
    unordered_map<string, vector<dbxElectron> > eles_map;
    unordered_map<string, vector<dbxTau> > taus_map;
    unordered_map<string, vector<dbxPhoton> > gams_map;
    unordered_map<string, vector<dbxJet> > jets_map;
    unordered_map<string, vector<dbxJet> >ljets_map;
    unordered_map<string, vector<dbxTruth> >truth_map;
    unordered_map<string, vector<dbxTrack> >track_map;
    unordered_map<string, vector<dbxParticle> >combo_map;
    unordered_map<string, vector<dbxParticle> >constits_map;
    unordered_map<string, TVector2 >  met_map;

    evt_data anevt;

    //temporary variables
    TVector2 met;
  DEBUG("Begin filling\n");
            met.SetMagPhi( met_pt,  met_phi);

    //temporary variables
    TLorentzVector  alv;

    for (int i=0; i<numbermuon; i++) {
        alv.SetPxPyPzE(muon_px[i], muon_py[i], muon_pz[i],  muon_e[i]); // all in GeV
        muons.emplace_back(alv);
        muons.back().setCharge(muon_ch[i]);
        muons.back().setPdgID(muon_ch[i]*(-13) );
        muons.back().setIsTight (muon_isTight[i] );
        muons.back().setIsMedium(muon_isMedium[i]);
        muons.back().setIsLoose (muon_isLoose[i] );
        muons.back().setParticleIndx(i);
    }
    DEBUG("MUON OK\n");

    for (int i=0; i<numberelectron; i++) {
        alv.SetPxPyPzE(electron_px[i], electron_py[i], electron_pz[i],  electron_e[i]); // all in GeV
        electrons.emplace_back(alv);
        electrons.back().setCharge(electron_ch[i]);
        electrons.back().setParticleIndx(i);
        electrons.back().setPdgID( electron_ch[i]*(-11) );
        electrons.back().setIsTight(electron_isTight[i]);
        electrons.back().setIsMedium(electron_isMedium[i]);
        electrons.back().setIsLoose(electron_isLoose[i]);
    }
    DEBUG("ELECTRON OK\n");

    for (int i=0; i<numbertau; i++) {
        alv.SetPxPyPzE(tau_px[i], tau_py[i], tau_pz[i],  tau_e[i]); // all in GeV
        taus.emplace_back(alv);
        taus.back().setCharge(tau_ch[i]);
        taus.back().setParticleIndx(i);
    }
    DEBUG("TAU OK\n");

    for (int i=0; i<numberphoton; i++) {
        alv.SetPxPyPzE(photon_px[i], photon_py[i], photon_pz[i],  photon_e[i]); // all in GeV
        photons.emplace_back(alv);
        photons.back().setCharge(0);
        photons.back().setParticleIndx(i);
    }
    DEBUG("Photon OK\n");

    for (int i=0; i<numberjet; i++) {
        alv.SetPtEtaPhiM(jet_pt[i], jet_eta[i], jet_phi[i],  jet_mass[i]); // all in GeV
        jets.emplace_back(alv);
        jets.back().setCharge(jet_ch[i]);
        jets.back().setParticleIndx(i);
        jets.back().setFlavor(jet_btag[i]); // btag distro
    }
    DEBUG("JET OK\n");

    for (int i=0; i<numberfatjet; i++) {
        alv.SetPtEtaPhiM(fatjet_pt[i], fatjet_eta[i], fatjet_phi[i],  fatjet_mass[i]); // all in GeV
        ljets.emplace_back(alv);
        ljets.back().setCharge(fatjet_ch[i]);
        ljets.back().setParticleIndx(i);
    }
    DEBUG("FATJET OK\n");

//------------ auxiliary information -------
anevt.run_no=128;
anevt.user_evt_weight=1.0;
anevt.lumiblk_no=1;
anevt.RunYear=2018;
anevt.top_hfor_type=0;
anevt.event_no=1;
anevt.TRG_e= 0;
anevt.TRG_m= 0;
anevt.TRG_j= 0;
anevt.vxp_maxtrk_no= 9;
anevt.m_HF_Classification=numberelectron;
anevt.badjet=0;
anevt.mcevt_weight=0;
anevt.pileup_weight=1.0;
anevt.z_vtx_weight = 1.0;
anevt.weight_bTagSF_77 = 1.0;
anevt.weight_leptonSF = 1.0;
anevt.vxpType=0;
anevt.lar_Error=0;
anevt.core_Flags=0;
anevt.maxEvents=nentries;


    DEBUG("Filling finished\n");

    muos_map["MUO"].swap(muons);
    eles_map["ELE"].swap(electrons);
    taus_map["TAU"].swap(taus);
    gams_map["PHO"].swap(photons);
    jets_map["JET"].swap(jets);
    ljets_map["FJET"].swap(ljets);
    truth_map["Truth"].swap(truths);
    track_map["Track"].swap(track);
    combo_map["Combo"].swap(combos);
    constits_map["Constits"].swap(constits);
    met_map["MET"] = met;

   ao.muos=muos_map;
   ao.eles=eles_map;
   ao.taus=taus_map;
   ao.gams=gams_map;
   ao.jets=jets_map;
   ao.ljets=ljets_map;
   ao.truth=truth_map;
   ao.track=track_map;
   ao.combos=combo_map;
   ao.constits=constits_map;
   ao.met=met_map;
   ao.evt = anevt;

    // <<< GetPhysicsObjects <<<



}

void newpoet::Loop(analy_struct aselect, char *extname)
{
    // Signal HANDLER
    signal (SIGINT, _fsig_handler); // signal handler has issues with CINT
    if (fChain == 0) {
        cout <<"Error opening the data file"<<endl; return;
    }
    int verboseFreq(aselect.verbfreq);

    map < string, string > syst_names;

    AnalysisController aCtrl(&aselect, syst_names);
    aCtrl.Initialize(extname);
    cout << "End of analysis initialization"<<endl;
    // <<< "if (fChain == 0) return" anchor <<<



    // >>> "Long64_t nentries" anchor >>>
    // Long64_t nentries =  fChain->GetEntriesFast();
    Long64_t nentries =  fChain->GetEntriesFast();

    if (aselect.maxEvents > 0 ) {
        nentries=aselect.maxEvents;
    }
    cout << "number of entries " << nentries << endl;
    Long64_t startevent = 0;
    if (aselect.startpt > 0 ) {
        startevent=aselect.startpt;
    }
    cout << "starting entry " << startevent << endl;
    Long64_t lastevent = startevent + nentries;
    if (lastevent > fChain->GetEntriesFast() ) {
        lastevent=fChain->GetEntriesFast();
        cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
    }
    cout << "last entry " << lastevent << endl;

    for (Long64_t j=startevent; j<lastevent; ++j) {

        if ( fctrlc ) { cout << "Processed " << j << " events"; break; }
        if (0 > LoadTree (j)) break;
        if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

        AnalysisObjects a0;
        GetPhysicsObjects(j, &a0, nentries);
        ttr_map["events"]->SetEntry(j);
        aCtrl.RunTasks(a0);
    }// event loop ends.

    aCtrl.Finalize();
}
