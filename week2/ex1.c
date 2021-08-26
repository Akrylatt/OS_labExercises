#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {

  int i = INT_MAX;
  float f = FLT_MAX_EXP;
  double d = DBL_MAX;

  printf("Max value of int: %d \n", i);
  printf("Size of int: %lu \n", sizeof(i));

  printf("Max value of float exponent is: %f \n", f);
  printf("Size of float: %lu \n", sizeof(f));

  printf("Max value of double: %lf \n", d);
  printf("Size of float: %lu", sizeof(d));

  return 0;
}