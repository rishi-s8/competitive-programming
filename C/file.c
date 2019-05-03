#include <stdio.h>
FILE *f;
int main()
{

  f=fopen("out", "w");
  printf("Wow!\n");
  //system("./file 1>&3");
  fclose(f);
  return 0;
}
