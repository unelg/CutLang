//How to define an external function?
//write such a .h file and include it in dbxCut.cpp
//
#ifndef DBX_EX1_H
#define DBX_EX1_H

class dbxCutEx1of : public dbxCut {
 public:
      dbxCutEx1of( ): dbxCut("Ex1"){}
      dbxCutEx1of(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("Ex1",ts,is,v){}

      bool select(AnalysisObjects *ao){
          float result;
          result=calc(ao);
          return (Ccompare(result) ); 
      }
// 0 is muon // 1 is electron // 8 is gammas      
// 2 is any jet // 3 is a b jet // 4 is light jet
// 7 met

      float calc(AnalysisObjects *ao){
/*
         double meff=0;
         for (unsigned int jj=0; jj<2; jj++)
           switch (getParticleType(jj*2)){

            case 0: for (int ii=0; ii<ao->muos.size(); ii++) meff+=ao->muos[ii].lv().Pt();
                    break;
            case 1: for (int ii=0; ii<ao->eles.size(); ii++) meff+=ao->eles[ii].lv().Pt();
                    break;
            case 2: for (int ii=0; ii<ao->jets.size(); ii++) meff+=ao->jets[ii].lv().Pt();
                    break;
            case 3: for (int ii=0; ii<tagJets(ao,1).size(); ii++) meff+=tagJets(ao,1)[ii].lv().Pt();
                    break;
            case 4: for (int ii=0; ii<tagJets(ao,0).size(); ii++) meff+=tagJets(ao,0)[ii].lv().Pt();
                    break;
            case 7: meff+=ao->met.Mod();
                    break;
            case 8: for (int ii=0; ii<ao->gams.size(); ii++) meff+=ao->gams[ii].lv().Pt();
                    break;
         }
*/
         int maxJ=ao->jets.size();
         if (maxJ>3) maxJ=3;
         double dphimin=999;
         TLorentzVector ametlv;
         for (int i=0; i<maxJ; i++) {
               ametlv.SetPxPyPzE(ao->met.Px(), ao->met.Py(), 0, ao->met.Mod());
               double dphi = fabs(ao->jets[i].lv().DeltaPhi( ametlv ) );
               std::cout <<"\n i:"<<i<<" dphi:"<<dphi<<"\t";
               if (dphi < dphimin) dphimin = dphi;
         }
         std::cout <<" min:"<<dphimin<<"\n";
         return dphimin;
      }
private:
};


#endif
