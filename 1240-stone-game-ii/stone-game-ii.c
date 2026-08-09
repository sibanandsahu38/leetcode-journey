#include <string.h>

static int memo[101][101];
static int suffix[101];
static int tp;

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

static int dfs(int i, int m) {
    if (i + 2 * m >= tp) return suffix[i];
    if (memo[i][m] != 0) return memo[i][m];
    int mo = 1e9;
    int limit = 2 * m;
    for (int x = 1; x <= limit; x++) {
        int nextM = (x > m) ? x : m;
        int opponent = dfs(i + x, nextM);
        if (opponent < mo) mo = opponent;
    }
    return memo[i][m] = suffix[i] - mo;
}

int stoneGameII(int* piles, int pilesSize) {
    tp= pilesSize;
    suffix[pilesSize - 1] = piles[pilesSize - 1];
    for (int i = pilesSize - 2; i >= 0; i--) 
        suffix[i] = suffix[i + 1] + piles[i];
    for (int i = 0; i < pilesSize; i++) 
        memset(memo[i], 0, (pilesSize + 1) * sizeof(int));
    return dfs(0, 1);
}