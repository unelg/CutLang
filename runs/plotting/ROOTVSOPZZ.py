#!/usr/bin/env python

# This notebook is for checking ZZ histograms.
# Using python
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
f = TFile("histoOut-VSOPZZ.root")

# Get the histograms
# Overview region:
hneinp = f.Get("overview/hneinp")
hnminp = f.Get("overview/hnminp")
hnesel = f.Get("overview/hnesel")
hnmsel = f.Get("overview/hnmsel")
hnenminp = f.Get("overview/hnenminp")
hnenmsel = f.Get("overview/hnenmsel")

# Zeeinp region
hZeeinp = f.Get("Zeeinp/hZeeinp")
# Zeesel region
hZeesel = f.Get("Zeesel/hZeesel")
# Zmminp region
hZmminp = f.Get("Zmminp/hZmminp")
# Zmmsel region
hZmmsel = f.Get("Zmmsel/hZmmsel")
# Zeemminp region
hZeeinp2 = f.Get("Zeemminp/hZeeinp")
hZmminp2 = f.Get("Zeemminp/hZmminp")
hZeemminp = f.Get("Zeemminp/hZeemminp")
# Zeemmsel region
hZeesel2 = f.Get("Zeemmsel/hZeesel")
hZmmsel2 = f.Get("Zeemmsel/hZmmsel")
hZeemmsel = f.Get("Zeemmsel/hZeemmsel")

# In order to be able to make many plots, let's define two generic histogrms to which we can 
# assign any of the histograms above:
h1 = hnesel
h2 = hnmsel

# Our purpose in this exercise is to compare the shapes of signal and background distributions.
# To do this comparison best, the area integral under histograms being compared should be the same.
# Therefore we scale the hisgograms so that the area integral under the histograms equals 1. 
#h1.Scale(1./hmet1.Integral())
#h2.Scale(1./hmet2.Integral())

# Histogram style settings:
h1.SetLineWidth(2)
h2.SetLineWidth(2)

h1.SetLineColor(600) # kBlue
h2.SetLineColor(416+2) # kGreen + 2

# Titles, labels.  
# Remember that it is enough to set these variables ONLY FOR THE FIRST HISTOGRAM YOU WILL DRAW
# i.e., the one you will call by .Draw().  The rest you will draw by .Draw("same") will only 
# contribute with the historam curve.
#h1.SetTitle()
#h1.GetXaxis().SetTitle("x")
title = h1.GetTitle()
print(title)
h1.GetXaxis().SetTitle(title)
h1.GetXaxis().SetTitleOffset(1.25)
h1.GetXaxis().SetTitleSize(0.05)
h1.GetXaxis().SetLabelSize(0.045)
h1.GetXaxis().SetNdivisions(8, 5, 0)
h1.GetYaxis().SetTitle("number of events")
h1.GetYaxis().SetTitleOffset(1.4)
h1.GetYaxis().SetTitleSize(0.05)
h1.GetYaxis().SetLabelSize(0.045)

# Make a generically usable legend
l = TLegend(0.65, 0.75, 0.88, 0.87)
l.SetBorderSize(0)
l.SetFillStyle(0000)
# You can change the legend titles from here based on what you are plotting
l.AddEntry(h1,h1.GetName(), "l")
l.AddEntry(h2,h2.GetName(), "l")

# Plot and display MET
# Make a dedicated canvas
c = TCanvas("c", "c", 620, 500)
c.SetBottomMargin(0.15)
c.SetLeftMargin(0.15)
c.SetRightMargin(0.15)
# Draw the histograms and the legend
# Make sure you draw the background before the signal
h1.Draw()
h2.Draw("same")
l.Draw("same")
c.Draw()
c.Print("ZZ_c.pdf")

# We need a different canvas for the new histogram
c2 = TCanvas("c2", "c2", 620, 500)
c2.SetBottomMargin(0.15)
c2.SetLeftMargin(0.15)
c2.SetRightMargin(0.15)
hZeemmsel.Draw("colz")
c2.Draw()
c2.Print("ZZ_c2.pdf")

