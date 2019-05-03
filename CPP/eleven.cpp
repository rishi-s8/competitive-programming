#include <bits/stdc++.h>
using namespace std;

unsigned long long f[1001];

unsigned long long fib(int n)
{
  if(f[n]!=0)
    return f[n];
  unsigned long long y = fib(n-1)+fib(n-2);
  f[n]=y;
  return y;
}

int main()
{
  memset(f,0,sizeof(f));
  f[1]=1;
  f[2]=1;
  fib(1000);
  int n;
  cin >> n;
  string s;
  for(int i=1; i<=n; ++i)
  {
    if(binary_search(f+1, f+1001, i))
      s+='O';
    else
      s+='o';
  }
  cout << s << endl;
}
