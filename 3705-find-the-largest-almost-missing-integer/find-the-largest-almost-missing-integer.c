int largestInteger(int* a, int n, int k) {
    int c[51] = {0};
    for (int i = 0; i <= n - k; i++)
        for (int v = 0; v <= 50; v++)
            for (int j = i; j < i + k; j++)
                if (a[j] == v) { c[v]++; break; }

    for (int i = 50; i >= 0; i--) 
        if (c[i] == 1) return i;
    return -1;
}