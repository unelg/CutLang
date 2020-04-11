#ifndef ANALYSIS_CORE_H
#define ANALYSIS_CORE_H
#include "TH1.h"

// This is the header file to define the interfaces of the various minor pieces of code that resides
//   in the analysis_core directory.

bool isGoodRun(int,int);
TString operator+(const TString &s, Float_t f);
//std::string operator*=(const std::string &s, const std::string &s2){return s;}
void PrintEfficiencies(TH1D* effh, bool skip_hist=false);
TString operator+(const TString &s, Float_t f);

/*
Int_t TNamed::Merge(TCollection *in){
 
  TIter nxo(in);
  Int_t n = 0;
  while (TObject *o = nxo()) {
     TNamed *c = dynamic_cast<TNamed *>(o);
      if (c) {
       fVal = c->GetVal();
       n++;
      }
   }
 return n;
}

*/

#endif // ANALYSIS_CORE_H
