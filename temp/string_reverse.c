#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void reverseString(char *str) {
  size_t length = strlen(str);
  size_t i, j;
  char temp;

  for (i = 0, j = length - 1; i < j; ++i, --j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main(void) {
  char inputString[BUFFER_SIZE];
  printf("Enter string: ");
  if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
    inputString[strcspn(inputString, "\n")] = '\0';
    reverseString(inputString);
    printf("Reversed string: %s\n", inputString);
    return EXIT_SUCCESS;
  }
}
