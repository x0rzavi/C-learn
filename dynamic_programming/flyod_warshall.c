// Floyd Warshall Algorithm
// Dynamic Programming
// CLRS
#include <limits.h>
#include <stdio.h>
#define VERTICES 5

void floyd_warshall(int graph[][VERTICES]);
void print_graph(int graph[][VERTICES]);

int main(void) {
  int graph[VERTICES][VERTICES] = {{0, 3, 8, INT_MAX, -4},
                                   {INT_MAX, 0, INT_MAX, 1, 7},
                                   {INT_MAX, 4, 0, INT_MAX, INT_MAX},
                                   {2, INT_MAX, -5, 0, INT_MAX},
                                   {INT_MAX, INT_MAX, INT_MAX, 6, 0}};
  floyd_warshall(graph);
}

void floyd_warshall(int graph[][VERTICES]) {
  int distances[VERTICES][VERTICES];

  for (int i = 0; i < VERTICES; i++) {
    for (int j = 0; j < VERTICES; j++) {
      distances[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < VERTICES; k++) {
    for (int i = 0; i < VERTICES; i++) {
      for (int j = 0; j < VERTICES; j++) {
        if (distances[i][k] != INT_MAX &&
            distances[k][j] != INT_MAX && // fix overflow
            distances[i][k] + distances[k][j] < distances[i][j]) {
          distances[i][j] = distances[i][k] + distances[k][j];
        }
      }
    }
    // print_graph(distances); // print each step
    // printf("\n");
  }

  print_graph(distances);
}

void print_graph(int graph[][VERTICES]) {
  printf("All pairs shortest paths are: \n");
  for (int i = 0; i < VERTICES; i++) {
    for (int j = 0; j < VERTICES; j++) {
      if (graph[i][j] == INT_MAX) {
        printf("%5s", "INF");
      } else {
        printf("%5d", graph[i][j]);
      }
    }
    printf("\n");
  }
}
