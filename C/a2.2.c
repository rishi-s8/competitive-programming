/*
*** RISHI SHARMA
*** B17138
*** ASSIGNMENT 2
*** TASK 2
*/
#include <stdio.h>
#include <math.h>
int fact(int n)
{
  if(n<=1)
    return 1;
  return n*fact(n-1);
}
double sin_me(float x, int n)
{
  double sum=0;
  for(int i=1, k=1; k<=n; i+=2, ++k)
  {
    if(i%2==0)
      x=-x;
    sum+=pow(x,i)/fact(i);
  }
  return sum;
}

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d!=%d\n",n,fact(n));
  float x;
  scanf("%f", &x);
  printf("sin(%f,%d)=%lf\n",x,n,sin_me(x,n));
  return 0;
}
