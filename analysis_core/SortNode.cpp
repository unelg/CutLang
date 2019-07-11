//  SortNode.cpp
//
//  Created by Arpon Paul on 11/07/2019.
//


#include "SortNode.h"
#include "FuncNode.h"
//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

using namespace std;




SortNode::SortNode(Node* funcVal, std::string s)
{
    symbol=s;   //symbol = "ascend" for ascending sorting, "descend" for descending sorting
    left=funcVal; //FuncNode for the function value (i.e the criteria of sorting)
    right=NULL;
}

double SortNode::evaluate(AnalysisObjects* ao)
{
    DEBUG("---------------"<<getStr()<<"\n");
    particles.clear();
    DEBUG(" LoopF2:\n");
    left->getParticles(&particles);//should fill with particles pointers no more cast needed
    DEBUG(" LoopF3:\n");


    int type=particles.at(0)->type;
    string ac=particles.at(0)->collection;
    int Max; //Total number of particles of the selected type
    switch(type) //assuming all particles have the same type
    {
    case 0:
        Max=ao->muos[ac].size();
        break;
    case 1:
        Max=ao->eles[ac].size();
        break;
    case 2:
        Max=ao->jets[ac].size();
        break;
    case 3:
        Max=left->tagJets(ao,1,ac).size();
        break;
    case 4:
        Max=left->tagJets(ao,0,ac).size();
        break;

			case 8: Max=ao->gams[ac].size();break;
			case 11: Max=ao->taus[ac].size();break;
			case 20: Max=ao->combos[ac].size();break;
    }
    double tempFuncVal[Max]; //temporarily stores the function values for the selected type particles
//    cout<<"N = "<<Max<<endl;
//    cout<<"Before sorting : "<<endl;
    for (int i = 0; i < Max; i++)
    {
        particles.at(0)->index = i;
        tempFuncVal[i] = left->evaluate(ao);
//        cout<<"FuncValue of ao->eles[ "<<particles.at(0)->collection<<" ].at("<<i<<") = "<<left->evaluate(ao)<<endl;
  }


    switch(type)
    {
	//sorting
    case 0: //muons
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend") //ascending sort
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxMuon tempMuon = ao->muos[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->muos[ac].at(i) = ao->muos[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->muos[ac].at(j) = tempMuon;
                    }
                }
                if(symbol == "descend") //descending sort
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxMuon tempMuon = ao->muos[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->muos[ac].at(i) = ao->muos[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->muos[ac].at(j) = tempMuon;
                    }
                }
            }

        }
    case 1: //electrons
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxElectron tempElec = ao->eles[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->eles[ac].at(i) = ao->eles[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->eles[ac].at(j) = tempElec;
                    }
                }
                if(symbol == "descend")
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxElectron tempElec = ao->eles[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->eles[ac].at(i) = ao->eles[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->eles[ac].at(j) = tempElec;
                    }
                }
            }

        }

    case 2: //jets
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxJet tempJet = ao->jets[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->jets[ac].at(i) = ao->jets[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->jets[ac].at(j) = tempJet;
                    }
                }
                if(symbol == "descend")
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxJet tempJet = ao->jets[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->jets[ac].at(i) = ao->jets[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->jets[ac].at(j) = tempJet;
                    }
                }
            }

        }

     case 8: //photons
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxPhoton tempPho = ao->gams[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->gams[ac].at(i) = ao->gams[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->gams[ac].at(j) = tempPho;
                    }
                }
                if(symbol == "descend")
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxPhoton tempPho = ao->gams[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->gams[ac].at(i) = ao->gams[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->gams[ac].at(j) = tempPho;
                    }
                }
            }

        }

     case 11: //Taus
	for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxTau tempTau = ao->taus[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->taus[ac].at(i) = ao->taus[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->taus[ac].at(j) = tempTau;
                    }
                }
                if(symbol == "descend")
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxTau tempTau = ao->taus[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->taus[ac].at(i) = ao->taus[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->taus[ac].at(j) = tempTau;
                    }
                }
            }

        }
    
    case 20: //combos
	 for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxParticle tempCombo = ao->combos[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->combos[ac].at(i) = ao->combos[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->combos[ac].at(j) = tempCombo;
                    }
                }
                if(symbol == "descend")
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        double temp = tempFuncVal[i];
                        dbxParticle tempCombo = ao->combos[ac].at(i);
                        tempFuncVal[i] = tempFuncVal[j];
                        ao->combos[ac].at(i) = ao->combos[ac].at(j);;
                        tempFuncVal[j] = temp;
                        ao->combos[ac].at(j) = tempCombo;
                    }
                }
            }

        }
    }

/*    cout<<"After sorting : "<<endl;
    for (int i = 0; i < Max; i++)
    {
        particles.at(0)->index = i;
        cout<<"FuncValue of ao->eles[ "<<particles.at(0)->collection<<" ].at("<<i<<") = "<<left->evaluate(ao)<<endl;
    }
    cout<<endl;
*/
}
void SortNode::Reset() {}

void SortNode::getParticles(std::vector<myParticle *>* particles) {}
void SortNode::getParticlesAt(std::vector<myParticle *>* particles, int index) {}
SortNode::~SortNode()
{
}


