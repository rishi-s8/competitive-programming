#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define infinite 1000000000
#define mp make_pair
using namespace std;

int main()
{ _
  int n,m,x,y,w;
  cin >> n >> m;
  vector<int> dist(n+1, infinite);
  vector< pair<int, int> > G[n+1];
  //vector<int> parent(n+1);
  vector<bool> visited(n+1);
  for(int i=0; i<m; ++i)
  {
    cin>>x>>y>>w;
    G[x].push_back(mp(y,w));
  }
  x=1;
  dist[x]=0;
  set< pair<int, int> > s;
  s.insert(make_pair(0,x));
  while(!s.empty())
  {
    pair<int,int> p = *s.begin();
    s.erase(s.begin());
    w=p.first, x=p.second;
    if(visited[x])  continue;
    visited[x]=true;
    for(auto i=G[x].begin(); i!=G[x].end(); ++i)
    {
      int d= i->second + dist[x];
      if(dist[i->first] > d)
      {
        dist[i->first]=d;
        s.insert(make_pair(d,i->first));
      }
    }
  }

  for(int i=2; i<=n; ++i)
  {
    cout << dist[i] << " ";
  }
  cout << endl;
  return 0;
}
