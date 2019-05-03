#include <bits/stdc++.h>

using namespace std;
int mod = 100000;
int main()
{
  int x, l, n, temp;
  cin >> x >> l >> n;
  vector<int> y;
  for(int i=0; i<n; ++i)
  {
    cin >> temp;
    y.push_back(temp);
  }
//  sort(y.begin(), y.end());

  vector<bool> visited(mod+1, false);
  list<int> d;
  int depth;
  d.push_back(0);
  list<int> q;
  q.push_back(x);
  long long s;
  while(!q.empty())
  {
    depth = d.front();
    d.pop_front();
    s=q.front();
    q.pop_front();
    if(s==l)
    {
      cout << depth << endl;
      return 0;
    }
    for(int i =0; i<n; ++i)
    {
      temp = (s*y[i])%mod;
    //  cout << "New node: " << temp  << endl;
      if(!visited[temp])
      {
        visited[temp] = true;
        q.push_back(temp);
        d.push_back(depth+1);
      }
    }
  }
  cout << -1 << endl;
}
