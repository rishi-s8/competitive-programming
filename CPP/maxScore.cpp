#include <bits/stdc++.h>
using namespace std;


int main()
{
  int t, n, temp;
  scanf("%d", &t);

  while(t--)
  {
    scanf("%d", &n);
    vector< set<int> > vect(n);
    for(int i=0; i< n; ++i)
      for(int j=0; j<n; ++j)
      {
        scanf("%d", &temp);
        vect[i].insert(temp);
      }

    int last = *(vect[n-1].rbegin());
    long sum=last;
    for(auto i=vect.rbegin()+1; i!=vect.rend(); ++i)
    {
      for(auto j=i->rbegin(); ; ++j)
      {
    //    cout << "Sum: " << sum << endl;
        if(*j < last)
        {
          //cout << "Current element is " << *j << " so adding\n";
          last = *j;
          sum+=last;
          break;
        }
        else if(j== i->rend())
        {
        //    cout << "Current element is " << *j << " But j is at first element\n";
          sum=-1;
          break;
        }
      }
      if(sum==-1)
        break;
    }
    printf("%ld\n", sum);
  }
}
