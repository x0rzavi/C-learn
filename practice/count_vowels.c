#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countVowels(char const *str) {
  int count = 0;
  char ch;

  for (int i = 0; i < str[i] != '\0'; ++i) {
    ch = tolower(str[i]);
    switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      ++count;
      break;
    default:
      break;
    }
  }

  return count;
}

int main(void) {
  printf("Enter string: ");
  fflush(stdout);

  char inputString[256];

  if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
    inputString[strcspn(inputString, "\n")] = '\0';
    int vowels = countVowels(inputString);
    printf("Number: %d\n", vowels);
    return EXIT_SUCCESS;
  }
}
