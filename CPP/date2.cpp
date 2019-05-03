#include <iostream>
using namespace std;
struct date
{
  int d, m, y;
};
bool isleap(int);
int main()
{
  cout << "Enter date(dd mm yy): ";
  date d1;
  cin>>d1.d>>d1.m>>d1.y;
  cout << "Enter Days to be added: ";
  int n;
  cin >> n;
  int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  if(isleap(d1.y))
    days[2]=29;
  d1.d+=n;
  while(d1.m>12||d1.d>days[d1.m])
  {
    if(d1.m>12)
    {
      d1.y+=(d1.m)/12;
      d1.m%=12;
    }
    if(isleap(d1.y))
      days[2]=29;
    else
      days[2]=28;
    if(d1.d>days[d1.m])
    {
      d1.d-=days[d1.m];
      d1.m+=1;
    }
  }
  cout << "The new date is: " << d1.d<<'-'<<d1.m<<'-'<<d1.y<<endl;
  return 0;
}

bool isleap(int y)
{
  if(y%4!=0)
    return false;
  else if(y%100==0 && y%400!=0)
    return false;
  return true;
}
