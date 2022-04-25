#include "PolFitter.h"
#include "TGraph.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TLine.h"
#include "TStyle.h"
#include "TProfile.h"
#include<iostream>



//using namespace std;


TGraph* PolFitter::graph(bool drawgraph){
	
	TGraph *g = new TGraph(x->size(),&(x->at(0)),&(y->at(0)));
	g->SetLineColor(2);
	g->SetTitle("k vs CL");
	g->GetXaxis()->SetTitle("CL");
	g->GetYaxis()->SetTitle("k");

	if(drawgraph==true){

		TCanvas *c1 = new TCanvas("c1","k vs CL",600,10,600,400);
		g->Draw("AC*");
    
		c1->SaveAs("kvsCL.pdf");
	}

	
	return g;
	
}


TString PolFitter::GetPolOrderStr(){

	TString pl ="pol";

	if(polorder>9){ 

		std::cout<<"Not be able to fit pol > pol9, so that it will be set to pol9 "<<std::endl;
		polorder=9;
		pl += polorder;	

	}
	
	else {
		pl += polorder;
	}

	return pl;
}


TF1* PolFitter::fitfunction(){
	
	TGraph *g = new TGraph(x->size(),&(x->at(0)),&(y->at(0)));
	TString pr = GetPolOrderStr();
	
	g->Fit(pr);
	TF1 *func= g->GetFunction(pr);
	TF1 *func_1=(TF1*)func->Clone("func_1");
	
	delete g;
	return func_1;
}


TProfile* PolFitter::profile(int nbins,double xmin,double xmax,double ymin,double ymax,bool drawprofile){
	
	TProfile *pro = new TProfile("pro","k vs CL (pro)",nbins,xmin,xmax,ymin,ymax);
	for (int i=0; i<x->size(); i++){
		pro->Fill(x->at(i),y->at(i));
	}
	
	if(drawprofile==true){
		TCanvas *c2 = new TCanvas("c2","k vs CL (pro)",600,10,600,400);
		pro->Draw();
		c2->SaveAs("profile.pdf");
	}
	
	
	return pro;

}


TF1* PolFitter::fitprofile(int nbins,double xmin,double xmax,double ymin,double ymax){
	
	TProfile *prof=profile(nbins,xmin,xmax,ymin,ymax);
	TString po= GetPolOrderStr();
	
	prof->Fit(po);
	TF1 *profunc=prof->GetFunction(po);
	TF1 *profunc_1=(TF1*)profunc->Clone("profunc_1");
	
	delete prof;
	return profunc_1;

}
