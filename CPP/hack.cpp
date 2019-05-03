#include <bits/stdc++.h>
using namespace std;
//#define pback push_back
long p = 29009933;
long ar[10000000];

long  k(long  n)
{
  if(n==1)
    return 1;
  else if(ar[n]!=0)
    return ar[n];
  long q=((n%p)*k(n-1))%p;
  ar[n]=q;
  return q;

}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  for(int i=0; i<10000000; ++i)
    ar[i]=0;
  int t;
  cin >> t;
  while(t--)
  {
     long long n;
    cin >> n;
    if(n>=104729)
        cout << 0 << '\n';
    else
        cout << k(n) << '\n';
  }

  return 0;
}
