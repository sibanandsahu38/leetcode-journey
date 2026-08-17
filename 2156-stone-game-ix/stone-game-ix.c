#include <stdbool.h>
#include <stdlib.h>
bool stoneGameIX(int* stones, int stonesSize) {
    int c[3] = {0};
    for (int i = 0; i < stonesSize; i++) {
        c[stones[i] % 3]++;
    }
    return c[0] % 2 == 0 ? (c[1] && c[2]) : (abs(c[1] - c[2]) > 2);
}