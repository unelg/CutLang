#ifndef BP_A_H
#define BP_A_H

#include "dbx_a.h"
#include "ReadCard.h"
#include <iostream>
#include "analysis_core.h"


class BPdbxA : public dbxA {
  public: 
      BPdbxA(char *aname) : dbxA ( aname)
         {
         sprintf (cname,"%s",aname); // keep the current analysis name in the class variable
         int r=dbxA::setDir(cname);  // make the relevant root directory
         if (r)  std::cout <<"Root Directory Set Failure in:"<<cname<<std::endl;
         //grl_cut=false;
         }

      int initGRL();
      int readAnalysisParams();
      int plotVariables(int sel);
      int printEfficiencies();
      int bookAdditionalHistos();
      int makeAnalysis(vector<dbxMuon> muons, vector<dbxElectron> electrons, vector<dbxPhoton> photons,
                               vector<dbxJet> jets, TVector2 met, evt_data anevt); 
      int saveHistos() {
        int r = dbxA::saveHistos();
        return r;
      }

   private:
      bool grl_cut;
      char cname[CHMAX];

      TH1F *a_histos[99];
       int  b_histos[9];
      vector < vector < pair<int, std::vector<dbxCut*>  > > > histos_order;
      map <int, vector<std::pair<string,string> > > levelObjectMap;


      // Sezen's handmade histograms
      //TH1D* h_eff = new TH1D("h_eff", "efficiencies", 20, 0, 20);
      TH1D* mWHh1;
      TH1D* mWHh2;
      TH1D* mTopHh1;
      TH1D* mTopHh2;
      TH1D* WHbRh1;
      TH1D* WHbRh2;
      TH1D* xWHbRh1;
      TH1D* xWHbRh2;
      TH1D* Zlm;

      Double_t minwidthw, minwidthz, minptm, minmassmm, maxetam, mindrmm, maxetconem, minptj;
      Double_t maxetaj, maxmet ;
      Int_t chargeveto, minnjetsw;  
      int TRGe, TRGm;
 
//DBXcut relevant variables
        std::vector< std::vector<dbxCut*>     > mycutlist;
        std::vector< std::vector<std::string> > myopelist;
        dbxCutList                              BPcutlist;
        std::vector< pair< int , int >        > forbidthese;
  
        map < string, vector<string> > obj_names;
        map < string,  pair< vector< std::vector<dbxCut*> >, vector< vector<string> >  >  > obj_defs;


        std::vector<int> ret_i;
        std::vector<int> ret_t;
        vector <int>  found_type_vecs, found_idx_vecs, found_idx_origs;
 
};
#endif
