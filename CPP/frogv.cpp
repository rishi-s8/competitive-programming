#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k,p;
    cin >> n >> k >> p;
    vector<pair<int,int> > ar(n+1);
    int temp;
    for(int i=0; i<n; ++i)
    {
        cin >> temp;
        ar[i]=make_pair(temp,i+1);
    }
    sort(ar.rbegin(), ar.rend());
    int dp[n+1];
    dp[ar[0].second]=ar[0].first+k;
    for(int i=1; i<n; ++i)
    {
        if(ar[i-1].first-ar[i].first<=k)
            dp[ar[i].second]=dp[ar[i-1].second];
        else
            dp[ar[i].second]=ar[i].first+k;
    }

    int x, y;
    while(p--)
    {
        cin >> x >> y;
        if(dp[x]==dp[y])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
