objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

ROOTCFLAGS    = $(shell root-config --cflags)
CXXFLAGS     += $(ROOTCFLAGS) -O3 -I../analysis_core  -D__STANDALONE__ 
CXX           = $(shell root-config --cxx) -g


%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(objects)
	root -q -l -b -e '{gROOT->LoadMacro("dbxParticle.cpp+");}' 
	root -q -l -b -e '{gROOT->LoadMacro("dbx_muon.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_tau.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_electron.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_photon.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_jet.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_truth.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_track.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("dbx_track.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("DBXNtuple.cpp+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("delphesParticles.h+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("TStringAddFloat.cpp+");}' &
	root -q -l -b -e '{gROOT->LoadMacro("ReadCardCINT.C+");}' &
	test -L ../runs/DBXNtuple_cpp_ACLiC_dict_rdict.pcm   || ( ln -s ../analysis_core/DBXNtuple_cpp_ACLiC_dict_rdict.pcm     ../runs/ )
	test -L ../runs/dbxParticle_cpp_ACLiC_dict_rdict.pcm || ( ln -s ../analysis_core/dbxParticle_cpp_ACLiC_dict_rdict.pcm   ../runs/ )
	test -L ../runs/dbx_electron_h_ACLiC_dict_rdict.pcm  || ( ln -s ../analysis_core/dbx_electron_h_ACLiC_dict_rdict.pcm    ../runs/ )
	test -L ../runs/dbx_jet_h_ACLiC_dict_rdict.pcm       || ( ln -s ../analysis_core/dbx_jet_h_ACLiC_dict_rdict.pcm         ../runs/ )
	test -L ../runs/dbx_muon_h_ACLiC_dict_rdict.pcm      || ( ln -s ../analysis_core/dbx_muon_h_ACLiC_dict_rdict.pcm        ../runs/ )
	test -L ../runs/dbx_photon_h_ACLiC_dict_rdict.pcm    || ( ln -s ../analysis_core/dbx_photon_h_ACLiC_dict_rdict.pcm      ../runs/ )
	test -L ../runs/dbx_tau_h_ACLiC_dict_rdict.pcm       || ( ln -s ../analysis_core/dbx_tau_h_ACLiC_dict_rdict.pcm         ../runs/ )
	test -L ../runs/dbx_truth_h_ACLiC_dict_rdict.pcm     || ( ln -s ../analysis_core/dbx_truth_h_ACLiC_dict_rdict.pcm       ../runs/ )
	test -L ../runs/dbx_track_h_ACLiC_dict_rdict.pcm     || ( ln -s ../analysis_core/dbx_track_h_ACLiC_dict_rdict.pcm       ../runs/ )
	test -L ../runs/delphesParticles_h_ACLiC_dict_rdict.pcm|| ( ln -s ../analysis_core/delphesParticles_h_ACLiC_dict_rdict.pcm ../runs/ )
	test -L ../CLA/DBXNtuple_cpp_ACLiC_dict_rdict.pcm   || ( ln -s ../analysis_core/DBXNtuple_cpp_ACLiC_dict_rdict.pcm     ../CLA/ )
	test -L ../CLA/dbxParticle_cpp_ACLiC_dict_rdict.pcm || ( ln -s ../analysis_core/dbxParticle_cpp_ACLiC_dict_rdict.pcm   ../CLA/ )
	test -L ../CLA/dbx_electron_h_ACLiC_dict_rdict.pcm  || ( ln -s ../analysis_core/dbx_electron_h_ACLiC_dict_rdict.pcm    ../CLA/ )
	test -L ../CLA/dbx_jet_h_ACLiC_dict_rdict.pcm       || ( ln -s ../analysis_core/dbx_jet_h_ACLiC_dict_rdict.pcm         ../CLA/ )
	test -L ../CLA/dbx_muon_h_ACLiC_dict_rdict.pcm      || ( ln -s ../analysis_core/dbx_muon_h_ACLiC_dict_rdict.pcm        ../CLA/ )
	test -L ../CLA/dbx_photon_h_ACLiC_dict_rdict.pcm    || ( ln -s ../analysis_core/dbx_photon_h_ACLiC_dict_rdict.pcm      ../CLA/ )
	test -L ../CLA/dbx_tau_h_ACLiC_dict_rdict.pcm       || ( ln -s ../analysis_core/dbx_tau_h_ACLiC_dict_rdict.pcm         ../CLA/ )
	test -L ../CLA/dbx_truth_h_ACLiC_dict_rdict.pcm     || ( ln -s ../analysis_core/dbx_truth_h_ACLiC_dict_rdict.pcm       ../CLA/ )
	test -L ../CLA/dbx_track_h_ACLiC_dict_rdict.pcm     || ( ln -s ../analysis_core/dbx_track_h_ACLiC_dict_rdict.pcm       ../CLA/ )
	test -L ../CLA/delphesParticles_h_ACLiC_dict_rdict.pcm|| ( ln -s ../analysis_core/delphesParticles_h_ACLiC_dict_rdict.pcm ../CLA/ )

clean:
	rm -f *.o  *.so  *.d  *.pcm

clean:
	rm -f *.o  *.so  *.d  *.pcm
