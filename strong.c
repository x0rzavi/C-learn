#include <stdio.h>

int fact(int n);

int main() {
  int n, digit, sum = 0;
  printf("Enter n: ");
  scanf("%d", &n);
  int copy = n;

  while (n != 0) {
    digit = n % 10;
    sum = sum + fact(digit);
    n = n / 10;
  }

  if (sum == copy) {
    printf("Strong");
  } else {
    printf("Not strong");
  }

  return 0;
}

int fact(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}
