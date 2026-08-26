char* shortestBeautifulSubstring(char* s, int k) {
    int p[1000], n = 0, min = 1000, best = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == '1') p[n++] = i;    
    if (n < k) return "";
    for (int i = 0; i <= n - k; i++) {
        int len = p[i + k - 1] - p[i] + 1;
        if (len < min || (len == min && strncmp(s + p[i], s + p[best], len) < 0)) {
            min = len;
            best = i;
        }
    }
    char* res = (char*)calloc(min + 1, sizeof(char));
    return strncpy(res, s + p[best], min);
}