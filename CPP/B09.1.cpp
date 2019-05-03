#include <iostream>
#include <string.h>
using namespace std;

int search(string s, char ar[9][5], int sz[9]);

int main()
{
  char ar[9][5];
  int sz[9]={3,3,5,4,4,3,5,5,4};
  string s="ONE";
  for(int i=0;i<sz[0];i++)
    ar[0][i]=s[i];
  s="TWO";
  for(int i=0;i<sz[1];i++)
    ar[1][i]=s[i];
  s="THREE";
  for(int i=0;i<sz[2];i++)
    ar[2][i]=s[i];
  s="FOUR";
  for(int i=0;i<sz[3];i++)
    ar[3][i]=s[i];
  s="FIVE";
  for(int i=0;i<sz[4];i++)
    ar[4][i]=s[i];
  s="SIX";
  for(int i=0;i<sz[5];i++)
    ar[5][i]=s[i];
  s="SEVEN";
  for(int i=0;i<sz[6];i++)
    ar[6][i]=s[i];
  s="EIGHT";
  for(int i=0;i<sz[7];i++)
    ar[7][i]=s[i];
  s="NINE";
  for(int i=0;i<sz[8];i++)
    ar[8][i]=s[i];

  cin >> s;
  int digit=search(s,ar,sz);
  if(digit==-1)
    cout << "NO" << endl;
  else
    cout << digit << endl;
  return 0;

}

int search(string s, char ar[9][5], int sz[9])
{
  int len = s.size(), k=-1, flag=0;
  for(int i=0; i<9;i++)
  {
      for(int j=0;j<sz[i];j++)
      {
        k = s.find_first_of(ar[i][j], k+1);
        cout << "Found " << ar[i][j] << " at " << k << endl;
        if(k==-1)
        {
          flag=1;
          break;
        }
        else if(j==sz[i]-1)
          return i+1;
      }
      if(flag==1)
      {
        flag=0;
        continue;
      }

    }
    return -1;
}
