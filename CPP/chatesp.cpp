#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  char ar[26]="abcdefghijklmnopqrstuvwxyz";
  scanf("%d", &t);
  while(t--)
  {
    int n, a;
    scanf("%d%d", &n, &a);
    if(n<=a)
    {
      printf("1 ");
      for(int i=0; i<n; ++i)
        printf("%c ", ar[i]);
      printf("\n");
      continue;
    }
    else if(n<=a*a)
    {
      printf("%d", a);
      for(int i=0; i<n; ++i)
        printf("%c ", ar[i/a]);
      printf("\n");
      continue;
    }
    else
    {

    }

  }
}
