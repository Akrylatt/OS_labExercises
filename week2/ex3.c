#include <stdio.h>

int main(void) {

  int hight;

  scanf(("%d"), &hight);

  for( int i = 0; i <= hight; i++){
    for(int k = 0; k <= (((2*hight) - 1) - ((2 * i) - 1))/ 2; k++){
      printf(" ");
    }
    for(int j = 0; j < (2 * i) - 1; j++){
      printf("*");
    }
    printf("\n");
  }
 
  return 0;
}