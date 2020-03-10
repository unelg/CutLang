//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb  3 22:43:15 2020 by ROOT version 6.18/04
// from TTree Delphes/Analysis tree
// found on file: /Users/ngu/Downloads/cmsfull.root
//////////////////////////////////////////////////////////

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTreeReaderArray.h>
#include <TTreeReader.h>


// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include <TVector3.h>
#include <TLorentzVector.h>
#include <TRefArray.h>
#include <TRef.h>

#ifndef __delphes_h__
#define __delphes_h__
class GenParticle: public TObject {
public:
  Int_t PID; // particle HEP ID number | hepevt.idhep[number]
  Int_t Status; // particle status | hepevt.isthep[number]
  Int_t IsPU; // 0 or 1 for particles from pile-up interactions
  Int_t M1; // particle 1st mother | hepevt.jmohep[number][0] - 1
  Int_t M2; // particle 2nd mother | hepevt.jmohep[number][1] - 1
  Int_t D1; // particle 1st daughter | hepevt.jdahep[number][0] - 1
  Int_t D2; // particle last daughter | hepevt.jdahep[number][1] - 1
  Int_t Charge; // particle charge
  Float_t Mass; // particle mass
  Float_t E; // particle energy | hepevt.phep[number][3]
  Float_t Px; // particle momentum vector (x component) | hepevt.phep[number][0]
  Float_t Py; // particle momentum vector (y component) | hepevt.phep[number][1]
  Float_t Pz; // particle momentum vector (z component) | hepevt.phep[number][2]
  Float_t P; // particle momentum
  Float_t PT; // particle transverse momentum
  Float_t Eta; // particle pseudorapidity
  Float_t Phi; // particle azimuthal angle
  Float_t Rapidity; // particle rapidity
  Float_t CtgTheta; // particle cotangent of theta
  Float_t D0; // particle transverse impact parameter
  Float_t DZ; // particle longitudinal impact parameter
  Float_t T; // particle vertex position (t component) | hepevt.vhep[number][3]
  Float_t X; // particle vertex position (x component) | hepevt.vhep[number][0]
  Float_t Y; // particle vertex position (y component) | hepevt.vhep[number][1]
  Float_t Z; // particle vertex position (z component) | hepevt.vhep[number][2]
  ClassDef(GenParticle, 3)
};

class Jet: public TObject {
public:
  Float_t PT; // jet transverse momentum
  Float_t Eta; // jet pseudorapidity
  Float_t Phi; // jet azimuthal angle
  Float_t T; //particle arrival time of flight
  Float_t Mass; // jet invariant mass
  Float_t DeltaEta; // jet radius in pseudorapidity
  Float_t DeltaPhi; // jet radius in azimuthal angle
  UInt_t Flavor; // jet flavor
  UInt_t FlavorAlgo; // jet flavor
  UInt_t FlavorPhys; // jet flavor
  UInt_t BTag; // 0 or 1 for a jet that has been tagged as containing a heavy quark
  UInt_t BTagAlgo; // 0 or 1 for a jet that has been tagged as containing a heavy quark
  UInt_t BTagPhys; // 0 or 1 for a jet that has been tagged as containing a heavy quark
  UInt_t TauTag; // 0 or 1 for a jet that has been tagged as a tau
  Float_t TauWeight; // probability for jet to be identified as tau
  Int_t Charge; // tau charge
  Float_t EhadOverEem; // ratio of the hadronic versus electromagnetic energy deposited in the calorimeter
  Int_t NCharged; // number of charged constituents
  Int_t NNeutrals; // number of neutral constituents
  Float_t NeutralEnergyFraction;  // charged energy fraction
  Float_t ChargedEnergyFraction;  // neutral energy fraction 
  Float_t Beta; // (sum pt of charged pile-up constituents)/(sum pt of charged constituents)
  Float_t BetaStar; // (sum pt of charged constituents coming from hard interaction)/(sum pt of charged constituents)
  Float_t MeanSqDeltaR; // average distance (squared) between constituent and jet weighted by pt (squared) of constituent
  Float_t PTD; // average pt between constituent and jet weighted by pt of constituent
  Float_t FracPt[5]; // (sum pt of constituents within a ring 0.1*i < DeltaR < 0.1*(i+1))/(sum pt of constituents)
  Float_t Tau[5]; // N-subjettiness
  TLorentzVector SoftDroppedJet;
  TLorentzVector SoftDroppedSubJet1;
  TLorentzVector SoftDroppedSubJet2;
  TLorentzVector TrimmedP4[5]; // first entry (i=0) is the total Trimmed Jet 4-momenta and from i=1 to 4 are the trimmed subjets 4-momenta
  TLorentzVector PrunedP4[5]; // first entry (i=0) is the total Pruned Jet 4-momenta and from i=1 to 4 are the pruned subjets 4- momenta
  TLorentzVector SoftDroppedP4[5]; // first entry (i=0) is the total SoftDropped Jet 4-momenta and from i=1 to 4 are the pruned subjets 4-momenta
  Int_t NSubJetsTrimmed; // number of subjets trimmed
  Int_t NSubJetsPruned; // number of subjets pruned
  Int_t NSubJetsSoftDropped; // number of subjets soft-dropped
  Double_t ExclYmerge23;
  Double_t ExclYmerge34;
  Double_t ExclYmerge45;
  Double_t ExclYmerge56;
  TRefArray Constituents; // references to constituents
  TRefArray Particles; // references to generated particles
  TLorentzVector Area;
  ClassDef(Jet, 5)
};

class Vertex: public TObject {
public:
  Float_t T; // vertex position (t component)
  Float_t X; // vertex position (x component)
  Float_t Y; // vertex position (y component)
  Float_t Z; // vertex position (z component)
  Double_t ErrorT; // vertex position error (t component)
  Double_t ErrorX; // vertex position error (x component)
  Double_t ErrorY; // vertex position error (y component)
  Double_t ErrorZ; // vertex position error (z component)
  Int_t Index; // vertex index
  Int_t NDF; // number of degrees of freedom
  Double_t Sigma; // vertex position (z component) error
  Double_t SumPT2; // sum pt^2 of tracks attached to the vertex
  Double_t GenSumPT2; // sum pt^2 of gen tracks attached to the vertex
  Double_t GenDeltaZ; // distance in z to closest generated vertex
  Double_t BTVSumPT2; // sum pt^2 of tracks attached to the secondary vertex
  TRefArray Constituents; // references to constituents
  ClassDef(Vertex, 3)
};

class MissingET: public TObject {
public:
  Float_t MET; // mising transverse energy
  Float_t Eta; // mising energy pseudorapidity
  Float_t Phi; // mising energy azimuthal angle
  ClassDef(MissingET, 1)
};

class Photon: public TObject {
public:
  Float_t PT; // photon transverse momentum
  Float_t Eta; // photon pseudorapidity
  Float_t Phi; // photon azimuthal angle
  Float_t E; // photon energy
  Float_t T; // particle arrival time of flight
  Float_t EhadOverEem; // ratio of the hadronic versus electromagnetic energy deposited in the calorimeter
  TRefArray Particles; // references to generated particles
  Float_t IsolationVar; // isolation variable
  Float_t IsolationVarRhoCorr; // isolation variable
  Float_t SumPtCharged; // isolation variable
  Float_t SumPtNeutral; // isolation variable
  Float_t SumPtChargedPU; // isolation variable
  Float_t SumPt; // isolation variable
  Int_t Status; // 1: prompt -- 2: non prompt -- 3: fake
  ClassDef(Photon, 5)
};

class Electron: public TObject {
public:
  Float_t PT; // electron transverse momentum
  Float_t Eta; // electron pseudorapidity
  Float_t Phi; // electron azimuthal angle
  Float_t T; // particle arrival time of flight
  Int_t Charge; // electron charge
  Float_t EhadOverEem; // ratio of the hadronic versus electromagnetic energy deposited in the calorimeter
  TRef Particle; // reference to generated particle
  Float_t IsolationVar; // isolation variable
  Float_t IsolationVarRhoCorr; // isolation variable
  Float_t SumPtCharged; // isolation variable
  Float_t SumPtNeutral; // isolation variable
  Float_t SumPtChargedPU; // isolation variable
  Float_t SumPt; // isolation variable
  Float_t D0; // track transverse impact parameter
  Float_t DZ; // track longitudinal impact parameter
  Float_t ErrorD0; // track transverse impact parameter error
  Float_t ErrorDZ; // track longitudinal impact parameter error
  ClassDef(Electron, 5)
};

class Muon: public TObject {
public:
  Float_t PT; // muon transverse momentum
  Float_t Eta; // muon pseudorapidity
  Float_t Phi; // muon azimuthal angle
  Float_t T; // particle arrival time of flight
  Int_t Charge; // muon charge
  TRef Particle; // reference to generated particle
  Float_t IsolationVar; // isolation variable
  Float_t IsolationVarRhoCorr; // isolation variable
  Float_t SumPtCharged; // isolation variable
  Float_t SumPtNeutral; // isolation variable
  Float_t SumPtChargedPU; // isolation variable
  Float_t SumPt; // isolation variable
  Float_t D0; // track transverse impact parameter
  Float_t DZ; // track longitudinal impact parameter
  Float_t ErrorD0; // track transverse impact parameter error
  Float_t ErrorDZ; // track longitudinal impact parameter error
  ClassDef(Muon, 5)
};

class Track: public TObject {
public:
  Int_t PID; // HEP ID number
  Int_t Charge; // track charge
  Float_t P; // track momentum
  Float_t PT; // track transverse momentum
  Float_t Eta; // track pseudorapidity
  Float_t Phi; // track azimuthal angle
  Float_t CtgTheta; // track cotangent of theta
  Float_t EtaOuter; // track pseudorapidity at the tracker edge
  Float_t PhiOuter; // track azimuthal angle at the tracker edge
  Float_t T; // track vertex position (t component)
  Float_t X; // track vertex position (x component)
  Float_t Y; // track vertex position (y component)
  Float_t Z; // track vertex position (z component)
  Float_t TOuter; // track position (t component) at the tracker edge
  Float_t XOuter; // track position (x component) at the tracker edge
  Float_t YOuter; // track position (y component) at the tracker edge
  Float_t ZOuter; // track position (z component) at the tracker edge
  Float_t Xd; // X coordinate of point of closest approach to vertex
  Float_t Yd; // Y coordinate of point of closest approach to vertex
  Float_t Zd; // Z coordinate of point of closest approach to vertex
  Float_t L; // track path length
  Float_t D0; // track transverse impact parameter
  Float_t DZ; // track longitudinal impact parameter
  Float_t ErrorP; // track momentum error
  Float_t ErrorPT; // track transverse momentum error
  Float_t ErrorPhi; // track azimuthal angle error
  Float_t ErrorCtgTheta; // track cotangent of theta error
  Float_t ErrorT; // time measurement error
  Float_t ErrorD0; // track transverse impact parameter error
  Float_t ErrorDZ; // track longitudinal impact parameter error
  TRef Particle; // reference to generated particle
  Int_t VertexIndex; // reference to vertex
  ClassDef(Track, 5)
};

class ScalarHT: public TObject {
public:
  Float_t HT; // scalar sum of transverse momenta
  ClassDef(ScalarHT, 2)
};

class Weight: public TObject {
public:
  Float_t Weight; // weight for the event
  ClassDef(Weight, 2)
};




#endif
