#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int t;
  cin >> t;
  while(t--)
  {
    int n,x,y;
    cin >> n;
    vector<pair<int,int> > segments(n);
    for(int i=0; i<n; ++i)
    {
      cin >> x >> y;
      segments[i]=make_pair(x,y);
    }
    int q;
    cin >> q;
    while(q--)
    {
      vector<int> crosses(n,0);
      int m;
      cin >> m;
      for(int i=0; i<m; ++i)
      {
        cin >> x;
        for(int z=0; z<n; ++z)
          if(x>=segments[z].first && x<=segments[z].second)
            crosses[z]++;
      }
      int count=0;
      for(auto z:crosses)
        if(z&1) ++count;
      cout << count << endl;
    }
  }
}
