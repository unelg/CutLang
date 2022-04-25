#ifndef __CALCULATECHISQUARE_C
#define __CALCULATECHISQUARE_C
#include <iostream>
#include <iomanip>
#include <TH1F.h>
#include <cmath>

float CalculateChiSquare(TH1F* mc, TH1F* data) {
  using namespace std;

  if (!data) return -1.;
  double eff, err;
  float chisq=0.0;
  float d,m,e;
  int ndp=0;

  for (int s=1; s<=data->GetNbinsX(); ++s) {
    d = data->GetBinContent(s) ;
    e = data->GetBinError(s) ;
    m = mc->GetBinContent(s) ;
#ifdef __DEBUG_CHI2__
     cout << "d:"<<d<<" +-:"<<e<<"  m:"<<m<<endl;
#endif
    if ((m>0) && (e>0) ) {
     chisq+=(d-m)*(d-m)/e/e;
     ndp++;
    } 
  }

  cout << "=> Chi Square = " << setw(6) << setprecision(4) << chisq ;
  cout << " \tNDF = " << setw(3) << setprecision(4) <<  ndp;
  cout << " \tChi Square/NDF = " << setw(6) << setprecision(4) << sqrt(chisq)/ndp <<endl;
  return sqrt(chisq)/ndp;
}
#endif
