#include <bits/stdc++.h>
#define MAX 1299827
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  // x:(weight,y)
  if(n!=2)
  {
    vector< pair<int, int> > v[n+1];
    v[n].push_back(make_pair(2,1));
    for(int i=2; i<n-1; ++i)
    {
      v[n].push_back(make_pair(2,i));
    }
    v[n].push_back(make_pair(MAX-2*(n-2),n-1));
    int count=n-1;
    for(int i=1; i<=n-2 && count<m; ++i)
    {
      for(int j=i+1; j<=n-1 && count<m; ++j)
      {
        v[i].push_back(make_pair(MAX+MAX,j));
        ++count;
      }
    }
    printf("2 %d\n", MAX);
    for(int i=1; i<=n; ++i)
    {
      for(auto j=v[i].begin(); j!=v[i].end(); ++j)
      {
        printf("%d %d %d\n", i, j->second, j->first);
      }
    }
  }
  else
  {
    printf("2 2\n");
    printf("1 2 2\n");
  }
  return 0;
}
