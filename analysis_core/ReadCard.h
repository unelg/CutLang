#ifndef __READCARD_H
#define __READCARD_H
#include<string>




std::string ReadCardString(const char *filename, const char *varname, const char *defval = "xxx", const int verbose = 0) ;
double ReadCard(const char *filename, const char *varname, const double defval = 0, const int verbose = 0) ;

#endif

