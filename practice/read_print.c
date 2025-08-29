#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number;
  printf("Enter number: ");
  fflush(stdout);

  if (scanf("%d", &number) == 1) {
    printf("Entered: %d\n", number);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
