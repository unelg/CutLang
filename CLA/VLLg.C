#define VLLg_cxx
#include "VLLg.h"
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

extern void _fsig_handler (int) ;
extern bool fctrlc;
extern TTreeReader *ttreader;

void VLLg::Loop( analy_struct aselect, char *extname )
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
       ttreader->Next();
#ifdef __DEBUG__
std::cout << "Read Event"<<std::endl;
#endif
       int RunNumber=137;

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
       TLorentzVector  alv, alv0, alv1, alv2, alv3;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       dbxTau      *adbxt;
       dbxPhoton   *adbxp;

    #ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
    #endif


//JETS
        unsigned int jetsize=3;
        for (unsigned int i=0; i<jetsize; i++) {
            if (i==0) alv.SetPtEtaPhiM( jet_pt0*0.001, jet_eta0, 0.0, 0.0 ); // all in GeV
            if (i==1) alv.SetPtEtaPhiM( jet_pt1*0.001, jet_eta1, 0.0, 0.0 ); // all in GeV
            if (i==2) alv.SetPtEtaPhiM( jet_pt2*0.001, jet_eta2, 0.0, 0.0 ); // all in GeV
            adbxj= new dbxJet(alv);
            adbxj->setCharge(-99);
            adbxj->setParticleIndx(i);
            jets.push_back(*adbxj);
            delete adbxj;
        }
    #ifdef __DEBUG__
        std::cout << "Jets OK:"<< jetsize <<std::endl;
    #endif

//LEPTONS

#ifdef __DEBUG__
        cout << "1L:"<<(int)onelep_type<<" 2L:"<<(int)dilep_type<<" 3L:"<<(int)trilep_type<<" 4L:"<<(int)quadlep_type<<"\n";
        cout << "1L:"<<lep_Pt_0<<" 2L:"<<lep_Pt_1<<" 3L:"<<lep_Pt_2<<" 4L:"<<lep_Pt_3<<"\n";
#endif
      for (int ii=1; ii<2; ii++){
        int nlep=0;
        if( (int)onelep_type >0 ) nlep=1;
        if( (int)dilep_type >0  ) nlep=2;
        if( (int)trilep_type >0 ) nlep=3;
        if( (int)quadlep_type>0 ) nlep=4;

        if (nlep==0) break;
        alv0.SetPtEtaPhiE( lep_Pt_0*0.001, lep_Eta_0, lep_Phi_0, lep_E_0*0.001 ); // all in GeV       
        if (abs(lep_ID_0)==13) { // muons
            adbxm= new dbxMuon(alv0);
            adbxm->setCharge(lep_ID_0 / 13 );
            adbxm->setPdgID( lep_ID_0 );
            adbxm->setParticleIndx(0);
            adbxm->setZ0(lep_Z0SinTheta_0 );
            muons.push_back(*adbxm);
            delete adbxm;
        }
        if (abs(lep_ID_0)==11) { // electrons
            adbxe= new dbxElectron(alv0);
            adbxe->setCharge(lep_ID_0 / 11 );
            adbxe->setPdgID( lep_ID_0 );
            adbxe->setParticleIndx(0);
            adbxe->setZ0(lep_Z0SinTheta_0 );
            electrons.push_back(*adbxe);
            delete adbxe;
        }
        if (nlep==1) break;
        alv1.SetPtEtaPhiE( lep_Pt_1*0.001, lep_Eta_1, lep_Phi_1, lep_E_1*0.001 ); // all in GeV       
//1
        if (abs(lep_ID_1)==13) { // muons
            adbxm= new dbxMuon(alv1);
            adbxm->setCharge(lep_ID_1 / 13 );
            adbxm->setPdgID( lep_ID_1 );
            adbxm->setParticleIndx(1);
            adbxm->setZ0(lep_Z0SinTheta_1 );
            muons.push_back(*adbxm);
            delete adbxm;
        }
        if (abs(lep_ID_1)==11) { // electrons
            adbxe= new dbxElectron(alv1);
            adbxe->setCharge(lep_ID_1 / 11 );
            adbxe->setPdgID( lep_ID_1 );
            adbxe->setParticleIndx(1);
            adbxe->setZ0(lep_Z0SinTheta_1 );
            electrons.push_back(*adbxe);
            delete adbxe;
        }
        if (nlep==2) break;
        alv2.SetPtEtaPhiE( lep_Pt_2*0.001, lep_Eta_2, lep_Phi_2, lep_E_2*0.001 ); // all in GeV       
//2
        if (abs(lep_ID_2)==13) { // muons
            adbxm= new dbxMuon(alv2);
            adbxm->setCharge(lep_ID_2 / 13 );
            adbxm->setPdgID( lep_ID_2 );
            adbxm->setParticleIndx(2);
            adbxm->setZ0(lep_Z0SinTheta_2 );
            muons.push_back(*adbxm);
            delete adbxm;
        }
        if (abs(lep_ID_2)==11) { // electrons
            adbxe= new dbxElectron(alv2);
            adbxe->setCharge(lep_ID_2 / 11 );
            adbxe->setPdgID( lep_ID_2 );
            adbxe->setParticleIndx(2);
            adbxe->setZ0(lep_Z0SinTheta_2 );
            electrons.push_back(*adbxe);
            delete adbxe;
        }
        if (nlep==3) break;
        alv3.SetPtEtaPhiE( lep_Pt_3*0.001, lep_Eta_3, lep_Phi_3, lep_E_3*0.001 ); // all in GeV       
//3
        if (abs(lep_ID_3)==13) { // muons
            adbxm= new dbxMuon(alv3);
            adbxm->setCharge(lep_ID_3 / 13 );
            adbxm->setPdgID( lep_ID_3 );
            adbxm->setParticleIndx(3);
            muons.push_back(*adbxm);
            delete adbxm;
        }
        if (abs(lep_ID_3)==11) { // electrons
            adbxe= new dbxElectron(alv3);
            adbxe->setCharge(lep_ID_3 / 11 );
            adbxe->setPdgID( lep_ID_3 );
            adbxe->setParticleIndx(3);
            electrons.push_back(*adbxe);
            delete adbxe;
        }

       }
//MET
        met.SetMagPhi( met_met*0.001,  met_phi);

//------------ auxiliary information -------
        anevt.run_no=runNumber;
        anevt.correction_weight=1;
        anevt.luminosity_weight=1.0;
        anevt.weight_xsec=1;
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
       ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       track_map.insert( pair <string,vector<dbxTrack>    > ("Track",       track) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, track_map, combo_map, constits_map, met_map, anevt};

        aCtrl.RunTasks(a0);

      
} // end of for over events

  aCtrl.Finalize();

}


