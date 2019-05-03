#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void extract_word(char* str, char* new_str);

int main()
{
  char s[500], opt[10];
  int i;
  while(1)
  {
    i=0;
    printf("Enter s: ");
    fgets(s,500,stdin);
    extract_word(s, opt);
    if(!strcmp(opt,"exit\n"))
    {
      printf("Exiting!\n");
      return 0;
    }
    i+=strlen(opt)+1;
    if(!strcmp(opt,"max"))
    {
      int num=0, max=INT_MIN;
      while(s[i]!='\0')
      {
        extract_word(s+i, opt);
        if(opt[0]=='-')
        {
          //Do for negative
        }
        else
        {
          //Do for positive
          num=atoi(opt);
        }
        if(num>max)
          max=num;
        i+=strlen(opt)+1;
      }
      printf("Max: %d\n", max);
    }
  }

  //printf("Extracted Word: %s\n", opt);
  return 0;

}

void extract_word(char* str, char* new_str)
{
  int i=0;
  while(str[i]!=' ')
  {
    new_str[i]=str[i];
    i++;
  }
  new_str[i]='\0';
}
