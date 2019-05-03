#include <stdio.h>
#include <float.h>
int main()
{
  float f=1;
  while(f>0)
  {
    printf("Value of float: %f\n", f);
    f/=10;
  }
  return 0;
}
