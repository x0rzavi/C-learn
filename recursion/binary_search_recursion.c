#include <stdio.h>

int search(int arr[], int lower_limit, int upper_limit, int element) {
  if (lower_limit <= upper_limit) {
    int mid = (lower_limit + upper_limit) / 2;
    if (arr[mid] == element) {
      return mid;
    } else if (arr[mid] < element) {
      return search(arr, mid + 1, upper_limit, element);
    } else {
      return search(arr, lower_limit, mid - 1, element);
    }
  } else {
    return -1;
  }
}

int main(void) {
  int arr[] = {13, 19, 23, 34, 39, 100, 230}; // sorted array
  int len = sizeof(arr) / sizeof(arr[0]);
  int element = 39;
  printf("Element %d found at index %d\n", element,
         search(arr, 0, len, element));
}
