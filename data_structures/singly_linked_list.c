#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data);
void insert_beginning(node **head, node **tail, int *node_count, int data);
void insert_end(node **head, node **tail, int *node_count, int data);
void insert_position(node **head, node **tail, int *node_count, int data,
                     int index); // indexing starts AT 1 and NOT 0
void insert_before(node **head, node **tail, int *node_count, int data,
                   int element);
void insert_after(node **head, node **tail, int *node_count, int data,
                  int element);
void delete_beginning(node **head, int *node_count);
void delete_end(node **head, node **tail, int *node_count);
void delete_position(node **head, node **tail, int *node_count,
                     int index); // indexing starts AT 1 and NOT 0
void delete_before(node **head, int *node_count, int element);
void delete_after(node **head, node **tail, int *node_count, int element);
void display(node **head, int node_count);
void free_linked_list(node **head, int *node_count);
void get_node_count(int node_count);
void linear_search(node **head, int element);
int get_data(char *prompt);

int main(void) {
  int node_count = 0;
  node *head = NULL;
  node *tail = NULL;

  printf("1. Insert beginning\n");
  printf("2. Insert end\n");
  printf("3. Insert position\n");
  printf("4. Insert before\n");
  printf("5. Insert after\n");
  printf("6. Delete beginning\n");
  printf("7. Delete end\n");
  printf("8. Delete position\n");
  printf("9. Delete before\n");
  printf("10. Delete after\n");
  printf("11. Display\n");
  printf("12. Count\n");
  printf("13. Linear search\n");
  printf("99. Exit\n\n");

  while (true) {
    int choice;
    printf("Enter choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    // clang-format off
    switch (choice) {
      case 1: insert_beginning(&head, &tail, &node_count, get_data("Enter data to insert: ")); break;
      case 2: insert_end(&head, &tail, &node_count, get_data("Enter data to insert: ")); break;
      case 3: insert_position(&head, &tail, &node_count, get_data("Enter data to insert: "), get_data("Enter index to insert at: ")); break;
      case 4: insert_before(&head, &tail, &node_count, get_data("Enter data to insert: "), get_data("Enter element to insert before: ")); break;
      case 5: insert_after(&head, &tail, &node_count, get_data("Enter data to insert: "), get_data("Enter element to insert after: ")); break;
      case 6: delete_beginning(&head, &node_count); break;
      case 7: delete_end(&head, &tail, &node_count); break;
      case 8: delete_position(&head, &tail, &node_count, get_data("Enter index to delete at: ")); break;
      case 9: delete_before(&head, &node_count, get_data("Enter element to delete before: ")); break;
      case 10: delete_after(&head, &tail, &node_count, get_data("Enter element to delete after: ")); break;
      case 11: display(&head, node_count); break;
      case 12: get_node_count(node_count); break;
      case 13: linear_search(&head, get_data("Enter element to search: ")); break;
      case 99:
        free_linked_list(&head, &node_count);
        printf("Exiting\n");
        exit(0);
      default:
        printf("Invalid choice\n");
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
  (*node_count)++;
  display(head, *node_count);
}

void insert_end(node **head, node **tail, int *node_count, int data) {
  node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
  } else {
    (*tail)->next = new_node;
  }
  *tail = new_node;
  (*node_count)++;
  display(head, *node_count);
}

void insert_position(node **head, node **tail, int *node_count, int data,
                     int index) {
  if (index == 1) {
    insert_beginning(head, tail, node_count, data);
    return;
  }

  if (index == *node_count + 1) {
    insert_end(head, tail, node_count, data);
    return;
  }

  if (index > 1 && index <= *node_count) {
    node *new_node = create_node(data);
    node *trav = *head;
    for (int i = 1; i < index - 1;
         i++) { // traverse UNTIL JUST BEFORE position to insert
      trav = trav->next;
    }
    new_node->next = trav->next;
    trav->next = new_node;
    (*node_count)++;
    display(head, *node_count);
  } else {
    printf("Invalid index %d\n\n", index);
  }
}

void insert_before(node **head, node **tail, int *node_count, int data,
                   int element) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  if ((*head)->data == element) { // if head node contains element
    insert_beginning(head, tail, node_count, data);
    return;
  }

  node *trav = *head;
  while (trav->next != NULL &&
         trav->next->data !=
             element) { // traverse UNTIL JUST BEFORE node containing element
    trav = trav->next;
  }
  if (trav->next != NULL) { // stopped BEFORE a node; node found
    node *new_node = create_node(data);
    new_node->next = trav->next;
    trav->next = new_node;
    (*node_count)++;
    display(head, *node_count);
  } else {
    printf("Element %d not found\n", element);
  }
}

void insert_after(node **head, node **tail, int *node_count, int data,
                  int element) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  node *trav = *head;
  while (trav != NULL &&
         trav->data !=
             element) { // traverse UNTIL JUST ON node containing element
    trav = trav->next;
  }

  if (trav != NULL) { // stopped ON a node; node found
    node *new_node = create_node(data);
    new_node->next = trav->next;
    trav->next = new_node;
    (*node_count)++;
    if (trav == *tail) {
      *tail = new_node; // update tail node ptr
    }
  } else {
    printf("Element %d not found\n", element);
  }
  display(head, *node_count);
}

void delete_beginning(node **head, int *node_count) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  node *temp = *head;
  *head = (*head)->next;
  printf("Deleted node with data: %d\n", temp->data);
  free(temp);
  (*node_count)--;
  display(head, *node_count);
}

void delete_end(node **head, node **tail, int *node_count) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  if (*head == *tail) { // if only 1 node present
    printf("Deleted node with data: %d\n", (*head)->data);
    *head = NULL;
    *tail = NULL;
    (*node_count)--;
  } else {
    node *trav = *head;
    while (trav->next != *tail) { // traverse UNTIL JUST BEFORE tail
      trav = trav->next;
    }
    printf("Deleted node with data: %d\n", (*tail)->data);
    free(*tail);
    *tail = trav;
    (*tail)->next = NULL;
    (*node_count)--;
  }
  display(head, *node_count);
}

void delete_position(node **head, node **tail, int *node_count,
                     int index) { // indexing starts AT 1 and NOT 0
  if (index == 1) {
    delete_beginning(head, node_count);
    return;
  }

  if (index == *node_count) {
    delete_end(head, tail, node_count);
    return;
  }

  if (index > 1 && index < *node_count) {
    node *prev = NULL;
    node *curr = *head;
    for (int i = 1; i < index;
         i++) { // traverse curr ptr UNTIL JUST ON node to delete
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    printf("Deleted node with data: %d\n", curr->data);
    free(curr);
    (*node_count)--;
    display(head, *node_count);
  } else {
    printf("Invalid index %d\n\n", index);
  }
}

void delete_before(node **head, int *node_count, int element) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  if ((*head)->data == element) {
    printf("Cannot delete before first node\n");
    return;
  }

  node *prev = NULL;
  node *curr = *head;
  while (curr->next != NULL &&
         curr->next->data !=
             element) { // traverse curr ptr UNTIL JUST BEFORE node to delete
    prev = curr;
    curr = curr->next;
  }

  if (curr->next != NULL) {
    if (prev == NULL) { // if node to delete is 1st node
      *head = curr->next;
    } else {
      prev->next = curr->next;
    }
    printf("Deleted node with data: %d\n", curr->data);
    free(curr);
    (*node_count)--;
    display(head, *node_count);
  } else {
    printf("Element %d not found\n", element);
  }
}

void delete_after(node **head, node **tail, int *node_count, int element) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  node *trav = *head;
  while (trav != NULL &&
         trav->data !=
             element) { // traverse UNTIL JUST ON node AFTER which to delete
    trav = trav->next;
  }

  if (trav != NULL && trav->next != NULL) { // check if NOT last node
    node *temp = trav->next;
    trav->next = temp->next;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
    (*node_count)--;
    display(head, *node_count);
    if (trav->next == NULL) {
      *tail = trav; // update tail ptr if trav is last node
    }
  } else {
    printf("Element %d not found or no more nodes to delete\n", element);
  }
}

void display(node **head, int node_count) {
  if (node_count == 0) {
    printf("Linked list empty\n\n");
    return;
  }

  // char buffer[50]; // TEST
  printf("HEAD ->");
  for (node *trav = *head; trav != NULL;
       trav = trav->next) { // using for loop instead of while
    printf(" %d ->", trav->data);
    // snprintf(buffer, sizeof(buffer), "%d ", trav->data); // TEST
    // printf("%s", buffer); // TEST
  }
  printf(" TAIL\n\n");
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
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}

void get_node_count(int node_count) {
  printf("Number of node(s) is %d\n\n", node_count);
}

void linear_search(node **head, int element) {
  int found = -1, i;
  node *trav;
  for (trav = *head, i = 1; trav != NULL; trav = trav->next, i++) {
    if (trav->data == element) {
      printf("Element %d found at index %d\n\n", element, i);
      found = 1;
    }
  }
  if (found == -1) {
    printf("Element %d was not found\n\n", element);
  }
}
