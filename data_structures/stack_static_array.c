#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void push(int arr[], int *tos, int data);
void pop(int arr[], int *tos);
void peek(int arr[], int *tos);
void display(int arr[], int *tos);
int get_data(char *prompt);

int main(void) {
  int stack[MAXSIZE];
  int tos = -1; // empty stack

  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  printf("99. Exit\n");

  while (true) {
    int choice;
    printf("\nEnter choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    // clang-format off
    switch (choice) {
      case 1: push(stack, &tos, get_data("Enter data to push: ")); break;
      case 2: pop(stack, &tos); break;
      case 3: peek(stack, &tos); break;
      case 4: display(stack, &tos); break;
      case 99: exit(EXIT_SUCCESS);
      default: printf("Invalid choice\n");
    }
    // clang-format on
  }
}

void push(int arr[], int *tos, int data) {
  if (*tos + 1 == MAXSIZE) {
    printf("Stack overflow\n");
  } else {
    arr[++(*tos)] = data; // pre-increment since tos = -1 initially
    printf("Pushed element %d\n", data);
  }
}

void pop(int arr[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
  } else {
    printf("Popped element %d\n", arr[*tos]);
    (*tos)--;
  }
}

void peek(int arr[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
  } else {
    printf("Peeked element %d\n", arr[*tos]);
  }
}

void display(int arr[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    return;
  }

  for (int i = *tos; i != -1; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}
