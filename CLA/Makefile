MACHINE = $(shell uname -s)
LINUX   = Linux
MAC     = Darwin
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)
TODAYDATE     = $(shell date)	

# Define a variable for the library path
ONNX_PATH ?= 

ifeq ($(strip $(ONNX_PATH)),)
    # Library not found
    $(info No ONNX path is given. You can specify one via \
         'make ONNX_PATH=/path/to/onnxruntime')
    ONNX_LIB :=
    ONNX_INC :=
else
    # Library found
    $(info ONNX path is set to ${ONNX_PATH})
    ONNX_LIB := -L$(ONNX_PATH)/lib -lonnxruntime
    ONNX_INC := -I$(ONNX_PATH)/include
endif

# we try to identify where the various subdirs (like CorrectionMethods) are
SUBDIRLOC = $(shell test -d ../CLA && echo ../ || echo ./)

# now we have the include directories defined, possibly using the SUBDIRLOC variable as the root
INCLUDES  = -I$(ROOTSYS)/include  -I. -I$(SUBDIRLOC)analysis_core/ -I$(SUBDIRLOC)BP/ -I$(SUBDIRLOC)Dump/ $(ONNX_INC) 
###/Users/ngu/project/onnx/onnxruntime-osx-arm64-1.16.3/include

# allow Make to use the same include directories as locations of the sources of various files
VPATH = $(subst -I,:,$(INCLUDES))

JUPY	      = $(shell uname -n | grep -c 'jupyter')

BISONV     = $(shell which bison)
YACCV      = $(shell which yacc)
FLEXV      = $(shell which flex)
LEXEV      = $(shell which lex)

CXX           = $(shell root-config --cxx) -g -O2 
#-D_CLV_
#-D__DEBUG__
CXXFLAGS      =$(INCLUDES) -Wall -fPIC -Wunused-variable -Wsign-compare
LD            = $(shell root-config --ld) -stdlib=libstdc++
#LDFLAGS       = -g

SOFLAGS       = -shared

CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTLIBS)  -lMinuit -L. -lDBXNtuple_cpp  -ldbx_electron_h -ldbx_tau_h -ldbx_muon_h -ldbx_photon_h -ldbx_jet_h -ldbxParticle_cpp -ldbx_truth_h -l dbx_track_h -ldelphesParticles_h -lz $(ONNX_LIB) -Wl,-rpath,/usr/local/lib
GLIBS         = $(ROOTGLIBS)

#LIBS += -lzstd -lCling -lpng -ltbb -lssl -lcrypto

BISEXE = 1
LEXEXE = 1

#ifneq ($(YACCV),)
#BISEXE = yacc
#endif

ifneq ($(BISONV),)
BISEXE = bison
endif

ifneq ($(LEXV),)
LEXEXE = lex
endif

ifneq ($(FLEXV),)
LEXEXE = flex
endif


ifeq (1, ${DJUPY})
	 LIBS += -lCling -lpng -ltbb -lssl -lcrypto
endif

ifneq (0, ${JUPY})
	 LIBS += -lCling -lpng -ltbb -lssl -lcrypto
endif

ANLOBJS       = bp_a.o dump_a.o 
OBJS_1        = $(ANLOBJS) lhco.o lvl0.o DELPHES2.o fcc.o delphes.o atlasopen.o atlasopenR2.o AtlasTRT.o cmsod.o cmsod2.o AtlMin.o CMSnanoAOD.o VLLf.o VLLt.o newpoet.o
OBJS_2        = b.o l.o

ifneq ($(MACHINE), $(MAC))
	cpargs = -pHr
else
	cpargs = -pr
	LDFLAGS = -g -undefined dynamic_lookup
endif

.PHONY: clean cleanall auxiliaries softlinks

CLA.exe : checks auxiliaries $(OBJS_1) $(OBJS_2) softlinks
	sed "s/XXXXYYYYZZZZ/$(TODAYDATE)/g"  CLA.Q > CLA.C ; $(CXX) $(CXXFLAGS) $(INCLUDES) -c CLA.C
	$(CXX) $(LDFLAGS) -o $@ $(OBJS_1) $(OBJS_2) CLA.o $(SUBDIRLOC)analysis_core/*.o $(CXXFLAGS)  $(LIBS)

checks:
ifeq (${BISEXE},1)
	@echo no yacc or bison. Can NOT Continue. Please install bison
	exit 1
endif
ifeq (${LEXEXE},1)
	@echo no lex or flex. Can NOT Continue. Please install flex
	exit 1
endif
	@echo yacc:$(YACCV) bison:$(BISONV) executable:$(BISEXE)
	@echo lex:$(LEXV) flex:$(FLEXV) executable:$(LEXEXE)


b.o : parse.y
	@echo You can run as   make ONNX_PATH=/Users/ngu/project/onnx/onnxruntime-osx-arm64-1.16.3
	@echo "==================================================================================="
	$(BISEXE) -d -v -o b.cpp parse.y; 

ifeq ($(ONNX_PATH),)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c b.cpp
else
	$(CXX) $(CXXFLAGS) $(INCLUDES) -DONNX_PRESENT -c b.cpp
endif

l.o : parse.l
	$(LEXEXE) -s -o l.cpp parse.l ; $(CXX) $(INCLUDES) -c l.cpp

auxiliaries:
	$(MAKE) -C $(SUBDIRLOC)analysis_core

# it might be good to handle the creation of all the necessary softlinks here
softlinks: auxiliaries
	test -r libdbx_muon_h.so       || ( ln -s $(SUBDIRLOC)analysis_core/dbx_muon_h.so      libdbx_muon_h.so     ; ln -s libdbx_muon_h.so dbx_muon_h.so )
	test -r libdbx_tau_h.so        || ( ln -s $(SUBDIRLOC)analysis_core/dbx_tau_h.so       libdbx_tau_h.so      ; ln -s libdbx_tau_h.so dbx_tau_h.so )
	test -r libdbx_electron_h.so   || ( ln -s $(SUBDIRLOC)analysis_core/dbx_electron_h.so  libdbx_electron_h.so ; ln -s libdbx_electron_h.so dbx_electron_h.so )
	test -r libdbx_photon_h.so     || ( ln -s $(SUBDIRLOC)analysis_core/dbx_photon_h.so    libdbx_photon_h.so   ; ln -s libdbx_photon_h.so dbx_photon_h.so )
	test -r libdbx_jet_h.so        || ( ln -s $(SUBDIRLOC)analysis_core/dbx_jet_h.so       libdbx_jet_h.so      ; ln -s libdbx_jet_h.so dbx_jet_h.so )
	test -r libdbx_truth_h.so      || ( ln -s $(SUBDIRLOC)analysis_core/dbx_truth_h.so     libdbx_truth_h.so    ; ln -s libdbx_truth_h.so dbx_truth_h.so )
	test -r libdbx_track_h.so      || ( ln -s $(SUBDIRLOC)analysis_core/dbx_track_h.so     libdbx_track_h.so    ; ln -s libdbx_track_h.so dbx_track_h.so )
	test -r libdbxParticle_cpp.so  || ( ln -s $(SUBDIRLOC)analysis_core/dbxParticle_cpp.so libdbxParticle_cpp.so; ln -s libdbxParticle_cpp.so dbxParticle_cpp.so )
	test -r libDBXNtuple_cpp.so    || ( ln -s $(SUBDIRLOC)analysis_core/DBXNtuple_cpp.so   libDBXNtuple_cpp.so  ; ln -s libDBXNtuple_cpp.so DBXNtuple_cpp.so )
	test -r libdelphesParticles_h.so  || ( ln -s $(SUBDIRLOC)analysis_core/delphesParticles_h.so   libdelphesParticles_h.so  ; ln -s libdelphesParticles_h.so delphesParticles.so )

$(ANLOBJS): %.o : %.cxx
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# clean
clean:
	rm -f *~ *.o *.so *.o~ *.d core DBX2analysis a.out CLA.exe _* b.* l.cpp 
	$(MAKE) -C $(SUBDIRLOC)analysis_core clean

# clean everything including the auxiliaries we depend on
cleanall: clean
	$(MAKE) -C $(SUBDIRLOC)analysis_core clean

