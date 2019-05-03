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

vector< pair <int, pair<int,int> > > p;
int n;
vector< vector< pair <int,int> > > v;
vector < vector<int> > mat;
void generateMST()
{
    p.clear();
    v.clear();
    v.assign(n+1, vector< pair<int,int> >());
    for(int i=1; i<n; ++i)
        for(int j=i+1; j<=n; ++j)
            if(mat[i][j])
                p.push_back((make_pair(mat[i][j], (make_pair(i,j)))));
    sort(p.begin(),p.end());
    disjointSet D(n+1);
    //...Kruskal
    int m = p.size();
    for(int i=0; i<m; ++i)
    {
        int x=p[i].second.first;
        int y=p[i].second.second;
        if(D.root(x)!=D.root(y))
        {
            D.Union(x,y);
            v[x].push_back(make_pair(y,mat[x][y]));
            v[y].push_back(make_pair(x,mat[y][x]));
        }
    }
}
vector<int> visited;
void dfs(int s, int minHere)
{
    visited[s]=minHere;
    for(auto z: v[s])
        if(!visited[z.first])
            dfs(z.first,min(minHere,z.second));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int temp;
        cin >> n;
        mat.clear();
        mat.assign(n+1,vector<int>());
        for(int i=1; i<=n; ++i)
        {
            mat[i].push_back(0);
            for(int j=1; j<=n; ++j)
            {
                cin >> temp;
                mat[i].push_back(temp);
            }
        }
        long long ans = 0;
        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j)
            {
                if(mat[i][j] > mat[j][i])
                {
                    ans+=mat[i][j]-mat[j][i];
                    mat[j][i]=mat[i][j];
                }
                else
                {
                    ans+=mat[j][i]-mat[i][j];
                    mat[i][j]=mat[j][i];
                }
            }
        generateMST();
        for(int i=1;i<n; ++i)
        {
            cout << i << " ";
            for(auto z:v[i])
                cout << "(" <<  z.first << "," << z.second << ")" << " ";
            cout << endl;
        }
        for(int i=1; i<n; ++i)
        {
            visited.assign(n+1,0);
            dfs(i,INT_MAX);
            for(int j=i+1; j<=n; ++j)
            {
                if(visited[j]>mat[i][j])
                {
                    ans+=2*mat[i][j];
                    mat[i][j]=mat[j][i]=visited[j];
                }
            }
        }
        cout << ans << endl;

        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                cout << mat[i][j] << " ";
            cout << endl;
        }
        
    }
}
