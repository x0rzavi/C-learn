// Finding Minimum and Maximum
// Iterative
// Horowitz
#include <stdio.h>

typedef struct Values {
  int min;
  int max;
} Values;

Values find_min_max(int arr[], int len);

int main(void) {
  int arr[] = {13, 19, 23, 34, 39, 100, 230};
  int len = sizeof(arr) / sizeof(arr[0]);
  Values min_max = find_min_max(arr, len);
  printf("Minimum element: %d\n", min_max.min);
  printf("Maximum element: %d\n", min_max.max);
}

Values find_min_max(int arr[], int len) {
  Values min_max;
  min_max.min = arr[0];
  min_max.max = arr[0];
  for (int i = 1; i < len; i++) {
    if (arr[i] < min_max.min) {
      min_max.min = arr[i];
    } else if (arr[i] > min_max.max) {
      min_max.max = arr[i];
    }
  }
  return min_max;
}
