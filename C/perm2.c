#include <stdio.h>
#include <string.h>

void exchange(char* a, char* b)
{
  char temp = *a;
  *a=*b;
  *b=temp;
}

int already_printed(char* str, char printed[100000][10], int x)
{
  for(int i=0; i<x; ++i)
  {
    if(!strcmp(str, printed[i]))
      return 1;
  }
  return 0;
}

void perm_helper(char str[], int l)
{
  static char printed[100000][10];
  static int x=0;
  if(str[l+1]=='\0')
  {
      if(!already_printed(str, printed, x))
      {
        printf("%s\n", str);
        strcpy(printed[x++], str);
      }
  }
  else
  {
    for(int i=l; str[i]!='\0'; ++i)
    {
      exchange(&str[l], &str[i]);
      perm_helper(str, l+1);
      exchange(&str[i], &str[l]);
    }
  }
}

void perm(char str[])
{
  int len=strlen(str);
  if(str[len-1]=='\n')
    str[--len]='\0';
  perm_helper(str, 0);
}

int main()
{
  char str[100];
  printf("Enter String: ");
  fgets(str, 100, stdin);
  perm(str);
  return 0;
}
