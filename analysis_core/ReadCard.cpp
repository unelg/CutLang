#ifndef __READCARD_CPP
#define __READCARD_CPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>
#include <stdlib.h>

#include "ReadCard.h"
// If the variable cannot be found in the cardfile or the cardfile
//   has problems, the 3rd argument defval is returned.
// The fourth argument can be set to -1,0,1. -1 suppresses the warning
//   issued when defval is being used. 1 prints the varname = value
//   pairs as read from the cardfile.


// improved atof that can also handle binary strings ( 0b0110 = 6 )
double satof( std::string str ) {
  std::string tmp = str;
  //tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
  // we do the next two lines instead of the above line thanks to ROOT CINT!
  std::string::size_type pos = std::string::npos;
  while ((pos=tmp.find_first_of(" \t"))!=std::string::npos) tmp.erase(pos,1);
  if ( tmp[0] == '0' && tmp[1] == 'b' &&  // if binary, handle differently
       str.find_last_of('b') == 1 ) {
    return (std::bitset<32>(tmp.substr(2))).to_ulong(); }
  return atof(str.c_str());
}

double ReadCard(const char *filename, const char *varname,
                const double defval, const int verbose ) {
  
  using namespace std;

  ifstream cardfile(filename);
  if ( ! cardfile.good()) {
    cerr << "The cardfile " << filename << " file has problems... " << endl;
    return defval;
  }

  string tempLine;
  string tempS1, tempS2, tempS3;
  string subdelimiter = "=";
  string hashdelimiter = "#";
  double value(defval);
  bool foundInFile(false);

//cout << "search this:"<<varname<<"\n";
  while ( ! cardfile.eof() ) {

    getline( cardfile, tempLine );
    if ( tempLine[0] == '#' ) continue; // skip comment lines

    size_t apos=tempLine.find(subdelimiter);
                        tempS1 = tempLine.substr(0, apos); //
    size_t found = tempS1.find(string(varname) );
    if (found==std::string::npos) continue;  // skip line if not found.
    std::string::size_type pos = std::string::npos;
    while ((pos=tempS1.find_first_of(" \t"))!=std::string::npos) tempS1.erase(pos,1);
//  cout << "Match is:"<<tempS1<<"\n";
    if (tempS1 != string(varname)) continue; // skip line if not exact match
    tempS2 = tempLine.substr(apos+subdelimiter.length(),std::string::npos); //
//  cout << "Word is:"<<tempS2<<"\n";
    size_t bpos=tempS2.find(hashdelimiter);
         tempS3=tempS2.substr(0,bpos); //
//  cout << "GoodWord is:"<<tempS3<<"\n";
    value = satof(tempS3);

    if ( verbose>0 ) cout << varname << " = " << value << endl;
    foundInFile = true;
    break;
  }

  if ( verbose>=0 && !foundInFile )
    cout << "Warning! ReadCard using the default value for " << varname << " as:"<< value<< endl;
  cardfile.close();
  return value;
}

std::string ReadCardString(const char *filename, const char *varname,
                           const char *defval, const int verbose) {
  using namespace std;
  ifstream cardfile(filename);
  if ( ! cardfile.good()) {
    cerr << "The cardfile " << filename << " file has problems... " << endl;
    return defval;
  }

  string tempLine, tmpvar;
  string value=defval;
  bool foundInFile(false);

  string tempS1, tempS2, tempS3;
  string subdelimiter = "=";
  string hashdelimiter = "#";
  string quotedelimiter = "\"";
  std::string::size_type pos = std::string::npos;

//  cout << "search this:"<<varname<<"\n";
  while ( ! cardfile.eof() ) {

    getline( cardfile, tempLine );
    if ( tempLine[0] == '#' ) continue; // skip comment lines

    size_t apos=tempLine.find(subdelimiter);
                        tempS1 = tempLine.substr(0, apos); //
    size_t found = tempS1.find(string(varname) );
    if (found==std::string::npos) continue;  // skip line if not found.
    while ((pos=tempS1.find_first_of(" \t"))!=std::string::npos) tempS1.erase(pos,1);
//  cout << "Match is:"<<tempS1<<"\n";
    if (tempS1 != string(varname)) continue; // skip line if not exact match

    tempS2 = tempLine.substr(apos+subdelimiter.length(),std::string::npos); //
//  cout << "Word is:"<<tempS2<<".\n";
    size_t bpos=tempS2.find(hashdelimiter);
         tempS3=tempS2.substr(0,bpos); //
//  cout << "simple Word is:"<<tempS3<<".\n";
    bpos=tempS2.find(quotedelimiter);
    if (bpos==std::string::npos) { // no quotes found clean the spaces
        pos=std::string::npos;
        while ((pos=tempS3.find_first_of(" \t"))!=std::string::npos) tempS3.erase(pos,1);
    } else {  //clean the space before and after quotes
      tempS3.erase(0, bpos+1); //clean before
//    cout << "new Word is:"<<tempS3<<".\n";
      bpos=tempS3.find(quotedelimiter);
      tempS3.erase(bpos,std::string::npos);
    }
//  cout << "GoodWord is:"<<tempS3<<".\n";
    value = tempS3;

  if ( verbose>0 ) cout << varname << " = " << value << endl;
    foundInFile = true;
    break;
  }

  if ( verbose>=0 && !foundInFile )
    cout << "Warning! ReadCardString is using the default value for " << varname << " as:"<< value<<endl;
  cardfile.close();
  return value;

}

#endif // __READCARD_CPP
