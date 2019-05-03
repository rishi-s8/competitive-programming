#include <bits/stdc++.h>
using namespace std;

void sqrGen(vector<int> &sq, int n)
{
  int i = 2;
  int s;
  while((s=i*i)<=n)
  {
    sq.push_back(s);
    ++i;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> sq;
  sqrGen(sq, pow(10,8));
  int k=100000;
  long long s=1000000;
  while(true)
  {
    // if(binary_search(sq.begin(), sq.end(), s))
    //   ++k;
    // else
    // {
      for(auto i = sq.begin(); *i<s; ++i)
      {
        cout << "s: " << s << " n/a^2: "<< n/(*i) << endl;
        if(s%(*i) == 0)
        {
          //cout << "s: " << n/((*i) * (*i)) << endl;
          ++k;
          //break;
          return 0;
        }
      }
    // }
    if(k==n)
    {
      cout << s << endl;
      return 0;
    }
    ++s;
  }

}
