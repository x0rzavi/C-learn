#include <stdio.h>

void insertion_sort(int arr[], int length);
void print_arr(int arr[], int length);

int main(void) {
  int arr[] = {5, 2, 4, 6, 4, 1, 3};
  int length = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, length);
  insertion_sort(arr, length);
  print_arr(arr, length);
}

void insertion_sort(int arr[], int length) {
  for (int i = 1; i < length; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void print_arr(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
