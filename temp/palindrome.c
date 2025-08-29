#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void isPalindrome(char const *inputString) {
  int strLength = strlen(inputString) - 1;
  for (int i = 0; i < strLength / 2; ++i) {
    if (inputString[i] != inputString[strLength - i - 1]) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main(void) {
  char inputString[BUFFER_SIZE];
  if (fgets(inputString, sizeof(inputString), stdin) != NULL) {
    isPalindrome(inputString);
  }
}
