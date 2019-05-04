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

   virtual int makeAnalysis(AnalysisObjects ao, int);
   virtual int makeAnalysis(AnalysisObjects ao) { return makeAnalysis(ao,0); }
   virtual int makeAnalysis(AnalysisObjects ao, map <int, TVector2>, vector <double>){std::cout<<"3RR0Rg!\n"; return 0;}

   virtual int plotVariables(int); // the detail level and save is controlled here
   virtual int saveHistos();
   string getName() { return cname;}
   virtual int initGRL() { return 0;}
   virtual int readAnalysisParams() { return 0;}
   virtual int bookAdditionalHistos() { return 0;}
   virtual int setQCD() { return 0;}
   virtual int printEfficiencies() { return 0;}
   virtual int setDir(char *); // to have multiple directories
   virtual int ChangeDir(char *); // to be able to cd later on
   virtual int addRunLumiInfo(int rn, int lbn); // to have list of run and lumi block numbers
   static const string perName[NPERIOD];
   static double deltaR(double eta1, double phi1, double eta2, double phi2);
   static int getPeriodIndx(unsigned int);
   static int getMCPeriodIndx(unsigned int, unsigned int);
   static double getPeriodLumi(unsigned int);
   static const double totalLumi2011() {  return 4713.11; } // lumi in pb-1.

/////////////////////////////////////
// Kaya's modification   
   void initializeTTree(TTree* t, Double_t* adresler, int len_Fields, const char* branchNamePrefix, const char* fields[]);
   void initializeTTree4TLorentzVector(TTree* t, Double_t* adresler, const char* branchNamePrefix);
   void initializeTTree4dbxParticle(TTree* t, Double_t* adresler, const char* branchNamePrefix);
   void initializeTTree4dbxMuon(TTree* t, Double_t* adresler, const char* branchNamePrefix);
   void initializeTTree4dbxElectron(TTree* t, Double_t* adresler, const char* branchNamePrefix);
   void initializeTTree4dbxJet(TTree* t, Double_t* adresler, const char* branchNamePrefix);

   void fillTTree4LorentzVector(TTree* t, Double_t* adresler, TLorentzVector & vec);
   void fillTTree4dbxParticle(TTree* t, Double_t* adresler, dbxParticle & dbx_particle);
   void fillTTree4dbxMuon(TTree* t, Double_t* adresler, dbxMuon & dbx_muon);
   void fillTTree4dbxElectron(TTree* t, Double_t* adresler, dbxElectron & dbx_electron);
   void fillTTree4dbxJet(TTree* t, Double_t* adresler, dbxJet & dbx_jet);
/////////////////////////////////////

   void   setDataCardPrefix(string dcp) { dataCardPrefix = dcp; }
   string getDataCardPrefix() { return dataCardPrefix; }
   string getDataCardName()   { return dataCardPrefix+"-card.txt"; }

   char cname[128];
   TH1F *eff;
// list the analysis parameters here.
   float minpte, minptm, minptg, maxmet;
   float maxetae,maxetam,maxetag, minmetmu,minmwte,minmwtmu;  // leptons
   float minmete,minmwtmete;  // met and mwt related
   float minmetm,minmwtmetm;  // met and mwt related
   float minptj, maxetaj;   // basic jet definitions 
   float mindrjm, mindrje; // isolation related
   float minptj1, minptj2, minEj2,  minetaj2, mindrjj, minetajj;
   float mqhxmin, mqhxmax,maxdeltam;//related to reconstructed quark mass
   float maxMuPtCone, maxMuEtCone, maxElPtCone, maxElEtCone;
   float jetVtxf2011,jetVtxf2012,jetVtxf;
   //serhat
   float MW,MZ,SGMW,SGMZ,SGHQ,SGHQBAR,MINPTE0,MINPTE1,MINPTMO,MINPTM1,MINNJETS;
   float MINPTJ0,MINPTJ1,MINPTELES,MINWMASS,MAXWMASS,MINPTPR1CHI2,MINDRWPR1CHI2;
   float MINPTPR2CHI2,MAXZMASS,MINZMASS,MINDRZPR2CHI2,MINPTZREC,MINPTWREC,MINDELTAM;
   bool QCDRUN;
   //eof serhat
   int HFtype;
   int TRGe, TRGm;


// mass values that could be used in the analysis
   Double_t m_mw, m_mz, m_mh;
   Double_t GEV;


private:
// file to output histogtrams
   TFile *histoOut;
   
// run and lumi block information
    int p_runno;
    int p_lumino;
#define m_idx 8

    string dataCardPrefix;

// common histograms 
// these should be malloc'ed but I have no time to implement it. NGU.
// so this thing will crap out if more than 7 jets
   TH1F *hmet[m_idx], *hjpt[m_idx], *hept[m_idx], *hmpt[m_idx],*hgpt[m_idx],
        *heeta[m_idx], *hmeta[m_idx], *hjeta[m_idx], *hgeta[m_idx],
        *hephi[m_idx], *hmphi[m_idx], *hjphi[m_idx], *hmetphi[m_idx], *hjetm[m_idx], *hgphi[m_idx];
   TH1F *hlepq[m_idx];

   TH1F *hmet_err[m_idx],  *hjpt_err[m_idx],  *hept_err[m_idx],  *hmpt_err[m_idx],  *hgpt_err[m_idx],
        *heeta_err[m_idx], *hmeta_err[m_idx], *hjeta_err[m_idx], *hgeta_err[m_idx],
        *hephi_err[m_idx], *hgphi_err[m_idx], *hmphi_err[m_idx], *hjphi_err[m_idx], *hmetphi_err[m_idx], *hjetm_err[m_idx];

   TH1F *metx[m_idx], *mety[m_idx];
   TNtuple *rntuple;

};

#endif
