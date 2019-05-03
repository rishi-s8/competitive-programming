#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n,m,a;
  cin >> n >> m >> a;
  long long horizontal = ceil((double)n/a);
  long long vertical = horizontal*ceil((double)m/a);
  long long ans=vertical;
  vertical=ceil((double)m/a);
  horizontal=vertical*ceil((double)n/a);
  if(ans<horizontal)
    ans=horizontal;
  cout << ans << endl;
}
