#include <bits/stdc++.h>
using namespace std;

void generator(multiset<string> &setSubs, string s);

int main()
{
  string s = "abc";
  multiset<string> setSubs;
  generator(setSubs,s);
  for(auto i = setSubs.begin(); i!=setSubs.end(); ++i)
    cout << *i << endl;
}

void generator(multiset<string> &setSubs, string s)
{
  string t;
  int len=s.size();
  for(int i=0; i<len; ++i)
  {
    for(int j=1; i+j<=len; ++j)
    {
      t=s.substr(i,j);
    //  cout << t << endl;
      setSubs.insert(t);
    }
  }
}
