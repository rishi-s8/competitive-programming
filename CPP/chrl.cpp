#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m=1000000007;
  int n, k;
  scanf("%d%d", &n, &k);
  int ar[100001];
  for(int i=0; i<n; ++i)
    scanf("%d", ar+i);
  long long prod=1;
  for(int i=0; i<n; ++i)
  {
    prod=(prod*ar[i])%m;
    int min_ind=i+1;
    for(int j=1; j<=k; ++j)
    {
      if(i+j==n-1)
      {
        prod=(prod*ar[i+j])%m;
        printf("%d\n", prod);
        return 0;
      }
      if(ar[min_ind]>=ar[i+j])
        min_ind=i+j;
    }
    i=min_ind-1;
  }
}
