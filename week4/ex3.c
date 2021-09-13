#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  while(1){
    char command[50];

    scanf("%s", command);

    system(command);
  }
  return 0;
}