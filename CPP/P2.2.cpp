#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int sz=0;
  deque<char> dq;
  deque<char>::iterator iter;
  for(int i=0; s[i]!='\0'; i++)
  {
    dq.push_back(s[i]);
    sz++;
  }
  int n, z;
  cin >> n >> z;
  for(int i=0; i<n;i++)
  {

    for(int p=0; p<sz; p++)
    {
      iter=dq.begin()+p;
      switch(*iter)
      {
        case 'A':
          *iter='B';
          break;
        case 'B':
          *iter='A';
          sz++,p++;
          iter++;
          dq.insert(iter, 'B');
          break;
          case 'C':
            *iter='C';
            iter++,p++;
            sz++;
            dq.insert(iter, 'D');
            break;
            case 'D':
              *iter='D';
              iter++,p++;
              sz++;
              dq.insert(iter, 'C');
              break;
              case 'E':
                iter++,p++;
                sz++;
                dq.insert(iter, 'E');
                break;
      }
    }
  }
  int array[5]={0,0,0,0,0};
  for(int k=0; k<z; k++)
  {
    array[dq[k]-65]++;
  }
  for(int phi=0;phi<5;phi++)
    cout << array[phi] << ' ';
  cout << endl;
  return 0;
}
