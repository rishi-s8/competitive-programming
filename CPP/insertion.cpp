#include <iostream>
using namespace std;

void my_insert(int ar[], int i)
{
  int val=ar[i];
  while(i>0 && val<ar[i-1])
  {
    ar[i]=ar[i-1];
    --i;
  }
  ar[i]=val;
}

void my_sort(int ar[], int n)
{
  for(int i=1; i<n; ++i)
  {
    my_insert(ar, i);
    // for(int i=0; i<5; ++i)
    //   cout << i << ' ';
    // cout << '\n';
  }
}



int main()
{
  int a[10];
  for(int i=0; i<5; ++i)
    cin >> a[i];

  my_sort(a,5);
  for(int i=0; i<5; ++i)
    cout << a[i] << ' ';
  cout << '\n';
  return 0;
}
