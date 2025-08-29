#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void insertEnd(int data) {
  node *newNode = malloc(sizeof(node));
  newNode->data = data;
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void printList() {
  for (node *trav = head; trav != NULL; trav = trav->next) {
    printf("%d ", trav->data);
  }
}

void insertIndex(int index, int data) {
  node *newNode = malloc(sizeof(node));
  newNode->data = data;
  node *trav = head;
  for (int i = 0; i < index - 1; ++i) {
    trav = trav->next;
  }
  newNode->next = trav->next;
  trav->next = newNode;
}

void lengthList() {
  int count = 0;
  for (node *trav = head; trav != NULL; trav = trav->next) {
    count++;
  }
  printf("Length: %d\n", count);
}

int main(void) {
  insertEnd(40);
  insertEnd(20);
  insertEnd(30);
  insertEnd(50);
  insertIndex(4, 50);
  printList();
  lengthList();
  return EXIT_SUCCESS;
}
