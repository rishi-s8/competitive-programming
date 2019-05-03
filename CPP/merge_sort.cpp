#include <iostream>
using namespace std;

int* sort(int* ar, int a, int b);
int* merge(int* p, int* q, int sz);

int main()
{
  int ar[3]={3,2,1};
  int* sorted=sort(ar, 0, 2);
  for(int i=0; i<3; i++)
    cout << sorted[i] << endl;
  return 0;
}

int* sort(int* ar, int a, int b)
{
  int* r;
  int* s;
  if(a+1>=b)
  {
    if(ar[a]>ar[b])
    {
      cout << "Sorting 2:\n";
      cout << "a: " << a << "b: "<<b << endl;
      int temp=ar[a];
      ar[a]=ar[b];
      ar[b]=temp;
    }
    return ar;
  }
  else
  {
    cout << "Applying Recursion\n";
    cout << a << endl << b << endl;
    r = sort(ar, a, b/2);
    cout << "*r: "<< *r << " *r+1:" << *(r+1) << endl;
    cout << "Sorting Second:\n";
    s = sort(ar, (a+b)/2 + 1, b);
    cout << *s << endl;
    cout << "Merging 1\n";
    return merge(r,s, a+b+1);
  }
  cout << "Return NULL\n";
  return NULL;
}

int* merge(int* p, int* q, int sz)
{
  cout << "Merging2\n";
  int fi[sz];
  for(int i=0; i<sz; i++)
  {
    if(*p<*q || *q==NULL)
    {
        cout << "I*p: " << *p <<  " *q: " << *q << endl;
        fi[i]=*p;
        p++;
    }
    else
    {
      cout << "E*p: " << *p <<  " *q: " <<*q << endl;
      fi[i]=*q;
      q++;
    }
  }
  return fi;
}
