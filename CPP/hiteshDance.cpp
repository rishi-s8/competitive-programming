#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int bfs(vector<int> v[], vector<bool> &visited, int x)
{
  queue<int> distance;
  distance.push(0);
  int a=1, b=0;
  visited[x]=true;
  queue<int> q;
  q.push(x);
  // cout << "x: " << x << "Team: a\n";
  while(!q.empty())
  {
    int d=distance.front();
    distance.pop();
    x=q.front();
    q.pop();
    for(auto i=v[x].begin(); i!=v[x].end(); ++i)
      if(!visited[*i])
      {
        distance.push(d+1);
        if(!(d%2))
        {
          b++;
        }
        else
        {
          ++a;
        }
        visited[*i]=true;
        q.push(*i);
      }
  }
  return max(a,b);
}


int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int m, x, y, minimum=200000, maximum=-1;
    vector<int> v[20001];
    cin >> m;
    for(int i=0; i<m; ++i)
    {
      cin >> x >> y;
      minimum=min(minimum,min(x,y));
      maximum=max(maximum,max(x,y));
      v[x].push_back(y);
      v[y].push_back(x);
    }
    vector<bool> visited(20001, false);
    int maxSize=0;
    for(int i=minimum; i<=maximum; ++i)
    {
       if(v[i].size())
       {
         // cout << "Checking Vertex: " << i << endl;
         if(!visited[i])
         {
           // cout << "Performing BFS..\n";
           maxSize+=bfs(v,visited,i);
        }
      }
    }
    cout << maxSize << endl;
  }
}
