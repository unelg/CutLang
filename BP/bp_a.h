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
          cname=aname;
//       int r=dbxA::setDir(aname);  // make the relevant root directory
//       if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
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
      string cname;
      TString algoname;
      TString asysnam;
      std::string mysystematics;
      std::vector<TString> effCL;
      std::vector< string> binCL;

      unsigned short int TRGe, TRGm;
      unsigned int systematics_bci;
      bool skip_histos;
      bool skip_effs;
      bool systematicsRun;
      std::vector<int> save;
      unordered_set<int> optimize;
      static map<int, std::vector<myParticle *> > particleBank;

 
//relevant variables
        list<std::string> parts; //for def of particles as given by user
        map<std::string,Node*> NodeVars;//for variable defintion
        map<std::string,std::vector<myParticle*> > ListParts;//for particle definition
        map<std::string,pair<std::vector<float>,bool> > ListTables;//for table definition
        map<std::string, std::vector<cntHisto> > cntHistos;
        map<int, std::vector<std::string> > systmap;
        map<int,Node*> NodeCuts;//cuts and histos
        map<int,Node*> BinCuts;//binning
        map<int,string> BinNames;//binning
        map<std::string,Node*> ObjectCuts;//cuts for user defined objects
        std::vector<std::string> NameInitializations;
        std::vector<int> TRGValues;
        std::vector<double> bincounts;
};
#endif
