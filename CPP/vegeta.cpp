#include <bits/stdc++.h>
using namespace std;


vector<int> primeFactors;

void prefixSum(int n)
{
    for(int i=2; i<=n; ++i)
        primeFactors[i]+=primeFactors[i-1];
}
void sieve(int n)
{
    primeFactors.assign(n+1, 0);
    for(int i=2; i<=n; ++i)
        if(primeFactors[i]==0)
            for(int j=i; j<=n; j+=i)
                ++primeFactors[j];
    prefixSum(n);
}




int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sieve(1000000);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        cout << primeFactors[m-1]-primeFactors[n-1] << endl;
    }
}
