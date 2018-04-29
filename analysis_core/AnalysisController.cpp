#include "AnalysisController.h"
#include "ReadCard.h"
#include <string>

//#define __DEBUG__
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
AnalysisController::AnalysisController( analy_struct *iselect,  std::map <string, int> systematics) 
{
	extra_analysis_count=1;

	// ----- how many do we run in parallel ----
	if (iselect->dosystematics) {
		for( map<string,int>::iterator it=systematics.begin(); it!=systematics.end(); ++it) {
			syst_names.insert(*it);
		}
	}
	aselect=*iselect;

	cout << " #systematic included:"<<syst_names.size() <<endl;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::Initialize(char *extname) {

	int analyindex=0;
        int k=0;
        int last_a=0;

/*
 *
 *  The BP analysis
 *
 */
	for (int i=0; i<aselect.BPcount; i++) {
		char tmp[32];
		sprintf (tmp,"BP_%i",i+1);
		dbxAnalyses.push_back( new BPdbxA(tmp) ); // BP analysis with name
	}
	cout << "End of BP initialization"<<endl;


/*
 *
 *  Dump analysis
 *
 */
	for (int i=0; i<aselect.Dumpcount; i++) {
		char tmp[32];
		sprintf (tmp,"Dump_%i",i+1);
		dbxAnalyses.push_back( new DumpdbxA(tmp) ); // Dump analysis with name
	}
	cout << "End of Dumper initialization"<<endl;


// common suff for all analyses
// ----------------------------
        for (k=0; k<dbxAnalyses.size(); k++) {
		dbxAnalyses[k]->initGRL();
		dbxAnalyses[k]->readAnalysisParams();
		dbxAnalyses[k]->bookAdditionalHistos();
//              std::cout << " => " << k << " "<< dbxAnalyses[k]->getName() <<endl;
        }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::RunTasks( AnalysisObjects a0,  map <string,   AnalysisObjects> analysis_objs_map){

   int evret=0;
   std::string delimiter = "_";
   std::string sysnam="";
   for (int k=0; k<dbxAnalyses.size(); k++) 
   {
        bool aDumper=false; 
        int token_cnt=0;
        sysnam="";
        string ana=dbxAnalyses[k]->getName();
        size_t pos = 0;
        std::string token;
        while ((pos = ana.find(delimiter)) != std::string::npos) {
         token = ana.substr(0, pos);
         ana.erase(0, pos + delimiter.length());
         token_cnt++;
         if (token=="Dump") { aDumper=true; break;}
         if (token_cnt>1) { // systematics or QCD or WHF
           if ((ana.find("WHF") == std::string::npos) && (ana.find("qcd") == std::string::npos ) ){
            sysnam=ana;
            break;
           }
         }
        }
       
        if (sysnam.size()< 1){
             if (!aDumper){
#ifdef __DEBUG__
                cout << dbxAnalyses[k]->getName()<<" to be executed with defaults"<<endl;
#endif
	        evret=dbxAnalyses[k]->makeAnalysis(a0.muos, a0.eles, a0.gams, a0.jets, a0.met, a0.evt); // regular analysis
             } else {
#ifdef __DEBUG__
                cout << dbxAnalyses[k]->getName()<<" to be executed with Dumper specials"<<endl;
#endif
		std::map <int, TVector2> metsmap;
		int kmet=1;
		for ( std::map<string, AnalysisObjects>::iterator anit=analysis_objs_map.begin(); anit!=analysis_objs_map.end(); ++anit){
			AnalysisObjects these_objs= anit->second;
			TVector2        a_met     = these_objs.met ;
			metsmap.insert ( std::pair<int, TVector2> (kmet, a_met));
			kmet++;
		}
		evret=dbxAnalyses[k]->makeAnalysis(a0.muos, a0.eles, a0.gams, a0.jets, a0.met, a0.evt,metsmap, m_quad_unc);
             }
        } else {
             map<string, AnalysisObjects>::iterator il=analysis_objs_map.find(sysnam);
             if (il==analysis_objs_map.end()) {cout<<"Systematics name mismatch. "<<sysnam<<" not found, MAJOR error\n"; exit (888);};
#ifdef __DEBUG__
                cout << k<<" "<<dbxAnalyses[k]->getName()<<" also known as "<< il->first<<" to be executed with systematics"<<endl;
#endif
		AnalysisObjects these_objs=il->second;
		std::vector<dbxMuon> a_muons    = (these_objs.muos.size()>0) ? these_objs.muos : a0.muos;
		std::vector<dbxElectron> a_eles = (these_objs.eles.size()>0) ? these_objs.eles : a0.eles;
		std::vector<dbxPhoton>   a_gams = (these_objs.gams.size()>0) ? these_objs.gams : a0.gams;
		std::vector<dbxJet> a_jets      = (these_objs.jets.size()>0) ? these_objs.jets : a0.jets;
		TVector2 a_met      = (these_objs.met.Mod()>0  ) ? these_objs.met  : a0.met ;
		evt_data a_evt      = these_objs.evt;
		evret=dbxAnalyses[k]->makeAnalysis(a_muons, a_eles, a_gams, a_jets, a_met, a_evt); // generic
#ifdef __DEBUG__
                  cout<<"retval=:"<<evret<<endl;
#endif
        }
   }

#ifdef __DEBUG__
	std::cout << "An Event finished." <<std::endl;
#endif
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::SetJetUncs(vector <double> uncs){
	m_quad_unc.clear();
	for (unsigned int u=0; u<uncs.size(); u++) m_quad_unc.push_back( uncs.at(u) );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::Finalize(){
	for ( int i=0; i<dbxAnalyses.size(); i++)
	{
		cout <<"Efficiencies for analysis : "<< dbxAnalyses[i]->cname <<endl;
		dbxAnalyses[i]->printEfficiencies();
		dbxAnalyses[i]->saveHistos();
	}

}

