#include <iostream>
#include <iomanip>
using namespace std;

long double fact(int n)
{
  if(n<=1)
    return 1;
  else
    return n*fact(n-1);
}

int main()
{
  long double res;
  int n;
  cout << "Enter num: ";
  cin >> n;
  res=fact(n);
  cout << "Result: " << fixed << res << endl;
  return 0;
}
