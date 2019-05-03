#include <bits/stdc++.h>
using namespace std;

void colourGraph(vector<int> v[], int n);

int main()
{
  int n, m;
  cin >> n >> m;
  int x, y;
  vector<int> v[n+1];
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  colourGraph(v, n);
}

void colourGraph(vector<int> v[], int n)
{
  vector<bool> used(n, false);
  vector<int> ans(n+1, -1);
  ans[1]=0;

  for(int i=2; i<=n; ++i)
  {
    for(auto j=v[i].begin(); j!=v[i].end(); ++j)
    {
      if(ans[*j]!=-1)
      {
        used[ans[*j]]=true;
      }
    }
    int c;
    for(c=0; c<n; ++c)
      if(used[c]==false)  break;
    ans[i]=c;

    for(auto j=v[i].begin(); j!=v[i].end(); ++j)
    {
      if(ans[*j]!=-1)
        used[ans[*j]]=false;
    }
  }

  for(int i=1; i<=n; ++i)
    cout << "Vertex: " << i << " Colour: " << ans[i] << endl;

}
