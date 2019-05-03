#include <bits/stdc++.h>
#define inf 1000000009
using namespace std;

int main()
{
  int c;
  cin >> c;
  int f;
  cin >> f;
  int x, y, w;
  int adj[231][231];
  for(int i=1; i<=c; ++i)
    for(int j=1;j<=c; ++j) adj[i][j]=inf;

  for(int i=0; i<f; ++i)
  {
    cin >> x >> y >> w;
    adj[x][x]=0;
    adj[y][y]=0;
    adj[x][y]=w;
    adj[y][x]=w;
  }
  int dist[231][231];
  for(int i=1; i<=c; ++i)
    for(int j=1;j<=c; ++j)
      dist[i][j]=adj[i][j];

  for(int i=1; i<=c; ++i)
    for(int j=1; j<=c; ++j)
      for(int k=1; k<=c; ++k)
        dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
  int ans=0;
  for(int i=1; i<=c; ++i)
    for(int j=1; j<=c; ++j)
      ans=max(ans,dist[i][j]);
  cout << ans << endl;
}
