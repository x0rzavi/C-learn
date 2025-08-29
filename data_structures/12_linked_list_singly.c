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
void delete_element(node **head, node **tail, int *node_count, int element);
void display_iterative(node **head, int node_count);
void display_recursion(node **head, int node_count);
void display_reverse_recursion(node **head, int node_count);
void reverse_iterative(node **head, node **tail, int node_count);
node *reverse_recursion(node **head, node **tail, int node_count);
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
  printf("11. Delete element\n");
  printf("12. Display iterative\n");
  printf("13. Display recursion\n");
  printf("14. Display reverse recursion\n");
  printf("15. Count\n");
  printf("16. Linear search\n");
  printf("17. Reverse iterative\n");
  printf("18. Reverse recursion\n");
  printf("98. Clear list\n");
  printf("99. Exit\n");

  while (true) {
    int choice;
    printf("\nEnter choice: ");
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
      case 11: delete_element(&head, &tail, &node_count, get_data("Enter element to delete: ")); break;
      case 12: display_iterative(&head, node_count); break;
      case 13: display_recursion(&head, node_count); break;
      case 14: display_reverse_recursion(&head, node_count); break;
      case 15: get_node_count(node_count); break;
      case 16: linear_search(&head, get_data("Enter element to search: ")); break;
      case 17: reverse_iterative(&head, &tail, node_count); break;
      case 18: head = reverse_recursion(&head, &tail, node_count); display_iterative(&head, node_count); break;
      case 98: free_linked_list(&head, &node_count); break;
      case 99: free_linked_list(&head, &node_count); exit(EXIT_SUCCESS);
      default: printf("Invalid choice\n");
    }
    // clang-format on
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
  display_iterative(head, *node_count);
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
  display_iterative(head, *node_count);
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
    display_iterative(head, *node_count);
  } else {
    printf("Invalid index %d\n", index);
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
    display_iterative(head, *node_count);
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
  display_iterative(head, *node_count);
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
  display_iterative(head, *node_count);
}

void delete_end(node **head, node **tail, int *node_count) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  if (*head == *tail) { // if only 1 node present
    printf("Deleted node with data: %d\n", (*head)->data);
    node *temp = *head;
    free(temp);
    *head = NULL;
    *tail = NULL;
    (*node_count)--;
    return;
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
  display_iterative(head, *node_count);
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
    display_iterative(head, *node_count);
  } else {
    printf("Invalid index %d\n", index);
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
    display_iterative(head, *node_count);
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
    if (trav->next == NULL) { // if trav is now last node
      *tail = trav;
    }
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
    (*node_count)--;
    display_iterative(head, *node_count);
  } else {
    printf("Element %d not found or no more nodes to delete\n", element);
  }
}

void delete_element(node **head, node **tail, int *node_count, int element) {
  if (*head == NULL) {
    printf("Linked list empty\n");
    return;
  }

  if ((*head)->data == element) {
    delete_beginning(head, node_count);
    return;
  }

  node *trav = *head;
  while (trav->next != NULL &&
         trav->next->data !=
             element) { // traverse UNTIL JUST BEFORE node to delete
    trav = trav->next;
  }

  if (trav->next != NULL) {
    node *temp = trav->next;
    trav->next = temp->next;
    if (trav->next == NULL) { // if trav is now last node
      *tail = trav;
    }
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
    (*node_count)--;
    display_iterative(head, *node_count);
  } else {
    printf("Element %d not found\n", element);
  }
}

void display_iterative(node **head, int node_count) {
  if (node_count == 0) {
    printf("Linked list empty\n");
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
  printf(" TAIL\n");
}

void display_recursion(node **head, int node_count) {
  if (node_count == 0) {
    printf("Linked list empty\n");
    return;
  }

  if (*head == NULL) { // base case for recursive call
    printf("\n");
    return;
  }
  printf("%d ", (*head)->data);
  display_recursion(&((*head)->next), node_count);
}

void display_reverse_recursion(node **head, int node_count) {
  if (node_count == 0) {
    printf("Linked list empty\n");
    return;
  }

  if (*head == NULL) { // base case for recusive call
    return;
  }
  display_reverse_recursion(&((*head)->next), node_count);
  printf("%d ", (*head)->data);
}

void reverse_iterative(node **head, node **tail, int node_count) {
  // https://youtu.be/G0_I-ZF0S38?si=kyfVL9gKlVrGCMvJ
  if (node_count == 0) {
    printf("Linked list empty\n");
    return;
  }

  node *curr = *head;
  node *prev = NULL;
  node *next = NULL;
  *tail = *head;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
  display_iterative(head, node_count);
}

node *reverse_recursion(node **head, node **tail, int node_count) {
  // https://youtu.be/G0_I-ZF0S38?si=kyfVL9gKlVrGCMvJ
  if (node_count == 0) {
    printf("Linked list empty\n");
    return NULL;
  }

  if ((*head)->next == NULL) { // base case for recursive call
    return *head;
  }

  node *new_head = reverse_recursion(&((*head)->next), tail, node_count);
  *tail = *head;
  (*head)->next->next = *head;
  (*head)->next = NULL;
  return new_head;
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
  printf("Cleared linked list\n");
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}

void get_node_count(int node_count) {
  printf("Number of node(s) is %d\n", node_count);
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
