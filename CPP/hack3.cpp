#include <bits/stdc++.h>
using namespace std;
#define pback push_back

//long ar[100000];
//long sum(long n)
//{
//  return (n*(n+1))/2;
//}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    long n;
  //  int q=0;
    cin >> n;
    for(long i=0; i<n; ++i)
    {
      long p=(i*(i+1))/2;
      long q;
      long right = (sqrt(8*n + 1) + 1)/2, left=i;

      while(left<right)
      {

        long mid = (left+right)/2;

        q=(mid*(mid+1))/2;
      //  cout << "Printing:\n p: " << p << " q: " << q << " Left: " << left << " Right: " << right << endl;
        if((p+q)==n)
        {
          cout << "YES\n";
          return 0;
        }
        else if((p+q)<n)
        {
          left=mid+1;
        }
        else
          right = mid-1;
      }


    }
    cout << "NO\n";




  return 0;
}
