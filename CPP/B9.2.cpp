#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  char ar[4][4], backup[4][4];
  ifstream myfile;
  myfile.open("in.txt", ios::in);
  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
        myfile >> ar[i][j];
        backup[i][j]=ar[i][j];
    }
  }
  myfile.close();

  int n;
  cin >> n;
  char temp;
  while(n--)
  {
    for(int i=0; i<4; i++)
    {
      for(int j=0; j<4; j++)
      {
        temp=ar[i][j];
        if(!search_proximity(ar,i,j))
          continue;
        else if()
      }
    }
  }




  /*for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
      cout << ar[i][j];
    cout << endl;
  }*/
  return 0;
}
