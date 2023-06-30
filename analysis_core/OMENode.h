//  
//  OMENode.h
//  Created by 8/7/23.
//

#ifndef OMENode_h
#define OMENode_h
#include "Node.h"

#include <iostream>
#include <fstream>
#include <ios>
#include <stdio.h>
#include <cstdio>

class OMENode : public Node{
private:
      vector<Node*> variableList;
         short int selector;
public:
	OMENode(std::string s, short int sele, vector<Node*> VariableList){
                symbol=s;
                selector=sele;
		left = NULL;
		right = NULL;
                variableList = VariableList;
	}
    virtual void getParticles(std::vector<myParticle *>* particles) override{
                 std::vector<myParticle *>  bparticles;
                 std::vector<myParticle *> *aparticles=&bparticles;
                 variableList[0]->getParticlesAt(aparticles,0);
                  particles->push_back(bparticles[0]);
                 }
    virtual void getParticlesAt(std::vector<myParticle *>* particles,int index) override{
                 std::vector<myParticle *>  bparticles;
                 std::vector<myParticle *> *aparticles=&bparticles;
                 variableList[0]->getParticlesAt(aparticles,0);
                  particles->push_back(bparticles[index]);
                 }
    virtual void Reset() override{}
    virtual double evaluate(AnalysisObjects* ao) override {
           std::vector<myParticle *>  bparticles;
           std::vector<myParticle *> *aparticles=&bparticles;
// .........vector<Node*> variableList;
            for (int i = 0; i < (int)variableList.size(); i++)
            {
                variableList[i]->getParticlesAt(aparticles,0);
                //std::cout<< aparticles->at(i)->index <<"c "; // what if we have 0 particles?
                std::cout<< variableList[i]->evaluate(ao) << " , ";
            }
            std::cout << "\n";
            return 1;
        
    }
    virtual ~OMENode() {}
};

#endif // OMENode_h
