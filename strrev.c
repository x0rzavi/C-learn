#include <stdio.h>
#include <string.h>

int main() {
  char name[] = "Avishek Sen";
  int n = strlen(name) - 1;

  for (int i = 0; i < n / 2; i++) {
    int temp = name[n - i];
    name[n - i] = name[i];
    name[i] = temp;
  }

  // for (int i = 0; i < n; i++) {
  //         printf("%c ", name[i]);
  // }
  fputs(name, stdout);
  return 0;
}
