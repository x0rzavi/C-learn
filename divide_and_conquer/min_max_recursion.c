// Finding Minimum and Maximum
// Divide and Conquer
// Horowitz
#include <stdio.h>

typedef struct Values {
  int min;
  int max;
} Values;

Values find_min_max(int arr[], int lower_index, int upper_index);

int main(void) {
  int arr[] = {13, 19, 23, 34, 39, 100, 230};
  int len = sizeof(arr) / sizeof(arr[0]);
  Values min_max = find_min_max(arr, 0, len - 1);
  printf("Minimum element: %d\n", min_max.min);
  printf("Maximum element: %d\n", min_max.max);
}

Values find_min_max(int arr[], int lower_index, int upper_index) {
  Values min_max, min_max_left, min_max_right;

  if (lower_index == upper_index) { // small problem
    min_max.min = arr[lower_index];
    min_max.max = arr[lower_index];
    return min_max;
  } else if (upper_index - lower_index == 1) { // small problem
    if (arr[lower_index] < arr[upper_index]) {
      min_max.min = arr[lower_index];
      min_max.max = arr[upper_index];
    } else {
      min_max.min = arr[upper_index];
      min_max.max = arr[lower_index];
    }
    return min_max;
  } else { // reduce into subproblems
    int mid = (lower_index + upper_index) / 2;
    min_max_left = find_min_max(arr, lower_index, mid - 1);
    min_max_right = find_min_max(arr, mid + 1, upper_index);

    if (min_max_left.min < min_max_right.min) {
      min_max.min = min_max_left.min;
    } else {
      min_max.min = min_max_right.min;
    }
    if (min_max_left.max > min_max_right.max) {
      min_max.max = min_max_left.max;
    } else {
      min_max.max = min_max_right.max;
    }
    return min_max;
  }
}
