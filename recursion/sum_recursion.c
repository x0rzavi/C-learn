#include <stdio.h>

int sum(int arr[], int len) {
  if (len == 0) {
    return arr[len];
  } else {
    return arr[len] + sum(arr, len - 1);
  }
}

int main(void) {
  int arr[] = {2, 4, 6, 10, 0, 1};
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("Sum is %d\n", sum(arr, len - 1));
}
