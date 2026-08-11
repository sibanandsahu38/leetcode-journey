int missingInteger(int* a, int n) {
    int s = a[0], i, j;
    for (i = 1; i < n && a[i] == a[i-1] + 1; i++)
        s += a[i];
    while (1) {
        for (j = 0; j < n; j++)
            if (a[j] == s) break;
        if (j == n) return s;
        s++;
    }
}