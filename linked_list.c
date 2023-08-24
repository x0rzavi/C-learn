#include <stdio.h>
#include <stdlib.h>
typedef struct node {
        int data;
        struct node *next;
} node;
node *start = NULL, *new_node, *temp, *prev;

void create();
void insert_begn();
void insert_end();
void delete_begn();
void delete_end();
void display();

int main() {
        printf("1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. DELETE FROM BEGINNING\n");
        printf("4. DELETE FROM END\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n\n");
        
        while (1) {
                int c; printf("Enter choice: "); scanf("%d", &c);
                switch (c) {
                        case 1: insert_begn(); break;
                        case 2: insert_end(); break;
                        case 3: delete_begn(); break;
                        case 4: delete_end(); break;
                        case 5: display(); break;
                        case 6: exit(1);
                        default: printf("Wrong choice!\n");
                }
        }
        return 0;
}

void create() {
        int n; printf("Enter data: "); scanf("%d", &n);
        new_node = (node*)malloc(sizeof(node)); // malloc to init structure since new_node is pointer type variable
        new_node->data = n;
        new_node->next = NULL;
}

void insert_begn() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                new_node->next = start;
                start = new_node;
        }
}

void insert_end() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                temp = start;
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                temp->next = new_node;
        }
}

void display() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                temp = start;
                printf("Linked list elements: START -> ");
                while (temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                }
                printf("END");
        }
        printf("\n");
}

void delete_begn() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                temp = start;
                printf("Deleted: %d", temp->data);
                start = temp->next;
        }
        printf("\n");
}

void delete_end() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                int c = 1; temp = start; // keeping track of node number
                while (temp->next != NULL) {
                        prev = temp;
                        temp = temp->next;
                        c++;
                }
                printf("Deleted: %d", temp->data);
                if (c == 1) { // if 1st node
                        start = NULL;
                } else {
                        prev->next = NULL;
                }
        }
        printf("\n");
}
