#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  string s, part;
  scanf("%d", &t);
  string get="ab";
  while(t--)
  {

    int n, p;
    scanf("%d%d", &n,&p);
    if(p<=2)
    {
      printf("impossible\n");
      continue;
    }
      part.clear();
    part.resize(p);
    int l=0, r=p-1;
    for(l=0; l<r; l++, r--)
    {
      part[l]=get[l%2];
      part[r]=part[l];
    }
    if(p%2!=0)
    {
      part[l]=get[l%2];
    }
    s.resize(n);
    s.clear();

    for(int k=0; k<n/p; ++k)
      s+=part;
    //s[n]='\0';
    int len=s.size();
    cout << s << '\n';
  }
}
