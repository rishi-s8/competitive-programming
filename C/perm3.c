#include <stdio.h>
#include <string.h>

void exchange(char* a, char* b)
{
  char temp = *a;
  *a=*b;
  *b=temp;
}

void perm_helper(char str[], int l, int len)
{
  if(str[l+1]=='\0')
    printf("%s\n", str);
  else
  {
    for(int i=l; str[i]!='\0'; ++i)
    {
      exchange(&str[len-1], &str[i]);
      perm_helper(str, l+1, len);
      exchange(&str[i], &str[len-1]);
    }
  }
}

void perm(char str[])
{
  int len=strlen(str);
  perm_helper(str, 0, len);
}

int main()
{
  char str[100];
  printf("Enter String: ");
  gets(str);
  perm(str);
  return 0;
}
