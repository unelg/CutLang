#include "Comb.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;


void suppr_bad_combi_Comb(vector<int>& temp, vector<int> tab_select, int& n, int pas)
{
    vector<int> temp_combi(pas);
    int k = 0;

    do
    {
        for(int i = 0; i<pas; i++) { temp_combi[i] = temp[i+k]; }
        if(temp_combi==tab_select)
        {
            temp.erase(temp.begin()+k, temp.begin()+ k + pas );
            k-=pas;
            n-=pas;
        }
        k+=pas;
    }while(k<n);
}

void suppr_by_set_Comb(vector<vector<int> >&output, vector<int> temp, vector<vector<int> > set_select, int n, int pas)
{
    int N = n;
    for(int i = 0; i<set_select.size(); i++) suppr_bad_combi_Comb(temp, set_select[i], N, pas);
    temp.erase(temp.begin()+N, temp.end());
    if(N!=0)
    {
        if(output.size()>0){ if(temp!=output.back()) output.push_back(temp); }
        else output.push_back(temp);
    }
}

void combinaison(int N, int K, vector<vector<int> >& output, vector<vector<int> > tab_select)
{
    vector<int> temp;
    string bitmask(K, 1);
    bitmask.resize(N, 0);

    do
    {
        temp.clear();
        for (int k = 0; k < N; ++k) 
        {
            if (bitmask[k]) {temp.push_back(k);}
        }
        suppr_by_set_Comb(output, temp, tab_select, 2, 2);
    }while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

Comb::Comb(int JetTotal, int JetReco) : nJetTotal(JetTotal), nJetReco(JetReco)
{
    combinaison(nJetTotal, nJetReco, output_, tab_selection);
}

Comb::Comb(int JetTotal, int JetReco, vector<vector<int> > tab_select) : nJetTotal(JetTotal), nJetReco(JetReco), tab_selection(tab_select)
{
    combinaison(nJetTotal, nJetReco, output_, tab_selection);
}

Comb::~Comb()
{
    //dtor
}

void Comb::affiche()
{
    for(size_t i = 0; i<output_.size(); ++i)
    {
        for(size_t j = 0; j<nJetReco; ++j)
            cout << output_[i][j] << " " ;
        cout << endl;
    }
}

vector<vector<int> > Comb::output()
{
  return output_;
}
