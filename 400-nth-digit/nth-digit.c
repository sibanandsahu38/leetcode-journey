int findNthDigit(int n) {
    long d = 1;
    long c = 9;
    long s = 1;
    while (n > d * c) {
        n-= d * c;
        d++;
        c*=10;
        s*=10;
    }
    s+=(n-1)/d;
    char str[20];
    sprintf(str, "%ld", s);
    return str[(n - 1) % d] - '0';
}