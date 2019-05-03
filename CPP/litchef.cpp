#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  int t, n, ar[100000], ind;
  scanf("%d", &t);
  while(t--)
  {
    ind = 0;
    scanf("%d", &n)
    for(int i=0; i<n; i++)
    {
       scanf("%d", &ar[i]);
       if(ar[i]<ar[ind])
        ind=i;
     }
     printf("%d \n", ind+1);
  }
  return 0;
}
