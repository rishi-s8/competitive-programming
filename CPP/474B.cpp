#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int n; cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; ++i)
    cin >> v[i];
  bool correct;
  for(int i=0; i<n; ++i)
  {
    correct=true;
    for(int j=0; j<n; ++j)
      if(v[j]!=j)
        correct=false;
    if(correct)
      break;
    for(int j=0; j<n; ++j)
    {
      if(j%2==0)
        v[j]=(v[j]+1)%n;
      else
      {
         v[j]=v[j]-1;
         if(v[j]==-1) v[j] = n-1;
      }
    }

  }
  if(correct)
    cout << "Yes\n";
  else
    cout << "No\n";
}
