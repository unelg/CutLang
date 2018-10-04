objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

ROOTCFLAGS    = $(shell root-config --cflags)
CXXFLAGS     += $(ROOTCFLAGS) -O3 -I../analysis_core  -D__STANDALONE__ 
CXX           = $(shell root-config --cxx) -g


%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(objects)
#	rm -f *_dict.C

#	rootcint dbxParticle_dict.C  -c dbxParticle.h
#	rootcint dbx_muon_dict.C     -c dbx_muon.h
#	rootcint dbx_electron_dict.C -c dbx_electron.h
#	rootcint dbx_photon_dict.C   -c dbx_photon.h
#	rootcint dbx_jet_dict.C      -c dbx_jet.h
#	rootcint DBXNtuple_dict.C    -c DBXNtuple.h
#	$(CXX) $(CXXFLAGS) -c dbx_muon.h
#	$(CXX) $(CXXFLAGS) -c dbx_electron.h
#	$(CXX) $(CXXFLAGS) -c dbx_photon.h
#	$(CXX) $(CXXFLAGS) -c dbx_jet.h
#	$(CXX) $(CXXFLAGS) -shared -o dbxParticle.so dbxParticle.o dbxParticle_dict.C -I`root-config --incdir` `root-config --libs`
#	$(CXX) $(CXXFLAGS) -shared -o dbx_muon.so dbx_muon.o dbx_muon_dict.C -I`root-config --incdir` `root-config --libs`
#	$(CXX) $(CXXFLAGS) -shared -o dbx_electron.so dbx_electron.o dbx_electron_dict.C -I`root-config --incdir` `root-config --libs`
#	$(CXX) $(CXXFLAGS) -shared -o dbx_photon.so dbx_photon.o dbx_photon_dict.C -I`root-config --incdir` `root-config --libs`
#	$(CXX) $(CXXFLAGS) -shared -o dbx_jet.so dbx_jet.o dbx_jet_dict.C -I`root-config --incdir` `root-config --libs`
	root  -q -l -b -x makeSos.C

clean:
	rm -f *.o  *.so  *.d  *.pcm
