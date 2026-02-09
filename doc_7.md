### Question:

Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.

### Solution:

## (a) Data Structures used:

Graph: adjacency matrix graph[MAX][MAX] stores weights of edges.

dist[]: array to store shortest distance from source vertex to each vertex.

visited[]: array to track visited vertices.

## (b) Function description feri

minDistance(int dist[], int visited[], int n)
Returns the index of the unvisited vertex with the smallest distance.

dijkstra(int graph[MAX][MAX], int n, int src)
Implements Dijkstra’s algorithm to compute shortest distances from the source vertex to all others.
Prints the distances at the end.

## (c) Overview of main()

Initializes a weighted graph as an adjacency matrix.

Defines the source vertex.

Calls dijkstra() to compute shortest paths.

Prints the result.

## (d) Sample Output:

Vertex  Distance from Source 0
0       0
1       7
2       8
3       7
4       5