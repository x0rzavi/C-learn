#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void enqueue(int queue[], int *front, int *rear, int data);
void dequeue(int queue[], int *front, int *rear);
void peek(int queue[], int *front);
void display(int queue[], int *front, int *rear);
void clear(int *front, int *rear);
int get_data(char *prompt);

int main(void) {
  int queue[MAXSIZE];
  int front = -1; // empty queue
  int rear = -1;  // empty queue

  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Peek\n");
  printf("4. Display\n");
  printf("98. Clear\n");
  printf("99. Exit\n");

  while (true) {
    int choice;
    printf("\nEnter choice: ");
    fflush(stdout);
    scanf("%d", &choice);

    // clang-format off
    switch (choice) {
      case 1: enqueue(queue, &front, &rear, get_data("Enter data to enqueue: ")); break;
      case 2: dequeue(queue, &front, &rear); break;
      case 3: peek(queue, &front); break;
      case 4: display(queue, &front, &rear); break;
      case 98: clear(&front, &rear); break;
      case 99: clear(&front, &rear); exit(EXIT_SUCCESS);
      default: printf("Invalid choice\n");
    }
    // clang-format on
  }
}

void enqueue(int queue[], int *front, int *rear, int data) {
  if (*rear + 1 == MAXSIZE) {
    printf("Queue overflow\n");
    return;
  }

  if (*rear == -1 && *front == -1) {
    *rear = *front = 0;
  } else {
    (*rear)++;
  }
  queue[*rear] = data;
  printf("Enqueued element %d\n", data);
}

void dequeue(int queue[], int *front, int *rear) {
  if (*front == -1) {
    printf("Queue underflow\n");
    return;
  }

  printf("Dequeued element %d\n", queue[*front]);
  if (*front == *rear) {
    *front = *rear = -1;
  } else {
    (*front)++;
  }
}

void peek(int queue[], int *front) {
  if (*front == -1) {
    printf("Queue underflow\n");
  } else {
    printf("Peeked element %d\n", queue[*front]);
  }
}

void display(int queue[], int *front, int *rear) {
  if (*front == -1) {
    printf("Queue underflow\n");
    return;
  }

  for (int i = *front; i <= *rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

void clear(int *front, int *rear) {
  *front = *rear = -1;
  printf("Cleared queue\n");
}

int get_data(char *prompt) {
  printf("%s", prompt);
  fflush(stdout);
  int data;
  scanf("%d", &data);
  return data;
}
