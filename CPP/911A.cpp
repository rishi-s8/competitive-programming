#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; ++i)
    cin >> v[i];
  int minimum=*min_element(v.begin(),v.end());
  vector<int> indices;
  for(int i=0; i<n; ++i)
    if(v[i]==minimum)
      indices.push_back(i);
  int minDifference = 1000000;
  for(int i=0; i<indices.size()-1; ++i)
  {
    int diff = indices[i+1]-indices[i];
    minDifference=min(minDifference,diff);
  }
  cout << minDifference << endl;
}
