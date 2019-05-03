#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x, y;
  cout << "Enter number of cities: ";
  cin >> n;
  set<int> graph[n+1];
  cout << "Enter number of edges: ";
  cin >> m;
  cout << "Enter edges: ";
  for(int i=0; i<m; ++i)
  {
    cin >> x >> y;
    graph[x].insert(y);
    graph[y].insert(x);
  }

  cout << "Enter the two cities: ";
  cin >> x >> y;
  int s=x;
  vector<int> parent(n+1, -1);
  deque<int> queue;
  queue.push_back(x);
  parent[x]=0;
  while(!queue.empty())
  {
    s=queue.front();
    queue.pop_front();
    if(s==y)
      break;
    for(set<int>::iterator i=graph[s].begin(); i!=graph[s].end(); ++i)
    {
      if(parent[*i] == -1)
      {
        queue.push_back(*i);
        parent[*i] = s;
      }
    }
  }

  //BackTracking...
  queue.erase(queue.begin(), queue.end());

  s=y;
  while(s!=0)
  {
    queue.push_front(s);
    s=parent[s];
  }
  while(!queue.empty())
  {
    s=queue.front();
    queue.pop_front();
    cout << s;
    if(!queue.empty())
      cout << " -> ";
    else
      cout << endl;
  }

}
