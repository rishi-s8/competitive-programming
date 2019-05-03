#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b;
    int p = 1000000007;
    cin >> n >> k >> a >> b;
    vector<long long> dp(n+1,0);
    dp[1]=k;
    int q;
    cin >> q; 
    for(int i=2; i<=n; ++i)
    {
        long long an = 0;
        for(int j=1; j<i; ++j)
            an = (an+(dp[j]*dp[i-j])%p)%p;
        dp[i]=((b*an)%p+(a*dp[i-1])%p)%p;
    }
    int l,r;
    for(int i=0; i<q; ++i)
    {
        cin >> l >> r;
        long long ans = 0;
        for(int j=l; j<=r; ++j)
            ans = (ans+(dp[j]*dp[j])%p)%p;
        cout << ans << endl;
    }
}
