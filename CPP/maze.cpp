#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, m, k;

bool isValid(int i, int j)
{
  if(i>=0 && i<n && j>=0 && j<m)
    return true;
  return false;
}

void dfs(vector< vector<char> > &v, pair<int, int> p)
{
  stack< pair<int, int> > s;
  s.push(p);
  int i=p.first, j=p.second;
  bool visited[n][m];
  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<m; ++j)
      visited[i][j]=false;
  }
  visited[i][j]=true;
  while(!s.empty())
  {
    p=s.top();
    i=p.first, j=p.second;
    int count=0;
    if(isValid(i+1,j))
    {
      if(v[i+1][j]=='.' && !visited[i+1][j])
      {
        s.push(make_pair(i+1,j));
        visited[i+1][j]=true;
        ++count;
      }
    }
    if(isValid(i-1,j))
    {
      if(v[i-1][j]=='.' && !visited[i-1][j])
      {
        s.push(make_pair(i-1,j));
        visited[i-1][j]=true;
        ++count;
      }
    }
    if(isValid(i,j+1))
    {
      if(v[i][j+1]=='.' && !visited[i][j+1])
      {
        s.push(make_pair(i,j+1));
        visited[i][j+1]=true;
        ++count;
      }
    }
    if(isValid(i,j-1))
    {
      if(v[i][j-1]=='.' && !visited[i][j-1])
      {
        s.push(make_pair(i,j-1));
        visited[i][j-1]=true;
        ++count;
      }
    }
    if(count==0)
    {
      s.pop();
      v[i][j]='X';
      --k;
      if(k==0)
        break;
    }
  }
}

int main()
{ _
  char temp;
  cin >> n >> m >> k;
  vector< vector<char> > v(n);
  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<m; ++j)
    {
        cin >> temp;
        v[i].push_back(temp);
    }
  }
  int x, y;
  if(k>0)
    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<m; ++j)
      {
        if(v[i][j]=='.')
        {
          dfs(v, make_pair(i,j));
          k=0;
          break;
        }
      }
      if(!k)
        break;
    }

  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<m; ++j)
    {
      printf("%c", v[i][j]);
    }
    printf("\n");
  }
  return 0;
}
