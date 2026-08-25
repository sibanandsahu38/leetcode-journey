int missingMultiple(int* nums, int numsSize, int k) {
    int s= k;
    for (int i = 0;i<numsSize;i++)
        if (nums[i]==s) {
            s+=k; 
            i = -1;
        }    
    return s;
}