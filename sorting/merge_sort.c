#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int p, int r);
void print_arr(int arr[], int length);

int main(void) {
  int arr[] = {12, 3, 7, 9, 6, 14, 6, 11, 2};
  int length = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, length);
  merge_sort(arr, 0, length - 1);
  print_arr(arr, length);
}

void merge(int arr[], int p, int q, int r) {
  int count_left = q - p + 1;
  int count_right = r - q;
  int *arr_left = malloc(count_left * sizeof(int));
  int *arr_right = malloc(count_right * sizeof(int));

  for (int i = 0; i < count_left; i++) {
    arr_left[i] = arr[p + i];
  }
  for (int j = 0; j < count_right; j++) {
    arr_right[j] = arr[q + j + 1];
  }

  int i = 0, j = 0, k = p;
  while (i < count_left && j < count_right) {
    if (arr_left[i] <= arr_right[j]) {
      arr[k++] = arr_left[i++];
    } else {
      arr[k++] = arr_right[j++];
    }
  }
  while (i < count_left) {
    arr[k++] = arr_left[i++];
  }
  while (j < count_right) {
    arr[k++] = arr_right[j++];
  }

  // printf("Merge was called with:\n");  // debug
  // printf("Left arr: ");                // debug
  // print_arr(arr_left, count_left);     // debug
  // printf("Right arr: ");               // debug
  // print_arr(arr_right, count_right);   // debug
  // printf("\n");                        // debug

  free(arr_left);
  free(arr_right);
}

void merge_sort(int arr[], int p, int r) {
  if (p >= r) {
    return;
  } else {
    int middle = (p + r) / 2;
    merge_sort(arr, p, middle);     // recursively dividing
    merge_sort(arr, middle + 1, r); // recursively dividing
    merge(arr, p, middle, r);       // combine
  }
}

void print_arr(int arr[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
