#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define getInt(x) scanf("%d",&x)
#define getFloat(x) scanf("%f", &x)

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float a, b, c;
    getFloat(a);
    getFloat(b);
    getFloat(c);
    float D = b*b-4*a*c, r11, r12;
    // Traditional Method...
    if(D>=0)
    {
      r11 = (-b-sqrt(D))/(2*a), r12=(-b+sqrt(D))/(2*a);
      printf("r11 %f  	 r12 %f\n", r11,r12);
    }
    else
    {
      r11 = -b/(2*a), r12=fabs(sqrt(-D)/(2*a));
      printf("r11 %f+i %f r12 %f-i %f\n", r11, r12, r11, -r12);
    }
    // A Better way...
    float Q = -0.5*(b+(b/(fabs(b)))*sqrt(D));
    float r21 = Q/a;
    float r22 = c/Q;

    printf("r21 %f  	 r22 %f\n", r21, r22);
    return 0;
}
