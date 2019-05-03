/*
*** RISHI SHARMA
*** B17138
*** ASSIGNMENT 2
*** TASK 1
*/
#include <stdio.h>

void perform(int ar[5])
{
  for(int i=0; i<5; ++i)
    scanf("%d", &ar[i]);
  for(int i=0; i<5; ++i)
  {
    for(int j=0;j<4;++j)
    {
      if(ar[j]>ar[j+1])
      {  //swap(ar[j],ar[j+1]);
        ar[j]+=ar[j+1];
        ar[j+1]=ar[j]-ar[j+1];
        ar[j]-=ar[j+1];
      }
    }
  }
  printf("Maximum: %d\nMinimum: %d\n", ar[4], ar[0]);
}

int main()
{
  int ar[5];
  perform(ar);
  printf("PRINTING ASCENDING ORDER: \n");
  for(int k=0; k<5; ++k)
  {
    printf("%d ", ar[k]);
  }
  printf("\nPRINTING DESCENDING ORDER: \n");
  for(int k=4; k>=0; --k)
  {
    printf("%d ", ar[k]);
  }
  printf("\n");
  return 0;
}
