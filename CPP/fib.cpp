#include <iostream>
#include <vector>
using namespace std;

int fib(vector<int> &vec, int n);
int main()
{
  int a;
  vector<int> ivec;
  ivec.push_back(0);
  char c;
  cin >> c;
  ivec.push_back(c-'A'+1);
  cin >> c;
  ivec.push_back(c-'A'+1);
  for(int i=1;i<30;i++)
  {
    a = fib(ivec, i);
    c = a + 'A' - 1;
    cout << endl << c << "  " << c + 1 -'A' << endl;
  }
  return 0;

}

int fib(vector<int> &vec, int n)
{
  if(vec[n]!=NULL && vec[n]!= 0)
  {
    return vec[n];
  }
  else if(n<=2)
  {
    return vec[n];
  }
  int f;
  f=(fib(vec, n-1)%26+fib(vec,n-2)%26);
  if(f!=26)
    f%=26;
  vec[n]=f;
  return f;
}
