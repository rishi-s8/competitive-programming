#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, m, x, y;
    cin >> n >> m;
    vector<int> g[n+1];
    for(int i=0; i<n-1; ++i)
    {
      scanf("%d%d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    set<int> rest;
    for(int i=0; i<m; ++i)
    {
      scanf("%d", &x);
      rest.insert(x);
    }
    vector<int> restDepth;
    queue<int> q, depth;
    bitset<1000001> visited;
    x=1;
    q.push(x);
    visited[x]=1;
    depth.push(0);
    int d;
    while(!q.empty())
    {
      x=q.front();
      q.pop();
      d=depth.front();
      depth.pop();
      if(rest.find(x)!=rest.end())
        restDepth.push_back(d*2);
      for(auto i=g[x].begin(); i!=g[x].end(); ++i)
      {
        if(!visited[*i])
        {
          depth.push(d+1);
          q.push(*i);
          visited[*i]=true;
        }
      }
    }
    double sum=0;
    for(auto i=restDepth.begin(); i!=restDepth.end(); ++i)
      sum+=*i;
    sum/=m;
    cout << fixed << setprecision(6) << sum << endl;
  }
}
