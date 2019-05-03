#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int x, n;
    cin >> x >> n;
    vector<int> v(n+1);
    unsigned long long p = n;
    unsigned long long sum = (p*(p+1))/2  - (long long)x;
    unsigned long long sumCur = 0;
    unsigned long long sumCur1 = 0;
    if(sum%2!=0 || n<4)
    {
      cout << "impossible\n";
      continue;
    }
    sum/=2;
    for(int i=n; i>0; --i)
    {
      if(i==x)
      {
        v[i]=2;
      }
      else if(sumCur+i<=sum)
      {
        sumCur+=i;
        v[i]=0;
      }
      else
      {
        sumCur1+=i;
        v[i]=1;
      }
    }


    if(sumCur!=sumCur1 || sumCur!=sum)
    {
      sumCur1=n;
      sumCur=0;
      for(int i=n-1; i>0; --i)
      {
        if(i==x)
        {
          v[i]=2;
        }
        else if(sumCur+i<=sum)
        {
          sumCur+=i;
          v[i]=1;
        }
        else
        {
          sumCur1+=i;
          v[i]=0;
        }
      }
    }

    for(auto i=next(v.begin(),1); i!=v.end(); ++i)
       cout << *i;
    cout << endl;
  }
}
