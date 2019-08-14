#ifndef COMB_H
#define COMB_H
#include <vector>

using namespace std;


class Comb
{
    public:
        Comb(int, int);
        virtual ~Comb();
        vector<vector<int>> output();
        void affiche();

    protected:

    private:
        int nJetTotal;
        int nJetReco;
        vector<vector<int>> output_;
};

#endif // COMB_H
