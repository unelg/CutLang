#include "DBXNtuple.h"
ClassImp(DBXNtuple)

//---------------------------------------------------------------
DBXNtuple::DBXNtuple() : TObject()
 {
 }

 //---------------------------------------------------------------
DBXNtuple::~DBXNtuple()
 {

 }

//---------------------------------------------------------------
void DBXNtuple:: Clean(){
   nt_eles.clear();
   nt_muos.clear();
   nt_taus.clear();
   nt_jets.clear();
   nt_ljets.clear();
   nt_photons.clear();
   nt_combos.clear();
   nt_uncs.clear();
   nt_truth.clear();
   nt_sys_met.clear();
  nEle=0; nMuo=0; nJet=0;
  nt_met.Set((double)0, (double)0);
  nt_eles.reserve(100);
  nt_muos.reserve(100);
  nt_taus.reserve(100);
  nt_photons.reserve(100);
  nt_jets.reserve(100);
  nt_ljets.reserve(100);
  nt_uncs.reserve(100);
  nt_sys_met.reserve(100);
}

//---------------------------------------------------------------



