#ifndef DBX_PARTICLE_H
#define DBX_PARTICLE_H

#include "TLorentzVector.h"
#include <iostream>
#include <vector>
#define CHMAX 256


#ifndef USE_MEMCOPY
#define USE_MEMCOPY 0
#endif


struct analy_struct {   // Declare analysis types
	int BPcount;
	int Dumpcount;
	int maxEvents;
	int startpt;
	int verbfreq;
	bool dosystematics;
	bool doQCD;
	bool doHF;
        std::string dependencies;
};

typedef struct evt_data
{
	evt_data()
	{
	}

	void operator=( const evt_data &right)
	{

#if USE_MEMCOPY

		memcpy(this,right,sizeof(evt_data));
#else

		run_no       =right.run_no;
		lumiblk_no   =right.lumiblk_no;
		event_no     =right.event_no;
		TRG_e        =right.TRG_e;
		TRG_m        =right.TRG_m;
		TRG_j        =right.TRG_j;
		badjet       =right.badjet;
		top_hfor_type=right.top_hfor_type;
		mcevt_weight =right.mcevt_weight;
		user_evt_weight =right.user_evt_weight;
		isemuoverlap =right.isemuoverlap;
		vxp_maxtrk_no=right.vxp_maxtrk_no;
		vxpType      =right.vxpType;
		lar_Error    =right.lar_Error;
		pileup_weight=right.pileup_weight;
		bad_lar_feb  =right.bad_lar_feb;
		met_loose    =right.met_loose;
		maxEvents    =right.maxEvents;
		HLT_IsoMu17_eta2p1_LooseIsoPFTau20   =right.HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
		core_Flags   =right.core_Flags;
		z_vtx_weight =right.z_vtx_weight;

                weight_mc    =right.weight_mc;
                weight_pileup=right.weight_pileup;
              weight_leptonSF=right.weight_leptonSF;
             weight_bTagSF_77=right.weight_bTagSF_77;
      	    correction_weight=right.correction_weight;
      	    luminosity_weight=right.luminosity_weight;
		 weight_xsec =right.weight_xsec; 
                weight_jvt   =right.weight_jvt;
       weight_sherpa_22_vjets=right.weight_sherpa_22_vjets;
             weight_pileup_UP=right.weight_pileup_UP;
           weight_pileup_DOWN=right.weight_pileup_DOWN;
                weight_leptonSF_EL_SF_Trigger_UP = right.weight_leptonSF_EL_SF_Trigger_UP;
                weight_leptonSF_EL_SF_Trigger_DOWN = right.weight_leptonSF_EL_SF_Trigger_DOWN;
                weight_leptonSF_EL_SF_Reco_UP = right.weight_leptonSF_EL_SF_Reco_UP;
                weight_leptonSF_EL_SF_Reco_DOWN = right.weight_leptonSF_EL_SF_Reco_DOWN;
                weight_leptonSF_EL_SF_ID_UP = right.weight_leptonSF_EL_SF_ID_UP;
                weight_leptonSF_EL_SF_ID_DOWN = right.weight_leptonSF_EL_SF_ID_DOWN;
                weight_leptonSF_EL_SF_Isol_UP = right.weight_leptonSF_EL_SF_Isol_UP;
                weight_leptonSF_EL_SF_Isol_DOWN = right.weight_leptonSF_EL_SF_Isol_DOWN;
                weight_leptonSF_MU_SF_Trigger_STAT_UP = right.weight_leptonSF_MU_SF_Trigger_STAT_UP;
                weight_leptonSF_MU_SF_Trigger_STAT_DOWN = right.weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
                weight_leptonSF_MU_SF_Trigger_SYST_UP = right.weight_leptonSF_MU_SF_Trigger_SYST_UP;
                weight_leptonSF_MU_SF_Trigger_SYST_DOWN = right.weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
                weight_leptonSF_MU_SF_ID_STAT_UP = right.weight_leptonSF_MU_SF_ID_STAT_UP;
                weight_leptonSF_MU_SF_ID_STAT_DOWN = right.weight_leptonSF_MU_SF_ID_STAT_DOWN;
                weight_leptonSF_MU_SF_ID_SYST_UP = right.weight_leptonSF_MU_SF_ID_SYST_UP;
                weight_leptonSF_MU_SF_ID_SYST_DOWN = right.weight_leptonSF_MU_SF_ID_SYST_DOWN;
                weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP = right.weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
                weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN = right.weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
                weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP = right.weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
                weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN = right.weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
                weight_leptonSF_MU_SF_Isol_STAT_UP = right.weight_leptonSF_MU_SF_Isol_STAT_UP;
                weight_leptonSF_MU_SF_Isol_STAT_DOWN = right.weight_leptonSF_MU_SF_Isol_STAT_DOWN;
                weight_leptonSF_MU_SF_Isol_SYST_UP = right.weight_leptonSF_MU_SF_Isol_SYST_UP;
                weight_leptonSF_MU_SF_Isol_SYST_DOWN = right.weight_leptonSF_MU_SF_Isol_SYST_DOWN;
                weight_leptonSF_MU_SF_TTVA_STAT_UP = right.weight_leptonSF_MU_SF_TTVA_STAT_UP;
                weight_leptonSF_MU_SF_TTVA_STAT_DOWN = right.weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
                weight_leptonSF_MU_SF_TTVA_SYST_UP = right.weight_leptonSF_MU_SF_TTVA_SYST_UP;
                weight_leptonSF_MU_SF_TTVA_SYST_DOWN = right.weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
                weight_bTagSF_77_extrapolation_up = right.weight_bTagSF_77_extrapolation_up;
                weight_bTagSF_77_extrapolation_down = right.weight_bTagSF_77_extrapolation_down;
                weight_bTagSF_77_extrapolation_from_charm_up = right.weight_bTagSF_77_extrapolation_from_charm_up;
                weight_bTagSF_77_extrapolation_from_charm_down = right.weight_bTagSF_77_extrapolation_from_charm_down;
                weight_jvt_UP = right.weight_jvt_UP;
                weight_jvt_DOWN = right.weight_jvt_DOWN;
                weight_bTagSF_77_eigenvars_B_up=right.weight_bTagSF_77_eigenvars_B_up;
                weight_bTagSF_77_eigenvars_C_up=right.weight_bTagSF_77_eigenvars_C_up;
                weight_bTagSF_77_eigenvars_Light_up=right.weight_bTagSF_77_eigenvars_Light_up;
                weight_bTagSF_77_eigenvars_B_down=right.weight_bTagSF_77_eigenvars_B_down;
                weight_bTagSF_77_eigenvars_C_down=right.weight_bTagSF_77_eigenvars_C_down;
                weight_bTagSF_77_eigenvars_Light_down=right.weight_bTagSF_77_eigenvars_Light_down;
#endif
	}
	unsigned int run_no;
	unsigned int lumiblk_no;
	unsigned int event_no;
	bool TRG_e, TRG_m, TRG_j;
	bool badjet;
	int  top_hfor_type;
	float mcevt_weight;
	bool isemuoverlap;
	unsigned int vxp_maxtrk_no;
	int vxpType;
	unsigned int lar_Error;
	float pileup_weight;
	bool bad_lar_feb;
	TVector2 met_loose;
	unsigned int maxEvents;
	bool HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
	unsigned int core_Flags;
	float z_vtx_weight;
        double user_evt_weight;

//S.I
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_bTagSF_77;
   Float_t         correction_weight;
   Float_t         luminosity_weight;
   Float_t         weight_xsec;
   Float_t         weight_jvt;
   Float_t         weight_sherpa_22_vjets;
   Float_t         weight_pileup_UP;
   Float_t         weight_pileup_DOWN;
   Float_t         weight_leptonSF_EL_SF_Trigger_UP;
   Float_t         weight_leptonSF_EL_SF_Trigger_DOWN;
   Float_t         weight_leptonSF_EL_SF_Reco_UP;
   Float_t         weight_leptonSF_EL_SF_Reco_DOWN;
   Float_t         weight_leptonSF_EL_SF_ID_UP;
   Float_t         weight_leptonSF_EL_SF_ID_DOWN;
   Float_t         weight_leptonSF_EL_SF_Isol_UP;
   Float_t         weight_leptonSF_EL_SF_Isol_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
   Float_t         weight_bTagSF_77_extrapolation_up;
   Float_t         weight_bTagSF_77_extrapolation_down;
   Float_t         weight_bTagSF_77_extrapolation_from_charm_up;
   Float_t         weight_bTagSF_77_extrapolation_from_charm_down;
   Float_t         weight_jvt_UP;
   Float_t         weight_jvt_DOWN;

   std::vector<float> weight_bTagSF_77_eigenvars_B_up;
   std::vector<float> weight_bTagSF_77_eigenvars_C_up;
   std::vector<float> weight_bTagSF_77_eigenvars_Light_up;
   std::vector<float> weight_bTagSF_77_eigenvars_B_down;
   std::vector<float> weight_bTagSF_77_eigenvars_C_down;
   std::vector<float> weight_bTagSF_77_eigenvars_Light_down;

//E S.I.

}evt_data;


class dbxParticle : public TObject  {

public:
	dbxParticle();
	dbxParticle(TLorentzVector);
	dbxParticle(TLorentzVector, int);
	~dbxParticle();
	dbxParticle  operator+ (dbxParticle& c);
	static double deltaR(dbxParticle,dbxParticle);
	static double deltaPhi(dbxParticle,dbxParticle);
	//dbxParticle  operator-() const;
	static bool comparePt(dbxParticle lhs, dbxParticle rhs) { return (lhs.lv().Pt() > rhs.lv().Pt()); }
	void Reset(){  p_charge=0; p_pdgID=0; p_lvector.SetPtEtaPhiM(0, 0, 0, 0); p_attribute.clear(); }
	void dump();
	void dump_b ();
	void dumpLHCO(std::ofstream&  );

	int setCharge( int);
	int setPdgID( int);
	int setEtCone( double );
	int setPtCone( double );
	int setFlavor ( double );
	int setIsTight ( int );

	int setParticleIndx ( int );
	int setTlv( TLorentzVector );
       void setPPPE(float px, float py, float pz, float Ee ){p_lvector.SetPxPyPzE(px, py, pz, Ee ); }
       void addTlv(TLorentzVector *alv){p_lvector.SetPxPyPzE( p_lvector.Px()+alv->Px(),  p_lvector.Py()+alv->Py(),  p_lvector.Pz()+alv->Pz(),  p_lvector.E()+alv->E()); }
       void addTlv(TLorentzVector alv){p_lvector.SetPxPyPzE( p_lvector.Px()+alv.Px(),  p_lvector.Py()+alv.Py(),  p_lvector.Pz()+alv.Pz(),  p_lvector.E()+alv.E()); }
	int setScaleFactor ( double );
	int setScaleFactorReco ( double );
	int setScaleFactorId ( double );
	int setScaleFactorTrig ( double );
	int setScaleFactorTrigMcEff(double);
	int setScaleFactorIso (double );
	int setScaleFactorUncertainty ( double );
	int setScaleFactorUncertaintyUp ( double );
	int setScaleFactorUncertaintyDown ( double );
	int setSFRecoUncertaintyUp( double );
	int setSFRecoUncertaintyDown( double );
	int setSFTrigUncertaintyUp( double );
	int setSFTrigUncertaintyDown( double );
	int setSFTrigMcEffUncertaintyUp( double );
	int setSFTrigMcEffUncertaintyDown( double );
	int setSFIDUncertaintyUp( double );
	int setSFIDUncertaintyDown( double );
	int setSFIsoUncertaintyUp( double );
	int setSFIsoUncertaintyDown( double );
	int scaleLorentzVector ( double );
	int setZ0 (double );
        void setPt_Uncorrected(double v){p_Pt_Uncorrected=v;}
	void setAttribute(int k, double v) {
                  if (k>(int)p_attribute.size()) { std::cerr<<"NO Such Attribute! Use addAttribute first.\n";
                  } else { p_attribute[k]=v; }
        }
	void addAttribute(double v) {p_attribute.push_back(v);}

	int q()  { return p_charge; }
	int pdgID() {return p_pdgID; }
	double Attribute(int k)  { if (k>(int)p_attribute.size()){
                                 std::cerr<<"NO Such Attribute! ID:"<<k<<"\n";return -999999;} else {return p_attribute.at(k);} }
	int nAttribute() { return p_attribute.size(); }
	double EtCone()  { return p_et_cone; }
	double PtCone()  { return p_pt_cone; }
	double Flavor()  { return p_flavor; }
	int    isTight() { return p_istight; }
	int    ParticleIndx() { return p_particleindx; }
	TLorentzVector lv()  const{ return p_lvector; }
	double ScaleFactor()  { return p_scalefactor; }
	double ScaleFactorReco()  { return p_scalefactorreco; }
	double ScaleFactorId()  { return p_scalefactorid; }
	double ScaleFactorTrig()  { return p_scalefactortrig; }
	double ScaleFactorTrigMcEff()  { return p_scalefactortrig_mceff; }
	double ScaleFactorIso() { return p_scalefactoriso; }
	double ScaleFactorUncertainty()  { return p_escalefactor; }
	double ScaleFactorUncertaintyUp()  { return p_scalefactorup; }
	double ScaleFactorUncertaintyDown()  { return p_scalefactordown; }
	double SFRecoUncertaintyUp() { return p_recouncertaintyup ; }
	double SFRecoUncertaintyDown() { return p_recouncertaintydown; }
	double SFTrigUncertaintyUp() { return p_triguncertaintyup ; }
	double SFTrigUncertaintyDown() { return p_triguncertaintydown; }
	double SFTrigMcEffUncertaintyUp() { return p_trigmceffuncertaintyup ; }
	double SFTrigMcEffUncertaintyDown() { return p_trigmceffuncertaintydown; }
	double SFIDUncertaintyUp() { return p_iduncertaintyup ; }
	double SFIDUncertaintyDown() { return p_iduncertaintydown ; }
	double SFIsoUncertaintyUp() { return p_isouncertaintyup ; }
	double SFIsoUncertaintyDown() { return p_isouncertaintydown ; }
	double Z0() {return p_z0;}
        double Pt_Uncorrected() {return p_Pt_Uncorrected;}


private:
        std::vector<double> p_attribute;
	int p_charge;
	int p_pdgID;
	double p_et_cone;
	double p_pt_cone;
	double p_flavor;
	int p_particleindx;
	TLorentzVector p_lvector;
	double p_scalefactor;
	double p_scalefactorreco;
	double p_scalefactorid;
	double p_scalefactortrig;
	double p_scalefactortrig_mceff;
	double p_scalefactoriso;
	double p_escalefactor;
	double p_scalefactorup;
	double p_scalefactordown;
	int p_istight;
	double p_recouncertaintyup ;
	double p_recouncertaintydown;
	double p_triguncertaintyup ;
	double p_triguncertaintydown;
	double p_trigmceffuncertaintyup ;
	double p_trigmceffuncertaintydown;
	double p_iduncertaintyup ;
	double p_iduncertaintydown ;
	double p_isouncertaintyup ;
	double p_isouncertaintydown ;
	double p_z0;
        double p_Pt_Uncorrected;

	ClassDef(dbxParticle,2);
};

#endif
