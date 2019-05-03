#include <iostream>
using namespace std;

int main()
{
  int n=5;
  int ar[n];
  for(int a=0; a<n; a++)
    cin >> ar[a];
  int min=0, temp;
  for(int b=0; b<n; b++, min=b)
  {
    for(int f=0; f<b; f++)
    {
      if(ar[b]<ar[f])
      {
        temp=ar[b];
        for(int k=b; k>f; k--)
        {
          ar[k]=ar[k-1];
        }
        ar[f]=temp;
      }
    }
    for(int p=0; p<n; p++)
      cout << ar[p]<< " ";
    cout << endl;
  }
  cout << "The Elements of the sorted array are:\n";
  for(int p=0; p<n; p++)
    cout << ar[p]<< " ";
  cout << endl;
  return 0;
}
