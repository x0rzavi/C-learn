// Binary Search
// Iterative
// Horowitz
#include <stdio.h>

int binary_search(int arr[], int len, int element);

int main(void) {
  int arr[] = {13, 19, 23, 34, 39, 100, 230}; // sorted array
  int len = sizeof(arr) / sizeof(arr[0]);
  int element = 100;
  printf("Element %d found at index %d\n", element,
         binary_search(arr, len, element));
}

int binary_search(int arr[], int len, int element) {
  int lower_index = 0, upper_index = len - 1;
  while (lower_index <= upper_index) {
    int mid = (lower_index + upper_index) / 2;
    if (element < arr[mid]) {
      upper_index = mid - 1;
    } else if (element > arr[mid]) {
      lower_index = mid + 1;
    } else {
      return mid;
    }
  }
  return -1; // element not found
}
