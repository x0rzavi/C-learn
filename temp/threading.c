#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int run(void *arg) {
  int *a = arg;
  printf("THREAD: Running thread with arg %d\n", *a);
  return 1229;
}

int main(void) {
  thrd_t t;
  int arg = 1230;

  printf("Launching a thread\n");
  thrd_create(&t, run, &arg);

  printf("Doing other things while thread runs\n");
  printf("Waiting for thread to finish\n");

  int res;
  thrd_join(t, &res);
  printf("Thread finished with result %d\n", res);

  return EXIT_SUCCESS;
}
