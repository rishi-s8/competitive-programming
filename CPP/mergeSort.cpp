#include <iostream>
using namespace std;



void merge_ar(int *s1, int n1, int *s2, int n2, int* sorted)
{
  //int sorted[n1+n2];
  int *s=sorted;
  bool term_n1=false, term_n2=false;
  int i=0, j=0;
  printf("Merging: \n");

  while(i<n1 && j<n2)
  {
    printf("Comparing: %d, %d\n", *(s1+i), *(s2+j));
    if(*(s1+i)>*(s2+j))
    {
      *s  = *(s2+j);
      s++;
      j++;
    }
    else
    {
      *s = *(s1+i);
      s++;
      i++;
    }
  }
  while(i<n1)
  {
    *s= *(s1+i);
    i++;
    s++;
  }
  while(j<n2)
  {
    *s= *(s2+j);
    j++;
    s++;
  }
  for(int i=0; i<n1+n2; i++)
    printf("%d ", sorted[i]);
  printf("\n");
}
void sort_ar(int* ar, int left, int right, int* sorted)
{
  if(left<right)
  {
    int middle = (left + right)/2;
    //int *s1 = ar;
    int* sorted1 = new int(middle-left + 1);
    int* sorted2 = new int(right-middle + 1);
  //  int* sorted2 = new int(right-middle + 1);
    sort_ar(ar, left, middle, sorted1);
    //int *s2 = ar + middle + 1;
    sort_ar(ar, middle+1, right-middle, sorted2);
    merge_ar(sorted1,  middle + 1, sorted2, right-middle+1, sorted);
  }
}
int main()
{
  int ar[3]={3,2,1};
  int* sorted = new int(3);
  sort_ar(ar, 0, 2, sorted);
  for(int i=0; i<3; i++)
    cout << sorted[i] << endl;
  return 0;
}
