#include<iostream>
#include <iomanip> 
#include <vector>
#include "PolFitter.cpp"
//#include "ReadCard.cpp"
//#include "../RSL/RSLimit.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

//#ifdef __MAKECINT__
//#pragma link C++ class std::vector<double>+;
//#endif

void CalculateLimits ( TH1 *sigh, TH1 *bkgh, TH1 *dath, int qm, int opmode, TString lepton, string btag_txt, int pset=3, int disc=2) {
//#define __DEBUG__

static int done_once=0;
int aaa=999; // this is to see what happens in each step
float err=0.005; // this is how close we want to get the 5x10^-2 which is the 95% CL.
float epsi=9.9; // this is the initial value of the calculated CLs and Expected CLS=4.55x10^-2
float epsi_prev; // we heep track of the previous epsilon to see if the calculation converges or not.
float coeff=0.10; // initially we search the k with 5% variations and as epsilon gets smaller so does this percentage.
int sgnChangeCnt=0; // keep track of the number of sign changes to count if the calculation oscillates or converges.
float k=0.01; // the initial coefficient
int shit_again=0; // to count and exit infinite loops
float target=0.05; // this is the target 1.96 sigma AKA 95% CL., 4.55E-2 is 2 sigma
int mcevts=50000; // ngu made this 5k instead of 50k, he is not patient. feel free to increase
float tmpcl, tmpclb, clb_1k, cls_1k=1;
float tmpcl_prev;
int is2d=0;
int sigma=0;
int sum_channels=(int)ReadCard("ANA_DEFS","SUMCHANNELS"); //0:dont 1:do add the e- and mu
int CLs_CLsb=(int)ReadCard("ANA_DEFS","STAT"); //0: CLs, 1:CLsb
int  staterr=(int)ReadCard("ANA_DEFS","STATERR"); //0: false, 1:true
int  systerr=(int)ReadCard("ANA_DEFS","SYSTERR"); //0: false, 1:true
int Limitter=(int)ReadCard("ANA_DEFS","LIMITTER"); // 0: TLimit, 1:RSLimit, 2:fastPCLimitter, 3:mclimit
TString limitterTXT[4];  limitterTXT[0]="TLimit"; limitterTXT[1]="RSLimit"; limitterTXT[2]="fastPCL"; limitterTXT[3]="MCLimit";
cout << "Will Calculate Limit with:"<<limitterTXT[Limitter]<<endl;
//Variables in vector form ; vectors initialized
std::vector<double>* kvec = new std::vector<double>(0);
std::vector<double>* CLvec= new std::vector<double>(0);

// I dont like static but...
 double k_expp2, k_expp1, k_exp0,k_expm1, k_expm2, k_obs;

if ( gROOT->GetListOfTypes()->FindObject("vector<sbin>") == 0 ) {
   gROOT->LoadMacro("../analysis_core/sbinset.C+");
}
#ifdef __ROOT6__
  //R__LOAD_LIBRARY(../RSL/RSLimit.C+);
#else
  if ( gROOT->LoadMacro("../RSL/RSLimit.C+") < 0 ) {
    cerr<<("RSLimit Library failure! Forcing TLimit utilization\n");
    Limitter=0; 
  }
#endif

if (opmode!=99) {
 sigma=opmode;
} else {
 sigma=0; // i know, but...
}

char err_txt[8];
if (!staterr) { sprintf (err_txt,"NoEr"); } else { sprintf (err_txt,"Stat"); }
if (systerr) sprintf (err_txt,"Syst");
char stat_txt[32];
if (CLs_CLsb) { sprintf (stat_txt,"CLsb"); } else { sprintf (stat_txt,"CLs"); }

char exptxt[128];
TString thislepton=lepton;
if (sum_channels) { // read the other lepton channel and add.
 thislepton="BOTH";
}
sprintf (exptxt,"mQ %i %s _%s_ %s %s sf  ",qm,btag_txt.c_str(),thislepton.Data(), err_txt, stat_txt);

char fname[128]; sprintf (fname,"Limit.txt");
std::ofstream of(fname,fstream::app);
of << fixed;
if (opmode == -2) {
   of << endl;
   of << "#Limitter is " << limitterTXT[Limitter] << "   toyMCevts="<< mcevts <<endl;
}
TString infileo="sibg_";
TString infilen="sibg_";
if (lepton == "MUON") { //  cout << "ADDING e- to mu"<<endl; 
    infilen+="ELE_";
    infileo+="MUON_";
}
if (lepton == "ELE") { // cout << "ADDING mu to e-"<<endl; 
    infilen+="MUON_";
    infileo+="ELE_";
}
infilen+=qm;
infilen+="_";
infilen+=pset;
infilen+="_";
infilen+=disc;
infilen+=".root";

infileo+=qm;
infileo+="_";
infileo+=pset;
infileo+="_";
infileo+=disc;
infileo+=".root";

if (sigh != NULL) {
  if (sigh->InheritsFrom("TH2F")) {
   is2d=1;
  }
} else { // we are told to get the histograms from the existing file, which is infileo
 TFile *eFile = new TFile (infileo);
    sigh = (TH1F*)((TH1F*)eFile->Get("signal"))->Clone();
    bkgh = (TH1F*)((TH1F*)eFile->Get("sample_1"))->Clone();
    dath = (TH1F*)((TH1F*)eFile->Get("data"))->Clone();
}
 
TFile  *bd;
do {
// limits and such
 TH1* toplams = (TH1*) sigh->Clone();
 TH1* toplamb = (TH1*) bkgh->Clone();
 TH1* toplamq = (TH1*) dath->Clone();
 toplams->Scale(k);

// the other channel
  TH1F *toplams_other, *toplamb_other, *toplamq_other;
  if (sum_channels) { // read the other lepton channel and add.
    bd = new TFile(infilen);
    toplams_other = (TH1F*)((TH1F*)bd->Get("signal"))->Clone();
    toplamb_other = (TH1F*)((TH1F*)bd->Get("sample_1"))->Clone();
    toplamq_other = (TH1F*)((TH1F*)bd->Get("data"))->Clone();
    toplams_other->Scale(k);
   }

// here we should have the preparation of 2D-->1D Histogram.
 if (is2d) {
/*
  TH2* hmcsig = (TH2*)toplams->Clone();
  TH2* hmcbkg = (TH2*)toplamb->Clone();
  sbinSet ss(hmcsig,hmcbkg);
  ss.Mergeator(.3,20);
  std::cout << "Number of bins: "<< ss.getNBins() << std::endl;
  TH1F* rs= ss.Rebinneator(hmcsig);
  TH1F* rb= ss.Rebinneator(hmcbkg);
  if (opmode!=99) {
    TH1F* tt=(TH1F*)rb->Clone(); tt->Add(rs);   // expected
  } else {
    TH1F* tt= ss.Rebinneator(toplamq);   // observed beware of 2D
  }
#ifdef __DEBUG__
  TLimitDataSource* ms = new TLimitDataSource(rs,rb,tt);
  TConfidenceLevel *mc = TLimit::ComputeLimit(ms,5000);
  cout<< "CLs ="<<mc->GetExpectedCLs_b(sigma)<<endl;;
  cout<< "CLsb ="<<mc->GetExpectedCLsb_b(sigma)<<endl;;
#endif
   toplamq=(TH1F*)tt->Clone();
   toplams=(TH1F*)rs->Clone();
   toplamb=(TH1F*)rb->Clone();
   //tt->Delete();
   rs->Delete();
   rb->Delete();
*/
;
 } else {
  // the 1D case 
  if (opmode!=99) {
   toplamq->Add(toplams,toplamb);    // signal +bg ~= data
    cout << "MC mode @"<<qm<< " ";
  } else {
   toplamq = (TH1*) dath->Clone();
    cout << "Data mode @"<<qm<<" " << " k="<<k;
  }
 }

#ifdef __DEBUG__
  TCanvas* c3 = new TCanvas();
  c3->SetLogy();
  toplams->SetMaximum( toplamb->GetMaximum()*1E3);
  toplams->SetMinimum( toplamb->GetMaximum()/1E5);
  toplams->SetMarkerStyle(20); toplams->SetMarkerColor(40); toplams->SetLineColor(40); toplams->Draw("e");
  toplamb->SetMarkerStyle(22); toplamb->SetMarkerColor(kBlack); toplamb->SetLineColor(kBlack); toplamb->Draw("same")
;
  toplamq->SetMarkerStyle(21); toplamq->SetMarkerColor(kBlue); toplamq->SetLineColor(kBlue); toplamq->Draw("same");
  c3->SaveAs("toplamb.eps");
#endif


if (Limitter==0 ) {    //TLimit ----------
   TLimitDataSource* mydatasource  = new TLimitDataSource();

if (systerr) {
// the below is an example on how to add systematic errors
   TVectorD errorb(2);
   TVectorD errors(2);
   TObjArray* names = new TObjArray();
   TObjString name1("bg uncertainty");
   TObjString name2("sig uncertainty");
   names->AddLast(&name1);
   names->AddLast(&name2);
   // sqrt( pow(3213.82*0.1,2) + pow(569.722*0.3,2) + pow(33.5309*0.3,2) + pow(256.367*0.1,2) ) / (3213.82+569.722+33.5309+256.367) = errorb[0]
   errorb[0]=0.0896; // error source 1: 9% (10% err for tt & single t, 30% err for W/Z+jets, add in quad)
   errorb[1]=0.044;  // error source 2: 4.4%  ( lumi err )
   errors[0]=0;      // error source 1: 0%
   errors[1]=0.044;  // error source 2: 4.4%  ( lumi err )
   mydatasource->AddChannel(toplams,toplamb,toplamq,&errors,&errorb,names);
   staterr=1; // force in case of systematic errors
   cout <<"systematics"<<endl;
} else {
   mydatasource->AddChannel(toplams,toplamb,toplamq);
   if (sum_channels) { // read the other lepton channel and add.
      mydatasource->AddChannel(toplams_other,toplamb_other,toplamq_other);
   }
}


   TConfidenceLevel *myconfidence = TLimit::ComputeLimit(mydatasource,mcevts,staterr); 
// if staterr=0: no statistical fluctiations
// if staterr=1: with statistical fluctiations

   if (opmode!=99) {
    tmpclb=myconfidence->GetExpectedCLb_b(sigma);  // bg only
    if (CLs_CLsb) {
     tmpcl=myconfidence->GetExpectedCLsb_b(sigma);  // expected
    } else {   
     tmpcl=myconfidence->GetExpectedCLs_b(sigma);  // expected
    }
   } else {
    tmpclb=myconfidence->CLb(sigma);  // bg only
    if (CLs_CLsb) {
     tmpcl=myconfidence->CLsb(); //observed aka measured
    } else {   
     tmpcl=myconfidence->CLs(); //observed aka measured
     float tmp2cl=myconfidence->CLsb(); 
    }
   } 
 // myconfidence->Draw();
   mydatasource->Delete();
   myconfidence->Delete();

} else if (Limitter==1) {       //RSLimit we will use the HypoTestInterter.
 
 if (done_once==0) {
    cout << "Doing all in one go with RSLimit. This will potentially be long"<<endl;;
/* ----
 TFile  *bd = new TFile("sibg.root");
  TH1F *sihh = (TH1F*)((TH1F*)bd->Get("signal"))->Clone();
  TH1F *bghh = (TH1F*)((TH1F*)bd->Get("sample_1"))->Clone();
  TH1F *dthh = (TH1F*)((TH1F*)bd->Get("data"))->Clone();
        bd->Close();
 cout <<"file closed"<<endl;
 TCanvas *c5=new TCanvas();
 c5->cd();
 cout << "Canvas drawn"<<endl;
 bghh->Draw();
 cout << "Histo drawn"<<endl;
 dthh->Draw("esame");
 sihh->Draw("same");
 RSLimit u4limit(sihh, bghh, dthh);
 cout <<"RSL initialized"<<endl;
*/
      TString RSoutfilename="RSL_HTI_";
              RSoutfilename+=qm;
              RSoutfilename+=".pdf";
 
 /*RSLimit u4limit(sigh, bkgh, dath);
    u4limit.UseProof(2);
    u4limit.SetToyMC(mcevts,mcevts);
    u4limit.SelectTestStats(1); // RatioOfProfiledLikelihoodsTestStat :log likelihood ratio = 
                                // log( Lambda(mu_alt , conditional MLE for alt nuisance)/ Lambda(mu_null , conditional MLE for null nuisance)
    u4limit.SetCLsCLsb(CLs_CLsb); //0:CLs  1:CLs+b
    u4limit.Initialize();
    u4limit.DoHTI(true);
    float lowerLim= 0.72 -0.51333E-02*qm +0.93333E-05*qm*qm; 
    //float lowerLim= 0.02;
    float upperLim= lowerLim*12;
    cout << "Scanning between "<<lowerLim << "  and  "<< upperLim<<endl;
    u4limit.TestHypothesis(10, lowerLim*u4limit.GetXS0(), upperLim*u4limit.GetXS0()); // the real computation is here
    u4limit.DrawHTIPlot(RSoutfilename);
    k_expp2=u4limit.GetKFactorExp(-2);
    k_expp1=u4limit.GetKFactorExp(-1);
     k_exp0=u4limit.GetKFactorExp(0);
    k_expm1=u4limit.GetKFactorExp(1);
    k_expm2=u4limit.GetKFactorExp(2);
      k_obs=u4limit.GetKFactorObs();
*/
/*    RSLimit t4limit(sigh, bkgh, dath); // this is a second copy. we only get CLb and CLs values @ k=1
    t4limit.UseProof(2);
    t4limit.SetToyMC(mcevts,mcevts);
    t4limit.SelectTestStats(1); // log likelihood ratio
    t4limit.SetCLsCLsb(CLs_CLsb); //0:CLs  1:CLs+b
    t4limit.Initialize();
    t4limit.TestHypothesis(1, 0., 1.5); // the real computation is here
//----cls
    double u4lim_exp_p2s= t4limit.ConfidenceLevelExp(2);
    double u4lim_exp_m2s= t4limit.ConfidenceLevelExp(-2);
    double u4lim_exp_p1s= t4limit.ConfidenceLevelExp(1);
    double u4lim_exp_m1s= t4limit.ConfidenceLevelExp(-1);
    double u4lim_obs    = t4limit.ConfidenceLevelObs();
    double u4lim_exp    = t4limit.ConfidenceLevelExp(0);
//----clb
    double u4lim_exb_p2s= t4limit.ConfidenceLevelExp(2,1);
    double u4lim_exb_m2s= t4limit.ConfidenceLevelExp(-2,1);
    double u4lim_exb_p1s= t4limit.ConfidenceLevelExp(1,1);
    double u4lim_exb_m1s= t4limit.ConfidenceLevelExp(-1,1);
    double u4lim_obb    = t4limit.ConfidenceLevelObs(1);
    double u4lim_exb    = t4limit.ConfidenceLevelExp(0,1);
 */
//-----save the file or king
     TFile bb("rsl_out.root","recreate");/*
     TParameter<double> *k_expp2_tmp=new TParameter<double> ("kf_expp2", k_expp2);k_expp2_tmp->Write();
     TParameter<double> *k_expm2_tmp=new TParameter<double> ("kf_expm2", k_expm2);k_expm2_tmp->Write();
     TParameter<double> *k_expp1_tmp=new TParameter<double> ("kf_expp1", k_expp1);k_expp1_tmp->Write();
     TParameter<double> *k_expm1_tmp=new TParameter<double> ("kf_expm1", k_expm1);k_expm1_tmp->Write();
     TParameter<double> *k_exp0_tmp=new TParameter<double>  ("kf_exp0",   k_exp0);k_exp0_tmp->Write();
     TParameter<double> *k_obs_tmp=new TParameter<double>   ("kf_obs",     k_obs);k_obs_tmp->Write();
     TParameter<double> *u_expp2_tmp=new TParameter<double> ("u_expp2", u4lim_exp_p2s);u_expp2_tmp->Write();
     TParameter<double> *u_expm2_tmp=new TParameter<double> ("u_expm2", u4lim_exp_m2s);u_expm2_tmp->Write();
     TParameter<double> *u_expp1_tmp=new TParameter<double> ("u_expp1", u4lim_exp_p1s);u_expp1_tmp->Write();
     TParameter<double> *u_expm1_tmp=new TParameter<double> ("u_expm1", u4lim_exp_m1s);u_expm1_tmp->Write();
     TParameter<double> *u_exp0_tmp=new TParameter<double>  ("u_exp0",  u4lim_exp    );u_exp0_tmp->Write();
     TParameter<double> *u_obs_tmp=new TParameter<double>   ("u_obs",   u4lim_obs    );u_obs_tmp->Write();
     TParameter<double> *u_expp2_tmb=new TParameter<double> ("u_exbp2", u4lim_exb_p2s);u_expp2_tmb->Write();
     TParameter<double> *u_expm2_tmb=new TParameter<double> ("u_exbm2", u4lim_exb_m2s);u_expm2_tmb->Write();
     TParameter<double> *u_expp1_tmb=new TParameter<double> ("u_exbp1", u4lim_exb_p1s);u_expp1_tmb->Write();
     TParameter<double> *u_expm1_tmb=new TParameter<double> ("u_exbm1", u4lim_exb_m1s);u_expm1_tmb->Write();
     TParameter<double> *u_exp0_tmb=new TParameter<double>  ("u_exb0",  u4lim_exb    );u_exp0_tmb->Write();
     TParameter<double> *u_obs_tmb=new TParameter<double>   ("u_obb",   u4lim_obb    );u_obs_tmb->Write();
     bb.Close();
     */
    done_once=1;
 }
TFile bb("rsl_out.root");
TParameter<double> *kf_expp2, *kf_expm2, *kf_expp1, *kf_expm1, *kf_exp0, *kf_obs;
TParameter<double> *u_expp2, *u_expm2, *u_expp1, *u_expm1, *u_exp0, *u_obs;
TParameter<double> *u_exbp2, *u_exbm2, *u_exbp1, *u_exbm1, *u_exb0, *u_obb;


 switch (opmode) {
   case 99: k=kf_obs->GetVal();    cls_1k=u_obs->GetVal();   clb_1k=u_obb->GetVal()   ;  break;
   case -2: k=kf_expm2->GetVal();  cls_1k=u_expm2->GetVal(); clb_1k=u_exbm2->GetVal() ;  break;
   case -1: k=kf_expm1->GetVal();  cls_1k=u_expm1->GetVal(); clb_1k=u_exbm1->GetVal() ;  break;
    case 0: k=kf_exp0->GetVal();   cls_1k=u_exp0->GetVal();  clb_1k=u_exb0->GetVal()  ;  break;
    case 1: k=kf_expp1->GetVal();  cls_1k=u_expp2->GetVal(); clb_1k=u_exbp2->GetVal() ;  break;
    case 2: k=kf_expp2->GetVal();  cls_1k=u_expp1->GetVal(); clb_1k=u_exbp1->GetVal() ;  break;
 }
 bb.Close();
 tmpcl=target;

//delete u4limit; 
} else if ( Limitter==2 ) { // fast PCL , with or without systematics
 cout << "Doing all in one go with fast PCL. This will potentially be long"<<endl;;
 if (!systerr) gROOT->ProcessLine(".! ../pcl/runpcl.sh 1 ");
 if ( systerr) gROOT->ProcessLine(".! ../pcl/runpcl.sh 4 ");
 TFile bb("pcl_out.root");
 TParameter<double> *b_up2, *b_up1, *b_med, *b_dn1, *b_dn2, *lim_obs;
 switch (opmode) {
        case -2: k=b_up2->GetVal(); break; 
        case -1: k=b_up1->GetVal(); break;
        case  0: k=b_med->GetVal(); break;
        case +1: k=b_dn1->GetVal(); break;
        case +2: k=b_dn2->GetVal(); break;
        case 99: k=lim_obs->GetVal(); break;
  }
 tmpcl=target;
 bb.Close(); 

} else if (Limitter==3) { // MCLimit, with or without systematics
   cout << "Doing all in one go with MCLimit. This will potentially be long"<<endl;;
   TString mclimitrun =".! ../mclimit/runmcl.sh ";
           mclimitrun+=infileo;
           mclimitrun+=" ";
   if (sum_channels){
           mclimitrun+=infilen;
           mclimitrun+=" ";
   } else { 
           mclimitrun+=infileo;
           mclimitrun+=" ";
   }
   if   (!systerr)    mclimitrun+=1; // here we also know if e- or mu
   if   ( systerr)    mclimitrun+=1; //# systematic shapes
   if   (!systerr)    mclimitrun+=" nosyst "; // here we say no errors
   if   ( systerr)    mclimitrun+=" syst "; //systematic error calculation
   mclimitrun+=mcevts;

   gROOT->ProcessLine(mclimitrun);
   TFile bb("mcl_out.root");
   TParameter<double> *b_up2, *b_up1, *b_med, *b_dn1, *b_dn2, *lim_obs;
   TParameter<double> *s1k_up2, *s1k_up1, *s1k_med, *s1k_dn1, *s1k_dn2, *s1k_obs;
   TParameter<double> *b1k_up2, *b1k_up1, *b1k_med, *b1k_dn1, *b1k_dn2, *b1k_obs;
   switch (opmode) {
          case +2: k=b_up2->GetVal(); cls_1k= s1k_up2->GetVal(); clb_1k= b1k_up2->GetVal(); break; 
          case +1: k=b_up1->GetVal(); cls_1k= s1k_up1->GetVal(); clb_1k= b1k_up1->GetVal(); break;
          case  0: k=b_med->GetVal(); cls_1k= s1k_med->GetVal(); clb_1k= b1k_med->GetVal(); break;
          case -1: k=b_dn1->GetVal(); cls_1k= s1k_dn1->GetVal(); clb_1k= b1k_dn1->GetVal(); break;
          case -2: k=b_dn2->GetVal(); cls_1k= s1k_dn2->GetVal(); clb_1k= b1k_dn2->GetVal(); break;
          case 99: k=lim_obs->GetVal(); cls_1k=s1k_obs->GetVal();clb_1k= b1k_obs->GetVal(); break;
    }
   tmpcl=target;
   bb.Close(); 

} else {
  cout << "Limitter undefined, check the ANA_DEFS file"<<endl;
  exit ;
}

// at this point k and tmpcl are calculated.
   epsi_prev=epsi;
   epsi=(target-tmpcl);
   if (!CLs_CLsb && (k==1) && (Limitter==0)) { // we save the measured CLs value for Sinan's CLs plots
    cls_1k=tmpcl;
    clb_1k=tmpclb;
   }
   cout << "begin k="<<k<<"  currentCL="<<tmpcl<<"  epsi="<<epsi<<endl;
   kvec->push_back(k);
   CLvec->push_back(tmpcl);
   if ((fabs(epsi)<err) || (k<1e-4) || (coeff<1e-4)) {
      char filen[128];
      char outtxt[128];

       of << exptxt ;
       of << setprecision(2)<<k;
       switch (sigma)  {
        case -2: sprintf (filen,"LLR_ExpH0M2"); break;
        case -1: sprintf (filen,"LLR_ExpH0M1"); break;
        case  0: if (opmode!=99) {
                  sprintf(filen,"LLR_ExpH0Med"); break;
                 } else {
                  sprintf(filen,"LLR_Meas"); break;
                 }
        case +1: sprintf(filen,"LLR_ExpH0P1"); break;
        case +2: sprintf(filen,"LLR_ExpH0P2"); break;
       }
       sprintf (outtxt,"  %s ",filen);
       of << outtxt;
       of << setprecision(5)<<tmpcl<< " cls1k "<< cls_1k << " clb1k "<< clb_1k<<endl;
#ifdef __DEBUG__
       TCanvas* c2 = new TCanvas();
       c2->SetLogy();
       toplams->SetMaximum( toplamb->GetMaximum()*1E3);
       toplams->SetMinimum( toplamb->GetMaximum()/1E5);
       toplams->SetMarkerStyle(20); toplams->SetMarkerColor(40); toplams->SetLineColor(40); 
       toplamb->SetMarkerStyle(22); toplamb->SetMarkerColor(kBlack); toplamb->SetLineColor(kBlack); 
       toplamq->SetMarkerStyle(21); toplamq->SetMarkerColor(kBlue); toplamq->SetLineColor(kBlue); 
       toplams->Draw("e"); toplamb->Draw("same"); toplamq->Draw("same");
       TLegend *leg  = new TLegend( 0.61, 0.62, 0.97, 0.90 );
       leg->AddEntry(toplams,"signal","lp");
       leg->AddEntry(toplamb,"background","lp");
       leg->AddEntry(toplamq,"total/data","lp");
       leg->Draw();
       sprintf (outtxt,"%d-%s.eps",qm,filen);
       c2->SaveAs(outtxt);
#endif
       epsi=0.0;
   } else {
   // we have to adjust
   if (aaa!=999) { cout << "0 for next step, 999 to continue, -1 to exit"<<endl;
                   cin >> aaa; if (aaa==-1) { exit(1);}
   } 

   if ((epsi_prev/fabs(epsi_prev)) != (epsi/fabs(epsi))) sgnChangeCnt++;
   if (sgnChangeCnt>10) {
     PolFitter P(CLvec,kvec,2);
     P.graph(true);
//   TF1* CLfit = P.fitfunction();
//   P.profile(30,0.,0.4,0.,5.,true);
     TF1* CLfit = P.fitprofile(50,0.,0.7,0.,24.); //(CL , k)
     k=fabs(CLfit->Eval(0.05));
     cout << "FROM FIT.........................................."<<k<<endl;
     sgnChangeCnt=0;
     cout << "Kick to make it converge...................................................."<<endl;
     coeff/=1.5;
   } else {
   if (tmpcl==tmpcl_prev) shit_again++;
  // work in steps of coeff
   if (tmpcl==1) k=k/1.1;
   if (tmpcl==0) { /* cout << "increase by 1.5: k="<<k<<endl; */ k=k+1.5;} 
   else if (tmpcl==tmpcl_prev ) { /* cout<<"decrease by 20%"<<endl; */ k=k/1.2;}
   else if (k<0) k=0.25;
   else if (epsi>0) {
        k=k*(1-coeff);
     } else {
        k=k*(1+coeff);
     }
  
   if (shit_again>20) { cout<< "shit"<<endl; return;}

   }// regular situation, no result from PolFit.

   }
   
   tmpcl_prev=tmpcl;
   toplams->Delete();
   toplamb->Delete();
   toplamq->Delete();
   if (sum_channels) { // read the other lepton channel and add.
     toplams_other->Delete();
     toplamb_other->Delete();
     toplamq_other->Delete();
     bd->Close(); //causes a segfault if called before deleting the _others.
   }
} while ((fabs(epsi)>err) ) ;
  cout << "k="<<k<<"  currentCL="<<tmpcl<<"  epsi="<<epsi<<endl;

of.close();

//////////////////////////////////////////////////////////////////////////////
//  TLimitDataSource* mydatasource = new TLimitDataSource(sigh,bkgh,dath);
//  TConfidenceLevel *myconfidence = TLimit::ComputeLimit(mydatasource,mcevts);
//  cout << setprecision(5)<<"  CLsb   : " << myconfidence->CLsb() << endl;
//  cout << setprecision(5)<<"  CLs    : " << myconfidence->CLs()  << endl;
//  cout << setprecision(5)<<"  CLb    : " << myconfidence->CLb()  << endl;
//  cout << setprecision(5)<<"< CLsb > : " << myconfidence->GetExpectedCLsb_b() << endl;
//  cout << setprecision(5)<<"< CLs >  : " << myconfidence->GetExpectedCLs_b()  << endl;
//  cout << setprecision(5)<<"< CLb >  : " << myconfidence->GetExpectedCLb_b()  << endl;
//  cout << setprecision(5)<<"<CLb>0s  : " << myconfidence->GetExpectedCLb_b(0)  << endl;
//  cout << setprecision(5)<<"<CLb>1s  : " << myconfidence->GetExpectedCLb_b(1)  << endl;
//  cout << setprecision(5)<<"<CLb>2s  : " << myconfidence->GetExpectedCLb_b(2)  << endl;
//  cout << setprecision(5)<<"stats B  : " << myconfidence->GetExpectedStatistic_b(0) << endl;
//////////////////////////////////////////////////////////////////////////////

} 
