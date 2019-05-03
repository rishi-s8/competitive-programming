#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
  /*if(argc!=3)
  {
    cerr<<"USAGE: ./exp_fac [p] [n]";
    cout<<endl;
    return -1;
  }*/
  int base=atoi(argv[1]);
  long n=atol(argv[2]);
  int ex=0;

  long d=base;
  long k=n/d;
  while(k)
  {
    ex+=k;
    d*=base;
    k=n/d;
  }
  cout<<"Maximum Power: "<<ex<<endl;
  return 0;
}
