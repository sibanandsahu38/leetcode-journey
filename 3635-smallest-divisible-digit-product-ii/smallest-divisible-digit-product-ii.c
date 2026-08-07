long long gcd_ll(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

char* smallestNumber(char* num, long long t) {
    long long temp = t;

    for (int digit = 2; digit <= 9; digit++) {
        while (temp % digit == 0) {
            temp /= digit;
        }
    }

    if (temp != 1) {
        char* result = malloc(3);
        strcpy(result, "-1");
        return result;
    }

    int n = strlen(num);

    char* digits = malloc(n + 2);
    strcpy(digits, num);

    long long* remaining = calloc(n + 1, sizeof(long long));
    remaining[0] = t;

    int lastValidPos = n - 1;

    for (int i = 0; i < n; i++) {
        int digit = digits[i] - '0';

        if (digit == 0) {
            lastValidPos = i;
            break;
        }

        long long common = gcd_ll(remaining[i], digit);
        remaining[i + 1] = remaining[i] / common;
    }

    if (remaining[n] == 1) {
        free(remaining);
        return digits;
    }

    for (int i = lastValidPos; i >= 0; i--) {
        int currentDigit = digits[i] - '0';

        for (int newDigit = currentDigit + 1; newDigit <= 9; newDigit++) {
            digits[i] = '0' + newDigit;

            long long need = remaining[i];
            need /= gcd_ll(need, newDigit);

            char* suffix = malloc(n + 1);
            int suffixSize = 0;

            for (int j = i + 1; j < n; j++) {
                int chosenDigit = 9;

                while (chosenDigit > 1 &&
                       need % chosenDigit != 0) {
                    chosenDigit--;
                }

                if (need % chosenDigit == 0) {
                    need /= chosenDigit;
                }

                suffix[suffixSize++] = '0' + chosenDigit;
            }

            if (need == 1) {
                for (int a = 0, b = suffixSize - 1; a < b; a++, b--) {
                    char tmp = suffix[a];
                    suffix[a] = suffix[b];
                    suffix[b] = tmp;
                }

                for (int j = i + 1; j < n; j++) {
                    digits[j] = suffix[j - i - 1];
                }

                digits[n] = '\0';

                free(suffix);
                free(remaining);

                return digits;
            }

            free(suffix);
        }

        digits[i] = num[i];
    }

    char* factors = malloc(n + 100);
    int factorCount = 0;

    long long remainingT = t;

    for (int digit = 9; digit >= 2; digit--) {
        while (remainingT % digit == 0) {
            factors[factorCount++] = '0' + digit;
            remainingT /= digit;
        }
    }

    int requiredLength = n + 1;

    if (factorCount > requiredLength) {
        requiredLength = factorCount;
    }

    while (factorCount < requiredLength) {
        factors[factorCount++] = '1';
    }

    for (int i = 0, j = factorCount - 1; i < j; i++, j--) {
        char tmp = factors[i];
        factors[i] = factors[j];
        factors[j] = tmp;
    }

    factors[factorCount] = '\0';

    free(digits);
    free(remaining);

    return factors;
}