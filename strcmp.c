#include <stdio.h>

int main() {
  char a[15], b[15], count = 0;
  printf("Enter 1st string: ");
  fgets(a, 15, stdin);
  printf("Enter 2nd string: ");
  fgets(b, 15, stdin);

  for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      count++;
      printf("Strings are not equal");
      break;
    }
  }

  if (count == 0) {
    printf("Strings are equal");
  }
  return 0;
}
