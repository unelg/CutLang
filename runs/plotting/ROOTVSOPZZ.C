// This C script is for checking ZZ histograms.
// This C script is for comparing signal and background distributions from 2 different ROOT files.

// Let's start with setting some ROOT style parameters:
// You do not need to know what they mean, but can directly use these settings
{
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

// Open the files with signal and bg histograms given by CutLang:
TFile f("histoOut-VSOPZZ.root");

// Get the histograms
// Overview region:
TH1D* hneinp = (TH1D*)f.Get("overview/hneinp");
TH1D* hnminp = (TH1D*)f.Get("overview/hnminp");
TH1D* hnesel = (TH1D*)f.Get("overview/hnesel");
TH1D* hnmsel = (TH1D*)f.Get("overview/hnmsel");
TH2D* hnenminp = (TH2D*)f.Get("overview/hnenminp");
TH2D* hnenmsel = (TH2D*)f.Get("overview/hnenmsel");

// Zeeinp region
TH1D* hZeeinp = (TH1D*)f.Get("Zeeinp/hZeeinp");
// Zeesel region
TH1D* hZeesel = (TH1D*)f.Get("Zeesel/hZeesel");
// Zmminp region
TH1D* hZmminp = (TH1D*)f.Get("Zmminp/hZmminp");
// Zmmsel region
TH1D* hZmmsel = (TH1D*)f.Get("Zmmsel/hZmmsel");
// Zeemminp region
TH1D* hZeeinp2 = (TH1D*)f.Get("Zeemminp/hZeeinp");
TH1D* hZmminp2 = (TH1D*)f.Get("Zeemminp/hZmminp");
TH2D* hZeemminp = (TH2D*)f.Get("Zeemminp/hZeemminp");
// Zeemmsel region
TH1D* hZeesel2 = (TH1D*)f.Get("Zeemmsel/hZeesel");
TH1D* hZmmsel2 = (TH1D*)f.Get("Zeemmsel/hZmmsel");
TH2D* hZeemmsel = (TH2D*)f.Get("Zeemmsel/hZeemmsel");

// In order to be able to make many plots, let's define two generic histogrms to which we can
// assign any of the histograms above:
TH1D* h1 = (TH1D*)hnesel->Clone();
TH1D* h2 = (TH1D*)hnmsel->Clone();

// Our purpose in this exercise is to compare the shapes of signal and background distributions.
// To do this comparison best, the area integral under histograms being compared should be the same.
// Therefore we scale the hisgograms so that the area integral under the histograms equals 1.
//h1.Scale(1./hmet1.Integral())
//h2.Scale(1./hmet2.Integral())

// Histogram style settings:
h1->SetLineWidth(2);
h2->SetLineWidth(2);

h1->SetLineColor(600); // kBlue
h2->SetLineColor(416+2); // kGreen + 2

// Titles, labels.
// Remember that it is enough to set these variables ONLY FOR THE FIRST HISTOGRAM YOU WILL DRAW
// i.e., the one you will call by .Draw().  The rest you will draw by .Draw("same") will only
// contribute with the historam curve.
//h1.SetTitle()
//h1.GetXaxis().SetTitle("x")
title = h1->GetTitle();
h1->GetXaxis()->SetTitle(title);
h1->GetXaxis()->SetTitleOffset(1.25);
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.045);
h1->GetXaxis()->SetNdivisions(8, 5, 0);
h1->GetYaxis()->SetTitle("number of events");
h1->GetYaxis()->SetTitleOffset(1.4);
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetLabelSize(0.045);

// Make a generically usable legend
TLegend l(0.65, 0.75, 0.88, 0.87);
l.SetBorderSize(0);
l.SetFillStyle(0000);
// You can change the legend titles from here based on what you are plotting
l.AddEntry(h1,h1->GetName(), "l");
l.AddEntry(h2,h2->GetName(), "l");

// Plot and display MET
// Make a dedicated canvas
TCanvas c("c", "c", 620, 500);
c.SetBottomMargin(0.15);
c.SetLeftMargin(0.15);
c.SetRightMargin(0.15);
// Draw the histograms and the legend
// Make sure you draw the background before the signal
h1->Draw();
h2->Draw("same");
l.Draw("same");
c.Draw();
c.Print("ZZ_c.pdf");

// We need a different canvas for the new histogram
TCanvas c2("c2", "c2", 620, 500);
c2.SetBottomMargin(0.15);
c2.SetLeftMargin(0.15);
c2.SetRightMargin(0.15);
hZeemmsel->Draw("colz");
c2.Draw();
c2.Print("ZZ_c2.pdf");

}
