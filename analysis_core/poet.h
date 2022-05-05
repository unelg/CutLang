#ifndef poet_h
#define poet_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "dbxParticle.h"
#include "Node.h"
#include "TRefArray.h"
#include "TRef.h"
// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"

class poet {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Declaration of leaf types
   std::vector<float>   *muon_e;
   std::vector<float>   *muon_pt;
   std::vector<float>   *muon_px;
   std::vector<float>   *muon_py;
   std::vector<float>   *muon_pz;
   std::vector<float>   *muon_eta;
   std::vector<float>   *muon_phi;
   std::vector<float>   *muon_ch;
   std::vector<int>     *muon_isSoft;
   std::vector<int>     *muon_isTight;
   std::vector<float>   *muon_dxy;
   std::vector<float>   *muon_dz;
   std::vector<float>   *muon_dxyError;
   std::vector<float>   *muon_dzError;
   std::vector<float>   *muon_pfreliso03all;
   std::vector<float>   *muon_pfreliso04all;
   std::vector<float>   *muon_jetidx;
   std::vector<float>   *muon_genpartidx;

   std::vector<float>   *electron_e;
   std::vector<float>   *electron_pt;
   std::vector<float>   *electron_px;
   std::vector<float>   *electron_py;
   std::vector<float>   *electron_pz;
   std::vector<float>   *electron_eta;
   std::vector<float>   *electron_phi;
   std::vector<float>   *electron_ch;
   std::vector<float>   *electron_iso;
   std::vector<bool>    *electron_isLoose;
   std::vector<bool>    *electron_isMedium;
   std::vector<bool>    *electron_isTight;
   std::vector<float>   *electron_dxy;
   std::vector<float>   *electron_dz;
   std::vector<float>   *electron_dxyError;
   std::vector<float>   *electron_dzError;

   std::vector<float>   *tau_e;         
   std::vector<float>   *tau_pt;        
   std::vector<float>   *tau_px;        
   std::vector<float>   *tau_py;        
   std::vector<float>   *tau_pz;        
   std::vector<float>   *tau_eta;       
   std::vector<float>   *tau_phi;       
   std::vector<float>   *tau_ch ;       
   std::vector<float>   *tau_mass;      
   std::vector<float>   *tau_decaymode; 
   std::vector<float>   *tau_iddecaymode;
   std::vector<float>   *tau_idisoraw   ;
   std::vector<float>   *tau_idisovloose;
   std::vector<float>   *tau_idisoloose ;
   std::vector<float>   *tau_idisomedium;
   std::vector<float>   *tau_idisotight ;
   std::vector<float>   *tau_idantieletight;
   std::vector<float>   *tau_idantimutight;

   std::vector<float>*  jet_e           ; 
   std::vector<float>*  jet_pt          ; 
   std::vector<float>*  jet_px          ; 
   std::vector<float>*  jet_py          ; 
   std::vector<float>*  jet_pz          ; 
   std::vector<float>*  jet_eta         ; 
   std::vector<float>*  jet_phi         ; 
   std::vector<float>*  jet_ch          ; 
   std::vector<float>*  jet_mass        ; 
   std::vector<double>* jet_btag        ; 
   std::vector<float>*  jet_pt_uncorr   ; 

   std::vector<float>   *photon_e        ;
   std::vector<float>   *photon_pt       ;
   std::vector<float>   *photon_px       ;
   std::vector<float>   *photon_py       ;
   std::vector<float>   *photon_pz       ;
   std::vector<float>   *photon_eta      ;
   std::vector<float>   *photon_phi      ;
   std::vector<float>   *photon_ch       ;
   std::vector<float>   *photon_chIso    ;
   std::vector<float>   *photon_nhIso    ;
   std::vector<float>   *photon_phIso    ;
   std::vector<bool>    *photon_isLoose  ;
   std::vector<bool>    *photon_isMedium ;
   std::vector<bool>    *photon_isTight  ;

  float   met_e           ;
  float   met_pt          ;
  float   met_px          ;
  float   met_py          ;
  float   met_phi         ;
  float   met_significance;
  float   met_rawpt       ;
  float   met_rawphi      ;
  float   met_rawe        ;



// List of branches
   TBranch   *b_muon_e;   //!
   TBranch   *b_muon_pt;   //!
   TBranch   *b_muon_px;   //!
   TBranch   *b_muon_py;   //!
   TBranch   *b_muon_pz;   //!
   TBranch   *b_muon_eta;   //!
   TBranch   *b_muon_phi;   //!
   TBranch   *b_muon_ch;   //!
   TBranch   *b_muon_isSoft;   //!
   TBranch   *b_muon_isTight;   //!
   TBranch   *b_muon_dxy;   //!
   TBranch   *b_muon_dz;   //!
   TBranch   *b_muon_dxyError;   //!
   TBranch   *b_muon_dzError;   //!
   TBranch   *b_muon_pfreliso03all;   //!
   TBranch   *b_muon_pfreliso04all;   //!
   TBranch   *b_muon_jetidx;   //!
   TBranch   *b_muon_genpartidx;   //!

   TBranch   *b_electron_e;
   TBranch   *b_electron_pt;
   TBranch   *b_electron_px;
   TBranch   *b_electron_py;
   TBranch   *b_electron_pz;
   TBranch   *b_electron_eta;
   TBranch   *b_electron_phi;
   TBranch   *b_electron_ch;
   TBranch   *b_electron_iso;
   TBranch   *b_electron_isLoose;
   TBranch   *b_electron_isMedium;
   TBranch   *b_electron_isTight;
   TBranch   *b_electron_dxy;
   TBranch   *b_electron_dz;
   TBranch   *b_electron_dxyError;
   TBranch   *b_electron_dzError;

   TBranch   *b_tau_e;         
   TBranch   *b_tau_pt;        
   TBranch   *b_tau_px;        
   TBranch   *b_tau_py;        
   TBranch   *b_tau_pz;        
   TBranch   *b_tau_eta;       
   TBranch   *b_tau_phi;       
   TBranch   *b_tau_ch ;       
   TBranch   *b_tau_mass;      
   TBranch   *b_tau_decaymode; 
   TBranch   *b_tau_iddecaymode;
   TBranch   *b_tau_idisoraw   ;
   TBranch   *b_tau_idisovloose;
   TBranch   *b_tau_idisoloose ;
   TBranch   *b_tau_idisomedium;
   TBranch   *b_tau_idisotight ;
   TBranch   *b_tau_idantieletight;
   TBranch   *b_tau_idantimutight;

   TBranch   *b_jet_e           ; 
   TBranch   *b_jet_pt          ; 
   TBranch   *b_jet_px          ; 
   TBranch   *b_jet_py          ; 
   TBranch   *b_jet_pz          ; 
   TBranch   *b_jet_eta         ; 
   TBranch   *b_jet_phi         ; 
   TBranch   *b_jet_ch          ; 
   TBranch   *b_jet_mass        ; 
   TBranch   *b_jet_btag        ; 
   TBranch   *b_jet_pt_uncorr   ; 

   TBranch   *b_photon_e        ;
   TBranch   *b_photon_pt       ;
   TBranch   *b_photon_px       ;
   TBranch   *b_photon_py       ;
   TBranch   *b_photon_pz       ;
   TBranch   *b_photon_eta      ;
   TBranch   *b_photon_phi      ;
   TBranch   *b_photon_ch       ;
   TBranch   *b_photon_chIso    ;
   TBranch   *b_photon_nhIso    ;
   TBranch   *b_photon_phIso    ;
   TBranch   *b_photon_isLoose  ;
   TBranch   *b_photon_isMedium ;
   TBranch   *b_photon_isTight  ;

   TBranch   *b_met_e           ;
   TBranch   *b_met_pt          ;
   TBranch   *b_met_px          ;
   TBranch   *b_met_py          ;
   TBranch   *b_met_phi         ;
   TBranch   *b_met_significance;
   TBranch   *b_met_rawpt       ;
   TBranch   *b_met_rawphi      ;
   TBranch   *b_met_rawe        ;


   poet(char *file_name, TChain *tree=0);
   virtual ~poet();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     GetPhysicsObjects(Long64_t entry, AnalysisObjects *a0, Long64_t nentries );
   virtual void     Loop(analy_struct aselect, char *extname);

};

#endif

#ifdef poet_cxx
//                XXXX           chain
poet::poet(char *file_name, TChain *tree) : fChain(0) 
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("Events");
     chain->Add(file_name);
  }

  if (tree == 0) {
     Init(chain);
  } else {
     Init(tree);
  }
  
}
poet::~poet()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t poet::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t poet::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void poet::Init(TChain *tree)
{
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;

//------------e,m,t
     electron_e=0;
     electron_pt=0;
     electron_px=0;
     electron_py=0;
     electron_pz=0;
     electron_eta=0;
     electron_phi=0;
     electron_ch=0;
     electron_iso=0;
     electron_isLoose=0;
     electron_isMedium=0;
     electron_isTight=0;
     electron_dxy=0;
     electron_dz=0;
     electron_dxyError=0;
     electron_dzError=0;

     muon_e=0;
     muon_pt=0;
     muon_px=0;
     muon_py=0;
     muon_pz=0;
     muon_eta=0;
     muon_phi=0;
     muon_ch=0;
     muon_isSoft=0;
     muon_isTight=0;
     muon_dxy=0;
     muon_dz=0;
     muon_dxyError=0;
     muon_dzError=0;
     muon_pfreliso03all=0;
     muon_pfreliso04all=0;
     muon_jetidx=0;
     muon_genpartidx=0;

    tau_e=0;         
    tau_pt=0;        
    tau_px=0;        
    tau_py=0;        
    tau_pz=0;        
    tau_eta=0;       
    tau_phi=0;       
    tau_ch =0;       
    tau_mass=0;      
    tau_decaymode=0; 
    tau_iddecaymode=0;
    tau_idisoraw   =0;
    tau_idisovloose=0;
    tau_idisoloose =0;
    tau_idisomedium=0;
    tau_idisotight =0;
    tau_idantieletight=0;
    tau_idantimutight=0;
                      
   jet_e=0; 
   jet_pt=0; 
   jet_px=0; 
   jet_py=0; 
   jet_pz=0; 
   jet_eta=0; 
   jet_phi=0; 
   jet_ch=0; 
   jet_mass=0; 
   jet_btag=0; 
   jet_pt_uncorr=0; 

   photon_e        =0;
   photon_pt       =0;
   photon_px       =0;
   photon_py       =0;
   photon_pz       =0;
   photon_eta      =0;
   photon_phi      =0;
   photon_ch       =0;
   photon_chIso    =0;
   photon_nhIso    =0;
   photon_phIso    =0;
   photon_isLoose  =0;
   photon_isMedium =0;
   photon_isTight  =0;



 //  fChain->SetMakeClass(1);

//   fChain->SetBranchAddress("numbermuon", &numbermuon, &b_numbermuon);
//   fChain->SetBranchAddress("muon_pt", &muon_pt, &b_muon_pt);
//   fChain->SetBranchAddress("muon_eta", &muon_eta, &b_muon_eta);
//   fChain->SetBranchAddress("muon_phi", &muon_phi, &b_muon_phi);
   fChain->SetBranchAddress("muon_e", &muon_e, &b_muon_e);
   fChain->SetBranchAddress("muon_px", &muon_px, &b_muon_px);
   fChain->SetBranchAddress("muon_py", &muon_py, &b_muon_py);
   fChain->SetBranchAddress("muon_pz", &muon_pz, &b_muon_pz);
   fChain->SetBranchAddress("muon_ch", &muon_ch, &b_muon_ch);
//   fChain->SetBranchAddress("muon_isSoft", &muon_isSoft, &b_muon_isSoft);
   fChain->SetBranchAddress("muon_isTight", &muon_isTight, &b_muon_isTight);
//   fChain->SetBranchAddress("muon_dxy", &muon_dxy, &b_muon_dxy);
//   fChain->SetBranchAddress("muon_dz", &muon_dz, &b_muon_dz);
//   fChain->SetBranchAddress("muon_dxyError", &muon_dxyError, &b_muon_dxyError);
//   fChain->SetBranchAddress("muon_dzError", &muon_dzError, &b_muon_dzError);
//   fChain->SetBranchAddress("muon_pfreliso03all", &muon_pfreliso03all, &b_muon_pfreliso03all);
//   fChain->SetBranchAddress("muon_pfreliso04all", &muon_pfreliso04all, &b_muon_pfreliso04all);
//   fChain->SetBranchAddress("muon_jetidx", &muon_jetidx, &b_muon_jetidx);
//   fChain->SetBranchAddress("muon_genpartidx", &muon_genpartidx, &b_muon_genpartidx);


   fChain->SetBranchAddress("electron_e",  &electron_e,  &b_electron_e);
   fChain->SetBranchAddress("electron_px", &electron_px, &b_electron_px);
   fChain->SetBranchAddress("electron_py", &electron_py, &b_electron_py);
   fChain->SetBranchAddress("electron_pz", &electron_pz, &b_electron_pz);
   fChain->SetBranchAddress("electron_ch", &electron_ch, &b_electron_ch);
   fChain->SetBranchAddress("electron_isLoose", &electron_isLoose, &b_electron_isLoose);
   fChain->SetBranchAddress("electron_isMedium", &electron_isMedium, &b_electron_isMedium);
   fChain->SetBranchAddress("electron_isTight", &electron_isTight, &b_electron_isTight);


   fChain->SetBranchAddress("photon_e",  &photon_e,  &b_photon_e);
   fChain->SetBranchAddress("photon_px", &photon_px, &b_photon_px);
   fChain->SetBranchAddress("photon_py", &photon_py, &b_photon_py);
   fChain->SetBranchAddress("photon_pz", &photon_pz, &b_photon_pz);
//   fChain->SetBranchAddress("photon_ch", &photon_ch, &b_photon_ch);

   fChain->SetBranchAddress("jet_e",  &jet_e,  &b_jet_e);
   fChain->SetBranchAddress("jet_px", &jet_px, &b_jet_px);
   fChain->SetBranchAddress("jet_py", &jet_py, &b_jet_py);
   fChain->SetBranchAddress("jet_pz", &jet_pz, &b_jet_pz);
   fChain->SetBranchAddress("jet_ch", &jet_ch, &b_jet_ch);

   fChain->SetBranchAddress("tau_e",  &tau_e,  &b_tau_e);
   fChain->SetBranchAddress("tau_px", &tau_px, &b_tau_px);
   fChain->SetBranchAddress("tau_py", &tau_py, &b_tau_py);
   fChain->SetBranchAddress("tau_pz", &tau_pz, &b_tau_pz);
   fChain->SetBranchAddress("tau_ch", &tau_ch, &b_tau_ch);

}

#endif // #ifdef __poet
