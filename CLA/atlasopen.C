#define atlasopen_cxx
#include "atlasopen.h"
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

void atlasopen::Loop(analy_struct aselect, char *extname)
{
// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   float blow_th=0.7892;
   int prev_RunNumber=-1;

   map < string, int > syst_names;
        syst_names["01_jes"]       = 2;
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

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t j=startevent; j<lastevent; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);
#ifdef __DEBUG__
std::cout << "Read Event"<<std::endl;
#endif
/*
       int RunNumber=137;
       if (int(RunNumber)!=prev_RunNumber) {
               cout << "Working on Run #:"<<RunNumber<<endl;
               prev_RunNumber=RunNumber;
       }
*/
       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>       taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>    ljets;
       vector<dbxTruth>   truth;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;

       map<string, vector<dbxMuon>     > muos_map;
       map<string, vector<dbxElectron> > eles_map;
       map<string, vector<dbxTau>      > taus_map;
       map<string, vector<dbxPhoton>   > gams_map;
       map<string, vector<dbxJet>      > jets_map;
       map<string, vector<dbxJet>     >ljets_map;
       map<string, vector<dbxTruth>    >truth_map;
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

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

        for (unsigned int i=0; i<lep_n; i++) {
            alv.SetPtEtaPhiE( lep_pt[i]*0.001, lep_eta[i], lep_phi[i], lep_E[i]*0.001 ); // all in GeV
            if (lep_type[i]==13) {
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(lep_charge[i] );
		adbxm->setPdgID(-13*lep_charge[i]);
                adbxm->setEtCone(lep_etcone20[i]  );
                adbxm->setPtCone(lep_ptcone30[i]  );
                adbxm->setParticleIndx(i);
                adbxm->setZ0(lep_z0[i] );
                muons.push_back(*adbxm);
                delete adbxm;
            }
            if (lep_type[i]==11) {
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(lep_charge[i] );
		adbxe->setPdgID(-11*lep_charge[i]);
                adbxe->setParticleIndx(i);
                adbxe->setEtCone(lep_etcone20[i]  );
                adbxe->setPtCone(lep_ptcone30[i]  );
                adbxe->setZ0(lep_z0[i] );
                electrons.push_back(*adbxe);
                delete adbxe;
            }
	    if (lep_type[i]==15) {
                adbxt= new dbxTau(alv);
                adbxt->setCharge(lep_charge[i] );
		adbxt->setPdgID(-15*lep_charge[i]);
                adbxt->setEtCone(lep_etcone20[i]  );
                adbxt->setPtCone(lep_ptcone30[i]  );
                adbxt->setParticleIndx(i);
                adbxt->setZ0(lep_z0[i] );
                taus.push_back(*adbxt);
                delete adbxt;
            }
        }

#ifdef __DEBUG__
std::cout << "Muons, Electrons and Taus OK:"<< Electron_ <<std::endl;
#endif

/*
//PHOTONS
        for (unsigned int i=0; i<Photon_size; i++) {
                alv.SetPtEtaPhiM( Photon_PT[i], Photon_Eta[i], Photon_Phi[i], 0 ); // all in GeV
                adbxp= new dbxPhoton(alv);
                adbxp->setCharge(0);
                adbxp->setParticleIndx(i);
                adbxp->setClusterE(Photon_EhadOverEem[i] );
                photons.push_back(*adbxp);
                delete adbxp;
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<Photon_size<<std::endl;
#endif
*/
//JETS
        for (unsigned int i=0; i<alljet_n; i++) {
                alv.SetPtEtaPhiE( jet_pt[i]*0.001, jet_eta[i], jet_phi[i], jet_E[i]*0.001 ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setJVtxf(jet_jvf[i]);
                adbxj->setParticleIndx(i);
                adbxj->setFlavor(jet_MV1[i] );
                adbxj->set_isbtagged_77( jet_MV1[i] > blow_th ); // 5 is btag
                jets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<Jet_<<std::endl;
#endif
//MET
        met.SetMagPhi( met_et*0.001,  met_phi);
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif


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
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map, anevt};

        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
