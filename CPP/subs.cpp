#include <iostream>
#include <string>
using namespace std;

bool subs(string s)
{
  for(int i=0; s[i]!='\0';++i)
    for(int j=i+1; s[j]!='\0';++j)
      if(s[j]==s[i])
        return true;
  return false;
}

int main()
{
  int t;
  bool y=false;
  string s;
  s.reserve(100);
  scanf("%d",&t);
  while(t--)
  {
    cin >> s;
    if(subs(s))
      printf("yes\n");
    else
      printf("no\n");
  }
}
