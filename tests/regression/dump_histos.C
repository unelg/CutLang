// dump_histos.C: every histogram of every region of a CutLang output file as text, sorted by name.
// The ref_ regions added by run_regression_tests.sh are skipped (they only save the event lists).
// Per histogram: "histo <region>/<name> dim <d> entries <n>", one "axis" line per dimension with the bin
// edges, and one "bins" line with content and error of every bin (under- and overflow included).
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include "TFile.h"
#include "TH1.h"
#include "TSystem.h"

static std::set<std::string> key_names(TDirectory* d) {
  std::set<std::string> names;   // a key can appear in several cycles; Get() returns the latest
  for (TObject* k : *d->GetListOfKeys()) names.insert(k->GetName());
  return names;
}

void dump_histos(const char* in, const char* out) {
  TFile f(in);
  if (f.IsZombie()) { std::cerr << "cannot open " << in << "\n"; gSystem->Exit(1); }
  std::ofstream o(out);
  o << std::setprecision(10);
  for (const std::string& region : key_names(&f)) {
    TDirectory* d = dynamic_cast<TDirectory*>(f.Get(region.c_str()));
    if (!d || region.rfind("ref_", 0) == 0) continue;
    for (const std::string& name : key_names(d)) {
      TH1* h = dynamic_cast<TH1*>(d->Get(name.c_str()));
      if (!h) continue;
      o << "histo " << region << "/" << name << " dim " << h->GetDimension()
        << " entries " << h->GetEntries() << "\n";
      TAxis* axes[3] = {h->GetXaxis(), h->GetYaxis(), h->GetZaxis()};
      for (int a = 0; a < h->GetDimension(); ++a) {
        o << "axis " << axes[a]->GetNbins();
        for (int i = 1; i <= axes[a]->GetNbins() + 1; ++i) o << " " << axes[a]->GetBinLowEdge(i);
        o << "\n";
      }
      o << "bins";
      for (int i = 0; i < h->GetNcells(); ++i) o << " " << h->GetBinContent(i) << " " << h->GetBinError(i);
      o << "\n";
    }
  }
}
