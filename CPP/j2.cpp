#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

long long power(long long x, unsigned long long y, long long p)
{
	long long res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
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

long long modInverse(int a, int m)
{
	int g = gcd(a, m);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else
	{
		// If a and m are relatively prime, then modulo inverse
		// is a^(m-2) mode m
		return power(a, m-2, m);
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b;
    int p = 1000000007;
    cin >> n >> k >> a >> b;

    vector<long long> coeff(n+1, 1);
    int y=1,z=2;

    for(int i=2; i<=n; ++i)
    {
      coeff[i] = ((coeff[i-1]*y)%p * modInverse(z,p))%p;
      y+=2,z++;
    }

    for(int i=2; i<=n; ++i)
      coeff[i] = (coeff[i]*power(2,i-1,p))%p;

    if(a==0)
    {
      long long x = coeff[n];
      cout << ((x*power(k,n,p))%p * power(b,n-1,p))%p << endl;
    }
    else
    {
      vector<long long> dp(n+1,0);
      dp[1]=k;
      for(int i=2; i<=n; ++i)
      {
          long long an = 0;
          for(int j=1; j<i; ++j)
              an = (an+(dp[j]*dp[i-j])%p)%p;
          dp[i]=((b*an)%p+(a*dp[i-1])%p)%p;
      }
      cout << dp[n] << endl;
    }
}
