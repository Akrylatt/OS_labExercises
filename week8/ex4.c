#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

// Comment: We can see that using the free(ptr) command the memory usage is constant whereas if we do not use it the memory usage is increasing

int main(void) {

  pid_t x = fork();
  char *ptr;
  int size = 10*1024*1024;


  for (int i = 0; i < 10; i++){
    ptr = calloc(size, 1);
    int a = RUSAGE_SELF;
    struct rusage u;
    int r = getrusage(a, &u);
    printf("Memory usage: %ld\n", u.ru_maxrss);
    sleep(1);
    free(ptr);

  }

}