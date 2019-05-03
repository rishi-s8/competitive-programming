#include <iostream>
using namespace std;

int main()
{
  const int n1=7;
  int ar[n1]={-32768,13,1,5,3,0,6};
  for(int i=1, temp, j; i<n1; i++)
  {
    temp=ar[i];
    j=i-1;
    while(temp<ar[j])
    {
      ar[j+1]=ar[j];
      j--;
    }
    ar[j+1]=temp;
  }

  cout << "Printing Array: ";
  for(int i=1; i<n1; i++)
  {
    cout << ar[i] << " ";
  }
  cout << endl;
  return 0;

}
