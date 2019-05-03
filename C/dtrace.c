#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define getFloat(x) scanf("%f", &x)
#define getInt(x) scanf("%d", &x)

////////// begin ADT ////////////

/* Define Vector type */
typedef float* Vector;
typedef float* Vec;
/* Define the functions */

Vector adt_createVector(int dim) {
    /* Function body */
    Vector p = (Vector) malloc(dim*sizeof(float));
    return p;
}

Vector adt_loadVector(Vector vec, int dim) {
    /* Function body */
    for(int i=0; i<dim; ++i)
      getFloat(vec[i]);
    return vec;
}

Vector adt_addVector(Vector vec1, Vector vec2, Vector vec3, int dim) {
    /* Function body */
    for(int i=0; i<dim; ++i)
      vec3[i]=vec1[i]+vec2[i];
    return vec3;
}

/* Include the other functions as well */

float adt_normVector(Vector vec2, int dim)
{
  float norm=0;
  for(int i=0; i<dim; ++i)
    norm+=vec2[i]*vec2[i];
  norm=sqrt(norm);
  return norm;
}

//Multiply a vector with a scalar
Vector adt_scaleVector(Vector vec3, Vector vec4, float scalar, int dim)
{
  for(int i=0; i<dim; ++i)
    vec4[i]=vec3[i]*scalar;
  return vec4;

}

//Check equalityh of two vecors
int adt_equalVectors(Vector vec1, Vector vec2, int dim)
{
  for(int i=0; i<dim; ++i)
    if(vec1[i]!=vec2[i]) return 0;
  return 1;
}

void print(Vector vec, int dim)
{
  for(int i=0; i<dim-1; ++i)
    printf("%.2f \t ",vec[i]);

  printf("%.2f \n", vec[dim-1]);
}




///////// end of ADT //////////


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /* The below code is an incomplete template for reference */
    /* Function names starting with adt_ are from the vector ADT */

    /* Get vector dimension from stdin */
    int dim;
    getInt(dim);
    float norm2;

    /* Create the empty vectors */
    Vec vec1 = adt_createVector(dim);
    Vec vec2 = adt_createVector(dim);
    Vec vec3 = adt_createVector(dim);
    Vec vec4 = adt_createVector(dim);

    /* Populate the vectors from stdin */
    adt_loadVector(vec1,dim);
    adt_loadVector(vec2,dim);

    /* perform operations */
    vec3 = adt_addVector(vec1,vec2,vec3,dim);
    norm2 = adt_normVector(vec2,dim);
    vec4 = adt_scaleVector(vec3,vec4,norm2,dim);

    /* Display the result */
    print(vec4, dim);



    return 0;
}
