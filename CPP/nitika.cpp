#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a , long long b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    long long p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int modInverse(int a, int m)
{
    int g = gcd(a, m);
        // If a and m are relatively prime, then modulo inverse
        // is a^(m-2) mode m
        return power(a, m-2, m);
}



int main()
{
  long long inf = 1000000007;
  typedef long double ld;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  long double PI = acos(-1);
  int T;
  cin >> T;
  while(T--)
  {
    ld l, d, t;
    cin >> l >> d >> t;
    ld w = acos(d/l);
    ld timePeriod = ((ld)2*PI)/w;
    t=fmod(t,timePeriod);
    ld answer = l*(cos(w*t));
    long long integral=floor(answer);
    ld frac=answer-integral;
    long long precision = 1000000000;
    long long gcd_ = gcd(round(frac*precision), precision);
    long long numerator=((long long)round(frac*precision)/gcd_)%inf, denominator=(precision/gcd_)%inf;
    integral= (integral + inf)%inf;
    numerator=(numerator+(integral*denominator) +inf)%inf;
    cout << (inf+numerator*modInverse(denominator,inf))%inf << endl;
  }
}
