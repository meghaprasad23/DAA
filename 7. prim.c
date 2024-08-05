#include <stdio.h>
#include <stdbool.h>

#define INF 9999999
#define V 5

int G[V][V] = {
    { 0, 4, 0, 8, 0 },
    { 4, 0, 3, 1, 0 },
    { 0, 3, 0, 7, 8 },
    { 8, 1, 7, 0, 3 },
    { 0, 0, 8, 3, 0 },
};

int main() {
    int no_edge = 0;
    int selected[V] = {0};
    selected[0] = 1;
    int total_cost = 0;  // Variable to store the total cost of the MST

    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] && G[i][j] < min) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        total_cost += G[x][y];  // Add the weight of the selected edge to total cost
        selected[y] = 1;
        no_edge++;
    }

    printf("Minimum Cost of MST: %d\n", total_cost);  // Print the total cost

    return 0;
}
