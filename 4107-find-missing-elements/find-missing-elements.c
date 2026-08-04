#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int min= nums[0];
    int max = nums[numsSize - 1];
    int max_possible_missing = (max- min + 1) - numsSize;

    if (max_possible_missing <= 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * max_possible_missing);
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) 
        for (int missing = nums[i] + 1; missing < nums[i + 1]; missing++) 
            result[count++] = missing;
    *returnSize = count;
    return result;
}