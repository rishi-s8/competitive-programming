#include <bits/stdc++.h>
using namespace std;

void fn(int ar1[3], int ar2[3])
{
  int smaller;
  for(int i=0; i<)
}

int main()
{
  int t;
  int ar[3][3];
  cin>>t;
  while(t--)
  {
    for(int i=0; i<3; ++i)
      for(int j=0; j<3; ++j)
        cin>>ar[i][j];
    int smaller, equal=false;
    if(ar[0][0]<ar[1][0])
      smaller=0;
    else if(ar[0][0]==ar[1][0])
      equal=true;
    else
      smaller=1;
    for(int k=1; k<3; ++k)
      if(ar[smaller][k]>ar[1-smaller])
      {
        equal=false;
        cout << "no\n";
        break;
      }
    if(ar[1][0]<ar[2][0])
      smaller=1;


  }
}
