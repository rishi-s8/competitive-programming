#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> v[], int n, int v);

void dfsHelper(vector<int> v[], bool visited[], int n, int v);

int main()
{
  int n, m;
  cout << "Enter number of Nodes: ";
  cin >> n;
  cout << "Enter number of Edges: ";
  cin >> m;
  int x, y;
  vector<int> v[n+1];
  cout << "Enter edges: ";
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cout << "Printing Nodes: Depth First Traversal...\n";
  dfs(v, n, 1);
  return 0;
}

void dfs(vector<int> v[], int n, int v)
{
  bool visited[n]={false};
  dfsHelper(v, visited, n, m);
}

void dfsHelper(vector<int> v[], bool visited[], int n, int v)
{
  visited[v]=true;
  
}
