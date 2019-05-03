#include <bits/stdc++.h>
using namespace std;

char getMax(string &a, char ch);

int main()
{
  string a, b, c;
  cin >> a >> b;
  int lenA=a.size(), lenB=b.size();
  bool done = false, pr=false;
  sort(a.begin(), a.end());
  if(lenA>lenB)
  {
    while(lenB!=lenA)
    {
      b = '0' + b;
      ++lenB;
    }
  }
  prev_permutation(a.begin(), a.end());
  while(stoll(a)>stoll(b))
  {
    prev_permutation(a.begin(), a.end());
  }
  cout << a << endl;
}
