#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int count(int i,int j)
{
  int n = gcd(i,j);
  int result=0;
  for(int i=1; i<=sqrt(n); ++i)
    if(n%i==0)
      if(n/i==i) result++;
      else  result+=2;
  return result;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int ar[11][11];
  for(int i=1; i<=10; ++i)
  {
    ar[i][i]=0;
    for(int j=1; j<i; ++j)
    {
      if(i==1||j==1)  ar[i][j]=1;
      else ar[i][j]=count(i,j);
    }
  }
  for(int i=1; i<=10; ++i)
  {
      for(int j=i+1; j<=10; ++j)
      ar[i][j]=ar[j][i];
  }

  cout << "\t";
  for(int i=0; i<10; ++i)
    cout<< i+1 << "\t";
  cout << endl;
  for(int i=1; i<=10; ++i)
  {
    cout << i << "\t";
    for(int j=1; j<=10; ++j)
      cout << ar[i][j] << "\t";
    cout << endl;
  }
}
