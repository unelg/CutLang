//include these and only compile main.cpp OR compile together
// #include "l.cpp"
// #include "b.cpp"
#include<iostream>
using namespace std;
extern int yyparse(int*);

int main(void){
            int nastiness=1000;
  
  int value = yyparse(&nastiness);
  cout<<"\n Parse Value!!!!!!!!!!!!!!!!!!!!!: \t "<<to_string(nastiness)<<endl;
  return 0;
}