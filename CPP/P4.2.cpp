#include <iostream>
#include <deque>
#include <iterator>
using namespace std;

/* ..... METHODS ..... */
void method1(deque<int> &a)
{
  const int temp = a[0];
  a.pop_front();
  deque<int>::iterator iter = a.begin()+3;
  a.insert(iter,temp);
}

void method2(deque<int> &a)
{
  deque<int>::iterator iter = a.end()-1;
  const int temp = *iter;
  a.pop_back();
  iter-=3;
  a.insert(iter,temp);
}

void method3(deque<int> &a)
{
  deque<int>::iterator iter = a.begin()+3;
  const int temp = *iter;
  a.erase(iter);
  a.push_front(temp);
}

void method4(deque<int> &a)
{
  deque<int>::iterator iter = a.begin()+3;
  const int temp = *iter;
  a.erase(iter);
  a.push_back(temp);
}


bool is_sorted(deque<int> &dq)
{
  for(int i=0; i<6; i++)
    if(dq[i+1]<dq[i])
      return false;
  return true;
}

int min(int ar[])
{
  int temp;
  for(int i=0; i<4; i++)
    for(int j=1; j<4; j++)
      if(ar[j]<ar[j-1])
      {
        temp=ar[j];
        ar[j]=ar[j-1];
        ar[j-1]=temp;
      }
  for(int j=0; j<4; j++)
    if(ar[j]>=0)
      return ar[j];
  return ar[0];
}

int sort(deque<int> &d, int method_i=1, int depth=0, int MAX_DEPTH=50, int self_depth=0)
{
  deque<int> fi = d;
  cout << "DEPTH: " << depth << endl;
  if(depth>=MAX_DEPTH)
    return -1;
  cout << "Applying Method: " << method_i << endl;
  switch(method_i)
  {
    case 1:
      method1(fi);
    case 2:
      method2(fi);
      break;
    case 3:
      method3(fi);
      break;
    case 4:
      method4(fi);
      break;
  }
  if (is_sorted(fi))
  {
    /*for(int i=0; i<7; i++)
      cout << fi[i] << " ";*/
    return depth;
  }
  self_depth++;
  if(self_depth>3)
  {
    method_i=(method_i=1)%5;
    if(method_i==0) method_i++;
    self_depth=0;
  }

  return sort(fi, method_i, depth+1, MAX_DEPTH-1, self_depth);

}


int main()
{
  deque<int> dq;
  /*for(int i=0,j=7, k; i<7; i++,j--)
  {
    //cin >> k;
    k=j;
    dq.push_back(k);
  }*/
  dq.push_back(6);
  dq.push_back(4);
  dq.push_back(1);
  dq.push_back(7);
  dq.push_back(3);
  dq.push_back(5);
  dq.push_back(2);
  deque<int> backup = dq;
  int ar[4];
  for(int i=0; i<4; i++)
    ar[i]=sort(dq, i+1);
  int s=min(ar);
  //for(int i=0; i<7; i++)
    cout << s;
  cout << endl;


  return 0;
}
