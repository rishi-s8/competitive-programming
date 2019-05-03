#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
  int t, num;
  string s;
  char temp[2];
  scanf("%d\n", &t);
  while(t--)
  {
    int done[] = {0,0,0,0};
    char ar[]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    cin >> s;
    for(int i=0; s[i]!='\0'; ++i)
    {
      if(s[i]>='6' && s[i]<='8' && done[s[i]-'0'-6]==0)
      {
        done[s[i]-'0'-6]=1;
        for(int j=0; s[j]!='\0'; ++j)
        {
          if(i!=j)
          {
            temp[0]=s[i];
            temp[1]=s[j];
            num=atoi(&temp[0]);
            if(num >= 'A' && num <='Z')
            {
              ar[num-'A'] = char(num);
            }
            temp[0]=s[j];
            temp[1]=s[i];
            num=atoi(&temp[0]);
            if(num >= 'A' && num <='Z')
            {
              ar[num-'A'] = char(num);
            }
          }
        }
      }
      if(s[i]=='9' && done[3]==0)
      {
        done[3]=1;
        for(int j=0; s[j]!='\0'; ++j)
          if(s[j]=='0')
          {
            ar[25]='Z';
          }
      }
    }
    for(int k=0; k<26; ++k)
      if(ar[k]!='0')
      {
          printf("%c",ar[k]);
      }
      printf("\n");
  }
  return 0;
}
