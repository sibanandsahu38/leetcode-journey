int power(int a, int b) {
    int ans = 1;
    a %= 1337;
    while (b--)
        ans = (ans * a) %1337;
    return ans;
}

int superPow(int a, int* b, int bSize) {
    int ans = 1;
    for (int i = 0; i < bSize; i++) 
        ans = (power(ans, 10) * power(a, b[i])) %1337;
    return ans;
}