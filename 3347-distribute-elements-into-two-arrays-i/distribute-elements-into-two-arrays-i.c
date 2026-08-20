/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int n, int* r) {
    int *a = malloc(n * 4), *b = malloc(n * 4), s1 = 1, s2 = 1;
    a[0] = nums[0], b[0] = nums[1];
    for (int i = 2; i < n; i++)
        if (a[s1 - 1] > b[s2 - 1]) a[s1++] = nums[i];
        else b[s2++] = nums[i];
    for (int i = 0; i < s2; i++) a[s1++] = b[i];
    return *r = n, free(b), a;
}