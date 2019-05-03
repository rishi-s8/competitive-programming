#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define infinite 1000000000
using namespace std;

void djikstra(vector< pair<int, int> > V[], vector<int> &distance, int source);
int cities;
int main()
{
  int roads, from, to, length, chocoAvailable, expiryTime, temp;
  cin >> cities >> roads >> chocoAvailable >> expiryTime;
  vector<bool> chocolates(cities+1, false);
  for(int i=0; i<chocoAvailable; ++i)
  {
    cin >> temp;
    chocolates[temp]=true;
  }
  vector< pair<int, int> > V[cities+1];
  for(int i=0; i<roads; ++i)
  {
    cin >> from >> to >> length;
    V[from].push_back(make_pair(to,length));
    V[to].push_back(make_pair(from,length));
  }
  cin >> from >> to;
  vector<int> fromChocolates(cities+1, infinite);
  djikstra(V,fromChocolates, from);
  vector<int> toChocolates(cities+1, infinite);
  djikstra(V,toChocolates, to);
  int min_distance=infinite;
  for(int i=1; i<=cities; ++i)
  {
    //cout << "1: " << fromChocolates[i] << " 2: " << toChocolates[i] << endl;
    if(chocolates[i])
    {
      if(fromChocolates[i]==infinite || toChocolates[i]==infinite)
        length=infinite;
      else
        length=fromChocolates[i]+toChocolates[i];
      min_distance=min(min_distance,length);
    }
  }
  if(min_distance>expiryTime)
    min_distance=-1;
  cout << min_distance << endl;
}

void djikstra(vector<pair<int,int> > V[], vector<int> &distance, int source)
{
  vector<bool> visited(cities+1, false);
  distance[source]=0;
  set< pair<int,int> > s;
  s.insert(make_pair(0,source));
  while(!s.empty())
  {
    pair<int, int> p = *s.begin();
    s.erase(s.begin());
    int w=p.first, y=p.second;
    if(visited[y]) continue;
    visited[y]=true;
    for(auto i = V[y].begin(); i!=V[y].end(); ++i)
    {
      int d = i->second, x=i->first;
      if(distance[x] > d+distance[y])
      {
        distance[x]=d+distance[y];
        s.insert(make_pair(distance[x],x));
      }
    }
  }
}
