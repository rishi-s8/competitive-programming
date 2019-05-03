#include <iostream>
using namespace std;

int main()
{
  int x = 10105, y= 123456;
  int ans1=1, ans2=1;
  for(int i=0; i<x; ++i)
    ans1=(ans1*2)%10000;
  for(int j=0; j<y; ++j)
    ans2=(ans2*2)%10000;
  cout << (ans1+ans2)%10000 << endl;
}
