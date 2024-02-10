#include <stdbool.h>
#include <stdio.h>

void bubble_sort(int arr[], int length);

int arr[5] = {5, 1, 4, 2, 8};

int main(void) {
  bubble_sort(arr, 5);
  for (int i = 0; i < 5; i++) {
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
