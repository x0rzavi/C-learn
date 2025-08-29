#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data);
void insert_beginning(node **head, node **tail, int *node_count, int data);
void display_iterative(node **head, int node_count);
void free_linked_list(node **head, int *node_count);
int get_data(char *prompt);
void push(node *stack[], int *tos, node *data);
node *pop(node *stack[], int *tos);
bool is_empty(int tos);
void reverse_linked_list(
    node **head, int node_count, node *stack[],
    int tos // not *tos since stack operations are local and internal
);

int main(void) {
  int node_count = 0;
  node *head = NULL;
  node *tail = NULL;
  node *stack[MAXSIZE];
  int tos = -1;

  insert_beginning(&head, &tail, &node_count, 10);
  insert_beginning(&head, &tail, &node_count, 20);
  insert_beginning(&head, &tail, &node_count, 30);
  insert_beginning(&head, &tail, &node_count, 40);
  display_iterative(&head, node_count);
  reverse_linked_list(&head, node_count, stack, tos);
  free_linked_list(&head, &node_count);
}

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_beginning(node **head, node **tail, int *node_count, int data) {
  node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
  if (*tail == NULL) { // no tail node
    *tail = new_node;
  }
  (*node_count)++;
}

void display_iterative(node **head, int node_count) {
  if (node_count == 0) {
    printf("Linked list empty\n");
    return;
  }

  printf("HEAD ->");
  for (node *trav = *head; trav != NULL;
       trav = trav->next) { // using for loop instead of while
    printf(" %d ->", trav->data);
  }
  printf(" TAIL\n");
}

void free_linked_list(node **head, int *node_count) {
  node *trav;
  while (*head != NULL) {
    trav = *head; // free up each head consecutively
    *head = (*head)->next;
    free(trav);
  }
  *node_count = 0;
  printf("Cleared linked list\n");
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}

void push(node *stack[], int *tos, node *data) {
  if (*tos + 1 == MAXSIZE) {
    printf("Stack overflow\n");
  } else {
    stack[++(*tos)] = data; // pre-increment since tos = -1 initially
  }
}

node *pop(node *stack[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    return NULL;
  } else {
    return stack[(*tos)--];
  }
}

bool is_empty(int tos) { return (tos == -1); }

void reverse_linked_list(node **head, int node_count, node *stack[],
                         int tos) { // FIX: memory leak
  for (node *trav = *head; trav != NULL; trav = trav->next) {
    push(stack, &tos, trav);
  }
  node *new_head = pop(stack, &tos);
  node *trav = new_head;
  while (!is_empty(tos)) {
    trav->next = pop(stack, &tos);
    trav = trav->next;
  }
  trav->next = NULL;
  display_iterative(&new_head, node_count);
}
