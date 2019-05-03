#include <bits/stdc++.h>
using namespace std;

int main()
{

  cout<< 1 << " "<< 5000 << " " << 5000 << endl;
  char c='a';
  for(int i=0;i<5000; ++i)
    printf("%c", c+i%26);
  printf("\n");
  c='z';
  for(int i=0;i<5000; ++i)
    printf("%c", c-i%26);

}
