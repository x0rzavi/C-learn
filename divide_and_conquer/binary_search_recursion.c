// Binary Search
// Divide and Conquer
// Horowitz
#include <stdio.h>

int binary_search(int arr[], int lower_limit, int upper_limit, int element);

int main(void) {
  int arr[] = {13, 19, 23, 34, 39, 100, 230}; // sorted array
  int len = sizeof(arr) / sizeof(arr[0]);
  int element = 230;
  printf("Element %d found at index %d\n", element,
         binary_search(arr, 0, len, element));
}

int binary_search(int arr[], int lower_limit, int upper_limit, int element) {
  if (lower_limit == upper_limit) { // small problem
    if (element == arr[lower_limit]) {
      return lower_limit;
    } else {
      return -1; // element not found
    }
  } else { // reduce into subproblem
    int mid = (lower_limit + upper_limit) / 2;
    if (element == arr[mid]) {
      return mid;
    } else if (element > arr[mid]) {
      return binary_search(arr, mid + 1, upper_limit, element);
    } else {
      return binary_search(arr, lower_limit, mid - 1, element);
    }
  }
}
