#include <math.h>
#include <stdio.h>

int main() {
  int n;
  printf("Enter binary: ");
  scanf("%d", &n);

  int power = 0, sum = 0, digit;
  while (n != 0) {
    digit = n % 10;
    sum = sum + (digit * pow(2, power));
    n = n / 10;
    power++;
  }

  printf("Decimal number: %d", sum);
  return 0;
}
