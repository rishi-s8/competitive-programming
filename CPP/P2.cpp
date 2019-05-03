#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
  vector<char> s;
  int f=0;
  int sz=0;
  string str;
  cin >> str;
  char temp;
  int k=str.size();
  for(int j=0; j<k; j++)
  {
    s.push_back(str[j]);
    sz++;
  }
  int n;
  cin >> n;
  int z;
  cin >> z;
  for(int i=0; i<n; i++)
  {
    for(int iter=0; iter<sz; iter++)
    {
      switch(s[iter])
      {
        case 'A':
            s[iter]='B';
            f=1;
            break;
       case 'B':
            s[iter]='A';
            s.push_back('B');
            break;
      case  'C':
            s[iter]='C';
            s.push_back('D');
            break;
      case  'D':
            s[iter]='D';
            s.push_back('C');
            break;
      case  'E':
            s.push_back('E');
            break;
      }
      if(f!=1)
      {
        sz++;
        temp = s[sz-1];
        for(int phi=sz-1;phi>iter+1;phi--)
          s[phi]=s[phi-1];
        s[iter+1]=temp;
        iter++;
      }
    }
  }
  int ar[5]={0,0,0,0,0};
  for(int i=0; i<z;i++)
  {
    ar[s[i]-65]++;
  }
  for(int j=0; j<5;j++)
  {
    cout << ar[j] << " ";
  }

  return 0;
}
