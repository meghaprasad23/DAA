#include <stdio.h>

#define MAX_ITEMS 4
#define MAX_WEIGHT 7

int weights[MAX_ITEMS] = {3, 5, 6, 2};
int values[MAX_ITEMS] = {10, 4, 9, 11};

void knapsack(int W, int n, int weights[], int values[]) {
    int dp[MAX_ITEMS+1][MAX_WEIGHT+1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = dp[i-1][w] > (dp[i-1][w-weights[i-1]] + values[i-1]) ? dp[i-1][w] : (dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("Maximum value in Knapsack = %d\n", dp[n][W]);

    int w = W;
    printf("Items included:\n");
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i, weights[i-1], values[i-1]);
            w -= weights[i-1];
        }
    }
}

int main() {
    int W = 7;
    int n = 4;

    knapsack(W, n, weights, values);

    return 0;
}
