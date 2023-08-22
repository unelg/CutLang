#define AtlasTRT_cxx
#include "AtlasTRT.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTreeReader.h>
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

// header and lines to handle ctrl+C gracefully
extern void _fsig_handler (int) ;
extern bool fctrlc;

void AtlasTRT::Loop(analy_struct aselect, char *extname)
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
//   cout << "End of analysis initialization"<<endl;

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
       if (0 > LoadTree (j)) break;
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>     taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>     ljets;
       vector<dbxTruth>   truth;
       vector<dbxTrack>   tracks;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;

       map<string, vector<dbxMuon>     >  muos_map;
       map<string, vector<dbxElectron> >  eles_map;
       map<string, vector<dbxTau>      >  taus_map;
       map<string, vector<dbxPhoton>   >  gams_map;
       map<string, vector<dbxJet>      >  jets_map;
       map<string, vector<dbxJet>      > ljets_map;
       map<string, vector<dbxTruth>    > truth_map;
       map<string, vector<dbxTrack>    > track_map;
       map<string, vector<dbxParticle> > combo_map;
       map<string, vector<dbxParticle> > constits_map;
       map<string, TVector2            >   met_map;

//temporary variables
       TLorentzVector  alv;
       TVector2 met;
       dbxTruth    *adbxg;
       dbxTrack    *adbxk;

//#define __DEBUG__
#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

     std::cout << "Evt:"<<eventNumber<<"\n";

     alv.SetPtEtaPhiE( trackPt, trackEta, trackPhi, trackE ); // all in GeV
     adbxk= new dbxTrack(alv);
     adbxk->setParticleIndx(0);
     adbxk->addAttribute( truthID);         // attri 0
     adbxk->addAttribute( truthParentID);   // attri 1
     adbxk->addAttribute( averageMu);       // attri 2
     adbxk->addAttribute( truthMatchProb);  // attri 3
     adbxk->addAttribute( nTRTHits);        // attri 4
     adbxk->addAttribute( nTRTHits);        // attri 5
     adbxk->addAttribute( nTRTHits);        // attri 6
     adbxk->addAttribute( nTRTHits);        // attri 7
     adbxk->addAttribute( 0);        // attri 8 // start hits
     adbxk->addAttribute( 0);        // attri 9 // stop hits

     tracks.push_back(*adbxk);
                delete adbxk;

//std::cout << "TRK pT:"<< trackPt<< " E:"<< trackE<< " AveMU:"<< averageMu<<std::endl;
     alv.SetPtEtaPhiE( truthTrackPt, truthTrackEta, truthTrackPhi, 0 ); // all in GeV
     adbxg= new dbxTruth(alv);
     adbxg->setParticleIndx(0);
     truth.push_back(*adbxg);
               delete adbxg;
 
//------------ auxiliary information -------
        anevt.run_no=runNumber;
        anevt.user_evt_weight=1.0;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=eventNumber;
        anevt.TRG_e= 1;
        anevt.TRG_m= 1;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 9;
        anevt.badjet=0;
        anevt.mcevt_weight=1.0;
        anevt.pileup_weight=1.0;
        anevt.z_vtx_weight = 1.0;
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
       ljets_map.insert( pair <string,vector<dbxJet>      > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       track_map.insert( pair <string,vector<dbxTrack>    > ("Track",      tracks) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, 
                            truth_map, track_map, combo_map, constits_map, met_map, anevt};

        aCtrl.RunTasks(a0);

   }// endof events

  aCtrl.Finalize();

} //end of loop
