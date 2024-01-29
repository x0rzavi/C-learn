#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init_stack(int **arr, size_t *tos, size_t *size, int initial_size);
void push(int **arr, size_t *tos, size_t *size, int element);
void pop(int **arr, size_t *tos);
void peek(int **arr, size_t *tos);
void get_element_count(size_t tos);
void check_resize(int **arr, size_t *tos, size_t *size);
void display(int **arr, size_t tos);
void linear_search(int **arr, size_t *tos, int element);
void clear_stack(int **arr, size_t *tos, size_t *size);
int get_data(char *prompt);

int main(void) {
  int *arr;
  size_t tos = -1; // top of stack
  size_t size = 0;

  printf("1. Initialize\n");
  printf("2. Push\n");
  printf("3. Pop\n");
  printf("4. Peek\n");
  printf("5. Count\n");
  printf("6. Linear search\n");
  printf("7. Display\n");
  printf("98. Clear\n");
  printf("99. Exit\n");

  while (true) {
    int choice;
    printf("\nEnter choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    // clang-format off
    switch (choice) {
      case 1: init_stack(&arr, &tos, &size, get_data("Enter initial size: ")); break;
      case 2: push(&arr, &tos, &size, get_data("Enter data to push: ")); break;
      case 3: pop(&arr, &tos); break;
      case 4: peek(&arr, &tos); break;
      case 5: get_element_count(tos); break;
      case 6: linear_search(&arr, &tos, get_data("Enter element to search: ")); break;
      case 7: display(&arr, tos); break;
      case 98: clear_stack(&arr, &tos, &size); break;
      case 99: free(arr); exit(0); // NOLINT
      default: printf("Invalid choice\n");
    }
    // clang-format on
  }
}

void init_stack(int **arr, size_t *tos, size_t *size, int initial_size) {
  *arr = calloc(initial_size, sizeof(int));
  *tos = -1; // stack empty
  *size = initial_size;
  printf("Initialized stack\n");
}

void check_resize(int **arr, size_t *tos, size_t *size) {
  if (*tos + 2 == *size) { // stack overflow; *tos + 2 since *tos = -1 initially
                           // & +1 to adjust for pre-increment
    *size *= 2;
    *arr = realloc(*arr, *size * sizeof(int));
  }
}

void push(int **arr, size_t *tos, size_t *size, int element) {
  check_resize(arr, tos, size);
  (*arr)[++(*tos)] = element; // pre-increment since tos = -1 initially
  printf("Pushed element %d\n", element);
}

void pop(int **arr, size_t *tos) {
  if (*tos == (size_t)-1) {
    printf("Stack empty\n");
    return;
  }

  printf("Popped element %d\n", (*arr)[(*tos)--]);
}

void peek(int **arr, size_t *tos) {
  if (*tos == (size_t)-1) {
    printf("Stack empty\n");
    return;
  }

  printf("Peeked element %d\n", (*arr)[*tos]);
}

void linear_search(int **arr, size_t *tos, int element) {
  int found = -1;
  for (size_t i = 0; i <= *tos; i++) {
    if ((*arr)[i] == element) {
      printf("Element %d found at index %zu\n", element,
             *tos - i); // reverse index
      found = 1;
    }
  }
  if (found == -1) {
    printf("Element %d was not found\n", element);
  }
}

void display(int **arr, size_t tos) {
  if (tos == (size_t)-1) {
    printf("Stack empty\n");
    return;
  }

  for (size_t i = tos; i != (size_t)-1; i--) {
    printf("%d ", (*arr)[i]);
  }
  printf("\n");
}

void get_element_count(size_t tos) {
  printf("Number of element(s) is %zu\n", tos + 1);
}

void clear_stack(int **arr, size_t *tos, size_t *size) {
  for (size_t i = 0; i < *size; i++) {
    (*arr)[i] = 0;
  }
  *tos = -1;
  printf("Cleared stack\n");
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}
