#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a;
  char *x = (char*) &a;
  x[0]=1; x[1]=2;
  printf("%d\n",a );
}
