#include "dbx_a.h"

#include <iostream>
#include "TRandom3.h"


dbxA:: ~dbxA() {}

dbxA:: dbxA(char *aname) {
  m_mw=80.4;
  m_mz=91.2;
  m_mh=125.5;
  GEV = 1000.;
  p_runno=-1;
  p_lumino=-1;
  HFtype=-1;
  sprintf (cname, "%s",aname); // more checks here

  cout << "This is "<<cname<<endl;

  char tmp[128];
  sprintf (tmp, "histoOut-%s.root",cname);

  if (strcmp(aname,"same")==0) {
   histoOut= new TFile (tmp,"update");
  } else {
   histoOut= new TFile (tmp,"recreate");
  }
  setDataCardPrefix(cname);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: addRunLumiInfo(int rn, int lbn) {  // to keep track of the lumi
 if ((p_runno!=rn) || (p_lumino!= lbn)) {
  p_runno=rn;
  p_lumino=lbn;
  rntuple->Fill(p_runno, p_lumino);
 }
 return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: makeAnalysis(AnalysisObjects ao, int idx) {
  int retval=0;
/*
//  cout << "e:"<<electrons.size() << " m:"<<muons.size()<<   " p:"<<photons.size()  <<" j:"<<jets.size()<<endl;
   
    double evt_weight = anevt.mcevt_weight; //BG
    
//    cout << "filling muons"<<endl;
// -------------MUONS------
  for (Int_t i=0; i<(Int_t)muons.size(); i++) {
         hmpt[idx]->Fill( fabs(muons.at(i).lv().Pt()), evt_weight );
     hmpt_err[idx]->Fill( fabs(muons.at(i).lv().Pt()), evt_weight*evt_weight );
        hmeta[idx]->Fill( muons.at(i).lv().Eta(), evt_weight );
    hmeta_err[idx]->Fill( muons.at(i).lv().Eta(), evt_weight*evt_weight );
        hmphi[idx]->Fill( muons.at(i).lv().Phi(), evt_weight );
    hmphi_err[idx]->Fill( muons.at(i).lv().Phi(), evt_weight*evt_weight );
        hlepq[idx]->Fill( muons.at(i).q(), evt_weight );
  }

// cout << "filling electrons"<<endl;
// ------------ELECTRONS------
    for (Int_t i=0; i<(Int_t)electrons.size(); i++) {
         hept[idx]->Fill( fabs(electrons.at(i).lv().Pt() ), evt_weight );
     hept_err[idx]->Fill( fabs(electrons.at(i).lv().Pt() ), evt_weight*evt_weight );
        heeta[idx]->Fill( electrons.at(i).lv().Eta(), evt_weight );
    heeta_err[idx]->Fill( electrons.at(i).lv().Eta(), evt_weight*evt_weight );
        hephi[idx]->Fill( electrons.at(i).lv().Phi(), evt_weight);
    hephi_err[idx]->Fill( electrons.at(i).lv().Phi(), evt_weight*evt_weight );
        hlepq[idx]->Fill( electrons.at(i).q(),evt_weight);
   }

// cout << "filling photons"<<endl;
// ------------PHOTONS------
    for (Int_t i=0; i<(Int_t)photons.size(); i++) {
         hgpt[idx]->Fill( fabs(photons.at(i).lv().Pt() ), evt_weight );
     hgpt_err[idx]->Fill( fabs(photons.at(i).lv().Pt() ), evt_weight*evt_weight );
        hgeta[idx]->Fill( photons.at(i).lv().Eta(), evt_weight );
    hgeta_err[idx]->Fill( photons.at(i).lv().Eta(), evt_weight*evt_weight );
        hgphi[idx]->Fill( photons.at(i).lv().Phi(), evt_weight );
    hgphi_err[idx]->Fill( photons.at(i).lv().Phi(), evt_weight*evt_weight );
   }


//  cout << "filling jets"<<endl;
// ------------JETS------
    for (Int_t i=0; i<(Int_t)jets.size(); i++) {
         hjpt[idx]->Fill( fabs(jets.at(i).lv().Pt()  ), evt_weight);
     hjpt_err[idx]->Fill( fabs(jets.at(i).lv().Pt()  ), evt_weight*evt_weight);
        hjeta[idx]->Fill( jets.at(i).lv().Eta() , evt_weight);
    hjeta_err[idx]->Fill( jets.at(i).lv().Eta() , evt_weight*evt_weight);
        hjphi[idx]->Fill( jets.at(i).lv().Phi() , evt_weight);
    hjphi_err[idx]->Fill( jets.at(i).lv().Phi() , evt_weight*evt_weight);
        hjetm[idx]->Fill( jets.at(i).lv().M() , evt_weight);
    hjetm_err[idx]->Fill( jets.at(i).lv().M() , evt_weight*evt_weight);
   }

//  cout << "filling met"<<endl;
// ------------MET------
        hmet[idx]->Fill( met.Mod() , evt_weight);
    hmet_err[idx]->Fill( met.Mod() , evt_weight*evt_weight);
     hmetphi[idx]->Fill( met.Phi_mpi_pi(met.Phi()) , evt_weight);
 hmetphi_err[idx]->Fill( met.Phi_mpi_pi(met.Phi()) , evt_weight*evt_weight);

//  cout << "done.\n"<<endl;
*/
  return retval;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: plotVariables(int uselect ) {
// CANVAS definitions
    int retval=0;
    const Double_t small=1e-4;
    char tmp[128], idxn[128];
    sprintf(tmp,"c1-%s",cname);
    sprintf(idxn,"pt-%s",cname);
    TCanvas *c1 = new TCanvas(idxn, tmp, 150, 10, 850, 500);
    c1->SetFillColor(0); c1->SetBorderMode(0); c1->Divide(1,3,small,small);
    c1->Draw();

    sprintf(tmp,"c2-%s",cname);
    sprintf(idxn,"aux-%s",cname);
    TCanvas *c2 = new TCanvas(idxn, tmp, 10, 10, 450, 500);
    c2->SetFillStyle(0); c2->SetFrameFillStyle(0);
    c2->SetBorderMode(0); //c2->Divide(2,2,small,small);
    c2->Draw();

    sprintf(tmp,"c3-%s",cname);
    sprintf(idxn,"angle-%s",cname);
    TCanvas *c3 = new TCanvas(idxn, tmp, 10, 10, 250, 500);
    c3->SetFillStyle(0); c3->SetFrameFillStyle(0);
    c3->SetBorderMode(0); c3->Divide(1,3,small,small);
    c3->Draw();

///////////////////////////
// eta-phi plots
//
     c3->cd(1);
     gPad->SetFillStyle(0);
     gPad->SetFrameFillStyle(0);
     hjeta[0]->SetFillStyle(0);
     hjeta[0]->SetLineColor(2);
     hjeta[0]->Draw();
     hjphi[0]->Draw("same");
     hmetphi[0]->SetLineColor(4);
     hmetphi[0]->Draw("same");
     c3->cd(2);
     gPad->SetFillStyle(0);
     gPad->SetFrameFillStyle(0);
     heeta[0]->SetFillStyle(0);
     heeta[0]->SetLineColor(2);
     heeta[0]->Draw();
     hephi[0]->Draw("same");
     c3->cd(3);
     gPad->SetFillStyle(0);
     gPad->SetFrameFillStyle(0);
     hmeta[0]->SetFillStyle(0);
     hmeta[0]->SetLineColor(2);
     hmeta[0]->Draw();
     hmphi[0]->Draw("same");

// efficiency & multiplicity plots
//
  c2->cd(1);
  eff->Draw();
// ////////////////////////////////
// PT  plots
//
  c1->cd(1);
 // gPad->SetLogy(1);
  hmet[0]->Draw();
  c1->cd(2);
  hept[0]->Draw();
  hmpt[0]->SetLineColor(2);
  hmpt[0]->Draw("same");
  gPad->SetLogy(1);
  c1->cd(3);
  hjpt[0]->Draw();
  gPad->SetLogy(1);
/////////////////////////////////

/////////////////////////////////
// save the plots
      char aaa[64];
  sprintf (aaa, "%s-1.png",cname); c1->SaveAs(aaa);
  sprintf (aaa, "%s-2.png",cname); c2->SaveAs(aaa);
  sprintf (aaa, "%s-3.png",cname); c3->SaveAs(aaa);
  sprintf (aaa, "%s-1.eps",cname); c1->SaveAs(aaa);
  sprintf (aaa, "%s-2.eps",cname); c2->SaveAs(aaa);
  sprintf (aaa, "%s-3.eps",cname); c3->SaveAs(aaa);

  return retval;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: saveHistos() {
  int retval=0;
  cout << "saving...\n";
  histoOut->Write();
  cout << "saved.\n";
  return retval;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: ChangeDir(char *dn) {
 cout <<"Going to "<<dn<<".\n";
 histoOut->cd(dn);
 return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA:: setDir(char *dn) {
  int retval=0;
  TDirectory *ndir= new TDirectory();
  ndir = histoOut->mkdir(dn);
  histoOut->cd(dn);
  cout << "Made dir:"<<dn<<".\n";
  eff= new TH1F("eff","selection efficiencies ",30,0.5,30.5);
  rntuple = new TNtuple("rntuple","run info","rn:lb");
  char hname[64];
  if (0)
  for (int k=0; k<m_idx; k++ ) {
    sprintf (hname,"metx%i",k); metx[k]= new TH1F (hname, "met x (GeV)",50,-12,12);
    sprintf (hname,"mety%i",k); mety[k]= new TH1F (hname, "met y (MeV)",50,-12,12);

    sprintf (hname,"hmet%i",k);         hmet[k]= new TH1F(hname, "Missing E_{T} (GeV)",       360, 0.0, 1800.0);
    sprintf (hname,"hmet_err%i",k); hmet_err[k]= new TH1F(hname, "Missing E_{T} qcd (GeV)",   360, 0.0, 1800.0);
    sprintf (hname,"jpt%i",k);          hjpt[k]= new TH1F(hname, "p_{T} jets (GeV)",          360, 0.0, 1800.0);
    sprintf (hname,"jpt_err%i",k);  hjpt_err[k]= new TH1F(hname, "p_{T} qcd jets (GeV)",      360, 0.0, 1800.0);
    sprintf (hname,"ept%i",k);          hept[k]= new TH1F(hname, "p_{T} electrons (GeV)",     360, 0.0, 1800.0);
    sprintf (hname,"ept_err%i",k);  hept_err[k]= new TH1F(hname, "p_{T} qcd electrons (GeV)", 360, 0.0, 1800.0);
    sprintf (hname,"mpt%i",k);          hmpt[k]= new TH1F(hname, "p_{T} muons (GeV)",         360, 0.0, 1800.0);
    sprintf (hname,"mpt_err%i",k);  hmpt_err[k]= new TH1F(hname, "p_{T} qcd muons (GeV)",     360, 0.0, 1800.0);
    sprintf (hname,"gpt%i",k);          hgpt[k]= new TH1F(hname, "p_{T} photons (GeV)",       360, 0.0, 1800.0);
    sprintf (hname,"gpt_err%i",k);  hgpt_err[k]= new TH1F(hname, "p_{T} qcd photons (GeV)",   360, 0.0, 1800.0);

    sprintf (hname,"eeta%i",k);         heeta[k]= new TH1F(hname, "#eta electrons",    200,-5.0,5.0);
    sprintf (hname,"eeta_err%i",k); heeta_err[k]= new TH1F(hname, "#eta qcd electrons",200,-5.0,5.0);
    sprintf (hname,"geta%i",k);         hgeta[k]= new TH1F(hname, "#eta photons",      200,-5.0,5.0);
    sprintf (hname,"geta_err%i",k); hgeta_err[k]= new TH1F(hname, "#eta qcd photons",  200,-5.0,5.0);
    sprintf (hname,"meta%i",k);         hmeta[k]= new TH1F(hname, "#eta muons",        200,-5.0,5.0);
    sprintf (hname,"meta_err%i",k); hmeta_err[k]= new TH1F(hname, "#eta qcd muons",    200,-5.0,5.0);
    sprintf (hname,"jeta%i",k);         hjeta[k]= new TH1F(hname, "#eta jets",         200,-5.0,5.0);
    sprintf (hname,"jeta_err%i",k); hjeta_err[k]= new TH1F(hname, "#eta qcd jets",     200,-5.0,5.0);

    sprintf (hname,"ephi%i",k);         hephi[k]= new TH1F(hname, "#phi electrons",32,-3.2, 3.2);
    sprintf (hname,"ephi_err%i",k); hephi_err[k]= new TH1F(hname, "#phi qcd electrons",32,-3.2, 3.2);
    sprintf (hname,"gphi%i",k);         hgphi[k]= new TH1F(hname, "#phi photons",32,-3.2, 3.2);
    sprintf (hname,"gphi_err%i",k); hgphi_err[k]= new TH1F(hname, "#phi qcd photons",32,-3.2, 3.2);
    sprintf (hname,"mphi%i",k);         hmphi[k]= new TH1F(hname, "#phi muons",32,-3.2, 3.2);
    sprintf (hname,"mphi_err%i",k); hmphi_err[k]= new TH1F(hname, "#phi qcd muons",32,-3.2, 3.2);
    sprintf (hname,"jphi%i",k);         hjphi[k]= new TH1F(hname, "#phi jets",32,-3.2, 3.2);
    sprintf (hname,"jphi_err%i",k); hjphi_err[k]= new TH1F(hname, "#phi qcd jets",32,-3.2, 3.2);

    sprintf (hname,"hmetphi%i",k);         hmetphi[k]= new TH1F(hname, "#phi of Missing E_{T}",32,-3.2, 3.2);
    sprintf (hname,"hmetphi_err%i",k); hmetphi_err[k]= new TH1F(hname, "#phi of Missing E_{T} qcd",32,-3.2, 3.2);

    sprintf (hname,"hlepq%i",k);         hlepq[k]= new TH1F(hname,"lepton charge", 3, -1.5, 1.5);

    sprintf (hname,"hjetm%i",k);         hjetm[k]= new TH1F(hname,"Invariant Mass of Jet", 160, -400.0, 400.0);
    sprintf (hname,"hjetm_err%i",k); hjetm_err[k]= new TH1F(hname,"Invariant Mass of qcd Jet", 160, -400.0, 400.0);

    sprintf (hname,"hlepq%i",k);         hlepq[k]= new TH1F(hname,"charge of lepton", 3, -1.5, 1.5);
  }
  return retval;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double dbxA::deltaR(double eta1, double phi1, double eta2, double phi2)
{
   double deta= fabs(eta1 - eta2);
   double dphi= fabs(phi1 - phi2);
   if (dphi > M_PI) dphi=2*M_PI-dphi;

   double dR=sqrt((dphi*dphi)+(deta*deta));
   return dR;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::getPeriodIndx(unsigned int runno)
{

    const size_t runStart[] = { 177986, 179710, 180614, 182013, 182726, 183544, 185353, 186516, 186873, 188902, 190503 };
    const size_t runEnd[] = { 178109, 180481, 180776, 182519, 183462, 184169, 186493, 186755, 187815, 190343, 191933 };

    int index = -1;
    //std::cout << "runno :  " << runno << std::endl;
    for (unsigned int i = 0; i < NPERIOD; i++)
    {
      if ( (runStart[i] <= runno) && (runno <= runEnd[i]) )
      {
          index = i;
          //std::cout << "index :  " << index << " period : " << dbxA::periodName[index] << std::endl;
          break;
      }
    }
    if ( index < 0 ) std::cout << "WARNING : Run number " << runno << " not found ! " << std::endl;

    return index;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double dbxA::getPeriodLumi(unsigned int periodIndex)
{

     // lumi in pb-1.
     const double lumi[] = { 11.7377, 166.6502, 48.7802, 132.4979, 507.9311, 259.4593, 337.5425,
                             226.3913, 590.3638, 1404.7923, 1026.9443 };
     return lumi[periodIndex];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int dbxA::getMCPeriodIndx(unsigned int runNumber, unsigned int seed) {

  TRandom3 m_myRandomPeriod;

  if(runNumber==180164)
    return dbxA::getPeriodIndx(runNumber);
  else if(runNumber==183003)
    return dbxA::getPeriodIndx(runNumber);
  // the first is for mc11a, second for mc11b
  else if(runNumber==185649 || runNumber==186169){

    // if you want reproducible random numbers, either use the debug option or
    // provide a seed (e.g. the eventnumber)
    m_myRandomPeriod.SetSeed(seed);

    // weight by the fraction of lumi from each sub-set of this period
    double rnd = m_myRandomPeriod.Uniform();
    if ( rnd <= dbxA::getPeriodLumi(6)/(dbxA::getPeriodLumi(6)+dbxA::getPeriodLumi(7)+dbxA::getPeriodLumi(8)) )             return 6;
    else if ( rnd <= (dbxA::getPeriodLumi(6)+dbxA::getPeriodLumi(7))/(dbxA::getPeriodLumi(6)+dbxA::getPeriodLumi(7)+dbxA::getPeriodLumi(8))) return 7;
    else  return 8;
  }
  else if(runNumber==185761 || runNumber==189751) return 10;

  return -1;
}

/*
 * in "initializeTTree4Something()" methods, a big piece of code was redundant. I implemented that piece of code in another method to eliminate redundancy of code. From now on, "initializeTTree4Something()" will call this method instead of executing redundant code.
 */
void dbxA::initializeTTree(TTree* t, Double_t* adresler, int len_Fields, const char* branchNamePrefix, const char* fields[]) {
    const char* branchName;
    string branchName_str;
    const char* leafList;
    string leafList_str;
    for (int i = 0; i < len_Fields; i++) {
        // + does not work for "const char*"
        //branchName_str = branchNamePrefix + "." + genParticle_Fields[i];
        branchName_str = string(branchNamePrefix) + "." + string(fields[i]);
        branchName = branchName_str.c_str();

        // + does not work for "const char*"
        //leafList_str = genParticle_Fields[i] + "/D";
        leafList_str = string(fields[i]) + "/D";
        leafList = leafList_str.c_str();

        // http://root.cern.ch/root/html/TTree.html#TTree:Branch
        t->Branch(branchName, &adresler[i], leafList);
    }

}

void dbxA:: initializeTTree4TLorentzVector(TTree* t, Double_t* adresler, const char* branchNamePrefix) {

    // Elements of "lorentzVector_Fields" will be used as suffix for branch names
    // Length of "lorentzVector_Fields" is 32. So the "adresler" must be of length 32. The user should have allocated "adresler" with length 32 before calling this function.
    // http://stackoverflow.com/questions/3814804/initializing-a-static-const-char-array
    const char* lorentzVector_Fields[] = {"Beta", "CosTheta", "E", "Energy", "Et", "Et2", "Eta", "Gamma", "M", "M2", "Mag", "Mag2", "Minus", "Mt", "Mt2", "P", "Perp", "Perp2", "Phi", "Plus", "PseudoRapidity", "Pt", "Px", "Py", "Pz", "Rapidity", "Rho", "T", "Theta", "X", "Y", "Z"};

    // http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    int len_Fields = (sizeof (lorentzVector_Fields) / sizeof (*lorentzVector_Fields)); // =32

    initializeTTree(t, adresler, len_Fields, branchNamePrefix, lorentzVector_Fields);
}

/*
 * example usage :
 *
    TTree *t_dbxP = new TTree("Particles", "a tree of dbxParticles");
    Double_t fields_t_dbxP[numOfFields_dbxParticle];
    const char* prefix_t_dbxP = "prtcl"; // must start with lowercase letter, dont know the stupid reason for that
    initializeTTree4TLorentzVector(t_dbxP, fields_t_dbxP, prefix_t_dbxP);
 *
 */
void dbxA:: initializeTTree4dbxParticle(TTree* t, Double_t* adresler, const char* branchNamePrefix) {

    // Names of "dbxParticle" fields will be used as suffix for branch names
    // Length of retrievable "dbxParticle" fields is 17. So the "adresler" must be of length 17. The user should have allocated "adresler" with length 17 before calling this function.
    // http://stackoverflow.com/questions/3814804/initializing-a-static-const-char-array
    const char* dbxParticle_Fields[] = {"q","EtCone","PtCone","Flavor","isTight","ParticleIndx","ScaleFactor","ScaleFactorUncertainty","ScaleFactorUncertaintyUp","ScaleFactorUncertaintyDown","SFRecoUncertaintyUp","SFRecoUncertaintyDown","SFTrigUncertaintyUp","SFTrigUncertaintyDown","SFIDUncertaintyUp","SFIDUncertaintyDown","Z0"};

    // http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    int len_Fields = (sizeof (dbxParticle_Fields) / sizeof (*dbxParticle_Fields)); // =17

    initializeTTree(t, adresler, len_Fields, branchNamePrefix, dbxParticle_Fields);
}

void dbxA:: initializeTTree4dbxMuon(TTree* t, Double_t* adresler, const char* branchNamePrefix) {

    // Names of "dbxMuon" fields will be used as suffix for branch names
    // Length of retrievable "dbxMuon" fields is 25. So the "adresler" must be of length 25. The user should have allocated "adresler" with length 25 before calling this function.
    // http://stackoverflow.com/questions/3814804/initializing-a-static-const-char-array
    const char* dbxMuon_Fields[] = {"q","EtCone","PtCone","Flavor","isTight","ParticleIndx","ScaleFactor","ScaleFactorUncertainty","ScaleFactorUncertaintyUp","ScaleFactorUncertaintyDown","SFRecoUncertaintyUp","SFRecoUncertaintyDown","SFTrigUncertaintyUp","SFTrigUncertaintyDown","SFIDUncertaintyUp","SFIDUncertaintyDown","Z0","MuTriggerMatch","TopMuInTrigger","MuIdTheta","MuIdPhi","PtMsup","PtMsdown","PtIdup","PtIddown"};

    // http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    int len_Fields = (sizeof (dbxMuon_Fields) / sizeof (*dbxMuon_Fields)); // =25

    initializeTTree(t, adresler, len_Fields, branchNamePrefix, dbxMuon_Fields);
}

void dbxA:: initializeTTree4dbxElectron(TTree* t, Double_t* adresler, const char* branchNamePrefix) {

    // Names of "dbxElectron" fields will be used as suffix for branch names
    // Length of retrievable "dbxElectron" fields is 29. So the "adresler" must be of length 29. The user should have allocated "adresler" with length 29 before calling this function.
    // http://stackoverflow.com/questions/3814804/initializing-a-static-const-char-array
    const char* dbxElectron_Fields[] = {"q","EtCone","PtCone","Flavor","isTight","ParticleIndx","ScaleFactor","ScaleFactorUncertainty","ScaleFactorUncertaintyUp","ScaleFactorUncertaintyDown","SFRecoUncertaintyUp","SFRecoUncertaintyDown","SFTrigUncertaintyUp","SFTrigUncertaintyDown","SFIDUncertaintyUp","SFIDUncertaintyDown","Z0","ElTriggerMatch","ElTriggerDR","TrkTheta","TrkEta","TrkPhi","BestEt","PtCone30","EtCone20","Ep_elE_up","Ep_elE_down","clusterE","clusterEta"};

    // http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    int len_Fields = (sizeof (dbxElectron_Fields) / sizeof (*dbxElectron_Fields)); // =29

    initializeTTree(t, adresler, len_Fields, branchNamePrefix, dbxElectron_Fields);
}

void dbxA:: initializeTTree4dbxJet(TTree* t, Double_t* adresler, const char* branchNamePrefix) {

    // Names of "dbxJet" fields will be used as suffix for branch names
    // Length of retrievable "dbxJet" fields is 34. So the "adresler" must be of length 34. The user should have allocated "adresler" with length 34 before calling this function.
    // http://stackoverflow.com/questions/3814804/initializing-a-static-const-char-array
    const char* dbxJet_Fields[] = {"q","EtCone","PtCone","Flavor","isTight","ParticleIndx","ScaleFactor","ScaleFactorUncertainty","ScaleFactorUncertaintyUp","ScaleFactorUncertaintyDown","SFRecoUncertaintyUp","SFRecoUncertaintyDown","SFTrigUncertaintyUp","SFTrigUncertaintyDown","SFIDUncertaintyUp","SFIDUncertaintyDown","Z0","Jee_status","JLabel","JesuRelativePos","JesuRelativeNeg","JerUncert","Sv0mass","Sv0nt2","Sv0svok","Sv0ntrk","Sv0ntrkv","Sv0ntrkj","Sv0efrc","JetVtxF","EmEta","EmPhi","EtaCorr","JetFrac"};

    // http://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array
    int len_Fields = (sizeof (dbxJet_Fields) / sizeof (*dbxJet_Fields)); // =34

    initializeTTree(t, adresler, len_Fields, branchNamePrefix, dbxJet_Fields);
}

/*
 * fills branches of the given TTree "t". "t" is a TTree that contains all the fields of type "TLorentzVector".
 * Values are taken from the TLorentzVector "vec". Branches of "t" are filled with values of the fields of "vec".
 *
 * "adresler" must be the same addresses that were used during the initialization of the "TTree" object.
 *
 *  http://www.cplusplus.com/doc/tutorial/pointers/
 */
void dbxA:: fillTTree4LorentzVector(TTree* t, Double_t* adresler, TLorentzVector & vec) {

    adresler[0] = vec.Beta();
    adresler[1] = vec.CosTheta();
    adresler[2] = vec.E();
    adresler[3] = vec.Energy();
    adresler[4] = vec.Et();
    adresler[5] = vec.Et2();
    adresler[6] = vec.Eta();
    adresler[7] = vec.Gamma();
    adresler[8] = vec.M();
    adresler[9] = vec.M2();
    adresler[10] = vec.Mag();
    adresler[11] = vec.Mag2();
    adresler[12] = vec.Minus();
    adresler[13] = vec.Mt();
    adresler[14] = vec.Mt2();
    adresler[15] = vec.P();
    adresler[16] = vec.Perp();
    adresler[17] = vec.Perp2();
    adresler[18] = vec.Phi();
    adresler[19] = vec.Plus();
    adresler[20] = vec.PseudoRapidity();
    adresler[21] = vec.Pt();
    adresler[22] = vec.Px();
    adresler[23] = vec.Py();
    adresler[24] = vec.Pz();
    adresler[25] = vec.Rapidity();
    adresler[26] = vec.Rho();
    adresler[27] = vec.T();
    adresler[28] = vec.Theta();
    adresler[29] = vec.X();
    adresler[30] = vec.Y();
    adresler[31] = vec.Z();

    t->Fill();
    //delete t;
}

/*
 * fills branches of the given TTree "t". "t" is a TTree that contains all the fields of type "dbxParticle".
 * Values are taken from the dbxParticle "dbx_particle". Branches of "t" are filled with values of the fields of "dbx_particle".
 *
 * "adresler" must be the same addresses that were used during the initialization of the "TTree" object.
 *
 *  http://www.cplusplus.com/doc/tutorial/pointers/
 */
void dbxA:: fillTTree4dbxParticle(TTree* t, Double_t* adresler, dbxParticle & dbx_particle) {

	adresler[0] = dbx_particle.q();
	adresler[1] = dbx_particle.EtCone();
	adresler[2] = dbx_particle.PtCone();
	adresler[3] = dbx_particle.Flavor();
	adresler[4] = dbx_particle.isTight();
	adresler[5] = dbx_particle.ParticleIndx();
	adresler[6] = dbx_particle.ScaleFactor();
	adresler[7] = dbx_particle.ScaleFactorUncertainty();
	adresler[8] = dbx_particle.ScaleFactorUncertaintyUp();
	adresler[9] = dbx_particle.ScaleFactorUncertaintyDown();
	adresler[10] = dbx_particle.SFRecoUncertaintyUp();
	adresler[11] = dbx_particle.SFRecoUncertaintyDown();
	adresler[12] = dbx_particle.SFTrigUncertaintyUp();
	adresler[13] = dbx_particle.SFTrigUncertaintyDown();
	adresler[14] = dbx_particle.SFIDUncertaintyUp();
	adresler[15] = dbx_particle.SFIDUncertaintyDown();
	adresler[16] = dbx_particle.Z0();

    t->Fill();
    //delete t;
}

/*
 * fills branches of the given TTree "t". "t" is a TTree that contains all the fields of type "dbxMuon".
 * Values are taken from the dbxMuon "dbx_muon". Branches of "t" are filled with values of the fields of "dbx_muon".
 *
 * "adresler" must be the same addresses that were used during the initialization of the "TTree" object.
 *
 *  http://www.cplusplus.com/doc/tutorial/pointers/
 */
void dbxA:: fillTTree4dbxMuon(TTree* t, Double_t* adresler, dbxMuon & dbx_muon) {

	adresler[0] = dbx_muon.q();
	adresler[1] = dbx_muon.EtCone();
	adresler[2] = dbx_muon.PtCone();
	adresler[3] = dbx_muon.Flavor();
	adresler[4] = dbx_muon.isTight();
	adresler[5] = dbx_muon.ParticleIndx();
	adresler[6] = dbx_muon.ScaleFactor();
	adresler[7] = dbx_muon.ScaleFactorUncertainty();
	adresler[8] = dbx_muon.ScaleFactorUncertaintyUp();
	adresler[9] = dbx_muon.ScaleFactorUncertaintyDown();
	adresler[10] = dbx_muon.SFRecoUncertaintyUp();
	adresler[11] = dbx_muon.SFRecoUncertaintyDown();
	adresler[12] = dbx_muon.SFTrigUncertaintyUp();
	adresler[13] = dbx_muon.SFTrigUncertaintyDown();
	adresler[14] = dbx_muon.SFIDUncertaintyUp();
	adresler[15] = dbx_muon.SFIDUncertaintyDown();
	adresler[16] = dbx_muon.Z0();
	adresler[17] = dbx_muon.MuTriggerMatch();
	adresler[18] = dbx_muon.TopMuInTrigger();
	adresler[19] = dbx_muon.MuIdTheta();
	adresler[20] = dbx_muon.MuIdPhi();
	adresler[21] = dbx_muon.PtMsup();
	adresler[22] = dbx_muon.PtMsdown();
	adresler[23] = dbx_muon.PtIdup();
	adresler[24] = dbx_muon.PtIddown();

    t->Fill();
    //delete t;
}

/*
 * fills branches of the given TTree "t". "t" is a TTree that contains all the fields of type "dbxElectron".
 * Values are taken from the dbxElectron "dbx_electron". Branches of "t" are filled with values of the fields of "dbx_electron".
 *
 * "adresler" must be the same addresses that were used during the initialization of the "TTree" object.
 *
 *  http://www.cplusplus.com/doc/tutorial/pointers/
 */
void dbxA:: fillTTree4dbxElectron(TTree* t, Double_t* adresler, dbxElectron & dbx_electron) {

	adresler[0] = dbx_electron.q();
	adresler[1] = dbx_electron.EtCone();
	adresler[2] = dbx_electron.PtCone();
	adresler[3] = dbx_electron.Flavor();
	adresler[4] = dbx_electron.isTight();
	adresler[5] = dbx_electron.ParticleIndx();
	adresler[6] = dbx_electron.ScaleFactor();
	adresler[7] = dbx_electron.ScaleFactorUncertainty();
	adresler[8] = dbx_electron.ScaleFactorUncertaintyUp();
	adresler[9] = dbx_electron.ScaleFactorUncertaintyDown();
	adresler[10] = dbx_electron.SFRecoUncertaintyUp();
	adresler[11] = dbx_electron.SFRecoUncertaintyDown();
	adresler[12] = dbx_electron.SFTrigUncertaintyUp();
	adresler[13] = dbx_electron.SFTrigUncertaintyDown();
	adresler[14] = dbx_electron.SFIDUncertaintyUp();
	adresler[15] = dbx_electron.SFIDUncertaintyDown();
	adresler[16] = dbx_electron.Z0();
	adresler[17] = dbx_electron.ElTriggerMatch();
	adresler[18] = dbx_electron.ElTriggerDR();
	adresler[19] = dbx_electron.TrkTheta();
	adresler[20] = dbx_electron.TrkEta();
	adresler[21] = dbx_electron.TrkPhi();
	adresler[22] = dbx_electron.BestEt();
	adresler[23] = dbx_electron.PtCone30();
	adresler[24] = dbx_electron.EtCone20();
	adresler[25] = dbx_electron.Ep_elE_up();
	adresler[26] = dbx_electron.Ep_elE_down();
	adresler[27] = dbx_electron.clusterE();
	adresler[28] = dbx_electron.clusterEta();

    t->Fill();
    //delete t;
}

/*
 * fills branches of the given TTree "t". "t" is a TTree that contains all the fields of type "dbxJet".
 * Values are taken from the dbxJet "dbx_jet". Branches of "t" are filled with values of the fields of "dbx_jet".
 *
 * "adresler" must be the same addresses that were used during the initialization of the "TTree" object.
 *
 *  http://www.cplusplus.com/doc/tutorial/pointers/
 */
void dbxA:: fillTTree4dbxJet(TTree* t, Double_t* adresler, dbxJet & dbx_jet) {

	adresler[0] = dbx_jet.q();
	adresler[1] = dbx_jet.EtCone();
	adresler[2] = dbx_jet.PtCone();
	adresler[3] = dbx_jet.Flavor();
	adresler[4] = dbx_jet.isTight();
	adresler[5] = dbx_jet.ParticleIndx();
	adresler[6] = dbx_jet.ScaleFactor();
	adresler[7] = dbx_jet.ScaleFactorUncertainty();
	adresler[8] = dbx_jet.ScaleFactorUncertaintyUp();
	adresler[9] = dbx_jet.ScaleFactorUncertaintyDown();
	adresler[10] = dbx_jet.SFRecoUncertaintyUp();
	adresler[11] = dbx_jet.SFRecoUncertaintyDown();
	adresler[12] = dbx_jet.SFTrigUncertaintyUp();
	adresler[13] = dbx_jet.SFTrigUncertaintyDown();
	adresler[14] = dbx_jet.SFIDUncertaintyUp();
	adresler[15] = dbx_jet.SFIDUncertaintyDown();
	adresler[16] = dbx_jet.Z0();
	adresler[17] = dbx_jet.Jee_status();
	adresler[18] = dbx_jet.JLabel();
	adresler[19] = dbx_jet.JesuRelativePos();
	adresler[20] = dbx_jet.JesuRelativeNeg();
	adresler[21] = dbx_jet.JerUncert();
	adresler[22] = dbx_jet.Sv0mass();
	adresler[23] = dbx_jet.Sv0nt2();
	adresler[24] = dbx_jet.Sv0svok();
	adresler[25] = dbx_jet.Sv0ntrk();
	adresler[26] = dbx_jet.Sv0ntrkv();
	adresler[27] = dbx_jet.Sv0ntrkj();
	adresler[28] = dbx_jet.Sv0efrc();
	adresler[29] = dbx_jet.JetVtxF();
	adresler[30] = dbx_jet.EmEta();
	adresler[31] = dbx_jet.EmPhi();
	adresler[32] = dbx_jet.EtaCorr();
	adresler[33] = dbx_jet.JetFrac();

    t->Fill();
    //delete t;
}
