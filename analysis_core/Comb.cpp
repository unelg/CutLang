#include "Comb.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;


void combinaison(int N, int K, vector<vector<int>>& output)
{
    vector<int> temp;
    string bitmask(K, 1);
    bitmask.resize(N, 0);

    do
    {
        temp.clear();
        for (int k = 0; k < N; ++k) // [0..N-1] integers
        {

            if (bitmask[k]) {temp.push_back(k);}
        }
        output.push_back(temp);
    }while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

Comb::Comb(int JetTotal, int JetReco) : nJetTotal(JetTotal), nJetReco(JetReco)
{
    combinaison(nJetTotal, nJetReco, output_);
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

vector<vector<int>> Comb::output()
{
  return output_;
}
