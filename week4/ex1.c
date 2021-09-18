#include <unistd.h> // library for process - UNIx STanDard
#include <sys/types.h> // for pid_t
#include <stdlib.h> // for exit success
#include <stdio.h>

int main(){
	int i = 100;
	pid_t x = fork(); // returns id of the new proces; pid_t is int
	if(x == 0){
		printf("Hello from child %d \n", (x-i));
	}
	else if(x > 0){
		printf("Hello from parent %d \n", (x-i));
	}
	else{
		return EXIT_FAILLER;
	}



	return EXIT_SUCCESS;

}