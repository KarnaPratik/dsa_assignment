#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

// Enqueue function
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Function to dequeue
int dequeue() {
    if (front == -1) return -1;
    int v = queue[front++];
    if (front > rear) front = rear = -1;
    return v;
}

// BFS ma dulne kasari? Traversal function
void BFS(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front != -1) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS ma dulne kasari? Traversal feri tara recursive chahi
void DFSUtil(int graph[][MAX], int n, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFSUtil(graph, n, i, visited);
    }
}

void DFS(int graph[][MAX], int n, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(graph, n, start, visited);
    printf("\n");
}

int main() {
    int n = 5; // number of vertices
    int graph[MAX][MAX] = {0};

    // Example undirected graph
    // edges: 0-1, 0-2, 1-2, 1-3, 3-4
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[3][4] = graph[4][3] = 1;

    BFS(graph, n, 0);
    DFS(graph, n, 0);

    return 0;
}