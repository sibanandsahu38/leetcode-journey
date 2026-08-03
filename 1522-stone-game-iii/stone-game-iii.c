char* stoneGameIII(int* value, int size) {
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    for (int i = size - 1; i >= 0; i--) {
        int v1 = value[i];
        int v2 = v1 + (i + 1 < size ? value[i + 1] : 0);
        int v3 = v2 + (i + 2 < size ? value[i + 2] : 0);

        int s0 = v1 - s1;
        s0 = s0 > v2 - s2 ? s0 : v2 - s2;
        s0 = s0 > v3 - s3 ? s0 : v3 - s3;

        s3 = s2;
        s2 = s1;
        s1 = s0;
    }

    return s1 > 0 ? "Alice" : (s1 < 0 ? "Bob" : "Tie");
}