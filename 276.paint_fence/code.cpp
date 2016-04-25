class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = k;
        if (n == 1) return dp[n - 1];
        dp[1] = dp[0] * (k - 1) + k;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] * (k - 1);
            dp[i] += dp[i - 2] * (k - 1);
        }
        return dp[n - 1];
    }
};
