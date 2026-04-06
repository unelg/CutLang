#define atlasopenR2_cxx
#include "atlasopenR2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <signal.h>
#include <unordered_map>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"
#include "TTreeReader.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;

void atlasopenR2::Loop(analy_struct aselect, char *extname)
{
// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   float blow_th=0.7892;

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
#ifdef __DEBUG__
std::cout << "Read Event"<<std::endl;
#endif
       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>       taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
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
       TLorentzVector  alv;
       TVector2 met;

DEBUG("Begin Filling"<<std::endl);

        for (unsigned int i=0; i<lep_n; i++) {
            alv.SetPtEtaPhiE( lep_pt->at(i)*0.001, lep_eta->at(i), lep_phi->at(i), lep_E->at(i)*0.001 ); // all in GeV
            if (lep_type->at(i)==13) {
                muons.emplace_back(alv);
                muons.back().setCharge(lep_charge->at(i));
		muons.back().setPdgID(-13*lep_charge->at(i));
                muons.back().setEtCone(0.001*lep_etcone20->at(i)  );
                muons.back().setPtCone(0.001*lep_ptcone30->at(i)  );
                muons.back().setIsTight(lep_isTightID->at(i) );
                muons.back().setParticleIndx(i);
                muons.back().setIsTight(lep_isTightID->at(i) );
                muons.back().setZZero(lep_z0->at(i));
            }
            if (lep_type->at(i)==11) {
                electrons.emplace_back(alv);
                electrons.back().setCharge(lep_charge->at(i));
		electrons.back().setPdgID(-11*lep_charge->at(i));
                electrons.back().setParticleIndx(i);
                electrons.back().setEtCone(0.001*lep_etcone20->at(i)  );
                electrons.back().setPtCone(0.001*lep_ptcone30->at(i)  );
                electrons.back().setIsTight(lep_isTightID->at(i) );
                electrons.back().setZZero(lep_z0->at(i));
            }
        }

DEBUG("Muons, Electrons OK\n");

// TAUS
        for(unsigned int i=0; i<tau_n; i++){
                alv.SetPtEtaPhiE( tau_pt->at(i)*0.001, tau_eta->at(i), tau_phi->at(i), tau_E->at(i)*0.001 ); // all in GeV
                taus.emplace_back(alv);
                taus.back().setCharge(tau_charge->at(i) );
		taus.back().setPdgID(-15*tau_charge->at(i));
                taus.back().setParticleIndx(i);
        }

DEBUG("Taus OK\n");

//PHOTONS
        for (unsigned int i=0; i<photon_n; i++) {
                alv.SetPtEtaPhiM( photon_pt->at(i)*0.001, photon_eta->at(i), photon_phi->at(i), 0 ); // all in GeV
                photons.emplace_back(alv);
		photons.back().setPdgID(22);
                photons.back().setEtCone(0.001*photon_etcone20->at(i) );
                photons.back().setPtCone(0.001*photon_ptcone30->at(i) );
                photons.back().setIsTight(photon_isTightID->at(i) );
                photons.back().setCharge(0);
                photons.back().setParticleIndx(i);
        }
DEBUG("Photons OK\n");

//JETS
        for (unsigned int i=0; i<jet_n; i++) {
                alv.SetPtEtaPhiE( jet_pt->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_E->at(i)*0.001 ); // all in GeV
                jets.emplace_back(alv);
                jets.back().setCharge(-99);
                jets.back().setParticleIndx(i);
                jets.back().setJVtxf(jet_jvt->at(i));
                jets.back().setFlavor(jet_MV2c10->at(i) );
                jets.back().set_isbtagged_77( jet_MV2c10->at(i) > blow_th ); // 5 is btag
        }
DEBUG("Jets ok\n");

//FAT JETS
        for (unsigned int i=0; i<largeRjet_n; i++) {
                alv.SetPtEtaPhiE( largeRjet_pt->at(i)*0.001, largeRjet_eta->at(i), largeRjet_phi->at(i), largeRjet_E->at(i)*0.001 ); // all in GeV
                ljets.emplace_back(alv);
                ljets.back().setCharge(-99);
                ljets.back().setParticleIndx(i);
                ljets.back().setFlavor(largeRjet_tau32->at(i));
        }
DEBUG("FATJET ok\n");

//MET
        met.SetMagPhi( met_et*0.001,  met_phi);
DEBUG("MET ok\n");


//------------ auxiliary information -------
        anevt.run_no=runNumber;
        anevt.user_evt_weight=1.0;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=eventNumber;
        anevt.TRG_e= trigE;
        anevt.TRG_m= trigM;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 9;
        anevt.badjet=0;
        anevt.mcevt_weight=mcWeight;
        anevt.pileup_weight=1.0;
        anevt.z_vtx_weight = 1.0;
        anevt.weight_bTagSF_77 = scaleFactor_BTAG;
        anevt.weight_leptonSF = scaleFactor_LepTRIGGER;
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
       combo_map["Combo"].swap(combos);
/*
       truth_map["Truth"].swap(truth);
       track_map["Track"].swap(track);
       constits_map["Constits"].swap(constis);
*/

        met_map["MET"] = met;

        a0.muos=muos_map;
        a0.eles=eles_map;
        a0.taus=taus_map;
        a0.gams=gams_map;
        a0.jets=jets_map;
        a0.ljets=ljets_map;
        a0.combos=combo_map;
        a0.evt = anevt;

        ttr_map["mini"]->SetEntry(j);
        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
