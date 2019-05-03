#include <bits/stdc++.h>
using namespace std;
#define pback push_back

//long ar[100000];

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    long n;
  //  int q=0;
    cin >> n;
    long right = (sqrt(8*n))/2;
    long p,q;
    for(int j=right, k=0; j>=0; --j)
    {
      for(int i=k; i<=j; ++i)
      {
      //  printf("i=%d, j=%d\n", i, j);
        p = (i*(i+1))/2;
        q = (j*(j+1))/2;
        if(p+q == n)
        {
          cout << "YES\n";
          return 0;
        }
        else if(p+q > n)
          break;
      }
      //printf("i = %d\n", i);
      k+=(sqrt(8*(j-1)))/2;

      //printf("I am here i = %d\n", i);
    }


    cout << "NO\n";




  return 0;
}
