#include <stdio.h>
#include <limits.h>

#define MAXV 100

struct Edge {
    int u, v, w;
};

// Function to find vertex with minimum distance value
int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra’s algorithm implementation
void dijkstra(int V, struct Edge edges[], int E, int src) {
    int adj[MAXV][MAXV];
    int dist[MAXV];
    int sptSet[MAXV];

    // Initialize adjacency matrix with INF
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = INT_MAX;

    // Fill adjacency matrix from edge list
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        adj[u][v] = w;
        adj[v][u] = w; // comment this line if graph is directed
    }

    // Initialize distances and sptSet[]
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    // Main loop of Dijkstra’s
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        if (u == -1) break; // No reachable vertex
        sptSet[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && adj[u][v] != INT_MAX &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print the result
    printf("\nVertex\tDistance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int V, E, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("\nEnter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("\nEnter source vertex: ");
    scanf("%d", &src);

    dijkstra(V, edges, E, src);

    return 0;
}
