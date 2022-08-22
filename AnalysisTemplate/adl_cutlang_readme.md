# How to install CutLang

## From source

Available on **Linux, macOS, and windows**

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

If needed, update the package using
```bash
  cd CutLang
  git pull
  CLA_recompile # this will run the following in order
  # cd $CUTLANG_PATH/CLA
  # make clean
  # make -j
```

You can remove the package using
```bash
  rm -rf /path/to/CutLang
```

## Conda

Available on **Linux, macOS**

*Requirements*
- [Anaconda](https://www.anaconda.com/) or [Miniconda](https://docs.conda.io/en/latest/miniconda.html)

Create and activate the environment using
```bash
 # download CutLang and create environment
 conda create -c conda-forge -c cutlang --name <my-environment> cutlang
 # activate environment
 conda activate <my-environment> 
```
If needed, update the environment using
```bash
 # remove the existing environment and install the latest version
 conda create -c conda-forge -c cutlang --name <my-environment> cutlang
 # or just run in environment with cutlang installed
 conda update -c conda-forge -c cutlang cutlang
 # or force update (temporary, do not use unless necessary)
 CLA_conda_update
```

# How to write an ADL file

The ADL files are organized in blocks of objects, definitions, and regions.

Physics objects are made with keyword `object`, followed by name of the object, and can be used to implement cuts or define objects not in root files originally. For example, Delphes files do not contain taus as objects, but hadronic taus can be constructed as such:

```
object taus
  take Jet
  select TauTag(Jet) == 1
```

where first the object is given a name `taus`, and a tau object is constructed from jets that are tagged as originating from taus. After this, `taus` can be used in the rest of the file and it will refer to this object.


Definitions are made with keyword `define` and used to construct variables. We can define, for example, a doubly charged Higgs which decays into two taus as

```
define DCH : taus[-1] taus[-2]
```

where the negative indices mark unknown indices.

Regions begin with keyword `region`. With them it is easier to stay on track of your code and the final root file contents. We can, for example, define three regions, `fourtaus`, `twotaus`, `threetaus`:

```
region fourtaus
  select      ALL                   # to count all events

region twotaus
  select      ALL                   # to count all events

region threetaus
  select      ALL                   # to count all events
```

Which will then look like this:

![Regions in root file.](regionsA.png)

![Regions can be expanded by clicking on them.](regionsB.png)


Selections are made using the keyword `select`. In the region `fourtaus` for example, we select only the events that have four or more taus:

```
region fourtaus
  select      ALL                   # to count all events
  select      Size(taus) >= 4       # to select only the events with 4 or more taus
```

Histograms can be drawn by using the keyword `histo`, then specifying the name of the histogram in the final root file (TauPt in example), the title (Tau pT (GeV)), the number of bins (100), the start bin (0), the end bin (200), and the variable that is plotted (Pt(taus)):

```
histo  TauPt, "Tau pT (GeV)", 100, 0, 200, Pt(taus)
```

# How to run an ADL file with CutLang

```
CLA <input.root> <ROOTFILE TYPE> -i <analysis.adl>
```

which will then output `histoOut-analysis.root`.

If you're using `conda` but want to change something in scripts, you have to go to directory `CLA/` and `make`, then run `CLA.sh` in directory `runs/`.

# How to run a model with ADL and Cutlang

You'll need an ADL file. Run `python3 wrapperReadADLOutput.py` inside the folder `AnalysisTemplate` You can either have a model directory ready or you can initialize it. If your model name is `abc`, both `abc` and `model_abc` work when prompted the model name.

If your ADL file is inside the model directory, the script will recognize it automatically. In other case, you'll need to input the path manually. Same with other output files (samples, xsections, and weights).