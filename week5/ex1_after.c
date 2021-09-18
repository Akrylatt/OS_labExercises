#include <stdio.h>
#include <pthread.h>


typedef struct{
  char * text;
  pthread_t thread_id;
  int thread_num;

 } thread_info;

void* job(void* args){
  thread_info* t = (thread_info*)args;
  t->text = "Hello";
  pthread_t id = pthread_self();
  printf("%s from the thread %lu \n", t->text, id);
}

int main(void) {

  pthread_t thread_id;
  int t; // some param; if you need more param use struct
  thread_info th_info;

  pthread_t x = pthread_self();

  pthread_create(&thread_id, NULL, &job, &th_info);
  printf("Thread #1 created \n");

  pthread_create(&thread_id, NULL, &job, &th_info);
  printf("Thread #2 created \n");

  pthread_create(&thread_id, NULL, &job, &th_info);
  printf("Thread #3 created \n");


  pthread_join(thread_id, NULL); // The paren did not wait for the child thread; therfroe, we must join, so that they wait
  
}

// gcc -pthread ex1.c