class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> dp(n, 0);
        dp[0] = 9;
        int factor = 9, ans = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] * factor--;
        }
        for (int i = 0; i < n; i++) {
            ans += dp[i];
        }
        return ans + 1;
    }
};
