// NB: to use this macro:
// - change the line below "std::string inputDir = ..." according to the directory containing the .root files (pathresolver is not used here)
// - make sure to have these lines executed by ROOT:
//   [] .include ../NNLOttbar/TTbarNNLOReweighter/
//   [] .L ../NNLOttbar/TTbarNNLOReweighter/macros/RecursiveReweighting.C+
// where "../NNLOttbar/TTbarNNLOReweighter" here should be changed to the actual location of your TTbarNNLOReweighter package
// - otherwise, to use it inside TRExFitter, you should have in your config file the following lines:
//   CustomFunctions: "../NNLOttbar/TTbarNNLOReweighter/macros/RecursiveReweighting.C"
//   CustomIncludePaths: "../NNLOttbar/TTbarNNLOReweighter/"

#define OMITPATHRESOLVER
#include "TTbarNNLORecursiveRew.cxx"

bool alreadyRun;
int readingSample;
int readingSyst;

TTbarNNLORecursiveRew *myReweighter;

// ____________________________________________________________________________
//
double RecursiveReweighting(double Top_pt,double ATop_pt,double TTbar_M,double TTbar_Pt){ //,int sample=0,int syst=0){
    int sample=0; //NGU
    int syst=0; //NGU
    if(!alreadyRun){
        readingSample = -999;
        readingSyst = -999;
        alreadyRun = true;
    }
    // reset everything in case a new systematic is run over
    if(readingSample!=sample || readingSyst!=syst){
        delete myReweighter;
        myReweighter = 0x0;
        readingSample = sample;
        readingSyst = syst;
    }
    if(myReweighter==0x0){
        myReweighter = new TTbarNNLORecursiveRew( sample, syst, false );
        // new 3x3 (with rebinned ttbar pT)
        myReweighter->SetInputDirectory("../NNLOttbar/TTbarNNLOReweighter/data/");
        myReweighter->SetInputSuffix("_MATRIX_3iter_2021_1e8");
        //
        myReweighter->Init();
    }
    return myReweighter->GetWeight(Top_pt,ATop_pt,TTbar_M,TTbar_Pt);
}
