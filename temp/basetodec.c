#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>

int baseToDec(char *value, int base) {
  int power = 0;
  int decValue = 0;
  size_t valueLen = strlen(value);
  for (int i = valueLen - 1; i >= 0; --i) {
    if (value[i] >= 'A' && value[i] <= 'F') {
      decValue += ((value[i] - 'A' + 10) * pow(base, power++));
    } else {
      decValue += ((value[i] - '0') * pow(base, power++));
    }
  }
  return decValue;
}

int main(void) {
  printf("Decimal value: %d\n", baseToDec("AF", 8));
  return EXIT_SUCCESS;
}
