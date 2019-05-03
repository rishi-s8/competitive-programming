#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ar[1501], temp;
  memset(ar,0,sizeof(ar));
  for(int i=0; i<3; ++i)
  {
    cin>>temp;
    ar[temp]++;
  }
  if(ar[1]>=1 || ar[2]>=2 || ar[3]>=3|| (ar[4]>=2 && ar[2]>=1))
    cout << "YES\n";
  else cout << "NO\n";
  return 0;

}
