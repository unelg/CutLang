#define atlasopenR2_cxx
#include "atlasopenR2.h"
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

       map<string, vector<dbxMuon>     > muos_map;
       map<string, vector<dbxElectron> > eles_map;
       map<string, vector<dbxTau>      > taus_map;
       map<string, vector<dbxPhoton>   > gams_map;
       map<string, vector<dbxJet>      > jets_map;
       map<string, vector<dbxJet>     >ljets_map;
       map<string, vector<dbxTruth>    >truth_map;
       map<string, vector<dbxTrack>    >track_map;
       map<string, vector<dbxParticle> >combo_map;
       map<string, vector<dbxParticle> >constits_map;
       map<string, TVector2            >  met_map;

//temporary variables
       TLorentzVector  alv;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       dbxTau      *adbxt;
       dbxPhoton   *adbxp;

DEBUG("Begin Filling"<<std::endl);

        for (unsigned int i=0; i<lep_n; i++) {
            alv.SetPtEtaPhiE( lep_pt->at(i)*0.001, lep_eta->at(i), lep_phi->at(i), lep_E->at(i)*0.001 ); // all in GeV
            if (lep_type->at(i)==13) {
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(lep_charge->at(i) );
		adbxm->setPdgID(-13*lep_charge->at(i));
                adbxm->setEtCone(0.001*lep_etcone20->at(i)  );
                adbxm->setPtCone(0.001*lep_ptcone30->at(i)  );
                adbxm->setParticleIndx(i);
                adbxm->setZ0(lep_z0->at(i) );
                muons.push_back(*adbxm);
                delete adbxm;
            }
            if (lep_type->at(i)==11) {
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(lep_charge->at(i) );
		adbxe->setPdgID(-11*lep_charge->at(i));
                adbxe->setParticleIndx(i);
                adbxe->setEtCone(0.001*lep_etcone20->at(i)  );
                adbxe->setPtCone(0.001*lep_ptcone30->at(i)  );
                adbxe->setZ0(lep_z0->at(i) );
                electrons.push_back(*adbxe);
                delete adbxe;
            }
	    if (lep_type->at(i)==15) {
                adbxt= new dbxTau(alv);
                adbxt->setCharge(lep_charge->at(i) );
		adbxt->setPdgID(-15*lep_charge->at(i));
                adbxt->setEtCone(0.001*lep_etcone20->at(i)  );
                adbxt->setPtCone(0.001*lep_ptcone30->at(i)  );
                adbxt->setParticleIndx(i);
                adbxt->setZ0(lep_z0->at(i) );
                taus.push_back(*adbxt);
                delete adbxt;
            }
        }

DEBUG("Muons, Electrons and Taus OK\n");


//PHOTONS
        for (unsigned int i=0; i<photon_n; i++) {
                alv.SetPtEtaPhiM( photon_pt->at(i), photon_eta->at(i), photon_phi->at(i), 0 ); // all in GeV
                adbxp= new dbxPhoton(alv);
		adbxp->setPdgID(22);
                adbxp->setEtCone(0.001*photon_etcone20->at(i) );
                adbxp->setPtCone(0.001*photon_ptcone30->at(i) );
                adbxp->setIsTight(photon_isTightID->at(i) );
                adbxp->setCharge(0);
                adbxp->setParticleIndx(i);
                photons.push_back(*adbxp);
                delete adbxp;
        }
DEBUG("Photons OK\n");

//JETS
        for (unsigned int i=0; i<jet_n; i++) {
                alv.SetPtEtaPhiE( jet_pt->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_E->at(i)*0.001 ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
                adbxj->setJVtxf(jet_jvt->at(i));
                adbxj->setFlavor(jet_MV2c10->at(i) );
                adbxj->set_isbtagged_77( jet_MV2c10->at(i) > blow_th ); // 5 is btag
//                adbxj->setJVtxf(jet_jvf->at(i));
//                adbxj->setFlavor(jet_MV1->at(i) );
//                adbxj->set_isbtagged_77( jet_MV1->at(i) > blow_th ); // 5 is btag
                jets.push_back(*adbxj);
                delete adbxj;
        }
DEBUG("Jets ok\n");
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

        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       track_map.insert( pair <string,vector<dbxTrack>    > ("Track",       track) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, track_map,  combo_map, constits_map, met_map, anevt};
        ttr_map["mini"]->SetEntry(j);
        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
