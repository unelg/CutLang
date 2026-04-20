#define CMSnanoAOD_cxx
#include "CMSnanoAOD.h"
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
#include <unordered_map>

// header and lines to handle ctrl+C gracefully
extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;

void CMSnanoAOD::Loop(analy_struct aselect, char *extname)
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

   // Declare maps BEFORE the event loop
 unordered_map<string, vector<dbxMuon>     > muos_map;
 unordered_map<string, vector<dbxElectron> > eles_map;
 unordered_map<string, vector<dbxTau>      > taus_map;
 unordered_map<string, vector<dbxPhoton>   > gams_map;
 unordered_map<string, vector<dbxJet>      > jets_map;
 unordered_map<string, vector<dbxJet>      > ljets_map;
 unordered_map<string, vector<dbxTruth>    > truth_map;
 unordered_map<string, vector<dbxTrack>    > track_map;
 unordered_map<string, vector<dbxParticle> > combo_map;
 unordered_map<string, vector<dbxParticle> > constits_map;
 unordered_map<string, TVector2            > met_map;
// Pre-populate with fixed keys once
muos_map["MUO"];  eles_map["ELE"];  taus_map["TAU"];
gams_map["PHO"];  jets_map["JET"];  ljets_map["FJET"];
truth_map["Truth"]; track_map["Track"];
combo_map["Combo"]; constits_map["Constits"]; met_map["MET"];

AnalysisObjects a0;

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
       vector<dbxTrack>    track;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;
       muos_map["MUO"].clear();
       eles_map["ELE"].clear();
       taus_map["TAU"].clear();
       gams_map["PHO"].clear();
       jets_map["JET"].clear();
       ljets_map["FJET"].clear();
       truth_map["Truth"].clear();
       track_map["Track"].clear();
       combo_map["Combo"].clear();
       constits_map["Constits"].clear();
       met_map["MET"].Clear();

//temporary variables
       TLorentzVector  alv;
       TVector2 met;

//#define __DEBUG__
#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif

        for (unsigned int i=0; i<nMuon; i++) {
                alv.SetPtEtaPhiM( Muon_pt[i], Muon_eta[i], Muon_phi[i], (105.658/1E3) ); // all in GeV
                muons.emplace_back(alv);
                muons.back().setCharge(Muon_charge[i] );
                muons.back().setPdgID(-13*Muon_charge[i] );
                muons.back().addAttribute( Muon_dz[i]);         // attri 0
                muons.back().addAttribute( Muon_dxy[i]     );   // attri 1
                muons.back().addAttribute( Muon_miniPFRelIso_all[i]     ); // attri 2
                muons.back().addAttribute( Muon_softId[i]     ); // attri 3
                muons.back().addAttribute( Muon_tightId[i]    ); // attri 4
                muons.back().addAttribute( Muon_genPartIdx[i]    ); // attri 5
                muons.back().addAttribute( Muon_pfRelIso03_all[i]    ); // attri 6
                muons.back().setParticleIndx(i);
        }
#ifdef __DEBUG__
std::cout << "Muons OK:"<< nMuon<<std::endl;
#endif
//ELECTRONS

        for (unsigned int i=0; i<nElectron; i++) {
                alv.SetPtEtaPhiM( Electron_pt[i], Electron_eta[i], Electron_phi[i], (0.511/1E3) ); // all in GeV
                electrons.emplace_back(alv);
                electrons.back().setCharge(Electron_charge[i] );
                electrons.back().setPdgID(-11*Electron_charge[i] );
                electrons.back().setParticleIndx(i);
                electrons.back().addAttribute( Electron_dz[i]);       // attri 0
                electrons.back().addAttribute( Electron_dxy[i]     ); // attri 1
                electrons.back().addAttribute( Electron_miniPFRelIso_all[i]  ); // attri 2 
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< nElectron <<std::endl;
#endif
//PHOTONS
        for (unsigned int i=0; i<nPhoton; i++) {
                alv.SetPtEtaPhiM( Photon_pt[i], Photon_eta[i], Photon_phi[i], 0 ); // all in GeV
                photons.emplace_back(alv);
                photons.back().setCharge(0);
                photons.back().setParticleIndx(i);
                photons.back().addAttribute( Photon_sieie[i]);   // 0
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<nPhoton<<std::endl;
#endif
//GENS
        for (unsigned int i=0; i<nGenPart; i++) {
                alv.SetPtEtaPhiM( GenPart_pt[i], GenPart_eta[i], GenPart_phi[i], GenPart_mass[i] ); // all in GeV
                truth.emplace_back(alv);
                truth.back().setPdgID(GenPart_pdgId[i] );
                truth.back().setCharge(GenPart_pdgId[i]/abs(GenPart_pdgId[i]) );
                truth.back().setParticleIndx(i);
                truth.back().addAttribute( 0);   // 0
                truth.back().addAttribute( 0);  // 1 
                truth.back().addAttribute( 0); // 2 
                truth.back().addAttribute( GenPart_status[i] ); // 3
        }
#ifdef __DEBUG__
std::cout << "Truth OK:"<<nGenPart<<std::endl;
#endif



//JETS
        for (unsigned int i=0; i<nJet; i++) {
                alv.SetPtEtaPhiM( Jet_pt[i], Jet_eta[i], Jet_phi[i], Jet_mass[i] ); // all in GeV
                jets.emplace_back(alv);
                jets.back().setCharge(-99);
                jets.back().setParticleIndx(i);
                jets.back().setFlavor(Jet_btagDeepB[i] );
                jets.back().set_isbtagged_77( (Jet_btagDeepB[i]>0.8) ); // 5 is btag
        //        jets.back().setJVtxf(Jet_Ntrk[i] );
                jets.back().addAttribute( (double)Jet_puId[i]);       // attri 0
        }
#ifdef __DEBUG__
std::cout << "Jets:"<<nJet<<std::endl;
#endif
//LJETS---------------------FATJET--------------------------------------
        for (unsigned int i=0; i<nFatJet; i++) {
                alv.SetPtEtaPhiM( FatJet_pt[i], FatJet_eta[i], FatJet_phi[i], FatJet_mass[i] ); // all in GeV
                ljets.emplace_back(alv);
                ljets.back().setCharge(-99);
                ljets.back().setParticleIndx(i);
                ljets.back().setFlavor(FatJet_btagDeepB[i] );
                ljets.back().set_isbtagged_77( (FatJet_btagDeepB[i]>0.8) ); // 5 is btag
                ljets.back().addAttribute( FatJet_msoftdrop[i]); // attri 0
                ljets.back().addAttribute( FatJet_tau1[i]     ); // attri 1
                ljets.back().addAttribute( FatJet_tau2[i]     ); // attri 2
                ljets.back().addAttribute( FatJet_tau3[i]     ); // attri 3
        }
#ifdef __DEBUG__
std::cout << "FatJets:"<<nFatJet<<std::endl;
#endif
//TAUS
        for (unsigned int i=0; i<nTau; i++) {
                alv.SetPtEtaPhiM( Tau_pt[i], Tau_eta[i], Tau_phi[i], Tau_mass[i] ); // all  in GeV
                taus.emplace_back(alv);
                taus.back().setCharge(-99);
                taus.back().setParticleIndx(i);
                taus.back().setIsolation(Tau_idMVAnewDM2017v2[i] );
                taus.back().addAttribute(Tau_idMVAnewDM2017v2[i] ); // attri 0
                taus.back().addAttribute(Tau_idDecayMode[i] ); // attri 1
                taus.back().addAttribute(Tau_idIsoTight[i] ); // attri 2
                taus.back().addAttribute(Tau_idAntiEleTight[i] ); // attri 3
                taus.back().addAttribute(Tau_idAntiMuTight[i] ); // attri 4
                taus.back().addAttribute(Tau_genPartIdx[i] ); // attri 5
                taus.back().addAttribute(Tau_relIso_all[i] ); // attri 6
                taus.back().addAttribute(Tau_decayMode[i] ); // attri 5
//--------added tau variables for SS.
        }
#ifdef __DEBUG__
std::cout << "Taus:"<<nTau<<std::endl;
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

        ttr_map["Events"]->SetEntry(j);
        TTreeReader myreader("Events",fChain->GetDirectory() );
        vector<TTreeReaderValue<Bool_t> > myHLTs;
        vector<string> myHLT_names;

        // Extract the first token book variables
        std::string s = aselect.hlt;
        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
 //               DEBUG(token <<"\n");
                TTreeReaderValue<Bool_t> myHLT(myreader,token.c_str() );
                myHLTs.push_back(myHLT);
                myHLT_names.push_back(token);
                s.erase(0, pos + delimiter.length());
        }
        myreader.SetEntry(j);

        // Extract the values
        for (unsigned int hv=0; hv<myHLTs.size(); hv++){
                Bool_t trgvalue=*(myHLTs[hv]);
//                DEBUG(myHLT_names[hv]<<":" << trgvalue << std::endl);
                anevt.hlt_map[myHLT_names[hv]]=trgvalue; // filling map
        }

#ifdef __DEBUG__
std::cout << "Filling finished"<<std::endl;
#endif
        muos_map["MUO"].swap(muons);
        eles_map["ELE"].swap(electrons);
        taus_map["TAU"].swap(taus);
        gams_map["PHO"].swap(photons);
        jets_map["JET"].swap(jets);
        ljets_map["FJET"].swap(ljets);
        truth_map["Truth"].swap(truth);
        track_map["Track"].swap(track);
        combo_map["Combo"].swap(combos);
        constits_map["Constits"].swap(constis);
        met_map["MET"] = met;
        a0.muos = muos_map;
        a0.eles = eles_map;
        a0.taus = taus_map;
        a0.gams = gams_map;
        a0.jets = jets_map;
        a0.ljets = ljets_map;
        a0.truth = truth_map;
        a0.track = track_map;
        a0.combos = combo_map;
        a0.constits = constits_map;
        a0.met = met_map;
        a0.evt = anevt;

        aCtrl.RunTasks(a0);

   }// endof events

  aCtrl.Finalize();
}//end of loop
