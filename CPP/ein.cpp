#include <bits/stdc++.h>
#define IN 1000
using namespace std;

int main()
{
  vector<int> vec;
  int a, n, t, k, val;
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d%d", &n, &k);
    vec.clear();
    a=n;
    while(n--)
    {
      scanf("%d", &val);
      vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    vec.insert(vec.end(), k, IN);
    printf("%d\n", vec[(a+k)/2]);
  }
}
