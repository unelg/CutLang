// mtautau used in CMS-SUS-16-048
#include "TLorentzVector.h"
//namespace softdilepton {

  // Find m(tautau) for boosted taus with alligned decay products.
  // For leptons l1, l2 and neutrino(s) nu1, nu2 coming from tau1, tau2 decays,
  // collinearity implies p(nu1) = a * p(l1), p(nu2) = b * p(l2)
  //   1) Use the constraint from MET to find a and b
  //   2) Compute nu and tau momenta
  //   3) Find the ditau invariant mass
  // Suggested in arXiv:1401.1235 , used in CMS SUS-16-048
  double fMtautau(TLorentzVector lep1, TLorentzVector lep2, TLorentzVector met){

    double px1 = lep1.Px();
    double py1 = lep1.Py();
    double px2 = lep2.Px();
    double py2 = lep2.Py();
    double metx = met.Px();
    double mety = met.Py();

    // Compute the solution of the two coupled equations:
    //     metx = a * px1 + b * px2
    //     mety = a * py1 + b * py2
    // for a and b:

    double a = (metx * py2 - mety * px2) / (px1 * py2 - py1 * px2);
    double b = (metx * py1 - mety * px1) / (px2 * py1 - py2 * px1);

    // Neutrino vectors
    TLorentzVector nu1, nu2;
    nu1.SetPxPyPzE(a*px1, a*py1, 0., sqrt(a*px1 * a*px1 + a*py1 * a*py1));
    nu2.SetPxPyPzE(b*px2, b*py2, 0., sqrt(b*px2 * b*px2 + b*py2 * b*py2));

    // Reconstruct the taus from leptons and neutrinos
    TLorentzVector tau1 = lep1 + nu1;
    TLorentzVector tau2 = lep2 + nu2;

    // Reconstruct the Z from Z --> tau tau
    TLorentzVector Z = tau1 + tau2;

    return Z.M();
  }
/*
  // MT : transverse mass 
  double fMT(TLorentzVector& lepton, TLorentzVector& pfmet){
     return sqrt( 2 * lepton.Pt() * pfmet.Pt() * ( 1 - cos( pfmet.Phi() - lepton.Phi() ) ) );
  }

}
*/

