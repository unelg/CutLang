#define delphes_cxx
#include "delphes.h"
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

void delphes::Loop(analy_struct aselect, char *extname)
{

// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   int prev_RunNumber=-1;

   map < string, int > syst_names;
        syst_names["01_jes"]       = 2;
   AnalysisController aCtrl(&aselect, syst_names);
   aCtrl.Initialize(extname);
   cout << "End of analysis initialization"<<endl;

   Long64_t nentries = fChain->GetEntriesFast();
   if (aselect.maxEvents > 0) nentries=aselect.maxEvents;
   for (Long64_t j=0; j<nentries; ++j) {

       if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       //fChain->GetTree()->GetEntry(j);
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
       vector<dbxTau>      taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>    ljets;
       vector<dbxTruth>   truth;

       map<string, vector<dbxMuon>     > muos_map;
       map<string, vector<dbxElectron> > eles_map;
       map<string, vector<dbxTau>      > taus_map;
       map<string, vector<dbxPhoton>   > gams_map;
       map<string, vector<dbxJet>      > jets_map;
       map<string, vector<dbxJet>     >ljets_map;
       map<string, vector<dbxTruth>    >truth_map;
       map<string, TVector2            >  met_map;


       

//temporary variables
       TLorentzVector  alv, alv_up, alv_down, slv;
       TLorentzVector  alv_msdown, alv_msup, alv_iddown, alv_idup, alv_ptsup,alv_ptsdown;
       TLorentzVector dummyTlv(0.,0.,0.,0.);
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       //dbxTau      *adbxt;
       dbxPhoton   *adbxp;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

        for (unsigned int i=0; i<Muon_; i++) {
                alv.SetPtEtaPhiM( Muon_PT[i], Muon_Eta[i], Muon_Phi[i], (105.658/1E3) ); // all in GeV
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(Muon_Charge[i] );
		adbxe->setPdgID(-13*Muon_Charge[i] );
                adbxm->setEtCone(Muon_IsolationVarRhoCorr[i] );
                adbxm->setPtCone(Muon_IsolationVar[i]        );
                adbxm->setParticleIndx(i);
                muons.push_back(*adbxm);
                delete adbxm;
        }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< Muon_<<std::endl;
#endif
//ELECTRONS

        for (unsigned int i=0; i<Electron_; i++) {
                alv.SetPtEtaPhiM( Electron_PT[i], Electron_Eta[i], Electron_Phi[i], (0.511/1E3) ); // all in GeV
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(Electron_Charge[i] );
		adbxe->setPdgID(-11*Electron_Charge[i] );
                adbxe->setParticleIndx(i);
                adbxe->setClusterE(Electron_EhadOverEem[i] );
                electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< Electron_ <<std::endl;
#endif
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
//JETS
        for (unsigned int i=0; i<Jet_; i++) {
                alv.SetPtEtaPhiM( Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i] ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
                adbxj->setFlavor(Jet_Flavor[i] );
                adbxj->set_isbtagged_77( (Jet_Flavor[i]==5) ); // 5 is btag
        //        adbxj->setJVtxf(Jet_Ntrk[i] );
                jets.push_back(*adbxj);
                delete adbxj;
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
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=Event_Number[0];
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
       ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, met_map,  anevt};

        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
