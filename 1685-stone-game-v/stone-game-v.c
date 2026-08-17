#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int memo[501][501], pref[501];

int dfs(int i, int j) {
    if (i >= j) return 0;
    if (memo[i][j]) return memo[i][j];

    int res = 0, total = pref[j + 1] - pref[i];
    for (int k = i; k < j; k++) {
        int l = pref[k + 1] - pref[i], r = total - l;
        int score = MAX(l <= r ? l + dfs(i, k) : 0, 
                        r <= l ? r + dfs(k + 1, j) : 0);
        res = MAX(res, score);
    }
    return memo[i][j] = res;
}

int stoneGameV(int* stones, int n) {
    memset(memo, 0, sizeof(memo));
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stones[i];
    return dfs(0, n - 1);
}