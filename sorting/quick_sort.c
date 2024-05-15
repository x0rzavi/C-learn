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
  int *pivot = &arr[lower_index];
  int i = lower_index, j = upper_index;

  while (i < j) { // stop if i & j are on same index
    while (arr[i] <= *pivot) {
      i++;
    }
    while (arr[j] > *pivot) {
      j--;
    }
    if (i < j) {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(pivot, &arr[j]);
  return j; // pivot index
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
