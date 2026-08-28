char* lexPalindromicPermutation(char* s, char* target) {
    int c[26]={},n=strlen(s),odd=0,mid=-1,k=0;
    for(int i=0;s[i];i++) c[s[i]-'a']++;
    for(int i=0;i<26;i++)
        if(c[i]%2) odd++,mid=i;
    if(odd>1) return "";
    char *a=malloc(n+1);
    int h=n/2;
    for(int i=0;i<26;i++) c[i]/=2;
    for(int p=0;p<h;p++){
        int ok=0;
        for(int x=0;x<26;x++) if(c[x]){
            c[x]--; a[p]='a'+x;
            char t[305]; int z=p+1;
            memcpy(t,a,z);
            for(int j=25;j>=0;j--)
                for(int q=0;q<c[j];q++) t[z++]='a'+j;
            if(n%2) t[z++]='a'+mid;
            for(int j=z-1;j>=0;j--)
                if(j<h) t[z++]=t[j];
            t[n]=0;
            if(strcmp(t,target)>0) ok=1;
            if(ok) break;
            c[x]++;
        }
        if(!ok) return "";
    }
    k=h;
    if(n%2)a[k++]='a'+mid;
    for(int i=h-1;i>=0;i--)a[k++]=a[i];
    a[k]=0;
    return strcmp(a,target)>0?a:"";
}