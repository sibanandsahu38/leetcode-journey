int maxSubarrayLength(int* a, int n, int k) {
    int m = 2 * n + 1;
    int *s = calloc(m, sizeof(int));
    int *c = calloc(m, sizeof(int));
    int l = 0, ans = 0;

    for (int r=0;r<n;r++) {
        int p=a[r]%m;
        while (s[p] && s[p] != a[r]) p = (p + 1) % m;
        s[p] = a[r];
        c[p]++;
        while (c[p] > k) {
            int q = a[l] % m;
            while (s[q] != a[l]) q=(q+1)%m;
            c[q]--;
            l++;
        }
        if (r-l+1>ans) ans=r-l+1;
    }
    return ans;
}