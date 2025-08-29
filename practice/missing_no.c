#include <stdio.h>
#include <stdlib.h>

int find_missing_number(int *nums, int n) {
  int sum_of_n = (n * (n + 1)) / 2;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
  }
  return sum_of_n - sum;
}

int main(void) {
  int nums[] = {3, 0, 2, 4, 5};
  int n = sizeof(nums) / sizeof(nums[0]);
  printf("Missing number is: %d\n", find_missing_number(nums, n));
  return EXIT_SUCCESS;
}
