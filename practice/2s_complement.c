#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Enter binary: ");
  fflush(stdout);
  unsigned binary;
  if (fscanf(stdin, "%b", &binary) != 0) {
    printf("Original: %b\n", binary);
    binary = ~binary;
    binary += 1;
    printf("2's complement: %b\n", binary);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
