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

    void performInnerOperation(vector<int> v,vector<int> indices, double current_difference,AnalysisObjects* ao){
        FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            
        cout<<"Replacing\n"<<endl;
        for(int i=0;i<v.size();i++){
            funcnode->setParticleIndex(indices[i],v[i]);
            cout<<funcnode->getParticleIndex(indices[i])<<" : "<<v[i]<<" ";
        }
        double tmpval=left->evaluate(ao);
        double diff=right->evaluate(ao)-tmpval;
            
        if ( (*f)(diff,current_difference) ) {
            current_difference = fabs(diff);
            bestIndices=v;
        }
        cout<<"eND\n\n"<<endl;
    ;
    }

    void runNestedLoop( int start, int N, int level, int maxDepth, vector<int> v,vector<int> indices,double curr_diff,AnalysisObjects* ao) {
    if(level==maxDepth) performInnerOperation (v,indices,curr_diff,ao);
    else{
        for (int x = start; x <= N; x++ ) {
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
            
            DEBUG("Evaluate\n");
            FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            std::vector<myParticle>* particles=funcnode->getParticles();
            vector<int> indices;
            for(int i=0;i<particles->size();i++){
                if(particles->at(i).index<0) indices.push_back(i);
            }

            int MaxDepth=indices.size();//number of nested loops needed
            DEBUG("Depth:"<<MaxDepth<<"\n");
           
            int type=particles->at(indices[0]).type;
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
            DEBUG("Before nesting\n");
            runNestedLoop( 0, Max, 0, MaxDepth, v,indices,current_difference,ao);

            DEBUG("Now use BestIndices \n");
            for(int i=0;i<bestIndices.size();i++){
                funcnode->setParticleIndex(indices[i],bestIndices[i]);
                cout<<funcnode->getParticleIndex(indices[i])<<" : "<<bestIndices[i]<<" ";
            }
            
            return 1;
   
    }
    virtual void Reset(){
            left->Reset();
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
