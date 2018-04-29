#ifndef __PRINTEFFICIENCIES_C
#define __PRINTEFFICIENCIES_C

#include <iomanip>
#include <TH1F.h>
#include <cmath>
#include <iostream>


void PrintEfficiencies(TH1F* effh) {
  using namespace std;

  // Prints out the efficiencies
  if (!effh) return;
  double eff, err;
  cout << "Based on " << effh->GetBinContent(2) << " events:\n";
  int s;
  for (s=2; s<=effh->GetNbinsX(); ++s) {
    if ( strlen(effh->GetXaxis()->GetBinLabel(s)) < 2) break;
    eff = effh->GetBinContent(s) / effh->GetBinContent(s-1);
    err = sqrt(eff*(1-eff)/effh->GetBinContent(s-1));
    cout << "Efficiency for " << setw(24) << effh->GetXaxis()->GetBinLabel(s)
	 << " = "  << setw(6) << setprecision(4) << eff
	 << " +- " << setw(9) << setprecision(4) << err 
         << setw(6) <<" evt: "<<setw(8)<< setprecision(10)<<effh->GetBinContent(s) <<endl; 
  }

  eff = effh->GetBinContent(s-1) / effh->GetBinContent(2);
  err = sqrt(eff*(1-eff)/effh->GetBinContent(2));
  cout << " --> Overall efficiency\t = "
       << setw(6) << setprecision(4) << eff*100.
       << " % +- " << setw(6) << setprecision(3) << err*100. << " %" <<endl; 
  return;
}

#endif
