// TODO: Refactor
#include <stdbool.h>
#include <stdio.h>

void bubble_sort(int arr[], int length);

int main(void) {
  int arr[6] = {5, 1, 4, 1, 2, 8};
  bubble_sort(arr, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubble_sort(int arr[], int length) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 1; i < length; i++) {
      if (arr[i - 1] > arr[i]) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        swapped = true;
      }
    }
    length--;
  }
}
