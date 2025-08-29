// wrong code
#include <stdio.h>

int main() {
  int num, digit, sum = 0;
  printf("Enter num: ");
  scanf("%d", &num);
  int copy = num;

  while (num != 0) {
    digit = num % 10;
    sum = sum + (digit * digit * digit);
    num = num / 10;
  }

  if (copy == sum) {
    printf("Armstrong");
  } else {
    printf("Not Armstrong");
  }

  return 0;
}
