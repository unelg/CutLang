#define delphes_cxx
#include "delphes.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <signal.h>
#include <TObject.h>
#include <TBranchElement.h>

#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_a.h"
#include "DBXNtuple.h"
#include "analysis_core.h"
#include "AnalysisController.h"
#include <unistd.h>
#include "TTreeReader.h"
#include <unordered_map>

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


extern void _fsig_handler (int) ;
extern bool fctrlc;


TClonesArray* delphes::UseBranch(const char *branchName, TTree *fChain){
  TClonesArray *array = 0;
  TBranchMap::iterator itBranchMap = fBranchMap.find(branchName);
  if(itBranchMap != fBranchMap.end()) {
    cout << "** WARNING: branch '" << branchName << "' is already in use" << endl;
    array = itBranchMap->second.second;
  } else {      
    TBranch *branch = fChain->GetBranch(branchName);
    if(branch) {
      if(branch->IsA() == TBranchElement::Class()) {
        TBranchElement *element = static_cast<TBranchElement *>(branch);
        const char *className = element->GetClonesName();
        Int_t size = element->GetMaximum();
        TClass *cl = gROOT->GetClass(className);
        if(cl) {
          array = new TClonesArray(cl, size);
          array->SetName(branchName);
          fBranchMap.insert(make_pair(branchName, make_pair(branch, array)));
          branch->SetAddress(&array);
        }
      }
    }
  }

  if(!array) {
    cout << "** WARNING: cannot access branch '" << branchName << "', return NULL pointer" << endl;
  }
  return array;
};


void delphes::Loop(analy_struct aselect, char *extname)
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

   TClonesArray *branchParticle = UseBranch("Particle", fChain);
   TClonesArray *branchJet = UseBranch("Jet", fChain);
   TClonesArray *branchFJet = UseBranch("FatJet", fChain);
   TClonesArray *branchPhoton = UseBranch("Photon", fChain);
   TClonesArray *branchElectron = UseBranch("Electron", fChain);
   TClonesArray *branchMuon = UseBranch("Muon", fChain);
   TClonesArray *branchTrack = UseBranch("Track", fChain);
   TClonesArray *branchEFlowPhoton = UseBranch("EFlowPhoton", fChain);
   TClonesArray *branchEFT = UseBranch("EFlowTrack", fChain);
   TClonesArray *branchEFN = UseBranch("EFlowNeutralHadron", fChain);
   TClonesArray *branchMET = UseBranch("MissingET", fChain);
//-----------------------------------------------------------min and max nb events
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentinfile=nentries;
   cout << "number of entries " << nentries << endl;
   if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
   cout << "Forced number of entries " << nentries << endl;
   Long64_t startevent = 0;
   if (aselect.startpt>0 ) startevent=aselect.startpt;
   Long64_t lastevent = startevent + nentries;
   cout << "starting entry " << startevent << "  last:"<<lastevent<< endl;
   if (lastevent > nentinfile ) { lastevent=nentinfile;
     cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
   }
//--------------------------------------------------------------generic variables

   GenParticle *particle;
   Jet *jet;
   FatJet *fjet;
   Photon *photon;
   Electron *electron;
   Muon *muon;
   MissingET *metd;
   Track *track;
   Int_t i, j;
   TObject *object;
   TLorentzVector momentum;
   Track *eftrk;
   Tower *efpho;
   Tower *efnh;

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

//--------------------------------------------------------------event loop
   for (Long64_t je=startevent; je<lastevent; ++je) {

       if ( fctrlc ) { cout << "Processed " << je << " events\n"; break; }
       if ( je%verboseFreq == 0 ) cout << "Processing event " << je << endl;
       DEBUG("Read Event:"<<je<<std::endl);
       int RunNumber=137;
// Load selected branches with data from specified event
  fChain->LoadTree(je);

  TBranchMap::iterator itBranchMap;
  TBranch *branch;
  for(itBranchMap = fBranchMap.begin(); itBranchMap != fBranchMap.end(); ++itBranchMap) {
    branch = itBranchMap->second.first;
    if(branch) {
      branch->GetEntry(je);
    }
  }
  DEBUG("Branch Entries retrieved\n");

       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>      taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>     ljets;
       vector<dbxTruth>   truth;
       vector<dbxTrack>   tracks;
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
       TLorentzVector  alv, alv_up, alv_down, slv;
       TLorentzVector  alv_msdown, alv_msup, alv_iddown, alv_idup, alv_ptsup,alv_ptsdown;
       TLorentzVector dummyTlv(0.,0.,0.,0.);
       TVector2 met;
      DEBUG("Begin Filling"<<std::endl);
      if (branchMuon != NULL)
      for(i = 0; i < branchMuon->GetEntriesFast(); ++i) {
              muon= (Muon*) branchMuon->At(i);
              alv.SetPtEtaPhiM( muon->PT, muon->Eta, muon->Phi, (105.658/1E3) ); // all in GeV
              muons.emplace_back(alv);
              muons.back().setCharge(muon->Charge );
      	      muons.back().setPdgID(-13*muon->Charge );
              muons.back().setEtCone(muon->IsolationVarRhoCorr);
              muons.back().setPtCone(muon->IsolationVar       );
              muons.back().setParticleIndx(i);
              muons.back().addAttribute( muon->DZ);          //0
              muons.back().addAttribute( muon->D0);         //1
              muons.back().addAttribute( muon->IsolationVar   ); //2
//---calculate miniiso here.
	      double minisovar=0.0;
	      double absisovar=0.0;
              double coneradius;

              if (muon->PT < 50) { // small PT recipe 
                coneradius=0.2;
              } else if (muon->PT < 200){             // medium PT recipe
                coneradius=10 / (muon->PT) ;
              } else {        // large PT recipe
                coneradius=0.05;
              }

// EFphotons
              if (branchEFlowPhoton)
              for ( int im=0; im < branchEFlowPhoton->GetEntriesFast(); ++im){
               efpho= ( Tower *) branchEFlowPhoton->At(im);
   DEBUG("mPT:"<<muon->PT<<" ET:"<<efpho->ET<<" Eta:"<<efpho->Eta << " Phi:"<< efpho->Phi << " E:"<<efpho->E<<"\n");
               slv.SetPtEtaPhiE( efpho->ET, efpho->Eta, efpho->Phi, efpho->E ); // all in GeV
               // DEBUG("M:"<<slv.M()<<"\n");
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) { minisovar+=slv.Pt();
//                                          cout << " pt:"<<efpho->ET<<"\n";
                                        }
              }
//              cout << "P mini iso:"<<minisovar<<"\n";
// EFTracks
              if (branchEFT)
              for ( int it=0; it < branchEFT->GetEntriesFast(); ++it){
               eftrk= ( Track *) branchEFT->At(it);
//               if ( eftrk->PT == muon->PT) { cout << "Same PT as muon\n"; }
               slv.SetPtEtaPhiM( eftrk->PT, eftrk->Eta, eftrk->Phi,  eftrk->Mass ); // all in GeV
if (it == 0){
   DEBUG("tET:"<<eftrk->PT<<" Eta:"<<eftrk->Eta << " Phi:"<< eftrk->Phi << " M:"<<eftrk->Mass <<"\n");
}
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) minisovar+=slv.Pt();
               if (deltaR < 0.3 && eftrk->PT != muon->PT) absisovar+=slv.Pt();
              }
              
//              cout << "T mini iso:"<<minisovar<<"\n";

// EFNeutralHAdrons
              if (branchEFN)
              for (int in=0; in < branchEFN->GetEntriesFast(); ++in){
               efnh= ( Tower *) branchEFN->At(in);
   DEBUG(" PT:"<<efnh->ET<<" Eta:"<<efnh->Eta << " Phi:"<< efnh->Phi << " E:"<<efnh->E<<"\n");
               slv.SetPtEtaPhiE( efnh->ET, efnh->Eta, efnh->Phi, efnh->E ); // all in GeV
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) minisovar+=slv.Pt();
              }
//              cout << "N mini iso:"<<minisovar<<"\n";


//              minisovar=(minisovar-muon->PT)/muon->PT;
             //if (minisovar>0) cout << " mini iso:"<<minisovar<<"\n";
//              cout << " --> muon pT, mini iso:"<< muon->PT << ", " << minisovar<<"\n";
              muons.back().addAttribute( minisovar ); // 3
              muons.back().addAttribute( absisovar ); // 4
//             if (minisovar > 0.2) cout << minisovar << " muon" << endl;
      }
      DEBUG("Muons OK:"<< branchMuon->GetEntriesFast()<< std::endl);

//ELECTRONS
      if (branchElectron != NULL)
      for(i = 0; i < branchElectron->GetEntriesFast(); ++i) {
              electron= (Electron*) branchElectron->At(i);
              alv.SetPtEtaPhiM( electron->PT, electron->Eta, electron->Phi, (0.511/1E3) ); // all in GeV
              electrons.emplace_back(alv);
              electrons.back().setCharge(electron->Charge );
      	      electrons.back().setPdgID(-11*electron->Charge );
              electrons.back().setParticleIndx(i);
              electrons.back().setClusterE(electron->EhadOverEem );
              electrons.back().addAttribute( electron->DZ);         // 0
              electrons.back().addAttribute( electron->D0     );   // 1
              electrons.back().addAttribute( electron->IsolationVar );


//---calculate miniiso here.
	      double minisovar=0.0;
	      double absisovar=0.0;
              double coneradius;
              if (electron->PT < 50) { // small PT recipe 
                coneradius=0.2;
              } else if (electron->PT < 200){             // medium PT recipe
                coneradius=10 / (electron->PT) ;
              } else {        // large PT recipe
                coneradius=0.05;
              }
// EFphotons
              if (branchEFlowPhoton)
              for ( int im=0; im < branchEFlowPhoton->GetEntriesFast(); ++im){
               efpho= ( Tower *) branchEFlowPhoton->At(im);
   DEBUG("mPT:"<<electron->PT<<" ET:"<<efpho->ET<<" Eta:"<<efpho->Eta << " Phi:"<< efpho->Phi << " E:"<<efpho->E<<"\n");
               slv.SetPtEtaPhiE( efpho->ET, efpho->Eta, efpho->Phi, efpho->E ); // all in GeV
               // DEBUG("M:"<<slv.M()<<"\n");
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) { minisovar+=slv.Pt();
//                                          cout << " pt:"<<efpho->ET<<"\n";
                                        }
              }
//              cout << "P mini iso:"<<minisovar<<"\n";
// EFTracks
              if (branchEFT)
              for ( int it=0; it < branchEFT->GetEntriesFast(); ++it){
               eftrk= ( Track *) branchEFT->At(it);
//               if ( eftrk->PT == electron->PT) { cout << "Same PT as electron\n"; }
               slv.SetPtEtaPhiM( eftrk->PT, eftrk->Eta, eftrk->Phi,  eftrk->Mass ); // all in GeV
if (it == 0){
   DEBUG("tET:"<<eftrk->PT<<" Eta:"<<eftrk->Eta << " Phi:"<< eftrk->Phi << " M:"<<eftrk->Mass <<"\n");
}
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) minisovar+=slv.Pt();
               if (deltaR < 0.3 && eftrk->PT != electron->PT) absisovar+=slv.Pt();
              }
//              cout << "T mini iso:"<<minisovar<<"\n";

// EFNeutralHAdrons
              if (branchEFN)
              for (int in=0; in < branchEFN->GetEntriesFast(); ++in){
               efnh= ( Tower *) branchEFN->At(in);
   DEBUG(" PT:"<<efnh->ET<<" Eta:"<<efnh->Eta << " Phi:"<< efnh->Phi << " E:"<<efnh->E<<"\n");
               slv.SetPtEtaPhiE( efnh->ET, efnh->Eta, efnh->Phi, efnh->E ); // all in GeV
               double deltaR=alv.DeltaR(slv);
               if (deltaR < coneradius) minisovar+=slv.Pt();
              }
//              cout << "N mini iso:"<<minisovar<<"\n";


              minisovar=(minisovar-electron->PT)/electron->PT;
             //if (minisovar>0) cout << " mini iso:"<<minisovar<<"\n";
//              cout << " --> electron pT, mini iso:"<< electron->PT << ", " << minisovar<<"\n";

 //             if (minisovar > 0.1) cout << minisovar << " electron" << endl;

              electrons.back().addAttribute( minisovar ); // mini 3
              electrons.back().addAttribute( absisovar ); // abs  4
      }
      DEBUG("Electrons OK:"<< i <<std::endl);
//PHOTONS
      if (branchPhoton != NULL)
      for(i = 0; i < branchPhoton->GetEntriesFast(); ++i) {
                photon= (Photon*) branchPhoton->At(i);
                alv.SetPtEtaPhiM( photon->PT, photon->Eta, photon->Phi, 0 ); // all in GeV
                photons.emplace_back(alv);
                photons.back().setCharge(0);
                photons.back().setParticleIndx(i);
                photons.back().setClusterE(photon->EhadOverEem );
        }
        DEBUG("Photons OK:"<<i<<std::endl);

//------------------------------------------------------
// TRACKS...
    // Selecting tracks
      if (branchTrack != NULL)
      for(i = 0; i < branchTrack->GetEntriesFast(); ++i) {
        track= (Track*) branchTrack->At(i);
        double Tr_pt = track->PT;
        double Tr_eta = track->Eta;
        int TparticleId  =  track->PID; 
        slv.SetPtEtaPhiM( Tr_pt, Tr_eta, track->Phi,  track->Mass );
        tracks.emplace_back(slv);
        tracks.back().setParticleIndx(i);
      	tracks.back().setPdgID( TparticleId );

        double mT = 0.01;

        bool isElectron   = ( TparticleId== 11 || TparticleId == -11) ;
        bool isMuon       = ( TparticleId== 13 || TparticleId == -13) ;
        double aFlavor = 0;
        double IsoCone    = 0.3 ;
        double ChargedSum = 0.0;
        for(int kk = 0; kk < branchTrack->GetEntriesFast(); ++kk) {
         Track *atrack = (Track*) branchTrack->At(kk);
         alv.SetPtEtaPhiM( atrack->PT, atrack->Eta, atrack->Phi,  atrack->Mass );
         double deltaR=slv.DeltaR(alv);
         if (deltaR < IsoCone ) ChargedSum+=atrack->PT;
 //        if (deltaR < IsoCone && fabs(atrack->Charge) >0) ChargedSum+=atrack->PT;
        } 
//        cout <<" Charged sum:"<<ChargedSum<<"\t";
//  we extract the main  track's PT?
        ChargedSum -= Tr_pt;
//        cout <<" corrected:"<<ChargedSum<<"\n";
 //       cout <<"PDGID:"<<TparticleId<<"\n";
        tracks.back().setPtCone(ChargedSum);

 //iso tracks
        if ( (isMuon || isElectron) && Tr_pt >  5 && mT < 100 && ChargedSum/Tr_pt < 0.2) { aFlavor=1; }
        if (!(isMuon || isElectron) && Tr_pt > 10 && mT < 100 && ChargedSum/Tr_pt < 0.1) { aFlavor=2; }

        tracks.back().setFlavor(aFlavor); 
      }
//------------------------------------------------------
// regular jets

    // Loop over all jets in event
    if (branchJet != NULL)
    for(i = 0; i < branchJet->GetEntriesFast(); ++i) { 
      jet = (Jet*) branchJet->At(i);
      alv.SetPtEtaPhiM( jet->PT, jet->Eta, jet->Phi, jet->Mass ); // all in GeV
//      cout<<"This Jet pt: "<<jet->PT<<", eta: "<<jet->Eta<<", phi: "<<jet->Phi <<" Q:"<<jet->Charge<<endl;
      jets.emplace_back(alv);
      jets.back().setCharge(jet->Charge);
      jets.back().setParticleIndx(i);
      jets.back().setFlavor(jet->Flavor);
      jets.back().set_isbtagged_77(  (bool)jet->BTag ); //  btag
      jets.back().set_isTautagged( (bool)jet->TauTag); // tau tag
// Loop over all jet's constituents
      for(j = 0; j < jet->Particles.GetEntriesFast(); ++j) {
       object = jet->Particles.At(j);
// Check if the constituent is accessible
       if(object == 0) continue;
       if(object->IsA() == GenParticle::Class()) {
        particle = (GenParticle*) object;
//        cout << "    GenPart pt: " << particle->PT << ", eta: " << particle->Eta << ", M: " << particle->Mass << endl;
        alv.SetPtEtaPhiM( particle->PT, particle->Eta, particle->Phi, particle->Mass ); 
        constis.emplace_back(alv);
        constis.back().setCharge( particle->Charge );
        constis.back().setPdgID(  particle->PID );
        constis.back().setParticleIndx(j);
        constis.back().addAttribute( particle->DZ);  //0
        constis.back().addAttribute( particle->D0);  
        constis.back().addAttribute( 0     ); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
        constis.back().addAttribute( particle->Status ); //3
        constis.back().addAttribute( particle->Z ); //4
        constis.back().addAttribute( particle->Y ); //5
        constis.back().addAttribute( particle->X ); //6
        constis.back().addAttribute( particle->T ); //7
       }
      }// end of loop over jets constits.
    if (constis.size() > 0){
      TString cname ="JET_";
              cname+=i;    // jet index
              cname+="c"; //  c for constituents
       constits_map[cname.Data()] = constis;
       DEBUG("Inserting "<<cname<<" :"<<constis.size()<<"\n");
       constis.clear();
    }
    }// end of loop over jets
    DEBUG("Jets:"<<i<<std::endl);



//------------------------------------------------------
// FAT jets

    // Loop over all jets in event
    if (branchFJet != NULL)
    for(i = 0; i < branchFJet->GetEntriesFast(); ++i) { 
      fjet = (FatJet*) branchFJet->At(i);
      alv.SetPtEtaPhiM( fjet->PT, fjet->Eta, fjet->Phi, fjet->Mass ); // all in GeV
//      cout<<"This Jet pt: "<<fjet->PT<<", eta: "<<fjet->Eta<<", phi: "<<fjet->Phi <<" Q:"<<fjet->Charge<<endl;
      ljets.emplace_back(alv);
      ljets.back().setCharge(fjet->Charge);
      ljets.back().setParticleIndx(i);
      ljets.back().setFlavor(fjet->Flavor);
      ljets.back().set_isbtagged_77(  (bool)fjet->BTag ); //  btag
      ljets.back().set_isTautagged( (bool)fjet->TauTag); // tau tag
// Loop over all jet's constituents
      for(j = 0; j < fjet->Particles.GetEntriesFast(); ++j) {
       object = fjet->Particles.At(j);
// Check if the constituent is accessible
       if(object == 0) continue;
       if(object->IsA() == GenParticle::Class()) {
        particle = (GenParticle*) object;
//        cout << "    GenPart pt: " << particle->PT << ", eta: " << particle->Eta << ", M: " << particle->Mass << endl;
        alv.SetPtEtaPhiM( particle->PT, particle->Eta, particle->Phi, particle->Mass ); 
        constis.emplace_back(alv);
        constis.back().setCharge( particle->Charge );
        constis.back().setPdgID(  particle->PID );
        constis.back().setParticleIndx(j);
        constis.back().addAttribute( particle->DZ);  //0
        constis.back().addAttribute( particle->D0);  
        constis.back().addAttribute( 0     ); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
        constis.back().addAttribute( particle->Status ); //3
        constis.back().addAttribute( particle->Z ); //4
        constis.back().addAttribute( particle->Y ); //5
        constis.back().addAttribute( particle->X ); //6
        constis.back().addAttribute( particle->T ); //7
       }
      }// end of loop over jets constits.
    if (constis.size() > 0){
      TString cname ="FJET_";
              cname+=i;    // jet index
              cname+="c"; //  c for constituents
       constits_map[cname.Data()] = constis;
       DEBUG("Inserting "<<cname<<" :"<<constis.size()<<"\n");
       constis.clear();
    }
    }// end of loop over fjets
    DEBUG("FatJets:"<<i<<std::endl);





//-----------------------------
//GEN LEVEL particles
        if (branchParticle != NULL)
        for(i = 0; i < branchParticle->GetEntriesFast(); ++i) { 
                particle = (GenParticle*) branchParticle->At(i);
                alv.SetPtEtaPhiM( particle->PT, particle->Eta, particle->Phi, particle->Mass ); // all in GeV
 //       if (abs( particle->PID)==15)
//	cout<< i << "    GenPart pt: " << particle->PT << ", status: " << particle->Status << ", M: " << particle->Mass << endl;
                truth.emplace_back(alv);
                truth.back().setCharge( particle->Charge );
                truth.back().setPdgID(  particle->PID );
                truth.back().setParticleIndx(i);
                truth.back().addAttribute( particle->DZ);   // 0
                truth.back().addAttribute( particle->D0);  // 1 
                truth.back().addAttribute( 0     ); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
                truth.back().addAttribute( particle->Status ); // 3
                truth.back().addAttribute( particle->Z );  //4
                truth.back().addAttribute( particle->Y );  //5
                truth.back().addAttribute( particle->X );  //6
                truth.back().addAttribute( particle->T );  //7
                truth.back().addAttribute( particle->D1 );  //8
                truth.back().addAttribute( particle->D2 );  //9

		int d1 = particle->D1;
		int d2 = particle->D2;
		double highestPT = -99;
		double leadingX = 0;
	        double leadingY = 0;
		if (d1 >= 0 && d2 >= 0 && d1 <= d2 && d2 < branchParticle->GetEntriesFast()) {
			for (int ik = d1; ik <= d2; ik++) {
				GenParticle *daughter = (GenParticle*) branchParticle->At(ik);
				if (daughter->PT > highestPT) {
					highestPT = daughter->PT;
					leadingX = daughter->X;
					leadingY = daughter->Y;
				}
			}
		}
		truth.back().addAttribute(leadingX); //10
		truth.back().addAttribute(leadingY); //11

//
/*
              unsigned int nkids=particle->D2-particle->D1 +1;
               // if (abs( particle->PID ) >=  9000000 && nkids>1 && particle->Status > 60 )
                if (abs( particle->PID ) == 15  )
             {
             cout << "Gen:"<<i<<" Status:"<< particle->Status << " pdgID:"<< particle->PID
                  <<" has "<<nkids<<" kids." << " from:"<<particle->D1<<" to:"<<particle->D2<< "\t"; 
             cout <<" M:"<<particle->Mass<<"\n";

             for (int ik=particle->D1; ik<=particle->D2; ik++) {
               GenParticle *apart = (GenParticle*) branchParticle->At(ik);
               cout << "\t\t"<< ik<<"  Status:"<< apart->Status << " pdgID:"<< apart->PID<<"\n";
               }
//             cout <<"vtx:"<<particle->X <<" y:"<<particle->Y<<"\n";
             }
*/
        }
    DEBUG("GENs:"<<i<<std::endl);

//MET
        metd = (MissingET*) branchMET->At(0);
        met.SetMagPhi( metd->MET,  metd->Phi);
        DEBUG("MET OK"<<std::endl);


//------------ auxiliary information -------
        anevt.run_no=RunNumber;
        anevt.lumiblk_no=1;
        anevt.user_evt_weight=1;
        anevt.top_hfor_type=0;
//        anevt.event_no=Event_Number[0];
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
        anevt.core_Flags=0;
	anevt.maxEvents=nentries;

        DEBUG("Filling finished evt:"<<j<<std::endl);
       muos_map["MUO"].swap(muons);
       eles_map["ELE"].swap(electrons);
       taus_map["TAU"].swap(taus);
       gams_map["PHO"].swap(photons);
       jets_map["JET"].swap(jets);
       ljets_map["FJET"].swap(ljets);
       truth_map["Truth"].swap(truth);
       track_map["Track"].swap(tracks);
       combo_map["Combo"].swap(combos);
       if (constits_map.size() < 1) constits_map["Constits"].swap(constis);
       met_map["MET"] = met;
        a0.muos=muos_map;
        a0.eles=eles_map;
        a0.taus=taus_map;
        a0.gams=gams_map;
        a0.jets=jets_map;
        a0.ljets=ljets_map;
        a0.truth=truth_map;
        a0.track=track_map;
        a0.combos=combo_map;
        a0.constits=constits_map;
        a0.met=met_map;
        a0.evt = anevt;


        aCtrl.RunTasks(a0); // leaks

  }// event loop ends.

  aCtrl.Finalize();

}
