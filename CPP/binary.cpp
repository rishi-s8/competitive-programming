#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ar[] = {-1,2,3,5,6,8,9};
  int l=0, r=6, key = 7;
  int m;
  while(r-l>1)
  {
    m = l + (r-l)/2;
    if(ar[m]>=key)
      r=m;
    else
      l=m;
  }
  cout << ar[l] << endl;
}
