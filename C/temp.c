#include <stdio.h>

int main()
// Conversion of temp from fahrenheit to celsius
{
  float c,f,lower,upper,step;

  lower = 0;
  upper = 100;
  step = 20;
  f = lower;

  while (f <= upper) {
      c = (5.0/9.0)*(f-32);
      printf("%f  %f\n",f,c);
      f = f + step;
    }
    return 0;
}
