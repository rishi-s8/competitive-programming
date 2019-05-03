
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin >> n >> m;
  vector < string > v(n);
  char temp;
  string move = "DLUR";
  pair<int,int> start, end;
  for(int i=0; i<n; ++i)
  {
    for(int j=0; j<m; ++j)
    {
      cin >> temp;
      v[i]+=temp;
      if(temp=='S')
        start={i,j};
      else if(temp=='E')
        end={i,j};
    }
  }
    // cout << "\nStart: " << start.first <<", " << start.second << endl;
    // cout << "\nEnd: " << end.first <<", " << end.second << endl;
  string code;
  cin >> code;
  int count=0;
  bool correctPath;
  for(int i=0; i<24; ++i)
  {
    // cout << "Directions: " << move << endl;
    correctPath=false;
    pair<int,int> current=start;
    for(auto c:code)
    {
      // cout << "\nCurrent: " << current.first <<", " << current.second << endl;
      char k = move[((int)c-'0')];
      // cout << "k: " << k << endl;
      if(k=='R')
        (current.second)++;
      else if(k=='L')
        (current.second)--;
      else if(k=='U')
        (current.first)--;
      else if(k=='D')
        (current.first)++;
      if(current.first<0 || current.first >=n || current.second<0 || current.second>=m||v[current.first][current.second]=='#')
        break;
      else if(current==end)
      {
        correctPath=true;
        break;
      }
    }
    if(correctPath)
    {
      count++;

    }
    next_permutation(move.begin(),move.end());
  }
  cout << count << endl;

}
