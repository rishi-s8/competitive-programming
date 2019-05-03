#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int len = s.size();
    int count = 0;
    for(int i=0; i<len; ++i)
      if(s[i]=='1') ++count;
      else break;
    if(count == 1)
    {
      cout << s << " 0\n";
      return 0; 
    }
    string a(len+1,'0');

    a[0]='1';
    cout << a << " ";
    for(int i=len-1; i>=0; --i)
    {
      if(s[i]=='1')
      {
        cout << "1";
        for(int j=1; j<len-i; ++j) cout << "0";
        cout << endl;
        break;
      }
    }
}
