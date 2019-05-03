#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
  int t, num;
  bool found;
  string s;
  char temp[2];
  scanf("%d\n", &t);
  while(t--)
  {
    found = false;
    int done[] = {0,0,0,0};
    char ar[]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    cin >> s;
    for(int i=0; s[i]!='\0'; ++i)
    {
      for(int j=i+1; s[j]!='\0'; ++j)
      {
        if(done[s[j]-'0'-6]!=0)
          continue;
        else if(s[j]>='6' && s[j]<='8')
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
        }
        else if(s[i]=='0')
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
