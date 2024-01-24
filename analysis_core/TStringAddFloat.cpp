// Global function to add float to TString
#ifndef __TSTRINGADDFLOAT_h
#define __TSTRINGADDFLOAT_h
#include "TString.h"

TString operator+(const TString &s, Float_t f)
{
  char si[32];
  snprintf(si, sizeof(si), "%g", f);
  return s+si;
}

#endif

