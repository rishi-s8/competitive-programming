#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        unordered_map<int, int> m;
        set<int> s;
        vector<int> v(n);
        for(int i=0; i<n; ++i)
        {
            cin >> v[i];
            m[v[i]]=i;
            s.insert(v[i]);
        }
        unordered_map<int, int> greaterThan, smallerThan;
        int acc = 1;
        for(set<int>::iterator iter=s.begin(); iter!=s.end(); ++iter)
        {
            greaterThan[*iter]=n-acc;
            smallerThan[*iter]=acc-1;
            acc++;
        }
        while(q--)
        {
            int x;
            cin >> x;
            int nG = greaterThan[x], nS=smallerThan[x];
            int swapG=0, swapL=0;
            int l=0, r=n-1, ans=0;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(x==v[mid])
                    break;
                else if(m[x]>mid)
                {
                    if(v[mid]>x)
                    {
                        ++swapL;
                    }
                    else
                    {
                        --nS;
                    }
                    l=mid+1;
                }
                else
                {
                    if(v[mid]<x)
                    {
                        ++swapG;
                    }
                    else
                    {
                        --nG;
                    }
                    r=mid-1;
                }
            }
            if(swapG==swapL)
            {
                ans+=swapG;
                swapG=swapL=0;
            }
            else if(swapG>swapL)
            {
                if(nG<swapG)
                    ans=-1;
                else
                    ans=swapG;
            }
            else
            {
                if(nS<swapL)
                    ans=-1;
                else
                    ans=swapL;
            }
            cout << ans << "\n";
        }
    }
}
