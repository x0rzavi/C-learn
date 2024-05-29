// Matrix Chain Multiplication
// Divide and Conquer
// CLRS
#include <limits.h>
#include <stdio.h>

int matrix_chain_order(int dimensions[], int length);

int main(void) {
  int dimensions[] = {4, 10, 3, 12, 20, 7};
  int length = sizeof(dimensions) / sizeof(dimensions[0]);
  int min_mul = matrix_chain_order(dimensions, length);
  printf("Minimum number of multiplications: %d\n", min_mul);
}

int matrix_chain_order(int dimensions[], int length) {
  int costs[length][length];
  for (int i = 0; i < length; i++) {
    costs[i][i] = 0;
  }

  for (int l = 1; l < length; l++) {
    for (int i = 0; i < length - l; i++) {
      int j = i + l;
      costs[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int new_cost = costs[i][k] + costs[k + 1][j] +
                       (dimensions[i - 1] * dimensions[k] * dimensions[j]);
        if (new_cost < costs[i][j]) {
          costs[i][j] = new_cost;
        }
      }
    }
  }

  return costs[0][length - 2];
}
