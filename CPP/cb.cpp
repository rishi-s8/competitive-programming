#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{ _
  long double R,x1,x2,y1,y2,r,x3,y3;
  cin >> R >>x1>>y1 >> x2 >> y2;
  if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)-R*R>=0)
  {
    cout << fixed << setprecision(8) << x1 << " " << y1 << " " << R << endl;
  }
  else
  {
    r=(sqrtl((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2)) + R)/2;
    long double cosT=(x1-x2)/(2*r-R), sinT=(y1-y2)/(2*r-R);
    x3=(r*cosT+x2), y3=(r*sinT+y2);
    cout << fixed << setprecision(8) << x3 << " " << y3 << " " << r << endl;
  }
}
