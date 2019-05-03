#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin >> t;
  while(t--)
  {
    long long c, d, l;
    cin >> c >> d >> l;
    if(l%4!=0) cout << "No\n";
    else if(l>4*c+4*d) cout << "No\n";
    else if(l<4*d) cout << "No\n";
    else if(2*d<c)
    {
      if(l<4*d+4*c-8*d) cout << "No\n";
    }
    else cout << "Yes\n";
  }
}
