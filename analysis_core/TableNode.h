//
//  TableNode.h
//  mm
//
//  Created by ngu  on Oct19.
//  Copyright © 2019 . All rights reserved.
//

#ifndef TableNode_h
#define TableNode_h

#include <stdio.h>
#include <math.h>
#include "Node.h"
//takes care of Table Operations
//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


class TableNode : public Node{
private:
    double (*f)(double, AnalysisObjects* );
    std::vector<float>   atable;
    std::vector<float> errtable;
    Node* left2;
    bool errors; 

public:
    TableNode(double (*func)(double, AnalysisObjects*), 
              Node* l, std::pair<std::vector<float>, bool> tabe, std::string s){
        f=func;
        symbol=s;
        left=l;
        left2=NULL;
        errors=tabe.second;
        right=NULL;
        if (errors){
          for (int ii=0; ii<tabe.first.size(); ii+=5){
           atable.push_back( tabe.first[ii]);
           errtable.push_back( tabe.first[ii+1]);
           errtable.push_back( tabe.first[ii+2]);
           atable.push_back( tabe.first[ii+3]);
           atable.push_back( tabe.first[ii+4]);
          }
        } else {
          atable=tabe.first;
        }
    }
    TableNode(double (*func)(double, AnalysisObjects*), 
              Node* l, Node* l2, std::pair<std::vector<float>, bool> tabe, std::string s){
        f=func;
        symbol=s;
        left=l;
        left2=l2;
        errors=tabe.second;
        right=NULL;
        if (errors){
          for (int ii=0; ii<tabe.first.size(); ii+=7){
           atable.push_back( tabe.first[ii]);
           errtable.push_back( tabe.first[ii+1]);
           errtable.push_back( tabe.first[ii+2]);
           atable.push_back( tabe.first[ii+3]);
           atable.push_back( tabe.first[ii+4]);
           atable.push_back( tabe.first[ii+5]);
           atable.push_back( tabe.first[ii+6]);
          }
        } else {
          atable=tabe.first;
        }
    }

    virtual double evaluate(AnalysisObjects* ao) override;

    virtual void getParticles(std::vector<myParticle *>* particles) override{
          left->getParticles(particles);
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{
        left->getParticlesAt(particles,index);
    }
    virtual void Reset() override{
        left->Reset();
    }
    virtual ~TableNode() {
        if (left!=NULL) delete left;
    }
};

double tweight(double value, AnalysisObjects* ao ) ;
double thitmiss(double value, AnalysisObjects* ao ) ;

#endif /* TableNode */
