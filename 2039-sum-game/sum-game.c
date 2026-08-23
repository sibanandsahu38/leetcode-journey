bool sumGame(char* num) {
    int d=0,q=0,n=strlen(num);
    for(int i=0;i<n;i++) {
        int c=(i<n/2) ? 1:-1;
        if(num[i]=='?') q+=c;
        else d+=c*(num[i]-'0');
    }
    return 2*d+9*q !=0;
    
}