#include <stdlib.h>
#include <string.h>

int* global_nums;
int compare_indices(const void* a, const void* b) {
    int val_a = global_nums[*(int*)a];
    int val_b = global_nums[*(int*)b];
    return (val_a > val_b) - (val_a < val_b); 
}

int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    int* idx = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) idx[i] = i;
    global_nums = nums;
    qsort(idx, numsSize, sizeof(int), compare_indices);
    int start = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (i == numsSize || nums[idx[i]] - nums[idx[i - 1]] > limit) {
            int len = i - start;
            int* temp_idx = (int*)malloc(len * sizeof(int));
            memcpy(temp_idx, &idx[start], len * sizeof(int));
            qsort(temp_idx, len, sizeof(int), compare_ints);
            for (int j = 0; j < len; j++) 
                ans[temp_idx[j]] = nums[idx[start + j]];
            free(temp_idx);
            start = i;
        }
    }

    free(idx);
    return ans;
}
