char* lexGreaterPermutation(char* s, char* t) {
    int n = strlen(s), cnt[26] = {0}, i, j, k;
    for (i = 0; i < n; i++) cnt[s[i] - 'a']++;
    for (i = 0; i < n; i++) {
        if (cnt[t[i] - 'a'] == 0) break;
        cnt[t[i] - 'a']--;
    }
    while (i >= 0) {
        if (i < n)
            for (j = t[i] - 'a' + 1; j < 26; j++)
                if (cnt[j]) {
                    char *ans = malloc(n + 1);
                    memcpy(ans, t, i);
                    ans[i] = 'a' + j;
                    cnt[j]--;
                    k = i + 1;
                    for (j = 0; j < 26; j++)
                        while (cnt[j]--)
                            ans[k++] = 'a' + j;
                    ans[n] = '\0';
                    return ans;
                }
        if (i == 0) break;
        cnt[t[--i] - 'a']++;
    }
    return "";
}