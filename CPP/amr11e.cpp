#include <bits/stdc++.h>
using namespace std;

vector<int> lowest_prime;
vector<long long> dp;

void sieve()
{
    int n = 10000000;
    lowest_prime.assign(n+1,0);
    dp.assign(n+1,0);
    for(int i=1; i<n; ++i)
        lowest_prime[i]=i;
    for(int i=2; i*i<=n; ++i)
    {
        if(lowest_prime[i]==i)
            for(int j=i*i; j<=n; j+=i)
                if(lowest_prime[j]==j) lowest_prime[j]=i;
        dp[i]=dp[i-1]+lowest_prime[i];
    }

}



int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
