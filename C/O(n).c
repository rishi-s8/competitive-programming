// #include <sys/resource.h>
// #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <math.h>
// #include <sys/time.h>
#include <stdio.h>
#include <time.h>

#define SZ1 10000


float *x;

int main()
{
    // Calculate the time taken by fun()
    FILE* fp;
    clock_t t;
    double time_taken;
    float min;
    int ans1, ans2;

    //Open File
    fp=fopen("Downloads/data/data_array/data_10k.txt", "r");
    x = malloc(SZ1*sizeof(float));
    //Read Data
    if(fp!=NULL)
      for(int i=0; i<SZ1; ++i)
        fscanf(fp, "%f",x+i);
    //Start Time
    t = clock();
    //Calculate max
    int max = x[0];
    for(int i=1; i<SZ1; ++i)
    {
      if(max<x[i])  max=x[i];
      usleep(1); //Delay by 1us
    }

    //Stop Time
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("program took %f seconds to execute \n", time_taken);

    //Free memory
    free(x);
    free(y);
    return 0;
}
