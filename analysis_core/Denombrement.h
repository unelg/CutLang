#ifndef DENOMBREMENT_H
#define DENOMBREMENT_H
#include <vector>

using namespace std;


class Denombrement
{
    public:
        Denombrement(int, int);
        Denombrement(int, int, vector<vector<int>>);
        virtual ~Denombrement();

        vector<vector<int>> output();
        void affiche();
        void affiche(int);
        void affiche(int, int);
        void itt();

        void select(vector<vector<int>>);

        void output(vector<vector<int>>&);

    private:

        int nJetRecontr;
        int nJetTotal;

        int nZ = (nJetTotal + 1)/nJetRecontr;

        vector<vector<int>> out;
        vector<vector<int>> tab_selection;
        int itteration_ = 1;
};

#endif // DENOMBREMENT_H
