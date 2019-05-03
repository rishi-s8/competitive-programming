#include <bits/stdc++.h>

using namespace std;

long long inf = 1000000007;
int fac[1000004];


long long power(long long x, long long y, long long p)  //(x^y) mod p
{
    long long res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
long long modInverse(int n, int p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

int fact(int n)
{
  if(fac[n]!=0) return fac[n];
  long long y = ((long long)n * fact(n-1))%inf;
  return (fac[n]=y);
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

long long COS(int n, int d, int l)
{
  unsigned long long sum = 0, s1, s2, s3, d2=power(d,2,inf), l2=power(l,2,inf);
  unsigned long long inv = power(modInverse(l,inf),n-1,inf);
  cout << "inv: " << inv << endl;
  int sign = 1;
  for(int r=0; 2*r<=n; ++r)
  {
    s1=nCrModPFermat(n,2*r,inf);
    s2=power(d,n-2*r,inf);
    s3=(inf+sign*power(l2-d2,r,inf))%inf;
    sign=-sign;
    s2 = (s2*s3)%inf;
    s1 = (s2*s1)%inf;
    sum=(sum + s1)%inf;
    cout << sum << endl;
  }
  sum = (sum*inv)%inf;
  cout << sum << endl;
  return sum;
}


int main()
{
  typedef long double ld;
  memset(fac, 0, sizeof(fac));
  fac[0]=1;
  for(int i=100000; i<=1000000; i+=100000)  fact(i);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int T; cin >> T;
  while(T--)
  {
    int l, d, t;
    cin >> l >> d >> t;
    // if(t==1)
    // {
    //   cout << d << endl;
    //   continue;
    // }
    int gcd_ = gcd(d,l);
    d/=gcd_;
    l/=gcd_;
    cout<< (COS(t,d,l))%inf << endl;
  }
}
