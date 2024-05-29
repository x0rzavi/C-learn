// Quick Sort
// Divide and Conquer
// CLRS
#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int lower_index, int upper_index);
void quicksort(int arr[], int lower_index, int upper_index);
void print_arr(int arr[], int len);

int main(void) {
  int arr[] = {3, 5, 2, 3, 1, 4};
  int len = sizeof(arr) / sizeof(arr[0]);
  int upper_index = len - 1;
  printf("Unsorted array: ");
  print_arr(arr, len);
  quicksort(arr, 0, upper_index);
  printf("Sorted array: ");
  print_arr(arr, len);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int lower_index, int upper_index) {
  int *pivot = &arr[upper_index];
  int i = lower_index - 1;
  for (int j = lower_index; j < upper_index; j++) {
    if (arr[j] <= *pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], pivot);
  return i + 1; // pivot index
}

void quicksort(int arr[], int lower_index, int upper_index) {
  if (lower_index < upper_index) { // only run if there are more than 1 element
    int pivot_index = partition(arr, lower_index, upper_index);
    quicksort(arr, 0, pivot_index - 1);
    quicksort(arr, pivot_index + 1, upper_index);
  }
}

void print_arr(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
