// Loop through all histos in the current gPad and make sure all of
// them are totally visible.  Useful when you plot two or more histograms
// with the "same" option and some bin contents are not visible due to
// the range set automatically by the first plotted histo.
void HistoAutoRange() {
#define __HistoAutoRange__

  if ( gROOT->GetListOfCanvases()->GetEntries() == 0 ) return;
  TList *glist = gPad->GetListOfPrimitives();
  bool islogy = gPad->GetLogy();

  // First identify the current range for the y-axis
  double ymin=0, ymax=0;
  for (int i=0; i<glist->GetEntries(); ++i) {
    TObject *obj = glist->At(i);
    if ( obj->InheritsFrom("TFrame") ) {
	ymin = ((TFrame*)obj)->GetY1();
	ymax = ((TFrame*)obj)->GetY2();
	break;
    }
  }
  if ( islogy ) { ymin = ymin/10; ymax = 10*ymax; }

  // Now loop through histos and find the extrema
  for (int i=0; i<glist->GetEntries(); ++i) {
    TObject *obj = glist->At(i);
    if ( obj->InheritsFrom("TH1") ) {
      TH1 *histo = (TH1*)obj;

      // If this is a 2D histogram, sorry, we can't do it (yet).
      if ( obj->InheritsFrom("TH2") ) return;

      // if log scale plot, do not modify the minimum - problems with negatives
      if ( !islogy ) {
	ymin = TMath::Min( ymin, histo->GetMinimum() );
	ymin = TMath::Min( ymin, histo->GetBinContent(histo->GetMinimumBin()));
      }

      ymax = TMath::Max( ymax, (islogy ? 1.8 : 1.1) *
			 ( histo->GetBinContent(histo->GetMaximumBin()) +
			   (int)(histo->GetSumw2N() != 0) *
			         histo->GetBinError(histo->GetMaximumBin()) ) );
    }
  }
  if ( (ymin<=0) ) ymin=1;

  // Finally set the new min/max
  for (int i=0; i<glist->GetEntries(); ++i) {
    TObject *obj = glist->At(i);
    if ( obj->InheritsFrom("TH1") ) {
      ((TH1*)obj)->GetYaxis()->SetRangeUser(ymin, ymax);
//       cout << "y: "<< ymin << " " << ymax <<endl;
    //  ((TH1*)obj)->SetMinimum(); // needed to get gPad->SetLogy() working
    }
  }

  gPad->Modified();

}



// Loop through all histos in the current gPad and convert to log scale
//  if it would look better.  The "better" condition is based on comparing
//  the maximum content for each histo and identifying if the quotient
//  of any such maxima exceeds a certain factor.  There is also a check
//  against very "sharp" histograms, where the mean number of entries for
//  the non-empty bins is much smaller than the max bin content.
void HistoAutoLogScale(float xfactor=20) {

  if ( gROOT->GetListOfCanvases()->GetEntries() == 0 ) return;
  TList *glist = gPad->GetListOfPrimitives();
  if ( gPad->GetLogy() ) return;

  float maxhisthi = -1;
  float maxhistlo = -1;
  bool sharphisto(false);

  // Now loop through histos and find the extrema
  for (int i=0; i<glist->GetEntries(); ++i) {
    TObject *obj = glist->At(i);
    if ( obj->InheritsFrom("TH1") ) {

      // If this is a 2D histogram, sorry, nothing to do yet.
      if ( obj->InheritsFrom("TH2") ) return;

      TH1 *histo = (TH1*)obj;

      // If any of the histos have negative content, sorry, nothing to do.
      if ( histo->GetBinContent(histo->GetMinimumBin()) < 0 ) return;

      float maxhist = histo->GetBinContent(histo->GetMaximumBin());

      if ( maxhisthi < 0 )
	maxhisthi = maxhistlo = maxhist;
      else {
	if ( maxhistlo > maxhist ) maxhistlo = maxhist;
	if ( maxhisthi < maxhist ) maxhisthi = maxhist;
      }

      // If any of the histos have a very sharp peak
      unsigned int nbinsfull = 0;  float integral = 0;
      for (int ib=1; ib<=histo->GetNbinsX(); ++ib)
	if ( histo->GetBinContent(ib) > 0 ) {
	  nbinsfull++; integral += histo->GetBinContent(ib); }
      if ( maxhist * nbinsfull > (integral-maxhist) * xfactor ) {
	sharphisto = true; break; }

    }
  }

  if ( maxhistlo * xfactor < maxhisthi  ||  sharphisto ) gPad->SetLogy();
  gPad->Modified();

}
