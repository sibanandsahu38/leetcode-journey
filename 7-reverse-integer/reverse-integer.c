#include<math.h>
int reverse(int x){
    long rev = 0;
        while (x != 0) {
        rev = rev * 10 + x % 10;
        if (rev > INT_MAX || rev < INT_MIN) 
            return 0;
        x /= 10;
    }
        return (int)rev;
    }