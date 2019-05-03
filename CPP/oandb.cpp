#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

int bfs (int arr[][1000],int x,int y,int n,int m)
{
    int count=0;
    queue<pair<int,int> > q;
    arr[x][y]=-1;
    q.push(mp(x,y));
    while (!q.empty())
    {
      tie(x,y)=q.front();
      q.pop();
      count++;
      for (int i=-1;i<2;++i)
        for (int j=-1;j<2;++j)
        {
            if ((!(i==0&&j==0))&&x+i>=0&&x+i<n&&y+j>=0&&y+j<m)
                if (arr[x+i][y+j]==1)
                {
                    arr[x+i][y+j]=-1;
                    q.push(mp(x+i,y+j));
                }
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][1000];
        int max=0,count=0,num;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                cin>>arr[i][j];
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (arr[i][j]==1)
                {
                    num=bfs(arr,i,j,n,m);
                    if(max<num)
                        max=num;
                    count++;
                }
        cout<<count<<' '<<max<<'\n';
    }
}
