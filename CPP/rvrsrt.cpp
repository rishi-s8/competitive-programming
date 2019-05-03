#include <bits/stdc++.h>
using namespace std;

int compare (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a);
}
int main()
{
  int ar[1001];
  int n, last, max;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d",&ar[i]);
  last=INT_MAX;
mergesort(ar, n, sizeof(int), compare);
  for(int i=0; i<n; ++i)
  {
    if(ar[i]!=last)
    {
      printf("%d ", ar[i]);
      last=ar[i];
    }
  }
  printf("\n");
}
