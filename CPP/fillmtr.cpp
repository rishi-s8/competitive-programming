#include <iostream>
using namespace std;
int main()
{
  int t,n,q,ar[1001][1001],i,j,val;
  scanf("%d", &t);
  bool fill;
  while(t--)
  {
    fill=true;
    scanf("%d%d",&n,&q);
    for(int a=1; a<=n; ++a)
      for(int b=1;b<=n;++b)
        ar[a][b]=-1;
    for(int a=0; a<q; ++a)
    {
      scanf("%d%d%d",&i,&j,&val);
      ar[i][j]=val;
      if(i==j && (val!=0 && val!=-1))
      {
        fill = false;
        break;
      }
      else if(ar[j][i]!=-1 && ar[j][i]!=val)
      {
        fill=false;
        break;
      }
      ar[j][i]=ar[i][j];
      if(i>j)
      {
        if(i-1>0 && j-1>0 && ar[i-1][j-1]!=-1 && ar[i][j-1]!=ar[i-1][j-1]+ar[i][j])
        {
          fill=false;
          break;
        }
        if(i+1<=n && ar[i+1][j+1]!=-1 && ar[i+1][j]!=ar[i][j]+ar[i+1][j+1])
        {
          fill=false;
          break;
        }
      }
      else if(i<j)
      {
        if(i-1>0 && ar[i-1][j-1]!=-1 && ar[i-1][j]!=ar[i-1][j-1]+ar[i][j])
        {
          fill=false;
          break;
        }
        if(j+1<=n && ar[i+1][j+1]!=-1 && ar[i][j+1]!=ar[i][j]+ar[i+1][j+1])
        {
          fill=false;
          break;
        }
      }
      i+=j;
      j=i-j;
      i-=j;
      if(i>j)
      {
        if(i-1>0 && j-1>0 && ar[i-1][j-1]!=-1 && ar[i][j-1]!=ar[i-1][j-1]+ar[i][j])
        {
          fill=false;
          ar[i][j-1]=ar[i-1][j-1]+ar[i][j];
          break;
        }
        if(i+1<=n && ar[i+1][j+1]!=-1 && ar[i+1][j]!=ar[i][j]+ar[i+1][j+1])
        {
          fill=false;
          ar[i+1][j]=ar[i][j]+ar[i+1][j+1];
          break;
        }
      }
      else if(i<j)
      {
        if(i-1>0 && ar[i-1][j-1]!=-1 && ar[i-1][j]!=ar[i-1][j-1]+ar[i][j])
        {
          fill=false;
          ar[i-1][j]=ar[i-1][j-1]+ar[i][j];
          break;
        }
        if(j+1<=n && ar[i+1][j+1]!=-1 && ar[i][j+1]!=ar[i][j]+ar[i+1][j+1])
        {
          fill=false;
          ar[i][j+1]=ar[i][j]+ar[i+1][j+1];
          break;
        }
      }
    }
    if(fill)
    {
      printf("yes\n");
    }
    else
      printf("no\n");
  }
}
