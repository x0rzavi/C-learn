#include <stdbool.h>
#include <stdio.h>
#define MAX_VERTICES 10
#define MAX_QUEUE_ELEMENTS 30

void add_edge(int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int source,
              int destination);
void enqueue(int queue[MAX_QUEUE_ELEMENTS], int *front, int *rear, int element);
int dequeue(int queue[MAX_QUEUE_ELEMENTS], int *front, int *rear);
bool is_empty(int *front);
void bfs_traversal(int start_node,
                   int adjacency_matrix[MAX_VERTICES][MAX_VERTICES],
                   int is_visited[MAX_VERTICES], int queue[MAX_QUEUE_ELEMENTS],
                   int *front, int *rear);

int main(void) {
  int adjacency_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
  int is_visited[MAX_VERTICES] = {0};
  int queue[MAX_QUEUE_ELEMENTS] = {0};
  int front = -1, rear = -1;

  add_edge(adjacency_matrix, 0, 1);
  add_edge(adjacency_matrix, 0, 2);
  add_edge(adjacency_matrix, 0, 3);
  add_edge(adjacency_matrix, 1, 4);
  add_edge(adjacency_matrix, 1, 5);
  add_edge(adjacency_matrix, 5, 6);
  add_edge(adjacency_matrix, 3, 7);
  add_edge(adjacency_matrix, 3, 8);
  add_edge(adjacency_matrix, 8, 9);
  bfs_traversal(0, adjacency_matrix, is_visited, queue, &front, &rear);
}

void add_edge(int adjacency_matrix[MAX_VERTICES][MAX_VERTICES], int src,
              int dest) {
  adjacency_matrix[src][dest] = 1;
}

void enqueue(int queue[MAX_QUEUE_ELEMENTS], int *front, int *rear,
             int element) {
  if (*rear + 1 == MAX_QUEUE_ELEMENTS) {
    return;
  }

  if (*rear == -1 && *front == -1) {
    *rear = *front = 0;
  } else {
    (*rear)++;
  }
  queue[*rear] = element;
}

int dequeue(int queue[MAX_QUEUE_ELEMENTS], int *front, int *rear) {
  if (*front == -1) {
    return -1;
  }

  int popped_element = queue[*front];
  if (*front == *rear) {
    *front = *rear = -1;
  } else {
    (*front)++;
  }
  return popped_element;
}

bool is_empty(int *front) { return *front == -1; }

void bfs_traversal(int start_node,
                   int adjacency_matrix[MAX_VERTICES][MAX_VERTICES],
                   int visited[MAX_VERTICES], int queue[MAX_QUEUE_ELEMENTS],
                   int *front, int *rear) {
  visited[start_node] = 1;
  enqueue(queue, front, rear, start_node);

  printf("BFS Traversal: ");
  while (!is_empty(front)) {
    int visited_node = dequeue(queue, front, rear);
    printf("%d ", visited_node);

    for (int i = 0; i < MAX_VERTICES; i++) {
      if (adjacency_matrix[visited_node][i] == 1 && visited[i] != 1) {
        visited[i] = 1;
        enqueue(queue, front, rear, i);
      }
    }
  }
}
