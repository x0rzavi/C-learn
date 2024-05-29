// Bellman Ford Algorithm
// Greedy Algorithm
// CLRS using Adjacency Matrix
#include <limits.h>
#include <stdio.h>
#define MAX_VERTICES 5

void bellman_ford(int graph[][MAX_VERTICES], int source);
void print_distances(int distances[MAX_VERTICES], int source);

int main(void) {
  int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 6, INT_MAX, 7, INT_MAX},
                                           {INT_MAX, 0, 5, 8, -4},
                                           {INT_MAX, -2, 0, INT_MAX, INT_MAX},
                                           {INT_MAX, INT_MAX, -3, 0, 9},
                                           {2, INT_MAX, 7, INT_MAX, 0}};
  bellman_ford(graph, 0);
}

void bellman_ford(int graph[][MAX_VERTICES], int source) {
  int distances[MAX_VERTICES];
  for (int i = 0; i < MAX_VERTICES; i++) {
    distances[i] = INT_MAX;
  }
  distances[source] = 0;

  for (int i = 0; i < MAX_VERTICES - 1; i++) {
    for (int u = 0; u < MAX_VERTICES; u++) {
      for (int v = 0; v < MAX_VERTICES; v++) {
        if (distances[u] != INT_MAX && graph[u][v] != INT_MAX && // fix overflow
            distances[v] > distances[u] + graph[u][v]) {
          distances[v] = distances[u] + graph[u][v];
        }
      }
    }
  }
  print_distances(distances, source);
}

void print_distances(int distances[MAX_VERTICES], int source) {
  printf("Single source from %d shortest paths are: \n", source);
  printf("Node\tDistance\n");
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (distances[i] == INT_MAX) {
      printf("%d\t%s\n", i, "INF");
    } else {
      printf("%d\t%d\n", i, distances[i]);
    }
  }
}
