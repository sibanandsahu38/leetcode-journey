int maximumLengthSubstring(char* s) {
    int a[26]={0},l=0,r=0,an=0;
    while(s[r]){
        a[s[r]-'a']++;
        while(a[s[r]-'a']>2)a[s[l++]-'a']--;
        if(r-l+1>an) an=r-l+1;
        r++;
    }
    return an;
    
}