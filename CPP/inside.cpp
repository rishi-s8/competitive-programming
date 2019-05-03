#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > points;
int n=4;
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

int pnpoly(int nvert, pair<int,int> test)
{
  for(int i=0; i<n; ++i)
  {
    if(onSegment(points[i],test,points[(i+1)%n])) return 0;
  }
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((points[i].second>test.second) != (points[j].second>test.second)) &&
     ((long double)test.first < (points[j].first-points[i].first) * ((long double)test.second-points[i].second) / (points[j].second-points[i].second) + points[i].first) )
       c = !c;
  }
  return c;
}

int main()
{
    points.assign(4, pair<int,int>());
    points[0]=make_pair(1,1);
    points[1]=make_pair(2,0);
    points[2]=make_pair(3,1);
    points[3]=make_pair(2,2);
    if(pnpoly(4,make_pair(1,1)))   cout << "1,1\n";
    if(pnpoly(4,make_pair(2,1)))   cout << "2,1\n";
}
