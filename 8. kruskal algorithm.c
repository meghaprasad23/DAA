#include <stdio.h>

#define INF 999
#define MAX 9

int cost[MAX][MAX], parent[MAX];
int n, mincost = 0;

int find(int i);
int unionSets(int i, int j);

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF;
        }

    printf("\nEdges of Minimum Cost Spanning Tree:\n");
    for (int ne = 1; ne < n; ) {
        int min = INF, a = -1, b = -1;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }

        int u = find(a);
        int v = find(b);

        if (unionSets(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}

int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}
