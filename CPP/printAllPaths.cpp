#include <bits/stdc++.h>
using namespace std;

void printAllPaths(vector< pair<int, int> > G[], int cities, int u, int d, int t);
void printAllPaths(vector< pair<int, int> > G[],  vector<bool> &visited, vector< pair<int, int> > &path, vector< pair<int, int> > &bestPath, int u, int d, int dis, int &maximum);
int main()
{
  int cities, roads, from, to, maxTraffic;
  cin >> cities >> roads;
  vector< pair<int, int> > G[cities+1];
  for(int i=0; i<roads; ++i)
  {
    cin >> from >> to >> maxTraffic;
    G[from].push_back(make_pair(to, maxTraffic));
    G[to].push_back(make_pair(from,maxTraffic));
  }
  cin >> from >> to >> maxTraffic;
  printAllPaths(G,cities,from, to, maxTraffic);
}

void printAllPaths(vector< pair<int, int> > G[], int cities, int u, int d, int t)
{
  vector<bool> visited(cities+1, false);
  vector< pair<int, int> > path, bestPath;
  int maximum=0;
  printAllPaths(G, visited, path, bestPath, u, d, 10000, maximum);
  for(auto i=bestPath.begin(); i!=bestPath.end(); ++i)
    cout << i->first << " ";
  cout << endl << ceil((float)t/(maximum-1)) << endl;
}
void printAllPaths(vector< pair<int, int> > G[],  vector<bool> &visited, vector< pair<int, int> > &path, vector< pair<int, int> > &bestPath, int u, int d, int dis, int &maximum)
{
  path.push_back(make_pair(u,dis));
  visited[u]=true;
  if(u==d)
  {
    int k=10000;
    for(auto i = path.begin(); i!=path.end(); ++i)
      k=min(k,i->second);
    if(maximum<k)
    {
      maximum=k;
      bestPath=path;
    }
  }
  else
  {
    for(auto i=G[u].begin(); i!=G[u].end(); ++i)
    {
      if(!visited[i->first])
      {
        printAllPaths(G, visited, path, bestPath, i->first, d, i->second, maximum);
      }
    }
  }
  visited[u]=false;
  path.pop_back();
}
