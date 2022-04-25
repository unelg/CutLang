void pricontents (TH1F * h) {

int nb=h->GetNbinsX();
float tot=0.;


 for (int i=1; i<=nb; i++) {
  tot+=h->GetBinContent(i);
 }

 cout << "total is:"<<tot<<endl;

}
