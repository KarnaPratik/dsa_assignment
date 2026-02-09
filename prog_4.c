#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev; //previous pointer extra hunxa doubly linked list ma
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
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
    newNode->prev = temp;
}

// Insert after a given node value
void insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Delete a node
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", key);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;  // deleting head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

//list printing hudai xa guys
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create list: 10 <-> 20 <-> 30
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Initial list: ");
    display(head);

    // Insert after 20
    insertAfter(head, 20, 25);
    printf("After inserting 25 after 20: ");
    display(head);

    // Delete node 10
    deleteNode(&head, 10);
    printf("After deleting 10: ");
    display(head);

    return 0;
}