#include <iostream>
using namespace std;

int find_rot(int ar[], int l, int r);

int main()
{
  int ar[]={12,14,18,21,3,6,8,9, 10, 11,12};
  int l=0, r=9;
  cout << "Rotation: " << find_rot(ar, l, r) << endl;
  return 0;
}

int find_rot(int ar[], int l, int r)
{
  int i=l, j = r;
  if(ar[i]<ar[j])
    return i;
  int m;
  while(l<=r)
  {
    if(l==r)
      return l;
    m=l+(r-l)/2;
    if(ar[m]<ar[i])
      r=m;
    else
      l=m+1;
  }
  return m;
}
