#include <bits/stdc++.h>
#define F first
#define S second
#define inf 1000000009
using namespace std;
vector< pair<int,int> > points;
int n;
bool onSegment(pair<int,int> p, pair<int,int> q, pair<int,int> r)
{
    long long a = (long long)p.first * (q.second - r.second) + q.first * (r.second - p.second) +
                             r.first * (p.second - q.second);
    if(a)
        return false;
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
            q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;
    return false;
}

int pnpoly(pair<int,int> test)
{
  for(int i=0; i<n; ++i)
  {
    if(onSegment(points[i],test,points[(i+1)%n])) return 0;
  }
  int i, j, c = 0;
  for (i = 0, j = n-1; i < n; j = i++) {
    if ( ((points[i].second>test.second) != (points[j].second>test.second)) &&
     ((long double)test.first < (points[j].first-points[i].first) * ((long double)test.second-points[i].second) / (points[j].second-points[i].second) + points[i].first) )
       c = !c;
  }
  return c;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  int t; cin >> t;
  while(t--)
  {
    cin >> n;
    int x,y;
    points.assign(n,pair<int,int>());
    map< pair<int,int>, bool> visited;
    for(int i=0; i<n; ++i)
    {
      cin >> x >> y;
      points[i]=make_pair(x,y);
      visited[points[i]]=false;
    }
    int movex[]={1,-1,0,0};
    int movey[]={0,0,-1,1};
    int count=0;
    queue< pair<int,int> >q;
    pair<int,int> z,p=make_pair(inf,inf);
    //q.push(points[0]);
    bool done=false;
    for(int i=0; i<n && !done; ++i)
    {
      z=points[i];
      for(int j=0; j<4; ++j)
      {
        if(pnpoly(make_pair(z.F+movex[j],z.S+movey[j])))
        {
          p=make_pair(z.F+movex[j],z.S+movey[j]);
          done=true;
          break;
        }
      }
    }
    if(p==make_pair(inf,inf))
    {
      cout << -1 << endl;
      continue;
    }

    q.push(p);
    visited[p]=true;
    vector< pair<int,int> > ans;
    while(!q.empty())
    {
      p=q.front();
      q.pop();
      ans.push_back(p);
      ++count;
      if(count==n/10) break;
      for(int i=0; i<4; ++i)
      {
        z=make_pair(p.F+movex[i], p.S+movey[i]);
        if(!visited[z] && pnpoly(z))
        {
          visited[z]=true;
          q.push(z);
        }
      }
    }
    if(count<n/10)
    {
      cout << -1 << endl;
    }
    else
    {
      for(auto i:ans)
        cout << i.F << " " << i.S << endl;
    }

  }
}
