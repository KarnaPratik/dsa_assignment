### Question:

How can we implement the doubly linked list using structure? Write a method to
insert(after given node) and delete the node in a doubly linked list. Write main() to demonstrate the use of the functions.

### Solution:

## (a) Explanation of Data Structure

A doubly linked list is implemented using a structure.

Each node contains three fields:

an integer data

a pointer prev pointing to the previous node

a pointer next pointing to the next node

The list is accessed using a pointer called head.

## (b) Function yaaha xa

createNode(int data)
Allocates memory for a new node, initializes its data, and sets both pointers to NULL.

insertEnd(struct Node** head, int data)
Inserts a new node at the end of the doubly linked list.

insertAfter(struct Node* head, int key, int data)
Inserts a new node after the node containing the given key value.
Updates both next and prev pointers to maintain the list structure.

deleteNode(struct Node** head, int key)
Deletes the node containing the given key value.
Handles deletion of the head node as well as middle or last nodes.

display(struct Node* head)
Traverses the list from head to last node and prints the data elements.

## (c) main() explain:

Initializes the head pointer to NULL.

Inserts nodes into the doubly linked list.

Displays the initial list.

Calls the insertAfter function to insert a new node after a given node.

Calls the deleteNode function to delete a node.

Displays the list after each operation.

## (d) Sample Output:

Initial list: 10 20 30 

After inserting 25 after 20: 10 20 25 30 

After deleting 10: 20 25 30 
