#include <bits/stdc++.h>
typedef long long Int;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
      vector<int> workers(2,0);
      int n,m,x,k;
      char temp;
      cin >> n >> m >> x >> k;
      for(int i=0; i<k; ++i)
      {
        cin>>temp;
        if(temp=='E')
          workers[0]++;
        else
          workers[1]++;
      }
      bool done = false;
      for(int i=1; i<=m; ++i)
      {
        if(workers[i%2]<=x)
        {
          n-=workers[i%2];
          workers[i%2]=0;
        }
        else
        {
          n-=x;
          workers[i%2]-=x;
        }
        if(n<=0)
        {
          done = true;
          break;
        }
      }
      if(done)
        cout << "yes\n";
      else
        cout << "no\n";
    }
}
