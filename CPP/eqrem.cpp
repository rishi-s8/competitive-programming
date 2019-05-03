#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    vector< vector< pair<int,int> > > mods(m);
    for(int i=0; i<n; ++i) mods[v[i]%m].push_back({v[i],i});
    vector< pair<int, int> > free;
    int k = n/m;
    long long count = 0;
    for(int i=0; i<2*m; ++i)
    {
        int j=i%m;
        while(mods[j].size() > k)
        {
            free.push_back(mods[j].back());
            mods[j].pop_back();
        }
        while(mods[j].size()<k && !free.empty())
        {
            auto e = free.back();
            free.pop_back();
            int add = (j-(e.first)%m+m)%m;
            e.first+=add;
            count+=add;
            mods[j].push_back(e);
        }
    }

    for(auto z: mods)
        for(auto y: z)
            v[y.second]=y.first;

    cout << count << endl;
    for(auto z: v)
        cout << z << " ";
    cout << endl;
}
