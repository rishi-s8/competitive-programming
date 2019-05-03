#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p = 1000000007;
    int t;
    cin >> t;
    while(t--)
    {
        long long m, n;
        cin >> m >> n;
        vector<long long> a(m), b(m);
        for(int i=0; i<m; ++i)
            cin >> a[i];

        for(int i=0; i<m; ++i)
            cin >> b[i];

        vector<long long> ans(1000000, 0); 
        for(auto z: a)
            ans[1] = (ans[1]+(z*m)%p)%p;

        for(auto z: b)
            ans[2] = (ans[2]+(z*m)%p)%p;

        for(int i=3; i<=n; ++i)
            ans[i] = (ans[i-1]+ans[i-2])%p;
        cout << ans[n] << endl;
    }
}

