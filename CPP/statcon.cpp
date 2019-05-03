#include <iostream>
using namespace std;

int main()
{
  int t,n,i,a;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    i=n-n/2;
    a=n+n/2;
    if(n%2==0)
    {
      for(; i<a;++i)
        printf("%d ", i);
    }
    else
    {
      for(; i<=a;++i)
        printf("%d ", i);
    }
    printf("\n");
  }
}
