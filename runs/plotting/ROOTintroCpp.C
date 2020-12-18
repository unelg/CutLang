{
  // Let's start with setting some ROOT style parameters:
  // You do not need to know what they mean, but can directly use these settings
  
  gStyle->SetOptStat(kFALSE);
  gStyle->SetPalette(1);
  
  gStyle->SetTextFont(42);
  
  gStyle->SetTitleStyle(0000);
  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleFontSize(0.055);
  
  gStyle->SetTitleFont(42, "xyz");
  gStyle->SetTitleSize(0.5, "xyz");
  gStyle->SetLabelFont(42, "xyz");
  gStyle->SetLabelSize(0.45, "xyz");

  // We are currently in the CutLang/binder directory.  Let's move to the CutLang/runs directory:
  gSystem->cd("../runs/");
  // Let's open the histoOut-exHistos.root file 
  TFile f("histoOut-exHistos.root");
  // Let's see what is in there
  f.ls();

  // There is a ROOT directory (TDirectory) called presel.
  // Let's go inside
  f.cd("presel");
  // ... and// There is a ROOT directory (TDirectory) called presel.
  // Let's go inside
  f.cd("presel");
  // ... and check what is there
  f.ls();
    
  /* 
     There are lots of histograms in the presel directory.  
     Some of them are 1-dimensional (TH1D), which have only one variable.
     Here, the histograms hjet1pt, hjet2pt, hjet3pt, hjet4pt are plotting the transverse moementa of the 1st, 2nd, 3rd and 4th jet in the events.
     We will plot these histograms on top of each other.
     Those histograms can be accessed with their names.  In C++, they are pointer.
     There is also a 2-dimensional histogram hmetjet1pt.  We will get to that one shortly. 
  */
  
  // We start with setting the style of the histograms.
  // Let's increase the line width of the histograms.
  hjet1pt->SetLineWidth(2);
  hjet2pt->SetLineWidth(2);
  hjet3pt->SetLineWidth(2);
  hjet4pt->SetLineWidth(2);
  
  // Now let's set the colors.
  // Information about ROOT colors: https://root.cern.ch/doc/master/classTColor.html
  // Set the histogram line color:
  hjet1pt->SetLineColor(616+1); // kMagenta + 1
  hjet2pt->SetLineColor(600); // kBlue
  hjet3pt->SetLineColor(632+1); // kRed + 1
  hjet4pt->SetLineColor(416+2); // kGreen + 2

  // Set the histogram fill color:
  hjet1pt->SetFillColor(616+1); // kMagenta + 1
  hjet2pt->SetFillColor(600); // kBlue
  hjet3pt->SetFillColor(632+1); // kRed + 1
  hjet4pt->SetFillColor(416+2); // kGreen + 2
  
  // Let's get even more fancy and fill "in style"
  // https://root.cern.ch/root/html528/TMarker.html
  hjet1pt->SetFillStyle(3003);
  hjet2pt->SetFillStyle(3003);
  hjet3pt->SetFillStyle(3003);
  hjet4pt->SetFillStyle(3003);
  
  // One can also plot markers with different styles, but we won't do it here.
  // https://root.cern.ch/root/html528/TMarker.html
  
  // Set the histogram title
  hjet4pt->SetTitle("Jet p_{T}");
  // Set the x-axis title and font properties
  hjet4pt->GetXaxis()->SetTitle("p_{T} (GeV)");
  hjet4pt->GetXaxis()->SetTitleOffset(1.25);
  hjet4pt->GetXaxis()->SetTitleSize(0.05);
  hjet4pt->GetXaxis()->SetLabelSize(0.045);
  hjet4pt->GetXaxis()->SetNdivisions(8, 5, 0);
  // Set the y-axis title and font properties
  hjet4pt->GetYaxis()->SetTitle("number of events");
  hjet4pt->GetYaxis()->SetTitleOffset(1.4);
  hjet4pt->GetYaxis()->SetTitleSize(0.05);
  hjet4pt->GetYaxis()->SetLabelSize(0.045);

  // To plot our histogram, we first need a canvas.
  TCanvas c1("c1", "c1", 620, 500);
  // ... and we need to make wide margins for all the axis titles to fit in:
  c1.SetBottomMargin(0.15);
  c1.SetLeftMargin(0.15);
  c1.SetRightMargin(0.15);

  // Now we can plot the histograms.  We start with the distribution which has the highest y-axis value, so everything can fit into the frame.
  // If you want to understand this better, you can start with drawing hjet1pt, then the others
  hjet4pt->Draw();
  hjet3pt->Draw("same");
  hjet2pt->Draw("same");
  hjet1pt->Draw("same");
  // The histogram will be drawn on the TCanvas c1.  Now we can draw the canvas:
  c1.Draw();
  
  // In order the see which histogram corresponds to which distribution, we need a legend.
  // This is how we make one:
  TLegend l1(0.65, 0.67, 0.88, 0.87);
  l1.SetBorderSize(0);
  l1.SetFillStyle(0000);
  l1.AddEntry(hjet1pt,"jet 1 p_{T}", "f");
  l1.AddEntry(hjet2pt,"jet 2 p_{T}", "f");
  l1.AddEntry(hjet3pt,"jet 3 p_{T}", "f");
  l1.AddEntry(hjet4pt,"jet 4 p_{T}", "f");
  l1.Draw("same");

  // We re-draw the canvas c1 in order to see the legend:
  c1.Draw();
  // Let's save c1 as a pdf file
  c1.Print("hjetpt.pdf");

  // Now let's take the 2D histogram hmetjet1pt.  It shows missing transverse energy versus the 1st jet pT.
  // Let's set the axis titles.
  hmetjet1pt->GetXaxis()->SetTitle("MET (GeV)");
  hmetjet1pt->GetYaxis()->SetTitle("jet 1 p_{T} (GeV)");
  hmetjet1pt->GetZaxis()->SetTitle("number of events");

  // We need a different canvas for the new histogram
  TCanvas c2("c2", "c2", 620, 500);
  c2.SetBottomMargin(0.15);
  c2.SetLeftMargin(0.15);
  c2.SetRightMargin(0.15);
  
  // Let's draw the histogram.  The colz option draws the histogram with the nice colors and the z-axis bar.
  // You can learn about drawing options from https://root.cern/doc/master/classTHistPainter.html
  // and perhaps try a few for fun
  hmetjet1pt->Draw("colz");
  // As usual, we need to draw the canvas separately
  c2.Draw();
  // Let's save c2 as a pdf file
  c2.Print("hmetjet1pt.pdf");

}
