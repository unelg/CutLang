#ifndef BP_A_H
#define BP_A_H

#include "dbx_a.h"
#include "ReadCard.h"
#include <iostream>
#include "analysis_core.h"
#include "myParticle.h"
#include "Node.h"
#include <list>
#include "DBXNtuple.h"
#include "TFile.h"
#include "TTree.h"


class BPdbxA : public dbxA {
  public: 
      BPdbxA(char *aname) : dbxA ( aname)
         {
         sprintf (cname,"%s",aname); // keep the current analysis name in the class variable
//       int r=dbxA::setDir(cname);  // make the relevant root directory
//       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
         //grl_cut=false;
         }

      int getInputs(std::string);
      int initGRL();
      int readAnalysisParams();
      int plotVariables(int sel);
      int printEfficiencies();
      int bookAdditionalHistos();
      int makeAnalysis(AnalysisObjects *ao, int controlword, int preResults );
      int Finalize();
      int saveHistos() {
        int r = dbxA::saveHistos();
        std::map<int, Node*>::iterator jter = NodeCuts.begin();
        for (std::vector<int>::iterator it = save.begin() ; it != save.end(); ++it) {
             int diff = *it - jter->first;
             for(int i = 0; i < diff; i++) jter++;
             jter->second->saveFile();
        }
        return r;
      }
      
   private:
      bool grl_cut;
      char cname[CHMAX];
      char algoname[CHMAX];
      std::vector<TString> effCL;
      std::vector< string> binCL;

      int TRGe, TRGm;
      bool skip_histos;
      bool skip_effs;
      vector<int> save;
      unordered_set<int> optimize;
      static map<int, vector<myParticle *> > particleBank;

 
//relevant variables
        list<string> parts; //for def of particles as given by user
        map<string,Node*> NodeVars;//for variable defintion
        map<string,vector<myParticle*> > ListParts;//for particle definition
        map<string,pair<vector<float>,bool> > ListTables;//for table definition
        map<string, vector<cntHisto> > cntHistos;
        map<int,Node*> NodeCuts;//cuts and histos
        map<int,Node*> BinCuts;//binning
        map<string,Node*> ObjectCuts;//cuts for user defined objects
        std::vector<std::string> NameInitializations;
        vector<double> TRGValues;
        vector<double> bincounts;
};
#endif
