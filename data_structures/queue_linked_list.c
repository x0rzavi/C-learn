#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data);
void insert_end(node **head, node **tail, int *node_count, int data);
void delete_beginning(node **head, int *node_count);
void display(node **head, int node_count);
void free_linked_list(node **head, int *node_count);
void get_node_count(int node_count);
void linear_search(node **head, int element);
void (*enqueue)(node **head, node **tail, int *node_count,
                int data) = insert_end; // ptr to function
void (*dequeue)(node **head,            // ptr to function
                int *node_count) = delete_beginning;
void peek(node **head);
int get_data(char *prompt);

int main(void) {
  int node_count = 0;
  node *head = NULL;
  node *tail = NULL;

  enqueue(&head, &tail, &node_count, 100);
  enqueue(&head, &tail, &node_count, 200);
  enqueue(&head, &tail, &node_count, 300);
  dequeue(&head, &node_count);
  display(&head, node_count);
  free_linked_list(&head, &node_count);
}

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_end(node **head, node **tail, int *node_count, int data) {
  node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    *tail = new_node;
  } else {
    (*tail)->next = // NOLINT: *tail is never NULL so no NULL dereference
        new_node;
    *tail = new_node;
  }
  (*node_count)++;
  printf("Enqueued element %d\n", new_node->data);
}

void delete_beginning(node **head, int *node_count) {
  if (*head == NULL) {
    printf("Queue empty\n");
    return;
  }

  node *temp = *head;
  *head = (*head)->next;
  printf("Dequeued element %d\n", temp->data);
  free(temp);
  (*node_count)--;
}

void peek(node **head) {
  if (*head == NULL) {
    printf("Queue empty\n");
    return;
  }

  printf("Peeked element %d\n", (*head)->data);
}

void display(node **head, int node_count) {
  if (node_count == 0) {
    printf("Queue empty\n");
    return;
  }

  printf("HEAD ->");
  for (node *trav = *head; trav != NULL;
       trav = trav->next) { // using for loop instead of while
    printf(" %d ->", trav->data);
  }
  printf(" TAIL\n");
}

void get_node_count(int node_count) {
  printf("Number of node(s) is %d\n", node_count);
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}

void free_linked_list(node **head, int *node_count) {
  node *trav;
  while (*head != NULL) {
    trav = *head; // free up each head consecutively
    *head = (*head)->next;
    // printf("Freed node containing data %d\n", trav->data); // DEBUG
    free(trav);
  }
  *node_count = 0;
  printf("Cleared queue\n");
}

void linear_search(node **head, int element) {
  int found = -1, i;
  node *trav;
  for (trav = *head, i = 1; trav != NULL; trav = trav->next, i++) {
    if (trav->data == element) {
      printf("Element %d found at index %d\n", element, i);
      found = 1;
    }
  }
  if (found == -1) {
    printf("Element %d was not found\n", element);
  }
}
