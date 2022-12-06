 <img src="https://user-images.githubusercontent.com/87129919/205923941-83ed108a-ec52-4d2c-8e5f-180bb7c84f9d.png" align="right"  height="50"/> 


## About
This is the repository for *CutLang: A Particle Physics Analysis Description Language Runtime Interpreter*. 
CutLang is a domain-specific language and interpreter for cut-based HEP data analysis. It allows users to write analysis in ADL (Analysis Description Language) files, which are then interpreted by the CutLang framework at run time. The linterpreter is implemented in C++ and is built on top of the CERN data analysis framework ROOT. CutLang offers several features to make data analysis more efficient and error-free, including object definitions, event selections, histogramming, and Monte Carlo weighting. It also supports multi-core/multi-CPU hardware and has the ability to save events at any stage of the analysis. The latest version CutLang V3 uses the Lex/Yacc-based approach for ADL file processing and has several enhancements over the previous version, including improved handling of object combinatorics, the ability to include tables and weights, and support for more complex algorithms.
CutLang provides a standard and accessible way to write and interpret HEP analyses. By facilitating the preservation, sharing, and communication of HEP analysis methods, CutLang and ADL can help to advance the field of HEP data analysis.


### What is ADL? 
ADL (Analysis Description Language) is a domain-specific language used to describe and implement analysis in high-energy particle physics experiments. ADL allows users to write HEP analyses in a clear and easily readable format. ADL is written in a way that is independent of any specific computing framework, making it easier to share and compare analyses between different users and experiments. It is used to define the criteria for selecting events of interest and to specify how the selected events should be processed (e.g. by calculating certain variables or performing specific cuts). ADL is typically used in conjunction with a Monte Carlo simulation to generate samples of events and a data analysis framework to process the events and produce results.


**Launch tutorial:**

With *jupyter lab*: [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/master?urlpath=/lab/tree/binder/index.ipynb)

With *jupyter notebook*: [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/master?urlpath=/notebooks/binder/index.ipynb)

# Contents
- [Using CutLang](#using-cutlang)
  - [From source](#using-cutlang-from-source)
    - [Setup](#using-cutlang-from-source-setup)
    - [Update](#using-cutlang-from-source-update)
    - [Remove](#using-cutlang-from-source-remove)
  - [With conda](#using-cutlang-with-conda)
    - [Setup](#using-cutlang-with-conda-setup)
    - [Update](#using-cutlang-with-conda-update)
    - [Remove](#using-cutlang-with-conda-remove)
  - [With docker](#using-cutlang-with-docker)
    - [Setup](#using-cutlang-with-docker-setup)
    - [Update](#using-cutlang-with-docker-update)
    - [Remove](#using-cutlang-with-docker-remove)
  - [With Jupyter](#using-cutlang-with-jupyter)
    - [Setup](#using-cutlang-with-jupyter-setup)
    - [Starting](#using-cutlang-with-jupyter-starting)
- [Running CutLang](#running-cutlang)
- [Tutorial](#tutorial)
  - [Setup](#tutorial-setup)
  - [Starting](#tutorial-starting)
  - [Update](#tutorial-update)
- [Jupyter CutLang magic](#jupyter-cutlang-magic)
- [FAQ](#faq)
  - [Where to find an example ntuple ?](#faq-where-to-find-an-example-ntuple)
- [Contributing](#contributing)
  - [Setting up the development environment](#contributing-setting-up-the-development-environment)
    - [From source](#contributing-setting-up-the-development-environment-from-source)
    - [With conda](#contributing-setting-up-the-development-environment-with-conda)
    - [With docker](#contributing-setting-up-the-development-environment-with-docker)
  - [Build and deploy environment](#contributing-build-and-deploy-environment)
    - [Conda](#contributing-build-and-deploy-environment-conda)
    - [Docker](#contributing-build-and-deploy-environment-docker)
  - [Note](#contributing-note)


# <a name="using-cutlang"></a> Using CutLang
Cutlang is available on **Linux, macOS, and windows (partially)**.

## <a name="using-cutlang-from-source"></a> From source
Available on **Linux, macOS, and windows**

### <a name="using-cutlang-from-source-setup"></a> Setup
*Requirements*
- ROOT6 (root.cern.ch)
- command line compilation utilities (make, gcc, g++...)
- flex
- bison # without installing flex and bison, the make command gets interrupted by a fatal error.*

Setup the package using
```bash
  git clone https://github.com/unelg/CutLang.git
  cd CutLang
  source setup.sh
  # if you want, you can run
  # echo "source /path/to/CutLang/setup.sh" >> ~/.bashrc
  # to keep it active all the time
  CLA_compile # this will run the following in order
  # cd $CUTLANG_PATH/CLA
  # make -j
```
Now, you can run CutLang (please see [Running](#running-cutlang) part)

### <a name="using-cutlang-from-source-update"></a> Update
Update the package using
```bash
  cd CutLang
  git pull
  CLA_recompile # this will run the following in order
  # cd $CUTLANG_PATH/CLA
  # make clean
  # make -j
```

### <a name="using-cutlang-from-source-remove"></a> Remove
Remove the package using
```bash
  rm -rf /path/to/CutLang
```

## <a name="using-cutlang-with-conda"></a> With conda
Available on **Linux, macOS**
[![Anaconda-Server Badge](https://anaconda.org/cutlang/cutlang/badges/version.svg?v=c)](https://anaconda.org/cutlang/cutlang)[![Anaconda-Server Badge](https://anaconda.org/cutlang/cutlang/badges/latest_release_date.svg?v=c)](https://anaconda.org/cutlang/cutlang)[![Anaconda-Server Badge](https://anaconda.org/cutlang/cutlang/badges/platforms.svg?v=c)](https://anaconda.org/cutlang/cutlang)

### <a name="using-cutlang-with-conda-setup"></a> Setup
*Requirements*
- [Anaconda](https://www.anaconda.com/) or [Miniconda](https://docs.conda.io/en/latest/miniconda.html)

Create and activate the environment using
```bash
 conda create -c conda-forge -c cutlang --name <my-environment> cutlang # download CutLang and create environment
 conda activate <my-environment> # activate environment
```
Now, you can run CutLang (please see [Running](#running-cutlang) part)

### <a name="using-cutlang-with-conda-update"></a> Update
Update the environment using
```bash
 conda create -c conda-forge -c cutlang --name <my-environment> cutlang # remove the existing environment and install the latest version
 # or just
 conda update -c conda-forge -c cutlang cutlang # run in environment with cutlang installed

 # or force update (temporary, do not use unless necessary)
 CLA_conda_update
```

### <a name="using-cutlang-with-conda-remove"></a> Remove
Remove the environment using
```bash
  conda deactivate <my-environment>
  conda env remove --name <my-environment>
```

## <a name="using-cutlang-with-docker"></a> With Docker
Available on **Linux, macOS, and windows**

### <a name="using-cutlang-with-docker-setup"></a> Setup
*Requirements*
- [Docker](https://www.docker.com/products/docker-desktop)

Download the image and run the container using
```bash
  docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v $PWD/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest 
#If you would like to re-run by mounting another directory, you should stop the container using
docker stop CutLang-root-vnc && docker container rm CutLang-root-vnc
#and rerun with a different path as 
docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v /path/you/want/:/src ...
#For example: 
docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v ~/example_work_dir/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest
```
*For Windows:*
```bash
 docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v %cd%/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest
 #If you would like to re-run by mounting another directory, you should stop the container using
docker stop CutLang-root-vnc && docker container rm CutLang-root-vnc
#and rerun with a different path as 
docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v /path/you/want/:/src ... 
#For example:
docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v ~/example_work_dir/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc:latest
```
Execute the container using
```bash
docker exec -it CutLang-root-vnc bash
```
If you have installed the container successfully, you will see
```bash
For examples see /CutLang/runs/
and for LHC analysis implementations, see
https://github.com/ADL4HEP/ADLLHCanalyses
```
Now, the container is ready to run CutLang.

You can leave the container by typing
```bash
exit
```
### <a name="using-cutlang-with-docker-update"></a> Update
In case an update is necessary, you can perform the update as follows:
```bash
docker pull cutlang/cutlang-root-vnc:latest
docker stop CutLang-root-vnc && docker container rm CutLang-root-vnc
docker run -p 8888:8888 -p 5901:5901 -p 6080:6080 -d -v $PWD/:/src --name CutLang-root-vnc cutlang/cutlang-root-vnc
```

### <a name="using-cutlang-with-docker-remove"></a> Remove
Remove the docker container and image using
```bash
docker stop CutLang-root-vnc
docker ps -a | grep "CutLang-root-vnc" | awk '{print $1}' | xargs docker rm
docker images -a | grep "cutlang-root-vnc" | awk '{print $3}' | xargs docker rmi
```


## <a name="using-cutlang-with-jupyter"></a> With Jupyter
Available on **Linux, macOS, windows**

*In order to run CutLang in Jupyter, you must first complete the setup from source or with conda or docker.*
### <a name="using-cutlang-with-jupyter-setup"></a> Setup
- **You should have completed the CutLang setup and be able to run the CLA command without any problems.**

### <a name="using-cutlang-with-jupyter-starting"></a> Starting
*Starts Jupyter with "ROOT c++ with CutLang" kernel in your current directory*
```bash
  CLA_Jupyter lab
  # or
  CLA_Jupyter notebook
  # Jupyter will be started, you can use by using the link 127.0.0.1:8888/... in the logs
```

# <a name="running-cutlang"></a> Running CutLang

CutLang is run anywhere using the `CLA` (shell script) or using the `CLA.py` scripts

```bash
 CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents]
 # Also, you can start simultaneous processes, which can increase the analysis speed tremendously.
 CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents] -j 0
 # When you enter 0 in the j flag, it will start the process as much as the number of processor cores, if you want, you can set the number of processes by changing the value from 0.
 # for example:
 # CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents] -j 8
 # above command starts 8 simultaneous processes
```
- Input event formats can be: *DELPHES, CMSNANO, LHCO, FCC, ATLASVLL, ATLASOD, CMSOD, VLLBG3 and LVL0 (CutLang internal format)* 
- Number of events is optional.

The output will be saved in `histoOut-[adlfilename].root`.  This ROOT file will have a separate directory for each search region, which contains the relevant histograms and ADL content defining the region. The histogram(s) `cutflow` (and `bincounts`, in case search bins are specified in the region) exist by default.  

# <a name="tutorial"></a> Tutorial
**Launch with binder:**

With *jupyter lab*: [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/master?urlpath=/lab/tree/binder/index.ipynb)

With *jupyter notebook*: [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/master?urlpath=/notebooks/binder/index.ipynb)

*or* Self host

## <a name="tutorial-setup"></a> Setup (Self host)

* **You should have completed the CutLang installation and be able to run the CLA command without any problems.**

## <a name="tutorial-starting"></a> Starting (Self host)
Starts Jupyter with "ROOT c++ with CutLang" kernel in $CUTLANG_PATH directory
```bash
  CLA_tutorial lab
  # or
  CLA_tutorial notebook
  # Jupyter will be started, you can use the tutorial by using the link 127.0.0.1:8888/... in the logs
  # Then you can browse index and other ipynb files in binder folder
```

## <a name="tutorial-update"></a> Update (Self host)
```bash
  CLA_tutorial_update
  # force update (temporary, do not use unless necessary)
```

# <a name="jupyter-cutlang-magic"></a> Jupyter CutLang Magic
*CutLang can be used on Jupyter notebooks with ROOT*
- You can see how to use ROOT notebooks from the [link](https://root.cern.ch/notebooks/HowTos/HowTo_ROOT-Notebooks.html)
- You can also run CutLang on any cell as (For detailed information, you can check the [tutorial](#tutorial) section.)
```bash
%%cutlang file=<root-file-name> filetype=<root-file-type> ...
```

# <a name="faq"></a> FAQ

## <a name="faq-where-to-find-an-example-ntuple"></a> Where to find an example ntuple ?
Ntuple files are kept in CLA directory

## <a name="faq-where-to-find-an-example-ntuple"></a> Where to find an example adl files ?
Example adl files are kept in runs directory, you can also check out the repository at https://github.com/ADL4HEP/ADLLHCanalyses

# <a name="contributing"></a> Contributing

## <a name="contributing-setting-up-the-development-environment"></a> Setting up the development environment

### <a name="contributing-setting-up-the-development-environment-from-source"></a> From source
You can refer to [using CutLang from source](#using-cutlang-from-source)

### <a name="contributing-setting-up-the-development-environment-with-conda"></a> With conda
Create and activate the environment using
```bash
 git clone https://github.com/unelg/CutLang.git
 cd CutLang
 conda env create -f scripts/environment.yml # create environment with dependencies
 conda activate CutLang-dev # activate development environment
 source setup.sh
 # if you want, you can run
 # echo "source /path/to/CutLang/setup.sh" >> ~/.bashrc
 # to keep it active all the time

 # then you should run (just first time)
 CLA_recompile # this will run the following in order
 # cd $CUTLANG_PATH/CLA
 # make clean
 # make -j
```

### <a name="contributing-setting-up-the-development-environment-with-docker"></a> With docker
Compile CutLang, and build and run the container using
```bash
 git clone https://github.com/unelg/CutLang.git
 cd CutLang
 ./scripts/docker/util.sh dev
 # ! Do not add the dockerfile created for the development environment to the git
 docker-compose up
```
Exec the container using (in the another terminal window)
```bash
 docker exec -it cutlang-dev bash
 # then you should run in docker (just first time)
 CLA_recompile # this will run the following in order
 # cd $CUTLANG_PATH/CLA
 # make clean
 # make -j
```

## <a name="contributing-build-and-deploy-environment"></a> Build and deploy environment

### <a name="contributing-build-and-deploy-environment-conda"></a> Conda
Requirements
- [conda-build](https://docs.conda.io/projects/conda-build/en/latest/install-conda-build.html)

See https://anaconda.org

```bash
 git clone https://github.com/unelg/CutLang.git
 cd CutLang
 cd scripts/conda
 # To change version you have to edit scripts/conda/meta.yaml
 conda-build -c conda-forge .
 # You will see the "anaconda upload /file/path/to/upload" command at the end of the logs after the compile process is finished, you can upload the package to the relevant conda channel by using this.
 # and then it can be used with:
 # conda create -c conda-forge -c <your-username> --name <your-environment> cutlang
```

### <a name="contributing-build-and-deploy-environment-docker"></a> Docker
See https://hub.docker.com

```bash
 git clone https://github.com/unelg/CutLang.git
 cd CutLang
 ./scripts/docker/util.sh prod
 # you need to edit docker-compose.yml image name <your-username/cutlang>
 docker-compose build
 docker push <your-username>/<your-image-name>:<tagname>
 # example:
 # docker push cutlang/cutlang:latest
```

## <a name="contributing-note"></a> Note
Please, if version is updated, wait until all tests have been checked in the respective commit and the packages have been released. (Related mail will be sent)
