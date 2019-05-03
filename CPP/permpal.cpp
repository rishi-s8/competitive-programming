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
    int len=s.size();
    vector< vector<int> > v(26);
    for(int i=0; i<len; ++i)
      v[s[i]-'a'].push_back(i);
    int odd=-1;
    bool correct=true;
    for(int i=0; i<26; ++i)
    {
      if(v[i].size()%2 && odd!=-1)
      {
        correct=false;
        break;
      }
      else if(v[i].size()%2)
        odd=i;
    }
    if((len%2==0 && odd!=-1)||(!correct))
    {
      cout << -1 << endl;
      continue;
    }
    deque<int> q;
    if(odd!=-1)
    {
      q.push_back(*(v[odd].begin())+1);
      (v[odd]).erase((v[odd]).begin());
    }
    vector<int>::iterator it;
    for(int i=0; i<26; ++i)
    {
      while(v[i].size())
      {
        it=v[i].begin();
        q.push_front(*it+1);
        it=v[i].erase(it);
        q.push_back(*it+1);
        it=v[i].erase(it);
      }
    }
    for(auto z:q)
      cout << z << " ";
    cout << endl;
  }
}
