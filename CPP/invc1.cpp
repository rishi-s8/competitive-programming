#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> vec;
  for(int i=0, k=0; i<n;++i)
  {
    scanf("%d", &k);
    vec.push_back(k);
  }
  int count=0;
  for(int k=0; k<n; ++k)
  {
    for(int i=k+1; i<n; ++i)
      if(vec[k]>vec[i])
        ++count;
  }
  printf("%d\n", count);
}
