#include <bits/stdc++.h>
typedef long long Int;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string days[7]={"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int t;
    cin >> t;
    while(t--)
    {
      Int k; cin >> k;
      vector<int> week(7);
      Int weekSum=0;
      int lastDay;
      for(int i=0; i<7; ++i)
      {
        cin >> week[i];
        weekSum+=week[i];
        if(week[i]>0) lastDay=i;
      }
      k = (int)((Int)k%weekSum);
    //  cout << "k: " << k << endl;
      int day=lastDay;
      if(k>0)
        for(int i=1; i<=7; ++i)
          {
            k-=week[(lastDay+i)%7];
            if(k<=0)
            {
              day=(lastDay+i)%7;
              break;
            }

          }

      cout << days[day] << endl;
    }
}
