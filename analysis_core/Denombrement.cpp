//
//
//
//
//

#include <iostream>
#include <algorithm>
#include "Denombrement.h"
#include "Comb.h"
#include <vector>
#include <string>
#include <iterator>


//#define _CLV_
#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif



using namespace std;
int itteration = 1;

struct curseur
{
    int left;
    int right;
};

void suppr_bad_combi(vector<int>& temp, vector<int>& tab_select, int& n, int pas)
{
    vector<int> temp_combi(pas);
    int k = 0;
    vector<int> tab;

    do
    {
        for(int i = 0; i<pas; i++)
            temp_combi[i] = temp[i+k];       

        if(temp_combi==tab_select)
        {
            for(int l = 0; l<k; l++)
                tab.push_back(temp[l]);

            for(int l = k+pas; l<temp.size(); l++)
                tab.push_back(temp[l]);

            temp=tab;
            k-=pas;
            n-=pas;
        }

        k+=pas;
    }while(k<n);
}

void suppr_by_set(vector<vector<int>>&output, vector<int> temp, vector<vector<int>> set_select, int n, int pas)
{
    int N = n;
    vector<int>tab;
    for(int i = 0; i<set_select.size(); i++)
        {
            suppr_bad_combi(temp, set_select[i], N, pas);
        }

    for(int i = 0; i<N; i++)
        tab.push_back(temp[i]);
    if(N!=0)
    {
        if( output.size()==0 || tab!=output.back() ) output.push_back(tab);
    }
}

void reccursion(void c(int, int, int,vector<vector<int>>,  vector<vector<int>>&, vector<int>, int&, int), void e( vector<vector<int>>, vector<int>, vector<vector<int>>&, int, int, int, int, int, int, int), vector<vector<int>> tab_select, vector<int> temp ,
                vector<vector<int>>& output, int& left_begin, int& right_end, int& real_end,int& interrup, int& pas, int nbZ)
{
    if(right_end > real_end)
        c(right_end-real_end + pas, pas, real_end+1-pas, tab_select, output, temp, itteration, nbZ);

    if (left_begin < real_end - pas)
    {
        int n = left_begin;
        while(n < real_end - pas)
            n = n + pas;

        for(int j(n); j > (left_begin + 1); j = j - pas)
            e(tab_select, temp, output, j, j+1 , right_end, real_end, j, pas, 0);
    }
}

void sort(vector<int>& input, int pas, int nbZ)
{
    for(int i = 0; i<nbZ; ++i)
    {
        for(int j = i*pas; j<pas+i*pas-1; ++j)
        {
            for(int k = j+1; k<pas+i*pas; ++k)
            {
                if(input[j]>input[k])
                    swap(input[j],input[k]);
            }
        }
    }
}

void comb(int N, int K, int n, vector<vector<int>> tab_select, vector<vector<int>>& output, vector<int> tab, int& itt, int nbZ)
{
    vector<int> temp = tab;
    string bit_conteur(K, 1);
    bit_conteur.resize(N, 0);
    int total = n+K;

    while (std::prev_permutation(bit_conteur.begin(), bit_conteur.end()))
    {
        int i(0), j(0);
        for (int k = 0; k < N; ++k)
        {
            if (bit_conteur[k]) {temp[i+n] = tab[k+n]; ++i;}
            else {temp[j+n+K] = tab[k+n]; ++j;}

        }
        sort(temp, K, nbZ);
        suppr_by_set(output, temp, tab_select, total, K);
        ++itt;
    }
}

void etape(vector<vector<int>> tab_select, vector<int> tab , vector<vector<int>>& output, int left_begin, int right_begin, int right_end, int real_end, int interrup, int pas, int stop = 0)// ici le pas est le nombre "nJet" de jets // tab
{
    int arret = stop;
    int nbZ = (real_end + 1)/pas;
    curseur a;
    vector<int> temp = tab;
    vector<int> tab2 = tab;

    int righ_begin_temp = right_begin;

    a.left = left_begin;
    a.right = right_begin;
    int total = real_end+1;

    do
    {
        do
        {
            for(int i(right_begin); i <= right_end; i++)
            {
                a.right = i;
                swap(temp[a.left],temp[a.right]);
                sort(temp,pas, nbZ);
                suppr_by_set(output, temp, tab_select, real_end+1, pas);
                 ++itteration;
                reccursion(comb, etape, tab_select, temp, output, left_begin, right_end, real_end, interrup, pas, nbZ);

                if (a.left != left_begin && i != right_end)
                {
                    etape(tab_select, temp,output, left_begin, a.right+1, right_end, real_end, a.left, pas );
                    right_begin = righ_begin_temp;
                }
            }

            if(a.left != interrup + 1)
            {
                --a.left;
                temp = tab2;
            }
            else
                arret = 1;

        }while( (a.left>(left_begin-pas+1) || a.right != right_end) && (arret == 0) );

        --right_end;

        if(right_end >= real_end && arret==0)
        {
            temp = tab2;

            for(int i(a.left); i<tab.size()-1; ++i)
                temp[i] = temp[i+1];
            temp[tab.size() - 1] = tab2[a.left];

            tab2 = temp;

            a.left = left_begin;
            a.right = right_begin;

            sort(temp, pas, nbZ);
            suppr_by_set(output, temp, tab_select, total, pas);
              ++itteration;

            reccursion(comb, etape, tab_select, temp, output, left_begin, right_end, real_end, interrup, pas, nbZ);
        }
    }while(right_end >= real_end && arret==0);
}

void etape_combinatoire(vector<vector<int>> tab_select, vector<int> tab , vector<vector<int>>& output, int left_begin, int right_begin, int right_end, int real_end, int interrup, int pas, int stop = 0) // tab, output
{
    int n = left_begin;
    while(n < real_end - pas)
    {
        n = n + pas;
    }
        comb(right_end-real_end + pas, pas, real_end+1-pas, tab_select, output, tab, itteration, (real_end+1)/pas);

    for(int i(n); i > (left_begin - 1); i= i - pas)
    {
        etape(tab_select, tab, output, i, i+1 , right_end, real_end, i, pas);
    }
}

Denombrement::Denombrement( int JetReconstr, int JetTotal, vector<vector<int>> tab_select) : nJetRecontr(JetReconstr), nJetTotal(JetTotal), tab_selection(tab_select)
{
    if(JetTotal>2)
    {
        vector<int> tab(nJetTotal+1);
        for(int i = 0; i<nJetTotal+1 ; ++i)
        {
            tab[i] = i;
        }
        suppr_by_set(out, tab, tab_selection, nZ*nJetRecontr, nJetRecontr);
        etape_combinatoire( tab_selection, tab, out, nJetRecontr-1, nJetRecontr, nJetTotal, nZ*nJetRecontr-1, nJetRecontr-1, nJetRecontr, 0);
    }
    else
    {
        Comb simple_combination = Comb(nJetTotal+1, nJetRecontr, tab_selection);
        out = simple_combination.output();
    }
}

Denombrement::Denombrement( int JetReconstr, int JetTotal) : nJetRecontr(JetReconstr), nJetTotal(JetTotal) //,nParticles(JetTotal)
{
//---------------------------combine JetReconstr particles, out of JetTotal 
//   if (nParticles.size()<2){
    if (nJetTotal>2)
    {
        vector<int> tab(nJetTotal+1);
        for(int i = 0; i<nJetTotal+1 ; ++i) { tab[i] = i; }
        suppr_by_set(out, tab, tab_selection, nZ*nJetRecontr, nJetRecontr);
        etape_combinatoire( tab_selection, tab, out, nJetRecontr-1, nJetRecontr, nJetTotal, nZ*nJetRecontr-1, nJetRecontr-1, nJetRecontr, 0);
    } else {
        Comb simple_combination = Comb(nJetTotal+1, nJetRecontr);
        out = simple_combination.output();
    }
//   } else { // now we have 2 particle types to be merged, like muons and taus, 

//   }
}

Denombrement::~Denombrement()
{
    //dtor
}

vector<vector<int>> Denombrement::output()
{
    return out;
}

void Denombrement::affiche()
{
    for(int i = 0; i<out.size(); ++i)
    {
        for(int j = 0; j<out[i].size(); ++j)
        {
            cout<< out[i][j] << " ";
            if(j%nJetRecontr == nJetRecontr-1) cout<<"  ";
        }
        cout<<"\n";
    }
}

void Denombrement::itt()
{
    itteration_ = itteration;
    DEBUG("\nLe nombre d'itterations est: " << itteration_ << "\n");
    itteration = 1;
}

void Denombrement::output(vector<vector<int>>& tab)
{
    out = tab;
}

