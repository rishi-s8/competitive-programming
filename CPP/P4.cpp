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
/* ..... RESET ..... */
int digit_sorted(deque<int> &d)
{
  int s=1;
  for(int i=1;i<7;i++)
  {
    if(d[i]<d[i-1])
      return s;
    s++;
  }
  return s;
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
  return ar[0];
}


int sort(deque<int> &d, int MAX_DEPTH=10)
{
  int count=0;
  deque<int> back=d;
  if(!MAX_DEPTH)
    return -1;
  int s=digit_sorted(d);
  cout << "DIGIT0:" << s << endl;
  int ds=s;
  if(ds==7)
    return count;
  deque<int> fi = d;
  do{
    d=fi;
    s=ds;
    //cout << "ENTERED FIRST LOOP" << endl;
    method1(fi);
    ds=digit_sorted(fi);
    if(ds>s)
      count++;
    if(ds==7)
    {
      return count;
    }
  }while(ds>s);
  fi=d;
  ds=s;
  do{
    d=fi;
    s=ds;
    method2(fi);
    ds=digit_sorted(fi);
    if(ds>s)
      count++;
    if(ds==7)
    {
      return count;
    }
  }while(ds>s);

  fi=d;
  ds=s;

  do{
    d=fi;
    s=ds;
    method3(fi);
    ds=digit_sorted(fi);
    if(ds>s)
      count++;
    if(ds==7)
    {
      return count;
    }
  }while(ds>s);
  fi=d;
  ds=s;
  do{
    d=fi;
    s=ds;
    method4(fi);
    ds=digit_sorted(fi);
    if(ds>s)
      count++;

    if(ds==7)
    {
      return count;
    }
  }while(ds>s);
  fi=d;
  --MAX_DEPTH;
  if(back==fi)
  {
    cout << "SAME after all methods in this recursion." << endl;
    int ar[4];
    method1(fi);
    ar[0]=sort(fi, MAX_DEPTH-1);
    fi=d;
    method2(fi);
    ar[1]=sort(fi, MAX_DEPTH-1);
    fi=d;
    method3(fi);
    ar[2]=sort(fi, MAX_DEPTH-1);
    fi=d;
    method4(fi);
    ar[3]=sort(fi, MAX_DEPTH-1);
    return min(ar);

  }
  return count + sort(fi, MAX_DEPTH);
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
  int s = sort(dq);
  //for(int i=0; i<7; i++)
    cout << s;
  cout << endl;


  return 0;
}
