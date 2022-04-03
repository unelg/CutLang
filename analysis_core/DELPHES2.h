//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Mar 31 14:18:48 2022 by ROOT version 6.26/00
// from TTree Delphes/Analysis tree
// found on file: /Users/ngu/Dropbox/cutlang/inputformats/UPSGDelphes.root
//////////////////////////////////////////////////////////

#ifndef DELPHES2_h
#define DELPHES2_h

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

class DELPHES2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxEvent = 1;
   static constexpr Int_t kMaxWeight = 1022;
   static constexpr Int_t kMaxParticle = 520;
   static constexpr Int_t kMaxVertex = 258;
   static constexpr Int_t kMaxGenJet = 14;
   static constexpr Int_t kMaxGenJetAK8 = 6;
   static constexpr Int_t kMaxGenMissingET = 1;
   static constexpr Int_t kMaxParticleFlowCandidate = 358;
   static constexpr Int_t kMaxPhoton = 39;
   static constexpr Int_t kMaxPhotonLoose = 8;
   static constexpr Int_t kMaxPhotonMedium = 8;
   static constexpr Int_t kMaxPhotonTight = 8;
   static constexpr Int_t kMaxElectron = 30;
   static constexpr Int_t kMaxElectronLoose = 5;
   static constexpr Int_t kMaxElectronMedium = 5;
   static constexpr Int_t kMaxElectronTight = 5;
   static constexpr Int_t kMaxMuon = 16;
   static constexpr Int_t kMaxMuonLoose = 5;
   static constexpr Int_t kMaxMuonMedium = 5;
   static constexpr Int_t kMaxMuonTight = 4;
   static constexpr Int_t kMaxJetPUPPI = 12;
   static constexpr Int_t kMaxJetPUPPIAK8 = 5;
   static constexpr Int_t kMaxJetPUPPILoose = 11;
   static constexpr Int_t kMaxJetPUPPITight = 10;
   static constexpr Int_t kMaxRho = 5;
   static constexpr Int_t kMaxPuppiMissingET = 1;
   static constexpr Int_t kMaxGenPileUpMissingET = 1;
   static constexpr Int_t kMaxScalarHT = 1;

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];   //[Event_]
   UInt_t          Event_fBits[kMaxEvent];   //[Event_]
   Long64_t        Event_Number[kMaxEvent];   //[Event_]
   Float_t         Event_ReadTime[kMaxEvent];   //[Event_]
   Float_t         Event_ProcTime[kMaxEvent];   //[Event_]
   Int_t           Event_ProcessID[kMaxEvent];   //[Event_]
   Int_t           Event_MPI[kMaxEvent];   //[Event_]
   Float_t         Event_Weight[kMaxEvent];   //[Event_]
   Float_t         Event_CrossSection[kMaxEvent];   //[Event_]
   Float_t         Event_CrossSectionError[kMaxEvent];   //[Event_]
   Float_t         Event_Scale[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQED[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQCD[kMaxEvent];   //[Event_]
   Int_t           Event_ID1[kMaxEvent];   //[Event_]
   Int_t           Event_ID2[kMaxEvent];   //[Event_]
   Float_t         Event_X1[kMaxEvent];   //[Event_]
   Float_t         Event_X2[kMaxEvent];   //[Event_]
   Float_t         Event_ScalePDF[kMaxEvent];   //[Event_]
   Float_t         Event_PDF1[kMaxEvent];   //[Event_]
   Float_t         Event_PDF2[kMaxEvent];   //[Event_]
   Int_t           Event_size;
   Int_t           Weight_;
   UInt_t          Weight_fUniqueID[kMaxWeight];   //[Weight_]
   UInt_t          Weight_fBits[kMaxWeight];   //[Weight_]
   Float_t         Weight_Weight[kMaxWeight];   //[Weight_]
   Int_t           Weight_size;
   Int_t           Particle_;
   UInt_t          Particle_fUniqueID[kMaxParticle];   //[Particle_]
   UInt_t          Particle_fBits[kMaxParticle];   //[Particle_]
   Int_t           Particle_PID[kMaxParticle];   //[Particle_]
   Int_t           Particle_Status[kMaxParticle];   //[Particle_]
   Int_t           Particle_IsPU[kMaxParticle];   //[Particle_]
   Int_t           Particle_M1[kMaxParticle];   //[Particle_]
   Int_t           Particle_M2[kMaxParticle];   //[Particle_]
   Int_t           Particle_D1[kMaxParticle];   //[Particle_]
   Int_t           Particle_D2[kMaxParticle];   //[Particle_]
   Int_t           Particle_Charge[kMaxParticle];   //[Particle_]
   Float_t         Particle_Mass[kMaxParticle];   //[Particle_]
   Float_t         Particle_E[kMaxParticle];   //[Particle_]
   Float_t         Particle_Px[kMaxParticle];   //[Particle_]
   Float_t         Particle_Py[kMaxParticle];   //[Particle_]
   Float_t         Particle_Pz[kMaxParticle];   //[Particle_]
   Float_t         Particle_P[kMaxParticle];   //[Particle_]
   Float_t         Particle_PT[kMaxParticle];   //[Particle_]
   Float_t         Particle_Eta[kMaxParticle];   //[Particle_]
   Float_t         Particle_Phi[kMaxParticle];   //[Particle_]
   Float_t         Particle_Rapidity[kMaxParticle];   //[Particle_]
   Float_t         Particle_T[kMaxParticle];   //[Particle_]
   Float_t         Particle_X[kMaxParticle];   //[Particle_]
   Float_t         Particle_Y[kMaxParticle];   //[Particle_]
   Float_t         Particle_Z[kMaxParticle];   //[Particle_]
   Int_t           Particle_size;
   Int_t           Vertex_;
   UInt_t          Vertex_fUniqueID[kMaxVertex];   //[Vertex_]
   UInt_t          Vertex_fBits[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_T[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_X[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_Y[kMaxVertex];   //[Vertex_]
   Float_t         Vertex_Z[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_ErrorT[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_ErrorX[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_ErrorY[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_ErrorZ[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_Index[kMaxVertex];   //[Vertex_]
   Int_t           Vertex_NDF[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_Sigma[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_SumPT2[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_GenSumPT2[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_GenDeltaZ[kMaxVertex];   //[Vertex_]
   Double_t        Vertex_BTVSumPT2[kMaxVertex];   //[Vertex_]
   TRefArray       Vertex_Constituents[kMaxVertex];
   Int_t           Vertex_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_T[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_Flavor[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_FlavorPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagAlgo[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTagPhys[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_TauWeight[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NCharged[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NNeutrals[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_NeutralEnergyFraction[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_ChargedEnergyFraction[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Beta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_BetaStar[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MeanSqDeltaR[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PTD[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_FracPt[kMaxGenJet][5];   //[GenJet_]
   Float_t         GenJet_Tau[kMaxGenJet][5];   //[GenJet_]
   TLorentzVector  GenJet_SoftDroppedJet[kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedSubJet1[kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedSubJet2[kMaxGenJet];
   TLorentzVector  GenJet_TrimmedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_PrunedP4[5][kMaxGenJet];
   TLorentzVector  GenJet_SoftDroppedP4[5][kMaxGenJet];
   Int_t           GenJet_NSubJetsTrimmed[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsPruned[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NSubJetsSoftDropped[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge23[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge34[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge45[kMaxGenJet];   //[GenJet_]
   Double_t        GenJet_ExclYmerge56[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   TLorentzVector  GenJet_Area[kMaxGenJet];
   Int_t           GenJet_size;
   Int_t           GenJetAK8_;
   UInt_t          GenJetAK8_fUniqueID[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_fBits[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_PT[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_Eta[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_Phi[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_T[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_Mass[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_DeltaEta[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_DeltaPhi[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_Flavor[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_FlavorAlgo[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_FlavorPhys[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_BTag[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_BTagAlgo[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_BTagPhys[kMaxGenJetAK8];   //[GenJetAK8_]
   UInt_t          GenJetAK8_TauTag[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_TauWeight[kMaxGenJetAK8];   //[GenJetAK8_]
   Int_t           GenJetAK8_Charge[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_EhadOverEem[kMaxGenJetAK8];   //[GenJetAK8_]
   Int_t           GenJetAK8_NCharged[kMaxGenJetAK8];   //[GenJetAK8_]
   Int_t           GenJetAK8_NNeutrals[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_NeutralEnergyFraction[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_ChargedEnergyFraction[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_Beta[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_BetaStar[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_MeanSqDeltaR[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_PTD[kMaxGenJetAK8];   //[GenJetAK8_]
   Float_t         GenJetAK8_FracPt[kMaxGenJetAK8][5];   //[GenJetAK8_]
   Float_t         GenJetAK8_Tau[kMaxGenJetAK8][5];   //[GenJetAK8_]
   TLorentzVector  GenJetAK8_SoftDroppedJet[kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_SoftDroppedSubJet1[kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_SoftDroppedSubJet2[kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_TrimmedP4[5][kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_PrunedP4[5][kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_SoftDroppedP4[5][kMaxGenJetAK8];
   Int_t           GenJetAK8_NSubJetsTrimmed[kMaxGenJetAK8];   //[GenJetAK8_]
   Int_t           GenJetAK8_NSubJetsPruned[kMaxGenJetAK8];   //[GenJetAK8_]
   Int_t           GenJetAK8_NSubJetsSoftDropped[kMaxGenJetAK8];   //[GenJetAK8_]
   Double_t        GenJetAK8_ExclYmerge23[kMaxGenJetAK8];   //[GenJetAK8_]
   Double_t        GenJetAK8_ExclYmerge34[kMaxGenJetAK8];   //[GenJetAK8_]
   Double_t        GenJetAK8_ExclYmerge45[kMaxGenJetAK8];   //[GenJetAK8_]
   Double_t        GenJetAK8_ExclYmerge56[kMaxGenJetAK8];   //[GenJetAK8_]
   TRefArray       GenJetAK8_Constituents[kMaxGenJetAK8];
   TRefArray       GenJetAK8_Particles[kMaxGenJetAK8];
   TLorentzVector  GenJetAK8_Area[kMaxGenJetAK8];
   Int_t           GenJetAK8_size;
   Int_t           GenMissingET_;
   UInt_t          GenMissingET_fUniqueID[kMaxGenMissingET];   //[GenMissingET_]
   UInt_t          GenMissingET_fBits[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_MET[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Eta[kMaxGenMissingET];   //[GenMissingET_]
   Float_t         GenMissingET_Phi[kMaxGenMissingET];   //[GenMissingET_]
   Int_t           GenMissingET_size;
   Int_t           ParticleFlowCandidate_;
   UInt_t          ParticleFlowCandidate_fUniqueID[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   UInt_t          ParticleFlowCandidate_fBits[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Int_t           ParticleFlowCandidate_PID[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Int_t           ParticleFlowCandidate_Charge[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_E[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_P[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_PT[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Eta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Phi[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_CtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_C[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Mass[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_EtaOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_PhiOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_T[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_X[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Y[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Z[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_TOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_XOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_YOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ZOuter[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Xd[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Yd[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Zd[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_L[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_D0[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_DZ[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Nclusters[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_dNdx[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorP[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorPT[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorPhi[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorCtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorT[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorD0[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorDZ[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorC[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorD0Phi[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorD0C[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorD0DZ[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorD0CtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorPhiC[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorPhiDZ[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorPhiCtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorCDZ[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorCCtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_ErrorDZCtgTheta[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Int_t           ParticleFlowCandidate_VertexIndex[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Int_t           ParticleFlowCandidate_NTimeHits[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Eem[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Ehad[kMaxParticleFlowCandidate];   //[ParticleFlowCandidate_]
   Float_t         ParticleFlowCandidate_Edges[kMaxParticleFlowCandidate][4];   //[ParticleFlowCandidate_]
   TRefArray       ParticleFlowCandidate_Particles[kMaxParticleFlowCandidate];
   Int_t           ParticleFlowCandidate_size;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   Float_t         Photon_T[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Float_t         Photon_IsolationVar[kMaxPhoton];   //[Photon_]
   Float_t         Photon_IsolationVarRhoCorr[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtCharged[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtNeutral[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPtChargedPU[kMaxPhoton];   //[Photon_]
   Float_t         Photon_SumPt[kMaxPhoton];   //[Photon_]
   Int_t           Photon_Status[kMaxPhoton];   //[Photon_]
   Int_t           Photon_size;
   Int_t           PhotonLoose_;
   UInt_t          PhotonLoose_fUniqueID[kMaxPhotonLoose];   //[PhotonLoose_]
   UInt_t          PhotonLoose_fBits[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_PT[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_Eta[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_Phi[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_E[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_T[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_EhadOverEem[kMaxPhotonLoose];   //[PhotonLoose_]
   TRefArray       PhotonLoose_Particles[kMaxPhotonLoose];
   Float_t         PhotonLoose_IsolationVar[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_IsolationVarRhoCorr[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_SumPtCharged[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_SumPtNeutral[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_SumPtChargedPU[kMaxPhotonLoose];   //[PhotonLoose_]
   Float_t         PhotonLoose_SumPt[kMaxPhotonLoose];   //[PhotonLoose_]
   Int_t           PhotonLoose_Status[kMaxPhotonLoose];   //[PhotonLoose_]
   Int_t           PhotonLoose_size;
   Int_t           PhotonMedium_;
   UInt_t          PhotonMedium_fUniqueID[kMaxPhotonMedium];   //[PhotonMedium_]
   UInt_t          PhotonMedium_fBits[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_PT[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_Eta[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_Phi[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_E[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_T[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_EhadOverEem[kMaxPhotonMedium];   //[PhotonMedium_]
   TRefArray       PhotonMedium_Particles[kMaxPhotonMedium];
   Float_t         PhotonMedium_IsolationVar[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_IsolationVarRhoCorr[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_SumPtCharged[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_SumPtNeutral[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_SumPtChargedPU[kMaxPhotonMedium];   //[PhotonMedium_]
   Float_t         PhotonMedium_SumPt[kMaxPhotonMedium];   //[PhotonMedium_]
   Int_t           PhotonMedium_Status[kMaxPhotonMedium];   //[PhotonMedium_]
   Int_t           PhotonMedium_size;
   Int_t           PhotonTight_;
   UInt_t          PhotonTight_fUniqueID[kMaxPhotonTight];   //[PhotonTight_]
   UInt_t          PhotonTight_fBits[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_PT[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_Eta[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_Phi[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_E[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_T[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_EhadOverEem[kMaxPhotonTight];   //[PhotonTight_]
   TRefArray       PhotonTight_Particles[kMaxPhotonTight];
   Float_t         PhotonTight_IsolationVar[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_IsolationVarRhoCorr[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_SumPtCharged[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_SumPtNeutral[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_SumPtChargedPU[kMaxPhotonTight];   //[PhotonTight_]
   Float_t         PhotonTight_SumPt[kMaxPhotonTight];   //[PhotonTight_]
   Int_t           PhotonTight_Status[kMaxPhotonTight];   //[PhotonTight_]
   Int_t           PhotonTight_size;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   Float_t         Electron_T[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Float_t         Electron_IsolationVar[kMaxElectron];   //[Electron_]
   Float_t         Electron_IsolationVarRhoCorr[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtCharged[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtNeutral[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPtChargedPU[kMaxElectron];   //[Electron_]
   Float_t         Electron_SumPt[kMaxElectron];   //[Electron_]
   Float_t         Electron_D0[kMaxElectron];   //[Electron_]
   Float_t         Electron_DZ[kMaxElectron];   //[Electron_]
   Float_t         Electron_ErrorD0[kMaxElectron];   //[Electron_]
   Float_t         Electron_ErrorDZ[kMaxElectron];   //[Electron_]
   Int_t           Electron_size;
   Int_t           ElectronLoose_;
   UInt_t          ElectronLoose_fUniqueID[kMaxElectronLoose];   //[ElectronLoose_]
   UInt_t          ElectronLoose_fBits[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_PT[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_Eta[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_Phi[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_T[kMaxElectronLoose];   //[ElectronLoose_]
   Int_t           ElectronLoose_Charge[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_EhadOverEem[kMaxElectronLoose];   //[ElectronLoose_]
   TRef            ElectronLoose_Particle[kMaxElectronLoose];
   Float_t         ElectronLoose_IsolationVar[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_IsolationVarRhoCorr[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_SumPtCharged[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_SumPtNeutral[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_SumPtChargedPU[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_SumPt[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_D0[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_DZ[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_ErrorD0[kMaxElectronLoose];   //[ElectronLoose_]
   Float_t         ElectronLoose_ErrorDZ[kMaxElectronLoose];   //[ElectronLoose_]
   Int_t           ElectronLoose_size;
   Int_t           ElectronMedium_;
   UInt_t          ElectronMedium_fUniqueID[kMaxElectronMedium];   //[ElectronMedium_]
   UInt_t          ElectronMedium_fBits[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_PT[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_Eta[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_Phi[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_T[kMaxElectronMedium];   //[ElectronMedium_]
   Int_t           ElectronMedium_Charge[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_EhadOverEem[kMaxElectronMedium];   //[ElectronMedium_]
   TRef            ElectronMedium_Particle[kMaxElectronMedium];
   Float_t         ElectronMedium_IsolationVar[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_IsolationVarRhoCorr[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_SumPtCharged[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_SumPtNeutral[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_SumPtChargedPU[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_SumPt[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_D0[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_DZ[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_ErrorD0[kMaxElectronMedium];   //[ElectronMedium_]
   Float_t         ElectronMedium_ErrorDZ[kMaxElectronMedium];   //[ElectronMedium_]
   Int_t           ElectronMedium_size;
   Int_t           ElectronTight_;
   UInt_t          ElectronTight_fUniqueID[kMaxElectronTight];   //[ElectronTight_]
   UInt_t          ElectronTight_fBits[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_PT[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_Eta[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_Phi[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_T[kMaxElectronTight];   //[ElectronTight_]
   Int_t           ElectronTight_Charge[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_EhadOverEem[kMaxElectronTight];   //[ElectronTight_]
   TRef            ElectronTight_Particle[kMaxElectronTight];
   Float_t         ElectronTight_IsolationVar[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_IsolationVarRhoCorr[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_SumPtCharged[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_SumPtNeutral[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_SumPtChargedPU[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_SumPt[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_D0[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_DZ[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_ErrorD0[kMaxElectronTight];   //[ElectronTight_]
   Float_t         ElectronTight_ErrorDZ[kMaxElectronTight];   //[ElectronTight_]
   Int_t           ElectronTight_size;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   Float_t         Muon_T[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Float_t         Muon_IsolationVar[kMaxMuon];   //[Muon_]
   Float_t         Muon_IsolationVarRhoCorr[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtCharged[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtNeutral[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPtChargedPU[kMaxMuon];   //[Muon_]
   Float_t         Muon_SumPt[kMaxMuon];   //[Muon_]
   Float_t         Muon_D0[kMaxMuon];   //[Muon_]
   Float_t         Muon_DZ[kMaxMuon];   //[Muon_]
   Float_t         Muon_ErrorD0[kMaxMuon];   //[Muon_]
   Float_t         Muon_ErrorDZ[kMaxMuon];   //[Muon_]
   Int_t           Muon_size;
   Int_t           MuonLoose_;
   UInt_t          MuonLoose_fUniqueID[kMaxMuonLoose];   //[MuonLoose_]
   UInt_t          MuonLoose_fBits[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_PT[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_Eta[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_Phi[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_T[kMaxMuonLoose];   //[MuonLoose_]
   Int_t           MuonLoose_Charge[kMaxMuonLoose];   //[MuonLoose_]
   TRef            MuonLoose_Particle[kMaxMuonLoose];
   Float_t         MuonLoose_IsolationVar[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_IsolationVarRhoCorr[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_SumPtCharged[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_SumPtNeutral[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_SumPtChargedPU[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_SumPt[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_D0[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_DZ[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_ErrorD0[kMaxMuonLoose];   //[MuonLoose_]
   Float_t         MuonLoose_ErrorDZ[kMaxMuonLoose];   //[MuonLoose_]
   Int_t           MuonLoose_size;
   Int_t           MuonMedium_;
   UInt_t          MuonMedium_fUniqueID[kMaxMuonMedium];   //[MuonMedium_]
   UInt_t          MuonMedium_fBits[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_PT[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_Eta[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_Phi[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_T[kMaxMuonMedium];   //[MuonMedium_]
   Int_t           MuonMedium_Charge[kMaxMuonMedium];   //[MuonMedium_]
   TRef            MuonMedium_Particle[kMaxMuonMedium];
   Float_t         MuonMedium_IsolationVar[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_IsolationVarRhoCorr[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_SumPtCharged[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_SumPtNeutral[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_SumPtChargedPU[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_SumPt[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_D0[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_DZ[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_ErrorD0[kMaxMuonMedium];   //[MuonMedium_]
   Float_t         MuonMedium_ErrorDZ[kMaxMuonMedium];   //[MuonMedium_]
   Int_t           MuonMedium_size;
   Int_t           MuonTight_;
   UInt_t          MuonTight_fUniqueID[kMaxMuonTight];   //[MuonTight_]
   UInt_t          MuonTight_fBits[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_PT[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_Eta[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_Phi[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_T[kMaxMuonTight];   //[MuonTight_]
   Int_t           MuonTight_Charge[kMaxMuonTight];   //[MuonTight_]
   TRef            MuonTight_Particle[kMaxMuonTight];
   Float_t         MuonTight_IsolationVar[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_IsolationVarRhoCorr[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_SumPtCharged[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_SumPtNeutral[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_SumPtChargedPU[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_SumPt[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_D0[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_DZ[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_ErrorD0[kMaxMuonTight];   //[MuonTight_]
   Float_t         MuonTight_ErrorDZ[kMaxMuonTight];   //[MuonTight_]
   Int_t           MuonTight_size;
   Int_t           JetPUPPI_;
   UInt_t          JetPUPPI_fUniqueID[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_fBits[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_PT[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_Eta[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_Phi[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_T[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_Mass[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_DeltaEta[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_DeltaPhi[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_Flavor[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_FlavorAlgo[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_FlavorPhys[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_BTag[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_BTagAlgo[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_BTagPhys[kMaxJetPUPPI];   //[JetPUPPI_]
   UInt_t          JetPUPPI_TauTag[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_TauWeight[kMaxJetPUPPI];   //[JetPUPPI_]
   Int_t           JetPUPPI_Charge[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_EhadOverEem[kMaxJetPUPPI];   //[JetPUPPI_]
   Int_t           JetPUPPI_NCharged[kMaxJetPUPPI];   //[JetPUPPI_]
   Int_t           JetPUPPI_NNeutrals[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_NeutralEnergyFraction[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_ChargedEnergyFraction[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_Beta[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_BetaStar[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_MeanSqDeltaR[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_PTD[kMaxJetPUPPI];   //[JetPUPPI_]
   Float_t         JetPUPPI_FracPt[kMaxJetPUPPI][5];   //[JetPUPPI_]
   Float_t         JetPUPPI_Tau[kMaxJetPUPPI][5];   //[JetPUPPI_]
   TLorentzVector  JetPUPPI_SoftDroppedJet[kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_SoftDroppedSubJet1[kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_SoftDroppedSubJet2[kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_TrimmedP4[5][kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_PrunedP4[5][kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_SoftDroppedP4[5][kMaxJetPUPPI];
   Int_t           JetPUPPI_NSubJetsTrimmed[kMaxJetPUPPI];   //[JetPUPPI_]
   Int_t           JetPUPPI_NSubJetsPruned[kMaxJetPUPPI];   //[JetPUPPI_]
   Int_t           JetPUPPI_NSubJetsSoftDropped[kMaxJetPUPPI];   //[JetPUPPI_]
   Double_t        JetPUPPI_ExclYmerge23[kMaxJetPUPPI];   //[JetPUPPI_]
   Double_t        JetPUPPI_ExclYmerge34[kMaxJetPUPPI];   //[JetPUPPI_]
   Double_t        JetPUPPI_ExclYmerge45[kMaxJetPUPPI];   //[JetPUPPI_]
   Double_t        JetPUPPI_ExclYmerge56[kMaxJetPUPPI];   //[JetPUPPI_]
   TRefArray       JetPUPPI_Constituents[kMaxJetPUPPI];
   TRefArray       JetPUPPI_Particles[kMaxJetPUPPI];
   TLorentzVector  JetPUPPI_Area[kMaxJetPUPPI];
   Int_t           JetPUPPI_size;
   Int_t           JetPUPPIAK8_;
   UInt_t          JetPUPPIAK8_fUniqueID[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_fBits[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_PT[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_Eta[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_Phi[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_T[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_Mass[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_DeltaEta[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_DeltaPhi[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_Flavor[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_FlavorAlgo[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_FlavorPhys[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_BTag[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_BTagAlgo[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_BTagPhys[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   UInt_t          JetPUPPIAK8_TauTag[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_TauWeight[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Int_t           JetPUPPIAK8_Charge[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_EhadOverEem[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Int_t           JetPUPPIAK8_NCharged[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Int_t           JetPUPPIAK8_NNeutrals[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_NeutralEnergyFraction[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_ChargedEnergyFraction[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_Beta[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_BetaStar[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_MeanSqDeltaR[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_PTD[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_FracPt[kMaxJetPUPPIAK8][5];   //[JetPUPPIAK8_]
   Float_t         JetPUPPIAK8_Tau[kMaxJetPUPPIAK8][5];   //[JetPUPPIAK8_]
   TLorentzVector  JetPUPPIAK8_SoftDroppedJet[kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_SoftDroppedSubJet1[kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_SoftDroppedSubJet2[kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_TrimmedP4[5][kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_PrunedP4[5][kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_SoftDroppedP4[5][kMaxJetPUPPIAK8];
   Int_t           JetPUPPIAK8_NSubJetsTrimmed[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Int_t           JetPUPPIAK8_NSubJetsPruned[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Int_t           JetPUPPIAK8_NSubJetsSoftDropped[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Double_t        JetPUPPIAK8_ExclYmerge23[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Double_t        JetPUPPIAK8_ExclYmerge34[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Double_t        JetPUPPIAK8_ExclYmerge45[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   Double_t        JetPUPPIAK8_ExclYmerge56[kMaxJetPUPPIAK8];   //[JetPUPPIAK8_]
   TRefArray       JetPUPPIAK8_Constituents[kMaxJetPUPPIAK8];
   TRefArray       JetPUPPIAK8_Particles[kMaxJetPUPPIAK8];
   TLorentzVector  JetPUPPIAK8_Area[kMaxJetPUPPIAK8];
   Int_t           JetPUPPIAK8_size;
   Int_t           JetPUPPILoose_;
   UInt_t          JetPUPPILoose_fUniqueID[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_fBits[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_PT[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_Eta[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_Phi[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_T[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_Mass[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_DeltaEta[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_DeltaPhi[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_Flavor[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_FlavorAlgo[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_FlavorPhys[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_BTag[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_BTagAlgo[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_BTagPhys[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   UInt_t          JetPUPPILoose_TauTag[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_TauWeight[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Int_t           JetPUPPILoose_Charge[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_EhadOverEem[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Int_t           JetPUPPILoose_NCharged[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Int_t           JetPUPPILoose_NNeutrals[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_NeutralEnergyFraction[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_ChargedEnergyFraction[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_Beta[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_BetaStar[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_MeanSqDeltaR[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_PTD[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_FracPt[kMaxJetPUPPILoose][5];   //[JetPUPPILoose_]
   Float_t         JetPUPPILoose_Tau[kMaxJetPUPPILoose][5];   //[JetPUPPILoose_]
   TLorentzVector  JetPUPPILoose_SoftDroppedJet[kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_SoftDroppedSubJet1[kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_SoftDroppedSubJet2[kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_TrimmedP4[5][kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_PrunedP4[5][kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_SoftDroppedP4[5][kMaxJetPUPPILoose];
   Int_t           JetPUPPILoose_NSubJetsTrimmed[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Int_t           JetPUPPILoose_NSubJetsPruned[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Int_t           JetPUPPILoose_NSubJetsSoftDropped[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Double_t        JetPUPPILoose_ExclYmerge23[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Double_t        JetPUPPILoose_ExclYmerge34[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Double_t        JetPUPPILoose_ExclYmerge45[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   Double_t        JetPUPPILoose_ExclYmerge56[kMaxJetPUPPILoose];   //[JetPUPPILoose_]
   TRefArray       JetPUPPILoose_Constituents[kMaxJetPUPPILoose];
   TRefArray       JetPUPPILoose_Particles[kMaxJetPUPPILoose];
   TLorentzVector  JetPUPPILoose_Area[kMaxJetPUPPILoose];
   Int_t           JetPUPPILoose_size;
   Int_t           JetPUPPITight_;
   UInt_t          JetPUPPITight_fUniqueID[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_fBits[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_PT[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_Eta[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_Phi[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_T[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_Mass[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_DeltaEta[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_DeltaPhi[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_Flavor[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_FlavorAlgo[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_FlavorPhys[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_BTag[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_BTagAlgo[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_BTagPhys[kMaxJetPUPPITight];   //[JetPUPPITight_]
   UInt_t          JetPUPPITight_TauTag[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_TauWeight[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Int_t           JetPUPPITight_Charge[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_EhadOverEem[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Int_t           JetPUPPITight_NCharged[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Int_t           JetPUPPITight_NNeutrals[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_NeutralEnergyFraction[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_ChargedEnergyFraction[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_Beta[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_BetaStar[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_MeanSqDeltaR[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_PTD[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_FracPt[kMaxJetPUPPITight][5];   //[JetPUPPITight_]
   Float_t         JetPUPPITight_Tau[kMaxJetPUPPITight][5];   //[JetPUPPITight_]
   TLorentzVector  JetPUPPITight_SoftDroppedJet[kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_SoftDroppedSubJet1[kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_SoftDroppedSubJet2[kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_TrimmedP4[5][kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_PrunedP4[5][kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_SoftDroppedP4[5][kMaxJetPUPPITight];
   Int_t           JetPUPPITight_NSubJetsTrimmed[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Int_t           JetPUPPITight_NSubJetsPruned[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Int_t           JetPUPPITight_NSubJetsSoftDropped[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Double_t        JetPUPPITight_ExclYmerge23[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Double_t        JetPUPPITight_ExclYmerge34[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Double_t        JetPUPPITight_ExclYmerge45[kMaxJetPUPPITight];   //[JetPUPPITight_]
   Double_t        JetPUPPITight_ExclYmerge56[kMaxJetPUPPITight];   //[JetPUPPITight_]
   TRefArray       JetPUPPITight_Constituents[kMaxJetPUPPITight];
   TRefArray       JetPUPPITight_Particles[kMaxJetPUPPITight];
   TLorentzVector  JetPUPPITight_Area[kMaxJetPUPPITight];
   Int_t           JetPUPPITight_size;
   Int_t           Rho_;
   UInt_t          Rho_fUniqueID[kMaxRho];   //[Rho_]
   UInt_t          Rho_fBits[kMaxRho];   //[Rho_]
   Float_t         Rho_Rho[kMaxRho];   //[Rho_]
   Float_t         Rho_Edges[kMaxRho][2];   //[Rho_]
   Int_t           Rho_size;
   Int_t           PuppiMissingET_;
   UInt_t          PuppiMissingET_fUniqueID[kMaxPuppiMissingET];   //[PuppiMissingET_]
   UInt_t          PuppiMissingET_fBits[kMaxPuppiMissingET];   //[PuppiMissingET_]
   Float_t         PuppiMissingET_MET[kMaxPuppiMissingET];   //[PuppiMissingET_]
   Float_t         PuppiMissingET_Eta[kMaxPuppiMissingET];   //[PuppiMissingET_]
   Float_t         PuppiMissingET_Phi[kMaxPuppiMissingET];   //[PuppiMissingET_]
   Int_t           PuppiMissingET_size;
   Int_t           GenPileUpMissingET_;
   UInt_t          GenPileUpMissingET_fUniqueID[kMaxGenPileUpMissingET];   //[GenPileUpMissingET_]
   UInt_t          GenPileUpMissingET_fBits[kMaxGenPileUpMissingET];   //[GenPileUpMissingET_]
   Float_t         GenPileUpMissingET_MET[kMaxGenPileUpMissingET];   //[GenPileUpMissingET_]
   Float_t         GenPileUpMissingET_Eta[kMaxGenPileUpMissingET];   //[GenPileUpMissingET_]
   Float_t         GenPileUpMissingET_Phi[kMaxGenPileUpMissingET];   //[GenPileUpMissingET_]
   Int_t           GenPileUpMissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;

   // List of branches
   TBranch        *b_Event_;   //!
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_ReadTime;   //!
   TBranch        *b_Event_ProcTime;   //!
   TBranch        *b_Event_ProcessID;   //!
   TBranch        *b_Event_MPI;   //!
   TBranch        *b_Event_Weight;   //!
   TBranch        *b_Event_CrossSection;   //!
   TBranch        *b_Event_CrossSectionError;   //!
   TBranch        *b_Event_Scale;   //!
   TBranch        *b_Event_AlphaQED;   //!
   TBranch        *b_Event_AlphaQCD;   //!
   TBranch        *b_Event_ID1;   //!
   TBranch        *b_Event_ID2;   //!
   TBranch        *b_Event_X1;   //!
   TBranch        *b_Event_X2;   //!
   TBranch        *b_Event_ScalePDF;   //!
   TBranch        *b_Event_PDF1;   //!
   TBranch        *b_Event_PDF2;   //!
   TBranch        *b_Event_size;   //!
   TBranch        *b_Weight_;   //!
   TBranch        *b_Weight_fUniqueID;   //!
   TBranch        *b_Weight_fBits;   //!
   TBranch        *b_Weight_Weight;   //!
   TBranch        *b_Weight_size;   //!
   TBranch        *b_Particle_;   //!
   TBranch        *b_Particle_fUniqueID;   //!
   TBranch        *b_Particle_fBits;   //!
   TBranch        *b_Particle_PID;   //!
   TBranch        *b_Particle_Status;   //!
   TBranch        *b_Particle_IsPU;   //!
   TBranch        *b_Particle_M1;   //!
   TBranch        *b_Particle_M2;   //!
   TBranch        *b_Particle_D1;   //!
   TBranch        *b_Particle_D2;   //!
   TBranch        *b_Particle_Charge;   //!
   TBranch        *b_Particle_Mass;   //!
   TBranch        *b_Particle_E;   //!
   TBranch        *b_Particle_Px;   //!
   TBranch        *b_Particle_Py;   //!
   TBranch        *b_Particle_Pz;   //!
   TBranch        *b_Particle_P;   //!
   TBranch        *b_Particle_PT;   //!
   TBranch        *b_Particle_Eta;   //!
   TBranch        *b_Particle_Phi;   //!
   TBranch        *b_Particle_Rapidity;   //!
   TBranch        *b_Particle_T;   //!
   TBranch        *b_Particle_X;   //!
   TBranch        *b_Particle_Y;   //!
   TBranch        *b_Particle_Z;   //!
   TBranch        *b_Particle_size;   //!
   TBranch        *b_Vertex_;   //!
   TBranch        *b_Vertex_fUniqueID;   //!
   TBranch        *b_Vertex_fBits;   //!
   TBranch        *b_Vertex_T;   //!
   TBranch        *b_Vertex_X;   //!
   TBranch        *b_Vertex_Y;   //!
   TBranch        *b_Vertex_Z;   //!
   TBranch        *b_Vertex_ErrorT;   //!
   TBranch        *b_Vertex_ErrorX;   //!
   TBranch        *b_Vertex_ErrorY;   //!
   TBranch        *b_Vertex_ErrorZ;   //!
   TBranch        *b_Vertex_Index;   //!
   TBranch        *b_Vertex_NDF;   //!
   TBranch        *b_Vertex_Sigma;   //!
   TBranch        *b_Vertex_SumPT2;   //!
   TBranch        *b_Vertex_GenSumPT2;   //!
   TBranch        *b_Vertex_GenDeltaZ;   //!
   TBranch        *b_Vertex_BTVSumPT2;   //!
   TBranch        *b_Vertex_Constituents;   //!
   TBranch        *b_Vertex_size;   //!
   TBranch        *b_GenJet_;   //!
   TBranch        *b_GenJet_fUniqueID;   //!
   TBranch        *b_GenJet_fBits;   //!
   TBranch        *b_GenJet_PT;   //!
   TBranch        *b_GenJet_Eta;   //!
   TBranch        *b_GenJet_Phi;   //!
   TBranch        *b_GenJet_T;   //!
   TBranch        *b_GenJet_Mass;   //!
   TBranch        *b_GenJet_DeltaEta;   //!
   TBranch        *b_GenJet_DeltaPhi;   //!
   TBranch        *b_GenJet_Flavor;   //!
   TBranch        *b_GenJet_FlavorAlgo;   //!
   TBranch        *b_GenJet_FlavorPhys;   //!
   TBranch        *b_GenJet_BTag;   //!
   TBranch        *b_GenJet_BTagAlgo;   //!
   TBranch        *b_GenJet_BTagPhys;   //!
   TBranch        *b_GenJet_TauTag;   //!
   TBranch        *b_GenJet_TauWeight;   //!
   TBranch        *b_GenJet_Charge;   //!
   TBranch        *b_GenJet_EhadOverEem;   //!
   TBranch        *b_GenJet_NCharged;   //!
   TBranch        *b_GenJet_NNeutrals;   //!
   TBranch        *b_GenJet_NeutralEnergyFraction;   //!
   TBranch        *b_GenJet_ChargedEnergyFraction;   //!
   TBranch        *b_GenJet_Beta;   //!
   TBranch        *b_GenJet_BetaStar;   //!
   TBranch        *b_GenJet_MeanSqDeltaR;   //!
   TBranch        *b_GenJet_PTD;   //!
   TBranch        *b_GenJet_FracPt;   //!
   TBranch        *b_GenJet_Tau;   //!
   TBranch        *b_GenJet_SoftDroppedJet;   //!
   TBranch        *b_GenJet_SoftDroppedSubJet1;   //!
   TBranch        *b_GenJet_SoftDroppedSubJet2;   //!
   TBranch        *b_GenJet_TrimmedP4;   //!
   TBranch        *b_GenJet_PrunedP4;   //!
   TBranch        *b_GenJet_SoftDroppedP4;   //!
   TBranch        *b_GenJet_NSubJetsTrimmed;   //!
   TBranch        *b_GenJet_NSubJetsPruned;   //!
   TBranch        *b_GenJet_NSubJetsSoftDropped;   //!
   TBranch        *b_GenJet_ExclYmerge23;   //!
   TBranch        *b_GenJet_ExclYmerge34;   //!
   TBranch        *b_GenJet_ExclYmerge45;   //!
   TBranch        *b_GenJet_ExclYmerge56;   //!
   TBranch        *b_GenJet_Constituents;   //!
   TBranch        *b_GenJet_Particles;   //!
   TBranch        *b_GenJet_Area;   //!
   TBranch        *b_GenJet_size;   //!
   TBranch        *b_GenJetAK8_;   //!
   TBranch        *b_GenJetAK8_fUniqueID;   //!
   TBranch        *b_GenJetAK8_fBits;   //!
   TBranch        *b_GenJetAK8_PT;   //!
   TBranch        *b_GenJetAK8_Eta;   //!
   TBranch        *b_GenJetAK8_Phi;   //!
   TBranch        *b_GenJetAK8_T;   //!
   TBranch        *b_GenJetAK8_Mass;   //!
   TBranch        *b_GenJetAK8_DeltaEta;   //!
   TBranch        *b_GenJetAK8_DeltaPhi;   //!
   TBranch        *b_GenJetAK8_Flavor;   //!
   TBranch        *b_GenJetAK8_FlavorAlgo;   //!
   TBranch        *b_GenJetAK8_FlavorPhys;   //!
   TBranch        *b_GenJetAK8_BTag;   //!
   TBranch        *b_GenJetAK8_BTagAlgo;   //!
   TBranch        *b_GenJetAK8_BTagPhys;   //!
   TBranch        *b_GenJetAK8_TauTag;   //!
   TBranch        *b_GenJetAK8_TauWeight;   //!
   TBranch        *b_GenJetAK8_Charge;   //!
   TBranch        *b_GenJetAK8_EhadOverEem;   //!
   TBranch        *b_GenJetAK8_NCharged;   //!
   TBranch        *b_GenJetAK8_NNeutrals;   //!
   TBranch        *b_GenJetAK8_NeutralEnergyFraction;   //!
   TBranch        *b_GenJetAK8_ChargedEnergyFraction;   //!
   TBranch        *b_GenJetAK8_Beta;   //!
   TBranch        *b_GenJetAK8_BetaStar;   //!
   TBranch        *b_GenJetAK8_MeanSqDeltaR;   //!
   TBranch        *b_GenJetAK8_PTD;   //!
   TBranch        *b_GenJetAK8_FracPt;   //!
   TBranch        *b_GenJetAK8_Tau;   //!
   TBranch        *b_GenJetAK8_SoftDroppedJet;   //!
   TBranch        *b_GenJetAK8_SoftDroppedSubJet1;   //!
   TBranch        *b_GenJetAK8_SoftDroppedSubJet2;   //!
   TBranch        *b_GenJetAK8_TrimmedP4;   //!
   TBranch        *b_GenJetAK8_PrunedP4;   //!
   TBranch        *b_GenJetAK8_SoftDroppedP4;   //!
   TBranch        *b_GenJetAK8_NSubJetsTrimmed;   //!
   TBranch        *b_GenJetAK8_NSubJetsPruned;   //!
   TBranch        *b_GenJetAK8_NSubJetsSoftDropped;   //!
   TBranch        *b_GenJetAK8_ExclYmerge23;   //!
   TBranch        *b_GenJetAK8_ExclYmerge34;   //!
   TBranch        *b_GenJetAK8_ExclYmerge45;   //!
   TBranch        *b_GenJetAK8_ExclYmerge56;   //!
   TBranch        *b_GenJetAK8_Constituents;   //!
   TBranch        *b_GenJetAK8_Particles;   //!
   TBranch        *b_GenJetAK8_Area;   //!
   TBranch        *b_GenJetAK8_size;   //!
   TBranch        *b_GenMissingET_;   //!
   TBranch        *b_GenMissingET_fUniqueID;   //!
   TBranch        *b_GenMissingET_fBits;   //!
   TBranch        *b_GenMissingET_MET;   //!
   TBranch        *b_GenMissingET_Eta;   //!
   TBranch        *b_GenMissingET_Phi;   //!
   TBranch        *b_GenMissingET_size;   //!
   TBranch        *b_ParticleFlowCandidate_;   //!
   TBranch        *b_ParticleFlowCandidate_fUniqueID;   //!
   TBranch        *b_ParticleFlowCandidate_fBits;   //!
   TBranch        *b_ParticleFlowCandidate_PID;   //!
   TBranch        *b_ParticleFlowCandidate_Charge;   //!
   TBranch        *b_ParticleFlowCandidate_E;   //!
   TBranch        *b_ParticleFlowCandidate_P;   //!
   TBranch        *b_ParticleFlowCandidate_PT;   //!
   TBranch        *b_ParticleFlowCandidate_Eta;   //!
   TBranch        *b_ParticleFlowCandidate_Phi;   //!
   TBranch        *b_ParticleFlowCandidate_CtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_C;   //!
   TBranch        *b_ParticleFlowCandidate_Mass;   //!
   TBranch        *b_ParticleFlowCandidate_EtaOuter;   //!
   TBranch        *b_ParticleFlowCandidate_PhiOuter;   //!
   TBranch        *b_ParticleFlowCandidate_T;   //!
   TBranch        *b_ParticleFlowCandidate_X;   //!
   TBranch        *b_ParticleFlowCandidate_Y;   //!
   TBranch        *b_ParticleFlowCandidate_Z;   //!
   TBranch        *b_ParticleFlowCandidate_TOuter;   //!
   TBranch        *b_ParticleFlowCandidate_XOuter;   //!
   TBranch        *b_ParticleFlowCandidate_YOuter;   //!
   TBranch        *b_ParticleFlowCandidate_ZOuter;   //!
   TBranch        *b_ParticleFlowCandidate_Xd;   //!
   TBranch        *b_ParticleFlowCandidate_Yd;   //!
   TBranch        *b_ParticleFlowCandidate_Zd;   //!
   TBranch        *b_ParticleFlowCandidate_L;   //!
   TBranch        *b_ParticleFlowCandidate_D0;   //!
   TBranch        *b_ParticleFlowCandidate_DZ;   //!
   TBranch        *b_ParticleFlowCandidate_Nclusters;   //!
   TBranch        *b_ParticleFlowCandidate_dNdx;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorP;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorPT;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorPhi;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorCtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorT;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorD0;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorDZ;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorC;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorD0Phi;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorD0C;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorD0DZ;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorD0CtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorPhiC;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorPhiDZ;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorPhiCtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorCDZ;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorCCtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_ErrorDZCtgTheta;   //!
   TBranch        *b_ParticleFlowCandidate_VertexIndex;   //!
   TBranch        *b_ParticleFlowCandidate_NTimeHits;   //!
   TBranch        *b_ParticleFlowCandidate_Eem;   //!
   TBranch        *b_ParticleFlowCandidate_Ehad;   //!
   TBranch        *b_ParticleFlowCandidate_Edges;   //!
   TBranch        *b_ParticleFlowCandidate_Particles;   //!
   TBranch        *b_ParticleFlowCandidate_size;   //!
   TBranch        *b_Photon_;   //!
   TBranch        *b_Photon_fUniqueID;   //!
   TBranch        *b_Photon_fBits;   //!
   TBranch        *b_Photon_PT;   //!
   TBranch        *b_Photon_Eta;   //!
   TBranch        *b_Photon_Phi;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_T;   //!
   TBranch        *b_Photon_EhadOverEem;   //!
   TBranch        *b_Photon_Particles;   //!
   TBranch        *b_Photon_IsolationVar;   //!
   TBranch        *b_Photon_IsolationVarRhoCorr;   //!
   TBranch        *b_Photon_SumPtCharged;   //!
   TBranch        *b_Photon_SumPtNeutral;   //!
   TBranch        *b_Photon_SumPtChargedPU;   //!
   TBranch        *b_Photon_SumPt;   //!
   TBranch        *b_Photon_Status;   //!
   TBranch        *b_Photon_size;   //!
   TBranch        *b_PhotonLoose_;   //!
   TBranch        *b_PhotonLoose_fUniqueID;   //!
   TBranch        *b_PhotonLoose_fBits;   //!
   TBranch        *b_PhotonLoose_PT;   //!
   TBranch        *b_PhotonLoose_Eta;   //!
   TBranch        *b_PhotonLoose_Phi;   //!
   TBranch        *b_PhotonLoose_E;   //!
   TBranch        *b_PhotonLoose_T;   //!
   TBranch        *b_PhotonLoose_EhadOverEem;   //!
   TBranch        *b_PhotonLoose_Particles;   //!
   TBranch        *b_PhotonLoose_IsolationVar;   //!
   TBranch        *b_PhotonLoose_IsolationVarRhoCorr;   //!
   TBranch        *b_PhotonLoose_SumPtCharged;   //!
   TBranch        *b_PhotonLoose_SumPtNeutral;   //!
   TBranch        *b_PhotonLoose_SumPtChargedPU;   //!
   TBranch        *b_PhotonLoose_SumPt;   //!
   TBranch        *b_PhotonLoose_Status;   //!
   TBranch        *b_PhotonLoose_size;   //!
   TBranch        *b_PhotonMedium_;   //!
   TBranch        *b_PhotonMedium_fUniqueID;   //!
   TBranch        *b_PhotonMedium_fBits;   //!
   TBranch        *b_PhotonMedium_PT;   //!
   TBranch        *b_PhotonMedium_Eta;   //!
   TBranch        *b_PhotonMedium_Phi;   //!
   TBranch        *b_PhotonMedium_E;   //!
   TBranch        *b_PhotonMedium_T;   //!
   TBranch        *b_PhotonMedium_EhadOverEem;   //!
   TBranch        *b_PhotonMedium_Particles;   //!
   TBranch        *b_PhotonMedium_IsolationVar;   //!
   TBranch        *b_PhotonMedium_IsolationVarRhoCorr;   //!
   TBranch        *b_PhotonMedium_SumPtCharged;   //!
   TBranch        *b_PhotonMedium_SumPtNeutral;   //!
   TBranch        *b_PhotonMedium_SumPtChargedPU;   //!
   TBranch        *b_PhotonMedium_SumPt;   //!
   TBranch        *b_PhotonMedium_Status;   //!
   TBranch        *b_PhotonMedium_size;   //!
   TBranch        *b_PhotonTight_;   //!
   TBranch        *b_PhotonTight_fUniqueID;   //!
   TBranch        *b_PhotonTight_fBits;   //!
   TBranch        *b_PhotonTight_PT;   //!
   TBranch        *b_PhotonTight_Eta;   //!
   TBranch        *b_PhotonTight_Phi;   //!
   TBranch        *b_PhotonTight_E;   //!
   TBranch        *b_PhotonTight_T;   //!
   TBranch        *b_PhotonTight_EhadOverEem;   //!
   TBranch        *b_PhotonTight_Particles;   //!
   TBranch        *b_PhotonTight_IsolationVar;   //!
   TBranch        *b_PhotonTight_IsolationVarRhoCorr;   //!
   TBranch        *b_PhotonTight_SumPtCharged;   //!
   TBranch        *b_PhotonTight_SumPtNeutral;   //!
   TBranch        *b_PhotonTight_SumPtChargedPU;   //!
   TBranch        *b_PhotonTight_SumPt;   //!
   TBranch        *b_PhotonTight_Status;   //!
   TBranch        *b_PhotonTight_size;   //!
   TBranch        *b_Electron_;   //!
   TBranch        *b_Electron_fUniqueID;   //!
   TBranch        *b_Electron_fBits;   //!
   TBranch        *b_Electron_PT;   //!
   TBranch        *b_Electron_Eta;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_T;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_EhadOverEem;   //!
   TBranch        *b_Electron_Particle;   //!
   TBranch        *b_Electron_IsolationVar;   //!
   TBranch        *b_Electron_IsolationVarRhoCorr;   //!
   TBranch        *b_Electron_SumPtCharged;   //!
   TBranch        *b_Electron_SumPtNeutral;   //!
   TBranch        *b_Electron_SumPtChargedPU;   //!
   TBranch        *b_Electron_SumPt;   //!
   TBranch        *b_Electron_D0;   //!
   TBranch        *b_Electron_DZ;   //!
   TBranch        *b_Electron_ErrorD0;   //!
   TBranch        *b_Electron_ErrorDZ;   //!
   TBranch        *b_Electron_size;   //!
   TBranch        *b_ElectronLoose_;   //!
   TBranch        *b_ElectronLoose_fUniqueID;   //!
   TBranch        *b_ElectronLoose_fBits;   //!
   TBranch        *b_ElectronLoose_PT;   //!
   TBranch        *b_ElectronLoose_Eta;   //!
   TBranch        *b_ElectronLoose_Phi;   //!
   TBranch        *b_ElectronLoose_T;   //!
   TBranch        *b_ElectronLoose_Charge;   //!
   TBranch        *b_ElectronLoose_EhadOverEem;   //!
   TBranch        *b_ElectronLoose_Particle;   //!
   TBranch        *b_ElectronLoose_IsolationVar;   //!
   TBranch        *b_ElectronLoose_IsolationVarRhoCorr;   //!
   TBranch        *b_ElectronLoose_SumPtCharged;   //!
   TBranch        *b_ElectronLoose_SumPtNeutral;   //!
   TBranch        *b_ElectronLoose_SumPtChargedPU;   //!
   TBranch        *b_ElectronLoose_SumPt;   //!
   TBranch        *b_ElectronLoose_D0;   //!
   TBranch        *b_ElectronLoose_DZ;   //!
   TBranch        *b_ElectronLoose_ErrorD0;   //!
   TBranch        *b_ElectronLoose_ErrorDZ;   //!
   TBranch        *b_ElectronLoose_size;   //!
   TBranch        *b_ElectronMedium_;   //!
   TBranch        *b_ElectronMedium_fUniqueID;   //!
   TBranch        *b_ElectronMedium_fBits;   //!
   TBranch        *b_ElectronMedium_PT;   //!
   TBranch        *b_ElectronMedium_Eta;   //!
   TBranch        *b_ElectronMedium_Phi;   //!
   TBranch        *b_ElectronMedium_T;   //!
   TBranch        *b_ElectronMedium_Charge;   //!
   TBranch        *b_ElectronMedium_EhadOverEem;   //!
   TBranch        *b_ElectronMedium_Particle;   //!
   TBranch        *b_ElectronMedium_IsolationVar;   //!
   TBranch        *b_ElectronMedium_IsolationVarRhoCorr;   //!
   TBranch        *b_ElectronMedium_SumPtCharged;   //!
   TBranch        *b_ElectronMedium_SumPtNeutral;   //!
   TBranch        *b_ElectronMedium_SumPtChargedPU;   //!
   TBranch        *b_ElectronMedium_SumPt;   //!
   TBranch        *b_ElectronMedium_D0;   //!
   TBranch        *b_ElectronMedium_DZ;   //!
   TBranch        *b_ElectronMedium_ErrorD0;   //!
   TBranch        *b_ElectronMedium_ErrorDZ;   //!
   TBranch        *b_ElectronMedium_size;   //!
   TBranch        *b_ElectronTight_;   //!
   TBranch        *b_ElectronTight_fUniqueID;   //!
   TBranch        *b_ElectronTight_fBits;   //!
   TBranch        *b_ElectronTight_PT;   //!
   TBranch        *b_ElectronTight_Eta;   //!
   TBranch        *b_ElectronTight_Phi;   //!
   TBranch        *b_ElectronTight_T;   //!
   TBranch        *b_ElectronTight_Charge;   //!
   TBranch        *b_ElectronTight_EhadOverEem;   //!
   TBranch        *b_ElectronTight_Particle;   //!
   TBranch        *b_ElectronTight_IsolationVar;   //!
   TBranch        *b_ElectronTight_IsolationVarRhoCorr;   //!
   TBranch        *b_ElectronTight_SumPtCharged;   //!
   TBranch        *b_ElectronTight_SumPtNeutral;   //!
   TBranch        *b_ElectronTight_SumPtChargedPU;   //!
   TBranch        *b_ElectronTight_SumPt;   //!
   TBranch        *b_ElectronTight_D0;   //!
   TBranch        *b_ElectronTight_DZ;   //!
   TBranch        *b_ElectronTight_ErrorD0;   //!
   TBranch        *b_ElectronTight_ErrorDZ;   //!
   TBranch        *b_ElectronTight_size;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_PT;   //!
   TBranch        *b_Muon_Eta;   //!
   TBranch        *b_Muon_Phi;   //!
   TBranch        *b_Muon_T;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_Particle;   //!
   TBranch        *b_Muon_IsolationVar;   //!
   TBranch        *b_Muon_IsolationVarRhoCorr;   //!
   TBranch        *b_Muon_SumPtCharged;   //!
   TBranch        *b_Muon_SumPtNeutral;   //!
   TBranch        *b_Muon_SumPtChargedPU;   //!
   TBranch        *b_Muon_SumPt;   //!
   TBranch        *b_Muon_D0;   //!
   TBranch        *b_Muon_DZ;   //!
   TBranch        *b_Muon_ErrorD0;   //!
   TBranch        *b_Muon_ErrorDZ;   //!
   TBranch        *b_Muon_size;   //!
   TBranch        *b_MuonLoose_;   //!
   TBranch        *b_MuonLoose_fUniqueID;   //!
   TBranch        *b_MuonLoose_fBits;   //!
   TBranch        *b_MuonLoose_PT;   //!
   TBranch        *b_MuonLoose_Eta;   //!
   TBranch        *b_MuonLoose_Phi;   //!
   TBranch        *b_MuonLoose_T;   //!
   TBranch        *b_MuonLoose_Charge;   //!
   TBranch        *b_MuonLoose_Particle;   //!
   TBranch        *b_MuonLoose_IsolationVar;   //!
   TBranch        *b_MuonLoose_IsolationVarRhoCorr;   //!
   TBranch        *b_MuonLoose_SumPtCharged;   //!
   TBranch        *b_MuonLoose_SumPtNeutral;   //!
   TBranch        *b_MuonLoose_SumPtChargedPU;   //!
   TBranch        *b_MuonLoose_SumPt;   //!
   TBranch        *b_MuonLoose_D0;   //!
   TBranch        *b_MuonLoose_DZ;   //!
   TBranch        *b_MuonLoose_ErrorD0;   //!
   TBranch        *b_MuonLoose_ErrorDZ;   //!
   TBranch        *b_MuonLoose_size;   //!
   TBranch        *b_MuonMedium_;   //!
   TBranch        *b_MuonMedium_fUniqueID;   //!
   TBranch        *b_MuonMedium_fBits;   //!
   TBranch        *b_MuonMedium_PT;   //!
   TBranch        *b_MuonMedium_Eta;   //!
   TBranch        *b_MuonMedium_Phi;   //!
   TBranch        *b_MuonMedium_T;   //!
   TBranch        *b_MuonMedium_Charge;   //!
   TBranch        *b_MuonMedium_Particle;   //!
   TBranch        *b_MuonMedium_IsolationVar;   //!
   TBranch        *b_MuonMedium_IsolationVarRhoCorr;   //!
   TBranch        *b_MuonMedium_SumPtCharged;   //!
   TBranch        *b_MuonMedium_SumPtNeutral;   //!
   TBranch        *b_MuonMedium_SumPtChargedPU;   //!
   TBranch        *b_MuonMedium_SumPt;   //!
   TBranch        *b_MuonMedium_D0;   //!
   TBranch        *b_MuonMedium_DZ;   //!
   TBranch        *b_MuonMedium_ErrorD0;   //!
   TBranch        *b_MuonMedium_ErrorDZ;   //!
   TBranch        *b_MuonMedium_size;   //!
   TBranch        *b_MuonTight_;   //!
   TBranch        *b_MuonTight_fUniqueID;   //!
   TBranch        *b_MuonTight_fBits;   //!
   TBranch        *b_MuonTight_PT;   //!
   TBranch        *b_MuonTight_Eta;   //!
   TBranch        *b_MuonTight_Phi;   //!
   TBranch        *b_MuonTight_T;   //!
   TBranch        *b_MuonTight_Charge;   //!
   TBranch        *b_MuonTight_Particle;   //!
   TBranch        *b_MuonTight_IsolationVar;   //!
   TBranch        *b_MuonTight_IsolationVarRhoCorr;   //!
   TBranch        *b_MuonTight_SumPtCharged;   //!
   TBranch        *b_MuonTight_SumPtNeutral;   //!
   TBranch        *b_MuonTight_SumPtChargedPU;   //!
   TBranch        *b_MuonTight_SumPt;   //!
   TBranch        *b_MuonTight_D0;   //!
   TBranch        *b_MuonTight_DZ;   //!
   TBranch        *b_MuonTight_ErrorD0;   //!
   TBranch        *b_MuonTight_ErrorDZ;   //!
   TBranch        *b_MuonTight_size;   //!
   TBranch        *b_JetPUPPI_;   //!
   TBranch        *b_JetPUPPI_fUniqueID;   //!
   TBranch        *b_JetPUPPI_fBits;   //!
   TBranch        *b_JetPUPPI_PT;   //!
   TBranch        *b_JetPUPPI_Eta;   //!
   TBranch        *b_JetPUPPI_Phi;   //!
   TBranch        *b_JetPUPPI_T;   //!
   TBranch        *b_JetPUPPI_Mass;   //!
   TBranch        *b_JetPUPPI_DeltaEta;   //!
   TBranch        *b_JetPUPPI_DeltaPhi;   //!
   TBranch        *b_JetPUPPI_Flavor;   //!
   TBranch        *b_JetPUPPI_FlavorAlgo;   //!
   TBranch        *b_JetPUPPI_FlavorPhys;   //!
   TBranch        *b_JetPUPPI_BTag;   //!
   TBranch        *b_JetPUPPI_BTagAlgo;   //!
   TBranch        *b_JetPUPPI_BTagPhys;   //!
   TBranch        *b_JetPUPPI_TauTag;   //!
   TBranch        *b_JetPUPPI_TauWeight;   //!
   TBranch        *b_JetPUPPI_Charge;   //!
   TBranch        *b_JetPUPPI_EhadOverEem;   //!
   TBranch        *b_JetPUPPI_NCharged;   //!
   TBranch        *b_JetPUPPI_NNeutrals;   //!
   TBranch        *b_JetPUPPI_NeutralEnergyFraction;   //!
   TBranch        *b_JetPUPPI_ChargedEnergyFraction;   //!
   TBranch        *b_JetPUPPI_Beta;   //!
   TBranch        *b_JetPUPPI_BetaStar;   //!
   TBranch        *b_JetPUPPI_MeanSqDeltaR;   //!
   TBranch        *b_JetPUPPI_PTD;   //!
   TBranch        *b_JetPUPPI_FracPt;   //!
   TBranch        *b_JetPUPPI_Tau;   //!
   TBranch        *b_JetPUPPI_SoftDroppedJet;   //!
   TBranch        *b_JetPUPPI_SoftDroppedSubJet1;   //!
   TBranch        *b_JetPUPPI_SoftDroppedSubJet2;   //!
   TBranch        *b_JetPUPPI_TrimmedP4;   //!
   TBranch        *b_JetPUPPI_PrunedP4;   //!
   TBranch        *b_JetPUPPI_SoftDroppedP4;   //!
   TBranch        *b_JetPUPPI_NSubJetsTrimmed;   //!
   TBranch        *b_JetPUPPI_NSubJetsPruned;   //!
   TBranch        *b_JetPUPPI_NSubJetsSoftDropped;   //!
   TBranch        *b_JetPUPPI_ExclYmerge23;   //!
   TBranch        *b_JetPUPPI_ExclYmerge34;   //!
   TBranch        *b_JetPUPPI_ExclYmerge45;   //!
   TBranch        *b_JetPUPPI_ExclYmerge56;   //!
   TBranch        *b_JetPUPPI_Constituents;   //!
   TBranch        *b_JetPUPPI_Particles;   //!
   TBranch        *b_JetPUPPI_Area;   //!
   TBranch        *b_JetPUPPI_size;   //!
   TBranch        *b_JetPUPPIAK8_;   //!
   TBranch        *b_JetPUPPIAK8_fUniqueID;   //!
   TBranch        *b_JetPUPPIAK8_fBits;   //!
   TBranch        *b_JetPUPPIAK8_PT;   //!
   TBranch        *b_JetPUPPIAK8_Eta;   //!
   TBranch        *b_JetPUPPIAK8_Phi;   //!
   TBranch        *b_JetPUPPIAK8_T;   //!
   TBranch        *b_JetPUPPIAK8_Mass;   //!
   TBranch        *b_JetPUPPIAK8_DeltaEta;   //!
   TBranch        *b_JetPUPPIAK8_DeltaPhi;   //!
   TBranch        *b_JetPUPPIAK8_Flavor;   //!
   TBranch        *b_JetPUPPIAK8_FlavorAlgo;   //!
   TBranch        *b_JetPUPPIAK8_FlavorPhys;   //!
   TBranch        *b_JetPUPPIAK8_BTag;   //!
   TBranch        *b_JetPUPPIAK8_BTagAlgo;   //!
   TBranch        *b_JetPUPPIAK8_BTagPhys;   //!
   TBranch        *b_JetPUPPIAK8_TauTag;   //!
   TBranch        *b_JetPUPPIAK8_TauWeight;   //!
   TBranch        *b_JetPUPPIAK8_Charge;   //!
   TBranch        *b_JetPUPPIAK8_EhadOverEem;   //!
   TBranch        *b_JetPUPPIAK8_NCharged;   //!
   TBranch        *b_JetPUPPIAK8_NNeutrals;   //!
   TBranch        *b_JetPUPPIAK8_NeutralEnergyFraction;   //!
   TBranch        *b_JetPUPPIAK8_ChargedEnergyFraction;   //!
   TBranch        *b_JetPUPPIAK8_Beta;   //!
   TBranch        *b_JetPUPPIAK8_BetaStar;   //!
   TBranch        *b_JetPUPPIAK8_MeanSqDeltaR;   //!
   TBranch        *b_JetPUPPIAK8_PTD;   //!
   TBranch        *b_JetPUPPIAK8_FracPt;   //!
   TBranch        *b_JetPUPPIAK8_Tau;   //!
   TBranch        *b_JetPUPPIAK8_SoftDroppedJet;   //!
   TBranch        *b_JetPUPPIAK8_SoftDroppedSubJet1;   //!
   TBranch        *b_JetPUPPIAK8_SoftDroppedSubJet2;   //!
   TBranch        *b_JetPUPPIAK8_TrimmedP4;   //!
   TBranch        *b_JetPUPPIAK8_PrunedP4;   //!
   TBranch        *b_JetPUPPIAK8_SoftDroppedP4;   //!
   TBranch        *b_JetPUPPIAK8_NSubJetsTrimmed;   //!
   TBranch        *b_JetPUPPIAK8_NSubJetsPruned;   //!
   TBranch        *b_JetPUPPIAK8_NSubJetsSoftDropped;   //!
   TBranch        *b_JetPUPPIAK8_ExclYmerge23;   //!
   TBranch        *b_JetPUPPIAK8_ExclYmerge34;   //!
   TBranch        *b_JetPUPPIAK8_ExclYmerge45;   //!
   TBranch        *b_JetPUPPIAK8_ExclYmerge56;   //!
   TBranch        *b_JetPUPPIAK8_Constituents;   //!
   TBranch        *b_JetPUPPIAK8_Particles;   //!
   TBranch        *b_JetPUPPIAK8_Area;   //!
   TBranch        *b_JetPUPPIAK8_size;   //!
   TBranch        *b_JetPUPPILoose_;   //!
   TBranch        *b_JetPUPPILoose_fUniqueID;   //!
   TBranch        *b_JetPUPPILoose_fBits;   //!
   TBranch        *b_JetPUPPILoose_PT;   //!
   TBranch        *b_JetPUPPILoose_Eta;   //!
   TBranch        *b_JetPUPPILoose_Phi;   //!
   TBranch        *b_JetPUPPILoose_T;   //!
   TBranch        *b_JetPUPPILoose_Mass;   //!
   TBranch        *b_JetPUPPILoose_DeltaEta;   //!
   TBranch        *b_JetPUPPILoose_DeltaPhi;   //!
   TBranch        *b_JetPUPPILoose_Flavor;   //!
   TBranch        *b_JetPUPPILoose_FlavorAlgo;   //!
   TBranch        *b_JetPUPPILoose_FlavorPhys;   //!
   TBranch        *b_JetPUPPILoose_BTag;   //!
   TBranch        *b_JetPUPPILoose_BTagAlgo;   //!
   TBranch        *b_JetPUPPILoose_BTagPhys;   //!
   TBranch        *b_JetPUPPILoose_TauTag;   //!
   TBranch        *b_JetPUPPILoose_TauWeight;   //!
   TBranch        *b_JetPUPPILoose_Charge;   //!
   TBranch        *b_JetPUPPILoose_EhadOverEem;   //!
   TBranch        *b_JetPUPPILoose_NCharged;   //!
   TBranch        *b_JetPUPPILoose_NNeutrals;   //!
   TBranch        *b_JetPUPPILoose_NeutralEnergyFraction;   //!
   TBranch        *b_JetPUPPILoose_ChargedEnergyFraction;   //!
   TBranch        *b_JetPUPPILoose_Beta;   //!
   TBranch        *b_JetPUPPILoose_BetaStar;   //!
   TBranch        *b_JetPUPPILoose_MeanSqDeltaR;   //!
   TBranch        *b_JetPUPPILoose_PTD;   //!
   TBranch        *b_JetPUPPILoose_FracPt;   //!
   TBranch        *b_JetPUPPILoose_Tau;   //!
   TBranch        *b_JetPUPPILoose_SoftDroppedJet;   //!
   TBranch        *b_JetPUPPILoose_SoftDroppedSubJet1;   //!
   TBranch        *b_JetPUPPILoose_SoftDroppedSubJet2;   //!
   TBranch        *b_JetPUPPILoose_TrimmedP4;   //!
   TBranch        *b_JetPUPPILoose_PrunedP4;   //!
   TBranch        *b_JetPUPPILoose_SoftDroppedP4;   //!
   TBranch        *b_JetPUPPILoose_NSubJetsTrimmed;   //!
   TBranch        *b_JetPUPPILoose_NSubJetsPruned;   //!
   TBranch        *b_JetPUPPILoose_NSubJetsSoftDropped;   //!
   TBranch        *b_JetPUPPILoose_ExclYmerge23;   //!
   TBranch        *b_JetPUPPILoose_ExclYmerge34;   //!
   TBranch        *b_JetPUPPILoose_ExclYmerge45;   //!
   TBranch        *b_JetPUPPILoose_ExclYmerge56;   //!
   TBranch        *b_JetPUPPILoose_Constituents;   //!
   TBranch        *b_JetPUPPILoose_Particles;   //!
   TBranch        *b_JetPUPPILoose_Area;   //!
   TBranch        *b_JetPUPPILoose_size;   //!
   TBranch        *b_JetPUPPITight_;   //!
   TBranch        *b_JetPUPPITight_fUniqueID;   //!
   TBranch        *b_JetPUPPITight_fBits;   //!
   TBranch        *b_JetPUPPITight_PT;   //!
   TBranch        *b_JetPUPPITight_Eta;   //!
   TBranch        *b_JetPUPPITight_Phi;   //!
   TBranch        *b_JetPUPPITight_T;   //!
   TBranch        *b_JetPUPPITight_Mass;   //!
   TBranch        *b_JetPUPPITight_DeltaEta;   //!
   TBranch        *b_JetPUPPITight_DeltaPhi;   //!
   TBranch        *b_JetPUPPITight_Flavor;   //!
   TBranch        *b_JetPUPPITight_FlavorAlgo;   //!
   TBranch        *b_JetPUPPITight_FlavorPhys;   //!
   TBranch        *b_JetPUPPITight_BTag;   //!
   TBranch        *b_JetPUPPITight_BTagAlgo;   //!
   TBranch        *b_JetPUPPITight_BTagPhys;   //!
   TBranch        *b_JetPUPPITight_TauTag;   //!
   TBranch        *b_JetPUPPITight_TauWeight;   //!
   TBranch        *b_JetPUPPITight_Charge;   //!
   TBranch        *b_JetPUPPITight_EhadOverEem;   //!
   TBranch        *b_JetPUPPITight_NCharged;   //!
   TBranch        *b_JetPUPPITight_NNeutrals;   //!
   TBranch        *b_JetPUPPITight_NeutralEnergyFraction;   //!
   TBranch        *b_JetPUPPITight_ChargedEnergyFraction;   //!
   TBranch        *b_JetPUPPITight_Beta;   //!
   TBranch        *b_JetPUPPITight_BetaStar;   //!
   TBranch        *b_JetPUPPITight_MeanSqDeltaR;   //!
   TBranch        *b_JetPUPPITight_PTD;   //!
   TBranch        *b_JetPUPPITight_FracPt;   //!
   TBranch        *b_JetPUPPITight_Tau;   //!
   TBranch        *b_JetPUPPITight_SoftDroppedJet;   //!
   TBranch        *b_JetPUPPITight_SoftDroppedSubJet1;   //!
   TBranch        *b_JetPUPPITight_SoftDroppedSubJet2;   //!
   TBranch        *b_JetPUPPITight_TrimmedP4;   //!
   TBranch        *b_JetPUPPITight_PrunedP4;   //!
   TBranch        *b_JetPUPPITight_SoftDroppedP4;   //!
   TBranch        *b_JetPUPPITight_NSubJetsTrimmed;   //!
   TBranch        *b_JetPUPPITight_NSubJetsPruned;   //!
   TBranch        *b_JetPUPPITight_NSubJetsSoftDropped;   //!
   TBranch        *b_JetPUPPITight_ExclYmerge23;   //!
   TBranch        *b_JetPUPPITight_ExclYmerge34;   //!
   TBranch        *b_JetPUPPITight_ExclYmerge45;   //!
   TBranch        *b_JetPUPPITight_ExclYmerge56;   //!
   TBranch        *b_JetPUPPITight_Constituents;   //!
   TBranch        *b_JetPUPPITight_Particles;   //!
   TBranch        *b_JetPUPPITight_Area;   //!
   TBranch        *b_JetPUPPITight_size;   //!
   TBranch        *b_Rho_;   //!
   TBranch        *b_Rho_fUniqueID;   //!
   TBranch        *b_Rho_fBits;   //!
   TBranch        *b_Rho_Rho;   //!
   TBranch        *b_Rho_Edges;   //!
   TBranch        *b_Rho_size;   //!
   TBranch        *b_PuppiMissingET_;   //!
   TBranch        *b_PuppiMissingET_fUniqueID;   //!
   TBranch        *b_PuppiMissingET_fBits;   //!
   TBranch        *b_PuppiMissingET_MET;   //!
   TBranch        *b_PuppiMissingET_Eta;   //!
   TBranch        *b_PuppiMissingET_Phi;   //!
   TBranch        *b_PuppiMissingET_size;   //!
   TBranch        *b_GenPileUpMissingET_;   //!
   TBranch        *b_GenPileUpMissingET_fUniqueID;   //!
   TBranch        *b_GenPileUpMissingET_fBits;   //!
   TBranch        *b_GenPileUpMissingET_MET;   //!
   TBranch        *b_GenPileUpMissingET_Eta;   //!
   TBranch        *b_GenPileUpMissingET_Phi;   //!
   TBranch        *b_GenPileUpMissingET_size;   //!
   TBranch        *b_ScalarHT_;   //!
   TBranch        *b_ScalarHT_fUniqueID;   //!
   TBranch        *b_ScalarHT_fBits;   //!
   TBranch        *b_ScalarHT_HT;   //!
   TBranch        *b_ScalarHT_size;   //!

   DELPHES2(char *file_name, TChain *tree=0);
   virtual ~DELPHES2();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     GetPhysicsObjects(Long64_t entry, AnalysisObjects *a0, Long64_t nentries );
   virtual void     Loop(analy_struct aselect, char *extname);

};

#endif

#ifdef DELPHES2_cxx
DELPHES2::DELPHES2(char *file_name, TChain *tree) : fChain(0) 
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("Delphes");
     chain->Add(file_name);
  }
  if (tree == 0) {
     Init(chain);
  } else {
     Init(tree);
  }
}

DELPHES2::~DELPHES2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DELPHES2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DELPHES2::LoadTree(Long64_t entry)
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

void DELPHES2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
   fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
   fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
   fChain->SetBranchAddress("Event.MPI", Event_MPI, &b_Event_MPI);
   fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event.CrossSection", Event_CrossSection, &b_Event_CrossSection);
   fChain->SetBranchAddress("Event.CrossSectionError", Event_CrossSectionError, &b_Event_CrossSectionError);
   fChain->SetBranchAddress("Event.Scale", Event_Scale, &b_Event_Scale);
   fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
   fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
   fChain->SetBranchAddress("Event.ID1", Event_ID1, &b_Event_ID1);
   fChain->SetBranchAddress("Event.ID2", Event_ID2, &b_Event_ID2);
   fChain->SetBranchAddress("Event.X1", Event_X1, &b_Event_X1);
   fChain->SetBranchAddress("Event.X2", Event_X2, &b_Event_X2);
   fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
   fChain->SetBranchAddress("Event.PDF1", Event_PDF1, &b_Event_PDF1);
   fChain->SetBranchAddress("Event.PDF2", Event_PDF2, &b_Event_PDF2);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("Weight", &Weight_, &b_Weight_);
   fChain->SetBranchAddress("Weight.fUniqueID", Weight_fUniqueID, &b_Weight_fUniqueID);
   fChain->SetBranchAddress("Weight.fBits", Weight_fBits, &b_Weight_fBits);
   fChain->SetBranchAddress("Weight.Weight", Weight_Weight, &b_Weight_Weight);
   fChain->SetBranchAddress("Weight_size", &Weight_size, &b_Weight_size);
   fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
   fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
   fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
   fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
   fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
   fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
   fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
   fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
   fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
   fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
   fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
   fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
   fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
   fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
   fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
   fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
   fChain->SetBranchAddress("Particle.P", Particle_P, &b_Particle_P);
   fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
   fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
   fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
   fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
   fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
   fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
   fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
   fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
   fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
   fChain->SetBranchAddress("Vertex", &Vertex_, &b_Vertex_);
   fChain->SetBranchAddress("Vertex.fUniqueID", Vertex_fUniqueID, &b_Vertex_fUniqueID);
   fChain->SetBranchAddress("Vertex.fBits", Vertex_fBits, &b_Vertex_fBits);
   fChain->SetBranchAddress("Vertex.T", Vertex_T, &b_Vertex_T);
   fChain->SetBranchAddress("Vertex.X", Vertex_X, &b_Vertex_X);
   fChain->SetBranchAddress("Vertex.Y", Vertex_Y, &b_Vertex_Y);
   fChain->SetBranchAddress("Vertex.Z", Vertex_Z, &b_Vertex_Z);
   fChain->SetBranchAddress("Vertex.ErrorT", Vertex_ErrorT, &b_Vertex_ErrorT);
   fChain->SetBranchAddress("Vertex.ErrorX", Vertex_ErrorX, &b_Vertex_ErrorX);
   fChain->SetBranchAddress("Vertex.ErrorY", Vertex_ErrorY, &b_Vertex_ErrorY);
   fChain->SetBranchAddress("Vertex.ErrorZ", Vertex_ErrorZ, &b_Vertex_ErrorZ);
   fChain->SetBranchAddress("Vertex.Index", Vertex_Index, &b_Vertex_Index);
   fChain->SetBranchAddress("Vertex.NDF", Vertex_NDF, &b_Vertex_NDF);
   fChain->SetBranchAddress("Vertex.Sigma", Vertex_Sigma, &b_Vertex_Sigma);
   fChain->SetBranchAddress("Vertex.SumPT2", Vertex_SumPT2, &b_Vertex_SumPT2);
   fChain->SetBranchAddress("Vertex.GenSumPT2", Vertex_GenSumPT2, &b_Vertex_GenSumPT2);
   fChain->SetBranchAddress("Vertex.GenDeltaZ", Vertex_GenDeltaZ, &b_Vertex_GenDeltaZ);
   fChain->SetBranchAddress("Vertex.BTVSumPT2", Vertex_BTVSumPT2, &b_Vertex_BTVSumPT2);
   fChain->SetBranchAddress("Vertex.Constituents", Vertex_Constituents, &b_Vertex_Constituents);
   fChain->SetBranchAddress("Vertex_size", &Vertex_size, &b_Vertex_size);
   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.T", GenJet_T, &b_GenJet_T);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.Flavor", GenJet_Flavor, &b_GenJet_Flavor);
   fChain->SetBranchAddress("GenJet.FlavorAlgo", GenJet_FlavorAlgo, &b_GenJet_FlavorAlgo);
   fChain->SetBranchAddress("GenJet.FlavorPhys", GenJet_FlavorPhys, &b_GenJet_FlavorPhys);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.BTagAlgo", GenJet_BTagAlgo, &b_GenJet_BTagAlgo);
   fChain->SetBranchAddress("GenJet.BTagPhys", GenJet_BTagPhys, &b_GenJet_BTagPhys);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.TauWeight", GenJet_TauWeight, &b_GenJet_TauWeight);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.NCharged", GenJet_NCharged, &b_GenJet_NCharged);
   fChain->SetBranchAddress("GenJet.NNeutrals", GenJet_NNeutrals, &b_GenJet_NNeutrals);
   fChain->SetBranchAddress("GenJet.NeutralEnergyFraction", GenJet_NeutralEnergyFraction, &b_GenJet_NeutralEnergyFraction);
   fChain->SetBranchAddress("GenJet.ChargedEnergyFraction", GenJet_ChargedEnergyFraction, &b_GenJet_ChargedEnergyFraction);
   fChain->SetBranchAddress("GenJet.Beta", GenJet_Beta, &b_GenJet_Beta);
   fChain->SetBranchAddress("GenJet.BetaStar", GenJet_BetaStar, &b_GenJet_BetaStar);
   fChain->SetBranchAddress("GenJet.MeanSqDeltaR", GenJet_MeanSqDeltaR, &b_GenJet_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJet.PTD", GenJet_PTD, &b_GenJet_PTD);
   fChain->SetBranchAddress("GenJet.FracPt[5]", GenJet_FracPt, &b_GenJet_FracPt);
   fChain->SetBranchAddress("GenJet.Tau[5]", GenJet_Tau, &b_GenJet_Tau);
   fChain->SetBranchAddress("GenJet.SoftDroppedJet", GenJet_SoftDroppedJet, &b_GenJet_SoftDroppedJet);
   fChain->SetBranchAddress("GenJet.SoftDroppedSubJet1", GenJet_SoftDroppedSubJet1, &b_GenJet_SoftDroppedSubJet1);
   fChain->SetBranchAddress("GenJet.SoftDroppedSubJet2", GenJet_SoftDroppedSubJet2, &b_GenJet_SoftDroppedSubJet2);
   fChain->SetBranchAddress("GenJet.TrimmedP4[5]", GenJet_TrimmedP4, &b_GenJet_TrimmedP4);
   fChain->SetBranchAddress("GenJet.PrunedP4[5]", GenJet_PrunedP4, &b_GenJet_PrunedP4);
   fChain->SetBranchAddress("GenJet.SoftDroppedP4[5]", GenJet_SoftDroppedP4, &b_GenJet_SoftDroppedP4);
   fChain->SetBranchAddress("GenJet.NSubJetsTrimmed", GenJet_NSubJetsTrimmed, &b_GenJet_NSubJetsTrimmed);
   fChain->SetBranchAddress("GenJet.NSubJetsPruned", GenJet_NSubJetsPruned, &b_GenJet_NSubJetsPruned);
   fChain->SetBranchAddress("GenJet.NSubJetsSoftDropped", GenJet_NSubJetsSoftDropped, &b_GenJet_NSubJetsSoftDropped);
   fChain->SetBranchAddress("GenJet.ExclYmerge23", GenJet_ExclYmerge23, &b_GenJet_ExclYmerge23);
   fChain->SetBranchAddress("GenJet.ExclYmerge34", GenJet_ExclYmerge34, &b_GenJet_ExclYmerge34);
   fChain->SetBranchAddress("GenJet.ExclYmerge45", GenJet_ExclYmerge45, &b_GenJet_ExclYmerge45);
   fChain->SetBranchAddress("GenJet.ExclYmerge56", GenJet_ExclYmerge56, &b_GenJet_ExclYmerge56);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet.Area", GenJet_Area, &b_GenJet_Area);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   fChain->SetBranchAddress("GenJetAK8", &GenJetAK8_, &b_GenJetAK8_);
   fChain->SetBranchAddress("GenJetAK8.fUniqueID", GenJetAK8_fUniqueID, &b_GenJetAK8_fUniqueID);
   fChain->SetBranchAddress("GenJetAK8.fBits", GenJetAK8_fBits, &b_GenJetAK8_fBits);
   fChain->SetBranchAddress("GenJetAK8.PT", GenJetAK8_PT, &b_GenJetAK8_PT);
   fChain->SetBranchAddress("GenJetAK8.Eta", GenJetAK8_Eta, &b_GenJetAK8_Eta);
   fChain->SetBranchAddress("GenJetAK8.Phi", GenJetAK8_Phi, &b_GenJetAK8_Phi);
   fChain->SetBranchAddress("GenJetAK8.T", GenJetAK8_T, &b_GenJetAK8_T);
   fChain->SetBranchAddress("GenJetAK8.Mass", GenJetAK8_Mass, &b_GenJetAK8_Mass);
   fChain->SetBranchAddress("GenJetAK8.DeltaEta", GenJetAK8_DeltaEta, &b_GenJetAK8_DeltaEta);
   fChain->SetBranchAddress("GenJetAK8.DeltaPhi", GenJetAK8_DeltaPhi, &b_GenJetAK8_DeltaPhi);
   fChain->SetBranchAddress("GenJetAK8.Flavor", GenJetAK8_Flavor, &b_GenJetAK8_Flavor);
   fChain->SetBranchAddress("GenJetAK8.FlavorAlgo", GenJetAK8_FlavorAlgo, &b_GenJetAK8_FlavorAlgo);
   fChain->SetBranchAddress("GenJetAK8.FlavorPhys", GenJetAK8_FlavorPhys, &b_GenJetAK8_FlavorPhys);
   fChain->SetBranchAddress("GenJetAK8.BTag", GenJetAK8_BTag, &b_GenJetAK8_BTag);
   fChain->SetBranchAddress("GenJetAK8.BTagAlgo", GenJetAK8_BTagAlgo, &b_GenJetAK8_BTagAlgo);
   fChain->SetBranchAddress("GenJetAK8.BTagPhys", GenJetAK8_BTagPhys, &b_GenJetAK8_BTagPhys);
   fChain->SetBranchAddress("GenJetAK8.TauTag", GenJetAK8_TauTag, &b_GenJetAK8_TauTag);
   fChain->SetBranchAddress("GenJetAK8.TauWeight", GenJetAK8_TauWeight, &b_GenJetAK8_TauWeight);
   fChain->SetBranchAddress("GenJetAK8.Charge", GenJetAK8_Charge, &b_GenJetAK8_Charge);
   fChain->SetBranchAddress("GenJetAK8.EhadOverEem", GenJetAK8_EhadOverEem, &b_GenJetAK8_EhadOverEem);
   fChain->SetBranchAddress("GenJetAK8.NCharged", GenJetAK8_NCharged, &b_GenJetAK8_NCharged);
   fChain->SetBranchAddress("GenJetAK8.NNeutrals", GenJetAK8_NNeutrals, &b_GenJetAK8_NNeutrals);
   fChain->SetBranchAddress("GenJetAK8.NeutralEnergyFraction", GenJetAK8_NeutralEnergyFraction, &b_GenJetAK8_NeutralEnergyFraction);
   fChain->SetBranchAddress("GenJetAK8.ChargedEnergyFraction", GenJetAK8_ChargedEnergyFraction, &b_GenJetAK8_ChargedEnergyFraction);
   fChain->SetBranchAddress("GenJetAK8.Beta", GenJetAK8_Beta, &b_GenJetAK8_Beta);
   fChain->SetBranchAddress("GenJetAK8.BetaStar", GenJetAK8_BetaStar, &b_GenJetAK8_BetaStar);
   fChain->SetBranchAddress("GenJetAK8.MeanSqDeltaR", GenJetAK8_MeanSqDeltaR, &b_GenJetAK8_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJetAK8.PTD", GenJetAK8_PTD, &b_GenJetAK8_PTD);
   fChain->SetBranchAddress("GenJetAK8.FracPt[5]", GenJetAK8_FracPt, &b_GenJetAK8_FracPt);
   fChain->SetBranchAddress("GenJetAK8.Tau[5]", GenJetAK8_Tau, &b_GenJetAK8_Tau);
   fChain->SetBranchAddress("GenJetAK8.SoftDroppedJet", GenJetAK8_SoftDroppedJet, &b_GenJetAK8_SoftDroppedJet);
   fChain->SetBranchAddress("GenJetAK8.SoftDroppedSubJet1", GenJetAK8_SoftDroppedSubJet1, &b_GenJetAK8_SoftDroppedSubJet1);
   fChain->SetBranchAddress("GenJetAK8.SoftDroppedSubJet2", GenJetAK8_SoftDroppedSubJet2, &b_GenJetAK8_SoftDroppedSubJet2);
   fChain->SetBranchAddress("GenJetAK8.TrimmedP4[5]", GenJetAK8_TrimmedP4, &b_GenJetAK8_TrimmedP4);
   fChain->SetBranchAddress("GenJetAK8.PrunedP4[5]", GenJetAK8_PrunedP4, &b_GenJetAK8_PrunedP4);
   fChain->SetBranchAddress("GenJetAK8.SoftDroppedP4[5]", GenJetAK8_SoftDroppedP4, &b_GenJetAK8_SoftDroppedP4);
   fChain->SetBranchAddress("GenJetAK8.NSubJetsTrimmed", GenJetAK8_NSubJetsTrimmed, &b_GenJetAK8_NSubJetsTrimmed);
   fChain->SetBranchAddress("GenJetAK8.NSubJetsPruned", GenJetAK8_NSubJetsPruned, &b_GenJetAK8_NSubJetsPruned);
   fChain->SetBranchAddress("GenJetAK8.NSubJetsSoftDropped", GenJetAK8_NSubJetsSoftDropped, &b_GenJetAK8_NSubJetsSoftDropped);
   fChain->SetBranchAddress("GenJetAK8.ExclYmerge23", GenJetAK8_ExclYmerge23, &b_GenJetAK8_ExclYmerge23);
   fChain->SetBranchAddress("GenJetAK8.ExclYmerge34", GenJetAK8_ExclYmerge34, &b_GenJetAK8_ExclYmerge34);
   fChain->SetBranchAddress("GenJetAK8.ExclYmerge45", GenJetAK8_ExclYmerge45, &b_GenJetAK8_ExclYmerge45);
   fChain->SetBranchAddress("GenJetAK8.ExclYmerge56", GenJetAK8_ExclYmerge56, &b_GenJetAK8_ExclYmerge56);
   fChain->SetBranchAddress("GenJetAK8.Constituents", GenJetAK8_Constituents, &b_GenJetAK8_Constituents);
   fChain->SetBranchAddress("GenJetAK8.Particles", GenJetAK8_Particles, &b_GenJetAK8_Particles);
   fChain->SetBranchAddress("GenJetAK8.Area", GenJetAK8_Area, &b_GenJetAK8_Area);
   fChain->SetBranchAddress("GenJetAK8_size", &GenJetAK8_size, &b_GenJetAK8_size);
   fChain->SetBranchAddress("GenMissingET", &GenMissingET_, &b_GenMissingET_);
   fChain->SetBranchAddress("GenMissingET.fUniqueID", GenMissingET_fUniqueID, &b_GenMissingET_fUniqueID);
   fChain->SetBranchAddress("GenMissingET.fBits", GenMissingET_fBits, &b_GenMissingET_fBits);
   fChain->SetBranchAddress("GenMissingET.MET", GenMissingET_MET, &b_GenMissingET_MET);
   fChain->SetBranchAddress("GenMissingET.Eta", GenMissingET_Eta, &b_GenMissingET_Eta);
   fChain->SetBranchAddress("GenMissingET.Phi", GenMissingET_Phi, &b_GenMissingET_Phi);
   fChain->SetBranchAddress("GenMissingET_size", &GenMissingET_size, &b_GenMissingET_size);
   fChain->SetBranchAddress("ParticleFlowCandidate", &ParticleFlowCandidate_, &b_ParticleFlowCandidate_);
   fChain->SetBranchAddress("ParticleFlowCandidate.fUniqueID", ParticleFlowCandidate_fUniqueID, &b_ParticleFlowCandidate_fUniqueID);
   fChain->SetBranchAddress("ParticleFlowCandidate.fBits", ParticleFlowCandidate_fBits, &b_ParticleFlowCandidate_fBits);
   fChain->SetBranchAddress("ParticleFlowCandidate.PID", ParticleFlowCandidate_PID, &b_ParticleFlowCandidate_PID);
   fChain->SetBranchAddress("ParticleFlowCandidate.Charge", ParticleFlowCandidate_Charge, &b_ParticleFlowCandidate_Charge);
   fChain->SetBranchAddress("ParticleFlowCandidate.E", ParticleFlowCandidate_E, &b_ParticleFlowCandidate_E);
   fChain->SetBranchAddress("ParticleFlowCandidate.P", ParticleFlowCandidate_P, &b_ParticleFlowCandidate_P);
   fChain->SetBranchAddress("ParticleFlowCandidate.PT", ParticleFlowCandidate_PT, &b_ParticleFlowCandidate_PT);
   fChain->SetBranchAddress("ParticleFlowCandidate.Eta", ParticleFlowCandidate_Eta, &b_ParticleFlowCandidate_Eta);
   fChain->SetBranchAddress("ParticleFlowCandidate.Phi", ParticleFlowCandidate_Phi, &b_ParticleFlowCandidate_Phi);
   fChain->SetBranchAddress("ParticleFlowCandidate.CtgTheta", ParticleFlowCandidate_CtgTheta, &b_ParticleFlowCandidate_CtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.C", ParticleFlowCandidate_C, &b_ParticleFlowCandidate_C);
   fChain->SetBranchAddress("ParticleFlowCandidate.Mass", ParticleFlowCandidate_Mass, &b_ParticleFlowCandidate_Mass);
   fChain->SetBranchAddress("ParticleFlowCandidate.EtaOuter", ParticleFlowCandidate_EtaOuter, &b_ParticleFlowCandidate_EtaOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.PhiOuter", ParticleFlowCandidate_PhiOuter, &b_ParticleFlowCandidate_PhiOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.T", ParticleFlowCandidate_T, &b_ParticleFlowCandidate_T);
   fChain->SetBranchAddress("ParticleFlowCandidate.X", ParticleFlowCandidate_X, &b_ParticleFlowCandidate_X);
   fChain->SetBranchAddress("ParticleFlowCandidate.Y", ParticleFlowCandidate_Y, &b_ParticleFlowCandidate_Y);
   fChain->SetBranchAddress("ParticleFlowCandidate.Z", ParticleFlowCandidate_Z, &b_ParticleFlowCandidate_Z);
   fChain->SetBranchAddress("ParticleFlowCandidate.TOuter", ParticleFlowCandidate_TOuter, &b_ParticleFlowCandidate_TOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.XOuter", ParticleFlowCandidate_XOuter, &b_ParticleFlowCandidate_XOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.YOuter", ParticleFlowCandidate_YOuter, &b_ParticleFlowCandidate_YOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.ZOuter", ParticleFlowCandidate_ZOuter, &b_ParticleFlowCandidate_ZOuter);
   fChain->SetBranchAddress("ParticleFlowCandidate.Xd", ParticleFlowCandidate_Xd, &b_ParticleFlowCandidate_Xd);
   fChain->SetBranchAddress("ParticleFlowCandidate.Yd", ParticleFlowCandidate_Yd, &b_ParticleFlowCandidate_Yd);
   fChain->SetBranchAddress("ParticleFlowCandidate.Zd", ParticleFlowCandidate_Zd, &b_ParticleFlowCandidate_Zd);
   fChain->SetBranchAddress("ParticleFlowCandidate.L", ParticleFlowCandidate_L, &b_ParticleFlowCandidate_L);
   fChain->SetBranchAddress("ParticleFlowCandidate.D0", ParticleFlowCandidate_D0, &b_ParticleFlowCandidate_D0);
   fChain->SetBranchAddress("ParticleFlowCandidate.DZ", ParticleFlowCandidate_DZ, &b_ParticleFlowCandidate_DZ);
   fChain->SetBranchAddress("ParticleFlowCandidate.Nclusters", ParticleFlowCandidate_Nclusters, &b_ParticleFlowCandidate_Nclusters);
   fChain->SetBranchAddress("ParticleFlowCandidate.dNdx", ParticleFlowCandidate_dNdx, &b_ParticleFlowCandidate_dNdx);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorP", ParticleFlowCandidate_ErrorP, &b_ParticleFlowCandidate_ErrorP);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorPT", ParticleFlowCandidate_ErrorPT, &b_ParticleFlowCandidate_ErrorPT);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorPhi", ParticleFlowCandidate_ErrorPhi, &b_ParticleFlowCandidate_ErrorPhi);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorCtgTheta", ParticleFlowCandidate_ErrorCtgTheta, &b_ParticleFlowCandidate_ErrorCtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorT", ParticleFlowCandidate_ErrorT, &b_ParticleFlowCandidate_ErrorT);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorD0", ParticleFlowCandidate_ErrorD0, &b_ParticleFlowCandidate_ErrorD0);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorDZ", ParticleFlowCandidate_ErrorDZ, &b_ParticleFlowCandidate_ErrorDZ);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorC", ParticleFlowCandidate_ErrorC, &b_ParticleFlowCandidate_ErrorC);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorD0Phi", ParticleFlowCandidate_ErrorD0Phi, &b_ParticleFlowCandidate_ErrorD0Phi);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorD0C", ParticleFlowCandidate_ErrorD0C, &b_ParticleFlowCandidate_ErrorD0C);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorD0DZ", ParticleFlowCandidate_ErrorD0DZ, &b_ParticleFlowCandidate_ErrorD0DZ);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorD0CtgTheta", ParticleFlowCandidate_ErrorD0CtgTheta, &b_ParticleFlowCandidate_ErrorD0CtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorPhiC", ParticleFlowCandidate_ErrorPhiC, &b_ParticleFlowCandidate_ErrorPhiC);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorPhiDZ", ParticleFlowCandidate_ErrorPhiDZ, &b_ParticleFlowCandidate_ErrorPhiDZ);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorPhiCtgTheta", ParticleFlowCandidate_ErrorPhiCtgTheta, &b_ParticleFlowCandidate_ErrorPhiCtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorCDZ", ParticleFlowCandidate_ErrorCDZ, &b_ParticleFlowCandidate_ErrorCDZ);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorCCtgTheta", ParticleFlowCandidate_ErrorCCtgTheta, &b_ParticleFlowCandidate_ErrorCCtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.ErrorDZCtgTheta", ParticleFlowCandidate_ErrorDZCtgTheta, &b_ParticleFlowCandidate_ErrorDZCtgTheta);
   fChain->SetBranchAddress("ParticleFlowCandidate.VertexIndex", ParticleFlowCandidate_VertexIndex, &b_ParticleFlowCandidate_VertexIndex);
   fChain->SetBranchAddress("ParticleFlowCandidate.NTimeHits", ParticleFlowCandidate_NTimeHits, &b_ParticleFlowCandidate_NTimeHits);
   fChain->SetBranchAddress("ParticleFlowCandidate.Eem", ParticleFlowCandidate_Eem, &b_ParticleFlowCandidate_Eem);
   fChain->SetBranchAddress("ParticleFlowCandidate.Ehad", ParticleFlowCandidate_Ehad, &b_ParticleFlowCandidate_Ehad);
   fChain->SetBranchAddress("ParticleFlowCandidate.Edges[4]", ParticleFlowCandidate_Edges, &b_ParticleFlowCandidate_Edges);
   fChain->SetBranchAddress("ParticleFlowCandidate.Particles", ParticleFlowCandidate_Particles, &b_ParticleFlowCandidate_Particles);
   fChain->SetBranchAddress("ParticleFlowCandidate_size", &ParticleFlowCandidate_size, &b_ParticleFlowCandidate_size);
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon.IsolationVar", Photon_IsolationVar, &b_Photon_IsolationVar);
   fChain->SetBranchAddress("Photon.IsolationVarRhoCorr", Photon_IsolationVarRhoCorr, &b_Photon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Photon.SumPtCharged", Photon_SumPtCharged, &b_Photon_SumPtCharged);
   fChain->SetBranchAddress("Photon.SumPtNeutral", Photon_SumPtNeutral, &b_Photon_SumPtNeutral);
   fChain->SetBranchAddress("Photon.SumPtChargedPU", Photon_SumPtChargedPU, &b_Photon_SumPtChargedPU);
   fChain->SetBranchAddress("Photon.SumPt", Photon_SumPt, &b_Photon_SumPt);
   fChain->SetBranchAddress("Photon.Status", Photon_Status, &b_Photon_Status);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   fChain->SetBranchAddress("PhotonLoose", &PhotonLoose_, &b_PhotonLoose_);
   fChain->SetBranchAddress("PhotonLoose.fUniqueID", PhotonLoose_fUniqueID, &b_PhotonLoose_fUniqueID);
   fChain->SetBranchAddress("PhotonLoose.fBits", PhotonLoose_fBits, &b_PhotonLoose_fBits);
   fChain->SetBranchAddress("PhotonLoose.PT", PhotonLoose_PT, &b_PhotonLoose_PT);
   fChain->SetBranchAddress("PhotonLoose.Eta", PhotonLoose_Eta, &b_PhotonLoose_Eta);
   fChain->SetBranchAddress("PhotonLoose.Phi", PhotonLoose_Phi, &b_PhotonLoose_Phi);
   fChain->SetBranchAddress("PhotonLoose.E", PhotonLoose_E, &b_PhotonLoose_E);
   fChain->SetBranchAddress("PhotonLoose.T", PhotonLoose_T, &b_PhotonLoose_T);
   fChain->SetBranchAddress("PhotonLoose.EhadOverEem", PhotonLoose_EhadOverEem, &b_PhotonLoose_EhadOverEem);
   fChain->SetBranchAddress("PhotonLoose.Particles", PhotonLoose_Particles, &b_PhotonLoose_Particles);
   fChain->SetBranchAddress("PhotonLoose.IsolationVar", PhotonLoose_IsolationVar, &b_PhotonLoose_IsolationVar);
   fChain->SetBranchAddress("PhotonLoose.IsolationVarRhoCorr", PhotonLoose_IsolationVarRhoCorr, &b_PhotonLoose_IsolationVarRhoCorr);
   fChain->SetBranchAddress("PhotonLoose.SumPtCharged", PhotonLoose_SumPtCharged, &b_PhotonLoose_SumPtCharged);
   fChain->SetBranchAddress("PhotonLoose.SumPtNeutral", PhotonLoose_SumPtNeutral, &b_PhotonLoose_SumPtNeutral);
   fChain->SetBranchAddress("PhotonLoose.SumPtChargedPU", PhotonLoose_SumPtChargedPU, &b_PhotonLoose_SumPtChargedPU);
   fChain->SetBranchAddress("PhotonLoose.SumPt", PhotonLoose_SumPt, &b_PhotonLoose_SumPt);
   fChain->SetBranchAddress("PhotonLoose.Status", PhotonLoose_Status, &b_PhotonLoose_Status);
   fChain->SetBranchAddress("PhotonLoose_size", &PhotonLoose_size, &b_PhotonLoose_size);
   fChain->SetBranchAddress("PhotonMedium", &PhotonMedium_, &b_PhotonMedium_);
   fChain->SetBranchAddress("PhotonMedium.fUniqueID", PhotonMedium_fUniqueID, &b_PhotonMedium_fUniqueID);
   fChain->SetBranchAddress("PhotonMedium.fBits", PhotonMedium_fBits, &b_PhotonMedium_fBits);
   fChain->SetBranchAddress("PhotonMedium.PT", PhotonMedium_PT, &b_PhotonMedium_PT);
   fChain->SetBranchAddress("PhotonMedium.Eta", PhotonMedium_Eta, &b_PhotonMedium_Eta);
   fChain->SetBranchAddress("PhotonMedium.Phi", PhotonMedium_Phi, &b_PhotonMedium_Phi);
   fChain->SetBranchAddress("PhotonMedium.E", PhotonMedium_E, &b_PhotonMedium_E);
   fChain->SetBranchAddress("PhotonMedium.T", PhotonMedium_T, &b_PhotonMedium_T);
   fChain->SetBranchAddress("PhotonMedium.EhadOverEem", PhotonMedium_EhadOverEem, &b_PhotonMedium_EhadOverEem);
   fChain->SetBranchAddress("PhotonMedium.Particles", PhotonMedium_Particles, &b_PhotonMedium_Particles);
   fChain->SetBranchAddress("PhotonMedium.IsolationVar", PhotonMedium_IsolationVar, &b_PhotonMedium_IsolationVar);
   fChain->SetBranchAddress("PhotonMedium.IsolationVarRhoCorr", PhotonMedium_IsolationVarRhoCorr, &b_PhotonMedium_IsolationVarRhoCorr);
   fChain->SetBranchAddress("PhotonMedium.SumPtCharged", PhotonMedium_SumPtCharged, &b_PhotonMedium_SumPtCharged);
   fChain->SetBranchAddress("PhotonMedium.SumPtNeutral", PhotonMedium_SumPtNeutral, &b_PhotonMedium_SumPtNeutral);
   fChain->SetBranchAddress("PhotonMedium.SumPtChargedPU", PhotonMedium_SumPtChargedPU, &b_PhotonMedium_SumPtChargedPU);
   fChain->SetBranchAddress("PhotonMedium.SumPt", PhotonMedium_SumPt, &b_PhotonMedium_SumPt);
   fChain->SetBranchAddress("PhotonMedium.Status", PhotonMedium_Status, &b_PhotonMedium_Status);
   fChain->SetBranchAddress("PhotonMedium_size", &PhotonMedium_size, &b_PhotonMedium_size);
   fChain->SetBranchAddress("PhotonTight", &PhotonTight_, &b_PhotonTight_);
   fChain->SetBranchAddress("PhotonTight.fUniqueID", PhotonTight_fUniqueID, &b_PhotonTight_fUniqueID);
   fChain->SetBranchAddress("PhotonTight.fBits", PhotonTight_fBits, &b_PhotonTight_fBits);
   fChain->SetBranchAddress("PhotonTight.PT", PhotonTight_PT, &b_PhotonTight_PT);
   fChain->SetBranchAddress("PhotonTight.Eta", PhotonTight_Eta, &b_PhotonTight_Eta);
   fChain->SetBranchAddress("PhotonTight.Phi", PhotonTight_Phi, &b_PhotonTight_Phi);
   fChain->SetBranchAddress("PhotonTight.E", PhotonTight_E, &b_PhotonTight_E);
   fChain->SetBranchAddress("PhotonTight.T", PhotonTight_T, &b_PhotonTight_T);
   fChain->SetBranchAddress("PhotonTight.EhadOverEem", PhotonTight_EhadOverEem, &b_PhotonTight_EhadOverEem);
   fChain->SetBranchAddress("PhotonTight.Particles", PhotonTight_Particles, &b_PhotonTight_Particles);
   fChain->SetBranchAddress("PhotonTight.IsolationVar", PhotonTight_IsolationVar, &b_PhotonTight_IsolationVar);
   fChain->SetBranchAddress("PhotonTight.IsolationVarRhoCorr", PhotonTight_IsolationVarRhoCorr, &b_PhotonTight_IsolationVarRhoCorr);
   fChain->SetBranchAddress("PhotonTight.SumPtCharged", PhotonTight_SumPtCharged, &b_PhotonTight_SumPtCharged);
   fChain->SetBranchAddress("PhotonTight.SumPtNeutral", PhotonTight_SumPtNeutral, &b_PhotonTight_SumPtNeutral);
   fChain->SetBranchAddress("PhotonTight.SumPtChargedPU", PhotonTight_SumPtChargedPU, &b_PhotonTight_SumPtChargedPU);
   fChain->SetBranchAddress("PhotonTight.SumPt", PhotonTight_SumPt, &b_PhotonTight_SumPt);
   fChain->SetBranchAddress("PhotonTight.Status", PhotonTight_Status, &b_PhotonTight_Status);
   fChain->SetBranchAddress("PhotonTight_size", &PhotonTight_size, &b_PhotonTight_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron.IsolationVar", Electron_IsolationVar, &b_Electron_IsolationVar);
   fChain->SetBranchAddress("Electron.IsolationVarRhoCorr", Electron_IsolationVarRhoCorr, &b_Electron_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Electron.SumPtCharged", Electron_SumPtCharged, &b_Electron_SumPtCharged);
   fChain->SetBranchAddress("Electron.SumPtNeutral", Electron_SumPtNeutral, &b_Electron_SumPtNeutral);
   fChain->SetBranchAddress("Electron.SumPtChargedPU", Electron_SumPtChargedPU, &b_Electron_SumPtChargedPU);
   fChain->SetBranchAddress("Electron.SumPt", Electron_SumPt, &b_Electron_SumPt);
   fChain->SetBranchAddress("Electron.D0", Electron_D0, &b_Electron_D0);
   fChain->SetBranchAddress("Electron.DZ", Electron_DZ, &b_Electron_DZ);
   fChain->SetBranchAddress("Electron.ErrorD0", Electron_ErrorD0, &b_Electron_ErrorD0);
   fChain->SetBranchAddress("Electron.ErrorDZ", Electron_ErrorDZ, &b_Electron_ErrorDZ);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   fChain->SetBranchAddress("ElectronLoose", &ElectronLoose_, &b_ElectronLoose_);
   fChain->SetBranchAddress("ElectronLoose.fUniqueID", ElectronLoose_fUniqueID, &b_ElectronLoose_fUniqueID);
   fChain->SetBranchAddress("ElectronLoose.fBits", ElectronLoose_fBits, &b_ElectronLoose_fBits);
   fChain->SetBranchAddress("ElectronLoose.PT", ElectronLoose_PT, &b_ElectronLoose_PT);
   fChain->SetBranchAddress("ElectronLoose.Eta", ElectronLoose_Eta, &b_ElectronLoose_Eta);
   fChain->SetBranchAddress("ElectronLoose.Phi", ElectronLoose_Phi, &b_ElectronLoose_Phi);
   fChain->SetBranchAddress("ElectronLoose.T", ElectronLoose_T, &b_ElectronLoose_T);
   fChain->SetBranchAddress("ElectronLoose.Charge", ElectronLoose_Charge, &b_ElectronLoose_Charge);
   fChain->SetBranchAddress("ElectronLoose.EhadOverEem", ElectronLoose_EhadOverEem, &b_ElectronLoose_EhadOverEem);
   fChain->SetBranchAddress("ElectronLoose.Particle", ElectronLoose_Particle, &b_ElectronLoose_Particle);
   fChain->SetBranchAddress("ElectronLoose.IsolationVar", ElectronLoose_IsolationVar, &b_ElectronLoose_IsolationVar);
   fChain->SetBranchAddress("ElectronLoose.IsolationVarRhoCorr", ElectronLoose_IsolationVarRhoCorr, &b_ElectronLoose_IsolationVarRhoCorr);
   fChain->SetBranchAddress("ElectronLoose.SumPtCharged", ElectronLoose_SumPtCharged, &b_ElectronLoose_SumPtCharged);
   fChain->SetBranchAddress("ElectronLoose.SumPtNeutral", ElectronLoose_SumPtNeutral, &b_ElectronLoose_SumPtNeutral);
   fChain->SetBranchAddress("ElectronLoose.SumPtChargedPU", ElectronLoose_SumPtChargedPU, &b_ElectronLoose_SumPtChargedPU);
   fChain->SetBranchAddress("ElectronLoose.SumPt", ElectronLoose_SumPt, &b_ElectronLoose_SumPt);
   fChain->SetBranchAddress("ElectronLoose.D0", ElectronLoose_D0, &b_ElectronLoose_D0);
   fChain->SetBranchAddress("ElectronLoose.DZ", ElectronLoose_DZ, &b_ElectronLoose_DZ);
   fChain->SetBranchAddress("ElectronLoose.ErrorD0", ElectronLoose_ErrorD0, &b_ElectronLoose_ErrorD0);
   fChain->SetBranchAddress("ElectronLoose.ErrorDZ", ElectronLoose_ErrorDZ, &b_ElectronLoose_ErrorDZ);
   fChain->SetBranchAddress("ElectronLoose_size", &ElectronLoose_size, &b_ElectronLoose_size);
   fChain->SetBranchAddress("ElectronMedium", &ElectronMedium_, &b_ElectronMedium_);
   fChain->SetBranchAddress("ElectronMedium.fUniqueID", ElectronMedium_fUniqueID, &b_ElectronMedium_fUniqueID);
   fChain->SetBranchAddress("ElectronMedium.fBits", ElectronMedium_fBits, &b_ElectronMedium_fBits);
   fChain->SetBranchAddress("ElectronMedium.PT", ElectronMedium_PT, &b_ElectronMedium_PT);
   fChain->SetBranchAddress("ElectronMedium.Eta", ElectronMedium_Eta, &b_ElectronMedium_Eta);
   fChain->SetBranchAddress("ElectronMedium.Phi", ElectronMedium_Phi, &b_ElectronMedium_Phi);
   fChain->SetBranchAddress("ElectronMedium.T", ElectronMedium_T, &b_ElectronMedium_T);
   fChain->SetBranchAddress("ElectronMedium.Charge", ElectronMedium_Charge, &b_ElectronMedium_Charge);
   fChain->SetBranchAddress("ElectronMedium.EhadOverEem", ElectronMedium_EhadOverEem, &b_ElectronMedium_EhadOverEem);
   fChain->SetBranchAddress("ElectronMedium.Particle", ElectronMedium_Particle, &b_ElectronMedium_Particle);
   fChain->SetBranchAddress("ElectronMedium.IsolationVar", ElectronMedium_IsolationVar, &b_ElectronMedium_IsolationVar);
   fChain->SetBranchAddress("ElectronMedium.IsolationVarRhoCorr", ElectronMedium_IsolationVarRhoCorr, &b_ElectronMedium_IsolationVarRhoCorr);
   fChain->SetBranchAddress("ElectronMedium.SumPtCharged", ElectronMedium_SumPtCharged, &b_ElectronMedium_SumPtCharged);
   fChain->SetBranchAddress("ElectronMedium.SumPtNeutral", ElectronMedium_SumPtNeutral, &b_ElectronMedium_SumPtNeutral);
   fChain->SetBranchAddress("ElectronMedium.SumPtChargedPU", ElectronMedium_SumPtChargedPU, &b_ElectronMedium_SumPtChargedPU);
   fChain->SetBranchAddress("ElectronMedium.SumPt", ElectronMedium_SumPt, &b_ElectronMedium_SumPt);
   fChain->SetBranchAddress("ElectronMedium.D0", ElectronMedium_D0, &b_ElectronMedium_D0);
   fChain->SetBranchAddress("ElectronMedium.DZ", ElectronMedium_DZ, &b_ElectronMedium_DZ);
   fChain->SetBranchAddress("ElectronMedium.ErrorD0", ElectronMedium_ErrorD0, &b_ElectronMedium_ErrorD0);
   fChain->SetBranchAddress("ElectronMedium.ErrorDZ", ElectronMedium_ErrorDZ, &b_ElectronMedium_ErrorDZ);
   fChain->SetBranchAddress("ElectronMedium_size", &ElectronMedium_size, &b_ElectronMedium_size);
   fChain->SetBranchAddress("ElectronTight", &ElectronTight_, &b_ElectronTight_);
   fChain->SetBranchAddress("ElectronTight.fUniqueID", ElectronTight_fUniqueID, &b_ElectronTight_fUniqueID);
   fChain->SetBranchAddress("ElectronTight.fBits", ElectronTight_fBits, &b_ElectronTight_fBits);
   fChain->SetBranchAddress("ElectronTight.PT", ElectronTight_PT, &b_ElectronTight_PT);
   fChain->SetBranchAddress("ElectronTight.Eta", ElectronTight_Eta, &b_ElectronTight_Eta);
   fChain->SetBranchAddress("ElectronTight.Phi", ElectronTight_Phi, &b_ElectronTight_Phi);
   fChain->SetBranchAddress("ElectronTight.T", ElectronTight_T, &b_ElectronTight_T);
   fChain->SetBranchAddress("ElectronTight.Charge", ElectronTight_Charge, &b_ElectronTight_Charge);
   fChain->SetBranchAddress("ElectronTight.EhadOverEem", ElectronTight_EhadOverEem, &b_ElectronTight_EhadOverEem);
   fChain->SetBranchAddress("ElectronTight.Particle", ElectronTight_Particle, &b_ElectronTight_Particle);
   fChain->SetBranchAddress("ElectronTight.IsolationVar", ElectronTight_IsolationVar, &b_ElectronTight_IsolationVar);
   fChain->SetBranchAddress("ElectronTight.IsolationVarRhoCorr", ElectronTight_IsolationVarRhoCorr, &b_ElectronTight_IsolationVarRhoCorr);
   fChain->SetBranchAddress("ElectronTight.SumPtCharged", ElectronTight_SumPtCharged, &b_ElectronTight_SumPtCharged);
   fChain->SetBranchAddress("ElectronTight.SumPtNeutral", ElectronTight_SumPtNeutral, &b_ElectronTight_SumPtNeutral);
   fChain->SetBranchAddress("ElectronTight.SumPtChargedPU", ElectronTight_SumPtChargedPU, &b_ElectronTight_SumPtChargedPU);
   fChain->SetBranchAddress("ElectronTight.SumPt", ElectronTight_SumPt, &b_ElectronTight_SumPt);
   fChain->SetBranchAddress("ElectronTight.D0", ElectronTight_D0, &b_ElectronTight_D0);
   fChain->SetBranchAddress("ElectronTight.DZ", ElectronTight_DZ, &b_ElectronTight_DZ);
   fChain->SetBranchAddress("ElectronTight.ErrorD0", ElectronTight_ErrorD0, &b_ElectronTight_ErrorD0);
   fChain->SetBranchAddress("ElectronTight.ErrorDZ", ElectronTight_ErrorDZ, &b_ElectronTight_ErrorDZ);
   fChain->SetBranchAddress("ElectronTight_size", &ElectronTight_size, &b_ElectronTight_size);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.T", Muon_T, &b_Muon_T);
   fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon.IsolationVar", Muon_IsolationVar, &b_Muon_IsolationVar);
   fChain->SetBranchAddress("Muon.IsolationVarRhoCorr", Muon_IsolationVarRhoCorr, &b_Muon_IsolationVarRhoCorr);
   fChain->SetBranchAddress("Muon.SumPtCharged", Muon_SumPtCharged, &b_Muon_SumPtCharged);
   fChain->SetBranchAddress("Muon.SumPtNeutral", Muon_SumPtNeutral, &b_Muon_SumPtNeutral);
   fChain->SetBranchAddress("Muon.SumPtChargedPU", Muon_SumPtChargedPU, &b_Muon_SumPtChargedPU);
   fChain->SetBranchAddress("Muon.SumPt", Muon_SumPt, &b_Muon_SumPt);
   fChain->SetBranchAddress("Muon.D0", Muon_D0, &b_Muon_D0);
   fChain->SetBranchAddress("Muon.DZ", Muon_DZ, &b_Muon_DZ);
   fChain->SetBranchAddress("Muon.ErrorD0", Muon_ErrorD0, &b_Muon_ErrorD0);
   fChain->SetBranchAddress("Muon.ErrorDZ", Muon_ErrorDZ, &b_Muon_ErrorDZ);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("MuonLoose", &MuonLoose_, &b_MuonLoose_);
   fChain->SetBranchAddress("MuonLoose.fUniqueID", MuonLoose_fUniqueID, &b_MuonLoose_fUniqueID);
   fChain->SetBranchAddress("MuonLoose.fBits", MuonLoose_fBits, &b_MuonLoose_fBits);
   fChain->SetBranchAddress("MuonLoose.PT", MuonLoose_PT, &b_MuonLoose_PT);
   fChain->SetBranchAddress("MuonLoose.Eta", MuonLoose_Eta, &b_MuonLoose_Eta);
   fChain->SetBranchAddress("MuonLoose.Phi", MuonLoose_Phi, &b_MuonLoose_Phi);
   fChain->SetBranchAddress("MuonLoose.T", MuonLoose_T, &b_MuonLoose_T);
   fChain->SetBranchAddress("MuonLoose.Charge", MuonLoose_Charge, &b_MuonLoose_Charge);
   fChain->SetBranchAddress("MuonLoose.Particle", MuonLoose_Particle, &b_MuonLoose_Particle);
   fChain->SetBranchAddress("MuonLoose.IsolationVar", MuonLoose_IsolationVar, &b_MuonLoose_IsolationVar);
   fChain->SetBranchAddress("MuonLoose.IsolationVarRhoCorr", MuonLoose_IsolationVarRhoCorr, &b_MuonLoose_IsolationVarRhoCorr);
   fChain->SetBranchAddress("MuonLoose.SumPtCharged", MuonLoose_SumPtCharged, &b_MuonLoose_SumPtCharged);
   fChain->SetBranchAddress("MuonLoose.SumPtNeutral", MuonLoose_SumPtNeutral, &b_MuonLoose_SumPtNeutral);
   fChain->SetBranchAddress("MuonLoose.SumPtChargedPU", MuonLoose_SumPtChargedPU, &b_MuonLoose_SumPtChargedPU);
   fChain->SetBranchAddress("MuonLoose.SumPt", MuonLoose_SumPt, &b_MuonLoose_SumPt);
   fChain->SetBranchAddress("MuonLoose.D0", MuonLoose_D0, &b_MuonLoose_D0);
   fChain->SetBranchAddress("MuonLoose.DZ", MuonLoose_DZ, &b_MuonLoose_DZ);
   fChain->SetBranchAddress("MuonLoose.ErrorD0", MuonLoose_ErrorD0, &b_MuonLoose_ErrorD0);
   fChain->SetBranchAddress("MuonLoose.ErrorDZ", MuonLoose_ErrorDZ, &b_MuonLoose_ErrorDZ);
   fChain->SetBranchAddress("MuonLoose_size", &MuonLoose_size, &b_MuonLoose_size);
   fChain->SetBranchAddress("MuonMedium", &MuonMedium_, &b_MuonMedium_);
   fChain->SetBranchAddress("MuonMedium.fUniqueID", MuonMedium_fUniqueID, &b_MuonMedium_fUniqueID);
   fChain->SetBranchAddress("MuonMedium.fBits", MuonMedium_fBits, &b_MuonMedium_fBits);
   fChain->SetBranchAddress("MuonMedium.PT", MuonMedium_PT, &b_MuonMedium_PT);
   fChain->SetBranchAddress("MuonMedium.Eta", MuonMedium_Eta, &b_MuonMedium_Eta);
   fChain->SetBranchAddress("MuonMedium.Phi", MuonMedium_Phi, &b_MuonMedium_Phi);
   fChain->SetBranchAddress("MuonMedium.T", MuonMedium_T, &b_MuonMedium_T);
   fChain->SetBranchAddress("MuonMedium.Charge", MuonMedium_Charge, &b_MuonMedium_Charge);
   fChain->SetBranchAddress("MuonMedium.Particle", MuonMedium_Particle, &b_MuonMedium_Particle);
   fChain->SetBranchAddress("MuonMedium.IsolationVar", MuonMedium_IsolationVar, &b_MuonMedium_IsolationVar);
   fChain->SetBranchAddress("MuonMedium.IsolationVarRhoCorr", MuonMedium_IsolationVarRhoCorr, &b_MuonMedium_IsolationVarRhoCorr);
   fChain->SetBranchAddress("MuonMedium.SumPtCharged", MuonMedium_SumPtCharged, &b_MuonMedium_SumPtCharged);
   fChain->SetBranchAddress("MuonMedium.SumPtNeutral", MuonMedium_SumPtNeutral, &b_MuonMedium_SumPtNeutral);
   fChain->SetBranchAddress("MuonMedium.SumPtChargedPU", MuonMedium_SumPtChargedPU, &b_MuonMedium_SumPtChargedPU);
   fChain->SetBranchAddress("MuonMedium.SumPt", MuonMedium_SumPt, &b_MuonMedium_SumPt);
   fChain->SetBranchAddress("MuonMedium.D0", MuonMedium_D0, &b_MuonMedium_D0);
   fChain->SetBranchAddress("MuonMedium.DZ", MuonMedium_DZ, &b_MuonMedium_DZ);
   fChain->SetBranchAddress("MuonMedium.ErrorD0", MuonMedium_ErrorD0, &b_MuonMedium_ErrorD0);
   fChain->SetBranchAddress("MuonMedium.ErrorDZ", MuonMedium_ErrorDZ, &b_MuonMedium_ErrorDZ);
   fChain->SetBranchAddress("MuonMedium_size", &MuonMedium_size, &b_MuonMedium_size);
   fChain->SetBranchAddress("MuonTight", &MuonTight_, &b_MuonTight_);
   fChain->SetBranchAddress("MuonTight.fUniqueID", MuonTight_fUniqueID, &b_MuonTight_fUniqueID);
   fChain->SetBranchAddress("MuonTight.fBits", MuonTight_fBits, &b_MuonTight_fBits);
   fChain->SetBranchAddress("MuonTight.PT", MuonTight_PT, &b_MuonTight_PT);
   fChain->SetBranchAddress("MuonTight.Eta", MuonTight_Eta, &b_MuonTight_Eta);
   fChain->SetBranchAddress("MuonTight.Phi", MuonTight_Phi, &b_MuonTight_Phi);
   fChain->SetBranchAddress("MuonTight.T", MuonTight_T, &b_MuonTight_T);
   fChain->SetBranchAddress("MuonTight.Charge", MuonTight_Charge, &b_MuonTight_Charge);
   fChain->SetBranchAddress("MuonTight.Particle", MuonTight_Particle, &b_MuonTight_Particle);
   fChain->SetBranchAddress("MuonTight.IsolationVar", MuonTight_IsolationVar, &b_MuonTight_IsolationVar);
   fChain->SetBranchAddress("MuonTight.IsolationVarRhoCorr", MuonTight_IsolationVarRhoCorr, &b_MuonTight_IsolationVarRhoCorr);
   fChain->SetBranchAddress("MuonTight.SumPtCharged", MuonTight_SumPtCharged, &b_MuonTight_SumPtCharged);
   fChain->SetBranchAddress("MuonTight.SumPtNeutral", MuonTight_SumPtNeutral, &b_MuonTight_SumPtNeutral);
   fChain->SetBranchAddress("MuonTight.SumPtChargedPU", MuonTight_SumPtChargedPU, &b_MuonTight_SumPtChargedPU);
   fChain->SetBranchAddress("MuonTight.SumPt", MuonTight_SumPt, &b_MuonTight_SumPt);
   fChain->SetBranchAddress("MuonTight.D0", MuonTight_D0, &b_MuonTight_D0);
   fChain->SetBranchAddress("MuonTight.DZ", MuonTight_DZ, &b_MuonTight_DZ);
   fChain->SetBranchAddress("MuonTight.ErrorD0", MuonTight_ErrorD0, &b_MuonTight_ErrorD0);
   fChain->SetBranchAddress("MuonTight.ErrorDZ", MuonTight_ErrorDZ, &b_MuonTight_ErrorDZ);
   fChain->SetBranchAddress("MuonTight_size", &MuonTight_size, &b_MuonTight_size);
   fChain->SetBranchAddress("JetPUPPI", &JetPUPPI_, &b_JetPUPPI_);
   fChain->SetBranchAddress("JetPUPPI.fUniqueID", JetPUPPI_fUniqueID, &b_JetPUPPI_fUniqueID);
   fChain->SetBranchAddress("JetPUPPI.fBits", JetPUPPI_fBits, &b_JetPUPPI_fBits);
   fChain->SetBranchAddress("JetPUPPI.PT", JetPUPPI_PT, &b_JetPUPPI_PT);
   fChain->SetBranchAddress("JetPUPPI.Eta", JetPUPPI_Eta, &b_JetPUPPI_Eta);
   fChain->SetBranchAddress("JetPUPPI.Phi", JetPUPPI_Phi, &b_JetPUPPI_Phi);
   fChain->SetBranchAddress("JetPUPPI.T", JetPUPPI_T, &b_JetPUPPI_T);
   fChain->SetBranchAddress("JetPUPPI.Mass", JetPUPPI_Mass, &b_JetPUPPI_Mass);
   fChain->SetBranchAddress("JetPUPPI.DeltaEta", JetPUPPI_DeltaEta, &b_JetPUPPI_DeltaEta);
   fChain->SetBranchAddress("JetPUPPI.DeltaPhi", JetPUPPI_DeltaPhi, &b_JetPUPPI_DeltaPhi);
   fChain->SetBranchAddress("JetPUPPI.Flavor", JetPUPPI_Flavor, &b_JetPUPPI_Flavor);
   fChain->SetBranchAddress("JetPUPPI.FlavorAlgo", JetPUPPI_FlavorAlgo, &b_JetPUPPI_FlavorAlgo);
   fChain->SetBranchAddress("JetPUPPI.FlavorPhys", JetPUPPI_FlavorPhys, &b_JetPUPPI_FlavorPhys);
   fChain->SetBranchAddress("JetPUPPI.BTag", JetPUPPI_BTag, &b_JetPUPPI_BTag);
   fChain->SetBranchAddress("JetPUPPI.BTagAlgo", JetPUPPI_BTagAlgo, &b_JetPUPPI_BTagAlgo);
   fChain->SetBranchAddress("JetPUPPI.BTagPhys", JetPUPPI_BTagPhys, &b_JetPUPPI_BTagPhys);
   fChain->SetBranchAddress("JetPUPPI.TauTag", JetPUPPI_TauTag, &b_JetPUPPI_TauTag);
   fChain->SetBranchAddress("JetPUPPI.TauWeight", JetPUPPI_TauWeight, &b_JetPUPPI_TauWeight);
   fChain->SetBranchAddress("JetPUPPI.Charge", JetPUPPI_Charge, &b_JetPUPPI_Charge);
   fChain->SetBranchAddress("JetPUPPI.EhadOverEem", JetPUPPI_EhadOverEem, &b_JetPUPPI_EhadOverEem);
   fChain->SetBranchAddress("JetPUPPI.NCharged", JetPUPPI_NCharged, &b_JetPUPPI_NCharged);
   fChain->SetBranchAddress("JetPUPPI.NNeutrals", JetPUPPI_NNeutrals, &b_JetPUPPI_NNeutrals);
   fChain->SetBranchAddress("JetPUPPI.NeutralEnergyFraction", JetPUPPI_NeutralEnergyFraction, &b_JetPUPPI_NeutralEnergyFraction);
   fChain->SetBranchAddress("JetPUPPI.ChargedEnergyFraction", JetPUPPI_ChargedEnergyFraction, &b_JetPUPPI_ChargedEnergyFraction);
   fChain->SetBranchAddress("JetPUPPI.Beta", JetPUPPI_Beta, &b_JetPUPPI_Beta);
   fChain->SetBranchAddress("JetPUPPI.BetaStar", JetPUPPI_BetaStar, &b_JetPUPPI_BetaStar);
   fChain->SetBranchAddress("JetPUPPI.MeanSqDeltaR", JetPUPPI_MeanSqDeltaR, &b_JetPUPPI_MeanSqDeltaR);
   fChain->SetBranchAddress("JetPUPPI.PTD", JetPUPPI_PTD, &b_JetPUPPI_PTD);
   fChain->SetBranchAddress("JetPUPPI.FracPt[5]", JetPUPPI_FracPt, &b_JetPUPPI_FracPt);
   fChain->SetBranchAddress("JetPUPPI.Tau[5]", JetPUPPI_Tau, &b_JetPUPPI_Tau);
   fChain->SetBranchAddress("JetPUPPI.SoftDroppedJet", JetPUPPI_SoftDroppedJet, &b_JetPUPPI_SoftDroppedJet);
   fChain->SetBranchAddress("JetPUPPI.SoftDroppedSubJet1", JetPUPPI_SoftDroppedSubJet1, &b_JetPUPPI_SoftDroppedSubJet1);
   fChain->SetBranchAddress("JetPUPPI.SoftDroppedSubJet2", JetPUPPI_SoftDroppedSubJet2, &b_JetPUPPI_SoftDroppedSubJet2);
   fChain->SetBranchAddress("JetPUPPI.TrimmedP4[5]", JetPUPPI_TrimmedP4, &b_JetPUPPI_TrimmedP4);
   fChain->SetBranchAddress("JetPUPPI.PrunedP4[5]", JetPUPPI_PrunedP4, &b_JetPUPPI_PrunedP4);
   fChain->SetBranchAddress("JetPUPPI.SoftDroppedP4[5]", JetPUPPI_SoftDroppedP4, &b_JetPUPPI_SoftDroppedP4);
   fChain->SetBranchAddress("JetPUPPI.NSubJetsTrimmed", JetPUPPI_NSubJetsTrimmed, &b_JetPUPPI_NSubJetsTrimmed);
   fChain->SetBranchAddress("JetPUPPI.NSubJetsPruned", JetPUPPI_NSubJetsPruned, &b_JetPUPPI_NSubJetsPruned);
   fChain->SetBranchAddress("JetPUPPI.NSubJetsSoftDropped", JetPUPPI_NSubJetsSoftDropped, &b_JetPUPPI_NSubJetsSoftDropped);
   fChain->SetBranchAddress("JetPUPPI.ExclYmerge23", JetPUPPI_ExclYmerge23, &b_JetPUPPI_ExclYmerge23);
   fChain->SetBranchAddress("JetPUPPI.ExclYmerge34", JetPUPPI_ExclYmerge34, &b_JetPUPPI_ExclYmerge34);
   fChain->SetBranchAddress("JetPUPPI.ExclYmerge45", JetPUPPI_ExclYmerge45, &b_JetPUPPI_ExclYmerge45);
   fChain->SetBranchAddress("JetPUPPI.ExclYmerge56", JetPUPPI_ExclYmerge56, &b_JetPUPPI_ExclYmerge56);
   fChain->SetBranchAddress("JetPUPPI.Constituents", JetPUPPI_Constituents, &b_JetPUPPI_Constituents);
   fChain->SetBranchAddress("JetPUPPI.Particles", JetPUPPI_Particles, &b_JetPUPPI_Particles);
   fChain->SetBranchAddress("JetPUPPI.Area", JetPUPPI_Area, &b_JetPUPPI_Area);
   fChain->SetBranchAddress("JetPUPPI_size", &JetPUPPI_size, &b_JetPUPPI_size);
   fChain->SetBranchAddress("JetPUPPIAK8", &JetPUPPIAK8_, &b_JetPUPPIAK8_);
   fChain->SetBranchAddress("JetPUPPIAK8.fUniqueID", JetPUPPIAK8_fUniqueID, &b_JetPUPPIAK8_fUniqueID);
   fChain->SetBranchAddress("JetPUPPIAK8.fBits", JetPUPPIAK8_fBits, &b_JetPUPPIAK8_fBits);
   fChain->SetBranchAddress("JetPUPPIAK8.PT", JetPUPPIAK8_PT, &b_JetPUPPIAK8_PT);
   fChain->SetBranchAddress("JetPUPPIAK8.Eta", JetPUPPIAK8_Eta, &b_JetPUPPIAK8_Eta);
   fChain->SetBranchAddress("JetPUPPIAK8.Phi", JetPUPPIAK8_Phi, &b_JetPUPPIAK8_Phi);
   fChain->SetBranchAddress("JetPUPPIAK8.T", JetPUPPIAK8_T, &b_JetPUPPIAK8_T);
   fChain->SetBranchAddress("JetPUPPIAK8.Mass", JetPUPPIAK8_Mass, &b_JetPUPPIAK8_Mass);
   fChain->SetBranchAddress("JetPUPPIAK8.DeltaEta", JetPUPPIAK8_DeltaEta, &b_JetPUPPIAK8_DeltaEta);
   fChain->SetBranchAddress("JetPUPPIAK8.DeltaPhi", JetPUPPIAK8_DeltaPhi, &b_JetPUPPIAK8_DeltaPhi);
   fChain->SetBranchAddress("JetPUPPIAK8.Flavor", JetPUPPIAK8_Flavor, &b_JetPUPPIAK8_Flavor);
   fChain->SetBranchAddress("JetPUPPIAK8.FlavorAlgo", JetPUPPIAK8_FlavorAlgo, &b_JetPUPPIAK8_FlavorAlgo);
   fChain->SetBranchAddress("JetPUPPIAK8.FlavorPhys", JetPUPPIAK8_FlavorPhys, &b_JetPUPPIAK8_FlavorPhys);
   fChain->SetBranchAddress("JetPUPPIAK8.BTag", JetPUPPIAK8_BTag, &b_JetPUPPIAK8_BTag);
   fChain->SetBranchAddress("JetPUPPIAK8.BTagAlgo", JetPUPPIAK8_BTagAlgo, &b_JetPUPPIAK8_BTagAlgo);
   fChain->SetBranchAddress("JetPUPPIAK8.BTagPhys", JetPUPPIAK8_BTagPhys, &b_JetPUPPIAK8_BTagPhys);
   fChain->SetBranchAddress("JetPUPPIAK8.TauTag", JetPUPPIAK8_TauTag, &b_JetPUPPIAK8_TauTag);
   fChain->SetBranchAddress("JetPUPPIAK8.TauWeight", JetPUPPIAK8_TauWeight, &b_JetPUPPIAK8_TauWeight);
   fChain->SetBranchAddress("JetPUPPIAK8.Charge", JetPUPPIAK8_Charge, &b_JetPUPPIAK8_Charge);
   fChain->SetBranchAddress("JetPUPPIAK8.EhadOverEem", JetPUPPIAK8_EhadOverEem, &b_JetPUPPIAK8_EhadOverEem);
   fChain->SetBranchAddress("JetPUPPIAK8.NCharged", JetPUPPIAK8_NCharged, &b_JetPUPPIAK8_NCharged);
   fChain->SetBranchAddress("JetPUPPIAK8.NNeutrals", JetPUPPIAK8_NNeutrals, &b_JetPUPPIAK8_NNeutrals);
   fChain->SetBranchAddress("JetPUPPIAK8.NeutralEnergyFraction", JetPUPPIAK8_NeutralEnergyFraction, &b_JetPUPPIAK8_NeutralEnergyFraction);
   fChain->SetBranchAddress("JetPUPPIAK8.ChargedEnergyFraction", JetPUPPIAK8_ChargedEnergyFraction, &b_JetPUPPIAK8_ChargedEnergyFraction);
   fChain->SetBranchAddress("JetPUPPIAK8.Beta", JetPUPPIAK8_Beta, &b_JetPUPPIAK8_Beta);
   fChain->SetBranchAddress("JetPUPPIAK8.BetaStar", JetPUPPIAK8_BetaStar, &b_JetPUPPIAK8_BetaStar);
   fChain->SetBranchAddress("JetPUPPIAK8.MeanSqDeltaR", JetPUPPIAK8_MeanSqDeltaR, &b_JetPUPPIAK8_MeanSqDeltaR);
   fChain->SetBranchAddress("JetPUPPIAK8.PTD", JetPUPPIAK8_PTD, &b_JetPUPPIAK8_PTD);
   fChain->SetBranchAddress("JetPUPPIAK8.FracPt[5]", JetPUPPIAK8_FracPt, &b_JetPUPPIAK8_FracPt);
   fChain->SetBranchAddress("JetPUPPIAK8.Tau[5]", JetPUPPIAK8_Tau, &b_JetPUPPIAK8_Tau);
   fChain->SetBranchAddress("JetPUPPIAK8.SoftDroppedJet", JetPUPPIAK8_SoftDroppedJet, &b_JetPUPPIAK8_SoftDroppedJet);
   fChain->SetBranchAddress("JetPUPPIAK8.SoftDroppedSubJet1", JetPUPPIAK8_SoftDroppedSubJet1, &b_JetPUPPIAK8_SoftDroppedSubJet1);
   fChain->SetBranchAddress("JetPUPPIAK8.SoftDroppedSubJet2", JetPUPPIAK8_SoftDroppedSubJet2, &b_JetPUPPIAK8_SoftDroppedSubJet2);
   fChain->SetBranchAddress("JetPUPPIAK8.TrimmedP4[5]", JetPUPPIAK8_TrimmedP4, &b_JetPUPPIAK8_TrimmedP4);
   fChain->SetBranchAddress("JetPUPPIAK8.PrunedP4[5]", JetPUPPIAK8_PrunedP4, &b_JetPUPPIAK8_PrunedP4);
   fChain->SetBranchAddress("JetPUPPIAK8.SoftDroppedP4[5]", JetPUPPIAK8_SoftDroppedP4, &b_JetPUPPIAK8_SoftDroppedP4);
   fChain->SetBranchAddress("JetPUPPIAK8.NSubJetsTrimmed", JetPUPPIAK8_NSubJetsTrimmed, &b_JetPUPPIAK8_NSubJetsTrimmed);
   fChain->SetBranchAddress("JetPUPPIAK8.NSubJetsPruned", JetPUPPIAK8_NSubJetsPruned, &b_JetPUPPIAK8_NSubJetsPruned);
   fChain->SetBranchAddress("JetPUPPIAK8.NSubJetsSoftDropped", JetPUPPIAK8_NSubJetsSoftDropped, &b_JetPUPPIAK8_NSubJetsSoftDropped);
   fChain->SetBranchAddress("JetPUPPIAK8.ExclYmerge23", JetPUPPIAK8_ExclYmerge23, &b_JetPUPPIAK8_ExclYmerge23);
   fChain->SetBranchAddress("JetPUPPIAK8.ExclYmerge34", JetPUPPIAK8_ExclYmerge34, &b_JetPUPPIAK8_ExclYmerge34);
   fChain->SetBranchAddress("JetPUPPIAK8.ExclYmerge45", JetPUPPIAK8_ExclYmerge45, &b_JetPUPPIAK8_ExclYmerge45);
   fChain->SetBranchAddress("JetPUPPIAK8.ExclYmerge56", JetPUPPIAK8_ExclYmerge56, &b_JetPUPPIAK8_ExclYmerge56);
   fChain->SetBranchAddress("JetPUPPIAK8.Constituents", JetPUPPIAK8_Constituents, &b_JetPUPPIAK8_Constituents);
   fChain->SetBranchAddress("JetPUPPIAK8.Particles", JetPUPPIAK8_Particles, &b_JetPUPPIAK8_Particles);
   fChain->SetBranchAddress("JetPUPPIAK8.Area", JetPUPPIAK8_Area, &b_JetPUPPIAK8_Area);
   fChain->SetBranchAddress("JetPUPPIAK8_size", &JetPUPPIAK8_size, &b_JetPUPPIAK8_size);
   fChain->SetBranchAddress("JetPUPPILoose", &JetPUPPILoose_, &b_JetPUPPILoose_);
   fChain->SetBranchAddress("JetPUPPILoose.fUniqueID", JetPUPPILoose_fUniqueID, &b_JetPUPPILoose_fUniqueID);
   fChain->SetBranchAddress("JetPUPPILoose.fBits", JetPUPPILoose_fBits, &b_JetPUPPILoose_fBits);
   fChain->SetBranchAddress("JetPUPPILoose.PT", JetPUPPILoose_PT, &b_JetPUPPILoose_PT);
   fChain->SetBranchAddress("JetPUPPILoose.Eta", JetPUPPILoose_Eta, &b_JetPUPPILoose_Eta);
   fChain->SetBranchAddress("JetPUPPILoose.Phi", JetPUPPILoose_Phi, &b_JetPUPPILoose_Phi);
   fChain->SetBranchAddress("JetPUPPILoose.T", JetPUPPILoose_T, &b_JetPUPPILoose_T);
   fChain->SetBranchAddress("JetPUPPILoose.Mass", JetPUPPILoose_Mass, &b_JetPUPPILoose_Mass);
   fChain->SetBranchAddress("JetPUPPILoose.DeltaEta", JetPUPPILoose_DeltaEta, &b_JetPUPPILoose_DeltaEta);
   fChain->SetBranchAddress("JetPUPPILoose.DeltaPhi", JetPUPPILoose_DeltaPhi, &b_JetPUPPILoose_DeltaPhi);
   fChain->SetBranchAddress("JetPUPPILoose.Flavor", JetPUPPILoose_Flavor, &b_JetPUPPILoose_Flavor);
   fChain->SetBranchAddress("JetPUPPILoose.FlavorAlgo", JetPUPPILoose_FlavorAlgo, &b_JetPUPPILoose_FlavorAlgo);
   fChain->SetBranchAddress("JetPUPPILoose.FlavorPhys", JetPUPPILoose_FlavorPhys, &b_JetPUPPILoose_FlavorPhys);
   fChain->SetBranchAddress("JetPUPPILoose.BTag", JetPUPPILoose_BTag, &b_JetPUPPILoose_BTag);
   fChain->SetBranchAddress("JetPUPPILoose.BTagAlgo", JetPUPPILoose_BTagAlgo, &b_JetPUPPILoose_BTagAlgo);
   fChain->SetBranchAddress("JetPUPPILoose.BTagPhys", JetPUPPILoose_BTagPhys, &b_JetPUPPILoose_BTagPhys);
   fChain->SetBranchAddress("JetPUPPILoose.TauTag", JetPUPPILoose_TauTag, &b_JetPUPPILoose_TauTag);
   fChain->SetBranchAddress("JetPUPPILoose.TauWeight", JetPUPPILoose_TauWeight, &b_JetPUPPILoose_TauWeight);
   fChain->SetBranchAddress("JetPUPPILoose.Charge", JetPUPPILoose_Charge, &b_JetPUPPILoose_Charge);
   fChain->SetBranchAddress("JetPUPPILoose.EhadOverEem", JetPUPPILoose_EhadOverEem, &b_JetPUPPILoose_EhadOverEem);
   fChain->SetBranchAddress("JetPUPPILoose.NCharged", JetPUPPILoose_NCharged, &b_JetPUPPILoose_NCharged);
   fChain->SetBranchAddress("JetPUPPILoose.NNeutrals", JetPUPPILoose_NNeutrals, &b_JetPUPPILoose_NNeutrals);
   fChain->SetBranchAddress("JetPUPPILoose.NeutralEnergyFraction", JetPUPPILoose_NeutralEnergyFraction, &b_JetPUPPILoose_NeutralEnergyFraction);
   fChain->SetBranchAddress("JetPUPPILoose.ChargedEnergyFraction", JetPUPPILoose_ChargedEnergyFraction, &b_JetPUPPILoose_ChargedEnergyFraction);
   fChain->SetBranchAddress("JetPUPPILoose.Beta", JetPUPPILoose_Beta, &b_JetPUPPILoose_Beta);
   fChain->SetBranchAddress("JetPUPPILoose.BetaStar", JetPUPPILoose_BetaStar, &b_JetPUPPILoose_BetaStar);
   fChain->SetBranchAddress("JetPUPPILoose.MeanSqDeltaR", JetPUPPILoose_MeanSqDeltaR, &b_JetPUPPILoose_MeanSqDeltaR);
   fChain->SetBranchAddress("JetPUPPILoose.PTD", JetPUPPILoose_PTD, &b_JetPUPPILoose_PTD);
   fChain->SetBranchAddress("JetPUPPILoose.FracPt[5]", JetPUPPILoose_FracPt, &b_JetPUPPILoose_FracPt);
   fChain->SetBranchAddress("JetPUPPILoose.Tau[5]", JetPUPPILoose_Tau, &b_JetPUPPILoose_Tau);
   fChain->SetBranchAddress("JetPUPPILoose.SoftDroppedJet", JetPUPPILoose_SoftDroppedJet, &b_JetPUPPILoose_SoftDroppedJet);
   fChain->SetBranchAddress("JetPUPPILoose.SoftDroppedSubJet1", JetPUPPILoose_SoftDroppedSubJet1, &b_JetPUPPILoose_SoftDroppedSubJet1);
   fChain->SetBranchAddress("JetPUPPILoose.SoftDroppedSubJet2", JetPUPPILoose_SoftDroppedSubJet2, &b_JetPUPPILoose_SoftDroppedSubJet2);
   fChain->SetBranchAddress("JetPUPPILoose.TrimmedP4[5]", JetPUPPILoose_TrimmedP4, &b_JetPUPPILoose_TrimmedP4);
   fChain->SetBranchAddress("JetPUPPILoose.PrunedP4[5]", JetPUPPILoose_PrunedP4, &b_JetPUPPILoose_PrunedP4);
   fChain->SetBranchAddress("JetPUPPILoose.SoftDroppedP4[5]", JetPUPPILoose_SoftDroppedP4, &b_JetPUPPILoose_SoftDroppedP4);
   fChain->SetBranchAddress("JetPUPPILoose.NSubJetsTrimmed", JetPUPPILoose_NSubJetsTrimmed, &b_JetPUPPILoose_NSubJetsTrimmed);
   fChain->SetBranchAddress("JetPUPPILoose.NSubJetsPruned", JetPUPPILoose_NSubJetsPruned, &b_JetPUPPILoose_NSubJetsPruned);
   fChain->SetBranchAddress("JetPUPPILoose.NSubJetsSoftDropped", JetPUPPILoose_NSubJetsSoftDropped, &b_JetPUPPILoose_NSubJetsSoftDropped);
   fChain->SetBranchAddress("JetPUPPILoose.ExclYmerge23", JetPUPPILoose_ExclYmerge23, &b_JetPUPPILoose_ExclYmerge23);
   fChain->SetBranchAddress("JetPUPPILoose.ExclYmerge34", JetPUPPILoose_ExclYmerge34, &b_JetPUPPILoose_ExclYmerge34);
   fChain->SetBranchAddress("JetPUPPILoose.ExclYmerge45", JetPUPPILoose_ExclYmerge45, &b_JetPUPPILoose_ExclYmerge45);
   fChain->SetBranchAddress("JetPUPPILoose.ExclYmerge56", JetPUPPILoose_ExclYmerge56, &b_JetPUPPILoose_ExclYmerge56);
   fChain->SetBranchAddress("JetPUPPILoose.Constituents", JetPUPPILoose_Constituents, &b_JetPUPPILoose_Constituents);
   fChain->SetBranchAddress("JetPUPPILoose.Particles", JetPUPPILoose_Particles, &b_JetPUPPILoose_Particles);
   fChain->SetBranchAddress("JetPUPPILoose.Area", JetPUPPILoose_Area, &b_JetPUPPILoose_Area);
   fChain->SetBranchAddress("JetPUPPILoose_size", &JetPUPPILoose_size, &b_JetPUPPILoose_size);
   fChain->SetBranchAddress("JetPUPPITight", &JetPUPPITight_, &b_JetPUPPITight_);
   fChain->SetBranchAddress("JetPUPPITight.fUniqueID", JetPUPPITight_fUniqueID, &b_JetPUPPITight_fUniqueID);
   fChain->SetBranchAddress("JetPUPPITight.fBits", JetPUPPITight_fBits, &b_JetPUPPITight_fBits);
   fChain->SetBranchAddress("JetPUPPITight.PT", JetPUPPITight_PT, &b_JetPUPPITight_PT);
   fChain->SetBranchAddress("JetPUPPITight.Eta", JetPUPPITight_Eta, &b_JetPUPPITight_Eta);
   fChain->SetBranchAddress("JetPUPPITight.Phi", JetPUPPITight_Phi, &b_JetPUPPITight_Phi);
   fChain->SetBranchAddress("JetPUPPITight.T", JetPUPPITight_T, &b_JetPUPPITight_T);
   fChain->SetBranchAddress("JetPUPPITight.Mass", JetPUPPITight_Mass, &b_JetPUPPITight_Mass);
   fChain->SetBranchAddress("JetPUPPITight.DeltaEta", JetPUPPITight_DeltaEta, &b_JetPUPPITight_DeltaEta);
   fChain->SetBranchAddress("JetPUPPITight.DeltaPhi", JetPUPPITight_DeltaPhi, &b_JetPUPPITight_DeltaPhi);
   fChain->SetBranchAddress("JetPUPPITight.Flavor", JetPUPPITight_Flavor, &b_JetPUPPITight_Flavor);
   fChain->SetBranchAddress("JetPUPPITight.FlavorAlgo", JetPUPPITight_FlavorAlgo, &b_JetPUPPITight_FlavorAlgo);
   fChain->SetBranchAddress("JetPUPPITight.FlavorPhys", JetPUPPITight_FlavorPhys, &b_JetPUPPITight_FlavorPhys);
   fChain->SetBranchAddress("JetPUPPITight.BTag", JetPUPPITight_BTag, &b_JetPUPPITight_BTag);
   fChain->SetBranchAddress("JetPUPPITight.BTagAlgo", JetPUPPITight_BTagAlgo, &b_JetPUPPITight_BTagAlgo);
   fChain->SetBranchAddress("JetPUPPITight.BTagPhys", JetPUPPITight_BTagPhys, &b_JetPUPPITight_BTagPhys);
   fChain->SetBranchAddress("JetPUPPITight.TauTag", JetPUPPITight_TauTag, &b_JetPUPPITight_TauTag);
   fChain->SetBranchAddress("JetPUPPITight.TauWeight", JetPUPPITight_TauWeight, &b_JetPUPPITight_TauWeight);
   fChain->SetBranchAddress("JetPUPPITight.Charge", JetPUPPITight_Charge, &b_JetPUPPITight_Charge);
   fChain->SetBranchAddress("JetPUPPITight.EhadOverEem", JetPUPPITight_EhadOverEem, &b_JetPUPPITight_EhadOverEem);
   fChain->SetBranchAddress("JetPUPPITight.NCharged", JetPUPPITight_NCharged, &b_JetPUPPITight_NCharged);
   fChain->SetBranchAddress("JetPUPPITight.NNeutrals", JetPUPPITight_NNeutrals, &b_JetPUPPITight_NNeutrals);
   fChain->SetBranchAddress("JetPUPPITight.NeutralEnergyFraction", JetPUPPITight_NeutralEnergyFraction, &b_JetPUPPITight_NeutralEnergyFraction);
   fChain->SetBranchAddress("JetPUPPITight.ChargedEnergyFraction", JetPUPPITight_ChargedEnergyFraction, &b_JetPUPPITight_ChargedEnergyFraction);
   fChain->SetBranchAddress("JetPUPPITight.Beta", JetPUPPITight_Beta, &b_JetPUPPITight_Beta);
   fChain->SetBranchAddress("JetPUPPITight.BetaStar", JetPUPPITight_BetaStar, &b_JetPUPPITight_BetaStar);
   fChain->SetBranchAddress("JetPUPPITight.MeanSqDeltaR", JetPUPPITight_MeanSqDeltaR, &b_JetPUPPITight_MeanSqDeltaR);
   fChain->SetBranchAddress("JetPUPPITight.PTD", JetPUPPITight_PTD, &b_JetPUPPITight_PTD);
   fChain->SetBranchAddress("JetPUPPITight.FracPt[5]", JetPUPPITight_FracPt, &b_JetPUPPITight_FracPt);
   fChain->SetBranchAddress("JetPUPPITight.Tau[5]", JetPUPPITight_Tau, &b_JetPUPPITight_Tau);
   fChain->SetBranchAddress("JetPUPPITight.SoftDroppedJet", JetPUPPITight_SoftDroppedJet, &b_JetPUPPITight_SoftDroppedJet);
   fChain->SetBranchAddress("JetPUPPITight.SoftDroppedSubJet1", JetPUPPITight_SoftDroppedSubJet1, &b_JetPUPPITight_SoftDroppedSubJet1);
   fChain->SetBranchAddress("JetPUPPITight.SoftDroppedSubJet2", JetPUPPITight_SoftDroppedSubJet2, &b_JetPUPPITight_SoftDroppedSubJet2);
   fChain->SetBranchAddress("JetPUPPITight.TrimmedP4[5]", JetPUPPITight_TrimmedP4, &b_JetPUPPITight_TrimmedP4);
   fChain->SetBranchAddress("JetPUPPITight.PrunedP4[5]", JetPUPPITight_PrunedP4, &b_JetPUPPITight_PrunedP4);
   fChain->SetBranchAddress("JetPUPPITight.SoftDroppedP4[5]", JetPUPPITight_SoftDroppedP4, &b_JetPUPPITight_SoftDroppedP4);
   fChain->SetBranchAddress("JetPUPPITight.NSubJetsTrimmed", JetPUPPITight_NSubJetsTrimmed, &b_JetPUPPITight_NSubJetsTrimmed);
   fChain->SetBranchAddress("JetPUPPITight.NSubJetsPruned", JetPUPPITight_NSubJetsPruned, &b_JetPUPPITight_NSubJetsPruned);
   fChain->SetBranchAddress("JetPUPPITight.NSubJetsSoftDropped", JetPUPPITight_NSubJetsSoftDropped, &b_JetPUPPITight_NSubJetsSoftDropped);
   fChain->SetBranchAddress("JetPUPPITight.ExclYmerge23", JetPUPPITight_ExclYmerge23, &b_JetPUPPITight_ExclYmerge23);
   fChain->SetBranchAddress("JetPUPPITight.ExclYmerge34", JetPUPPITight_ExclYmerge34, &b_JetPUPPITight_ExclYmerge34);
   fChain->SetBranchAddress("JetPUPPITight.ExclYmerge45", JetPUPPITight_ExclYmerge45, &b_JetPUPPITight_ExclYmerge45);
   fChain->SetBranchAddress("JetPUPPITight.ExclYmerge56", JetPUPPITight_ExclYmerge56, &b_JetPUPPITight_ExclYmerge56);
   fChain->SetBranchAddress("JetPUPPITight.Constituents", JetPUPPITight_Constituents, &b_JetPUPPITight_Constituents);
   fChain->SetBranchAddress("JetPUPPITight.Particles", JetPUPPITight_Particles, &b_JetPUPPITight_Particles);
   fChain->SetBranchAddress("JetPUPPITight.Area", JetPUPPITight_Area, &b_JetPUPPITight_Area);
   fChain->SetBranchAddress("JetPUPPITight_size", &JetPUPPITight_size, &b_JetPUPPITight_size);
   fChain->SetBranchAddress("Rho", &Rho_, &b_Rho_);
   fChain->SetBranchAddress("Rho.fUniqueID", Rho_fUniqueID, &b_Rho_fUniqueID);
   fChain->SetBranchAddress("Rho.fBits", Rho_fBits, &b_Rho_fBits);
   fChain->SetBranchAddress("Rho.Rho", Rho_Rho, &b_Rho_Rho);
   fChain->SetBranchAddress("Rho.Edges[2]", Rho_Edges, &b_Rho_Edges);
   fChain->SetBranchAddress("Rho_size", &Rho_size, &b_Rho_size);
   fChain->SetBranchAddress("PuppiMissingET", &PuppiMissingET_, &b_PuppiMissingET_);
   fChain->SetBranchAddress("PuppiMissingET.fUniqueID", PuppiMissingET_fUniqueID, &b_PuppiMissingET_fUniqueID);
   fChain->SetBranchAddress("PuppiMissingET.fBits", PuppiMissingET_fBits, &b_PuppiMissingET_fBits);
   fChain->SetBranchAddress("PuppiMissingET.MET", PuppiMissingET_MET, &b_PuppiMissingET_MET);
   fChain->SetBranchAddress("PuppiMissingET.Eta", PuppiMissingET_Eta, &b_PuppiMissingET_Eta);
   fChain->SetBranchAddress("PuppiMissingET.Phi", PuppiMissingET_Phi, &b_PuppiMissingET_Phi);
   fChain->SetBranchAddress("PuppiMissingET_size", &PuppiMissingET_size, &b_PuppiMissingET_size);
   fChain->SetBranchAddress("GenPileUpMissingET", &GenPileUpMissingET_, &b_GenPileUpMissingET_);
   fChain->SetBranchAddress("GenPileUpMissingET.fUniqueID", GenPileUpMissingET_fUniqueID, &b_GenPileUpMissingET_fUniqueID);
   fChain->SetBranchAddress("GenPileUpMissingET.fBits", GenPileUpMissingET_fBits, &b_GenPileUpMissingET_fBits);
   fChain->SetBranchAddress("GenPileUpMissingET.MET", GenPileUpMissingET_MET, &b_GenPileUpMissingET_MET);
   fChain->SetBranchAddress("GenPileUpMissingET.Eta", GenPileUpMissingET_Eta, &b_GenPileUpMissingET_Eta);
   fChain->SetBranchAddress("GenPileUpMissingET.Phi", GenPileUpMissingET_Phi, &b_GenPileUpMissingET_Phi);
   fChain->SetBranchAddress("GenPileUpMissingET_size", &GenPileUpMissingET_size, &b_GenPileUpMissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
}

#endif // #ifdef DELPHES2_cxx
