class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (i + 1 == j || isPalin[i + 1][j - 1]) {
                        isPalin[i][j] = true;
                        if (j + 1 == n) dp[i] = 0;
                        else dp[i] = min(dp[j + 1] + 1, dp[i]);
                    }
                }
            }
        }
        return dp[0];
    }
};
