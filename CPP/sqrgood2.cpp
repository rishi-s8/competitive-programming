#include <bits/stdc++.h>
using namespace std;

int ar[1000000];

// void sqrGen(vector<int> &sq, int n)
// {
//   int i = 2;
//   int s;
//   while((s=i*i)<=n)
//   {
//     sq.push_back(s);
//     ++i;
//   }
// }
long S(long n);


int main()
{
  int n;
  cin >> n;
  // vector<int> sq;
  memset(ar, 0, sizeof(int)*1000000);
  ar[1]=4;
  // sqrGen(sq, pow(10,8));
  cout << S(n) << endl;

}


long S(long n)
{
  if(ar[n]!=0)
    return ar[n];
  else
  {
    long sum = n;
    //int sign=+1;
    int sq = (int)sqrt(n);
    for(int i=2; i<=sq; ++i)
    {
      sum-=S(n/(i*i));
      //sign=-sign;
    }
    ar[n]=sum;
    return sum;
  }

}
