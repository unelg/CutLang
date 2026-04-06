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
#include "TTreeReader.h"
#include <unordered_map>

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

   map < string, string > syst_names;
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
       int mch;
       float mpx,mpy,mpz,mma, muE, jfv;

#ifdef __DEBUG__
std::cout << "Begin Filling"<<std::endl;
#endif


//MUONS
// E2 = p^2 + m^2
        muons_=10;
	for (int i=0; i<muons_; i++) {
                mpx=fChain->GetLeaf("muons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("muons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("muons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("muons.core.p4.mass")->GetValue(i);
                mch=fChain->GetLeaf("muons.core.charge")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
		muons.emplace_back(alv);
		muons.back().setCharge(mch );
                muons.back().setEtCone( -99 );
                muons.back().setPtCone( -99 );
		muons.back().setParticleIndx(i);
        }

#ifdef __DEBUG__
std::cout << "Muons OK:"<< muons_<<std::endl;
#endif

//ELECTRONS
        electrons_=10;
	for (int i=0; i<electrons_; i++) {
                mpx=fChain->GetLeaf("electrons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("electrons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("electrons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("electrons.core.p4.mass")->GetValue(i);
                mch=fChain->GetLeaf("electrons.core.charge")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
		electrons.emplace_back(alv);
		electrons.back().setCharge(mch);
		electrons.back().setParticleIndx(i);
                electrons.back().setClusterE( -99 );
        }

#ifdef __DEBUG__
std::cout << "Electrons OK:"<< electrons_ <<std::endl;
#endif
//PHOTONS
        photons_=100;
        for (int i=0; i<photons_; i++) {
                mpx=fChain->GetLeaf("photons.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("photons.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("photons.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("photons.core.p4.mass")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
        	photons.emplace_back(alv);
        	photons.back().setCharge(0);
        	photons.back().setParticleIndx(i);
                photons.back().setClusterE(-99 );
        }
#ifdef __DEBUG__
std::cout << "Photons OK:"<<photons_<<std::endl;
#endif

//JETS
        jets_=100;
	for (int i=0; i<jets_; i++) {
                mpx=fChain->GetLeaf("jets.core.p4.px")->GetValue(i);
                mpy=fChain->GetLeaf("jets.core.p4.py")->GetValue(i);
                mpz=fChain->GetLeaf("jets.core.p4.pz")->GetValue(i);
                mma=fChain->GetLeaf("jets.core.p4.mass")->GetValue(i);
                jfv=fChain->GetLeaf("jetsFlavor.tag")->GetValue(i);

                if (mpz == 0.0) break;

                muE=sqrt (mpx*mpx + mpy*mpy + mpz*mpz + mma*mma);
		alv.SetPxPyPzE( mpx, mpy, mpz,  muE); // all in GeV
  		jets.emplace_back(alv);
  		jets.back().setCharge(-99);
  		jets.back().setParticleIndx(i);
                jets.back().set_isbtagged_77( jfv==5); // I am not sure about this one, NGU
                jets.back().setFlavor( jfv); // I am not sure about this one, NGU
                jets.back().setJVtxf( -99 );
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

#ifdef __DEBUG__
std::cout << "An event finished"<<std::endl;
#endif

   } // end of event loop
          aCtrl.Finalize();

}
