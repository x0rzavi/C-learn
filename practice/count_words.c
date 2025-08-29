#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int countWords(char inputStr[static 1]) {
  int count = 0;
  for (size_t i = 0; inputStr[i] != '\0'; ++i) {
    if (inputStr[i] == ' ') {
      ++count;
    }
  }
  count++;
  return count;
}

int main(void) {
  printf("Enter a string: ");
  fflush(stdout);
  char inputStr[BUFFER_SIZE];
  if (fgets(inputStr, BUFFER_SIZE, stdin) != NULL) {
    inputStr[strcspn(inputStr, "\n")] = '\0';
    printf("%d\n", countWords(inputStr));
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
