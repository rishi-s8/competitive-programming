#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > adj;
vector<bool> visited;

void dfs(int n)
{
	cout << n << " ";
	visited[n]=true;
	for(auto i : adj[n])
	{
		if(!visited[i])
			dfs(i);
	}
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,a,b;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
	visited.assign(n+1,false);
    for(int i=0; i<n; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
	}
	dfs(1);
}
