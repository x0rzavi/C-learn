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
void delete_node(node **root, int data);
node *find_minimum(node *root);
node *find_maximum(node *root);
int find_height(node *root);
void free_tree(node *root);
int max(int a, int b);

int main(void) {
  node *root = NULL;
  insert(&root, 12);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 13);
  insert(&root, 17);
  insert(&root, 1);
  insert(&root, 9);
  insert(&root, 14);
  insert(&root, 20);
  delete_node(&root, 15);
  search(root, 15);
  printf("Minimum element: %d\n", find_minimum(root)->data);
  printf("Maximum element: %d\n", find_maximum(root)->data);
  printf("Height of tree %d\n", find_height(root));
  free_tree(root);
}

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
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

void delete_node(node **root, int data) {
  if (*root == NULL) {
    return;
  }

  if (data < (*root)->data) {
    delete_node(&((*root)->left), data);
  } else if (data > (*root)->data) {
    delete_node(&((*root)->right), data);
  } else if (data == (*root)->data) { // found node with data
    if ((*root)->left == NULL && (*root)->right == NULL) { // if 0 child
      free(*root);
      *root = NULL;
    } else if ((*root)->left == NULL) { // if 1 child
      node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) { // if 1 child
      node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else { // if 2 children
      node *minimum_right_subtree = find_minimum((*root)->right);
      (*root)->data = minimum_right_subtree->data;
      delete_node(&((*root)->right), minimum_right_subtree->data);
    }
  }
}

void search(node *root, int data) {
  if (root == NULL) {
    printf("Element not found\n");
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

node *find_minimum(node *root) {
  if (root == NULL) {
    // return -1;
    return NULL;
  }

  if (root->left == NULL) {
    // return root->data;
    return root;
  } else {
    return find_minimum(root->left);
  }
}

node *find_maximum(node *root) {
  if (root == NULL) {
    // return -1;
    return NULL;
  }

  if (root->right == NULL) {
    // return root->data;
    return root;
  } else {
    return find_maximum(root->right);
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
