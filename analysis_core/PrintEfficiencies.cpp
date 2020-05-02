#ifndef __PRINTEFFICIENCIES_C
#define __PRINTEFFICIENCIES_C

#include <iomanip>
#include <TH1F.h>
#include <cmath>
#include <iostream>


void PrintEfficiencies(TH1D* effh, bool skip_histos) {
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

void ComputeEfficiences(TH1D *eff1, double xsec1, TH1F *eff2, double xsec2) {
  using namespace std;

  // Compute and print out efficiencies by combining two separate samples
  if (!eff1 || !eff2) return;
  if (eff1->GetNbinsX() != eff2->GetNbinsX()) return;

  cout << "Based on " << eff1->GetBinContent(2) << " events with xsec="
       << xsec1 << " and " << eff2->GetBinContent(2)
       << " events with xsec=" << xsec2 << endl;

  double eff(0), before(1), after(0);

   for (int s=2; s<=eff1->GetNbinsX(); ++s) {
     before = xsec1 * eff1->GetBinContent(s-1) / eff1->GetBinContent(2)
            + xsec2 * eff2->GetBinContent(s-1) / eff2->GetBinContent(2);
     after  = xsec1 * eff1->GetBinContent(s) / eff1->GetBinContent(2)
            + xsec2 * eff2->GetBinContent(s) / eff2->GetBinContent(2);
     eff = after / before;
     cout << "Efficiency for " << eff1->GetXaxis()->GetBinLabel(s) << "\t = "
	  << setw(6) << setprecision(4) << eff << endl; }

   eff = after / (xsec1+xsec2);
   cout << " --> Overall efficiency\t = "
	<< setw(6) << setprecision(4) << eff*100. << endl;
   return;
}
#endif
