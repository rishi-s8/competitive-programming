#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
      string s;
      cin >> s;
      long long count = 0;
      map<char,int> l;
      l['c']=l['h']=l['e']=l['f']=0;
      int len=s.size();
      for(int i=0; i<4; ++i)
      {
        l[s[i]]++;
      }
      if(l['c'] && l['h'] && l['e'] && l['f'])
        ++count;
      for(int i=4; i<len; ++i)
      {
        l[s[i-4]]--;
        l[s[i]]++;
        if(l['c'] && l['h'] && l['e'] && l['f'])
          ++count;
      }
      if(count)
        cout << "lovely " << count << endl;
      else
        cout << "normal" << endl;
    }
}
