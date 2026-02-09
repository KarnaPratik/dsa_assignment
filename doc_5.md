### Question:

How can we implement the undirected graph using the adjacency matrix? Write a function that implements the BFS and DFS technique to traverse through the graph. Demonstrate the use of your program with an example graph.

### Solution:

## (a) Explanation of Data Structures

The graph is represented using an adjacency matrix, a 2D array graph[MAX][MAX].

A queue array is used for BFS traversal.

An array visited[] keeps track of visited vertices for both BFS and DFS.

## (b) Function aaudai xa:

enqueue(int v)
Adds a vertex to the queue for BFS.

dequeue()
Removes and returns a vertex from the queue for BFS.

BFS(int graph[][MAX], int n, int start)
Performs Breadth-First Search starting from the given vertex.
Uses a queue and visited array.

DFSUtil(int graph[][MAX], int n, int v, int visited[])
Recursive helper function for DFS. Prints vertices in depth-first order.

DFS(int graph[][MAX], int n, int start)
Initializes visited array and calls DFSUtil to perform Depth-First Search.

## (c) Overview of main()

Initializes an example graph with 5 vertices.

Adds edges to the adjacency matrix.

Calls BFS and DFS functions to traverse the graph starting from vertex 0.

Prints BFS and DFS traversal order.

## (d) Sample Output:

BFS Traversal: 0 1 2 3 4 

DFS Traversal: 0 1 2 3 4 