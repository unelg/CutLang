#define CMSnanoAOD_cxx
#include "CMSnanoAOD.h"
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
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;


       map<string, vector<dbxMuon>     >  muos_map;
       map<string, vector<dbxElectron> >  eles_map;
       map<string, vector<dbxTau>      >  taus_map;
       map<string, vector<dbxPhoton>   >  gams_map;
       map<string, vector<dbxJet>      >  jets_map;
       map<string, vector<dbxJet>      > ljets_map;
       map<string, vector<dbxTruth>    > truth_map;
       map<string, vector<dbxParticle> > combo_map;
       map<string, vector<dbxParticle> > constits_map;
       map<string, TVector2            >   met_map;

//temporary variables
       TLorentzVector  alv;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       dbxTau      *adbxt;
       dbxPhoton   *adbxp;
       dbxTruth    *adbxg;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

        for (unsigned int i=0; i<nMuon; i++) {
                alv.SetPtEtaPhiM( Muon_pt[i], Muon_eta[i], Muon_phi[i], (105.658/1E3) ); // all in GeV
                adbxm= new dbxMuon(alv);
                adbxm->setCharge(Muon_charge[i] );
                adbxm->setPdgID(-13*Muon_charge[i] );
//                adbxm->setEtCone(Muon_IsolationVarRhoCorr[i] );
//                adbxm->setPtCone(Muon_IsolationVar[i]        );
                adbxm->addAttribute( Muon_dz[i]);         // attri 0
                adbxm->addAttribute( Muon_dxy[i]     );   // attri 1
                adbxm->addAttribute( Muon_miniPFRelIso_all[i]     ); // attri 2
                adbxm->addAttribute( Muon_softId[i]     ); // attri 3
                adbxm->addAttribute( Muon_tightId[i]    ); // attri 4
                adbxm->addAttribute( Muon_genPartIdx[i]    ); // attri 5
                adbxm->addAttribute( Muon_pfRelIso03_all[i]    ); // attri 6
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
                adbxm->setPdgID(-11*Electron_charge[i] );
                adbxe->setParticleIndx(i);
                adbxe->addAttribute( Electron_dz[i]);       // attri 0
                adbxe->addAttribute( Electron_dxy[i]     ); // attri 1
                adbxe->addAttribute( Electron_miniPFRelIso_all[i]  ); // attri 2 
                electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< nElectron <<std::endl;
#endif
//PHOTONS
        for (unsigned int i=0; i<nPhoton; i++) {
                alv.SetPtEtaPhiM( Photon_pt[i], Photon_eta[i], Photon_phi[i], 0 ); // all in GeV
                adbxp= new dbxPhoton(alv);
                adbxp->setCharge(0);
                adbxp->setParticleIndx(i);
                photons.push_back(*adbxp);
                delete adbxp;
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<nPhoton<<std::endl;
#endif
//GENS
        for (unsigned int i=0; i<nGenPart; i++) {
                alv.SetPtEtaPhiM( GenPart_pt[i], GenPart_eta[i], GenPart_phi[i], GenPart_mass[i] ); // all in GeV
                adbxg= new dbxTruth(alv);
                adbxg->setPdgID(GenPart_pdgId[i] );
                adbxg->setCharge(GenPart_pdgId[i]/abs(GenPart_pdgId[i]) );
                adbxg->setParticleIndx(i);
                adbxg->addAttribute( 0);   // 0
                adbxg->addAttribute( 0);  // 1 
                adbxg->addAttribute( 0); // 2 
                adbxg->addAttribute( GenPart_status[i] ); // 3
                truth.push_back(*adbxg);
                delete adbxg;
        }
#ifdef __DEBUG__
std::cout << "Truth OK:"<<nGenPart<<std::endl;
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
                adbxj->addAttribute( (double)Jet_puId[i]);       // attri 0
                jets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<nJet<<std::endl;
#endif
//LJETS---------------------FATJET--------------------------------------
        for (unsigned int i=0; i<nFatJet; i++) {
                alv.SetPtEtaPhiM( FatJet_pt[i], FatJet_eta[i], FatJet_phi[i], FatJet_mass[i] ); // all in GeV
                adbxj= new dbxJet(alv);
                adbxj->setCharge(-99);
                adbxj->setParticleIndx(i);
                adbxj->setFlavor(FatJet_btagDeepB[i] );
                adbxj->set_isbtagged_77( (FatJet_btagDeepB[i]>0.8) ); // 5 is btag
                adbxj->addAttribute( FatJet_msoftdrop[i]); // attri 0
                adbxj->addAttribute( FatJet_tau1[i]     ); // attri 1
                adbxj->addAttribute( FatJet_tau2[i]     ); // attri 2
                adbxj->addAttribute( FatJet_tau3[i]     ); // attri 3
                ljets.push_back(*adbxj);
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "FatJets:"<<nFatJet<<std::endl;
#endif
//TAUS
        for (unsigned int i=0; i<nTau; i++) {
                alv.SetPtEtaPhiM( Tau_pt[i], Tau_eta[i], Tau_phi[i], Tau_mass[i] ); // all  in GeV
                adbxt= new dbxTau(alv);
                adbxt->setCharge(-99);
                adbxt->setParticleIndx(i);
                adbxt->setIsolation(Tau_idMVAnewDM2017v2[i] );
                adbxt->addAttribute(Tau_idMVAnewDM2017v2[i] ); // attri 0
                adbxt->addAttribute(Tau_idDecayMode[i] ); // attri 1
                adbxt->addAttribute(Tau_idIsoTight[i] ); // attri 2
                adbxt->addAttribute(Tau_idAntiEleTight[i] ); // attri 3
                adbxt->addAttribute(Tau_idAntiMuTight[i] ); // attri 4
                adbxt->addAttribute(Tau_genPartIdx[i] ); // attri 5
                adbxt->addAttribute(Tau_relIso_all[i] ); // attri 6
                adbxt->addAttribute(Tau_decayMode[i] ); // attri 5
//--------added tau variables for SS.
                taus.push_back(*adbxt);
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
        anevt.user_evt_weight=1;
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
        anevt.HLT_IsoMu17_eta2p1_LooseIsoPFTau20=HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
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
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map, anevt};

        aCtrl.RunTasks(a0);

   }// endof events

  aCtrl.Finalize();
}//end of loop
