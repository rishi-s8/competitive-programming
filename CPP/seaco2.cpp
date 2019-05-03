#include <iostream>
#include <math.h>
using namespace std;

unsigned int res[100000];
unsigned int ar[1001][3];
void perform1(unsigned int b,unsigned int c)
{
  for(unsigned int j=b-1; j<c; ++j)
    ++(res[j]);
}

void perform2(unsigned int b,unsigned int c)
{
  for(unsigned int i=b-1;i<c;++i)
  {
    if(ar[i][0]==1)
      perform1(ar[i][1],ar[i][2]);
    else
      perform2(ar[i][1],ar[i][2]);
  }
}

int main()
{
  unsigned int T, n, m,a,b,c;

  scanf("%d", &T);
  while(T--)
  {
    scanf("%d%d",&n, &m);
    for(unsigned int s=0;s<n;s++)
      res[s]=0;
    for(unsigned int i=0; i<m; ++i)
    {
        scanf("%d%d%d", &a,&b,&c);
        if(a==1)
        {
          perform1(b,c);
        }
        else
        {
          perform2(b, c);
        }
        ar[i][0]=a;ar[i][1]=b;ar[i][2]=c;
    }
    unsigned int temp;
    for(int s=0;s<n;s++)
    {
      temp = res[s]%(unsigned int)val;
      printf("%d ", temp);
    }
    printf("\n");

  }
  return 0;
}
