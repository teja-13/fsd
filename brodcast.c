#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int adjacencyMatrix[MAX][MAX];
int numNodes;
bool visited[MAX];

// Function to perform BFS and print broadcast tree
void broadcastTree(int rootNode) {
    int queue[MAX], front = 0, rear = 0;
    int i, currentNode;

    // Initialize visited array
    for (i = 1; i <= numNodes; i++)
        visited[i] = false;

    // Start from root node
    queue[rear++] = rootNode;
    visited[rootNode] = true;

    printf("\nBroadcast Tree starting from node %d:\n", rootNode);

    while (front < rear) {
        currentNode = queue[front++];
        printf("%d -> ", currentNode);

        // Traverse all adjacent nodes
        for (i = 1; i <= numNodes; i++) {
            if ((adjacencyMatrix[currentNode][i] == 1 || adjacencyMatrix[i][currentNode] == 1) && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }

    printf("END\n");
}

int main() {
    int i, j, rootNode;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= numNodes; i++) {
        for (j = 1; j <= numNodes; j++) {
            printf("Is there a connection from node %d to node %d (1=yes, 0=no): ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Input root node
    printf("Enter root node (1 to %d): ", numNodes);
    scanf("%d", &rootNode);

    // Display broadcast tree
    broadcastTree(rootNode);

    return 0;
}
