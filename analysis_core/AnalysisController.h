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
    AnalysisController ( analy_struct *,  std::map <std::string, int> syst_names ) ;
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
     std::map <std::string, int>  syst_names;
                             int  extra_analysis_count;
              std::vector<dbxA*>  dbxAnalyses;
          std::map <string, int>  snull;
              std::map <std::string, AnalysisObjects> anull;
                             int  mainAnalysis;
         std::unordered_set<int>  depAnalyses;
                            bool  do_deps;
};

#endif
