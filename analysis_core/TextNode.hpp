
#ifndef text_hpp
#define text_hpp

#include <stdio.h>
#include <math.h>
#include <limits>
#include "Node.h"


//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

//takes care of text
class TextNode : public Node{
private:
public:
    TextNode(Node* l, std::string s){
        symbol=s;
        left=l;
    }

    virtual void getParticles(std::vector<myParticle *>* particles) override{
//        left->getParticles(particles);
        
    }

    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{
          particles->clear();
//        left->getParticlesAt(particles,index);
    }
    virtual void Reset() override{
//        left->Reset();
    }
    virtual double evaluate(AnalysisObjects* ao) override{

//            cout <<symbol;
         return std::numeric_limits<double>::quiet_NaN();
    }
    virtual ~TextNode() {
    }

};

#endif 
