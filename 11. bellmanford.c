#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_EDGES 1000

typedef struct {
    char src, dest;
    int weight;
} Edge;

int getIndex(char c) {
    return c - 'a';
}

void bellmanFord(Edge edges[], int V, int E, char src) {
    int distance[V];
    int srcIndex = getIndex(src);

    for (int i = 0; i < V; i++)
        distance[i] = INF;
    distance[srcIndex] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = getIndex(edges[j].src);
            int v = getIndex(edges[j].dest);
            if (distance[u] != INF && distance[u] + edges[j].weight < distance[v])
                distance[v] = distance[u] + edges[j].weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = getIndex(edges[i].src);
        int v = getIndex(edges[i].dest);
        if (distance[u] != INF && distance[u] + edges[i].weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%c \t\t %d\n", 'a' + i, distance[i]);
}

int main() {
    int V = 6, E = 10;

    Edge edges[MAX_EDGES] = {
        {'a', 'b', -4}, {'a', 'f', -3}, {'b', 'd', -1}, {'b', 'e', -2},
        {'c', 'b', 8},  {'c', 'f', 3},  {'d', 'a', 6},  {'d', 'f', 4},
        {'e', 'c', -3}, {'e', 'f', 2}
    };

    bellmanFord(edges, V, E, 'a');
    return 0;
}
