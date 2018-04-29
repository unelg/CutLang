//How to define an external function?
//write such a .h file and include it in dbxCut.cpp
//
#ifndef DBX_EX1_H
#define DBX_EX1_H

class dbxCutEx1of : public dbxCut {
 public:
      dbxCutEx1of( ): dbxCut("}Meff"){}
      dbxCutEx1of(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}Meff",ts,is,v){}

      bool select(AnalysisObjects *ao){
          float result;
          result=calc(ao);
          return (Ccompare(result) ); 
      }
// 0 is muon // 1 is electron // 8 is gammas      
// 2 is any jet // 3 is a b jet // 4 is light jet
// 7 met

      float calc(AnalysisObjects *ao){
         double meff;
         for (int jj=0; jj<2; jj++)
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
/*
         double meff = ao->met.Mod() ;
         for (int i=0; i<ao->jets.size(); i++) {
               meff += ao->jets[i].lv().Pt();
         }
*/
         return meff;
      }
private:
};


#endif
