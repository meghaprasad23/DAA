#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int parent[100], rank[100];

int find(int i) {
    return parent[i] == i ? i : (parent[i] = find(parent[i]));
}

void unionSets(int u, int v) {
    int rootU = find(u), rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
        else parent[rootU] = rootV, rank[rootU] += (rank[rootU] == rank[rootV]);
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int numEdges, int numVertices) {
    Edge mst[100];
    int mstSize = 0, totalCost = 0;

    for (int i = 0; i < numVertices; i++) parent[i] = i, rank[i] = 0;

    qsort(edges, numEdges, sizeof(Edge), compare);

    for (int i = 0; i < numEdges && mstSize < numVertices - 1; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            mst[mstSize++] = edges[i];
            totalCost += edges[i].weight;
            unionSets(u, v);
        }
    }

    printf("Edges in the MST:\n");
    for (int i = 0; i < mstSize; i++)
        printf("%d - %d: %d\n", mst[i].u + 1, mst[i].v + 1, mst[i].weight);
    printf("Total cost: %d\n", totalCost);
}

int main() {
    int numVertices = 5, numEdges = 7;
    Edge edges[] = {{0, 1, 10}, {0, 4, 5}, {1, 2, 1}, {2, 3, 2}, {3, 4, 3}, {4, 2, 6}, {4, 1, 7}};
    kruskal(edges, numEdges, numVertices);
    return 0;
}
