#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, temp;
  cin >> n;
  vector<int> v(n);
  for(auto i=v.begin(); i!=v.end(); ++i)
  {
    cin >> temp;
    *i=temp;
  }
  int q;
  cin  >> q;
  int x,y;
  int alive=n;
  // if(n<=pow(2,17) && q<=pow(2,11))
  // {
    for(int i = 0; i<q; ++i)
    {
      cin >> x >> y;
      for(int k=0; k<=x; ++k)
      {
        if((k&x)==k && v[k]>0)
        {
          v[k]-=y;
          if(v[k]<=0)
            --alive;
        }
      }
      for(int z=0; z<n; ++z)
        cout << v[z] << " ";
      cout << endl;
    }
  // }
  // else
  // {
  //   for(int i=0; i<q; ++i)
  //   {
  //     cin >> x >> y;
  //
  //     if(x==0)
  //       alive-=1;
  //     else
  //     {
  //       int count = 1;
  //       while(x)
  //       {
  //         if(x%2)
  //           count*=2;
  //         x/=2;
  //       }
  //       alive-=count;
  //     }
  //     cout << alive << endl;
  //   }
  //
}
