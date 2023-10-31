#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int data;
        struct node *next;
        struct node *prev;
} node;
node *start = NULL, *new_node = NULL, *temp = NULL, *prev = NULL, *next = NULL;

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
void search();
void sort();
void rev();
void display();
int count();

int main() {
        printf(" 1. Insert at Beginning\n");
        printf(" 2. Insert at End\n");
        printf(" 3. Insert before Node\n");
        printf(" 4. Insert after Node\n");
        printf(" 5. Insert at Position\n");
        printf(" 6. Delete from Beginning\n");
        printf(" 7. Delete from End\n");
        // printf(" 8. Delete before Node\n");
        // printf(" 9. Delete after Node\n");
        // printf("10. Delete at Position\n");
        // printf("11. Search\n");
        // printf("12. Sort\n");
        // printf("13. Reverse\n");
        printf("14. Display\n");
        printf("15. Count\n");
        printf("16. Exit\n");
        while (1) {
                int c; printf("\nEnter choice: "); scanf("%d", &c);
                switch (c) {
                        case 1: insert_begn(); break;
                        case 2: insert_end(); break;
                        case 3: insert_bef(); break;
                        case 4: insert_aft(); break;
                        case 5: insert_pos(); break;
                        case 6: delete_begn(); break;
                        case 7: delete_end(); break;
                        // case 8: delete_bef(); break;
                        // case 9: delete_aft(); break;
                        case 14: display(); break;
                        case 15: count(); break;
                        case 16: printf("Goodbye!\n"); exit(1);
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
        new_node->prev = NULL;
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

int count() {
        int c = 0;
        temp = start;
        while (temp != NULL) {
                c++;
                temp = temp->next;
        }
        printf("Item count: %d\n", c);
        return c;
}

void insert_begn() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                new_node->next = start;
                start->prev = new_node;
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
                new_node->prev = temp;
        }
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
        } else if (temp->prev == NULL) { // only 1 node found
                insert_begn();
        } else {
                create();
                prev->next = new_node;
                new_node->prev = prev;
                new_node->next = temp;
                temp->prev = new_node;
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
                new_node->prev = temp;
                temp->next = new_node;
                temp->next->prev = new_node;
        }
}

void insert_pos() {
        int c = count();
        int pos; printf("Enter position to insert at: "); scanf("%d", &pos);
        if (pos == 1) {
                insert_begn();
        } else if (pos == c) {
                insert_end();
        } else if (pos > 1 && pos < c) {
                int i = 1;
                temp = start;
                while (temp != NULL && i < pos - 1) { // iterating upto pos - 1 times; just before node to insert before
                        temp = temp->next;
                        i++;
                }
                create();
                new_node->next = temp->next; // inserting before node
                new_node->prev = temp;
                temp->next = new_node;
                temp->next->prev = new_node;
        } else {
                printf("Invalid postion!\n");
        }
}

void delete_begn() {
        if (start == NULL) {
                printf("Underflow!\n");
        } else {
                temp = start;
                printf("Deleted: %d\n", temp->data);
                start = temp->next;
                free(temp);
        }
}

void delete_end() {
        if (start == NULL) {
                printf("Underflow!\n");
        } else {
                if (start->next == NULL) { // check if only 1 node
                        printf("Deleted: %d\n", start->data);
                        start = NULL;
                } else {
                        temp = start;
                        while (temp->next != NULL) {
                                prev = temp;
                                temp = temp->next;
                        }
                        printf("Deleted: %d\n", temp->data);
                        prev->next = NULL;
                        free(temp);
                }
        }
}

// void delete_bef() {
//         if (start == NULL) {
//                 printf("Underflow!");
//         } else {
//                 int data; printf("Enter data item to delete before: "); scanf("%d", &data);
//                 temp = start;
//                 while (temp != NULL && temp->next->data != data) {
//                         prev = temp;
//                         temp = temp->next;
//                 }
//                 if (temp == NULL) {
//                         printf("Data item %d not found!\n", data);
//                 } else if (temp->prev == NULL) { // only 2 nodes found
//                         delete_begn();
//                 } else {
//                         printf("Deleted: %d\n", temp->data);
//                         temp->next->prev = prev;
//                         prev->next = temp->next;
//                         free(temp);
//                 }
//         }
// }
//
// void delete_aft() {
//         if (start == NULL) {
//                 printf("Underflow!");
//         } else {
//                 int data; printf("Enter data item to delete after: "); scanf("%d", &data);
//                 temp = start;
//                 while (temp != NULL && temp->data != data) {
//                         temp = temp->next;
//                 }
//                 if (temp == NULL) {
//                         printf("Data item %d not found!\n", data);
//                 } else {
//                         next = temp->next;
//                         printf("Deleted: %d\n", next->data);
//                         next->next = temp->next;
//                         free(temp);
//                 }
//         }
// }
