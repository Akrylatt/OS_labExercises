#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// Comment: We can see from the top table that the process is not much memory and CPU demanding. We hav

/*
PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND       
      1 runner    20   0 1682716  25636  13936 S   0.0  0.1   0:02.01 .pid1-wrapped 
     14 runner    20   0  762956  42904  32736 S   0.0  0.2   0:01.20 querydb       
    266 runner    20   0   30896  22488   1924 S   0.0  0.1   0:00.01 main          
    267 runner    20   0   30896  21820   1288 S   0.0  0.1   0:00.02 main          
    375 runner    20   0    4648    780    708 S   0.0  0.0   0:00.00 sh            
    376 runner    20   0    4648    788    716 S   0.0  0.0   0:00.00 sh            
    377 runner    20   0   41668   3668   3216 S   0.0  0.0   0:00.00 top           
    378 runner    20   0   41668   3596   3144 R   0.0  0.0   0:00.01 top 
*/

int main(void) {

  pid_t x = fork();
  char *ptr;
  int size = 10*1024*1024;


  for (int i = 0; i < 10; i++){
    ptr = calloc(size, 1);
    sleep(1);
    printf("Iteration # %d\n", i);

    memset(ptr, 0, size);

    system("top -d 1");

  }

}