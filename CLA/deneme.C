#include "fcc.h"
#include "lhco.h"
#include "atlasopen.h"
#include "atlasopenR2.h"
#include "cmsod.h"
#include "cmsod2.h"
#include "delphes.h"
#include "lvl0.h"
#include "VLLMin.h"
#include "CMSnanoAOD.h"
#include "AtlMin.h"
#include "AtlasTRT.h"
#include "VLLBG3.h"
#include "VLLg.h"
#include "VLLf.h"
#include "VLLMinSignal.h"
#include "DELPHES2.h"
#include "dbxParticle.h"
//#include "dbxAna.h"
#include <TH2.h>
#include <TError.h>
#include <TApplication.h>

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <unistd.h>

#include "SFuncNode.h"


//------------------------ TEST 
using namespace std;

int root_analysisd3pd(string sample, analy_struct aselect);

int main(int argc, char*argv[])
{

 for (int i=0; i<100; i++){ // event loop 100 evts
  cout << i<<"\n";
       vector<dbxMuon>     muons;
       vector<dbxElectron> electrons;
       vector<dbxTau>      taus;
       vector<dbxPhoton>   photons;
       vector<dbxJet>      jets;
       vector<dbxJet>    ljets;
       vector<dbxTruth>   truth;
       vector<dbxTrack>   track;
       vector<dbxParticle> combos;
       vector<dbxParticle> constis;
       evt_data anevt;
       TVector2 met;

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

  
  for (int j=0; j<10; j++){
     dbxJet      *adbxj;
     TLorentzVector  alv;
     alv.SetPtEtaPhiM( j*10, -j*2, j*1.2, j*100);
     adbxj= new dbxJet(alv);
     adbxj->setCharge(j);
     adbxj->setParticleIndx(i*j);
     adbxj->setFlavor(j);
     adbxj->addAttribute(0);
     adbxj->addAttribute(j);
     adbxj->addAttribute(i);

     jets.push_back(*adbxj);
     delete adbxj;
  }

         met.SetMagPhi( i*120,  i*13.3);

         anevt.run_no=i;
        anevt.lumiblk_no=1;


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
   AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map,track_map, combo_map, constits_map, met_map,  anevt};


  SFuncNode * aCut= new SFuncNode(userfuncA, fhemisphere, jet_t, "HEMISPHERE" , NULL);
  map<int,Node*> NodeCuts;
  NodeCuts.insert(make_pair(0,aCut));
  delete aCut;
  std::map<int, Node*>::iterator iter = NodeCuts.begin();

//  while(iter != NodeCuts.end()) {
//   iter->second->evaluate(&a0);
//   iter++;
//  }


 usleep (1000000);
}

}
