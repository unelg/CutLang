# CutLang
This is the repository for CutLang V3

*A Particle Physics Analysis Description Language and Runtime Interpreter*

**Launch tutorial:** [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/shenburak/CutLang/HEAD)


## Installation

### Using conda + [install.sh](https://raw.githubusercontent.com/shenburak/CutLang/master/install.sh) -> (beta - may not work)

Create and install CutLang using
```bash
 # Please fill <my-environment> with environment name you want
 bash -c "$(curl https://raw.githubusercontent.com/shenburak/CutLang/master/install.sh | bash -s install <my-environment>)"
```

Activate the conda environment using (from new terminal)
```bash
 conda activate <my-environment>
```
Now, you can use CutLang (please see [Running](#running) part)

### Using conda
[![Anaconda-Server Badge](https://anaconda.org/shenburak/cutlang/badges/version.svg)](https://anaconda.org/shenburak/cutlang)[![Anaconda-Server Badge](https://anaconda.org/shenburak/cutlang/badges/latest_release_date.svg)](https://anaconda.org/shenburak/cutlang)[![Anaconda-Server Badge](https://anaconda.org/shenburak/cutlang/badges/platforms.svg)](https://anaconda.org/shenburak/cutlang)

- Create and activate the environment using (If root is already installed on the system)
```bash
 conda create -c conda-forge -c shenburak --name <my-environment> cutlang # download CutLang package and create environment
 conda activate <my-environment> # activate environment
```
- Create and activate the environment using (If root is not installed on the system and you want to install the root conda package with CutLang)
```bash
 conda create -c conda-forge -c shenburak --name <my-environment> cutlang root_base # download CutLang and root package and create environment
 conda activate <my-environment> # activate environment
```
*Now, you can use CutLang (please see [Running](#running) part)*

- **Update** the environment using
```bash
 conda create -c conda-forge -c shenburak --name <my-environment> cutlang # remove the existing environment and install the latest version without root
 # or
 conda create -c conda-forge -c shenburak --name <my-environment> cutlang root_base # remove the existing environment and install the latest version with root
 # or just
 conda update cutlang # run in environment with cutlang installed
```
### Using docker

Download the image and run the container using
```bash
 docker run -p 80:80 -d -v $PWD/:/src --name CutLang shenburak/cutlang # download image and run container in current directory from downloaded image
 # for windows: docker run -p 80:80 -d -v %cd%/:/src --name CutLang shenburak/cutlang
 # if you want to re-run by mounting another directory, you should run:
 # docker stop CutLang && docker container rm CutLang
 # and go back step 2 with different path 'docker run -p 80:80 -d -v /path/to/you/want/:/src ...'
 # example:
 # docker run -p 80:80 -d -v ~/example_work_dir/:/src --name CutLang shenburak/cutlang
```
Exec the container using
```bash
 docker exec -it CutLang bash
```
**Update** the docker image using
```bash
 docker pull shenburak/cutlang:latest # install the latest image
 # and
 docker stop CutLang && docker container rm CutLang
 docker run -p 80:80 -d -v $PWD/:/src --name CutLang shenburak/cutlang
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

CutLang is run anywhere using the `CLA` (shell script) or using the `CLA.py` scripts

```bash
 CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents]
```
* Input event formats can be: DELPHES, CMSNANO, LHCO, FCC, ATLASVLL, ATLASOD, CMSOD, VLLBG3 and LVL0 (CutLang internal format) 
* Number of events is optional.

The output will be saved in `histoOut-[adlfilename].root`.  This ROOT file will have a separate directory for each search region, which contains the relevant histograms and ADL content defining the region.  The histogram(s) `cutflow` (and `bincounts`, in case search bins are specified in the region) exist by default.  
## Tutorial
**Launch with binder:**
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/shenburak/CutLang/HEAD)
or
Self host:
* **You should have completed the CutLang installation and be able to run the CLA command without any problems.**
* To setup the kernel if you have compiled CutLang from source (you can skip this step if you have downloaded CutLang with conda or docker)

```bash
  ./setup_kernel.sh  
```
* To start the tutorial (you can run it anywhere)
```bash
  CLA_tutorial
  # Jupyter lab will be started, you can use the tutorial by using the link 127.0.0.1:80/... in the logs
```
## JupyterLab
*Starts JupyterLab with "ROOT c++ with CutLang" kernel*
* **You should have completed the CutLang installation and be able to run the CLA command without any problems.**
* To setup the kernel if you have compiled CutLang from source (you can skip this step if you have downloaded CutLang with conda or docker)

```bash
  ./setup_kernel.sh  
```
* To start the JupyterLab
```bash
  CLA_JupyterLab
  # Jupyter lab will be started, you can use by using the link 127.0.0.1:80/... in the logs
```
## Contributing

### Setting up the development environment

#### Using conda

Create and activate the environment using
```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 conda env create -f environment.yml # create environment with dependencies
 conda activate CutLang-dev # activate development environment
 cd CLA
 make clean
 make
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
 ./docker_util.sh dev
 docker-compose up
```
Exec the container using (in the another terminal window)
```bash
 docker exec -it cutlang-dev bash
 # then you should run in docker (just first time)
 cd CLA
 make clean
 make
```

### Build and deploy environment
#### Conda

Requirements
- [conda-build](https://docs.conda.io/projects/conda-build/en/latest/install-conda-build.html)

See https://anaconda.org

```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 conda-build -c conda-forge .
 # You will see the "anaconda upload /file/path/to/upload" command at the end of the logs after the compile process is finished, you can upload the package to the relevant conda channel by using this.
 # and then it can be used with:
 # conda create -c conda-forge -c <your-username> --name <your-environment> cutlang
```
#### Docker

See https://hub.docker.com

```bash
 git clone https://github.com/shenburak/CutLang.git
 cd CutLang
 ./docker_util.sh prod
 docker-compose build
 docker push <your-username>/<your-image-name>:<tagname>
 # example:
 # docker push shenburak/cutlang:latest
```