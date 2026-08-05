#include <stdio.h>
#include <stdlib.h>
static int count_completed(long long* P, int n, long long t) {
    int l=0, h = n - 1;
    int c = 0;
    
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (P[m] <= t) {
            c= m+ 1;
            l= m + 1;
        } else
            h=m-1;
    }
    return c;
}
int* countTasks(int* tasks, int tasksSize, int* shifts, int shiftsSize, int* returnSize) {
    int n = tasksSize;
    int m = shiftsSize;
    long long* P = (long long*)malloc(n * sizeof(long long));
    P[0] = tasks[0];
    for (int i = 1; i < n; i++) P[i] = P[i - 1] + tasks[i];
    long long total_work = P[n - 1];
    int* ans = (int*)malloc(m * sizeof(int));
    *returnSize = m;
    long long curr_work = 0;
    for (int j = 0; j < m; j++) {
        curr_work += shifts[j];
        if (curr_work >= total_work) {
            ans[j] = 0;
            curr_work = 0;
        } else {
            int completed = count_completed(P, n, curr_work);
            ans[j] = n - completed;
        }
    }
    free(P);
    return ans;
}