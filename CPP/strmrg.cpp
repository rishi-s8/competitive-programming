#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  string a, b;
//  string c;

  while(t--)
  {

    int n, m;
    cin >> n >> m;
    a.erase();
    b.erase();
  //  c.erase();
    a.resize(n);
    b.resize(m);
  //  c.resize(n+m);
  //  auto z=c.begin();
    cin >> a >> b;
    auto i = a.begin(), j = b.begin();
    char last = '0';
    int count = 0;
    while(i!=a.end() && j!=b.end())
    {
      if(*i == last)
      {
  //      c.insert(z, *i); ++z;
        last=*i;
        ++i;
      }
      else if(*j==last)
      {
  //      c.insert(z, *j); ++z;
        last=*j;
        ++j;
      }
      else
      {
        ++count;
        //Find steps to get *i in b, find consequtive occurances
        auto k1=next(j,1);
        int c1=0, s1=0;
        while(*k1!=*i)
        {
          //cout<<"Looking for " << *i << " current: " << *k1 << endl;
          if(k1==b.end())
          {
            s1=INT_MAX;
            break;
          }
          ++k1;
          ++s1;
        }
        while(*k1==*i && k1!=b.end())
        {
          ++k1;
          ++c1;
        }
        //Find steps to get *j in a
        k1=next(i,1);
        int c2=0, s2=0;
        while(*k1!=*j)
        {
        //  cout<<"Looking for " << *j << " current: " << *k1 << endl;
          if(k1==a.end())
          {
            s2=INT_MAX;
            break;
          }
          s2++;
          ++k1;
        }
        while(*k1==*j && k1 !=a.end())
        {
          c2++;
          ++k1;
        }
        //Make choice
        if(s1 < s2)
        {
          // choose from b
      //    cout << *i << " is closer: " << s1 << " < " << s2 << endl;
          last=*j;
          j++;
        }
        else if(s1>s2)
        {
      //    cout << *j << " is closer: " << s2 << " < " << s1 << endl;
          last=*i;
          ++i;
        }
        else if(c1>c2)
        {
      //    cout << "Equal distance But " << *i  << " more" << endl;
          last=*j;
          j++;
        }
        else
        {
      //    cout << "Equal distance But " << *j  << " more" << endl;
          last=*i;
          ++i;
        }
      }
    //  c.insert(z, last); ++z;
    //  cout<< "Current String: " << c << endl;
    }
  //  cout << "Completed 1..\n";
    while(i!=a.end())
    {
//      cout << "Entered 2..\n";
  //    cout << "Value: " << *i << endl;
  //    c.insert(z, *i); ++z;
    //  cout<< "Current String: " << c << endl;
      if(last!=*i)
      {
        ++count;
        last=*i;

      }
      ++i;
    }
  //  cout << "Completed 2..\n";

    while(j!=b.end())
    {
    //  c.insert(z, *j);
  //    cout << "Inserted..\n";
    //  ++z;
  //    cout<< "Current String: " << c << endl;
      if(last!=*j)
      {
        ++count;

        last=*j;

      }
      ++j;
    }
    cout << count << endl;
  //  cout << count << " " << c <<  endl;
  }
}
