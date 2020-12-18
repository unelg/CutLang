# CutLang
This is the repository for CutLang V3 


## Installation

Requirements
* ROOT6 (root.cern.ch) 
* command line compilation utilities (make, gcc, g++...) 
* flex
* bison #without installing flex and bison, the make command gets interrupted by a fatal error.

Install the package using
```bash
 git clone https://github.com/unelg/CutLang.git
 cd CutLang/CLA
 make
 cd ../runs
```

## Running

CutLang is run using the `CLA.sh` or `CLA.py` script as

```bash
 ./CLA.sh (or ./CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents]
```
* Input event formats can be: DELPHES, CMSNANO, LHCO, FCC, ATLASVLL, ATLASOD, CMSOD, VLLBG3 and LVL0 (CutLang internal format) 
* Number of events is optional.

The output will be saved in `histoOut-[adlfilename].root`.  This ROOT file will have a separate directory for each search region, which contains the relevant histograms and ADL content defining the region.  The histogram(s) `cutflow` (and `bincounts`, in case search bins are specified in the region) exist by default.  
