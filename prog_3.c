#include <stdio.h>
#include <stdlib.h>

// Linked list ko euta node
struct Node {
    int data;
    struct Node* next;
};

// New node creation
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Reverse traversal. Using recursion
void reverseTraversal(struct Node* head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next);
    printf("%d ", head->data);
}

// Suru ma normal display garne
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Normal Traversal: ");
    display(head);

    printf("\nReverse Traversal: ");
    reverseTraversal(head);

    return 0;
}