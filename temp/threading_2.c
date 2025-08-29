#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <time.h>

int run(void *arg) {
  (void)arg;
  printf("Thread running\n");
  return 0;
}

#define THREAD_COUNT 5

int main(void) {
  thrd_t t;
  for (int i = 0; i < THREAD_COUNT; ++i) {
    thrd_create(&t, run, NULL);
    thrd_detach(t);
  }

  thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
  return EXIT_SUCCESS;
}
