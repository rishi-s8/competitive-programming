#include <bits/stdc++.h>
#define vi set<int>
#define pb push_back
using namespace std;

list<int> T;
vector<bool> visited;
vector< vi >  adj;
void topologicalSort(int n);

int main()
{
  int n,m,x,y;
  cin >> n >> m;
  adj.assign(n+1, vi());
  visited.assign(n+1,false);

  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    adj[x].insert(y);
  }
  for(int i=n; i>=1; --i)
  {
      if(!visited[i])
        topologicalSort(i);
  }
  for(auto i : T)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}


void topologicalSort(int n)
{
  cout << "n: " << n << endl;
  visited[n]=true;
  for(auto i = adj[n].rbegin(); i!=adj[n].rend(); ++i)
    if(!visited[*i])
      topologicalSort(*i);
  cout << "Inserting: " << n << endl;
  T.push_front(n);
}
