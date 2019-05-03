#include <bits/stdc++.h>
using namespace std;

double calc(int num, int max)
{
  return ((double) num*(num-1)) / (max*(max-1));
}
int main()
{
  int t;
  cin >> t;
  vector<int> v;
  double prob;
  while(t--)
  {
    v.erase(v.begin(), v.end());
    int n;
    cin>>n;
    int k;
    for(int i=0; i<n; ++i)
    {
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    int count_max=1;
    int j=n-2;
    while(v[j]==v[j+1] && j>=0)
    {
      ++count_max;
      j--;
    }
    if(count_max>1)
    {
      prob=calc(count_max, n);
    }
    else
    {
      int n_max=1;
      j--;
      while(v[j]==v[j+1] && j>=0)
      {
        ++n_max;
        j--;
      }
      prob=((double)n_max) * 2 / (n*(n-1)) ;
    }
    cout << prob << '\n';
  }
}
