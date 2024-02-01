#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 40

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *create_node(int data);
void insert_level_order(
    node **root, node *queue[], int front, int rear,
    int data); // local front & rear to make use of apprently new queue
void free_tree(node *root);
void enqueue(node *queue[], int *front, int *rear, node *root);
void dequeue(int *front, int *rear);
node *peek(node *queue[], int *front);
bool is_empty(int *front);
void level_order_traversal(
    node *root, node *queue[], int front,
    int rear); // local front & rear to make use of apprently new queue
void preorder_traversal(node *root);
void inorder_traversal(node *root);
void postorder_traversal(node *root);

int main(void) {
  node *queue[MAXSIZE];
  int front = -1;
  int rear = -1;

  node *root = NULL;
  insert_level_order(&root, queue, front, rear, 1);
  insert_level_order(&root, queue, front, rear, 2);
  insert_level_order(&root, queue, front, rear, 3);
  insert_level_order(&root, queue, front, rear, 4);
  insert_level_order(&root, queue, front, rear, 5);

  printf("\nLevel order traversal: ");
  level_order_traversal(root, queue, front, rear);

  printf("\nPreorder order traversal: ");
  preorder_traversal(root);

  printf("\nInorder order traversal: ");
  inorder_traversal(root);

  printf("\nPostorder order traversal: ");
  postorder_traversal(root);
  free_tree(root);
}

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_level_order(node **root, node *queue[], int front, int rear,
                        int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }

  enqueue(queue, &front, &rear, *root);
  while (!is_empty(&front)) {
    node *current = peek(queue, &front);
    dequeue(&front, &rear);

    if (current->left == NULL) {
      current->left = create_node(data);
      return;
    } else {
      enqueue(queue, &front, &rear, current->left);
    }

    if (current->right == NULL) {
      current->right = create_node(data);
      return;
    } else {
      enqueue(queue, &front, &rear, current->right);
    }
  }
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

void dequeue(int *front, int *rear) {
  if (*front == -1) {
    printf("Queue underflow\n");
    return;
  }

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

void free_tree(node *root) {
  if (root != NULL) {
    free_tree(root->left);
    free_tree(root->right);
    free(root);
  }
}

void level_order_traversal(node *root, node *queue[], int front, int rear) {
  if (root == NULL) {
    printf("Empty binary search tree\n");
    return;
  }

  enqueue(queue, &front, &rear, root);
  while (!is_empty(&front)) {
    root = peek(queue, &front);
    if (root->left != NULL) {
      enqueue(queue, &front, &rear, root->left);
    }
    if (root->right != NULL) {
      enqueue(queue, &front, &rear, root->right);
    }
    printf("%d ", queue[front]->data);
    dequeue(&front, &rear);
  }
}

void preorder_traversal(node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void inorder_traversal(node *root) {
  if (root == NULL) {
    return;
  }

  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

void postorder_traversal(node *root) {
  if (root == NULL) {
    return;
  }

  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);
}
