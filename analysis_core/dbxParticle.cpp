#include "dbxParticle.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

#ifndef __DBX_PARTICLE_C__
ClassImp(dbxParticle)

dbxParticle:: dbxParticle() : TObject() {
/*
  p_et_cone = -999;
  p_pt_cone = -999;
  p_flavor = -999;
  p_istight = -999;
  p_particleindx = -999;
  p_scalefactor=1.;
  p_escalefactor=999.;
*/
  p_charge=0; // not initialized
  p_pdgID= 0.;
  p_lvector.SetPtEtaPhiM(0, 0, 0, 0);
}
dbxParticle:: dbxParticle (TLorentzVector lv){
  p_et_cone = -999;
  p_pt_cone = -999;
  p_flavor = -999;
  p_istight = -999;
  p_particleindx = -999;
  p_charge=-999; // not initialized
  p_lvector=lv;
  p_scalefactor=1.;
  p_scalefactorreco=1.;
  p_scalefactorid=1.;
  p_scalefactortrig=1.;
  p_escalefactor=999.;
  p_recouncertaintyup = 1.;
  p_recouncertaintydown = 1.;
  p_triguncertaintyup = 1.;
  p_triguncertaintydown = 1.;
  p_iduncertaintyup = 1.;
  p_iduncertaintydown = 1.;
  p_z0 = -999;
}

dbxParticle:: ~dbxParticle() {}

dbxParticle:: dbxParticle (TLorentzVector lv, int q){
  p_pdgID = 0.;
  p_et_cone = -999;
  p_pt_cone = -999;
  p_flavor = -999;
  p_istight = -999;
  p_particleindx = -999;
  p_charge=q; // initalized
  p_lvector=lv;
  p_scalefactor=1.;
  p_escalefactor=999.;
  p_recouncertaintyup = 1.;
  p_recouncertaintydown = 1.;
  p_triguncertaintyup = 1.;
  p_triguncertaintydown = 1.;
  p_iduncertaintyup = 1.;
  p_iduncertaintydown = 1.;
  p_z0=-999;

}
dbxParticle  dbxParticle::operator+ (dbxParticle& p)
{
     dbxParticle result (this->lv()+p.lv(), this->q()+p.q() );
//    dbxParticle result ;
//    result.setTlv(this->lv()+p.lv());
//    result.setCharge(this->q()+p.q());
      return result;
}

int dbxParticle::setPdgID(int pdgID)
{
	p_pdgID = pdgID;
	return 0;
}

double dbxParticle::deltaR(dbxParticle p1,dbxParticle p2){
    
  return p1.lv().DeltaR(p2.lv());
}


double dbxParticle::deltaPhi(dbxParticle p1,dbxParticle p2){
  
  return p1.lv().DeltaPhi(p2.lv());
}

int dbxParticle:: setCharge (int q){
 p_charge=q;
 return 0;
}

int dbxParticle:: setFlavor (double fla){
 p_flavor=fla;
 return 0;
}

int dbxParticle:: setEtCone (double iso){
 p_et_cone=iso;
 return 0;
}

int dbxParticle:: setPtCone (double iso){
 p_pt_cone=iso;
 return 0;
}

int dbxParticle:: setIsTight (int indx){
 p_istight=indx;
 return 0;
}

int dbxParticle:: setParticleIndx (int indx){
 p_particleindx=indx;
 return 0;
}

int dbxParticle:: setTlv (TLorentzVector lv){
 p_lvector=lv;
 return 0;
}


int dbxParticle:: setScaleFactor (double sf){
 p_scalefactor=sf;
 return 0;
}

int dbxParticle:: setScaleFactorReco (double sf){
 p_scalefactorreco=sf;
 return 0;
}
int dbxParticle:: setScaleFactorId (double sf){
 p_scalefactorid=sf;
 return 0;
}
int dbxParticle:: setScaleFactorTrig (double sf){
 p_scalefactortrig=sf;
 return 0;
}
int dbxParticle:: setScaleFactorTrigMcEff (double sf){
 p_scalefactortrig_mceff=sf;
 return 0;
}
int dbxParticle:: setScaleFactorIso(double sf){
 p_scalefactoriso=sf;
 return 0;
}

////////////////////////////////////////////////////////////////////////////
//These don't make sense now, we keep them for historical reasons 26.02.2014
int dbxParticle:: setScaleFactorUncertainty (double sf){
 p_escalefactor=sf;
 return 0;
}

int dbxParticle:: setScaleFactorUncertaintyUp (double sf){
 p_scalefactorup=sf;
 return 0;
}

int dbxParticle:: setScaleFactorUncertaintyDown (double sf){
 p_scalefactordown= sf;
 return 0;
}

//////////////////////////////////////////////////////////////////////////
int dbxParticle:: scaleLorentzVector ( double scale ){
 p_lvector*=scale;
 return 0;
}

int dbxParticle:: setZ0(double q){
  p_z0=q;
 return 0;
}

int dbxParticle:: setSFRecoUncertaintyUp( double sf ) { p_recouncertaintyup = sf; return 0; }
int dbxParticle:: setSFRecoUncertaintyDown( double sf ) { p_recouncertaintydown = sf; return 0; }
int dbxParticle:: setSFTrigUncertaintyUp( double sf ) { p_triguncertaintyup = sf; return 0; }
int dbxParticle:: setSFTrigUncertaintyDown( double sf ) { p_triguncertaintydown = sf; return 0; }
int dbxParticle:: setSFTrigMcEffUncertaintyUp( double sf ) { p_trigmceffuncertaintyup = sf; return 0; }
int dbxParticle:: setSFTrigMcEffUncertaintyDown( double sf ) { p_trigmceffuncertaintydown = sf; return 0; }
int dbxParticle:: setSFIDUncertaintyUp( double sf ) { p_iduncertaintyup = sf; return 0; }
int dbxParticle:: setSFIDUncertaintyDown( double sf ) { p_iduncertaintydown = sf; return 0; }
int dbxParticle:: setSFIsoUncertaintyUp( double sf ) { p_isouncertaintyup = sf; return 0; }
int dbxParticle:: setSFIsoUncertaintyDown( double sf ) { p_isouncertaintydown = sf; return 0; }


void dbxParticle:: dump (){
 std::cout << "Px="<<p_lvector.Px()<< "  Py="<<p_lvector.Py()<< "  Pz="<<p_lvector.Pz()<< "  E="<<p_lvector.E()<<std::endl;
}


void dbxParticle:: dump_b (){
 std::cout << "PT="<<p_lvector.Pt()<< "  Eta="<<p_lvector.Eta()<< "  Phi="<<p_lvector.Phi()<< "  M="<<p_lvector.M()<<std::endl;
}

void dbxParticle:: dumpLHCO (std::ofstream& fn){
 using namespace std;
//  #  typ      eta    phi      pt    jmas  ntrk  btag   had/em  sv0  dum2
 fn << fixed <<setprecision(1)<<p_lvector.Eta()<< setw(9)<<setprecision(1)<<p_lvector.Phi()<< setw(9)<<setprecision(1)<<p_lvector.Pt()<< setw(9)<<setprecision(1)<<p_lvector.M();
 fn << fixed<<setw(9)<<setprecision(1)<<p_charge<< setw(9)<<0.0<< setw(9)<<setprecision(1)<< 0.0 << setw(9)<<setprecision(2);
 if (fabs(p_charge)==1) fn << 0.0;
 else fn<<p_flavor;
 fn<<setw(9)<<0.0<<std::endl;
}


#define __DBX_PARTICLE_C__
#endif
