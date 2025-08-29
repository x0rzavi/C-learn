#include <stdio.h>
#include <stdlib.h>

void swapNumbers(int *a, int *b) {
  printf("a: %d, b: %d\n", *a, *b);
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
  printf("a: %d, b: %d\n", *a, *b);
}

int main(void) {
  int num1 = 10;
  int num2 = 20;

  swapNumbers(&num1, &num2);
  return EXIT_SUCCESS;
}
