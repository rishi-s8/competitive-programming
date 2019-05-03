#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, a, b;
    int p = 1000000007;
//    cin >> n >> k >> a >> b;
    a=0,b=1,k=1;
    for(int i=1; i<14; ++i)
    {
    n=i; 
    
    vector<long long> dp(n+1,0);
    dp[1]=k;
    //if(a==0)
    //else
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
