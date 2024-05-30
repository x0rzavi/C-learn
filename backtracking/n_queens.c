#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int x[MAX]; // Global array to store positions of queens

// Function to check if a queen can be placed at row k and column i
int Place(int k, int i) {
  for (int j = 1; j <= k - 1; j++) {
    if (x[j] == i                         // same column
        || abs(x[j] - i) == abs(j - k)) { // same diagonal
      return 0;                           // Can't place the queen
    }
  }
  return 1; // Can place the queen
}

// Function to print the solution
void PrintSolution(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (x[i] == j) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

// Function to solve the n-queens problem using backtracking
void NQueens(int k, int n) {
  for (int i = 1; i <= n; i++) {
    if (Place(k, i)) {
      x[k] = i;
      if (k == n) {
        PrintSolution(n);
      } else {
        NQueens(k + 1, n);
      }
    }
  }
}

int main() {
  int n;
  printf("Enter the number of queens: ");
  scanf("%d", &n);
  NQueens(1, n);
  return 0;
}
