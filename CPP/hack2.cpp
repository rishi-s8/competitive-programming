#include <bits/stdc++.h>
using namespace std;
#define pback push_back
long p = 29009933;
//long long ar[100001];

long long k(long long n)
{
  if(n==1)
    return 1;
  return ((n%p)*k(n-1))%p;
  //ar[n]=q;
//  return q;

}
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  //for(int i=0; i<100001; ++i)
    //ar[i]=0;
  int t;
  cin >> t;
  while(t--)
  {
     long long n;
    cin >> n;
    cout << k(n) << endl;
  }

  return 0;
}
