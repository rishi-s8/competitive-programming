#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1000000009

using namespace std;

struct Point
{
  long long x, y;
  Point(){}
  Point(double a, double b) { x = a; y = b; }
};

Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
double cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }

double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool isInConvex(vector <Point> &A, Point &P)
{
  int n=A.size(); int lo=1, hi=n-1;
  if(area(A[0],A[1],P)<=0) return false;
  if(area(A[n-1], A[0], P) <= 0) return false;
  while(hi - lo > 1)
	{
		int mid = (lo + hi) / 2;

		if(area(A[0], A[mid], P) > 0) lo = mid;
		else hi = mid;
	}
	return area(A[lo], A[hi], P) > 0;
}

int main()
{
  int t; cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<Point> A;
    map<pair<long,long> ,bool> visited;
    Point P;
    for(int i=0; i<n; ++i)
    {
      cin >> P.x >> P.y;
      A.push_back(P);
      visited[make_pair(P.x,P.y)]=false;
    }
    int movex[]={1,-1,0,0};
    int movey[]={0,0,-1,1};
    int count=0;
    queue< Point >q;
    Point z,w;
    bool done=false;
    P.x=inf, P.y=inf;
    for(int i=0; i<n && !done; ++i)
    {
      z=A[i];
      for(int j=0; j<4; ++j)
      {
        w.x=z.x+movex[i];
        w.y=z.y+movey[i];
        if(isInConvex(A,w))
        {
          P=w;
          done=true;
          break;
        }
      }
    }
    if(P.x==inf || P.y==inf)
    {
      cout << "-1\n";
      continue;
    }
    q.push(P);
    visited[make_pair(P.x,P.y)]=true;
    vector<Point> ans;
    while(!q.empty())
    {
      P=q.front();
      q.pop();
      ans.push_back(P);
      ++count;
      if(count==n/10) break;
      for(int i=0; i<4; ++i)
      {
        z.x=P.x+movex[i], z.y=P.y+movey[i];
        if(!visited[make_pair(z.x,z.y)] && isInConvex(A,z))
        {
          visited[make_pair(z.x,z.y)]=true;
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
        cout << i.x << " " << i.y << endl;
    }
  }
}
