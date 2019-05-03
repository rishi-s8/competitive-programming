#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<string> g;

bool dfs(int l)
{
    visited[l]=true;
    for(auto z:g)
    {
        if(!visited[l])
        {
            if(g[l]!=
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> n;
    while(n)
    {
        visited.assign(n+1,false);
        g.assign(n+1,"");
        int x; string s;
        vector<string> g(n+1, false);
        for(int i=0; i<n; ++i)
        {
            cin >> x >> s;
            g[x]=s;
        }
        bool paradox = dfs(g,1);
        cin >> n;
    }
}
