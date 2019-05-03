#include <iostream>
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    int ar[100001];
    scanf("%d",&n);
    for(int i=0, j=2; i<n-1;i+=2,j+=2)
    {
      ar[i]=j;
      ar[i+1]=j-1;
    }
    if(n%2!=0)
    {
      ar[n-1]=ar[n-2];
      ar[n-2]=n;
    }
    for(int f=0;f<n;f++)
      printf("%d ", ar[f]);
    printf("\n");
  }
}
