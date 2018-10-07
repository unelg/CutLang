# CutLang
This is the repository for CutLang V3 

1/ Directory structure for CutLang

===Analysis_core===
basic_parser		Parsing arithmetic expressions	
atlasopen		Data format definition for ATLAS opendata type
cmsod 	        	Data format definition for CMS opendata	type
delphes			Data format definiton for DELPHES type
fcc			Data format definition for FCC	type
lhco			Data format definition for LHCO	type
lvl0			Data format definition for LVL0	type
makeSos			Root macro for making shared object library for particles and cuts	
dbx_a			Define analysis class
dbx_electron		Define the electron class (setters, getters, attributes)		superclass: dbxParticle 
dbx_jet			Define the jet class (setters, getters, attributes)			superclass: dbxParticle 
dbx_muon		Define the muon class (setters, getters, attributes)			superclass: dbxParticle 
dbx_photon		Define the photon class (setters, getters attributes)			superclass: dbxParticle 
dbxCut			Define basic Cut class, and Children Cuts				superclass: TObject 
DBXNtuple		Define Ntuple class: vectors of other elementary particles (elec,muon…)	superclass: TObject 
dbxParticle		Define the base particle class (setters, getters, operators)		superclass: TObject 
ex1			Define external function						superclass: dbxCut
AnalysisController      Degine analysis control class
PrintEfficiencies	Print out efficiencies for an analysis
ReadCard		Read the card text files line by line	
TStringAddFloat		Operator + of a String and a float	
Makefile		to compile and prepare the object libraries

===BP===
bp_a			Define  BP analysis class						superclass: dbx_a

===Dump===
dump_a			Define  Dump analysis class, dumps data in LVL0 format			superclass: dbx_a

===CLA===
CLA			The main program parsing command line parameters
Makefile                to prepare the executable code

===Runs===
showall			Root macro for plotting histograms
CLA.sh			bash script to run the code, once compiled.
*.ini 			Description of various analysis

===scripts===
adduserfunction.py	python script to add user defined analysis cut
ini2txt.sh		bash scipt to convert ini files into 2 txt files, histograms and cuts
separate_algos.sh       bash scipt to prepare signal regions to be studied in parallel

2/ Requirements
*ROOT (root.cern.ch) needs to be installed
*command line compilation utilities (makes,gcc,g++...) need to be available

3/ Compilation
 cd CutLang/CLA
 make
 cd ../runs

4/ Running
 ./CLA.sh [inputfilename] [inputfiletype] -i [inifilename]


