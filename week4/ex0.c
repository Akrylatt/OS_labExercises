#include <unistd.h> // library for process - UNIx STanDard
#include <sys/types.h> // for pid_t
#include <stdlib.h> // for exit success
#include <stdio.h>

int main(){
	printf("Before Fork\n");
	pid_t x = fork(); // returns id of the new proces; pid_t is int
	// pid == 0 means child process, pid > 0 means parent process
	printf("After Fork\n");
	printf("pid = %d", x);

	return EXIT_SUCCESS

}