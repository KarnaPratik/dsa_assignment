#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];       // Source vandaa sab vanda shortest point chahiyeko
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < n-1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Shortest distances haru print vayo
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {0};

    // Example weighted graph (undirected)
    // Graph edges with weights:
    // 0-1: 10, 0-4: 5
    // 1-2: 1, 1-4: 2
    // 2-3: 4
    // 3-0: 7, 3-2: 6
    // 4-1: 3, 4-2: 9, 4-3: 2
    graph[0][1] = 10; graph[1][0] = 10;
    graph[0][4] = 5;  graph[4][0] = 5;
    graph[1][2] = 1;  graph[2][1] = 1;
    graph[1][4] = 2;  graph[4][1] = 2;
    graph[2][3] = 4;  graph[3][2] = 4;
    graph[3][0] = 7;  graph[0][3] = 7;
    graph[4][2] = 9;  graph[2][4] = 9;
    graph[4][3] = 2;  graph[3][4] = 2;

    int source = 0;
    dijkstra(graph, n, source);

    return 0;
}