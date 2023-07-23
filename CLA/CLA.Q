#include "fcc.h"
#include "lhco.h"
#include "atlasopen.h"
#include "atlasopenR2.h"
#include "cmsod.h"
#include "cmsod2.h"
#include "delphes.h"
#include "lvl0.h"
#include "VLLMin.h"
#include "CMSnanoAOD.h"
#include "AtlMin.h"
#include "AtlasTRT.h"
#include "VLLBG3.h"
#include "VLLg.h"
#include "VLLf.h"
#include "VLLMinSignal.h"
#include "DELPHES2.h"
#include "dbxParticle.h"
#include "newpoet.h"
//#include "dbxAna.h"
#include <TH2.h>
#include <TError.h>
#include <TApplication.h>
//#include "TDSet.h"
//#include <TProof.h>

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
//------------------------ TEST 
using namespace std;

int root_analysisd3pd(string sample, analy_struct aselect);
TTreeReader *ttreader;

int main(int argc, char*argv[])
{

/** select analysis */
 analy_struct aselect;
 aselect.Dumpcount=0;
 aselect.BPcount=1;
 aselect.dosystematics=false;
 aselect.doQCD=false;
 aselect.doRS=false;
 aselect.maxEvents=0; // now the default is 0
 aselect.startpt=0;
 aselect.verbfreq=1000;

 bool  use_fcc=false;
 bool use_lhco=false;
 bool use_lvl0=false;
 bool use_poet=false;
 bool use_delphes=false;
 bool use_atlasod=false;
 bool use_atlasodR2=false;
 bool use_atlmin=false;
 bool use_atltrt=false;
 bool use_cmsod=false;
 bool use_cmsodR2=false;
 bool use_cmsnano=false;
 bool use_vllf=false;
 bool use_vllg=false;
 bool use_vllmin=false;
 bool use_vllbg3 =false;
 bool use_vllsignal =false;
 bool use_DELPHES2=false;

 string inptype;
 char *username=NULL;

cout << "CLA v2.50.0\t";
 cout << "compiled on XXXXYYYYZZZZ \n";

for (int i = 2; i < argc; i++) {
     if (i + 1 != argc) // Check that we haven't finished parsing already
         if        (std::string(argv[i]) == "-D")  { // Dump
             aselect.Dumpcount = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-BP") { // BP
             aselect.BPcount = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-S") { // systematics
             aselect.dosystematics = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-RS") { // Run Summary 
             aselect.doRS = true;  
//             cout <<"RS will be added\n";
         } else if (std::string(argv[i]) == "-Q") { // do QCD
             aselect.doQCD = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-P") { // use prereqs
             aselect.dependencies=argv[i + 1];  i++;
         } else if (std::string(argv[i]) == "-UN") { // username to be added to histoname
             username = argv[i + 1];  i++;
         } else if (std::string(argv[i]) == "-V") { // verbosity frequency in #events
             aselect.verbfreq = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-EVT") { // max events
             aselect.maxEvents = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-ST") { // start point
             aselect.startpt = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-HLT") { // HLT list
             aselect.hlt = std::string(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-inp") { // use LHCO format input
             inptype = argv[i + 1];  i++;
         } else {
             std::cout << "invalid arguments, please read the help below.\n";
     }
 }


 std::cout << "Analysis run count is "<< aselect.BPcount<<std::endl;
 if (aselect.Dumpcount > 0) std::cout << "#Dump runs is "<< aselect.Dumpcount<<std::endl;
 if (aselect.BPcount+aselect.Dumpcount < 1) {
  	     std::cout << "No analysis is set to run. Please set at least one.\n";
             std::cout << argv[0] << " filename.root \n"
                       << " [-inp LVL0 | DELPHES2 | LHCO | FCC | DELPHES | ATLASVLL | POET | ATLTRT | ATLMIN | ATLASOD | ATLASODR2 | CMSOD | CMSODR2 | CMSNANO | VLLBG3 | VLLSIGNAL | VLLG]\n"
                       << " [-BP #] [-D 1|0] [-P ] \n"
                       << " [-Q 1|0] [-HF 1|0] [-S 1|0] \n"
                       << " [-EVT #] [-UN userName] [-V v_freq] \n"  ;
  exit(-2);
 }

      if (inptype == "LHCO")    { use_lhco =true;}
 else if (inptype == "FCC" )    { use_fcc  =true;}
 else if (inptype == "POET" )   { use_poet =true;}
 else if (inptype == "DELPHES2"){ use_DELPHES2 =true;}
 else if (inptype == "LVL0")    { use_lvl0 =true;}
 else if (inptype == "DELPHES") { use_delphes =true;}
 else if (inptype == "ATLASVLL"){ use_vllmin =true;}
 else if (inptype == "ATLMIN")  { use_atlmin =true;}
 else if (inptype == "ATLTRT")  { use_atltrt =true;}
 else if (inptype == "ATLASOD") { use_atlasod =true;}
 else if (inptype == "ATLASODR2") { use_atlasodR2 =true;}
 else if (inptype == "CMSOD")   { use_cmsod =true;}
 else if (inptype == "CMSODR2") { use_cmsodR2 =true;}
 else if (inptype == "CMSNANO") { use_cmsnano =true;}
 else if (inptype == "VLLBG3")	{ use_vllbg3 =true;}
 else if (inptype == "VLLG")	{ use_vllg =true;}
 else if (inptype == "VLLF")	{ use_vllf =true;}
 else if (inptype == "VLLSIGNAL")	{ use_vllsignal =true;}
 else{
   std::cout<<"unknown input mode. exiting..."<<endl;
   exit(-3);
 }

 aselect.inputtype=inptype;

/** Chain the files  split by ',' */
  std::string argStr = argv[1];
  std::vector<std::string> fileList;
  for (size_t i=0,n; i <= argStr.length(); i=n+1) {
     n = argStr.find_first_of(',',i);
     if (n == std::string::npos) n = argStr.length();
     std::string tmp = argStr.substr(i,n-i);
     fileList.push_back(tmp);
  }
//  TApplication* theApp = new TApplication("App", &argc, argv);

  TChain *chain;

  std::string leafname;


  if (use_lhco){
   cout << "WARNING: using LHCO~~~reduced functionality~~~\n";
   leafname="LHCO";
  }else if (use_DELPHES2){
   cout << "~Now using DELPHES2 files.~\n";
   leafname="Delphes"; //DELPHES2 anchor
   cout << "~chained~\n";
  }else if (use_lvl0){
   cout << "~Now using LVL0 files.~\n";
   leafname="nt_tree";
  }else if (use_fcc){
   cout << "~Now using FCC files.~~~~~~ beta!\n";
   leafname="events";
  }else if (use_poet){
   cout << "~Now using new POET files.~~~~~~ alpha!\n";
   leafname="events";
/*
  TChain *cmuos;
  TChain *celes;
  TChain *ctaus;
  TChain *cjets;
  TChain *cphotons;
     chain = new TChain("mymuons/Events");
     celes = new TChain("myelectrons/Events");
     chain->AddFriend(celes);
     ctaus = new TChain("mytaus/Events");
     chain->AddFriend(ctaus);
     cjets = new TChain("myjets/Events");
     chain->AddFriend(cjets);
  cphotons = new TChain("myphotons/Events");
     chain->AddFriend(cphotons);
*/
  }else if (use_cmsodR2){
   cout << "~Now using CMS Open Data R2 files.~~~~~~ beta!\n";
   leafname="Events";
  }else if (use_cmsod){
   cout << "~Now using CMS Open Data files.~~~~~~ beta!\n";
   leafname="events";
  }else if (use_cmsnano){
   cout << "~Now using CMS NanoAOD files.~~~~~~ beta!\n";
   leafname="Events";
  }else if (use_atlasod){
   cout << "~Now using ATLAS Open Data files.~~~~~~ beta!\n";
   leafname="mini";
  }else if (use_atlasodR2){
   cout << "~Now using ATLAS Open Data R2 files.~~~~~~ beta!\n";
   leafname="mini";
  }else if (use_atlmin){
   cout << "~Now using ATLAS Mini NTUPLE files.~~~~~~ alpha!\n";
   leafname="nominal";
  }else if (use_atltrt){
   cout << "~Now using ATLAS TRT NTUPLE files.~~~~~~ alpha!\n";
   leafname="track_tree";
  }else if (use_vllmin){
   cout << "~Now using ATLAS VLL MIN Data files.~~~~~~ alpha!\n";
   leafname="/physics";
  }else if (use_delphes){
   cout << "~Now using Delphes files.~~~~~~ beta!\n";
   leafname = "Delphes";
  }else if (use_vllbg3){
   cout << "~Now using ATLAS v3 background files.~~~~~~ alpha!\n";
   leafname = "NOSYS/physics";
  }else if (use_vllsignal){
   cout << "~Now using ATLAS VLL Signal files.~~~~~~ alpha!\n";
   leafname = "physics";
  }else if (use_vllf){
   cout << "~Now using ATLAS VLL Group f files.~~~~~~ alpha!\n";
   leafname = "nominal";
  }else if (use_vllg){
   cout << "~Now using ATLAS VLL Group g files.~~~~~~ alpha!\n";
   leafname = "nominal";
  }else{
   leafname = "physics";
  }

   chain = new TChain(leafname.c_str() );
   TFile * _afile = TFile::Open(fileList[0].c_str());
   ttreader =  new TTreeReader(leafname.c_str(), _afile);


  int aret;
  for (unsigned int iFile=0; iFile<fileList.size(); ++iFile){
    std::cout << "open " << fileList[iFile].c_str() << std::endl;
    gErrorIgnoreLevel = 5000;
    aret=chain->Add(fileList[iFile].c_str(), 0);
    cout << "RetVal:"<<aret<<endl;
//  if (use_wank){
//   aret=celes->Add(fileList[iFile].c_str(), 0);
//   aret=ctaus->Add(fileList[iFile].c_str(), 0);
//   aret=cjets->Add(fileList[iFile].c_str(), 0);
//   aret=cphotons->Add(fileList[iFile].c_str(), 0);
//  }
  }
  if (chain->GetEntries() > 0 ) {
    cout << "initialized with the chain..."<< chain->GetEntries()<<endl; 
    string xxx="XXX";

   if (use_lhco){
    lhco *lhcoa=new lhco((char*)xxx.c_str(),chain);
          lhcoa->Loop(aselect, username);
   } else if (use_DELPHES2){
    DELPHES2 *DELPHES2a=new DELPHES2((char*)xxx.c_str(),chain);
          cout << "DELPHES2 obj ok\n";
             DELPHES2a->Loop(aselect, username);
  } else if (use_poet){
    newpoet *poeta=new newpoet((char*)xxx.c_str(),chain);
          poeta->Loop(aselect, username);
   } else if (use_lvl0){
    lvl0 *lvl0a=new lvl0((char*)xxx.c_str(),chain);
          lvl0a->Loop(aselect, username);
   } else if (use_cmsnano){
    CMSnanoAOD *CMSnanoAODa=new CMSnanoAOD((char*)xxx.c_str(),chain);
                CMSnanoAODa->Loop(aselect, username);
   } else if (use_cmsod){
    cmsod *cmsoda=new cmsod((char*)xxx.c_str(),chain);
           cmsoda->Loop(aselect, username);
   } else if (use_cmsodR2){
    cmsod2 *cmsoda=new cmsod2((char*)xxx.c_str(),chain);
           cmsoda->Loop(aselect, username);
   } else if (use_atlasod){
    atlasopen *atlasoda=new atlasopen((char*)xxx.c_str(),chain);
               atlasoda->Loop(aselect, username);
   } else if (use_atlasodR2){
    atlasopenR2 *atlasoda=new atlasopenR2((char*)xxx.c_str(),chain);
               atlasoda->Loop(aselect, username);
   } else if (use_vllmin){
     VLLMin *vllmina=new VLLMin((char*)xxx.c_str(),chain);
             vllmina->Loop(aselect, username);
  } else if (use_atlmin){
    AtlMin *atlmina=new AtlMin((char*)xxx.c_str(),chain);
            atlmina->Loop(aselect, username);
  } else if (use_atltrt){
   AtlasTRT *atltrta=new AtlasTRT((char*)xxx.c_str(),chain);
             atltrta->Loop(aselect, username);
   } else if (use_fcc){
    fcc *fcca=new fcc((char*)xxx.c_str(),chain);
         fcca->Loop(aselect, username);
   } else if (use_delphes){
    delphes *delphesa=new delphes((char*)xxx.c_str(),chain);
             delphesa->Loop(aselect, username);
   } else if (use_vllbg3){
    VLLBG3 *VLLBG3a=new VLLBG3((char*)xxx.c_str(),chain);
           VLLBG3a->Loop(aselect, username);
   } else if (use_vllsignal){
    VLLMinSignal *VLLMinSignala=new VLLMinSignal((char*)xxx.c_str(),chain);
          VLLMinSignala->Loop(aselect, username);
   } else if (use_vllg){
    VLLg *VLLga=new VLLg((char*)xxx.c_str(),chain);
          VLLga->Loop(aselect, username);
   } else if (use_vllf){
    VLLf *VLLfa=new VLLf((char*)xxx.c_str(),chain);
          VLLfa->Loop(aselect, username);
  }

  cout << "finished."<<endl;

  } else {
    std::cout <<"WARNING: No events found in files " << std::endl;
  }
  //chain->Delete();
  return 0;

}
