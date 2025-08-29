#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void sortSentence(char inputStr[static 1]) {
  char *word;
  word = strtok(inputStr, " ");
  while (word) {
    qsort(word, strlen(word), sizeof(char),
          (int (*)(const void *a, const void *b))strcmp);
    printf("%s ", word);
    word = strtok(NULL, " ");
  }
}

int main(void) {
  printf("Enter sentence: ");
  fflush(stdout);
  char inputStr[BUFFER_SIZE];
  if (fgets(inputStr, BUFFER_SIZE, stdin) != NULL) {
    inputStr[strcspn(inputStr, "\n")] = '\0';
    sortSentence(inputStr);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
