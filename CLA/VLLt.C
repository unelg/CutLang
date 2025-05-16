#define VLLt_cxx
#include "VLLt.h"
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
#include <iostream>
#include "TTreeReader.h"
using namespace std;

extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;


//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif



void VLLt::Loop(  analy_struct aselect, char *extname )
{
// Signal HANDLER
   signal (SIGINT, _fsig_handler); // signal handler has issues with CINT

   if (fChain == 0) {
          cout <<"Error opening the data file"<<endl; return;
   }

   int verboseFreq(aselect.verbfreq);
   evt_data anevt;
   float blow_th=1.7400;

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

DEBUG("Read Event\n");

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
       TLorentzVector  alv, alv0, alv1, alv2, alv3, alv4, alv5;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;

DEBUG("Begin Filling\n");

//JETS
   unsigned int jet_n=jet_pt_NOSYS->size();
        for (unsigned int i=0; i<jet_n; i++) {
                alv.SetPtEtaPhiE( jet_pt_NOSYS->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_e_NOSYS->at(i)*0.001 ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
//                adbxj->setJVtxf(jets_DFCommonJets_fJvt->at(i));
                adbxj->setFlavor(jet_GN2v01_Continuous_quantile->at(i) );
                adbxj->set_isbtagged_77( jet_GN2v01_FixedCutBEff_77_select->at(i) ); // 5 is btag
                jets.push_back(*adbxj);
                delete adbxj;
        }
DEBUG("Jets ok\n");

//ELECTRONS
    unsigned int ele_n=el_pt_NOSYS->size();
    for (unsigned int i=0; i<ele_n;i++) {
            alv.SetPtEtaPhiE(el_pt_NOSYS->at(i)*0.001, el_eta->at(i), el_phi->at(i), el_e_NOSYS->at(i)*0.001);
            adbxe = new dbxElectron(alv);
            adbxe->setCharge(el_charge->at(i));
            adbxe->setParticleIndx(i);
            electrons.push_back(*adbxe);
            delete adbxe;
    }

//MUONS
    unsigned int mu_n=mu_pt_NOSYS->size();
    for (unsigned int i=0; i<mu_n; i++){
            alv.SetPtEtaPhiE(mu_pt_NOSYS->at(i)*0.001, mu_eta->at(i), mu_phi->at(i), mu_e_NOSYS->at(i)*0.001);
            adbxm = new dbxMuon(alv);
            adbxm->setCharge(mu_charge->at(i));
            adbxm->setParticleIndx(i);
            muons.push_back(*adbxm);
            delete adbxm;
    }
      
//MET
        met.SetMagPhi( met_met_NOSYS*0.001,  met_phi_NOSYS);


//------------ auxiliary information -------
        anevt.run_no=runNumber;
	anevt.ChannelNo=mcChannelNumber;
	anevt.RunYear=1;
        anevt.correction_weight=1.0;
        anevt.luminosity_weight=1.0;
        anevt.weight_xsec=1.0;
        anevt.user_evt_weight=1.0;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.event_no=eventNumber;
        anevt.TRG_e= 1;
        anevt.TRG_m= 1;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 9;
        anevt.badjet=0;
        anevt.weight_mc=1;
	anevt.m_HF_Classification=1;
        anevt.weight_pileup=1;
	anevt.weight_jvt=1;
        anevt.z_vtx_weight = 1.0;
        anevt.weight_bTagSF_77 = 1;
        anevt.weight_leptonSF = 1;
        anevt.vxpType=0;
        anevt.lar_Error=0;
        anevt.core_Flags=0;
        anevt.maxEvents=nentries;



DEBUG("Filling finished"<<std::endl);
        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxJet>      > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       track_map.insert( pair <string,vector<dbxTrack>    > ("Track",       track) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );
    if (constits_map.size() < 1) // we only add this if it was previously empty...
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );

    ttr_map["reco"]->SetEntry(j);
    AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map,track_map, combo_map, constits_map, met_map, anevt};
    aCtrl.RunTasks(a0);


}// end of event loop
   aCtrl.Finalize();

}
