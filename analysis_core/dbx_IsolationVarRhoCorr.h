//How to define a user function?
//write such a .h file and include it in dbxCut.cpp
//
#ifndef DBX_ISOLATIONVARRHOCORR_H
#define DBX_ISOLATIONVARRHOCORR_H

class dbxCutIsolationVarRhoCorr : public dbxCut {
 public:
      dbxCutIsolationVarRhoCorr() : dbxCut("IsolationVarRhoCorr"){}
      dbxCutIsolationVarRhoCorr(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("IsolationVarRhoCorr",ts,is,v){}

      bool select(AnalysisObjects *ao){
          float result;
          result=calc(ao);
          return (Ccompare(result) ); 
      }
      float calc(AnalysisObjects *ao){
         float retval=0.0;

         // ***********************************
         // Write your own code here
         // ***********************************
         
         return retval;
}
private:
};

#endif

