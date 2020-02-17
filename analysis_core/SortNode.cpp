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



void SelectionSort(double* tempFuncVal,int* sortedIndex, int Max, string symbol)
{

	for(int i = 0; i<Max; i++)
	{	
		sortedIndex[i] = i;	
	}
        for(int i = 0; i<Max - 1; i++)
        {
            for(int j = i+1; j<Max; j++)
            {
	if(symbol == "ascend") //ascending sort
                {
                    if(tempFuncVal[i]>tempFuncVal[j])
                    {
                        swap(tempFuncVal[i],tempFuncVal[j]);
                        swap(sortedIndex[i],sortedIndex[j]);
                    }

			
                }
                if(symbol == "descend") //descending sort
                {
                    if(tempFuncVal[i]<tempFuncVal[j])
                    {
                        swap(tempFuncVal[i],tempFuncVal[j]);
                        swap(sortedIndex[i],sortedIndex[j]);
                    }
                }
}}

}
 //quick sort ----------
int partition (double *arr, int *sortedIndex, int start, int end, string symbol) //Auxilliary function for quick sort
{
    int pivot = arr[end]; // pivot
    int i = (start - 1); // Index of smaller element

    for (int j = start; j <= end - 1; j++)
    {
	if(symbol == "ascend"){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
	    swap(sortedIndex[i],sortedIndex[j]);
        }}

	if(symbol == "descend"){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] >= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
	    swap(sortedIndex[i],sortedIndex[j]);
        }}
    }
    swap(arr[i + 1], arr[end]);
    swap(sortedIndex[i + 1],sortedIndex[end]);
    
    return (i + 1);
}


void QuickSortAux(double* arr, int* sortedIndex,  int start, int end, string symbol) //Auxilliary function for quick sort
{
    if (start < end)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, sortedIndex, start, end, symbol);
        // Separately sort elements before
        // partition and after partition
        QuickSortAux(arr, sortedIndex, start, pi - 1, symbol);
        QuickSortAux(arr, sortedIndex, pi + 1, end, symbol);
    }
}



void QuickSort(double* tempFuncVal,int* sortedIndex, int Max, string symbol)
{
	for(int i = 0; i<Max; i++)
	{	
		sortedIndex[i] = i;	
	}
	QuickSortAux(tempFuncVal, sortedIndex, 0, Max - 1, symbol);
	
}

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
      case 12: Max=ao->muos[ac].size(); break;
       case 1: Max=ao->eles[ac].size(); break;
       case 2: Max=ao->jets[ac].size(); break;
       case 3: Max=left->tagJets(ao,1,ac).size(); break;
       case 4: Max=left->tagJets(ao,0,ac).size(); break;
       case 8: Max=ao->gams[ac].size();break;
      case 11: Max=ao->taus[ac].size();break;
      case 20: Max=ao->combos[ac].size();break;
    }
    double tempFuncVal[Max]; //temporarily stores the function values for the selected type particles
   //cout<<"N = "<<Max<<endl;
    for (int i = 0; i < Max; i++) {
        particles.at(0)->index = i;
        tempFuncVal[i] = left->evaluate(ao);
      //  cout<<"FuncValue of ao->eles[ "<<particles.at(0)->collection<<" ].at("<<i<<") = "<<left->evaluate(ao)<<endl;
     }
	
	int sortedIndex[Max]; 
	//SelectionSort(tempFuncVal,sortedIndex, Max, symbol);
	QuickSort(tempFuncVal,sortedIndex, Max, symbol);
    switch(type)
    {
	//sorting
    case 12: //muons
	{vector<dbxMuon> tempMuon;
	for(int i = 0; i<Max; i++) {	
		tempMuon.push_back( ao->muos[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max; i++) {
		ao->muos[ac].at(i) = tempMuon.at(i);
	}
	break; }
    case 1: //electrons
	{vector<dbxElectron> tempElec;
	for(int i = 0; i < Max; i++) {	
		tempElec.push_back( ao->eles[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max;i++) {
		ao->eles[ac].at(i) = tempElec.at(i);
	}
        break; }

    case 2: //jets
	{vector<dbxJet> tempJet;
	for(int i = 0; i < Max; i++) {	
		tempJet.push_back( ao->jets[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max;i++) {
		ao->jets[ac].at(i) = tempJet.at(i);
	}
        break; }
     case 8: //photons
	{vector<dbxPhoton> tempPho;
	for(int i = 0; i < Max; i++) {	
		tempPho.push_back( ao->gams[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max;i++) {
		ao->gams[ac].at(i) = tempPho.at(i);
	}
        break; }
     case 11: //Taus
	{vector<dbxTau> tempTau;
	for(int i = 0; i < Max; i++) {	
		tempTau.push_back( ao->taus[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max;i++) {
		ao->taus[ac].at(i) = tempTau.at(i);
	}
        break; }
    case 20: //combos
	{vector<dbxParticle> tempCombo;
	for(int i = 0; i < Max; i++) {	
		tempCombo.push_back( ao->combos[ac].at(sortedIndex[i]) );
	}
	for(int i = 0;i<Max;i++)
        {
		ao->combos[ac].at(i) = tempCombo.at(i);
	}

        break; }
    }

 /* cout<<"After sorting : "<<endl;
    for (int i = 0; i < Max; i++)
    {
        particles.at(0)->index = i;
        tempFuncVal[i] = left->evaluate(ao);
        cout<<"FuncValue of ao->eles[ "<<particles.at(0)->collection<<" ].at("<<i<<") = "<<left->evaluate(ao)<<endl;
    }
    cout<<endl;*/
 
 return 1;
}
void SortNode::Reset() {}

void SortNode::getParticles(std::vector<myParticle *>* particles) {}
void SortNode::getParticlesAt(std::vector<myParticle *>* particles, int index) {}
SortNode::~SortNode()
{
}


