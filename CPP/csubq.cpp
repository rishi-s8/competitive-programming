#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ar[100001]={0};
  int n,q,L,R,t,x,y,count;
  scanf("%d%d%d%d", &n,&q,&L,&R);
  while(q--)
  {
    // printf("q: %d\n", q);
    count=0;
    scanf("%d%d%d", &t,&x,&y);
    // printf("t: %d, x:%d , y:%d \n", t, x, y);
    if(t==1)
      ar[x]=y;
    else
    {
      //printf("Enter, x=%d, y=%d\n", x, y);
      int concurrent=0, index=x, max=0, intiator=0;
      for(int i=x; i<=y; ++i)
      {
        if(ar[i]>max)
          max=ar[i];
        printf("max: %d, index: %d, count: %d\n", max, index, count);
        if(concurrent==0)
        {
          printf("concurrent is 0\n");
          if(ar[i]>=L && ar[i]<=R)
          {
            printf("current element is bounded\n");
            ++count;
            concurrent=1;
            index=i;
            max=ar[i];
          }
        }
        else if(max>R || max<L)
        {
          printf("max crossed\n");
          concurrent=0;
        }
        else
        {
          printf("Adding %d to count: %d\n", 1+i-index, count);
          count+= 1+i-index;

        }
      }
      printf("%d\n", count);
    }
    //printf("Printing array: \n");
    // for(int i=1; i<=n; ++i)
    // {
    //   printf("%d ", ar[i]);
    // }

  }
}
