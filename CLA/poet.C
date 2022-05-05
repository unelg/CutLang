#define poet_cxx
#include "poet.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


// >>> "include" anchor >>>
#include <signal.h>
#include "dbx_electron.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "dbx_tau.h"
#include "dbx_truth.h"
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
// <<< "include" anchor <<<
   
void poet::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0, Long64_t nentries )
{

    // >>> GetPhysicsObjects >>>

    int retval=fChain->GetEntry(j);
    DEBUG( "Read:"<<retval<<"bytes\n");
    vector<dbxMuon>     muons; 
    vector<dbxElectron> electrons; 
    vector<dbxPhoton>   photons; 
    vector<dbxJet>      jets;
    vector<dbxTau>      taus;
    vector<dbxJet>     ljets;
    vector<dbxTruth>    truths;
    vector<dbxTrack>   track;
    vector<dbxParticle> combos;
    vector<dbxParticle> constits;

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
    
    evt_data anevt;
    
    //temporary variables
    TVector2 met;


    DEBUG("Begin filling\n");


    //temporary variables
    TLorentzVector  alv;
    //TLorentzVector dummyTlv(0.,0.,0.,0.);
    int Tcount=0;
    int Mcount=0;
    int Lcount=0;

    dbxMuon *adbxm;
    for (unsigned int i=0; i<muon_px->size(); i++) {
        alv.SetPxPyPzE(muon_px->at(i), muon_py->at(i), muon_pz->at(i),  muon_e->at(i)); // all in GeV
        adbxm = new dbxMuon(alv);
	adbxm->setCharge(muon_ch->at(i));
        adbxm->setPdgID(muon_ch->at(i)*(-13) );
        adbxm->setIsTight(muon_isTight->at(i));
/*
	adbxm->setd0(Muon_D0[i]);
        adbxm->setPdgID(-13*Muon_Charge[i] );
        adbxm->setEtCone(Muon_IsolationVarRhoCorr[i]);
        adbxm->setPtCone(Muon_IsolationVar[i]       );

	adbxm->addAttribute(Muon_DZ[i]);
	adbxm->addAttribute(Muon_D0[i]);
        adbxm->addAttribute(Muon_IsolationVar[i]     );
	adbxm->addAttribute(Muon_SumPtCharged[i]);
	adbxm->addAttribute(Muon_SumPtNeutral[i]);
	adbxm->addAttribute(Muon_SumPtChargedPU[i]);
	adbxm->addAttribute(Muon_SumPt[i]);
	adbxm->addAttribute(Muon_ErrorD0[i]);
	adbxm->addAttribute(Muon_ErrorDZ[i]);
*/
        adbxm->setParticleIndx(i);
        muons.push_back(*adbxm);
        delete adbxm;
    }
    DEBUG("MUON OK\n");

   dbxElectron *adbxe;
    for (unsigned int i=0; i<electron_px->size(); i++) {
        alv.SetPxPyPzE(electron_px->at(i), electron_py->at(i), electron_pz->at(i),  electron_e->at(i)); // all in GeV
        adbxe = new dbxElectron(alv);
        adbxe->setCharge(electron_ch->at(i));
        adbxe->setParticleIndx(i);
        adbxe->setPdgID( electron_ch->at(i)*(-11) );
        adbxe->setIsTight(electron_isTight->at(i));
        adbxe->setIsMedium(electron_isMedium->at(i));
        adbxe->setIsLoose(electron_isLoose->at(i));
        electrons.push_back(*adbxe);
        delete adbxe;
    }
    DEBUG("ELECTRON OK\n");

   dbxTau *adbxt;
    for (unsigned int i=0; i<tau_px->size(); i++) {
        alv.SetPxPyPzE(tau_px->at(i), tau_py->at(i), tau_pz->at(i),  tau_e->at(i)); // all in GeV
        adbxt = new dbxTau(alv);
        adbxt->setCharge(tau_ch->at(i));
        adbxt->setParticleIndx(i);
        taus.push_back(*adbxt);
        delete adbxt;
    }
    DEBUG("TAU OK\n");

   dbxPhoton *adbxp;
    for (unsigned int i=0; i<photon_px->size(); i++) {
        alv.SetPxPyPzE(photon_px->at(i), photon_py->at(i), photon_pz->at(i),  photon_e->at(i)); // all in GeV
        adbxp = new dbxPhoton(alv);
        adbxp->setCharge(0);
        adbxp->setParticleIndx(i);
        photons.push_back(*adbxp);
        delete adbxp;
    }
    DEBUG("Photon OK\n");

   dbxJet *adbxj;
    for (unsigned int i=0; i<jet_px->size(); i++) {
        alv.SetPxPyPzE(jet_px->at(i), jet_py->at(i), jet_pz->at(i),  jet_e->at(i)); // all in GeV
        adbxj = new dbxJet(alv);
        adbxj->setCharge(jet_ch->at(i));
        adbxj->setParticleIndx(i);
        jets.push_back(*adbxj);
        delete adbxj;
    }
    DEBUG("TAU OK\n");
                        
        
// FILLED CONTENT END

//------------ auxiliary information -------
anevt.run_no=128;
anevt.user_evt_weight=1.0;
anevt.lumiblk_no=1;
anevt.top_hfor_type=0;
anevt.event_no=1;
anevt.TRG_e= 0;
anevt.TRG_m= 0;
anevt.TRG_j= 0;
anevt.vxp_maxtrk_no= 9;
anevt.badjet=0;
anevt.mcevt_weight=0;
anevt.pileup_weight=1.0;
anevt.z_vtx_weight = 1.0;
anevt.weight_bTagSF_77 = 1.0;
anevt.weight_leptonSF = 1.0;
anevt.vxpType=0;
anevt.lar_Error=0;
anevt.core_Flags=0;
anevt.maxEvents=nentries;
    

    DEBUG("Filling finished\n");
    
    muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
    eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
    taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
    gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
    jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
    ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
    truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truths) );
    track_map.insert( pair <string,vector<dbxTrack>    > ("Track",       track) );
    combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
    constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constits) );
    met_map.insert( pair <string,TVector2>             ("MET",           met) );

   *a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map,track_map, combo_map, constits_map, met_map, anevt};
    
    // <<< GetPhysicsObjects <<<

}

void poet::Loop(analy_struct aselect, char *extname)
{
    // Signal HANDLER
    signal (SIGINT, _fsig_handler); // signal handler has issues with CINT
    if (fChain == 0) {
        cout <<"Error opening the data file"<<endl; return;
    }
    int verboseFreq(aselect.verbfreq);

    map < string, int > syst_names;
    syst_names["01_jes"]       = 2;

    AnalysisController aCtrl(&aselect, syst_names);
    aCtrl.Initialize(extname);
    cout << "End of analysis initialization"<<endl;
    // <<< "if (fChain == 0) return" anchor <<<
    


    // >>> "Long64_t nentries" anchor >>>
    // Long64_t nentries =  fChain->GetEntriesFast();
    Long64_t nentries =  fChain->GetEntriesFast();

    if (aselect.maxEvents > 0 ) {
        nentries=aselect.maxEvents;
    }
    cout << "number of entries " << nentries << endl;
    Long64_t startevent = 0;
    if (aselect.startpt > 0 ) {
        startevent=aselect.startpt;
    }
    cout << "starting entry " << startevent << endl;
    Long64_t lastevent = startevent + nentries;
    if (lastevent > fChain->GetEntriesFast() ) {
        lastevent=fChain->GetEntriesFast();
        cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
    }
    cout << "last entry " << lastevent << endl;

   Long64_t nbytes = 0, nb = 0;

    for (Long64_t j=startevent; j<lastevent; ++j) {

        if ( fctrlc ) { cout << "Processed " << j << " events"; break; }
        if (0 > LoadTree (j)) break;
        if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

        AnalysisObjects a0;
        GetPhysicsObjects(j, &a0, nentries);
        aCtrl.RunTasks(a0);
    }// event loop ends.

    aCtrl.Finalize();
}
    
