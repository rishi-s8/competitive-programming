#include <bits/stdc++.h>
using namespace std;

set<int> inverted;
void merge(int ar[], int start, int mid, int end)
{
    int p=start, q=mid+1;
    int k=0;
    int temp[end-start+1];
    while(k<=end-start)
    {
        if(p>mid)
            temp[k++]=ar[q++];
        else if(q>end)
            temp[k++]=ar[p++];
        else if(ar[q]<ar[p])
        {
            inverted.insert(ar[q]);
            temp[k++]=ar[q++];
        }
        else
        {
            temp[k++]=ar[p++];
        }
    }
    for(int i=start; i<=end; ++i)
    {
        ar[i]=temp[i-start];
    }
}
void mergeSort(int ar[], int start, int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        mergeSort(ar, start, mid);
        mergeSort(ar, mid+1, end);
        merge(ar, start, mid, end);
    }
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    // c=0;
    inverted.erase(inverted.begin(),inverted.end());
    int n; cin >> n;
    vector<int> j(n),l(n);
    for(int i=0; i<n; ++i)
      cin >> j[i];
    for(int i=0; i<n; ++i)
      cin >> l[i];
    bool arjun=true;
    for(int i=0; i<n; ++i)
    {
      if(j[i]==-1)
      {
        j.erase(j.begin()+i);
        l.erase(l.begin()+i);
        n--;
        i--;
      }
    }
    if(n==0 || n==1)
      arjun=true;
    else
    {
      int ar[n];
      for(int i=0; i<n; ++i)
        ar[i]=l[i];
      mergeSort(ar, 0, n-1);
    }
    if(inverted.size()>1) arjun = false;
    if(arjun)
      cout << "#laughing_arjun\n";
    else
      cout << "#itsnot_arjun\n";

  }
}
