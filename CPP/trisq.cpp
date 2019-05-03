#include <bits/stdc++.h>
using namespace std;


long long result(int b)
{
  if(b-2<2)
    return 0;
  int k = b-2;
  return result(b-2) + k/2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin >> t;
  while(t--)
  {
    int b; cin >>b;
    cout << result(b) << endl;
  }
  return 0;
}
