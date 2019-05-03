#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  char ar[]="abc";
  char cr[]="ba";
  string s;
  int phi[]={0,1,1,2,2,3,3,3};
  char br[]="aababb";
  scanf("%d", &t);
  while(t--)
  {
    int n, a;
    scanf("%d%d", &n, &a);
    if(n==1)
    {
      printf("1 a\n");
    }
    else if(a==1)
    {
      printf("%d ", n);
      for(int i=0; i<n; ++i)
        printf("a");
      printf("\n");
    }
    else if(a>2)
    {
      printf("1 ");
      for(int i=0; i<n; ++i)
        printf("%c", ar[i%3]);
      printf("\n");
    }
    else if(n>8)
    {
      printf("4 ");
      for(int i=0; i<n;++i)
      {
        printf("%c", br[i%6]);
      }
      printf("\n");
    }
    else if(n==4)
    {
      printf("2 aabb\n");
    }
    else if(n==8)
    {
      printf("3 aaababbb\n");
    }
    else
    {
      s.clear();
      s.resize(n);
      printf("%d ", phi[n]);
      for(int i=0;i<phi[n]-1;++i)
        s[i]='a';
      for(int i=phi[n]-1; i<=n-phi[n]; ++i)
      {
        int z = i-phi[n]+1;
        //printf("adding %c to location %d\n", cr[z%2] ,i);

        s[i]=cr[z%2];
      }
    //  int len=s.size();
      for(int k=0;k<phi[n]-1;++k)
        s[n-1-k]='b';
      cout<< s << '\n';
    }

  }
}
