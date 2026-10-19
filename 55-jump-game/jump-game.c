bool canJump(int* nums,int n) {
    int i=0,t=0;
    while(i<=t && i<n){
        if(i+nums[i]>t) t=i+nums[i];
        i++;
    }
    return t>=n-1;
}