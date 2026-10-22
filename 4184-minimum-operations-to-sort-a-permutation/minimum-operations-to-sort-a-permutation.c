int minOperations(int* nums, int n) {
    if(n<=1) return 0;
    int d=(nums[1]-nums[0]+n)%n;
    if(d!=1 && d!=n-1) return -1;
    for(int i=2;i<n;i++)
        if((nums[i]-nums[i-1]+n)%n!=d) return -1;
    return !*nums? (d==1 ? 0:2):(n-*nums<*nums+2 ? n-*nums:*nums+2);
}