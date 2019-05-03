#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, p;
  scanf("%d",&t);
  int n, r, upper, lower, f;
  while(t--)
  {
    f=-1;
    upper=INT_MAX, lower=0;
    scanf("%d%d",&n,&r);
    int i=0;
    for(; i<n; ++i)
    {
      scanf("%d", &p);
      if(p>upper || p<lower)
      {
        printf("NO\n");
        f=0;
        i++;
        break;
      }
      else if(r<p)
        upper=p;
      else
        lower=p;
    }
    if(f!=0)
      printf("YES\n");
    else
    {
      for(;i<n;++i)
        scanf("%d\n", &p);
    }
  }
}
