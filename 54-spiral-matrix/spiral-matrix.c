/**
 * Return an array of integers.
 * The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int total = matrixSize * matrixColSize[0];
    int *ans = (int*)malloc(total * sizeof(int));
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;
    int k = 0;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            ans[k++] = matrix[top][j];
        top++;
        for (int i = top; i <= bottom; i++)
            ans[k++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans[k++] = matrix[bottom][j];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = k;
    return ans;
}