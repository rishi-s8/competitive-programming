#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{ _
  int n, temp;
  cin >> n;
  vector<int> v;
  for(int i=0; i<n; ++i)
  {
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  int maxCount=0;
  auto i=v.rbegin();
  do
  {
    int m=*i;
    for(i; *i==m && i!=v.rend(); ++i) maxCount++;
    if(maxCount % 2 != 0)
    {
      cout << "Conan\n";
      return 0;
    }
  } while(maxCount!=0 && i!=v.rend());
  cout << "Agasa\n";
  return 0;
}
