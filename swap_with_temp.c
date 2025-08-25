#include <stdio.h>

int main() {
  int a, b, temp;
  printf("Enter a & b: ");
  scanf("%d%d", &a, &b);

  temp = b;
  b = a;
  a = temp;

  printf("a & b is: %d %d", a, b);
  return 0;
}
