#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

void push(char stack[], int *tos, char data);
char pop(char stack[], int *tos);
void reverse(char string[], char stack[],
             int tos // not *tos since stack operations are local and internal
);

int main(void) {
  char stack[MAXSIZE];
  char string[MAXSIZE];
  int tos = -1;

  printf("Enter string: ");
  fflush(stdout);
  fgets(string, sizeof string, stdin);
  if (string[strlen(string) - 1] == '\n') { // remove newline
    string[strlen(string) - 1] = '\0';
  }

  reverse(string, stack, tos);
}

void push(char stack[], int *tos, char data) {
  // if (*tos + 1 == MAXSIZE) {
  //   printf("Stack overflow\n");
  //   return;
  // }
  stack[++(*tos)] = data;
}

char pop(char stack[], int *tos) {
  // if (*tos == -1) {
  //   printf("Stack underflow\n");
  //   return '\0';
  // }
  return stack[(*tos)--];
}

void reverse(char string[], char stack[], int tos) {
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    push(stack, &tos, string[i]);
  }
  for (int i = 0; i < len; i++) {
    string[i] = pop(stack, &tos);
  }
  printf("Reversed string: %s\n", string);
}
