#define cmsod_cxx
#include "cmsod.h"
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

//#define __DEBUG__
extern void _fsig_handler (int) ;
extern bool fctrlc;

void cmsod::Loop(analy_struct aselect, char *extname)
{

// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   float blow_th=1.7400;
   int prev_RunNumber=-1;

   map < string, int > syst_names;
        syst_names["01_jes"]       = 2;
   AnalysisController aCtrl(&aselect, syst_names);
   aCtrl.Initialize(extname);
   cout << "End of analysis initialization"<<endl;

   TString CardName="BP_1-card.txt";
   blow_th=ReadCard(CardName,"btag_lowthreshold_CMSOD",blow_th);

   Long64_t nentries = fChain->GetEntriesFast();
   if (aselect.maxEvents > 0) nentries=aselect.maxEvents;
   for (Long64_t j=0; j<nentries; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);
#ifdef __DEBUG__
std::cout << "Read Event"<<std::endl;
#endif
       int RunNumber=137;
/*
       if (int(RunNumber)!=prev_RunNumber) {
               cout << "Working on Run #:"<<RunNumber<<endl;
               prev_RunNumber=RunNumber;
       }
*/
       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxTau>      taus;
       vector<dbxLJet>    ljets;
       vector<dbxTruth>   truth;

       map<string, vector<dbxMuon>     > muos_map;
       map<string, vector<dbxElectron> > eles_map;
       map<string, vector<dbxTau>      > taus_map;
       map<string, vector<dbxPhoton>   > gams_map;
       map<string, vector<dbxJet>      > jets_map;
       map<string, vector<dbxLJet>     >ljets_map;
       map<string, vector<dbxTruth>    >truth_map;
       map<string, TVector2            >  met_map;

//temporary variables
       TLorentzVector  alv;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       dbxTau      *adbxt;
       dbxPhoton   *adbxp;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

        for (unsigned int i=0; i<NMuon; i++) {
                alv.SetPxPyPzE( Muon_Px[i], Muon_Py[i], Muon_Pz[i], Muon_E[i] ); // all in GeV
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(Muon_Charge[i] );
                adbxm->setEtCone(Muon_Iso[i]  );
                adbxm->setParticleIndx(i);
                muons.push_back(*adbxm);
                delete adbxm;
        }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< Muon_<<std::endl;
#endif
//ELECTRONS

        for (unsigned int i=0; i<NElectron; i++) {
                alv.SetPxPyPzE( Electron_Px[i], Electron_Py[i], Electron_Pz[i], Electron_E[i] ); // all in GeV
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(Electron_Charge[i] );
                adbxe->setEtCone(Electron_Iso[i]  );
                adbxe->setParticleIndx(i);
                electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< Electron_ <<std::endl;
#endif
//PHOTONS
        for (unsigned int i=0; i<NPhoton; i++) {
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
        for (unsigned int i=0; i<NJet; i++) {
                alv.SetPxPyPzE( Jet_Px[i], Jet_Py[i], Jet_Pz[i], Jet_E[i] ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
                adbxj->set_isbtagged_77( (Jet_btag[i]>= blow_th ) ); // cms is >=
                jets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<Jet_<<std::endl;
#endif
//MET
        met.Set(MET_px, MET_py);
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif


//------------ auxiliary information -------
        anevt.run_no=RunNumber;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=j;
        anevt.TRG_e= 1;
        anevt.TRG_m= 0;
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
        anevt.tile_Error=0;
        anevt.core_Flags=0;

#ifdef __DEBUG__
std::cout << "Filling finished"<<std::endl;
#endif

        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxLJet>     > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, met_map,  anevt};

        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
