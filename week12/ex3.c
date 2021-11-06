#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <linux/input-event-codes.h>

#define N 10


static const char *const evval[3] = {
  "RELEASED", "PRESSED", "REPEATED"
};

static int queue[N];

void append(int val){
    for(int i = 1; i < N; i++){
        queue[i - 1] = queue[i];
    }
    queue[N] = val;
}

int main(void) {

  const char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;

  int fd = open(dev, O_RDONLY);

  if(fd == -1){
    fprintf(stderr, "Failed to open %s\n", dev);
    return -1;
  }

  while(1){
      read(fd, &ev, sizeof ev);

    if(ev.type == EV_KEY && ev.value == 1){
        append(ev.code);

			if (queue[N-1] == KEY_E && queue[N-2] == KEY_P) {
				printf("I passed the Exam!\n");
			}
			if (queue[N-1] == KEY_P && queue[N-2] == KEY_A && queue[N-3] == KEY_C) {
				printf("Get some cappuccino!\n");
			}
			else if(queue[N-1] == KEY_C && queue[N-2] == KEY_C && queue[N-3] == KEY_S && queue[N-4] == KEY_G){
            printf("Get some Cheese cake!\n");
        }
		}
  }

  fflush(stdout);
  fprintf(stderr, "%s \n", strerror(errno));
  return -1;

}