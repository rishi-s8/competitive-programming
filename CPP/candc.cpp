#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  char ar[101][101];
  char l[]={'R', 'G'};
  cin >> t;
  while(t--)
  {
    int sumr=0, sumg=0;
    int n, m;
    cin>> n>>m;
    for(int i=0; i<n; ++i)
    {
      for(int j=0; j<m; ++j)
      {

          cin >> ar[i][j];
          if(i%2==0)
          {
            if(j%2==0)
            {
              if(ar[i][j]!='R')
              {
                sumr+=3;
              }
              else
              {
                sumg+=5;
              }
            }
            else
            {
              if(ar[i][j]!='G')
              {
                sumr+=5;
              }
              else
              {
                sumg+=3;
              }
            }
          }
          else
          {
            if(j%2==0)
            {
              if(ar[i][j]!='G')
              {
                sumr+=5;
              }
              else
              {
                sumg+=3;
              }
            }
            else
            {
              if(ar[i][j]!='R')
              {
                sumr+=3;
              }
              else
              {
                sumg+=5;
              }
            }

          }
      }
    }

    cout << min(sumr, sumg) << endl;

  }
}
