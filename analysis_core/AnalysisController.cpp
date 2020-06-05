#include "AnalysisController.h"
#include "ReadCard.h"
#include <string>

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif
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

        do_deps=false;
	string prereqs=aselect.dependencies;
	if (prereqs.length()>2 ){
          do_deps=true;
	  size_t kol=prereqs.find_first_of(':',0);
	  if (kol == std::string::npos){ cerr<<"Wrong dependency list format. Use: m:i,j,k \n"; exit (14);}
	  mainAnalysis= atoi(prereqs.substr(0,kol).c_str());
	  cout<<"Indep region ID:"<<mainAnalysis<<"\n";
	  std::string depStr = prereqs.substr(kol+1, prereqs.length());
	  for (size_t i=0,n; i <= depStr.length(); i=n+1) {
	   n = depStr.find_first_of(',',i);
	   if (n == std::string::npos) n = depStr.length();
	     std::string tmp = depStr.substr(i,n-i);
	     cout <<"Dep region id:"<<atoi(tmp.c_str() )<<"\n";
             depAnalyses.insert(atoi(tmp.c_str()) );
	  }
	} 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::Initialize(char *extname) {

	int analyindex=0;
        int k=0;
        int last_a=0;

/*
 *  The BP analysis
 */
	for (int i=0; i<aselect.BPcount; i++) {
		char tmp[32];
		sprintf (tmp,"BP_%i",i+1);
		dbxAnalyses.push_back( new BPdbxA(tmp) ); // BP analysis with name
	}
	DEBUG("End of BP initialization\n");

/*
 *  Dump analysis
 */
	for (int i=0; i<aselect.Dumpcount; i++) {
		char tmp[32];
		sprintf (tmp,"Dump_%i",i+1);
		dbxAnalyses.push_back( new DumpdbxA(tmp) ); // Dump analysis with name
	}
	DEBUG("End of Dumper initialization\n");


// common suff for all analyses
// ----------------------------
        for (k=0; k<dbxAnalyses.size(); k++) {
		dbxAnalyses[k]->initGRL();
		dbxAnalyses[k]->readAnalysisParams();
                std::cout << " => " << k << " "<< dbxAnalyses[k]->getName() <<endl;
		dbxAnalyses[k]->bookAdditionalHistos();
        }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void AnalysisController::RunTasks( AnalysisObjects a0,  map <string,   AnalysisObjects> analysis_objs_map){
//-------------------------------------------------this is called for each event read from the ntuple file
   int evret=0; // return value of each analysis
   std::string delimiter = "_";
   std::string sysnam="";
   AnalysisObjects refA0=a0;
   int controlword=0; // no dependency, all cuts executed.
   int mainAresults;

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
/*
         if (token_cnt>1) { // systematics or QCD or WHF
           if ((ana.find("WHF") == std::string::npos) && (ana.find("qcd") == std::string::npos ) ){
            sysnam=ana;
            break;
           }
         }
*/
        }
       
        if (sysnam.size()< 1){ // not a systematics run condition
             if (!aDumper){ //not a dumper, i.e. BP run
//-----------------------------assume initial analysis returns this:
//2:     1,pass  0,fail
//5:     1,pass  1,pass  1,pass  1,pass  0,fail
//10005: 1,pass  1,pass  1,pass  1,pass  1,pass

//-------------at this point we should know if anAnalysis depends on Another.
                DEBUG(dbxAnalyses[k]->getName()<<" to be executed with defaults"<<endl);
                int lastpass=0;
               if(do_deps) {
                if ( depAnalyses.find(k) != depAnalyses.end() ){ // if this is analysis 1, we are dependent, get info from 0.
                   if (mainAresults < 10000) controlword=mainAresults; // means last cut fails.
                   else {
                      lastpass=1;
                      controlword=(mainAresults-10000);
                   }
                }
               } else {
                  a0.evt.user_evt_weight=refA0.evt.user_evt_weight;
               }
//----------------------------------------------
	        evret=dbxAnalyses[k]->makeAnalysis(&a0, controlword, lastpass);   //------------------------------ regular analysis
//----------------------------------------------
               if(do_deps) {
                   if (k==mainAnalysis) {
                    mainAresults=evret; // save the results from main;
                    DEBUG("Main at "<<k<<" has evret:"<<evret<<"\n");
                   }
                }
             } else {      // the below is a dumper
                DEBUG(dbxAnalyses[k]->getName()<<" to be executed with Dumper specials"<<endl);
		std::map <int, TVector2> metsmap;
		int kmet=1;
		for ( std::map<string, AnalysisObjects>::iterator anit=analysis_objs_map.begin(); anit!=analysis_objs_map.end(); ++anit){
			AnalysisObjects these_objs= anit->second;
			TVector2        a_met     = these_objs.met.begin()->second ;
			metsmap.insert ( std::pair<int, TVector2> (kmet, a_met));
			kmet++;
		}
		evret=dbxAnalyses[k]->makeAnalysis(&a0,metsmap, m_quad_unc);
             }
        } else { //systematics run
             map<string, AnalysisObjects>::iterator il=analysis_objs_map.find(sysnam);
             if (il==analysis_objs_map.end()) {cout<<"Systematics name mismatch. "<<sysnam<<" not found, MAJOR error\n"; exit (888);};
                DEBUG( k<<" "<<dbxAnalyses[k]->getName()<<" also known as "<< il->first<<" to be executed with systematics"<<endl );
		AnalysisObjects these_objs=il->second;
		evret=dbxAnalyses[k]->makeAnalysis(&these_objs); // generic
                DEBUG("retval=:"<<evret<<endl);
        }
   }

	DEBUG("An Event finished." <<std::endl);
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
		dbxAnalyses[i]->printEfficiencies();
		dbxAnalyses[i]->saveHistos();
	}

}

