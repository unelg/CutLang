#ifndef PolFitter_H_
#define PolFitter_H_

#include<vector>

class TGraph;
class TF1;
class TProfile;
class TString;

class PolFitter
{
    private:
	std::vector<double>* x;
	std::vector<double>* y;
	unsigned int polorder;
	
	//This member is common both for fitfunction and fitprofile
	//It gets the polynomial order
	TString GetPolOrderStr();
	
    public:
	//Constructor of the PolFitter class
	PolFitter(std::vector<double>* z, std::vector<double>* t,unsigned int po){
		x=z;
		y=t;
		polorder=po;
	}

	//graph returns a TGraph of the input std::vectors
	// it can optionally draw the TGraph on a canvas and save it in a ps file
	TGraph* graph(bool);

	// fitfunction performs the polynomial fit for the graph and returns the result as a TF1 object
	TF1* fitfunction();
	
	// profile performs a profile histogram (with user definite binning and range) and returns the result as TProfile 
	// and it can optionally draws and saves profile histo
	TProfile* profile(int nbins,double xmin,double xmax,double ymin,double ymax,bool drawprofile=false);
	
	//fitprofile perfoms the polynomial fit for the profile histogram and returns as a TF1 object
	TF1* fitprofile(int,double,double,double,double);

	//Destructor
	~PolFitter() {}

};

#endif

