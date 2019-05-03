#include <bits/stdc++.h>
using namespace std;

bool isPower(long long a, int k)
{
  while(a!=1)
  {
    if(a%k!=0)
      return false;
    a/=k;
  }
  return true;
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin>>n>>k;
    int result=0;
    long long temp;
    for(int i=0; i<n; ++i)
    {
      cin >> temp;
      if(isPower(temp, k))
        ++result;
    }
    cout << result << endl;
  }
}
