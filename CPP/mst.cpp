#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
    vector< pair<int,int> > v;
    int n;
    public:
    disjointSet(int k)
    {
        n=k;
        v.push_back(make_pair(0,0));
        for(int i=1; i<=n; ++i)
        {
            v.push_back(make_pair(i,1));
        }
    }
    int root(int a)
    {
        while(a!=v[a].first)
        {
            v[a].first=v[v[a].first].first;
            a=v[a].first;
        }
        return a;
    }
    void Union(int a, int b)
    {
        int rootA=root(a), rootB=root(b);
        if(rootA!=rootB)
        {
            if(v[rootA].second > v[rootB].second)
            {
                v[rootB].first=rootA;
                v[rootA].second+=v[rootB].second;
            }
            else
            {
                v[rootA].first=rootB;
                v[rootB].second+=v[rootA].second;
            }
        }
    }
};

int main()
{
    int n, m, x, y, weight;
    cin >> n >> m;
    vector< pair <int, pair<int,int> > > p(m);
    for(int i=0; i<m; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = (make_pair(weight, (make_pair(x,y))));
    }
    sort(p.begin(), p.end());
    disjointSet D(n+1);
    int minimum=0;
    vector< pair<int,int> > v;
    //...Kruskal
    for(int i=0; i<m; ++i)
    {
        weight=p[i].first;
        x=p[i].second.first;
        //cout << "x: " << x << " y: " << y << endl;
        y=p[i].second.second;
      //  cout << "root(x)= " << D.root(x) << " root(y)= " << D.root(y) << endl;
        if(D.root(x)!=D.root(y))
        {
            D.Union(x,y);
            v.push_back(make_pair(x,y));
            minimum+=weight;
        }
    }
    cout << minimum << endl;
    for(auto z: v)
        cout << z.first << " " << z.second << endl;

}
