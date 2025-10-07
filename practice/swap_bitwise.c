#include <stdio.h>

int main(void) {
  int a = 10, b = 20;

  a ^= b;
  b ^= a;
  a ^= b;

  printf("%d %d", a, b);
}
