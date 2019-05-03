#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
      int n,k; cin >> n >> k;
      int a;
      map<int, int> m;
      for(int i=0; i< n; ++i)
      {
        cin >> a;
        if(m.count(a)==0)
          m[a]=1;
        else
          ++m[a];
      }
      long long ans=0;
      bool done = false;
      for(auto z : m)
             if(z.second== k)
             {
                ans+=z.first;
                done=true;
              }
      if(done)
        cout << ans << endl;
      else
        cout << -1 << endl;
    }
}
