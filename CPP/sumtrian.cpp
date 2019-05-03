#include <bits/stdc++.h>
using namespace std;
#define getInt(x) scanf("%d", &x)

int main()
{
  int t;
  getInt(t);
  while(t--)
  {
    int n, temp;
    getInt(n);
    vector<int> v[n];
    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<=i; ++j)
      {
        getInt(temp);
        v[i].push_back(temp);
      }
    }

    for(int i=n-2; i>=0; --i)
    {
      for(int j=0; j<v[i].size(); ++j)
      {
        v[i][j]+=max(v[i+1][j], v[i+1][j+1]);
      }
    }
    printf("%d\n", v[0][0]);
  }
}
