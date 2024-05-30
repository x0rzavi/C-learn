#include <stdio.h>

// Function to implement job sequencing algorithm
int JS(int d[], int n, int J[]) {
  d[0] = J[0] = 0; // Initialize
  J[1] = 1;        // Include job 1
  int k = 1;       // Number of jobs in the optimal solution

  for (int i = 2; i <= n; i++) {
    // Consider jobs in non-increasing order of profit
    int r = k;
    while ((d[J[r]] > d[i]) && (d[J[r]] != 0)) {
      r = r - 1;
    }
    if ((d[J[r]] <= d[i]) && (d[i] > r)) {
      // Insert i into J
      for (int q = k; q >= r + 1; q--) {
        J[q + 1] = J[q];
      }
      J[r + 1] = i;
      k = k + 1;
    }
  }
  return k; // Number of jobs in the optimal solution
}

int main() {
  int n; // Number of jobs

  printf("Enter the number of jobs: ");
  scanf("%d", &n);

  int d[n + 1]; // Deadlines
  int p[n + 1]; // Profits
  int J[n + 1]; // Job sequence

  printf("Enter the deadlines for the jobs:\n");
  for (int i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
  }

  printf("Enter the profits for the jobs:\n");
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }

  // Sort jobs in non-increasing order of profits
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (p[i] < p[j]) {
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
      }
    }
  }

  int k = JS(d, n, J); // Get the optimal job sequence

  printf("Number of jobs in the optimal solution: %d\n", k);
  printf("Jobs in the optimal solution:\n");
  for (int i = 1; i <= k; i++) {
    printf("%d ", J[i]);
  }
  printf("\n");

  return 0;
}
