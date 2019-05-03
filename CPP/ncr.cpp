#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long x, long long p) {
    //calculates a^x mod p in logarithmic time.
    long long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long long modInverse(long long a, long long p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
long long modBinomial(long long n, long long k, long long p) {
// calculates C(n,k) mod p (assuming p is prime).

    long long numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    long long denominator = 1; // k!
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}

int main()
{

  long long n = 10000000;
  long long k = 5000000;
  int p = 1000000007;
  cout << modBinomial(n,k,p) << endl;
}
