#include <bits/stdc++.h>
using namespace std;

long double f(long double m)
{
  return m*log2(m);
}

int main()
{
  int time, c;
  cin >> time >> c;
  long double high = time/c;
  long double low=1;
  long double m;
  long double result;
  while(low<=high)
  {
    m=low + (high-low)/2;
    cout << fixed << setprecision(9) << "Mid: " << m << endl;
    long double calc=c*f(m)-time;
    cout << fixed << setprecision(9) << "Calc: " << calc << endl;
    if(calc <= 1E-8 && calc>=0)
    {

      cout << fixed << setprecision(9) << m << endl;
      return 0;
    }
    else if(calc <0)
    {
      cout << "Calc < 0 and hence low=m" << endl;
      low=m;
    }
    else
    {
      cout << "Calc > 10^-9 and hence high=m" << endl;
      high=m;
    }
  }
  return 0;
}
