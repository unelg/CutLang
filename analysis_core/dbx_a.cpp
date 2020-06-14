#include "dbx_a.h"

#include <iostream>
#include "TRandom3.h"


dbxA:: ~dbxA() {}

dbxA:: dbxA(char *aname) {
  GEV = 1000.;
  p_runno=-1;
  p_lumino=-1;
  HFtype=-1;
  sprintf (cname, "%s",aname); // more checks here

  cout << "This is "<<cname<<endl;

  char tmp[128];
  sprintf (tmp, "histoOut-%s.root",cname);

  if (strcmp(aname,"same")==0) {
   histoOut= new TFile (tmp,"update");
  } else {
   histoOut= new TFile (tmp,"recreate");
  }
  setDataCardPrefix(cname);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: addRunLumiInfo(int rn, int lbn) {  // to keep track of the lumi
 if ((p_runno!=rn) || (p_lumino!= lbn)) {
  p_runno=rn;
  p_lumino=lbn;
  rntuple->Fill(p_runno, p_lumino);
 }
 return 0;
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
  histoOut->Write(cname);
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
  int retval=0;
  TDirectory *ndir= new TDirectory();
  ndir = histoOut->mkdir(dn);
  histoOut->cd(dn);
  return retval;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::defHistos( unsigned int effsize) {
  int retval=0;
  eff= new TH1D("cutflow","cutflow event counts ",effsize,0.5,effsize+0.5);
  rntuple = new TNtuple("rntuple","run info","rn:lb");
  return retval;

//  if (binsize>0) hbincounts= new TH1F("bincounts","event counts in bins ",binsize,0.5,binsize+0.5);
}

