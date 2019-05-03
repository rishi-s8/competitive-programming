#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<long double> p(n+1);
    for(int i=1; i<=n; ++i)
        cin >> p[i];
    for(int j=0; j<q; ++j)
    {
        int o, l, r;
        cin >> o >> l >> r;
        if(o==0)
        {
            long double ans = 1;
            for(int i=l; i<=r; ++i)
                ans*=(1-p[i]);
            cout << fixed << setprecision(8) << ans << endl;
        }
        else
        {   
            long double t;
            cin >> t;
            for(int i=l; i<=r; ++i)
                p[i]*=t;
        }
    }
}
