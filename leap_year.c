#include <stdio.h>

void checkLeap(int n);

int main() {
  int num;
  printf("Enter year: ");
  scanf("%d", &num);
  checkLeap(num);

  return 0;
}

void checkLeap(int n) {
  if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) {
    printf("Leap year\n");
  } else {
    printf("Not leap year\n");
  }
}
