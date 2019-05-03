#include <bits/stdc++.h>
using namespace std;

void generator(multiset<string> &setSubs, string s);

int main()
{
  string s;
  cin >> s;
  multiset<string> setSubs;
  generator(setSubs, s);
  int q;
  scanf("%d", &q);
  long p, m, g=0;
  while(q--)
  {
    scanf("%ld%ld", &p,&m);
    int k = (p*g)%m+1;
    int sum=0;
    auto i = setSubs.begin();
    while(sum+(*i).size() <k)
    {
      sum+=(*i).size();
      ++i;
    }
    char c = (*i)[k-sum-1];
    g+=c;
    cout << c << endl;


  }
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
