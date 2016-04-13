class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if (dividend < 0) sign *= -1;
        if (divisor < 0) sign *= -1;
        unsigned long long dividendLL = abs((long long) dividend);
        unsigned long long divisorLL = abs((long long) divisor);
        if (dividendLL < divisorLL) return 0;
        long long ans = 0;
        int bit = 0;
        unsigned long long subdivisorLL = divisorLL;
        while (dividendLL >= subdivisorLL << 1) {
            bit++;
            subdivisorLL <<= 1;
        }
        if (bit == 31 && sign == 1) return INT_MAX;
        dividendLL -= subdivisorLL;
        ans += 1 << bit;
        while (dividendLL >= divisorLL) {
            while (dividendLL < divisorLL << bit) bit--;
            dividendLL -= divisorLL << bit;
            ans += 1 << bit;
        }
        return ans * sign;
    }
};
