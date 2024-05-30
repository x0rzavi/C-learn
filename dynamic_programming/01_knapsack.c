#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int knapsack_size, int weights[], int profits[], int num_items) {
  int i, w;
  int K[num_items + 1][knapsack_size + 1];

  for (i = 0; i <= num_items; i++) {
    for (w = 0; w <= knapsack_size; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (weights[i - 1] <= w)
        K[i][w] =
            max(profits[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  return K[num_items][knapsack_size];
}

int main() {
  int profits[] = {60, 100, 120};
  int weights[] = {10, 20, 30};
  int knapsack_size = 50;
  int num_items = sizeof(profits) / sizeof(profits[0]);
  printf("%d", knapsack(knapsack_size, weights, profits, num_items));
  return 0;
}
