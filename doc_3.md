### Question:

3. Write and Implement the reverse traversal algorithm in the linked list. Write main() to demonstrate the use of the function.

### Solution:

## (a) Data structure define:

A singly linked list is used.

Each node is defined using a structure containing: an integer for data and next pointer to point to the next node.

The list is accessed using a pointer called head.

## (b) Function k k xa:

createNode(int data)
Creates a new node, assigns data to it, sets the next pointer to NULL, and returns the node.

insertEnd(struct Node** head, int data)
Inserts a new node at the end of the linked list.

display(struct Node* head)
Traverses the linked list from head to last node and prints all elements in normal order.

reverseTraversal(struct Node* head)
Prints the linked list elements in reverse order using recursion.
It first calls itself with the next node and prints the data while returning from the recursive calls.

## (c) main() here:

Initializes the head pointer to NULL.

Inserts multiple nodes into the linked list.

Displays the list in normal order.

Calls the reverseTraversal function to display the list in reverse order.

## (d) Sample Output:

Normal Traversal: 10 20 30 40 

Reverse Traversal: 40 30 20 10 