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
AnalysisController::AnalysisController( analy_struct *iselect,  std::map <string, string> systematics) 
{
	extra_analysis_count=1;
	// ----- how many do we run in parallel ----
	if (iselect->dosystematics) {
		for( map<string,string>::iterator it=systematics.begin(); it!=systematics.end(); ++it) {
			syst_names.insert(*it);
	          	cout << "systematic included:"<<it->first <<endl;
		}
	}
	aselect=*iselect;
	cout << " #systematic included:"<<syst_names.size() <<endl;

        do_deps=false;
        do_RS = iselect->doRS ;
 //       cout << " H:"<< do_RS<<"\n";        

	string prereqs=aselect.dependencies;
	if (prereqs.length()>2 ){
          do_deps=true;
/*
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
*/
          vector<size_t> mainpos;
          size_t kol = prereqs.find('@', 0);
          size_t focol=10, focom, deplen;
	  if (kol == std::string::npos){ cerr<<"Wrong dependency list format. Use: @m:i,j,k \n"; exit (14);}
          while(kol != std::string::npos && focol != std::string::npos) {
                focol=prereqs.find_first_of(':',0);
                size_t leni=focol-kol;
	//  	cout<<kol<<","<<focol<<" Indep region STR="<<prereqs.substr(1,leni) <<" val="<<atoi(prereqs.substr(1,leni).c_str() ) <<"\n";
          	int mainAnalysis= atoi(prereqs.substr(1,leni).c_str()); // start at 1 to skip@, and find a number
                mainAnalyses.insert(mainAnalysis);
                kol = prereqs.find(':', 0);
                focol=prereqs.find_first_of('@',kol+1);
                focom=prereqs.find_first_of(',',kol+1);
        //        cout << "fo@="<<focol<<" fo,="<<focom<<"\n";
                if (focol<focom) {
                 cout << "No dependency.\n";
                 deplen=0;
                } else
                {

                deplen=focol-kol-2;
       //         cout <<" DepLen="<<deplen<<"\t";
	  	std::string depStr = prereqs.substr(kol+1, deplen); // NGU..
        //        cout <<"DepSTR="<<depStr<<"\n";

	  	for (size_t i=0,n; i <= depStr.length(); i=n+1) {
	   		n = depStr.find_first_of(',',i);
	   		if (n == std::string::npos) n = depStr.length();
	     		std::string tmp = depStr.substr(i,n-i);
        //                cout  << "Dep str="<<tmp<<"\n";
                        int depregid=atoi(tmp.c_str() );
                        if (depregid==mainAnalysis) { deplen++; break;}
	 //    		cout <<"Dep region id="<<depregid<<"\n";
             		depAnalyses.insert(depregid);
                        
		} // end of deps
                } // end of focol<focom
                prereqs.erase (prereqs.begin(), prereqs.begin()+focol);
        //        cout <<"----------------------------------="<<prereqs<<"\n";
          	kol = prereqs.find_first_of('@', 0);
                }
	} // end of prereqs.
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
                analyindex++;
		char tmp[128];
		sprintf (tmp,"BP_%i",analyindex);
		dbxAnalyses.push_back( new BPdbxA(tmp) ); // BP analysis with name

          if (aselect.dosystematics) { // another loop here for systematics
            for (map<string,string>::iterator it = syst_names.begin(); it != syst_names.end(); it++) {
                                std::string s = tmp;
                                            s+= "_";
                                            s+= it->first;
                                std::string targetVar = it->second ;
                                k++;
                                cout <<k<<"th syst (" << s << ") analysis initialized  with card: "<<tmp<<" , ";
                                dbxAnalyses.push_back( new BPdbxA( (char*)s.c_str() ) ); // analysis with new name
                                dbxAnalyses.back()->setDataCardPrefix(tmp);  // but with old datacard
                                cout << endl;
            }
          }// end of systematics if
	} // end of BP count

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
         if (do_RS ) {
           todos.push_back( dbxAnalyses[k] );
         }
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
         if (token_cnt>1) {
          if ((ana.find("WHF") == std::string::npos) && (ana.find("qcd") == std::string::npos ) ){
            sysnam=ana;
            break;
           }
         }
        }
       
        if (sysnam.size()< 1){ // not a systematics run condition
             if (!aDumper){ //not a dumper, i.e. BP run
//-----------------------------assume initial analysis returns this:
//2:     1,pass  0,fail
//5:     1,pass  1,pass  1,pass  1,pass  0,fail
//10005: 1,pass  1,pass  1,pass  1,pass  1,pass
//  k is the analysis index
//-------------at this point we should know if anAnalysis depends on Another.
               DEBUG(dbxAnalyses[k]->getName()<<" to be executed with defaults"<<endl);
               int lastpass=0;
               if(do_deps) { // take care to analyses depending on each other
                if ( depAnalyses.find(k) != depAnalyses.end() ){ // if result is True, this analysis is dependent, get info from 0.
                   if (mainAresults < 10000) controlword=mainAresults; // means last cut fails.
                   else {
                      lastpass=1;
                      controlword=(mainAresults-10000);
                   }
                   a0.evt.user_evt_weight=refA0.evt.user_evt_weight;
                }
               } else {
                   a0.evt.user_evt_weight=refA0.evt.user_evt_weight;
               }
//----------------------------------------------
	       evret=dbxAnalyses[k]->makeAnalysis(&a0, controlword, lastpass);   //------------------------------ regular analysis

/*
               for (dbxA *i:todos ) {
                i->addRunLumiInfo(a0.evt.run_no, a0.evt.lumiblk_no ,a0.evt.event_no, evret<10000? 0 : 1 );
                cout << "filling RS:"<<i->getName()<<" has:"<< (evret<10000? 0 : 1) << " for event:"<<a0.evt.event_no<<"\n" ;
               }
*/               

//     cout << "filling RS:"<<dbxAnalyses[k]->getName()<<" has:"<< (evret<10000? 0 : 1) << " for event:"<<a0.evt.event_no<<"\n" ;
     if(do_RS) dbxAnalyses[k]->addRunLumiInfo(a0.evt.run_no, a0.evt.lumiblk_no ,a0.evt.event_no, evret<10000? 0 : 1);
//----------------------------------------------
             if(do_deps) { 
                   if (mainAnalyses.find(k) != mainAnalyses.end() ) {   //was k==mainAnalysis
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
		evret=dbxAnalyses[k]->makeAnalysis(&these_objs, 0, 0); // no cache
                DEBUG("retval:"<<evret<<endl);
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

