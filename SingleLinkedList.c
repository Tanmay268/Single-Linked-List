//SLL
//Tanmay Kaushik
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

void insertAtBeginning(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtMiddle(Node** head, int value, int pos) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtFront(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
}

void deleteAtEnd(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (pos == 1) {
        deleteAtFront(head);
        return;
    }
    Node* prev = NULL;
    for (int i = 1; i < pos && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == *head && pos != 1) return;
    prev->next = temp->next;
    free(temp);
}

void deleteByValue(Node** head, int value) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (temp->data == value) {
        deleteAtFront(head);
        return;
    }
    Node* prev = NULL;
    while (temp->next != *head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data == value) {
        prev->next = temp->next;
        free(temp);
    }
}

int search(Node* head, int value) {
    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);
    return -1;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, value, pos;

    printf("Menu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Middle\n");
    printf("4. Delete at Front\n");
    printf("5. Delete at End\n");
    printf("6. Delete at Position\n");
    printf("7. Delete by Value\n");
    printf("8. Search\n");
    printf("9. Display\n");
    printf("10. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value to insert at middle and position: ");
                scanf("%d %d", &value, &pos);
                insertAtMiddle(&head, value, pos);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                pos = search(head, value);
                if (pos == -1) {
                    printf("Value not found\n");
                } else {
                    printf("Value found at position: %d\n", pos);
                }
                break;
            case 9:
                display(head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 10);

    return 0;
}
