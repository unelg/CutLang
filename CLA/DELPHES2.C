//////////////////////////////////////////////////////////
// This file has been automatically generated on
// 2022-03-31_12-18-47 by CutLang
// from TTree Delphes/Analysis tree
// found on file: /Users/ngu/Dropbox/cutlang/inputformats/UPSGDelphes.root
//////////////////////////////////////////////////////////
#define DELPHES2_cxx
#include "DELPHES2.h"
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
#include "TTreeReader.h"

//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

extern void _fsig_handler (int) ;
extern bool fctrlc;
extern map<string, TTreeReader*> ttr_map;

// <<< "include" anchor <<<
   
void DELPHES2::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0, Long64_t nentries )
{

    // >>> GetPhysicsObjects >>>

    fChain->GetEntry(j);
    vector<dbxMuon>         muons; 
    vector<dbxElectron> electrons; 
    vector<dbxPhoton>     photons; 
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


    DEBUG("Begin filling\n")

//////////////////////////////////////////////////////////
// This content for filled has been automatically generated on
// 2022-03-31_12-18-47 by CutLang
// from TTree Delphes/Analysis tree
// found on file: /Users/ngu/Dropbox/cutlang/inputformats/UPSGDelphes.root
//////////////////////////////////////////////////////////

    //temporary variables
    TLorentzVector  alv;
    //TLorentzVector dummyTlv(0.,0.,0.,0.);
    int Tcount=0;
    int Mcount=0;
    int Lcount=0;

    // >>> MUON >>>

    dbxMuon *adbxm;
    for (int i=0; i<Muon_size; i++) {
        alv.SetPtEtaPhiM(Muon_PT[i], Muon_Eta[i], Muon_Phi[i],  (105.658/1E3)); // all in GeV

        adbxm = new dbxMuon(alv);
	adbxm->setd0(Muon_D0[i]);
	adbxm->setCharge(Muon_Charge[i]);
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
//	adbxm->addAttribute(Muon_T[i]); // time of flight

    for (int j=0; j<MuonTight_size && Tcount<MuonTight_size; j++) {
        cout << "M T:"<<MuonTight_T[j]<< " "<<j <<endl;
        if (Muon_T[i] == MuonTight_T[j] ) { 
           cout << "tight set\n";
           adbxm->setIsTight (true);
           Tcount++;
        }
    }
    for (int j=0; j<MuonMedium_size && Mcount<MuonMedium_size; j++) {
        cout << "M M:"<<MuonMedium_T[j]<< " "<<j <<endl;
        if (Muon_T[i] == MuonMedium_T[j] ) { 
           cout << "Medium set\n";
           adbxm->setIsMedium (true);
           Mcount++;
        }
    }
    for (int j=0; j<MuonLoose_size && Lcount<MuonLoose_size; j++) {
        cout << "M L:"<<MuonLoose_T[j]<< " "<<j <<endl;
        if (Muon_T[i] == MuonLoose_T[j] ) { 
           cout << "Loose set\n";
           adbxm->setIsLoose (true);
           Lcount++;
        }
    }
        adbxm->setParticleIndx(i);
        muons.push_back(*adbxm);
        delete adbxm;
    }

    DEBUG("MUON OK\n")

    // <<< MUON <<<
                        
    // >>> ELECTRON >>>

    dbxElectron *adbxe;
    Tcount=0;
    Mcount=0;
    Lcount=0;
    for (int i=0; i<Electron_size; i++) {
        alv.SetPtEtaPhiM(Electron_PT[i], Electron_Eta[i], Electron_Phi[i],  (0.511/1E3) ); // all in GeV
        adbxe = new dbxElectron(alv);
	adbxe->setCharge(Electron_Charge[i]);
        adbxe->setPdgID(-11*Electron_Charge[i] );
	adbxe->setClusterE(Electron_EhadOverEem[i]);

        cout << "E N:"<<Electron_T[i]<< " "<< i <<endl;

	adbxe->addAttribute(Electron_DZ[i]);
	adbxe->addAttribute(Electron_D0[i]);
	adbxe->addAttribute(Electron_IsolationVar[i]);
		adbxe->addAttribute(Electron_IsolationVarRhoCorr[i]);
		adbxe->addAttribute(Electron_SumPtCharged[i]);
		adbxe->addAttribute(Electron_SumPtNeutral[i]);
		adbxe->addAttribute(Electron_SumPtChargedPU[i]);
		adbxe->addAttribute(Electron_SumPt[i]);
		adbxe->addAttribute(Electron_ErrorD0[i]);
		adbxe->addAttribute(Electron_ErrorDZ[i]);
//		adbxe->addAttribute(Electron_T[i]);
		
    for (int j=0; j<ElectronTight_size && Tcount<ElectronTight_size; j++) {
        cout << "E T:"<<ElectronTight_T[j]<< " "<<j <<endl;
        if (Electron_T[i] == ElectronTight_T[j] ) { 
           cout << "tight set\n";
           adbxe->setIsTight (true);
           Tcount++;
        }
    }
    for (int j=0; j<ElectronMedium_size && Mcount<ElectronMedium_size; j++) {
        cout << "E M:"<<ElectronMedium_T[j]<< " "<<j <<endl;
        if (Electron_T[i] == ElectronMedium_T[j] ) { 
           cout << "Medium set\n";
           adbxe->setIsMedium (true);
           Mcount++;
        }
    }
    for (int j=0; j<ElectronLoose_size && Lcount<ElectronLoose_size; j++) {
        cout << "E L:"<<ElectronLoose_T[j]<< " "<<j <<endl;
        if (Electron_T[i] == ElectronLoose_T[j] ) { 
           cout << "Loose set\n";
           adbxe->setIsLoose (true);
           Lcount++;
        }
    }


        adbxe->setParticleIndx(i);
        electrons.push_back(*adbxe);
        delete adbxe;
    }
    DEBUG("ELECTRON norm OK\n")

    // <<< ELECTRON <<<
                        
    // >>> PHOTON >>>

    dbxPhoton *adbxp;
    Tcount=0;
    Mcount=0;
    Lcount=0;
    for (int i=0; i<Photon_size; i++) {
        alv.SetPtEtaPhiE(Photon_PT[i], Photon_Eta[i], Photon_Phi[i], Photon_E[i]); // all in GeV

        adbxp = new dbxPhoton(alv);
        adbxp->setCharge(0);
	adbxp->setClusterE(Photon_EhadOverEem[i]);
		adbxp->addAttribute(0);
		adbxp->addAttribute(0);
		adbxp->addAttribute(Photon_IsolationVar[i]);
		adbxp->addAttribute(Photon_IsolationVarRhoCorr[i]);
		adbxp->addAttribute(Photon_SumPtCharged[i]);
		adbxp->addAttribute(Photon_SumPtNeutral[i]);
		adbxp->addAttribute(Photon_SumPtChargedPU[i]);
		adbxp->addAttribute(Photon_SumPt[i]);
		adbxp->addAttribute(Photon_Status[i]);
//		adbxp->addAttribute(Photon_T[i]);
    cout << "P N:"<<Photon_T[j]<< " "<<j <<endl;
		
    for (int j=0; j<PhotonTight_size && Tcount<PhotonTight_size; j++) {
        cout << "P T:"<<PhotonTight_T[j]<< " "<<j <<endl;
        if (Photon_T[i] == PhotonTight_T[j] ) { 
           cout << "tight set\n";
           adbxp->setIsTight (true);
           Tcount++;
        }
    }
    for (int j=0; j<PhotonMedium_size && Mcount<PhotonMedium_size; j++) {
        cout << "P M:"<<PhotonMedium_T[j]<< " "<<j <<endl;
        if (Photon_T[i] == PhotonMedium_T[j] ) { 
           cout << "Medium set\n";
           adbxp->setIsMedium (true);
           Mcount++;
        }
    }
    for (int j=0; j<PhotonLoose_size && Lcount<PhotonLoose_size; j++) {
        cout << "P L:"<<PhotonLoose_T[j]<< " "<<j <<endl;
        if (Photon_T[i] == PhotonLoose_T[j] ) { 
           cout << "Loose set\n";
           adbxp->setIsLoose (true);
           Lcount++;
        }
    }
        adbxp->setParticleIndx(i);
        photons.push_back(*adbxp);
        delete adbxp;
    }

    cout<<"PHOTON OK\n";
    DEBUG("PHOTON OK\n")

    // <<< PHOTON <<<
                        
    // >>> JET >>>

    Tcount=0;
    Mcount=0;
    Lcount=0;
    dbxJet *adbxj;
    for (int i=0; i<JetPUPPI_; i++) {
        alv.SetPtEtaPhiM(JetPUPPI_PT[i], JetPUPPI_Eta[i], JetPUPPI_Phi[i],  JetPUPPI_Mass[i]); // all in GeV
        adbxj = new dbxJet(alv);
        adbxj->setFlavor(JetPUPPI_Flavor[i]);
        adbxj->set_isbtagged_77(  (bool)JetPUPPI_BTag[i] ); //  btag
        adbxj->set_isTautagged( (bool)JetPUPPI_TauTag[i]); // tau tag
        adbxj->setParticleIndx(i);
//	adbxj->setClusterE(JetPUPPI_EhadOverEem[i]);
        adbxj->setCharge(JetPUPPI_Charge[i]); 
// constits need to be added 
    for (int j=0; j<JetPUPPITight_size && Tcount<JetPUPPITight_size; j++) {
        cout << "j T:"<<JetPUPPITight_T[j]<< " "<<j <<endl;
        if (JetPUPPI_T[i] == JetPUPPITight_T[j] ) { 
           cout << "tight set\n";
           adbxj->setIsTight (true);
           Tcount++;
        }
    }
/*
    for (unsigned int j=0; j<JetPUPPIMedium_size && Mcount<JetPUPPIMedium_size; j++) {
        cout << "j M:"<<JetPUPPIMedium_T[j]<< " "<<j <<endl;
        if (JetPUPPI_T[i] == JetPUPPIMedium_T[j] ) { 
           cout << "Medium set\n";
           adbxj->setIsMedium (true);
           Mcount++;
        }
    }
*/
    for (int j=0; j<JetPUPPILoose_size && Lcount<JetPUPPILoose_size; j++) {
        cout << "j L:"<<JetPUPPILoose_T[j]<< " "<<j <<endl;
        if (JetPUPPI_T[i] == JetPUPPILoose_T[j] ) { 
           cout << "Loose set\n";
           adbxj->setIsLoose (true);
           Lcount++;
        }
    }
        jets.push_back(*adbxj);
        delete adbxj;
    }

    DEBUG("JET OK\n")

    // <<< JET <<<
    
                    
    /*
    tau not found!!!
    // >>> TAU >>>

    dbxTau *adbxt;
    for (unsigned int i=0; i<nTAU_example; i++) {
        _alv_example.SetPtEtaPhiM(Muon_pt_example[i], Muon_eta_example[i], Muon_phi_example[i],  (105.658/1E3)_example); // all in GeV

        adbxt = new dbxTau(alv);

        adbxt_example->addAttribute(PARTICLE_dxy_example[i]);
        adbxt_example->setCharge(PARTICLE_charge_example[i]);

        adbxt->setParticleIndx(i);
        taus.push_back(*adbxt);
        delete adbxt;
    }

    DEBUG("TAU OK\n")

    // <<< TAU <<<
    tau not found!!!
    */
                    
    // >>> LJET >>>

    dbxJet *adbxlj;
    for (int i=0; i<JetPUPPIAK8_; i++) {
        alv.SetPtEtaPhiM(JetPUPPIAK8_PT[i], JetPUPPIAK8_Eta[i], JetPUPPIAK8_Phi[i],  JetPUPPIAK8_Mass[i]); // all in GeV
        adbxlj = new dbxJet(alv);
        adbxlj->setParticleIndx(i);
        adbxlj->setCharge(JetPUPPIAK8_Charge[i]);
        adbxlj->setFlavor(JetPUPPIAK8_Flavor[i]);
        adbxlj->set_isbtagged_77(  (bool)JetPUPPIAK8_BTag[i] ); //  btag
        adbxlj->set_isTautagged( (bool)JetPUPPIAK8_TauTag[i]); // tau tag
//	adbxlj->setClusterE(JetPUPPIAK8_EhadOverEem[i]);

        adbxlj->addAttribute( 0);   // 0
        adbxlj->addAttribute( 0);  // 1 
        adbxlj->addAttribute( 0); // this is dummy, as we dont have isolation variable for GEN particles(unlike e,m,photon)
        adbxlj->addAttribute( 0); // 3
        adbxlj->addAttribute( 0);  //4
        adbxlj->addAttribute( 0);  //5
        adbxlj->addAttribute( 0);  //6
        adbxlj->addAttribute( 0);  //7
        adbxlj->addAttribute( 1);  //8
        adbxlj->addAttribute( JetPUPPIAK8_NSubJetsPruned[i] );  //9

        ljets.push_back(*adbxlj);
        delete adbxlj;
    }

    DEBUG("LJET OK\n")

    // <<< LJET <<<
                    
    /*
    truth not found!!!
    // >>> TRUTH >>>

    dbxTruth *adbxgen;
    for (unsigned int i=0; i<nTRUTH_example; i++) {
        _alv_example.SetPtEtaPhiM(Muon_pt_example[i], Muon_eta_example[i], Muon_phi_example[i],  (105.658/1E3)_example); // all in GeV

        adbxgen = new dbxTruth(alv);

        adbxgen_example->addAttribute(PARTICLE_dxy_example[i]);
        adbxgen_example->setCharge(PARTICLE_charge_example[i]);

        adbxgen->setParticleIndx(i);
        truths.push_back(*adbxgen);
        delete adbxgen;
    }

    DEBUG("TRUTH OK\n")

    // <<< TRUTH <<<
    truth not found!!!
    */
                    
    
    // >>> MET >>>
    met.SetMagPhi(PuppiMissingET_MET[0],  PuppiMissingET_Phi[0]); //gev already
    // <<< MET <<<
        
// FILLED CONTENT END

//------------ auxiliary information -------
anevt.run_no=128;
anevt.user_evt_weight=Event_Weight[0];
anevt.lumiblk_no=1;
anevt.top_hfor_type=0;
anevt.event_no=Event_Number[0];
anevt.TRG_e= 0;
anevt.TRG_m= 0;
anevt.TRG_j= 0;
anevt.vxp_maxtrk_no= 9;
anevt.badjet=0;
anevt.mcevt_weight=Event_CrossSection[0];
anevt.pileup_weight=1.0;
anevt.z_vtx_weight = 1.0;
anevt.weight_bTagSF_77 = 1.0;
anevt.weight_leptonSF = 1.0;
anevt.vxpType=0;
anevt.lar_Error=0;
anevt.core_Flags=0;
anevt.maxEvents=nentries;
    

    DEBUG("Filling finished\n")
    
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

void DELPHES2::Loop(analy_struct aselect, char *extname)
{

    cout << "I am in DELPHES2.C " << endl;
    // Signal HANDLER
    signal (SIGINT, _fsig_handler); // signal handler has issues with CINT
    if (fChain == 0) {
        cout <<"Error opening the data file"<<endl; return;
    }
    int verboseFreq(aselect.verbfreq);

    map < string, string > syst_names;

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
    for (Long64_t j=startevent; j<lastevent; ++j) {

        if ( fctrlc ) { cout << "Processed " << j << " events"; break; }
        if (0 > LoadTree (j)) break;
        if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

        AnalysisObjects a0;
        GetPhysicsObjects(j, &a0, nentries);
        ttr_map["Delphes"]->SetEntry(j);
        aCtrl.RunTasks(a0);
    }// event loop ends.

    aCtrl.Finalize();
}
    
