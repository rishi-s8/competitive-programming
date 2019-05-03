#include <iostream>
using namespace std;

int main()
{
  int sum;
  cin >> sum;
  int sum1=0;
  int n;
  cin >> n;
  int fi=sum-1;
  int ar[sum];
  for(int i=0;i<sum; i++)
    ar[i]=1;
  for(int j=1, k; j<n; j++)
  {

    k=fi-1;
    ar[k]++;
    for(int p=k+1; p<sum; p++)
      ar[p]=1;

    for(int l=0;l<=sum;l++)
    {
      sum1+=ar[l];
      if(sum1==sum)
      {
        sum1=0;
        fi=l;
        break;
      }

    }
  }
  for(int m=0; m<=fi; m++)
  cout << ar[m] << " " ;
  cout << endl;
  return 0;
}
