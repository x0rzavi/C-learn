#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long factorial(int n) {
  long long result = 1;

  if (n < 0) {
    return -1;
  }

  if (n == 0) {
    return 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (result > LLONG_MAX / i) {
      return -2;
    }
    result *= i;
  }

  return result;
}

int main(void) {
  int number;
  long long factorial_result;

  printf("Enter number: ");
  fflush(stdout);

  if (scanf("%d", &number) == 1) {
    factorial_result = factorial(number);

    printf("Factorial is: %lld", factorial_result);
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}
