#ifndef SearchNode_h
#define SearchNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include "Node.h"
#define _CLV_

//takes care of Minimizing/Maximizing
class SearchNode : public Node{
private:
    double (*f)(double, double);

    void performInnerOperation(vector<int> v){
        for(auto i=v.begin();i!=v.end();i++){
            cout<<*i<<" ";
        }
        cout<<"END"<<endl;
    ;
    }

    void runNestedLoop( int start, int N, int level, int maxDepth, vector<int> v) {
    if(level==maxDepth) performInnerOperation (v);
    else{
        for (int x = start; x <= N; x++ ) {
            //check if particle x is forbidden
            v.push_back(x); //add the current value
            runNestedLoop( x+1 , N, level + 1, maxDepth, v );
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
            //std::vector<myParticle>* particles=((FuncNode*)left)->getParticles();
            FuncNode* funcnode=dynamic_cast<FuncNode*>(left);
            std::vector<myParticle>* particles=funcnode->getParticles();
            list<int> indices;
            for(int i=0;i<particles->size();i++){
                if(particles->at(i).index<0) indices.push_back(i);
            }
            int MaxDepth=indices.size();//number of nested loops needed

            



//-------------replace negative indices
              tmpval=evaluate(ao);

           if ( (*f)() ) {
              current_difference = fabs(target-tmpval);
              save_current_indices;
           }


//------------LOOPS end here

            
            return (*f)(left->evaluate(ao),right->evaluate(ao));
   
    }

    virtual ~SearchNode() {
//        if (left!=NULL) delete left;
//        if (right!=NULL) delete right;
    }

};

double maxim( double tmpval, double current_difference){
    return (fabs(target-tmpval) > current_difference );
}

double minim( double tmpval, double current_difference){
    return (fabs(target-tmpval) < current_difference );
}

#endif
