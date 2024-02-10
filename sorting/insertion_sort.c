// TODO: Refactor
#include <stdbool.h>
#include <stdio.h>

void insertion_sort(int arr[], int length);

int main(void) {
  int arr[9] = {3, 7, 4, 5, 1, 9, 2, 6, 1};
  insertion_sort(arr, 9);
  for (int i = 0; i < 9; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertion_sort(int arr[], int length) {
  for (int i = 1; i < length; i++) {
    int shift = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > shift) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = shift;
  }
}
