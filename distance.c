#include <stdio.h>

struct RoutingTable {
    unsigned distance[20];
    unsigned nextHop[20];
} rt[10];

int main() {
    int costMatrix[20][20], numNodes = 4, i, j, k, updated;

    // Sample subnet graph with weights (delays)
    // Nodes: 1, 2, 3, 4
    // Delay between nodes:
    //    0  3  5  INF
    //    3  0  INF 1
    //    5  4  0  2
    //    INF 1  2  0
    int INF = 99;
    int sample[4][4] = {
        {0, 3, 5, INF},
        {3, 0, INF, 1},
        {5, 4, 0, 2},
        {INF, 1, 2, 0}
    };

    printf("\nUsing sample subnet graph with %d nodes\n", numNodes);

    // Initialize costMatrix and routing table
    for(i = 0; i < numNodes; i++){
        for(j = 0; j < numNodes; j++){
            costMatrix[i][j] = sample[i][j];
            rt[i].distance[j] = costMatrix[i][j];
            rt[i].nextHop[j] = j;
        }
    }

    // Distance Vector Routing Algorithm
    do{
        updated = 0;
        for(i = 0; i < numNodes; i++){
            for(j = 0; j < numNodes; j++){
                for(k = 0; k < numNodes; k++){
                    if(rt[i].distance[j] > costMatrix[i][k] + rt[k].distance[j]){
                        rt[i].distance[j] = costMatrix[i][k] + rt[k].distance[j];
                        rt[i].nextHop[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while(updated);

    // Display routing tables
    for(i = 0; i < numNodes; i++){
        printf("\nRouting Table for Router %d:\n", i+1);
        printf("Destination\tNext Hop\tDistance\n");
        for(j = 0; j < numNodes; j++){
            printf("     %d\t\t   %d\t\t   %d\n", j+1, rt[i].nextHop[j]+1, rt[i].distance[j]);
        }
    }
    printf("\n");
    return 0;
}
