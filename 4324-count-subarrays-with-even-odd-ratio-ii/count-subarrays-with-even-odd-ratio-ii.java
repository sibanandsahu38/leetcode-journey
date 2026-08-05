import java.util.Arrays;

public class Solution {
    
    private static long mergeSort(long[] arr, int left, int right, long[] slot) {
        long cnt = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            cnt += mergeSort(arr, left, mid, slot);
            cnt += mergeSort(arr, mid + 1, right, slot);
            
            int i = left;
            int indices = mid + 1;
            int cand = left;
            
            while (i <= mid && indices <= right) {
                if (arr[i] >= arr[indices]) {
                    cnt += (mid - i + 1);
                    slot[cand++] = arr[indices++];
                } else {
                    slot[cand++] = arr[i++];
                }
            }
            
            while (i <= mid) {
                slot[cand++] = arr[i++];
            }
            
            while (indices <= right) {
                slot[cand++] = arr[indices++];
            }
            
            for (i = left; i <= right; i++) {
                arr[i] = slot[i];
            }
        }
        return cnt;
    }

    public static long countRatioSubarrays(int[] nums, int a, int b) {
        int numsSize = nums.length;
        long[] P = new long[numsSize + 1];
        long[] slot = new long[numsSize + 1];
        
        P[0] = 0;
        for (int i = 0; i < numsSize; i++) {
            long val = (nums[i] % 2 == 0) ? b : -a;
            P[i + 1] = P[i] + val;
        }
        return mergeSort(P, 0, numsSize, slot);
    }
}
