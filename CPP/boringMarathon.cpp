#include <bits/stdc++.h>
using namespace std;

unsigned long long binomialCoeff(unsigned long long n, unsigned long long k)
{
    unsigned long long res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res = (res*(n - i))%1000000009;
        res /= (i + 1);
    }

    return res;
}

unsigned long long  catalan(unsigned long long n)
{
    unsigned long long  c = binomialCoeff(2*n, n);
    return c/(n+1);
}


int main()
{
    int n;
    cin >> n;
    cout << catalan(n)%1000000009 << endl;
    return 0;
}
