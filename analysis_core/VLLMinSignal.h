//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 18 20:09:46 2019 by ROOT version 6.11/02
// from TTree physics/xAOD->NTuple tree
// found on file: mc16_13TeV.311528.CompHepPythia8EvtGen_A14NNPDF23LO_WjjnuZlle150GeV.deriv.DAOD_EXOT12.e7404_a875_r9364_p3638.root
//////////////////////////////////////////////////////////

#ifndef VLLMinSignal_h
#define VLLMinSignal_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "TClonesArray.h"
#include "TObject.h"
#include "dbxParticle.h"
#include "Node.h"

// Header file for the classes stored in the TTree if any.
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "vector"
#include "string"

using namespace std;

class VLLMinSignal {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_e17_lhloose_nod0_mu14 = 4;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_2e12_lhloose_L12EM10VH = 9;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0 = 9;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_mu22_mu8noL1 = 3;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_e17_lhloose_mu14 = 4;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_mu18_mu8noL1 = 3;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI = 1;
   static constexpr Int_t kMaxtrigMatchedPairs_HLT_2e24_lhvloose_nod0 = 1;

   // Declaration of leaf types
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   ULong64_t       mcEventNumber;
   vector<float>   *mcEventWeights;
   UInt_t          mcChannelNumber;
   UInt_t          randomRunNumber;
   Float_t         averageMu;
   Float_t         averageMuScaled;
   Float_t         actualMu;
   Float_t         actualMuScaled;
   Float_t         pileupWeight_NOSYS;
   Bool_t          trigPassed_HLT_2e12_lhloose_L12EM10VH;
   Bool_t          trigPassed_HLT_2e17_lhvloose_nod0;
   Bool_t          trigPassed_HLT_e17_lhloose_nod0_mu14;
   Bool_t          trigPassed_HLT_e17_lhloose_mu14;
   Bool_t          trigPassed_HLT_mu22_mu8noL1;
   Bool_t          trigPassed_HLT_mu18_mu8noL1;
   Bool_t          trigPassed_HLT_2e17_lhvloose_nod0_L12EM15VHI;
   Bool_t          trigPassed_HLT_2e24_lhvloose_nod0;
   Int_t           trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_;
   UChar_t         trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_first[kMaxtrigMatchedPairs_HLT_e17_lhloose_nod0_mu14];   //[trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_]
   UChar_t         trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_second[kMaxtrigMatchedPairs_HLT_e17_lhloose_nod0_mu14];   //[trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_]
   Int_t           trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_;
   UChar_t         trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_first[kMaxtrigMatchedPairs_HLT_2e12_lhloose_L12EM10VH];   //[trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_]
   UChar_t         trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_second[kMaxtrigMatchedPairs_HLT_2e12_lhloose_L12EM10VH];   //[trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_]
   Int_t           trigMatchedPairs_HLT_2e17_lhvloose_nod0_;
   UChar_t         trigMatchedPairs_HLT_2e17_lhvloose_nod0_first[kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0];   //[trigMatchedPairs_HLT_2e17_lhvloose_nod0_]
   UChar_t         trigMatchedPairs_HLT_2e17_lhvloose_nod0_second[kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0];   //[trigMatchedPairs_HLT_2e17_lhvloose_nod0_]
   Int_t           trigMatchedPairs_HLT_mu22_mu8noL1_;
   UChar_t         trigMatchedPairs_HLT_mu22_mu8noL1_first[kMaxtrigMatchedPairs_HLT_mu22_mu8noL1];   //[trigMatchedPairs_HLT_mu22_mu8noL1_]
   UChar_t         trigMatchedPairs_HLT_mu22_mu8noL1_second[kMaxtrigMatchedPairs_HLT_mu22_mu8noL1];   //[trigMatchedPairs_HLT_mu22_mu8noL1_]
   Int_t           trigMatchedPairs_HLT_e17_lhloose_mu14_;
   UChar_t         trigMatchedPairs_HLT_e17_lhloose_mu14_first[kMaxtrigMatchedPairs_HLT_e17_lhloose_mu14];   //[trigMatchedPairs_HLT_e17_lhloose_mu14_]
   UChar_t         trigMatchedPairs_HLT_e17_lhloose_mu14_second[kMaxtrigMatchedPairs_HLT_e17_lhloose_mu14];   //[trigMatchedPairs_HLT_e17_lhloose_mu14_]
   Int_t           trigMatchedPairs_HLT_mu18_mu8noL1_;
   UChar_t         trigMatchedPairs_HLT_mu18_mu8noL1_first[kMaxtrigMatchedPairs_HLT_mu18_mu8noL1];   //[trigMatchedPairs_HLT_mu18_mu8noL1_]
   UChar_t         trigMatchedPairs_HLT_mu18_mu8noL1_second[kMaxtrigMatchedPairs_HLT_mu18_mu8noL1];   //[trigMatchedPairs_HLT_mu18_mu8noL1_]
   Int_t           trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_;
   UChar_t         trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_first[kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI];   //[trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_]
   UChar_t         trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_second[kMaxtrigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI];   //[trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_]
   Int_t           trigMatchedPairs_HLT_2e24_lhvloose_nod0_;
   UChar_t         trigMatchedPairs_HLT_2e24_lhvloose_nod0_first[kMaxtrigMatchedPairs_HLT_2e24_lhvloose_nod0];   //[trigMatchedPairs_HLT_2e24_lhvloose_nod0_]
   UChar_t         trigMatchedPairs_HLT_2e24_lhvloose_nod0_second[kMaxtrigMatchedPairs_HLT_2e24_lhvloose_nod0];   //[trigMatchedPairs_HLT_2e24_lhvloose_nod0_]
   Float_t         JVTEfficiency_NOSYS;
   Float_t         fJVTEfficiency_NOSYS;
   Float_t         FTagEfficiency_MV2c10_FixedCutBEff_77_NOSYS;
   vector<float>   *jet_m;
   vector<float>   *jet_pt_NOSYS;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<char>    *jet_selected_NOSYS;
   vector<char>    *jet_FTag_MV2c10_FixedCutBEff_77_NOSYS;
   vector<float>   *el_m;
   vector<float>   *el_pt_NOSYS;
   vector<float>   *el_eta;
   vector<float>   *el_caloCluster_eta;
   vector<float>   *el_phi;
   vector<float>   *el_charge;
   vector<char>    *el_selected_NOSYS;
   vector<char>    *el_likelihood_Tight;
   vector<char>    *el_isIsolated_FCLoose_NOSYS;
   vector<float>   *el_effSF_Reco_NOSYS;
   vector<float>   *el_effSF_PID_Tight_NOSYS;
   vector<float>   *el_effSF_Isol_Tight_FCLoose_NOSYS;
   vector<float>   *el_effSF_Chflip_Tight_FCLoose_NOSYS;
   vector<float>   *el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS;
   vector<float>   *el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS;
   vector<float>   *el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS;
   vector<float>   *el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS;
   vector<float>   *el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS;
   vector<float>   *el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS;
   vector<unsigned int> *el_truthClassification;
   vector<char>    *el_truthSignal;
   vector<int>     *el_truthType;
   vector<int>     *el_truthOrigin;
   vector<int>     *el_firstEgMotherPdgId;
   vector<int>     *el_firstEgMotherTruthType;
   vector<int>     *el_firstEgMotherTruthOrigin;
   vector<float>   *mu_m;
   vector<float>   *mu_pt_NOSYS;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_charge;
   vector<char>    *mu_selected_NOSYS;
   vector<char>    *mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS;
   vector<float>   *mu_effSF_Reco_NOSYS;
   vector<float>   *mu_effSF_TTVA_NOSYS;
   vector<float>   *mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS;
   vector<float>   *mu_effMC_Trig_Medium_HLT_mu22_NOSYS;
   vector<float>   *mu_effData_Trig_Medium_HLT_mu22_NOSYS;
   vector<float>   *mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS;
   vector<float>   *mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS;
   vector<float>   *mu_effMC_Trig_Medium_HLT_mu14_NOSYS;
   vector<float>   *mu_effData_Trig_Medium_HLT_mu14_NOSYS;
   vector<float>   *mu_effMC_Trig_Medium_HLT_mu18_NOSYS;
   vector<float>   *mu_effData_Trig_Medium_HLT_mu18_NOSYS;
   vector<unsigned int> *mu_truthClassification;
   vector<char>    *mu_truthSignal;
   vector<int>     *mu_truthType;
   vector<int>     *mu_truthOrigin;
   vector<string>  *met_name;
   vector<double>  *met_NOSYS;
   vector<double>  *met_px_NOSYS;
   vector<double>  *met_py_NOSYS;
   vector<double>  *met_phi_NOSYS;
   vector<double>  *met_sumet_NOSYS;
   vector<float>   *met_significance_NOSYS;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_mcEventNumber;   //!
   TBranch        *b_mcEventWeights;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_averageMu;   //!
   TBranch        *b_averageMuScaled;   //!
   TBranch        *b_actualMu;   //!
   TBranch        *b_actualMuScaled;   //!
   TBranch        *b_pileupWeight_NOSYS;   //!
   TBranch        *b_trigPassed_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_trigPassed_HLT_2e17_lhvloose_nod0;   //!
   TBranch        *b_trigPassed_HLT_e17_lhloose_nod0_mu14;   //!
   TBranch        *b_trigPassed_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_trigPassed_HLT_mu22_mu8noL1;   //!
   TBranch        *b_trigPassed_HLT_mu18_mu8noL1;   //!
   TBranch        *b_trigPassed_HLT_2e17_lhvloose_nod0_L12EM15VHI;   //!
   TBranch        *b_trigPassed_HLT_2e24_lhvloose_nod0;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu22_mu8noL1_;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu22_mu8noL1_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu22_mu8noL1_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_mu14_;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_mu14_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_e17_lhloose_mu14_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu18_mu8noL1_;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu18_mu8noL1_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_mu18_mu8noL1_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_second;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_first;   //!
   TBranch        *b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_second;   //!
   TBranch        *b_JVTEfficiency_NOSYS;   //!
   TBranch        *b_fJVTEfficiency_NOSYS;   //!
   TBranch        *b_FTagEfficiency_MV2c10_FixedCutBEff_77_NOSYS;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet_pt_NOSYS;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_selected_NOSYS;   //!
   TBranch        *b_jet_FTag_MV2c10_FixedCutBEff_77_NOSYS;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_el_pt_NOSYS;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_caloCluster_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_selected_NOSYS;   //!
   TBranch        *b_el_likelihood_Tight;   //!
   TBranch        *b_el_isIsolated_FCLoose_NOSYS;   //!
   TBranch        *b_el_effSF_Reco_NOSYS;   //!
   TBranch        *b_el_effSF_PID_Tight_NOSYS;   //!
   TBranch        *b_el_effSF_Isol_Tight_FCLoose_NOSYS;   //!
   TBranch        *b_el_effSF_Chflip_Tight_FCLoose_NOSYS;   //!
   TBranch        *b_el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS;   //!
   TBranch        *b_el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS;   //!
   TBranch        *b_el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS;   //!
   TBranch        *b_el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS;   //!
   TBranch        *b_el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS;   //!
   TBranch        *b_el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS;   //!
   TBranch        *b_el_truthClassification;   //!
   TBranch        *b_el_truthSignal;   //!
   TBranch        *b_el_truthType;   //!
   TBranch        *b_el_truthOrigin;   //!
   TBranch        *b_el_firstEgMotherPdgId;   //!
   TBranch        *b_el_firstEgMotherTruthType;   //!
   TBranch        *b_el_firstEgMotherTruthOrigin;   //!
   TBranch        *b_mu_m;   //!
   TBranch        *b_mu_pt_NOSYS;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_selected_NOSYS;   //!
   TBranch        *b_mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS;   //!
   TBranch        *b_mu_effSF_Reco_NOSYS;   //!
   TBranch        *b_mu_effSF_TTVA_NOSYS;   //!
   TBranch        *b_mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS;   //!
   TBranch        *b_mu_effMC_Trig_Medium_HLT_mu22_NOSYS;   //!
   TBranch        *b_mu_effData_Trig_Medium_HLT_mu22_NOSYS;   //!
   TBranch        *b_mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS;   //!
   TBranch        *b_mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS;   //!
   TBranch        *b_mu_effMC_Trig_Medium_HLT_mu14_NOSYS;   //!
   TBranch        *b_mu_effData_Trig_Medium_HLT_mu14_NOSYS;   //!
   TBranch        *b_mu_effMC_Trig_Medium_HLT_mu18_NOSYS;   //!
   TBranch        *b_mu_effData_Trig_Medium_HLT_mu18_NOSYS;   //!
   TBranch        *b_mu_truthClassification;   //!
   TBranch        *b_mu_truthSignal;   //!
   TBranch        *b_mu_truthType;   //!
   TBranch        *b_mu_truthOrigin;   //!
   TBranch        *b_met_name;   //!
   TBranch        *b_met_NOSYS;   //!
   TBranch        *b_met_px_NOSYS;   //!
   TBranch        *b_met_py_NOSYS;   //!
   TBranch        *b_met_phi_NOSYS;   //!
   TBranch        *b_met_sumet_NOSYS;   //!
   TBranch        *b_met_significance_NOSYS;   //!

    VLLMinSignal(char *file_name, TChain *tree=0, int year=2012);
    virtual ~VLLMinSignal();
    virtual Int_t    Cut(Long64_t entry);
    virtual Int_t    GetEntry(Long64_t entry);
    virtual void     GetPhysicsObjects(Long64_t entry, AnalysisObjects *a0);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree, int year);
    virtual void     Loop(analy_struct aselect, char *sampletype);
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef VLLMinSignal_cxx
VLLMinSignal::VLLMinSignal( char *file_name, TChain *tree, int year) : fChain(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
    TChain* chain;
    if (tree == 0) {
        chain = new TChain("/physics/nominal");
        chain->Add(file_name);
    }
    if (tree == 0) {
        Init(chain, year);
    } else {
        Init(tree, year);
    }
}

VLLMinSignal::~VLLMinSignal()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t VLLMinSignal::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t VLLMinSignal::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void VLLMinSignal::Init(TTree *tree, int year)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mcEventWeights = 0;
   jet_m = 0;
   jet_pt_NOSYS = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_selected_NOSYS = 0;
   jet_FTag_MV2c10_FixedCutBEff_77_NOSYS = 0;
   el_m = 0;
   el_pt_NOSYS = 0;
   el_eta = 0;
   el_caloCluster_eta = 0;
   el_phi = 0;
   el_charge = 0;
   el_selected_NOSYS = 0;
   el_likelihood_Tight = 0;
   el_isIsolated_FCLoose_NOSYS = 0;
   el_effSF_Reco_NOSYS = 0;
   el_effSF_PID_Tight_NOSYS = 0;
   el_effSF_Isol_Tight_FCLoose_NOSYS = 0;
   el_effSF_Chflip_Tight_FCLoose_NOSYS = 0;
   el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS = 0;
   el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS = 0;
   el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS = 0;
   el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS = 0;
   el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS = 0;
   el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS = 0;
   el_truthClassification = 0;
   el_truthSignal = 0;
   el_truthType = 0;
   el_truthOrigin = 0;
   el_firstEgMotherPdgId = 0;
   el_firstEgMotherTruthType = 0;
   el_firstEgMotherTruthOrigin = 0;
   mu_m = 0;
   mu_pt_NOSYS = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_charge = 0;
   mu_selected_NOSYS = 0;
   mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS = 0;
   mu_effSF_Reco_NOSYS = 0;
   mu_effSF_TTVA_NOSYS = 0;
   mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS = 0;
   mu_effMC_Trig_Medium_HLT_mu22_NOSYS = 0;
   mu_effData_Trig_Medium_HLT_mu22_NOSYS = 0;
   mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS = 0;
   mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS = 0;
   mu_effMC_Trig_Medium_HLT_mu14_NOSYS = 0;
   mu_effData_Trig_Medium_HLT_mu14_NOSYS = 0;
   mu_effMC_Trig_Medium_HLT_mu18_NOSYS = 0;
   mu_effData_Trig_Medium_HLT_mu18_NOSYS = 0;
   mu_truthClassification = 0;
   mu_truthSignal = 0;
   mu_truthType = 0;
   mu_truthOrigin = 0;
   met_name = 0;
   met_NOSYS = 0;
   met_px_NOSYS = 0;
   met_py_NOSYS = 0;
   met_phi_NOSYS = 0;
   met_sumet_NOSYS = 0;
   met_significance_NOSYS = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("mcEventNumber", &mcEventNumber, &b_mcEventNumber);
   fChain->SetBranchAddress("mcEventWeights", &mcEventWeights, &b_mcEventWeights);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("averageMu", &averageMu, &b_averageMu);
   fChain->SetBranchAddress("averageMuScaled", &averageMuScaled, &b_averageMuScaled);
   fChain->SetBranchAddress("actualMu", &actualMu, &b_actualMu);
   fChain->SetBranchAddress("actualMuScaled", &actualMuScaled, &b_actualMuScaled);
   fChain->SetBranchAddress("pileupWeight_NOSYS", &pileupWeight_NOSYS, &b_pileupWeight_NOSYS);
   fChain->SetBranchAddress("trigPassed_HLT_2e12_lhloose_L12EM10VH", &trigPassed_HLT_2e12_lhloose_L12EM10VH, &b_trigPassed_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("trigPassed_HLT_2e17_lhvloose_nod0", &trigPassed_HLT_2e17_lhvloose_nod0, &b_trigPassed_HLT_2e17_lhvloose_nod0);
   fChain->SetBranchAddress("trigPassed_HLT_e17_lhloose_nod0_mu14", &trigPassed_HLT_e17_lhloose_nod0_mu14, &b_trigPassed_HLT_e17_lhloose_nod0_mu14);
   fChain->SetBranchAddress("trigPassed_HLT_e17_lhloose_mu14", &trigPassed_HLT_e17_lhloose_mu14, &b_trigPassed_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("trigPassed_HLT_mu22_mu8noL1", &trigPassed_HLT_mu22_mu8noL1, &b_trigPassed_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("trigPassed_HLT_mu18_mu8noL1", &trigPassed_HLT_mu18_mu8noL1, &b_trigPassed_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("trigPassed_HLT_2e17_lhvloose_nod0_L12EM15VHI", &trigPassed_HLT_2e17_lhvloose_nod0_L12EM15VHI, &b_trigPassed_HLT_2e17_lhvloose_nod0_L12EM15VHI);
   fChain->SetBranchAddress("trigPassed_HLT_2e24_lhvloose_nod0", &trigPassed_HLT_2e24_lhvloose_nod0, &b_trigPassed_HLT_2e24_lhvloose_nod0);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_nod0_mu14", &trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_, &b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_nod0_mu14.first", trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_first, &b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_nod0_mu14.second", trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_second, &b_trigMatchedPairs_HLT_e17_lhloose_nod0_mu14_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH", &trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_, &b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH.first", trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_first, &b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH.second", trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_second, &b_trigMatchedPairs_HLT_2e12_lhloose_L12EM10VH_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0", &trigMatchedPairs_HLT_2e17_lhvloose_nod0_, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0.first", trigMatchedPairs_HLT_2e17_lhvloose_nod0_first, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0.second", trigMatchedPairs_HLT_2e17_lhvloose_nod0_second, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu22_mu8noL1", &trigMatchedPairs_HLT_mu22_mu8noL1_, &b_trigMatchedPairs_HLT_mu22_mu8noL1_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu22_mu8noL1.first", trigMatchedPairs_HLT_mu22_mu8noL1_first, &b_trigMatchedPairs_HLT_mu22_mu8noL1_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu22_mu8noL1.second", trigMatchedPairs_HLT_mu22_mu8noL1_second, &b_trigMatchedPairs_HLT_mu22_mu8noL1_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_mu14", &trigMatchedPairs_HLT_e17_lhloose_mu14_, &b_trigMatchedPairs_HLT_e17_lhloose_mu14_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_mu14.first", trigMatchedPairs_HLT_e17_lhloose_mu14_first, &b_trigMatchedPairs_HLT_e17_lhloose_mu14_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_e17_lhloose_mu14.second", trigMatchedPairs_HLT_e17_lhloose_mu14_second, &b_trigMatchedPairs_HLT_e17_lhloose_mu14_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu18_mu8noL1", &trigMatchedPairs_HLT_mu18_mu8noL1_, &b_trigMatchedPairs_HLT_mu18_mu8noL1_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu18_mu8noL1.first", trigMatchedPairs_HLT_mu18_mu8noL1_first, &b_trigMatchedPairs_HLT_mu18_mu8noL1_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_mu18_mu8noL1.second", trigMatchedPairs_HLT_mu18_mu8noL1_second, &b_trigMatchedPairs_HLT_mu18_mu8noL1_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI", &trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI.first", &trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_first, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI.second", &trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_second, &b_trigMatchedPairs_HLT_2e17_lhvloose_nod0_L12EM15VHI_second);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e24_lhvloose_nod0", &trigMatchedPairs_HLT_2e24_lhvloose_nod0_, &b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e24_lhvloose_nod0.first", &trigMatchedPairs_HLT_2e24_lhvloose_nod0_first, &b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_first);
   fChain->SetBranchAddress("trigMatchedPairs_HLT_2e24_lhvloose_nod0.second", &trigMatchedPairs_HLT_2e24_lhvloose_nod0_second, &b_trigMatchedPairs_HLT_2e24_lhvloose_nod0_second);
   fChain->SetBranchAddress("JVTEfficiency_NOSYS", &JVTEfficiency_NOSYS, &b_JVTEfficiency_NOSYS);
   fChain->SetBranchAddress("fJVTEfficiency_NOSYS", &fJVTEfficiency_NOSYS, &b_fJVTEfficiency_NOSYS);
   fChain->SetBranchAddress("FTagEfficiency_MV2c10_FixedCutBEff_77_NOSYS", &FTagEfficiency_MV2c10_FixedCutBEff_77_NOSYS, &b_FTagEfficiency_MV2c10_FixedCutBEff_77_NOSYS);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet_pt_NOSYS", &jet_pt_NOSYS, &b_jet_pt_NOSYS);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_selected_NOSYS", &jet_selected_NOSYS, &b_jet_selected_NOSYS);
   fChain->SetBranchAddress("jet_FTag_MV2c10_FixedCutBEff_77_NOSYS", &jet_FTag_MV2c10_FixedCutBEff_77_NOSYS, &b_jet_FTag_MV2c10_FixedCutBEff_77_NOSYS);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("el_pt_NOSYS", &el_pt_NOSYS, &b_el_pt_NOSYS);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_caloCluster_eta", &el_caloCluster_eta, &b_el_caloCluster_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_selected_NOSYS", &el_selected_NOSYS, &b_el_selected_NOSYS);
   fChain->SetBranchAddress("el_likelihood_Tight", &el_likelihood_Tight, &b_el_likelihood_Tight);
   fChain->SetBranchAddress("el_isIsolated_FCLoose_NOSYS", &el_isIsolated_FCLoose_NOSYS, &b_el_isIsolated_FCLoose_NOSYS);
   fChain->SetBranchAddress("el_effSF_Reco_NOSYS", &el_effSF_Reco_NOSYS, &b_el_effSF_Reco_NOSYS);
   fChain->SetBranchAddress("el_effSF_PID_Tight_NOSYS", &el_effSF_PID_Tight_NOSYS, &b_el_effSF_PID_Tight_NOSYS);
   fChain->SetBranchAddress("el_effSF_Isol_Tight_FCLoose_NOSYS", &el_effSF_Isol_Tight_FCLoose_NOSYS, &b_el_effSF_Isol_Tight_FCLoose_NOSYS);
   fChain->SetBranchAddress("el_effSF_Chflip_Tight_FCLoose_NOSYS", &el_effSF_Chflip_Tight_FCLoose_NOSYS, &b_el_effSF_Chflip_Tight_FCLoose_NOSYS);
   fChain->SetBranchAddress("el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS", &el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS, &b_el_effSF_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS);
   fChain->SetBranchAddress("el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS", &el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS, &b_el_effMC_Trig_Tight_FCLoose_MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0_NOSYS);
   fChain->SetBranchAddress("el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS", &el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS, &b_el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS);
   fChain->SetBranchAddress("el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS", &el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS, &b_el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e17_lhvloose_nod0_L1EM15VHI_NOSYS);
   fChain->SetBranchAddress("el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS", &el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS, &b_el_effSF_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS);
   fChain->SetBranchAddress("el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS", &el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS, &b_el_effMC_Trig_Tight_FCLoose_DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH_NOSYS);
   fChain->SetBranchAddress("el_truthClassification", &el_truthClassification, &b_el_truthClassification);
   fChain->SetBranchAddress("el_truthSignal", &el_truthSignal, &b_el_truthSignal);
   fChain->SetBranchAddress("el_truthType", &el_truthType, &b_el_truthType);
   fChain->SetBranchAddress("el_truthOrigin", &el_truthOrigin, &b_el_truthOrigin);
   fChain->SetBranchAddress("el_firstEgMotherPdgId", &el_firstEgMotherPdgId, &b_el_firstEgMotherPdgId);
   fChain->SetBranchAddress("el_firstEgMotherTruthType", &el_firstEgMotherTruthType, &b_el_firstEgMotherTruthType);
   fChain->SetBranchAddress("el_firstEgMotherTruthOrigin", &el_firstEgMotherTruthOrigin, &b_el_firstEgMotherTruthOrigin);
   fChain->SetBranchAddress("mu_m", &mu_m, &b_mu_m);
   fChain->SetBranchAddress("mu_pt_NOSYS", &mu_pt_NOSYS, &b_mu_pt_NOSYS);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_selected_NOSYS", &mu_selected_NOSYS, &b_mu_selected_NOSYS);
   fChain->SetBranchAddress("mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS", &mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS, &b_mu_isIsolated_FCTightTrackOnly_FixedRad_NOSYS);
   fChain->SetBranchAddress("mu_effSF_Reco_NOSYS", &mu_effSF_Reco_NOSYS, &b_mu_effSF_Reco_NOSYS);
   fChain->SetBranchAddress("mu_effSF_TTVA_NOSYS", &mu_effSF_TTVA_NOSYS, &b_mu_effSF_TTVA_NOSYS);
   fChain->SetBranchAddress("mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS", &mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS, &b_mu_effSF_Isol_FCTightTrackOnly_FixedRad_NOSYS);
   fChain->SetBranchAddress("mu_effMC_Trig_Medium_HLT_mu22_NOSYS", &mu_effMC_Trig_Medium_HLT_mu22_NOSYS, &b_mu_effMC_Trig_Medium_HLT_mu22_NOSYS);
   fChain->SetBranchAddress("mu_effData_Trig_Medium_HLT_mu22_NOSYS", &mu_effData_Trig_Medium_HLT_mu22_NOSYS, &b_mu_effData_Trig_Medium_HLT_mu22_NOSYS);
   fChain->SetBranchAddress("mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS", &mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS, &b_mu_effMC_Trig_Medium_HLT_mu8noL1_NOSYS);
   fChain->SetBranchAddress("mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS", &mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS, &b_mu_effData_Trig_Medium_HLT_mu8noL1_NOSYS);
   fChain->SetBranchAddress("mu_effMC_Trig_Medium_HLT_mu14_NOSYS", &mu_effMC_Trig_Medium_HLT_mu14_NOSYS, &b_mu_effMC_Trig_Medium_HLT_mu14_NOSYS);
   fChain->SetBranchAddress("mu_effData_Trig_Medium_HLT_mu14_NOSYS", &mu_effData_Trig_Medium_HLT_mu14_NOSYS, &b_mu_effData_Trig_Medium_HLT_mu14_NOSYS);
   fChain->SetBranchAddress("mu_effMC_Trig_Medium_HLT_mu18_NOSYS", &mu_effMC_Trig_Medium_HLT_mu18_NOSYS, &b_mu_effMC_Trig_Medium_HLT_mu18_NOSYS);
   fChain->SetBranchAddress("mu_effData_Trig_Medium_HLT_mu18_NOSYS", &mu_effData_Trig_Medium_HLT_mu18_NOSYS, &b_mu_effData_Trig_Medium_HLT_mu18_NOSYS);
   fChain->SetBranchAddress("mu_truthClassification", &mu_truthClassification, &b_mu_truthClassification);
   fChain->SetBranchAddress("mu_truthSignal", &mu_truthSignal, &b_mu_truthSignal);
   fChain->SetBranchAddress("mu_truthType", &mu_truthType, &b_mu_truthType);
   fChain->SetBranchAddress("mu_truthOrigin", &mu_truthOrigin, &b_mu_truthOrigin);
   fChain->SetBranchAddress("met_name", &met_name, &b_met_name);
   fChain->SetBranchAddress("met_NOSYS", &met_NOSYS, &b_met_NOSYS);
   fChain->SetBranchAddress("met_px_NOSYS", &met_px_NOSYS, &b_met_px_NOSYS);
   fChain->SetBranchAddress("met_py_NOSYS", &met_py_NOSYS, &b_met_py_NOSYS);
   fChain->SetBranchAddress("met_phi_NOSYS", &met_phi_NOSYS, &b_met_phi_NOSYS);
   fChain->SetBranchAddress("met_sumet_NOSYS", &met_sumet_NOSYS, &b_met_sumet_NOSYS);
   fChain->SetBranchAddress("met_significance_NOSYS", &met_significance_NOSYS, &b_met_significance_NOSYS);
   Notify();
}

Bool_t VLLMinSignal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void VLLMinSignal::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t VLLMinSignal::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef VLLMinSignal_cxx
