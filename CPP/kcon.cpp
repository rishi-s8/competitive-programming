#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, k;
  int ar[100005];
  scanf("%d", &t);
  while(t--)
  {
      scanf("%d%d", &n, &k);
      for(int i=0; i<n; ++i)
        scanf("%d", ar+i);
      long sum=accumulate(ar,ar+n, 0);
      sum*=k;
      long sumCur=0, sumTot=0;
      for(long i=0; i<n; ++i)
      {
        sumCur+=ar[i];
        if(sumCur<0)
          sumCur=0;
        else if(sumTot<sumCur)
          sumTot=sumCur;
      }
      int x = *max_element(ar, ar+n);
      if(x<0)
        sumTot=x;
      long sum1 = sumTot;
      if(k==1)
      {
        printf("%ld\n", max(sumTot,sum));
        continue;
      }

      else if(sum==sum1)
      {
          printf("%ld\n", k*sum);
          continue;
      }


      for(long i=0; i<n; ++i)
      {
        sumCur+=ar[i];
        if(sumCur<0)
          sumCur=0;
        else if(sumTot<sumCur)
          sumTot=sumCur;
      }
      long sum2=sumTot;
      if(k==2)
      {
        printf("%ld\n", sum2);
        continue;
      }

      for(long i=0; i<n; ++i)
      {
        sumCur+=ar[i];
        if(sumCur<0)
          sumCur=0;
        else if(sumTot<sumCur)
          sumTot=sumCur;
      }
      long sum3=sumTot;
      if(k==3)
      {
        printf("%ld\n", sum3);
        continue;
      }
      else
      {
        printf("%ld\n", sum2+ (k-2)*(sum3-sum2));
      }





  }
}
