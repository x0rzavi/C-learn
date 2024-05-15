#include <stdio.h>

int max(int arr[], int len) {
  if (len == 0) {
    return arr[len];
  } else {
    int max_rest = max(arr, len - 1);
    return arr[len] > max_rest ? arr[len] : max_rest;
  }
}

int main(void) {
  int arr[] = {24, 20, 100, 34, 39, 24, 19};
  int len = sizeof(arr) / sizeof(arr[0]);
  printf("Max element is %d\n", max(arr, len - 1));
}
