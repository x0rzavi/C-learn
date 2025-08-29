#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
  char inputString[BUFFER_SIZE];

  printf("Enter string: ");
  fflush(stdout);
  if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
    inputString[strcspn(inputString, "\n")] = '\0';
    printf("Entered: %s\n", inputString);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
