#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include "Node.h"

#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif


//takes care of Minimizing/Maximizing
class SearchNode : public Node{
private:
    double (*f)(double, double);
    vector<int> bestIndices;

    void performInnerOperation(vector<int> v,vector<int> indices, double *current_difference,AnalysisObjects* ao){
        FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            
        for(int i=0;i<v.size();i++){
            funcnode->setParticleIndex(indices[i],v[i]);
            DEBUG(funcnode->getParticleIndex(indices[i])<<" : "<<v[i]<<" ");
        }
        double tmpval=left->evaluate(ao);
        double diff=right->evaluate(ao)-tmpval;
            
        if ( (*f)(diff,*current_difference) ) {
            DEBUG("diff:"<<diff<<" c_diff:"<<*current_difference<<"\n");
            *current_difference = fabs(diff);
            bestIndices=v;
        }
    }

    void runNestedLoop( int start, int N, int level, int maxDepth, vector<int> v,vector<int> indices,double *curr_diff,AnalysisObjects* ao) {
    if(level==maxDepth) performInnerOperation (v,indices,curr_diff,ao);
    else{
        for (int x = start; x < N; x++ ) {
            //check if particle x is forbidden
            v.push_back(x); //add the current value
            runNestedLoop( x+1 , N, level + 1, maxDepth, v,indices, curr_diff,ao );
            v.pop_back();//remove the value
        }
    }
}


public:

    SearchNode(double (*func)(double, double), Node* l, Node* r, std::string s){
        f=func;
        symbol=s;
        left=l;
        right=r;
    }

    virtual double evaluate(AnalysisObjects* ao){
            
            DEBUG("Evaluate 1\n");
            FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            DEBUG("Evaluate 2\n");
            std::vector<myParticle *>* particles=funcnode->getParticles();
            DEBUG("Evaluate 3\n");
            vector<int> indices;
            for(int i=0;i<particles->size();i++){
                DEBUG("Part:"<<i<<"  idx:"<<particles->at(i)->index<<"\n");
                if(particles->at(i)->index<0) indices.push_back(i);
            }

            int MaxDepth=indices.size();//number of nested loops needed
            DEBUG("Depth:"<<MaxDepth<<"\n");
                      
            int type=particles->at(indices[0])->type;
            int Max;
            switch(type){
                case 0: Max=ao->muos.size();break;
                case 1: Max=ao->eles.size();break;
                case 2: Max=ao->jets.size();break;
                case 3: Max=funcnode->tagJets(ao,1).size();break;
                case 4: Max=funcnode->tagJets(ao,0).size();break;
            }
            vector<int> v;
            double current_difference =1000;
            runNestedLoop( 0, Max, 0, MaxDepth, v,indices, &current_difference,ao);

            for(int i=0;i<bestIndices.size();i++){
                funcnode->setParticleIndex(indices[i],bestIndices[i]);
                DEBUG("BEST"<<funcnode->getParticleIndex(indices[i])<<" : "<<bestIndices[i]<<" ");
            }
            DEBUG("\n");
            return 1;
   
    }
    virtual void Reset(){
            ((FuncNode*)left)->ResetParticles();
    }

    virtual ~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }

};

double maxim( double difference, double current_difference){
    return (fabs(difference) > current_difference );
}

double minim( double difference, double current_difference){
    return fabs(difference) < current_difference ;
}

#endif
