#include <iostream>
using namespace std;

int main()
{
    const int n1=5,n2=6, n3=n1+n2;
    int i, j, k;
    int a[n1]={1, 3, 4, 5, 10}, b[n2]={10, 9, 6, 3, 2, 0}, c[n3];
    for(i=0, j=0, k=n2-1; j<n1 && k>=0; i++)
    {

      if(a[j]<b[k])
      {
        c[i]=a[j];
        j++;
      }
      else
      {
        c[i]=b[k];
        k--;
      }
    }
    if(j<n1&&k<0)
    {
      for(i;i<n3&&j<n1;i++,j++)
      {
        c[i]=a[j];
      }
    }
    else if(j>=n1&&k>=0)
    {
      for(i;i<n3&&k>=0;i++,k--)
      {
        c[i]=b[k];
      }
    }

    cout << "Printing Array: ";
    for(i=0; i<n3; i++)
    {
      cout << c[i] << " ";
    }
    cout << endl;
    return 0;

}
