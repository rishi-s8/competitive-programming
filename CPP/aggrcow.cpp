#include <bits/stdc++.h>
using namespace std;

int main()
{
  //int t;
  long n,c;
  long temp, result;
  vector<long> v;
  long high, low;
//  cin >> t;
//  while(t--)
  //{
    v.erase(v.begin(), v.end());

    cin>>n>>c;
    for(long i=0; i<n; ++i)
    {
      cin >> temp;
      v.push_back(temp);
    }
    sort(v.begin(), v.end());
    high=v[n-1]-v[0] + 1;
    low=1;
    long m;

    while(low<high)
    {
      // printf("High: %ld, Low: %ld\n", high, low);
      long allowed=1;
      m = low + (high-low)/2;
      // printf("Mid: %ld\n", m);
      //count allowed

      for(long i=1, last=0; i<n; ++i)
      {
        if(v[i]-v[last]>=m)
        {
          allowed++;
          last=i;
        }
      }

  //    printf("Allowed: %ld\n", allowed);

      if(allowed>=c)
      {
      //  printf("Setting Result from %ld to %ld\n", result, m);
        result=m;
        low=m+1;
      }

      if(allowed < c)
      {
        high=m;
      }
    }
    cout << result << endl;
//  }
}
