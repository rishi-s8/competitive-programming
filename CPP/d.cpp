#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector< vector<int> > adj, dp;
vector<int> parent;
vector<bool> visited, recstack;
map<int,char> l;
int n;

bool isCyclic(int i)
{
  if(!visited[i])
  {
    visited[i]=true;
    recstack[i]=true;
    for(auto z : adj[i])
      if(!visited[z] && isCyclic(z))
        return true;
      else if(recstack[z])
        return true;
  }
  recstack[i]=false;
  return false;
}

bool isCyclic()
{
  for(int i=1; i<=n; ++i)
  {
    if(isCyclic(i))
      return true;
  }
  return false;
}

void dfs(int i)
{
  visited[i]=true;
  for(auto z:adj[i])
  {
    if(!visited[z])
    {
      parent[z]=i;
      dfs(z);
    }
  }
  for(auto z:adj[i])
  {
    if(z!=parent[i])
      for(int x=0; x<26; ++x)
      {
        dp[i][x]=max(dp[i][x],dp[z][x]);
      }
  }
  dp[i][l[i]-'a']++;
}

void topologicalsort()
{
  queue<int> Q,T;
  vector<int> inDegree(n+1, 0);
  for(int i=1; i<=n; ++i)
    for(auto z : adj[i])
      inDegree[z]++;
  for(int i=1; i<=n; ++i)
    if(inDegree[i]==0)
    {
      T.push(i);
      visited[i]=true;
    }
  while(!Q.empty())
  {
    int i=Q.front();
    Q.pop();
    T.push(i);
    for(auto z : adj[i])
    {
      if(!visited[z])
      {
        inDegree[z]--;
        if(!inDegree[z])
        {
          Q.push(z);
          visited[z]=true;
        }
      }
    }
  }
  fill(visited.begin(),visited.end(),false);
  while(!T.empty())
  {
    int i=T.front();
    if(!visited[i])
      dfs(i);
    T.pop();
  }
}


int main()
{ _
  int m, x, y;
  char temp;
  cin >> n >> m;
  adj.assign(n+1,vector<int>());
  visited.assign(n+1,false);
  recstack.assign(n+1,false);
  dp.assign(n+1, vector<int>(26,0));
  parent.assign(n+1,0);
  for(int i=1; i<=n; ++i)
  {
    cin >> temp;
    l[i]=temp;
  }
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    adj[x].push_back(y);
  }

  if(isCyclic())
  {
    cout << -1 << endl;
    return 0;
  }
  fill(visited.begin(),visited.end(),false);
  topologicalsort();
  int MAX=0;
  for(int i=1; i<=n; ++i)
    MAX=max(MAX,*max_element(dp[i].begin(),dp[i].end()));
  cout << MAX << endl;
}
