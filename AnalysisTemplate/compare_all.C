#define __stacksums__
#define __showsums__
#define __ROOT6__

#include "../AnalysisTemplate/compare.H"
#include "../AnalysisTemplate/CalculateChiSquare.C"
#include "../AnalysisTemplate/prepareSamples.C"
#include "../AnalysisTemplate/CalculateLimits.C"
#include "../AnalysisTemplate/pricontents.C"
#include "../AnalysisTemplate/HistoAutoRange.C"

R__LOAD_LIBRARY(../analysis_core/TStringAddFloat_cpp)


//#define __DEBUG__

// qm = new quark mass [GeV]
// lumi = luminosity in pb-1
// lumi= -1 means read from file=ANA_DEFS but alternatively you can give a value as well.
// skf = signal xsection scale factor
// skf = signal scale factor (bazen sinyali 10 kat felan buyuturuz ki grafiklede gozuksun.
// pset= plot set demek, deyin cizilecegi
// pset = integer representing the plot set we are interested in
// disc = index of the discriminant to use
// disc = get limits or not, if disc is negative, we will simply generate the sibg file and exit
// ratio = data/mc cizdirmek icin 0: cizme, 1:ciz.
//19 all dijetmass histos.txt ,29,35afterChi,34beforeChi,33afterAll
//111,112,113,114,115,121,122,123,124,125,131,132,133,134,135,145,215,225,235,245,345,445,545,645
//111,113,115,121,123,125,131,133,135,145,245,215,235,225,345,445,545,645,716,736,726,916,936,926,1115,1215,955,1025,1026,1016
//20,21,22,23//299,295,298,294,296,292,1115, reweighting histos
//115,117,125,127,135,137,145,147,215,217,225,227,235,237,245,247,545,546
void compare_all( int qm=1200, float lumi=-1, float skf=1, string psetstr="2", int disc=0, int ratio=1, bool saveHist=false, bool printEffs=false, bool saveEffs=false)
{
gROOT->Reset();
gStyle->SetPalette(1);

//	if ( gROOT->GetListOfGlobals()->FindObject("atlasStyle") == 0 ) {
		gROOT->ProcessLine(".x ../analysis_core/rootlogon.C");
		gROOT->SetStyle("ATLAS"); gROOT->ForceStyle();
//	}
//#ifndef __HistoAutoRange__
//	gROOT->LoadMacro("../AnalysisTemplate/HistoAutoRange.C");
//#endif
	bool verbose=true;
	const int measured_limit=(int) ReadCard("ANA_DEFS","OBSERVEDLIMIT",1,0); // 0: dont do, 1: do measured=observed limit calculation
	string btag_txt="uB"; //0B:b-tag veto  1B: 1-btag    uB: untagged

// true or false for the injection test.
	bool injection=false;
	bool log_graphs=(int)ReadCard("ANA_DEFS","LOG_GRAPHS",0,0); // 0:linear, 1:log y scale
	float inj_coef=ReadCard("ANA_DEFS","INJECTION",0,0);
	int ecm=ReadCard("ANA_DEFS","ECM",0,0);
	bool systerr=(int)ReadCard("ANA_DEFS","SYSTERR",0,0);
	if ( inj_coef > 0 ) injection=true;

    float lumi_r9364 = 0.0, lumi_r10201 = 0.0, lumi_r10724 = 0.0; //under construction
// if default, read default lumi from ANA_DEFS file
	if (lumi==-1) {
		lumi=ReadCard("ANA_DEFS","INTLUMI",0,0);
                lumi_r9364=0;
                lumi_r10201=0;
                lumi_r10724=0;
//      lumi_r9364=ReadCard("ANA_DEFS","INTLUMI_r9364",0,0); //under construction
//      lumi_r10201=ReadCard("ANA_DEFS","INTLUMI_r10201",0,0); //under construction
//      lumi_r10724=ReadCard("ANA_DEFS","INTLUMI_r10724",0,0); //under construction
	}

	string modeldir= ReadCardString("ANA_DEFS","MODEL","FF_1",0);
	TString Directory= ReadCardString("ANA_DEFS","DIRECTORY","FF_1",0);
	string sampleFile= "sample-" + modeldir;
	sampleFile+=".txt";
	const int nsamples = ReadCard(sampleFile.c_str(),"SAMPLESIZE",86,0);
	Sample *samples[nsamples];

	const int ntypes = ReadCard(sampleFile.c_str(),"TYPESIZE",14,0);
	SampleType *sampletypes[ntypes];
        cout << "We will have "<< ntypes << " different types made from "<<nsamples<<" samples.\n";



	int CLs_CLsb=(int)ReadCard("ANA_DEFS","STAT",0,0);
	int leptonindex=(int)ReadCard("ANA_DEFS","CHANNEL",0,0);
	TString lepton;
	if (leptonindex==0) lepton="MUON" ;
	if (leptonindex==1) lepton="ELE" ;

// ======================================
// read the files and prepare the samples
// ======================================================================
    cout << "preparation of samples begins:" << endl;
	prepareSamples(qm, lumi, lumi_r9364, lumi_r10201, lumi_r10724, skf, samples, nsamples, sampletypes, ntypes);
	cout <<"data, signal and background samples ready ntypes:"<< ntypes<<endl;

  int  nparams=20; // gokhan being lazy here 
  int *ipset;
       ipset=(int *)malloc(nparams*sizeof(int));  
   

   if ( decode_ints(&nparams, psetstr, ipset) ){
     cout << "ERROR: Can NOT decode plot set string\n";
     exit (2);
   }
  const int nplots=nparams;
  TCanvas *c1[nplots];

  for (int kplot=0; kplot<nplots; kplot++) // loop over the list of plots to be made
  {
        int pset=ipset[kplot];
        int nvars=ReadCard("compare.dat", (TString::Format("PSET%d",pset)).Data()  ,0,0);
	if (nvars==0) {
		cout << "Variable set undefined, pset should be: "<<endl;
                gSystem->Exec("grep \"PSET\" compare.dat|awk \'{print $1}\' ");
		exit (1);
	}
	   string vars[nvars];			
           //vars=(string *)calloc(40*nvars, sizeof(char));  // a variable can have a max of 40 chars
        int    *rebin, *smooth;
         float *minmax;
          char *opt;
               opt=(char *)malloc(nvars*sizeof(char));
             rebin=(int *)malloc(nvars*sizeof(int));
            smooth=(int *)malloc(nvars*sizeof(int));
            minmax=(float *)malloc(2*nvars*sizeof(float));
      string astr;
      astr=ReadCardString("compare.dat",(lepton+(TString::Format("%d",pset))).Data(),"ERROR",0);
      decode_strs(&nparams, astr, vars);
      astr=ReadCardString("compare.dat",(TString::Format("rebin%d",pset)).Data(),"ERROR",0);
      decode_ints(&nparams, astr, rebin);
      astr=ReadCardString("compare.dat",(TString::Format("minmax%d",pset)).Data(),"ERROR",0);
      if (astr!="ERROR") { decode_floats(&nparams, astr, minmax);
      } else{ for (int pippo=0; pippo<2*nvars; pippo++) minmax[pippo]=0.0;
      } 
/*
      astr=ReadCardString("compare.dat",(TString::Format("smooth%d",pset)).Data(),"ERROR",0);
      decode_ints(nvars, astr, smooth);
      astr=ReadCardString("compare.dat",(TString::Format("opt%d",pset)).Data(),"ERROR",0);
      decode_chars(nvars, astr, opt);
*/
      for (int j=0; j<nvars; j++) {opt[j]=1; smooth[j]=0;} //disable
      
// ======================================================================
//now create the list of histograms we want plotted.

	PlotHistos ph = {vars, rebin, smooth, opt, minmax}; //FIXME
	TH1 *histos[__MAXNSMPLS__][__MAXNVARS__];

        cout << "we can start plotting w/"<<ntypes <<"\n";	
      int signals[4] = {9,10,7,8};
      int smbg[1] = {0};
    // **************************************
    if (ratio == 1) {
        c1[kplot] = compare(samples, nsamples, sampletypes, ntypes, histos, ph, nvars, "", "", 0,1,kplot);
    } if (ratio == 2) {
       // c1[kplot] = compare(samples, nsamples, sampletypes, ntypes, histos, ph, nvars, "", "",signals,1,kplot);
    } else {
    //    c1[kplot] = compare(samples, nsamples, sampletypes, ntypes, histos, ph, nvars, "", "",smbg,-1,kplot);
    }
      cout << "plotting is done" << endl;

/*  THE BELOW IS AN EXAMPLE ON HOW TO MANUALLY IMPOSE DIFFERENT HISTOGRAM RANGES.
*/
	float ymax0,ymax1;
	float yscale=2.0;
	if (log_graphs) yscale=3;
	if (nvars>1) for (unsigned i=0; i<ntypes; ++i) {
		for (unsigned jk=0; jk<nvars; jk++) {
			if (histos[i][jk]!=0 ) {
				histos[i][0]->SetYTitle("");
				ymax0 = histos[i][jk]->GetBinContent(histos[i][jk]->GetMaximumBin());
					histos[i][jk]->GetYaxis()->SetRangeUser(1, ymax0*yscale);
			}
		}
	}

	cout  <<"~~~~~~~~ 1 should we add QCD?"<<endl;

/*
	Double_t error ;
	for (unsigned i=0; i<nvars; i++) {
		// Histos[6] is sum of histos to be shown with error bars, to be updated.
		// Histos[5] is the QCD sample with correct error bars.
		if ( histos[5][i] != NULL )
			//histos[5][i]->Draw();
			for (int bin=0;bin<histos[5][i]->GetNbinsX(); bin++) {
				error = histos[5][i]->GetBinError(bin);
				histos[6][i]->SetBinError(bin,error);
			}
	}
*/

        if (printEffs || saveEffs ) {
             for (int kType=0; kType<ntypes; kType++)
                PrintTypeEfficiency( sampletypes[kType], samples, printEffs, saveEffs);  cout << endl;
        }


// compatibility tests : 0 has data and 1 all bg samples added
	Double_t *kst;     kst=(Double_t *)malloc(nvars*sizeof(Double_t));
	Double_t *chi2ndf; chi2ndf=(Double_t *)malloc(nvars*sizeof(Double_t));

	for (unsigned i=0; i<nvars; i++) {
                chi2ndf[i]=0;
		if (histos[1][i]->InheritsFrom("TH2F"))  continue;
		// ROOT's own chi2 and our implementation (add OF to include overflows)
		  ((TH1F*)histos[1][i])->Chi2Test(histos[0][i],"P");
		  chi2ndf[i]=0.0;
		chi2ndf[i]=CalculateChiSquare( (TH1F*)histos[1][i], (TH1F*)histos[0][i]);
		// ROOT's kolmogorov test add the X option for toyMCs and D for debug
//		  kst[i]=0.0;
//		  kst[i]=((TH1F*)histos[1][i])->KolmogorovTest(histos[0][i],"O"));
	}


// loop over all variables, plots and make it nice.

	c1[kplot]->SetWindowSize(1100,740);
	for (unsigned i=1; i<=nvars; i++) {

		TVirtualPad *subpad = (TVirtualPad*)c1[kplot]->cd(i);
		if (ratio) {
			TVirtualPad *subsubpad = subpad->cd(1);
			if (log_graphs) { subsubpad->SetLogy(1); } else { subsubpad->SetLogy(0);}
		} else {
			if (log_graphs) { subpad->SetLogy(1); } else { subpad->SetLogy(0);}
		}

// niceties
		TLatex lLumi;
		lLumi.SetNDC();
		char tmp[32];
		TString TsLumi = "L=";
		        TsLumi += TString::Format("%2.1f",lumi/1E3);
		        TsLumi +=" fb^{-1}";
		float location= 0.77;
		lLumi.DrawLatex( location,0.70,TsLumi);
		if ( ecm == 8 ) {
			lLumi.DrawLatex( location,0.66,"#sqrt{s}=8 TeV");
		}
		if ( ecm == 13 ) {
			lLumi.DrawLatex( location,0.66,"#sqrt{s}=13 TeV");
		}
//		lLumi.SetTextSize(0.1);

//              TString TsKS = "KS Prob.=";
//                      sprintf(tmp, "%.2f", kst[i-1]);
//                      TsKS += tmp;
//              lLumi.DrawLatex( 0.46,0.60,TsKS);

/*
                if (chi2ndf[i-1] > 0){
        	   TString TsChi2ndf = "#chi^{2}/ndf=";
        	   sprintf(tmp, "%.2f", chi2ndf[i-1]);
        	   TsChi2ndf += tmp;
        	   lLumi.DrawLatex( 0.46,0.49,TsChi2ndf);
        	   cout << "chi2="<<TsChi2ndf<< endl;
                }
*/
	}

	c1[kplot]->Update(); // force y-scale settings
	cout  <<"~~~~~~~~ 3 should we calculate a chi2 or KS test for data-mc comparison?"<<endl;
	//HistoAutoRange();
	//HistoAutoLogScale();

// Save the canvas
        TString fn="comp-";
        fn += pset; fn+="-"; fn+=leptonindex; fn+="-"; fn+=qm; fn+="-"; fn+=modeldir; fn+=".pdf";
        c1[kplot]->SaveAs(fn);


// --------------------------------prepare si bg and data files.
	// now do we need to do run statistics test or not ?
	if ( disc != 0 ) { // if disc is negative, we will simply generate the sibg file and exit
		// statistical studies
		int Limitter=(int)ReadCard("ANA_DEFS","LIMITTER",0,0);  // 0: TLimit, 1:RSLimit, 2:fastPCLimitter 3:mclimit...
		cout << "Will Calculate Limits with:"<<Limitter<<endl;
		TH1* toplams = (TH1*)(histos[7][abs(disc)-1])->Clone();  // signal MC do not rely on "5" read it from model file
		TH1* toplamb = (TH1*)(histos[1][abs(disc)-1])->Clone();  // total SM bg   do not rely on "5" read it from model file
		TH1* toplamq; // this will host the data or pseudodata
		     toplamq = (TH1*)(histos[0][abs(disc)-1])->Clone();  // data is always the 0th type.

		if (injection) {
                TH1* toplami = (TH1*)(histos[0][abs(disc)-1])->Clone();  // signal to inject is the pseudodata from ANAdefs
		cout<<"injection will start with coef:"<< inj_coef<<endl;
		     toplamq = (TH1*)(histos[1][abs(disc)-1])->Clone();  // start with the SMBG
		     toplami->Scale(inj_coef);                      // inject coef*signal, into pseudodata
		     toplamq->Add(toplami, 1);                      // inject coef*signal, into pseudodata
		if (1) {
			TCanvas *sp = new TCanvas ("Testinj","Testinj"); 
			sp->cd(); sp->SetLogy();
			toplamq->SetLineColor(3); toplamq->Draw();
			toplamb->SetLineColor(4); toplamb->Draw("same");
			toplami->SetLineColor(2); toplami->Draw("same");
			toplams->SetLineColor(1); toplams->Draw("same");
                        ymax0 = toplamq->GetBinContent(toplamq->GetMaximumBin());
                        toplamq->GetYaxis()->SetRangeUser(1.,ymax0*yscale);
                        toplamq->GetXaxis()->SetRangeUser(0.,1600.);

                        TLegend *leg = new TLegend(0.4,0.80,0.94,0.93);
                        leg->SetFillStyle(0);
                        leg->AddEntry(toplamb, "SM bg", "lp");
                        leg->AddEntry(toplami, "injected signal", "lp");
                        leg->AddEntry(toplams, "expected signal", "lp");
                        leg->AddEntry(toplamq, "pseudo data", "lp");
                        leg->SetShadowColor(0);
                        leg->SetFillColor(0);
                        leg->SetMargin(0.4);
                        leg->SetBorderSize(0);
                        leg->SetNColumns(3);
                        leg->Draw();
			c1[kplot]->Update();
                        sp->SaveAs("Testinj.pdf");
		}
		} //this is the injection study stuff.

///////////////// write file with si, bg, data
			TFile bb("sibg.root","recreate");
			if (toplamq!=0)  toplamq->Write("data");
			if ( !systerr ) {  // no systematics
				cout << "no systematics included"<<endl;
				TParameter<double> *tp1=new TParameter<double> ("uncert_1", 0.01,'f'); tp1->Write();
				TParameter<double> *tp2=new TParameter<double> ("uncert_2", 0.01,'f'); tp2->Write();
				TParameter<double> *tp3=new TParameter<double> ("uncert_3", 0.01,'f'); tp3->Write();
				TParameter<double> *tp4=new TParameter<double> ("uncert_4", 0.01,'f'); tp4->Write();
				TParameter<double> *tp5=new TParameter<double> ("uncert_5", 0.01,'f'); tp5->Write();
				toplams->Write("signal");
// typeId-2= Z+jets typeId-3= dibosons typeId-4= ttbar typeId-5= singletop typeId-6= ttbarV
                                histos[2][abs(disc)-1]->Write("sample_1");
                                histos[3][abs(disc)-1]->Write("sample_2");
                                histos[4][abs(disc)-1]->Write("sample_3");
                                histos[5][abs(disc)-1]->Write("sample_4");
                                histos[6][abs(disc)-1]->Write("sample_5");
                                histos[7][abs(disc)-1]->Write("signal600");
                                histos[8][abs(disc)-1]->Write("signal700");
                                histos[9][abs(disc)-1]->Write("signal800");
                                histos[10][abs(disc)-1]->Write("signal900");
                                histos[11][abs(disc)-1]->Write("signal1000");
                                histos[12][abs(disc)-1]->Write("signal1100");
                                histos[13][abs(disc)-1]->Write("signal1200");
                                histos[14][abs(disc)-1]->Write("signal1400");
                histos[15][abs(disc)-1]->Write("signal600HjZj");
                histos[16][abs(disc)-1]->Write("signal600WjZj");
                histos[17][abs(disc)-1]->Write("signal600ZjZj");

                histos[18][abs(disc)-1]->Write("signal700HjZj");
                histos[19][abs(disc)-1]->Write("signal700WjZj");
                histos[20][abs(disc)-1]->Write("signal700ZjZj");

                histos[21][abs(disc)-1]->Write("signal800HjZj");
                histos[22][abs(disc)-1]->Write("signal800WjZj");
                histos[23][abs(disc)-1]->Write("signal800ZjZj");

                histos[24][abs(disc)-1]->Write("signal900HjZj");
                histos[25][abs(disc)-1]->Write("signal900WjZj");
                histos[26][abs(disc)-1]->Write("signal900ZjZj");

                histos[27][abs(disc)-1]->Write("signal1000HjZj");
                histos[28][abs(disc)-1]->Write("signal1000WjZj");
                histos[28][abs(disc)-1]->Write("signal1000ZjZj");

                histos[30][abs(disc)-1]->Write("signal1100HjZj");
                histos[31][abs(disc)-1]->Write("signal1100WjZj");
                histos[32][abs(disc)-1]->Write("signal1100ZjZj");
                
                histos[33][abs(disc)-1]->Write("signal1200HjZj");
                histos[34][abs(disc)-1]->Write("signal1200WjZj");
                histos[35][abs(disc)-1]->Write("signal1200ZjZj");

                histos[36][abs(disc)-1]->Write("signal1400HjZj");
                histos[37][abs(disc)-1]->Write("signal1400WjZj");
                histos[38][abs(disc)-1]->Write("signal1400ZjZj");
			} else {
				cout << "WITH systematics ..."<<endl;
				// as a convention we can add the modelname if data histogram is null=> these are systematics
				// read the modelname from the card...
				TString bkg_str[6]; 
                                TString sig_str="signal";
                                for (int ksyst=1; ksyst<=6; ksyst++) {bkg_str[ksyst-1]="sample_"; bkg_str[ksyst-1]+=ksyst;}
				// tokenize the string to write only the bg id and sub_sample_id when writing the systematics
				//if ( toplamq == 0 ) 
                                {	
				        TString Directory= ReadCardString("ANA_DEFS","DIRECTORY","FF_1",0);
					TString add_str="_syst_";
					Ssiz_t from = 0; TString act, tok; int count=0;
					do {
						if (!Directory.Tokenize(act, from, "_")) {
							cout  << "finished with:"<< act<<endl;
						}
						count++;
						if (count==3 ) {int j3=act.Atoi(); add_str+=j3; add_str+="_";}
						if (count==5 ) {
							TString tmp_act = act[act.Sizeof()-3];
							if( tmp_act.Atoi() > 0 ) add_str+=act[act.Sizeof()-3];  //This line allows us to get systematics with the 2nd decimal
							add_str+=act[act.Sizeof()-2];
						}

					} while ( act.Sizeof()>1   );
					if (count<4) add_str="";

                                        for (int ksyst=1; ksyst<=6; ksyst++) {bkg_str[ksyst-1]+=add_str;}
					sig_str+=add_str;
				}
				toplams->Write(sig_str);
                                for (int ksyst=1; ksyst<=5; ksyst++) {
                                    histos[ksyst+1][abs(disc)-1]->Write( bkg_str[ksyst-1] );
                                }

				// parameters.
				TParameter<double> *tp1=new TParameter<double> ("uncert_1", ReadCard("xsections.txt","bg13-1stat",0,0),'f');
				TParameter<double> *tp2=new TParameter<double> ("uncert_2", ReadCard("xsections.txt","bg13-2stat",0,0),'f');
				TParameter<double> *tp3=new TParameter<double> ("uncert_3", ReadCard("xsections.txt","bg13-3stat",0,0),'f');
				TParameter<double> *tp4=new TParameter<double> ("uncert_4", ReadCard("xsections.txt","bg13-4stat",0,0),'f');
				TParameter<double> *tp5=new TParameter<double> ("uncert_5", ReadCard("xsections.txt","bg13-5stat",0,0),'f');
				cout << "TP: "<<tp1->GetVal()<<" "<<tp2->GetVal()<< endl;
				tp1->Write();
				tp2->Write();
				tp3->Write();
				tp4->Write();
				tp5->Write();
			} // end of systematics --- we use it now..

			bb.Close();
			// copy the sibg file
			TString cp_root_file =".! cp sibg.root sibg_";
			cp_root_file+=lepton;
			cp_root_file+="_";
			cp_root_file+=qm;
			cp_root_file+="_";
			cp_root_file+=pset;
			cp_root_file+="_";
			cp_root_file+=abs(disc);
            //cp_root_file+="_";
            //cp_root_file+=modeldir;
			cp_root_file+=".root";
			// save or not depending on user input.
			// delete the previous output file if needed.
			if (saveHist) gROOT->ProcessLine(cp_root_file);

			if ( disc > 0 ) {
				if ( Limitter==2 ) {
					gROOT->ProcessLine(".! rm -f fpcl.out"); //delete the previous output file if needed.
				}
				if ( Limitter==3 ) {
					gROOT->ProcessLine(".! rm -f mclimit.out"); //delete the previous output file if needed.
				}
                                cout << "Limit Calculation. Please be patient...\n";
/*
				CalculateLimits(toplams,toplamb,toplamq, qm, -2, lepton, btag_txt, pset, disc);
				CalculateLimits(toplams,toplamb,toplamq, qm, -1, lepton, btag_txt, pset, disc);
				CalculateLimits(toplams,toplamb,toplamq, qm,  0, lepton, btag_txt, pset, disc);
				CalculateLimits(toplams,toplamb,toplamq, qm, +1, lepton, btag_txt, pset, disc);
				CalculateLimits(toplams,toplamb,toplamq, qm, +2, lepton, btag_txt, pset, disc);
				if (measured_limit)  CalculateLimits(toplams,toplamb,toplamq, qm, 99, lepton, btag_txt, pset, disc);
*/
			} //end of disc > 0 : really calculate


	} // end of discriminent 0 or not

} // end of k-plot list

}

