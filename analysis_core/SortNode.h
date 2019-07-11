//  SortNode.h
//  
//  Created by Arpon Paul on 11/07/2019.
//

#ifndef SortNode_h
#define SortNode_h

#include <stdio.h>
#include <math.h>
#include <list>
#include <unordered_set>
#include "myParticle.h"
#include "Node.h"


using namespace std;

//takes care of Minimizing/Maximizing
class SortNode : public Node{
private:
    double (*f)();

    std::vector<myParticle *> particles;//pointers to particles in all nodes that have to be changed
public:
    SortNode(Node* funcVal, std::string s);
    virtual double evaluate(AnalysisObjects* ao) override;
    virtual void getParticles(std::vector<myParticle *>* particles) override;
    virtual void getParticlesAt(std::vector<myParticle *>* particles, int index) override;
    virtual void Reset() override;     
    virtual ~SortNode() ;

};


#endif
