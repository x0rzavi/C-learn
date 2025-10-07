#include <stdio.h>

int main(void) {
  printf("Enter number of rows: ");
  int rows, coeff = 1;
  scanf("%d", &rows);

  for (int i = 0; i < rows; ++i) {
    for (int space = 0; space < rows - i - 1; ++space) {
      printf(" ");
    }

    for (int j = 0; j <= i; ++j) {
      if (j == 0 | i == 0) {
        coeff = 1;
      } else {
        coeff = coeff * (i - j + 1) / j;
      }

      printf(" %d", coeff);
    }
    printf("\n");
  }
}
