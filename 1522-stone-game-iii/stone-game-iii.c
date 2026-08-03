#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int dp1 = 0, dp2 = 0, dp3 = 0;

    for (int i = stoneValueSize - 1; i >= 0; i--) {
        int t1= stoneValue[i] - dp1;
        int t2 = -1e9;
        if (i + 1 < stoneValueSize) {
            t2= stoneValue[i] + stoneValue[i + 1] - dp2;
        }
        int t3= -1e9;
        if (i + 2 < stoneValueSize) {
            t3= stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp3;
        }
        int c= MAX(t1, MAX(t2,t3));
        dp3 = dp2;
        dp2 = dp1;
        dp1 = c;
    }
    if (dp1 > 0) return "Alice";
    if (dp1 < 0) return "Bob";
    return "Tie";
}

