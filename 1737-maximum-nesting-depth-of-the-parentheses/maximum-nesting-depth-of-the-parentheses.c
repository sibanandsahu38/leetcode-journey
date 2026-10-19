int maxDepth(char* s) {
    int i=0,c=0,t=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='(') c++;
        if(s[i]==')') c--;
        t=(t<c)? c:t;
    }
    return t;
}