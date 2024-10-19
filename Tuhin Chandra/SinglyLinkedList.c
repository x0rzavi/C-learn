//Single linked List create, insert at last, insert at begin, display, delete
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtHead(struct Node** head, struct Node** tail, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } 
    else {
        temp->next = *head;
        *head = temp;
    }
}

void insertAtTail(struct Node** head, struct Node** tail, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        *tail = temp;
    } 
    else {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(int position, struct Node** head, struct Node** tail) {
    //deleting the starting node
    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    } 
    else {
        struct Node* curr = *head;
        struct Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
        if (prev->next == NULL)
            *tail = prev;
    }
}

int main() {
    printf("Perform the Linked List operations:\n");
    int choice, val,pos;
    struct Node* head = NULL;
    struct Node* tail = NULL;
    do {
        printf("1 for Insert at begin\n2 for Insert at end\n3 for Delete\n4 for Display\n5 To exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertAtHead(&head, &tail, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertAtTail(&head, &tail, val);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteNode(pos, &head, &tail);
                break;
            case 4:
                display(head);
                break;
            case 5:
                break;
            default:
                printf("Enter correct choices !!\n");
        }
    } while (choice != 5);

    // Free memory for all nodes before exiting
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
