objects := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

ROOTCFLAGS    = $(shell root-config --cflags)
CXXFLAGS     += $(ROOTCFLAGS) -O3 -I../analysis_core  -D__STANDALONE__ 
CXX           = $(shell root-config --cxx) -g


%.o : %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(objects)
	root  -q -l -b -x makeSos.C
clean:
	rm -f *.o  *.so  *.d  *.pcm
