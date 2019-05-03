#include <stdio.h>
#include <string.h>

char permutations[1000][1000];
int fact(int n)
{
  if(n==1)
    return 1;
  return n*fact(n-1);
}
void perm(char str[])
{

  static int i = 0;
  if(strlen(str)==1)
  {
    strcpy(permutations[i], str);
    ++i;
  }
  else
  {
    perm(str+1);
    int unique=i;
    int loop_max=strlen(str+1);
    for(int x=0; x<loop_max; ++x)
    {
      for(int j=0; j<unique; ++j)
        strcpy(permutations[i++], permutations[j]);
    }

    char first = str[0];
    char str_first[1000];
    int len=strlen(permutations[0]);
    for(int k=0; k<i; ++k)
    {
      int l=k%(unique+1);
      strncpy(str_first, permutations[k], l);
      str_first[l]='\0';
      strcat(str_first, &first);
      strcat(str_first, *(permutations+k)+l);
      strcpy(permutations[k], str_first);
    }
  }
  return;
}

int main()
{
  char str[1000];
  printf("Enter String: \n");
  fgets(str,1000,stdin);
  int len=strlen(str);
  if(len==1)
  {
    printf("\n");
    return 0;
  }

  str[--len]='\0';
  printf("%s\n",str);
  return 0;
  len=fact(len);
  perm(str);
  for(int i=0; i<len; ++i)
  {
    printf("%s\n", permutations[i]);
  }
  return 0;
}
