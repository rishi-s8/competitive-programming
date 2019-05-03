#include <bits/stdc++.h>
using namespace std;

//int F(string s);
void trunc(string &b, int &m)
{
  for(int i=1; i<m; ++i)
  {
    if(b[i]==b[i-1])
    {
      b.erase(b.begin()+i,b.begin()+i+1);
      i--;
      m--;
    }
  }
}
int ar[2][5001];
int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    string a, b;
    int n, m;
    cin >> n >> m;
    cin >> a >> b;
    trunc(a,n);
    trunc(b,m);
    //cout << n<< " " << a << endl <<m<<" "<<b<< endl;

    for(int i=0; i<2; ++i)
      for(int j=0; j<=m; ++j)
        ar[i][j]=0;
    bool bi;
    // for(int i=0; i<n; ++i)
    // {
    //   bi=i&1;
    //   for(int j=1; j<=m; ++j)
    //   {
    //     if(a[i]==b[j-1])
    //     {
    //       ar[bi][j]=1+ar[1-bi][j-1];
    //     }
    //     else
    //       ar[bi][j]=max(ar[1-bi][j], ar[bi][j-1]);
    //   }
    // }
    for(int i=0; i<=n; ++i)
    {
      bi=i&1;
      for(int j=0; j<=m; ++j)
      {
        if(i==0|| j==0)
          ar[bi][j]=0;
        else if(a[i-1]==b[j-1])
        {
          ar[bi][j]=1+ar[1-bi][j-1];
        }
        else
          ar[bi][j]=max(ar[1-bi][j], ar[bi][j-1]);
      }
    }
    //cout << "lcs: " << ar[bi][m] << endl;
    cout << n+m-ar[bi][m] << endl;
  }
}
