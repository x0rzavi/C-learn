#include <ctype.h> // isdigit()
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40
#define MAXTOKENS 20

void push(int stack[], int *tos, int data);
int pop(int stack[], int *tos);
int evaluate(int stack[], char string[], int *tos); // 1 char for each token
int evaluate_multi(
    int stack[], char string[],
    int *tos); // more than 1 char for each token separted by space
int calculate(int operand_1, int operand_2, char operand);

int main(void) {
  char string[MAXSIZE];
  int stack[MAXSIZE];
  int tos = -1;

  printf("Enter prefix expression: ");
  fflush(stdout);
  fgets(string, sizeof string, stdin);
  if (string[strlen(string) - 1] == '\n') { // remove newline
    string[strlen(string) - 1] = '\0';
  }

  // printf("Evaluated expression: %d\n", evaluate(stack, string, &tos));
  printf("Evaluated expression: %d\n", evaluate_multi(stack, string, &tos));
}

void push(int stack[], int *tos, int data) {
  if (*tos + 1 == MAXSIZE) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
  } else {
    stack[++(*tos)] = data;
  }
}

int pop(int stack[], int *tos) {
  if (*tos == -1) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
  } else {
    return stack[(*tos)--];
  }
}

int evaluate(int stack[], char string[], int *tos) {
  int len = strlen(string);
  for (int i = len; i >= 0; i--) {
    char token = string[i];
    if (isdigit(token)) {
      push(stack, tos, token - '0'); // convert to digit from a char
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      int operand_1 = pop(stack, tos);
      int operand_2 = pop(stack, tos);
      int result = calculate(operand_1, operand_2, token);
      push(stack, tos, result);
    }
  }
  return pop(stack, tos);
}

int evaluate_multi(int stack[], char string[], int *tos) {
  char *token = strtok(string, " "); // split string by space as delimiter
  char *tokens[MAXTOKENS];
  int token_count = 0;

  while (token != NULL) {
    tokens[token_count++] = token;
    token = strtok(NULL, " "); // continue tokenization
  }

  for (int i = token_count - 1; i >= 0; i--) { // process token right to left
    if (isdigit(tokens[i][0])) {
      push(stack, tos, atoi(tokens[i])); // convert to digit from a string
    } else if (tokens[i][0] == '+' || tokens[i][0] == '-' ||
               tokens[i][0] == '*' || tokens[i][0] == '/') {
      int operand_2 = pop(stack, tos);
      int operand_1 = pop(stack, tos);
      int result = calculate(operand_1, operand_2, tokens[i][0]);
      push(stack, tos, result);
    }
  }
  return pop(stack, tos);
}

int calculate(int operand_1, int operand_2, char operand) {
  // clang-format off
  switch (operand) {
    case '+': return operand_1 + operand_2; break;
    case '-': return operand_1 - operand_2; break;
    case '*': return operand_1 * operand_2; break;
    case '/':
      if (operand_2 == 0) {
        printf("Division by 0\n");
        exit(EXIT_FAILURE);
      }
      return operand_1 / operand_2; break;
    default: return 0;
  }
  // clang-format on
}
