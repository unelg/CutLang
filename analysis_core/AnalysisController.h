#ifndef _AnalysisController_h
#define _AnalysisController_h

#include <vector>
#include <unordered_set>
#include <map>
#include <string>
#include "dbx_electron.h"
#include "dbx_photon.h"
#include "dbx_muon.h"
#include "dbx_jet.h"

// analysis related headers
#include "DBXNtuple.h"
#include "../BP/bp_a.h"
#include "../Dump/dump_a.h"
#include "analysis_core.h"

class AnalysisController {
 public : 
    AnalysisController ( analy_struct *,  std::map <std::string, string> syst_names ) ;
    AnalysisController ( analy_struct *as ) { AnalysisController(as, snull); }
   ~AnalysisController ( ) {};
    void Initialize ( char*);
    void SetJetUncs( vector<double> );
    void RunTasks (AnalysisObjects,  std::map <std::string, AnalysisObjects>);
    void RunTasks (AnalysisObjects aos) {RunTasks (aos, anull); }
    void Finalize();
    void MakePlots();

 private:
                    analy_struct  aselect;
                  vector<double>  m_quad_unc;
   std::map <std::string,string>  syst_names;
                             int  extra_analysis_count;
              std::vector<dbxA*>  dbxAnalyses;
              std::vector<dbxA*>  todos;
       std::map <string, string>  snull;
              std::map <std::string, AnalysisObjects> anull;
         std::unordered_set<int>  mainAnalyses;
         std::unordered_set<int>  depAnalyses;
                            bool  do_deps;
                            bool  do_RS;
};

#endif
