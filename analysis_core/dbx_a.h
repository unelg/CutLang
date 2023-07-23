#ifndef DBX_A_H
#define DBX_A_H

#include <vector>
#include <cmath>
#include "TLorentzVector.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TH1F.h"
#include "TH2F.h"
#include <iostream>
#include "TCanvas.h"

#include "dbx_electron.h"
#include "dbx_photon.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "Node.h"

using namespace std;

#define NPERIOD 11



class dbxA {

public:
	dbxA( char*);
	~dbxA();

   virtual int makeAnalysis(AnalysisObjects *ao, int, int);
   virtual int makeAnalysis(AnalysisObjects *ao, int);
   virtual int makeAnalysis(AnalysisObjects *ao) { return makeAnalysis(ao,0); } // execute default
   virtual int makeAnalysis(AnalysisObjects *ao, map <int, TVector2>, vector <double>){std::cout<<"3RR0Rg!\n"; return 0;}

   virtual int saveHistos();
   virtual int defHistos(unsigned int);
   string getName() { return cname;}
   virtual int initGRL() { return 0;}
   virtual int readAnalysisParams() { return 0;}
   virtual int setQCD() { return 0;}
   virtual int printEfficiencies() { return 0;}
   virtual int setDir(char *); // to have multiple directories
   virtual int ChangeDir(char *); // to be able to cd later on
   virtual void addRunLumiInfo(int rn, int lbn, int evntno, bool rslt); // to have list of run and lumi block numbers
   static const string perName[NPERIOD];

   void   setDataCardPrefix(string dcp) { dataCardPrefix = dcp; }
   string getDataCardPrefix() { return dataCardPrefix; }

   std::string cname;
   std::string itype;
   TH1D *eff, *hbincounts;

private:
// file to output histogtrams
   TFile *histoOut;
   
// run and lumi block information
    int p_runno;
    int p_lumino;
    string dataCardPrefix;
    TNtuple *rntuple;

};

#endif
