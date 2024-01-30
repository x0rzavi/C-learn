#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20

void push(char stack[], int *tos, char data);
void pop(int *tos);
char peek(char stack[], int *tos);
bool is_empty(int *tos);
bool is_match(char stack[], int *tos, char data);
bool check_brackets(char string[], char stack[], int *tos);

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

  printf("%s\n",
         check_brackets(string, stack, &tos) ? "Balanced" : "Not balanced");
}

void push(char stack[], int *tos, char data) {
  if (*tos + 1 == MAXSIZE) {
    printf("Stack overflow\n");
  } else {
    stack[++(*tos)] = data;
  }
}

void pop(int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
  } else {
    (*tos)--;
  }
}

char peek(char stack[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    return '\0';
  } else {
    return stack[*tos];
  }
}

bool check_brackets(char string[], char stack[], int *tos) {
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
      push(stack, tos, string[i]);
    } else if (string[i] == ')' || string[i] == '}' || string[i] == ']') {
      if (is_empty(tos) || !is_match(stack, tos, string[i])) {
        return false;
      } else {
        pop(tos);
      }
    }
  }
  return is_empty(tos);
}

bool is_empty(int *tos) { return (*tos == -1); }

bool is_match(char stack[], int *tos, char data) {
  char top = peek(stack, tos);
  if (data == ')' && top == '(')
    return true;
  else if (data == '}' && top == '{')
    return true;
  else if (data == ']' && top == '[')
    return true;
  else
    return false;
}
