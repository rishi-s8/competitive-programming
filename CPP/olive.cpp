#include <bits/stdc++.h>
using namespace std;

int bfs(int ar[][1001], int x, int y, int n, int m);

int main()
{
  int t;
  cin >> t;
  int n,m;
  int ar[1001][1001];
  while(t--)
  {
    int temp, max=INT_MIN, count =0;
    cin >> n >> m;
    for(int i=0; i<n;++i)
      for(int j=0; j<m;++j)
        cin >> ar[i][j];

    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<m; ++j)
      {
        if(ar[i][j]==1)
        {
          temp=bfs(ar, i, j, n, m);
          if(temp>max)
            max=temp;
          ++count;
        }
      }
    }
    cout << count << " " << max << endl;

  }
}

int bfs(int ar[][1001], int x, int y, int n, int m)
{
  queue< pair<int,int> > q;
  q.push(make_pair(x,y));
  ar[x][y]=0;
  int count=0;
  while(!q.empty())
  {
    x=q.front().first;
    y=q.front().second;
    q.pop();
    ++count;
    for(int i=x-1; i<x+2; ++i)
    {
      for(int j=y-1; j<y+2; ++j)
      {
        if(i>=0 && j>=0 && i<n && j<m)
        {
          if(ar[i][j]==1)
          {
              ar[i][j]=0;
              q.push(make_pair(i,j));
          }
        }
      }
    }
  }
  return count;
}
