#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];

        for(int i=0; i<n; ++i)
            cin >> b[i];

        set<int> s;
        int operations=0;
        for(int i=0; i<n; ++i)
        {
           // Remove all elements larger than a[i] from set
            for(auto j = s.rbegin(); j!=s.rend();j=s.rbegin())
                if(*j<=a[i]) break;
                else s.erase(*j);
            // Remove all elements smaller than b[i] from set
            for(auto j = s.begin(); j!=s.end(); j=s.begin())
                if(*j>=b[i]) break;
                else s.erase(j);

            if(b[i] == a[i])
                continue;
            else if(b[i]>a[i])
            {
                operations=-1;
                break;
            }

            // Find b[i] in the set
            if(s.find(b[i])==s.end())
            {
                s.insert(b[i]);
                ++operations;
            }
        }
        cout << operations << endl;
    }
}
