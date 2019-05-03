#include <bits/stdc++.h>
using namespace std;

int ar[5001][5001];
int main()
{
  string a, b;
  cin >> a >> b;
  int lenA=a.size(), lenB=b.size();

  int i=0, j=0;

  for(i=0; i<=lenA; ++i)
  {
    for(int j=0; j<=lenB; ++j)
    {
      if(i==0 || j==0)
        ar[i][j]=0;
      else if (a[i-1]==b[j-1])
        ar[i][j]=1+ar[i-1][j-1];
      else
        ar[i][j]=max(ar[i-1][j], ar[i][j-1]);
    }
  }
  cout << "Length: " << ar[lenA][lenB] << endl;
}
