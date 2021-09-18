#include <stdio.h>
#include <pthread.h>

#define N 100

char s[N];

int consumerSleeps, producerSleeps;
int position;

void* Produce(void* args){

  while(1){
    if(producerSleeps){
      continue;
    }
    if(position == N){
      // wake up consumerSleeps
      consumerSleeps = 0;
      // sleep producer
      producerSleeps = 1;
    }
    // Produce
    s[position] = 3;
    position++;
  }

  return NULL;
}

void* Consume(void* args){

  while(1){
    if(consumerSleeps){
      continue;
    }
    if(position == 0){
      // wake up consumerSleeps
      consumerSleeps = 1;
      // sleep producer
      producerSleeps = 0;
    }
    // Produce
    s[position] = '\0';
    position--;
  }

  return NULL;
}


int main(void) {

  consumerSleeps = 1;

  pthread_t tProducer, tConsumer;

  pthread_create(&tProducer, NULL, &Produce, NULL);

  pthread_create(&tProducer, NULL, &Consume, NULL);
  return 0;
}