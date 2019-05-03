#include <bits/stdc++.h>
using namespace std;


pair <int, int> bfs(vector <pair <int, int> > v[], int n, int s)
{
//  int s = 1;
  queue<int> q;
  q.push(s);
  //vector<bool> visited(n+1, false);
  vector<int> dist(n+1, -1);
  dist[s]=0;
  while(!q.empty())
  {
    s=q.front();
    q.pop();
    for(auto it = v[s].begin(); it!=v[s].end(); ++it)
    {
      if(dist[(*it).first]==-1)
      {
        q.push((*it).first);
        dist[(*it).first]=dist[s]+(*it).second;
      }
    }
  }
  int max_ind=1;
  for(int i=2; i<=n; ++i)
  {
    if(dist[i]>dist[max_ind])
      max_ind=i;
  }
  return make_pair(max_ind, dist[max_ind]);
}

int main()
{
  int t, n;
  cin >> t;
  while(t--)
  {
    int x,y, w;
    cin >> n;
    vector< pair<int,int> > v[n+1];
    for(int i=0; i<n-1; ++i)
    {
      cin >> x >> y >> w;
      v[x].push_back(make_pair(y,w));
      v[y].push_back(make_pair(x,w));
    }
    pair <int, int> t1, t2;
    t1 = bfs(v, n, 1);
    t2= bfs(v, n, t1.first);
    int max_dist = t2.second;
    int price;
    if(max_dist<100)
      price=0;
    else if(max_dist<=1000)
      price=100;
    else if(max_dist<=10000)
      price = 1000;
    else
      price=10000;
    cout << price << " " << max_dist << endl;
  }
}
