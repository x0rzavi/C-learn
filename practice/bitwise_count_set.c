// Brian Kernighan's algorithm
#include <stdio.h>

int main(void) {
  printf("Enter an integer: ");
  int n;
  scanf("%d", &n);

  int count = 0;
  while (n) {
    n &= (n - 1);
    ++count;
  }

  printf("Number of set bits: %d\n", count);
}
