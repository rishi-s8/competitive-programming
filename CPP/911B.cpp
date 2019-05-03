#include <bits/stdc++.h>
using namespace std;

int calc(int tempA, int tempB, int tempN, int minimum);
int main()
{
  int n, a ,b, temp;
  cin >> n >> a >> b;
  if(a>b)
  {
    temp=a;
    a=b;
    b=temp;
  }
  int left=1, right=a+1, soln=0;
  while(left<right)
  {
    int mid=(left+right)/2;
    int ans=calc(a,b,n,mid);
    if(ans<=0)
    {
      left=mid+1;
      soln=max(soln,mid);
    }
    else
      right=mid;
  }
  cout << soln << endl;

}

int calc(int tempA, int tempB, int tempN, int minimum)
{
  while(tempA>=minimum)
  {
    tempN--;
    tempA-=minimum;
  }
  while(tempB>=minimum)
  {
    tempN--;
    tempB-=minimum;
  }
  return tempN;
}
