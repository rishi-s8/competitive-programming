#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >>m;
  vector< vector< pair<int, int> > > g(n+1);
  int x,y,w;
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y >> w;
    g[x].push_back(make_pair(y,w));
    g[y].push_back(make_pair(x,w));
  }
  vector<int> shortestPathLength(n+1, 100000);
  vector<int> parent(n+1, 0);
  int start=4, end=n;
  shortestPathLength[start]=0;
  for(int i=0; i<n;++i)
  {
    for(auto j = g[(i+start>n)?(i+start)%n+1 : i+start].begin(); j!= g[(i+start>n)?(i+start)%n+1 : i+start].end(); ++j)
    {
      if(shortestPathLength[(i+start>n)?(i+start)%n+1 : i+start]+j->second < shortestPathLength[j->first])
      {
        shortestPathLength[j->first]= shortestPathLength[(i+start>n)?(i+start)%n+1 : i+start]+j->second;
        cout << "shortestPathLength to " << j->first << " = " << shortestPathLength[j->first] << endl;
        parent[j->first]=(i+start>n)?(i+start)%n+1 : i+start;
        cout << "parent: " << parent[j->first] << endl;
      }
    }
  }
  cout << "End: ";
  cin >> end;
  cout << "shortestPathLength: " <<  shortestPathLength[end] << endl;
  cout << "Shortest Path: ";
  cout << end << ((end==1)? "\n" : "--->");
  // do {
  //   cout << parent[end] << ((end!=1) ? "--->" : "\n");
  //   end=parent[end];
  // } while(end!=start);
}
