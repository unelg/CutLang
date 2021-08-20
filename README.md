# CutLang
This is the repository for CutLang V3.

*A Particle Physics Analysis Description Language and Runtime Interpreter*

**Launch tutorial:** [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/HEAD)

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
  - [With JupyterLab](#using-cutlang-with-jupyterlab)
    - [Setup](#using-cutlang-with-jupyterlab-setup)
    - [Starting](#using-cutlang-with-jupyterlab-starting)
- [Running CutLang](#running-cutlang)
- [Tutorial](#tutorial)
  - [Setup](#tutorial-setup)
  - [Starting](#tutorial-starting)
  - [Update](#tutorial-update)
  - [How should I follow the tutorial ?](#tutorial-how-should-i-follow-the-tutorial)
- [JupyterLab CutLang magic](#jupyterlab-cutlang-magic)
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
 docker run -p 8888:8888 -d -v $PWD/:/src --name CutLang cutlang/cutlang # download image and run container in current directory from downloaded image
 # for windows: docker run -p 8888:8888 -d -v %cd%/:/src --name CutLang cutlang/cutlang
 # if you want to re-run by mounting another directory, you should run:
 # docker stop CutLang && docker container rm CutLang
 # and go back step 2 with different path 'docker run -p 8888:8888 -d -v /path/to/you/want/:/src ...'
 # example:
 # docker run -p 8888:8888 -d -v ~/example_work_dir/:/src --name CutLang cutlang/cutlang
```
Exec the container using
```bash
 docker exec -it CutLang bash
```
Now, you can run CutLang (please see [Running](#running-cutlang) part)

### <a name="using-cutlang-with-docker-update"></a> Update
Update the docker image using
```bash
 docker pull cutlang/cutlang:latest # install the latest image
 # and
 docker stop CutLang && docker container rm CutLang
 docker run -p 8888:8888 -d -v $PWD/:/src --name CutLang cutlang/cutlang
```

### <a name="using-cutlang-with-docker-remove"></a> Remove
Remove the docker container and image using
```bash
  docker stop CutLang
  docker ps -a | grep "CutLang" | awk '{print $1}' | xargs docker rm
  docker images -a | grep "cutlang" | awk '{print $3}' | xargs docker rmi
```

## <a name="using-cutlang-with-jupyterlab"></a> With JupyterLab
Available on **Linux, macOS, windows**

*In order to run CutLang in JupyterLab, you must first complete the setup from source or with conda or docker.*
### <a name="using-cutlang-with-jupyterlab-setup"></a> Setup
- **You should have completed the CutLang setup and be able to run the CLA command without any problems.**

### <a name="using-cutlang-with-jupyterlab-starting"></a> Starting
*Starts JupyterLab with "ROOT c++ with CutLang" kernel in your current directory*
```bash
  CLA_JupyterLab
  # Jupyter lab will be started, you can use by using the link 127.0.0.1:8888/... in the logs
```

# <a name="running-cutlang"></a> Running CutLang

CutLang is run anywhere using the `CLA` (shell script) or using the `CLA.py` scripts

```bash
 CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents]
 # Also, you can start simultaneous processes, which can increase the analysis speed tremendously.
 CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents] -j 0
 # When you enter 0 in the j flag, it will start the process as much as the number of processor cores, if you want, you can set the number of processes by changing the value to 0.
 # for example:
 # CLA (or CLA.py) [inputrootfile] [inputeventformat] -i [adlfilename.adl] -e [numberofevents] -j 8
 # above command starts 8 simultaneous processes
```
- Input event formats can be: *DELPHES, CMSNANO, LHCO, FCC, ATLASVLL, ATLASOD, CMSOD, VLLBG3 and LVL0 (CutLang internal format)* 
- Number of events is optional.

The output will be saved in `histoOut-[adlfilename].root`.  This ROOT file will have a separate directory for each search region, which contains the relevant histograms and ADL content defining the region. The histogram(s) `cutflow` (and `bincounts`, in case search bins are specified in the region) exist by default.  

# <a name="tutorial"></a> Tutorial
**Launch with binder:** [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/unelg/CutLang/HEAD)

*or* Self host

## <a name="tutorial-setup"></a> Setup (Self host)

* **You should have completed the CutLang installation and be able to run the CLA command without any problems.**

## <a name="tutorial-starting"></a> Starting (Self host)
Starts JupyterLab with "ROOT c++ with CutLang" kernel in $CUTLANG_PATH directory
```bash
  CLA_tutorial
  # Jupyter lab will be started, you can use the tutorial by using the link 127.0.0.1:8888/... in the logs
  # Then you can browse example1 and other ipynb files in binder folder
```

## <a name="tutorial-update"></a> Update (Self host)
```bash
  CLA_tutorial_update
  # force update (temporary, do not use unless necessary)
```

## <a name="tutorial-how-should-i-follow-the-tutorial"></a> How should I follow the tutorial ?
At startup you can enter binder folder and open example1.ipynb

# <a name="jupyterlab-cutlang-magic"></a> JupyterLab CutLang Magic
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