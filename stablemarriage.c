#include <stdio.h>
#include <stdbool.h>

#define N 3

bool prefers(int preferences[N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (preferences[w][i] == m1) return true;
        if (preferences[w][i] == m) return false;
    }
    return false;
}

void stableMarriage(int preferences[N][N]) {
    int womenPartner[N] = {-1, -1, -1};
    bool menFree[N] = {true, true, true};
    
    int freeCount = N;
    
    while (freeCount > 0) {
        int m;
        for (m = 0; m < N; m++) if (menFree[m]) break;
        
        for (int i = 0; i < N && menFree[m]; i++) {
            int w = preferences[m][i];
            
            if (womenPartner[w] == -1) {
                womenPartner[w] = m;
                menFree[m] = false;
                freeCount--;
            } else {
                int m1 = womenPartner[w];
                if (!prefers(preferences, w, m, m1)) {
                    womenPartner[w] = m;
                    menFree[m] = false;
                    menFree[m1] = true;
                }
            }
        }
    }
    
    printf("Stable matches:\n");
    for (int i = 0; i < N; i++) printf("Woman %d - Man %d\n", i, womenPartner[i]);
}

int main() {
    int preferences[N][N] = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };
    
    stableMarriage(preferences);
    return 0;
}
