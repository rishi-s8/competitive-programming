#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{ _
  int n,k;
  cin >> n >> k;
  set<char> c;
  char temp;
  string s;
  cin >> s;
  for(auto i : s)
    c.insert(i);
  if(k>n)
  {
    while(k>n)
    {
      s+=(*c.begin());
      n++;
    }
     cout << s << endl;
     return 0;
  }
  else
  {
    s=s.substr(0,k);
    for(int i=k-1; i>=0; --i)
    {
      if(c.upper_bound(s[i])!=c.end())
      {
        s[i]=*(c.upper_bound(s[i]));
        cout << s << endl;
        return 0;
      }
      else s[i]= *c.begin();
    }
  }
}
