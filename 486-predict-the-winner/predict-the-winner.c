#include <stdbool.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool predictTheWinner(int* nums, int numsSize) {
    if (numsSize % 2 == 0) return true;
    int dp[numsSize][numsSize];
    for (int i = 0; i < numsSize; i++) dp[i][i] = nums[i];
    for (int length = 2; length <= numsSize; length++)
        for (int i = 0; i <= numsSize - length; i++) {
            int j = i + length - 1;
            int pl = nums[i] - dp[i + 1][j];
            int pr = nums[j] - dp[i][j - 1];
            dp[i][j] = MAX(pl, pr);
        }
    return dp[0][numsSize - 1] >= 0;
}
