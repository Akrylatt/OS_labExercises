#include <stdio.h>

int main(int argc, char *argv[]) {

  int hight = 1;
  if(argc > 1){
    sscanf(argv[1], "%d", &hight);
  }
  

  // scanf(("%d"), &hight);

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