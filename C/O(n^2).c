// #include <sys/resource.h>
// #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <math.h>
// #include <sys/time.h>
#include <stdio.h>
#include <time.h>

#define SZ1 10000


float *x, *y;

int main()
{
    // Calculate the time taken by fun()
    FILE* fp;
    clock_t t;
    double time_taken;
    float min;
    int ans1, ans2;

    //Open File
    fp=fopen("Downloads/data/data_2D_points/data2d_10k.txt", "r");
    x = malloc(SZ1*sizeof(float));
    y = malloc(SZ1*sizeof(float));
    //Read Data
    if(fp!=NULL)
      for(int i=0; i<SZ1; ++i)
        fscanf(fp, "%f%f",x+i, y+i);
    //Start Time
    t = clock();
    //Calculate pair
    min=pow(x[0]-x[1],2)+pow(y[0]*y[1],2);
    ans1=0, ans2=1;
    for(int i=0; i<SZ1; ++i)
    {
      for(int j=i+1; j<SZ1; ++j)
      {
          if(min>pow(x[i]-x[j],2)+pow(y[i]-y[j],2))
          {
            min=pow(x[i]-x[j],2)+pow(y[i]-y[j],2);
            ans1=i;
            ans2=j;
          }
      }
    }
    //Output Answer
    printf("Closest Pair: (%f,%f), (%f,%f)\n", x[ans1],y[ans1],x[ans2],y[ans2]);
    //Stop Time
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("program took %f seconds to execute \n", time_taken);

    //Free memory
    free(x);
    free(y);
    return 0;
}
