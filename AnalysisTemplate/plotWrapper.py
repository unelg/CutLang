import re
import ROOT
from os import listdir
from os.path import exists,isfile
import numpy as np

resdir = input('Give results directory with all root files (default: ./results/): ')
if resdir:
    resdir = resdir
else:
    resdir = './results/'
    
if not exists(resdir):
    msg = 'Results directory ('+resdir+') not found!'
    print(msg)

bgdir = 'backgrounds/'
sigdir = 'signals/'
datadir = 'data/'
dirs = [sigdir,bgdir,datadir]
datas = []

for i in range(len(dirs)):
    ddir = resdir+dirs[i]
    if not exists(ddir):
        msg = 'Directory '+ddir+' not found!'
        print(msg)
        datas.append([])
    else:
        datas.append(listdir(ddir))

print(datas)        

print('***************** Filling signal histograms ******************')

import uproot
paths = []
for d in datas[0]:
    paths.append(resdir+sigdir+d)

# c4 = ROOT.TCanvas("c", "c", 600,500)
mll = ROOT.THStack("hs","Stacked histos, signal")
leg = ROOT.TLegend(0.65,0.6,0.9,0.9)
leg.SetHeader("Mass points")

colors = [ROOT.kBlue,ROOT.kRed,ROOT.kBlack,ROOT.kYellow,ROOT.kMagenta,ROOT.kSpring,ROOT.kAzure,ROOT.kPink]
for pi in range(len(paths)):
    # print("Filling from file",paths[pi])
    f = uproot.open(paths[pi])
    tthist = f['twotaus/HppReco']
    freq = tthist.to_numpy()[0]
    bins = tthist.to_numpy()[1]
    vals = []
    for i in range(len(freq)):
        for hits in range(int(freq[i])):
            vals.append(bins[i])
    h = ROOT.TH1F("hist","hist",64,0,1000)
    for i in vals:
        h.Fill(i)
    h.SetLineColor(colors[pi])
    num = re.search(r'\d+', paths[pi]).group(0)
    legname = str(num)+' GeV'
    leg.AddEntry(h,legname,"l")
    mll.Add(h)
    
    del h
# print(leg)    
# mll.Add(leg)
mll.Draw()
input("Press any button to continue")
leg.Draw("SAME")
# c4.BuildLegend()#leg)

input("Press any button to continue")

ofn = 'results/histo_w_all.root'    
outHistFile = ROOT.TFile.Open(ofn,"RECREATE")
outHistFile.cd()
mll.Write()
outHistFile.Close()


