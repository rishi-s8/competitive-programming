#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, x;
    cin >> n;
    vector< vector<int> > p(n);
    for(int i=0;i<n;++i)
    {
      for(int j=0; j<n; ++j)
      {
        cin >> x;
        p[i].push_back(x);
      }
    }
    if(p[0][0] || p[n-1][n-1])
    {
        cout << 0 << endl;
        continue;
    }
    vector< pair<int, int> > move = {make_pair(1,0),make_pair(-1,0),make_pair(0,-1),make_pair(0,1)};
    stack< pair<int, int> >s;
    s.push(make_pair(0,0));
    int y;
    int count = 0;
    p[0][0]=2;
    while(!s.empty())
    {
      x=s.top().first;
      y=s.top().second;
      s.pop();
      for(auto it=move.begin(); it!=move.end(); ++it)
      {
        int a=it->first, b=it->second;
        if(a==n-1 && b==n-1)
        {
          count++;
          continue;
        }
        if(p[a][b]==0)
        {
          s.push();
        }
      }

    }
  }
}
