#include <bits/stdc++.h>
using namespace std;

int p, q, c, m;
set< pair <int,int> > ar;

long long ans;

void dfs(int pi, int qi)
{
    //cout << "pi: " << pi << " qi: " << qi << endl;
    if(pi==p && qi==q)
    {
        ans= (ans+1)%1000000007;;
        return;
    }

    if(pi+1<=p && ar.find(make_pair(pi+1,qi))==ar.end())
        dfs(pi+1,qi);
    if(qi+1<=q && ar.find(make_pair(p,qi+1)) == ar.end() && pi-qi>c)
        dfs(pi,qi+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ans=0;
    cin >> p >> q >> c >> m;
    int x, y;
    for(int i=0; i<m; ++i)
    {
        cin >> x >> y;
        ar.insert(make_pair(x,y));
    }
    if(ar.find(make_pair(p,q))!=ar.end())
    {
        cout << 0 << endl;
        return 0;
    }
    else if(c>=p+q-1)
    {
        cout << 1 << endl;
        return 0;
    }
    dfs(c+1,0);
    cout << ans << endl;
}
