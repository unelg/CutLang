#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include "Node.h"
//takes care of Minimizing/Maximising
class SearchNode : public Node{
private:
    double (*f)(double, double);
public:
    SearchNode(double (*func)(double, double), Node* l, Node* r, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=r;
    }

    virtual double evaluate(AnalysisObjects* ao){
            //std::vector<myParticle>* particles=((FuncNode*)left)->getParticles();
            FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            std::vector<myParticle>* particles=funcnode->getParticles();
            list<int> indices;
            for(int i=0;i<particles->size();i++){
                if(particles->at(i).index<0) indices.push_back(i);
            }
            int level=indices.size();

            
            return (*f)(left->evaluate(ao),right->evaluate(ao));
   
    }
    virtual ~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }

};
#endif
