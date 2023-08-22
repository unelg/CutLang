#define cmsod2_cxx
#include "cmsod2.h"
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

//#define __DEBUG__
extern bool fctrlc;

void cmsod2::Loop(analy_struct aselect, char *extname)
{

// Signal HANDLER
//   signal (SIGINT, _f2sig_handler); // signal handler has issues with CINT

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

   for (Long64_t j=startevent; j<lastevent; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);

#ifdef __DEBUG__
std::cout << "Read Event"<<std::endl;
#endif

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
       dbxElectron *adbxe;
       dbxMuon     *adbxm;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif
      for (unsigned int i=0; i<nMuon; i++) {
              alv.SetPtEtaPhiM( Muon_pt[i], Muon_eta[i], Muon_phi[i], Muon_mass[i] ); // all in GeV
              adbxm= new dbxMuon(alv);
              adbxm->setCharge(Muon_charge[i] );
              adbxm->setEtCone(Muon_pfRelIso03_all[i]  );
              adbxm->setPtCone(Muon_pfRelIso04_all[i]  );
              adbxm->setParticleIndx(i);
              muons.push_back(*adbxm);
              delete adbxm;
      }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< nMuon<<std::endl;
#endif
//ELECTRONS

      for (unsigned int i=0; i<nElectron; i++) {
              alv.SetPtEtaPhiM( Electron_pt[i], Electron_eta[i], Electron_phi[i], Electron_mass[i] ); // all in GeV
              adbxe= new dbxElectron(alv);
              adbxe->setCharge(Electron_charge[i] );
              adbxe->setEtCone(Electron_pfRelIso03_all[i]  );
              adbxe->setParticleIndx(i);
              electrons.push_back(*adbxe);
              delete adbxe;
      }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< nElectron <<std::endl;
#endif
/*
//PHOTONS
       dbxPhoton   *adbxp;
      for (unsigned int i=0; i<0; i++) {
              alv.SetPxPyPzE( Photon_Px[i], Photon_Py[i], Photon_Pz[i], Photon_E[i] ); // all in GeV
              adbxp= new dbxPhoton(alv);
              adbxp->setCharge(0);
              adbxp->setParticleIndx(i);
              adbxp->setEtCone(Photon_Iso[i]  );
              photons.push_back(*adbxp);
              delete adbxp;
      }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<Photon_size<<std::endl;
#endif
//JETS
   float blow_th=1.7400;
       dbxJet      *adbxj;
      for (unsigned int i=0; i<0; i++) {
              alv.SetPxPyPzE( Jet_Px[i], Jet_Py[i], Jet_Pz[i], Jet_E[i] ); // all in GeV
              adbxj= new dbxJet(alv);
              adbxj->setCharge(-99);
              adbxj->setParticleIndx(i);
              adbxj->setFlavor(Jet_btag[i] );
              adbxj->set_isbtagged_77( (Jet_btag[i]>= blow_th ) ); // cms is >=
              jets.push_back(*adbxj);
              delete adbxj;
      }
#ifdef __DEBUG__
std::cout << "Jets:"<<Jet_<<std::endl;
#endif
*/
//MET
      met.SetMagPhi( MET_pt,  MET_phi);
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif


//------------ auxiliary information -------
        anevt.run_no=run;
        anevt.lumiblk_no=luminosityBlock;
        anevt.top_hfor_type=0;
        anevt.event_no=j;
        anevt.TRG_e= 1;
        anevt.TRG_m= 0;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 9;
        anevt.badjet=0;
        anevt.user_evt_weight=1;
        anevt.mcevt_weight=1;
        anevt.pileup_weight=1.0;
        anevt.z_vtx_weight = 1.0;
        anevt.weight_jvt=1.0;
        anevt.weight_bTagSF_77 = 1.0;
        anevt.weight_leptonSF = 1.0;
        anevt.vxpType=0;
        anevt.lar_Error=0;
        anevt.core_Flags=0;
        anevt.maxEvents=nentries;

#ifdef __DEBUG__
std::cout << "Filling finished"<<std::endl;
#endif

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

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, track_map, combo_map, constits_map, met_map,  anevt};

        aCtrl.RunTasks(a0);

   }// event loop ends.

  aCtrl.Finalize();

}
