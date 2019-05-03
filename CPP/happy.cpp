#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int x, vector<bool> &visited, vector< pair <int, int> > &pc);

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> g[n+1];
  int x,y;
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int count=0;
  vector<bool> visited(n+1, false);
  vector< pair <int, int> > pc(n+1, make_pair(1,-1));
  for(int i=1; i<=n; ++i)
    if(!visited[i])
    {
      pc[i].first=0;
      dfs(g, i, visited , pc);
    }
  x=1;
  for(auto i=next(pc.begin(),1); i!=pc.end(); ++i, ++x)
  {
      if(i->second > 1)
        count++;
  }
  cout << count << endl;

}

void dfs(vector<int> g[], int x, vector<bool> &visited, vector< pair <int, int> > &pc)
{
  stack<int> s;
  s.push(x);
  visited[x]=true;
  while(!s.empty())
  {
    x=s.top();
    s.pop();
    for(auto i=g[x].begin(); i!=g[x].end(); ++i)
    {
      pc[x].second +=1;
      if(!visited[*i])
      {
        visited[*i]=true;
        s.push(*i);
      }
    }
  }



}
