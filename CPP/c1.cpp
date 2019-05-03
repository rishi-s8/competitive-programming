#include <bits/stdc++.h>
#define infinite 1000000000000000
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{ _
   int n, d;
   cin >> n  >> d;
   deque<int> m;
   int temp;
   for(int i=0; i<n; ++i)
   {
     cin >> temp;
     m.push_back(temp);
   }
   sort(m.begin(),m.end());
   int count = 0;
   for(int i=0; i<n; ++i)
   {
     if((*m.rbegin())-(*m.begin())<=d)  break;
     else
     {
       ++count;
       if(m[m.size-2]-m[0]>m[m.size-1])
     }
   }
   cout << count << endl;

}
