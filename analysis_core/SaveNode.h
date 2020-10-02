//  
//  SaveNode.h
//  Created by Jinen Setpal on 18/2/20.
//

#ifndef SaveNode_h
#define SaveNode_h
#include "Node.h"
#include "TFile.h"
#include "TTree.h"
#include "DBXNtuple.h"

class SaveNode : public Node{
private:
	std::string name, fname;
	DBXNtuple *ntsave;
	TFile *ftsave;
	TTree *ttsave;
public:
	SaveNode(std::string s){
                symbol="save";
		name = s;
		left = NULL;
		right = NULL;
		ntsave = new DBXNtuple;
	       	fname = "lvl0_" + name + ".root";
	}
    virtual void getParticles(std::vector<myParticle *>* particles) override{}
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{}
    virtual void Reset() override{}
    virtual void createFile() override {
	    ftsave = new TFile (fname.c_str(),"RECREATE"); // il faut changer le nom du fichier
	    ttsave = new TTree ("nt_tree", "saving data on the grid");
    }
    virtual void saveFile() override {
            std::cout << "Closing file\n";
	    ftsave->Write();
	    ftsave->Close();
    }
    virtual double evaluate(AnalysisObjects* ao) override {
      ttsave->Branch("dbxAsave", ntsave);
      vector<dbxMuon>        muons = ao->muos.begin()->second;
      vector<dbxElectron> electrons= ao->eles.begin()->second;
      vector <dbxPhoton>    photons= ao->gams.begin()->second;
      vector<dbxJet>           jets= ao->jets.begin()->second;
      vector<dbxJet>          ljets= ao->ljets.begin()->second;
      vector<dbxTau>           taus= ao->taus.begin()->second;
      vector<dbxTruth>        truth= ao->truth.begin()->second;
      vector<dbxParticle>    combos= ao->combos.begin()->second;
      //-----------------------------------------

      TVector2 met = ao->met.begin()->second;
      evt_data anevt = ao->evt;
      //      here we save the DBXNTuple
      ntsave->Clean();
      ntsave->nEle=electrons.size();
      for ( int i=0; i<(int)electrons.size(); i++) {
	ntsave->nt_eles.push_back(electrons.at(i) );
      }
      ntsave->nMuo=muons.size();
      for ( int i=0; i<(int)muons.size(); i++) {
	ntsave->nt_muos.push_back(muons.at(i) );
      }
      ntsave->nJet=jets.size();
      for ( int i=0; i<(int)jets.size(); i++) {
	ntsave->nt_jets.push_back(jets.at(i) );
      }
      ntsave->nPhoton=photons.size();
      for ( int i=0; i<(int)photons.size(); i++) {
	ntsave->nt_photons.push_back(photons.at(i) );
      }
      ntsave->nLJet=ljets.size();
      for ( int i=0; i<(int)ljets.size(); i++) {
	ntsave->nt_ljets.push_back(ljets.at(i) );
      }
      ntsave->nTau=taus.size();
      for ( int i=0; i<(int)taus.size(); i++) {
	ntsave->nt_taus.push_back(taus.at(i) );
      }
      ntsave->nTruth=truth.size();
      for ( int i=0; i<(int)truth.size(); i++) {
	ntsave->nt_truth.push_back(truth.at(i) );
      }
      ntsave->nCombo=combos.size();
      for ( int i=0; i<(int)combos.size(); i++) {
	ntsave->nt_combos.push_back(combos.at(i) );
      }
      
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
      
      ttsave->Fill();
      return 1;
    }
    virtual ~SaveNode() {}
};

#endif // SaveNode_h
