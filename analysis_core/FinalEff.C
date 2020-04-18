// Prints Efficiency table of a root file
#include "FinalEff.h"

using namespace std;

//void PrintEfficiencies(TH1F* effh, bool skip_histos);
void FinalEff(TString file_addr,TString bpi, bool sh, bool se){
  if(se) return 0;  // skips efficiencies
  TFile *rootFile = TFile::Open(file_addr);
  //cout<<"Opened file at "<<file_addr<<endl;
  
  TIter next(rootFile->GetListOfKeys());
  TKey *key;
  while ((key = (TKey*)next())) {
    cout<<endl;
     TClass *cl = gROOT->GetClass(key->GetClassName());
     if (cl->InheritsFrom("TDirectoryFile")) {
       TString nm = key->GetName();
       TH1D *ee;
       rootFile->GetObject(nm+"/cutflow",ee);
       Int_t NBins = ee->GetNbinsX();
       TH1D *bc;
       rootFile->GetObject(nm+"/bincounts",bc);
       if(ee){
         for (Int_t i=1;i<=NBins;i++) {
           TString s = ee->GetXaxis()->GetBinLabel(i);
           if (s.BeginsWith("[Histo]")){
             ee->SetBinContent(i,ee->GetBinContent(i-1));
           }
         }
         cout <<"Efficiencies for analysis : "<< bpi <<endl;
         cout <<"\t\t\t\t\t\t"<<nm<<"\t";
         PrintEfficiencies(ee,sh);
         cout <<"Bins for analysis : "<< bpi <<endl;
         if(bc){
           cout <<setprecision(6);
           for (int ii=0; ii<bc->GetNbinsX(); ii++) std::cout<<"\t\t\t\t\t\tBin:"<<ii<<" has:"<< bc->GetBinContent(ii+1)<<" events\n";
         }
        }
     }
   }
   return;
}
