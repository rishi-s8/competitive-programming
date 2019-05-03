#include <bits/stdc++.h>
using namespace std;
int main()
{
  int inf = 1000000007;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, temp;
  cin >> t;
  while(t--)
  {
    int x,y,n;
    cin >> n >> x >> y;
    vector<int> v(101,inf);
    for(int i=1; i<=n; ++i)
    {
      cin >> temp;
      v[temp]=0;
    }
    for(int i=1; i<=100; ++i)
    {
      for(int j=1; j<=100; ++j)
      {
          if(v[j]==0)
          {
            if(v[j-i]==inf && j-i>0) v[j-i]=v[j]+i;
            if(v[j+i]==inf && j+i<=100) v[j+i]=v[j]+i;
          }
      }
    }
    int count=0;
    for(int i=1; i<=100; ++i)
      if(v[i]>x*y) ++count;
    cout << count << endl;
  }
}
