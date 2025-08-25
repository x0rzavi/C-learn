#include <stdio.h>

float convFahtCel(float fah);

int main() {
  float fah;
  printf("Enter fahreheit: ");
  scanf("%f", &fah);
  printf("Celcius: %f", convFahtCel(fah));
  return 0;
}

float convFahtCel(float fah) { return 5.0 / 9 * (fah - 32); }
