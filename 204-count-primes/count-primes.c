int countPrimes(int n) {
    if (n <= 2) return 0;
    int prime[n];
    for (int i = 0; i < n; i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i)
                prime[j] = 0;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
        if (prime[i]) count++;

    return count;
}


