// compare.h - a code to plot multiple variables from multiple sources
// Contains two classes:
// Sample - a sample from a single TFile containing the efficiency histogram,
//    also its xsection, preferred drawing color and whether it is smoothable.
//    (By default all samples are smoothable, but if you prefer that no
//    histogram drawn of the chosen sample to be ever Smooth()ed by compare(),
//    set smoothable to false.)
// SampleType - a class to handle collections of Samples. It has a name, a
//    vector of integers which one can use to address individual items from
//    a Sample array (this should be done by the enduser), and a boolean
//    to indicate whether this SampleType is to be drawn or not.
// It also contains the compare() function, which uses these classes for
//    smart drawing everything. Its behavior is controlled by a few C
//    preprocessor macros:
//    __singlelegend__ : Only one legend drawn (otherwise one legend per pad)
//    __unitarea__ : Everything drawn normalized to unit area
//    __showsums__ : Plot the SampleTypes and not the Samples.
//    __stacksums__: Plot a stack plot of SampleTypes and not individually.
//    Note that __stacksums__ is useless if you have <=1 SampleTypes. It is
//    most useful when you have a total background SampleType and a total
//    signal SampleType.
// In order to provide a list of histograms that you want to have plotted,
//    you need to feed in a PlotHistos object, and the total number of histos
//    into the compare() function. An example (nvars and ph) is here:
//    const int nvars = 3; string vars[nvars]={"h1","h2"};
//    int rebin [nvars]={1,1}, smooth[nvars]={0,0};
//    char opt  [nvars]={1,'x'};  //NGU minmax to be added
//    PlotHistos ph = {vars, rebin, smooth, opt, minmax};
// The smooth array can contain negative numbers, in which case the
//    experimental SmartSmooth() function will try to determine automatically
//    if it is worth smoothing the histogram.
// Two other useful functions are PrintTypeEfficiency(), which properly weights
//    the efficiencies extracted from each Sample to give you the correct
//    efficiency for a SampleType, and CheckTypeConsistency(), which checks
//    that all samples of a SampleType have the same eff histogram structure,
//    ie. that they were prepared with exactly the same cuts applied.

#ifndef __COMPARE_H__
#define __COMPARE_H__

// compare.H no longer calls #include<vector> by default. It is not needed
//    in recent ROOT versions (like 5.26), costs about 250-300ms!,
//    and re-including compare.H with that statement causes warnings.
//#include <vector>  // uncomment if using old ROOT versions
#include <string>
#include <iomanip>
#include "TFile.h"
#include "TCanvas.h"
#include "TMath.h"

#define __MAXNVARS__ 20
#define __MAXNSMPLS__ 99  // Also the max number of types allowed

#define __MAXNGOOD__ 10
int goodcolors[__MAXNGOOD__]={kBlack,kCyan,kRed,kBlue,kYellow,kGreen,kMagenta-8, kBlue-6,1,42};
int goodstyles[__MAXNGOOD__]={1,1,1,1,1,1,1,1,2,1};


class SampleType {
private:
    string m_name;
    string  m_leg;
    vector<int> m_components;
    bool m_drawable;
    string m_ForcedStyle;
public:
    SampleType(string samplename) { m_name=samplename; m_drawable=true; m_ForcedStyle=""; m_leg="xxx";}
    void SetLeg(string alegend) { m_leg=alegend;}
    void Add(int sampleno) { m_components.push_back(sampleno); }
    void AddRange(int samplenomin, int samplenomax) {
        for (int i=samplenomin; i<=samplenomax; ++i) Add(i);
    }
    void AddType(SampleType *subsample) {
        for ( int i=0; i<subsample->m_components.size(); ++i)
            m_components.push_back( subsample->m_components[i] );
    }
    bool Contains(int sampleno) {
        for ( int i=0; i<m_components.size(); ++i)
            if ( m_components[i]==sampleno ) return true;
        return false;
    }
    TString GetName() { return m_name; }
    const char* GetLeg() { return m_leg.c_str(); }
    void SetDrawable(bool drawable=true) { m_drawable=drawable; }
    void SetForcedStyle(string ForcedStyle="e1") { m_ForcedStyle=ForcedStyle; }
    string GetForcedStyle() { return m_ForcedStyle; }
    bool IsDrawable() { return m_drawable; }
    void CopyComponentList(vector<int> &list) {
        for ( int i=0; i<m_components.size(); ++i)
            list.push_back( m_components[i] );
    }
};


class Sample {
private:
    TFile *m_file;
    TDirectory *m_dir;
    bool m_real;
public:
    unsigned int histcol;
    float xsec;
    bool smoothable;
    // Note: here xsec is really the number of expected events for the sample
    Sample(string filename="", string dirname="", unsigned int color=0, float crosssec=-1 , bool issmoothable = true) {
        m_file = new TFile(filename.c_str());
        m_dir = new TDirectory();
        if (gDirectory->Get(dirname.c_str())!=0) m_file->cd(dirname.c_str());
        m_dir = gDirectory;
        histcol = color;
        xsec = crosssec;
        smoothable = issmoothable;
        if ( crosssec<0 && issmoothable ) {
            cout << "Warning, issmoothable cannot be true for xsec<0, overwriting!\n";
            issmoothable = false;
        }

        TH1F *eff = (TH1F*)(m_dir->Get("cutflow"));
        if ( eff != 0 ) {
            m_real=true;
            // if (  eff->GetBinContent(0) != 0 )  // generator-level cut eff.
            // xsec *= ( eff->GetBinContent(2) / eff->GetBinContent(0) );
            // cout << "Scaling factor = " << GetScaleFactor() << endl;
            //I, berare, really don't understand the physical meaning of this piece of code, this is why I am commenting it out.
            /*if ( xsec > eff->GetBinContent(2) )
                cout << "Warning! Your expected number of events = " << xsec << " > "
                << eff->GetBinContent(2) << " = # of events in "
                << filename << "\n"; */
        } else {
            m_real=false;
            cout << "\nError!!! Something wrong with " << filename << " for dir:"<< dirname.c_str()<< " !!!\n";
        }
    }
    ~Sample() { m_file->Close(); delete m_file; }
    TObject *Get(TString histoname) {  if (m_real) { return m_dir->Get(histoname); } else {
        return NULL;  }
    }
    const char* GetName() { return m_file->GetName(); }
    const char* GetTitle() {
        if (strcmp(m_file->GetTitle(),"")) return m_file->GetTitle();
        else return GetName();
    }
    const double GetScaleFactor() {
        if ( xsec == -1  ) return 1;
        else if ( xsec <0  ) return fabs(xsec);

        if ( m_dir->Get("cutflow") == 0 ) {
            cout << "***** Could not get the eff histogram for " << GetName()
            << " - returning 0 as scale factor! *****" << endl;
            return 0; }
        //return xsec / ((TH1F*)(m_dir->Get(cutflow")))->GetBinContent(2);
        return xsec;
    }
};

struct PlotHistos {
    string *vars;  // name of histogram as it appears in the root file
    int  *rebin;   // rebinning factor
    int *smooth;   // smoothing factor
    char   *opt;   // drawing option interpreted by compare().
    float *minmax; // drawing from to given by compare().
};


unsigned int DivideCanvas(TCanvas *canvas, unsigned int npads) {
    unsigned int xdiv=1, ydiv=1;
    for (;;) {
        if (npads<=xdiv*ydiv ) break; xdiv++;
        if (npads<=xdiv*ydiv ) break; ydiv++; }
    canvas->Divide(xdiv,ydiv,1e-4,1e-4);
    return ydiv; // return number of rows
}

bool CheckTypeConsistency(SampleType *type, Sample **samples) {

    if ( type == 0 || samples == 0 ) return false;

    vector<int> components(0);
    type->CopyComponentList( components );
    int ncomp = components.size();

    int firstSample = 0;
    for (; firstSample<ncomp; ++firstSample)
        if ( samples[components[firstSample]] != 0  &&
            samples[components[firstSample]]->Get("cutflow") != 0 ) break;

    if ( firstSample == ncomp ) {
        cout << "SampleType " << type->GetName() << " contains all empty samples\n";
        return false; }

    // only one sample is present: it is self-consistent. :-)
    if ( firstSample == ncomp-1 ) return true;

    TH1F *heff = (TH1F*)(samples[components[firstSample]]->Get("cutflow"));
    int ncuts = heff->GetNbinsX();

    // Check that all samples have the same number of cuts applied
    for (int is=firstSample+1; is<ncomp; ++is) {
        if ( samples[components[is]] == 0 ) continue;
        TH1F *heff2 = (TH1F*)(samples[components[is]]->Get("cutflow"));
        if ( heff2 == 0 ) continue;
        if ( ncuts != heff2->GetNbinsX() )  return false;
        /*
         for (int ic=1; ic<=ncuts; ++ic)
         if ( strcmp(heff2->GetXaxis()->GetBinLabel(ic),
         heff ->GetXaxis()->GetBinLabel(ic)) &&
         strcmp("",heff2->GetXaxis()->GetBinLabel(ic)) != 0 &&
         strcmp("",heff ->GetXaxis()->GetBinLabel(ic)) != 0 ) return false;
         */

    }

    return true;
}


void PrintTypeEfficiency(SampleType *type, Sample **samples, bool printEvts=false, bool saveEvts=false) {

    if ( type == 0 || samples == 0 ) return;

    vector<int> components(0);
    type->CopyComponentList( components );
    int ncomp = components.size(); if ( ncomp<1 ) return;
    cout << "Efficiency table for sampletype \"" << type->GetName()
    << "\" composed of " << ncomp << " sample(s).\n";

    for (int is=0; is<ncomp; ++is)
        if ( samples[components[is]]->Get("cutflow") == 0 ) {
            cout << "Missing sample " << samples[components[0]]->GetName() << endl;
            return; }

    // Check that all samples have the same cuts applied
    if ( ! CheckTypeConsistency(type, samples) ) {
        cout << "Sampletype " << type->GetName() << " failed consistency check.\n";
        return; }

    double before, after, totxsec, befer2, after2;  // befer2 = before error squared, after2 = after error squared
    int ncuts = ((TH1F*)(samples[components[0]]->Get("cutflow")))->GetNbinsX();
    int defprecision = cout.precision(); // record current precision
    char csvtype[64];
    sprintf (csvtype,"eff_%s.csv", type->GetName().Data());
    std::ofstream out_data(csvtype);
    
    for (int ic=2; ic<=ncuts; ++ic) {

        TH1F *effh = 0;
        before = after = totxsec = befer2 = after2 = 0;

        for (int is=0; is<components.size(); ++is) {
        effh = (TH1F*)(samples[components[is]]->Get("cutflow"));
        totxsec += samples[components[is]]->xsec;
        before +=  effh->GetBinContent(ic-1)  * samples[components[is]]->xsec ;
        befer2 +=  pow(effh->GetBinContent(ic-1)==0?effh->GetBinError(ic-2):effh->GetBinError(ic-1)  * samples[components[is]]->xsec, 2) ;
        //befer2 +=  pow(max(effh->GetBinError(ic-1),1) / effh->GetBinContent(2) * samples[components[is]]->xsec, 2) ;
        after  +=  effh->GetBinContent(ic)  * samples[components[is]]->xsec ;
        after2 +=  pow(effh->GetBinContent(ic)==0?effh->GetBinError(ic-1):effh->GetBinError(ic) * samples[components[is]]->xsec, 2) ;
        //after2 +=  pow(max(effh->GetBinError(ic),1) / effh->GetBinContent(2) * samples[components[is]]->xsec, 2) ;
        
        /*if (ic>14) {
         cout << samples[components[is]]->GetName() << "\t" << ic << "\t" << samples[components[is]]->xsec  << "\t\t";
         //cout << effh->GetBinContent(ic) << "\t" << max(1,effh->GetBinError(ic)) << endl; }
         cout << effh->GetBinContent(ic) << "\t" << (effh->GetBinContent(ic)==0?effh->GetBinError(ic-1):effh->GetBinError(ic)) << endl; }*/
    }


        if (after/before != after/before) break;
        cout << "Eff. for " << setw(17) << effh->GetXaxis()->GetBinLabel(ic)
        << " = "  << setw(9) << setprecision(4) << after / before ;
        if (printEvts) {
            if ((components.size() == 1) && (samples[components[0]]->xsec == -1)) {
                cout << "  #b:" << setw(9) << effh->GetBinContent(ic-1) << " +- " << effh->GetBinError(ic-1)
                << "\t #a:"<< setw(9) << effh->GetBinContent(ic)   << " +- " << effh->GetBinError(ic);
            } else {
                cout << "  #b:"<< setw(9) <<before<< " +- " << sqrt(befer2) << "\t #a:"<<setw(9) <<after << " +- " << sqrt(after2);
            }
        }
        cout << endl;
        if (saveEvts) {
            out_data << effh->GetXaxis()->GetBinLabel(ic) << "," << setprecision(4) << after / before ;
                if ((components.size() == 1) && (samples[components[0]]->xsec == -1)) {
                    out_data << "," << "#b:"<< "," << effh->GetBinContent(ic-1) << "," <<"+-"<< "," << effh->GetBinError(ic-1)
                    << "," << "#a:"<<  "," << effh->GetBinContent(ic)    << "," << "+-" << "," << effh->GetBinError(ic);
                } else {
                    out_data << "," <<" #b:" << "," << before << "," << "+-" << "," << sqrt(befer2) << "," << "#a:" << "," << after <<  ","<< "+-" << "," << sqrt(after2);
                }
            out_data << "\n";
        }
    } // end of loop over all cuts (ic)

    cout << " --> Overall eff. (%)\t   = "
    << setw(6) << setprecision(4) << after/totxsec*100. << endl;
    
    
    cout.precision(defprecision); // restore recorded precision
}



// if the smooth amount is positive, do smoothing as usual.
// if the smooth amount is negative, try to make a decision on whether or not
//   smoothing is ok or not.
bool SmartSmooth(TH1* histo, double scalefactor,
                 int smooth, Sample* sample) {
    if ( smooth == 0  ||  ! sample->smoothable ) return false;
    if ( smooth > 0 ) { histo->Smooth(smooth); return true; }
    int nbins = histo->GetNbinsX();
    if ( nbins < 3 ) return false;
    int np=0; float sqr=0;
    for (int k=1;k<=nbins;++k) {
        sqr += pow( histo->GetBinContent(k), 2);
        if ( k==1 || k==nbins ) continue;
        if ( histo->GetBinContent(k)>histo->GetBinContent(k-1) &&
            histo->GetBinContent(k)>histo->GetBinContent(k+1) ) np++; }
    if ( np<3 ) return false;
    if ( sqr/scalefactor>1e6 ) return false;
    cout << "SmartSmooth " << histo->GetName() << " " << setw(20)
    << sample->GetTitle() << "\t#peaks=" << np
    << "\tSumSqr=" << sqr << "\tDecisionWeight=" << sqr/scalefactor << endl;
    histo->Smooth(-1*smooth);
    return true;
}

bool RemoveNegatives(TH1* histo) {
    int nbins = histo->GetNbinsX();
    for (int k=1;k<=nbins;++k) {
        if ( histo->GetBinContent(k)>=0 ) continue;
        histo->SetBinContent(k,0);
        histo->SetBinError(k,0); }
    return true;
}

void set_rainbow_style()
{
    const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
}

// Takes the samples and groups-of-samples and plots selected
//  variables for the inputs.  If desired returns a 2D-array
//   of all the histograms plotted.
// If you want proper error bars: defdrawopt = ""
// If you want error bars after scaling & summing: defdrawopt = "histe"
TCanvas* compare(Sample **samples, const int nsamples,
                 SampleType **type, const int ntypes,
                 TH1 *outhistos[__MAXNSMPLS__][__MAXNVARS__],
                 const PlotHistos ph, const int nvars,
                 TString plotfilename = "compare.pdf",
                 TString defdrawopt = "histe",
                 int histU=-1, int histD=-1, int idx=99
                 )
{
    gROOT->cd();
    //gStyle->SetPalette(1);
    set_rainbow_style();

    if (nvars==0) return 0;

    // delete the old canvas, in case we are being called multiple times
    /* don't delete.
     TObject *canvObj = gROOT->FindObject("compCanv");
     if ( canvObj ) {
     if (canvObj->InheritsFrom("TCanvas")) delete canvObj;
     else { cout << "Error! Another object named compCanv.\n"; return 0; } }
     */
    TCanvas *compCanv = new TCanvas((TString::Format("compCanv%d",idx)).Data() ,"compare",800,600);
    // Count how many plots are "on" and prepare the canvas for that
    unsigned int num_on(0);

    for (int i=0; i<nvars; i++) if (ph.opt[i]) num_on++;
    unsigned int nrows=DivideCanvas(compCanv, num_on);
    int ncols=TMath::Nint(0.49999+num_on/float(nrows));

    double stack_vals[ntypes];
    int  stack_idx[ntypes];

    for (int i=0; i<ntypes; ++i) stack_vals[i]=-99.99;  // Clean vals

    TH1 *hist[nsamples][nvars];
    TH1 *typesum[ntypes][nvars]; // One histogram for each group
    for (int i=0; i<nvars; ++i) {  // Clean histos
        for (int is=0; is<nsamples; ++is)  hist[is][i]=0;
        for (int it=0; it<ntypes; ++it)  typesum[it][i]=0;
    }

    int nplotted = 0;

    for (int i=-1; i<nvars; ++i) if (i>=0 && ph.opt[i]) {

        // Why start with -1 and skip it?
        // This is a peculiarity of ROOT/CINT, without it, one either gets
        //   crashes and/or some weird errors like:
        // Error: non class,struct,union object $gPad used with . or ->
        // Using commands like gPad->GetCanvas()->FeedbackMode(kTRUE); overcome
        //   such errors, but causes other issues.

        nplotted++;
        compCanv->cd(nplotted);
        if ((histU>-1) && (histD>-1)){ // from Erdo
            TPad *pad1 = new TPad("pad1","pad1",0,0.25, 1,   1);
            pad1->SetBottomMargin(0.00);
            pad1->SetTopMargin(0.02);
            pad1->SetNumber(1);
            pad1->Draw();
            pad1->cd();
        }

        //-------
        bool is2d = false;
        TString drawopt = defdrawopt; // Default draw options
        bool isHO = (drawopt=="hist");  // is basic histo only?
        TLegend *leg = new TLegend(0.2,0.8,0.89,0.89);
        leg->SetFillStyle(0);
        int nsamplesplotted = 0;
        for (int j=0; j<nsamples; ++j) {

            if ( samples[j] == 0 ) continue;
            TObject *histobj = samples[j]->Get(ph.vars[i]);
            if ( histobj == 0 ) continue;
            TH1F *eff = (TH1F*)(samples[j]->Get("cutflow"));
            double scalefactor = samples[j]->GetScaleFactor();

            if ( histobj->InheritsFrom("TH3F") ) continue;
            else if ( histobj->InheritsFrom("TH2F") ) {
                if ( ph.opt[i] == 'x' || ph.opt[i] == 'y' ) {
                    TH2F *hist2d = new TH2F(*((TH2F*)samples[j]->Get(ph.vars[i])));
                    if ( ph.opt[i] == 'x' ) {
                        hist[j][i] = new TH1F(*((TH1F*)(hist2d->ProjectionX("_px"))));
                        hist[j][i]->SetTitle(TString(hist[j][i]->GetTitle())+"_px"); }
                    else {
                        hist[j][i] = new TH1F(*((TH1F*)(hist2d->ProjectionY("_py"))));
                        hist[j][i]->SetTitle(TString(hist[j][i]->GetTitle())+"_py"); }
                    delete hist2d;
                    if (ph.rebin[i]>1) hist[j][i]->Rebin(ph.rebin[i]);
                    if (ph.smooth[i]>0) SmartSmooth(hist[j][i], scalefactor,
                                                    ph.smooth[i], samples[j]);
                } // end of if ph.opt == 'x' || 'y'
                else {
                    hist[j][i] = new TH2F(*((TH2F*)samples[j]->Get(ph.vars[i])));
                    if (ph.rebin[i]>1) ((TH2*)hist[j][i])->Rebin2D(ph.rebin[i],ph.rebin[i]);
                    is2d = true;
                    drawopt = "box"; }
            }
            else { // if the object is a 1D histogram
                //---------CHECK the return value
                hist[j][i] = new TH1F(*((TH1F*)samples[j]->Get(ph.vars[i])));
                if (ph.rebin[i]>1) hist[j][i]->Rebin(ph.rebin[i]);
                SmartSmooth( hist[j][i], scalefactor, ph.smooth[i], samples[j] );
                //RemoveNegatives( hist[j][i] ); // Need to remove negatives for QCD problems
                //if (ph.smooth[i]>0) hist[j][i]->Smooth(ph.smooth[i]);
            }
            //   hist[j][i]->Sumw2();  // force compute errors
            if ( ! defdrawopt.Contains("hist",TString::kIgnoreCase ) )
                //hist[j][i]->Sumw2();  // if histogram not forced, compute errors, commented out because we calculate errors in our analysis
#if !defined(__showsums__) && defined(__unitarea__)
                hist[j][i]->Scale(1./hist[j][i]->GetEntries());
#else
            hist[j][i]->Scale(scalefactor);
#endif
            hist[j][i]->SetLineColor(samples[j]->histcol);
            hist[j][i]->SetMarkerColor(samples[j]->histcol);
            hist[j][i]->SetMarkerStyle(20+j%11); // using markers 20-30
            hist[j][i]->SetMarkerSize(0.3); // using markers 20-30
            if ( is2d ) {
                hist[j][i]->SetFillColor(samples[j]->histcol);
                hist[j][i]->SetFillStyle(samples[j]->histcol+3000); }
            else
                hist[j][i]->SetYTitle(TString::Format("Entries / %g", hist[j][i]->GetXaxis()->GetBinWidth(1)).Data());
            hist[j][i]->GetYaxis()->CenterTitle(true);
            if ( string(hist[j][i]->GetXaxis()->GetTitle()) == "" )
                hist[j][i]->SetXTitle(hist[j][i]->GetTitle());
            leg->AddEntry(hist[j][i], samples[j]->GetTitle(), is2d?"lf":isHO?"l":"lp");
            if (ph.minmax != 0) { // if min and max bounds are given
                //        cout << "Xaxis limits for:"<< ph.vars[i] <<" as: " << ph.minmax[2*i]<< " _ "<< ph.minmax[2*i+1]<<"\n";
                if (ph.minmax[2*i] != ph.minmax[2*i+1])
                    hist[j][i]->SetAxisRange(ph.minmax[2*i], ph.minmax[2*i+1], "X");
            }
            if ( nsamplesplotted==0 ) {             hist[j][i]->Draw(drawopt);
                // cout <<"hereeeeee\n";
            }
            else hist[j][i]->Draw(drawopt+"same");
            nsamplesplotted++;
            //cout << hist[j][i]->GetSumOfWeights() << endl;
            for ( int it=0; it<ntypes; ++it ) {
                if ( type[it]->Contains(j) ) {
                    if ( typesum[it][i]==0 ) {
                        //        cout << "Missing:"<< it<<"   Filling with sample:"<<j<< "  var:"<< i << "  "<< type[it]->GetName().Data()  <<"\n";
                        typesum[it][i] = (TH1*)hist[j][i]->Clone(type[it]->GetName().Data()  );
                    }
                    else {
                        typesum[it][i]->Add(hist[j][i]);
                        // turn on the debug if you need to see the individual contributions
                        // 2-19 light jets, 20-50 bb&cc , 51-55 c
                        //#define __DEBUG_CONTENTS__
#ifdef __DEBUG_CONTENTS__
                        if (it==10) cout <<"sample="<<j<< " Added:"<<hist[j][i]->GetSumOfWeights()<<endl;
#endif
                    }
                }
            }
        }
#ifdef __singlelegend__
        if ( nplotted==ncols )
#endif
            leg->Draw();
        bool uncert_plot=false;
        int uncert_typId=-1;
#ifdef __showsums__
        delete leg;
        leg = new TLegend(0.4,0.78,0.94,0.92);
        leg->SetFillStyle(0);
        THStack* stack = new THStack("stack","");
        for ( int it=0; it<ntypes; ++it ) // over the types.
            if ( type[it]->IsDrawable() ){
                if ( typesum[it][i] != 0 ) {
                    //        cout << "This is type ID:"<<it<<" and name:"<<type[it]->GetName()<< " leg:"<<type[it]->GetLeg()<<endl;
                    string fstyle=type[it]->GetForcedStyle();
                    string myl=type[it]->GetLeg() ;
                    if ( fstyle != "" ) {leg->AddEntry(typesum[it][i], ( myl== "xxx")?type[it]->GetName().Data():myl.c_str(), (fstyle=="e1")?"le":(fstyle=="b1")?"l":"f");
                    } else {
                        leg->AddEntry(typesum[it][i], type[it]->GetName().Data(), is2d?"lf":isHO?"f":"lp");
                    }
                    stack->SetTitle(typesum[it][i]->GetTitle());
                    int ndrawn = leg->GetListOfPrimitives()->LastIndex();
#ifdef __unitarea__
                    typesum[it][i]->Scale(1./typesum[it][i]->GetSumOfWeights());
#endif
                    typesum[it][i]->SetLineColor(ndrawn+1);
                    if ( ndrawn<__MAXNGOOD__ ) {
                        typesum[it][i]->SetLineColor(goodcolors[ndrawn]);
                        typesum[it][i]->SetMarkerColor(goodcolors[ndrawn]);
                        // NGU to fill histograms or not
                        if ((goodcolors[ndrawn]!=1) && (fstyle != "b1")) typesum[it][i]->SetFillColor(goodcolors[ndrawn]);
                        typesum[it][i]->SetLineStyle(goodstyles[ndrawn]);
                    }
#ifdef __stacksums__
                    TString ahisname=typesum[it][i]->GetName();
                    bool sibg= ahisname.Contains("signal",TString::kIgnoreCase) || ahisname.Contains("SMbg",TString::kIgnoreCase) || ahisname.Contains("Uncert",TString::kIgnoreCase);
                    //        cout<< (double)typesum[it][i]->GetEntries() << " for:"<<it<<" "<<type[it]->GetName() <<endl;
                    if ( it > 0 && (!sibg) )  {
                        stack_vals[it]=(double)typesum[it][i]->GetMaximum();
                        typesum[it][i]->SetFillColor(goodcolors[ndrawn]); //force filling for stacks
                    }
#endif
                    if ( is2d  ) {
                        typesum[it][i]->SetContour(255);
                        ////////  typesum[it][i]->SetFillColor(ndrawn+1);
                        ////////  typesum[it][i]->SetFillColor(goodcolors[ndrawn]);
                        ////////  typesum[it][i]->SetFillStyle(ndrawn ? ndrawn+3000 : 1001);
                        ////////  drawopt = "box";
                    }
                    // NGU
                    if ( !is2d && (fstyle != "")) {
                        drawopt=fstyle;
                        if (fstyle == "b1")  {
                            typesum[it][i]->SetMarkerSize(0.1);
                            drawopt="hist";
                        }
                        if (fstyle == "e2" || fstyle == "e3" || fstyle == "e4"  ) {
                            typesum[it][i]->SetFillStyle(3004);
                            typesum[it][i]->SetFillColor(kBlue+2);
                            typesum[it][i]->SetLineColor(kWhite);
                            typesum[it][i]->SetLineWidth(4);
                            typesum[it][i]->SetMarkerSize(0.01);
                            if (ahisname.Contains("Uncert",TString::kIgnoreCase)) { uncert_plot=true; uncert_typId=it;}
                        }
                    } else {drawopt="hist";}
                    //if (is2d) drawopt="cont2z";
                    if (is2d) drawopt="col";
                    if ( ndrawn==0 ) {typesum[it][i]->Draw(drawopt+"z"); }
                    else {typesum[it][i]->Draw(drawopt+"same"); }
                }
            } else { // not Drawable
                ;
            }

#ifdef __stacksums__
        //for(int itn=0; itn<ntypes; itn++) cout << stack_vals[itn] << " "; cout  << endl;
        TMath::Sort(ntypes, stack_vals, stack_idx, false); //reverse order
        //for(int itn=0; itn<ntypes; itn++) cout << stack_vals[stack_idx[itn] ] << " "; cout  << endl;
        for ( int it=0; it<ntypes; it++ ) {     // over the types fill in increasing order
            if (stack_vals[stack_idx[it]] >1)
                stack->Add(typesum[  stack_idx[it] ][i]);
        }
        stack->SetMinimum(0.9);
        stack->SetMaximum(4*stack->GetMaximum() );
        if (ph.minmax != 0) {
            stack->Draw("BAR"); // dummy one
            if (ph.minmax[2*i] != ph.minmax[2*i+1])
                stack->GetXaxis()->SetRangeUser(ph.minmax[2*i], ph.minmax[2*i+1]);
        }
        stack->Draw("BAR"); //realone
        //stack->GetYaxis()->SetTitle(typesum[0][i]->GetYaxis()->GetTitle());
        //stack->GetXaxis()->SetTitle(typesum[0][i]->GetXaxis()->GetTitle());
        for(int it=0; it<ntypes; it++){
            if (  type[it]->IsDrawable() ){
                if ( type[it]->GetForcedStyle() =="e1" ) typesum[it][i]->Draw("e1same");
                if ( type[it]->GetForcedStyle() =="e2" ) typesum[it][i]->Draw("e2same");
                if ( type[it]->GetForcedStyle() =="e3" ) typesum[it][i]->Draw("e3same");
                if ( type[it]->GetForcedStyle() =="e4" && typesum[it][i]!=0 ) typesum[it][i]->Draw("e4same");
            }
        }
#endif

#ifdef __singlelegend__
        if ( nplotted==ncols )
#endif
            leg->SetShadowColor(0);
        leg->SetFillColor(0);
        leg->SetMargin(0.4);
        leg->SetBorderSize(0);
        leg->SetNColumns(3);
        leg->Draw();
#endif

        //if ( 0 != gROOT->GetListOfGlobalFunctions()->FindObject("HistoAutoLogScale") )
        //  { HistoAutoLogScale(); HistoAutoRange(); }

        if ((histU>-1) && (histD>-1)){ // from Erdo
 //            cout << "Up:"<<histU<<"  Down:"<<histD<<"\n";
            // I plotted all my curves with different colors and such now I can do the ratio
            compCanv->cd(nplotted);
            TPad *pad2= new TPad("pad2","pad2",0,0.0  , 1,0.25);
            pad2->Draw();
            pad2->SetNumber(2);
            pad2->cd();
            pad2->SetTopMargin(0.10);
            pad2->SetBottomMargin(0.3);
            // U / D---> Data / MC
            TH1F *histRatio=((TH1F*)(typesum[histU][i])->Clone());
            TH1F *reversedHistRatio=((TH1F*)(typesum[histD][i])->Clone());
            histRatio->Divide((TH1F*)(typesum[histD][i])); //--------------------up divided by down
            reversedHistRatio->Divide((TH1F*)(typesum[histU][i]));
            histRatio->GetYaxis()->SetRangeUser(0.5,1.5);
            if (ph.minmax[2*i] != ph.minmax[2*i+1]){
                histRatio->GetXaxis()->SetRangeUser(ph.minmax[2*i],ph.minmax[2*i+1]);
            }
            histRatio->SetMarkerStyle(6);
            histRatio->SetMarkerColor(1);
            histRatio->SetFillStyle(3013);
            histRatio->SetFillColor(kGray+1);
            histRatio->SetLineColor(kMagenta-8);
            histRatio->GetXaxis()->SetLabelFont(43); //fontHocamvsd
            histRatio->GetXaxis()->SetLabelSize(10); //in pixels
            histRatio->GetXaxis()->SetTitleSize(0.18); //in pixels
            histRatio->GetXaxis()->SetTitleOffset(.7); //in pixels
            histRatio->GetYaxis()->SetLabelFont(43); //font
            histRatio->GetYaxis()->SetLabelSize(7); //in pixels
            histRatio->GetYaxis()->SetTitleFont(103); //font
            histRatio->GetYaxis()->SetTitleSize(13); //in pixels
            histRatio->GetYaxis()->SetTitleOffset(2); //in pixels
            histRatio->GetYaxis()->SetTitle("Data/MC"); //in pixels
            histRatio->GetYaxis()->CenterTitle(true);
            histRatio->GetYaxis()->SetNdivisions(5,2,0,true); //magic
            histRatio->Draw("e1p");
            
            float difference=0.0,sumOfDifference=0.0;
            int firstNonZeroBin = histRatio->FindFirstBinAbove(0,1), lastNonZeroBin = histRatio->FindLastBinAbove(0,1), zeroBins=0;
            //cout << firstNonZeroBin << " " << lastNonZeroBin << endl;
            
            for (unsigned int nbin= firstNonZeroBin; nbin <= lastNonZeroBin; nbin++ ){
            
                if (histRatio->GetBinContent(nbin) == 0 || reversedHistRatio->GetBinContent(nbin) == 0 ) zeroBins++;
                if (histRatio->GetBinContent(nbin) != 0 && reversedHistRatio->GetBinContent(nbin) != 0){
                    difference = (histRatio->GetBinContent(nbin)-1)*(histRatio->GetBinContent(nbin)-1)/histRatio->GetBinError(nbin)/histRatio->GetBinError(nbin);
                    sumOfDifference = sumOfDifference + difference;
/*
                    cout << "difference: " <<  difference << " nbin: " <<  nbin << " monte carlo: " <<typesum[histD][i]->GetBinContent(nbin) << " data: " << typesum[histU][i]->GetBinContent(nbin) << " sum of difference: " << sumOfDifference << " uncertainty: " <<histRatio->GetBinError(nbin) << " uncertainty calculated by hand: " << (difference*sqrt(TMath::Power(typesum[histU][i]->GetBinError(nbin)/typesum[histU][i]->GetBinContent(nbin),2)+TMath::Power(typesum[histD][i]->GetBinError(nbin)/typesum[histD][i]->GetBinContent(nbin),2))) << "bin content from histRatio " << histRatio->GetBinContent(nbin) <<endl;
*/
               }
            }
            
            
            char totalDifferencePerNDF[40];

            sprintf(totalDifferencePerNDF,"#chi^2/ndf = %g / %d",sumOfDifference,lastNonZeroBin-firstNonZeroBin-zeroBins);
            TPaveText *t1 = new TPaveText(1.0,0.5,0.1,0.1,"nb");
            t1->AddText(totalDifferencePerNDF);
            t1->SetTextColor(kBlue);
            t1->SetTextSize(0.08);
            t1->Draw();
            pad2->Update();

            if (uncert_plot ){
                cout << "UNC:"<< histU <<"  /  "<< uncert_typId <<"\n";
                TH1F *histRaUnc=((TH1F*)(typesum[histU][i])->Clone());
                histRaUnc->Rebin(2);
                histRaUnc->Divide((TH1F*)(typesum[uncert_typId][i]) );
                cout << "UNC bins:"<< histRaUnc->GetNbinsX() <<"  /  "<< typesum[uncert_typId][i]->GetNbinsX() <<"\n";
                histRaUnc->SetMarkerStyle(1);
                histRaUnc->SetMarkerSize(0.01);
                histRaUnc->SetMarkerColor(1);
                histRaUnc->SetFillStyle(3004);
                histRaUnc->SetLineWidth(4);
                histRaUnc->SetFillColor(kBlue+2);
                histRaUnc->SetLineColor(kWhite);
                //          histRaUnc->Draw("e");
                histRaUnc->Draw("e3psame");

            }

            Double_t xmin=histRatio->GetXaxis()->GetXmin();
            Double_t xmax=histRatio->GetXaxis()->GetXmax();
            if (ph.minmax[2*i] != ph.minmax[2*i+1]){
                xmin=ph.minmax[2*i];
                xmax=ph.minmax[2*i+1]; }
            TLine *l0=  new TLine(xmin, 1, xmax, 1);
            l0->SetLineStyle(3);
            l0->SetLineColor(2);
            l0->Draw();


            //compCanv->cd(nplotted);



        }
    } // end of loop over vars (i)


    compCanv->cd();
    if (plotfilename != "")
        compCanv->SaveAs(plotfilename);

    if ( outhistos!=0 )
#ifdef __showsums__
        for (int it=0; it<ntypes; ++it)
            for (int iv=0; iv<nvars; ++iv)
                outhistos[it][iv] = typesum[it][iv];
#else
    cout << "Error is here? samples:"<<nsamples<<endl;
    for (int is=0; is<nsamples; ++is)
        for (int iv=0; iv<nvars; ++iv)
            outhistos[is][iv] = hist[is][iv];
#endif

    return compCanv;
}

//**************************************************
int decode_chars(int *np, string str, char *charlist){
    std::stringstream ss(str);
    int k=0;
    char i;
    while (ss >> i) {
        charlist[k]=i; k++;
        if (ss.peek() == ',')
            ss.ignore();
    }
    *np=k;
    //    for (i=0; i< k; i++) std::cout << intlist[i]<<std::endl;
    return 0; //success
}

//**************************************************
int decode_ints(int *np, string str, int *intlist){
    std::stringstream ss(str);
    int i,k=0;
    while (ss >> i) {
        intlist[k]=i; k++;
        if (ss.peek() == ',')
            ss.ignore();
    }
    *np=k;
    //    for (i=0; i< k; i++) std::cout << intlist[i]<<std::endl;
    return 0; //success
}
//**************************************************
int decode_floats(int *np, string str, float *floatlist){
    std::stringstream ss(str);
    int k=0;
    float f;
    while (ss >> f) {
        floatlist[k]=f; k++;
        if (ss.peek() == ',')
            ss.ignore();
    }
    *np=k;
    //    for (i=0; i< k; i++) std::cout << floatlist[i]<<std::endl;
    return 0; //success
}


//**************************************************
int decode_strs(int *np, string str, string *strlist){
    std::stringstream ss(str);
    int k=0;
    string substr;
    while (ss.good() ) {
        getline( ss, substr, ',' );
        strlist[k]=substr; k++;
    }
    *np=k;
    //    for (int i=0; i< k; i++) std::cout << strlist[i] <<" "<<std::endl;
    return 0; //success
}
#endif
