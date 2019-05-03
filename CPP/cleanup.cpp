#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, m, temp;
    cin >> n >> m;
    vector<int> comp;
    for(int i=0; i<m; ++i)
    {
      cin >> temp;
      comp.push_back(temp);
    }
    sort(comp.begin(), comp.end());
    auto j = comp.begin();
    bool chef=true, ended=false;
    if(m==0)
      ended=true;
    for(int i=1; i<=n; ++i)
    {
      if(!ended && *j==i)
      {
          ++j;
          if(j==comp.end())
            ended=true;
        continue;
      }
      else if(chef)
        cout << i << " ";
      chef=!chef;
    }
    cout << endl;
    chef=true, ended=false;
    if(m==0)
      ended=true;
    j=comp.begin();
    for(int i=1; i<=n; ++i)
    {
      if(!ended && *j==i)
      {

          ++j;
          if(j==comp.end())
            ended=true;
        continue;
      }
      else if(!chef)
        cout << i << " ";
      chef=!chef;
    }
    cout << endl;
  }
}
