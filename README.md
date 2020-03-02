# CutLang
This is the repository for CutLang V3 


## Installation

Requirements
* ROOT (root.cern.ch) 
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

```bash
 ./CLA.sh [inputrootfile] [inputeventformat] -i [adlfilename]
```

