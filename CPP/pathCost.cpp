#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define infinite 1000000007
using namespace std;

int main()
{
  map<string,int> stations;
  string s1, s2;
  int n, m, x, y, z=0, w;
  cin >> n >> m;
  int ar[101][101];

  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      ar[i][j]=infinite;
  for(int i=0; i<n; ++i)
  {
    cin >> s1;
    stations[s1]=z++;
    ar[stations[s1]][stations[s1]]=0;
  }
  for(int i=0; i<m; ++i)
  {
    cin >> s1 >> s2 >> w;
    ar[stations[s1]][stations[s2]]=w;
    ar[stations[s2]][stations[s1]]=w;
  }

  int distance[101][101];
  for(int i=0; i<n; ++i)
  {
    copy(ar[i], ar[i]+n, distance[i]);
  }

  for(int k=0; k<n; ++k)
    for(int i = 0; i<n; ++i)
      for(int j=0; j<n; ++j)
        distance[i][j]=min(distance[i][j], distance[i][k]+distance[k][j]);

  int q;
  cin >> q;
  while(q--)
  {
    cin >> s1 >> s2;
    cout << distance[stations[s1]][stations[s2]] << endl;
  }

  return 0;
}
