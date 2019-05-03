#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  int ar[2]={0};
  string s;
  s.resize(100001);

  while(t--)
  {
    int prevI=-1;
    ar[0]=0;
    ar[1]=0;
    cin>>s;
    for(int i=0; s[i]!='\0'; ++i)
    {
      if(s[i]!='.')
      {
        if(prevI!=-1 && s[prevI]==s[i])
        {
          ar[s[i]-'A']+=i-prevI;
        }
        else
          ar[s[i]-'A']++;
        prevI=i;
      }
    }
    cout << ar[0] << ' ' << ar[1] << endl;
  }
}
