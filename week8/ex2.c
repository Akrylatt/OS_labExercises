#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// Comment: We get mostly zeros, because the amount of the memory we are allocationg is still too small, so it can fit into the memory without using swap


int main(void) {

  pid_t x = fork();
  char *ptr;
  int size = 10*1024*1024;


  for (int i = 0; i < 10; i++){
    ptr = calloc(size, 1);
    sleep(1);
    printf("Iteration # %d\n", i);

    memset(ptr, 0, size);

    system("vmstat 1");

  }

}