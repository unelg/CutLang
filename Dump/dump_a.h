#ifndef DUMP_A_H
#define DUMP_A_H

#include <map>
#include "dbx_a.h"
#include "ReadCard.h"
#include <iostream>
#include "analysis_core.h"
#include "myParticle.h"
#include "Node.h"

#include "DBXNtuple.h"
#include "TFile.h"
#include "TTree.h"



class DumpdbxA : public dbxA {
  public: 
      DumpdbxA(char *aname) : dbxA ( aname)
         {
         sprintf (cname,"%s",aname); // keep the current analysis name in the class variable
         int r=dbxA::setDir(cname);  // make the relevant root directory
         if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
         r=dbxA::defHistos(30);  // make the relevant root directory
         //grl_cut=false;
         }
      int getInputs();
      int Finalize();
      int initGRL();
      int readAnalysisParams();
      int printEfficiencies();
      int bookAdditionalHistos();
      int makeAnalysis(AnalysisObjects *ao);
      int makeAnalysis(AnalysisObjects *ao, map < int, TVector2 > met_syst_map, vector <double> uncs);

      int saveHistos() {
        Finalize();
        int r = dbxA::saveHistos();
	return r;
      }

   private:
      bool grl_cut;
      char cname[CHMAX];
      int TRGe, TRGm;

      TFile *ftsave;
      TTree *ttsave;
      DBXNtuple *ntsave;
      
};
#endif
