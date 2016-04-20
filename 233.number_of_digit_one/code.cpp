class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        long long nL = n;
        long long m = 1;
        int ans = 0;
        while (m <= nL) {
            long long a = nL / (10 * m);
            long long b = nL % (10 * m);
            ans += a * m;
            if (b >= 2 * m - 1) ans += m;
            else if (b >= m) ans += b - m + 1;
            m *= 10;
        }
        return ans;
    }
};
