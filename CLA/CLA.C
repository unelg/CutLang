#include "fcc.h"
#include "lhco.h"
#include "atlasopen.h"
#include "cmsod.h"
#include "delphes.h"
#include "lvl0.h"
#include "dbxParticle.h"
#include <TH2.h>
#include <TError.h>
#include <TApplication.h>

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int root_analysisd3pd(string sample, analy_struct aselect);

int main(int argc, char*argv[]) 
{ 

/** select analysis */
 analy_struct aselect;
 aselect.FFcount=0;
 aselect.N4count=0;
 aselect.Skeletoncount=0;
 aselect.Dumpcount=0;
 aselect.E61count=0;
 aselect.E62count=0;
 aselect.BPcount=1;
 aselect.TPcount=0;
 aselect.MCHcount=0;
 aselect.DCHcount=0;
 aselect.dosystematics=false;
 aselect.doQCD=false;
 aselect.doHF=false;
 aselect.maxEvents=0; // now the default is 0
 aselect.verbfreq=1000;

 bool  use_fcc=false;
 bool use_lhco=false;
 bool use_lvl0=false;
 bool use_delphes=false;
 bool use_atlasod=false;
 bool use_cmsod=false;

 string inptype;
 char *username=NULL;

 cout << "CLA v2.1.0\n";

for (int i = 2; i < argc; i++) {
     if (i + 1 != argc) // Check that we haven't finished parsing already
         if        (std::string(argv[i]) == "-FF")  { // FF
             aselect.FFcount = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-N4")  { // N4
             aselect.N4count = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-Skeleton")  { //Skeleton                                   
             aselect.Skeletoncount = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-D")  { // Dump                  
             aselect.Dumpcount = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-MCH") { // MCH
             aselect.MCHcount = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-DCH") { // DCH
             aselect.DCHcount = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-E61") { // E61
             aselect.E61count = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-E62") { // E62
             aselect.E62count = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-BP") { // BP 
             aselect.BPcount = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-S") { // systematics
             aselect.dosystematics = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-Q") { // do QCD
             aselect.doQCD = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-HF") { // heavy flavour
             aselect.doHF = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-UN") { // username to be added to histoname
             username = argv[i + 1];  i++;
         } else if (std::string(argv[i]) == "-V") { // verbosity frequency in #events
             aselect.verbfreq = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-EVT") { // max events
             aselect.maxEvents = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-inp") { // use LHCO format input
             inptype = argv[i + 1];  i++;
         } else {
             std::cout << "invalid arguments, please try again:\n";
             exit(-1);
     }
 }
 

 std::cout << "#BP  runs is "<< aselect.BPcount<<std::endl;
 std::cout << "#Dump runs is "<< aselect.Dumpcount<<std::endl;
 if (aselect.FFcount+aselect.MCHcount+aselect.DCHcount+aselect.E61count+aselect.E62count+aselect.BPcount+aselect.TPcount+aselect.N4count+aselect.Skeletoncount+aselect.Dumpcount < 1) {
  	     std::cout << "No analysis is set to run. Please set at least one.\n";
             std::cout << argv[0] << " d3pd.root \n"
                       << " [-inp LVL0 | LHCO | FCC | DELPHES | ATLASOD | CMSOD]\n"  
                       << " [-BP #] [-D 1|0] \n"
                       << " [-Q 1|0] [-HF 1|0] [-S 1|0] \n"  
                       << " [-EVT #] [-UN userName] [-V v_freq] \n"  ;
  exit(-2);
 }

      if (inptype == "LHCO")    { use_lhco =true;}
 else if (inptype == "FCC" )    { use_fcc  =true;}
 else if (inptype == "LVL0")    { use_lvl0 =true;}
 else if (inptype == "ATLASOD") { use_atlasod =true;}
 else if (inptype == "CMSOD")   { use_cmsod =true;}
 else if (inptype == "DELPHES") { use_delphes =true;}
 else{
   std::cout<<"unknown input mode. exiting..."<<endl;
   exit(-3);
 }

int ival=atoi(argv[1]);
if (ival==0) {
  /** Chain the files  split by ',' */
  std::string argStr = argv[1];
  std::vector<std::string> fileList;
  for (size_t i=0,n; i <= argStr.length(); i=n+1) {
     n = argStr.find_first_of(',',i);
     if (n == std::string::npos)
       n = argStr.length();
     std::string tmp = argStr.substr(i,n-i);
     fileList.push_back(tmp);
  }
  TApplication* theApp = new TApplication("App", &argc, argv);

  TChain *chain;
  if (use_lhco){
   cout << "WARNING: using LHCO~~~reduced functionality~~~\n";
   chain = new TChain("LHCO");
  }else if (use_lvl0){
   cout << "~Now using LVL0 files.~\n";
   chain = new TChain("nt_tree");
  }else if (use_fcc){
   cout << "~Now using FCC files.~~~~~~ beta!\n";
   chain = new TChain("events");
  }else if (use_cmsod){
   cout << "~Now using CMS Open Data files.~~~~~~ beta!\n";
   chain = new TChain("events");
  }else if (use_atlasod){
   cout << "~Now using ATLAS Open Data files.~~~~~~ beta!\n";
   chain = new TChain("mini");
  }else if (use_delphes){
   cout << "~Now using Delphes files.~~~~~~ beta!\n";
   chain = new TChain("Delphes");
  }else{
   chain = new TChain("physics");
  } 
  int aret;
  for (unsigned int iFile=0; iFile<fileList.size(); ++iFile){
    std::cout << "open " << fileList[iFile].c_str() << std::endl;
    gErrorIgnoreLevel = 5000;
    aret=chain->Add(fileList[iFile].c_str(), 0);
    cout << "RetVal:"<<aret<<endl;
  }
  if (chain->GetEntries() > 0 ) {
    cout << "initialized with the chain"<<endl;

    chain->GetEntry(0); 

   if (use_lhco){
    lhco *lhcoa=new lhco("XXX",chain);
          lhcoa->Loop(aselect, username);
   } else if (use_lvl0){
    lvl0 *lvl0a=new lvl0("XXX",chain);
          lvl0a->Loop(aselect, username);
   } else if (use_cmsod){
    cmsod *cmsoda=new cmsod("XXX",chain);
           cmsoda->Loop(aselect, username);
   } else if (use_atlasod){
    atlasopen *atlasoda=new atlasopen("XXX",chain);
               atlasoda->Loop(aselect, username);
   } else if (use_fcc){
    fcc *fcca=new fcc("XXX",chain);
         fcca->Loop(aselect, username);
   } else if (use_delphes){
    delphes *delphesa=new delphes("XXX",chain);
             delphesa->Loop(aselect, username);
  } 

  cout << "finished."<<endl;
  } else {
    std::cout <<"WARNING: No events found in files " << std::endl;
  }
  //chain->Delete(); 
  return 0;

} else {
    std::cout <<"ERROR: first argument should be the datafile name " << std::endl;
    return -2;
}

}
