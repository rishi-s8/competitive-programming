#include <iostream>
#include <vector>
using namespace std;

struct fraction
{
  int num, den;
};

vector<fraction> fract(fraction f);
void print(vector<fraction> vec)
{
  int i=0;
  while(vec[i]!=NULL)
  {
    cout << vec[i].den << ' ';
  }
  cout << endl;
}

int main()
{
  fraction f;
  vector<fraction> ivec;
  cout << "Numerator: " ;
  cin >> f.num;
  cout << "Denominator: ";
  cin >> f.den;
  if(f.num==1)
  {
     cout << den << endl;
     return 0;
  }
  ivec=fract(f);
  print(d);
  return 0;
}

vector<fraction> fract(fraction f)
{
    vector<fraction> ivec;
    fraction t;
    if(f.num>2)
    {
      t.num=1;
      t.den=f.den;
      ivec.push_back(t);
      f.num-=1;
      ivec.push_back(f);
    }


}
