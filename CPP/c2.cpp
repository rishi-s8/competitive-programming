#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{ _
  long long n,k,A,B;
  cin >> n >> k >> A >> B;
  long long sum=0;
  if(k==1)
  {
    cout << A*(n-1) << endl;
    return 0;
  }
  while(n!=1)
  {
    if(k>n)
    {
      cout << sum+A*(n-1) << endl;
      return 0;
    }
    if(n%k==0)
    {
      if((n-n/k)*A < B) sum+=(n-n/k)*A;
      else sum+=B;
      n/=k;
    }
    else
    {
      //cout << "n: " << n << " k: " << k << endl;
      sum+=(A)*(n%k);
      n-=(n%k);
      //cout << "n: " << n << " k: " << k <<   "sum: " << sum << endl;
    }
  }
  cout << sum << endl;
}
