#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40

void push(char stack[], int *tos, char data);
char pop(char stack[], int *tos);
char peek(char stack[], int *tos);
bool is_empty(int tos);
void convert(char string[], char stack[],
             int *tos); // 1 char for each token; no parenthesis
void convert_parenthesis(char string[], char stack[],
                         int *tos); // 1 char for each token; with parenthesis
bool has_higher_precedence(char top, char token);
bool is_opening_parenthesis(char top);

int main(void) {
  char string[MAXSIZE];
  char stack[MAXSIZE];
  int tos = -1;

  printf("Enter infix expression: ");
  fflush(stdout);
  fgets(string, sizeof string, stdin);
  if (string[strlen(string) - 1] == '\n') { // remove newline
    string[strlen(string) - 1] = '\0';
  }

  // convert(string, stack, &tos);
  convert_parenthesis(string, stack, &tos);
}

void push(char stack[], int *tos, char data) {
  if (*tos + 1 == MAXSIZE) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
  } else {
    stack[++(*tos)] = data;
  }
}

char pop(char stack[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  } else {
    return stack[(*tos)--];
  }
}

char peek(char stack[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  } else {
    return stack[*tos];
  }
}

bool is_empty(int tos) { return (tos == -1); }

void convert(char string[], char stack[], int *tos) {
  char result[MAXSIZE];
  int result_len = 0;
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    char token = string[i];
    if (isalpha(token)) {
      result[result_len++] = token;
    } else if (token == '+' || token == '-' || token == '*' || token == '/' ||
               token == '^') {
      while (!is_empty(*tos) &&
             has_higher_precedence(peek(stack, tos), token)) {
        result[result_len++] = pop(stack, tos);
      }
      push(stack, tos, token);
    }
  }
  while (!is_empty(*tos)) {
    result[result_len++] = pop(stack, tos);
  }
  result[result_len] = '\0';
  printf("Postfix expression: %s\n", result);
}

void convert_parenthesis(char string[], char stack[], int *tos) {
  char result[MAXSIZE];
  int result_len = 0;
  int len = strlen(string);
  for (int i = 0; i < len; i++) {
    char token = string[i];
    if (isalpha(token)) {
      result[result_len++] = token;
    } else if (token == '+' || token == '-' || token == '*' || token == '/' ||
               token == '^') {
      while (!is_empty(*tos) && !is_opening_parenthesis(peek(stack, tos)) &&
             has_higher_precedence(peek(stack, tos),
                                   token)) { // pop until top has higher
                                             // precedence than incoming token
        result[result_len++] = pop(stack, tos);
      }
      push(stack, tos, token);
    } else if (token == '(') {
      push(stack, tos, token);
    } else if (token == ')') {
      while (!is_empty(*tos) &&
             !is_opening_parenthesis(peek(
                 stack,
                 tos))) { // pop until opening parenthesis encountered in stack
        result[result_len++] = pop(stack, tos);
      }
      pop(stack, tos); // pop the encountered opening parenthesis
    }
  }
  while (!is_empty(*tos)) { // pop remaining tokens
    result[result_len++] = pop(stack, tos);
  }
  result[result_len] = '\0'; // NULL terminate array to make string
  printf("Postfix expression: %s\n", result);
}

int precedence(char token) {
  // clang-format off
  switch (token) {
    case '^': return 3; break;
    case '*':
    case '/': return 2; break;
    case '+':
    case '-': return 1; break;
    default: return 0;
  }
  // clang-format on
}

bool has_higher_precedence(char top, char token) {
  if (top == '^' && token == '^') { // right to left associativity
    return false;
  } else {
    return (precedence(top) >= precedence(token));
  }
}

bool is_opening_parenthesis(char top) { return (top == '('); }
