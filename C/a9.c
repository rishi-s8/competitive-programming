#include <stdio.h>
#include <string.h>

int main()
{
  FILE* inf = fopen("../Downloads/courses.txt", "r");
  if(inf==NULL)
  {
    printf("File not found\n");
    return -1;
  }
  char str[8][10];
  for(int i=0; i<8; ++i)
  {
    fscanf(inf, "%s", str[i]);
  }

  int k, f=0;
  printf("Enter column number: ");
  scanf("%d", &k);

  char toSearch[10];
  scanf("%s", toSearch);

//  printf("To Search: %s\n", toSearch);
  char searched[8][10];
  while(!feof(inf))
  {
    for(int i=0; i<8; ++i)
    {

      fscanf(inf,"%s", searched[i]);
    //  printf("Found: %s in column %d\n", searched[i], i);
    }
    if(!strcmp(searched[k-1], toSearch))
    {
      f=1;
      int j=0;
      for(; j<8; ++j)
      {
        printf("%s\t\t", searched[j]);
      }
      printf("\n");
    }
  }
  if(f==0)
  {
    printf("None!\n");
  }

  fclose(inf);
  return 0;
}
