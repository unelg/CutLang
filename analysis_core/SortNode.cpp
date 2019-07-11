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
    symbol=s;
    left=funcVal;
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
    int Max;
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

    }
    double tempFuncVal[Max];
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
    case 0:
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
                if(symbol == "ascend")
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
                if(symbol == "descend")
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
    case 1:
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

    case 2:
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
    }

/*    cout<<"After sorting : "<<endl;
    for (int i = 0; i < Max; i++)
    {
        particles.at(0)->index = i;
        tempFuncVal[i] = left->evaluate(ao);
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


