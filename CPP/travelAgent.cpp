#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{ _
  int n, m, x, y, w;
  cin >> n >> m;
  vector< pair<int, int> > g[n+1];
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y >> w;
    g[x].push_back(make_pair(y,w));
    g[y].push_back(make_pair(x,w));
  }
  vector<int> dist(n+1, 0);
  vector<int> parent(n+1, 0);
  vector<bool> visited(n+1, false);
  priority_queue< pair<int,int> > q; // weight,vertex
  int s,d,t;
  cin >> s >> d >> t;
  q.push(make_pair(t,s));
  dist[s]=t;
  while(!q.empty())
  {
    y=q.top().second;
    if(y==d)
      break;
    q.pop();
    if(visited[y])  continue;
    visited[y]=true;
    for(auto i = g[y].begin(); i!=g[y].end(); ++i)
    {
      if(dist[i->first]<i->second)
      {
        dist[i->first]=i->second;
        parent[i->first]=y;
        q.push(make_pair(i->second, i->first));
      }
    }
  }
  x=d;
  stack<int> st;
  cout << "got here..\n";
  while(x!=0)
  {
      st.push(x);
      x=parent[x];
  }
  cout << "here too..\n";
  while(!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl << dist[d] << endl;
}
