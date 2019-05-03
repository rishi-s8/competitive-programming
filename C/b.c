#include <stdio.h>

typedef struct
{
  int i;
  char ch;
} data;

int main()
{
    printf("Size of int = %ld\n", sizeof(int));
    printf("Size of char = %ld\n", sizeof(char));
    printf("Size of data = %ld\n", sizeof(data));
    return 0;
}
