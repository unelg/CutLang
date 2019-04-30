#define CMSnanoAOD_cxx
#include "CMSnanoAOD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <signal.h>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_ljet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"

// header and lines to handle ctrl+C gracefully
extern void _fsig_handler (int) ;
extern bool fctrlc;

void CMSnanoAOD::Loop(analy_struct aselect, char *extname)
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
       if (0 > LoadTree (j)) break;
       if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;
       fChain->GetEntry(j);

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxLJet>    ljets;
       vector<dbxTau>     taus;
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

        for (unsigned int i=0; i<nMuon; i++) {
                alv.SetPtEtaPhiM( Muon_pt[i], Muon_eta[i], Muon_phi[i], (105.658/1E3) ); // all in GeV
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(Muon_charge[i] );
//                adbxm->setEtCone(Muon_IsolationVarRhoCorr[i] );
//                adbxm->setPtCone(Muon_IsolationVar[i]        );
                adbxm->setParticleIndx(i);
                muons.push_back(*adbxm);
                delete adbxm;
        }
#ifdef __DEBUG__
std::cout << "Muons OK:"<< Muon_<<std::endl;
#endif
//ELECTRONS

        for (unsigned int i=0; i<nElectron; i++) {
                alv.SetPtEtaPhiM( Electron_pt[i], Electron_eta[i], Electron_phi[i], (0.511/1E3) ); // all in GeV
                adbxe= new dbxElectron(alv);
                adbxe->setCharge(Electron_charge[i] );
                adbxe->setParticleIndx(i);
//                adbxe->setClusterE(Electron_EhadOverEem[i] );
                electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< Electron_ <<std::endl;
#endif
//PHOTONS
        for (unsigned int i=0; i<nPhoton; i++) {
                alv.SetPtEtaPhiM( Photon_pt[i], Photon_eta[i], Photon_phi[i], 0 ); // all in GeV
                adbxp= new dbxPhoton(alv);
                adbxp->setCharge(0);
                adbxp->setParticleIndx(i);
//                adbxp->setClusterE(Photon_EhadOverEem[i] );
                photons.push_back(*adbxp);
                delete adbxp;
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<Photon_size<<std::endl;
#endif
//JETS
        for (unsigned int i=0; i<nJet; i++) {
                alv.SetPtEtaPhiM( Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i] ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
                adbxj->setFlavor(Jet_btagDeepB[i] );
                adbxj->set_isbtagged_77( (Jet_btagDeepB[i]>0.8) ); // 5 is btag
        //        adbxj->setJVtxf(Jet_Ntrk[i] );
                jets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<Jet_<<std::endl;
#endif
//TAUS
        for (unsigned int i=0; i<nTau; i++) {
                alv.SetPtEtaPhiM( Tau_pt[i], Tau_eta[i], Tau_phi[i], Tau_mass[i] ); // all  in GeV
                adbxt= new dbxTau(alv);
                adbxt->setCharge(-99);
                adbxt->setParticleIndx(i);
                adbxt->setIsolation(Tau_idMVAnewDM2017v2[i] );
                taus.push_back(*adbxtau);
                delete adbxt;
        }
#ifdef __DEBUG__
std::cout << "Taus:"<<Tau_<<std::endl;
#endif
//MET
        met.SetMagPhi( MET_pt,  MET_phi);
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif

        anevt.run_no=run;
        anevt.lumiblk_no=luminosityBlock;
        anevt.top_hfor_type=0;
        anevt.event_no=event;
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
        taus_map.insert( pair <string,vector<dbxElectron> > ("TAU",     electrons) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxLJet>     > ("Fatjet",      ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, met_map, anevt};

        aCtrl.RunTasks(a0);

   }// endof events

  aCtrl.Finalize();
}//end of loop