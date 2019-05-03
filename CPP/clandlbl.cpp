#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int count(int n)
{
  int result=0;
  for(int i=1; i<=sqrt(n); ++i)
    if(n%i==0)
      if(n/i==i) result++;
      else  result+=2;
  return result;
}

int count(int i,int j)
{
  return count(gcd(i,j));
}



int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  vector< vector <pair<int,int > > > commonDivisors(4);
  for(int i=1; i<=10; ++i)
  {
    for(int j=i+1; j<=10; ++j)
    {
      if(j==1||i==1)  commonDivisors[1].push_back(make_pair(i,j));
      else commonDivisors[count(i,j)].push_back(make_pair(i,j));
    }
  }
  // for(int i=1; i<=3; ++i)
  // {
  //   cout << "i: " << i << endl;
  //   for(auto z:commonDivisors[i])
  //     cout << "(" << z.first << "," << z.second << "), ";
  //   cout << endl;
  // }
  int t;
  cin >> t;
  while(t--)
  {
    int n, temp; cin >> n;
    vector< vector<int> > adj(n+1, vector<int>(n+1));
    for(int i=1; i<=n; ++i)
    {
      for(int j=1; j<=n; ++j)
      {
        cin >> adj[i][j];
      }
    }
    // cout << "....\n";
    // for(int i=1; i<=n; ++i)
    // {
    //   for(int j=1; j<=n; ++j)
    //   {
    //     cout << adj[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    priority_queue< vector<int> > q;
    vector<int> v(3);
    // cout << "....\n";
    for(int i=1; i<=n; ++i)
    {
      for(int j=i+1; j<=n; ++j)
      {
        v[0]=adj[i][j];
        v[1]=i;
        v[2]=j;
        q.push(v);
        // cout << v[0]  << " " << v[1] << " " << v[2] << endl;
      }
    }
    vector<int> ans(n+1,0);
    int x,y;
    vector<bool> taken(n+1, false);
    while(!q.empty())
    {
      temp=q.top()[0];
      x=q.top()[1];
      y=q.top()[2];
      q.pop();
      if(ans[x]==0 && ans[y]==0)
      {
        for(auto i=commonDivisors[temp].begin(); i!=commonDivisors[temp].end();++i)
        {
          if(i->second<=n && (!taken[i->first]) && (!taken[i->second]))
          {
            taken[i->first]=true;
            taken[i->second]=true;
            ans[x]=i->first;
            ans[y]=i->second;
            // printf("Assigning ans[%d]=%d, ans[%d]=%d\n", x, ans[x],y,ans[y]);
            break;
          }
        }
      }
      else if(ans[x]==0)
      {
        for(auto i=commonDivisors[temp].begin(); i!=commonDivisors[temp].end();++i)
        {
          if(i->second==ans[y] && (!taken[i->first]))
          {
            taken[i->first]=true;
            ans[x]=i->first;
            // printf("Assigning ans[%d]=%d\n",x,ans[x]);
            break;
          }
        }
      }
      else if(ans[y]==0)
      {
          for(auto i=commonDivisors[temp].begin(); i!=commonDivisors[temp].end();++i)
          {
            if(i->first==ans[x] && (!taken[i->second]))
            {
              taken[i->second]=true;
              ans[y]=i->second;
              // printf("Assigning ans[%d]=%d\n",y,ans[y]);
              break;
            }
          }
      }
    }
    // cout << "....\n";
    for(int i=1; i<=n; ++i)
      cout << ans[i] << "\n";

  }


}
