#include <bits/stdc++.h>

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t; cin >> t;
  long double reachTime, delay1, delay2;
  while(t--)
  {
    int n; cin >> n;
    vector<unsigned int> v(n);
    for(int i=0; i<n; ++i)
      cin >> v[i];
    int c, d, s; cin >> c >> d >> s;
    vector<long double> outTime0(n), outTime1(n);
    outTime0[0]=v[0];
    for(int i=1; i<n; ++i)
      outTime0[i]=outTime0[i-1]+v[i];
    outTime1[0]=2*v[0];
    for(int i=1; i<n; ++i)
    {
      reachTime=outTime1[i-1];
      if(reachTime<outTime0[i]) reachTime=outTime0[i];
      outTime1[i]=reachTime+v[i];
    }
    cout << fixed << setprecision(9) << (outTime1[n-1]-outTime0[n-1])*(c-1) << endl;
  }
}
