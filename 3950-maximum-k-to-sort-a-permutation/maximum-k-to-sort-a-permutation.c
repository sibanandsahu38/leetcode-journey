int sortPermutation(int* nums,int n) {
    int k=-1;
    while(n--) if(n!=nums[n]) k&=nums[n];
    return k<0 ? 0:k;
}