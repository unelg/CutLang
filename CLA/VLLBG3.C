#define VLLBG3_cxx
#include "VLLBG3.h"
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

void VLLBG3::GetPhysicsObjects( Long64_t j, AnalysisObjects *a0 )
{
    fChain->GetEntry(j);
    
    vector<dbxMuon>     muons;
    vector<dbxElectron> electrons;
    vector<dbxPhoton>   photons;
    vector<dbxJet>      jets;
    vector<dbxTau>      taus;
    vector<dbxJet>     ljets;
    vector<dbxTruth>    truth;
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

    evt_data anevt;
    int extra_analysis_count=1;
    int year=2015;
    int prev_RunNumber=-1;

    //temporary variables
    TLorentzVector  alv;
    TLorentzVector dummyTlv(0.,0.,0.,0.);
    TVector2 mets;
    dbxJet      *adbxj;
    dbxElectron *adbxe;
    dbxMuon     *adbxm;
    dbxPhoton   *adbxp;

    #ifdef __DEBUG__
        std::cout << "Begin Filling"<<std::endl;
    #endif
        /*
        // PHOTONS -------- // now tau info
        for (unsigned int i=0; i<tau_pt->size(); i++) {
            alv.SetPtEtaPhiE( tau_pt->at(i)*0.001, tau_eta->at(i), tau_phi->at(i), tau_m->at(i)*0.001 ); // all in GeV
            adbxp= new dbxPhoton(alv);
            adbxp->setCharge(tau_charge->at(i) );
            photons.push_back(*adbxp);
            delete adbxp;
        }
    #ifdef __DEBUG__
        std::cout << "Photons OK:"<< tau_pt->size()<<std::endl;
    #endif
        */
        //MUONS
        for (unsigned int i=0; i<mu_pt->size(); i++) {
            alv.SetPtEtaPhiM( mu_pt->at(i)*0.001, mu_eta->at(i), mu_phi->at(i), 0.1056583755 ); // all in GeV
            adbxm= new dbxMuon(alv);
            adbxm->setCharge(mu_charge->at(i) );
            //adbxm->setEtCone(mu_topoetcone20->at(i) ); we couldn't find et or pt cones.
            //adbxm->setPtCone(mu_ptvarcone30->at(i)  );
            adbxm->setParticleIndx(i);
            //adbxm->setisZCand(mu_isZCand->at(i) ); no such thing in vll analysis
            //adbxm->settrigMatch_HLT_mu26_ivarmedium(muon_TrigEff_SF_HLT_mu8noL1_RecoTight->at(i)); //we got the first one, this should be decided.
            //adbxm->settrigMatch_HLT_mu50(muon_TrigMCEff_HLT_mu8noL1_RecoTight->at(i)); //we got the second one, this should be decided
            //adbxm->settrigMatch_HLT_mu20_iloose_L1MU15(muon_TrigEff_SF_HLT_mu18_RecoTight->at(i)); // we got the the third one, this should be decided.

            muons.push_back(*adbxm);
            delete adbxm;
        }
    #ifdef __DEBUG__
        std::cout << "Muons OK:"<< mu_pt->size()<<std::endl;
    #endif

        //ELECTRONS
        for (unsigned int i=0; i<el_pt->size(); i++) {
            alv.SetPtEtaPhiM( el_pt->at(i)*0.001, el_eta->at(i), el_phi->at(i), 0.000511 ); // all in GeV
            //        std::cout << "ETA:"<<el_eta->at(i) <<std::endl;
            adbxe= new dbxElectron(alv);
            adbxe->setCharge(el_charge->at(i) );
            //        adbxe->setPtCone(el_ptvarcone20->at(i));// 30 has // this does not exist in vll analysis 20 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //        adbxe->setEtCone20(el_ptvarcone20->at(i) );
            //       adbxe->settrue_origin(el_true_origin->at(i));
            //        adbxe->settrue_type(el_true_type->at(i));
            adbxe->setParticleIndx(i);
            adbxe->setClusterEta(el_caloCluster_eta->at(i) );
            //        adbxe->setd0sig(el_trkd0sig->at(i) ); // BU IKISI YOK BULAMADIM MK NTUPLEINDA
            //        adbxe->setdelta_z0_sintheta(el_trkz0sintheta->at(i) );BU IKISI YOK BULAMADIM MK NTUPLEINDA
            //        adbxe->setisZCand(el_isZCand->at(i) );


            //adbxe->settrigMatch_HLT_e60_lhmedium_nod0(el_TrigEff_SF_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH_TightLLH->at(i)); // we got the first six ones, this should be decided in the future.
            //adbxe->settrigMatch_HLT_e26_lhtight_nod0_ivarloose(el_TrigMCEff_TRI_E_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH_TightLLH->at(i));
            //adbxe->settrigMatch_HLT_e140_lhloose_nod0(el_TrigEff_SF_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH_TightLLH->at(i));
            //adbxe->settrigMatch_HLT_e60_lhmedium(el_TrigMCEff_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH_TightLLH->at(i));
            //adbxe->settrigMatch_HLT_e24_lhmedium_L1EM20VH(el_TrigEff_SF_MULTI_L_2015_e12_lhloose_2016_e12_lhloose_nod0_2017_e12_lhloose_nod0_TightLLH->at(i));
            //adbxe->settrigMatch_HLT_e120_lhloose(el_TrigMCEff_MULTI_L_2015_e12_lhloose_2016_e12_lhloose_nod0_2017_e12_lhloose_nod0_TightLLH->at(i));

            electrons.push_back(*adbxe);
            delete adbxe;
        }

    #ifdef __DEBUG__
        std::cout << "Electrons OK:"<< el_pt->size() <<std::endl;
    #endif

        //JETS
        for (unsigned int i=0; i<jet_pt->size(); i++) {
            alv.SetPtEtaPhiM( jet_pt->at(i)*0.001, jet_eta->at(i), jet_phi->at(i), jet_m->at(i)*0.001 ); // all in GeV
            adbxj= new dbxJet(alv);
            adbxj->setCharge(-99);
            //      adbxj->setjvt(jet_JvtPass_Medium->at(i)); // this also should be decided in the future.
            adbxj->setParticleIndx(i);
            //      adbxj->setFlavor(jet_truthflav->at(i) );
            //adbxj->set_isbtagged_77(bool(jet_FTag_MV2c10_FixedCutBEff_77_NOSYS->at(i))); // Bora removed this
            //      adbxj->setmv2c00(jet_mv2c00->at(i));
            //      adbxj->setmv2c10(jet_mv2c10->at(i));
            //      adbxj->setmv2c20(jet_mv2c20->at(i));
            //      adbxj->setip3dsv1(jet_ip3dsv1->at(i));

            //               adbxj->set_isbtagged_77( jet_MV2c10mu[i] > 0.7892 ); //  is btag
            jets.push_back(*adbxj);
            delete adbxj;
        }
    #ifdef __DEBUG__
        std::cout << "Jets OK:"<< jet_pt->size() <<std::endl;
    #endif
       //MET
        // met.SetMagPhi( met*0.001,  met_phi); //mev-->gev //I am not sure about met. this should be checked.
         mets.SetMagPhi( met->at(5)*0.001,  met_phi->at(5)); //mev-->gev //I am not sure about met. this should be checked.
            // std::cout <<"met values: "<<met->at(i)<<endl;
        // std::cout <<"met size: "<<met->size()<<endl;
    #ifdef __DEBUG__
        std::cout << "MET OK"<<std::endl;
    #endif


        anevt.run_no=runNumber;
        anevt.user_evt_weight=1;
        anevt.event_no=eventNumber;
        anevt.lumiblk_no=1;
        anevt.top_hfor_type=0;
        anevt.TRG_e= 1;
        anevt.TRG_m= 0;
        anevt.TRG_j= 0;
        anevt.vxp_maxtrk_no= 1;
        anevt.badjet=0;
                
        //anevt.weight_mc=mcEventWeights
        //anevt.weight_mc=mcEventWeights->at(0);
        anevt.weight_mc=generatorWeight;
        //if (std::abs(generatorWeight)>100.0) {
        //  anevt.weight_mc=1;
        //  cout<<"MCEventWeight>100.0. It is set to 1"<<endl;
        //}
        //std::cout<< "EvtW: " << anevt.weight_mc<<std::endl;
        anevt.weight_pileup=pileupWeight;
        //std::cout<< "PileW: " << anevt.weight_pileup<<std::endl;
        anevt.correction_weight=correctionWeight;
        anevt.luminosity_weight=luminosityWeight;

        anevt.weight_jvt=1;
        //std::ifstream f("/home/boreas/DNEME/oku3.txt");
        //std::vector<float> dsid;
        //std::vector<float> xsec;
        //int index=0;
        //int index2=0;
        //if (f.is_open()){
        //  float tmpdsid;
        //  float tmpxsec;
        //  while(!f.eof()) // reads file to end of *file*, not line
        //      { 
        //         f >> tmpdsid; // read first column number
        //         f >> tmpxsec; // read second column 
        //         
        //         dsid.push_back(tmpdsid);
        //         xsec.push_back(tmpxsec);
        //      }
        //  f.close();
        //  //cout<<dsid.size()<<endl;
        //  //cout<<"DSID: "<<mcChannelNumber<<endl;
        //  std::vector<float>::iterator it = std::find(dsid.begin(), dsid.end(), mcChannelNumber*100);
        //  index = std::distance(dsid.begin(), it);
        //  if (index==dsid.size()){
        //    anevt.weight_xsec=1;
        //  }
        //  else { 
        //    std::vector<float>::iterator it = std::find(dsid.begin(), dsid.end(), mcChannelNumber);
        //    int index2 = std::distance(dsid.begin(), it);
        //    anevt.weight_xsec=xsec[index]/xsec[index2];
        //    cout<<"Xsecs and Ratio: "<< xsec[index] << " "<< xsec[index2]<< " "<<anevt.weight_xsec<<endl; 
        //  }
        //  
        //  //cout<<"Index: "<<index<<endl;
        //  //cout<<"Xsec: "<<xsec[index]<<endl;
        //}
        //else{cout<<"Failed to open"<<endl;}
        anevt.weight_xsec=1;
        //anevt.weight_xsec=xsec[index];
      //  anevt.weight_jvt=correctionWeight*luminosityWeight*xsec[index]; // didnt have jvt, others multiplied here for convenience
        //std::cout<< "CorrW: " << correctionWeight<<std::endl;
        //std::cout<< "LumW: " << luminosityWeight<<std::endl;
        //std::cout<<"Combined Weight for "<<j<<"th Event: " << anevt.weight_jvt*anevt.weight_pileup*anevt.weight_mc*anevt.weight_xsec*anevt.luminosity_weight*anevt.correction_weight<<endl;
        //std::cout<< "Xsec: " << xsec[index]<<std::endl;
        //std::cout<< "CorrW*LumW*Xsec: " << anevt.weight_jvt<<std::endl;
        //ofstream dumpfile;
        //dumpfile.open("/home/boreas/DNEME/cwdump.txt",ios::app);
        //dumpfile<<"Combined Weight for "<<j<<"th Event: " << anevt.weight_jvt*anevt.weight_pileup*anevt.weight_mc*anevt.weight_xsec*anevt.luminosity_weight*anevt.correction_weight<<endl;
        //dumpfile.close();
        //anevt.weight_leptonSF=actualMu; //this is completely wrong. electron and muon has different scale factors.
        /*anevt.weight_bTagSF_77=weight_bTagSF_MV2c10_77;
         anevt.weight_jvt=weight_jvt;

         anevt.weight_pileup_UP=weight_pileup_UP;
         anevt.weight_pileup_DOWN=weight_pileup_DOWN;
         anevt.weight_leptonSF_EL_SF_Trigger_UP=weight_leptonSF_EL_SF_Trigger_UP;
         anevt.weight_leptonSF_EL_SF_Trigger_DOWN=weight_leptonSF_EL_SF_Trigger_DOWN;
         anevt.weight_leptonSF_EL_SF_Reco_UP=weight_leptonSF_EL_SF_Reco_UP;
         anevt.weight_leptonSF_EL_SF_Reco_DOWN=weight_leptonSF_EL_SF_Reco_DOWN;
         anevt.weight_leptonSF_EL_SF_ID_UP=weight_leptonSF_EL_SF_ID_UP;
         anevt.weight_leptonSF_EL_SF_ID_DOWN=weight_leptonSF_EL_SF_ID_DOWN;
         anevt.weight_leptonSF_EL_SF_Isol_UP=weight_leptonSF_EL_SF_Isol_UP;
         anevt.weight_leptonSF_EL_SF_Isol_DOWN=weight_leptonSF_EL_SF_Isol_DOWN;
         anevt.weight_leptonSF_MU_SF_Trigger_STAT_UP=weight_leptonSF_MU_SF_Trigger_STAT_UP;
         anevt.weight_leptonSF_MU_SF_Trigger_STAT_DOWN=weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
         anevt.weight_leptonSF_MU_SF_Trigger_SYST_UP=weight_leptonSF_MU_SF_Trigger_SYST_UP;
         anevt.weight_leptonSF_MU_SF_Trigger_SYST_DOWN=weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
         anevt.weight_leptonSF_MU_SF_ID_STAT_UP=weight_leptonSF_MU_SF_ID_STAT_UP;
         anevt.weight_leptonSF_MU_SF_ID_STAT_DOWN=weight_leptonSF_MU_SF_ID_STAT_DOWN;
         anevt.weight_leptonSF_MU_SF_ID_SYST_UP=weight_leptonSF_MU_SF_ID_SYST_UP;
         anevt.weight_leptonSF_MU_SF_ID_SYST_DOWN=weight_leptonSF_MU_SF_ID_SYST_DOWN;
         anevt.weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP=weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
         anevt.weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN=weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
         anevt.weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP=weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
         anevt.weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN=weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
         anevt.weight_leptonSF_MU_SF_Isol_STAT_UP=weight_leptonSF_MU_SF_Isol_STAT_UP;
         anevt.weight_leptonSF_MU_SF_Isol_STAT_DOWN=weight_leptonSF_MU_SF_Isol_STAT_DOWN;
         anevt.weight_leptonSF_MU_SF_Isol_SYST_UP=weight_leptonSF_MU_SF_Isol_SYST_UP;
         anevt.weight_leptonSF_MU_SF_Isol_SYST_DOWN=weight_leptonSF_MU_SF_Isol_SYST_DOWN;
         anevt.weight_leptonSF_MU_SF_TTVA_STAT_UP=weight_leptonSF_MU_SF_TTVA_STAT_UP;
         anevt.weight_leptonSF_MU_SF_TTVA_STAT_DOWN=weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
         anevt.weight_leptonSF_MU_SF_TTVA_SYST_UP=weight_leptonSF_MU_SF_TTVA_SYST_UP;
         anevt.weight_leptonSF_MU_SF_TTVA_SYST_DOWN=weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
         anevt.weight_jvt_UP=weight_jvt_UP;
         anevt.weight_jvt_DOWN=weight_jvt_DOWN;
         anevt.weight_bTagSF_77_extrapolation_up=weight_bTagSF_MV2c10_77_extrapolation_up;
         anevt.weight_bTagSF_77_extrapolation_down=weight_bTagSF_MV2c10_77_extrapolation_down;
         anevt.weight_bTagSF_77_extrapolation_from_charm_up=weight_bTagSF_MV2c10_77_extrapolation_from_charm_up;
         anevt.weight_bTagSF_77_extrapolation_from_charm_down=weight_bTagSF_MV2c10_77_extrapolation_from_charm_down;
         //  anevt.mc_generator_weights=*mc_generator_weights;
         anevt.weight_bTagSF_77_eigenvars_B_up=*weight_bTagSF_MV2c10_77_eigenvars_B_up;
         anevt.weight_bTagSF_77_eigenvars_C_up=*weight_bTagSF_MV2c10_77_eigenvars_C_up;
         anevt.weight_bTagSF_77_eigenvars_Light_up=*weight_bTagSF_MV2c10_77_eigenvars_Light_up;
         anevt.weight_bTagSF_77_eigenvars_B_down=*weight_bTagSF_MV2c10_77_eigenvars_B_down;
         anevt.weight_bTagSF_77_eigenvars_C_down=*weight_bTagSF_MV2c10_77_eigenvars_C_down;
         anevt.weight_bTagSF_77_eigenvars_Light_down=*weight_bTagSF_MV2c10_77_eigenvars_Light_down;*/

    #ifdef __DEBUG__
        std::cout << "Filling finished"<<std::endl;
    #endif

        muos_map.insert( pair <string,vector<dbxMuon>     > ("MUO",         muons) );
        eles_map.insert( pair <string,vector<dbxElectron> > ("ELE",     electrons) );
        taus_map.insert( pair <string,vector<dbxTau>      > ("TAU",          taus) );
        gams_map.insert( pair <string,vector<dbxPhoton>   > ("PHO",       photons) );
        jets_map.insert( pair <string,vector<dbxJet>      > ("JET",          jets) );
        ljets_map.insert( pair <string,vector<dbxJet>     > ("FJET",        ljets) );
        truth_map.insert( pair <string,vector<dbxTruth>    > ("Truth",       truth) );
        combo_map.insert( pair <string,vector<dbxParticle> > ("Combo",      combos) );
        constits_map.insert( pair <string,vector<dbxParticle> > ("Constits",  constis) );
        met_map.insert( pair <string,TVector2>             ("MET",           mets) );

        *a0={muos_map, eles_map, taus_map, gams_map, jets_map, ljets_map, truth_map, combo_map, constits_map, met_map, anevt};
    }


void VLLBG3::Loop(analy_struct aselect, char *extname)
{
//   In a ROOT session, you can do:
//      root> .L VLLBG3.C
//      root> VLLBG3 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  cout << "I am in VLLBG3.C " << endl;
  if (fChain == 0) {
      cout <<"Error opening the data file"<<endl; return;
    }
  int verboseFreq(aselect.verbfreq);
    
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
  if (lastevent> fChain->GetEntriesFast() ){ lastevent=fChain->GetEntriesFast();
    cout << "Interval exceeds tree. Analysis is done on max available events starting from event : " << startevent << endl;
  }
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t j=startevent; j<lastevent; ++j) {

      //  if ( fctrlc ) { cout << "Processed " << j << " events\n"; break; }
      if (0 > LoadTree (j)) break;
      if ( j%verboseFreq == 0 ) cout << "Processing event " << j << endl;

      AnalysisObjects a0;
      GetPhysicsObjects(j, &a0);
      aCtrl.RunTasks(a0);

  }// event loop ends.
  aCtrl.Finalize();

 }
