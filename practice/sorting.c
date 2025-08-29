#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main(void) {
  int arr[] = {34, 29, 30, 98, 67};
  int length = sizeof(arr) / sizeof(arr[0]);
  int origLength = length;

  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 1; i < length; ++i) {
      if (arr[i] > arr[i - 1]) {
        swapped = true;
        swap(&arr[i], &arr[i - 1]);
      }
    }
    --length;
  }

  for (int i = 0; i < origLength; ++i) {
    printf("%d ", arr[i]);
  }
}
