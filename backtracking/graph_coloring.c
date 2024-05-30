#include <stdbool.h>
#include <stdio.h>

#define MAX 100

int x[MAX];      // Array to store color assignments
int G[MAX][MAX]; // Adjacency matrix of the graph
int n, m;        // Number of vertices and number of colors

// Function to assign a legal color to vertex k
void NextValue(int k) {
  do {
    x[k] = (x[k] + 1) % (m + 1); // Next highest color
    if (x[k] == 0)
      return; // All colors have been used
    int j;
    for (j = 1; j <= n; j++) {
      // Check if this color is distinct from adjacent colors
      if (G[k][j] != 0 && x[k] == x[j])
        break;
    }
    if (j == n + 1)
      return; // New color found
  } while (true);
}

// Recursive backtracking function to solve m-coloring problem
void mColoring(int k) {
  do {
    NextValue(k); // Assign a legal color to x[k]
    if (x[k] == 0)
      return; // No new color possible
    if (k == n) {
      for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
      }
      printf("\n"); // Print the color assignments
    } else {
      mColoring(k + 1); // Recur to color the next vertex
    }
  } while (true);
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of colors: ");
  scanf("%d", &m);

  printf("Enter the adjacency matrix:\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &G[i][j]);
    }
  }
  printf("\n");

  // Initialize color assignments to 0
  for (int i = 1; i <= n; i++) {
    x[i] = 0;
  }

  // Solve the m-coloring problem starting from vertex 1
  mColoring(1);

  return 0;
}
