#include <limits.h>
#include <stdio.h>

// Function to find the most efficient way to multiply
// given sequence of matrices
int MatrixChainOrder(int p[], int n) {
  int m[n][n];
  int i, j, k, L, q;

  // cost is zero when multiplying one matrix.
  for (i = 1; i < n; i++)
    m[i][i] = 0;

  // L is chain length.
  for (L = 2; L < n; L++) {
    for (i = 1; i < n - L + 1; i++) {
      j = i + L - 1;
      m[i][j] = INT_MAX;
      for (k = i; k <= j - 1; k++) {
        // q = cost/scalar multiplications
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
          m[i][j] = q;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%10d", m[i][j]);
    }
    printf("\n");
  }
  return m[1][n - 1];
}

int main() {
  int arr[] = {30, 35, 15, 5, 10, 20, 25};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Minimum number of multiplications is %d ",
         MatrixChainOrder(arr, size));

  return 0;
}
