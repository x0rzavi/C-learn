#include <stdio.h>
#define MAXSIZE 3

void push(int*, int*, int);
void pop(int*, int*);
void disp(int*, int*);

int main() {
        int stck[MAXSIZE], tos = -1, x = 1, c, val;
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        while (x) {
                printf("Enter choice: ");
                scanf("%d", &c);

                switch (c) {
                        case 1: printf("Enter value to push: ");
                                scanf("%d", &val);
                                push(stck, &tos, val);
                                break;
                        case 2: pop(stck, &tos); break;
                        case 3: disp(stck, &tos); break;
                        case 4: x = 0; break;
                        default: printf("Invalid option\n"); break;
                }
        }

        return 0;
}

void push(int* stck, int* tos, int val) {
        if (*tos == MAXSIZE - 1) {
                printf("Stack Overflow\n");
        } else {
                (*tos)++;
                stck[*tos] = val;
        }
}

void pop(int* stck, int* tos) {
        if (*tos == -1) {
                printf("Stack Underflow\n");
        } else {
                printf("%d\n", stck[*tos]);
                (*tos)--;
        }
}

void disp(int* stck, int* tos) {
        if (*tos == -1) {
                printf("Stack Underflow\n");
        } else {
                printf("Stack elements: ");
                for (int i = 0; i <= *tos; i++) {
                        printf("%d ", stck[i]);
                }
                printf("\n");
        }
}
