#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
using namespace std;

int n,m,t;
vector< vector<int> > adj;
vector<int> articulationPoint;
vector< pair<int,int> > bridge;
vector<int> parent, disc, low;
vector<bool> visited;

void dfs(int vertex)
{
  visited[vertex]=true;
  disc[vertex]=low[vertex]=t++;
  int child=0;
  for(auto i:adj[vertex])
  {
    if(!visited[i])
    {
      ++child;
      parent[i]=vertex;
      dfs(i);
      low[vertex]=min(low[vertex], low[i]);
      if(parent[vertex]==-1 && child>1)
        articulationPoint.pb(vertex);
      if(parent[vertex]!=-1 && low[i]>=disc[vertex])
      {
        articulationPoint.pb(vertex);
        bridge.pb(mp(min(i,vertex), max(i,vertex)));
      }
    }
    else if(parent[i]!=vertex)
      low[vertex]=min(low[vertex], disc[i]);
  }
}

int main()
{
  t=0;
  int x, y;
  cin >> n >> m;
  adj.assign(n,vector<int>());
  parent.assign(n,-1);
  disc.assign(n,10000);
  low.assign(n,10000);
  visited.assign(n,false);
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs(0);

  sort(articulationPoint.begin(),articulationPoint.end());
  cout << articulationPoint.size() << endl;
  for(auto i : articulationPoint)
    cout << i << " ";
  cout << endl << bridge.size() << endl;
  sort(bridge.begin(), bridge.end());
  for(auto j : bridge)
    cout << j.first << " " << j.second << endl;
}
