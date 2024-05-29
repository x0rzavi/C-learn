#include <stdio.h>
#define MAX_VERTICES 6

void dfs(int graph[][MAX_VERTICES], int is_visited[MAX_VERTICES], int source);

int main(void) {
  int is_visited[MAX_VERTICES] = {0};
  int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0, 0},
                                           {1, 0, 0, 1, 0},
                                           {1, 0, 0, 1, 1},
                                           {0, 1, 1, 0, 1},
                                           {0, 0, 1, 1, 0}};
  dfs(graph, is_visited, 0);
}

void dfs(int graph[][MAX_VERTICES], int is_visited[MAX_VERTICES], int source) {
  is_visited[source] = 1;
  printf("%d ", source);
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (!is_visited[i] && graph[source][i] == 1) {
      dfs(graph, is_visited, i);
    }
  }
}
