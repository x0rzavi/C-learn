// FIXME
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

void push(char);
char pop();
char P[SIZE], stck[SIZE];
int tos = -1, result;

int main() {
        printf("Enter postfix expression: ");
        fgets(P, SIZE, stdin); P[strlen(P) - 1] = '\0';
        char clBrac = ')'; strcat(P, &clBrac);
        for (int i = 0; P[i] != ')'; i++) {
                if (isdigit(P[i])) {
                        push(P[i]);
                } else if (P[i] == '+' || P[i] == '-' || P[i] == '*' || P[i] == '/') {
                        char ch1 = pop();
                        char ch2 = pop();
                        switch (P[i]) {
                                case '+': result = (int)ch1 + (int)ch2; break;
                                case '-': result = (int)ch1 - (int)ch2; break;
                                case '*': result = (int)ch1 * (int)ch2; break;
                                case '/': result = (int)ch1 / (int)ch2; break;
                        }
                        push(result);
                        // printf("\n%c %c %c = stck[tos]", ch1, P[i], ch2);
                }
        }

        printf("Result: %c", stck[tos]);
        return 0;
}

void push(char ch) {
        if (tos == SIZE - 1) {
                printf("Stack Overflow\n");
        } else {
                tos++;
                stck[tos] = ch;
        }
}

char pop() {
        char ch = -1;
        if (tos == -1) {
                printf("Stack Underflow\n");
        } else {
                ch = stck[tos];
                tos--;
        }
        return ch;
}
