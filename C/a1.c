/*
**RISHI SHARMA
**B17138
**IC150P
**ASSIGNMENT 1
**TASK_1
**y = (a/b) * e^(x) * (x)^(-0.5)
**FORMATTING OUTPUT
*/

#include <stdio.h>
#include <math.h>

float calc(int a, int b, float x);
int main()
{
  int a,b;
  printf("Enter a: ");
  scanf("%d",&a);
  printf("Enter b: ");
  scanf("%d",&b);
  printf("\nx\ty\n");
  //X FROM 0.1 TO 1.0, STEP = 0.1
  for(float x=0.1, y; x<=1.0; x+=0.1)
  {
    y = calc(a,b,x);
    printf("%.4f\t%.4f\n",x, y);
  }

  printf("\n");
  return 0;

}

float calc(int a, int b, float x)
{
  //y = (a/b) * e^(x) * (x)^(-0.5)
  return ((float) a)/b * exp(x) / sqrt(x);
}
