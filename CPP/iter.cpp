#include <iostream>
#include <deque>
#include <iterator>
using namespace std;
int main()
{
  deque<char> dq;
  for(char a='A'; a<='Z'; a++)
    dq.push_back(a);
deque<char>::iterator iter;

  iter=dq.begin()+2;
  dq.insert(iter, 'y');
  iter=dq.begin();
  while(iter!=dq.end())
    {cout << *iter << endl;
      iter++;

}
  return 0;

}
