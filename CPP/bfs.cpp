#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> tree[n+1];
  int x, y;
  for(int i=0; i<n-1; ++i)
  {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  cin >> x;
  vector<bool> visited(n+1, false);
  list<int> q, d;
  d.push_back(1);
  int s = 1;
  visited[s]=true;
  q.push_back(s);
  int level=1;
  int count=0;
  while(!q.empty() && level <= x)
  {
    s=q.front();
    q.pop_front();
    level=d.front();
    d.pop_front();
    if(level==x)
    {
      ++count;
    }
    for(int i=0; i<tree[s].size(); ++i)
    {
      if(!visited[tree[s][i]])
      {
        q.push_back(tree[s][i]);
        visited[tree[s][i]]=true;
        d.push_back(level+1);
      }
    }
  }

  cout << count << endl;


}
