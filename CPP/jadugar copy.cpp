#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; long long k;
    cin >> n >> m >> k;
    vector< long long > a(n), p(m);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<m; ++i)
    {
        cin >> p[i];
    } 
    vector<int> ans;
    for(auto z: a)
        ans.push_back(z);
    srand(time(NULL));
    
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
                long long nextMul;
                if(ans[j] < p[i]) nextMul = p[i];
                else nextMul = (ans[j]/p[i]+1)*p[i];

                if(nextMul-1-ans[j]<=k)                   a[j]=nextMul-1;
                if((ans[j]+k) % p[i] > a[j]%p[i])       a[j] =ans[j]+k;
                if((ans[j]+k-1) % p[i] > a[j]%p[i])     a[j] = ans[j]+k-1;
                if((ans[j]+k/2) % p[i] > a[j]%p[i])     a[j] = ans[j]+k/2;
                long long r = rand()%k;
                if((ans[j]+r) % p[i] > a[j]%p[i])     a[j] = ans[j]+r;
        }
    }
    
    for(int i=0; i<n; ++i)
    {
        if(k==1 && a[i]==2 && binary_search(p.begin(),p.end(),2))
            continue;
        int x = 0;
        while(binary_search(p.begin(), p.end(), a[i]))
        {
            a[i]=ans[i]+x;
            ++x;
        }
    }
    
    for(auto z:a)
        cout << z << " ";
    cout << endl;
}
