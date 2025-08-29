#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

char stack[STACK_SIZE];
int tos = -1;

void push(char data) { stack[++tos] = data; }
void pop() { printf("%c", stack[tos--]); }

void decToBase(int decimalNum, int base) {
  if (!decimalNum) {
    printf("0");
  }

  while (decimalNum) {
    int remainder = decimalNum % base;
    if (remainder < 10) {
      push(remainder + '0');
    } else {
      push(remainder - 10 + 'A');
    }
    decimalNum /= base;
  }

  while (tos != -1) {
    pop();
  }
  printf("\n");
}

int main(void) {
  printf("Enter decimal number and base: ");
  fflush(stdout);
  int decimalNum, base;
  fscanf(stdin, "%d %d", &decimalNum, &base);
  decToBase(decimalNum, base);

  printf("Octal: %o\n", decimalNum);
  printf("Hexadecimal: %x\n", decimalNum);

  char *hexStr = "A5F_is_the_value";
  char *endptr = NULL;
  printf("%ld\n", strtol(hexStr, &endptr, base));
  printf("%s\n", endptr);

  return EXIT_SUCCESS;
}
