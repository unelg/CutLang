#include "TTbarNNLORecursiveRew.h"

#include "TFile.h"
#include "TH1.h"

#include <iostream>
#ifndef OMITPATHRESOLVER
#include "PathResolver/PathResolver.h"
#endif

using namespace std;

TTbarNNLORecursiveRew::TTbarNNLORecursiveRew(int sampleId,int systVar,bool autoInit) :
  m_sampleId(sampleId),
  m_systVar(systVar),
  m_dir(""), // to be specified only if want a local directory
  m_suffix("_MATRIX_3iter_1e8"),
  m_Nrew(0)
{
    if(autoInit) Init();
}

TTbarNNLORecursiveRew::~TTbarNNLORecursiveRew(){
    m_rewList.clear();
    m_h_nnlo.clear();
    m_h_mc.clear();
}

void TTbarNNLORecursiveRew::SetInputDirectory(const std::string& dirName){
    m_dir = dirName;
}

void TTbarNNLORecursiveRew::SetInputSuffix(const std::string& suffix){
    m_suffix = suffix;
}

void TTbarNNLORecursiveRew::SetSampleID(int sampleID){
    m_sampleId = sampleID;
}

void TTbarNNLORecursiveRew::SetSystVar(int systVar){
    m_systVar = systVar;
}

void TTbarNNLORecursiveRew::SetRewList(std::vector<std::string> list){
    m_rewList = list;
}

void TTbarNNLORecursiveRew::AddRew(std::string rew){
    m_rewList.emplace_back( rew );
}

void TTbarNNLORecursiveRew::SetDefault3D(){
    m_rewList.clear();
    m_rewList.emplace_back( "TTbarPt" );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarPt" );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarPt" );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
}

void TTbarNNLORecursiveRew::SetDefault2D(){
    m_rewList.clear();
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
}

void TTbarNNLORecursiveRew::SetInverted2D(){
    m_rewList.clear();
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarM"  );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TopPt"   );
    m_rewList.emplace_back( "TTbarM"  );
}

void TTbarNNLORecursiveRew::Init(){
    // reset lists, in case the tool got re-initialized
    m_h_nnlo.clear();
    m_h_mc.clear();
    
    // in case no reweightig list is specified, use the default
    if(m_rewList.size()==0){
        // here the order of the reweighting steps is defined
        // it should be the same as the one used when deriving the reweighting
        m_rewList.emplace_back( "TTbarPt" );
        m_rewList.emplace_back( "TTbarM"  );
        m_rewList.emplace_back( "TopPt"   );
        m_rewList.emplace_back( "TopPt"   );
        m_rewList.emplace_back( "TTbarPt" );
        m_rewList.emplace_back( "TTbarM"  );
        m_rewList.emplace_back( "TopPt"   );
        m_rewList.emplace_back( "TopPt"   );
        m_rewList.emplace_back( "TTbarPt" );
        m_rewList.emplace_back( "TTbarM"  );
        m_rewList.emplace_back( "TopPt"   );
        m_rewList.emplace_back( "TopPt"   );
    }
    //
    // store size of list
    m_Nrew = m_rewList.size();
    //
    // get proper histograms from file
    //
    if(m_dir==""){
#ifndef OMITPATHRESOLVER
        m_dir = PathResolverFindCalibDirectory("TTbarNNLOReweighter/");
#endif
    }
    //
    string smpStr = "PP8";
    string sysStr = "";
    if(m_systVar!=0 && m_sampleId!=0){
        std::cout << "=== ERROR::TTbarNNLORecursiveRew: Trying to get systematic variation for non-nominal sample. Ignoring syst variation." << std::endl;
    }
    //
    if     (m_sampleId==1)     smpStr = "PH7new";
    else if(m_sampleId==2)     smpStr = "aMCH7";
    else if(m_sampleId==3)     smpStr = "PH7";
    else if(m_sampleId==4)     smpStr = "aMCP8";
    else if(m_sampleId==5)     smpStr = "PP8hdamp";
    else if(m_sampleId==6)     smpStr = "PP8muRup";
    else if(m_sampleId==7)     smpStr = "PP8muRdown";
    else if(m_sampleId==8)     smpStr = "PP8muFup";
    else if(m_sampleId==9)     smpStr = "PP8muFdown";
    else if(m_sampleId==10)    smpStr = "PP8FSRup";
    else if(m_sampleId==11)    smpStr = "PP8FSRdown";
    else if(m_sampleId==-1)    smpStr = "MECoff";
    //
    if     (m_systVar==  1) sysStr = "_scaleUpTopPt";
    else if(m_systVar== -1) sysStr = "_scaleDownTopPt";
    else if(m_systVar==  2) sysStr = "_scaleUpTTbarM";
    else if(m_systVar== -2) sysStr = "_scaleDownTTbarM";
    else if(m_systVar==  3) sysStr = "_scaleUpTTbarPt";
    else if(m_systVar== -3) sysStr = "_scaleDownTTbarPt";
    else if(m_systVar==  4) sysStr = "_PDFUp";
    else if(m_systVar== -4) sysStr = "_PDFDown";
    else if(m_systVar== 10) sysStr = "_muRUp";
    else if(m_systVar==-10) sysStr = "_muRDown";
    else if(m_systVar== 20) sysStr = "_muFUp";
    else if(m_systVar==-20) sysStr = "_muFDown";
    else if(m_systVar== 11) sysStr = "_muRUpTopPt";
    else if(m_systVar==-11) sysStr = "_muRDownTopPt";
    else if(m_systVar== 21) sysStr = "_muFUpTopPt";
    else if(m_systVar==-21) sysStr = "_muFDownTopPt";
    else if(m_systVar== 12) sysStr = "_muRUpTTbarM";
    else if(m_systVar==-12) sysStr = "_muRDownTTbarM";
    else if(m_systVar== 22) sysStr = "_muFUpTTbarM";
    else if(m_systVar==-22) sysStr = "_muFDownTTbarM";
    else if(m_systVar==100) sysStr = "_noEW";
    else if(m_systVar==2000) sysStr = "_fakeNNLOoneemission";
    else if(m_systVar==3000) sysStr = "_fakeNNLOnominal";
    //
    std::unique_ptr<TFile> f(TFile::Open((m_dir+"/RecursiveReweighting__"+smpStr+sysStr+m_suffix+".root").c_str()));
    std::cout << "=== INFO::TTbarNNLORecursiveRew: Opening file " << m_dir << f->GetName() << std::endl;
    if (!f) {
        std::cout << "=== ERROR::TTbarNNLORecursiveRew: Cannot open the file" << std::endl;
        exit(EXIT_FAILURE);
    }
    //
    // get NNLO prediction
    for(unsigned int i_rew=0;i_rew<m_Nrew;i_rew++){
        auto tmp = dynamic_cast<TH1*>(f->Get(("h_"+m_rewList[i_rew]).c_str()));
        if (!tmp) {
            std::cout << "=== ERROR::TTbarNNLORecursiveRew: Cannot read histogram " << "h_"+m_rewList[i_rew] << std::endl;
            exit(EXIT_FAILURE);
        }
        m_h_nnlo.emplace_back(tmp);
        m_h_nnlo[i_rew]->SetDirectory(nullptr);
    }
    //
    // get MC prediction (after proper reweighting)
    for(unsigned int i_rew=0;i_rew<m_Nrew;i_rew++){
        if(i_rew==0) {
            auto tmp = dynamic_cast<TH1*>(f->Get(("h_"+m_rewList[i_rew]+"_"+smpStr).c_str()));
            if (!tmp) {
                std::cout << "=== ERROR::TTbarNNLORecursiveRew: Cannot read histogram " << "h_"+m_rewList[i_rew]+"_"+smpStr << std::endl;
                exit(EXIT_FAILURE);
            }
            m_h_mc.emplace_back(tmp);
        }
        else {
            auto tmp = dynamic_cast<TH1*>(f->Get(("h_"+m_rewList[i_rew]+"_"+smpStr+"_rew_"+std::to_string(i_rew-1)).c_str()));
            if (!tmp) {
                std::cout << "=== ERROR::TTbarNNLORecursiveRew: Cannot read histogram " << "h_"+m_rewList[i_rew]+"_"+smpStr+"_rew_"+std::to_string(i_rew-1) << std::endl;
                exit(EXIT_FAILURE);
            }
            m_h_mc.emplace_back(tmp);
        }
        m_h_mc[i_rew]->SetDirectory(nullptr);
    }
    f->Close();
}

double TTbarNNLORecursiveRew::Reweight(double x,int idx) const{
    int bin = m_h_nnlo[idx]->FindBin(x);
    if(bin==0 || bin>m_h_nnlo[idx]->GetNbinsX()) return 1.;
    double y_nnlo = m_h_nnlo[idx]->GetBinContent(bin);
    double y_mc   = m_h_mc[idx]->GetBinContent(bin);
    if(y_nnlo==0) return 1.;
    if(y_mc  ==0) return 1.;
    return y_nnlo/y_mc;
}

double TTbarNNLORecursiveRew::GetWeight(double Top_pt,double ATop_pt,double TTbar_M,double TTbar_Pt) const{
    double result = 1.;
    for(unsigned int i_rew=0;i_rew<m_Nrew;i_rew++){
        if     (m_rewList[i_rew]=="TopPt")   result *= sqrt(Reweight(Top_pt,i_rew)*Reweight(ATop_pt,i_rew));
        else if(m_rewList[i_rew]=="TTbarPt") result *= Reweight(TTbar_Pt,i_rew);
        else if(m_rewList[i_rew]=="TTbarM")  result *= Reweight(TTbar_M,i_rew);
    }
    return result;
}
