#include <iostream>
using namespace std;


int main()
{
  unsigned int T,n,m;
  unsigned int res[100000];
  unsigned int ar[100001][3];
  unsigned int freq[100000];

  scanf("%u", &T);
  while(T--)
  {
    scanf("%u%u",&n, &m);
    for(unsigned int s=0;s<n||s<m;s++)
    {
       res[s]=0;
       freq[s]=1;
    }
    for(unsigned int i=0; i<m; ++i)
    {
        scanf("%u%u%u",&ar[i][0],&ar[i][1],&ar[i][2]);
    }
    for(int i=m-1; i>=0; --i)
    {
        if(ar[i][0]==2)
        {
          for(int k=ar[i][1]-1; k<ar[i][2]; ++k)
          {
            freq[k]=(freq[i]+freq[k])%1000000007;
          }
        }
        else
        {
          for(int j=ar[i][1]-1; j<ar[i][2]; ++j)
          {
            res[j]=(freq[i]+res[j])%1000000007;
          }
        }
        freq[i]=0;
    }
    for(int s=0;s<n;s++)
      printf("%u ",res[s]);
    printf("\n");
  }
  return 0;
}
