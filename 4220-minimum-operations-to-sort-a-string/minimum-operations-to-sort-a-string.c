int minOperations(char* s) {
    int n=strlen(s),c=1;
    char a=s[0],b=s[0];
    for(int i=1;i<n;i++) {
        if(s[i]<s[i-1]) c=0;
        if(s[i]<a) a=s[i];
        if(s[i]>b) b=s[i];
    }
    if(c) return 0;
    if(n==2) return -1;
    if(s[0]==a|| s[n-1]==b) return 1;
    for(int i=1;i<n-1;i++)
        if(s[i]==a || s[i]==b) return 2;
    return 3;
}