#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(void) {
  
  while(1){
    char command[50];
    char *args[50];
    int size = 0;

    scanf("%s", command);

    char *token = strtok(command, " ");

    while(token!=NULL){
      args[size] = token;
      token = strtok(NULL, " ");
      size++;
    }

    args[size]= NULL;

    pid_t x = fork();

    if(x == 0){
      
      int r = execvp(args[0], args);

      if(r < 0){
        perror("failed");
        exit(255);
      }
    }
  }
  return 0;
}