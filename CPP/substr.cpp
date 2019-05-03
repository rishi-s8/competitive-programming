#include <iostream>
using namespace std;

char* substring(char*, char*);
int main()
{
  char *str=new char[30];
  cout << "Enter String: ";
  cin.getline(str, 30);
  //cout << "str: " << str << endl;
  char *substr=new char[30];
  cout << "Enter Substring to be searched for: ";
  cin.getline(substr, 30);
  //cout << "substr: " << substr << endl;
  char* newstr = substring(str, substr);
  if(newstr!=NULL)
    cout << "FOUND IT! \n" << newstr << endl;
  else
    cout << "Substring Not Found! \n";
  delete str;
  delete substr;
  //delete newstr;
}

char* substring(char* str, char* substr)
{
  //cout << str << endl;
  char* ptr;
  for(int i=0,j=0; str[i]!='\0'; i++)
  {
    if(j==0)
    {
      ptr=str+i;
    }
    if(str[i]==substr[j])
    {
      j++;
      if(substr[j]=='\0')
        return ptr;
    }
    else
      j=0;
  }
  return NULL;
}
