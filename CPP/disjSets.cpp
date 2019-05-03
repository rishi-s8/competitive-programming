#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector < pair <int, int> > v;
    int n;
  public:
    disjointSet(int k)
    {
      n=k;
      v.push_back(make_pair(0,0));
      //sizeConnected.push_back(0);
      for(int i=1;i<=n; ++i)
      {
        v.push_back(make_pair(i,1));
      //  sizeConnected.push_back(0);
      }
    }

    int root(int i)
    {
      while(v[i].first!=i)
      {
        v[i].first=v[v[i].first].first;
        i=v[i].first;
      }
      return i;
    }

    void Union(int i, int j)
    {
      vector<int> sizeConnected(n+1);
      int rootI=root(i), rootJ=root(j);
      if(rootI!=rootJ)
      {
        if(v[rootI].second < v[rootJ].second)
        {
          v[rootI].first=rootJ;
          v[rootJ].second+=v[rootI].second;
        }
        else
        {
          v[rootJ].first=rootI;
          v[rootI].second+=v[rootJ].second;
        }
      }
      getSize(sizeConnected);
      printSize(sizeConnected);
    }

    void getSize(vector<int> &sizeConnected)
    {
      for(int i=1; i<=n; ++i)
      {
        ++sizeConnected[root(i)];
      }
      sort(sizeConnected.begin(), sizeConnected.end());
    }

    void printSize(vector<int> &sizeConnected)
    {
      for(int i=1; i<=n; ++i)
      {
        if(sizeConnected[i])
          printf("%d ", sizeConnected[i]);
      }
      printf("\n");
    }


};



int main()
{
  int n, m;
  cin >> n >> m;
  disjointSet D(n);
  int x, y;
  for(int i=0; i<m; ++i)
  {
    scanf("%d%d", &x, &y);
    D.Union(x, y);
  }
  cout << endl;
}
