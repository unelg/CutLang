#define VLLt_cxx
#include "VLLt.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <signal.h>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"
#include <iostream>
#include "TTreeReader.h"
#include <unordered_map>
using namespace std;

extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;


//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif



void VLLt::Loop(  analy_struct aselect, char *extname )
{
// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;

   map < string, string > syst_names;
   AnalysisController aCtrl(&aselect, syst_names);
   aCtrl.Initialize(extname);
   cout << "End of analysis initialization"<<endl;

   Long64_t nentries = fChain->GetEntriesFast();
   if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
   cout << "number of entries " << nentries << endl;
   Long64_t startevent = 0;
   if (aselect.startpt>0 ) startevent=aselect.startpt;
   cout << "starting entry " << startevent << endl;
   Long64_t lastevent = startevent + nentries;
   if (lastevent > fChain->GetEntriesFast() ) { lastevent=fChain->GetEntriesFast();
       cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
   }

   // Declare maps BEFORE the event loop
 unordered_map<string, vector<dbxMuon>     > muos_map;
 unordered_map<string, vector<dbxElectron> > eles_map;
 unordered_map<string, vector<dbxTau>      > taus_map;
 unordered_map<string, vector<dbxPhoton>   > gams_map;
 unordered_map<string, vector<dbxJet>      > jets_map;
 unordered_map<string, vector<dbxJet>      > ljets_map;
 unordered_map<string, vector<dbxTruth>    > truth_map;
 unordered_map<string, vector<dbxTrack>    > track_map;
 unordered_map<string, vector<dbxParticle> > combo_map;
 unordered_map<string, vector<dbxParticle> > constits_map;
 unordered_map<string, TVector2            > met_map;
// Pre-populate with fixed keys once
muos_map["MUO"];  eles_map["ELE"];  taus_map["TAU"];
gams_map["PHO"];  jets_map["JET"];  ljets_map["FJET"];
truth_map["Truth"]; track_map["Track"];
combo_map["Combo"]; constits_map["Constits"]; met_map["MET"];

AnalysisObjects a0;

for (Long64_t j=startevent; j<lastevent; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);

DEBUG("Read Event\n");

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxTau>      taus;
       vector<dbxJet>    ljets;
       vector<dbxTruth>   truth;
       vector<dbxTrack>    track;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;
       muos_map["MUO"].clear();
       eles_map["ELE"].clear();
       taus_map["TAU"].clear();
       gams_map["PHO"].clear();
       jets_map["JET"].clear();
       ljets_map["FJET"].clear();
       truth_map["Truth"].clear();
       track_map["Track"].clear();
       combo_map["Combo"].clear();
       constits_map["Constits"].clear();
       met_map["MET"].Clear();

//temporary variables
       TLorentzVector  alv, alv0, alv1, alv2, alv3, alv4, alv5;
       TVector2 met;
DEBUG("Begin Filling\n");

//JETS
   unsigned int jet_n=jet_pt_NOSYS->size();
        for (unsigned int i=0; i<jet_n; i++) {
                alv.SetPtEtaPhiE( jet_pt_NOSYS->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_e_NOSYS->at(i)*0.001 ); // all in GeV
                jets.emplace_back(alv);
                jets.back().setCharge(-99);
                jets.back().setParticleIndx(i);
//                jets.back().setJVtxf(jets_DFCommonJets_fJvt->at(i));
                jets.back().setFlavor(jet_GN2v01_Continuous_quantile->at(i) );
                jets.back().set_isbtagged_77( jet_GN2v01_FixedCutBEff_77_select->at(i) ); // 5 is btag
        }
DEBUG("Jets ok\n");

//ELECTRONS
    unsigned int ele_n=el_pt_NOSYS->size();
    for (unsigned int i=0; i<ele_n;i++) {
            alv.SetPtEtaPhiE(el_pt_NOSYS->at(i)*0.001, el_eta->at(i), el_phi->at(i), el_e_NOSYS->at(i)*0.001);
            electrons.emplace_back(alv);
            electrons.back().setCharge(el_charge->at(i));
            electrons.back().setParticleIndx(i);
    }

//MUONS
    unsigned int mu_n=mu_pt_NOSYS->size();
    for (unsigned int i=0; i<mu_n; i++){
            alv.SetPtEtaPhiE(mu_pt_NOSYS->at(i)*0.001, mu_eta->at(i), mu_phi->at(i), mu_e_NOSYS->at(i)*0.001);
            muons.emplace_back(alv);
            muons.back().setCharge(mu_charge->at(i));
            muons.back().setParticleIndx(i);
    }
      
//MET
        met.SetMagPhi( met_met_NOSYS*0.001,  met_phi_NOSYS);


//------------ auxiliary information -------
        anevt.run_no=runNumber;
	anevt.ChannelNo=mcChannelNumber;
	anevt.RunYear=1;
        anevt.correction_weight=1.0;
        anevt.luminosity_weight=1.0;
        anevt.weight_xsec=1.0;
        anevt.user_evt_weight=1.0;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=eventNumber;
        anevt.TRG_e= 1;
        anevt.TRG_m= 1;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 9;
        anevt.badjet=0;
        anevt.weight_mc=1;
	anevt.m_HF_Classification=1;
        anevt.weight_pileup=1;
	anevt.weight_jvt=1;
        anevt.z_vtx_weight = 1.0;
        anevt.weight_bTagSF_77 = 1;
        anevt.weight_leptonSF = 1;
        anevt.vxpType=0;
        anevt.lar_Error=0;
        anevt.core_Flags=0;
        anevt.maxEvents=nentries;



DEBUG("Filling finished"<<std::endl);
        muos_map["MUO"].swap(muons);
        eles_map["ELE"].swap(electrons);
        taus_map["TAU"].swap(taus);
        gams_map["PHO"].swap(photons);
        jets_map["JET"].swap(jets);
        ljets_map["FJET"].swap(ljets);
        truth_map["Truth"].swap(truth);
        track_map["Track"].swap(track);
        combo_map["Combo"].swap(combos);
        met_map["MET"] = met;
        if (constits_map.size() < 1) // we only add this if it was previously empty...
            constits_map["Constits"].swap(constis);

    ttr_map["reco"]->SetEntry(j);
        a0.muos = muos_map;
        a0.eles = eles_map;
        a0.taus = taus_map;
        a0.gams = gams_map;
        a0.jets = jets_map;
        a0.ljets = ljets_map;
        a0.truth = truth_map;
        a0.track = track_map;
        a0.combos = combo_map;
        a0.constits = constits_map;
        a0.met = met_map;
        a0.evt = anevt;
    aCtrl.RunTasks(a0);


}// end of event loop
   aCtrl.Finalize();

}
