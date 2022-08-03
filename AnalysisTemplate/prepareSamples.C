#include "../AnalysisTemplate/compare.H"
#include "TString.h"
#include "TRegexp.h"

R__LOAD_LIBRARY(../analysis_core/ReadCardCINT_C);
R__LOAD_LIBRARY(../analysis_core/TStringAddFloat_cpp);


float nxs(TString ps,       TString sample) { return ReadCard( TString(ps+ TString::Format("%s","xsectionsEdited.txt")).Data(),sample); }
float sumOfWeights(TString ps, TString sample) { return ReadCard( TString(ps+ TString::Format("%s","sumOfWeights.txt")).Data(),sample); }

float xs(string sample) { float xsl=ReadCard("xsections.txt",sample.c_str(),0,0);
    //cout <<"Reading:"<<sample<<"\n";
    if (xsl==0) cout << "Warning! Xsection is ZERO (0)\n";
    return xsl;
}
//##############################################################3
string sampleName(string modeldir, int i, string info="N") {
    string file="sample-" + modeldir;
    file += ".txt";
    string sample = Form("sampleId-%d-",i);
    sample += info;
    
    string astr=ReadCardString(file.c_str(),sample.c_str(),"Error",0);
    if (astr=="Error") {
        int leptonindex=(int)ReadCard("ANA_DEFS","CHANNEL",0,0);
        sample = Form("sampleId-%d-",i);
        sample += info;
        if (leptonindex == 1) {
            sample +="e";
        } else {
            sample +="m";
        }
        astr=ReadCardString(file.c_str(),sample.c_str(),"Error",0);
    }
    return astr;
}

string typeName(string modeldir, int i, string info="N") {
    string file="sample-" + modeldir;
    file += ".txt";
    string sample = Form("typeId-%d-",i);
    sample += info;
    
    return	ReadCardString(file.c_str(),sample.c_str(),"Error",0);
}
int typeValue(string modeldir, int i, string info="Rmin") {
    string file="sample-" + modeldir;
    file += ".txt";
    string sample = Form("typeId-%d-",i);
    sample += info;
    return	ReadCard(file.c_str(),sample.c_str(),0,0);
}

void prepareSamples(int qm=350, float lumi=0.0, float lumi_r9364=0.0, float lumi_r10201=0.0, float lumi_r10724=0.0,float skf=1.0, Sample **samples=NULL, int nsamples=1,  SampleType **type=NULL, int ntypes=1 )
{
    if ( gROOT->GetListOfGlobals()->FindObject("atlasStyle") == 0 ) {
        gROOT->ProcessLine(".x ../analysis_core/rootlogon.C");
        gROOT->SetStyle("ATLAS"); gROOT->ForceStyle();
    }
    string modeldir= ReadCardString("ANA_DEFS","MODEL","FF_1",0);
    string MCmodeldir= ReadCardString("ANA_DEFS","DIRECTORY",modeldir.c_str(),0);

    string sffx = ".root";   // file suffix for all files
    string pffx ;
    
    string datafilename;
    string qcdfilename ;
    int leptonindex=(int)ReadCard("ANA_DEFS","CHANNEL",0,0);
    if (leptonindex==0) { datafilename=ReadCardString("ANA_DEFS","DATAF_m","deneme",0);
        pffx=ReadCardString("ANA_DEFS", "MCD_m", "9", 0);
    }
    if (leptonindex==1) { datafilename=ReadCardString("ANA_DEFS","DATAF_e","deneme",0);
        pffx=ReadCardString("ANA_DEFS", "MCD_e", "8", 0);
    }
    pffx+="/";
    qcdfilename+=datafilename;
    qcdfilename+="_unc.root" ; // QCD

    if (datafilename.find("data") != std::string::npos || 1 ) { // NGU##########
        datafilename+=".root"    ;
        samples[0] = new Sample( datafilename.c_str(),    MCmodeldir,  kBlack, -1, 0 ); //data -1: no SF and 0: no smooth
    } else {
        std::string subdelimiter = "/";
        size_t apos=datafilename.find(subdelimiter);
        std::string subtoken1;
        subtoken1 = datafilename.substr(apos+subdelimiter.length(),std::string::npos); //
        cout << "You are injecting :"<<datafilename<<"   XS from:"<<subtoken1<<endl;
        float injcoef=lumi*xs(subtoken1);
        datafilename+=".root"    ;
        samples[0] = new Sample( datafilename.c_str(),    modeldir,  kBlack, injcoef, 0 ); //data
    }
    samples[1] = new Sample( datafilename.c_str(),     MCmodeldir,  kBlack, -1 );//QCD and uncertainty NGUUUUUUU
    cout<<"Lumi: "<<lumi<< " nsamples: "<<nsamples<<endl;
    
    //example
    //    samples[ 28] = new Sample( pffx+"410501"+sffx,"E62_1", kRed  ,lumi/xsCorree("410501")*xs("410501") ); //ttbar
    cout << "we can start looping over samples" << endl;
    for(int loop=2; loop<nsamples-2;loop++)
    {
        string sampleRunNo=sampleName(modeldir,loop,"F");
 /////       cout << "Loop:"<<loop << "  "<< pffx<<sampleRunNo<<"\n";
        std::string delimiter = "_";
        std::string token1 = sampleRunNo.substr(1, sampleRunNo.find(delimiter));
        std::string token2 = sampleRunNo.substr(2, sampleRunNo.find(delimiter));

        if (token1 == "r9364"  || token2 == "r9364"  )  lumi=lumi_r9364;
        if (token1 == "10201"  || token2 == "r10201" )  lumi=lumi_r10201;
        if (token1 == "r10724" || token2 == "r10724" ) lumi=lumi_r10724;
        
        if (sumOfWeights(pffx, sampleRunNo) == 0) {
            MCmodeldir=modeldir;
            cout << "SumOfWeights is ZERO, MC dir is: " << MCmodeldir << ". new Weight:"<< sumOfWeights(pffx, sampleRunNo) << endl;
            samples[ loop] = new Sample( pffx+sampleRunNo+sffx, MCmodeldir, kBlack, lumi*(nxs(pffx, sampleRunNo) / (sumOfWeights(pffx, sampleRunNo)) ) ); //renorm
            cout <<"Sample:"<< loop << " SRno:"<< sampleRunNo << " "<< lumi*(nxs(pffx, sampleRunNo) / (sumOfWeights(pffx, sampleRunNo) ) ) <<" ok\n";
        } else {
            samples[ loop] = new Sample( pffx+sampleRunNo+sffx, MCmodeldir, kBlack, lumi*(xs(sampleRunNo) / (sumOfWeights(pffx, sampleRunNo)) ) ); //renorm
#ifdef __VERBOSE
            cout << "loop number is: " << loop << endl;
            cout << "sample runno is: " << sampleRunNo << endl;
            cout << "lumi is: " << lumi << endl;
            cout << "xs is: " << xs( sampleRunNo) << endl;
            cout << "sumofweighted events is: " << sumOfWeights(pffx, sampleRunNo) << endl;
            cout << "xs is: " << nxs(pffx, sampleRunNo) << endl;
            cout << "sumofweighted events is: " << sumOfWeights(pffx, sampleRunNo) << endl;
            cout <<  lumi*(nxs(pffx, sampleRunNo) / (sumOfWeights(pffx, sampleRunNo) ) ) << endl;
#endif
            //cout << loop << " "<< sampleRunNo << " "<< lumi << " " << nxs(pffx, sampleRunNo) << " " << sumOfWeights(pffx, sampleRunNo) << " " <<  lumi*(nxs(pffx, sampleRunNo) / (sumOfWeights(pffx, sampleRunNo) ) ) <<" ok\n";
        }
    }
    cout <<"loop ends...\n";

// qm contains the index
    TString sigtype=sampleName(modeldir,qm,"TTS");

    samples[nsamples-2] = new Sample( pffx+sigtype.Data()+sffx, MCmodeldir, kRed, skf*lumi*xs(sigtype.Data())/(sumOfWeights(pffx, sigtype.Data())) ); //signal MC
//    cout << nsamples-2<<" Signal MC is from :" << pffx+sigtype.Data() +sffx<<endl;
    samples[nsamples-1] = new Sample( pffx+ sigtype.Data()+sffx, MCmodeldir, kRed , skf*lumi*xs(sigtype.Data())/ (sumOfWeights(pffx, sigtype.Data())) ); //the SAME signal MC to inject in injection tests
    
    // ALL SAMPLES ARE NOW READ.
    // The functionality to make groups of samples.
    
    cout<<"Starting BG defs"<<endl;
    string CARDNAME = "sample-"+modeldir+".txt";
    for (int typeL=0; typeL<ntypes ; typeL++)
    {
        string atype=typeName(modeldir,typeL,"N");
#ifdef __VERBOSE__
        cout << typeL << " atype is " << atype << endl;
#endif
        type[typeL] = new SampleType(atype);
        type[typeL]->SetDrawable( typeValue(modeldir,typeL,"Drawable")  ); // draw or not
        type[typeL]->SetForcedStyle(  typeName(modeldir,typeL,"Style")  ); // style
        
        int Rmin = 0, Rmax=0;
        int Typesa=0, Typesb=0;
        if ((typeL > 0) && (atype != "aQCD") && (atype!="Uncert"))  { // data and QCD are not user modifiable
            Rmin = typeValue(modeldir,typeL,"Rmin");
            Rmax = typeValue(modeldir,typeL,"Rmax");
            if (Rmin == 0 && Rmax == 0) { Typesa = typeValue(modeldir,typeL,"Typesa"); cout << Typesa << endl;
                Typesb = typeValue(modeldir,typeL,"Typesb");
            }
        } else if (atype == "aQCD" || atype == "Uncert") {Rmin=1; Rmax=1;}
        
        if ( Rmin < 0 ) Rmin = Rmin + nsamples;
        if ( Rmax < 0 ) Rmax = Rmax + nsamples;
#ifdef __VERBOSE__
        cout<<atype <<" ID: "<<typeL<<" has samples:"<<Rmin<<" - "<<Rmax<<endl;
#endif
        if( Rmin == Rmax )  type[typeL]->Add(Rmin);
        /*if (Rmin == 0 && Rmax == 0 && Typesa != 0) {
            size_t n = std::count(Types.begin(), Types.end(), ',');
            n=n++;
            for (int j=0; j < n; j++ ) {
                string token = Types.substr(j, Types.find(','));
                
                type[typeL]->AddType(type[j]);
            }*/
            /*cout << "do you enter here?" <<  endl;
            cout << "Typesa is: " << Typesa << " Typesb is: " << Typesb << endl;
            string xtype=typeName(modeldir,Typesa,"N");
            string ytype=typeName(modeldir,Typesb,"N");
            type[typeL]->AddType(SampleType[xtype]);
            type[typeL]->AddType(SampleType[ytype]);
        }*/
        else type[typeL]->AddRange(Rmin,Rmax);
        if( atype =="signal") {TString myl="signal x"; myl+=skf; type[typeL]->SetLeg(myl.Data()); }
        
    }
    cout<<"End BG defs. nTYPES:"<<ntypes <<endl;
    
}
