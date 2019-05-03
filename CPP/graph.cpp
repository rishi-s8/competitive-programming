#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e, x ,y;
    cin >> v >> e;
    vector< set<int> > adj(v+1);
    for(int i=0; i<e; ++i)
    {
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    cout << "GRAPHS\n";

    for(int i=1; i<=v; ++i)
    {
    
        cout << i << ": ";
        for(auto z:adj[i])
            cout << z << " ";
        cout << endl;
    }

}
