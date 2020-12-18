#!/usr/bin/env python

# This python script is for comparing signal and background distributions from 2 different ROOT files.
from ROOT import *

# Let's start with setting some ROOT style parameters:
# You do not need to know what they mean, but can directly use these settings

gStyle.SetOptStat(0)
gStyle.SetPalette(1)

gStyle.SetTextFont(42)

gStyle.SetTitleStyle(0000)
gStyle.SetTitleBorderSize(0)
gStyle.SetTitleFont(42)
gStyle.SetTitleFontSize(0.055)

gStyle.SetTitleFont(42, "xyz")
gStyle.SetTitleSize(0.5, "xyz")
gStyle.SetLabelFont(42, "xyz")
gStyle.SetLabelSize(0.45, "xyz")

# Open the files with signal and bg histograms given by CutLang: 
fs = TFile("../runs/histoOut-VSOPSUSY_sg.root")
fb = TFile("../runs/histoOut-VSOPSUSY_bg.root")

# Get the histograms
# MET and HT histograms from the signal file
hmetsg = fs.Get("SR/hmet")
hhtsg = fs.Get("SR/hht")
# MET and HT histograms from the BG file
hmetbg = fb.Get("SR/hmet")
hhtbg = fb.Get("SR/hht")

# Our purpose in this exercise is to compare the shapes of signal and background distributions.
# To do this comparison best, the area integral under histograms being compared should be the same.
# Therefore we scale the hisgograms so that the area integral under the histograms equals 1. 
hmetsg.Scale(1./hmetsg.Integral())
hmetbg.Scale(1./hmetbg.Integral())
hhtsg.Scale(1./hhtsg.Integral())
hhtbg.Scale(1./hhtbg.Integral())

# Histogram style settings:
hmetsg.SetLineWidth(2)
hhtsg.SetLineWidth(2)
hmetbg.SetLineWidth(2)
hhtbg.SetLineWidth(2)

hmetsg.SetLineColor(600) # kBlue
hmetbg.SetLineColor(416+2) # kGreen + 2
hhtsg.SetLineColor(600) # kBlue
hhtbg.SetLineColor(416+2) # kGreen + 2

# Titles, labels.  
# Remember that it is enough to set these variables ONLY FOR THE FIRST HISTOGRAM YOU WILL DRAW
# i.e., the one you will call by .Draw().  The rest you will draw by .Draw("same") will only 
# contribute with the historam curve.
hmetbg.SetTitle("MET")
hmetbg.GetXaxis().SetTitle("MET (GeV)")
hmetbg.GetXaxis().SetTitleOffset(1.25)
hmetbg.GetXaxis().SetTitleSize(0.05)
hmetbg.GetXaxis().SetLabelSize(0.045)
hmetbg.GetXaxis().SetNdivisions(8, 5, 0)
hmetbg.GetYaxis().SetTitle("number of events")
hmetbg.GetYaxis().SetTitleOffset(1.4)
hmetbg.GetYaxis().SetTitleSize(0.05)
hmetbg.GetYaxis().SetLabelSize(0.045)

hhtbg.SetTitle("HT")
hhtbg.GetXaxis().SetTitle("HT (GeV)")
hhtbg.GetXaxis().SetTitleOffset(1.25)
hhtbg.GetXaxis().SetTitleSize(0.05)
hhtbg.GetXaxis().SetLabelSize(0.045)
hhtbg.GetXaxis().SetNdivisions(8, 5, 0)
hhtbg.GetYaxis().SetTitle("number of events")
hhtbg.GetYaxis().SetTitleOffset(1.4)
hhtbg.GetYaxis().SetTitleSize(0.05)
hhtbg.GetYaxis().SetLabelSize(0.045)

# Make a generically usable legend
l = TLegend(0.65, 0.75, 0.88, 0.87)
l.SetBorderSize(0)
l.SetFillStyle(0000)
l.AddEntry(hmetsg,"signal", "l")
l.AddEntry(hmetbg,"BG", "l")

# Make a dedicated canvas
cmet = TCanvas("cmet", "cmet", 620, 500)
cmet.SetBottomMargin(0.15)
cmet.SetLeftMargin(0.15)
cmet.SetRightMargin(0.15)
# Draw the histograms and the legend
# Make sure you draw the background before the signal
hmetbg.Draw()
hmetsg.Draw("same")
l.Draw("same")
cmet.Draw()
cmet.Print("hmetsgbg.pdf")

# Make a dedicated canvas
cht = TCanvas("cht", "cht", 620, 500)
cht.SetBottomMargin(0.15)
cht.SetLeftMargin(0.15)
cht.SetRightMargin(0.15)
# Draw the histograms and the legend
# Make sure you draw the background before the signal
hhtbg.Draw()
hhtsg.Draw("same")
l.Draw("same")
cht.Draw()
cht.Print("hhtsgbg.pdf")
