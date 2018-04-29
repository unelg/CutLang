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
   nt_jets.clear();
   nt_uncs.clear();
   nt_sys_met.clear();
  nEle=0; nMuo=0; nJet=0;
  nt_met.Set((double)0, (double)0);
  nt_eles.reserve(100);
  nt_muos.reserve(100);
  nt_jets.reserve(100);
  nt_uncs.reserve(100);
  nt_sys_met.reserve(100);
}

//---------------------------------------------------------------



