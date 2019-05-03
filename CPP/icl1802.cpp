#include <bits/stdc++.h>
using namespace std;

class fraction
{
  public:
    int num, den;
    int gcd(int a, int b)
    {
        // Everything divides 0
        if (a == 0 || b == 0)
           return 0;

        // base case
        if (a == b)
            return a;

        // a is greater
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
    void add(int n, int d)
    {
      if(den == d)
        num+=n;
      else
      {
        num = num*d+n*den;
        den*=d;
      }
      int g = gcd(num, den);
      num/=g;
      den/=g;
    }

};


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t;
  cin >> t;
  while(t--)
  {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    fraction result;
    result.num=s.size(), result.den=1;
    for(auto i : s)
    {
      if(i-'a'+1-2*k>0)
        result.add(i-'a'+1-2*k, k);
    }
      cout << result.num << " " << result.den << endl;
  }

}
