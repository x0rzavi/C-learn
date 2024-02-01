#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *create_node(int data);
void search(node *root, int data);
void insert(node **root, int data);
void find_minimum(node *root);
void find_maximum(node *root);
int find_height(node *root);
void free_tree(node *root);
int max(int a, int b);
void enqueue(node *queue[], int *front, int *rear, node *root);
void dequeue(node *queue[], int *front, int *rear);
node *peek(node *queue[], int *front);
bool is_empty(int *front);
void level_order_traversal(node *root, node *queue[], int *front, int *rear);

int main(void) {
  node *queue[MAXSIZE];
  int front = -1;
  int rear = -1;

  node *root = NULL;
  insert(&root, 4);
  insert(&root, 10);
  insert(&root, 6);
  insert(&root, 5);
  insert(&root, 1);
  insert(&root, 8);
  insert(&root, 3);
  search(root, 8);
  find_minimum(root);
  find_maximum(root);
  printf("Height of tree %d\n", find_height(root));
  level_order_traversal(root, queue, &front, &rear);
  free_tree(root);
}

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void insert(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data <= (*root)->data) {
    insert(&((*root)->left), data);
  } else if (data > (*root)->data) {
    insert(&((*root)->right), data);
  }
}

void search(node *root, int data) {
  if (root == NULL) {
    printf("Empty binary search tree\n");
  } else if (root->data == data) {
    printf("Found element %d\n", data);
  } else if (data <= root->data) {
    search(root->left, data);
  } else if (data > root->data) {
    search(root->right, data);
  }
}

void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

void find_minimum(node *root) {
  if (root == NULL) {
    printf("Empty binary search tree\n");
    return;
  }

  if (root->left == NULL) {
    printf("Minimum element %d\n", root->data);
  } else {
    find_minimum(root->left);
  }
}

void find_maximum(node *root) {
  if (root == NULL) {
    printf("Empty binary search tree\n");
    return;
  }

  if (root->right == NULL) {
    printf("Maximum element %d\n", root->data);
  } else {
    find_maximum(root->right);
  }
}

int find_height(node *root) {
  if (root == NULL) {
    return -1;
  }
  int height_left = find_height(root->left);
  int height_right = find_height(root->right);
  return (max(height_left, height_right) + 1);
}

int max(int a, int b) { return a > b ? a : b; }

void level_order_traversal(node *root, node *queue[], int *front, int *rear) {
  if (root == NULL) {
    printf("Empty binary search tree\n");
    return;
  }

  enqueue(queue, front, rear, root);
  while (!is_empty(front)) {
    root = peek(queue, front);
    if (root->left != NULL) {
      enqueue(queue, front, rear, root->left);
    }
    if (root->right != NULL) {
      enqueue(queue, front, rear, root->right);
    }
    dequeue(queue, front, rear);
  }
  printf("\n");
}

void enqueue(node *queue[], int *front, int *rear, node *root) {
  if (*rear + 1 == MAXSIZE) {
    printf("Queue overflow\n");
    return;
  }

  if (*rear == -1 && *front == -1) {
    *rear = *front = 0;
  } else {
    (*rear)++;
  }
  queue[*rear] = root;
}

void dequeue(node *queue[], int *front, int *rear) {
  if (*front == -1) {
    printf("Queue underflow\n");
    return;
  }

  printf("%d ", queue[*front]->data);
  if (*rear == *front) {
    *rear = *front = -1;
  } else {
    (*front)++;
  }
}

node *peek(node *queue[], int *front) {
  if (*front == -1) {
    printf("Queue underflow\n");
    return NULL;
  }

  return queue[*front];
}

bool is_empty(int *front) { return (*front == -1); }
