#define lhco_cxx
#include "lhco.h"
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
#include "TTreeReader.h"
#include <unordered_map>

//#define __DEBUG__
//using namespace Root;

// header and lines to handle ctrl+C gracefully
extern void _fsig_handler (int) ;
extern bool fctrlc;

void lhco::Loop(analy_struct aselect, char *extname)
{

// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   int prev_RunNumber=-1;

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
       if (0 > LoadTree (j)) break;
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);

       int RunNumber=137;
       if (int(RunNumber)!=prev_RunNumber) {
               cout << "Working on Run #:"<<RunNumber<<endl;
               prev_RunNumber=RunNumber;
       }

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>      taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>      ljets;
       vector<dbxTruth>    truth;
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
       TLorentzVector  alv;
       TVector2 met;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif
//MUONS

	for ( int i=0; i<Muon_; i++) {
		alv.SetPtEtaPhiM( Muon_PT[i], Muon_Eta[i], Muon_Phi[i], (105.658/1E3) ); // all in GeV
		muons.emplace_back(alv);
		muons.back().setCharge(Muon_Charge[i] );
                muons.back().setEtCone(Muon_ETiso[i]  );
                muons.back().setPtCone(Muon_PTiso[i]  );
		muons.back().setParticleIndx(i);
        }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< Muon_<<std::endl;
#endif
//ELECTRONS

	for (int i=0; i<Electron_; i++) {
		alv.SetPtEtaPhiM( Electron_PT[i], Electron_Eta[i], Electron_Phi[i], (0.511/1E3) ); // all in GeV
		electrons.emplace_back(alv);
		electrons.back().setCharge(Electron_Charge[i] );
		electrons.back().setParticleIndx(i);
                electrons.back().setClusterE(Electron_EhadOverEem[i] );
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< Electron_ <<std::endl;
#endif
//PHOTONS
        for (int i=0; i<Photon_size; i++) {
        	alv.SetPtEtaPhiM( Photon_PT[i], Photon_Eta[i], Photon_Phi[i], 0 ); // all in GeV
        	photons.emplace_back(alv);
        	photons.back().setCharge(0);
        	photons.back().setParticleIndx(i);
                photons.back().setClusterE(Photon_EhadOverEem[i] );
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<Photon_size<<std::endl;
#endif
//JETS
	for (int i=0; i<Jet_; i++) {
  		alv.SetPtEtaPhiM( Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i] ); // all in GeV
  		jets.emplace_back(alv);
  		jets.back().setCharge(-99);
  		jets.back().setParticleIndx(i);
                jets.back().setFlavor(Jet_BTag[i] );
                jets.back().setJVtxf(Jet_Ntrk[i] );
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<Jet_<<std::endl;
#endif
//MET
        met.SetMagPhi( MissingET_MET[0],  MissingET_Phi[0]);
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif

//------------ auxiliary information -------
	anevt.run_no=RunNumber;
        anevt.user_evt_weight=1;
	anevt.lumiblk_no=1;
	anevt.top_hfor_type=0;
	anevt.event_no=Event_Number[0];
	anevt.TRG_e= Event_Trigger[0];
	anevt.TRG_m= 0;
	anevt.TRG_j= 0;
	anevt.vxp_maxtrk_no= 9;
	anevt.badjet=0;
	anevt.mcevt_weight=1.1;
	anevt.pileup_weight=1.1;
	anevt.z_vtx_weight = 1.1;
	anevt.vxpType=0;
	anevt.lar_Error=0;
	anevt.core_Flags=0;
	anevt.maxEvents=nentries;

#ifdef __DEBUG__
std::cout << "Filling finished"<<std::endl;
#endif

        muos_map["MUO"].swap(muons);
        eles_map["ELE"].swap(electrons);
        taus_map["TAU"].swap(taus);
        gams_map["PHO"].swap(photons);
        jets_map["JET"].swap(jets);
        ljets_map["FJET"].swap(ljets);
        truth_map["Truth"].swap(truth);
        track_map["Track"].swap(track);
        combo_map["Combo"].swap(combos);
        constits_map["Constits"].swap(constis);
        met_map["MET"] = met;
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

   } // end of event loop
        aCtrl.Finalize();


}
