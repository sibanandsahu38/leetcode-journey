#include <stdio.h>
#include <stdlib.h>
static inline long long fast_gcd(long long u, long long v) {
    if (u == 0) return v;
    if (v == 0) return u;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do {
        v >>= __builtin_ctzll(v);
        if (u > v) {
            long long temp = u;
            u = v;
            v = temp;
        }
        v -= u;
    } while (v != 0);
    return u << shift;
}
static int compare_desc(const void* a, const void* b) {
    int v1 = *(const int*)a;
    int v2 = *(const int*)b;
    if (v1 < v2) return 1;
    if (v1 > v2) return -1;
    return 0;
}
long long maxPairStrength(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_desc);
    int n = 0;
    for (int i = 0; i < numsSize; i++) {
        if (n >= 2 && nums[i] == nums[n - 1] && nums[i] == nums[n - 2]) {
            continue;
        }
        nums[n++] = nums[i];
    }
    long long max_strength = 0;
    for (int i = 0; i < n - 1; i++) {
        long long num_i = nums[i];
        if (num_i * nums[i + 1] <= max_strength) {
            break;
        }
        for (int j = i + 1; j < n; j++) {
            long long num_j = nums[j];
            long long prod = num_i * num_j;
            if (prod <= max_strength) {
                break;
            }
            long long g = fast_gcd(num_i, num_j);
            long long strength = prod / (g * g);

            if (strength > max_strength)
                max_strength = strength;
        }
    }

    return max_strength;
}