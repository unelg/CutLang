#define fcc_cxx
#include "fcc.h"
#include <TH2.h>
#include <TStyle.h>
#include <TLeaf.h>
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

// header and lines to handle ctrl+C gracefully
bool fctrlc(false);
void _fsig_handler (int) { fctrlc=true; printf("Sig. TERMINATE received!\n"); }

void fcc::Loop(analy_struct aselect, char *extname)
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
   if (aselect.maxEvents>0 ) nentries=aselect.maxEvents;
   cout << "number of entries " << nentries << endl;
   Long64_t startevent = 0;
   if (aselect.startpt>0 ) startevent=aselect.startpt;
   cout << aselect.startpt<< endl;
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
       int RunNumber=137;
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
       TLorentzVector  alv;
       TVector2 met;
       dbxJet      *adbxj;
       dbxElectron *adbxe;
       dbxMuon     *adbxm;
       dbxPhoton   *adbxp;
       int mch;
       float mpx,mpy,mpz,mma, muE, jfv;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif


//MUONS
// E2 = p^2 + m^2
        muons_=10;
	for (unsigned int i=0; i<muons_; i++) {
                mpx=fChain->GetLeaf("muons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("muons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("muons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("muons.core.p4.mass")->GetValue(i);
                mch=fChain->GetLeaf("muons.core.charge")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
		adbxm= new dbxMuon(alv);
		adbxm->setCharge(mch );
                adbxm->setEtCone( -99 );
                adbxm->setPtCone( -99 );
		adbxm->setParticleIndx(i);
	        muons.push_back(*adbxm);
                delete adbxm;
        }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< muons_<<std::endl;
#endif

//ELECTRONS
        electrons_=10;
	for (unsigned int i=0; i<electrons_; i++) {
                mpx=fChain->GetLeaf("electrons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("electrons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("electrons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("electrons.core.p4.mass")->GetValue(i);
                mch=fChain->GetLeaf("electrons.core.charge")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
		adbxe= new dbxElectron(alv);
		adbxe->setCharge(mch);
		adbxe->setParticleIndx(i);
                adbxe->setClusterE( -99 );
	        electrons.push_back(*adbxe);
                delete adbxe;
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< electrons_ <<std::endl;
#endif
//PHOTONS
        photons_=100;
        for (unsigned int i=0; i<photons_; i++) {
                mpx=fChain->GetLeaf("photons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("photons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("photons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("photons.core.p4.mass")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
        	adbxp= new dbxPhoton(alv);
        	adbxp->setCharge(0);
        	adbxp->setParticleIndx(i);
                adbxp->setClusterE(-99 );
                photons.push_back(*adbxp);
                delete adbxp;
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<photons_<<std::endl;
#endif

//JETS
        jets_=100;
	for (unsigned int i=0; i<jets_; i++) {
                mpx=fChain->GetLeaf("jets.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("jets.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("jets.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("jets.core.p4.mass")->GetValue(i);
                jfv=fChain->GetLeaf("jetsFlavor.tag")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
  		adbxj= new dbxJet(alv);
  		adbxj->setCharge(-99);
  		adbxj->setParticleIndx(i);
                adbxj->set_isbtagged_77( jfv==5); // I am not sure about this one, NGU
                adbxj->setFlavor( jfv); // I am not sure about this one, NGU
                adbxj->setJVtxf( -99 );
  	        jets.push_back(*adbxj);
//                adbxj->dump();
                delete adbxj;
        }
#ifdef __DEBUG__
std::cout << "Jets OK."<<std::endl;
#endif

//MET
        met.SetMagPhi(fChain->GetLeaf("met.magnitude")->GetValue(), fChain->GetLeaf("met.phi")->GetValue()   );
#ifdef __DEBUG__
std::cout << "MET OK"<<std::endl;
#endif

//------------ auxiliary information -------
	anevt.run_no=RunNumber;
        anevt.user_evt_weight=1;
	anevt.lumiblk_no=1;
	anevt.top_hfor_type=0;
	anevt.event_no=123;
	anevt.TRG_e= 1;
	anevt.TRG_m= 0;
	anevt.TRG_j= 0;
	anevt.vxp_maxtrk_no= 9;
	anevt.badjet=0;
	anevt.mcevt_weight=1.1;
	anevt.pileup_weight=1.1;
	anevt.z_vtx_weight = 1.1;
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
       ljets_map.insert( pair <string,vector<dbxJet>      > ("FJET",        ljets) );
       truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
       combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
         met_map.insert( pair <string,TVector2>             ("MET",           met) );

        AnalysisObjects a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map,constits_map, met_map,  anevt};

  	aCtrl.RunTasks(a0);

#ifdef __DEBUG__
std::cout << "An event finished"<<std::endl;
#endif

   } // end of event loop
          aCtrl.Finalize();

}
