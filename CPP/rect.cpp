#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  int ar[4];
  while(t--)
  {
    for(int i=0; i<4; ++i)
      scanf("%d", ar+i);
    sort(ar, ar+4);
    if(ar[0]==ar[1] && ar[2]==ar[3])
      printf("YES\n");
    else
      printf("NO\n");
  }
}
