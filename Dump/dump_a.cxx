#include "dump_a.h"
#include "TParameter.h"
#include <TRandom.h>
#include "DBXNtuple.h"
#include "TFile.h"

int DumpdbxA:: readAnalysisParams() {
  int retval=0;
  TString CardName=cname;
          CardName+="-card.txt";

// cout << "We are here:"<< system ("pwd; ls -l")<<endl;
// cout << "Reading analysis parameters from:" << CardName << endl ;


//  minptm= ReadCard(CardName,"minptm",15.);
  TRGe  = ReadCard(CardName,"TRGe",1);
  TRGm  = ReadCard(CardName,"TRGm",1);

  ///// PUT ANALYSIS PARAMETERS INTO .ROOT //////////////
	
//  TParameter<double> *minptm_tmp=new TParameter<double> ("minptm", minptm);
  TParameter<double> *TRGe_tmp=new TParameter<double> ("TRGe", TRGe);
  TParameter<double> *TRGm_tmp=new TParameter<double> ("TRGm", TRGm);
	
 // minptm_tmp->Write("maxetam");
  TRGe_tmp->Write("TRGe");
  TRGm_tmp->Write("TRGm");

  return retval;
}

int DumpdbxA:: printEfficiencies() {
    int retval=0;
    PrintEfficiencies(eff);
    return retval;
}

int DumpdbxA:: initGRL() {
  int retval=0;
  grl_cut=true;
  return retval;
}

int DumpdbxA:: bookAdditionalHistos() {
//additional histograms are defined here
  eff= new TH1D("eff","selection efficiencies",5,0.5,5.5);
  getInputs();

  return 0;
}

int DumpdbxA:: getInputs() {
        int retval=0;  
        ntsave = new DBXNtuple();
	ftsave = new TFile ("lvl0.root","RECREATE");
	ttsave = new TTree ("nt_tree", "saving data on the grid");
        ttsave->Branch("dbxAsave", ntsave);
        return retval;
}

/////////////////////////do not call this for this analysis//////////////////////
int DumpdbxA::makeAnalysis(AnalysisObjects *ao) {
    map < int, TVector2 > mymap;
    TVector2 a; 
    mymap[1]=a;      
    vector <double> b;
    return makeAnalysis(ao, mymap, b); 
}
/////////////////////////////Analysis for Dump/////////////////////////////////
int DumpdbxA::makeAnalysis(AnalysisObjects *ao, map < int, TVector2 > met_syst_map, vector <double> uncs ){
  vector<dbxMuon>        muons = ao->muos.begin()->second;
  vector<dbxElectron> electrons= ao->eles.begin()->second;
  vector <dbxPhoton>    photons= ao->gams.begin()->second;
  vector<dbxJet>           jets= ao->jets.begin()->second;
  vector<dbxJet>          ljets= ao->ljets.begin()->second;
  vector<dbxTau>           taus= ao->taus.begin()->second;
  vector<dbxTruth>        truth= ao->truth.begin()->second;
  vector<dbxParticle>    combos= ao->combos.begin()->second;
  TVector2 met = ao->met.begin()->second;
  evt_data anevt = ao->evt;

//      here we save the DBXNTuple
         ntsave->Clean();
         ntsave->nEle=electrons.size();
	 for ( int i=0; i<(int)electrons.size(); i++) {
 		ntsave->nt_eles.push_back(electrons.at(i) );
                TLorentzVector ele4p=electrons.at(i).lv();
//                std::cout<<"E Pt = " << ele4p.Pt() << " eta = " << ele4p.Eta() << " phi = " << ele4p.Phi() << std::endl;
         }
         ntsave->nMuo=muons.size();
	 for ( int i=0; i<(int)muons.size(); i++) {
		ntsave->nt_muos.push_back(muons.at(i) );
                TLorentzVector mu4p = muons.at(i).lv();
//                std::cout<<"M Pt = " << mu4p.Pt() << " eta = " << mu4p.Eta() << " phi = " << mu4p.Phi() << std::endl;
         }
         ntsave->nJet=jets.size();
	 for ( int i=0; i<(int)jets.size(); i++) {
		 ntsave->nt_jets.push_back(jets.at(i) );
                 TLorentzVector jet4p = jets.at(i).lv();
//                 std::cout<<"J Pt = " << jet4p.Pt() << " eta = " << jet4p.Eta() << " phi = " << jet4p.Phi() << std::endl;
         }
	 ntsave->nPhoton=photons.size();
	 for ( int i=0; i<(int)photons.size(); i++) {
 		ntsave->nt_photons.push_back(photons.at(i) );
                TLorentzVector photon4p=photons.at(i).lv();
         }
	 ntsave->nLJet=ljets.size();
	 for ( int i=0; i<(int)ljets.size(); i++) {
 		ntsave->nt_ljets.push_back(ljets.at(i) );
                TLorentzVector ljet4p=ljets.at(i).lv();
         }
	 ntsave->nTau=taus.size();
	 for ( int i=0; i<(int)taus.size(); i++) {
 		ntsave->nt_taus.push_back(taus.at(i) );
                TLorentzVector tau4p=taus.at(i).lv();
         }
	 ntsave->nTruth=truth.size();
	 for ( int i=0; i<(int)truth.size(); i++) {
 		ntsave->nt_truth.push_back(truth.at(i) );
                TLorentzVector truth4p=truth.at(i).lv();
         }
	 ntsave->nCombo=combos.size();
	 for ( int i=0; i<(int)combos.size(); i++) {
 		ntsave->nt_combos.push_back(combos.at(i) );
                TLorentzVector combo4p=combos.at(i).lv();
         }

	 for ( int i=0; i<(int)uncs.size(); i++) {
		 ntsave->nt_uncs.push_back(uncs.at(i) );
         }
for (map<int, TVector2>::iterator itm = met_syst_map.begin(); itm != met_syst_map.end(); itm++) {
   ntsave->nt_sys_met.push_back( (*itm).second );
//     cout << ((*itm).second).Mod() << "  " << ((*itm).second).Phi() << endl;
}
//     cout << "~~~~~~~~~~~~~~~~~~~~~ E:"<<TRGe <<"  M:"<<TRGm <<endl;


 ntsave->nt_met=met;
 ntsave->nt_evt=anevt;

 ntsave->nt_muos.resize    ( muons.size()             );
 ntsave->nt_eles.resize    ( electrons.size()         );
 ntsave->nt_taus.resize    ( taus.size()              );
 ntsave->nt_jets.resize    ( jets.size()              );
 ntsave->nt_ljets.resize   ( ljets.size()             );
 ntsave->nt_photons.resize ( photons.size()           );
 ntsave->nt_combos.resize  ( combos.size()            );
 ntsave->nt_truth.resize   ( truth.size()             );
 ntsave->nt_uncs.resize    ( uncs.size()              );

ttsave->Fill();

//cout <<"Fill finished.\n";
/////////////////////////////////////
//Cuts and additional analysis//////
/////////////////////////////////////

  int cur_cut=1;

  eff->GetXaxis()->SetBinLabel(cur_cut,"all");
  eff->Fill(cur_cut, anevt.mcevt_weight);
  cur_cut++;	


// force no GRL for MC events
  if ((TRGm>1) || (TRGe>1)) { grl_cut=false; }

// add the goodrunsList xml for this analysis
  eff->GetXaxis()->SetBinLabel(cur_cut,"GRL");
//if ( grl_cut) {
//       bool pass = isGoodRun(anevt.run_no,anevt.lumiblk_no);
//       if ( !pass ) return cur_cut;
//}
  eff->Fill(cur_cut, anevt.mcevt_weight);
  cur_cut++;


for (int k=cur_cut; k<=eff->GetNbinsX(); k++) eff->Fill(k,anevt.mcevt_weight);
  return 0;

//cout <<"finished.\n";
}
//~~~~~~~~~~~~~~~
int DumpdbxA:: Finalize() {
        ftsave->Write();      
        ftsave->Close();
        return 0;
}
