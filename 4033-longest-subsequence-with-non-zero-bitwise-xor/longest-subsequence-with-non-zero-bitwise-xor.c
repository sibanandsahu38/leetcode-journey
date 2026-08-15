int longestSubsequence(int*a,int n){
    int x=0,i;
    for(i=0;i<n;i++)x^=a[i];
    if(x) return n;
    for(i=0;i<n;i++)
    if(a[i]) return n-1;
    return 0;
}