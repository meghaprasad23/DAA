#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>

#define INF 999
#define N 5

int a[N][N] = {
    {INF,  2, INF, 12,  5},
    {  2, INF,  4,  8, INF},
    {INF,  4, INF,  3,  3},
    {12,  8,  3, INF, 10},
    {  5, INF,  3, 10, INF}
};

int min_cost = INT_MAX;
int best_path[N];
bool visited[N];

void TSP(int city, int count, int cost, int path[]) {
    if (count == N) {
        if (a[city][0] < INF && cost + a[city][0] < min_cost) {
            min_cost = cost + a[city][0];
            memcpy(best_path, path, N * sizeof(int));
        }
        return;
    }

    for (int next = 0; next < N; next++) {
        if (!visited[next] && a[city][next] < INF) {
            visited[next] = true;
            path[count] = next;
            TSP(next, count + 1, cost + a[city][next], path);
            visited[next] = false;
        }
    }
}

int main() {
    printf("Cost matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%3d ", a[i][j]);
        printf("\n");
    }

    int path[N] = {0};
    visited[0] = true;
    TSP(0, 1, 0, path);

    printf("\nOptimal Path: ");
    for (int i = 0; i < N; i++)
        printf("%d -> ", best_path[i] + 1);
    printf("1\n");

    printf("Minimum cost: %d\n", min_cost);
    return 0;
}
