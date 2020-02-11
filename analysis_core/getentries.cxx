// Gets number of entries from root file to use in parallel analysis
// call by root -l -q 'getentries.cxx($diraddr , &treeaddr)'

int getentries(TString diraddr, TString treeaddr){
  TFile *rf = TFile::Open(diraddr);
  TTree *tt;
  rf->GetObject(treeaddr,tt);
 int evtnum = tt->GetEntriesFast();
 return evtnum;
 exit;
}
//~/Downloads/Data/Data_15.root physics/nominal
