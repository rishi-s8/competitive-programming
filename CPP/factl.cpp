#include <iostream>
#include  <string.h>
//#include <stdlib.h>
using namespace std;

//string mult(string s1, int n);
string add(string s1, string s2);
string add_helper(string s1, string s2);
int main()
{
  string s1,s2;
  //int n=2;
  cout << "Enter the number1: ";
  cin >> s1;
  cout << "Enter the number2: ";
  cin>>s2;
  s2=add(s1,s2);
  cout<<"Result: " << s2 << endl;
  return 0;
}

string add(string s1, string s2)
{
  if(s1.size()>s2.size())
    return add_helper(s1,s2);
  return add_helper(s2,s1);
}

string add_helper(string s1, string s2)
{
  string s3;
  int carry=0, added=0;
  int len1=s1.size()-1;
  int len2=s2.size()-1;
  s3.resize(len1+2);
  while(len2>=0)
  {
    added=s1[len1]-'0' +s2[len2]-'0'+carry;
    carry=added/10;
    cout << "Added: " << added << endl;
    cout << "Carry: " << carry << endl;
    s3[len1+1]=(added%10)+'0';
    cout << "s3[" << len1+1 << "]=" << s3[len1+1] << endl;
    --len1; --len2;
  }
  while(len1>=0)
  {
    added=s1[len1]-'0'+carry;
    carry=added/10;
    cout << "Added: " << added << endl;
    cout << "Carry: " << carry << endl;
    s3[len1+1]=(added%10)+'0';
    cout << "s3[" << len1+1 << "]=" << s3[len1+1] << endl;
    --len1;
  }
  if(carry>0)
  {
      s3[0]=carry+'0';
      cout << "s3[0] = " << s3[0] << endl;
  }
  else
  {
      s3.erase(s3.begin());
  }
  return s3;
}

//TODO
/*string mult(string s1, int n)
{
  string ans;
  char ch;
  int k;
  int len=s1.size();
  for(int i=len-1; i>=0; i--)
  {
    ch=s1[i]);
    k=atoi(&ch);

  }
}*/
