// Enter infix expression: A+(B*C-D)^E+F
// Postfix expression is: ABC*D-E^+F+
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

void push(char);
char pop();
int prece(char);
char I[SIZE], P[SIZE], stck[SIZE]; 
int tos = -1, j = 0;

int main() {
        printf("Enter infix expression: ");
        fgets(I, SIZE, stdin); I[strlen(I) - 1] = '\0';
        char clBrac = ')'; strcat(I, &clBrac);
        
        push('(');
        for (int i = 0; I[i] != '\0'; i++) {
                if (I[i] == '(') {
                        push(I[i]);
                } else if (isalpha(I[i])) {
                        P[j] = I[i]; j++;
                } else if (I[i] == ')') {
                        char ch = pop();
                        while (ch != '(') {
                                P[j] = ch; j++;
                                ch = pop();
                        }
                } else {
                        while (prece(stck[tos]) >= prece(I[i])) {
                                char ch = pop();
                                P[j] = ch, j++;
                        }
                        push(I[i]);
                }
        }
        P[j] = '\0';
        printf("Postfix expression is: ");
        fputs(P, stdout);

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

int prece(char ch) {
        int p = -1;
        if (ch == '^') {
                p = 3;
        } else if (ch == '*' || ch == '/' || ch == '%') {
                p = 2;
        } else if (ch == '+' || ch == '-') {
                p = 1;
        } else if (ch == '(') {
                p = 0;
        }
        return p;
}
