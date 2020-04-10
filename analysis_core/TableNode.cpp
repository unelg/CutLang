//
//  TableNode.cpp
//  mm
//
//  Created by ngu  on Oct19.
//  Copyright © 2019 . All rights reserved.
//

#ifndef TableNode_cpp
#define TableNode_cpp

#include <stdio.h>
#include <math.h>
#include "TableNode.h"
#include <TF1.h>
//takes care of Table Operations
//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


//---------EVALUATE---------
double TableNode::evaluate(AnalysisObjects* ao) {
            double aval=left->evaluate(ao);
            double bval, tval; 
            bool range_found=false;
            int it;

            if (left2==NULL){ // 1D
              for (it=0; it<atable.size(); it+=3){ // 3 is for 1D only. value, min, max.
               if ( aval>=atable[it+1] && aval<atable[it+2]){
                range_found=true;
                tval=atable[it];
                DEBUG("aval:"<<aval<<" tval:"<<tval<<"\n");
                it=(it/3);
                break;
               } 
              }
            }else{ //2D
             bval=left2->evaluate(ao);
             for (it=0; it<atable.size(); it+=5){ // 5 is for 2D only. value, min, max, min2, max2.
               if (aval>=atable[it+1] && aval<atable[it+2] && bval>=atable[it+3] && bval<atable[it+4]){
                range_found=true;
                tval=atable[it];
                DEBUG("aval:"<<aval<< " bval:"<<bval<<"=> tval:"<<tval<<"\n");
                it=(it/5);
                break;
               } 
              }
             
            }// 1D & 2D ends.
            if (!range_found) {std::cerr << "Specified value "<< aval <<" is out of table range! Setting to ZERO.\n"; tval=0;}

            DEBUG(" Error condition:"<<errors<< " it:"<<it<<"\n");
            if (errors){
             double sigleft=errtable[it];
             double sigright=errtable[it+1];
             double Area=sqrt(2/3.14159265)/(sigright+sigleft);
             TString hesap="x>";
                     hesap+=tval;
                     hesap+="?gaus(0):gaus(3)";
             TF1 *f4 = new TF1("f4",hesap,0,1);
             f4->SetParameters(Area,tval,sigleft,Area,tval,sigright);
             DEBUG("err range"<<sigleft<<","<< sigright<<" modified tval:"<<f4->GetRandom()<<"\n"); 
            }

    return (*f)(tval, ao);
    }


double tweight(double value, AnalysisObjects* ao ) {
    ao->evt.user_evt_weight *= value;
    return 1;
}
double thitmiss(double value, AnalysisObjects* ao ) {
    DEBUG( "table hitmiss retval:"<<value<<"\n");
    return value;
}

#endif /* TableNode */
