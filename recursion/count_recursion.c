#include <stdio.h>

int count(int arr[], int index) {
  if (arr[index] == -1) {
    return 0;
  } else {
    return 1 + count(arr, index + 1);
  }
}

int main(void) {
  int arr[] = {2, 4, 6, 10, 0, 20, -1};
  printf("Item count is %d\n", count(arr, 0));
}
