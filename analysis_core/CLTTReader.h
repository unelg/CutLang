#ifndef CLTTReeReader_h
#define CLTTReeReader_h


#include "TTreeReader.h"
#include "TTreeReaderArray.h"
#include "TChain.h"

class myTTreader {

public:
        virtual double readvalue(int nix, TTreeReader *ttreader){ return 0; }
};



class myTTreaderF : public myTTreader{
private:
     double avalue;
     string sin;
public:
       TTreeReaderArray<Float_t>  *my_reader;
       myTTreaderF(TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Float_t>(*ttreader, s.c_str() );
           sin=s;
       }
      double readvalue(int nix, TTreeReader *ttreader) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

class myTTreaderI : public myTTreader{
private:
     double avalue;
     string sin;
public:
      TTreeReaderArray<Int_t> *my_reader;
      myTTreaderI( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Int_t>(*ttreader, s.c_str() );
           sin=s;
      }
      double readvalue(int nix, TTreeReader *ttreader) {
        cout <<"size:"<<my_reader->GetSize()<<"\n";
        cout <<"addr:"<<ttreader<<"\n";
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};


class myTTreaderD : public myTTreader{
private:
     double avalue;
public:
      TTreeReaderArray<Double_t> *my_reader;
      myTTreaderD( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Double_t>(*ttreader, s.c_str() );
      }
      double readvalue(int nix, TTreeReader *ttreader) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

class myTTreaderB : public myTTreader{
private:
     double avalue;
public:
      TTreeReaderArray<Bool_t> *my_reader;
      myTTreaderB( TTreeReader *ttreader, string s) {
           my_reader = new TTreeReaderArray<Bool_t>(*ttreader, s.c_str() );
      }
      double readvalue(int nix, TTreeReader *ttreader) {
        avalue=my_reader->At(nix) ; //->At(nix)
        return avalue;
      }
};

#endif
