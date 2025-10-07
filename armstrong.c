#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

bool isArmstrong(char str[static 1]) {
  int sum = 0;
  int length = strlen(str);
  long int num = strtol(str, NULL, 10);
  long int numCpy = num;
  while (num) {
    int digit = num % 10;
    sum += (pow(digit, length));
    num /= 10;
  }
  return sum == numCpy;
}

int main(void) {
  printf("Enter number: ");
  fflush(stdout);
  char num[256];
  if (fscanf(stdin, "%s", num) != 0) {
    printf("%d\n", isArmstrong(num));
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
