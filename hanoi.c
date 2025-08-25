#include <stdio.h>

void toh(int, char, char, char);

int main() {
  int n;
  printf("Enter no of discs: ");
  scanf("%d", &n);

  toh(n, 'A', 'B', 'C');
  return 0;
}

void toh(int n, char src, char aux, char dest) {
  if (n == 1) {
    printf("%c -> %c\n", src, dest);
  } else {
    toh(n - 1, src, dest, aux);
    toh(1, src, aux, dest);
    toh(n - 1, aux, src, dest);
  }
}
