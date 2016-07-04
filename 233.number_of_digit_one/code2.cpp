class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        long long count = 0;
        for (long long i = 1; i < INT_MAX && n >= i; i *= 10) {
            count += n / (i * 10) * i;
            if (n % (i * 10) > i - 1) count += min(n % (i * 10) - i + 1, i);
        }
        return count;
    }
};
