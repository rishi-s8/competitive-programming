#include <bits/stdc++.h>
using namespace std;

int main()
{
  for(int i=0; i<33; ++i)
  {
    for(int j=0; j<33; ++j)
    {
      if((j&i)==j)
      printf("%d&%d=%d\n", j,i,j&i);
    }
  }
}
