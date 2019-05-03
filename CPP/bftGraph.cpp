#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e, init=1;
  cout << "Enter Number of Nodes: ";
  cin >> n;
  cout << "Enter Number of edges: ";
  cin >> e;
  set<int> s[n+1];
  int x,y;
  cout << "Enter edges:\n";
  for(int i=0; i<e; ++i)
  {
    cin >> x >> y;
    s[x].insert(y);
    s[y].insert(x);
  }
  vector<bool> visited(n+1,false);
  list<int> q;
  set<int>::iterator iter;
  visited[init]=true;
  q.push_back(init);
  while(!q.empty())
  {
    init=q.front();
    cout << init << " ";
    q.pop_front();

    for(iter=s[init].begin(); iter!=s[init].end(); ++iter)
    {
      if(visited[*iter] ==  false)
      {
        q.push_back(*iter);
        visited[*iter]=true;
      }
    }
  }
  cout << "DONE\n";
}
