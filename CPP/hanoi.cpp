#include <iostream>
using namespace std;

void move(string fr, string to, string sub, int n);
void solve(int n);

int main()
{
  cout << "Please enter the length of the stack: ";
  int n;
  cin >> n;
  solve(n);
  return 0;
}

void move(string fr, string to, string sub, int n)
{
  cout << fr << " -> " << to <<endl;
}

void solve()
