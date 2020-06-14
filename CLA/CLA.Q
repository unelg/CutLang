#include "fcc.h"
#include "lhco.h"
#include "atlasopen.h"
#include "cmsod.h"
#include "delphes.h"
#include "lvl0.h"
#include "VLLMin.h"
#include "CMSnanoAOD.h"
#include "AtlMin.h"
#include "VLLBG3.h"
#include "dbxParticle.h"
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

int main(int argc, char*argv[])
{

/** select analysis */
 analy_struct aselect;
 aselect.Dumpcount=0;
 aselect.BPcount=1;
 aselect.dosystematics=false;
 aselect.doQCD=false;
 aselect.doHF=false;
 aselect.maxEvents=0; // now the default is 0
 aselect.startpt=0;
 aselect.verbfreq=1000;

 bool  use_fcc=false;
 bool use_lhco=false;
 bool use_lvl0=false;
 bool use_delphes=false;
 bool use_atlasod=false;
 bool use_atlmin=false;
 bool use_cmsod=false;
 bool use_cmsnano=false;
 bool use_vllmin=false;
 bool use_vllbg3 =false;

 string inptype;
 char *username=NULL;

 cout << "CLA v02.9.00\t";
 cout << "compiled on XXXXYYYYZZZZ \n";

for (int i = 2; i < argc; i++) {
     if (i + 1 != argc) // Check that we haven't finished parsing already
         if        (std::string(argv[i]) == "-D")  { // Dump
             aselect.Dumpcount = atoi(argv[i + 1]);   i++;
         } else if (std::string(argv[i]) == "-BP") { // BP
             aselect.BPcount = atoi(argv[i + 1]);  i++;
         } else if (std::string(argv[i]) == "-S") { // systematics
             aselect.dosystematics = atoi(argv[i + 1]);  i++;
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
                       << " [-inp LVL0 | LHCO | FCC | DELPHES | ATLASVLL | ATLASOD | CMSOD | CMSNANO | VLLBG3]\n"
                       << " [-BP #] [-D 1|0] [-P ] \n"
                       << " [-Q 1|0] [-HF 1|0] [-S 1|0] \n"
                       << " [-EVT #] [-UN userName] [-V v_freq] \n"  ;
  exit(-2);
 }

      if (inptype == "LHCO")    { use_lhco =true;}
 else if (inptype == "FCC" )    { use_fcc  =true;}
 else if (inptype == "LVL0")    { use_lvl0 =true;}
 else if (inptype == "DELPHES") { use_delphes =true;}
 else if (inptype == "ATLASVLL"){ use_vllmin =true;}
 else if (inptype == "ATLMIN")  { use_atlmin =true;}
 else if (inptype == "ATLASOD") { use_atlasod =true;}
 else if (inptype == "CMSOD")   { use_cmsod =true;}
 else if (inptype == "CMSNANO") { use_cmsnano =true;}
 else if (inptype == "VLLBG3")	{ use_vllbg3 =true;}
 else{
   std::cout<<"unknown input mode. exiting..."<<endl;
   exit(-3);
 }

/*
TProof* proof;
#define PROPT TProof::EUploadPackageOpt::kRemoveOld

      if (use_proof) {


        cout << "Making the cards package"<<endl;
        gSystem->Exec("mkdir cards; mkdir cards/PROOF-INF");
        gSystem->Exec("cp *-*.txt cards");
        gSystem->Exec("echo \"Int_t SETUP(){return 0;}\" > cards/PROOF-INF/SETUP.C");
        gSystem->Exec("tar czhf cards.par cards");
        gSystem->Exec("rm -rf cards");
        cout << "cards prepared.\n";

        cout << "Making the libs package"<<endl;
        gSystem->Exec("mkdir libs");
        gSystem->Exec("mkdir libs/PROOF-INF");
        gSystem->Exec("cp ../CLA/*.so* libs");
        gSystem->Exec("cp ../analysis_core/* libs");
        gSystem->Exec("cat ../analysis_core/SETUP.C | grep -v BAT | grep -v KLFitter > libs/PROOF-INF/SETUP.C");
        gSystem->Exec("tar czhf libs.par libs");
        gSystem->Exec("rm -rf libs");
        cout << "libs prepared\n";

        proof = TProof::Open("");
        proof->ClearCache();

        proof->UploadPackage("cards", PROPT );
        proof->EnablePackage("cards",1);
        proof->UploadPackage("libs", PROPT );
        proof->EnablePackage("libs",1);
        proof->ShowPackages();
        proof->Exec(".! uname -a");
        cout << "___________________________________________"<<endl;

       proof->Load("../CLA/dbxAna.C");

       dbxAna anAna;
       vector<string> tnames;
       tnames.push_back("nominal");
       TString          runname_tmp="107705";
       TString  runfile=runname_tmp;
                runfile+=".txt";

       vector<string>::iterator aniter;
       for (aniter = tnames.begin(); aniter < tnames.end(); aniter++){
          cout << "will work on Tree:"<<aniter->data()<< " From following files:"<<endl;
          TDSet *aset = new TDSet ("TTree",aniter->data() );
          string item_name;
          ifstream nameFileout;
                   nameFileout.open(runfile);
            while (nameFileout >> item_name) {
                     std::cout << item_name<<"\n";
             aset->Add(item_name.data());
            }

        cout << "----------------------------------------"<<endl;
//        proof->Process(aset, &anAna, " ", 0);

//      proof->Process(aset, "dbxAna", " -BP 1 -S 0 -AtlMin 1 ", 0); // the real execution
        aset->Process("dbxAna.C"," -BP 1 -S 0 -AtlMin 1 ",0); // the real execution
      }



       proof->Close();
       std::cout << "proof run finished\n";
       exit (0);
      }
*/

int ival=atoi(argv[1]);
if (ival==0) {
  /** Chain the files  split by ',' */
  std::string argStr = argv[1];
  std::vector<std::string> fileList;
  for (size_t i=0,n; i <= argStr.length(); i=n+1) {
     n = argStr.find_first_of(',',i);
     if (n == std::string::npos) n = argStr.length();
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
  }else if (use_cmsnano){
   cout << "~Now using CMS NanoAOD files.~~~~~~ beta!\n";
   chain = new TChain("Events");
  }else if (use_atlasod){
   cout << "~Now using ATLAS Open Data files.~~~~~~ beta!\n";
   chain = new TChain("mini");
  }else if (use_atlmin){
   cout << "~Now using ATLAS Mini NTUPLE files.~~~~~~ alpha!\n";
   chain = new TChain("nominal");
  }else if (use_vllmin){
   cout << "~Now using ATLAS VLL MIN Data files.~~~~~~ alpha!\n";
   chain = new TChain("/physics");
  }else if (use_delphes){
   cout << "~Now using Delphes files.~~~~~~ beta!\n";
   chain = new TChain("Delphes");
  }else if (use_vllbg3){
   cout << "~Now using ATLAS v3 background files.~~~~~~ alpha!\n";
   chain = new TChain("NOSYS/physics");
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
   } else if (use_cmsnano){
    CMSnanoAOD *CMSnanoAODa=new CMSnanoAOD("XXX",chain);
                CMSnanoAODa->Loop(aselect, username);
   } else if (use_cmsod){
    cmsod *cmsoda=new cmsod("XXX",chain);
           cmsoda->Loop(aselect, username);
   } else if (use_atlasod){
    atlasopen *atlasoda=new atlasopen("XXX",chain);
               atlasoda->Loop(aselect, username);
   } else if (use_vllmin){
     VLLMin *vllmina=new VLLMin("XXX",chain);
             vllmina->Loop(aselect, username);
  } else if (use_atlmin){
    AtlMin *atlmina=new AtlMin("XXX",chain);
            atlmina->Loop(aselect, username);
   } else if (use_fcc){
    fcc *fcca=new fcc("XXX",chain);
         fcca->Loop(aselect, username);
   } else if (use_delphes){
    delphes *delphesa=new delphes("XXX",chain);
             delphesa->Loop(aselect, username);
   } else if (use_vllbg3){
    VLLBG3 *VLLBG3a=new VLLBG3("XXX",chain);
           VLLBG3a->Loop(aselect, username);
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
