#!/usr/bin/env python

# Convert histograms to table format for ADL
# Run as:
#   ./histo2table.py <rootfilename> : lists the histograms
#   ./histo2table.py <rootfilename> <histoname> : converts the efficiencies into a table
#   ./histo2table.py -t/--type <tabletype> <rootfilename> <histoname> : converts the efficiencies into a table, overwrites tabletype (default is 'efficiency', can be "scalefactor', etc.)
# Author: Sezen Sekmen, 4 May 2020

import os,sys
from string import *
from optparse import OptionParser
from ROOT import *

parser = OptionParser()
parser.add_option("-t", "--type", dest="tabletype", default="efficiency",
                  help="table type, e.g. efficiency, SF, ...", metavar="FILE")
(options, args) = parser.parse_args()

if len(args) < 2:
    print '''
    Run as:
    ./histo2table.py <rootfilename> : lists the histograms
    ./histo2table.py <rootfilename> <histoname> : converts the efficiencies into a table
    ./histo2table.py -t/--type <tabletype> <rootfilename> <histoname> : converts the efficiencies into a table, overwrites tabletype (default is 'efficiency', can be "scalefactor', etc.)
    '''
#    print "(tabletype can be efficiency, scalefactor, etc.)"
    sys.exit(0)

tabletype = options.tabletype

showhistos = 0
printtable = 0
if len(args) == 1:
    rootfile = args[0]
    showhistos = 1

if len(args) == 2:
    rootfile = args[0]
    histo = args[1]
    printtable = 1

rf = TFile(rootfile)

# Show the histograms
if showhistos:
    rf.ls()

# Convert the histogram to table
if printtable:
    h = rf.Get(histo)
    nvars = atoi(h.ClassName()[2])
    tf = open(histo+'.txt', 'w')
    tf.write('table '+replace(histo, '_', '')+'\n')
    tf.write('  tabletype '+tabletype+'\n')
    tf.write('  nvars '+h.ClassName()[2]+'\n')
    tf.write('  errors true\n')
    # Print 1D histogram
    if nvars == 1:
        header = '  # %-6s %-8s %-8s %-8s %-8s \n' % ('val', 'err-', 'err+', 'xmin', 'xmax')
        tf.write(header)
        for b in range(h.GetXaxis().GetNbins()+1):
            val = h.GetBinContent(b)
            errlow = h.GetBinErrorLow(b)
            errup = h.GetBinErrorUp(b)
            xlow = h.GetXaxis().GetBinLowEdge(b)
            xup = h.GetXaxis().GetBinUpEdge(b)
            row = '%8.4f %8.4f %8.4f %8.1f %8.1f \n' % (val, errlow, errup, xlow, xup)
            tf.write(row)
    # Print 2D histogram
    if nvars == 2:
        tf.write('  # eff   err-    err+    xmin    xmax   ymin    ymax    \n')
        for bx in range(h.GetXaxis().GetNbins()+1):
            for by in range(h.GetYaxis().GetNbins()+1):
                val = h.GetBinContent(bx, by)
                errlow = h.GetBinErrorLow(bx, by)
                errup = h.GetBinErrorUp(bx, by)
                xlow = h.GetXaxis().GetBinLowEdge(bx)
                xup = h.GetXaxis().GetBinUpEdge(bx)
                ylow = h.GetYaxis().GetBinLowEdge(by)
                yup = h.GetYaxis().GetBinUpEdge(by)
                row = ' %7.4f %7.4f %7.4f %6.1f %6.1f %6.1f %6.1f \n' % (val, errlow, errup, xlow, xup, ylow, yup)
                tf.write(row)

