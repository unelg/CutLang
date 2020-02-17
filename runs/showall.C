void showall(TString regname="preselection", TString inpfile="histoOut-e6new.root" )
{

  using namespace std;

  vector<TString> histo;
  vector<TString> cift;
  vector<TString> tek;
  vector<TString> trip;
  vector<TString> quad;
  vector<TString> fifth;
    
  string word;
    
  histo.clear();
  ifstream infile("histoname.txt");

  while (infile >> word) {
    histo.push_back(word);
  }
/*
    for (unsigned n=0; n<histo.size(); ++n) {
        cout << histo.at( n ) << " ";
    }
*/    
  for (unsigned k=0; k<histo.size(); ++k) {
    TString endch = histo.at(k) ;
    char lastChar = endch( endch.Length() - 1 );
    //        cout << lastChar <<endl;
    if(lastChar == '2')
      {
	cift.push_back(endch);
      }else if(lastChar == '3')
      {
	trip.push_back(endch);
      }else if(lastChar == '4')
      {
	quad.push_back(endch);
      }else if(lastChar == '5')
      {
	fifth.push_back(endch);
      }else if(lastChar == '1')
      {
	tek.push_back(endch);
      }
        
  } // end loop over k

  TFile *_file0 = TFile::Open(inpfile);
  _file0->cd(regname);
    
  TCanvas *c1=new TCanvas("c1","CutLang histogramming example",200,10,700,500);
  gStyle->SetOptStat(1);
  gStyle->SetOptTitle(0);
  /*
    c1->SetFillColor(42);
    c1->GetFrame()->SetFillColor(21);
    c1->GetFrame()->SetBorderSize(6);
    c1->GetFrame()->SetBorderMode(-1);
  */

  double bmargin = 0.15;
  double lmargin = 0.15;

  if(tek.size() == 1)
    {
      c1->Divide(1,1);
    }
  else if (tek.size() == 2)
    {
      c1->Divide(1,2);
    }
  else if (tek.size() <= 4)
    {
      c1->Divide(2,2);
    }
  else if(tek.size() <= 6)
    {
      c1->Divide(2,3);
    }
  else if(tek.size() <= 9)
    {
      c1->Divide(3,3);
    }
  else if(tek.size() <= 12)
    {
      c1->Divide(3,4);
    }
  else if(tek.size() <= 16)
    {
      c1->Divide(4,4);
    }
    
  vector<TH1F*> vlist;
  TH1F *h, *h2, *h3, *h4, *h5;      // single

  double legxmin = 0.60;
  double legxmax = 0.83;
  double legymin = 0.80;
  double legymax = 0.85;
  double legystp = 0.07;
   
  cout <<"Tek:"<<tek.size()<<" Cift:"<<cift.size()<<"\n";
 
  for (unsigned int c=0;c<tek.size();c++)
    {
      h = (TH1F*)gROOT->FindObject(tek.at(c))->Clone();
      if (h==0) cout << "I couldn't find " << tek.at(c) << endl;
      vlist.push_back(h);
    }
    
  for (unsigned int c=0;c<tek.size();c++) {
    c1->cd(c+1);
    c1->cd(c+1)->SetBottomMargin(bmargin);
    c1->cd(c+1)->SetLeftMargin(lmargin);

    cout  << " drawing at " << c << " " << tek.at(c) << " " << vlist.at(c)->GetTitle() << endl;

    vlist.at(c)->SetLineColor(1);
    vlist.at(c)->GetXaxis()->SetTitle(vlist.at(c)->GetTitle() );
    vlist.at(c)->GetXaxis()->CenterTitle();
    vlist.at(c)->GetXaxis()->SetTitleOffset(1.1);
    vlist.at(c)->GetXaxis()->SetTitleSize(0.055);
    vlist.at(c)->GetXaxis()->SetTitleFont(42);
    vlist.at(c)->GetXaxis()->SetLabelOffset(0.012);
    vlist.at(c)->GetXaxis()->SetLabelSize(0.050);
    vlist.at(c)->GetXaxis()->SetLabelFont(42);
    vlist.at(c)->GetYaxis()->SetTitle("Number of events");
    vlist.at(c)->GetYaxis()->CenterTitle();
    vlist.at(c)->GetYaxis()->SetTitleOffset(1.28);
    vlist.at(c)->GetYaxis()->SetTitleSize(0.055);
    vlist.at(c)->GetYaxis()->SetLabelOffset(0.012);
    vlist.at(c)->GetYaxis()->SetLabelSize(0.050);
    vlist.at(c)->GetYaxis()->SetLabelFont(42);
    vlist.at(c)->GetYaxis()->SetTitleFont(42);

    vlist.at(c)->Draw();
    cout <<"done\n";    
    
    TLegend *l1 = new TLegend(legxmin, legymin, legxmax, legymax);
    l1->SetBorderSize(0);
    l1->SetFillStyle(0000);
    l1->SetTextSize(0.050);
    l1->SetTextFont(42);
    l1->AddEntry(vlist.at(c), vlist.at(c)->GetName(), "l");
    l1->Draw("same");
    cout <<"done label\n";    

    for (unsigned l=0; l<cift.size(); ++l)
      {
	TString strg = tek.at(c) ;
	if(strncmp (tek.at(c),cift.at(l),(strg.Length() - 1 )) == 0)
	  {
	    h2 = (TH1F*)gROOT->FindObject(cift.at(l));
	    h2->SetLineColor(2);
	    h2->Draw("SAME");

	    TLegend *l2 = new TLegend(legxmin, legymin-legystp, legxmax, legymax-legystp);
	    l2->SetBorderSize(0);
	    l2->SetFillStyle(0000);
	    l2->SetTextSize(0.050);
	    l2->SetTextFont(42);
	    l2->AddEntry(h2, h2->GetName(), "l");
	    l2->Draw("same");
	  }
      }
   cout <<"cift done\n";
    for (unsigned d=0; d<trip.size(); ++d)
      {
	TString strg2 = tek.at(c) ;
	if(strncmp (tek.at(c),trip.at(d), (strg2.Length() - 1)) == 0)
	  {
	    h3 = (TH1F*)gROOT->FindObject(trip.at(d));
	    h3->SetLineColor(3);
	    h3->Draw("SAME");
	       
	    TLegend *l3 = new TLegend(legxmin, legymin-2*legystp, legxmax, legymax-2*legystp);
	    l3->SetBorderSize(0);
	    l3->SetFillStyle(0000);
	    l3->SetTextSize(0.050);
	    l3->SetTextFont(42);
	    l3->AddEntry(h3, h3->GetName(), "l");
	    l3->Draw("same");
	  }
      }
   cout <<"trip done\n";
    for (unsigned s=0; s<quad.size(); ++s)
      {
	TString strg3 = tek.at(c) ;
	if(strncmp (tek.at(c),quad.at(s), (strg3.Length() - 1)) == 0)
	  {
	    h4 = (TH1F*)gROOT->FindObject(quad.at(s));
	    h4->SetLineColor(4);
	    h4->Draw("SAME");

	    TLegend *l4 = new TLegend(legxmin, legymin-3*legystp, legxmax, legymax-3*legystp);
	    l4->SetBorderSize(0);
	    l4->SetFillStyle(0000);
	    l4->SetTextSize(0.050);
	    l4->SetTextFont(42);
	    l4->AddEntry(h3, h3->GetName(), "l");
	    l4->Draw("same");
	  }
      }
   cout <<"quad done\n";
    for (unsigned z=0; z<fifth.size(); ++z)
      {
	TString strg4 = tek.at(c) ;
	if(strncmp (tek.at(c),fifth.at(z), (strg4.Length() - 1)) == 0)
	  {
	    h5 = (TH1F*)gROOT->FindObject(fifth.at(z));
	    h5->SetLineColor(3);
	    h5->SetTitle("");
	    h5->Draw("SAME");

	    TLegend *l5 = new TLegend(legxmin, legymin-4*legystp, legxmax, legymax-4*legystp);
	    l5->SetBorderSize(0);
	    l5->SetFillStyle(0000);
	    l5->SetTextSize(0.050);
	    l5->SetTextFont(42);
	    l5->AddEntry(h4, h4->GetName(), "l");
	    l5->Draw("same");
	  }
      }
	
  }// end of loop for 1s                
  cout <<" end of loop\n";  
                
  c1->Modified();
  c1->Update();
//  gSystem->ProcessEvents();
  TString pricanvas="all_";
          pricanvas+=regname;
          pricanvas+=".pdf";
  c1->SaveAs(pricanvas);
  c1->Modified();
  cout << "end of sw\n";   
}
