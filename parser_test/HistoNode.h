//
//  HistoNode.h
//  mm
//
//  Created by Anna-Monica  on 8/6/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef HistoNode_h
#define HistoNode_h
#include "Node.h"
#include <string>
class HistoNode : public Node{
private:
    std::string id;
    std::string Desciption;
    int lowerLimit;
    int upperLimit;
    int bins;
public:
    HistoNode( std::string id,std::string desc,int l1,int l2,int n,Node* l){
        this->id=id;
        Desciption=desc;
        lowerLimit=l1;
        upperLimit=l2;
        bins=n;
        symbol="histo "+id+","+Desciption+","+std::to_string(l1)+","+std::to_string(l2)+","+std::to_string(n);
        left=l;
        right=NULL;
    }
    
    virtual double evaluate() {
        std::cout<<"\nHisto should evaluate and fill ";
        return left->evaluate();

    }
    virtual ~HistoNode() {
        if (left!=NULL) delete left;
    }
    
};

#endif /* HistoNode_h */
