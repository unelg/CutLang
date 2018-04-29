#ifndef DBX_CUT_H
#define DBX_CUT_H

#include <iostream>
#include <vector>
#include <map>
#include <utility>

#include "dbxParticle.h"
#include "dbx_electron.h"
#include "dbx_photon.h"
#include "dbx_muon.h"
#include "dbx_jet.h"
#include "basic_parser.h"
#include "analysis_core.h"
#include "ReadCard.h"


struct AnalysisObjects {
    std::vector<dbxMuon>     muos;
    std::vector<dbxElectron> eles;
    std::vector<dbxPhoton>   gams;
    std::vector<dbxJet>      jets;
    TVector2            met;
    evt_data            evt;
};


class dbxCut : public TObject  {

public:
                  dbxCut( std::string name);
                  dbxCut( std::string name, int i);
                  dbxCut( std::string name, std::vector<int> mytypes, std::vector<int> myids, int myparam);

                 ~dbxCut(){ }

                    void setRa( float mn, float mx)   {p_min=mn; p_max=mx;}
                    void setLi( float f) {p_cutf=f;}
                    void setOp( std::string o){ p_oper=o; }
             std::string getName(){          return p_name;}
             std::string getOp(){            return p_oper;}
                     int getCi(){            return p_cuti;} // a cut index or some other info
                   float getLi(){            return p_cutf;}
                    bool isSearchable(){     return p_searchable;}
                   float getPrecalc(){       return p_precalc;} // a precalculated value
                    void setPrecalc(float v){       p_precalc=v;}

                     int getParticleType(int idx=-1){if (idx<0) {return p_part_type.size(); }else{ return p_part_type[idx]; }};
                    void setParticleType(int idx, int val){ p_part_type.at(idx)=val;}
                     int getParticleIndex(int idx=-1);
                    void setParticleIndex(int idx, int val){ p_part_index.at(idx)=val;}
                    void addTypesIndexes(std::vector<int> newtypes, std::vector<int> newids);

                    void addFoundType( int idx=-1){          p_found_types.push_back(idx); }
                     int getFoundType( int idx=-1){ return(  p_found_types.at(idx)      ); }
                    void addFoundIndex(int idx=-1){          p_found_idxs.push_back(idx); }

        std::vector<int> getFoundVector(){   return p_found_idxs; }
                    void setFoundVectors(std::vector<int> *vec, std::vector<int> *typ, std::vector<int> *vec_idx_orig ){ 
                                                                    p_found_idxs=*vec; p_found_types=*typ; p_found_orig_idxs=*vec_idx_orig; }
                    void clearFoundVector(){ p_found_idxs.clear();  p_found_types.clear(); }
                    int  getOrigFoundIndexes(int idx=-1){ if (idx<0) {return p_found_orig_idxs.size();  }else{return p_found_orig_idxs[idx]; } }
                    void clearOrigFoundVector(){ p_found_orig_idxs.clear(); }
                    void addOrigFoundVector(int val){ p_found_orig_idxs.push_back(val); }
                     int getSearchableType(int idx=-1);

                    void setForbiddenVector(std::vector< std::pair<int, int> > *vec ){ p_forbidden=*vec; }
      std::pair<int,int> getForbiddenPair(int idx=-1){ if (idx<0) {return std::make_pair(p_forbidden.size(), p_forbidden.size() ); }else{return p_forbidden[idx];} }
                    bool isForbidden(int, int);
                    bool normal_op;
                    bool find(AnalysisObjects *ao);
                   float cxcalc(AnalysisObjects *ao, std::vector<int> *param);

                    void addString(std::string v){p_toEvaluate+=v;}
             std::string getString(){return p_toEvaluate;}

                   void addParam(int v){p_params.push_back(v);}
        std::vector<int> * getParams(){return &p_params; }

                    void addArithOp(char v){p_arith_ops.push_back(v);}
                    char getLastArithOp(){return p_arith_ops.back();}

                    void addArithVal(float v){p_arith_vals.push_back(v);}
                   float getArithVals(int v=-1){if (v<0) {return p_arith_vals.size();} else { return p_arith_vals[v];  }; }
                    bool isSpecial(int order=1);
                   float doArithOps(float v, int order=1, float vt=0);

                    int  getNpart(){return p_Npart;}
                    void addApart(){p_Npart++;}

                    void clearFoundResults();
                    void useFoundResults();
                    bool Ccompare(float v);
     std::vector<dbxJet> tagJets(AnalysisObjects *ao, int jtype=1);
             dbxParticle partConstruct(AnalysisObjects *ao, int order=1 );
            virtual bool select(AnalysisObjects *){std::cout << "Cut Mother class, inhereted SELECT NOT implemented.\n"; return 0;}
           virtual float calc(AnalysisObjects *  ){std::cout << "Cut Mother class, inhereted CALC NOT implemented.\n"; return 0;}
private:
             std::string p_toEvaluate;
             std::string p_name;
             std::string p_oper;
                     int p_cuti;
                     int p_Npart;
                    bool p_searchable;
             std::string p_parts;
std::vector<std::pair<int, int> > p_forbidden; 
        std::vector<int> p_part_type, p_params;
        std::vector<int> p_part_index;
        std::vector<int> p_searchable_types;
        std::vector<int> p_found_idxs, p_found_types, p_found_orig_idxs;
        std::vector<int> p_keep_idx, p_keep_vals;
      std::vector<float> p_arith_vals;
       std::vector<char> p_arith_ops;
                   float p_cutf, p_min, p_max, p_precalc;
//std::vector<dbxParticle> aparticle;
            dbxParticle *aparticle;
             dbxParticle myPart, met4v;
          TLorentzVector ametlv;
    
       ClassDef(dbxCut,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ FillHistos
class dbxCutFillHistos : public dbxCut {
 public:
      dbxCutFillHistos( ): dbxCut("FillHistos"){}
      dbxCutFillHistos( int i): dbxCut("FillHistos", i){}
      bool select(AnalysisObjects *){ return 1; } // always pass 
private:
       ClassDef(dbxCutFillHistos,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ALL
class dbxCutALL : public dbxCut {
 public:
      dbxCutALL( ): dbxCut("ALL"){}
      dbxCutALL( int i): dbxCut("ALL", i){}
      bool select(AnalysisObjects *){ return 1; } // always pass 
private:
       ClassDef(dbxCutALL,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NELE
class dbxCutNEle : public dbxCut {
 public:
      dbxCutNEle( ): dbxCut("nELE"){}
      dbxCutNEle( int i): dbxCut("nELE", i){}
      float  calc(AnalysisObjects *ao){ return (ao->eles.size()); } 
      bool select(AnalysisObjects *ao){ return Ccompare(ao->eles.size()); } 
private:
       ClassDef(dbxCutNEle,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NMUO
class dbxCutNMu : public dbxCut {
 public:
      dbxCutNMu( ): dbxCut("nMUO"){}
      dbxCutNMu( int i): dbxCut("nMUO", i){}
      float  calc(AnalysisObjects *ao){ return (ao->muos.size()); } 
      bool select(AnalysisObjects *ao){ return Ccompare(ao->muos.size() ); } 
private:
       ClassDef(dbxCutNMu,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NJET
class dbxCutNJet : public dbxCut {
 public:
      dbxCutNJet( ): dbxCut("nJET"){}
      dbxCutNJet( int i): dbxCut("nJET", i){}
      float  calc(AnalysisObjects *ao){ return (ao->jets.size()); } 
      bool select(AnalysisObjects *ao){ return Ccompare(ao->jets.size() ); } 
private:
       ClassDef(dbxCutNJet,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NPHO
class dbxCutNPho : public dbxCut {
 public:
      dbxCutNPho( ): dbxCut("nPHO"){}
      dbxCutNPho( int i): dbxCut("nPHO", i){}
      float  calc(AnalysisObjects *ao){ return (ao->gams.size()); } 
      bool select(AnalysisObjects *ao){ return Ccompare(ao->gams.size() ); } 
private:
       ClassDef(dbxCutNPho,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Trig
class dbxCutTrig : public dbxCut {
 public:
      dbxCutTrig( ): dbxCut("Trig"){}
      dbxCutTrig( int i): dbxCut("Trig", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=dbxCut::getCi();
                     if ((TrigType>0) && (TrigType<4) ) return (ao->evt.TRG_m>0);  //mu
                     if ((TrigType>3) && (TrigType<16)) return (ao->evt.TRG_e>0);  //e
                     return 0;         }//default fail
private:
       ClassDef(dbxCutTrig,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ VtxTrks
class dbxCutVtxTrks : public dbxCut {
 public:
      dbxCutVtxTrks( ): dbxCut("VtxTrks"){}
      dbxCutVtxTrks( int i): dbxCut("VtxTrks", i){}
      bool select(AnalysisObjects *ao){ return ((ao->evt.vxpType == 1 || ao->evt.vxpType != 3) 
                                               && Ccompare(ao->evt.vxp_maxtrk_no) );  }
private:
       ClassDef(dbxCutVtxTrks,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NLEP
class dbxCutNLEP : public dbxCut {
 public:
      dbxCutNLEP( ): dbxCut("nLEP"){}
      dbxCutNLEP( int i): dbxCut("nLEP", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=getCi();
                     if ((TrigType>0) && (TrigType<4) ) return (Ccompare(ao->muos.size())); //  e.g. >=1mu in muon channel
                     if ((TrigType>3) && (TrigType<16)) return (Ccompare(ao->eles.size())); //  e.g.  >= 1e in e channel
                     return 0;         }//default fail
private:
       ClassDef(dbxCutNLEP,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ QQLEP
class dbxCutQQLEP : public dbxCut {
 public:
      dbxCutQQLEP( ): dbxCut("qLEP.qLEP"){}
      dbxCutQQLEP( int i): dbxCut("qLEP.qLEP", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=getCi();
                     if ((TrigType>0) && (TrigType<4) ) return (Ccompare(ao->muos[0].q() * ao->muos[1].q() )); //  in muon channel
                     if ((TrigType>3) && (TrigType<16)) return (Ccompare(ao->eles[0].q() * ao->eles[1].q() )); //   in e channel
                     return 0;         }//default fail
private:
       ClassDef(dbxCutQQLEP,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ m2LEP
class dbxCutm2LEP : public dbxCut {
 public:
      dbxCutm2LEP( ): dbxCut("m2LEP"){}
      dbxCutm2LEP( int i): dbxCut("m2LEP", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=getCi();
                     dbxParticle ZReco; 
                     if ((TrigType>0) && (TrigType<4) ) ZReco=(ao->muos[0] + ao->muos[1] ); //  in muon channel
                     if ((TrigType>3) && (TrigType<16)) ZReco=(ao->eles[0] + ao->eles[1] ); //   in e channel
                     return (Ccompare (ZReco.lv().M() ) );
      }//end of selection
private:
       ClassDef(dbxCutm2LEP,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ pt2LEP
class dbxCutpt2LEP : public dbxCut {
 public:
      dbxCutpt2LEP( ):      dbxCut("pt2LEP"){}
      dbxCutpt2LEP( int i): dbxCut("pt2LEP", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=getCi();
                     dbxParticle ZReco; 
                     if ((TrigType>0) && (TrigType<4) ) ZReco=(ao->muos[0] + ao->muos[1] ); //  in muon channel
                     if ((TrigType>3) && (TrigType<16)) ZReco=(ao->eles[0] + ao->eles[1] ); //   in e channel
                     return (Ccompare (ZReco.lv().Pt() ) );
      }//end of selection
private:
       ClassDef(dbxCutpt2LEP,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TrigMatch
class dbxCutTrigMatch : public dbxCut {
 public:
      dbxCutTrigMatch( ): dbxCut("TrigMatch"){}
      dbxCutTrigMatch( int i): dbxCut("TrigMatch", i){}
      bool select(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=dbxCut::getCi();
                     if ((TrigType>0) && (TrigType<4) ) return (ao->muos[0].MuTriggerMatch()); //muon channel
                     if ((TrigType>3) && (TrigType<16)) return (ao->eles[0].ElTriggerMatch()); //e channel
                     return 0;         }//default fail
private:
       ClassDef(dbxCutTrigMatch,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LEPsf
class dbxCutLEPsf : public dbxCut {
 public:
      dbxCutLEPsf( ): dbxCut("LEPsf"){}
      dbxCutLEPsf( int i): dbxCut("LEPsf", i){}
      bool select(AnalysisObjects *){ //depends on trigger type set previously
                     return 1;         }//default PASS
private:
       ClassDef(dbxCutLEPsf,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ R2LEPJ0
class dbxCutR_Z_J0 : public dbxCut {
 public:
      dbxCutR_Z_J0( ): dbxCut("R2LEPJ0"){}
      dbxCutR_Z_J0( int i): dbxCut("R2LEPJ0", i){}
      bool select(AnalysisObjects *ao){
                   return (Ccompare( calc(ao) ) );
                 } 
      float  calc(AnalysisObjects *ao){ //depends on trigger type set previously
                     dbxParticle ZReco; 
                     int TrigType=dbxCut::getCi();
                     if ((TrigType>0) && (TrigType<4) ) ZReco=(ao->muos[0] + ao->muos[1] ); //  in muon channel
                     if ((TrigType>3) && (TrigType<16)) ZReco=(ao->eles[0] + ao->eles[1] ); //   in e channel
                     return (ZReco.lv().DeltaR( ao->jets.at(0).lv() ) );
     }
private:
       ClassDef(dbxCutR_Z_J0,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MET
class dbxCutMET : public dbxCut {
 public:
      dbxCutMET( ): dbxCut("MET"){}
      dbxCutMET( int i): dbxCut("MET", i){}
      float  calc(AnalysisObjects *ao){ 
                     return (ao->met.Mod() );         }
      bool select(AnalysisObjects *ao){ 
                     return (Ccompare(ao->met.Mod()) );         }
private:
       ClassDef(dbxCutMET,1);
};	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MWT
class dbxCutMWT : public dbxCut {
 public:
      dbxCutMWT( ): dbxCut("MWT"){}
      dbxCutMWT( int i): dbxCut("MWT", i){}
      bool select(AnalysisObjects *ao){
                   return (Ccompare( calc(ao) ) );
                 } 
      float  calc(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=dbxCut::getCi();
                     double leppt=-99.99;
                     double theLeptonTrkPhi = -99.99;
                     if ((TrigType>0) && (TrigType<4) ) { //mu channel
                        theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
                                  leppt = ao->muos.at(0).lv().Pt();
                     }
                     if ((TrigType>3) && (TrigType<16)) { //e channel
                        theLeptonTrkPhi = ao->eles.at(0).TrkPhi();
                                  leppt = ao->eles.at(0).lv().Pt();
                     }
                     double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
                     if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
                     float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
                     return (mwt);         
           }
private:
       ClassDef(dbxCutMWT,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ METMWT
class dbxCutMETMWT : public dbxCut {
 public:
      dbxCutMETMWT( ): dbxCut("METMWT"){}
      dbxCutMETMWT( int i): dbxCut("METMWT", i){}
      bool select(AnalysisObjects *ao){
                   return (Ccompare( calc(ao) ) );
                 } 
      float  calc(AnalysisObjects *ao){ //depends on trigger type set previously
                     int TrigType=dbxCut::getCi();
                     double leppt=-99.99;
                     double theLeptonTrkPhi = -99.99;
                     if ((TrigType>0) && (TrigType<4) ) { //mu channel
                        theLeptonTrkPhi = ao->muos.at(0).lv().Phi();
                                  leppt = ao->muos.at(0).lv().Pt();
                     }
                     if ((TrigType>3) && (TrigType<16)) { //e channel
                        theLeptonTrkPhi = ao->eles.at(0).TrkPhi();
                                  leppt = ao->eles.at(0).lv().Pt();
                     }
                     double dphi_e_et = fabs(theLeptonTrkPhi - ao->met.Phi());
                     if (dphi_e_et>M_PI) dphi_e_et=2*M_PI-dphi_e_et;
                     float mwt=sqrt(2*leppt*ao->met.Mod()*(1-cos(dphi_e_et)));
                     return (mwt+ao->met.Mod() );         
      }
private:
       ClassDef(dbxCutMETMWT,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ nQGJET
class dbxCutnQGJet : public dbxCut {
 public:
      dbxCutnQGJet( ): dbxCut("nQGJET"){}
      dbxCutnQGJet( int i): dbxCut("nQGJET", i){}
      bool select(AnalysisObjects *ao){
                   return (Ccompare( calc(ao) ) );
                 } 
      float  calc(AnalysisObjects *ao){ 
                   int lightj_found=0;
                   for (UInt_t i=0; i<ao->jets.size(); i++) { 
                        if (ao->jets.at(i).isbtagged_77() == 0 ) {lightj_found++;} }
                   return (lightj_found  );         }
private:
       ClassDef(dbxCutnQGJet,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ nBJET
class dbxCutnBJet : public dbxCut {
 public:
      dbxCutnBJet( ): dbxCut("nBJET"){}
      dbxCutnBJet( int i): dbxCut("nBJET", i){}
      bool select(AnalysisObjects *ao){
                   return (Ccompare( calc(ao) ) );
                 } 
      float  calc(AnalysisObjects *ao){ 
                   int bj_found=0;
                   for (UInt_t i=0; i<ao->jets.size(); i++) { 
                        if (ao->jets.at(i).isbtagged_77() == 1 ) {bj_found++;} }
                   return (bj_found  );         }
private:
       ClassDef(dbxCutnBJet,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SumHTJET
class dbxCutSumHTJET : public dbxCut {
 public:
      dbxCutSumHTJET( ): dbxCut("SumHTJET"){}
      dbxCutSumHTJET( int i): dbxCut("SumHTJET", i){}
      float calc(AnalysisObjects *ao){ 
                   double sum_htjet=0;
                   for (UInt_t i=0; i<ao->jets.size(); i++) sum_htjet+=ao->jets.at(i).lv().Pt();
                   return (sum_htjet  );         }
      bool select(AnalysisObjects *ao){ 
                   double sum_htjet=0;
                   for (UInt_t i=0; i<ao->jets.size(); i++) sum_htjet+=ao->jets.at(i).lv().Pt();
                   return (Ccompare(sum_htjet ) );         }
private:
       ClassDef(dbxCutSumHTJET,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Number of /////// we dont want "normal" op
class dbxCutNof : public dbxCut {
 public:
      dbxCutNof( ): dbxCut("}N"){}
      dbxCutNof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}N",ts,is,v){}
      
      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutNof,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Phiof
class dbxCutPhiof : public dbxCut {
 public:
      dbxCutPhiof( ): dbxCut("}Phi"){normal_op=true;}
      dbxCutPhiof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}Phi",ts,is,v){normal_op=true;}
      
      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutPhiof,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Etatof
class dbxCutEtaof : public dbxCut {
 public:
      dbxCutEtaof( ): dbxCut("}Eta"){normal_op=true;}
      dbxCutEtaof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}Eta",ts,is,v){normal_op=true;}
      
      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutEtaof,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Ptof
class dbxCutPtof : public dbxCut {
 public:
      dbxCutPtof( ): dbxCut("}Pt"){normal_op=true;}
      dbxCutPtof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}Pt",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutPtof,1);
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Qof
class dbxCutQof : public dbxCut {
 public:
      dbxCutQof( ): dbxCut("}q"){normal_op=true;}
      dbxCutQof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}q",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutQof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Pzof
class dbxCutPzof : public dbxCut {
 public:
      dbxCutPzof( ): dbxCut("}Pz"){normal_op=true;}
      dbxCutPzof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}Pz",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutPzof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Pof
class dbxCutPof : public dbxCut {
 public:
      dbxCutPof( ): dbxCut("}P"){normal_op=true;}
      dbxCutPof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}P",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutPof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Eof
class dbxCutEof : public dbxCut {
 public:
      dbxCutEof( ): dbxCut("}E"){normal_op=true;}
      dbxCutEof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}E",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutEof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Mof
class dbxCutMof : public dbxCut {
 public:
      dbxCutMof( ): dbxCut("}m"){normal_op=true;}
      dbxCutMof(std::vector<int> ts, std::vector<int> is,int v ): dbxCut("}m",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
     float calc(AnalysisObjects *ao); 
private:
       ClassDef(dbxCutMof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Rof
class dbxCutdRof : public dbxCut {
 public:
      dbxCutdRof( ): dbxCut("}dR"){normal_op=true;}
      dbxCutdRof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}dR",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
      float calc(AnalysisObjects *ao);
private:
       ClassDef(dbxCutdRof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ dPhiof
class dbxCutdPhiof : public dbxCut {
 public:
      dbxCutdPhiof( ): dbxCut("}dPhi"){normal_op=true;}
      dbxCutdPhiof(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}dPhi",ts,is,v){normal_op=true;}

      bool select(AnalysisObjects *ao);
      float calc(AnalysisObjects *ao);
private:
       ClassDef(dbxCutdPhiof,1);
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ListClass
class dbxCutList : public TObject {
  public:
        dbxCutList(){
                    TrigType=0; // no trigger
	            cutlist.push_back(new dbxCutALL());
	            cutlist.push_back(new dbxCutFillHistos());
	            cutlist.push_back(new dbxCutNEle());
	            cutlist.push_back(new dbxCutNMu());
	            cutlist.push_back(new dbxCutNJet());
	            cutlist.push_back(new dbxCutNPho());
	            cutlist.push_back(new dbxCutNLEP());
	            cutlist.push_back(new dbxCutQQLEP());
	            cutlist.push_back(new dbxCutm2LEP());
	            cutlist.push_back(new dbxCutpt2LEP());
	            cutlist.push_back(new dbxCutTrig());
	            cutlist.push_back(new dbxCutVtxTrks());
   		    cutlist.push_back(new dbxCutTrigMatch());
                    cutlist.push_back(new dbxCutLEPsf());
                    cutlist.push_back(new dbxCutR_Z_J0());
                    cutlist.push_back(new dbxCutMET());
                    cutlist.push_back(new dbxCutMWT());
                    cutlist.push_back(new dbxCutMETMWT());
                    cutlist.push_back(new dbxCutnBJet());
                    cutlist.push_back(new dbxCutnQGJet());
                    cutlist.push_back(new dbxCutSumHTJET());
                    cutlist.push_back(new dbxCutQof());
                    cutlist.push_back(new dbxCutPtof());
                    cutlist.push_back(new dbxCutEtaof());
                    cutlist.push_back(new dbxCutPhiof());
                    cutlist.push_back(new dbxCutNof());
                    cutlist.push_back(new dbxCutMof());
                    cutlist.push_back(new dbxCutEof());
                    cutlist.push_back(new dbxCutPof());
                    cutlist.push_back(new dbxCutPzof());
                    cutlist.push_back(new dbxCutdRof());
                    cutlist.push_back(new dbxCutdPhiof());

        }
       ~dbxCutList(){}
        void setTrigType(int t){ TrigType=t; }
        std::vector<std::string> cutTokenizer(std::string s, std::vector<dbxCut*> *mycut);
  private:
        std::vector<dbxCut*> cutlist;
        int TrigType;
        ClassDef(dbxCutList,1);
};


#endif
