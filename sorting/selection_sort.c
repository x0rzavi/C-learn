// TODO: Refactor
#include <stdbool.h>
#include <stdio.h>

void selection_sort(int arr[], int length);

int main(void) {
  int arr[6] = {11, 25, 12, 22, 25, 64};
  selection_sort(arr, 6);
  for (int i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selection_sort(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    int min_index = i;
    for (int j = i + 1; j < length; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    int temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
  }
}
