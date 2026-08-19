bool isPowerOfTwo(int n) {
    return n > 0 && ((n ^ (n - 1)) >> 1) == (n - 1);    
}