#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{ _
  int n,m,k;
  char temp;
  cin >> n >> m >> k;
  vector< vector<char> > v(n);

  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<m; ++j)
    {
      cin >> temp;
      v[i].push_back(temp);
    }
  }
  long long sum=0;

  if(k!=1)
  {
    for(int i=0; i<n; ++i)
  {
    int cur=0;
    for(int j=0; j<m; ++j)
    {
      if(v[i][j]=='*' && cur>=k)
      {
        sum+=cur-k+1;
        cur=0;
      }
      else if(v[i][j]=='*')
        cur=0;
      if(v[i][j]=='.')
        cur++;
      if(j==m-1 && v[i][j]=='.' && cur>=k)
        sum+=cur-k+1;
    }
  }
  for(int i=0; i<m; ++i)
  {
    int cur=0;
    for(int j=0; j<n; ++j)
    {
      if(v[j][i]=='*' && cur>=k)
      {
        sum+=cur-k+1;
        cur=0;
      }
      else if(v[j][i]=='*')
        cur=0;
      if(v[j][i]=='.')
        cur++;
      if(j==n-1 && v[j][i]=='.' && cur>=k)
        sum+=cur-k+1;
    }
  }
  }
  else
  {
    for(auto z: v)
    {
      for(auto x:z)
      {
        if(x=='.')
          ++sum;
      }
    }
  }

  cout << sum << endl;
}
