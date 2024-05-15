#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX_VERTICES 6

void add_edge(int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int source,
              int destination, int weight);
int find_lowest_cost_node(int node_costs[MAX_VERTICES],
                          bool is_processed[MAX_VERTICES]);
void dijkstra(int start_node, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES],
              int node_costs[MAX_VERTICES], bool is_processed[MAX_VERTICES],
              int parent_nodess[MAX_VERTICES]);
void shortest_path(int start_node, int end_node,
                   int parent_nodes[MAX_VERTICES]);

int main(void) {
  int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
  int parent_nodes[MAX_VERTICES] = {0};
  int node_costs[MAX_VERTICES] = {0};
  bool is_processed[MAX_VERTICES] = {false};

  for (int i = 0; i < MAX_VERTICES; i++) {
    node_costs[i] = INT_MAX;
  }

  add_edge(adjacency_matrix, 0, 1, 5);
  add_edge(adjacency_matrix, 0, 2, 2);
  add_edge(adjacency_matrix, 1, 3, 4);
  add_edge(adjacency_matrix, 1, 4, 2);
  add_edge(adjacency_matrix, 2, 1, 8);
  add_edge(adjacency_matrix, 2, 4, 7);
  add_edge(adjacency_matrix, 3, 5, 3);
  add_edge(adjacency_matrix, 3, 4, 6);
  add_edge(adjacency_matrix, 4, 5, 1);
  dijkstra(0, adjacency_matrix, node_costs, is_processed, parent_nodes);
}

void add_edge(int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int src,
              int dest, int weight) {
  adjacency_matrix[src][dest] = weight;
}

int find_lowest_cost_node(int node_costs[MAX_VERTICES],
                          bool is_processed[MAX_VERTICES]) {
  int lowest_cost = INT_MAX;
  int lowest_cost_node = -1;
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (!is_processed[i] && node_costs[i] < lowest_cost) {
      lowest_cost = node_costs[i];
      lowest_cost_node = i;
    }
  }
  return lowest_cost_node;
}

void dijkstra(int start_node, int adjacency_matrix[MAX_VERTICES][MAX_VERTICES],
              int node_costs[MAX_VERTICES], bool is_processed[MAX_VERTICES],
              int parent_nodes[MAX_VERTICES]) {
  node_costs[start_node] = 0;
  int lowest_cost_node = find_lowest_cost_node(node_costs, is_processed);

  while (lowest_cost_node != -1) {
    int node_cost = node_costs[lowest_cost_node];
    for (int i = 0; i < MAX_VERTICES; i++) {
      if (adjacency_matrix[lowest_cost_node][i] != 0) {
        int new_node_cost = node_cost + adjacency_matrix[lowest_cost_node][i];
        if (new_node_cost < node_costs[i]) {
          node_costs[i] = new_node_cost;
          parent_nodes[i] = lowest_cost_node;
        }
      }
    }
    is_processed[lowest_cost_node] = true;
    lowest_cost_node = find_lowest_cost_node(node_costs, is_processed);
  }

  printf("Starting node: %d\n", start_node);
  printf("Node\tCosts\n");
  for (int i = 0; i < MAX_VERTICES; i++) {
    printf("%d\t%d\n", i, node_costs[i]);
  }
  shortest_path(start_node, MAX_VERTICES - 1, parent_nodes);
}

void shortest_path(int start_node, int end_node,
                   int parent_nodes[MAX_VERTICES]) {
  printf("Shortest path from %d to %d: ", start_node, end_node);
  while (end_node != start_node) {
    printf("%d ", end_node);
    end_node = parent_nodes[end_node];
  }
  printf("%d ", start_node);
}
