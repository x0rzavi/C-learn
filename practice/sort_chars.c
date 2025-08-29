#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void sortChars(char str[static 1]) {
  qsort(str, strlen(str), sizeof(char),
        (int (*)(const void *a, const void *b))strcmp);
  printf("%s\n", str);
}

int main(void) {
  printf("Enter a string: ");
  fflush(stdout);
  char inputStr[BUFFER_SIZE];
  if (fgets(inputStr, BUFFER_SIZE, stdin) != NULL) {
    inputStr[strcspn(inputStr, "\n")] = '\0';
    sortChars(inputStr);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
