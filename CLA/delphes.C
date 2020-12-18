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
   int prev_RunNumber=-1;

   map < string, int > syst_names;
        syst_names["01_jes"]       = 2;
   AnalysisController aCtrl(&aselect, syst_names);
   aCtrl.Initialize(extname);
   cout << "End of analysis initialization"<<endl;

   TClonesArray *branchParticle = UseBranch("Particle", fChain);
   TClonesArray *branchJet = UseBranch("Jet", fChain);
   TClonesArray *branchPhoton = UseBranch("Photon", fChain);
   TClonesArray *branchElectron = UseBranch("Electron", fChain);
   TClonesArray *branchMuon = UseBranch("Muon", fChain);
   TClonesArray *branchMET = UseBranch("MissingET", fChain);
//-----------------------------------------------------------min and max nb events
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nentinfile=nentries;
   cout << "number of entries " << nentries << endl;
   if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
   cout << "Forced number of entries " << nentries << endl;
   Long64_t startevent = 0;
   if (aselect.startpt>0 ) startevent=aselect.startpt;
   cout << "starting entry " << startevent << endl;
   Long64_t lastevent = startevent + nentries;
   if (lastevent > nentinfile ) { lastevent=nentinfile;
     cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
   }
//--------------------------------------------------------------generic variables
   GenParticle *particle;
   Jet *jet;
   Photon *photon;
   Electron *electron;
   Muon *muon;
   MissingET *metd;
   Int_t i, j;
   TObject *object;
   TLorentzVector momentum;
//--------------------------------------------------------------event loop
   for (Long64_t je=startevent; je<lastevent; ++je) {

       if ( fctrlc ) { cout << "Processed " << je << " events\n"; break; }
       if ( je%verboseFreq == 0 ) cout << "Processing event " << je << endl;
       DEBUG("Read Event"<<std::endl);
       int RunNumber=137;
/*
       if (int(RunNumber)!=prev_RunNumber) {
               cout << "Working on Run #:"<<RunNumber<<endl;
               prev_RunNumber=RunNumber;
       }
*/
 
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
       TLorentzVector  alv, alv_up, alv_down, slv;
       TLorentzVector  alv_msdown, alv_msup, alv_iddown, alv_idup, alv_ptsup,alv_ptsdown;
       TLorentzVector dummyTlv(0.,0.,0.,0.);
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       //dbxTau      *adbxt;
       dbxPhoton   *adbxp;
       dbxTruth    *adbxgen;

      DEBUG("Begin Filling"<<std::endl);
      if (branchMuon != NULL)
      for(i = 0; i < branchMuon->GetEntriesFast(); ++i) {
              muon= (Muon*) branchMuon->At(i);
              alv.SetPtEtaPhiM( muon->PT, muon->Eta, muon->Phi, (105.658/1E3) ); // all in GeV
              adbxm= new dbxMuon(alv);
              adbxm->setCharge(muon->Charge );
      	      adbxm->setPdgID(-13*muon->Charge );
              adbxm->setEtCone(muon->IsolationVarRhoCorr);
              adbxm->setPtCone(muon->IsolationVar       );
              adbxm->setParticleIndx(i);
              adbxm->addAttribute( muon->DZ);
              adbxm->addAttribute( muon->D0);
              adbxm->addAttribute( muon->IsolationVar   );
              muons.push_back(*adbxm);
              delete adbxm;
      }
      DEBUG("Muons OK:"<< std::endl);

//ELECTRONS
      if (branchElectron != NULL)
      for(i = 0; i < branchElectron->GetEntriesFast(); ++i) {
              electron= (Electron*) branchElectron->At(i);
              alv.SetPtEtaPhiM( electron->PT, electron->Eta, electron->Phi, (0.511/1E3) ); // all in GeV
              adbxe= new dbxElectron(alv);
              adbxe->setCharge(electron->Charge );
      	      adbxe->setPdgID(-11*electron->Charge );
              adbxe->setParticleIndx(i);
              adbxe->setClusterE(electron->EhadOverEem );
              adbxe->addAttribute( electron->DZ);
              adbxe->addAttribute( electron->D0     );
              adbxe->addAttribute( electron->IsolationVar     );
              electrons.push_back(*adbxe);
              delete adbxe;
      }
      DEBUG("Electrons OK:"<< i <<std::endl);
//PHOTONS
      if (branchPhoton != NULL)
      for(i = 0; i < branchPhoton->GetEntriesFast(); ++i) {
                photon= (Photon*) branchPhoton->At(i);
                alv.SetPtEtaPhiM( photon->PT, photon->Eta, photon->Phi, 0 ); // all in GeV
                adbxp= new dbxPhoton(alv);
                adbxp->setCharge(0);
                adbxp->setParticleIndx(i);
                adbxp->setClusterE(photon->EhadOverEem );
                photons.push_back(*adbxp);
                delete adbxp;
        }
        DEBUG("Photons OK:"<<i<<std::endl);

    // Loop over all jets in event
    if (branchJet != NULL)
    for(i = 0; i < branchJet->GetEntriesFast(); ++i) { 
      jet = (Jet*) branchJet->At(i);
      alv.SetPtEtaPhiM( jet->PT, jet->Eta, jet->Phi, jet->Mass ); // all in GeV
//      cout<<"This Jet pt: "<<jet->PT<<", eta: "<<jet->Eta<<", phi: "<<jet->Phi <<" T:"<<jet->T<<endl;
      adbxj= new dbxJet(alv);
      adbxj->setCharge(jet->Charge);
      adbxj->setParticleIndx(i);
      adbxj->setFlavor(jet->BTag);
      adbxj->set_isbtagged_77(  (bool)jet->BTag ); //  btag
      adbxj->set_isTautagged( (bool)jet->TauTag); // tau tag

// Loop over all jet's constituents
      for(j = 0; j < jet->Particles.GetEntriesFast(); ++j) {
       object = jet->Particles.At(j);
// Check if the constituent is accessible
       if(object == 0) continue;
       if(object->IsA() == GenParticle::Class()) {
        particle = (GenParticle*) object;
//        cout << "    GenPart pt: " << particle->PT << ", eta: " << particle->Eta << ", phi: " << particle->Phi << endl;
        alv.SetPtEtaPhiM( particle->PT, particle->Eta, particle->Phi, particle->Mass ); 
        adbxgen= new dbxTruth(alv);
        adbxgen->setCharge( particle->Charge );
        adbxgen->setPdgID(  particle->PID );
        adbxgen->setParticleIndx(j);
        adbxgen->addAttribute( particle->DZ);  //0
        adbxgen->addAttribute( particle->D0);  
        adbxgen->addAttribute( 0     ); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
        adbxgen->addAttribute( particle->Status ); //3
        adbxgen->addAttribute( particle->Z ); //4
        adbxgen->addAttribute( particle->Y ); //5
        adbxgen->addAttribute( particle->X ); //6
        adbxgen->addAttribute( particle->T ); //7
        constis.push_back(*adbxgen);
        delete adbxgen;
       }
      }// end of loop over jets constits.

    jets.push_back(*adbxj);
    delete adbxj;
    if (constis.size() > 0){
      TString cname ="JET_";
              cname+=i;    // jet index
              cname+="c"; //  c for constituents
       constits_map.insert( pair <string,vector<dbxParticle> > (cname.Data(), constis) );
       DEBUG("Inserting "<<cname<<" :"<<constis.size()<<"\n");
       constis.clear();
    }
    }// end of loop over jets
    DEBUG("Jets:"<<i<<std::endl);



//GEN LEVEL particles
        if (branchParticle != NULL)
        for(i = 0; i < branchParticle->GetEntriesFast(); ++i) { 
                particle = (GenParticle*) branchParticle->At(i);
                alv.SetPtEtaPhiM( particle->PT, particle->Eta, particle->Phi, particle->Mass ); // all in GeV
                adbxgen= new dbxTruth(alv);
                adbxgen->setCharge( particle->Charge );
                adbxgen->setPdgID(  particle->PID );
                adbxgen->setParticleIndx(i);
                adbxgen->addAttribute( particle->DZ);   // 0
                adbxgen->addAttribute( particle->D0);  // 1 
                adbxgen->addAttribute( 0     ); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
                adbxgen->addAttribute( particle->Status ); // 3
                adbxgen->addAttribute( particle->Z );  //4
                adbxgen->addAttribute( particle->Y );  //5
                adbxgen->addAttribute( particle->X );  //6
                adbxgen->addAttribute( particle->T );  //7
                adbxgen->addAttribute( particle->D1 );  //8
                adbxgen->addAttribute( particle->D2 );  //9
                unsigned int nkids=particle->D2-particle->D1 +1;
                truth.push_back(*adbxgen);
/*
                if (abs( particle->PID ) ==  1000021 && nkids>1 ){
                cout << "Gen:"<<i<<" Status:"<< particle->Status << " pdgID:"<< particle->PID
                     <<" has "<<nkids<<" kids." << " from:"<<particle->D1<<" to:"<<particle->D2<< "\n"; 
                cout <<"vtx:"<<particle->X <<" y:"<<particle->Y<<"\n";
                }
*/
                delete adbxgen;
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

        DEBUG("Filling finished"<<std::endl);
        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
       ljets_map.insert( pair <string,vector<dbxJet>      > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );
    if (constits_map.size() < 1) // we only add this if it was previously empty...
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map,  anevt};

        aCtrl.RunTasks(a0);

  }// event loop ends.

  aCtrl.Finalize();

}
