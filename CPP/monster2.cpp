#include <bits/stdc++.h>
using namespace std;
#define getInt(n) scanf("%d", &n)

int main()
{
        int n, temp;
        getInt(n);
        // A pair.. First element of pair contain value, second contains indices
        list< pair<int, int> > v(n);
        auto it = v.begin();
        for(int i=0; i<n; ++i, ++it)
        {
          getInt(temp);
          *it = make_pair(temp, i);
        }

        int q;
        getInt(q);
        int x,y,j;

        for(int i = 0; i<q; ++i)
        {
                scanf("%d%d", &x, &y);
                it=v.begin();
                while(it!=v.end())
                {
                  j=it->second;
                  if((j&x)==j)
                  {
                    it->first-=y;
                    if(it->first<=0)
                    {
                      n--;
                      //Erase element if it becomes <= 0
                      it=v.erase(it);
                    }
                    else ++it;
                  }
                  else
                    ++it;
                }
                printf("%d\n", n);
        }
}
