#include <stdio.h>

int main() {
  int days, daysInput, months, years;
  printf("Enter days: ");
  scanf("%d", &daysInput);

  years = daysInput / 365;
  months = (daysInput % 365) / 30;
  days = (daysInput % 365) % 30;

  printf("Years: %d\n", years);
  printf("Months: %d\n", months);
  printf("Days: %d\n", days);

  return 0;
}
