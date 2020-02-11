#ifndef FINALEFF_H
#define FINALEFF_H
#include "TH1.h"

#include <iomanip>
#include <TH1F.h>
#include <cmath>
#include <iostream>


void PrintEfficiencies(TH1F* effh, bool skip_histos) {
  using namespace std;

  // Prints out the efficiencies
  if (!effh) return;
  double eff, err;
  cout << "Based on " << effh->GetBinContent(2) << " events:\n";

  int s;
  for (s=2; s<=effh->GetNbinsX(); ++s) {
    eff = effh->GetBinContent(s) / effh->GetBinContent(s-1);
    err = sqrt(eff*(1-eff)/effh->GetBinContent(s-1));
    TString cutname=effh->GetXaxis()->GetBinLabel(s);
    if ( cutname.Sizeof() <1) break;
    if (skip_histos) { if ( cutname.BeginsWith("[Histo]") ) continue; }
    cout << setw(66) << effh->GetXaxis()->GetBinLabel(s)
	 << " : "  << setw(6) << setprecision(4) << eff
	 << " +- " << setw(9) << setprecision(3) << err 
         << setw(6) <<" evt: "<<setw(8)<< setprecision(10)<<effh->GetBinContent(s) <<endl; 
  }
  eff = effh->GetBinContent(s-1) / effh->GetBinContent(2);
  err = sqrt(eff*(1-eff)/effh->GetBinContent(2));
  cout << "\t\t\t\t\t --> Overall efficiency\t = "
       << setw(6) << setprecision(3) << eff*100.
       << " % +- " << setw(6) << setprecision(3) << err*100. << " %" <<endl; 
  return;
}


void FinalEff(TString file_addr, bool sh, bool se);
#endif // FINALEFF_H
