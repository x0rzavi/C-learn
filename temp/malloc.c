#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  int numElements = 5;

  p = malloc(sizeof(*p) * numElements);

  if (p == NULL) {
    return EXIT_FAILURE;
  }

  puts("Init array\n");
  for (int i = 0; i < numElements; ++i) {
    p[i] = i * 10;
    printf("%d\n", p[i]);
  }

  free(p);
  p = NULL;
  return EXIT_SUCCESS;
}
