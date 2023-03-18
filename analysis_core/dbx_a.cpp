#include "dbx_a.h"

#include <iostream>
#include "TRandom3.h"


dbxA:: ~dbxA() {}

dbxA:: dbxA(char *aname) {
  p_runno=-1;
  p_lumino=-1;
  cname=aname;

//  cout << "This is "<<cname<<endl;

  TString afile="histoOut-";
          afile+=cname;
          afile+=".root";

  if (strcmp(aname,"same")==0) {
   histoOut= new TFile (afile.Data(),"update");
  } else {
   histoOut= new TFile (afile.Data(),"recreate");
  }
  setDataCardPrefix(cname);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void dbxA:: addRunLumiInfo(int rn, int lbn, int evtno, bool rslt) {  // to keep track of the lumi
 if ((p_runno!=rn) || (p_lumino!= lbn)) {
  p_runno=rn;
  p_lumino=lbn;
 }
  rntuple->Fill(p_runno, p_lumino, evtno, rslt);
 return ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: makeAnalysis(AnalysisObjects *ao, int idx) {
  return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: makeAnalysis(AnalysisObjects *ao, int idx, int a) {
  return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::saveHistos() {
  int retval=0;
  cout << "saving...\t";
  histoOut->Flush();
  histoOut->Write(cname.c_str());
  cout << "saved.\n";
  return retval;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::ChangeDir(char *dn) {
 histoOut->cd(dn);
 return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::setDir(char *dn) {
//  std::cout<<"~~~~~~~~~~~~~~~~~~~~~="<<dn<<"\n";
  int retval=0;
  TDirectory *ndir= new TDirectory();
  ndir = histoOut->mkdir(dn);
  histoOut->cd(dn);
  delete ndir;
  return retval;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::defHistos( unsigned int effsize) {
  int retval=0;
  eff= new TH1D("cutflow","cutflow event counts ",effsize,0.5,effsize+0.5);
  rntuple = new TNtuple("rntuple","run info","rn:lb:evt:rslt");
  return retval;

//  if (binsize>0) hbincounts= new TH1F("bincounts","event counts in bins ",binsize,0.5,binsize+0.5);
}

