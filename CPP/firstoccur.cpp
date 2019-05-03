#include <iostream>
using namespace std;

int main()
{
  int ar[]={3,6,8,9,9,9, 10, 11,12,13, 14};
  int l=0, r=10;
  int key=9;
  int m;
  while(l<=r)
  {
    m=l+(r-l)/2;
    if(m==l)
    {
      cout << m << endl;
      return 0;
    }
    if(ar[m]>=key)
      r=m;
    else
      l=m+1;
  }
}
