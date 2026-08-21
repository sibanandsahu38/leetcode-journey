long long gcd(long long a, long long b) { 
    return b ? gcd(b, a % b) : a; 
}

long long findKthSmallest(int* coins, int coinsSize, int k) {
    int f[15], m = 0;
    for (int i = 0; i < coinsSize; i++) {
        int d = 0;
        for (int j = 0; j < coinsSize; j++)
            if (i != j && coins[i] % coins[j] == 0 && (coins[i] > coins[j] || i > j)) d = 1;
        if (!d) f[m++] = coins[i];
    }
    long long l = 1, h = 1LL * f[0] * k, ans = h;
    while (l <= h) {
        long long mid = l + (h - l) / 2, cnt = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            long long lcm = 1; int bits = 0;
            for (int i = 0; i < m; i++) if ((mask >> i) & 1) {
                bits++;
                long long g = gcd(lcm, f[i]);
                if (lcm / g > mid / f[i]) { lcm = mid + 1; break; }
                lcm = (lcm / g) * f[i];
            }
            cnt += (bits & 1 ? 1 : -1) * (mid / lcm);
        }
        if (cnt >= k) { ans = mid; h = mid - 1; }
        else l = mid + 1;
    }
    return ans;
}