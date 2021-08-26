#include <stdio.h>

void swap(int* a, int* b){
  int h = *a;
  *a = *b;
  *b = h;
}

int main(void) {
  int a;
  int b;

   scanf(("%d %d"), &a, &b);

   swap(&a, &b);
   printf("%d %d", a, b);

  return 0;
}