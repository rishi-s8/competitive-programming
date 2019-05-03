#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstdio>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

// #define EPS 1e-8
// #define PI acos(-1)

// struct point {
// 	double x, y;
// 	point(double _x, double _y) {
// 		x = _x, y = _y;
// 	}
// 	bool operator < (point other) {
// 		if (fabs(x - other.x) < EPS)
// 			return x < other.x;
// 		return y < other.y;
// 	}
// };

// cross product between 3 points
// double cross(point p, point q, point r) {
// 	return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
// }

// double angle(point a, point b, point c) {
// 	double ux = b.x - a.x, uy = b.y - a.y;
// 	double vx = c.x - a.x, vy = c.y - a.y;
// 	return acos((ux*vx + uy*vy)/ sqrt((ux*ux + uy*uy)*(vx*vx+vy*vy)));
// }

// // returns true if point p is in either convex/concave polygon P
// bool inPolygon(point p, vector<point> P) {
// 	if (P.size() == 0) return false;

// 	for (int i = 0; i < P.size(); i++) // point is in P
// 	  if (fabs(P[i].x - p.x) < EPS && fabs(P[i].y - p.y) < EPS)
// 	    return true;

// 	double sum = 0;
// 	for (int i = 0; i < P.size() - 1; i++)
// 	  if (cross(p, P[i], P[i+1]) < 0)
// 	    sum -= angle(p, P[i], P[i+1]);
// 	  else
// 	    sum += angle(p, P[i], P[i+1]);
// 	cout << "sum = " << sum << endl;
// 	return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS);
// }

// =============================================
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }

double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool isInConvex(const vector <Point> &A, const Point &P)
{
	int n = A.size(), lo = 1, hi = A.size() - 1;

	if(area(A[0], A[1], P) <= 0) return 0;
	if(area(A[n-1], A[0], P) <= 0) return 0;

	while(hi - lo > 1)
	{
		int mid = (lo + hi) / 2;

		if(area(A[0], A[mid], P) > 0) lo = mid;
		else hi = mid;
	}

	return area(A[lo], A[hi], P) > 0;
}

// =============================================

int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);

  int n, m;
  double a, b;
  vector<Point> A, B;

  // cin >> n;
  n = in();
  for(int i=0; i<n; i++) {
    // cin >> a >> b;
    a = in(); b = in();
    A.push_back(Point(a, b));
  }

  // cin >> m;
  m = in();
  for(int i=0; i<m; i++) {
    // cin >> a >> b;
    a = in(); b = in();
    B.push_back(Point(a, b));
  }

  int c = 0;
  for(int i=0; i<m; i++) {
    // cout << B[i].x << " - " << B[i].y << endl;
    if(isInConvex(A, B[i])) {
      c++;
    }
  }

  // cout << "c = " << c << endl;

  if(c == m) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
