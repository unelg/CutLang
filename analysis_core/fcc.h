//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Aug 19 05:36:06 2017 by ROOT version 5.34/18
// from TTree events/Events tree
// found on file: pp_ttbar_100TeV.root
//////////////////////////////////////////////////////////

#ifndef fcc_h
#define fcc_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "dbxParticle.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxmcEventWeights = 1;
const Int_t kMaxmuons = 30;
const Int_t kMaxelectrons = 30;
const Int_t kMaxphotons = 97;
const Int_t kMaxgenJets = 73;
const Int_t kMaxgenJetsFlavor = 53;
const Int_t kMaxjets = 58;
const Int_t kMaxjetsFlavor = 58;
const Int_t kMaxbTags = 58;
const Int_t kMaxcTags = 58;
const Int_t kMaxtauTags = 58;
const Int_t kMaxjetParts = 53;
const Int_t kMaxmet = 100;

class fcc {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           mcEventWeights_;
   Float_t         mcEventWeights_value[kMaxmcEventWeights];   //[mcEventWeights_]
   Int_t           muons_;
   UInt_t          muons_core_bits[kMaxmuons];   //[muons_]
   Int_t           muons_core_charge[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_mass[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_px[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_py[kMaxmuons];   //[muons_]
   Float_t         muons_core_p4_pz[kMaxmuons];   //[muons_]
   Int_t           muons_core_pdgId[kMaxmuons];   //[muons_]
   UInt_t          muons_core_status[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_x[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_y[kMaxmuons];   //[muons_]
   Float_t         muons_core_vertex_z[kMaxmuons];   //[muons_]
   UInt_t          muons_tracks_begin[kMaxmuons];   //[muons_]
   UInt_t          muons_tracks_end[kMaxmuons];   //[muons_]
   UInt_t          muons_clusters_begin[kMaxmuons];   //[muons_]
   UInt_t          muons_clusters_end[kMaxmuons];   //[muons_]
   Int_t           electrons_;
   UInt_t          electrons_core_bits[kMaxelectrons];   //[electrons_]
   Int_t           electrons_core_charge[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_mass[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_px[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_py[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_p4_pz[kMaxelectrons];   //[electrons_]
   Int_t           electrons_core_pdgId[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_core_status[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_x[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_y[kMaxelectrons];   //[electrons_]
   Float_t         electrons_core_vertex_z[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_tracks_begin[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_tracks_end[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_clusters_begin[kMaxelectrons];   //[electrons_]
   UInt_t          electrons_clusters_end[kMaxelectrons];   //[electrons_]

   Int_t           photons_;
   UInt_t          photons_core_bits[kMaxphotons];   //[photons_]
   Int_t           photons_core_charge[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_mass[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_px[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_py[kMaxphotons];   //[photons_]
   Float_t         photons_core_p4_pz[kMaxphotons];   //[photons_]
   Int_t           photons_core_pdgId[kMaxphotons];   //[photons_]
   UInt_t          photons_core_status[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_x[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_y[kMaxphotons];   //[photons_]
   Float_t         photons_core_vertex_z[kMaxphotons];   //[photons_]
   UInt_t          photons_tracks_begin[kMaxphotons];   //[photons_]
   UInt_t          photons_tracks_end[kMaxphotons];   //[photons_]
   UInt_t          photons_clusters_begin[kMaxphotons];   //[photons_]
   UInt_t          photons_clusters_end[kMaxphotons];   //[photons_]

   Int_t           genJets_;
   Float_t         genJets_core_area[kMaxgenJets];   //[genJets_]
   UInt_t          genJets_core_bits[kMaxgenJets];   //[genJets_]
   Float_t         genJets_core_p4_mass[kMaxgenJets];   //[genJets_]
   Float_t         genJets_core_p4_px[kMaxgenJets];   //[genJets_]
   Float_t         genJets_core_p4_py[kMaxgenJets];   //[genJets_]
   Float_t         genJets_core_p4_pz[kMaxgenJets];   //[genJets_]
   UInt_t          genJets_particles_begin[kMaxgenJets];   //[genJets_]
   UInt_t          genJets_particles_end[kMaxgenJets];   //[genJets_]
   
   Int_t           jets_;
   Float_t         jets_core_area[kMaxjets];   //[jets_]
   UInt_t          jets_core_bits[kMaxjets];   //[jets_]
   Float_t         jets_core_p4_mass[kMaxjets];   //[jets_]
   Float_t         jets_core_p4_px[kMaxjets];   //[jets_]
   Float_t         jets_core_p4_py[kMaxjets];   //[jets_]
   Float_t         jets_core_p4_pz[kMaxjets];   //[jets_]
   UInt_t          jets_particles_begin[kMaxjets];   //[jets_]
   UInt_t          jets_particles_end[kMaxjets];   //[jets_]

   Int_t           jetsFlavor_;
   Float_t         jetsFlavor_tag[kMaxjetsFlavor];   //[jetsFlavor_]
   Int_t           bTags_;
   Float_t         bTags_tag[kMaxbTags];   //[bTags_]
   Int_t           cTags_;
   Float_t         cTags_tag[kMaxcTags];   //[cTags_]
   Int_t           tauTags_;
   Float_t         tauTags_tag[kMaxtauTags];   //[tauTags_]

   Int_t           jetParts_;
   UInt_t          jetParts_core_bits[kMaxjetParts];   //[jetParts_]
   Int_t           jetParts_core_charge[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_p4_mass[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_p4_px[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_p4_py[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_p4_pz[kMaxjetParts];   //[jetParts_]
   Int_t           jetParts_core_pdgId[kMaxjetParts];   //[jetParts_]
   UInt_t          jetParts_core_status[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_vertex_x[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_vertex_y[kMaxjetParts];   //[jetParts_]
   Float_t         jetParts_core_vertex_z[kMaxjetParts];   //[jetParts_]
   UInt_t          jetParts_tracks_begin[kMaxjetParts];   //[jetParts_]
   UInt_t          jetParts_tracks_end[kMaxjetParts];   //[jetParts_]
   UInt_t          jetParts_clusters_begin[kMaxjetParts];   //[jetParts_]
   UInt_t          jetParts_clusters_end[kMaxjetParts];   //[jetParts_]
   Int_t           met_;
   Float_t         met_magnitude[kMaxmet];   //[met_]
   Float_t         met_phi[kMaxmet];   //[met_]
   Float_t         met_scalarSum[kMaxmet];   //[met_]

   // List of branches
   TBranch        *b_mcEventWeights_;   //!
   TBranch        *b_mcEventWeights_value;   //!
   TBranch        *b_muons_;   //!
   TBranch        *b_muons_core_bits;   //!
   TBranch        *b_muons_core_charge;   //!
   TBranch        *b_muons_core_p4_mass;   //!
   TBranch        *b_muons_core_p4_px;   //!
   TBranch        *b_muons_core_p4_py;   //!
   TBranch        *b_muons_core_p4_pz;   //!
   TBranch        *b_muons_core_pdgId;   //!
   TBranch        *b_muons_core_status;   //!
   TBranch        *b_muons_core_vertex_x;   //!
   TBranch        *b_muons_core_vertex_y;   //!
   TBranch        *b_muons_core_vertex_z;   //!
   TBranch        *b_muons_tracks_begin;   //!
   TBranch        *b_muons_tracks_end;   //!
   TBranch        *b_muons_clusters_begin;   //!
   TBranch        *b_muons_clusters_end;   //!
   TBranch        *b_electrons_;   //!
   TBranch        *b_electrons_core_bits;   //!
   TBranch        *b_electrons_core_charge;   //!
   TBranch        *b_electrons_core_p4_mass;   //!
   TBranch        *b_electrons_core_p4_px;   //!
   TBranch        *b_electrons_core_p4_py;   //!
   TBranch        *b_electrons_core_p4_pz;   //!
   TBranch        *b_electrons_core_pdgId;   //!
   TBranch        *b_electrons_core_status;   //!
   TBranch        *b_electrons_core_vertex_x;   //!
   TBranch        *b_electrons_core_vertex_y;   //!
   TBranch        *b_electrons_core_vertex_z;   //!
   TBranch        *b_electrons_tracks_begin;   //!
   TBranch        *b_electrons_tracks_end;   //!
   TBranch        *b_electrons_clusters_begin;   //!
   TBranch        *b_electrons_clusters_end;   //!
   TBranch        *b_photons_;   //!
   TBranch        *b_photons_core_bits;   //!
   TBranch        *b_photons_core_charge;   //!
   TBranch        *b_photons_core_p4_mass;   //!
   TBranch        *b_photons_core_p4_px;   //!
   TBranch        *b_photons_core_p4_py;   //!
   TBranch        *b_photons_core_p4_pz;   //!
   TBranch        *b_photons_core_pdgId;   //!
   TBranch        *b_photons_core_status;   //!
   TBranch        *b_photons_core_vertex_x;   //!
   TBranch        *b_photons_core_vertex_y;   //!
   TBranch        *b_photons_core_vertex_z;   //!
   TBranch        *b_photons_tracks_begin;   //!
   TBranch        *b_photons_tracks_end;   //!
   TBranch        *b_photons_clusters_begin;   //!
   TBranch        *b_photons_clusters_end;   //!
   TBranch        *b_pfphotons_;   //!
   TBranch        *b_pfphotons_core_bits;   //!
   TBranch        *b_pfphotons_core_charge;   //!
   TBranch        *b_pfphotons_core_p4_mass;   //!
   TBranch        *b_pfphotons_core_p4_px;   //!
   TBranch        *b_pfphotons_core_p4_py;   //!
   TBranch        *b_pfphotons_core_p4_pz;   //!
   TBranch        *b_pfphotons_core_pdgId;   //!
   TBranch        *b_pfphotons_core_status;   //!
   TBranch        *b_pfphotons_core_vertex_x;   //!
   TBranch        *b_pfphotons_core_vertex_y;   //!
   TBranch        *b_pfphotons_core_vertex_z;   //!
   TBranch        *b_pfphotons_tracks_begin;   //!
   TBranch        *b_pfphotons_tracks_end;   //!
   TBranch        *b_pfphotons_clusters_begin;   //!
   TBranch        *b_pfphotons_clusters_end;   //!
   TBranch        *b_genJets_;   //!
   TBranch        *b_genJets_core_area;   //!
   TBranch        *b_genJets_core_bits;   //!
   TBranch        *b_genJets_core_p4_mass;   //!
   TBranch        *b_genJets_core_p4_px;   //!
   TBranch        *b_genJets_core_p4_py;   //!
   TBranch        *b_genJets_core_p4_pz;   //!
   TBranch        *b_genJets_particles_begin;   //!
   TBranch        *b_genJets_particles_end;   //!
   TBranch        *b_jets_;   //!
   TBranch        *b_jets_core_area;   //!
   TBranch        *b_jets_core_bits;   //!
   TBranch        *b_jets_core_p4_mass;   //!
   TBranch        *b_jets_core_p4_px;   //!
   TBranch        *b_jets_core_p4_py;   //!
   TBranch        *b_jets_core_p4_pz;   //!
   TBranch        *b_jets_particles_begin;   //!
   TBranch        *b_jets_particles_end;   //!
   TBranch        *b_jetsFlavor_;   //!
   TBranch        *b_bTags_;   //!
   TBranch        *b_bTags_tag;   //!
   TBranch        *b_cTags_;   //!
   TBranch        *b_cTags_tag;   //!
   TBranch        *b_tauTags_;   //!
   TBranch        *b_tauTags_tag;   //!
   TBranch        *b_jetParts_;   //!
   TBranch        *b_jetParts_core_bits;   //!
   TBranch        *b_jetParts_core_charge;   //!
   TBranch        *b_jetParts_core_p4_mass;   //!
   TBranch        *b_jetParts_core_p4_px;   //!
   TBranch        *b_jetParts_core_p4_py;   //!
   TBranch        *b_jetParts_core_p4_pz;   //!
   TBranch        *b_jetParts_core_pdgId;   //!
   TBranch        *b_jetParts_core_status;   //!
   TBranch        *b_jetParts_core_vertex_x;   //!
   TBranch        *b_jetParts_core_vertex_y;   //!
   TBranch        *b_jetParts_core_vertex_z;   //!
   TBranch        *b_jetParts_tracks_begin;   //!
   TBranch        *b_jetParts_tracks_end;   //!
   TBranch        *b_jetParts_clusters_begin;   //!
   TBranch        *b_jetParts_clusters_end;   //!
   TBranch        *b_met_;   //!
   TBranch        *b_met_magnitude;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_scalarSum;   //!

   fcc(char *file_name, TChain *tree=0);
   virtual ~fcc();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef fcc_cxx
fcc::fcc(char *file_name, TChain *tree) : fChain(0)
{
  TChain* chain;
  if (tree == 0) {
     chain = new TChain("events");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }
}

fcc::~fcc()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t fcc::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t fcc::LoadTree(Long64_t entry)
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

void fcc::Init(TChain *tree)
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
//   fChain->SetMakeClass(1);

/*
   fChain->SetBranchAddress("mcEventWeights", &mcEventWeights_, &b_mcEventWeights_);
   fChain->SetBranchAddress("mcEventWeights.value", mcEventWeights_value, &b_mcEventWeights_value);
   fChain->SetBranchAddress("muons", &muons_, &b_muons_);
   fChain->SetBranchAddress("muons.core.bits", muons_core_bits, &b_muons_core_bits);
   fChain->SetBranchAddress("muons.core.charge", muons_core_charge, &b_muons_core_charge);
   fChain->SetBranchAddress("muons.core.p4.mass", muons_core_p4_mass, &b_muons_core_p4_mass);
   fChain->SetBranchAddress("muons.core.p4.px", muons_core_p4_px, &b_muons_core_p4_px);
   fChain->SetBranchAddress("muons.core.p4.py", muons_core_p4_py, &b_muons_core_p4_py);
   fChain->SetBranchAddress("muons.core.p4.pz", muons_core_p4_pz, &b_muons_core_p4_pz);
   fChain->SetBranchAddress("muons.core.pdgId", muons_core_pdgId, &b_muons_core_pdgId);
   fChain->SetBranchAddress("muons.core.status", muons_core_status, &b_muons_core_status);
   fChain->SetBranchAddress("muons.core.vertex.x", muons_core_vertex_x, &b_muons_core_vertex_x);
   fChain->SetBranchAddress("muons.core.vertex.y", muons_core_vertex_y, &b_muons_core_vertex_y);
   fChain->SetBranchAddress("muons.core.vertex.z", muons_core_vertex_z, &b_muons_core_vertex_z);
   fChain->SetBranchAddress("muons.tracks_begin", muons_tracks_begin, &b_muons_tracks_begin);
   fChain->SetBranchAddress("muons.tracks_end", muons_tracks_end, &b_muons_tracks_end);
   fChain->SetBranchAddress("muons.clusters_begin", muons_clusters_begin, &b_muons_clusters_begin);
   fChain->SetBranchAddress("muons.clusters_end", muons_clusters_end, &b_muons_clusters_end);
   fChain->SetBranchAddress("electrons", &electrons_, &b_electrons_);
   fChain->SetBranchAddress("electrons.core.bits", electrons_core_bits, &b_electrons_core_bits);
   fChain->SetBranchAddress("electrons.core.charge", electrons_core_charge, &b_electrons_core_charge);
   fChain->SetBranchAddress("electrons.core.p4.mass", electrons_core_p4_mass, &b_electrons_core_p4_mass);
   fChain->SetBranchAddress("electrons.core.p4.px", electrons_core_p4_px, &b_electrons_core_p4_px);
   fChain->SetBranchAddress("electrons.core.p4.py", electrons_core_p4_py, &b_electrons_core_p4_py);
   fChain->SetBranchAddress("electrons.core.p4.pz", electrons_core_p4_pz, &b_electrons_core_p4_pz);
   fChain->SetBranchAddress("electrons.core.pdgId", electrons_core_pdgId, &b_electrons_core_pdgId);
   fChain->SetBranchAddress("electrons.core.status", electrons_core_status, &b_electrons_core_status);
   fChain->SetBranchAddress("electrons.core.vertex.x", electrons_core_vertex_x, &b_electrons_core_vertex_x);
   fChain->SetBranchAddress("electrons.core.vertex.y", electrons_core_vertex_y, &b_electrons_core_vertex_y);
   fChain->SetBranchAddress("electrons.core.vertex.z", electrons_core_vertex_z, &b_electrons_core_vertex_z);
   fChain->SetBranchAddress("electrons.tracks_begin", electrons_tracks_begin, &b_electrons_tracks_begin);
   fChain->SetBranchAddress("electrons.tracks_end", electrons_tracks_end, &b_electrons_tracks_end);
   fChain->SetBranchAddress("electrons.clusters_begin", electrons_clusters_begin, &b_electrons_clusters_begin);
   fChain->SetBranchAddress("electrons.clusters_end", electrons_clusters_end, &b_electrons_clusters_end);
   fChain->SetBranchAddress("photons", &photons_, &b_photons_);
   fChain->SetBranchAddress("photons.core.bits", photons_core_bits, &b_photons_core_bits);
   fChain->SetBranchAddress("photons.core.charge", photons_core_charge, &b_photons_core_charge);
   fChain->SetBranchAddress("photons.core.p4.mass", photons_core_p4_mass, &b_photons_core_p4_mass);
   fChain->SetBranchAddress("photons.core.p4.px", photons_core_p4_px, &b_photons_core_p4_px);
   fChain->SetBranchAddress("photons.core.p4.py", photons_core_p4_py, &b_photons_core_p4_py);
   fChain->SetBranchAddress("photons.core.p4.pz", photons_core_p4_pz, &b_photons_core_p4_pz);
   fChain->SetBranchAddress("photons.core.pdgId", photons_core_pdgId, &b_photons_core_pdgId);
   fChain->SetBranchAddress("photons.core.status", photons_core_status, &b_photons_core_status);
   fChain->SetBranchAddress("photons.core.vertex.x", photons_core_vertex_x, &b_photons_core_vertex_x);
   fChain->SetBranchAddress("photons.core.vertex.y", photons_core_vertex_y, &b_photons_core_vertex_y);
   fChain->SetBranchAddress("photons.core.vertex.z", photons_core_vertex_z, &b_photons_core_vertex_z);
   fChain->SetBranchAddress("photons.tracks_begin", photons_tracks_begin, &b_photons_tracks_begin);
   fChain->SetBranchAddress("photons.tracks_end", photons_tracks_end, &b_photons_tracks_end);
   fChain->SetBranchAddress("photons.clusters_begin", photons_clusters_begin, &b_photons_clusters_begin);
   fChain->SetBranchAddress("photons.clusters_end", photons_clusters_end, &b_photons_clusters_end);
   fChain->SetBranchAddress("genJets", &genJets_, &b_genJets_);
   fChain->SetBranchAddress("genJets.core.area", genJets_core_area, &b_genJets_core_area);
   fChain->SetBranchAddress("genJets.core.bits", genJets_core_bits, &b_genJets_core_bits);
   fChain->SetBranchAddress("genJets.core.p4.mass", genJets_core_p4_mass, &b_genJets_core_p4_mass);
   fChain->SetBranchAddress("genJets.core.p4.px", genJets_core_p4_px, &b_genJets_core_p4_px);
   fChain->SetBranchAddress("genJets.core.p4.py", genJets_core_p4_py, &b_genJets_core_p4_py);
   fChain->SetBranchAddress("genJets.core.p4.pz", genJets_core_p4_pz, &b_genJets_core_p4_pz);
   fChain->SetBranchAddress("genJets.particles_begin", genJets_particles_begin, &b_genJets_particles_begin);
   fChain->SetBranchAddress("genJets.particles_end", genJets_particles_end, &b_genJets_particles_end);


   fChain->SetBranchAddress("jets", &jets_, &b_jets_);
   fChain->SetBranchAddress("jets.core.area", jets_core_area, &b_jets_core_area);
   fChain->SetBranchAddress("jets.core.bits", jets_core_bits, &b_jets_core_bits);
   fChain->SetBranchAddress("jets.core.p4.mass", jets_core_p4_mass, &b_jets_core_p4_mass);
   fChain->SetBranchAddress("jets.core.p4.px", jets_core_p4_px, &b_jets_core_p4_px);
   fChain->SetBranchAddress("jets.core.p4.py", jets_core_p4_py, &b_jets_core_p4_py);
   fChain->SetBranchAddress("jets.core.p4.pz", jets_core_p4_pz, &b_jets_core_p4_pz);
   fChain->SetBranchAddress("jets.particles_begin", jets_particles_begin, &b_jets_particles_begin);
   fChain->SetBranchAddress("jets.particles_end", jets_particles_end, &b_jets_particles_end);
   fChain->SetBranchAddress("jetsFlavor", &jetsFlavor_, &b_jetsFlavor_);
   fChain->SetBranchAddress("bTags", &bTags_, &b_bTags_);
   fChain->SetBranchAddress("bTags.tag", bTags_tag, &b_bTags_tag);
   fChain->SetBranchAddress("cTags", &cTags_, &b_cTags_);
   fChain->SetBranchAddress("cTags.tag", cTags_tag, &b_cTags_tag);
   fChain->SetBranchAddress("tauTags", &tauTags_, &b_tauTags_);
   fChain->SetBranchAddress("tauTags.tag", tauTags_tag, &b_tauTags_tag);
   fChain->SetBranchAddress("jetParts", &jetParts_, &b_jetParts_);
   fChain->SetBranchAddress("jetParts.core.bits", jetParts_core_bits, &b_jetParts_core_bits);
   fChain->SetBranchAddress("jetParts.core.charge", jetParts_core_charge, &b_jetParts_core_charge);
   fChain->SetBranchAddress("jetParts.core.p4.mass", jetParts_core_p4_mass, &b_jetParts_core_p4_mass);
   fChain->SetBranchAddress("jetParts.core.p4.px", jetParts_core_p4_px, &b_jetParts_core_p4_px);
   fChain->SetBranchAddress("jetParts.core.p4.py", jetParts_core_p4_py, &b_jetParts_core_p4_py);
   fChain->SetBranchAddress("jetParts.core.p4.pz", jetParts_core_p4_pz, &b_jetParts_core_p4_pz);
   fChain->SetBranchAddress("jetParts.core.pdgId", jetParts_core_pdgId, &b_jetParts_core_pdgId);
   fChain->SetBranchAddress("jetParts.core.status", jetParts_core_status, &b_jetParts_core_status);
   fChain->SetBranchAddress("jetParts.core.vertex.x", jetParts_core_vertex_x, &b_jetParts_core_vertex_x);
   fChain->SetBranchAddress("jetParts.core.vertex.y", jetParts_core_vertex_y, &b_jetParts_core_vertex_y);
   fChain->SetBranchAddress("jetParts.core.vertex.z", jetParts_core_vertex_z, &b_jetParts_core_vertex_z);
   fChain->SetBranchAddress("jetParts.tracks_begin", jetParts_tracks_begin, &b_jetParts_tracks_begin);
   fChain->SetBranchAddress("jetParts.tracks_end", jetParts_tracks_end, &b_jetParts_tracks_end);
   fChain->SetBranchAddress("jetParts.clusters_begin", jetParts_clusters_begin, &b_jetParts_clusters_begin);
   fChain->SetBranchAddress("jetParts.clusters_end", jetParts_clusters_end, &b_jetParts_clusters_end);

   fChain->SetBranchAddress("met", &met_, &b_met_);
   fChain->SetBranchAddress("met.magnitude", met_magnitude, &b_met_magnitude);
   fChain->SetBranchAddress("met.phi", met_phi, &b_met_phi);
   fChain->SetBranchAddress("met.scalarSum", met_scalarSum, &b_met_scalarSum);
*/
   Notify();
}

Bool_t fcc::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void fcc::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t fcc::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef fcc_cxx
