#include <unistd.h> // library for process - UNIx STanDard
#include <sys/types.h> // for pid_t
#include <stdlib.h> // for exit success
#include <stdio.h>

int main(){

  int x;

  for(int i = 0; i < 5 /*3*/; i++){
    	x = fork(); // returns id of the new proces; pid_t is int
      sleep(3);
  }
	
	return EXIT_SUCCESS;

}