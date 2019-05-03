#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mp make_pair
#define pb push_back
using namespace std;

int movex[] = {1,-1,0,0};
int movey[] = {0,0,1,-1};
vector< vector<int> > adj;
int n, m;
bool isValid(int x, int y)
{
  if(x>=0 && y>=0 && x<n && y<m)
    return true;
  return false;
}

bool dfs(pair<int,int> p)
{
  int x=p.first;
  int y=p.second;
  adj[x][y]=0;
  if(x==n-1 && y==m-1)
    return true;
  for(int i=0; i<4;++i)
  {
    if(isValid(x+movex[i], y+movey[i]) && adj[x+movex[i]][y+movey[i]])
    {
       if(dfs(mp(x+movex[i], y+movey[i])))
        return true;
    }
  }
  return false;
}

int main()
{ _
  cin >> n >> m;
  adj.assign(n, vector<int>(m));
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j)
      cin >> adj[i][j];
  if(!adj[0][0] || !adj[n-1][m-1])
    cout << "No\n";
  else
    dfs(mp(0,0)) ? cout << "Yes\n" : cout << "No\n";
}
