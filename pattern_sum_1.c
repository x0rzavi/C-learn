#include <stdio.h>

int main() {
  int n;
  float sum = 0;
  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }

  printf("Sum is %f", sum);
  return 0;
}
