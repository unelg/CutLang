//
//  Node.h
//  mm
//
//  Created by Anna-Monica  on 7/31/18.
//  Copyright © 2018 Anna-Monica. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <string>
#include <iostream>
//generic node interface
class Node{
protected:
    Node* left;
    Node* right;
    std::string symbol;
    void display(std::string indent){
        if(left!=NULL) left->display(indent+"     ");
        std::cout<<indent+symbol<<std::endl;
        if(right!=NULL) right->display("\n"+indent+"     ");
    }
public:
    void display(){
        this->display("");
    }
    virtual double evaluate()=0;
    
    virtual ~ Node(){
    }
};

struct AnalysisObjects {
    std::vector<dbxMuon>     muos;
    std::vector<dbxElectron> eles;
    std::vector<dbxPhoton>   gams;
    std::vector<dbxJet>      jets;
    TVector2            met;
    evt_data            evt;
};


#endif /* Node_h */
