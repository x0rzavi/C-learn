// Floyd Warshall Algorithm
// Dynamic Programming
// CLRS
#include <limits.h>
#include <stdio.h>
#define MAX_VERTICES 5

void floyd_warshall(int graph[][MAX_VERTICES]);
void print_graph(int graph[][MAX_VERTICES]);

int main(void) {
  int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 3, 8, INT_MAX, -4},
                                           {INT_MAX, 0, INT_MAX, 1, 7},
                                           {INT_MAX, 4, 0, INT_MAX, INT_MAX},
                                           {2, INT_MAX, -5, 0, INT_MAX},
                                           {INT_MAX, INT_MAX, INT_MAX, 6, 0}};
  floyd_warshall(graph);
}

void floyd_warshall(int graph[][MAX_VERTICES]) {
  int distances[MAX_VERTICES][MAX_VERTICES];

  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      distances[i][j] = graph[i][j];
    }
  }

  for (int k = 0; k < MAX_VERTICES; k++) {
    for (int i = 0; i < MAX_VERTICES; i++) {
      for (int j = 0; j < MAX_VERTICES; j++) {
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

void print_graph(int graph[][MAX_VERTICES]) {
  printf("All pairs shortest paths are: \n");
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      if (graph[i][j] == INT_MAX) {
        printf("%5s", "INF");
      } else {
        printf("%5d", graph[i][j]);
      }
    }
    printf("\n");
  }
}
