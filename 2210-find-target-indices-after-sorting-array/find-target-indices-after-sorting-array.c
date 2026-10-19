int c(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int* targetIndices(int* nums,int n, int t,int* r){
    qsort(nums,n,sizeof(int),c);
    int *s=malloc(n*sizeof(int));
    *r=0;
    for(int i=0;i<n;i++)
        if(nums[i]==t)
            s[(*r)++]=i;
    return s;
}