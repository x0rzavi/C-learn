#include <stdio.h>

int main() {
  int num, digit, sum = 0;
  printf("Enter num: ");
  scanf("%d", &num);
  int copy = nnum;

  while (nnum != 0) {
    digit = nnum % 10;
    sum = sum + (digit * digit * digit);
    nnum = nnum / 10;
  }

  if (copy == sum) {
    printf("Armstrong");
  } else {
    printf("Not Armstrong");
  }

  return 0;
}
