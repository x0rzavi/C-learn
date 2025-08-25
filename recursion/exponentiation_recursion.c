#include <stdio.h>

int powRec(int a, int b);

int main() {
  int a, b;
  printf("Enter a, b: ");
  scanf("%d%d", &a, &b);

  printf("a ^ b: %d", powRec(a, b));
  return 0;
}

int powRec(int a, int b) {
  if (b == 0) {
    return 1;
  } else {
    return a * powRec(a, b - 1);
  }
}
