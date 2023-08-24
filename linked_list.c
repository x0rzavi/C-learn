#include <stdio.h>
#include <stdlib.h>
typedef struct node {
        int data;
        struct node *next;
} node;
node *start = NULL, *new_node, *temp = NULL, *prev = NULL;

void create();
void insert_begn();
void insert_end();
void insert_bef();
void insert_aft();
void insert_pos();
void delete_begn();
void delete_end();
void delete_bef();
void delete_aft();
void delete_pos();
void display();
void count();

int main() {
        printf("1. INSERT AT BEGINNING\n");
        printf("2. INSERT AT END\n");
        printf("3. DELETE FROM BEGINNING\n");
        printf("4. DELETE FROM END\n");
        printf("5. INSERT BEFORE NODE\n");
        printf("6. INSERT AFTER NODE\n");
        printf("7. INSERT AT POSITION\n");
        printf("8. DELETE BEFORE NODE\n");
        printf("9. DELETE AFTER NODE\n");
        printf("10. DELETE AT POSITION\n");
        printf("11. DISPLAY\n");
        printf("12. COUNT ITEMS\n");
        printf("13. EXIT\n");
        
        while (1) {
                int c; printf("\nEnter choice: "); scanf("%d", &c);
                switch (c) {
                        case 1: insert_begn(); break;
                        case 2: insert_end(); break;
                        case 3: delete_begn(); break;
                        case 4: delete_end(); break;
                        case 5: insert_bef(); break;
                        case 6: insert_aft(); break;
                        case 11: display(); break;
                        case 12: count(); break;
                        case 13: exit(1);
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

void count() {
        int c = 0;
        temp = start;
        while (temp != NULL) {
                c++;
                temp = temp->next;
        }
        printf("Item count: %d\n", c);
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
                if (start->next == NULL) { // check if 1st node
                        printf("Deleted: %d", start->data);
                        start = NULL;
                } else {
                        temp = start;
                        while (temp->next != NULL) {
                                prev = temp;
                                temp = temp->next;
                        }
                        printf("Deleted: %d", temp->data);
                        prev->next = NULL;
                }
        }
        printf("\n");
}

void insert_bef() {
        int data; printf("Enter data item to insert before: "); scanf("%d", &data);
        temp = start;
        while (temp != NULL && temp->data != data) {
                prev = temp;
                temp = temp->next;
        }
        if (temp == NULL) {
                printf("Data item %d not found!\n", data);
        } else if (!prev) { // if prev is not defined insert at beginning
                insert_begn();
        } else {
                create();
                new_node->next = prev->next;
                prev->next = new_node;
        }

}

void insert_aft() {
        int data; printf("Enter data item to insert after: "); scanf("%d", &data);
        temp = start;
        while (temp != NULL && temp->data != data) {
                temp = temp->next;
        }
        if (temp == NULL) {
                printf("Data item %d not found!\n", data);
        } else {
                create();
                new_node->next = temp->next;
                temp->next = new_node;
        }
}

