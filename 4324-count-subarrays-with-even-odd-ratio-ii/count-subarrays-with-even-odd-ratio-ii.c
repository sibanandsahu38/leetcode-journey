#include <stdio.h>
#include <stdlib.h>

static int compareLongLong(const void* a, const void* b) {
    long long d= *(const long long*)a - *(const long long*)b;
    if (d<0) return -1;
    if (d>0) return 1;
    return 0;
}
static inline int rank(const long long* sorted, int size, long long val) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sorted[mid] == val) return mid + 1;
        if (sorted[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return low + 1;
}
static inline void add(int* bit, int size, int idx, int val) {
    for (; idx <= size; idx += idx & -idx)
        bit[idx] += val;
}
static inline int query(const int* bit, int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}
long long countRatioSubarrays(int* nums, int numsSize, int a, int b){
    int n = numsSize;
    if (n <= 3000) {
        long long ans = 0;
        long long b_val = b;
        long long a_val = a;

        for (int i = 0; i < n; i++) {
            long long delta = 0;
            int odds = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] & 1) {
                    odds++;
                    delta -= a_val;
                }else
                    delta += b_val;

                if (odds > 0 && delta <= 0) ans++;
            }
        }
        return ans;
    }
    long long* V = (long long*)malloc((n + 1) * sizeof(long long));
    long long* temp = (long long*)malloc((n + 1) * sizeof(long long));
    V[0] = 0;
    temp[0] = 0;
    long long pe = 0, po = 0;
    long long a_ll = a, b_ll = b;
    for (int i = 0; i < n; i++) {
        if ((nums[i] & 1) == 0) pe++;
        else po++;
        V[i + 1] = b_ll * pe - a_ll * po;
        temp[i + 1] = V[i + 1];
    }
    qsort(temp, n + 1, sizeof(long long), compareLongLong);
    int u = 0;
    for (int i = 0; i <= n; i++)
        if (i == 0 || temp[i] != temp[i - 1])
            temp[u++] = temp[i];
    int* bit = (int*)calloc(u + 1, sizeof(int));
    long long valid_count = 0;
    int last_inserted_l = -1;
    for (int R = 1; R <= n; R++) {
        if (nums[R - 1] & 1) {
            for (int l = last_inserted_l + 1; l <= R - 1; l++) {
                int rk = rank(temp, u, V[l]);
                add(bit, u, rk, 1);
            }
            last_inserted_l = R - 1;
        }

        int rr = rank(temp, u, V[R]);
        valid_count +=query(bit, u) -query(bit, rr - 1);
    }
    free(V);
    free(temp);
    free(bit);
    return valid_count;
}