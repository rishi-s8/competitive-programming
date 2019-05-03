#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d", &t);
  int d[100001];

  while(t--)
  {
    int n, q, x;
    scanf("%d%d", &n, &q);
    for(int i=0; i<n; ++i)
    {
      scanf("%d", d+i);
      if(d[i]==1)
      {
        --i, --n;
      }
    }
    for(int i=0; i< q; ++i)
    {
      scanf("%d", &x);
      for(int j=0; j<n && x>0; ++j)
      {
        x/=d[j];
      }
      printf("%d ", x);
    }
    printf("\n");
  }

}
