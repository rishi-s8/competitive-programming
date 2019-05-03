
  char s[words][10], char last='\0', ch;
  int i=0, j=0;
  while((ch=getchar())!='\0')
  {
      if((ch==',' || ch==' ') && last!=' ' && last!=',')
      {
        s[i][j]='\0';
        i++;
        j=0;
      else
      {
        s[i][j]=ch;
        j++;
      }
      last=ch;

  }

  //Now s[i] will have ith word
