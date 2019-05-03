#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

vector< vector<int> > adj;
vector<bool> visited;
vector<int> parent;
bool arbitrary;
int freqArray[27];
vector<int> dp;
map<int,char> l;

void dfs(int n)
{
  memset(freqArray, 0, sizeof(freqArray));
  visited[n]=true;
  for(auto i : adj[n])
  {
    if(!visited[i])
    {
      parent[i]=n;
      visited[i]=true;
      dfs(i);
    }
  }
  freqArray[(int)(l[n]-'a')]++;
  for(auto i:adj[n])
  {
    if(i!=parent[n])
    {
      if(l[i]==l[n])
        dp[n]=max(dp[n],dp[i]+1);
      dp[n]=max(dp[n],freqArray[(int)(l[n]-'a')]);
    }
  }

}

bool isCyclicUtil(int v, bool visited1[], bool *recStack)
{
    if(visited1[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited1[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        vector<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited1[*i] && isCyclicUtil(*i, visited1, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212
bool isCyclic(int n)
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited1 = new bool[n+1];
    bool *recStack = new bool[n+1];
    for(int i = 1; i < n+1; i++)
    {
        visited1[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i =1; i < n+1; i++)
        if (isCyclicUtil(i, visited1, recStack))
            return true;

    return false;
}

int main()
{ _
  int n,m,x,y;
  char temp;
  cin >> n >> m;
  adj.assign(n+1,vector<int>());
  dp.assign(n+1,1);
  visited.assign(n+1,false);
  parent.assign(n+1,0);
  for(int i=1; i<=n; ++i)
  {
    cin >> temp;
    l[i]=temp;
  }

  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    adj[x].push_back(y);
  }
  if(isCyclic(n))
  {
    cout<<-1 << endl;
    return 0;
  }

  for(int i=1; i<=n; ++i)
  {
    if(!visited[i])
      dfs(i);
  }
  cout << *max_element(dp.begin(),dp.end()) << endl;
  return 0;
}
