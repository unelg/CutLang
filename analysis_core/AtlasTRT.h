//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Oct 17 18:57:02 2021 by ROOT version 6.24/02
// from TTree hit_tree/hit_tree
// found on file: sample.root
//////////////////////////////////////////////////////////

#ifndef AtlasTRT_h
#define AtlasTRT_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "dbxParticle.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

class AtlasTRT {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         eventWeight;
   Int_t           eventNumber;
   Float_t         averageMu;
   UInt_t          runNumber;
   UInt_t          lumiBlock;
   UChar_t         nEvent;
   Float_t         trackPt;
   Float_t         trackEta;
   Float_t         trackPhi;
   Float_t         trackE;
   Float_t         trackM;
   UInt_t          isTightP;
   UInt_t          isLooseP;
   UInt_t          isLoose;
   UChar_t         nPixholes;
   UChar_t         nSCTholes;
   UChar_t         nIBLhits;
   UChar_t         nBLayhits;
   UChar_t         nexpIBLhits;
   UChar_t         nexpBLayhits;
   UChar_t         nPixhits;
   UChar_t         nSCThits;
   UChar_t         nTRTHits;
   UChar_t         nTRTTubeHits;
   UChar_t         nTRTOutliers;
   UChar_t         nOutliersOnTrack;
   UChar_t         nPixSharedHits;
   UChar_t         nSCTSharedHits;
   UChar_t         nSCTDeadSensors;
   UChar_t         nPixDeadSensors;
   Float_t         PHF;
   Float_t         TRTTrackOccupancy;
   Float_t         TRTLocalOccupancy;
   Float_t         TRTOccGlobal;
   Float_t         TRTOccBarrelA;
   Float_t         TRTOccBarrelC;
   Float_t         TRTOccEndcapAA;
   Float_t         TRTOccEndcapBA;
   Float_t         TRTOccEndcapAC;
   Float_t         TRTOccEndcapBC;
   Float_t         ToT_dEdx;
   Int_t           truthBarcode;
   Float_t         truthTrackPt;
   Float_t         truthTrackEta;
   Float_t         truthTrackPhi;
   Int_t           truthID;
   Int_t           truthParentID;
   Float_t         truthMatchProb;
   Float_t         restrackPt;
   Float_t         restrackEta;
   Float_t         restrackPhi;
   Float_t         pTresidual_reco;
   Float_t         pTresidual_res;
   UInt_t          indexTrack;
   Char_t          isHT;
   Char_t          HT;
   Int_t           bec;
   Int_t           strawlayer;
   Int_t           strawnumber;
   Int_t           lay;
   Float_t         driftTime;
   Float_t         trkdriftTime;
   Float_t         tot;
   Float_t         T0;
   Float_t         driftTimeToTCorrection;
   Float_t         driftTimeHTCorrection;
   Float_t         LE;
   Float_t         globalX;
   Float_t         globalY;
   Float_t         globalZ;
   Int_t           gasType;
   Int_t           type;
   Float_t         dclocX;
   Float_t         dclocXError;
   Float_t         msoslocX;
   Float_t         unbiasedTrkError;
   Float_t         biasedTrkError;
   Float_t         errDC;
   Float_t         unbiasedResidualX;
   Float_t         unbiasedPullX;
   Float_t         biasedResidualX;
   Float_t         biasedPullX;
   Float_t         hitR;
   Float_t         hitRError;

   // List of branches
   TBranch        *b_eventWeight;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_averageMu;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_nEvent;   //!
   TBranch        *b_trackPt;   //!
   TBranch        *b_trackEta;   //!
   TBranch        *b_trackPhi;   //!
   TBranch        *b_trackE;   //!
   TBranch        *b_trackM;   //!
   TBranch        *b_isTightP;   //!
   TBranch        *b_isLooseP;   //!
   TBranch        *b_isLoose;   //!
   TBranch        *b_nPixholes;   //!
   TBranch        *b_nSCTholes;   //!
   TBranch        *b_nIBLhits;   //!
   TBranch        *b_nBLayhits;   //!
   TBranch        *b_nexpIBLhits;   //!
   TBranch        *b_nexpBLayhits;   //!
   TBranch        *b_nPixhits;   //!
   TBranch        *b_nSCThits;   //!
   TBranch        *b_nTRTHits;   //!
   TBranch        *b_nTRTTubeHits;   //!
   TBranch        *b_nTRTOutliers;   //!
   TBranch        *b_nOutliersOnTrack;   //!
   TBranch        *b_nPixSharedHits;   //!
   TBranch        *b_nSCTSharedHits;   //!
   TBranch        *b_nSCTDeadSensors;   //!
   TBranch        *b_nPixDeadSensors;   //!
   TBranch        *b_PHF;   //!
   TBranch        *b_TRTTrackOccupancy;   //!
   TBranch        *b_TRTLocalOccupancy;   //!
   TBranch        *b_TRTOccGlobal;   //!
   TBranch        *b_TRTOccBarrelA;   //!
   TBranch        *b_TRTOccBarrelC;   //!
   TBranch        *b_TRTOccEndcapAA;   //!
   TBranch        *b_TRTOccEndcapBA;   //!
   TBranch        *b_TRTOccEndcapAC;   //!
   TBranch        *b_TRTOccEndcapBC;   //!
   TBranch        *b_ToT_dEdx;   //!
   TBranch        *b_truthBarcode;   //!
   TBranch        *b_truthTrackPt;   //!
   TBranch        *b_truthTrackEta;   //!
   TBranch        *b_truthTrackPhi;   //!
   TBranch        *b_truthID;   //!
   TBranch        *b_truthParentID;   //!
   TBranch        *b_truthMatchProb;   //!
   TBranch        *b_restrackPt;   //!
   TBranch        *b_restrackEta;   //!
   TBranch        *b_restrackPhi;   //!
   TBranch        *b_pTresidual_reco;   //!
   TBranch        *b_pTresidual_res;   //!
   TBranch        *b_indexTrack;   //!
   TBranch        *b_isHT;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_bec;   //!
   TBranch        *b_strawlayer;   //!
   TBranch        *b_strawnumber;   //!
   TBranch        *b_lay;   //!
   TBranch        *b_driftTime;   //!
   TBranch        *b_trkdriftTime;   //!
   TBranch        *b_tot;   //!
   TBranch        *b_T0;   //!
   TBranch        *b_driftTimeToTCorrection;   //!
   TBranch        *b_driftTimeHTCorrection;   //!
   TBranch        *b_LE;   //!
   TBranch        *b_globalX;   //!
   TBranch        *b_globalY;   //!
   TBranch        *b_globalZ;   //!
   TBranch        *b_gasType;   //!
   TBranch        *b_type;   //!
   TBranch        *b_dclocX;   //!
   TBranch        *b_dclocXError;   //!
   TBranch        *b_msoslocX;   //!
   TBranch        *b_unbiasedTrkError;   //!
   TBranch        *b_biasedTrkError;   //!
   TBranch        *b_errDC;   //!
   TBranch        *b_unbiasedResidualX;   //!
   TBranch        *b_unbiasedPullX;   //!
   TBranch        *b_biasedResidualX;   //!
   TBranch        *b_biasedPullX;   //!
   TBranch        *b_hitR;   //!
   TBranch        *b_hitRError;   //!

   AtlasTRT(char *file_name, TChain *tree=0);
   virtual ~AtlasTRT();
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(analy_struct aselect, char *sampletype);
};

#endif

#ifdef AtlasTRT_cxx
AtlasTRT::AtlasTRT(char *file_name, TChain *tree) : fChain(0)
{
  TChain* chain; 
  if (tree == 0) {
     chain = new TChain("hit_tree");
     chain->Add(file_name);
  }
  if (tree == 0) {
   Init(chain);
  } else {
   Init(tree);
  }
}

AtlasTRT::~AtlasTRT()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AtlasTRT::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AtlasTRT::LoadTree(Long64_t entry)
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

void AtlasTRT::Init(TTree *tree)
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

   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("averageMu", &averageMu, &b_averageMu);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("nEvent", &nEvent, &b_nEvent);
   fChain->SetBranchAddress("trackPt", &trackPt, &b_trackPt);
   fChain->SetBranchAddress("trackEta", &trackEta, &b_trackEta);
   fChain->SetBranchAddress("trackPhi", &trackPhi, &b_trackPhi);
   fChain->SetBranchAddress("trackE", &trackE, &b_trackE);
   fChain->SetBranchAddress("trackM", &trackM, &b_trackM);
   fChain->SetBranchAddress("isTightP", &isTightP, &b_isTightP);
   fChain->SetBranchAddress("isLooseP", &isLooseP, &b_isLooseP);
   fChain->SetBranchAddress("isLoose", &isLoose, &b_isLoose);
   fChain->SetBranchAddress("nPixholes", &nPixholes, &b_nPixholes);
   fChain->SetBranchAddress("nSCTholes", &nSCTholes, &b_nSCTholes);
   fChain->SetBranchAddress("nIBLhits", &nIBLhits, &b_nIBLhits);
   fChain->SetBranchAddress("nBLayhits", &nBLayhits, &b_nBLayhits);
   fChain->SetBranchAddress("nexpIBLhits", &nexpIBLhits, &b_nexpIBLhits);
   fChain->SetBranchAddress("nexpBLayhits", &nexpBLayhits, &b_nexpBLayhits);
   fChain->SetBranchAddress("nPixhits", &nPixhits, &b_nPixhits);
   fChain->SetBranchAddress("nSCThits", &nSCThits, &b_nSCThits);
   fChain->SetBranchAddress("nTRTHits", &nTRTHits, &b_nTRTHits);
   fChain->SetBranchAddress("nTRTTubeHits", &nTRTTubeHits, &b_nTRTTubeHits);
   fChain->SetBranchAddress("nTRTOutliers", &nTRTOutliers, &b_nTRTOutliers);
   fChain->SetBranchAddress("nOutliersOnTrack", &nOutliersOnTrack, &b_nOutliersOnTrack);
   fChain->SetBranchAddress("nPixSharedHits", &nPixSharedHits, &b_nPixSharedHits);
   fChain->SetBranchAddress("nSCTSharedHits", &nSCTSharedHits, &b_nSCTSharedHits);
   fChain->SetBranchAddress("nSCTDeadSensors", &nSCTDeadSensors, &b_nSCTDeadSensors);
   fChain->SetBranchAddress("nPixDeadSensors", &nPixDeadSensors, &b_nPixDeadSensors);
   fChain->SetBranchAddress("PHF", &PHF, &b_PHF);
   fChain->SetBranchAddress("TRTTrackOccupancy", &TRTTrackOccupancy, &b_TRTTrackOccupancy);
   fChain->SetBranchAddress("TRTLocalOccupancy", &TRTLocalOccupancy, &b_TRTLocalOccupancy);
   fChain->SetBranchAddress("TRTOccGlobal", &TRTOccGlobal, &b_TRTOccGlobal);
   fChain->SetBranchAddress("TRTOccBarrelA", &TRTOccBarrelA, &b_TRTOccBarrelA);
   fChain->SetBranchAddress("TRTOccBarrelC", &TRTOccBarrelC, &b_TRTOccBarrelC);
   fChain->SetBranchAddress("TRTOccEndcapAA", &TRTOccEndcapAA, &b_TRTOccEndcapAA);
   fChain->SetBranchAddress("TRTOccEndcapBA", &TRTOccEndcapBA, &b_TRTOccEndcapBA);
   fChain->SetBranchAddress("TRTOccEndcapAC", &TRTOccEndcapAC, &b_TRTOccEndcapAC);
   fChain->SetBranchAddress("TRTOccEndcapBC", &TRTOccEndcapBC, &b_TRTOccEndcapBC);
   fChain->SetBranchAddress("ToT_dEdx", &ToT_dEdx, &b_ToT_dEdx);
   fChain->SetBranchAddress("truthBarcode", &truthBarcode, &b_truthBarcode);
   fChain->SetBranchAddress("truthTrackPt", &truthTrackPt, &b_truthTrackPt);
   fChain->SetBranchAddress("truthTrackEta", &truthTrackEta, &b_truthTrackEta);
   fChain->SetBranchAddress("truthTrackPhi", &truthTrackPhi, &b_truthTrackPhi);
   fChain->SetBranchAddress("truthID", &truthID, &b_truthID);
   fChain->SetBranchAddress("truthParentID", &truthParentID, &b_truthParentID);
   fChain->SetBranchAddress("truthMatchProb", &truthMatchProb, &b_truthMatchProb);
   fChain->SetBranchAddress("restrackPt", &restrackPt, &b_restrackPt);
   fChain->SetBranchAddress("restrackEta", &restrackEta, &b_restrackEta);
   fChain->SetBranchAddress("restrackPhi", &restrackPhi, &b_restrackPhi);
   fChain->SetBranchAddress("pTresidual_reco", &pTresidual_reco, &b_pTresidual_reco);
   fChain->SetBranchAddress("pTresidual_res", &pTresidual_res, &b_pTresidual_res);
   fChain->SetBranchAddress("indexTrack", &indexTrack, &b_indexTrack);
   fChain->SetBranchAddress("isHT", &isHT, &b_isHT);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("bec", &bec, &b_bec);
   fChain->SetBranchAddress("strawlayer", &strawlayer, &b_strawlayer);
   fChain->SetBranchAddress("strawnumber", &strawnumber, &b_strawnumber);
   fChain->SetBranchAddress("lay", &lay, &b_lay);
   fChain->SetBranchAddress("driftTime", &driftTime, &b_driftTime);
   fChain->SetBranchAddress("trkdriftTime", &trkdriftTime, &b_trkdriftTime);
   fChain->SetBranchAddress("tot", &tot, &b_tot);
   fChain->SetBranchAddress("T0", &T0, &b_T0);
   fChain->SetBranchAddress("driftTimeToTCorrection", &driftTimeToTCorrection, &b_driftTimeToTCorrection);
   fChain->SetBranchAddress("driftTimeHTCorrection", &driftTimeHTCorrection, &b_driftTimeHTCorrection);
   fChain->SetBranchAddress("LE", &LE, &b_LE);
   fChain->SetBranchAddress("globalX", &globalX, &b_globalX);
   fChain->SetBranchAddress("globalY", &globalY, &b_globalY);
   fChain->SetBranchAddress("globalZ", &globalZ, &b_globalZ);
   fChain->SetBranchAddress("gasType", &gasType, &b_gasType);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("dclocX", &dclocX, &b_dclocX);
   fChain->SetBranchAddress("dclocXError", &dclocXError, &b_dclocXError);
   fChain->SetBranchAddress("msoslocX", &msoslocX, &b_msoslocX);
   fChain->SetBranchAddress("unbiasedTrkError", &unbiasedTrkError, &b_unbiasedTrkError);
   fChain->SetBranchAddress("biasedTrkError", &biasedTrkError, &b_biasedTrkError);
   fChain->SetBranchAddress("errDC", &errDC, &b_errDC);
   fChain->SetBranchAddress("unbiasedResidualX", &unbiasedResidualX, &b_unbiasedResidualX);
   fChain->SetBranchAddress("unbiasedPullX", &unbiasedPullX, &b_unbiasedPullX);
   fChain->SetBranchAddress("biasedResidualX", &biasedResidualX, &b_biasedResidualX);
   fChain->SetBranchAddress("biasedPullX", &biasedPullX, &b_biasedPullX);
   fChain->SetBranchAddress("hitR", &hitR, &b_hitR);
   fChain->SetBranchAddress("hitRError", &hitRError, &b_hitRError);
}

#endif // #ifdef AtlasTRT_cxx
