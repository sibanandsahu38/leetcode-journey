int mySqrt(int x) {
    int l = 0, h = x, ans = -1;

    while (l <= h) {
        long long m=(l+h) / 2;
        long long ms=m*m;

        if (ms==x)
            return m;
        else if(ms > x)
            h=m-1;
        else {
            ans=m;
            l=m+1;
        }
    }

    return ans;
}