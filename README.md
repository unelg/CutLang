# CutLang
This is the repository for CutLang V3 


## Installation

### Using conda

Create and activate the environment using
```bash
 conda create -c conda-forge -c shenburak --name <my-environment> cutlang # download CutLang package and create environment
 conda activate <my-environment> # activate environment
```
Now, you can use CutLang (please see [Running](#running) part)
### Using docker

Download the image and run the container using
```bash
 docker pull shenburak/cutlang # download image
 docker run -d -v $PWD/:/src --name CutLang shenburak/cutlang # run container in current directory from downloaded image
 # for windows: docker run -d -v %cd%/:/src --name CutLang shenburak/cutlang
 # if you want to re-run by mounting another directory, you should run:
 # docker stop CutLang && docker container rm CutLang
 # and go back step 2 with different path 'docker run -d -v /path/to/you/want/:/src ...'
```
Exec the container using
```bash
 docker exec -it CutLang bash
```
### From source

Requirements
* ROOT6 (root.cern.ch) # 6.24 version is preferred
* command line compilation utilities (make, gcc, g++...) 
* flex
* bison # without installing flex and bison, the make command gets interrupted by a fatal error.

Install the package using
```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang/CLA
 make
 cd ..
 source setup.sh
 # if you want, you can run
 # echo "source /path/to/CutLang/setup.sh" >> ~/.bashrc
 # to keep it active all the time
```

## <a name="running"></a> Running

CutLang is run anywhere using the `CLA.sh` script (with **CLA** alias) or using the `runs/CLA.py` script

```bash
 CLA (or ./runs/CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents]
```
* Input event formats can be: DELPHES, CMSNANO, LHCO, FCC, ATLASVLL, ATLASOD, CMSOD, VLLBG3 and LVL0 (CutLang internal format) 
* Number of events is optional.

The output will be saved in `histoOut-[adlfilename].root`.  This ROOT file will have a separate directory for each search region, which contains the relevant histograms and ADL content defining the region.  The histogram(s) `cutflow` (and `bincounts`, in case search bins are specified in the region) exist by default.  

## Contributing

### Setting up the development environment

#### Using conda

Create and activate the environment using
```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 conda env create -f environment.yml # create environment with dependencies
 conda activate CutLang-dev # activate development environment
 source setup.sh
 # if you want, you can run
 # echo "source /path/to/CutLang/setup.sh" >> ~/.bashrc
 # to keep it active all the time
```

#### Using docker

Compile CutLang, and build and run the container using
```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 docker-compose up
```
Exec the container using (in the another terminal window)
```bash
 docker exec -it cutlang-dev bash
 # then you should run in docker (just first time)
 cd CLA
 make
```

### Build and deploy environment
#### Conda

Requirements
- [conda-build](https://docs.conda.io/projects/conda-build/en/latest/install-conda-build.html)
```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 conda-build -c conda-forge .
 # You will see the "anaconda upload /file/path/to/upload" command at the end of the logs after the compile process is finished, you can upload the package to the relevant conda channel by using this.
 # and then it can be used with:
 # conda create -c conda-forge -c <your-username> --name <your-environment> cutlang
```