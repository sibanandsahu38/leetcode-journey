int largestInteger(int* nums, int numsSize, int k) {
    int count[51] = {0};
    for (int i = 0; i <= numsSize - k; i++) {
        int seen[51] = {0};
        for (int j = i; j < i + k; j++) seen[nums[j]] = 1;
        for (int v = 0; v <= 50; v++) count[v] += seen[v];
    }
    for (int i = 50; i >= 0; i--)
        if (count[i] == 1) return i;
    return -1;
}