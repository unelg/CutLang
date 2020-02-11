// Prints Efficiency table of a root file
#include "FinalEff.h"

using namespace std;

//void PrintEfficiencies(TH1F* effh, bool skip_histos);
void FinalEff(TString file_addr, bool sh, bool se){
  if(se) return;  // skips efficiencies
  TFile *rootFile = TFile::Open(file_addr);
  cout<<"Opened file at "<<file_addr<<endl;
  TIter next(rootFile->GetListOfKeys());
  TKey *key;
  cout<<"Efficiency table of combined file:"<<endl;
  while ((key = (TKey*)next())) {
    cout<<endl;
     TClass *cl = gROOT->GetClass(key->GetClassName());
     if (cl->InheritsFrom("TDirectoryFile")) {
       TString nm = key->GetName();
       TH1F *ee;
       rootFile->GetObject(nm+"/eff",ee);
       cout <<"\t\t\t\t\t\t"<<nm<<"\t";
       PrintEfficiencies(ee,sh);
     }
   }
   return;
}
