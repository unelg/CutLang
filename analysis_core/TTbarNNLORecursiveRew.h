#ifndef TTBARNNLORECURSIVEREW_H_
#define TTBARNNLORECURSIVEREW_H_

#include <memory>
#include <string>
#include <vector>

class TH1;

class TTbarNNLORecursiveRew {

  public:
    TTbarNNLORecursiveRew(int sampleID=0,int systVar=0,bool autoInit=true);
    ~TTbarNNLORecursiveRew();
    
    void SetInputDirectory(const std::string& dirName);
    void SetInputSuffix(const std::string& suffix);
    void SetSampleID(int sampleID);
    void SetSystVar(int systVar);
    void SetRewList(std::vector<std::string> list);
    void AddRew(std::string rew);
    void SetDefault3D();
    void SetDefault2D();
    void SetInverted2D();
    void Init();
    
    double Reweight(double x,int idx=0) const;
    double GetWeight(double Top_pt,double ATop_pt,double TTbar_M,double TTbar_Pt) const;
    
  private:
    int m_sampleId;
    int m_systVar;
    std::string m_dir;
    std::string m_suffix;
    unsigned int m_Nrew;
    std::vector<std::unique_ptr<TH1> > m_h_nnlo;
    std::vector<std::unique_ptr<TH1> > m_h_mc;
    std::vector<std::string> m_rewList;
};

#endif
