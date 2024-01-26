#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data);
void insert_beginning(node **head, node **tail, int *node_count, int data);
void delete_beginning(node **head, int *node_count);
void display(node **head, int node_count);
void free_linked_list(node **head, int *node_count);
void get_node_count(int node_count);
void linear_search(node **head, int element);
void (*pop)(node **head, int *node_count) = delete_beginning; // ptr to function
void (*push)(node **head, node **tail, int *node_count,       // ptr to function
             int data) = insert_beginning;
void peek(node **head);
int get_data(char *prompt);

int main(void) {
  int node_count = 0;
  node *head = NULL;
  node *tail = NULL;

  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Peek\n");
  printf("4. Count\n");
  printf("5. Linear search\n");
  printf("6. Display\n");
  printf("98. Clear\n");
  printf("99. Exit\n");

  while (true) {
    int choice;
    printf("\nEnter choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    switch (choice) {
      // clang-format off
      case 1: push(&head, &tail, &node_count, get_data("Enter data to push: ")); break;
      case 2: pop(&head, &node_count); break;
      case 3: peek(&head); break;
      case 4: get_node_count(node_count); break;
      case 5: linear_search(&head, get_data("Enter element to search: ")); break;
      case 6: display(&head, node_count); break;
      case 98: free_linked_list(&head, &node_count); break;
      case 99: free_linked_list(&head, &node_count); exit(0);
      default: printf("Invalid choice\n");
      // clang-format on
    }
  }
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
  printf("Pushed element %d\n", new_node->data);
  (*node_count)++;
}

void delete_beginning(node **head, int *node_count) {
  if (*head == NULL) {
    printf("Stack empty\n");
    return;
  }

  node *temp = *head;
  *head = (*head)->next;
  printf("Popped element %d\n", temp->data);
  free(temp);
  (*node_count)--;
}

void peek(node **head) {
  if (*head == NULL) {
    printf("Stack empty\n");
    return;
  }

  printf("Peeked element %d\n", (*head)->data);
}

void display(node **head, int node_count) {
  if (node_count == 0) {
    printf("Stack empty\n");
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
  printf("Cleared stack\n");
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
